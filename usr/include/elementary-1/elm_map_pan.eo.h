#ifndef _ELM_MAP_PAN_EO_H_
#define _ELM_MAP_PAN_EO_H_

#ifndef _ELM_MAP_PAN_EO_CLASS_TYPE
#define _ELM_MAP_PAN_EO_CLASS_TYPE

typedef Eo Elm_Map_Pan;

#endif

#ifndef _ELM_MAP_PAN_EO_TYPES
#define _ELM_MAP_PAN_EO_TYPES


#endif
#define ELM_MAP_PAN_CLASS elm_map_pan_class_get()

EAPI const Eo_Class *elm_map_pan_class_get(void) EINA_CONST;

EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_TILE_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_TILE_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_TILE_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_ROUTE_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_ROUTE_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_ROUTE_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_NAME_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_NAME_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_NAME_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_OVERLAY_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_OVERLAY_DEL;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_MAP_PAN_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_LOADED (&(_ELM_MAP_PAN_EVENT_LOADED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_TILE_LOAD (&(_ELM_MAP_PAN_EVENT_TILE_LOAD))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_TILE_LOADED (&(_ELM_MAP_PAN_EVENT_TILE_LOADED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_TILE_LOADED_FAIL (&(_ELM_MAP_PAN_EVENT_TILE_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_ROUTE_LOAD (&(_ELM_MAP_PAN_EVENT_ROUTE_LOAD))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_ROUTE_LOADED (&(_ELM_MAP_PAN_EVENT_ROUTE_LOADED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_ROUTE_LOADED_FAIL (&(_ELM_MAP_PAN_EVENT_ROUTE_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_NAME_LOAD (&(_ELM_MAP_PAN_EVENT_NAME_LOAD))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_NAME_LOADED (&(_ELM_MAP_PAN_EVENT_NAME_LOADED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_NAME_LOADED_FAIL (&(_ELM_MAP_PAN_EVENT_NAME_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_OVERLAY_CLICKED (&(_ELM_MAP_PAN_EVENT_OVERLAY_CLICKED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_OVERLAY_DEL (&(_ELM_MAP_PAN_EVENT_OVERLAY_DEL))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_LANGUAGE_CHANGED (&(_ELM_MAP_PAN_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_MAP_PAN_EVENT_ACCESS_CHANGED (&(_ELM_MAP_PAN_EVENT_ACCESS_CHANGED))

#endif
