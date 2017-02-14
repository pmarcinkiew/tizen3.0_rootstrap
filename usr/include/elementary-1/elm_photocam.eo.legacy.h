#ifndef _ELM_PHOTOCAM_EO_LEGACY_H_
#define _ELM_PHOTOCAM_EO_LEGACY_H_

#ifndef _ELM_PHOTOCAM_EO_CLASS_TYPE
#define _ELM_PHOTOCAM_EO_CLASS_TYPE

typedef Eo Elm_Photocam;

#endif

#ifndef _ELM_PHOTOCAM_EO_TYPES
#define _ELM_PHOTOCAM_EO_TYPES


#endif

/**
 * @brief Set the paused state for photocam
 *
 * This sets the paused state to on or off for photocam. The default is off.
 * This will stop zooming using animation on zoom level changes and change
 * instantly. This will stop any existing animations that are running.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] paused The pause state.
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_paused_set(Elm_Photocam *obj, Eina_Bool paused);

/**
 * @brief Get the paused state for photocam
 *
 * This gets the current paused state for the photocam object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The pause state.
 *
 * @ingroup Elm_Photocam
 */
EAPI Eina_Bool elm_photocam_paused_get(const Elm_Photocam *obj);

/**
 * @brief Set the gesture state for photocam.
 *
 * This sets the gesture state to on or off for photocam. The default is off.
 * This will start multi touch zooming.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] gesture The gesture state.
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_gesture_enabled_set(Elm_Photocam *obj, Eina_Bool gesture);

/**
 * @brief Get the gesture state for photocam.
 *
 * This gets the current gesture state for the photocam object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The gesture state.
 *
 * @ingroup Elm_Photocam
 */
EAPI Eina_Bool elm_photocam_gesture_enabled_get(const Elm_Photocam *obj);

/**
 * @brief Set the zoom level of the photo
 *
 * This sets the zoom level. If @c zoom is 1, it means no zoom. If it's smaller
 * than 1, it means zoom in. If it's bigger than 1, it means zoom out. For
 *  example, @c zoom 1 will be 1:1 pixel for pixel. @c zoom 2 will be 2:1 (that
 * is 2x2 photo pixels will display as 1 on-screen pixel) which is a zoom out.
 * 4:1 will be 4x4 photo pixels as 1 screen pixel, and so on. The @c zoom
 * parameter must be greater than 0. It is suggested to stick to powers of 2.
 * (1, 2, 4, 8, 16, 32, etc.).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] zoom The zoom level to set
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_zoom_set(Elm_Photocam *obj, double zoom);

/**
 * @brief Get the zoom level of the photo
 *
 * This returns the current zoom level of the photocam object. Note that if you
 * set the fill mode to other than #ELM_PHOTOCAM_ZOOM_MODE_MANUAL (which is the
 * default), the zoom level may be changed at any time by the  photocam object
 * itself to account for photo size and photocam viewport size.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The zoom level to set
 *
 * @ingroup Elm_Photocam
 */
EAPI double elm_photocam_zoom_get(const Elm_Photocam *obj);

/**
 * @brief Set the zoom mode
 *
 * This sets the zoom mode to manual or one of several automatic levels. Manual
 * (ELM_PHOTOCAM_ZOOM_MODE_MANUAL) means that zoom is set manually by
 * @ref elm_photocam_zoom_set and will stay at that level until changed by code
 * or until zoom mode is changed. This is the default mode. The Automatic modes
 * will allow the photocam object to automatically adjust zoom mode based on
 * properties.
 *
 * #ELM_PHOTOCAM_ZOOM_MODE_AUTO_FIT) will adjust zoom so the photo fits EXACTLY
 * inside the scroll frame with no pixels outside this region.
 * #ELM_PHOTOCAM_ZOOM_MODE_AUTO_FILL will be similar but ensure no pixels
 * within the frame are left unfilled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] mode The zoom mode.
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_zoom_mode_set(Elm_Photocam *obj, Elm_Photocam_Zoom_Mode mode);

/**
 * @brief Get the zoom mode
 *
 * This gets the current zoom mode of the photocam object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The zoom mode.
 *
 * @ingroup Elm_Photocam
 */
EAPI Elm_Photocam_Zoom_Mode elm_photocam_zoom_mode_get(const Elm_Photocam *obj);

/**
 * @brief Get the region of the image that is currently shown
 *
 * See also @ref elm_photocam_image_region_show.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x A pointer to the X-coordinate of region
 * @param[out] y A pointer to the Y-coordinate of region
 * @param[out] w A pointer to the width
 * @param[out] h A pointer to the height
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_image_region_get(const Elm_Photocam *obj, int *x, int *y, int *w, int *h);

/**
 * @brief Get the internal low-res image used for photocam
 *
 * This gets the internal image object inside photocam. Do not modify it. It is
 * for inspection only, and hooking callbacks to. Nothing else. It may be
 * deleted at any time as well.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The internal image object handle or @c null
 *
 * @ingroup Elm_Photocam
 */
EAPI Evas_Object *elm_photocam_internal_image_get(const Elm_Photocam *obj);

/**
 * @brief Get the current image pixel width and height
 *
 * This gets the current photo pixel width and height (for the original). The
 * size will be returned in the integers @c w and @c h that are pointed to.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] w A pointer to the width return
 * @param[out] h A pointer to the height return
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_image_size_get(const Elm_Photocam *obj, int *w, int *h);

/**
 * @brief Set the photocam image orientation.
 *
 * This function allows to rotate or flip the photocam image.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] orient The photocam image orientation @ref Evas_Image_Orient.
 * Default is #EVAS_IMAGE_ORIENT_NONE.
 *
 * @since 1.14
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_image_orient_set(Elm_Photocam *obj, Evas_Image_Orient orient);

/**
 * @brief Get the photocam image orientation.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The photocam image orientation @ref Evas_Image_Orient. Default is
 * #EVAS_IMAGE_ORIENT_NONE.
 *
 * @since 1.14
 *
 * @ingroup Elm_Photocam
 */
EAPI Evas_Image_Orient elm_photocam_image_orient_get(const Elm_Photocam *obj);

/**
 * @brief Set the viewed region of the image
 *
 * This shows the region of the image without using animation.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y Y-coordinate of region in image original pixels
 * @param[in] w Width of region in image original pixels
 * @param[in] h Height of region in image original pixels
 *
 * @ingroup Elm_Photocam
 */
EAPI void elm_photocam_image_region_show(Elm_Photocam *obj, int x, int y, int w, int h);

#endif
