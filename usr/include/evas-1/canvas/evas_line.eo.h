#ifndef _EVAS_LINE_EO_H_
#define _EVAS_LINE_EO_H_

#ifndef _EVAS_LINE_EO_CLASS_TYPE
#define _EVAS_LINE_EO_CLASS_TYPE

typedef Eo Evas_Line;

#endif

#ifndef _EVAS_LINE_EO_TYPES
#define _EVAS_LINE_EO_TYPES


#endif
#define EVAS_LINE_CLASS evas_line_class_get()

EAPI const Eo_Class *evas_line_class_get(void) EINA_CONST;

/**
 * @brief Sets the coordinates of the end points of the given evas line object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] x1 The X coordinate of the first point.
 * @param[in] y1 The Y coordinate of the first point.
 * @param[in] x2 The X coordinate of the second point.
 * @param[in] y2 The Y coordinate of the second point.
 *
 * @since 1.8
 *
 * @ingroup Evas_Line
 */
EOAPI void  evas_obj_line_xy_set(Evas_Coord x1, Evas_Coord y1, Evas_Coord x2, Evas_Coord y2);

/**
 * @brief Retrieves the coordinates of the end points of the given evas line
 * object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x1 The X coordinate of the first point.
 * @param[out] y1 The Y coordinate of the first point.
 * @param[out] x2 The X coordinate of the second point.
 * @param[out] y2 The Y coordinate of the second point.
 *
 * @ingroup Evas_Line
 */
EOAPI void  evas_obj_line_xy_get(Evas_Coord *x1, Evas_Coord *y1, Evas_Coord *x2, Evas_Coord *y2);


#endif
