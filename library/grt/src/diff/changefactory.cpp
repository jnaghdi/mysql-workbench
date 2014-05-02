/* 
 * Copyright (c) 2008, 2014, Oracle and/or its affiliates. All rights reserved.
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

#include "changefactory.h"
#include "changeobjects.h"
#include "grts/structs.h"
#include "base/log.h"

//DEFAULT_LOG_DOMAIN("diff")

#ifdef DEBUG_DIFF
static std::string rep(const grt::ValueRef &value)
{
  switch (value.type())
  {
    case grt::ObjectType:
      return grt::ObjectRef::cast_from(value)->get_string_member("name");
    default:
      return value.repr();
  }
}
#endif

namespace grt
{

bool is_any(ValueRef& s);


boost::shared_ptr<DiffChange> ChangeFactory::create_value_added_change(boost::shared_ptr<DiffChange> parent, const ValueRef &source, const ValueRef &target, bool dupvalue)
{
#ifdef DEBUG_DIFF
  log_info("value_added (%s)\n", rep(target).c_str());
#endif
  return boost::shared_ptr<DiffChange>(new ValueAddedChange(ValueAdded, target, dupvalue));
}


boost::shared_ptr<DiffChange> ChangeFactory::create_value_removed_change(boost::shared_ptr<DiffChange> parent, const ValueRef &source, const ValueRef &target)
{
#ifdef DEBUG_DIFF
  log_info("value_remove (%s)\n", rep(target).c_str());
#endif
  return boost::shared_ptr<DiffChange>(new ValueRemovedChange);
}


boost::shared_ptr<DiffChange> ChangeFactory::create_object_attr_modified_change(boost::shared_ptr<DiffChange> parent, const ObjectRef &source, const ObjectRef &target, const std::string &attr, boost::shared_ptr<DiffChange> change)
{
  if (change)
  {
#ifdef DEBUG_DIFF
    log_info("attr_change %s\n", attr.c_str());
    if (attr == "flags")
      log_info("%s.%s) %s // %s\n", ObjectRef::cast_from(source.get_member("owner")).get_string_member("name").c_str(), source.get_string_member("name").c_str(), source.get_member(attr).repr().c_str(), target.get_member(attr).repr().c_str());
#endif
    return boost::shared_ptr<DiffChange>(new ObjectAttrModifiedChange(attr, change));
  }
  return boost::shared_ptr<DiffChange>();
}


boost::shared_ptr<MultiChange> ChangeFactory::create_object_modified_change(boost::shared_ptr<DiffChange> parent, const ObjectRef &source, const ObjectRef &target, ChangeSet &changes)
{
  if (!changes.empty())
  {
#ifdef DEBUG_DIFF
    log_info("object_modified (%s)\n", rep(target).c_str());
#endif
    return boost::shared_ptr<MultiChange>(new MultiChange(ObjectModified, changes));
  }
  return boost::shared_ptr<MultiChange>();
}

template<class T> inline bool check(ValueRef source, ValueRef target)
{
  return T::cast_from(source) == T::cast_from(target);
}

boost::shared_ptr<DiffChange>  ChangeFactory::create_simple_value_change( boost::shared_ptr<DiffChange> parent, const ValueRef &source, const ValueRef &target )
{
  grt::Type t= UnknownType;
  if (source.is_valid())
    t= source.type();
  else if (target.is_valid())
    t= target.type();

  switch(t)
  {
  case IntegerType:
    if(check<grt::IntegerRef>(source, target))
      return boost::shared_ptr<DiffChange>();
    break;
  case DoubleType:
    if(check<grt::DoubleRef>(source, target))
      return boost::shared_ptr<DiffChange>();
    break;
  case StringType:
      if(check<grt::StringRef>(source, target))
        return boost::shared_ptr<DiffChange>();
    break;

  case ObjectType:
    break;
  case ListType:
  case DictType:
  case UnknownType:
    return boost::shared_ptr<DiffChange>();
    break;

  default:
    assert(0);
  }

#ifdef DEBUG_DIFF
  log_info("simple_value_change: %s -> %s\n", rep(source).c_str(), rep(target).c_str());
#endif
  return boost::shared_ptr<DiffChange>(new SimpleValueChange(source, target));
}


boost::shared_ptr<MultiChange> ChangeFactory::create_dict_change(boost::shared_ptr<DiffChange> parent, const DictRef &source, const DictRef &target, ChangeSet &changes)
{
  if (changes.empty())
    return boost::shared_ptr<MultiChange>();

  return boost::shared_ptr<MultiChange>(new MultiChange(DictModified, changes));
}

boost::shared_ptr<DiffChange> ChangeFactory::create_dict_item_added_change(boost::shared_ptr<DiffChange> parent, const DictRef &source, const DictRef &target, const std::string &key, ValueRef v, bool dupvalue)
{
  return boost::shared_ptr<DiffChange>(new DictItemAddedChange(key, v, dupvalue));
}

boost::shared_ptr<DiffChange> ChangeFactory::create_dict_item_modified_change(boost::shared_ptr<DiffChange> parent, const DictRef &source, const DictRef &target, const std::string &key, boost::shared_ptr<DiffChange> change)
{
  if (change)
    return boost::shared_ptr<DiffChange>(new DictItemModifiedChange(key, change));
  return boost::shared_ptr<DiffChange>();
}

boost::shared_ptr<DiffChange> ChangeFactory::create_dict_item_removed_change(boost::shared_ptr<DiffChange> parent, const DictRef &source, const DictRef &target, const std::string &key)
{
  return boost::shared_ptr<DiffChange>(new DictItemRemovedChange(key));
}

}

