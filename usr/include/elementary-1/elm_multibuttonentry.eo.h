#ifndef _ELM_MULTIBUTTONENTRY_EO_H_
#define _ELM_MULTIBUTTONENTRY_EO_H_

#ifndef _ELM_MULTIBUTTONENTRY_EO_CLASS_TYPE
#define _ELM_MULTIBUTTONENTRY_EO_CLASS_TYPE

typedef Eo Elm_Multibuttonentry;

#endif

#ifndef _ELM_MULTIBUTTONENTRY_EO_TYPES
#define _ELM_MULTIBUTTONENTRY_EO_TYPES


#endif
#define ELM_MULTIBUTTONENTRY_CLASS elm_multibuttonentry_class_get()

EAPI const Eo_Class *elm_multibuttonentry_class_get(void) EINA_CONST;

/**
 * @brief Control if the multibuttonentry is to be editable or not.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] editable If @c true, user can add/delete item in
 * multibuttonentry, if not, the multibuttonentry is non-editable.
 *
 * @since 1.7
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_editable_set(Eina_Bool editable);

/**
 * @brief Control if the multibuttonentry is to be editable or not.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return If @c true, user can add/delete item in multibuttonentry, if not,
 * the multibuttonentry is non-editable.
 *
 * @since 1.7
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Eina_Bool  elm_obj_multibuttonentry_editable_get(void);

/**
 * @brief Control the multibuttonentry to expanded state.
 *
 * In expanded state, the complete entry will be displayed. Otherwise, only
 * single line of the entry will be displayed.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] expanded the value of expanded state.  Set this to @c true for
 * expanded state.  Set this to false for single line state.
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_expanded_set(Eina_Bool expanded);

/**
 * @brief Control the multibuttonentry to expanded state.
 *
 * In expanded state, the complete entry will be displayed. Otherwise, only
 * single line of the entry will be displayed.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return the value of expanded state.  Set this to @c true for expanded
 * state.  Set this to false for single line state.
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Eina_Bool  elm_obj_multibuttonentry_expanded_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set a function to format the string that will be used to display the hidden
 * items counter.
 *
 * If @c format_function is @c NULL, the default format will be used, which is
 * $"... + %d".
 *
 * @if MOBILE @since_tizen 3.0 @endif
 *
 * @param[in] format_function format_function The actual format function
 * @param[in] data data User data to passed to @c format_function
 *
 * @since 1.9
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_format_function_set(Elm_Multibuttonentry_Format_Cb format_function, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Get a list of items in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The list of items, or NULL if none
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI const Eina_List * elm_obj_multibuttonentry_items_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the first item in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The first item, or NULL if none
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_first_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the last item in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The last item, or NULL if none
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_last_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the entry of the multibuttonentry object
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The entry object, or NULL if none
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Evas_Object * elm_obj_multibuttonentry_entry_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the selected item in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The selected item, or NULL if none
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_selected_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Prepend a new item to the multibuttonentry
 *
 * See @ref elm_wdg_item_del to delete the item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] func The callback function to be invoked when this item is
 * pressed.
 * @param[in] data The pointer to the data to be attached
 *
 * @return A handle to the item added or NULL if not possible
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_prepend(const char *label, Evas_Smart_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Remove all items in the multibuttonentry.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_clear(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Remove a filter from the list
 *
 * Removes the given callback from the filter list. See
 * elm_multibuttonentry_item_filter_append() for more information.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] data The user data passed when adding the function
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_item_filter_remove(Elm_Multibuttonentry_Item_Filter_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Add a new item to the multibuttonentry before the indicated object
 * reference.
 *
 * See @ref elm_wdg_item_del to delete the item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of new item
 * @param[in] func The callback function to be invoked when this item is
 * pressed.
 * @param[in] data The pointer to the data to be attached
 *
 * @return A handle to the item added or NULL if not possible
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_insert_before(Elm_Widget_Item *before, const char *label, Evas_Smart_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Append a new item to the multibuttonentry
 *
 * See @ref elm_wdg_item_del to delete the item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] func The callback function to be invoked when this item is
 * pressed.
 * @param[in] data The pointer to the data to be attached
 *
 * @return A handle to the item added or NULL if not possible
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_append(const char *label, Evas_Smart_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Prepend a filter function for text inserted in the Multibuttonentry
 *
 * Prepend the given callback to the list. See
 * elm_multibuttonentry_item_filter_append() for more information
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] data User data to pass to @c func
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_item_filter_prepend(Elm_Multibuttonentry_Item_Filter_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Append an item filter function for text inserted in the Multibuttonentry
 *
 * Append the given callback to the list. This functions will be called
 * whenever any text is inserted into the Multibuttonentry, with the text to be
 * inserted as a parameter. The callback function is free to alter the text in
 * any way it wants, but it must remember to free the given pointer and update
 * it. If the new text is to be discarded, the function can free it and set it
 * text parameter to NULL. This will also prevent any following filters from
 * being called.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] data User data to pass to @c func
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI void  elm_obj_multibuttonentry_item_filter_append(Elm_Multibuttonentry_Item_Filter_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Add a new item to the multibuttonentry after the indicated object
 *
 * See @ref elm_wdg_item_del to delete the item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of new item
 * @param[in] func The callback function to be invoked when this item is
 * pressed.
 * @param[in] data The pointer to the data to be attached
 *
 * @return A handle to the item added or NULL if not possible
 *
 * @ingroup Elm_Multibuttonentry
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_insert_after(Elm_Widget_Item *after, const char *label, Evas_Smart_Cb func, void *data);

EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_ITEM_SELECTED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_ITEM_ADDED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_ITEM_DELETED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_ITEM_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_ITEM_LONGPRESSED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_EXPANDED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_CONTRACTED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_EXPAND_STATE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_MULTIBUTTONENTRY_EVENT_CHANGED;

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_ITEM_SELECTED (&(_ELM_MULTIBUTTONENTRY_EVENT_ITEM_SELECTED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_ITEM_ADDED (&(_ELM_MULTIBUTTONENTRY_EVENT_ITEM_ADDED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_ITEM_DELETED (&(_ELM_MULTIBUTTONENTRY_EVENT_ITEM_DELETED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_ITEM_CLICKED (&(_ELM_MULTIBUTTONENTRY_EVENT_ITEM_CLICKED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_ITEM_LONGPRESSED (&(_ELM_MULTIBUTTONENTRY_EVENT_ITEM_LONGPRESSED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_EXPANDED (&(_ELM_MULTIBUTTONENTRY_EVENT_EXPANDED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_CONTRACTED (&(_ELM_MULTIBUTTONENTRY_EVENT_CONTRACTED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_EXPAND_STATE_CHANGED (&(_ELM_MULTIBUTTONENTRY_EVENT_EXPAND_STATE_CHANGED))

/**
 * No description
 */
#define ELM_MULTIBUTTONENTRY_EVENT_CHANGED (&(_ELM_MULTIBUTTONENTRY_EVENT_CHANGED))

#endif
