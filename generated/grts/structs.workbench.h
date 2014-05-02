#ifndef __grts_structs_workbench_h__
#define __grts_structs_workbench_h__

#include <grtpp.h>

#ifdef _WIN32
  #pragma warning(disable: 4355) // 'this' : used in base member initizalizer list
  #ifdef GRT_STRUCTS_WORKBENCH_EXPORT
  #define GRT_STRUCTS_WORKBENCH_PUBLIC __declspec(dllexport)
#else
  #define GRT_STRUCTS_WORKBENCH_PUBLIC __declspec(dllimport)
#endif
#else
  #define GRT_STRUCTS_WORKBENCH_PUBLIC
#endif

#include <grts/structs.h>
#include <grts/structs.app.h>
#include <grts/structs.db.h>
#include <grts/structs.db.query.h>
#include <grts/structs.db.mgmt.h>
#include <grts/structs.workbench.physical.h>
#include <grts/structs.workbench.logical.h>
#include <grts/structs.db.migration.h>


class workbench_OverviewPanel;
typedef grt::Ref<workbench_OverviewPanel> workbench_OverviewPanelRef;
class workbench_Document;
typedef grt::Ref<workbench_Document> workbench_DocumentRef;
class workbench_Workbench;
typedef grt::Ref<workbench_Workbench> workbench_WorkbenchRef;


class  workbench_OverviewPanel : public GrtObject
{
  typedef GrtObject super;
public:
  workbench_OverviewPanel(grt::GRT *grt, grt::MetaClass *meta=0)
  : GrtObject(grt, meta ? meta : grt->get_metaclass(static_class_name())),
     _caption(""),
     _expanded(0),
     _expandedHeight(0),
     _hasTabSelection(0),
     _implModule(""),
     _itemActivationFunction(""),
     _itemCountFunction(""),
     _itemDisplayMode(0),
     _itemInfoFunction(""),
     _nodeId(""),
    _selectedItems(grt, this, false),
     _tabActivationFunction(""),
     _tabCountFunction(""),
     _tabInfoFunction("")

  {
  }

  static std::string static_class_name() { return "workbench.OverviewPanel"; }

  /** Getter for attribute caption
   
    the caption displayed on the panel's header
   \par In Python:
value = obj.caption
   */
  grt::StringRef caption() const { return _caption; }
  /** Setter for attribute caption
   
    the caption displayed on the panel's header
    \par In Python:
obj.caption = value
   */
  virtual void caption(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_caption);
   _caption= value;
    member_changed("caption", ovalue, value);
  }

  /** Getter for attribute expanded
   
    specifies if the panel is currently expanded
   \par In Python:
value = obj.expanded
   */
  grt::IntegerRef expanded() const { return _expanded; }
  /** Setter for attribute expanded
   
    specifies if the panel is currently expanded
    \par In Python:
obj.expanded = value
   */
  virtual void expanded(const grt::IntegerRef &value)
  {
    grt::ValueRef ovalue(_expanded);
   _expanded= value;
    member_changed("expanded", ovalue, value);
  }

  /** Getter for attribute expandedHeight
   
    the panel's height when it is expanded
   \par In Python:
value = obj.expandedHeight
   */
  grt::IntegerRef expandedHeight() const { return _expandedHeight; }
  /** Setter for attribute expandedHeight
   
    the panel's height when it is expanded
    \par In Python:
obj.expandedHeight = value
   */
  virtual void expandedHeight(const grt::IntegerRef &value)
  {
    grt::ValueRef ovalue(_expandedHeight);
   _expandedHeight= value;
    member_changed("expandedHeight", ovalue, value);
  }

  /** Getter for attribute hasTabSelection
   
    specifies if the panel has attached tabs
   \par In Python:
value = obj.hasTabSelection
   */
  grt::IntegerRef hasTabSelection() const { return _hasTabSelection; }
  /** Setter for attribute hasTabSelection
   
    specifies if the panel has attached tabs
    \par In Python:
obj.hasTabSelection = value
   */
  virtual void hasTabSelection(const grt::IntegerRef &value)
  {
    grt::ValueRef ovalue(_hasTabSelection);
   _hasTabSelection= value;
    member_changed("hasTabSelection", ovalue, value);
  }

  /** Getter for attribute implModule
   
    GRT module implementing the item functionality
   \par In Python:
value = obj.implModule
   */
  grt::StringRef implModule() const { return _implModule; }
  /** Setter for attribute implModule
   
    GRT module implementing the item functionality
    \par In Python:
obj.implModule = value
   */
  virtual void implModule(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_implModule);
   _implModule= value;
    member_changed("implModule", ovalue, value);
  }

  /** Getter for attribute itemActivationFunction
   
    the function that is called when the item is activated
   \par In Python:
value = obj.itemActivationFunction
   */
  grt::StringRef itemActivationFunction() const { return _itemActivationFunction; }
  /** Setter for attribute itemActivationFunction
   
    the function that is called when the item is activated
    \par In Python:
obj.itemActivationFunction = value
   */
  virtual void itemActivationFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_itemActivationFunction);
   _itemActivationFunction= value;
    member_changed("itemActivationFunction", ovalue, value);
  }

  /** Getter for attribute itemCountFunction
   
    the function that returns the number of items
   \par In Python:
value = obj.itemCountFunction
   */
  grt::StringRef itemCountFunction() const { return _itemCountFunction; }
  /** Setter for attribute itemCountFunction
   
    the function that returns the number of items
    \par In Python:
obj.itemCountFunction = value
   */
  virtual void itemCountFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_itemCountFunction);
   _itemCountFunction= value;
    member_changed("itemCountFunction", ovalue, value);
  }

  /** Getter for attribute itemDisplayMode
   
    defines how the items on the panel are displayed. Setting it to 1 will cause a large icon display, 2 a small icon display and 3 a list
   \par In Python:
value = obj.itemDisplayMode
   */
  grt::IntegerRef itemDisplayMode() const { return _itemDisplayMode; }
  /** Setter for attribute itemDisplayMode
   
    defines how the items on the panel are displayed. Setting it to 1 will cause a large icon display, 2 a small icon display and 3 a list
    \par In Python:
obj.itemDisplayMode = value
   */
  virtual void itemDisplayMode(const grt::IntegerRef &value)
  {
    grt::ValueRef ovalue(_itemDisplayMode);
   _itemDisplayMode= value;
    member_changed("itemDisplayMode", ovalue, value);
  }

  /** Getter for attribute itemInfoFunction
   
    the function that returns the item information
   \par In Python:
value = obj.itemInfoFunction
   */
  grt::StringRef itemInfoFunction() const { return _itemInfoFunction; }
  /** Setter for attribute itemInfoFunction
   
    the function that returns the item information
    \par In Python:
obj.itemInfoFunction = value
   */
  virtual void itemInfoFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_itemInfoFunction);
   _itemInfoFunction= value;
    member_changed("itemInfoFunction", ovalue, value);
  }

  /** Getter for attribute nodeId
   
    the identifier of panel in the GUI
   \par In Python:
value = obj.nodeId
   */
  grt::StringRef nodeId() const { return _nodeId; }
  /** Setter for attribute nodeId
   
    the identifier of panel in the GUI
    \par In Python:
obj.nodeId = value
   */
  virtual void nodeId(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_nodeId);
   _nodeId= value;
    member_changed("nodeId", ovalue, value);
  }

  /** Getter for attribute selectedItems (read-only)
   
    specifies the indexes of the currently selected items on the panel
   \par In Python:
value = obj.selectedItems
   */
  grt::IntegerListRef selectedItems() const { return _selectedItems; }
private: // the next attribute is read-only
  virtual void selectedItems(const grt::IntegerListRef &value)
  {
    grt::ValueRef ovalue(_selectedItems);
   _selectedItems= value;
    member_changed("selectedItems", ovalue, value);
  }
public:

  /** Getter for attribute tabActivationFunction
   
    the function that is called when the tab is activated
   \par In Python:
value = obj.tabActivationFunction
   */
  grt::StringRef tabActivationFunction() const { return _tabActivationFunction; }
  /** Setter for attribute tabActivationFunction
   
    the function that is called when the tab is activated
    \par In Python:
obj.tabActivationFunction = value
   */
  virtual void tabActivationFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_tabActivationFunction);
   _tabActivationFunction= value;
    member_changed("tabActivationFunction", ovalue, value);
  }

  /** Getter for attribute tabCountFunction
   
    the function that returns the number of tabs
   \par In Python:
value = obj.tabCountFunction
   */
  grt::StringRef tabCountFunction() const { return _tabCountFunction; }
  /** Setter for attribute tabCountFunction
   
    the function that returns the number of tabs
    \par In Python:
obj.tabCountFunction = value
   */
  virtual void tabCountFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_tabCountFunction);
   _tabCountFunction= value;
    member_changed("tabCountFunction", ovalue, value);
  }

  /** Getter for attribute tabInfoFunction
   
    the function that returns the tab information
   \par In Python:
value = obj.tabInfoFunction
   */
  grt::StringRef tabInfoFunction() const { return _tabInfoFunction; }
  /** Setter for attribute tabInfoFunction
   
    the function that returns the tab information
    \par In Python:
obj.tabInfoFunction = value
   */
  virtual void tabInfoFunction(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_tabInfoFunction);
   _tabInfoFunction= value;
    member_changed("tabInfoFunction", ovalue, value);
  }

protected:

  grt::StringRef _caption;
  grt::IntegerRef _expanded;
  grt::IntegerRef _expandedHeight;
  grt::IntegerRef _hasTabSelection;
  grt::StringRef _implModule;
  grt::StringRef _itemActivationFunction;
  grt::StringRef _itemCountFunction;
  grt::IntegerRef _itemDisplayMode;
  grt::StringRef _itemInfoFunction;
  grt::StringRef _nodeId;
  grt::IntegerListRef _selectedItems;
  grt::StringRef _tabActivationFunction;
  grt::StringRef _tabCountFunction;
  grt::StringRef _tabInfoFunction;
private: // wrapper methods for use by grt
  static grt::ObjectRef create(grt::GRT *grt)
  {
    return grt::ObjectRef(new workbench_OverviewPanel(grt));
  }


public:
  static void grt_register(grt::GRT *grt)
  {
    grt::MetaClass *meta= grt->get_metaclass(static_class_name());
    if (!meta) throw std::runtime_error("error initializing grt object class, metaclass not found");
    meta->bind_allocator(&workbench_OverviewPanel::create);
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::caption;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::caption;
      meta->bind_member("caption", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::IntegerRef &)= &workbench_OverviewPanel::expanded;
      grt::IntegerRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::expanded;
      meta->bind_member("expanded", new grt::MetaClass::Property<workbench_OverviewPanel,grt::IntegerRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::IntegerRef &)= &workbench_OverviewPanel::expandedHeight;
      grt::IntegerRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::expandedHeight;
      meta->bind_member("expandedHeight", new grt::MetaClass::Property<workbench_OverviewPanel,grt::IntegerRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::IntegerRef &)= &workbench_OverviewPanel::hasTabSelection;
      grt::IntegerRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::hasTabSelection;
      meta->bind_member("hasTabSelection", new grt::MetaClass::Property<workbench_OverviewPanel,grt::IntegerRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::implModule;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::implModule;
      meta->bind_member("implModule", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::itemActivationFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::itemActivationFunction;
      meta->bind_member("itemActivationFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::itemCountFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::itemCountFunction;
      meta->bind_member("itemCountFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::IntegerRef &)= &workbench_OverviewPanel::itemDisplayMode;
      grt::IntegerRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::itemDisplayMode;
      meta->bind_member("itemDisplayMode", new grt::MetaClass::Property<workbench_OverviewPanel,grt::IntegerRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::itemInfoFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::itemInfoFunction;
      meta->bind_member("itemInfoFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::nodeId;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::nodeId;
      meta->bind_member("nodeId", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::IntegerListRef &)= &workbench_OverviewPanel::selectedItems;
      grt::IntegerListRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::selectedItems;
      meta->bind_member("selectedItems", new grt::MetaClass::Property<workbench_OverviewPanel,grt::IntegerListRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::tabActivationFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::tabActivationFunction;
      meta->bind_member("tabActivationFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::tabCountFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::tabCountFunction;
      meta->bind_member("tabCountFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_OverviewPanel::*setter)(const grt::StringRef &)= &workbench_OverviewPanel::tabInfoFunction;
      grt::StringRef (workbench_OverviewPanel::*getter)() const= &workbench_OverviewPanel::tabInfoFunction;
      meta->bind_member("tabInfoFunction", new grt::MetaClass::Property<workbench_OverviewPanel,grt::StringRef >(getter,setter));
    }
  }
};


class  workbench_Document : public app_Document
{
  typedef app_Document super;
public:
  workbench_Document(grt::GRT *grt, grt::MetaClass *meta=0)
  : app_Document(grt, meta ? meta : grt->get_metaclass(static_class_name())),
    _overviewPanels(grt, this, false),
    _physicalModels(grt, this, false)

  {
  }

  static std::string static_class_name() { return "workbench.Document"; }

  // logicalModel is owned by workbench_Document
  /** Getter for attribute logicalModel
   
    the logical model
   \par In Python:
value = obj.logicalModel
   */
  grt::Ref<workbench_logical_Model> logicalModel() const { return _logicalModel; }
  /** Setter for attribute logicalModel
   
    the logical model
    \par In Python:
obj.logicalModel = value
   */
  virtual void logicalModel(const grt::Ref<workbench_logical_Model> &value)
  {
    grt::ValueRef ovalue(_logicalModel);

    _logicalModel= value;
    owned_member_changed("logicalModel", ovalue, value);
  }

  /** Getter for attribute overviewCurrentModelType
   
    specifies if the panel is currently selected
   \par In Python:
value = obj.overviewCurrentModelType
   */
  grt::Ref<model_Model> overviewCurrentModelType() const { return _overviewCurrentModelType; }
  /** Setter for attribute overviewCurrentModelType
   
    specifies if the panel is currently selected
    \par In Python:
obj.overviewCurrentModelType = value
   */
  virtual void overviewCurrentModelType(const grt::Ref<model_Model> &value)
  {
    grt::ValueRef ovalue(_overviewCurrentModelType);
   _overviewCurrentModelType= value;
    member_changed("overviewCurrentModelType", ovalue, value);
  }

  // overviewPanels is owned by workbench_Document
  /** Getter for attribute overviewPanels (read-only)
   
    the panels that are presented on the overview page
   \par In Python:
value = obj.overviewPanels
   */
  grt::ListRef<workbench_OverviewPanel> overviewPanels() const { return _overviewPanels; }
private: // the next attribute is read-only
  virtual void overviewPanels(const grt::ListRef<workbench_OverviewPanel> &value)
  {
    grt::ValueRef ovalue(_overviewPanels);

    _overviewPanels= value;
    owned_member_changed("overviewPanels", ovalue, value);
  }
public:

  // physicalModels is owned by workbench_Document
  /** Getter for attribute physicalModels (read-only)
   
    the physical models
   \par In Python:
value = obj.physicalModels
   */
  grt::ListRef<workbench_physical_Model> physicalModels() const { return _physicalModels; }
private: // the next attribute is read-only
  virtual void physicalModels(const grt::ListRef<workbench_physical_Model> &value)
  {
    grt::ValueRef ovalue(_physicalModels);

    _physicalModels= value;
    owned_member_changed("physicalModels", ovalue, value);
  }
public:

protected:

  grt::Ref<workbench_logical_Model> _logicalModel;// owned
  grt::Ref<model_Model> _overviewCurrentModelType;
  grt::ListRef<workbench_OverviewPanel> _overviewPanels;// owned
  grt::ListRef<workbench_physical_Model> _physicalModels;// owned
private: // wrapper methods for use by grt
  static grt::ObjectRef create(grt::GRT *grt)
  {
    return grt::ObjectRef(new workbench_Document(grt));
  }


public:
  static void grt_register(grt::GRT *grt)
  {
    grt::MetaClass *meta= grt->get_metaclass(static_class_name());
    if (!meta) throw std::runtime_error("error initializing grt object class, metaclass not found");
    meta->bind_allocator(&workbench_Document::create);
    {
      void (workbench_Document::*setter)(const grt::Ref<workbench_logical_Model> &)= &workbench_Document::logicalModel;
      grt::Ref<workbench_logical_Model> (workbench_Document::*getter)() const= &workbench_Document::logicalModel;
      meta->bind_member("logicalModel", new grt::MetaClass::Property<workbench_Document,grt::Ref<workbench_logical_Model> >(getter,setter));
    }
    {
      void (workbench_Document::*setter)(const grt::Ref<model_Model> &)= &workbench_Document::overviewCurrentModelType;
      grt::Ref<model_Model> (workbench_Document::*getter)() const= &workbench_Document::overviewCurrentModelType;
      meta->bind_member("overviewCurrentModelType", new grt::MetaClass::Property<workbench_Document,grt::Ref<model_Model> >(getter,setter));
    }
    {
      void (workbench_Document::*setter)(const grt::ListRef<workbench_OverviewPanel> &)= &workbench_Document::overviewPanels;
      grt::ListRef<workbench_OverviewPanel> (workbench_Document::*getter)() const= &workbench_Document::overviewPanels;
      meta->bind_member("overviewPanels", new grt::MetaClass::Property<workbench_Document,grt::ListRef<workbench_OverviewPanel> >(getter,setter));
    }
    {
      void (workbench_Document::*setter)(const grt::ListRef<workbench_physical_Model> &)= &workbench_Document::physicalModels;
      grt::ListRef<workbench_physical_Model> (workbench_Document::*getter)() const= &workbench_Document::physicalModels;
      meta->bind_member("physicalModels", new grt::MetaClass::Property<workbench_Document,grt::ListRef<workbench_physical_Model> >(getter,setter));
    }
  }
};


  /** an object to store the workbench's data */
class  workbench_Workbench : public app_Application
{
  typedef app_Application super;
public:
  workbench_Workbench(grt::GRT *grt, grt::MetaClass *meta=0)
  : app_Application(grt, meta ? meta : grt->get_metaclass(static_class_name())),
     _docPath(""),
    _sqlEditors(grt, this, false)

  {
  }

  static std::string static_class_name() { return "workbench.Workbench"; }

  // doc is owned by workbench_Workbench
  /** Getter for attribute doc
   
    the Workbench document
   \par In Python:
value = obj.doc
   */
  grt::Ref<workbench_Document> doc() const { return grt::Ref<workbench_Document>::cast_from(_doc); }
  /** Setter for attribute doc
   
    the Workbench document
    \par In Python:
obj.doc = value
   */
  virtual void doc(const grt::Ref<workbench_Document> &value) { super::doc(value); }

  /** Getter for attribute docPath
   
    the Workbench document path
   \par In Python:
value = obj.docPath
   */
  grt::StringRef docPath() const { return _docPath; }
  /** Setter for attribute docPath
   
    the Workbench document path
    \par In Python:
obj.docPath = value
   */
  virtual void docPath(const grt::StringRef &value)
  {
    grt::ValueRef ovalue(_docPath);
   _docPath= value;
    member_changed("docPath", ovalue, value);
  }

  // migration is owned by workbench_Workbench
  /** Getter for attribute migration
   
    data for Migration Plugin
   \par In Python:
value = obj.migration
   */
  grt::Ref<db_migration_Migration> migration() const { return _migration; }
  /** Setter for attribute migration
   
    data for Migration Plugin
    \par In Python:
obj.migration = value
   */
  virtual void migration(const grt::Ref<db_migration_Migration> &value)
  {
    grt::ValueRef ovalue(_migration);

    _migration= value;
    owned_member_changed("migration", ovalue, value);
  }

  // rdbmsMgmt is owned by workbench_Workbench
  /** Getter for attribute rdbmsMgmt
   
    the RDBMS management information
   \par In Python:
value = obj.rdbmsMgmt
   */
  grt::Ref<db_mgmt_Management> rdbmsMgmt() const { return _rdbmsMgmt; }
  /** Setter for attribute rdbmsMgmt
   
    the RDBMS management information
    \par In Python:
obj.rdbmsMgmt = value
   */
  virtual void rdbmsMgmt(const grt::Ref<db_mgmt_Management> &value)
  {
    grt::ValueRef ovalue(_rdbmsMgmt);

    _rdbmsMgmt= value;
    owned_member_changed("rdbmsMgmt", ovalue, value);
  }

  // sqlEditors is owned by workbench_Workbench
  /** Getter for attribute sqlEditors (read-only)
   
    list of open SQL Editor instances
   \par In Python:
value = obj.sqlEditors
   */
  grt::ListRef<db_query_Editor> sqlEditors() const { return _sqlEditors; }
private: // the next attribute is read-only
  virtual void sqlEditors(const grt::ListRef<db_query_Editor> &value)
  {
    grt::ValueRef ovalue(_sqlEditors);

    _sqlEditors= value;
    owned_member_changed("sqlEditors", ovalue, value);
  }
public:

protected:

  grt::StringRef _docPath;
  grt::Ref<db_migration_Migration> _migration;// owned
  grt::Ref<db_mgmt_Management> _rdbmsMgmt;// owned
  grt::ListRef<db_query_Editor> _sqlEditors;// owned
private: // wrapper methods for use by grt
  static grt::ObjectRef create(grt::GRT *grt)
  {
    return grt::ObjectRef(new workbench_Workbench(grt));
  }


public:
  static void grt_register(grt::GRT *grt)
  {
    grt::MetaClass *meta= grt->get_metaclass(static_class_name());
    if (!meta) throw std::runtime_error("error initializing grt object class, metaclass not found");
    meta->bind_allocator(&workbench_Workbench::create);
    {
      void (workbench_Workbench::*setter)(const grt::Ref<workbench_Document> &)= 0;
      grt::Ref<workbench_Document> (workbench_Workbench::*getter)() const= 0;
      meta->bind_member("doc", new grt::MetaClass::Property<workbench_Workbench,grt::Ref<workbench_Document> >(getter,setter));
    }
    {
      void (workbench_Workbench::*setter)(const grt::StringRef &)= &workbench_Workbench::docPath;
      grt::StringRef (workbench_Workbench::*getter)() const= &workbench_Workbench::docPath;
      meta->bind_member("docPath", new grt::MetaClass::Property<workbench_Workbench,grt::StringRef >(getter,setter));
    }
    {
      void (workbench_Workbench::*setter)(const grt::Ref<db_migration_Migration> &)= &workbench_Workbench::migration;
      grt::Ref<db_migration_Migration> (workbench_Workbench::*getter)() const= &workbench_Workbench::migration;
      meta->bind_member("migration", new grt::MetaClass::Property<workbench_Workbench,grt::Ref<db_migration_Migration> >(getter,setter));
    }
    {
      void (workbench_Workbench::*setter)(const grt::Ref<db_mgmt_Management> &)= &workbench_Workbench::rdbmsMgmt;
      grt::Ref<db_mgmt_Management> (workbench_Workbench::*getter)() const= &workbench_Workbench::rdbmsMgmt;
      meta->bind_member("rdbmsMgmt", new grt::MetaClass::Property<workbench_Workbench,grt::Ref<db_mgmt_Management> >(getter,setter));
    }
    {
      void (workbench_Workbench::*setter)(const grt::ListRef<db_query_Editor> &)= &workbench_Workbench::sqlEditors;
      grt::ListRef<db_query_Editor> (workbench_Workbench::*getter)() const= &workbench_Workbench::sqlEditors;
      meta->bind_member("sqlEditors", new grt::MetaClass::Property<workbench_Workbench,grt::ListRef<db_query_Editor> >(getter,setter));
    }
  }
};




inline void register_structs_workbench_xml()
{
  grt::internal::ClassRegistry::register_class<workbench_OverviewPanel>();
  grt::internal::ClassRegistry::register_class<workbench_Document>();
  grt::internal::ClassRegistry::register_class<workbench_Workbench>();
}

#ifdef AUTO_REGISTER_GRT_CLASSES
static struct _autoreg__structs_workbench_xml { _autoreg__structs_workbench_xml() { register_structs_workbench_xml(); } } __autoreg__structs_workbench_xml;
#endif

#endif
