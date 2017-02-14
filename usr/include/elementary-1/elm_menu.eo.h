#ifndef _ELM_MENU_EO_H_
#define _ELM_MENU_EO_H_

#ifndef _ELM_MENU_EO_CLASS_TYPE
#define _ELM_MENU_EO_CLASS_TYPE

typedef Eo Elm_Menu;

#endif

#ifndef _ELM_MENU_EO_TYPES
#define _ELM_MENU_EO_TYPES


#endif
#define ELM_MENU_CLASS elm_menu_class_get()

EAPI const Eo_Class *elm_menu_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Get the selected item in the menu.
 *
 * @return The selected item or @c null.
 *
 * @ingroup Elm_Menu
 */
EOAPI Elm_Widget_Item * elm_obj_menu_selected_item_get(void);

/**
 * @internal
 *
 * Returns a list of the item's items.
 *
 * @ingroup Elm_Menu
 */
EOAPI const Eina_List * elm_obj_menu_items_get(void);

/**
 * @internal
 *
 * Get the first item in the menu.
 *
 * @ingroup Elm_Menu
 */
EOAPI Elm_Widget_Item * elm_obj_menu_first_item_get(void);

/**
 * @internal
 *
 * Get the last item in the menu.
 *
 * @ingroup Elm_Menu
 */
EOAPI Elm_Widget_Item * elm_obj_menu_last_item_get(void);

/**
 * @internal
 *
 * @brief Move the menu to a new position
 *
 * Sets the top-left position of the menu to ($x, @c y).
 *
 * @note @c x and @c y coordinates are relative to parent.
 *
 * @param[in] y The new position.
 *
 * @ingroup Elm_Menu
 */
EOAPI void  elm_obj_menu_move(Evas_Coord x, Evas_Coord y);

/**
 * @internal
 *
 * @brief Add an item at the end of the given menu widget.
 *
 * @note This function does not accept relative icon path.
 *
 * @param[in] icon An icon display on the item. The icon will be destroyed by
 * the menu.
 * @param[in] label The label of the item.
 * @param[in] func Function called when the user select the item.
 * @param[in] data Data sent by the callback.
 *
 * @return The new menu item.
 *
 * @ingroup Elm_Menu
 */
EOAPI Elm_Widget_Item * elm_obj_menu_item_add(Elm_Widget_Item *parent, const char *icon, const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @internal
 *
 * @brief Close a opened menu
 *
 * Hides the menu and all it's sub-menus.
 *
 * @ingroup Elm_Menu
 */
EOAPI void  elm_obj_menu_close(void);

/**
 * @internal
 *
 * @brief Add a separator item to menu @c obj under
 * @c parent.
 *
 * @param[in] parent The item to add the separator under.
 *
 * @return The created item or @c null.
 *
 * @ingroup Elm_Menu
 */
EOAPI Elm_Widget_Item * elm_obj_menu_item_separator_add(Elm_Widget_Item *parent);

EOAPI extern const Eo_Event_Description _ELM_MENU_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_MENU_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_MENU_EVENT_DISMISSED;
EOAPI extern const Eo_Event_Description _ELM_MENU_EVENT_ELM_ACTION_BLOCK_MENU;
EOAPI extern const Eo_Event_Description _ELM_MENU_EVENT_ELM_ACTION_UNBLOCK_MENU;

/**
 * No description
 */
#define ELM_MENU_EVENT_LANGUAGE_CHANGED (&(_ELM_MENU_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_MENU_EVENT_ACCESS_CHANGED (&(_ELM_MENU_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_MENU_EVENT_DISMISSED (&(_ELM_MENU_EVENT_DISMISSED))

/**
 * No description
 */
#define ELM_MENU_EVENT_ELM_ACTION_BLOCK_MENU (&(_ELM_MENU_EVENT_ELM_ACTION_BLOCK_MENU))

/**
 * No description
 */
#define ELM_MENU_EVENT_ELM_ACTION_UNBLOCK_MENU (&(_ELM_MENU_EVENT_ELM_ACTION_UNBLOCK_MENU))

#endif
