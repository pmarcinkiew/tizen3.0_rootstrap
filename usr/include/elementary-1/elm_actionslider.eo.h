#ifndef _ELM_ACTIONSLIDER_EO_H_
#define _ELM_ACTIONSLIDER_EO_H_

#ifndef _ELM_ACTIONSLIDER_EO_CLASS_TYPE
#define _ELM_ACTIONSLIDER_EO_CLASS_TYPE

typedef Eo Elm_Actionslider;

#endif

#ifndef _ELM_ACTIONSLIDER_EO_TYPES
#define _ELM_ACTIONSLIDER_EO_TYPES

/** A position for indicators, magnets, and enabled items.
 *
 * @ingroup Elm_Actionslider
 */
typedef enum
{
  ELM_ACTIONSLIDER_NONE = 0, /** No position is set. */
  ELM_ACTIONSLIDER_LEFT = 1 /* 0 << 0 */, /** Left position. */
  ELM_ACTIONSLIDER_CENTER = 2 /* 0 << 0 */, /** Center position. */
  ELM_ACTIONSLIDER_RIGHT = 4 /* 0 << 0 */, /** Right position. */
  ELM_ACTIONSLIDER_ALL = 7 /* (0 << 0) - 0 */ /** All positions for
                                               * left/center/right. */
} Elm_Actionslider_Pos;


#endif
#define ELM_ACTIONSLIDER_CLASS elm_actionslider_class_get()

EAPI const Eo_Class *elm_actionslider_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Set actionslider indicator position.
 *
 * @param[in] pos The position of the indicator.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI void  elm_obj_actionslider_indicator_pos_set(Elm_Actionslider_Pos pos);

/**
 * @internal
 *
 * @brief Get actionslider indicator position.
 *
 * @return The position of the indicator.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI Elm_Actionslider_Pos  elm_obj_actionslider_indicator_pos_get(void);

/**
 * @internal
 *
 * @brief Set actionslider magnet position.
 *
 * To make multiple positions magnets OR them together (e.g.
 * ELM_ACTIONSLIDER_LEFT | #ELM_ACTIONSLIDER_RIGHT)
 *
 * @param[in] pos Bit mask indicating the magnet positions.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI void  elm_obj_actionslider_magnet_pos_set(Elm_Actionslider_Pos pos);

/**
 * @internal
 *
 * @brief Get actionslider magnet position.
 *
 * @return Bit mask indicating the magnet positions.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI Elm_Actionslider_Pos  elm_obj_actionslider_magnet_pos_get(void);

/**
 * @internal
 *
 * @brief Set actionslider enabled position. To set multiple
 * positions as enabled OR them together(e.g. #ELM_ACTIONSLIDER_LEFT |
 * #ELM_ACTIONSLIDER_RIGHT).
 *
 * @note All the positions are enabled by default.
 *
 * @param[in] pos Bit mask indicating the enabled positions.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI void  elm_obj_actionslider_enabled_pos_set(Elm_Actionslider_Pos pos);

/**
 * @internal
 *
 * @brief Get actionslider enabled position.
 *
 * @return Bit mask indicating the enabled positions.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI Elm_Actionslider_Pos  elm_obj_actionslider_enabled_pos_get(void);

/**
 * @internal
 *
 * Get actionslider selected label.
 *
 * @ingroup Elm_Actionslider
 */
EOAPI const char * elm_obj_actionslider_selected_label_get(void);

EOAPI extern const Eo_Event_Description _ELM_ACTIONSLIDER_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ACTIONSLIDER_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ACTIONSLIDER_EVENT_POS_CHANGED;

/**
 * No description
 */
#define ELM_ACTIONSLIDER_EVENT_LANGUAGE_CHANGED (&(_ELM_ACTIONSLIDER_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_ACTIONSLIDER_EVENT_ACCESS_CHANGED (&(_ELM_ACTIONSLIDER_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_ACTIONSLIDER_EVENT_POS_CHANGED (&(_ELM_ACTIONSLIDER_EVENT_POS_CHANGED))

#endif
