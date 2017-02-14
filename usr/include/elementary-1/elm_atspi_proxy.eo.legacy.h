#ifndef _ELM_ATSPI_PROXY_EO_LEGACY_H_
#define _ELM_ATSPI_PROXY_EO_LEGACY_H_

#ifndef _ELM_ATSPI_PROXY_EO_CLASS_TYPE
#define _ELM_ATSPI_PROXY_EO_CLASS_TYPE

typedef Eo Elm_Atspi_Proxy;

#endif

#ifndef _ELM_ATSPI_PROXY_EO_TYPES
#define _ELM_ATSPI_PROXY_EO_TYPES


#endif
EAPI void elm_atspi_proxy_address_set(Elm_Atspi_Proxy *obj, const char *bus, const char *path);
EAPI void elm_atspi_proxy_address_get(const Elm_Atspi_Proxy *obj, const char **bus, const char **path);
EAPI Elm_Atspi_Proxy_Type elm_atspi_proxy_type_get(const Elm_Atspi_Proxy *obj);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] type
 *
 * @ingroup Elm_Atspi_Proxy
 */
EAPI void elm_atspi_proxy_constructor(Elm_Atspi_Proxy *obj, Elm_Atspi_Proxy_Type type);
EAPI void elm_atspi_proxy_address_get_retry_timer_add(Elm_Atspi_Proxy *obj);

#endif
