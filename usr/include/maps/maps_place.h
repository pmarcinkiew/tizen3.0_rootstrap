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

#ifndef __MAPS_PLACE_H__
#define __MAPS_PLACE_H__

#include <tizen_type.h>
#include <maps_address.h>
#include <maps_place_category.h>
#include <maps_place_attribute.h>
#include <maps_place_contact.h>
#include <maps_place_editorial.h>
#include <maps_place_link_object.h>
#include <maps_place_image.h>
#include <maps_place_review.h>
#include <maps_place_rating.h>
#include <maps_coordinates.h>

/**
 * @ingroup CAPI_MAPS_PLACE_MODULE
 * @defgroup CAPI_MAPS_PLACE_DATA_MODULE Place
 * @addtogroup CAPI_MAPS_PLACE_DATA_MODULE
 * @{
 * @file maps_place.h
 * @brief This file contains the functions related to Place information.
 * @brief This provides APIs related to Place information, used in Place Discovery and Search.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The Place handle.
 * @details The handle of Place instance.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks To release the handle, use maps_place_destroy().\n
 *          To clone the handle, use maps_place_clone().
 * @see maps_place_destroy()
 * @see maps_place_clone()
 */
typedef void *maps_place_h;


/**
 * @brief The Place list handle.
 * @details The handle of Place list instance.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @see maps_place_list_foreach()
 * @see maps_place_list_destroy()
 */
typedef void *maps_place_list_h;

/*----------------------------------------------------------------------------*/

/**
 * @brief Called when requesting the list of Place Properties.
 * @details This callback is invoked while iterating through the list of Place Properties.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a key and @a value must be released using free(), and corresponding release method for property value correspondingly.
 * @param[in] index The current index of property
 * @param[in] total The total amount of properties
 * @param[in] key The key of property
 * @param[in] value The value of property
 * @param[in] user_data The user data passed from maps_place_foreach_property()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_property() will invoke this callback.
 * @see maps_place_foreach_property()
 */
typedef bool(*maps_place_properties_cb) (int index, int total, char *key, void *value, void *user_data);

/**
 * @brief Called when requesting the list of Place Categories.
 * @details This callback is invoked while iterating through the list of Place Categories.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a category is valid only in this function and must be released using maps_place_category_destroy().\n
 *          To use @a category outside this function, clone it with maps_place_category_clone().
 * @param[in] index The current index of category
 * @param[in] total The total amount of categories
 * @param[in] category The Place category handle
 * @param[in] user_data The user data passed from maps_place_foreach_category()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_category() will invoke this callback.
 * @see maps_place_foreach_category()
 * @see #maps_place_category_h
 */
typedef bool(*maps_place_categories_cb) (int index, int total, maps_place_category_h category, void *user_data);


/**
 * @brief Called when requesting the list of Place Attributes.
 * @details This callback is invoked while iterating through the list of Place Attributes.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a attribute is valid only in this function and must be released using maps_place_attribute_destroy().\n
 *          To use @a attribute outside this function, clone it with maps_place_attribute_clone().
 * @param[in] index The current index of attribute
 * @param[in] total The total amount of attributes
 * @param[in] attribute The Place Attribute handle
 * @param[in] user_data The user data passed from the maps_place_foreach_attribute()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_attribute() will invoke this callback.
 * @see maps_place_foreach_attribute()
 * @see #maps_place_attribute_h
 */
typedef bool(*maps_place_attributes_cb) (int index, int total, maps_place_attribute_h attribute, void *user_data);


/**
 * @brief Called when requesting the list of Place Contacts.
 * @details This callback is invoked while iterating through the list of Place Contacts.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a contact is valid only in this function and must be released using maps_place_contact_destroy().\n
 *          To use @a contact outside this function, clone it with maps_place_contact_clone().
 * @param[in] index The current index of contact
 * @param[in] total The total amount of contacts
 * @param[in] contact The Place Contact handle
 * @param[in] user_data The user data passed from the maps_place_foreach_contact()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_contact() will invoke this callback.
 * @see maps_place_foreach_contact()
 * @see #maps_place_contact_h
 */
typedef bool(*maps_place_contacts_cb) (int index, int total, maps_place_contact_h contact, void *user_data);


/**
 * @brief Called when requesting the list of Place Editorial.
 * @details This callback is invoked while iterating through the list of Place Editorials.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a editorial is valid only in this function and must be released using maps_place_editorial_destroy().\n
 *          To use @a editorial outside this function, clone it with maps_place_editorial_clone().
 * @param[in] index The current index of editorial
 * @param[in] total The total amount of editorials
 * @param[in] editorial The Place Editorial handle
 * @param[in] user_data The user data passed from the maps_place_foreach_editorial()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_editorial() will invoke this callback.
 * @see maps_place_foreach_editorial()
 * @see #maps_place_editorial_h
 */

typedef bool(*maps_place_editorials_cb) (int index, int total, maps_place_editorial_h editorial, void *user_data);


/**
 * @brief Called when requesting the list of Place Image.
 * @details This callback is invoked while iterating through the list of Place Images.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a image is valid only in this function and must be released using maps_place_image_destroy().\n
 *          To use @a image outside this function, clone it with maps_place_image_clone().
 * @param[in] index The current index of image
 * @param[in] total The total amount of images
 * @param[in] image The Place Image handle
 * @param[in] user_data The user data passed from the maps_place_foreach_image()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_image() will invoke this callback.
 * @see maps_place_foreach_image()
 * @see #maps_place_image_h
 */
typedef bool(*maps_place_images_cb) (int index, int total, maps_place_image_h image, void *user_data);


/**
 * @brief Called when requesting the list of Place Review.
 * @details This callback is invoked while iterating through the list of Place Reviews.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a review is valid only in this function and must be released using maps_place_review_destroy().\n
 *          To use @a review outside this function, clone it with maps_place_review_clone().
 * @param[in] index The current index of review
 * @param[in] total The total amount of reviews
 * @param[in] review The Place Review handle
 * @param[in] user_data The user data passed from the maps_place_foreach_review()
 * @return @c true to continue with the next iteration of the loop,\n
 *         @c false to break out of the loop
 * @pre maps_place_foreach_review() will invoke this callback.
 * @see maps_place_foreach_review()
 * @see #maps_place_image_h
 */
typedef bool(*maps_place_reviews_cb) (int index, int total, maps_place_review_h review, void *user_data);


/**
 * @brief Called when requesting the list of Place.
 * @details This callback is invoked while iterating through the list of Place.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] index The current index of review
 * @param[in] place The Place handle
 * @param[in] user_data The user data passed from the maps_place_list_foreach()
 * @return @c true to continue with the next iteration of the loop, \n
 *         @c false to break out of the loop
 * @pre maps_place_list_foreach() will invoke this callback.
 * @see maps_place_list_foreach()
 * @see maps_place_get_id()
 * @see maps_place_get_name()
 * @see maps_place_get_uri()
 * @see maps_place_get_location()
 * @see maps_place_get_distance()
 * @see maps_place_get_rating()
 * @see maps_place_foreach_category()
 */
typedef bool(*maps_place_cb) (int index, maps_place_h place, void *user_data);

/*----------------------------------------------------------------------------*/

/**
 * @brief Destroys the Place handle and releases all its resources.
 * @details This function destroys the Place handle and releases all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] place The Place handle to destroy
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_clone()
 */
int maps_place_destroy(maps_place_h place);


/**
 * @brief Clones the Place handle.
 * @details This function clones the Place handle @a origin and all its resources.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a cloned must be released using maps_place_destroy().
 * @param[in] origin The original Place handle
 * @param[out] cloned A cloned Place handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_destroy()
 */
int maps_place_clone(const maps_place_h origin, maps_place_h *cloned);

/*----------------------------------------------------------------------------*/

/**
 * @brief Gets the Place ID.
 * @details This function gets the Place ID.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a id must be released using free().
 * @param[in] place The Place handle
 * @param[out] id The Place ID
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_id(const maps_place_h place, char **id);


/**
 * @brief Gets the Place name.
 * @details This function gets the Place name.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a name must be released using free().
 * @param[in] place The Place handle
 * @param[out] name The Place name
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_name(const maps_place_h place, char **name);


/**
 * @brief Gets the Place View URI.
 * @details This function gets the Place View URI.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a uri must be released using free().
 * @param[in] place The Place handle
 * @param[out] uri The Place View URI
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_uri(const maps_place_h place, char **uri);


/**
 * @brief Gets the Place Location.
 * @details This function gets the Place Location.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a location must be released using maps_coordinates_destroy().
 * @param[in] place The Place handle
 * @param[out] location The Place Location
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_location(const maps_place_h place, maps_coordinates_h *location);


/**
 * @brief Gets the Place distance from the center of the location.
 * @details This function gets the Place distance from the center of the location.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @param[in] place The Place handle
 * @param[out] distance The Place distance in meters
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_distance(const maps_place_h place, int *distance);


/**
 * @brief Gets the Place Address.
 * @details This function gets the Place Address.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a address must be released using maps_address_destroy().
 * @param[in] place The Place handle
 * @param[out] address The Place Address
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_address(const maps_place_h place, maps_address_h *address);

/**
 * @brief Gets the Place rating.
 * @details This function gets the Place rating.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a rating must be released using maps_place_rating_destroy().
 * @param[in] place The Place handle
 * @param[out] rating The Place rating handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_rating(const maps_place_h place, maps_place_rating_h *rating);


/**
 * @brief Retrieves all properties.
 * @details This function retrieves all Place properties.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The properties will be delivered via maps_place_properties_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_properties_cb() repeatedly to retrieve each property.
 * @see maps_place_properties_cb()
 */
int maps_place_foreach_property(const maps_place_h place, maps_place_properties_cb callback, void *user_data);


/**
 * @brief Retrieves all categories
 * @details This function retrieves all Place categories.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The categories will be delivered via maps_place_categories_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_categories_cb() repeatedly to retrieve each category.
 * @see maps_place_categories_cb()
 */
int maps_place_foreach_category(const maps_place_h place, maps_place_categories_cb callback, void *user_data);


/**
 * @brief Retrieves all attributes.
 * @details This function retrieves all Place Attributes.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The attributes will be delivered via maps_place_attributes_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_attributes_cb() repeatedly to retrieve each attribute.
 * @see maps_place_attributes_cb()
 */
int maps_place_foreach_attribute(const maps_place_h place, maps_place_attributes_cb callback, void *user_data);


/**
 * @brief Retrieves all contacts.
 * @details This function retrieves all Place Contacts.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The contacts will be delivered via maps_place_contacts_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_contacts_cb() repeatedly to retrieve each contact.
 * @see maps_place_contacts_cb()
 */
int maps_place_foreach_contact(const maps_place_h place, maps_place_contacts_cb callback, void *user_data);


/**
 * @brief Retrieves all editorials.
 * @details This function retrieves all Place Editorials.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The editorials will be delivered via maps_place_editorials_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_editorials_cb() repeatedly to retrieve each editorial.
 * @see maps_place_editorials_cb()
 */
int maps_place_foreach_editorial(const maps_place_h place, maps_place_editorials_cb callback, void *user_data);

/**
 * @brief Retrieves all images.
 * @details This function retrieves all Place Images.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The images will be delivered via maps_place_images_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_images_cb() repeatedly to retrieve each image.
 * @see maps_place_images_cb()
 */
int maps_place_foreach_image(const maps_place_h place, maps_place_images_cb callback, void *user_data);


/**
 * @brief Retrieves all reviews.
 * @details This function retrieves all Place reviews.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks The reviews will be delivered via maps_place_reviews_cb().
 * @param[in] place The Place handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_reviews_cb() repeatedly to retrieve each review.
 * @see maps_place_reviews_cb()
 */
int maps_place_foreach_review(const maps_place_h place, maps_place_reviews_cb callback, void *user_data);


/**
 * @brief Gets the Place supplier link.
 * @details This function gets the Place supplier link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a supplier must be released using maps_place_link_object_destroy().
 * @param[in] place The Place handle
 * @param[out] supplier The Place supplier link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_supplier_link(const maps_place_h place, maps_place_link_object_h *supplier);


/**
 * @brief Gets the Place related link.
 * @details This function gets the Place related link.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 2.3.2 @endif
 * @remarks @a related must be released using maps_place_link_object_destroy().
 * @param[in] place The Place handle
 * @param[out] related The Place related link
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 */
int maps_place_get_related_link(const maps_place_h place, maps_place_link_object_h *related);


/**
 * @brief Retrieves all Places.
 * @details This function retrieves all Places.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @remarks The places will be delivered via maps_place_cb().\n
 *          @a place_list must be released using maps_place_list_destroy().
 * @param[in] place_list The Place list handle
 * @param[in] callback The callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_FOUND Result not found
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @post This function invokes maps_place_cb() repeatedly to retrieve each place.
 * @see maps_place_cb()
 * @see maps_place_list_destroy()
 */
int maps_place_list_foreach(const maps_place_list_h place_list, maps_place_cb callback, void *user_data);


/**
 * @brief Frees all of the memory used by a Place list.
 * @since_tizen @if MOBILE 3.0 @elseif WEARABLE 2.3.2 @endif
 * @param[in] place_list The Place list handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MAPS_ERROR_NONE Successful
 * @retval #MAPS_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MAPS_ERROR_NOT_SUPPORTED Not supported
 * @see maps_place_list_foreach()
 */
int maps_place_list_destroy(maps_place_list_h place_list);


#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* __MAPS_PLACE_H__ */
