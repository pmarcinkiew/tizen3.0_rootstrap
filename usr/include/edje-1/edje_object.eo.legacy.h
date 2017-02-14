#ifndef _EDJE_OBJECT_EO_LEGACY_H_
#define _EDJE_OBJECT_EO_LEGACY_H_

#ifndef _EDJE_OBJECT_EO_CLASS_TYPE
#define _EDJE_OBJECT_EO_CLASS_TYPE

typedef Eo Edje_Object;

#endif

#ifndef _EDJE_OBJECT_EO_TYPES
#define _EDJE_OBJECT_EO_TYPES


#endif

/**
 * @brief Edje will automatically update the size hints on itself.
 *
 * By default edje doesn't set size hints on itself. With this function call,
 * it will do so if update is true. Be carefully, it cost a lot to trigger this
 * feature as it will recalc the object every time it make sense to be sure
 * that's its minimal size hint is always accurate.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] update Whether or not update the size hints.
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_update_hints_set(Edje_Object *obj, Eina_Bool update);

/**
 * @brief Whether or not Edje will update size hints on itself.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Whether or not update the size hints.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_update_hints_get(const Edje_Object *obj);

/**
 * @brief Set the RTL orientation for this object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] rtl new value of flag true/false
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_mirrored_set(Edje_Object *obj, Eina_Bool rtl);

/**
 * @brief Get the RTL orientation for this object.
 *
 * You can RTL orientation explicitly with edje_object_mirrored_set.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return new value of flag true/false
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_mirrored_get(const Edje_Object *obj);

/**
 * @brief Set the language for this object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] language The language value
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_language_set(Edje_Object *obj, const char *language);

/**
 * @brief Get the language for this object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The language value
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_language_get(const Edje_Object *obj);

/**
 * @brief Set the object's animation state.
 *
 * This function starts or stops an Edje object's animation. The information if
 * it's stopped can be retrieved by edje_object_animation_get().
 *
 * See also @ref edje_object_animation_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] on The animation state. @c true to starts or @c false to stops.
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_animation_set(Edje_Object *obj, Eina_Bool on);

/**
 * @brief Get the Edje object's animation state.
 *
 * This function returns if the animation is stopped or not. The animation
 * state is set by edje_object_animation_set().
 *
 * See also @ref edje_object_animation_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The animation state. @c true to starts or @c false to stops.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_animation_get(const Edje_Object *obj);

/**
 * @brief Set the Edje object to playing or paused states.
 *
 * This function sets the Edje object  obj to playing or paused states,
 * depending on the parameter  play. This has no effect if the object was
 * already at that state.
 *
 * See also @ref edje_object_play_get().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] play Object state ($true to playing, @c false to paused).
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_play_set(Edje_Object *obj, Eina_Bool play);

/**
 * @brief Get the Edje object's state.
 *
 * This function tells if an Edje object is playing or not. This state is set
 * by edje_object_play_set().
 *
 * See also @ref edje_object_play_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Object state ($true to playing, @c false to paused).
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_play_get(const Edje_Object *obj);

/**
 * @brief Set the given perspective object on this Edje object.
 *
 * Make the given perspective object be the default perspective for this Edje
 * object.
 *
 * There can be only one perspective object per Edje object, and if a previous
 * one was set, it will be removed and the new perspective object will be used.
 *
 * An Edje perspective will only affect a part if it doesn't point to another
 * part to be used as perspective.
 *
 * @ref edje_object_perspective_new() See also
 * @ref edje_object_perspective_get() @ref edje_perspective_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] ps The perspective object that will be used.
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_perspective_set(Edje_Object *obj, Edje_Perspective *ps);

/**
 * @brief Get the current perspective used on this Edje object.
 *
 * See also @ref edje_object_perspective_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The perspective object that will be used.
 *
 * @ingroup Edje_Object
 */
EAPI const Edje_Perspective *edje_object_perspective_get(const Edje_Object *obj);

/**
 * @brief Set the scaling factor for a given Edje object.
 *
 * This function sets an  individual scaling factor on the  obj Edje object.
 * This property (or Edje's global scaling factor, when applicable), will
 * affect this object's part sizes. If scale is not zero, than the individual
 * scaling will  override any global scaling set, for the object obj's parts.
 * Put it back to zero to get the effects of the global scaling again.
 *
 * @warning Only parts which, at EDC level, had the @"scale" property set to
 * @1, will be affected by this function. Check the complete @ref edcref
 * "syntax reference" for EDC files.
 *
 * See also @ref edje_object_scale_get() @ref edje_scale_get() for more details
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] scale The scaling factor (the default value is @0.0, meaning
 * individual scaling  not set)
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_scale_set(Edje_Object *obj, double scale);

/**
 * @brief Get a given Edje object's scaling factor.
 *
 * This function returns the individual scaling factor set on the obj Edje
 * object.
 *
 * See also @ref edje_object_scale_set() for more details
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The scaling factor (the default value is @0.0, meaning individual
 * scaling  not set)
 *
 * @ingroup Edje_Object
 */
EAPI double edje_object_scale_get(const Edje_Object *obj);

/**
 * @brief Get a given Edje object's base_scale factor.
 *
 * This function returns the base_scale factor set on the obj Edje object. The
 * base_scale can be set in the collection of edc. If it isn't set, the default
 * value is 1.0
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The base_scale factor (the default value is @ 1.0, that means the
 * edc file is made based on scale 1.0.
 *
 * @ingroup Edje_Object
 */
EAPI double edje_object_base_scale_get(const Edje_Object *obj);

/**
 * @brief Set the object text callback.
 *
 * This function sets the callback to be called when the text changes.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] func The callback function to handle the text change
 * @param[in] data The data associated to the callback function.
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_text_change_cb_set(Edje_Object *obj, Edje_Text_Change_Cb func, void *data);

/**
 * @brief Moves the cursor to the beginning of the text part @ref
 * evas_textblock_cursor_paragraph_first
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_begin_set(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Move the cursor to the end of the line. @ref
 * evas_textblock_cursor_line_char_last
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_line_end_set(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Sets Edje text class.
 *
 * This function sets the text class for the Edje.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text_class The text class name
 * @param[in] font Font name
 * @param[in] size Font Size
 *
 * @return @c true, on success or @c false, on error
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_text_class_set(Edje_Object *obj, const char *text_class, const char *font, Evas_Font_Size size);

/**
 * @brief Position the given cursor to a X,Y position.
 *
 * This is frequently used with the user cursor.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part containing the object.
 * @param[in] cur The cursor to adjust.
 * @param[in] x X Coordinate.
 * @param[in] y Y Coordinate.
 *
 * @return True on success, false on error.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_coord_set(Edje_Object *obj, const char *part, Edje_Cursor cur, Evas_Coord x, Evas_Coord y);

/**
 * @brief Moves the cursor to the end of the text part. @ref
 * evas_textblock_cursor_paragraph_last
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_end_set(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Sets the text for an object part, but converts HTML escapes to UTF8
 *
 * This converts the given string text to UTF8 assuming it contains HTML style
 * escapes like "&amp;" and "&copy;" etc. IF the part is of type TEXT, as
 * opposed to TEXTBLOCK.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 * @param[in] text The text string
 *
 * @return @c true on success, @c false otherwise
 *
 * @since 1.2
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_escaped_set(Edje_Object *obj, const char *part, const char *text);

/**
 * @brief Set the function that provides item objects for named items in an
 * edje entry text
 *
 * Item objects may be deleted any time by Edje, and will be deleted when the
 * Edje object is deleted (or file is set to a new file).
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The function to call (or @c null to disable) to get item
 * objects
 * @param[in] data The data pointer to pass to the func callback
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_item_provider_set(Edje_Object *obj, Edje_Item_Provider_Cb func, void *data);

/**
 * @brief Move the cursor to the beginning of the line. @ref
 * evas_textblock_cursor_line_char_first
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_line_begin_set(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Set an Edje message handler function for a given Edje object.
 *
 * For scriptable programs on an Edje object's defining EDC file which send
 * messages with the send_message() primitive, one can attach handler
 * functions, to be called in the code which creates that object (see @ref
 * edcref "the syntax" for EDC files).
 *
 * This function associates a message handler function and the attached data
 * pointer to the object obj.
 *
 * See also @ref edje_object_message_send()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] func The function to handle messages  coming from obj
 * @param[in] data Auxiliary data to be passed to func
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_message_handler_set(Edje_Object *obj, Edje_Message_Handler_Cb func, void *data);

/**
 * @brief Get the minimum size specified -- as an EDC property -- for a given
 * Edje object
 *
 * This function retrieves the obj object's minimum size values, as declared in
 * its EDC group definition.
 *
 * @note If the @c min EDC property was not declared for obj, this call will
 * return the value 0, for each axis.
 *
 * @note On failure, this function will make all non-$null size pointers'
 * pointed variables be set to zero.
 *
 * See also @ref edje_object_size_max_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] minw Pointer to a variable where to store the minimum width
 * @param[out] minh Pointer to a variable where to store the minimum height
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_size_min_get(const Edje_Object *obj, Evas_Coord *minw, Evas_Coord *minh);

/**
 * @brief Retrieve a list all accessibility part names
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A list all accessibility part names on obj
 *
 * @since 1.7.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_List *edje_object_access_part_list_get(const Edje_Object *obj);

/**
 * @brief Gets the (last) file loading error for a given Edje object
 *
 * This function is meant to be used after an Edje EDJ file loading, what takes
 * place with the edje_object_file_set() function. If that function does not
 * return @c true, one should check for the reason of failure with this one.
 *
 * @ref edje_load_error_str()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The Edje loading error, one of: - #EDJE_LOAD_ERROR_NONE -
 * #EDJE_LOAD_ERROR_GENERIC - #EDJE_LOAD_ERROR_DOES_NOT_EXIST -
 * #EDJE_LOAD_ERROR_PERMISSION_DENIED -
 * #EDJE_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED - #EDJE_LOAD_ERROR_CORRUPT_FILE
 * - #EDJE_LOAD_ERROR_UNKNOWN_FORMAT - #EDJE_LOAD_ERROR_INCOMPATIBLE_FILE -
 * #EDJE_LOAD_ERROR_UNKNOWN_COLLECTION - #EDJE_LOAD_ERROR_RECURSIVE_REFERENCE
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Load_Error edje_object_load_error_get(const Edje_Object *obj);

/**
 * @brief Get the maximum size specified -- as an EDC property -- for a given
 * Edje object
 *
 * This function retrieves the obj object's maximum size values, as declared in
 * its EDC group definition.
 *
 * @note If the @c max EDC property was not declared for obj, this call will
 * return the maximum size a given Edje object may have, for each axis.
 *
 * @note On failure, this function will make all non-$null size pointers'
 * pointed variables be set to zero.
 *
 * See also @ref edje_object_size_min_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] maxw Pointer to a variable where to store the maximum width
 * @param[out] maxh Pointer to a variable where to store the maximum height
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_size_max_get(const Edje_Object *obj, Evas_Coord *maxw, Evas_Coord *maxh);

/**
 * @brief Sets the object size class.
 *
 * This function sets the min and max values for an object level size class.
 * This will make all edje parts in the specified object that have the
 * specified size class update their min and max size with given values.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] size_class The size class name
 * @param[in] minw The min width
 * @param[in] minh The min height
 * @param[in] maxw The max width
 * @param[in] maxh The max height
 *
 * @return @c true, on success or @c false, on error
 *
 * @since 1.17
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_size_class_set(Edje_Object *obj, const char * size_class, int minw, int minh, int maxw, int maxh);

/**
 * @brief Gets the object size class.
 *
 * This function gets the min and max values for an object level size class.
 * These values will only be valid until the size class is changed or the edje
 * object is deleted.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] size_class The size class name
 * @param[out] minw The min width
 * @param[out] minh The min height
 * @param[out] maxw The max width
 * @param[out] maxh The max height
 *
 * @return @c true, on success or @c false, on error
 *
 * @since 1.17
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_size_class_get(const Edje_Object *obj, const char * size_class, int *minw, int *minh, int *maxw, int *maxh);

/**
 * @brief Set transition duration factor.
 *
 * This define the transition duration factor on this specific object. By
 * default all animation are run at a speed factor of 1.0.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] scale The transition duration factor
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_transition_duration_factor_set(Edje_Object *obj, double scale);

/**
 * @brief Get transition duration factor.
 *
 * This define the transition duration factor on this specific object. By
 * default all animation are run at a speed factor of 1.0.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The transition duration factor
 *
 * @ingroup Edje_Object
 */
EAPI double edje_object_transition_duration_factor_get(const Edje_Object *obj);

/**
 * @internal
 *
 * @brief Sets the object text min calculation policy.
 *
 * Do not use this API without understanding whats going on. It is made for
 * internal usage.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] state_name The state name
 * @param[in] min_x The min width policy
 * @param[in] min_y The min height policy
 *
 * @return @c true, on success or @c false, on error
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_min_policy_set(Edje_Object *obj, const char * part, const char * state_name, Eina_Bool min_x, Eina_Bool min_y);

/**
 * @internal
 *
 * @brief Gets the object text min calculation policy.
 *
 * Do not use this API without understanding whats going on. It is made for
 * internal usage.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 * @param[in] state_name The state name
 * @param[out] min_x The min width policy
 * @param[out] min_y The min height policy
 *
 * @return @c true, on success or @c false, on error
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_min_policy_get(const Edje_Object *obj, const char * part, const char * state_name, Eina_Bool *min_x, Eina_Bool *min_y);

/**
 * @brief Removes all object from the table.
 *
 * Removes all object from the table indicated by part, except the internal
 * ones set from the theme.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] clear If set, will delete subobjs on remove
 *
 * @return @c true clear the table, @c false on failure
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_table_clear(Edje_Object *obj, const char *part, Eina_Bool clear);

/**
 * @brief Facility to query the type of the given parameter of the given part.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] param the parameter name to use.
 *
 * @return #EDJE_EXTERNAL_PARAM_TYPE_MAX on errors, or another value from
 * #Edje_External_Param_Type on success.
 *
 * @ingroup Edje_Object
 */
EAPI Edje_External_Param_Type edje_object_part_external_param_type_get(const Edje_Object *obj, const char *part, const char *param);

/**
 * @brief Enables selection if the entry is an EXPLICIT selection mode type.
 *
 * The default is to  not allow selection. This function only affects user
 * selection, functions such as edje_object_part_text_select_all() and
 * edje_object_part_text_select_none() are not affected.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] allow true to enable, false otherwise
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_allow_set(const Edje_Object *obj, const char *part, Eina_Bool allow);

/**
 * @internal
 *
 * @brief Enables selection if the entry is an EXPLICIT
 * selection mode type.
 *
 * The default is to  not allow selection. This function only affects user
 * selection, functions such as edje_object_part_text_select_all() and
 * edje_object_part_text_select_none() are not affected.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] disable true to enable, false otherwise
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_disable_set(const Edje_Object *obj, const char *part, Eina_Bool disable);

/**
 * @brief Returns the state of the Edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] val_ret
 *
 * @return The part state: "default" for the default state "" for other states
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_part_state_get(const Edje_Object *obj, const char *part, double *val_ret);

/**
 * @brief Delete a function and matching user data from the markup filter list.
 *
 * Delete the given func filter and data user data from the list in part.
 * Returns the user data pointer given when added.
 *
 * See also @ref edje_object_text_markup_filter_callback_add and
 * @ref edje_object_text_markup_filter_callback_del
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The function callback to remove
 * @param[in] data The data passed to the callback function
 *
 * @return The same data pointer if successful, or @c null otherwise
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void *edje_object_text_markup_filter_callback_del_full(Edje_Object *obj, const char *part, Edje_Markup_Filter_Cb func, void *data);

/**
 * @brief Sets the drag step increment.
 *
 * Sets the x,y step increments for a dragable object.
 *
 * Values for dx and dy are real numbers that range from 0 to 1, representing
 * the relative size of the dragable area on that axis by which the part will
 * be moved.
 *
 * See also @ref edje_object_part_drag_step_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dx The x step amount
 * @param[in] dy The y step amount
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_step_set(Edje_Object *obj, const char *part, double dx, double dy);

/**
 * @brief Gets the drag step increment values.
 *
 * Gets the x and y step increments for the dragable object.
 *
 * See also @ref edje_object_part_drag_step_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] dx The x step increment pointer
 * @param[out] dy The y step increment pointer
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_step_get(const Edje_Object *obj, const char *part, double *dx, double *dy);

/**
 * @brief Get the input method context in entry.
 *
 * If ecore_imf was not available when edje was compiled, this function returns
 * @c null otherwise, the returned pointer is an Ecore_IMF
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The input method context (Ecore_IMF_Context *) in entry
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void *edje_object_part_text_imf_context_get(const Edje_Object *obj, const char *part);

/**
 * @brief Starts selecting at current cursor position
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_begin(const Edje_Object *obj, const char *part);

/**
 * @brief Return the text of the object part.
 *
 * This function returns the style associated with the textblock part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The text string
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_part_text_style_user_peek(const Edje_Object *obj, const char *part);

/**
 * @brief Advances the cursor to the next cursor position. @ref
 * evas_textblock_cursor_char_next
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The edje cursor to advance
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_next(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Set the style of the
 *
 * This function sets the style associated with the textblock part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style The style to set (textblock conventions).
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_style_user_push(Edje_Object *obj, const char *part, const char *style);

/**
 * @brief Insert text for an object part.
 *
 * This function inserts the text for an object part at the end; It does not
 * move the cursor.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text The text string
 *
 * @since 1.1
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_append(Edje_Object *obj, const char *part, const char *text);

/**
 * @brief Retrieve the geometry of a given Edje part, in a given Edje object's
 * group definition, relative to the object's area.
 *
 * This function gets the geometry of an Edje part within its group. The x and
 * y coordinates are relative to the top left corner of the whole obj object's
 * area.
 *
 * @note Use @c null pointers on the geometry components you're not interested
 * in: they'll be ignored by the function.
 *
 * @note On failure, this function will make all non-$null geometry pointers'
 * pointed variables be set to zero.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x A pointer to a variable where to store the part's x coordinate
 * @param[out] y A pointer to a variable where to store the part's y coordinate
 * @param[out] w A pointer to a variable where to store the part's width
 * @param[out] h A pointer to a variable where to store the part's height
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_geometry_get(const Edje_Object *obj, const char *part, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Hide the input panel (virtual keyboard). See also
 * @ref edje_object_part_text_input_panel_show
 *
 * Note that input panel is shown or hidden automatically according to the
 * focus state. This API can be used in the case of manually controlling by
 * using edje_object_part_text_input_panel_enabled_set.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_hide(const Edje_Object *obj, const char *part);

/**
 * @brief Return item geometry.
 *
 * This function return a list of Evas_Textblock_Rectangle item rectangles.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] item The item name
 * @param[out] cx Item x return (relative to entry part)
 * @param[out] cy Item y return (relative to entry part)
 * @param[out] cw Item width return
 * @param[out] ch Item height return
 *
 * @return 1 if item exists, 0 if not
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_item_geometry_get(const Edje_Object *obj, const char *part, const char *item, Evas_Coord *cx, Evas_Coord *cy, Evas_Coord *cw, Evas_Coord *ch);

/**
 * @brief Removes an object from the table.
 *
 * Removes an object from the table indicated by part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child_obj The object to pack in
 *
 * @return @c true object removed, @c false on failure
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_table_unpack(Edje_Object *obj, const char *part, Evas_Object *child_obj);

/**
 * @brief Aborts any selection action on a part.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_abort(const Edje_Object *obj, const char *part);

/**
 * @brief Delete a function and matching user data from the filter list.
 *
 * Delete the given func filter and data user data from the list in part.
 * Returns the user data pointer given when added.
 *
 * See also @ref edje_object_text_insert_filter_callback_add and
 * @ref edje_object_text_insert_filter_callback_del
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The function callback to remove
 * @param[in] data The data passed to the callback function
 *
 * @return The same data pointer if successful, or @c null otherwise
 *
 * @ingroup Edje_Object
 */
EAPI void *edje_object_text_insert_filter_callback_del_full(Edje_Object *obj, const char *part, Edje_Text_Filter_Cb func, void *data);

/**
 * @brief Delete the top style form the user style stack.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_style_user_pop(Edje_Object *obj, const char *part);

/**
 * @brief Set the input panel-specific data to deliver to the input panel.
 *
 * This API is used by applications to deliver specific data to the input
 * panel. The data format MUST be negotiated by both application and the input
 * panel. The size and format of data are defined by the input panel.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] data The specific data to be set to the input panel.
 * @param[in] len the length of data, in bytes, to send to the input panel
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_imdata_set(Edje_Object *obj, const char *part, const void *data, int len);

/**
 * @brief Get the specific data of the current active input panel.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] data The specific data to be got from the input panel
 * @param[in] len The length of data
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_imdata_get(const Edje_Object *obj, const char *part, void *data, int *len);

/**
 * @brief Insert text for an object part.
 *
 * This function inserts the text for an object part just before the cursor
 * position.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text The text string
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_insert(Edje_Object *obj, const char *part, const char *text);

/**
 * @brief Removes an object from the box.
 *
 * Removes from the box indicated by part, the object in the position pos.
 *
 * See also @ref edje_object_part_box_remove() and
 * @ref edje_object_part_box_remove_all()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] pos The position index of the object (starts counting from 0)
 *
 * @return Pointer to the object removed, or @c null.
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_box_remove_at(Edje_Object *obj, const char *part, unsigned int pos);

/**
 * @brief Copy the cursor to another cursor.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] src the cursor to copy from
 * @param[in] dst the cursor to copy to
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_copy(Edje_Object *obj, const char *part, Edje_Cursor src, Edje_Cursor dst);

/**
 * @brief Calculate the geometry of the region, relative to a given Edje
 * object's area, occupied by all parts in the object.
 *
 * This function gets the geometry of the rectangle equal to the area required
 * to group all parts in obj's group/collection. The x and y coordinates are
 * relative to the top left corner of the whole obj object's area. Parts placed
 * out of the group's boundaries will also be taken in account, so that x and y
 * may be negative.
 *
 * @note Use @c null pointers on the geometry components you're not interested
 * in: they'll be ignored by the function.
 *
 * @note On failure, this function will make all non-$null geometry pointers'
 * pointed variables be set to zero.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] y A pointer to a variable where to store the parts region's y
 * coordinate
 * @param[out] w A pointer to a variable where to store the parts region's
 * width
 * @param[out] h A pointer to a variable where to store the parts region's
 * height
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_parts_extends_calc(Edje_Object *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Set the dragable object location.
 *
 * Places the dragable object at the given location.
 *
 * Values for dx and dy are real numbers that range from 0 to 1, representing
 * the relative position to the dragable area on that axis.
 *
 * This value means, for the vertical axis, that 0.0 will be at the top if the
 * first parameter of @c y in the dragable part theme is 1, and at bottom if it
 * is -1.
 *
 * For the horizontal axis, 0.0 means left if the first parameter of @c x in
 * the dragable part theme is 1, and right if it is -1.
 *
 * See also @ref edje_object_part_drag_value_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dx The x value
 * @param[in] dy The y value
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_value_set(Edje_Object *obj, const char *part, double dx, double dy);

/**
 * @brief Get the dragable object location.
 *
 * Values for dx and dy are real numbers that range from 0 to 1, representing
 * the relative position to the dragable area on that axis.
 *
 * See also @ref edje_object_part_drag_value_set()
 *
 * Gets the drag location values.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] dx The X value pointer
 * @param[out] dy The Y value pointer
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_value_get(const Edje_Object *obj, const char *part, double *dx, double *dy);

/**
 * @brief Force a Size/Geometry calculation.
 *
 * Forces the object obj to recalculation layout regardless of freeze/thaw.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_calc_force(Edje_Object *obj);

/**
 * @brief Sets the cursor position to the given value
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The cursor to move
 * @param[in] pos the position of the cursor
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_pos_set(Edje_Object *obj, const char *part, Edje_Cursor cur, int pos);

/**
 * @brief Retrieves the current position of the cursor
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The cursor to get the position
 *
 * @return The cursor position
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI int edje_object_part_text_cursor_pos_get(const Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Freezes the Edje object.
 *
 * This function puts all changes on hold. Successive freezes will nest,
 * requiring an equal number of thaws.
 *
 * See also @ref edje_object_thaw()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The frozen state or 0 on Error
 *
 * @ingroup Edje_Object
 */
EAPI int edje_object_freeze(Edje_Object *obj);

/**
 * @brief Returns the content (char) at the cursor position. @ref
 * evas_textblock_cursor_content_get
 *
 * You must free the return (if not @c null) after you are done with it.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The cursor to use
 *
 * @return The character string pointed to (may be a multi-byte utf8 sequence)
 * terminated by a nul byte.
 *
 * @ingroup Edje_Object
 */
EAPI char *edje_object_part_text_cursor_content_get(const Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Set the layout of the input panel.
 *
 * The layout of the input panel or virtual keyboard can make it easier or
 * harder to enter content. This allows you to hint what kind of input you are
 * expecting to enter and thus have the input panel automatically come up with
 * the right mode.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] layout layout type
 *
 * @since 1.1
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_layout_set(Edje_Object *obj, const char *part, Edje_Input_Panel_Layout layout);

/**
 * @brief Get the layout of the input panel.
 *
 * See also @ref edje_object_part_text_input_panel_layout_set
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return Layout type of the input panel
 *
 * @since 1.1
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Input_Panel_Layout edje_object_part_text_input_panel_layout_get(const Edje_Object *obj, const char *part);

/**
 * @brief Packs an object into the table.
 *
 * Packs an object into the table indicated by part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child_obj The object to pack in
 * @param[in] col The column to place it in
 * @param[in] row The row to place it in
 * @param[in] colspan Columns the child will take
 * @param[in] rowspan Rows the child will take
 *
 * @return @c true object was added, @c false on failure
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_table_pack(Edje_Object *obj, const char *part, Evas_Object *child_obj, unsigned short col, unsigned short row, unsigned short colspan, unsigned short rowspan);

/**
 * @brief Set the language mode of the input panel.
 *
 * This API can be used if you want to show the Alphabet keyboard.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] lang the language to be set to the input panel.
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_language_set(Edje_Object *obj, const char *part, Edje_Input_Panel_Lang lang);

/**
 * @brief Get the language mode of the input panel.
 *
 * See also @ref edje_object_part_text_input_panel_language_set for more
 * details.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return input panel language type
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Input_Panel_Lang edje_object_part_text_input_panel_language_get(const Edje_Object *obj, const char *part);

/**
 * @brief Gets the number of columns and rows the table has.
 *
 * Retrieves the size of the table in number of columns and rows.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] cols Pointer where to store number of columns (can be @c null)
 * @param[out] rows Pointer where to store number of rows (can be @c null)
 *
 * @return @c true get some data, @c false on failure
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_table_col_row_size_get(const Edje_Object *obj, const char *part, int *cols, int *rows);

/**
 * @brief Get the object created by this external part.
 *
 * Parts of type external creates the part object using information provided by
 * external plugins. It's somehow like "swallow" (edje_object_part_swallow()),
 * but it's all set automatically.
 *
 * This function returns the part created by such external plugins and being
 * currently managed by this Edje.
 *
 * @note Almost all swallow rules apply: you should not move, resize, hide,
 * show, set the color or clipper of such part. It's a bit more restrictive as
 * one must  never delete this object!
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The externally created object, or @c null if there is none or part
 * is not an external.
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_external_object_get(const Edje_Object *obj, const char *part);

/**
 * @brief Get an object contained in an part of type EXTERNAL
 *
 * The content string must not be @c null. Its actual value depends on the code
 * providing the EXTERNAL.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] content A string identifying which content from the EXTERNAL to
 * get
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_external_content_get(const Edje_Object *obj, const char *part, const char *content);

/**
 * @brief Preload the images on the Edje Object in the background.
 *
 * This function requests the preload of all data images (on the given object)
 * in the background. The work is queued before being processed (because there
 * might be other pending requests of this type). It emits a signal
 * "preload,done" when finished.
 *
 * @note Use @c true on scenarios where you don't need the image data preloaded
 * anymore.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] cancel @c false will add it the preloading work queue, @c true
 * will remove it (if it was issued before).
 *
 * @return @c false if obj was not a valid Edje object otherwise @c true
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_preload(Edje_Object *obj, Eina_Bool cancel);

/**
 * @brief Sets the attribute to show the input panel automatically.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] enabled If true, the input panel is appeared when entry is
 * clicked or has a focus
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_enabled_set(Edje_Object *obj, const char *part, Eina_Bool enabled);

/**
 * @brief Retrieve the attribute to show the input panel automatically. See
 * also @ref edje_object_part_text_input_panel_enabled_set
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return true if it supports or false otherwise
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_input_panel_enabled_get(const Edje_Object *obj, const char *part);

/**
 * @brief Extends the current selection to the current cursor position
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_extend(const Edje_Object *obj, const char *part);

/**
 * @brief Inserts an object to the box.
 *
 * Adds child to the box indicated by part, in the position given by pos.
 *
 * See also @ref edje_object_part_box_append(),
 * @ref edje_object_part_box_prepend() and
 * @ref edje_object_part_box_insert_before()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to insert
 * @param[in] pos The position where to insert child
 *
 * @return @c true: Successfully added. @c false: An error occurred.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_box_insert_at(Edje_Object *obj, const char *part, Evas_Object *child, unsigned int pos);

/**
 * @brief Return a list of Evas_Textblock_Rectangle anchor rectangles.
 *
 * This function return a list of Evas_Textblock_Rectangle anchor rectangles.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] anchor The anchor name
 *
 * @return The list of anchor rects (const Evas_Textblock_Rectangle *), do not
 * modify! Geometry is relative to entry part.
 *
 * @ingroup Edje_Object
 */
EAPI const Eina_List *edje_object_part_text_anchor_geometry_get(const Edje_Object *obj, const char *part, const char *anchor);

/**
 * @brief Moves the cursor to the char below the current cursor position.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_down(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Sets the page step increments.
 *
 * Sets the x,y page step increment values.
 *
 * Values for dx and dy are real numbers that range from 0 to 1, representing
 * the relative size of the dragable area on that axis by which the part will
 * be moved.
 *
 * See also @ref edje_object_part_drag_page_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dx The x page step increment
 * @param[in] dy The y page step increment
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_page_set(Edje_Object *obj, const char *part, double dx, double dy);

/**
 * @brief Gets the page step increments.
 *
 * Gets the x,y page step increments for the dragable object.
 *
 * See also @ref edje_object_part_drag_page_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] dx The dx page increment pointer
 * @param[out] dy The dy page increment pointer
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_page_get(const Edje_Object *obj, const char *part, double *dx, double *dy);

/**
 * @brief Prepends an object to the box.
 *
 * Prepends child to the box indicated by part.
 *
 * See also @ref edje_object_part_box_append(),
 * @ref edje_object_part_box_insert_before() and
 * @ref edje_object_part_box_insert_at()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to prepend
 *
 * @return @c true: Successfully added. @c false: An error occurred.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_box_prepend(Edje_Object *obj, const char *part, Evas_Object *child);

/**
 * @brief Send/emit an Edje signal to a given Edje object
 *
 * This function sends a signal to the object  obj. An Edje program, at obj's
 * EDC specification level, can respond to a signal by having declared matching
 * @'signal' and @'source' fields on its block (see @ref edcref "the syntax"
 * for EDC files).
 *
 * See also @ref edje_object_signal_callback_add() for more on Edje signals.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source The signal's "source" string
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_signal_emit(Edje_Object *obj, const char *emission, const char *source);

/**
 * @brief Set the layout variation of the input panel.
 *
 * The layout variation of the input panel or virtual keyboard can make it
 * easier or harder to enter content. This allows you to hint what kind of
 * input you are expecting to enter and thus have the input panel automatically
 * come up with the right mode.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] variation layout variation type
 *
 * @since 1.8
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_layout_variation_set(Edje_Object *obj, const char *part, int variation);

/**
 * @brief Get the layout variation of the input panel.
 *
 * See also @ref edje_object_part_text_input_panel_layout_variation_set
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return Layout variation type of the input panel
 *
 * @since 1.8
 *
 * @ingroup Edje_Object
 */
EAPI int edje_object_part_text_input_panel_layout_variation_get(const Edje_Object *obj, const char *part);

/**
 * @brief Send an (Edje) message to a given Edje object
 *
 * This function sends an Edje message to obj and to all of its child objects,
 * if it has any (swallowed objects are one kind of child object). type and msg
 *  must be matched accordingly, as documented in #Edje_Message_Type.
 *
 * The id argument as a form of code and theme defining a common interface on
 * message communication. One should define the same IDs on both code and EDC
 * declaration (see @ref edcref "the syntax" for EDC files), to individualize
 * messages (binding them to a given context).
 *
 * The function to handle messages arriving  from obj is set with
 * edje_object_message_handler_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] id A identification number for the message to be sent
 * @param[in] msg The message's body, a struct depending on type
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_message_send(Edje_Object *obj, Edje_Message_Type type, int id, void *msg);

/**
 * @brief Set the selection to be none.
 *
 * This function sets the selection text to be none.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_none(const Edje_Object *obj, const char *part);

/**
 * @brief Get a handle to the Evas object implementing a given Edje part, in an
 * Edje object.
 *
 * This function gets a pointer of the Evas object corresponding to a given
 * part in the obj object's group.
 *
 * You should  never modify the state of the returned object (with @ref
 * evas_object_move() or @ref evas_object_hide() for example), because it's
 * meant to be managed by Edje, solely. You are safe to query information about
 * its current state (with evas_object_visible_get() or @ref
 * evas_object_color_get() for example), though.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The Edje part's name
 *
 * @return A pointer to the Evas object implementing the given part, or @c null
 * on failure (e.g. the given part doesn't exist)
 *
 * @ingroup Edje_Object
 */
EAPI const Evas_Object *edje_object_part_object_get(const Edje_Object *obj, const char *part);

/**
 * @brief Set the dragable object size.
 *
 * Values for dw and dh are real numbers that range from 0 to 1, representing
 * the relative size of the dragable area on that axis.
 *
 * Sets the size of the dragable object.
 *
 * See also @ref edje_object_part_drag_size_get()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dw The drag width
 * @param[in] dh The drag height
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_size_set(Edje_Object *obj, const char *part, double dw, double dh);

/**
 * @brief Get the dragable object size.
 *
 * Gets the dragable object size.
 *
 * See also @ref edje_object_part_drag_size_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] dw The drag width pointer
 * @param[out] dh The drag height pointer
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_size_get(const Edje_Object *obj, const char *part, double *dw, double *dh);

/**
 * @brief Delete a function from the filter list.
 *
 * Delete the given func filter from the list in part. Returns the user data
 * pointer given when added.
 *
 * See also @ref edje_object_text_insert_filter_callback_add and
 * @ref edje_object_text_insert_filter_callback_del_full
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The function callback to remove
 *
 * @return The user data pointer if successful, or @c null otherwise
 *
 * @ingroup Edje_Object
 */
EAPI void *edje_object_text_insert_filter_callback_del(Edje_Object *obj, const char *part, Edje_Text_Filter_Cb func);

/**
 * @brief Determine dragable directions.
 *
 * The dragable directions are defined in the EDC file, inside the @ref
 * dragable section, by the attributes @c x and @c y. See the @ref edcref for
 * more information.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return #EDJE_DRAG_DIR_NONE: Not dragable #EDJE_DRAG_DIR_X: Dragable in X
 * direction #EDJE_DRAG_DIR_Y: Dragable in Y direction #EDJE_DRAG_DIR_XY:
 * Dragable in X & Y directions
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Drag_Dir edje_object_part_drag_dir_get(const Edje_Object *obj, const char *part);

/**
 * @brief Sets the raw (non escaped) text for an object part.
 *
 * This function will not do escape for you if it is a TEXTBLOCK part, that is,
 * if text contain tags, these tags will not be interpreted/parsed by
 * TEXTBLOCK.
 *
 * See also @ref edje_object_part_text_unescaped_get().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text_to_escape The text string
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_unescaped_set(Edje_Object *obj, const char *part, const char *text_to_escape);

/**
 * @brief Returns the text of the object part, without escaping.
 *
 * This function is the counterpart of edje_object_part_text_unescaped_set().
 * Please notice that the result is newly allocated memory and should be
 * released with free() when done.
 *
 * See also @ref edje_object_part_text_unescaped_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The  allocated text string without escaping, or @c null on problems.
 *
 * @ingroup Edje_Object
 */
EAPI char *edje_object_part_text_unescaped_get(const Edje_Object *obj, const char *part);

/**
 * @brief Add a callback for an arriving Edje signal, emitted by a given Edje
 * object.
 *
 * Edje signals are one of the communication interfaces between code and a
 * given Edje object's theme. With signals, one can communicate two string
 * values at a time, which are: - "emission" value: the name of the signal, in
 * general - "source" value: a name for the signal's context, in general
 *
 * Though there are those common uses for the two strings, one is free to use
 * them however they like.
 *
 * Signal callback registration is powerful, in the way that  blobs may be used
 * to match multiple signals at once. All the "*?[\" set of @c fnmatch()
 * operators can be used, both for emission and source.
 *
 * Edje has  internal signals it will emit, automatically, on various actions
 * taking place on group parts. For example, the mouse cursor being moved,
 * pressed, released, etc., over a given part's area, all generate individual
 * signals.
 *
 * By using something like edje_object_signal_callback_add(obj, "mouse,down,*",
 * "button.*", signal_cb, NULL); being @ref "button.*" the pattern for the
 * names of parts implementing buttons on an interface, you'd be registering
 * for notifications on events of mouse buttons being pressed down on either of
 * those parts (those events all have the @"mouse,down," common prefix on their
 * names, with a suffix giving the button number). The actual emission and
 * source strings of an event will be passed in as the  emission and  source
 * parameters of the callback function (e.g. "mouse,down,2" and
 * @"button.close"), for each of those events.
 *
 * @note See @ref edcref "the syntax" for EDC files See also
 * @ref edje_object_signal_emit() on how to emits Edje signals from code to a
 * an object @ref edje_object_signal_callback_del_full()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source The signal's "source" string
 * @param[in] func The callback function to be executed when the signal is
 * emitted.
 * @param[in] data A pointer to data to pass in to func.
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_signal_callback_add(Edje_Object *obj, const char *emission, const char *source, Edje_Signal_Cb func, void *data);

/**
 * @brief Set the selection to be everything.
 *
 * This function selects all text of the object of the part.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_select_all(const Edje_Object *obj, const char *part);

/**
 * @brief Set the return key on the input panel to be disabled.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] disabled The state
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_return_key_disabled_set(Edje_Object *obj, const char *part, Eina_Bool disabled);

/**
 * @brief Get whether the return key on the input panel should be disabled or
 * not.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return true if it should be disabled
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_input_panel_return_key_disabled_get(const Edje_Object *obj, const char *part);

/**
 * @brief Set the autocapitalization type on the immodule.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] autocapital_type The type of autocapitalization
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_autocapital_type_set(Edje_Object *obj, const char *part, Edje_Text_Autocapital_Type autocapital_type);

/**
 * @brief Retrieves the autocapitalization type
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The autocapitalization type
 *
 * @since 1.1.0
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Text_Autocapital_Type edje_object_part_text_autocapital_type_get(const Edje_Object *obj, const char *part);

/**
 * @brief Unswallow an object.
 *
 * Causes the edje to regurgitate a previously swallowed object. :)
 *
 * @note obj_swallow will  not be deleted or hidden. Note: obj_swallow may
 * appear shown on the evas depending on its state when it got unswallowed.
 * Make sure you delete it or hide it if you do not want it to.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] obj_swallow The swallowed object
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_unswallow(Edje_Object *obj, Evas_Object *obj_swallow);

/**
 * @brief Set whether the prediction is allowed or not.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] prediction If true, the prediction feature is allowed.
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_prediction_allow_set(Edje_Object *obj, const char *part, Eina_Bool prediction);

/**
 * @brief Get whether the prediction is allowed or not.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return true if prediction feature is allowed.
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_prediction_allow_get(const Edje_Object *obj, const char *part);

/**
 * @brief Retrive an EDC data field's value from a given Edje object's group.
 *
 * This function fetches an EDC data field's value, which is declared on the
 * objects building EDC file, under its group. EDC data blocks are most
 * commonly used to pass arbitrary parameters from an application's theme to
 * its code.
 *
 * EDC data fields always hold  strings as values, hence the return type of
 * this function. Check the complete @ref edcref "syntax reference" for EDC
 * files.
 *
 * @warning Do not confuse this call with edje_file_data_get(), which queries
 * for a  global EDC data field on an EDC declaration file.
 *
 * @ref edje_object_file_set()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] key The data field's key string
 *
 * @return The data's value string. Must not be freed.
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_data_get(const Edje_Object *obj, const char *key);

/**
 * @brief Add a markup filter function for newly inserted text.
 *
 * Whenever text is inserted (not the same as set) into the given part, the
 * list of markup filter functions will be called to decide if and how the new
 * text will be accepted. The text parameter in the func filter is always
 * markup. It can be modified by the user and it's up to him to free the one
 * passed if he's to change the pointer. If doing so, the newly set text should
 * be malloc'ed, as once all the filters are called Edje will free it. If the
 * text is to be rejected, freeing it and setting the pointer to @c null will
 * make Edje break out of the filter cycle and reject the inserted text. This
 * function is different from edje_object_text_insert_filter_callback_add() in
 * that the text parameter in the fucn filter is always markup.
 *
 * @warning If you use this function with
 * edje_object_text_insert_filter_callback_add() togehter, all
 * Edje_Text_Filter_Cb functions and Edje_Markup_Filter_Cb functions will be
 * executed, and then filtered text will be inserted.
 *
 * See also @ref edje_object_text_markup_filter_callback_del,
 * @ref edje_object_text_markup_filter_callback_del_full and
 * @ref edje_object_text_insert_filter_callback_add
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The callback function that will act as markup filter
 * @param[in] data User provided data to pass to the filter function
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_text_markup_filter_callback_add(Edje_Object *obj, const char *part, Edje_Markup_Filter_Cb func, void *data);

/**
 * @brief Process an object's message queue.
 *
 * This function goes through the object message queue processing the pending
 * messages for  this specific Edje object. Normally they'd be processed only
 * at idle time.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_message_signal_process(Edje_Object *obj);

/**
 * @brief Removes an object from the box.
 *
 * Removes child from the box indicated by part.
 *
 * See also @ref edje_object_part_box_remove_at() and
 * @ref edje_object_part_box_remove_all()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to remove
 *
 * @return Pointer to the object removed, or @c null.
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_box_remove(Edje_Object *obj, const char *part, Evas_Object *child);

/**
 * @brief Thaws the Edje object.
 *
 * This function thaws the given Edje object.
 *
 * Note:: If sucessives freezes were done, an equal number of thaws will be
 * required.
 *
 * See also @ref edje_object_freeze()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The frozen state or 0 if the object is not frozen or on error.
 *
 * @ingroup Edje_Object
 */
EAPI int edje_object_thaw(Edje_Object *obj);

/**
 * @brief Get the object currently swallowed by a part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The swallowed object, or @c null if there is none.
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_swallow_get(const Edje_Object *obj, const char *part);

/**
 * @brief Reset the input method context if needed.
 *
 * This can be necessary in the case where modifying the buffer would confuse
 * on-going input method behavior
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_imf_context_reset(const Edje_Object *obj, const char *part);

/**
 * @brief Set the "return" key type. This type is used to set string or icon on
 * the "return" key of the input panel.
 *
 * An input panel displays the string or icon associated with this type
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] return_key_type The type of "return" key on the input panel
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_return_key_type_set(Edje_Object *obj, const char *part, Edje_Input_Panel_Return_Key_Type return_key_type);

/**
 * @brief Get the "return" key type.
 *
 * See also @ref edje_object_part_text_input_panel_return_key_type_set() for
 * more details
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The type of "return" key on the input panel
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Input_Panel_Return_Key_Type edje_object_part_text_input_panel_return_key_type_get(const Edje_Object *obj, const char *part);

/**
 * @brief Retrieve a child from a table
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] col The column of the child to get
 * @param[in] row The row of the child to get
 *
 * @return The child Evas.Object
 *
 * @ingroup Edje_Object
 */
EAPI Evas_Object *edje_object_part_table_child_get(const Edje_Object *obj, const char *part, unsigned int col, unsigned int row);

/**
 * @brief Adds an object to the box.
 *
 * Inserts child in the box given by part, in the position marked by reference.
 *
 * See also @ref edje_object_part_box_append(),
 * @ref edje_object_part_box_prepend() and
 * @ref edje_object_part_box_insert_at()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to insert
 * @param[in] reference The object to be used as reference
 *
 * @return @c true: Successfully added. @c false: An error occurred.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_box_insert_before(Edje_Object *obj, const char *part, Evas_Object *child, const Evas_Object *reference);

/**
 * @brief Set the parameter for the external part.
 *
 * Parts of type external may carry extra properties that have meanings defined
 * by the external plugin. For instance, it may be a string that defines a
 * button label and setting this property will change that label on the fly.
 *
 * @note external parts have parameters set when they change states. Those
 * parameters will never be changed by this function. The interpretation of how
 * state_set parameters and param_set will interact is up to the external
 * plugin.
 *
 * @note this function will not check if parameter value is valid using
 * #Edje_External_Param_Info minimum, maximum, valid choices and others.
 * However these should be checked by the underlying implementation provided by
 * the external plugin. This is done for performance reasons.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] param the parameter details, including its name, type and actual
 * value. This pointer should be valid, and the parameter must exist in
 * #Edje_External_Type.parameters_info, with the exact type, otherwise the
 * operation will fail and @c false will be returned.
 *
 * @return @c true if everything went fine, @c false on errors.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_external_param_set(Edje_Object *obj, const char *part, const Edje_External_Param *param);

/**
 * @brief Get the parameter for the external part.
 *
 * Parts of type external may carry extra properties that have meanings defined
 * by the external plugin. For instance, it may be a string that defines a
 * button label. This property can be modified by state parameters, by explicit
 * calls to edje_object_part_external_param_set() or getting the actual object
 * with edje_object_part_external_object_get() and calling native functions.
 *
 * This function asks the external plugin what is the current value,
 * independent on how it was set.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] param the parameter details. It is used as both input and output
 * variable. This pointer should be valid, and the parameter must exist in
 * #Edje_External_Type.parameters_info, with the exact type, otherwise the
 * operation will fail and @c false will be returned.
 *
 * @return @c true if everything went fine and param members are filled with
 * information, @c false on errors and param member values are not set or
 * valid.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_external_param_get(const Edje_Object *obj, const char *part, Edje_External_Param *param);

/**
 * @brief Calculate the minimum required size for a given Edje object.
 *
 * This call works exactly as edje_object_size_min_restricted_calc(), with the
 * last two arguments set to 0. Please refer to its documentation, then.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] minh Pointer to a variable where to store the minimum required
 * height
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_size_min_calc(Edje_Object *obj, Evas_Coord *minw, Evas_Coord *minh);

/**
 * @brief Appends an object to the box.
 *
 * Appends child to the box indicated by part.
 *
 * See also @ref edje_object_part_box_prepend(),
 * @ref edje_object_part_box_insert_before() and
 * @ref edje_object_part_box_insert_at()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to append
 *
 * @return @c true: Successfully added. @c false: An error occurred.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_box_append(Edje_Object *obj, const char *part, Evas_Object *child);

/**
 * @brief Calculate the minimum required size for a given Edje object.
 *
 * This call will trigger an internal recalculation of all parts of the obj
 * object, in order to return its minimum required dimensions for width and
 * height. The user might choose to  impose those minimum sizes, making the
 * resulting calculation to get to values equal or bigger than restrictedw and
 * restrictedh, for width and height, respectively.
 *
 * @note At the end of this call, obj  won't be automatically resized to new
 * dimensions, but just return the calculated sizes. The caller is the one up
 * to change its geometry or not.
 *
 * @warning Be advised that invisible parts in obj  will be taken into account
 * in this calculation.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] minh Pointer to a variable where to store the minimum required
 * height
 * @param[in] restrictedw Do not allow object's calculated (minimum) width to
 * be less than this value
 * @param[in] restrictedh Do not allow object's calculated (minimum) height to
 * be less than this value
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_size_min_restricted_calc(Edje_Object *obj, Evas_Coord *minw, Evas_Coord *minh, Evas_Coord restrictedw, Evas_Coord restrictedh);

/**
 * @brief Removes all elements from the box.
 *
 * Removes all the external objects from the box indicated by part. Elements
 * created from the theme will not be removed.
 *
 * See also @ref edje_object_part_box_remove() and
 * @ref edje_object_part_box_remove_at()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] clear Delete objects on removal
 *
 * @return 1: Successfully cleared. 0: An error occurred.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_box_remove_all(Edje_Object *obj, const char *part, Eina_Bool clear);

/**
 * @brief Pages x,y steps.
 *
 * Pages x,y where the increment is defined by edje_object_part_drag_page_set.
 *
 * Values for dx and dy are real numbers that range from 0 to 1.
 *
 * @warning Paging is bugged!
 *
 * See also @ref edje_object_part_drag_step()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dx The x step
 * @param[in] dy The y step
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_page(Edje_Object *obj, const char *part, double dx, double dy);

/**
 * @brief Sets the text for an object part
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text The text string
 *
 * @return @c true on success, @c false otherwise
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_set(Edje_Object *obj, const char *part, const char *text);

/**
 * @brief Return the text of the object part.
 *
 * This function returns the text associated to the object part.
 *
 * See also @ref edje_object_part_text_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The text string
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_part_text_get(const Edje_Object *obj, const char *part);

/**
 * @brief Set the attribute to show the input panel in case of only an user's
 * explicit Mouse Up event. It doesn't request to show the input panel even
 * though it has focus.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] ondemand If true, the input panel will be shown in case of only
 * Mouse up event. (Focus event will be ignored.)
 *
 * @since 1.9.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_show_on_demand_set(Edje_Object *obj, const char *part, Eina_Bool ondemand);

/**
 * @brief Get the attribute to show the input panel in case of only an user's
 * explicit Mouse Up event.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return @c true if the input panel will be shown in case of only Mouse up
 * event.
 *
 * @since 1.9.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_input_panel_show_on_demand_get(const Edje_Object *obj, const char *part);

/**
 * @brief Sets the input hint which allows input methods to fine-tune their
 * behavior.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] input_hints input hints
 *
 * @since 1.12.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_hint_set(Edje_Object *obj, const char *part, Edje_Input_Hints input_hints);

/**
 * @brief Gets the value of input hint
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The value of input hint
 *
 * @since 1.12.0
 *
 * @ingroup Edje_Object
 */
EAPI Edje_Input_Hints edje_object_part_text_input_hint_get(const Edje_Object *obj, const char *part);

/**
 * @brief Return the selection text of the object part.
 *
 * This function returns selection text of the object part.
 *
 * See also @ref edje_object_part_text_select_all() and
 * @ref edje_object_part_text_select_none()
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @return The text string
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_part_text_selection_get(const Edje_Object *obj, const char *part);

/**
 * @brief Returns whether the cursor points to a format. @ref
 * evas_textblock_cursor_is_format
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The cursor to adjust.
 *
 * @return true if it's true, false otherwise.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_is_format_get(const Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Gets font and font size from edje text class.
 *
 * This function gets the font and the font size from the object text class.
 * The font string will only be valid until the text class is changed or the
 * edje object is deleted.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] font Font name
 * @param[out] size Font Size
 *
 * @return @c true, on success or @c false, on error
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_text_class_get(const Edje_Object *obj, const char *text_class, const char **font, Evas_Font_Size *size);

/**
 * @brief Sets the object color class.
 *
 * This function sets the color values for an object level color class. This
 * will cause all edje parts in the specified object that have the specified
 * color class to have their colors multiplied by these values.
 *
 * The first color is the object, the second is the text outline, and the third
 * is the text shadow. (Note that the second two only apply to text parts).
 *
 * Setting color emits a signal "color_class,set" with source being the given
 * color.
 *
 * @note unlike Evas, Edje colors are  not pre-multiplied. That is,
 * half-transparent white is 255 255 255 128.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] r Object Red value
 * @param[in] g Object Green value
 * @param[in] b Object Blue value
 * @param[in] a Object Alpha value
 * @param[in] r2 Outline Red value
 * @param[in] g2 Outline Green value
 * @param[in] b2 Outline Blue value
 * @param[in] a2 Outline Alpha value
 * @param[in] r3 Shadow Red value
 * @param[in] g3 Shadow Green value
 * @param[in] b3 Shadow Blue value
 * @param[in] a3 Shadow Alpha value
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_color_class_set(Edje_Object *obj, const char *color_class, int r, int g, int b, int a, int r2, int g2, int b2, int a2, int r3, int g3, int b3, int a3);

/**
 * @brief Gets the object color class.
 *
 * This function gets the color values for an object level color class. If no
 * explicit object color is set, then global values will be used.
 *
 * The first color is the object, the second is the text outline, and the third
 * is the text shadow. (Note that the second two only apply to text parts).
 *
 * @note unlike Evas, Edje colors are  not pre-multiplied. That is,
 * half-transparent white is 255 255 255 128.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] r Object Red value
 * @param[out] g Object Green value
 * @param[out] b Object Blue value
 * @param[out] a Object Alpha value
 * @param[out] r2 Outline Red value
 * @param[out] g2 Outline Green value
 * @param[out] b2 Outline Blue value
 * @param[out] a2 Outline Alpha value
 * @param[out] r3 Shadow Red value
 * @param[out] g3 Shadow Green value
 * @param[out] b3 Shadow Blue value
 * @param[out] a3 Shadow Alpha value
 *
 * @return true if found or false if not found and all values are zeroed.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_color_class_get(const Edje_Object *obj, const char *color_class, int *r, int *g, int *b, int *a, int *r2, int *g2, int *b2, int *a2, int *r3, int *g3, int *b3, int *a3);

/**
 * @brief Gets the description of an object color class.
 *
 * This function gets the description of a color class in use by an object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] color_class
 *
 * @return The description of the target color class or @c null if not found
 *
 * @ingroup Edje_Object
 */
EAPI const char *edje_object_color_class_description_get(const Edje_Object *obj, const char *color_class);

/**
 * @brief Clear object color classes.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return @c true, on success or @c false, on error
 *
 * @since 1.17.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_color_class_clear(const Edje_Object *obj);

/**
 * @internal
 *
 * @brief Sets the parent object for color class.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] parent The parent object for color class
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_color_class_parent_set(Edje_Object *obj, Evas_Object *parent);

/**
 * @internal
 *
 * @brief Unsets the parent object color class.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_color_class_parent_unset(Edje_Object *obj);

/**
 * @brief Delete the object size class.
 *
 * This function deletes any values at the object level for the specified
 * object and size class.
 *
 * Deleting the size class will revert it to the values defined by
 * edje_size_class_set() or the color class defined in the theme file.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] size_class
 *
 * @since 1.17
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_size_class_del(Edje_Object *obj, const char *size_class);

/**
 * @brief Steps the dragable x,y steps.
 *
 * Steps x,y where the step increment is the amount set by
 * edje_object_part_drag_step_set.
 *
 * Values for dx and dy are real numbers that range from 0 to 1.
 *
 * See also @ref edje_object_part_drag_page()
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] dx The x step
 * @param[in] dy The y step
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_drag_step(Edje_Object *obj, const char *part, double dx, double dy);

/**
 * @brief Move the cursor to the char above the current cursor position.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_up(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Returns the cursor geometry of the part relative to the edje object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] x Cursor X position
 * @param[out] y Cursor Y position
 * @param[out] w Cursor width
 * @param[out] h Cursor height
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_geometry_get(const Edje_Object *obj, const char *part, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Returns the cursor geometry of the part relative to the edje object.
 * The cursor geometry is kept in mouse down and move.
 *
 * @internal @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0
 * @endif
 *
 * @param[out] x Cursor X position
 * @param[out] y Cursor Y position
 * @param[out] w Cursor width
 * @param[out] h Cursor height
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_cursor_on_mouse_geometry_get(const Edje_Object *obj, const char *part, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Return a list of char anchor names.
 *
 * This function returns a list of char anchor names.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The list of anchors (const char *), do not modify!
 *
 * @ingroup Edje_Object
 */
EAPI const Eina_List *edje_object_part_text_anchor_list_get(const Edje_Object *obj, const char *part);

/**
 * @brief Add a filter function for newly inserted text.
 *
 * Whenever text is inserted (not the same as set) into the given part, the
 * list of filter functions will be called to decide if and how the new text
 * will be accepted. There are three types of filters, EDJE_TEXT_FILTER_TEXT,
 * EDJE_TEXT_FILTER_FORMAT and EDJE_TEXT_FILTER_MARKUP. The text parameter in
 * the func filter can be modified by the user and it's up to him to free the
 * one passed if he's to change the pointer. If doing so, the newly set text
 * should be malloc'ed, as once all the filters are called Edje will free it.
 * If the text is to be rejected, freeing it and setting the pointer to @c null
 * will make Edje break out of the filter cycle and reject the inserted text.
 *
 * @warning This function will be deprecated because of difficulty in use. The
 * type(format, text, or markup) of text should be always checked in the filter
 * function for correct filtering. Please use
 * edje_object_text_markup_filter_callback_add() instead. There is no need to
 * check the type of text in the filter function because the text is always
 * markup. Warning: If you use this function with
 * edje_object_text_markup_filter_callback_add() together, all
 * Edje_Text_Filter_Cb functions and Edje_Markup_Filter_Cb functions will be
 * executed, and then filtered text will be inserted.
 *
 * See also @ref edje_object_text_insert_filter_callback_del,
 * @ref edje_object_text_insert_filter_callback_del_full and
 * @ref edje_object_text_markup_filter_callback_add
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The callback function that will act as filter
 * @param[in] data User provided data to pass to the filter function
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_text_insert_filter_callback_add(Edje_Object *obj, const char *part, Edje_Text_Filter_Cb func, void *data);

/**
 * @brief Show the input panel (virtual keyboard) based on the input panel
 * property such as layout, autocapital types, and so on.
 *
 * Note that input panel is shown or hidden automatically according to the
 * focus state. This API can be used in the case of manually controlling by
 * using edje_object_part_text_input_panel_enabled_set.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_input_panel_show(const Edje_Object *obj, const char *part);

/**
 * @brief Check if an Edje part exists in a given Edje object's group
 * definition.
 *
 * This function returns if a given part exists in the Edje group bound to
 * object obj (with edje_object_file_set()).
 *
 * This call is useful, for example, when one could expect or not a given GUI
 * element, depending on the  theme applied to obj.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part's name to check for existence in obj's group
 *
 * @return @c true, if the Edje part exists in obj's group or @c false,
 * otherwise (and on errors)
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_exists(const Edje_Object *obj, const char *part);

/**
 * @brief Delete a function from the markup filter list.
 *
 * Delete the given func filter from the list in part. Returns the user data
 * pointer given when added.
 *
 * See also @ref edje_object_text_markup_filter_callback_add and
 * @ref edje_object_text_markup_filter_callback_del_full
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] func The function callback to remove
 *
 * @return The user data pointer if successful, or @c null otherwise
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void *edje_object_text_markup_filter_callback_del(Edje_Object *obj, const char *part, Edje_Markup_Filter_Cb func);

/**
 * @brief Return true if the cursor points to a visible format For example \\t,
 * \\n, item and etc. @ evas_textblock_cursor_format_is_visible_get
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur The cursor to adjust.
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_is_visible_format_get(const Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief This function inserts text as if the user has inserted it.
 *
 * This means it actually registers as a change and emits signals, triggers
 * callbacks as appropriate.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text The text string
 *
 * @since 1.2.0
 *
 * @ingroup Edje_Object
 */
EAPI void edje_object_part_text_user_insert(const Edje_Object *obj, const char *part, const char *text);

/**
 * @brief Moves the cursor to the previous char @ref
 * evas_textblock_cursor_char_prev
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cur the edje cursor to work on
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_cursor_prev(Edje_Object *obj, const char *part, Edje_Cursor cur);

/**
 * @brief Return a list of char item names.
 *
 * This function returns a list of char item names.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The part name
 *
 * @return The list of items (const char *), do not modify!
 *
 * @ingroup Edje_Object
 */
EAPI const Eina_List *edje_object_part_text_item_list_get(const Edje_Object *obj, const char *part);

/**
 * @brief "Swallows" an object into one of the Edje object @c SWALLOW parts.
 *
 * Swallowing an object into an Edje object is, for a given part of type
 * @c SWALLOW in the EDC group which gave life to  obj, to set an external
 * object to be controlled by  obj, being displayed exactly over that part's
 * region inside the whole Edje object's viewport.
 *
 * From this point on,  obj will have total control over obj_swallow's geometry
 * and visibility. For instance, if  obj is visible, as in @ref
 * evas_object_show(), the swallowed object will be visible too -- if the given
 * @c SWALLOW part it's in is also visible. Other actions on  obj will also
 * reflect on the swallowed object as well (e.g. resizing, moving,
 * raising/lowering, etc.).
 *
 * Finally, all internal changes to  part, specifically, will reflect on the
 * displaying of  obj_swallow, for example state changes leading to different
 * visibility states, geometries, positions, etc.
 *
 * If an object has already been swallowed into this part, then it will first
 * be unswallowed (as in edje_object_part_unswallow()) before the new object is
 * swallowed.
 *
 * @note  obj  won't delete the swallowed object once it is deleted --
 *  obj_swallow will get to an unparented state again.
 *
 * For more details on EDC @c SWALLOW parts, see @ref edcref "syntax
 * reference".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] obj_swallow The object to occupy that part
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_swallow(Edje_Object *obj, const char *part, Evas_Object *obj_swallow);

/**
 * @brief Hide visible last character for password mode.
 *
 * @param[in] part The part name
 *
 * @return @c true if the visible character is hidden. @c false if there is no
 * visible character or the object is not set for password mode.
 *
 * @since 1.18.0
 *
 * @ingroup Edje_Object
 */
EAPI Eina_Bool edje_object_part_text_hide_visible_password(Edje_Object *obj, const char *part);

#endif
