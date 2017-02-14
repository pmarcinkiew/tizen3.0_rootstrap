#ifndef _EVAS_TEXT_EO_LEGACY_H_
#define _EVAS_TEXT_EO_LEGACY_H_

#ifndef _EVAS_TEXT_EO_CLASS_TYPE
#define _EVAS_TEXT_EO_CLASS_TYPE

typedef Eo Evas_Text;

#endif

#ifndef _EVAS_TEXT_EO_TYPES
#define _EVAS_TEXT_EO_TYPES


#endif

/**
 * @brief Controls the shadow color for the given text object.
 *
 * Shadow effects, which are fading colors decorating the text underneath it,
 * will just be shown if the object is set to one of the following styles:
 *
 * - @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_FAR_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SOFT_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SOFT_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_FAR_SOFT_SHADOW
 *
 * One can also change the direction where the shadow grows to, with
 * @ref evas_object_text_style_get
 *
 * See @ref evas_object_text_shadow_color_get
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] r The red component of the given color.
 * @param[in] g The green component of the given color.
 * @param[in] b The blue component of the given color.
 * @param[in] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_shadow_color_set(Evas_Text *obj, int r, int g, int b, int a);

/**
 * @brief Controls the shadow color for the given text object.
 *
 * Shadow effects, which are fading colors decorating the text underneath it,
 * will just be shown if the object is set to one of the following styles:
 *
 * - @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_FAR_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SOFT_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SOFT_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_FAR_SOFT_SHADOW
 *
 * One can also change the direction where the shadow grows to, with
 * @ref evas_object_text_style_get
 *
 * See @ref evas_object_text_shadow_color_get
 *
 * @note Use @c NULL pointers on the color components you're not interested in:
 * they'll be ignored by the function.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] r The red component of the given color.
 * @param[out] g The green component of the given color.
 * @param[out] b The blue component of the given color.
 * @param[out] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_shadow_color_get(const Evas_Text *obj, int *r, int *g, int *b, int *a);

/**
 * @brief Conttrols the ellipsis that should be used for the text object.
 *
 * This is a value between 0.0 and 1.0 indicating the position of the text to
 * be shown. 0.0 means the start will be shown and the end trimmed, 1.0 means
 * the beginning will be trimmed and the end will be shown, and any value in
 * between will cause ellipsis to be added in both end of the text and the
 * requested part to be shown. -1.0 means ellipsis is turned off.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] ellipsis the ellipsis. Allowed values: -1.0 or 0.0-1.0
 *
 * @since 1.8
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_ellipsis_set(Evas_Text *obj, double ellipsis);

/**
 * @brief Conttrols the ellipsis that should be used for the text object.
 *
 * This is a value between 0.0 and 1.0 indicating the position of the text to
 * be shown. 0.0 means the start will be shown and the end trimmed, 1.0 means
 * the beginning will be trimmed and the end will be shown, and any value in
 * between will cause ellipsis to be added in both end of the text and the
 * requested part to be shown. -1.0 means ellipsis is turned off.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return the ellipsis. Allowed values: -1.0 or 0.0-1.0
 *
 * @since 1.8
 *
 * @ingroup Evas_Text
 */
EAPI double evas_object_text_ellipsis_get(const Evas_Text *obj);

/**
 * @brief Sets the BiDi delimiters used in the textblock.
 *
 * BiDi delimiters are use for in-paragraph separation of bidi segments. This
 * is useful for example in recipients fields of e-mail clients where bidi
 * oddities can occur when mixing RTL and LTR.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] delim A null terminated string of delimiters, e.g ",|".
 *
 * @since 1.1
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_bidi_delimiters_set(Evas_Text *obj, const char *delim);

/**
 * @brief Sets the BiDi delimiters used in the textblock.
 *
 * BiDi delimiters are use for in-paragraph separation of bidi segments. This
 * is useful for example in recipients fields of e-mail clients where bidi
 * oddities can occur when mixing RTL and LTR.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A null terminated string of delimiters, e.g ",|".
 *
 * @since 1.1
 *
 * @ingroup Evas_Text
 */
EAPI const char *evas_object_text_bidi_delimiters_get(const Evas_Text *obj);

/**
 * @brief Controlss the outline color for the given text object.
 *
 * Outline effects (colored lines around text glyphs) will just be shown if the
 * object is set to one of the following styles: -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SOFT_OUTLINE -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SOFT_SHADOW
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] r The red component of the given color.
 * @param[in] g The green component of the given color.
 * @param[in] b The blue component of the given color.
 * @param[in] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_outline_color_set(Evas_Text *obj, int r, int g, int b, int a);

/**
 * @brief Controlss the outline color for the given text object.
 *
 * Outline effects (colored lines around text glyphs) will just be shown if the
 * object is set to one of the following styles: -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_SOFT_OUTLINE -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SHADOW -
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_OUTLINE_SOFT_SHADOW
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] r The red component of the given color.
 * @param[out] g The green component of the given color.
 * @param[out] b The blue component of the given color.
 * @param[out] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_outline_color_get(const Evas_Text *obj, int *r, int *g, int *b, int *a);

/**
 * @brief Sets the 'glow 2' color for the given text object.
 *
 * 'Glow 2' effects, which are glowing colors decorating the text's (immediate)
 * surroundings, will just be shown if the object is set to the
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_GLOW style. See also
 * @ref evas_object_text_glow_color_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] r The red component of the given color.
 * @param[in] g The green component of the given color.
 * @param[in] b The blue component of the given color.
 * @param[in] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_glow2_color_set(Evas_Text *obj, int r, int g, int b, int a);

/**
 * @brief Sets the 'glow 2' color for the given text object.
 *
 * 'Glow 2' effects, which are glowing colors decorating the text's (immediate)
 * surroundings, will just be shown if the object is set to the
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_GLOW style. See also
 * @ref evas_object_text_glow_color_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] r The red component of the given color.
 * @param[out] g The green component of the given color.
 * @param[out] b The blue component of the given color.
 * @param[out] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_glow2_color_get(const Evas_Text *obj, int *r, int *g, int *b, int *a);

/**
 * @brief Controls the style to apply on the given text object.
 *
 * Text object styles are one of the values in @ref Evas_Text_Style_Type Some
 * of those values are combinations of more than one style, and some account
 * for the direction of the rendering of shadow effects.
 *
 * @note One may use the helper macros #EVAS_TEXT_STYLE_BASIC_SET and
 * #EVAS_TEXT_STYLE_SHADOW_DIRECTION_SET to assemble a style value.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style a style type.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_style_set(Evas_Text *obj, Evas_Text_Style_Type style);

/**
 * @brief Controls the style to apply on the given text object.
 *
 * Text object styles are one of the values in @ref Evas_Text_Style_Type Some
 * of those values are combinations of more than one style, and some account
 * for the direction of the rendering of shadow effects.
 *
 * @note One may use the helper macros #EVAS_TEXT_STYLE_BASIC_SET and
 * #EVAS_TEXT_STYLE_SHADOW_DIRECTION_SET to assemble a style value.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return a style type.
 *
 * @ingroup Evas_Text
 */
EAPI Evas_Text_Style_Type evas_object_text_style_get(const Evas_Text *obj);

/**
 * @brief Sets the glow color for the given text object.
 *
 * Glow effects, which are glowing colors decorating the text's surroundings,
 * will just be shown if the object is set to the
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_GLOW style.
 *
 * @note Glow effects are placed from a short distance of the text itself, but
 * no touching it. For glowing effects right on the borders of the glyphs, see
 * 'glow 2' effects.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] r The red component of the given color.
 * @param[in] g The green component of the given color.
 * @param[in] b The blue component of the given color.
 * @param[in] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_glow_color_set(Evas_Text *obj, int r, int g, int b, int a);

/**
 * @brief Sets the glow color for the given text object.
 *
 * Glow effects, which are glowing colors decorating the text's surroundings,
 * will just be shown if the object is set to the
 * @ref Evas_Text_Style_Type.EVAS_TEXT_STYLE_GLOW style.
 *
 * @note Glow effects are placed from a short distance of the text itself, but
 * no touching it. For glowing effects right on the borders of the glyphs, see
 * 'glow 2' effects.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] r The red component of the given color.
 * @param[out] g The green component of the given color.
 * @param[out] b The blue component of the given color.
 * @param[out] a The alpha component of the given color.
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_glow_color_get(const Evas_Text *obj, int *r, int *g, int *b, int *a);
EAPI Evas_Coord evas_object_text_max_descent_get(const Evas_Text *obj);

/**
 * @brief Gets the text style pad of a text object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] l The left pad (or @c NULL).
 * @param[out] r The right pad (or @c NULL).
 * @param[out] t The top pad (or @c NULL).
 * @param[out] b The bottom pad (or @c NULL).
 *
 * @ingroup Evas_Text
 */
EAPI void evas_object_text_style_pad_get(const Evas_Text *obj, int *l, int *r, int *t, int *b);

/**
 * @brief Retrieves the direction of the text currently being displayed in the
 * text object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Text
 */
EAPI Evas_BiDi_Direction evas_object_text_direction_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_ascent_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_horiz_advance_get(const Evas_Text *obj);

/** // TIZEN_ONLY(20160425): Fix Evas Text truncated text case and
 * evas_object_text_horiz_width_get() is add ed. //
 * horiz_advance_without_ellipsis is changed to horiz_width_without_ellipsis.
 *
 * @ingroup Evas_Text
 */
EAPI Evas_Coord evas_object_text_horiz_width_without_ellipsis_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_inset_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_max_ascent_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_vert_advance_get(const Evas_Text *obj);
EAPI Evas_Coord evas_object_text_descent_get(const Evas_Text *obj);

/**
 * @brief Returns the logical position of the last char in the text up to the
 * pos given. this is NOT the position of the last char because of the
 * possibility of RTL in the text.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y
 *
 * @ingroup Evas_Text
 */
EAPI int evas_object_text_last_up_to_pos(const Evas_Text *obj, Evas_Coord x, Evas_Coord y);
EAPI int evas_object_text_char_coords_get(const Evas_Text *obj, Evas_Coord x, Evas_Coord y, Evas_Coord *cx, Evas_Coord *cy, Evas_Coord *cw, Evas_Coord *ch);

/**
 * @brief Retrieve position and dimension information of a character within a
 * text @ref Evas_Object
 *
 * This function is used to obtain the X, Y, width and height of the character
 * located at @c pos within the @ref Evas_Object @c obj. @c obj must be a text
 * object Any of the @c Evas_Coord parameters ($cx, @c cy, @c cw, @c ch) may be
 * @c NULL in which case no value will be assigned to that parameter.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] cx A pointer to an @ref Evas_Coord to store the X value in (can
 * be NULL).
 * @param[out] cy A pointer to an @ref Evas_Coord to store the Y value in (can
 * be NULL).
 * @param[out] cw A pointer to an @ref Evas_Coord to store the Width value in
 * (can be NULL).
 * @param[out] ch A pointer to an @ref Evas_Coord to store the Height value in
 * (can be NULL).
 *
 * @return @c false on success, @c true otherwise
 *
 * @ingroup Evas_Text
 */
EAPI Eina_Bool evas_object_text_char_pos_get(const Evas_Text *obj, int pos, Evas_Coord *cx, Evas_Coord *cy, Evas_Coord *cw, Evas_Coord *ch);

#endif
