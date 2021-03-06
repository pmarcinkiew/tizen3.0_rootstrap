/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
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

#ifndef __MAPS_VIEW_H__
#define __MAPS_VIEW_H__

#include <Evas.h>
#include <maps_types.h>
#include <maps_view_event_data.h>
#include <maps_view_snapshot.h>

/**
 *
 * @ingroup CAPI_MAPS_SERVICE_MODULE
 * @defgroup CAPI_MAPS_VIEW_MODULE View
 * @addtogroup CAPI_MAPS_VIEW_MODULE
 * @{
 * @file maps_view.h
 * @if WEARABLE
 * @section CAPI_MAPS_SERVICE_MODULE_FEATURE Related Features
 * This API is related with the following features:\n
 *  - http://tizen.org/feature/network.internet\n
 * It is recommended to design feature related codes in your application for reliability.\n
 * You can check if a device supports the related features for this API by using
 * @ref CAPI_SYSTEM_SYSTEM_INFO_MODULE, thereby controlling the procedure of your application.\n
 * To ensure your application is only running on the device with specific features,
 * please define the features in your manifest file using the manifest editor in the SDK.\n
 * More details on featuring your application can be found from
 * <a href="https://developer.tizen.org/development/getting-started/native-application/understanding-tizen-programming/application-filtering"><b>Feature List</b>.</a>
 * @endif
 * @brief This file contains the top level functions of View API.
 * @brief This provides APIs related to operations, used in View.
 * @details Supported View API features include:
 *          * Creating and destroying the View port, moving and resizing it
 *          * Changing zoom, and orientation
 *          * Changing properties: theme (day, satellite, terrain),
 *            language (English, Russian, Chinese, Italian, German, Spanish, etc.)
 *          * Converting screen coordinates to geographical and vise versa
 *          * Managing user's gestures: receiving user's gesture events, enabling or
 *            disabling specified user gestures, assigning View actions, which must be
 *            taken in response on user gestures.
 */


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Enumeration for View types (themes).
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 */
typedef enum _maps_view_type_e {
	MAPS_VIEW_TYPE_NORMAL, /**< Indicates the normal street theme */
	MAPS_VIEW_TYPE_SATELLITE, /**< Indicates the satellite theme */
	MAPS_VIEW_TYPE_TERRAIN, /**< Indicates the terrain theme */
	MAPS_VIEW_TYPE_HYBRID, /**< Indicates the hybrid theme, which is the satellite and normal street theme */
} maps_view_type_e;


/**
 * @brief Called when requesting the list of visual objects of the View.
 * @details This callback is invoked while iterating through the list of visual objects added to the View.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] index The current index of the visual object starts from 0
 * @param[in] total The total amount of visual objects
 * @param[in] object The visual object
 * @param[in] user_data The user data pointer passed from maps_view_foreach_object()
 * @return @c true to continue with the next iteration of the loop, \n
 *         @c false to break out of the loop
 * @pre maps_view_foreach_object() will invoke this callback.
 * @see #maps_view_object_h
 * @see maps_view_foreach_object()
 */
typedef bool(*maps_view_object_cb) (int index, int total, maps_view_object_h object, void *user_data);


/**
 * @brief Called when the View event occurs.
 * @details The View Panel invokes this callback when the map event occurs.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a event_data will be released automatically after this callback is terminated.\n
 *          To use @a event_data outside this function, clone it with maps_view_event_data_clone().
 * @param[in] type The new type of callback, listed in #maps_view_event_type_e
 * @param[in] event_data The event data
 * @param[in] user_data The user data pointer registered in maps_view_set_event_cb()
 * @pre maps_view_set_event_cb() sets the callback.
 * @pre maps_view_set_center(),
 *      maps_view_set_zoom_level(),
 *      maps_view_set_orientation(),
 *      invoke the callback with the type #MAPS_VIEW_EVENT_ACTION.
 * @see maps_view_set_event_cb()
 * @see maps_view_set_center()
 * @see maps_view_set_zoom_level()
 * @see maps_view_set_orientation()
 */
typedef void(*maps_view_on_event_cb) (maps_view_event_type_e type, maps_view_event_data_h event_data, void *user_data);

/* ----------------------CREATE AND DESTROY-----------------------------------*/


/**
 * @brief Creates the View and link it to the instance of maps service.
 * @details This function creates a new View widget, allocates all needed
 *          resources and issues its handle.\n
 *          The newly created View is linked to the specified map's service.\n
 *          The View by default is resized to fill whole parent area.\n
 *          To center the map on a specific geographical coordinates with a desired
 *          zoom level and rotation angle, use maps_view_set_center(),
 *          maps_view_set_zoom_level(), and maps_view_set_orientation() respectively.\n
 *          To change View theme, size, and visibility properties, use
 *          maps_view_set_type() and maps_view_set_visibility() respectively.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @remarks The @a View must be released using maps_view_destroy().
 * @param[in] maps The maps service handle
 * @param[in] obj The evas object to be drawn
 * @param[out] view The handle pointer to a maps_view_h, in which to store the newly created View handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a maps is created using maps_service_create().
 * @pre @a obj is recommended using a smart object.
 * @see maps_view_destroy()
 * @see maps_service_create()
 * @see maps_view_set_center()
 * @see maps_view_set_zoom_level()
 * @see maps_view_set_orientation()
 * @see maps_view_set_type()
 * @see maps_view_set_visibility()
 * @see elm_layout_add()
 */
int maps_view_create(maps_service_h maps, Evas_Object *obj, maps_view_h *view);


/**
 * @brief Destroys the View.
 * @details This function destroys the View, releases its handle and
 *          all allocated resources, unlinks the View from the instance of maps service.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @param[in] view The View handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a View is created using maps_view_create().
 * @see maps_view_create()
 */
int maps_view_destroy(maps_view_h view);


/*----------------------MAP ZOOM, ROTATE, SET CENTER--------------------------*/


/**
 * @brief Centers the map on a given geographical coordinates.
 * @details This function centers the map on a given geographical coordinates using current zoom and orientation.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] coordinates The geographical coordinates of the position to be centered on the View
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_view_get_center()
 * @see maps_view_set_zoom_level()
 * @see maps_view_set_orientation()
 * @see maps_coordinates_create()
 * @see maps_view_create()
 */
int maps_view_set_center(maps_view_h view, maps_coordinates_h coordinates);


/**
 * @brief Gets the central coordinates of a map.
 * @details This function gets the current central coordinates of a map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a coordinates must be released using maps_coordinates_destroy().
 * @param[in] view The view handle
 * @param[out] coordinates The pointer to #maps_coordinates_h in which to
 *                         store the geographical coordinates of the central position of the map
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_center()
 * @see maps_view_get_zoom_level()
 * @see maps_view_get_orientation()
 * @see maps_coordinates_destroy()
 * @see maps_view_create()
 */
int maps_view_get_center(const maps_view_h view, maps_coordinates_h *coordinates);


/**
 * @brief Sets zoom level of the map.
 * @details This function sets the integer zoom level of the map.\n
 *          If the specified zoom level exceeds the maps Provider allowed zoom range,
 *          the function returns #MAPS_ERROR_INVALID_PARAMETER error.\n
 *          To check the range of allowed zoom level, use maps_view_get_min_zoom_level()
 *          and maps_view_get_max_zoom_level().
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] level The new zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_zoom_level()
 * @see maps_view_set_orientation()
 * @see maps_view_get_min_zoom_level()
 * @see maps_view_get_max_zoom_level()
 * @see maps_view_create()
 */
int maps_view_set_zoom_level(maps_view_h view, int level);


/**
 * @brief Gets zoom level of the map.
 * @details This function gets the current integer zoom level of the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] level The pointer to an integer in which to store the current zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_zoom_level()
 * @see maps_view_get_min_zoom_level()
 * @see maps_view_get_max_zoom_level()
 * @see maps_view_create()
 */
int maps_view_get_zoom_level(const maps_view_h view, int *level);


/**
 * @brief Sets the minimal zoom level of the map.
 * @details This function sets the minimally allowed zoom level of the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @param[in] view The view handle
 * @param[out] level The new minimal zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_INVALID_OPERATION Operation is not valid
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_min_zoom_level()
 * @see maps_view_set_max_zoom_level()
 * @see maps_view_get_max_zoom_level()
 * @see maps_view_get_zoom_level()
 * @see maps_view_set_zoom_level()
 * @see maps_view_create()
 */
int maps_view_set_min_zoom_level(maps_view_h view, int level);


/**
 * @brief Gets the minimal zoom level of the map.
 * @details This function gets the minimally allowed zoom level of the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] min_zoom_level The pointer to an integer in which to store the minimally allowed zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_INVALID_OPERATION Operation is not valid
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_max_zoom_level()
 * @see maps_view_get_zoom_level()
 * @see maps_view_set_zoom_level()
 * @see maps_view_create()
 */
int maps_view_get_min_zoom_level(const maps_view_h view, int *min_zoom_level);


/**
 * @brief Sets the maximal zoom level of the map.
 * @details This function sets the maximally allowed zoom level of the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @param[in] view The view handle
 * @param[out] level The new maximal zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_INVALID_OPERATION Operation is not valid
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_min_zoom_level()
 * @see maps_view_get_min_zoom_level()
 * @see maps_view_get_max_zoom_level()
 * @see maps_view_get_zoom_level()
 * @see maps_view_set_zoom_level()
 * @see maps_view_create()
 */
int maps_view_set_max_zoom_level(maps_view_h view, int level);


/**
 * @brief Gets the maximal zoom level of the map.
 * @details This function gets the maximally allowed zoom level of the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] max_zoom_level The pointer to an integer in which to store the maximally allowed zoom level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_INVALID_OPERATION Operation is not valid
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_min_zoom_level()
 * @see maps_view_get_zoom_level()
 * @see maps_view_set_zoom_level()
 * @see maps_view_create()
 */
int maps_view_get_max_zoom_level(const maps_view_h view, int *max_zoom_level);


/**
 * @brief Sets the orientation on the View.
 * @details This function sets the rotation angle of the View.\n
 *          If the specified rotation angle exceeds the [0..360] range, the
 *          function returns #MAPS_ERROR_INVALID_PARAMETER error.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] angle The new orientation angle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_orientation()
 * @see maps_view_set_zoom_level()
 * @see maps_view_create()
 */
int maps_view_set_orientation(maps_view_h view, double angle);


/**
 * @brief Gets the orientation.
 * @details This function gets the current map rotation angle on the View.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] rotation_angle The pointer to a double in which to store the current rotation angle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_orientation()
 * @see maps_view_get_zoom_level()
 * @see maps_view_create()
 */
int maps_view_get_orientation(const maps_view_h view, double *rotation_angle);


/*----------------------SCREEN <--> GEOGRAPHY---------------------------------*/


/**
 * @brief Converts screen coordinates to the geographical coordinates.
 * @details This function converts screen coordinates to the geographical
 *          coordinates accordingly to the current map zoom and orientation.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @remarks The @a coordinates must be released using maps_coordinates_destroy().
 * @param[in] view The view handle
 * @param[in] x The x coordinate on the screen
 * @param[in] y The y coordinate on the screen
 * @param[out] coordinates The pointer to a #maps_coordinates_h in which to
 *                         store the handle of geographical coordinates,
 *                         corresponding to given screen coordinates
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_geolocation_to_screen()
 * @see #maps_coordinates_h
 * @see maps_coordinates_destroy()
 * @see maps_view_create()
 */
int maps_view_screen_to_geolocation(maps_view_h view, int x, int y, maps_coordinates_h *coordinates);


/**
 * @brief Converts geographical coordinates to the screen coordinates.
 * @details This function converts geographical coordinates to the screen
 *          coordinates accordingly to the current map zoom and orientation.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @param[in] view The view handle
 * @param[in] coordinates The geographical coordinates
 * @param[out] x The pointer to an integer in which to store the x coordinate on the screen,
 *               corresponding to given geographical coordinates
 * @param[out] y The pointer to an integer in which to store the y coordinate on the screen,
 *               corresponding to given geographical coordinates
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre @a coordinates is created using maps_coordinates_create().
 * @see maps_view_screen_to_geolocation()
 * @see #maps_coordinates_h
 * @see maps_coordinates_create()
 * @see maps_view_create()
 */
int maps_view_geolocation_to_screen(maps_view_h view, const maps_coordinates_h coordinates, int *x, int *y);


/* --------------------VIEW PREFERENCES----------------------------------*/


/**
 * @brief Sets View type.
 * @details This function switches the View to a specified type, one of
 *          listed in #maps_view_type_e enumeration.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] type The view type, one of listed in #maps_view_type_e
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see #maps_view_type_e
 * @see maps_view_get_type()
 * @see maps_view_set_language()
 * @see maps_view_create()
 */
int maps_view_set_type(maps_view_h view, maps_view_type_e type);


/**
 * @brief Gets View type.
 * @details This function gets the type of the given View.\n
 *          The type options are defined in the #maps_view_type_e enumeration.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] type The pointer to a #maps_view_type_e in which to store current view type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see #maps_view_type_e
 * @see maps_view_set_type()
 * @see maps_view_get_language()
 * @see maps_view_create()
 */
int maps_view_get_type(const maps_view_h view, maps_view_type_e *type);


/**
 * @brief Indicates whether the map should show the 3D buildings layer.
 * @details This function is called to indicate whether 3D buildings should be shown as a layer on the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @remarks To check if Maps Provider is capable of drawing 3D buildings,
 *          use maps_service_provider_is_data_supported() with
 *          #MAPS_VIEW_BUILDING passed as a service data parameter.
 * @param[in] view The view handle
 * @param[in] enable The enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_get_buildings_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_set_buildings_enabled(maps_view_h view, bool enable);


/**
 * @brief Queries whether the map has the 3D buildings layer enabled.
 * @details This function checks whether the map is set to show the 3D buildings layer.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] enable The pointer to a boolean in which to store the enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_set_buildings_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_get_buildings_enabled(const maps_view_h view, bool *enable);


/**
 * @brief Indicates whether the map should show the traffic layer.
 * @details This function is called to indicate whether traffic conditions should be shown as a layer on the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @remarks To check if Maps Provider is capable of drawing traffic conditions,
 *          use maps_service_provider_is_data_supported() with
 *          #MAPS_VIEW_TRAFFIC passed as a service data parameter.
 * @param[in] view The view handle
 * @param[in] enable The enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_get_traffic_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_set_traffic_enabled(maps_view_h view, bool enable);


/**
 * @brief Queries whether the map has the traffic layer enabled.
 * @details This function checks whether the map is set to show the traffic layer.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] enable The pointer to a boolean in which to store the enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_set_traffic_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_get_traffic_enabled(const maps_view_h view, bool *enable);


/**
 * @brief Indicates whether the map should show the public transit layer.
 * @details This function is called to indicate whether public transit routes should be shown as a layer on the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @remarks To check if Maps Provider is capable of drawing public transit routes,
 *          use maps_service_provider_is_data_supported() with
 *          #MAPS_VIEW_PUBLIC_TRANSIT passed as a service data parameter.
 * @param[in] view The view handle
 * @param[in] enable The enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_get_public_transit_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_set_public_transit_enabled(maps_view_h view, bool enable);


/**
 * @brief Queries whether the map has the public transit layer enabled.
 * @details This function checks whether the map is set to show the public transit routes layer.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] enable The pointer to a boolean in which to store the enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_set_public_transit_enabled()
 * @see maps_service_provider_is_data_supported()
 */
int maps_view_get_public_transit_enabled(const maps_view_h view, bool *enable);


/**
 * @brief Sets View language.
 * @details This function sets the language to the given View.\n
 *          Note that map display language is different from places and route language.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @remarks If specific language wasn't set explicitly or map tile doesn't
 *          support the requested language, the default language of your Maps Provider is used.\n
 *          In general, Map Provider set the default language as the mother tongue of the country or English.
 * @param[in] view The view handle
 * @param[in] language The display language in the map.
 *                     A language is specified as an ISO 3166 alpha-2 two letter country-code
 *                     followed by ISO 639-1 for the two-letter language code.
 *                     Each language tag is composed of one or more "subtags" separated by hyphens (-).
 *                     Each subtag is composed of basic Latin letters or digits only.
 *                     For example, "ko-KR" for Korean, "en-US" for American English
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_language()
 * @see maps_view_set_type()
 * @see maps_view_create()
 */
int maps_view_set_language(maps_view_h view, const char *language);


/**
 * @brief Gets View language.
 * @details This function gets the language set to the View.\n
 *          Note that map display language is different from places and route language.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The @a language should be freed using free().
 * @param[in] view The view handle
 * @param[out] language The pointer to a char* in which to store the language string value
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_language()
 * @see maps_view_get_type()
 * @see maps_view_create()
 */
int maps_view_get_language(const maps_view_h view, char **language);


/**
 * @brief Enables or disables scalebar.
 * @details This function enables or disables scalebar.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] enable The enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval  #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_get_scalebar_enabled()
 */
int maps_view_set_scalebar_enabled(maps_view_h view, bool enable);


/**
 * @brief Gets whether the scalebar is enabled or not.
 * @details This function gets whether the scalebar is enabled or not.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] enabled The pointer to a boolean in which to store the enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see maps_view_set_scalebar_enabled()
 */
int maps_view_get_scalebar_enabled(const maps_view_h view, bool *enabled);


/* --------------------MAPS PANEL MANIPULATIONS-------------------------------*/


/**
 * @brief Gets the View port.
 * @details This function gets the View port as a pointer on Evas_Object.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out]viewport The pointer to Evas_Object in which to store the View port
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_create()
 * @see Evas_Object
 */
int maps_view_get_viewport(const maps_view_h view, Evas_Object **viewport);


/**
 * @brief Sets geometry of View port.
 * @details This function set the position and (rectangular) size of the given View.\n
 *          The position, naturally, will be relative to the top left corner of the parent window.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] x X screen coordinate for the top left corner of View
 * @param[in] y Y screen coordinate for the top left corner of View
 * @param[in] width The new width of View in screen units
 * @param[in] height The new height of View in screen units
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_screen_location()
 * @see maps_view_resize()
 * @see maps_view_set_visibility()
 * @see maps_view_create()
 */
int maps_view_set_screen_location(maps_view_h view, int x, int y, int width, int height);


/**
 * @brief Gets geometry of View port.
 * @details This function retrieves the position and (rectangular) size of the given View.\n
 *          The position, naturally, will be relative to the top left corner of the parent window.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks Use NULL pointers on the geometry components you're not interested in.
 * @param[in] view The view handle
 * @param[out] x X screen coordinate for the top left corner of View
 * @param[out] y Y screen coordinate for the left top corner of View
 * @param[out] width The pointer to an integer in which to store the width of the view
 * @param[out] height The pointer to an integer in which to store the height of the view
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_screen_location()
 * @see maps_view_resize()
 * @see maps_view_get_visibility()
 * @see maps_view_create()
 */
int maps_view_get_screen_location(const maps_view_h view, int *x, int *y, int *width, int *height);


/**
 * @brief Moves the View.
 * @details This function moves View.
 * @remarks Newly created View port has the size of its parent.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[in] x The new x position, in screen units
 * @param[in] y The new y position, in screen units
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_screen_location()
 * @see maps_view_get_screen_location()
 * @see maps_view_set_visibility()
 * @see maps_view_create()
 */
int maps_view_move(maps_view_h view, int x, int y);


/**
 * @brief Resizes the View.
 * @details This function changes the size of the given View.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks Newly created View port has the size of its parent.
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice \n
 *            %http://tizen.org/privilege/internet \n
 *            %http://tizen.org/privilege/network.get
 * @param[in] view The view handle
 * @param[in] width The new new width in screen units
 * @param[in] height The new new height in screen units
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_CONNECTION_TIME_OUT Timeout error, no answer
 * @retval #MAPS_ERROR_NETWORK_UNREACHABLE Network unavailable
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_screen_location()
 * @see maps_view_get_screen_location()
 * @see maps_view_set_visibility()
 * @see maps_view_create()
 */
int maps_view_resize(maps_view_h view, int width, int height);


/**
 * @brief Shows or hides the View.
 * @details This function changes the visibility of View on the screen.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[in] visible The new visibility of the View
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_get_visibility()
 * @see maps_view_set_screen_location()
 * @see maps_view_create()
 */
int maps_view_set_visibility(maps_view_h view, bool visible);


/**
 * @brief Gets the View visibility.
 * @details This function retrieves whether or not the given View is visible.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[out] visible The pointer to a boolean in which to store the visibility of the View
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_set_visibility()
 * @see maps_view_set_screen_location()
 * @see maps_view_create()
 */
int maps_view_get_visibility(const maps_view_h view, bool *visible);


/* ---------------------UI CONTROL------------------------------------------*/


/**
 * @brief Sets the event callback.
 * @details This function sets the callback which will be invoked every time the
 *          View processes the user's gesture, action, and objects over the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks To unregister the callback, use maps_view_unset_event_cb().
 * @param[in] view The view handle
 * @param[in] type The event type
 * @param[in] callback The callback, matching the maps_view_on_event_cb() prototype
 * @param[in] user_data The user data pointer to be passed to the callback
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see maps_view_unset_event_cb()
 * @see maps_view_on_event_cb()
 * @see maps_view_set_gesture_enabled()
 * @see maps_view_create()
 */
int maps_view_set_event_cb(maps_view_h view, maps_view_event_type_e type, maps_view_on_event_cb callback, void *user_data);


/**
 * @brief Unsets the event callback.
 * @details This function unsets the event callback.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[in] type The event type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre the event callback is registered using maps_view_set_event_cb()
 * @see maps_view_set_event_cb()
 * @see maps_view_get_gesture_enabled()
 * @see maps_view_create()
 */
int maps_view_unset_event_cb(maps_view_h view, maps_view_event_type_e type);


/**
 * @brief Enables or disables the map gesture.
 * @details This function enables or disables the map gesture.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[in] gesture The user gesture, one listed in #maps_gesture_e
 * @param[in] enabled The enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @see #maps_gesture_e
 * @see maps_view_get_gesture_enabled()
 * @see maps_view_create()
 */
int maps_view_set_gesture_enabled(maps_view_h view, maps_view_gesture_e gesture, bool enabled);


/**
 * @brief Checks whether the map gesture is enabled or not.
 * @details This function checks whether the map gesture is enabled or not.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] view The view handle
 * @param[in] gesture The user gesture, one of listed in #maps_gesture_e
 * @param[out] enabled The pointer to a boolean in which to store the enable status
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre @a enabled status set ad default or modified using
 * maps_view_set_gesture_enabled().
 * @see #maps_gesture_e
 * @see maps_view_set_gesture_enabled()
 * @see maps_view_create()
 */
int maps_view_get_gesture_enabled(const maps_view_h view, maps_view_gesture_e gesture, bool *enabled);


/* ---------------------VISUAL OBJECTS ON THE MAP-----------------------------*/


/**
 * @brief Adds a visual object on the map.
 * @details This function adds a visual object on the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @remarks The @a object handle will be released automatically when the view is destroyed in the maps_view_destroy().
 * @param[in] view The view handle
 * @param[in] object The handle of the object to add
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre @a object is created using #maps_view_object_create_marker(),
 *      maps_view_object_create_polygon(), maps_view_object_create_polyline() or
 *      maps_view_object_create_group().
 * @see #maps_view_object_h
 * @see maps_view_object_create_marker()
 * @see maps_view_object_create_polygon()
 * @see maps_view_object_create_polyline()
 * @see maps_view_remove_object()
 * @see maps_view_remove_all_objects()
 * @see maps_view_create()
 */
int maps_view_add_object(maps_view_h view, maps_view_object_h object);


/**
 * @brief Removes a visual object from the map.
 * @details This function removes a visual object from the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @remarks The @a object handle will be released automatically by the View.
 * @param[in] view The view handle
 * @param[in] object The object to remove
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre @a object is added using maps_view_add_object().
 * @see maps_view_add_object()
 * @see maps_view_remove_all_objects()
 * @see #maps_view_object_h
 * @see maps_view_create()
 */
int maps_view_remove_object(maps_view_h view, maps_view_object_h object);


/**
 * @brief Removes all visual objects from the map.
 * @details This function removes all visual object from the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/mapservice
 * @remarks All object handles will be released automatically by the View.
 * @param[in] view The view handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_PERMISSION_DENIED Permission Denied
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre objects are added using maps_view_add_object().
 * @see #maps_view_object_h
 * @see maps_view_add_object()
 * @see maps_view_remove_all_objects()
 * @see maps_view_create()
 */
int maps_view_remove_all_objects(maps_view_h view);


/**
 * @brief Retrieves all visual objects on the map.
 * @details This function retrieves all visual objects previously added to the map.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The objects will be delivered via maps_view_object_cb().
 * @param[in] view The view handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data pointer to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a view is created using maps_view_create().
 * @pre objects are added using maps_view_add_object().
 * @post This function invokes maps_view_object_cb() repeatedly to retrieve each visual object.
 * @see #maps_view_object_h
 * @see maps_view_object_cb()
 * @see maps_view_add_object()
 * @see maps_view_remove_object()
 * @see maps_view_remove_all_objects()
 * @see maps_view_create()
 */
int maps_view_foreach_object(const maps_view_h view, maps_view_object_cb callback, void *user_data);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_VIEW_H__*/
