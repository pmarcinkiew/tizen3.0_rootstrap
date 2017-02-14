#ifndef _EVAS_POLYGON_EO_H_
#define _EVAS_POLYGON_EO_H_

#ifndef _EVAS_POLYGON_EO_CLASS_TYPE
#define _EVAS_POLYGON_EO_CLASS_TYPE

typedef Eo Evas_Polygon;

#endif

#ifndef _EVAS_POLYGON_EO_TYPES
#define _EVAS_POLYGON_EO_TYPES


#endif
#define EVAS_POLYGON_CLASS evas_polygon_class_get()

EAPI const Eo_Class *evas_polygon_class_get(void) EINA_CONST;

/**
 * @brief Adds the given point to the given evas polygon object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y The Y coordinate of the given point.
 *
 * @ingroup Evas_Polygon
 */
EOAPI void  evas_obj_polygon_point_add(Evas_Coord x, Evas_Coord y);

/**
 * @brief Removes all of the points from the given evas polygon object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Polygon
 */
EOAPI void  evas_obj_polygon_points_clear(void);


#endif
