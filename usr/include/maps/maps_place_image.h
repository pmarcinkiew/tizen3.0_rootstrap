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

#ifndef __MAPS_PLACE_IMAGE_H__
#define __MAPS_PLACE_IMAGE_H__

#include <maps_place_link_object.h>
#include <maps_place_media.h>

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_IMAGE_MODULE Image
 * @addtogroup CAPI_MAPS_PLACE_IMAGE_MODULE
 * @{
 * @file maps_place_image.h
 * @brief This function sets the place category ID.
 * @brief This provides APIs related to Place Image information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Image handle.
 * @details The handle of Place Image instance.
 * @remarks To release the handle, use maps_place_image_destroy().\n
 *          To clone the handle, use maps_place_image_clone().
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @see maps_place_image_destroy()
 * @see maps_place_image_clone()
 */
typedef void *maps_place_image_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Image handle and releases all its resources.
 * @details This function destroys the Place Image handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] image The Place Image handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_image_clone()
 */
int maps_place_image_destroy(maps_place_image_h image);


/**
 * @brief Clones the Place Image handle.
 * @details This function clones the Place Image handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_image_destroy().
 * @param[in] origin The original Place Image handle
 * @param[out] cloned A cloned Place Image handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_image_destroy()
 */
int maps_place_image_clone(const maps_place_image_h origin, maps_place_image_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Image ID.
 * @details This function gets the Place Image ID.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a id must be released using free().
 * @param[in] image The handle of Place Image
 * @param[out] id The Place Image ID
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_image_get_id(const maps_place_image_h image, char **id);


/**
 * @brief Gets the Place Image URL.
 * @details This function gets the Place Image URL.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a url must be released using free().
 * @param[in] image The handle of Place Image
 * @param[out] url The Place Image URL
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_image_get_url(const maps_place_image_h image, char **url);


/**
 * @brief Gets the Place Image width.
 * @details This function gets the Place Image width.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] image The handle of Place Image
 * @param[out] width The Place Image width
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_image_get_width(const maps_place_image_h image, int *width);


/**
 * @brief Gets the Place Image height.
 * @details This function gets the Place Image height.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] image The handle of Place Image
 * @param[out] height The Place Image height
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_image_get_height(const maps_place_image_h image, int *height);


/**
 * @brief Gets the Place Image user link.
 * @details This function gets the Place Image user link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a user must be released using maps_place_link_object_destroy().
 * @param[in] image The handle of Place Image
 * @param[out] user The Place Image user link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_link_object_h
 */
int maps_place_image_get_user_link(const maps_place_image_h image, maps_place_link_object_h *user);


/**
 * @brief Gets the Place Image media.
 * @details This function gets the Place Image media.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a media must be released using maps_place_media_destroy().
 * @param[in] image The handle of Place Image
 * @param[out] media The Place Image media
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_media_h
 */
int maps_place_image_get_media(const maps_place_image_h image, maps_place_media_h *media);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_IMAGE_H__ */
