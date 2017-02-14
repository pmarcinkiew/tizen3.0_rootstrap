#ifndef _ELM_FRAME_EO_H_
#define _ELM_FRAME_EO_H_

#ifndef _ELM_FRAME_EO_CLASS_TYPE
#define _ELM_FRAME_EO_CLASS_TYPE

typedef Eo Elm_Frame;

#endif

#ifndef _ELM_FRAME_EO_TYPES
#define _ELM_FRAME_EO_TYPES


#endif
#define ELM_FRAME_CLASS elm_frame_class_get()

EAPI const Eo_Class *elm_frame_class_get(void) EINA_CONST;

/**
 * @brief Manually collapse a frame without animations Use this to toggle the
 * collapsed state of a frame, bypassing animations.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] collapse @c true to collapse, @c false to expand.
 *
 * @ingroup Elm_Frame
 */
EOAPI void  elm_obj_frame_collapse_set(Eina_Bool collapse);

/**
 * @brief Determine the collapse state of a frame Use this to determine the
 * collapse state of a frame.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return @c true to collapse, @c false to expand.
 *
 * @ingroup Elm_Frame
 */
EOAPI Eina_Bool  elm_obj_frame_collapse_get(void);

/**
 * @brief Toggle autocollapsing of a frame When @c enable is @c true, clicking
 * a frame's label will collapse the frame vertically, shrinking it to the
 * height of the label. By default, this is DISABLED.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] autocollapse Whether to enable autocollapse.
 *
 * @ingroup Elm_Frame
 */
EOAPI void  elm_obj_frame_autocollapse_set(Eina_Bool autocollapse);

/**
 * @brief Determine autocollapsing of a frame
 *
 * When this returns @c true, clicking a frame's label will collapse the frame
 * vertically, shrinking it to the height of the label. By default, this is
 * DISABLED.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return Whether to enable autocollapse.
 *
 * @ingroup Elm_Frame
 */
EOAPI Eina_Bool  elm_obj_frame_autocollapse_get(void);

/**
 * @brief Manually collapse a frame with animations Use this to toggle the
 * collapsed state of a frame, triggering animations.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] collapse @c true to collapse, @c false to expand.
 *
 * @ingroup Elm_Frame
 */
EOAPI void  elm_obj_frame_collapse_go(Eina_Bool collapse);

EOAPI extern const Eo_Event_Description _ELM_FRAME_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_FRAME_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_FRAME_EVENT_LANGUAGE_CHANGED (&(_ELM_FRAME_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_FRAME_EVENT_ACCESS_CHANGED (&(_ELM_FRAME_EVENT_ACCESS_CHANGED))

#endif
