#ifndef _ELM_TOOLBAR_EO_H_
#define _ELM_TOOLBAR_EO_H_

#ifndef _ELM_TOOLBAR_EO_CLASS_TYPE
#define _ELM_TOOLBAR_EO_CLASS_TYPE

typedef Eo Elm_Toolbar;

#endif

#ifndef _ELM_TOOLBAR_EO_TYPES
#define _ELM_TOOLBAR_EO_TYPES

/**
 * @brief Set toolbar's items display behavior, it can be scrollable, show a
 * menu with exceeding items, or simply hide them.
 *
 * Default value is #ELM_TOOLBAR_SHRINK_MENU. It reads value from elm config.
 *
 * Values don't work as bitmask, only one can be chosen.
 *
 * See also @ref elm_obj_toolbar_shrink_mode_set,
 * @ref elm_obj_toolbar_shrink_mode_get.
 *
 * @ingroup Elm_Toolbar
 */
typedef enum
{
  ELM_TOOLBAR_SHRINK_NONE = 0, /** Set toolbar minimum size to fit all the
                                * items. */
  ELM_TOOLBAR_SHRINK_HIDE, /** Hide exceeding items. */
  ELM_TOOLBAR_SHRINK_SCROLL, /** Allow accessing exceeding items through a
                              * scroller. */
  ELM_TOOLBAR_SHRINK_MENU, /** Inserts a button to pop up a menu with exceeding
                            * items. */
  ELM_TOOLBAR_SHRINK_EXPAND, /** Expand all items according the size of the
                              * toolbar. */
  ELM_TOOLBAR_SHRINK_LAST /** Indicates error if returned by
                           * elm_toolbar_shrink_mode_get() */
} Elm_Toolbar_Shrink_Mode;


#endif
#define ELM_TOOLBAR_CLASS elm_toolbar_class_get()

EAPI const Eo_Class *elm_toolbar_class_get(void) EINA_CONST;

/**
 * @brief Control homogeneous mode.
 *
 * This will enable the homogeneous mode where items are of the same size.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] homogeneous Assume the items within the toolbar are of the same
 * size (true = on, false = off). Default is @c false.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_homogeneous_set(Eina_Bool homogeneous);

/**
 * @brief Control homogeneous mode.
 *
 * This will enable the homogeneous mode where items are of the same size.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return Assume the items within the toolbar are of the same size (true = on,
 * false = off). Default is @c false.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Eina_Bool  elm_obj_toolbar_homogeneous_get(void);

/**
 * @brief Control the alignment of the items.
 *
 * Alignment of toolbar items, from 0.0 to indicates to align left, to 1.0, to
 * align to right. 0.5 centralize items.
 *
 * Centered items by default.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] align The new alignment, a float between 0.0 and 1.0.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_align_set(double align);

/**
 * @brief Control the alignment of the items.
 *
 * Alignment of toolbar items, from 0.0 to indicates to align left, to 1.0, to
 * align to right. 0.5 centralize items.
 *
 * Centered items by default.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The new alignment, a float between 0.0 and 1.0.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI double  elm_obj_toolbar_align_get(void);

/**
 * @brief Control the toolbar select mode.
 *
 * elm_toolbar_select_mode_set() changes item select mode in the toolbar
 * widget. - #ELM_OBJECT_SELECT_MODE_DEFAULT : Items will only call their
 * selection func and callback when first becoming selected. Any further clicks
 * will do nothing, unless you set always select mode. -
 * #ELM_OBJECT_SELECT_MODE_ALWAYS : This means that, even if selected, every
 * click will make the selected callbacks be called. -
 * #ELM_OBJECT_SELECT_MODE_NONE : This will turn off the ability to select
 * items entirely and they will neither appear selected nor call selected
 * callback functions.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] mode The select mode If getting mode fails, it returns
 * #ELM_OBJECT_SELECT_MODE_MAX
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_select_mode_set(Elm_Object_Select_Mode mode);

/**
 * @brief Control the toolbar select mode.
 *
 * elm_toolbar_select_mode_set() changes item select mode in the toolbar
 * widget. - #ELM_OBJECT_SELECT_MODE_DEFAULT : Items will only call their
 * selection func and callback when first becoming selected. Any further clicks
 * will do nothing, unless you set always select mode. -
 * #ELM_OBJECT_SELECT_MODE_ALWAYS : This means that, even if selected, every
 * click will make the selected callbacks be called. -
 * #ELM_OBJECT_SELECT_MODE_NONE : This will turn off the ability to select
 * items entirely and they will neither appear selected nor call selected
 * callback functions.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The select mode If getting mode fails, it returns
 * #ELM_OBJECT_SELECT_MODE_MAX
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Object_Select_Mode  elm_obj_toolbar_select_mode_get(void);

/**
 * @brief Control the icon size, in pixels, to be used by toolbar items.
 *
 * @note Default value is $32. It reads value from elm config.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] icon_size The icon size in pixels
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_icon_size_set(int icon_size);

/**
 * @brief Control the icon size, in pixels, to be used by toolbar items.
 *
 * @note Default value is $32. It reads value from elm config.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The icon size in pixels
 *
 * @ingroup Elm_Toolbar
 */
EOAPI int  elm_obj_toolbar_icon_size_get(void);

/**
 * @brief Change a toolbar's orientation
 *
 * By default, a toolbar will be horizontal. Use this function to create a
 * vertical toolbar.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] horizontal If @c true, the toolbar is horizontal.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_horizontal_set(Eina_Bool horizontal);

/**
 * @brief Change a toolbar's orientation
 *
 * By default, a toolbar will be horizontal. Use this function to create a
 * vertical toolbar.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return If @c true, the toolbar is horizontal.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Eina_Bool  elm_obj_toolbar_horizontal_get(void);

/**
 * @brief Sets icon lookup order, for toolbar items' icons.
 *
 * Icons added before calling this function will not be affected. The default
 * lookup order is #ELM_ICON_LOOKUP_THEME_FDO.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] order The icon lookup order. (If getting the icon order loopup
 * fails, it returns #ELM_ICON_LOOKUP_THEME_FDO)
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_icon_order_lookup_set(Elm_Icon_Lookup_Order order);

/**
 * @brief Sets icon lookup order, for toolbar items' icons.
 *
 * Icons added before calling this function will not be affected. The default
 * lookup order is #ELM_ICON_LOOKUP_THEME_FDO.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The icon lookup order. (If getting the icon order loopup fails, it
 * returns #ELM_ICON_LOOKUP_THEME_FDO)
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Icon_Lookup_Order  elm_obj_toolbar_icon_order_lookup_get(void);

/**
 * @brief Control the item displaying mode of a given toolbar widget @c obj.
 *
 * The toolbar won't scroll under #ELM_TOOLBAR_SHRINK_NONE mode, but it will
 * enforce a minimum size, so that all the items will fit inside it. It won't
 * scroll and won't show the items that don't fit under
 * #ELM_TOOLBAR_SHRINK_HIDE mode. Finally, it'll scroll under
 * #ELM_TOOLBAR_SHRINK_SCROLL mode, and it will create a button to aggregate
 * items which didn't fit with the #ELM_TOOLBAR_SHRINK_MENU mode.
 *
 * If shrink mode is changed, Toolbar will send one of the following signal to
 * each item for informing the current shrink mode. "elm,state,shrink,default"
 * "elm,state,shrink,hide" "elm,state,shrink,scroll" "elm,state,shrink,menu"
 * "elm,state,shrink,expand"
 *
 * @warning This function's behavior will clash with those of
 * elm_scroller_policy_set(), so use either one of them, but not both.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] shrink_mode Toolbar's items display behavior
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_shrink_mode_set(Elm_Toolbar_Shrink_Mode shrink_mode);

/**
 * @brief Control the item displaying mode of a given toolbar widget @c obj.
 *
 * The toolbar won't scroll under #ELM_TOOLBAR_SHRINK_NONE mode, but it will
 * enforce a minimum size, so that all the items will fit inside it. It won't
 * scroll and won't show the items that don't fit under
 * #ELM_TOOLBAR_SHRINK_HIDE mode. Finally, it'll scroll under
 * #ELM_TOOLBAR_SHRINK_SCROLL mode, and it will create a button to aggregate
 * items which didn't fit with the #ELM_TOOLBAR_SHRINK_MENU mode.
 *
 * If shrink mode is changed, Toolbar will send one of the following signal to
 * each item for informing the current shrink mode. "elm,state,shrink,default"
 * "elm,state,shrink,hide" "elm,state,shrink,scroll" "elm,state,shrink,menu"
 * "elm,state,shrink,expand"
 *
 * @warning This function's behavior will clash with those of
 * elm_scroller_policy_set(), so use either one of them, but not both.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return Toolbar's items display behavior
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Toolbar_Shrink_Mode  elm_obj_toolbar_shrink_mode_get(void);

/**
 * @brief Control the parent object of the toolbar items' menus.
 *
 * Each item can be set as item menu, with elm_toolbar_item_menu_set().
 *
 * For more details about setting the parent for toolbar menus, see
 * elm_menu_parent_set().
 *
 * See: elm_menu_parent_set() for details. See: elm_toolbar_item_menu_set() for
 * details.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] parent The parent of the menu objects.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_menu_parent_set(Evas_Object *parent);

/**
 * @brief Control the parent object of the toolbar items' menus.
 *
 * Each item can be set as item menu, with elm_toolbar_item_menu_set().
 *
 * For more details about setting the parent for toolbar menus, see
 * elm_menu_parent_set().
 *
 * See: elm_menu_parent_set() for details. See: elm_toolbar_item_menu_set() for
 * details.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The parent of the menu objects.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Evas_Object * elm_obj_toolbar_menu_parent_get(void);

/**
 * @brief Set the standard priority of visible items in a toolbar
 *
 * If the priority of the item is up to standard priority, it is shown in basic
 * panel. The other items are located in more menu or panel. The more menu or
 * panel can be shown when the more item is clicked.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] priority The standard_priority of visible items
 *
 * @since 1.7
 *
 * @ingroup Elm_Toolbar
 */
EOAPI void  elm_obj_toolbar_standard_priority_set(int priority);

/**
 * @brief Set the standard priority of visible items in a toolbar
 *
 * If the priority of the item is up to standard priority, it is shown in basic
 * panel. The other items are located in more menu or panel. The more menu or
 * panel can be shown when the more item is clicked.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The standard_priority of visible items
 *
 * @since 1.7
 *
 * @ingroup Elm_Toolbar
 */
EOAPI int  elm_obj_toolbar_standard_priority_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the selected item.
 *
 * The selected item can be unselected with function
 * elm_toolbar_item_selected_set().
 *
 * The selected item always will be highlighted on toolbar.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The selected toolbar item.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_selected_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the first item in the given toolbar widget's list of items.
 *
 * See: @ref elm_obj_toolbar_item_append and @ref elm_obj_toolbar_last_item_get
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The first item or @c NULL, if it has no items (and on errors)
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_first_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the more item which is auto-generated by toolbar.
 *
 * Toolbar generates 'more' item when there is no more space to fit items in
 * and toolbar is in #ELM_TOOLBAR_SHRINK_MENU or #ELM_TOOLBAR_SHRINK_EXPAND
 * mode. The more item can be manipulated by elm_object_item_text_set() and
 * elm_object_item_content_set.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The toolbar more item.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_more_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the last item in the given toolbar widget's list of items.
 *
 * See: @ref elm_obj_toolbar_item_prepend and
 * @ref elm_obj_toolbar_first_item_get
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The last item or @c NULL, if it has no items (and on errors)
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_last_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Insert a new item into the toolbar object before item @c before.
 *
 * A new item will be created and added to the toolbar. Its position in this
 * toolbar will be just before item @c before.
 *
 * Items created with this method can be deleted with elm_object_item_del().
 *
 * Associated @c data can be properly freed when item is deleted if a callback
 * function is set with elm_object_item_del_cb_set().
 *
 * If a function is passed as argument, it will be called every time this item
 * is selected, i.e., the user clicks over an unselected item. If such function
 * isn't needed, just passing @c NULL as @c func is enough. The same should be
 * done for @c data.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by elm_toolbar_icon_order_lookup_set() function. If an absolute path is
 * provided it will load it direct from a file.
 *
 * @note This function does not accept relative icon path.
 *
 * See: elm_toolbar_item_icon_set()
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] icon A string with icon name or the absolute path of an image
 * file.
 * @param[in] label The label of the item.
 * @param[in] func The function to call when the item is clicked.
 * @param[in] data The data to associate with the item for related callbacks.
 *
 * @return The created item or @c NULL upon failure.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_insert_before(Elm_Widget_Item *before, const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Insert a new item into the toolbar object after item @c after.
 *
 * A new item will be created and added to the toolbar. Its position in this
 * toolbar will be just after item @c after.
 *
 * Items created with this method can be deleted with elm_object_item_del().
 *
 * Associated @c data can be properly freed when item is deleted if a callback
 * function is set with elm_object_item_del_cb_set().
 *
 * If a function is passed as argument, it will be called every time this item
 * is selected, i.e., the user clicks over an unselected item. If such function
 * isn't needed, just passing @c NULL as @c func is enough. The same should be
 * done for @c data.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by elm_toolbar_icon_order_lookup_set() function. If an absolute path is
 * provided it will load it direct from a file.
 *
 * @note This function does not accept relative icon path.
 *
 * See: elm_toolbar_item_icon_set()
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] icon A string with icon name or the absolute path of an image
 * file.
 * @param[in] label The label of the item.
 * @param[in] func The function to call when the item is clicked.
 * @param[in] data The data to associate with the item for related callbacks.
 *
 * @return The created item or @c NULL upon failure.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_insert_after(Elm_Widget_Item *after, const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Append item to the toolbar.
 *
 * A new item will be created and appended to the toolbar, i.e., will be set as
 * last item.
 *
 * Items created with this method can be deleted with elm_object_item_del().
 *
 * Associated @c data can be properly freed when item is deleted if a callback
 * function is set with elm_object_item_del_cb_set().
 *
 * If a function is passed as argument, it will be called every time this item
 * is selected, i.e., the user clicks over an unselected item. If such function
 * isn't needed, just passing @c NULL as @c func is enough. The same should be
 * done for @c data.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by elm_toolbar_icon_order_lookup_set() function. If an absolute path is
 * provided it will load it direct from a file.
 *
 * @note This function does not accept relative icon path.
 *
 * See: elm_toolbar_item_icon_set()
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of the item.
 * @param[in] func The function to call when the item is clicked.
 * @param[in] data The data to associate with the item for related callbacks.
 *
 * @return The created item or @c NULL upon failure.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_append(const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the number of items in a toolbar
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The number of items in @c obj toolbar
 *
 * @ingroup Elm_Toolbar
 */
EOAPI unsigned int  elm_obj_toolbar_items_count(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Prepend item to the toolbar.
 *
 * A new item will be created and prepended to the toolbar, i.e., will be set
 * as first item.
 *
 * Items created with this method can be deleted with elm_object_item_del().
 *
 * Associated @c data can be properly freed when item is deleted if a callback
 * function is set with elm_object_item_del_cb_set().
 *
 * If a function is passed as argument, it will be called every time this item
 * is selected, i.e., the user clicks over an unselected item. If such function
 * isn't needed, just passing @c NULL as @c func is enough. The same should be
 * done for @c data.
 *
 * Toolbar will load icon image from fdo or current theme. This behavior can be
 * set by elm_toolbar_icon_order_lookup_set() function. If an absolute path is
 * provided it will load it direct from a file.
 *
 * @note This function does not accept relative icon path.
 *
 * See: elm_toolbar_item_icon_set()
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of the item.
 * @param[in] func The function to call when the item is clicked.
 * @param[in] data The data to associate with the item for related callbacks.
 *
 * @return The created item or @c NULL upon failure.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_prepend(const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Returns a pointer to a toolbar item by its label.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] label The label of the item to find.
 *
 * @return The pointer to the toolbar item matching @c label or @c NULL on
 * failure.
 *
 * @ingroup Elm_Toolbar
 */
EOAPI Elm_Widget_Item * elm_obj_toolbar_item_find_by_label(const char *label);

EOAPI extern const Eo_Event_Description _ELM_TOOLBAR_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_TOOLBAR_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_TOOLBAR_EVENT_ITEM_FOCUSED;
EOAPI extern const Eo_Event_Description _ELM_TOOLBAR_EVENT_ITEM_UNFOCUSED;

/**
 * No description
 */
#define ELM_TOOLBAR_EVENT_LANGUAGE_CHANGED (&(_ELM_TOOLBAR_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_TOOLBAR_EVENT_ACCESS_CHANGED (&(_ELM_TOOLBAR_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_TOOLBAR_EVENT_ITEM_FOCUSED (&(_ELM_TOOLBAR_EVENT_ITEM_FOCUSED))

/**
 * No description
 */
#define ELM_TOOLBAR_EVENT_ITEM_UNFOCUSED (&(_ELM_TOOLBAR_EVENT_ITEM_UNFOCUSED))

#endif
