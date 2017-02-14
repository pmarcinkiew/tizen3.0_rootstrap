#ifndef _ELM_GENLIST_ITEM_EO_H_
#define _ELM_GENLIST_ITEM_EO_H_

#ifndef _ELM_GENLIST_ITEM_EO_CLASS_TYPE
#define _ELM_GENLIST_ITEM_EO_CLASS_TYPE

typedef Eo Elm_Genlist_Item;

#endif

#ifndef _ELM_GENLIST_ITEM_EO_TYPES
#define _ELM_GENLIST_ITEM_EO_TYPES


#endif
#define ELM_GENLIST_ITEM_CLASS elm_genlist_item_class_get()

EAPI const Eo_Class *elm_genlist_item_class_get(void) EINA_CONST;

/**
 * @brief @c brief Get the @c b previous item in a genlist widget's internal
 * list of items, given a handle to one of those items.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This returns the item placed before the @c p item, on the
 * container genlist.
 *
 * @c see elm_genlist_item_next_get()
 *
 * @c ingroup Genlist
 *
 * @return The item before @c item, or @c null if there's none (and on errors).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Elm_Widget_Item * elm_obj_genlist_item_prev_get(void);

/**
 * @brief @c brief Get the @c b next item in a genlist widget's internal list
 * of items, given a handle to one of those items.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This returns the item placed after the @c p item, on the container
 * genlist.
 *
 * @c see elm_genlist_item_prev_get()
 *
 * @c ingroup Genlist
 *
 * @return The item after @c item, or @c null if there's none (and on errors).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Elm_Widget_Item * elm_obj_genlist_item_next_get(void);

/**
 * @brief @c brief Get the parent item of the given item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This returns the item that was specified as parent of the item
 * @c p it on elm_genlist_item_append() and insertion related functions.
 *
 * @c ingroup Genlist
 *
 * @return The parent of the item or @c null if it has no parent.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Elm_Widget_Item * elm_obj_genlist_item_parent_get(void);

/**
 * @brief et the list of subitems of a given item
 *
 * This returns the list of subitems that an item possesses. It cannot be
 * changed.
 *
 * @return The list of subitems, @c null on error.
 *
 * @since 1.9
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI const Eina_List * elm_obj_genlist_item_subitems_get(void);

/**
 * @brief @c brief Set whether a given genlist item is selected or not
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark Use @c c EINA_TRUE, to make it selected, @c c EINA_FALSE to make
 * it unselected
 *
 * @c remark This sets the selected state of an item. If multi selection is not
 * enabled on the containing genlist and @c p selected is @c c EINA_TRUE, any
 * other previously selected items will get unselected in favor of this new
 * one.
 *
 * @c see elm_genlist_item_selected_get()
 *
 * @c ingroup Genlist
 *
 * @param[in] selected The selected state ($true selected, @c false not
 * selected).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_selected_set(Eina_Bool selected);

/**
 * @brief @c brief Get whether a given genlist item is selected or not
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * *return @c c EINA_TRUE, if it's selected, @c c EINA_FALSE otherwise
 *
 * @c see elm_genlist_item_selected_set() for more details
 *
 * @c ingroup Genlist
 *
 * @return The selected state ($true selected, @c false not selected).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Eina_Bool  elm_obj_genlist_item_selected_get(void);

/**
 * @brief @c brief Sets the expanded state of an item.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This function flags the item of type #ELM_GENLIST_ITEM_TREE as
 * expanded or not.
 *
 * @c remark The theme will respond to this change visually, and a signal
 * "expanded" or "contracted" will be sent from the genlist with a pointer to
 * the item that has been expanded/contracted.
 *
 * @c remark Calling this function won't show or hide any child of this item
 * (if it is a parent). You must manually delete and create them on the
 * callbacks of the "expanded" or "contracted" signals.
 *
 * @c see elm_genlist_item_expanded_get()
 *
 * @c ingroup Genlist
 *
 * @param[in] expanded The expanded state ($true expanded, @c false not
 * expanded).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_expanded_set(Eina_Bool expanded);

/**
 * @brief @c brief Get the expanded state of an item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This gets the expanded state of an item.
 *
 * @c see elm_genlist_item_expanded_set()
 *
 * @c ingroup Genlist
 *
 * @return The expanded state ($true expanded, @c false not expanded).
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Eina_Bool  elm_obj_genlist_item_expanded_get(void);

/**
 * @brief @c brief Get the depth of expanded item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c ingroup Genlist
 *
 * @return The depth of expanded item.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI int  elm_obj_genlist_item_expanded_depth_get(void);

/**
 * @brief @c brief Get the Genlist Item class for the given Genlist Item.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This returns the Genlist_Item_Class for the given item. It can be
 * used to examine the function pointers and item_style.
 *
 * @c ingroup Genlist
 *
 * @return Genlist Item class for the given item
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI const Elm_Genlist_Item_Class * elm_obj_genlist_item_class_get(void);

/**
 * @brief @c brief Get the index of the item. It is only valid once displayed.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c ingroup Genlist
 *
 * @return *return the position inside the list of item.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI int  elm_obj_genlist_item_index_get(void);

/**
 * @brief @c internal
 *
 * @c brief Get the item's decorate mode.
 *
 * @c remark This function just returns the name of the item's decorate mode.
 *
 * @c see elm_genlist_item_decorate_mode_set() @c see
 * elm_genlist_decorated_item_get()
 *
 * @c ingroup Genlist
 *
 * @return name of the item's decorate mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI const char * elm_obj_genlist_item_decorate_mode_get(void);

/**
 * @brief @c internal
 *
 * @c brief Set the flip state of a given genlist item.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark ($c EINA_TRUE = on, @c c EINA_FALSE = off)
 *
 * @c remark This function sets the flip state of a given genlist item. Flip
 * mode overrides current item object. It can be used for on-the-fly item
 * replace. Flip mode can be used with/without decorate mode.
 *
 * @c see elm_genlist_item_flip_get()
 *
 * @c ingroup Genlist
 *
 * @param[in] flip The flip mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_flip_set(Eina_Bool flip);

/**
 * @brief @c internal
 *
 * @c brief Get the flip state of a given genlist item.
 *
 * @c remark This function returns the flip state of a given genlist item. If
 * the parameter is invalid, it returns @c c EINA_FALSE.
 *
 * @c see elm_genlist_item_flip_set()
 *
 * @c ingroup Genlist
 *
 * @return The flip mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Eina_Bool  elm_obj_genlist_item_flip_get(void);

/**
 * @brief @c brief Set the genlist item's select mode.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark elm_genlist_select_mode_set() changes item's select mode. -
 * ELM_OBJECT_SELECT_MODE_DEFAULT : The item will only call their selection
 * func and callback when first becoming selected. Any further clicks will do
 * nothing, unless you set always select mode. - ELM_OBJECT_SELECT_MODE_ALWAYS
 * : This means that, even if selected, every click will make the selected
 * callbacks be called. - ELM_OBJECT_SELECT_MODE_NONE : This will turn off the
 * ability to select the item entirely and they will neither appear selected
 * nor call selected callback functions. - ELM_OBJECT_SELECT_MODE_DISPLAY_ONLY
 * : This will apply no-finger-size rule with ELM_OBJECT_SELECT_MODE_NONE.
 * No-finger-size rule makes an item can be smaller than lower limit. Clickable
 * objects should be bigger than human touch point device (your finger) for
 * some touch or small screen devices. So it is enabled, the item can be shrink
 * than predefined finger-size value. And the item will be updated.
 *
 * @c see elm_genlist_item_select_mode_get()
 *
 * @c ingroup Genlist
 *
 * @param[in] mode The selected mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_select_mode_set(Elm_Object_Select_Mode mode);

/**
 * @brief @c brief Get the genlist item's select mode.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * *return The select mode (If getting mode fails, it returns
 * ELM_OBJECT_SELECT_MODE_MAX)
 *
 * @c see elm_genlist_item_select_mode_set()
 *
 * @c ingroup Genlist
 *
 * @return The selected mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Elm_Object_Select_Mode  elm_obj_genlist_item_select_mode_get(void);

/**
 * @brief @c brief Get the Item's Type
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * *return The item type.
 *
 * @c remark This function returns the item's type. Normally the item's type.
 * If it failed, return value is ELM_GENLIST_ITEM_MAX
 *
 * @c ingroup Genlist
 *
 * @return Item type.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI Elm_Genlist_Item_Type  elm_obj_genlist_item_type_get(void);

/**
 * @brief @c brief Remove all sub-items (children) of the given item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c param it The item
 *
 * @c remark This removes all items that are children (and their descendants)
 * of the given item @c p it.
 *
 * @c see elm_genlist_clear() @c see elm_object_item_del()
 *
 * @c ingroup Genlist
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_subitems_clear(void);

/**
 * @brief @c brief Promote an item to the top of the list
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c param it The item
 *
 * @c ingroup Genlist
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_promote(void);

/**
 * @brief @c brief Demote an item to the end of the list
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c param it The item
 *
 * @c ingroup Genlist
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_demote(void);

/**
 * @brief @c brief Show the portion of a genlist's internal list containing a
 * given item, immediately.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This causes genlist to jump to the given item @c p it and show it
 * (by jumping to that position), if it is not fully visible.
 *
 * @c see elm_genlist_item_bring_in()
 *
 * @c ingroup Genlist
 *
 * @param[in] type The position to bring in, the given item to. $ref
 * Elm_Genlist_Item_Scrollto_Type.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_show(Elm_Genlist_Item_Scrollto_Type type);

/**
 * @brief @c brief Animatedly bring in, to the visible area of a genlist, a
 * given item on it.
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This causes genlist to jump to the given item @c p it and show it
 * (by animatedly scrolling), if it is not fully visible. This may use
 * animation and take a some time to do so.
 *
 * @c see elm_genlist_item_show()
 *
 * @c ingroup Genlist
 *
 * @param[in] type The position to bring in, the given item to. $ref
 * Elm_Genlist_Item_Scrollto_Type.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_bring_in(Elm_Genlist_Item_Scrollto_Type type);

/**
 * @brief @c brief Unset all contents fetched by the item class
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This instructs genlist to release references to contents in the
 * item, meaning that they will no longer be managed by genlist and are
 * floating "orphans" that can be re-used elsewhere if the user wants to.
 *
 * @c ingroup Genlist
 *
 * @param[out] l The contents list to return.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_all_contents_unset(Eina_List **l);

/**
 * @brief @c brief Update all the contents of an item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This updates an item by calling all the item class functions again
 * to get the contents, texts and states. Use this when the original item data
 * has changed and the changes are desired to be reflected.
 *
 * @c remark Use elm_genlist_realized_items_update() to update all already
 * realized items.
 *
 * @c remark This also updates internal genlist item object(edje_object as of
 * now). So when this is called between mouse down and mouse up, mouse up event
 * will be ignored because edje_object is deleted and created again by this
 * API. If you want to avoid this, please use @c ref
 * elm_genlist_item_fields_update.
 *
 * @c see elm_genlist_realized_items_update()
 *
 * @c ingroup Genlist
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_update(void);

/**
 * @brief @c brief Update the part of an item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This updates an item's part by calling item's fetching functions
 * again to get the contents, texts and states. Use this when the original item
 * data has changed and the changes are desired to be reflected. Second parts
 * argument is used for globbing to match '*', '?', and '.' It can be used at
 * updating multi fields.
 *
 * @c remark Use elm_genlist_realized_items_update() to update an item's all
 * property.
 *
 * @c see elm_genlist_item_update()
 *
 * @c ingroup Genlist
 *
 * @param[in] itf The type of item's part type.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_fields_update(const char *parts, Elm_Genlist_Item_Field_Type itf);

/**
 * @brief @c brief Update the item class of an item
 *
 * @c if MOBILE @c since_tizen 2.3 @c elseif WEARABLE @c since_tizen 2.3.1
 * @c endif
 *
 * @c remark This sets another class of the item, changing the way that it is
 * displayed. After changing the item class, elm_genlist_item_update() is
 * called on the item @c p it.
 *
 * @c ingroup Genlist
 *
 * @param[in] itc The item class for the item.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_class_update(const Elm_Genlist_Item_Class *itc);

/**
 * @brief @c internal
 *
 * @c brief Activate a genlist mode on an item
 *
 * @c remark A genlist mode is a different way of selecting an item. Once a
 * mode is activated on an item, any other selected item is immediately
 * unselected. This feature provides an easy way of implementing a new kind of
 * animation for selecting an item, without having to entirely rewrite the item
 * style theme. However, the elm_genlist_selected_* API can't be used to get
 * what item is activate for a mode.
 *
 * @c remark The current item style will still be used, but applying a genlist
 * mode to an item will select it using a different kind of animation.
 *
 * @c remark The current active item for a mode can be found by
 * elm_genlist_decorated_item_get().
 *
 * @c remark The characteristics of genlist mode are: - Only one mode can be
 * active at any time, and for only one item. - Genlist handles deactivating
 * other items when one item is activated. - A mode is defined in the genlist
 * theme (edc), and more modes can easily be added. - A mode style and the
 * genlist item style are different things. They can be combined to provide a
 * default style to the item, with some kind of animation for that item when
 * the mode is activated.
 *
 * @c remark When a mode is activated on an item, a new view for that item is
 * created. The theme of this mode defines the animation that will be used to
 * transit the item from the old view to the new view. This second (new) view
 * will be active for that item while the mode is active on the item, and will
 * be destroyed after the mode is totally deactivated from that item.
 *
 * @c see elm_genlist_mode_get() @c see elm_genlist_decorated_item_get()
 *
 * @c ingroup Genlist
 *
 * @param[in] decorate_it_set Boolean to define set or unset mode.
 *
 * @ingroup Elm_Genlist_Item
 */
EOAPI void  elm_obj_genlist_item_decorate_mode_set(const char *decorate_it_type, Eina_Bool decorate_it_set);


#endif
