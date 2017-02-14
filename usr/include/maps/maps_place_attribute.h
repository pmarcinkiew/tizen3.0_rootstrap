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

#ifndef __MAPS_PLACE_ATTRIBUTE_H__
#define __MAPS_PLACE_ATTRIBUTE_H__

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_ATTRIBUTE_MODULE Attribute
 * @addtogroup CAPI_MAPS_PLACE_ATTRIBUTE_MODULE
 * @{
 * @file maps_place_attribute.h
 * @brief This file contains the functions related to Place Attributes information.
 * @brief This provides APIs related to Place Attributes information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Attribute handle.
 * @details The handle of Place Attribute instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_place_attribute_destroy().\n
 *          To clone the handle, use maps_place_attribute_clone().
 * @see maps_place_attribute_destroy()
 * @see maps_place_attribute_clone()
 */
typedef void *maps_place_attribute_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Attribute handle and releases all its resources.
 * @details This function destroys the Place Attribute handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] attribute The Place Attribute handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_attribute_clone()
 */
int maps_place_attribute_destroy(maps_place_attribute_h attribute);


/**
 * @brief Clones the Place Attribute handle.
 * @details This function clones the Place Attribute handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_attribute_destroy().
 * @param[in] origin The original Place Attribute handle
 * @param[out] cloned A cloned Place Attribute handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_attribute_destroy()
 */
int maps_place_attribute_clone(const maps_place_attribute_h origin, maps_place_attribute_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Attribute ID.
 * @details This function gets the Place Attribute ID.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a id must be released using free().
 * @param[in] attribute The handle to Place Attribute
 * @param[out] id The Place Attribute ID
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_attribute_get_id(const maps_place_attribute_h attribute, char **id);


/**
 * @brief Gets the Place Attribute label.
 * @details This function gets the Place Attribute label.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a label must be released using free().
 * @param[in] attribute The handle to Place Attribute
 * @param[out] label The Place Attribute label
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_attribute_get_label(const maps_place_attribute_h attribute, char **label);


/**
 * @brief Gets the Place Attribute text.
 * @details This function gets the Place Attribute text.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a text must be released using free().
 * @param[in] attribute The handle to Place Attribute
 * @param[out] text The Place Attribute text
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_attribute_get_text(const maps_place_attribute_h attribute, char **text);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_ATTRIBUTE_H__ */
