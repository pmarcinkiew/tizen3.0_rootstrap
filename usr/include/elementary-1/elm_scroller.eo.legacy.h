#ifndef _ELM_SCROLLER_EO_LEGACY_H_
#define _ELM_SCROLLER_EO_LEGACY_H_

#ifndef _ELM_SCROLLER_EO_CLASS_TYPE
#define _ELM_SCROLLER_EO_CLASS_TYPE

typedef Eo Elm_Scroller;

#endif

#ifndef _ELM_SCROLLER_EO_TYPES
#define _ELM_SCROLLER_EO_TYPES

/**
 * @brief Type that controls when scrollbars should appear.
 *
 * See also @ref Elm_Interface_Scrollable.policy.set.
 *
 * @ingroup Elm_Scroller
 */
typedef enum
{
  ELM_SCROLLER_POLICY_AUTO = 0, /** Show scrollbars as needed */
  ELM_SCROLLER_POLICY_ON, /** Always show scrollbars */
  ELM_SCROLLER_POLICY_OFF, /** Never show scrollbars */
  ELM_SCROLLER_POLICY_LAST
} Elm_Scroller_Policy;

/**
 * @brief Type that controls how the content is scrolled.
 *
 * See also @ref Elm_Interface_Scrollable.single_direction.set.
 *
 * @ingroup Elm_Scroller
 */
typedef enum
{
  ELM_SCROLLER_SINGLE_DIRECTION_NONE = 0, /** Scroll every direction */
  ELM_SCROLLER_SINGLE_DIRECTION_SOFT, /** Scroll single direction if the
                                       * direction is certain */
  ELM_SCROLLER_SINGLE_DIRECTION_HARD, /** Scroll only single direction */
  ELM_SCROLLER_SINGLE_DIRECTION_LAST
} Elm_Scroller_Single_Direction;

/** Type that blocks the scroll movement in one or more direction.
 *
 * @since 1.8
 *
 * @ingroup Elm_Scroller
 */
typedef enum
{
  ELM_SCROLLER_MOVEMENT_NO_BLOCK = 1 /* 0 << 0 */, /** Do not block movements
                                                    */
  ELM_SCROLLER_MOVEMENT_BLOCK_VERTICAL = 2 /* 0 << 0 */, /** Block vertical
                                                          * movements */
  ELM_SCROLLER_MOVEMENT_BLOCK_HORIZONTAL = 4 /* 0 << 0 */ /** Block horizontal
                                                           * movements */
} Elm_Scroller_Movement_Block;


#endif

/**
 * @brief Set event propagation on a scroller
 *
 * This enables or disables event propagation from the scroller content to the
 * scroller and its parent. By default event propagation is enabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] propagation The propagation state
 *
 * @ingroup Elm_Scroller
 */
EAPI void elm_scroller_propagate_events_set(Elm_Scroller *obj, Eina_Bool propagation);

/**
 * @brief Get event propagation for a scroller
 *
 * This gets the event propagation for a scroller.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The propagation state
 *
 * @ingroup Elm_Scroller
 */
EAPI Eina_Bool elm_scroller_propagate_events_get(const Elm_Scroller *obj);

/**
 * @internal
 *
 * @brief Set custom theme elements for the scroller
 *
 * @param[in] klass
 * @param[in] group
 *
 * @ingroup Elm_Scroller
 */
EAPI void elm_scroller_custom_widget_base_theme_set(Elm_Scroller *obj, const char *klass, const char *group);

/**
 * @brief Set the maximum of the movable page at a flicking.
 *
 * The value of maximum movable page should be more than 1.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] page_limit_v The maximum of the movable vertical page
 *
 * @since 1.8
 *
 * @ingroup Elm_Scroller
 */
EAPI void elm_scroller_page_scroll_limit_set(const Elm_Scroller *obj, int page_limit_h, int page_limit_v);

/**
 * @brief Get the maximum of the movable page at a flicking.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] page_limit_v The maximum of the movable vertical page
 *
 * @since 1.8
 *
 * @ingroup Elm_Scroller
 */
EAPI void elm_scroller_page_scroll_limit_get(const Elm_Scroller *obj, int *page_limit_h, int *page_limit_v);

#endif
