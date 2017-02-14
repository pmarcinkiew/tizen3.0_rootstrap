#ifndef _ELM_COLOR_ITEM_EO_H_
#define _ELM_COLOR_ITEM_EO_H_

#ifndef _ELM_COLOR_ITEM_EO_CLASS_TYPE
#define _ELM_COLOR_ITEM_EO_CLASS_TYPE

typedef Eo Elm_Color_Item;

#endif

#ifndef _ELM_COLOR_ITEM_EO_TYPES
#define _ELM_COLOR_ITEM_EO_TYPES


#endif
#define ELM_COLOR_ITEM_CLASS elm_color_item_class_get()

EAPI const Eo_Class *elm_color_item_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Set Palette item's color.
 *
 * @param[in] r red-value of color
 * @param[in] g green-value of color
 * @param[in] b blue-value of color
 * @param[in] a alpha-value of color
 *
 * @ingroup Elm_Color_Item
 */
EOAPI void  elm_obj_color_item_color_set(int r, int g, int b, int a);

/**
 * @internal
 *
 * @brief Get Palette item's color.
 *
 * @param[out] r red-value of color
 * @param[out] g green-value of color
 * @param[out] b blue-value of color
 * @param[out] a alpha-value of color
 *
 * @ingroup Elm_Color_Item
 */
EOAPI void  elm_obj_color_item_color_get(int *r, int *g, int *b, int *a);

/**
 * @internal
 *
 * @brief Set the selected state of color palette item
 *
 * @param[in] selected @c true if selected @c false otherwise
 *
 * @since 1.9
 *
 * @ingroup Elm_Color_Item
 */
EOAPI void  elm_obj_color_item_selected_set(Eina_Bool selected);

/**
 * @internal
 *
 * @brief Get the selected state of color palette item
 *
 * @return @c true if selected @c false otherwise
 *
 * @since 1.9
 *
 * @ingroup Elm_Color_Item
 */
EOAPI Eina_Bool  elm_obj_color_item_selected_get(void);


#endif
