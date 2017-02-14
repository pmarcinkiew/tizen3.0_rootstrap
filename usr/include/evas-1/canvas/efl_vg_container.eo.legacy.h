#ifndef _EFL_VG_CONTAINER_EO_LEGACY_H_
#define _EFL_VG_CONTAINER_EO_LEGACY_H_

#ifndef _EFL_VG_CONTAINER_EO_CLASS_TYPE
#define _EFL_VG_CONTAINER_EO_CLASS_TYPE

typedef Eo Efl_VG_Container;

#endif

#ifndef _EFL_VG_CONTAINER_EO_TYPES
#define _EFL_VG_CONTAINER_EO_TYPES


#endif
EAPI Efl_VG_Base *evas_vg_container_child_get(Efl_VG_Container *obj, const char *name);
EAPI Eina_Iterator *evas_vg_container_children_get(Efl_VG_Container *obj) EINA_WARN_UNUSED_RESULT;

#endif
