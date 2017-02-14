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

#ifndef __MAPS_PLACE_CONTACT_H__
#define __MAPS_PLACE_CONTACT_H__

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_CONTACT_MODULE Contact
 * @addtogroup CAPI_MAPS_PLACE_CONTACT_MODULE
 * @{
 * @file maps_place_contact.h
 * @brief This file contains the functions related to Place Contact information.
 * @brief This provides APIs related to Place Contact, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Contact handle.
 * @details The handle of Place Contact instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_place_contact_destroy().\n
 *          To clone the handle, use maps_place_contact_clone().
 * @see maps_place_contact_destroy()
 * @see maps_place_contact_clone()
 */
typedef void *maps_place_contact_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Contact handle and releases all its resources.
 * @details This function destroys the Place Contact handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] contact The Place Contact handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_contact_clone()
 */
int maps_place_contact_destroy(maps_place_contact_h contact);


/**
 * @brief Clones the Place Contact handle.
 * @details This function clones the Place Contact handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_contact_destroy().
 * @param[in] origin The original Place Contact handle
 * @param[out] cloned A cloned Place Contact handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_contact_destroy()
 */
int maps_place_contact_clone(const maps_place_contact_h origin, maps_place_contact_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Contact label.
 * @details This function gets the Place Contact label.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a label must be released using free().
 * @param[in] contact The handle to Place Contact
 * @param[out] label The Place Contact label
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_contact_get_label(const maps_place_contact_h contact, char **label);


/**
 * @brief Gets the Place Contact type.
 * @details This function gets the Place Contact type.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a type must be released using free().
 * @param[in] contact The handle to Place Contact
 * @param[out] type The Place Contact type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_contact_get_type(const maps_place_contact_h contact, char **type);


/**
 * @brief Gets the Place Contact value.
 * @details This function gets the Place Contact value.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a value must be released using free().
 * @param[in] contact The handle to Place Contact
 * @param[out] value The Place Contact value
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_contact_get_value(const maps_place_contact_h contact, char **value);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_CONTACT_H__ */
