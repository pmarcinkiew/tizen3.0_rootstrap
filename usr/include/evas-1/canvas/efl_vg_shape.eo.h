#ifndef _EFL_VG_SHAPE_EO_H_
#define _EFL_VG_SHAPE_EO_H_

#ifndef _EFL_VG_SHAPE_EO_CLASS_TYPE
#define _EFL_VG_SHAPE_EO_CLASS_TYPE

typedef Eo Efl_VG_Shape;

#endif

#ifndef _EFL_VG_SHAPE_EO_TYPES
#define _EFL_VG_SHAPE_EO_TYPES


#endif
#define EFL_VG_SHAPE_CLASS efl_vg_shape_class_get()

EAPI const Eo_Class *efl_vg_shape_class_get(void) EINA_CONST;

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] f
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI void  efl_vg_shape_fill_set(Efl_VG *f);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI Efl_VG * efl_vg_shape_fill_get(void);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] f
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI void  efl_vg_shape_stroke_fill_set(Efl_VG *f);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI Efl_VG * efl_vg_shape_stroke_fill_get(void);

/**
 * @brief @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] m
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI void  efl_vg_shape_stroke_marker_set(Efl_VG *m);

/** @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Efl_VG_Shape
 */
EOAPI Efl_VG * efl_vg_shape_stroke_marker_get(void);


#endif
