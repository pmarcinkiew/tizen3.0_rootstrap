#ifndef _ELM_ATSPI_PROXY_EO_H_
#define _ELM_ATSPI_PROXY_EO_H_

#ifndef _ELM_ATSPI_PROXY_EO_CLASS_TYPE
#define _ELM_ATSPI_PROXY_EO_CLASS_TYPE

typedef Eo Elm_Atspi_Proxy;

#endif

#ifndef _ELM_ATSPI_PROXY_EO_TYPES
#define _ELM_ATSPI_PROXY_EO_TYPES


#endif
#define ELM_ATSPI_PROXY_CLASS elm_atspi_proxy_class_get()

EAPI const Eo_Class *elm_atspi_proxy_class_get(void) EINA_CONST;

EOAPI void  elm_obj_atspi_proxy_address_set(const char *bus, const char *path);

EOAPI void  elm_obj_atspi_proxy_address_get(const char **bus, const char **path);

EOAPI Elm_Atspi_Proxy_Type  elm_obj_atspi_proxy_type_get(void);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] type
 *
 * @ingroup Elm_Atspi_Proxy
 */
EOAPI void  elm_obj_atspi_proxy_constructor(Elm_Atspi_Proxy_Type type);

EOAPI void  elm_obj_atspi_proxy_address_get_retry_timer_add(void);

EOAPI extern const Eo_Event_Description _ELM_ATSPI_PROXY_EVENT_CONNECTED;
EOAPI extern const Eo_Event_Description _ELM_ATSPI_PROXY_EVENT_DISCONNECTED;

/**
 * No description
 */
#define ELM_ATSPI_PROXY_EVENT_CONNECTED (&(_ELM_ATSPI_PROXY_EVENT_CONNECTED))

/**
 * No description
 */
#define ELM_ATSPI_PROXY_EVENT_DISCONNECTED (&(_ELM_ATSPI_PROXY_EVENT_DISCONNECTED))

#endif
