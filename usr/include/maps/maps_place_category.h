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

#ifndef __MAPS_PLACE_CATEGORY_H__
#define __MAPS_PLACE_CATEGORY_H__

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_CATEGORY_MODULE Category
 * @addtogroup CAPI_MAPS_PLACE_CATEGORY_MODULE
 * @{
 * @file maps_place_category.h
 * @brief This file contains the functions related to Place Category information.
 * @brief This provides APIs related to Place Category information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Category handle.
 * @details The handle of Place Category instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_place_category_destroy().\n
 *          To clone the handle, use maps_place_category_clone().
 * @see maps_place_category_destroy()
 * @see maps_place_category_clone()
 */
typedef void *maps_place_category_h;

/*----------------------------------------------------------------------------*/


/**
 * @brief Creates a new Place Category handle.
 * @details This function creates a new Place Category handle and allocates all needed resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a category must be released using maps_place_category_destroy().\n
 *          @a category may be cloned using maps_place_category_clone().
 * @param[out] category A handle of a new Place Category on success
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_category_destroy()
 * @see maps_place_category_clone()
 */
int maps_place_category_create(maps_place_category_h *category);


/**
 * @brief Clones the Place Category handle.
 * @details This function clones the Place Category handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_category_destroy().
 * @param[in] origin The original Place Category handle
 * @param[out] cloned A cloned Place Category handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_category_destroy()
 */
int maps_place_category_clone(const maps_place_category_h origin, maps_place_category_h *cloned);


/**
 * @brief Destroys the Place Category handle and releases all its resources.
 * @details This function destroys the Place Category handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] category The Place Category handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_category_clone()
 */
int maps_place_category_destroy(maps_place_category_h category);


/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Category ID.
 * @details This function gets the Place Category ID.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a id must be released using free().
 * @param[in] category The handle of Place Category
 * @param[out] id The Place Category ID
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_category_get_id(const maps_place_category_h category, char **id);


/**
 * @brief Gets the Place Category name.
 * @details This function gets the Place Category name.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a name must be released using free().
 * @param[in] category The handle of Place Category
 * @param[out] name The Place Category name
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_category_get_name(const maps_place_category_h category, char **name);


/**
 * @brief Gets the Place Category URL.
 * @details This function gets the Place Category URL.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a url must be released using free().
 * @param[in] category The handle of Place Category
 * @param[out] url The Place Category URL
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_category_get_url(const maps_place_category_h category, char **url);


/**
 * @brief Sets the Place Category ID.
 * @details This function sets the Place Category ID.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] category The handle of Place Category
 * @param[in] id The Place Category ID
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a category is created using maps_place_category_create().
 * @see maps_place_category_create()
 * @see maps_place_category_get_id()
 */
int maps_place_category_set_id(maps_place_category_h category, const char *id);


/**
 * @brief Sets the Place Category name.
 * @details This function sets the Place Category name.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] category The handle of Place Category
 * @param[in] name The Place Category name
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a category is created using maps_place_category_create().
 * @see maps_place_category_create()
 * @see maps_place_category_get_name()
 */
int maps_place_category_set_name(maps_place_category_h category, const char *name);


/**
 * @brief Sets the Place Category URL.
 * @details This function sets the Place Category URL.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] category The handle of Place Category
 * @param[in] url The Place Category URL
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @pre @a category is created using maps_place_category_create().
 * @see maps_place_category_create()
 * @see maps_place_category_get_url()
 */
int maps_place_category_set_url(maps_place_category_h category, const char *url);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_CATEGORY_H__ */
