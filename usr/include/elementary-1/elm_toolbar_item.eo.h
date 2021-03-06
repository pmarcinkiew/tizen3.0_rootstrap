#ifndef _ELM_TOOLBAR_ITEM_EO_H_
#define _ELM_TOOLBAR_ITEM_EO_H_

#ifndef _ELM_TOOLBAR_ITEM_EO_CLASS_TYPE
#define _ELM_TOOLBAR_ITEM_EO_CLASS_TYPE

typedef Eo Elm_Toolbar_Item;

#endif

#ifndef _ELM_TOOLBAR_ITEM_EO_TYPES
#define _ELM_TOOLBAR_ITEM_EO_TYPES

/** Defines where to position the item in the toolbar.
 *
 * @ingroup Elm_Toolbar_Item
 */
typedef enum
{
  ELM_TOOLBAR_ITEM_SCROLLTO_NONE = 0, /** no scrollto */
  ELM_TOOLBAR_ITEM_SCROLLTO_IN = 1 /* 0 << 0 */, /** to the nearest viewport */
  ELM_TOOLBAR_ITEM_SCROLLTO_FIRST = 2 /* 0 << 0 */, /** to the first of
                                                     * viewport */
  ELM_TOOLBAR_ITEM_SCROLLTO_MIDDLE = 4 /* 0 << 0 */, /** to the middle of
                                                      * viewport */
  ELM_TOOLBAR_ITEM_SCROLLTO_LAST = 8 /* 0 << 0 */ /** to the last of viewport
                                                   */
} Elm_Toolbar_Item_Scrollto_Type;


#endif
#define ELM_TOOLBAR_ITEM_CLASS elm_toolbar_item_class_get()

EAPI const Eo_Class *elm_toolbar_item_class_get(void) EINA_CONST;

/**
 * @brief @MOBILE_ONLY
 *
 * Get the item before @c item in toolbar.
 *
 * @note If it is the first item, @c null will be returned.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The item before @c item, or @c null if none or on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_prev_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the item after @c item in toolbar.
 *
 * @note If it is the last item, @c null will be returned.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The item after @c item, or @c null if none or on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_next_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the priority of a toolbar item.
 *
 * This is used only when the toolbar shrink mode is set to
 * #ELM_TOOLBAR_SHRINK_MENU or #ELM_TOOLBAR_SHRINK_HIDE. When space is less
 * than required, items with low priority will be removed from the toolbar and
 * added to a dynamically-created menu, while items with higher priority will
 * remain on the toolbar, with the same order they were added.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] priority The @c item priority. The default is zero for set and 0
 * is returned on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_priority_set(int priority);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the priority of a toolbar item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The @c item priority. The default is zero for set and 0 is returned
 * on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI int  elm_obj_toolbar_item_priority_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the selected state of an item.
 *
 * This sets the selected state of the given item @c it. @c true for selected,
 * @c false for not selected.
 *
 * If a new item is selected the previously selected will be unselected.
 * Previously selected item can be get with function
 * @ref elm_obj_toolbar_selected_item_get.
 *
 * Selected items will be highlighted.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] selected The selected state.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_selected_set(Eina_Bool selected);

/**
 * @brief @MOBILE_ONLY
 *
 * Get whether the @c item is selected or not.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The selected state.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_selected_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the icon associated with @c item.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by @ref elm_obj_toolbar_icon_order_lookup_set function. If an absolute
 * path is provided it will load it direct from a file.
 *
 * @note This function does not accept relative icon path.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] icon A string with icon name or the absolute path of an image
 * file.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_icon_set(const char *icon);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the string used to set the icon of @c item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return A string with icon name or the absolute path of an image file.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI const char * elm_obj_toolbar_item_icon_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the real Evas(Edje) object created to implement the view of a given
 * toolbar @c item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The base Edje object associated with @c it.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Evas_Object * elm_obj_toolbar_item_object_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the icon object of @c item.
 *
 * See also @ref elm_obj_toolbar_item_icon_set,
 * @ref elm_obj_toolbar_item_icon_file_set,
 * @ref elm_obj_toolbar_item_icon_memfile_set.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The icon object.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Evas_Object * elm_obj_toolbar_item_icon_object_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set or unset item as a separator.
 *
 * Items aren't set as separator by default.
 *
 * If set as separator it will display separator theme, so won't display icons
 * or label.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] separator
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_separator_set(Eina_Bool separator);

/**
 * @brief @MOBILE_ONLY
 *
 * Get a value whether item is a separator or not.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_separator_get(void);

/**
 * @internal
 *
 * @brief Get toolbar item's menu.
 *
 * If @c item wasn't set as menu item with @ref elm_obj_toolbar_item_menu_set,
 * this function will set it.
 *
 * @return Item's menu object or @c null on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Evas_Object * elm_obj_toolbar_item_menu_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set @c state as the current state of @c it.
 *
 * If @c state is @c NULL, it won't select any state and the default item's
 * icon and label will be used. It's the behavior as @ref
 * elm_toolbar_item_state_unset.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] state
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_state_set(Elm_Toolbar_Item_State *state);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the current state of @c it.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Toolbar_Item_State * elm_obj_toolbar_item_state_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the icon associated with @c item to an image in a binary buffer.
 *
 * @note The icon image set by this function can be changed by
 * @ref elm_obj_toolbar_item_icon_set.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] size The size of binary data @c img.
 * @param[in] format Optional format of @c img to pass to the image loader.
 * @param[in] key Optional key of @c img to pass to the image loader (eg. if
 * @c img is an edje file).
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_icon_memfile_set(const void *img, size_t size, const char *format, const char *key);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the icon associated with @c item to an image in a binary buffer.
 *
 * @note The icon image set by this function can be changed by
 * elm_toolbar_item_icon_set().
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] key Optional key of @c img to pass to the image loader (eg. if
 * @c img is an edje file).
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_icon_file_set(const char *file, const char *key);

/**
 * @brief @MOBILE_ONLY
 *
 * Add a new state to @c item.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by @ref elm_obj_toolbar_icon_order_lookup_set function. If an absolute
 * path is provided it will load it direct from a file.
 *
 * States created with this function can be removed with
 * @ref elm_obj_toolbar_item_state_del.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of the new state.
 * @param[in] func The function to call when the item is clicked when this
 * state is selected.
 * @param[in] data The data to associate with the state.
 *
 * @return The toolbar item state, or @c null upon failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Toolbar_Item_State * elm_obj_toolbar_item_state_add(const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Delete a previously added state to @c item.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] state The state to be deleted.
 *
 * @return @c true on success or @c false on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Eina_Bool  elm_obj_toolbar_item_state_del(Elm_Toolbar_Item_State *state);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the state after selected state in toolbar's @c item.
 *
 * If last state is selected, this function will return first state.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The state after current state, or @c null on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Toolbar_Item_State * elm_obj_toolbar_item_state_next(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the state before selected state in toolbar's @c item.
 *
 * If first state is selected, this function will return last state.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The state before current state, or @c null on failure.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI Elm_Toolbar_Item_State * elm_obj_toolbar_item_state_prev(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Show a specific item, when the toolbar can be scrolled.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] scrollto The position the item should appear at.
 *
 * @since 1.8
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_show(Elm_Toolbar_Item_Scrollto_Type scrollto);

/**
 * @brief @MOBILE_ONLY
 *
 * Show a specific item with scroll animation, when the toolbar can be
 * scrolled.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] scrollto The position the item should appear at.
 *
 * @since 1.8
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_bring_in(Elm_Toolbar_Item_Scrollto_Type scrollto);

/**
 * @internal
 *
 * @brief Set whether the toolbar item opens a menu.
 *
 * A toolbar item can be set to be a menu, using this function.
 *
 * Once it is set to be a menu, it can be manipulated through the menu-like
 * function @ref elm_obj_toolbar_menu_parent_set and the other elm_menu
 * functions, using the Evas_Object @c menu returned by
 * @ref elm_obj_toolbar_item_menu_get.
 *
 * So, items to be displayed in this item's menu should be added with @ref
 * elm_menu_item_add.
 *
 * @param[in] menu If @c true, @c item will opens a menu when selected.
 *
 * @ingroup Elm_Toolbar_Item
 */
EOAPI void  elm_obj_toolbar_item_menu_set(Eina_Bool menu);


#endif
