#ifndef _ELM_THUMB_EO_LEGACY_H_
#define _ELM_THUMB_EO_LEGACY_H_

#ifndef _ELM_THUMB_EO_CLASS_TYPE
#define _ELM_THUMB_EO_CLASS_TYPE

typedef Eo Elm_Thumb;

#endif

#ifndef _ELM_THUMB_EO_TYPES
#define _ELM_THUMB_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief Set the compression for the thumb object.
 *
 * @param[in] compress The compression of the thumb.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_compress_set(Elm_Thumb *obj, int compress);

/**
 * @internal
 *
 * @brief Get the compression of the thumb object.
 *
 * @param[out] compress The compression of the thumb.
 *
 * @return Force the return type to be sure the argument doesn't become the
 * return
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_compress_get(const Elm_Thumb *obj, int *compress);

/**
 * @internal
 *
 * @brief Set the format for the thumb object.
 *
 * @param[in] format The format setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_format_set(Elm_Thumb *obj, Ethumb_Thumb_Format format);

/**
 * @internal
 *
 * @brief Get the format of the thumb object.
 *
 * @return The format setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI Ethumb_Thumb_Format elm_thumb_format_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Set the animation state for the thumb object.
 *
 * If its content is an animated video, you may start/stop the animation or
 * tell it o play continuously and looping.
 *
 * @param[in] setting The animation setting or #ELM_THUMB_ANIMATION_LAST
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_animate_set(Elm_Thumb *obj, Elm_Thumb_Animation_Setting setting);

/**
 * @internal
 *
 * @brief Get the animation state for the thumb object.
 *
 * @return The animation setting or #ELM_THUMB_ANIMATION_LAST
 *
 * @ingroup Elm_Thumb
 */
EAPI Elm_Thumb_Animation_Setting elm_thumb_animate_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Set the FDO size for the thumb object.
 *
 * @param[in] size The FDO size setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_fdo_size_set(Elm_Thumb *obj, Ethumb_Thumb_FDO_Size size);

/**
 * @internal
 *
 * @brief Get the fdo size of the thumb object.
 *
 * @return The FDO size setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI Ethumb_Thumb_FDO_Size elm_thumb_fdo_size_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Set the orientation for the thumb object.
 *
 * @param[in] orient The orientation setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_orientation_set(Elm_Thumb *obj, Ethumb_Thumb_Orientation orient);

/**
 * @internal
 *
 * @brief Get the orientation of the thumb object.
 *
 * @return The orientation setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI Ethumb_Thumb_Orientation elm_thumb_orientation_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Make the thumbnail 'editable'.
 *
 * This means the thumbnail is a valid drag target for drag and drop, and can
 * be cut or pasted too.
 *
 * @param[in] edit The editable state, default is @c false.
 *
 * @ingroup Elm_Thumb
 */
EAPI Eina_Bool elm_thumb_editable_set(Elm_Thumb *obj, Eina_Bool edit);

/**
 * @internal
 *
 * @brief Get whether the thumbnail is editable.
 *
 * This means the thumbnail is a valid drag target for drag and drop, and can
 * be cut or pasted too.
 *
 * @return The editable state, default is @c false.
 *
 * @ingroup Elm_Thumb
 */
EAPI Eina_Bool elm_thumb_editable_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Set the aspect for the thumb object.
 *
 * @param[in] aspect The aspect setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_aspect_set(Elm_Thumb *obj, Ethumb_Thumb_Aspect aspect);

/**
 * @internal
 *
 * @brief Get the aspect of the thumb object.
 *
 * @return The aspect setting.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI Ethumb_Thumb_Aspect elm_thumb_aspect_get(const Elm_Thumb *obj);

/**
 * @internal
 *
 * @brief Set the quality for the thumb object.
 *
 * @param[in] quality The quality of the thumb.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_quality_set(Elm_Thumb *obj, int quality);

/**
 * @internal
 *
 * @brief Get the quality of the thumb object.
 *
 * @param[out] quality The quality of the thumb.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_quality_get(const Elm_Thumb *obj, int *quality);

/**
 * @internal
 *
 * @brief Set the size for the thumb object.
 *
 * @param[in] tw The width of the thumb.
 * @param[in] th The height of the thumb.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_size_set(Elm_Thumb *obj, int tw, int th);

/**
 * @internal
 *
 * @brief Get the size of the thumb object.
 *
 * @param[out] tw The width of the thumb.
 * @param[out] th The height of the thumb.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_size_get(const Elm_Thumb *obj, int *tw, int *th);

/**
 * @internal
 *
 * @brief Set the crop alignment for the thumb object.
 *
 * @param[in] cropx The x coordinate of the crop.
 * @param[in] cropy The y coordinate of the crop.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_crop_align_set(Elm_Thumb *obj, double cropx, double cropy);

/**
 * @internal
 *
 * @brief Get the crop alignment of the thumb object.
 *
 * @param[out] cropx The x coordinate of the crop.
 * @param[out] cropy The y coordinate of the crop.
 *
 * @since 1.8
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_crop_align_get(const Elm_Thumb *obj, double *cropx, double *cropy);

/**
 * @internal
 *
 * @brief Get the path and key to the image or video
 * thumbnail generated by ethumb.
 *
 * One just needs to make sure that the thumbnail was generated before getting
 * its path; otherwise, the path will be @c null. One way to do that is by
 * asking for the path when/after the "generate,stop" smart callback is called.
 *
 * @param[out] file Pointer to thumb path.
 * @param[out] key Pointer to thumb key.
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_path_get(const Elm_Thumb *obj, const char **file, const char **key);

/**
 * @internal
 *
 * @brief Reload thumbnail if it was generated before.
 *
 * This is useful if the ethumb client configuration changed, like its size,
 * aspect or any other property one set in the handle returned by
 * elm_thumb_ethumb_client_get().
 *
 * If the options didn't change, the thumbnail won't be generated again, but
 * the old one will still be used.
 *
 * @ingroup Elm_Thumb
 */
EAPI void elm_thumb_reload(Elm_Thumb *obj);

#endif
