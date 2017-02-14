#ifndef _ELM_PHOTO_EO_LEGACY_H_
#define _ELM_PHOTO_EO_LEGACY_H_

#ifndef _ELM_PHOTO_EO_CLASS_TYPE
#define _ELM_PHOTO_EO_CLASS_TYPE

typedef Eo Elm_Photo;

#endif

#ifndef _ELM_PHOTO_EO_TYPES
#define _ELM_PHOTO_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief Set editability of the photo.
 *
 * An editable photo can be dragged to or from, and can be cut or pasted too.
 * Note that pasting an image or dropping an item on the image will delete the
 * existing content.
 *
 * @param[in] set To set of clear editability.
 *
 * @ingroup Elm_Photo
 */
EAPI void elm_photo_editable_set(Elm_Photo *obj, Eina_Bool set);

/**
 * @internal
 *
 * @brief Get editability of the photo.
 *
 * @return To set of clear editability.
 *
 * @ingroup Elm_Photo
 */
EAPI Eina_Bool elm_photo_editable_get(const Elm_Photo *obj);

/**
 * @internal
 *
 * @brief Set if the photo should be completely visible or
 * not.
 *
 * @param[in] fill Photo visibility.
 *
 * @ingroup Elm_Photo
 */
EAPI void elm_photo_fill_inside_set(Elm_Photo *obj, Eina_Bool fill);

/**
 * @internal
 *
 * @brief Get if the photo should be completely visible or
 * not.
 *
 * @return Photo visibility.
 *
 * @ingroup Elm_Photo
 */
EAPI Eina_Bool elm_photo_fill_inside_get(const Elm_Photo *obj);

/**
 * @internal
 *
 * @brief Set whether the original aspect ratio of the photo
 * should be kept on resize.
 *
 * The original aspect ratio (width / height) of the photo is usually distorted
 * to match the object's size. Enabling this option will fix this original
 * aspect, and the way that the photo is fit into the object's area.
 *
 * See also @ref elm_photo_aspect_fixed_get.
 *
 * @param[in] fixed @c true if the photo should fix the aspect, @c false
 * otherwise.
 *
 * @ingroup Elm_Photo
 */
EAPI void elm_photo_aspect_fixed_set(Elm_Photo *obj, Eina_Bool fixed);

/**
 * @internal
 *
 * @brief Get if the object keeps the original aspect ratio.
 *
 * @return @c true if the photo should fix the aspect, @c false otherwise.
 *
 * @ingroup Elm_Photo
 */
EAPI Eina_Bool elm_photo_aspect_fixed_get(const Elm_Photo *obj);

/**
 * @internal
 *
 * @brief Set the size that will be used on the photo
 *
 * @param[in] size The size of the photo
 *
 * @ingroup Elm_Photo
 */
EAPI void elm_photo_size_set(Elm_Photo *obj, int size);

/**
 * @internal
 *
 * @brief Get the size that will be used on the photo
 *
 * @return The size of the photo
 *
 * @ingroup Elm_Photo
 */
EAPI int elm_photo_size_get(const Elm_Photo *obj);

/**
 * @brief Set the file that will be used as thumbnail in the photo.
 *
 * @param[in] group The key used in case of an EET file.
 *
 * @ingroup Elm_Photo
 */
EAPI void elm_photo_thumb_set(const Elm_Photo *obj, const char *file, const char *group);

#endif
