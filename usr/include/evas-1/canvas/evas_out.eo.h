#ifndef _EVAS_OUT_EO_H_
#define _EVAS_OUT_EO_H_

#ifndef _EVAS_OUT_EO_CLASS_TYPE
#define _EVAS_OUT_EO_CLASS_TYPE

typedef Eo Evas_Out;

#endif

#ifndef _EVAS_OUT_EO_TYPES
#define _EVAS_OUT_EO_TYPES


#endif
#define EVAS_OUT_CLASS evas_out_class_get()

EAPI const Eo_Class *evas_out_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Sets the viewport region of the canvas that the
 * output displays.
 *
 * This sets both the viewport region in the canvas that displays on the given
 * output, but also the viewport size will match the  output resolution 1:1.
 *
 * @param[in] x
 * @param[in] y
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Evas_Out
 */
EOAPI void  evas_out_view_set(Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Gets the viewport region of the canvas that the output displays.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] x
 * @param[out] y
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Evas_Out
 */
EOAPI void  evas_out_view_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @internal
 *
 * @brief Sets the engine specific output parameters for a
 * given output.
 *
 * @param[in] info The engine parameters.
 *
 * @ingroup Evas_Out
 */
EOAPI Eina_Bool  evas_out_engine_info_set(Evas_Engine_Info *info);

/**
 * @internal
 *
 * @brief Gets the engine specific output parameters for a
 * given output.
 *
 * @return The engine parameters.
 *
 * @ingroup Evas_Out
 */
EOAPI Evas_Engine_Info * evas_out_engine_info_get(void);


#endif
