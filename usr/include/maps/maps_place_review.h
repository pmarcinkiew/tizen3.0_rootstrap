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

#ifndef __MAPS_PLACE_REVIEW_H__
#define __MAPS_PLACE_REVIEW_H__

#include <maps_place_media.h>
#include <maps_place_link_object.h>

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_REVIEW_MODULE Review
 * @addtogroup CAPI_MAPS_PLACE_REVIEW_MODULE
 * @{
 * @file maps_place_review.h
 * @brief This file contains the functions related to Place Review information.
 * @brief This provides APIs related to Place Review information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The Place Review handle.
 * @details The handle of Place Review instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_place_review_destroy().\n
 *          To clone the handle, use maps_place_review_clone().
 * @see maps_place_review_destroy()
 * @see maps_place_review_clone()
 */
typedef void *maps_place_review_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place Review handle and releases all its resources.
 * @details This function destroys the Place Review handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] review The Place Review handle to destroy
 * @return @c 0 on success,
 *          otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_review_clone()
 */
int maps_place_review_destroy(maps_place_review_h review);


/**
 * @brief Clones the Place Review handle.
 * @details This function clones the Place Review handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_review_destroy().
 * @param[in] origin The original Place Review handle
 * @param[out] cloned A cloned Place Review handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_review_destroy()
 */
int maps_place_review_clone(const maps_place_review_h origin, maps_place_review_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place Review date.
 * @details This function gets the Place Review date.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a date must be released using free().
 * @param[in] review The handle to Place Review
 * @param[out] date The Place Review date
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_review_get_date(const maps_place_review_h review, char **date);


/**
 * @brief Gets the Place Review title.
 * @details This function gets the Place Review title.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a title must be released using free().
 * @param[in] review The handle to Place Review
 * @param[out] title The Place Review title
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_review_get_title(const maps_place_review_h review, char **title);


/**
 * @brief Gets the Place Review rating.
 * @details This function gets the Place Review rating.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] review The handle to Place Review
 * @param[out] rating The Place Review rating
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_review_get_rating(const maps_place_review_h review, double *rating);


/**
 * @brief Gets the Place Review description.
 * @details This function gets the Place Review description.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a description must be released using free().
 * @param[in] review The handle to Place Review
 * @param[out] description The Place Review description
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_review_get_description(const maps_place_review_h review, char **description);


/**
 * @brief Gets the Place Review language.
 * @details This function gets the Place Review language.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a language must be released using free().
 * @param[in] review The handle to Place Review
 * @param[out] language The Place Review language
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_review_get_language(const maps_place_review_h review, char **language);


/**
 * @brief Gets the Place Review media.
 * @details This function gets the Place Review media.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a media must be released using maps_place_media_destroy().
 * @param[in] review The handle to Place Review
 * @param[out] media The Place Review media
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_media_h
 */
int maps_place_review_get_media(const maps_place_review_h review, maps_place_media_h *media);


/**
 * @brief Gets the Place Review user link.
 * @details This function gets the Place Review user link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a user must be released using maps_place_link_object_destroy().
 * @param[in] review The handle to Place Review
 * @param[out] user The Place Review user link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see #maps_place_link_object_h
 */
int maps_place_review_get_user_link(const maps_place_review_h review, maps_place_link_object_h *user);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_REVIEW_H__ */
