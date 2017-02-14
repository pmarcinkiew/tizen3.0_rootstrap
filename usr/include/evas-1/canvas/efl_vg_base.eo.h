#ifndef _EFL_VG_BASE_EO_H_
#define _EFL_VG_BASE_EO_H_

#ifndef _EFL_VG_BASE_EO_CLASS_TYPE
#define _EFL_VG_BASE_EO_CLASS_TYPE

typedef Eo Efl_VG_Base;

#endif

#ifndef _EFL_VG_BASE_EO_TYPES
#define _EFL_VG_BASE_EO_TYPES


#endif
#define EFL_VG_BASE_CLASS efl_vg_base_class_get()

EAPI const Eo_Class *efl_vg_base_class_get(void) EINA_CONST;

/**
 * @brief Give the bounding box in screen coordinate as being drawn.
 *
 * It will start as the control box until it is refined once the shape is
 * computed.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] r bounding box to be returned.
 *
 * @since 1.14
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_bounds_get(Eina_Rectangle *r);

/**
 * @brief Set an unique name from the parent point of view. @c null means no
 * name.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] name
 *
 * @since 1.16
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_name_set(const char *name);

/**
 * @brief Get an unique name from the parent point of view.
 *
 * @c null means no name. When set a parent after the name what defined, it
 * might be forced back to @c null if the parent already has a node of that
 * name.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @since 1.16
 *
 * @ingroup Efl_VG_Base
 */
EOAPI const char * efl_vg_name_get(void);

/**
 * @brief Sets the transformation matrix to be used for this node object.
 *
 * @note Pass @c null to cancel the applied transformation.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] m transformation matrix.
 *
 * @since 1.14
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_transformation_set(const Eina_Matrix3 *m);

/**
 * @brief Gets the transformation matrix used for this node object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return transformation matrix.
 *
 * @since 1.14
 *
 * @ingroup Efl_VG_Base
 */
EOAPI const Eina_Matrix3 * efl_vg_transformation_get(void);

/**
 * @brief Sets the origin position of this node object.
 *
 * This origin position affects to node transformation.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] x @c origin x position.
 * @param[in] y @c origin y position.
 *
 * @since 1.14
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_origin_set(double x, double y);

/**
 * @brief Gets the origin position of this node object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] x @c origin x position.
 * @param[out] y @c origin y position.
 *
 * @since 1.14
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_origin_get(double *x, double *y);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] m
 *
 * @ingroup Efl_VG_Base
 */
EOAPI void  efl_vg_mask_set(Efl_VG *m);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Base
 */
EOAPI Efl_VG * efl_vg_mask_get(void);

EOAPI Eina_Bool  efl_vg_interpolate(const Efl_VG_Base *from, const Efl_VG_Base *to, double pos_map);

EOAPI void  efl_vg_dup(const Efl_VG_Base *from);


#endif
