#ifndef _ELM_LAYOUT_EO_LEGACY_H_
#define _ELM_LAYOUT_EO_LEGACY_H_

#ifndef _ELM_LAYOUT_EO_CLASS_TYPE
#define _ELM_LAYOUT_EO_CLASS_TYPE

typedef Eo Elm_Layout;

#endif

#ifndef _ELM_LAYOUT_EO_TYPES
#define _ELM_LAYOUT_EO_TYPES


#endif

/**
 * @brief Set accessibility to all texblock(text) parts in the layout object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] can_access Makes all textblock(text) parts in the layout @c obj
 * possible to have accessibility. @c true means textblock(text) parts can be
 * accessible.
 *
 * @return @c true on success or @c false on failure. If @c obj is not a proper
 * layout object, @c false is returned.
 *
 * @since 1.7
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_edje_object_can_access_set(Elm_Layout *obj, Eina_Bool can_access);

/**
 * @brief Get accessibility state of texblock(text) parts in the layout object
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Makes all textblock(text) parts in the layout @c obj possible to
 * have accessibility. @c true means textblock(text) parts can be accessible.
 *
 * @since 1.7
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_edje_object_can_access_get(const Elm_Layout *obj);

/**
 * @brief Set the edje group from the elementary theme that will be used as
 * layout.
 *
 * Note that @c style will be the new style of @c obj too, as in an @ref
 * elm_object_style_set call.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] klass The class of the group.
 * @param[in] group The group.
 * @param[in] style The style to used.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_theme_set(Elm_Layout *obj, const char *klass, const char *group, const char *style);

/**
 * @brief Get the edje layout
 *
 * This returns the edje object. It is not expected to be used to then swallow
 * objects via @ref edje_object_part_swallow for example. Use @ref
 * elm_layout_content_set instead so child object handling and sizing is done
 * properly.
 *
 * @note This function should only be used if you really need to call some low
 * level Edje function on this edje object. All the common stuff (setting text,
 * emitting signals, hooking callbacks to signals, etc.) can be done with
 * proper elementary functions.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return An Evas_Object with the edje layout settings loaded @ref
 * elm_layout_file_set.
 *
 * @ingroup Elm_Layout
 */
EAPI Evas_Object *elm_layout_edje_get(const Elm_Layout *obj);

/**
 * @brief Remove all children of the given part box.
 *
 * The objects will be removed from the box part and their lifetime will not be
 * handled by the layout anymore. This is equivalent to
 * @ref elm_layout_box_remove for all box children.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] clear If true, then all objects will be deleted as well,
 * otherwise they will just be removed and will be dangling on the canvas.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_box_remove_all(Elm_Layout *obj, const char *part, Eina_Bool clear);

/**
 * @brief Sets if the cursor set should be searched on the theme or should use
 * the provided by the engine, only.
 *
 * @note Before you set if should look on theme you should define a cursor with
 * @ref elm_layout_part_cursor_set. By default it will only look for cursors
 * provided by the engine.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] engine_only If cursors should be just provided by the engine
 * ($true) or should also search on widget's theme as well ($false)
 *
 * @return @c true on success or @c false on failure, that may be part not
 * exists or it did not had a cursor set.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_part_cursor_engine_only_set(Elm_Layout *obj, const char *part_name, Eina_Bool engine_only);

/**
 * @brief Get a specific cursor engine_only for an edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part_name A part from loaded edje group.
 *
 * @return Whenever the cursor is just provided by engine or also from theme.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_part_cursor_engine_only_get(const Elm_Layout *obj, const char *part_name);

/**
 * @brief Unpack (remove) a child of the given part table.
 *
 * The object will be unpacked from the table part and its lifetime will not be
 * handled by the layout anymore. This is equivalent to @ref
 * elm_layout_content_unset for table.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to remove from table.
 *
 * @return The object that was being used, or @c null if not found.
 *
 * @ingroup Elm_Layout
 */
EAPI Evas_Object *elm_layout_table_unpack(Elm_Layout *obj, const char *part, Evas_Object *child);

/**
 * @brief Freezes the Elementary layout object.
 *
 * This function puts all changes on hold. Successive freezes will nest,
 * requiring an equal number of thaws.
 *
 * See also @ref elm_layout_thaw.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The frozen state or 0 on error.
 *
 * @ingroup Elm_Layout
 */
EAPI int elm_layout_freeze(Elm_Layout *obj);

/**
 * @brief Eval sizing.
 *
 * Manually forces a sizing re-evaluation. This is useful when the minimum size
 * required by the edje theme of this layout has changed. The change on the
 * minimum size required by the edje theme is not immediately reported to the
 * elementary layout, so one needs to call this function in order to tell the
 * widget (layout) that it needs to reevaluate its own size.
 *
 * The minimum size of the theme is calculated based on minimum size of parts,
 * the size of elements inside containers like box and table, etc. All of this
 * can change due to state changes, and that's when this function should be
 * called.
 *
 * Also note that a standard signal of "size,eval" "elm" emitted from the edje
 * object will cause this to happen too.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Layout
 */
EAPI void elm_layout_sizing_eval(Elm_Layout *obj);

/**
 * @brief Remove a child of the given part box.
 *
 * The object will be removed from the box part and its lifetime will not be
 * handled by the layout anymore. This is equivalent to @ref
 * elm_layout_content_unset for box.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The object to remove from box.
 *
 * @return The object that was being used, or @c null if not found.
 *
 * @ingroup Elm_Layout
 */
EAPI Evas_Object *elm_layout_box_remove(Elm_Layout *obj, const char *part, Evas_Object *child);

/**
 * @brief Request sizing reevaluation, restricted to current width and/or
 * height.
 *
 * Useful mostly when there are TEXTBLOCK parts defining the height of the
 * object and nothing else restricting it to a minimum width. Calling this
 * function will restrict the minimum size in the Edje calculation to whatever
 * size it the layout has at the moment.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] height Restrict minimum size ot the current height.
 *
 * @since 1.8
 *
 * @ingroup Elm_Layout
 */
EAPI void elm_layout_sizing_restricted_eval(Elm_Layout *obj, Eina_Bool width, Eina_Bool height);

/**
 * @brief Sets a specific cursor style for an edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style The theme style to use (default, transparent, ...).
 *
 * @return True on success or false on failure, that may be part not exists or
 * it did not had a cursor set.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_part_cursor_style_set(Elm_Layout *obj, const char *part_name, const char *style);

/**
 * @brief Get a specific cursor style for an edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part_name A part from loaded edje group.
 *
 * @return The theme style in use, defaults to "default". If the object does
 * not have a cursor set, then @c null is returned.
 *
 * @ingroup Elm_Layout
 */
EAPI const char *elm_layout_part_cursor_style_get(const Elm_Layout *obj, const char *part_name);

/**
 * @brief Set the text of the given part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] text The text to set.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_text_set(Elm_Layout *obj, const char *part, const char *text);

/**
 * @brief Get the text set in the given part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part The TEXT part to retrieve the text off.
 *
 * @ingroup Elm_Layout
 */
EAPI const char *elm_layout_text_get(const Elm_Layout *obj, const char *part);

/**
 * @brief Add a callback for a (Edje) signal emitted by a layout widget's
 * underlying Edje object.
 *
 * This function connects a callback function to a signal emitted by the
 * underlying Edje object of @c obj. Globs are accepted in either the emission
 * or source strings.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source The signal's source string.
 * @param[in] func The callback function to be executed when the signal is
 * emitted.
 * @param[in] data A pointer to data to pass in to the callback function.
 *
 * @ingroup Elm_Layout
 */
EAPI void elm_layout_signal_callback_add(Elm_Layout *obj, const char *emission, const char *source, Edje_Signal_Cb func, void *data);

/**
 * @brief Sets a specific cursor for an edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] cursor Cursor name to use, see Elementary_Cursor.h.
 *
 * @return @c true on success or @c false on failure, that may be part not
 * exists or it has "mouse_events: 0".
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_part_cursor_set(Elm_Layout *obj, const char *part_name, const char *cursor);

/**
 * @brief Get the cursor to be shown when mouse is over an edje part.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part_name A part from loaded edje group.
 *
 * @ingroup Elm_Layout
 */
EAPI const char *elm_layout_part_cursor_get(const Elm_Layout *obj, const char *part_name);

/**
 * @brief Insert child to layout box part before a reference object.
 *
 * Once the object is inserted, it will become child of the layout. Its
 * lifetime will be bound to the layout, whenever the layout dies the child
 * will be deleted automatically. One should use @ref elm_layout_box_remove to
 * make this layout forget about the object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The child object to insert into box.
 * @param[in] reference Another reference object to insert before in box.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_box_insert_before(Elm_Layout *obj, const char *part, Evas_Object *child, const Evas_Object *reference);

/**
 * @brief Insert child to layout box part at a given position.
 *
 * Once the object is inserted, it will become child of the layout. Its
 * lifetime will be bound to the layout, whenever the layout dies the child
 * will be deleted automatically. One should use @ref elm_layout_box_remove to
 * make this layout forget about the object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The child object to insert into box.
 * @param[in] pos The numeric position >=0 to insert the child.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_box_insert_at(Elm_Layout *obj, const char *part, Evas_Object *child, unsigned int pos);

/**
 * @brief Get the edje data from the given layout.
 *
 * This function fetches data specified inside the edje theme of this layout.
 * This function return NULL if data is not found.
 *
 * In EDC this comes from a data block within the group block that @c obj was
 * loaded from.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] key The data key.
 *
 * @return The edje data string.
 *
 * @ingroup Elm_Layout
 */
EAPI const char *elm_layout_data_get(const Elm_Layout *obj, const char *key);

/**
 * @brief Append child to layout box part.
 *
 * Once the object is appended, it will become child of the layout. Its
 * lifetime will be bound to the layout, whenever the layout dies the child
 * will be deleted automatically. One should use @ref elm_layout_box_remove to
 * make this layout forget about the object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The child object to append to box.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_box_append(Elm_Layout *obj, const char *part, Evas_Object *child);

/**
 * @brief Remove a signal-triggered callback from a given layout widget.
 *
 * This function removes the last callback attached to a signal emitted by the
 * undelying Edje object of @c obj, with parameters @c emission, @c source and
 * @c func matching exactly those passed to a previous call to
 * @ref elm_layout_signal_callback_add. The data pointer that was passed to
 * this call will be returned.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source The signal's source string.
 * @param[in] func The callback function being executed when the signal was
 * emitted.
 *
 * @return The data pointer of the signal callback (passed on
 * @ref elm_layout_signal_callback_add) or @c null on errors.
 *
 * @ingroup Elm_Layout
 */
EAPI void *elm_layout_signal_callback_del(Elm_Layout *obj, const char *emission, const char *source, Edje_Signal_Cb func);

/**
 * @brief Thaws the Elementary object.
 *
 * This function thaws the given Edje object and the Elementary sizing calc.
 *
 * @note If sucessives freezes were done, an equal number of thaws will be
 * required.
 *
 * See also @ref elm_layout_freeze.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The frozen state or 0 if the object is not frozen or on error.
 *
 * @ingroup Elm_Layout
 */
EAPI int elm_layout_thaw(Elm_Layout *obj);

/**
 * @brief Prepend child to layout box part.
 *
 * Once the object is prepended, it will become child of the layout. Its
 * lifetime will be bound to the layout, whenever the layout dies the child
 * will be deleted automatically. One should use @ref elm_layout_box_remove to
 * make this layout forget about the object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The child object to prepend to box.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_box_prepend(Elm_Layout *obj, const char *part, Evas_Object *child);

/**
 * @brief Send a (Edje) signal to a given layout widget's underlying Edje
 * object.
 *
 * This function sends a signal to the underlying Edje object of @c obj. An
 * Edje program on that Edje object's definition can respond to a signal by
 * specifying matching 'signal' and 'source' fields.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source The signal's source string.
 *
 * @ingroup Elm_Layout
 */
EAPI void elm_layout_signal_emit(Elm_Layout *obj, const char *emission, const char *source);

/**
 * @brief Insert child to layout table part.
 *
 * Once the object is inserted, it will become child of the table. Its lifetime
 * will be bound to the layout, and whenever the layout dies the child will be
 * deleted automatically. One should use @ref elm_layout_table_unpack to make
 * this layout forget about the object.
 *
 * If @c colspan or @c rowspan are bigger than 1, that object will occupy more
 * space than a single cell.
 *
 * See also @ref elm_layout_table_unpack, @ref elm_layout_table_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] child The child object to pack into table.
 * @param[in] col The column to which the child should be added. (>= 0)
 * @param[in] row The row to which the child should be added. (>= 0)
 * @param[in] colspan How many columns should be used to store this object. (>=
 * 1)
 * @param[in] rowspan How many rows should be used to store this object. (>= 1)
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_table_pack(Elm_Layout *obj, const char *part, Evas_Object *child, unsigned short col, unsigned short row, unsigned short colspan, unsigned short rowspan);

/**
 * @brief Unsets a cursor previously set with @ref elm_layout_part_cursor_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] part_name A part from loaded edje group, that had a cursor set
 * wit @ref elm_layout_part_cursor_set.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_part_cursor_unset(Elm_Layout *obj, const char *part_name);

/**
 * @brief Remove all the child objects of the given part table.
 *
 * The objects will be removed from the table part and their lifetime will not
 * be handled by the layout anymore. This is equivalent to
 * @ref elm_layout_table_unpack for all table children.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] clear If true, then all objects will be deleted as well,
 * otherwise they will just be removed and will be dangling on the canvas.
 *
 * @ingroup Elm_Layout
 */
EAPI Eina_Bool elm_layout_table_clear(Elm_Layout *obj, const char *part, Eina_Bool clear);

#endif
