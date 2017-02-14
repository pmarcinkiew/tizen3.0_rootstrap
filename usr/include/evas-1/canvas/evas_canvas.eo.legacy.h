#ifndef _EVAS_CANVAS_EO_LEGACY_H_
#define _EVAS_CANVAS_EO_LEGACY_H_

#ifndef _EVAS_CANVAS_EO_CLASS_TYPE
#define _EVAS_CANVAS_EO_CLASS_TYPE

typedef Eo Evas_Canvas;

#endif

#ifndef _EVAS_CANVAS_EO_TYPES
#define _EVAS_CANVAS_EO_TYPES


#endif

/**
 * @brief Sets the output framespace size of the render engine of the given
 * evas.
 *
 * The framespace size is used in the Wayland engines to denote space where the
 * output is not drawn. This is mainly used in ecore_evas to draw borders.
 *
 * The units used for @c w and @c h depend on the engine used by the evas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] x The left coordinate in output units, usually pixels.
 * @param[in] y The top coordinate in output units, usually pixels.
 * @param[in] w The width in output units, usually pixels.
 * @param[in] h The height in output units, usually pixels.
 *
 * @since 1.1
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_framespace_set(Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Get the render engine's output framespace coordinates in canvas
 * units.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x The left coordinate in output units, usually pixels.
 * @param[out] y The top coordinate in output units, usually pixels.
 * @param[out] w The width in output units, usually pixels.
 * @param[out] h The height in output units, usually pixels.
 *
 * @since 1.1
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_framespace_get(const Evas_Canvas *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Sets the output viewport of the given evas in evas units.
 *
 * The output viewport is the area of the evas that will be visible to the
 * viewer.  The viewport will be stretched to fit the output target of the evas
 * when rendering is performed.
 *
 * @note The coordinate values do not have to map 1-to-1 with the output
 * target. However, it is generally advised that it is done for ease of use.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] x The top-left corner x value of the viewport.
 * @param[in] y The top-left corner y value of the viewport.
 * @param[in] w The width of the viewport.  Must be greater than 0.
 * @param[in] h The height of the viewport.  Must be greater than 0.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_viewport_set(Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Get the render engine's output viewport coordinates in canvas units.
 *
 * Calling this function writes the current canvas output viewport size and
 * location values into the variables pointed to by @c x, @c y, @c w and @c h.
 *  On success the variables have the output location and size values written
 * to them in canvas units. Any of @c x, @c y, @c w or @c h that are @c null
 * will not be written to. If @c e is invalid, the results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x The top-left corner x value of the viewport.
 * @param[out] y The top-left corner y value of the viewport.
 * @param[out] w The width of the viewport.  Must be greater than 0.
 * @param[out] h The height of the viewport.  Must be greater than 0.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_viewport_get(const Evas_Canvas *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Set the image cache.
 *
 * This function sets the image cache of canvas in bytes.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] size The cache size.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_image_cache_set(Evas_Canvas *obj, int size);

/**
 * @brief Get the image cache.
 *
 * This function returns the image cache size of canvas in bytes.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The cache size.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_image_cache_get(const Evas_Canvas *obj);

/**
 * @brief Set the default set of flags an event begins with
 *
 * Events in evas can have an event_flags member. This starts out with  and
 * initial value (no flags). This lets you set the default flags that an event
 * begins with to be @c flags.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] flags The default flags to use.
 *
 * @since 1.2
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_default_flags_set(Evas_Canvas *obj, Evas_Event_Flags flags);

/**
 * @brief Get the default set of flags an event begins with
 *
 * This gets the default event flags events are produced with when fed in.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The default flags to use.
 *
 * @since 1.2
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Event_Flags evas_event_default_flags_get(const Evas_Canvas *obj);

/**
 * @brief Sets the output engine for the given evas.
 *
 * Once the output engine for an evas is set, any attempt to change it  will be
 * ignored. The value for @c render_method can be found using @ref
 * evas_render_method_lookup.
 *
 * @note it is mandatory that one calls @ref evas_init before setting the
 * output method.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] render_method The numeric engine value to use.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_method_set(Evas_Canvas *obj, int render_method);

/**
 * @brief Retrieves the number of the output engine used for the given evas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The numeric engine value to use.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_output_method_get(const Evas_Canvas *obj);

/**
 * @brief Changes the size of font cache of the given evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] size The size in bytes.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_cache_set(Evas_Canvas *obj, int size);

/**
 * @brief Get the size of font cache of the given evas in bytes.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The size in bytes.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_font_cache_get(const Evas_Canvas *obj);

/**
 * @brief Sets the output size of the render engine of the given evas.
 *
 * The evas will render to a rectangle of the given size once this function is
 * called.  The output size is independent of the viewport size. The viewport
 * will be stretched to fill the given rectangle.
 *
 * The units used for @c w and @c h depend on the engine used by the evas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] w The width in output units, usually pixels.
 * @param[in] h The height in output units, usually pixels.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_size_set(Evas_Canvas *obj, int w, int h);

/**
 * @brief Retrieve the output size of the render engine of the given evas.
 *
 * The output size is given in whatever the output units are for the engine.
 *
 * If either @c w or @c h is @c null, then it is ignored.  If @c e is invalid,
 * the returned results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] w The width in output units, usually pixels.
 * @param[out] h The height in output units, usually pixels.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_output_size_get(const Evas_Canvas *obj, int *w, int *h);

/**
 * @brief Attaches a specific pointer to the evas for fetching later.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data The attached pointer.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_data_attach_set(Evas_Canvas *obj, void *data);

/**
 * @brief Returns the pointer attached by @ref evas_data_attach_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The attached pointer.
 *
 * @ingroup Evas_Canvas
 */
EAPI void *evas_data_attach_get(const Evas_Canvas *obj);

/**
 * @brief Changes the font hinting for the given evas.
 *
 * #EVAS_FONT_HINTING_AUTO, #EVAS_FONT_HINTING_BYTECODE.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] hinting The used hinting, one of #EVAS_FONT_HINTING_NONE,
 * #EVAS_FONT_HINTING_AUTO, #EVAS_FONT_HINTING_BYTECODE.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_hinting_set(Evas_Canvas *obj, Evas_Font_Hinting_Flags hinting);

/**
 * @brief Retrieves the font hinting used by the given evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The used hinting, one of #EVAS_FONT_HINTING_NONE,
 * #EVAS_FONT_HINTING_AUTO, #EVAS_FONT_HINTING_BYTECODE.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Font_Hinting_Flags evas_font_hinting_get(const Evas_Canvas *obj);

/**
 * @brief Applies the engine settings for the given evas from the given
 * @c Evas_Engine_Info structure.
 *
 * To get the Evas_Engine_Info structure to use, call
 * @ref evas_engine_info_get. Do not try to obtain a pointer to an
 * @c Evas_Engine_Info structure in any other way.
 *
 * You will need to call this function at least once before you can create
 * objects on an evas or render that evas. Some engines allow their settings to
 * be changed more than once.
 *
 * Once called, the @c info pointer should be considered invalid.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] info The pointer to the engine info to use.
 *
 * @return @c true if no error occurred, @c false otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_engine_info_set(Evas_Canvas *obj, Evas_Engine_Info *info);

/**
 * @brief Retrieves the current render engine info struct from the given evas.
 *
 * The returned structure is publicly modifiable.  The contents are valid until
 * either @ref evas_engine_info_set or @ref evas_render are called.
 *
 * This structure does not need to be freed by the caller.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The pointer to the engine info to use.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Engine_Info *evas_engine_info_get(const Evas_Canvas *obj);

/**
 * @brief Retrieve the object that currently has focus.
 *
 * Evas can have (at most) one of its objects focused at a time. Focused
 * objects will be the ones having key events delivered to, which the
 * programmer can act upon by means of @ref evas_object_event_callback_add
 * usage.
 *
 * @note Most users wouldn't be dealing directly with Evas' focused objects.
 * Instead, they would be using a higher level library for that (like a
 * toolkit, as Elementary) to handle focus and who's receiving input for them.
 *
 * This call returns the object that currently has focus on the canvas @c e or
 * @c null, if none.
 *
 * See also @ref evas_object_focus_set, @ref evas_object_focus_get, @ref
 * evas_object_key_grab, @ref evas_object_key_ungrab.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The object that has focus or @c null if there is not one.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_focus_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Get the highest (stacked) Evas object on the canvas @c e.
 *
 * This function will take all populated layers in the canvas into account,
 * getting the highest object for the highest layer, naturally.
 *
 * @warning This function will skip objects parented by smart objects, acting
 * only on the ones at the "top level", with regard to object parenting.
 *
 * See also @ref evas_object_layer_get, @ref evas_object_layer_set, @ref
 * evas_object_below_get, @ref evas_object_above_get.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return A pointer to the highest object on it (if any) or @c null otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_object_top_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Returns a handle to the list of lock keys registered in the canvas
 * @c e.
 *
 * This is required to check for which locks are set at a given time with the
 * @ref evas_key_lock_is_set function.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return An Evas_Lock handle to query Evas' keys subsystem with @ref
 * evas_key_lock_is_set, or @c null on error.
 *
 * @ingroup Evas_Canvas
 */
EAPI const Evas_Lock *evas_key_lock_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief This function returns the current known pointer coordinates
 *
 * This function returns the current known canvas unit coordinates of the mouse
 * pointer and sets the contents of the Evas_Coords pointed to by @c x and @c y
 * to contain these coordinates. If @c e is not a valid canvas the results of
 * this function are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x The pointer to a Evas_Coord to be filled in.
 * @param[out] y The pointer to a Evas_Coord to be filled in.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_pointer_canvas_xy_get(const Evas_Canvas *obj, Evas_Coord *x, Evas_Coord *y);

/**
 * @brief Get the number of mouse or multi presses currently active.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @since 1.2
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_event_down_count_get(const Evas_Canvas *obj);

/**
 * @brief This gets the internal counter that counts the number of smart
 * calculations.
 *
 * Whenever evas performs smart object calculations on the whole canvas it
 * increments a counter by 1. This is the smart object calculate counter that
 * this function returns the value of. It starts at the value of 0 and will
 * increase (and eventually wrap around to negative values and so on) by 1
 * every time objects are calculated. You can use this counter to ensure you
 * don't re-do calculations withint the same calculation generation/run if the
 * calculations maybe cause self-feeding effects.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @since 1.1
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_smart_objects_calculate_count_get(const Evas_Canvas *obj);

/**
 * @brief Get the focus state known by the given evas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_focus_state_get(const Evas_Canvas *obj);

/**
 * @internal
 *
 * Get the changed marker for the canvas.
 *
 * @since 1.11
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_changed_get(const Evas_Canvas *obj);

/**
 * @brief This function returns the current known pointer coordinates.
 *
 * This function returns the current known screen/output coordinates of the
 * mouse pointer and sets the contents of the integers pointed to by @c x and
 * @c y to contain these coordinates. If @c e is not a valid canvas the results
 * of this function are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x The pointer to an integer to be filled in.
 * @param[out] y The pointer to an integer to be filled in.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_pointer_output_xy_get(const Evas_Canvas *obj, int *x, int *y);

/**
 * @brief Returns whether the mouse pointer is logically inside the canvas.
 *
 * When this function is called it will return a value of either @c false or
 * @c true, depending on if @ref evas_event_feed_mouse_in or
 * @ref evas_event_feed_mouse_out have been called to feed in a  mouse enter
 * event into the canvas.
 *
 * A return value of @c true indicates the mouse is logically inside the
 * canvas, and @c false implies it is logically outside the canvas.
 *
 * A canvas begins with the mouse being assumed outside ($false).
 *
 * If @c e is not a valid canvas, the return value is undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_pointer_inside_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Get the maximum image size evas can possibly handle.
 *
 * This function returns the largest image or surface size that evas can handle
 * in pixels, and if there is one, returns @c true. It returns @c false if no
 * extra constraint on maximum image size exists. You still should check the
 * return values of @c maxw and @c maxh as there may still be a limit, just a
 * much higher one.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] maxw Pointer to hold the return value in pixels of the maximum
 * width.
 * @param[out] maxh Pointer to hold the return value in pixels of the maximum
 * height.
 *
 * @since 1.1
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_image_max_size_get(const Evas_Canvas *obj, int *maxw, int *maxh);

/**
 * @brief Get the lowest (stacked) Evas object on the canvas @c e.
 *
 * This function will take all populated layers in the canvas into account,
 * getting the lowest object for the lowest layer, naturally.
 *
 * @warning This function will skip objects parented by smart objects, acting
 * only on the ones at the "top level", with regard to object parenting.
 *
 * See also @ref evas_object_layer_get, @ref evas_object_layer_set, @ref
 * evas_object_below_get, @ref evas_object_below_set.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return A pointer to the lowest object on it, if any, or @c null otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_object_bottom_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Returns a handle to the list of modifier keys registered in the
 * canvas @c e.
 *
 * This is required to check for which modifiers are set at a given time with
 * the @ref evas_key_modifier_is_set function.
 *
 * See also @ref evas_key_modifier_add, @ref evas_key_modifier_del,
 * @ref evas_key_modifier_on, @ref evas_key_modifier_off.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return An Evas_Modifier handle to query Evas' keys subsystem with @ref
 * evas_key_modifier_is_set, or @c null on error.
 *
 * @ingroup Evas_Canvas
 */
EAPI const Evas_Modifier *evas_key_modifier_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Returns a bitmask with the mouse buttons currently pressed, set to 1.
 *
 * Calling this function will return a 32-bit integer with the appropriate bits
 * set to 1 that correspond to a mouse button being depressed. This limits Evas
 * to a mouse devices with a maximum of 32 buttons, but that is generally in
 * excess of any host system's pointing device abilities.
 *
 * A canvas by default begins with no mouse buttons being pressed and only
 * calls to @ref evas_event_feed_mouse_down and @ref evas_event_feed_mouse_up
 * will alter that.
 *
 * The least significant bit corresponds to the first mouse button (button 1)
 * and the most significant bit corresponds to the last mouse button (button
 * 32).
 *
 * If @c e is not a valid canvas, the return value is undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A bitmask of the currently depressed buttons on the canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_pointer_button_down_mask_get(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Retrieve a list of Evas objects lying over a given position in a
 * canvas.
 *
 * This function will traverse all the layers of the given canvas, from top to
 * bottom, querying for objects with areas covering the given position. It will
 * enter the smart objects. It will not append to the list pass events as
 * hidden objects. Call eina_list_free on the returned list after usage.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] x The horizontal coordinate of the position.
 * @param[in] y The vertical coordinate of the position.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_List *evas_tree_objects_at_xy_get(Evas_Canvas *obj, Evas_Object *stop, int x, int y) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Mouse wheel event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * wheel is scrolled up or down. It prepares information to  be treated by the
 * callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] z How much mouse wheel was scrolled up or down.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_wheel(Evas_Canvas *obj, int direction, int z, unsigned int timestamp, const void *data);

/**
 * @brief Enables or turns on programmatically the lock key with name
 * @c keyname.
 *
 * The effect will be as if the key was put on its active state after this
 * call.
 *
 * See also @ref evas_key_lock_add, @ref evas_key_lock_del,
 * @ref evas_key_lock_del, @ref evas_key_lock_off.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the lock to enable.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_lock_on(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Key down event feed.
 *
 * This function will set some evas properties that is necessary when a key is
 * pressed. It prepares information to be treated by the callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] key The key pressed.
 * @param[in] string A string.
 * @param[in] compose The compose string.
 * @param[in] timestamp Timestamp of the mouse up event.
 * @param[in] data Data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_key_down(Evas_Canvas *obj, const char *keyname, const char *key, const char *string, const char *compose, unsigned int timestamp, const void *data);

/**
 * @brief Creates a bit mask from the @c keyname modifier key. Values returned
 * from different calls to it may be ORed together, naturally.
 *
 * This function is meant to be using in conjunction with @ref
 * evas_object_key_grab/\@ref evas_object_key_ungrab. Go check their
 * documentation for more information.
 *
 * See also @ref evas_key_modifier_add, @ref evas_key_modifier_get,
 * @ref evas_key_modifier_on, @ref evas_key_modifier_off, @ref
 * evas_key_modifier_is_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the modifier key to create the mask for.
 *
 * @return The bit mask or 0 if the @c keyname key wasn't registered as a
 * modifier for canvas @c e.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Modifier_Mask evas_key_modifier_mask_get(const Evas_Canvas *obj, const char *keyname) EINA_WARN_UNUSED_RESULT EINA_ARG_NONNULL(2);

/**
 * @brief Adds the @c keyname key to the current list of modifier keys.
 *
 * Modifiers are keys like shift, alt and ctrl, i.e., keys which are meant to
 * be pressed together with others, altering the behavior of the secondly
 * pressed keys somehow. Evas is so that these keys can be user defined.
 *
 * This call allows custom modifiers to be added to the Evas system at run
 * time. It is then possible to set and unset modifier keys programmatically
 * for other parts of the program to check and act on. Programmers using Evas
 * would check for modifier keys on key event callbacks using @ref
 * evas_key_modifier_is_set.
 *
 * @note If the programmer instantiates the canvas by means of the @ref
 * ecore_evas_new family of helper functions, Ecore will take care of
 * registering on it all standard modifiers: "Shift", "Control", "Alt", "Meta",
 * "Hyper", "Super".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the modifier key to add to the list of Evas
 * modifiers.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_modifier_add(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Disables or turns off programmatically the modifier key with name
 * @c keyname.
 *
 * See also @ref evas_key_modifier_add, @ref evas_key_modifier_get,
 * @ref evas_key_modifier_on, @ref evas_key_modifier_mask_get, @ref
 * evas_key_modifier_is_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the modifier to disable.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_modifier_off(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Hold event feed.
 *
 * This function makes the object to stop sending events.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_hold(Evas_Canvas *obj, int hold, unsigned int timestamp, const void *data);

/**
 * @brief Mouse move event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * is moved from its last position. It prepares information to be treated by
 * the callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] y The vertical position of the mouse pointer.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_move(Evas_Canvas *obj, int x, int y, unsigned int timestamp, const void *data);

/**
 * @brief Key up event feed.
 *
 * This function will set some evas properties that is necessary when a key is
 * released. It prepares information to be treated by the callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] key The key released.
 * @param[in] string A string.
 * @param[in] compose Compose.
 * @param[in] timestamp Timestamp of the mouse up event.
 * @param[in] data Data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_key_up(Evas_Canvas *obj, const char *keyname, const char *key, const char *string, const char *compose, unsigned int timestamp, const void *data);

/**
 * @brief Mouse out event feed.
 *
 * This function will set some evas properties that is necessar when the mouse
 * out event happens. It prepares information to be treated by the callback
 * function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_out(Evas_Canvas *obj, unsigned int timestamp, const void *data);
EAPI void evas_event_input_multi_move(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, unsigned int timestamp, const void *data);

/**
 * @brief Retrieve a list of Evas objects lying over a given position in a
 * canvas.
 *
 * This function will traverse all the layers of the given canvas, from top to
 * bottom, querying for objects with areas covering the given position. The
 * user can remove from query objects which are hidden and/or which are set to
 * pass events.
 *
 * @warning This function will skip objects parented by smart objects, acting
 * only on the ones at the "top level", with regard to object parenting.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] y The vertical coordinate of the position.
 * @param[in] include_pass_events_objects Boolean flag to include or not
 * objects which pass events in this calculation.
 * @param[in] include_hidden_objects Boolean flag to include or not hidden
 * objects in this calculation.
 *
 * @return The list of Evas objects that are over the given position in @c e.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_List *evas_objects_at_xy_get(const Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Eina_Bool include_pass_events_objects, Eina_Bool include_hidden_objects) EINA_WARN_UNUSED_RESULT;
EAPI void evas_event_input_multi_up(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, Evas_Button_Flags flags, unsigned int timestamp, const void *data);
EAPI void evas_event_feed_multi_down(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, Evas_Button_Flags flags, unsigned int timestamp, const void *data);

/**
 * @internal
 *
 * @brief Render the given Evas canvas asynchronously.
 *
 * This function only returns @c true when a frame will be rendered. If the
 * previous frame is still rendering, @c false will be returned  so the users
 * know not to wait for the updates callback and just  return to their main
 * loop.
 *
 * If a @c func callback is given, a list of updated areas will be generated
 * and the function will be called from the main thread after the rendered
 * frame is flushed to the screen. The resulting list should be freed with @ref
 * evas_render_updates_free.
 *
 * The list is given in the @c event_info parameter of the callback function.
 *
 * @return @c true if the canvas will render, @c false otherwise.
 *
 * @since 1.8
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_render_async(Evas_Canvas *obj);

/**
 * @internal
 *
 * @brief Render the given Evas canvas using the new
 * rendering infra.
 *
 * This is experimental and will change over time until noted here.
 *
 * This function only returns @c true when a frame will be rendered. If the
 * previous frame is still rendering, @c false will be returned so the users
 * know not to wait for the updates callback and just return to their main
 * loop.
 *
 * @return @c true if the canvas will render, @c false otherwise.
 *
 * @since 1.14
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_render2(Evas_Canvas *obj);

/**
 * @internal
 *
 * @brief Render the given Evas canvas using the new
 * rendering infra.
 *
 * This is experimental and will change over time until noted here.
 *
 * @return A newly allocated list of updated rectangles of the canvas
 * ($Eina.Rectangle structs). Free this list with @ref
 * evas_render_updates_free.
 *
 * @since 1.15
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_List *evas_render2_updates(Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Inform to the evas that it lost the focus.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_focus_out(Evas_Canvas *obj);

/**
 * @brief Mouse move event feed from input.
 *
 * Similar to the @ref evas_event_feed_mouse_move, this function will inform
 * Evas about mouse move events which were received by the input system,
 * relative to the 0,0 of the window, not to the canvas 0,0. It will take care
 * of doing any special transformation like adding the framespace offset to the
 * mouse event.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] y The vertical position of the mouse pointer relative to the 0,0
 * of the window/surface.
 * @param[in] timestamp The timestamp of the mouse move event.
 * @param[in] data The data for canvas.
 *
 * @since 1.8
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_input_mouse_move(Evas_Canvas *obj, int x, int y, unsigned int timestamp, const void *data);

/**
 * @brief Update the canvas internal objects but not triggering immediate
 * renderization.
 *
 * This function updates the canvas internal objects not triggering
 * renderization. To force renderization function @ref evas_render should be
 * used.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_norender(Evas_Canvas *obj);

/**
 * @brief Get the number of touched point in the evas.
 *
 * New touched point is added to the list whenever touching the evas and point
 * is removed whenever removing touched point from the evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The number of touched point on the evas.
 *
 * @ingroup Evas_Canvas
 */
EAPI unsigned int evas_touch_point_list_count(Evas_Canvas *obj);
EAPI void evas_event_input_multi_down(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, Evas_Button_Flags flags, unsigned int timestamp, const void *data);

/**
 * @brief Pop the nochange flag down 1.
 *
 * This tells evas, that while the nochange flag is greater than 0, do not mark
 * objects as "changed" when making changes.
 *
 * @warning Do not use this function unless you know what Evas exactly works
 * with "changed" state.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_nochange_pop(Evas_Canvas *obj);

/**
 * @brief Disables or turns off programmatically the lock key with name
 * @c keyname.
 *
 * The effect will be as if the key was put on its inactive state after this
 * call.
 *
 * See also @ref evas_key_lock_on.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the lock to disable.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_lock_off(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Push the nochange flag up 1
 *
 * This tells evas, that while the nochange flag is greater than 0, do not mark
 * objects as "changed" when making changes.
 *
 * @warning Do not use this function unless you know what Evas exactly works
 * with "changed" state.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_nochange_push(Evas_Canvas *obj);

/**
 * @brief Force the given evas and associated engine to flush its font cache.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_cache_flush(Evas_Canvas *obj);

/**
 * @brief Checks if the font hinting is supported by the given evas.
 *
 * One of #EVAS_FONT_HINTING_NONE, #EVAS_FONT_HINTING_AUTO,
 * #EVAS_FONT_HINTING_BYTECODE.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] hinting The hinting to use.
 *
 * @return @c true if it is supported, @c false otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_Bool evas_font_hinting_can_hint(const Evas_Canvas *obj, Evas_Font_Hinting_Flags hinting) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Retrieve the Evas object stacked at the top of a given position in a
 * canvas.
 *
 * This function will traverse all the layers of the given canvas, from top to
 * bottom, querying for objects with areas covering the given position. The
 * user can remove from the query objects which are hidden and/or which are set
 * to pass events.
 *
 * @warning This function will skip objects parented by smart objects, acting
 * only on the ones at the "top level", with regard to object parenting.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] y The vertical coordinate of the position.
 * @param[in] include_pass_events_objects Boolean flag to include or not
 * objects which pass events in this calculation.
 * @param[in] include_hidden_objects Boolean flag to include or not hidden
 * objects in this calculation.
 *
 * @return The Evas object that is over all other objects at the given
 * position.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_object_top_at_xy_get(const Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Eina_Bool include_pass_events_objects, Eina_Bool include_hidden_objects) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Enables or turns on programmatically the modifier key with name
 * @c keyname.
 *
 * The effect will be as if the key was pressed for the whole time between this
 * call and a matching evas_key_modifier_off().
 *
 * See also @ref evas_key_modifier_off.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the modifier to enable.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_modifier_on(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Mouse up event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * button is released. It prepares information to be treated by the callback
 * function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] flags Evas button flags.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_up(Evas_Canvas *obj, int b, Evas_Button_Flags flags, unsigned int timestamp, const void *data);

/**
 * @brief Mouse down event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * button is pressed. It prepares information to be treated by the callback
 * function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] flags Evas button flags.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_down(Evas_Canvas *obj, int b, Evas_Button_Flags flags, unsigned int timestamp, const void *data);

/**
 * @brief Re feed event.
 *
 * This function re-feeds the event pointed by event_copy.
 *
 * This function call evas_event_feed_* functions, so it can cause havoc if not
 * used wisely. Please use it responsibly.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] event_type Event type.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_refeed_event(Evas_Canvas *obj, void *event_copy, Evas_Callback_Type event_type);

/**
 * @brief List of available font descriptions known or found by this evas.
 *
 * The list depends on Evas compile time configuration, such as fontconfig
 * support, and the paths provided at runtime as explained in @ref
 * Evas_Font_Path_Group.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return A newly allocated list of strings. Do not change the strings. Be
 * sure to call @ref evas_font_available_list_free after you're done.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_List *evas_font_available_list(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;
EAPI Eina_List *evas_objects_in_rectangle_get(const Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h, Eina_Bool include_pass_events_objects, Eina_Bool include_hidden_objects) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Retrieves the object on the given evas with the given name.
 *
 * This looks for the evas object given a name by @ref evas_object_name_set. If
 * the name is not unique canvas-wide, then which one of the many objects with
 * that name is returned is undefined, so only use this if you can ensure the
 * object name is unique.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] name The given name.
 *
 * @return If successful, the Evas object with the given name. Otherwise,
 * @c null.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_object_name_find(const Evas_Canvas *obj, const char *name) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Appends a font path to the list of font paths used by the given evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] path The new font path.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_path_append(Evas_Canvas *obj, const char *path) EINA_ARG_NONNULL(2);

/**
 * @brief This function returns the @c id of nth touch point.
 *
 * The point which comes from Mouse Event has @c id 0 and The point which comes
 * from Multi Event has @c id that is same as Multi Event's device id.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] n The number of the touched point (0 being the first).
 *
 * @return id of nth touch point, if the call succeeded, -1 otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_touch_point_list_nth_id_get(Evas_Canvas *obj, unsigned int n);

/**
 * @brief Removes all font paths loaded into memory for the given evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_path_clear(Evas_Canvas *obj);

/**
 * @brief Call user-provided @c calculate smart functions and unset the flag
 * signalling that the object needs to get recalculated to all smart objects in
 * the canvas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_smart_objects_calculate(Evas_Canvas *obj);

/**
 * @brief This function returns the nth touch point's coordinates.
 *
 * Touch point's coordinates is updated whenever moving that point on the
 * canvas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] x The pointer to a Evas_Coord to be filled in.
 * @param[out] y The pointer to a Evas_Coord to be filled in.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_touch_point_list_nth_xy_get(Evas_Canvas *obj, unsigned int n, Evas_Coord *x, Evas_Coord *y);

/**
 * @brief Removes the @c keyname key from the current list of lock keys on
 * canvas @c e.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the key to remove from the locks list.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_lock_del(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Add a damage rectangle.
 *
 * This is the function by which one tells evas that a part of the canvas has
 * to be repainted.
 *
 * @note All newly created Evas rectangles get the default color values of 255
 * 255 255 255 (opaque white).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y The rectangle's top position.
 * @param[in] w The rectangle's width.
 * @param[in] h The rectangle's height.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_damage_rectangle_add(Evas_Canvas *obj, int x, int y, int w, int h);
EAPI void evas_sync(Evas_Canvas *obj);

/**
 * @brief Retrieves the list of font paths used by the given evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The list of font paths used.
 *
 * @ingroup Evas_Canvas
 */
EAPI const Eina_List *evas_font_path_list(const Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Reload the image cache.
 *
 * This function reloads the image cache of canvas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_image_cache_reload(Evas_Canvas *obj);

/**
 * @brief Convert/scale a canvas coordinate into output screen coordinates.
 *
 * This function takes in a horizontal coordinate as the @c x parameter and
 * converts it into output units, accounting for output size, viewport size and
 * location, returning it as the function  return value. If @c e is invalid,
 * the results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] x The canvas x coordinate.
 *
 * @return The output/screen coordinate translated to output coordinates.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_coord_world_x_to_screen(const Evas_Canvas *obj, Evas_Coord x) EINA_WARN_UNUSED_RESULT;
EAPI void evas_event_feed_multi_move(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, unsigned int timestamp, const void *data);

/**
 * @brief Force immediate renderization of the given Evas canvas.
 *
 * This function forces an immediate renderization update of the given canvas
 * @c e.
 *
 * @note This is a very low level function, which most of Evas' users wouldn't
 * care about. One would use it, for example, to grab an Evas' canvas update
 * regions and paint them back, using the canvas' pixmap, on a displaying
 * system working below Evas.
 *
 * @note Evas is a stateful canvas. If no operations changing its state took
 * place since the last rendering action, you won't see no changes and this
 * call will be a no-op.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A newly allocated list of updated rectangles of the canvas
 * ($Eina.Rectangle structs). Free this list with @ref
 * evas_render_updates_free.
 *
 * @ingroup Evas_Canvas
 */
EAPI Eina_List *evas_render_updates(Evas_Canvas *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Flush the image cache of the canvas.
 *
 * This function flushes image cache of canvas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_image_cache_flush(Evas_Canvas *obj);

/**
 * @brief Convert/scale an output screen coordinate into canvas coordinates.
 *
 * This function takes in a vertical coordinate as the @c y parameter and
 * converts it into canvas units, accounting for output size, viewport size and
 * location, returning it as the function return value. If @c e is invalid, the
 * results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y The screen/output y coordinate.
 *
 * @return The screen coordinate translated to canvas unit coordinates.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Coord evas_coord_screen_y_to_world(const Evas_Canvas *obj, int y) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Removes the @c keyname key from the current list of modifier keys on
 * canvas @c e.
 *
 * See also @ref evas_key_modifier_add.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the key to remove from the modifiers list.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_modifier_del(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief This function returns the @c state of nth touch point.
 *
 * The point's @c state is EVAS_TOUCH_POINT_DOWN when pressed,
 * EVAS_TOUCH_POINT_STILL when the point is not moved after pressed,
 * EVAS_TOUCH_POINT_MOVE when moved at least once after pressed and
 * EVAS_TOUCH_POINT_UP when released.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] n The number of the touched point (0 being the first).
 *
 * @return @c state of nth touch point, if the call succeeded,
 * EVAS_TOUCH_POINT_CANCEL otherwise.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Touch_Point_State evas_touch_point_list_nth_state_get(Evas_Canvas *obj, unsigned int n);

/**
 * @brief Inform to the evas that it got the focus.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_focus_in(Evas_Canvas *obj);

/**
 * @brief Add an "obscured region" to an Evas canvas.
 *
 * This is the function by which one tells an Evas canvas that a part of it
 * must not be repainted. The region must be rectangular and its coordinates
 * inside the canvas viewport are passed in the call. After this call, the
 * region specified won't participate in any form in Evas' calculations and
 * actions during its rendering updates, having its displaying content frozen
 * as it was just after this function took place.
 *
 * We call it "obscured region" because the most common use case for this
 * rendering (partial) freeze is something else (most probably other canvas)
 * being on top of the specified rectangular region, thus shading it completely
 * from the user's final scene in a display. To avoid unnecessary processing,
 * one should indicate to the obscured canvas not to bother about the
 * non-important area.
 *
 * The majority of users won't have to worry about this function, as they'll be
 * using just one canvas in their applications, with nothing inset or on top of
 * it in any form.
 *
 * To make this region one that has to be repainted again, call the function
 * @ref evas_obscured_clear.
 *
 * @note This is a very low level function, which most of Evas' users wouldn't
 * care about.
 *
 * @note This function does not flag the canvas as having its state changed. If
 * you want to re-render it afterwards expecting new contents, you have to add
 * "damage" regions yourself (see @ref evas_damage_rectangle_add).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y The rectangle's top left corner's vertical coordinate.
 * @param[in] w The rectangle's width.
 * @param[in] h The rectangle's height.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_obscured_rectangle_add(Evas_Canvas *obj, int x, int y, int w, int h);

/**
 * @brief Make the canvas discard as much data as possible used by the engine
 * at runtime.
 *
 * This function will unload images, delete textures and much more, where
 * possible. You may also want to call @ref evas_render_idle_flush immediately
 * prior to this to perhaps discard a little more, though this function should
 * implicitly delete most of what @ref evas_render_idle_flush might discard
 * too.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_render_dump(Evas_Canvas *obj);

/**
 * @brief Get a image from evas
 *
 * @param[in] stride
 * @param[in] width
 * @param[in] height
 * @param[in] format
 * @param[in] sx
 * @param[in] sy
 * @param[in] sw
 * @param[in] sh
 * @param[in] dx
 * @param[in] dy
 * @param[in] dw
 * @param[in] dh
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_render_copy(Evas_Canvas *obj, void *buffer, int stride, int width, int height, unsigned int format, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh);

/**
 * @brief Mouse in event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * in event happens. It prepares information to be treated by the callback
 * function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_in(Evas_Canvas *obj, unsigned int timestamp, const void *data);

/**
 * @brief Retrieve the Evas object stacked at the top of a given rectangular
 * region in a canvas
 *
 * This function will traverse all the layers of the given canvas, from top to
 * bottom, querying for objects with areas overlapping with the given
 * rectangular region inside @c e. The user can remove from the query objects
 * which are hidden and/or which are set to pass events.
 *
 * @warning This function will skip objects parented by smart objects, acting
 * only on the ones at the "top level", with regard to object parenting.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] y The top left corner's vertical coordinate for the rectangular
 * region.
 * @param[in] w The width of the rectangular region.
 * @param[in] h The height of the rectangular region.
 * @param[in] include_pass_events_objects Boolean flag to include or not
 * objects which pass events in this calculation.
 * @param[in] include_hidden_objects Boolean flag to include or not hidden
 * objects in this calculation.
 *
 * @return The Evas object that is over all other objects at the given
 * rectangular region.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Object *evas_object_top_in_rectangle_get(const Evas_Canvas *obj, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h, Eina_Bool include_pass_events_objects, Eina_Bool include_hidden_objects) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Force renderization of the given canvas.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_render(Evas_Canvas *obj);
EAPI void evas_event_feed_multi_up(Evas_Canvas *obj, int d, int x, int y, double rad, double radx, double rady, double pres, double ang, double fx, double fy, Evas_Button_Flags flags, unsigned int timestamp, const void *data);

/**
 * @brief Prepends a font path to the list of font paths used by the given
 * evas.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] path The new font path.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_font_path_prepend(Evas_Canvas *obj, const char *path) EINA_ARG_NONNULL(2);

/**
 * @brief Remove all "obscured regions" from an Evas canvas.
 *
 * This function removes all the rectangles from the obscured regions list of
 * the canvas @c e. It takes obscured areas added with
 * @ref evas_obscured_rectangle_add and make them again a regions that have to
 * be repainted on rendering updates.
 *
 * @note This is a very low level function, which most of Evas' users wouldn't
 * care about.
 *
 * @note This function does not flag the canvas as having its state changed. If
 * you want to re-render it afterwards expecting new contents, you have to add
 * "damage" regions yourself (see @ref evas_damage_rectangle_add).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_obscured_clear(Evas_Canvas *obj);

/**
 * @brief Mouse cancel event feed.
 *
 * This function will call @ref evas_event_feed_mouse_up when a mouse cancel
 * event happens.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] data The data for canvas.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_cancel(Evas_Canvas *obj, unsigned int timestamp, const void *data);

/**
 * @brief Convert/scale an output screen coordinate into canvas coordinates.
 *
 * This function takes in a horizontal coordinate as the @c x parameter and
 * converts it into canvas units, accounting for output size, viewport size and
 * location, returning it as the function return value. If @c e is invalid, the
 * results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] x The screen/output x coordinate.
 *
 * @return The screen coordinate translated to canvas unit coordinates.
 *
 * @ingroup Evas_Canvas
 */
EAPI Evas_Coord evas_coord_screen_x_to_world(const Evas_Canvas *obj, int x) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Adds the @c keyname key to the current list of lock keys.
 *
 * Locks are keys like caps lock, num lock or scroll lock, i.e., keys which are
 * meant to be pressed once -- toggling a binary state which is bound to it --
 * and thus altering the behavior of all  subsequently pressed keys somehow,
 * depending on its state. Evas is so that these keys can be defined by the
 * user.
 *
 * This allows custom locks to be added to the evas system at run time. It is
 * then possible to set and unset lock keys programmatically for other parts of
 * the program to check and act on. Programmers using Evas would check for lock
 * keys on key event callbacks using @ref evas_key_lock_is_set.
 *
 * @note If the programmer instantiates the canvas by means of the
 * ecore_evas_new() family of helper functions, Ecore will take care of
 * registering on it all standard lock keys: "Caps_Lock", "Num_Lock",
 * "Scroll_Lock".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] keyname The name of the key to add to the locks list.
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_key_lock_add(Evas_Canvas *obj, const char *keyname) EINA_ARG_NONNULL(2);

/**
 * @brief Make the canvas discard internally cached data used for rendering.
 *
 * This function flushes the arrays of delete, active and render objects. Other
 * things it may also discard are: shared memory segments, temporary scratch
 * buffers, cached data to avoid re-compute of that data etc.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_render_idle_flush(Evas_Canvas *obj);

/**
 * @brief Convert/scale a canvas coordinate into output screen coordinates.
 *
 * This function takes in a vertical coordinate as the @c x parameter and
 * converts it into output units, accounting for output size, viewport size and
 * location, returning it as the function return value. If @c e is invalid, the
 * results are undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y The canvas y coordinate.
 *
 * @return The output/screen coordinate translated to output coordinates.
 *
 * @ingroup Evas_Canvas
 */
EAPI int evas_coord_world_y_to_screen(const Evas_Canvas *obj, Evas_Coord y) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Key down event feed with keycode.
 *
 * This function will set some evas properties that is necessary when a key is
 * pressed. It prepares information to be treated by the callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] key The key released.
 * @param[in] string A string.
 * @param[in] compose Compose.
 * @param[in] timestamp Timestamp of the mouse up event.
 * @param[in] data Data for canvas.
 * @param[in] keycode Key scan code numeric value for canvas.
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_key_down_with_keycode(Evas_Canvas *obj, const char *keyname, const char *key, const char *string, const char *compose, unsigned int timestamp, const void *data, unsigned int keycode);

/**
 * @brief Key up event feed with keycode.
 *
 * This function will set some evas properties that is necessary when a key is
 * released. It prepares information to be treated by the callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] key The key released.
 * @param[in] string A string.
 * @param[in] compose Compose.
 * @param[in] timestamp Timestamp of the mouse up event.
 * @param[in] data Data for canvas.
 * @param[in] keycode Key scan code numeric value for canvas.
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_key_up_with_keycode(Evas_Canvas *obj, const char *keyname, const char *key, const char *string, const char *compose, unsigned int timestamp, const void *data, unsigned int keycode);

/**
 * @brief Input device axis update event feed.
 *
 * This function will set some evas properties that is necessary when an e.g.
 * stylus axis is updated. It prepares information to be treated by the
 * callback function.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] device System-provided device identifier.
 * @param[in] toolid Type of tool currently being used.
 * @param[in] naxes Number of elements in the \p axis array.
 * @param[in] axis Array containing the current value of all updated axes.
 * @param[in] data Data for canvas.
 *
 * @since 1.13
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_axis_update(Evas_Canvas *obj, unsigned int timestamp, int device, int toolid, int naxes, const Evas_Axis *axis, const void *data);

/**
 * @brief Mouse down event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * button is pressed. It prepares information to be treated by the callback
 * function.
 *
 * @param[in] flags Evas button flags.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 * @param[in] rad The average of major and minor radius
 * @param[in] radx The major radius of touch point
 * @param[in] rady The minor radius of touch point
 * @param[in] pres The pressure of touch
 * @param[in] ang The angle relative to perpenficular(0.0), in degrees
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_down_with_multi_info(Evas_Canvas *obj, int b, Evas_Button_Flags flags, unsigned int timestamp, const void *data, double rad, double radx, double rady, double pres, double ang);

/**
 * @brief Mouse up event feed.
 *
 * This function will set some evas properties that is necessary when the mouse
 * button is released. It prepares information to be treated by the callback
 * function.
 *
 * @param[in] flags Evas button flags.
 * @param[in] timestamp The timestamp of the mouse up event.
 * @param[in] data The data for canvas.
 * @param[in] rad The average of major and minor radius
 * @param[in] radx The major radius of touch point
 * @param[in] rady The minor radius of touch point
 * @param[in] pres The pressure of touch
 * @param[in] ang The angle relative to perpenficular(0.0), in degrees
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_feed_mouse_up_with_multi_info(Evas_Canvas *obj, int b, Evas_Button_Flags flags, unsigned int timestamp, const void *data, double rad, double radx, double rady, double pres, double ang);

/**
 * @brief Mouse move event feed from input.
 *
 * Similar to the @ref evas_event_feed_mouse_move, this function will inform
 * Evas about mouse move events which were received by the input system,
 * relative to the 0,0 of the window, not to the canvas 0,0. It will take care
 * of doing any special transformation like adding the framespace offset to the
 * mouse event.
 *
 * @param[in] y The vertical position of the mouse pointer relative to the 0,0
 * of the window/surface.
 * @param[in] timestamp The timestamp of the mouse move event.
 * @param[in] data The data for canvas.
 * @param[in] rad The average of major and minor radius
 * @param[in] radx The major radius of touch point
 * @param[in] rady The minor radius of touch point
 * @param[in] pres The pressure of touch
 * @param[in] ang The angle relative to perpenficular(0.0), in degrees
 *
 * @since 1.8
 *
 * @ingroup Evas_Canvas
 */
EAPI void evas_event_input_mouse_move_with_multi_info(Evas_Canvas *obj, int x, int y, unsigned int timestamp, const void *data, double rad, double radx, double rady, double pres, double ang);

#endif
