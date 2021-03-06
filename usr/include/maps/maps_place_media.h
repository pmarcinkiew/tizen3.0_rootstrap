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

#ifndef __MAPS_PLACE_MEDIA_H__
#define __MAPS_PLACE_MEDIA_H__

#include <maps_place_link_object.h>

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_MEDIA_MODULE Media
 * @addtogroup CAPI_MAPS_PLACE_MEDIA_MODULE
 * @{
 * @file maps_place_media.h
 * @brief This file contains the functions related to Place Media information.
 * @brief This provides APIs related to Place Media information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Media handle.
 * @details The handle of Place Media instance.
 * @remarks To release the handle, use maps_place_media_destroy(). \n
 *          To clone the handle, use maps_place_media_clone().
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @see maps_place_media_destroy()
 * @see maps_place_media_clone()
 */
typedef void *maps_place_media_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Media handle and releases all its resources.
 * @details This function destroys the Place Media handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] media The Place Media handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_media_clone()
 */
int maps_place_media_destroy(maps_place_media_h media);


/**
 * @brief Clones the Place Media handle.
 * @details This function clones the Place Media handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_media_destroy().
 * @param[in] origin The original Place Media handle
 * @param[out] cloned A cloned Place Media handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_media_destroy()
 */
int maps_place_media_clone(const maps_place_media_h origin, maps_place_media_h *cloned);

/*---------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Media attribution.
 * @details This function gets the Place Media attribution.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a attribution must be released using free().
 * @param[in] media The handle of Place Media
 * @param[out] attribution The Place Media attribution
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_media_get_attribution(const maps_place_media_h media, char **attribution);


/**
 * @brief Gets the Place Media supplier link.
 * @details This function gets the Place Media supplier link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a supplier must be released using maps_place_link_object_destroy().
 * @param[in] media The handle of Place Media
 * @param[out] supplier The Place Media supplier link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_link_object_h
 */
int maps_place_media_get_supplier(const maps_place_media_h media, maps_place_link_object_h *supplier);


/**
 * @brief Gets the Place Media "via" link.
 * @details This function gets the Place Media "via" link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a via must be released using maps_place_link_object_destroy().
 * @param[in] media The handle of Place Media
 * @param[out] via The Place Media via link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_link_object_h
 */
int maps_place_media_get_via(const maps_place_media_h media, maps_place_link_object_h *via);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_MEDIA_H__ */
