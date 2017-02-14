#ifndef _ELM_PANEL_EO_LEGACY_H_
#define _ELM_PANEL_EO_LEGACY_H_

#ifndef _ELM_PANEL_EO_CLASS_TYPE
#define _ELM_PANEL_EO_CLASS_TYPE

typedef Eo Elm_Panel;

#endif

#ifndef _ELM_PANEL_EO_TYPES
#define _ELM_PANEL_EO_TYPES

/** Panel orientation mode
 *
 * @ingroup Elm_Panel
 */
typedef enum
{
  ELM_PANEL_ORIENT_TOP = 0, /** Panel (dis)appears from the top */
  ELM_PANEL_ORIENT_BOTTOM, /** Panel (dis)appears from the bottom */
  ELM_PANEL_ORIENT_LEFT, /** Panel (dis)appears from the left */
  ELM_PANEL_ORIENT_RIGHT /** Panel (dis)appears from the right */
} Elm_Panel_Orient;


#endif

/**
 * @brief Set the orientation of the panel
 *
 * Set from where the panel will (dis)appear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] orient The panel orientation.
 *
 * @ingroup Elm_Panel
 */
EAPI void elm_panel_orient_set(Elm_Panel *obj, Elm_Panel_Orient orient);

/**
 * @brief Get the orientation of the panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The panel orientation.
 *
 * @ingroup Elm_Panel
 */
EAPI Elm_Panel_Orient elm_panel_orient_get(const Elm_Panel *obj);

/**
 * @brief Set the state of the panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] hidden If true, the panel will run the animation to disappear.
 *
 * @ingroup Elm_Panel
 */
EAPI void elm_panel_hidden_set(Elm_Panel *obj, Eina_Bool hidden);

/**
 * @brief Get the state of the panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the panel will run the animation to disappear.
 *
 * @ingroup Elm_Panel
 */
EAPI Eina_Bool elm_panel_hidden_get(const Elm_Panel *obj);

/**
 * @brief Set the scrollability of the panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] scrollable The scrollable state.
 *
 * @ingroup Elm_Panel
 */
EAPI void elm_panel_scrollable_set(Elm_Panel *obj, Eina_Bool scrollable);

/**
 * @brief Get the state of the scrollability.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The scrollable state.
 *
 * @since 1.12
 *
 * @ingroup Elm_Panel
 */
EAPI Eina_Bool elm_panel_scrollable_get(const Elm_Panel *obj);

/**
 * @brief Set the size of the scrollable panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] ratio
 *
 * @ingroup Elm_Panel
 */
EAPI void elm_panel_scrollable_content_size_set(Elm_Panel *obj, double ratio);

/**
 * @brief Toggle the hidden state of the panel from code
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Panel
 */
EAPI void elm_panel_toggle(Elm_Panel *obj);

#endif
