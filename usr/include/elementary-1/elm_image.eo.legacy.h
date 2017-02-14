#ifndef _ELM_IMAGE_EO_LEGACY_H_
#define _ELM_IMAGE_EO_LEGACY_H_

#ifndef _ELM_IMAGE_EO_CLASS_TYPE
#define _ELM_IMAGE_EO_CLASS_TYPE

typedef Eo Elm_Image;

#endif

#ifndef _ELM_IMAGE_EO_TYPES
#define _ELM_IMAGE_EO_TYPES


#endif

/**
 * @brief Contrtol if thhe image is 'editable'.
 *
 * This means the image is a valid drag target for drag and drop, and can be
 * cut or pasted too.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] set Turn on or off editability. Default is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_editable_set(Elm_Image *obj, Eina_Bool set);

/**
 * @brief Contrtol if thhe image is 'editable'.
 *
 * This means the image is a valid drag target for drag and drop, and can be
 * cut or pasted too.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Turn on or off editability. Default is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_editable_get(const Elm_Image *obj);

/**
 * @brief Control the smooth effect for an image.
 *
 * Set the scaling algorithm to be used when scaling the image. Smooth scaling
 * provides a better resulting image, but is slower.
 *
 * The smooth scaling should be disabled when making animations that change the
 * image size, since it will be faster. Animations that don't require resizing
 * of the image can keep the smooth scaling enabled (even if the image is
 * already scaled, since the scaled image will be cached).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] smooth @c true if smooth scaling should be used, @c false
 * otherwise. Default is @c true.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_smooth_set(Elm_Image *obj, Eina_Bool smooth);

/**
 * @brief Control the smooth effect for an image.
 *
 * Set the scaling algorithm to be used when scaling the image. Smooth scaling
 * provides a better resulting image, but is slower.
 *
 * The smooth scaling should be disabled when making animations that change the
 * image size, since it will be faster. Animations that don't require resizing
 * of the image can keep the smooth scaling enabled (even if the image is
 * already scaled, since the scaled image will be cached).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true if smooth scaling should be used, @c false otherwise.
 * Default is @c true.
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_smooth_get(const Elm_Image *obj);

/**
 * @brief Control scaling behaviour of this object.
 *
 * This function disables scaling of the elm_image widget through the function
 * elm_object_scale_set(). However, this does not affect the widget size/resize
 * in any way. For that effect, take a look at @ref elm_image_resizable_get and
 * @ref elm_widget_scale_get
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] no_scale @c true if the object is not scalable, @c false
 * otherwise. Default is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_no_scale_set(Elm_Image *obj, Eina_Bool no_scale);

/**
 * @brief Control scaling behaviour of this object.
 *
 * This function disables scaling of the elm_image widget through the function
 * elm_object_scale_set(). However, this does not affect the widget size/resize
 * in any way. For that effect, take a look at @ref elm_image_resizable_get and
 * @ref elm_widget_scale_get
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true if the object is not scalable, @c false otherwise. Default
 * is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_no_scale_get(const Elm_Image *obj);

/**
 * @brief Control whether the original aspect ratio of the image should be kept
 * on resize.
 *
 * The original aspect ratio (width / height) of the image is usually distorted
 * to match the object's size. Enabling this option will retain this original
 * aspect, and the way that the image is fit into the object's area depends on
 * the option set by @ref elm_image_fill_outside_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] fixed @c true if the image should retain the aspect, @c false
 * otherwise.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_aspect_fixed_set(Elm_Image *obj, Eina_Bool fixed);

/**
 * @brief @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 *
 * @return @c true if the image should retain the aspect, @c false otherwise.
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_aspect_fixed_get(const Elm_Image *obj);

/**
 * @brief Contrtol the image orientation.
 *
 * This function allows to rotate or flip the given image.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] orient The image orientation Elm_Image_Orient Default is
 * #ELM_IMAGE_ORIENT_NONE.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_orient_set(Elm_Image *obj, Elm_Image_Orient orient);

/**
 * @brief Contrtol the image orientation.
 *
 * This function allows to rotate or flip the given image.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The image orientation Elm_Image_Orient Default is
 * #ELM_IMAGE_ORIENT_NONE.
 *
 * @ingroup Elm_Image
 */
EAPI Elm_Image_Orient elm_image_orient_get(const Elm_Image *obj);

/**
 * @brief Control if the image fills the entire object area, when keeping the
 * aspect ratio.
 *
 * When the image should keep its aspect ratio even if resized to another
 * aspect ratio, there are two possibilities to resize it: keep the entire
 * image inside the limits of height and width of the object ($fill_outside is
 * @c false) or let the extra width or height go outside of the object, and the
 * image will fill the entire object ($fill_outside is @c true).
 *
 * @note This option will have no effect if @ref elm_image_aspect_fixed_get is
 * set to @c false.
 *
 * See also @ref Elm.Image.fill_inside.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] fill_outside @c true if the object is filled outside, @c false
 * otherwise. Default is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_fill_outside_set(Elm_Image *obj, Eina_Bool fill_outside);

/**
 * @brief Control if the image fills the entire object area, when keeping the
 * aspect ratio.
 *
 * When the image should keep its aspect ratio even if resized to another
 * aspect ratio, there are two possibilities to resize it: keep the entire
 * image inside the limits of height and width of the object ($fill_outside is
 * @c false) or let the extra width or height go outside of the object, and the
 * image will fill the entire object ($fill_outside is @c true).
 *
 * @note This option will have no effect if @ref elm_image_aspect_fixed_get is
 * set to @c false.
 *
 * See also @ref Elm.Image.fill_inside.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true if the object is filled outside, @c false otherwise. Default
 * is @c false.
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_fill_outside_get(const Elm_Image *obj);

/**
 * @brief Control if the object is (up/down) resizable.
 *
 * This function limits the image resize ability. If @c size_up is set to
 * @c false, the object can't have its height or width resized to a value
 * higher than the original image size. Same is valid for @c size_down.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] up A bool to set if the object is resizable up. Default is
 * @c true.
 * @param[in] down A bool to set if the object is resizable down. Default is
 * @c true.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_resizable_set(Elm_Image *obj, Eina_Bool up, Eina_Bool down);

/**
 * @brief Control if the object is (up/down) resizable.
 *
 * This function limits the image resize ability. If @c size_up is set to
 * @c false, the object can't have its height or width resized to a value
 * higher than the original image size. Same is valid for @c size_down.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] up A bool to set if the object is resizable up. Default is
 * @c true.
 * @param[out] down A bool to set if the object is resizable down. Default is
 * @c true.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_resizable_get(const Elm_Image *obj, Eina_Bool *up, Eina_Bool *down);

/**
 * @brief Enable or disable preloading of the image
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] disabled If true, preloading will be disabled
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_preload_disabled_set(Elm_Image *obj, Eina_Bool disabled);

/**
 * @brief Set a location in memory to be used as an image object's source
 * bitmap.
 *
 * This function is handy when the contents of an image file are mapped in
 * memory, for example.
 *
 * The @c format string should be something like $"png", $"jpg", $"tga",
 * $"tiff", $"bmp" etc, when provided ($NULL, on the contrary). This improves
 * the loader performance as it tries the "correct" loader first, before trying
 * a range of other possible loaders until one succeeds.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] img The binary data that will be used as image source
 * @param[in] size The size of binary data blob @c img
 * @param[in] format (Optional) expected format of @c img bytes
 * @param[in] key Optional indexing key of @c img to be passed to the image
 * loader (eg. if @c img is a memory-mapped EET file)
 *
 * @return @c true = success, @c false = error
 *
 * @since 1.7
 *
 * @ingroup Elm_Image
 */
EAPI Eina_Bool elm_image_memfile_set(Elm_Image *obj, const void *img, size_t size, const char *format, const char *key);

/**
 * @brief Get the inlined image object of the image widget.
 *
 * This function allows one to get the underlying @c Evas_Object of type Image
 * from this elementary widget. It can be useful to do things like get the
 * pixel data, save the image to a file, etc.
 *
 * @note Be careful to not manipulate it, as it is under control of elementary.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The inlined image object, or NULL if none exists
 *
 * @ingroup Elm_Image
 */
EAPI Evas_Object *elm_image_object_get(const Elm_Image *obj);

/**
 * @brief Get the current size of the image.
 *
 * This is the real size of the image, not the size of the object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] w Pointer to store width, or NULL.
 * @param[out] h Pointer to store height, or NULL.
 *
 * @ingroup Elm_Image
 */
EAPI void elm_image_object_size_get(const Elm_Image *obj, int *w, int *h);

#endif
