/* 
 * Copyright (c) 2007, 2014, Oracle and/or its affiliates. All rights reserved.
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

using namespace System;
using namespace System::Collections::Generic;

#include "ConvUtils.h"
#include "GrtTemplates.h"
#include "DelegateWrapper.h"
#include "IconManager.h"
#include "Grt.h"
#include "ModelWrappers.h"
#include "var_grid_model_wr.h"
#include "ActionList.h"
#include "GrtThreadedTaskWrapper.h"

#include "recordset_wr.h"

#include "mforms/menubar.h"
#include "mforms/toolbar.h"

using namespace MySQL::Forms;
using namespace MySQL::Grt;
using namespace MySQL::Grt::Db;

//--------------------------------------------------------------------------------------------------

RecordsetWrapper::RecordsetWrapper(Ref ref)
  : VarGridModelWrapper(Ref_N2M<::VarGridModel>(&ref)), _ref(ref), 
  task(gcnew GrtThreadedTaskWrapper(_ref->task.get())), action_list(gcnew ActionList(&_ref->action_list()))
{
}

//--------------------------------------------------------------------------------------------------

RecordsetWrapper::RecordsetWrapper(IntPtr nref_ptr)
  : _ref(gcnew ManagedRef<::Recordset>(nref_ptr)), VarGridModelWrapper(Ref_N2M<::VarGridModel>(&_ref)),
  task(gcnew GrtThreadedTaskWrapper(_ref->task.get())), action_list(gcnew ActionList(&_ref->action_list()))
{
}

//--------------------------------------------------------------------------------------------------

RecordsetWrapper::~RecordsetWrapper()
{
  if (!(void*)~_ref)
    return;
  delete action_list;
  delete task;
  delete _ref;
  delete _apply_changes;
  _apply_changes = nullptr;
}

//--------------------------------------------------------------------------------------------------

void RecordsetWrapper::register_edit_actions()
{
  mforms::ToolBarItem *item;
  item = _ref->get_toolbar()->find_item("record_del");
  if (item)
  {
    item->signal_activated()->connect(boost::bind(&::ActionList::trigger_action, &_ref->action_list(), "record_del"));
    _ref->get_toolbar()->find_item("record_add")->signal_activated()->connect(boost::bind(&::ActionList::trigger_action, &_ref->action_list(), "record_add"));
    _ref->get_toolbar()->find_item("record_edit")->signal_activated()->connect(boost::bind(&::ActionList::trigger_action, &_ref->action_list(), "record_edit"));
  }
  item = _ref->get_toolbar()->find_item("record_wrap_vertical");
  if (item)
    item->signal_activated()->connect(boost::bind(&::ActionList::trigger_action, &_ref->action_list(), "record_wrap_vertical"));
}

//--------------------------------------------------------------------------------------------------

void RecordsetWrapper::pending_changes(int %upd_count, int %ins_count, int %del_count)
{
  int upd_count_, ins_count_, del_count_;
  _ref->pending_changes(upd_count_, ins_count_, del_count_);
  upd_count=upd_count_; ins_count=ins_count_; del_count=del_count_;
}

//--------------------------------------------------------------------------------------------------

void RecordsetWrapper::set_apply_changes(DelegateSlot0<void, void>::ManagedDelegate ^apply)
{
  _apply_changes = gcnew DelegateSlot0<void, void>(apply);
  _ref->apply_changes = _apply_changes->get_slot();
}

//--------------------------------------------------------------------------------------------------

void RecordsetWrapper::copy_rows_to_clipboard(List<int> ^indexes)
{
  std::vector<int> row_indexes = IntListToCppVector(indexes);
  _ref->copy_rows_to_clipboard(row_indexes);
}

//--------------------------------------------------------------------------------------------------

ContextMenuStrip ^RecordsetWrapper::get_context_menu(List<int> ^indexes, int clicked_column)
{
  std::vector<int> row_indexes = IntListToCppVector(indexes);
  _ref->update_selection_for_menu(row_indexes, clicked_column);
  return dynamic_cast<ContextMenuStrip ^>(ObjectMapper::GetManagedComponent(_ref->get_context_menu()));
}

//--------------------------------------------------------------------------------------------------

bool RecordsetWrapper::delete_nodes(List<NodeId^> ^nodes)
{
  std::vector<bec::NodeId> nodes_= convert_node_list(nodes);
  return _ref->delete_nodes(nodes_);
}

//--------------------------------------------------------------------------------------------------
