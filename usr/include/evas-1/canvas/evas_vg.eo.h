#ifndef _EVAS_VG_EO_H_
#define _EVAS_VG_EO_H_

#ifndef _EVAS_VG_EO_CLASS_TYPE
#define _EVAS_VG_EO_CLASS_TYPE

typedef Eo Evas_VG;

#endif

#ifndef _EVAS_VG_EO_TYPES
#define _EVAS_VG_EO_TYPES


#endif
#define EVAS_VG_CLASS evas_vg_class_get()

EAPI const Eo_Class *evas_vg_class_get(void) EINA_CONST;

/**
 * @brief Get the root node of the evas_object_vg.
 *
 * @note To manually create the shape object and show in the Vg object canvas
 * you must create the hirarchy and set the parent as root node.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return Root node of the VG canvas.
 *
 * @since 1.14
 *
 * @ingroup Evas_VG
 */
EOAPI Efl_VG * evas_obj_vg_root_node_get(void);


#endif
