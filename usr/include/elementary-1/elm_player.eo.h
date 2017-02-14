#ifndef _ELM_PLAYER_EO_H_
#define _ELM_PLAYER_EO_H_

#ifndef _ELM_PLAYER_EO_CLASS_TYPE
#define _ELM_PLAYER_EO_CLASS_TYPE

typedef Eo Elm_Player;

#endif

#ifndef _ELM_PLAYER_EO_TYPES
#define _ELM_PLAYER_EO_TYPES


#endif
#define ELM_PLAYER_CLASS elm_player_class_get()

EAPI const Eo_Class *elm_player_class_get(void) EINA_CONST;

EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_FORWARD_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_INFO_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_NEXT_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_PAUSE_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_PLAY_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_PREV_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_REWIND_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_QUALITY_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_EJECT_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_VOLUME_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_MUTE_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_PLAYER_EVENT_LANGUAGE_CHANGED;

/**
 * No description
 */
#define ELM_PLAYER_EVENT_FORWARD_CLICKED (&(_ELM_PLAYER_EVENT_FORWARD_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_INFO_CLICKED (&(_ELM_PLAYER_EVENT_INFO_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_NEXT_CLICKED (&(_ELM_PLAYER_EVENT_NEXT_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_PAUSE_CLICKED (&(_ELM_PLAYER_EVENT_PAUSE_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_PLAY_CLICKED (&(_ELM_PLAYER_EVENT_PLAY_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_PREV_CLICKED (&(_ELM_PLAYER_EVENT_PREV_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_REWIND_CLICKED (&(_ELM_PLAYER_EVENT_REWIND_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_QUALITY_CLICKED (&(_ELM_PLAYER_EVENT_QUALITY_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_EJECT_CLICKED (&(_ELM_PLAYER_EVENT_EJECT_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_VOLUME_CLICKED (&(_ELM_PLAYER_EVENT_VOLUME_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_MUTE_CLICKED (&(_ELM_PLAYER_EVENT_MUTE_CLICKED))

/**
 * No description
 */
#define ELM_PLAYER_EVENT_LANGUAGE_CHANGED (&(_ELM_PLAYER_EVENT_LANGUAGE_CHANGED))

#endif
