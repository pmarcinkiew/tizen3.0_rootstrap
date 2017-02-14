#ifndef _EFL_VG_BASE_EO_LEGACY_H_
#define _EFL_VG_BASE_EO_LEGACY_H_

#ifndef _EFL_VG_BASE_EO_CLASS_TYPE
#define _EFL_VG_BASE_EO_CLASS_TYPE

typedef Eo Efl_VG_Base;

#endif

#ifndef _EFL_VG_BASE_EO_TYPES
#define _EFL_VG_BASE_EO_TYPES


#endif

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
EAPI void evas_vg_node_bounds_get(Efl_VG_Base *obj, Eina_Rectangle *r);

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
EAPI void evas_vg_node_name_set(Efl_VG_Base *obj, const char *name);

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
EAPI const char *evas_vg_node_name_get(const Efl_VG_Base *obj);

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
EAPI void evas_vg_node_transformation_set(Efl_VG_Base *obj, const Eina_Matrix3 *m);

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
EAPI const Eina_Matrix3 *evas_vg_node_transformation_get(const Efl_VG_Base *obj);

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
EAPI void evas_vg_node_origin_set(Efl_VG_Base *obj, double x, double y);

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
EAPI void evas_vg_node_origin_get(const Efl_VG_Base *obj, double *x, double *y);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] m
 *
 * @ingroup Efl_VG_Base
 */
EAPI void evas_vg_node_mask_set(Efl_VG_Base *obj, Efl_VG *m);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Base
 */
EAPI Efl_VG *evas_vg_node_mask_get(const Efl_VG_Base *obj);
EAPI Eina_Bool evas_vg_node_interpolate(Efl_VG_Base *obj, const Efl_VG_Base *from, const Efl_VG_Base *to, double pos_map);
EAPI void evas_vg_node_dup(Efl_VG_Base *obj, const Efl_VG_Base *from);

#endif
