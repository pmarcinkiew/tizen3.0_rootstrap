#ifndef _EFL_VG_CONTAINER_EO_H_
#define _EFL_VG_CONTAINER_EO_H_

#ifndef _EFL_VG_CONTAINER_EO_CLASS_TYPE
#define _EFL_VG_CONTAINER_EO_CLASS_TYPE

typedef Eo Efl_VG_Container;

#endif

#ifndef _EFL_VG_CONTAINER_EO_TYPES
#define _EFL_VG_CONTAINER_EO_TYPES


#endif
#define EFL_VG_CONTAINER_CLASS efl_vg_container_class_get()

EAPI const Eo_Class *efl_vg_container_class_get(void) EINA_CONST;

EOAPI Efl_VG_Base * efl_vg_container_child_get(const char *name);

EOAPI Eina_Iterator * efl_vg_container_children_get(void);


#endif
