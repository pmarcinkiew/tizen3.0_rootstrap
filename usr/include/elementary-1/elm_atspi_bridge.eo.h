#ifndef _ELM_ATSPI_BRIDGE_EO_H_
#define _ELM_ATSPI_BRIDGE_EO_H_

#ifndef _ELM_ATSPI_BRIDGE_EO_CLASS_TYPE
#define _ELM_ATSPI_BRIDGE_EO_CLASS_TYPE

typedef Eo Elm_Atspi_Bridge;

#endif

#ifndef _ELM_ATSPI_BRIDGE_EO_TYPES
#define _ELM_ATSPI_BRIDGE_EO_TYPES


#endif
#define ELM_ATSPI_BRIDGE_CLASS elm_atspi_bridge_class_get()

EAPI const Eo_Class *elm_atspi_bridge_class_get(void) EINA_CONST;

/**
 * @brief Indicate if connection with AT-SPI2 bus has been established.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Elm_Atspi_Bridge
 */
EOAPI Eina_Bool  elm_obj_atspi_bridge_connected_get(void);

/** Get root object of accessible object hierarchy
 *
 * @ingroup Elm_Atspi_Bridge
 */
EOAPI Eo * elm_obj_atspi_bridge_root_get(void);

EOAPI extern const Eo_Event_Description _ELM_ATSPI_BRIDGE_EVENT_CONNECTED;
EOAPI extern const Eo_Event_Description _ELM_ATSPI_BRIDGE_EVENT_DISCONNECTED;

/**
 * No description
 */
#define ELM_ATSPI_BRIDGE_EVENT_CONNECTED (&(_ELM_ATSPI_BRIDGE_EVENT_CONNECTED))

/**
 * No description
 */
#define ELM_ATSPI_BRIDGE_EVENT_DISCONNECTED (&(_ELM_ATSPI_BRIDGE_EVENT_DISCONNECTED))

#endif
