#ifndef _ELM_COLORSELECTOR_EO_LEGACY_H_
#define _ELM_COLORSELECTOR_EO_LEGACY_H_

#ifndef _ELM_COLORSELECTOR_EO_CLASS_TYPE
#define _ELM_COLORSELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Colorselector;

#endif

#ifndef _ELM_COLORSELECTOR_EO_TYPES
#define _ELM_COLORSELECTOR_EO_TYPES


#endif

/**
 * @brief @MOBILE_ONLY
 *
 * Set color to colorselector.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] r r-value of color
 * @param[in] g g-value of color
 * @param[in] b b-value of color
 * @param[in] a a-value of color
 *
 * @ingroup Elm_Colorselector
 */
EAPI void elm_colorselector_color_set(Elm_Colorselector *obj, int r, int g, int b, int a);

/**
 * @brief @MOBILE_ONLY
 *
 * Get current color from colorselector.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[out] r r-value of color
 * @param[out] g g-value of color
 * @param[out] b b-value of color
 * @param[out] a a-value of color
 *
 * @ingroup Elm_Colorselector
 */
EAPI void elm_colorselector_color_get(const Elm_Colorselector *obj, int *r, int *g, int *b, int *a);

/**
 * @brief @MOBILE_ONLY
 *
 * Set current palette's name
 *
 * When colorpalette name is set, colors will be loaded from and saved to
 * config using the set name. If no name is set then colors will be loaded from
 * or saved to "default" config.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] palette_name Name of palette
 *
 * @ingroup Elm_Colorselector
 */
EAPI void elm_colorselector_palette_name_set(Elm_Colorselector *obj, const char *palette_name);

/**
 * @brief @MOBILE_ONLY
 *
 * Get current palette's name
 *
 * Returns the currently set palette name using which colors will be
 * saved/loaded in to config.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return Name of palette
 *
 * @ingroup Elm_Colorselector
 */
EAPI const char *elm_colorselector_palette_name_get(const Elm_Colorselector *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set Colorselector's mode.
 *
 * Colorselector supports three modes palette only, selector only and both.
 * Only palette mode is supported in Tizen 3.0.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] mode Elm_Colorselector_Mode
 *
 * @ingroup Elm_Colorselector
 */
EAPI void elm_colorselector_mode_set(Elm_Colorselector *obj, Elm_Colorselector_Mode mode);

/**
 * @brief @MOBILE_ONLY
 *
 * Get Colorselector's mode.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return Elm_Colorselector_Mode
 *
 * @ingroup Elm_Colorselector
 */
EAPI Elm_Colorselector_Mode elm_colorselector_mode_get(const Elm_Colorselector *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Get list of palette items.
 *
 * Note That palette item list is internally managed by colorselector widget
 * and it should not be freed/modified by application.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @return The list of color palette items.
 *
 * @since 1.9
 *
 * @ingroup Elm_Colorselector
 */
EAPI const Eina_List *elm_colorselector_palette_items_get(const Elm_Colorselector *obj);

/**
 * @internal
 *
 * @brief Get the selected item in colorselector palette.
 *
 * @return The selected item, or @c null if none selected.
 *
 * @since 1.9
 *
 * @ingroup Elm_Colorselector
 */
EAPI Elm_Widget_Item *elm_colorselector_palette_selected_item_get(const Elm_Colorselector *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Add a new color item to palette.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @param[in] g g-value of color
 * @param[in] b b-value of color
 * @param[in] a a-value of color
 *
 * @return A new color palette Item.
 *
 * @ingroup Elm_Colorselector
 */
EAPI Elm_Widget_Item *elm_colorselector_palette_color_add(Elm_Colorselector *obj, int r, int g, int b, int a);

/**
 * @brief @MOBILE_ONLY
 *
 * Clear the palette items.
 *
 * @if MOBILE @since_tizen 2.3 @endif
 *
 * @ingroup Elm_Colorselector
 */
EAPI void elm_colorselector_palette_clear(Elm_Colorselector *obj);

#endif
