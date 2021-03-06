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

#ifndef __MAPS_PLACE_URL_H__
#define __MAPS_PLACE_URL_H__

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_URL_MODULE URL
 * @addtogroup CAPI_MAPS_PLACE_URL_MODULE
 * @{
 * @file maps_place_url.h
 * @brief This file contains the functions related to Place URL information.
 * @brief This provides APIs related to Place URL information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place URL handle.
 * @details The handle of Place URL instance.
 * @remarks To release the handle, use maps_place_url_destroy(). \n
 *          To clone the handle, use maps_place_url_clone().
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @see maps_place_url_destroy()
 * @see maps_place_url_clone()
 */
typedef void *maps_place_url_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place URL handle and releases all its resources.
 * @details This function destroys the Place URL handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] url The Place URL handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_url_clone()
 */
int maps_place_url_destroy(maps_place_url_h url);


/**
 * @brief Clones the Place URL handle.
 * @details This function clones the Place URL handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_url_destroy().
 * @param[in] origin The original Place URL handle
 * @param[out] cloned A cloned Place URL handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_url_destroy()
 */
int maps_place_url_clone(const maps_place_url_h origin, maps_place_url_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place URL path.
 * @details This function gets the Place URL path.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a path must be released using free().
 * @param[in] url The handle to Place URL handle
 * @param[out] path The Place URL path
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_url_get_path(const maps_place_url_h url, char **path);


/**
 * @brief Gets the Place URL description.
 * @details This function gets the Place URL description.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a desc must be released using free().
 * @param[in] url The handle to Place URL handle
 * @param[out] desc The Place URL description
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_url_get_description(const maps_place_url_h url, char **desc);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_URL_H__ */
