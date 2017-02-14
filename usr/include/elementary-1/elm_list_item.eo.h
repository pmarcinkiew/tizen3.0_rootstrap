#ifndef _ELM_LIST_ITEM_EO_H_
#define _ELM_LIST_ITEM_EO_H_

#ifndef _ELM_LIST_ITEM_EO_CLASS_TYPE
#define _ELM_LIST_ITEM_EO_CLASS_TYPE

typedef Eo Elm_List_Item;

#endif

#ifndef _ELM_LIST_ITEM_EO_TYPES
#define _ELM_LIST_ITEM_EO_TYPES


#endif
#define ELM_LIST_ITEM_CLASS elm_list_item_class_get()

EAPI const Eo_Class *elm_list_item_class_get(void) EINA_CONST;

/**
 * @brief Set or unset item as a separator.
 *
 * Items aren't set as separator by default.
 *
 * If set as separator it will display separator theme, so won't display icons
 * or label.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] setting @c true means item @c it is a separator. @c false
 * indicates it's not.
 *
 * @ingroup Elm_List_Item
 */
EOAPI void  elm_obj_list_item_separator_set(Eina_Bool setting);

/**
 * @brief Get a value whether item is a separator or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true means item @c it is a separator. @c false indicates it's
 * not.
 *
 * @ingroup Elm_List_Item
 */
EOAPI Eina_Bool  elm_obj_list_item_separator_get(void);

/**
 * @brief Set the selected state of an item.
 *
 * This sets the selected state of the given item.
 *
 * If a new item is selected the previously selected will be unselected, unless
 * multiple selection is enabled with @ref elm_list_multi_select_set.
 * Previously selected item can be get with function @ref
 * elm_list_selected_item_get.
 *
 * Selected items will be highlighted.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] selected The selected state.
 *
 * @ingroup Elm_List_Item
 */
EOAPI void  elm_obj_list_item_selected_set(Eina_Bool selected);

/**
 * @brief Get whether the item is selected or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The selected state.
 *
 * @ingroup Elm_List_Item
 */
EOAPI Eina_Bool  elm_obj_list_item_selected_get(void);

/**
 * @brief Get the real Evas(Edje) object created to implement the view of a
 * given list item.
 *
 * Base object is the @c Evas_Object that represents that item.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The base Edje object associated with the item.
 *
 * @ingroup Elm_List_Item
 */
EOAPI Evas_Object * elm_obj_list_item_object_get(void);

/**
 * @brief Get the item before the item in list.
 *
 * @note If it is the first item, @c null will be returned.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The item before or @c null.
 *
 * @ingroup Elm_List_Item
 */
EOAPI Elm_Widget_Item * elm_obj_list_item_prev_get(void);

/**
 * @brief Get the item after the item in list.
 *
 * @note If it is the last item, @c null will be returned.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The item after or @c null.
 *
 * @ingroup Elm_List_Item
 */
EOAPI Elm_Widget_Item * elm_obj_list_item_next_get(void);

/**
 * @brief Show item in the list view.
 *
 * It won't animate list until item is visible. If such behavior is wanted, use
 * @ref elm_obj_list_item_bring_in instead.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_List_Item
 */
EOAPI void  elm_obj_list_item_show(void);

/**
 * @brief Bring in the given item to list view.
 *
 * This causes list to jump to the given item and show it (by scrolling), if it
 * is not fully visible.
 *
 * This may use animation to do so and take a period of time.
 *
 * If animation isn't wanted, @ref elm_obj_list_item_show can be used.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_List_Item
 */
EOAPI void  elm_obj_list_item_bring_in(void);


#endif
