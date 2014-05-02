/* 
 * Copyright (c) 2008, 2012, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */
#include "stdafx.h"

#include "mforms/mforms.h"

using namespace mforms;

static boost::signals2::signal<void (int)> _radio_activated;
static int radio_group_id = 0;

int RadioButton::new_id()
{
  return ++radio_group_id;
}


RadioButton::RadioButton(int group_id)
: _group_id(group_id)
{
  _radio_impl= &ControlFactory::get_instance()->_radio_impl;

  _radio_impl->create(this, group_id);
  
  scoped_connect(&_radio_activated, boost::bind(&RadioButton::radio_activated, this, _1));
}


void RadioButton::set_active(bool flag)
{
  _updating= true;
  (*_radio_impl->set_active)(this, flag);
  if (flag)
    _radio_activated(_group_id);
  _updating= false;
}


bool RadioButton::get_active()
{
  return (*_radio_impl->get_active)(this);
}


void RadioButton::radio_activated(int group_id)
{
  if (group_id == _group_id && !_updating)
    set_active(false);
}


void RadioButton::callback()
{
  if (!_updating)
  {
    _updating = true;
    _radio_activated(_group_id);
    _updating = false;
    _signal_toggled();
  }

  Button::callback();
}

