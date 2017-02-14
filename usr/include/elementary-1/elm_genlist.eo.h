#ifndef _ELM_GENLIST_EO_H_
#define _ELM_GENLIST_EO_H_

#ifndef _ELM_GENLIST_EO_CLASS_TYPE
#define _ELM_GENLIST_EO_CLASS_TYPE

typedef Eo Elm_Genlist;

#endif

#ifndef _ELM_GENLIST_EO_TYPES
#define _ELM_GENLIST_EO_TYPES


#endif
#define ELM_GENLIST_CLASS elm_genlist_class_get()

EAPI const Eo_Class *elm_genlist_class_get(void) EINA_CONST;

EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_ITEM_FOCUSED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_ITEM_UNFOCUSED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_VBAR_DRAG;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_VBAR_PRESS;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_VBAR_UNPRESS;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_HBAR_DRAG;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_HBAR_PRESS;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_HBAR_UNPRESS;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EDGE_TOP;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EDGE_BOTTOM;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EDGE_LEFT;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EDGE_RIGHT;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MOVED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MOVED_BEFORE;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MOVED_AFTER;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_SWIPE;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_PINCH_IN;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_PINCH_OUT;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_SWIPE_DOWN;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_SWIPE_UP;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_SWIPE_RIGHT;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_MULTI_SWIPE_LEFT;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_RELEASED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_ACTIVATED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_HIGHLIGHTED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_UNHIGHLIGHTED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_REALIZED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_UNREALIZED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_CONTRACT_REQUEST;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EXPAND_REQUEST;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_CONTRACTED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_EXPANDED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_INDEX_UPDATE;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_TREE_EFFECT_FINISHED;
EOAPI extern const Eo_Event_Description _ELM_GENLIST_EVENT_FILTER_DONE;

/**
 * No description
 */
#define ELM_GENLIST_EVENT_LANGUAGE_CHANGED (&(_ELM_GENLIST_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_ACCESS_CHANGED (&(_ELM_GENLIST_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_ITEM_FOCUSED (&(_ELM_GENLIST_EVENT_ITEM_FOCUSED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_ITEM_UNFOCUSED (&(_ELM_GENLIST_EVENT_ITEM_UNFOCUSED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_VBAR_DRAG (&(_ELM_GENLIST_EVENT_VBAR_DRAG))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_VBAR_PRESS (&(_ELM_GENLIST_EVENT_VBAR_PRESS))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_VBAR_UNPRESS (&(_ELM_GENLIST_EVENT_VBAR_UNPRESS))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_HBAR_DRAG (&(_ELM_GENLIST_EVENT_HBAR_DRAG))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_HBAR_PRESS (&(_ELM_GENLIST_EVENT_HBAR_PRESS))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_HBAR_UNPRESS (&(_ELM_GENLIST_EVENT_HBAR_UNPRESS))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EDGE_TOP (&(_ELM_GENLIST_EVENT_EDGE_TOP))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EDGE_BOTTOM (&(_ELM_GENLIST_EVENT_EDGE_BOTTOM))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EDGE_LEFT (&(_ELM_GENLIST_EVENT_EDGE_LEFT))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EDGE_RIGHT (&(_ELM_GENLIST_EVENT_EDGE_RIGHT))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MOVED (&(_ELM_GENLIST_EVENT_MOVED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MOVED_BEFORE (&(_ELM_GENLIST_EVENT_MOVED_BEFORE))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MOVED_AFTER (&(_ELM_GENLIST_EVENT_MOVED_AFTER))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_SWIPE (&(_ELM_GENLIST_EVENT_SWIPE))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_PINCH_IN (&(_ELM_GENLIST_EVENT_MULTI_PINCH_IN))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_PINCH_OUT (&(_ELM_GENLIST_EVENT_MULTI_PINCH_OUT))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_SWIPE_DOWN (&(_ELM_GENLIST_EVENT_MULTI_SWIPE_DOWN))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_SWIPE_UP (&(_ELM_GENLIST_EVENT_MULTI_SWIPE_UP))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_SWIPE_RIGHT (&(_ELM_GENLIST_EVENT_MULTI_SWIPE_RIGHT))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_MULTI_SWIPE_LEFT (&(_ELM_GENLIST_EVENT_MULTI_SWIPE_LEFT))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_RELEASED (&(_ELM_GENLIST_EVENT_RELEASED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_ACTIVATED (&(_ELM_GENLIST_EVENT_ACTIVATED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_HIGHLIGHTED (&(_ELM_GENLIST_EVENT_HIGHLIGHTED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_UNHIGHLIGHTED (&(_ELM_GENLIST_EVENT_UNHIGHLIGHTED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_REALIZED (&(_ELM_GENLIST_EVENT_REALIZED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_UNREALIZED (&(_ELM_GENLIST_EVENT_UNREALIZED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_CONTRACT_REQUEST (&(_ELM_GENLIST_EVENT_CONTRACT_REQUEST))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EXPAND_REQUEST (&(_ELM_GENLIST_EVENT_EXPAND_REQUEST))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_CONTRACTED (&(_ELM_GENLIST_EVENT_CONTRACTED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_EXPANDED (&(_ELM_GENLIST_EVENT_EXPANDED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_INDEX_UPDATE (&(_ELM_GENLIST_EVENT_INDEX_UPDATE))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_TREE_EFFECT_FINISHED (&(_ELM_GENLIST_EVENT_TREE_EFFECT_FINISHED))

/**
 * No description
 */
#define ELM_GENLIST_EVENT_FILTER_DONE (&(_ELM_GENLIST_EVENT_FILTER_DONE))

#endif
