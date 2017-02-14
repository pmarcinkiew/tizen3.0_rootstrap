#ifndef _ELM_MULTIBUTTONENTRY_ITEM_EO_H_
#define _ELM_MULTIBUTTONENTRY_ITEM_EO_H_

#ifndef _ELM_MULTIBUTTONENTRY_ITEM_EO_CLASS_TYPE
#define _ELM_MULTIBUTTONENTRY_ITEM_EO_CLASS_TYPE

typedef Eo Elm_Multibuttonentry_Item;

#endif

#ifndef _ELM_MULTIBUTTONENTRY_ITEM_EO_TYPES
#define _ELM_MULTIBUTTONENTRY_ITEM_EO_TYPES


#endif
#define ELM_MULTIBUTTONENTRY_ITEM_CLASS elm_multibuttonentry_item_class_get()

EAPI const Eo_Class *elm_multibuttonentry_item_class_get(void) EINA_CONST;

/**
 * @brief Control the selected state of an item
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] selected @c true if selected @c false otherwise
 *
 * @ingroup Elm_Multibuttonentry_Item
 */
EOAPI void  elm_obj_multibuttonentry_item_selected_set(Eina_Bool selected);

/**
 * @brief Control the selected state of an item
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return @c true if selected @c false otherwise
 *
 * @ingroup Elm_Multibuttonentry_Item
 */
EOAPI Eina_Bool  elm_obj_multibuttonentry_item_selected_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the previous item in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The item before the item
 *
 * @ingroup Elm_Multibuttonentry_Item
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_prev_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the next item in the multibuttonentry
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The item after the item
 *
 * @ingroup Elm_Multibuttonentry_Item
 */
EOAPI Elm_Widget_Item * elm_obj_multibuttonentry_item_next_get(void);


#endif
