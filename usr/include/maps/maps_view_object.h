/* Copyright (c) 2010-2014 Samsung Electronics Co., Ltd. All rights reserved.
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef __MAPS_VIEW_OBJECT_H__
#define __MAPS_VIEW_OBJECT_H__

#include <Evas.h>
#include <maps_coordinates.h>

/**
 * @ingroup CAPI_MAPS_VIEW_MODULE
 * @defgroup CAPI_MAPS_VIEW_OBJECT_MODULE View Object
 * @addtogroup CAPI_MAPS_VIEW_OBJECT_MODULE
 * @{
 * @file maps_view_object.h
 * @brief This file contains the functions of Map Object API.
 * @brief This provides APIs related to operations, used in View Object.
 * @details Supported Object types are following:
 *          * Markers
 *          * Polygons
 *          * Polylines
 *          * Group Objects
 *          .
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The View Object handle.
 * @details The handle of an arbitrary visual object instance.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The handle may be issued with one of following functions:
 *          * maps_view_object_create_marker()
 *          * maps_view_object_create_polygon()
 *          * maps_view_object_create_polyline()\n
 *          To release the handle, use maps_view_object_destroy().\n
 *          Note that when the object is added to View, it will be released automatically when the View is destroyed.
 * @see maps_view_object_destroy()
 * @see maps_view_add_object()
 */
typedef void *maps_view_object_h;


/**
 * @brief Enumeration for visual object types.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 */
typedef enum _maps_view_object_type_e {
	MAPS_VIEW_OBJECT_POLYLINE, /**< Indicates the polyline */
	MAPS_VIEW_OBJECT_POLYGON, /**< Indicates the polygon */
	MAPS_VIEW_OBJECT_MARKER, /**< Indicates the marker */
	MAPS_VIEW_OBJECT_OVERLAY, /**< Indicates the overlay */
} maps_view_object_type_e;


/**
 * @brief Enumeration for map marker types.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 */
typedef enum _maps_view_marker_type_e {
	MAPS_VIEW_MARKER_PIN, /**< Indicates the pin marker type */
	MAPS_VIEW_MARKER_STICKER, /**< Indicates the sticker marker type */
} maps_view_marker_type_e;


/**
 * @brief Enumeration for overlay types.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 */
typedef enum _maps_view_overlay_type_e {
	MAPS_VIEW_OVERLAY_NORMAL, /**< Indicates the normal type */
	MAPS_VIEW_OVERLAY_BUBBLE, /**< Indicates the bubble type */
	MAPS_VIEW_OVERLAY_BOX, /**< Indicates the box type */
} maps_view_overlay_type_e;


/**
 * @brief Called when requesting the list of points of polyline.
 * @details This callback is invoked while iterating through the list of points, added to the polyline.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a point must be released using maps_coordinates_destroy().\n
 *          To use @a point outside this function, clone it with maps_coordinates_clone().
 * @param[in] index The current index of path point
 * @param[in] total The total amount of path points
 * @param[in] point The point
 * @param[in] user_data The user data pointer passed from maps_view_object_polyline_foreach_point()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_view_object_polyline_foreach_point() will invoke this callback.
 * @see maps_view_object_polyline_foreach_point()
 * @see #maps_coordinates_h
 */
typedef bool(*maps_view_object_polyline_point_cb) (int index, int total, maps_coordinates_h point, void *user_data);


/**
 * @brief Called when requesting the list of points of polygon.
 * @details This callback is invoked while iterating through the list of points, added to the polygon.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a point must be released using maps_coordinates_destroy().\n
 *          To use @a point outside this function, clone it with maps_coordinates_clone().
 * @param[in] index The current index of path point
 * @param[in] total The total amount of path points
 * @param[in] point The point
 * @param[in] user_data The user data pointer passed from maps_view_object_polygon_foreach_point()
 * @return @c true to continue with the next iteration of the loop,\n
 *          @c false to break out of the loop
 * @pre maps_view_object_polygon_foreach_point() will invoke this callback.
 * @see maps_view_object_polygon_foreach_point()
 * @see #maps_coordinates_h
 */
typedef bool(*maps_view_object_polygon_point_cb) (int index, int total, maps_coordinates_h point, void *user_data);


/*----------------------------------------------------------------------------*/
/*
 * Common Visual Object Features
 */


/**
 * @brief Creates a marker visual object.
 * @details This function creates a marker on a given geographical coordinates.
 *          The marker is specified with a given image file and a type.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a marker can be released by using maps_view_object_destroy().\n
 *          If added to the View using maps_view_add_object(), @a marker will be released automatically when the View is destroyed.\n
 *         http://tizen.org/privilege/mediastorage is needed if input or output path are relevant to media storage.\n
 *         http://tizen.org/privilege/externalstorage is needed if input or output path are relevant to external storage.
 * @param[in] coordinates The geographical coordinates to add marker on
 * @param[in] image_file_path The file name with the image for the marker
 * @param[in] type The type of the marker, one of listed in maps_view_marker_type_e
 * @param[out] marker The handle of newly created marker
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using map_coordinates_create().
 * @see #maps_view_object_h
 * @see #maps_view_marker_type_e
 * @see maps_view_object_create_polygon()
 * @see maps_view_object_create_polyline()
 * @see maps_view_add_object()
 * @see maps_view_object_destroy()
 * @see #maps_coordinates_h
 */
int maps_view_object_create_marker(maps_coordinates_h coordinates, const char *image_file_path, maps_view_marker_type_e type, maps_view_object_h *marker);


/**
 * @brief Creates a polyline visual object.
 * @details This function creates a polyline visual object, specified with a list of geographical coordinates, line, width, and color.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a polyline can be released by using maps_view_object_destroy().\n
 *          If added to the View using maps_view_add_object(), @a polyline will be released automatically when the View is destroyed.
 * @param[in] coordinates The list of geographical coordinates
 * @param[in] r The red component of polyline color [0 ~ 255]
 * @param[in] g The green component of polyline color [0 ~ 255]
 * @param[in] b The blue component of polyline color [0 ~ 255]
 * @param[in] a The alpha component of polyline color [0 ~ 255]
 * @param[in] width The width of line [1 ~ 100] (pixels)
 * @param[out] polyline The handle of newly added polyline
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates is created using maps_coordinates_list_create().
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polygon()
 * @see maps_view_add_object()
 * @see maps_view_object_destroy()
 * @see #maps_coordinates_list_h
 * @see maps_coordinates_list_create()
 */
int maps_view_object_create_polyline(maps_coordinates_list_h coordinates, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int width, maps_view_object_h *polyline);


/**
 * @brief Creates a polygon visual object.
 * @details This function creates a polygon visual object, specified with a list of geographical coordinates and fill color.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a polygon can be released by using maps_view_object_destroy().\n
 *          If added to the View using maps_view_add_object(), @a polygon will be released automatically when the View is destroyed.
 * @param[in] coordinates The list of geographical coordinates
 * @param[in] r The red component of polygon background color [0 ~ 255]
 * @param[in] g The green component of polygon background color [0 ~ 255]
 * @param[in] b The blue component of polygon background color [0 ~ 255]
 * @param[in] a The alpha component of polygon background color [0 ~ 255]
 * @param[out] polygon The handle of newly created polygon
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates is created using maps_coordinates_list_create().
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polyline()
 * @see maps_view_add_object()
 * @see maps_view_object_destroy()
 * @see #maps_coordinates_list_h
 * @see maps_coordinates_list_create()
 */
int maps_view_object_create_polygon(maps_coordinates_list_h coordinates, unsigned char r, unsigned char g, unsigned char b, unsigned char a, maps_view_object_h *polygon);


/**
 * @brief Creates an overlay object.
 * @details This function creates an overlay object to contain Evas objects.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a overlay can be released by using maps_view_object_destroy().\n
 *          If added to the View using maps_view_add_object(), @a overlay will be released automatically when the View is destroyed.
 * @param[in] coordinates The list of geographical coordinates
 * @param[in] object The Evas object to be contained
 * @param[in] type The type of boxing the @a object
 * @param[out] overlay The handle of newly created polygon
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates is created using maps_coordinates_list_create().
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polyline()
 * @see maps_view_object_create_polygon()
 * @see maps_view_add_object()
 * @see maps_view_object_destroy()
 * @see #maps_coordinates_h
 * @see maps_coordinates_create()
 */
int maps_view_object_create_overlay(maps_coordinates_h coordinates, Evas_Object *object, maps_view_overlay_type_e type, maps_view_object_h *overlay);


/**
 * @brief Destroys the object.
 * @details This function destroys the object handle and releases all its resources.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] object The object handle to destroy
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polygon()
 * @see maps_view_object_create_polyline()
 */
int maps_view_object_destroy(maps_view_object_h object);


/**
 * @brief Gets the object type.
 * @details This function gets the object type.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] object The object handle
 * @param[out] type The pointer to #maps_view_object_type_e in which to store the object type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a object is created using maps_view_object_create_marker(),
 *      maps_view_object_create_polyline() or maps_view_object_create_polygon().
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polyline()
 * @see maps_view_object_create_polygon()
 */
int maps_view_object_get_type(maps_view_object_h object, maps_view_object_type_e *type);


/**
 * @brief Shows the object.
 * @details This function changes the visibility of the given object on the View.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] object The object handle
 * @param[in] visible The new visibility of the object
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a object is created using maps_view_object_create_marker(),
 *      maps_view_object_create_polyline(), maps_view_object_create_polygon().
 * @see #maps_view_object_h
 * @see maps_view_object_get_visible()
 */
int maps_view_object_set_visible(maps_view_object_h object, bool visible);


/**
 * @brief Gets the object visibility.
 * @details This function retrieves whether or not the given object is visible.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] object The object handle
 * @param[out] visible The pointer to a boolean in which to store the object visibility
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a object is created using maps_view_object_create_marker(),
 *      maps_view_object_create_polyline(), maps_view_object_create_polygon().
 * @see #maps_view_object_h
 * @see maps_view_object_set_visible()
 */
int maps_view_object_get_visible(const maps_view_object_h object, bool *visible);


/*----------------------------------------------------------------------------*/
/*
 * Polyline
 */

/**
 * @brief Sets points to the polyline.
 * @details This function sets point list to the polyline.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polyline The polyline object handle
 * @param[in] points The points to set
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @pre @a points are created using maps_coordinates_list_create().
 * @post Previous points will be destroyed automatically.
 * @see #maps_view_object_h
 * @see #maps_coordinates_list_h
 * @see maps_coordinates_list_create()
 * @see maps_view_object_create_polyline()
 * @see maps_view_object_polyline_foreach_point()
 */
int maps_view_object_polyline_set_polyline(maps_view_object_h polyline, maps_coordinates_list_h points);


/**
 * @brief Retrieves all points, added to the polyline.
 * @details This function retrieves all points, added to the polyline.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The points will be delivered via maps_view_object_polyline_point_cb().
 * @param[in] polyline The polyline object handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data pointer to be passed to the callback function
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @post This function invokes maps_view_object_polyline_point_cb() repeatedly to retrieve each point.
 * @see #maps_view_object_h
 * @see maps_view_object_create_polyline()
 * @see maps_view_object_polyline_set_polyline()
 * @see maps_view_object_polyline_point_cb()
 */
int maps_view_object_polyline_foreach_point(maps_view_object_h polyline, maps_coordinates_cb callback, void *user_data);


/**
 * @brief Sets the polyline color.
 * @details This function sets the polyline color on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polyline The polyline object handle
 * @param[in] r The red component of the color
 * @param[in] g The green component of the color
 * @param[in] b The blue component of the color
 * @param[in] a The alpha component of the color
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @see maps_view_object_polyline_get_color()
 * @see maps_view_object_polyline_set_width()
 * @see maps_view_object_create_polyline()
 */
int maps_view_object_polyline_set_color(maps_view_object_h polyline, unsigned char r, unsigned char g, unsigned char b, unsigned char a);


/**
 * @brief Gets the polyline color.
 * @details This function gets the polyline color on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polyline The polyline object handle
 * @param[out] r The unsigned char pointer in which to store the red component of the color,
 *               or NULL if not interested
 * @param[out] g The unsigned char pointer in which to store the green component of the color,
 *               or NULL if not interested
 * @param[out] b The unsigned char pointer in which to store the blue component of the color,
 *               or NULL if not interested
 * @param[out] a The unsigned char pointer in which to store the alpha component of the color,
 *               or NULL if not interested
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @pre color components may be previously set using maps_view_object_polyline_set_color().
 * @see maps_view_object_polyline_set_color()
 * @see maps_view_object_polyline_get_width()
 * @see maps_view_object_create_polyline()
 */
int maps_view_object_polyline_get_color(const maps_view_object_h polyline, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a);


/**
 * @brief Sets the polyline width.
 * @details This function sets the polyline width on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polyline The polyline object handle
 * @param[in] width The new width of line [1 ~ 100] (pixels)
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @see maps_view_object_polyline_get_width()
 * @see maps_view_object_polyline_set_color()
 * @see maps_view_object_create_polyline()
 */
int maps_view_object_polyline_set_width(maps_view_object_h polyline, int width);


/**
 * @brief Gets the polyline width.
 * @details This function gets the polyline width on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polyline The polyline object handle
 * @param[out] width The width of line [1 ~ 100] (pixels)
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polyline is created using maps_view_object_create_polyline().
 * @pre @a width may be previously set using maps_view_object_polyline_set_width().
 * @see maps_view_object_polyline_set_width()
 * @see maps_view_object_polyline_get_color()
 * @see maps_view_object_create_polyline()
 */
int maps_view_object_polyline_get_width(const maps_view_object_h polyline, int *width);


/*----------------------------------------------------------------------------*/
/*
 * Polygon
 */


/**
 * @brief Sets points to the polygon.
 * @details This function sets point list to the polygon.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polygon The polygon object handle
 * @param[in] points The points to set
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polygon is created using maps_view_object_create_polygon().
 * @pre @a points are created using maps_coordinates_list_create().
 * @see maps_view_object_create_polygon()
 * @see #maps_view_object_h
 * @see #maps_coordinates_list_h
 * @see maps_coordinates_list_create()
 * @see maps_view_object_polygon_foreach_point()
 */
int maps_view_object_polygon_set_polygon(maps_view_object_h polygon, maps_coordinates_list_h points);


/**
 * @brief Retrieves all points, added to the polygon.
 * @details This function retrieves all points, added to the polygon.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The objects will be delivered via maps_view_object_polygon_point_cb().
 * @param[in] polygon The polygon object handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polygon is created using maps_view_object_create_polygon().
 * @post This function invokes maps_view_object_polygon_point_cb() repeatedly to retrieve each point.
 * @see maps_view_object_polygon_point_cb()
 * @see maps_view_object_create_polygon()
 * @see #maps_view_object_h
 * @see maps_view_object_polygon_set_polygon()
 */
int maps_view_object_polygon_foreach_point(maps_view_object_h polygon, maps_coordinates_cb callback, void *user_data);


/**
 * @brief Sets polygon fill color.
 * @details This function sets the polygon fill color on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polygon The polygon object handle
 * @param[in] r The red component of the fill color
 * @param[in] g The green component of the fill color
 * @param[in] b The blue component of the fill color
 * @param[in] a The alpha component of the fill color
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polygon is created using maps_view_object_create_polygon().
 * @see maps_view_object_polygon_get_fill_color()
 * @see maps_view_object_create_polygon()
 */
int maps_view_object_polygon_set_fill_color(maps_view_object_h polygon, unsigned char r, unsigned char g, unsigned char b, unsigned char a);


/**
 * @brief Gets polygon fill color.
 * @details This function gets the polygon fill color on canvas.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] polygon The polygon data handle
 * @param[in] r The unsigned char pointer in which to store the red component of the background color
 * @param[in] g The unsigned char pointer in which to store the green component of the background color
 * @param[in] b The unsigned char pointer in which to store the blue component of the background color
 * @param[in] a The unsigned char pointer in which to store the alpha component of the background color
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a polygon is created using maps_view_object_create_polygon().
 * @pre Fill color components may be previously set using maps_view_object_polygon_set_fill_color().
 * @see maps_view_object_polygon_set_fill_color()
 * @see maps_view_object_create_polygon()
 */
int maps_view_object_polygon_get_fill_color(const maps_view_object_h polygon, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a);


/*----------------------------------------------------------------------------*/
/*
 * Marker
 */


/**
 * @brief Sets the marker coordinates.
 * @details This function sets the marker geographical coordinates.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] marker The marker object handle
 * @param[in] coordinates The marker geographical coordinates handle
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_view_object_create_marker()
 * @see maps_view_object_marker_get_coordinates()
 * @see #maps_coordinates_h
 * @see maps_coordinates_create()
 */
int maps_view_object_marker_set_coordinates(maps_view_object_h marker, maps_coordinates_h coordinates);


/**
 * @brief Sets the marker screen size.
 * @details This function sets the marker screen size.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] marker The marker object handle
 * @param[in] width The marker pixels in width on the screen
 * @param[in] height The marker pixels in height on the screen
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @see maps_view_object_create_marker()
 * @see maps_view_object_marker_get_size()
 */
int maps_view_object_marker_resize(maps_view_object_h marker, int width, int height);


/**
 * @brief Sets the marker image file path.
 * @details This function sets the marker image file path.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks http://tizen.org/privilege/mediastorage is needed if input or output path are relevant to media storage.\n
 *          http://tizen.org/privilege/externalstorage is needed if input or output path are relevant to external storage.
 * @param[in] marker The marker object handle
 * @param[in] file_path The marker image file path
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @see maps_view_object_marker_get_image_file()
 * @see maps_view_object_create_marker()
 */
int maps_view_object_marker_set_image_file(maps_view_object_h marker, const char *file_path);


/**
 * @brief Gets the marker image file path.
 * @details This function gets the marker image file path.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a file_path should be freed using free().
 * @param[in] marker The marker object handle
 * @param[out] file_path The marker image file path
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @pre @a file_path may be set previously using maps_view_object_marker_set_image_file().
 * @see maps_view_object_marker_set_image_file()
 * @see maps_view_object_create_marker()
 */
int maps_view_object_marker_get_image_file(const maps_view_object_h marker, char **file_path);


/**
 * @brief Gets the marker coordinates.
 * @details This function gets the marker geographical coordinates.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a coordinates should be freed using maps_coordinates_destroy().
 * @param[in] marker The marker object handle
 * @param[out] coordinates The pointer to #maps_coordinates_h in which to store the marker geographical coordinates
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @pre @a coordinates may be set previously using maps_view_object_marker_set_coordinates().
 * @see maps_view_object_marker_set_coordinates()
 * @see #maps_coordinates_h
 * @see maps_view_object_create_marker()
 */
int maps_view_object_marker_get_coordinates(const maps_view_object_h marker, maps_coordinates_h *coordinates);


/**
 * @brief Gets the marker screen size.
 * @details This function gets the marker size on the screen.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] marker The marker object handle
 * @param[out] width The pointer to an integer in which to store the marker width on the screen in pixels
 * @param[out] height The pointer to an integer in which to store the marker height on the screen in pixels
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @pre @a width and @a height may be set previously using maps_view_object_marker_resize().
 * @see maps_view_object_marker_resize()
 * @see maps_view_object_create_marker()
 */
int maps_view_object_marker_get_size(const maps_view_object_h marker, int *width, int *height);


/**
 * @brief Gets the marker type.
 * @details This function gets the marker type.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] marker The marker object handle
 * @param[out] type The pointer to a maps_view_marker_type_e in which to store the marker type
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @see #maps_view_marker_type_e
 * @see maps_view_object_create_marker()
 */
int maps_view_object_marker_get_type(const maps_view_object_h marker, maps_view_marker_type_e *type);


/**
 * @brief Sets the marker z-order.
 * @details This function sets the z-order.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a z_order must be in range of [-100, 100].
 * @param[in] marker The marker object handle
 * @param[in] z_order The z-order
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @see maps_view_object_create_marker()
 * @see maps_view_object_marker_get_z_order()
 */
int maps_view_object_marker_set_z_order(maps_view_object_h marker, int z_order);


/**
 * @brief Gets the marker z-order.
 * @details This function gets the z-order.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] marker The marker object handle
 * @param[out] z_order The z-order
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_marker().
 * @see maps_view_object_create_marker()
 * @see maps_view_object_marker_set_z_order()
 */
int maps_view_object_marker_get_z_order(const maps_view_object_h marker, int *z_order);



/*----------------------------------------------------------------------------*/
/*
 * Overlay
 */


/**
 * @brief Gets the Evas object.
 * @details This function gets the Evas object.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a object must not be released.
 * @param[in] overlay The overlay object handle
 * @param[out] object The Evas object handle
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a marker is created using maps_view_object_create_overlay().
 * @see maps_view_object_create_overlay()
 */
int maps_view_object_overlay_get_object(maps_view_object_h overlay, Evas_Object **object);


/**
 * @brief Sets the overlay coordinates.
 * @details This function sets the overlay geographical coordinates.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] overlay The overlay object handle
 * @param[in] coordinates The overlay geographical coordinates handle
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_get_coordinates()
 * @see #maps_coordinates_h
 * @see maps_coordinates_create()
 */
int maps_view_object_overlay_set_coordinates(maps_view_object_h overlay, maps_coordinates_h coordinates);


/**
 * @brief Gets the overlay coordinates.
 * @details This function gets the overlay geographical coordinates.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a coordinates should be freed using maps_coordinates_destroy().
 * @param[in] overlay The overlay object handle
 * @param[out] coordinates The pointer to #maps_coordinates_h in which to store the overlay geographical coordinates
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @pre @a coordinates may be set previously using maps_view_object_overlay_set_coordinates().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_set_coordinates()
 * @see #maps_coordinates_h
 * @see maps_coordinates_destroy()
 */
int maps_view_object_overlay_get_coordinates(const maps_view_object_h overlay, maps_coordinates_h *coordinates);


/**
 * @brief Sets the minimal zoom level for overlay.
 * @details This function sets the minimally allowed zoom level of the map to show the overlay.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] overlay The overlay object handle
 * @param[in] zoom The new minimal zoom level
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_get_min_zoom_level()
 * @see maps_view_object_overlay_set_max_zoom_level()
 * @see maps_view_object_overlay_get_max_zoom_level()
 */
int maps_view_object_overlay_set_min_zoom_level(maps_view_object_h overlay, int zoom);


/**
 * @brief Gets the minimal zoom level for overlay.
 * @details This function gets the minimally allowed zoom level of the map to show the overlay.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] overlay The overlay object handle
 * @param[out] zoom The pointer to an integer in which to store the minimally allowed zoom level.
 * @return @c 0,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_set_min_zoom_level()
 * @see maps_view_object_overlay_set_max_zoom_level()
 * @see maps_view_object_overlay_get_max_zoom_level()
 */
int maps_view_object_overlay_get_min_zoom_level(const maps_view_object_h overlay, int *zoom);


/**
 * @brief Sets the minimal zoom level for overlay.
 * @details This function sets the minimally allowed zoom level of the map to show the overlay.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] overlay The overlay object handle
 * @param[in] zoom The new minimal zoom level
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_get_min_zoom_level()
 * @see maps_view_object_overlay_set_min_zoom_level()
 * @see maps_view_object_overlay_get_max_zoom_level()
 */
int maps_view_object_overlay_set_max_zoom_level(maps_view_object_h overlay, int zoom);


/**
 * @brief Gets the minimal zoom level for overlay.
 * @details This function gets the minimally allowed zoom level of the map to show the overlay.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] overlay The overlay object handle
 * @param[out] zoom The pointer to an integer in which to store the minimally allowed zoom level
 * @return @c 0,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a overlay is created using maps_view_object_create_overlay().
 * @see maps_view_object_create_overlay()
 * @see maps_view_object_overlay_get_min_zoom_level()
 * @see maps_view_object_overlay_set_min_zoom_level()
 * @see maps_view_object_overlay_set_max_zoom_level()
 */
int maps_view_object_overlay_get_max_zoom_level(const maps_view_object_h overlay, int *zoom);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_VIEW_OBJECT_H__ */
