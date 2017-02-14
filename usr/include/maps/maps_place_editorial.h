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

#ifndef __MAPS_PLACE_EDITORIAL_H__
#define __MAPS_PLACE_EDITORIAL_H__

#include <maps_place_media.h>

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_EDITORIAL_MODULE Editorial
 * @addtogroup CAPI_MAPS_PLACE_EDITORIAL_MODULE
 * @{
 * @file maps_place_editorial.h
 * @brief This file contains the functions related to Place Editorial
 * information.
 * @brief This provides APIs related to Place Editorial information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Editorial handle.
 * @details The handle of Place Editorial instance.
 * @remarks To release the handle, use maps_place_editorial_destroy().\n
 *          To clone the handle, use maps_place_editorial_clone().
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @see maps_place_editorial_destroy()
 * @see maps_place_editorial_clone()
 */
typedef void *maps_place_editorial_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Editorial handle and releases all its resources.
 * @details This function destroys the Place Editorial handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] editorial The Place Editorial handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_editorial_clone()
 */
int maps_place_editorial_destroy(maps_place_editorial_h editorial);


/**
 * @brief Clones the Place Editorial handle.
 * @details This function clones the Place Editorial handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_editorial_destroy().
 * @param[in] origin The original Place Editorial handle
 * @param[out] cloned A cloned Place Editorial handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_editorial_destroy()
 */
int maps_place_editorial_clone(const maps_place_editorial_h origin, maps_place_editorial_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Editorial description.
 * @details This function gets the Place Editorial description.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a description must be released using free().
 * @param[in] editorial The handle of Place Editorial
 * @param[out] description The Place Editorial description
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_editorial_get_description(const maps_place_editorial_h editorial, char **description);


/**
 * @brief Gets the Place Editorial language.
 * @details This function gets the Place Editorial language.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a language must be released using free().
 * @param[in] editorial The handle of Place Editorial
 * @param[out] language The Place Editorial language
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_editorial_get_language(const maps_place_editorial_h editorial, char **language);


/**
 * @brief Gets the Place Editorial media.
 * @details This function gets the Place Editorial media.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a media must be released using maps_place_media_destroy().
 * @param[in] editorial The handle of Place Editorial
 * @param[out] media The Place Editorial media
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_media_h
 */
int maps_place_editorial_get_media(const maps_place_editorial_h editorial, maps_place_media_h *media);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_EDITORIAL_H__ */
