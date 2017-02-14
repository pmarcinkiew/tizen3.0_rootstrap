#ifndef _EFL_VG_SHAPE_EO_LEGACY_H_
#define _EFL_VG_SHAPE_EO_LEGACY_H_

#ifndef _EFL_VG_SHAPE_EO_CLASS_TYPE
#define _EFL_VG_SHAPE_EO_CLASS_TYPE

typedef Eo Efl_VG_Shape;

#endif

#ifndef _EFL_VG_SHAPE_EO_TYPES
#define _EFL_VG_SHAPE_EO_TYPES


#endif

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] f
 *
 * @ingroup Efl_VG_Shape
 */
EAPI void evas_vg_shape_fill_set(Efl_VG_Shape *obj, Efl_VG *f);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EAPI Efl_VG *evas_vg_shape_fill_get(const Efl_VG_Shape *obj);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] f
 *
 * @ingroup Efl_VG_Shape
 */
EAPI void evas_vg_shape_stroke_fill_set(Efl_VG_Shape *obj, Efl_VG *f);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EAPI Efl_VG *evas_vg_shape_stroke_fill_get(const Efl_VG_Shape *obj);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] m
 *
 * @ingroup Efl_VG_Shape
 */
EAPI void evas_vg_shape_stroke_marker_set(Efl_VG_Shape *obj, Efl_VG *m);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EAPI Efl_VG *evas_vg_shape_stroke_marker_get(const Efl_VG_Shape *obj);

#endif
