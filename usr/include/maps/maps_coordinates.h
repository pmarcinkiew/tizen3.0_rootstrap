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

#ifndef __MAPS_COORDINATES_H__
#define __MAPS_COORDINATES_H__

#include <tizen_type.h>

/**
 * @ingroup CAPI_MAPS_SERVICE_MODULE
 * @defgroup CAPI_MAPS_COORDS_MODULE Coordinates
 * @addtogroup CAPI_MAPS_COORDS_MODULE
 * @{*
 * @file maps_coordinates.h
 * @brief This file contains the functions related to Geographical Coordinates.
 * @brief This provides APIs related to Geographical Coordinates.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle of the Geographical Coordinates.
 * @details The Geographical Coordinates handle can be obtained via call of maps_coordinates_create().
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_coordinates_destroy().\n
 *          To clone the handle, use maps_coordinates_clone().
 */
typedef void *maps_coordinates_h;


/**
 * @brief Structure of the Geographical Coordinates.
 * @details This structure represents a Geographical Coordinates, specified with the @a latitude and @a longitude values.\n
 *          The @a latitude must be in range of [-90.0, 90.0].\n
 *          The @a longitude must be in range of [-180.0, 180.0].
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks #maps_coordinates_h is a void pointer to the #maps_coordinates_h.
 * @remarks Do not use #maps_coordinates_s directly if you are an application developer.
 *          Using #maps_coordinates_h is recommended.
 * @see maps_coordinates_h
 */
typedef struct _maps_coordinates_s {
	double latitude; /**< The latitude [-90.0 ~ 90.0] (degrees) */
	double longitude; /**< The longitude [-180.0 ~ 180.0] (degrees) */
} maps_coordinates_s;


/**
 * @brief The coordinates list handle.
 * @details The coordinates list handle can be obtained via calling of maps_coordinates_list_create().
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 */
typedef void *maps_coordinates_list_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Creates a new instance of Geographical Coordinates and initiates a handle with it.
 * @details This function creates @a coordinates, a new instance of Geographical
 *          Coordinates of type #maps_coordinates_h with a specified @a latitude and @a longitude.\n
 *          New handle is assigned with this instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a coordinates must be released using maps_coordinates_destroy().\n
 *          @a coordinates may be cloned using maps_coordinates_clone().
 * @param[in] latitude The latitude [-90.0 ~ 90.0] (degrees)
 * @param[in] longitude The longitude [-180.0 ~ 180.0] (degrees)
 * @param[out] coordinates The coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_clone()
 * @see maps_coordinates_destroy()
 */
int maps_coordinates_create(const double latitude, const double longitude, maps_coordinates_h *coordinates);


/**
 * @brief Destroys the Geographical Coordinates and releases all its resources.
 * @details This function destroys the Geographical Coordinates #maps_coordinates_h and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle to destroy
 * @return @c 0 on coordinates,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create_rectangle().
 * @see maps_coordinates_create()
 * @see maps_coordinates_clone()
 */
int maps_coordinates_destroy(maps_coordinates_h coordinates);


/**
 * @brief Clones the Geographical Coordinates.
 * @details This function makes a clone of the @a origin Geographical Coordinates of type #maps_coordinates_h.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_coordinates_destroy().
 * @param[in] origin The original coordinate handle
 * @param[out] cloned A cloned coordinate handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a origin is created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_destroy()
 */
int maps_coordinates_clone(const maps_coordinates_h origin, maps_coordinates_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the latitude of the coordinates.
 * @details This function gets the @a latitude value of the coordinates handle.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[out] latitude The latitude of the coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_set_latitude()
 */
int maps_coordinates_get_latitude(const maps_coordinates_h coordinates, double *latitude);


/**
 * @brief Gets the longitude of the coordinates.
 * @details This function gets the @a longitude value of the coordinates handle.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[out] longitude The longitude of the coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_set_longitude()
 */
int maps_coordinates_get_longitude(const maps_coordinates_h coordinates, double *longitude);


/**
 * @brief Gets the latitude and longitude of the coordinates.
 * @details This function gets the @a longitude and @a longitude value of the coordinates handle.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[out] latitude The latitude of the coordinates handle
 * @param[out] longitude The longitude of the coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_set_latitude_longitude()
 */
int maps_coordinates_get_latitude_longitude(const maps_coordinates_h coordinates, double *latitude, double *longitude);
/*----------------------------------------------------------------------------*/

/**
 * @brief Sets the latitude of the coordinates.
 * @details This function sets the @a latitude value of the coordinates handle.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[in] latitude The latitude of the coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_get_latitude()
 */
int maps_coordinates_set_latitude(maps_coordinates_h coordinates, const double latitude);


/**
 * @brief Sets the longitude of the coordinates.
 * @details This function sets the @a longitude value of the coordinates handle.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[out] longitude The longitude of the coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_get_longitude()
 */
int maps_coordinates_set_longitude(maps_coordinates_h coordinates, const double longitude);


/**
 * @brief Sets the latitude and longitude of the coordinates.
 * @details This function sets the @a latitude and @a latitude value of the coordinates handle.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates The coordinates handle
 * @param[in] latitude The latitude [-90.0 ~ 90.0] (degrees)
 * @param[in] longitude The longitude [-180.0 ~ 180.0] (degrees)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a coordinates are created using maps_coordinates_create().
 * @see maps_coordinates_create()
 * @see maps_coordinates_get_latitude_longitude()
 */
int maps_coordinates_set_latitude_longitude(maps_coordinates_h coordinates, const double latitude, const double longitude);


/**
 * @brief Creates a coordinates list having a set of coordinates.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[out] coordinates_list The coordinates list handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_destroy()
 */
int maps_coordinates_list_create(maps_coordinates_list_h *coordinates_list);


/**
 * @brief Frees all of the memory used by a coordinates list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates_list Coordinates list handle
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_create()
 */
int maps_coordinates_list_destroy(maps_coordinates_list_h coordinates_list);


/**
 * @brief Appends a coordinates to a coordinates list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates_list The coordinates list handle
 * @param[in] coordinates The coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_create()
 * @see maps_coordinates_list_destroy()
 */
int maps_coordinates_list_append(maps_coordinates_list_h coordinates_list, maps_coordinates_h coordinates);


/**
 * @brief Removes a coordinates from a coordinates list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates_list The coordinates list handle
 * @param[in] coordinates The coordinates handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_create()
 * @see maps_coordinates_list_destroy()
 */
int maps_coordinates_list_remove(maps_coordinates_list_h coordinates_list, maps_coordinates_h coordinates);


/**
 * @brief Gets the number of elements in a coordinates list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates_list The coordinates list handle
 * @param[out] length The number of elements in the coordinates list
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_create()
 * @see maps_coordinates_list_destroy()
 */
int maps_coordinates_list_get_length(maps_coordinates_list_h coordinates_list, int *length);


/**
 * @brief Called iteratively to get a coordinates information.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] index The index of iteration
 * @param[in] coordinates The handle of coordinates
 * @param[in] user_data The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @see batch_coordinates_foreach_coordinates()
 */
typedef bool (*maps_coordinates_cb) (int index, maps_coordinates_h coordinates, void *user_data);


/**
 * @brief Retrieves all coordinates by invoking a specific callback for each coordinates of coordinates list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] coordinates_list The coordinates list handle
 * @param[in] callback The iteration callback
 * @param[in] user_data The user data to be passed to the callback function
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_coordinates_list_create()
 * @see maps_coordinates_list_destroy()
 * @see maps_coordinates_list_get_length()
 */
int maps_coordinates_list_foreach(maps_coordinates_list_h coordinates_list, maps_coordinates_cb callback, void *user_data);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_COORDINATES_H__ */
