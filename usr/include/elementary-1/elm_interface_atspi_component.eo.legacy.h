#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_LEGACY_H_
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_LEGACY_H_

#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Component;

#endif

#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_TYPES
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_TYPES


#endif

/** Highlights accessible widget. returns true if highlight grab has successed,
 * false otherwise.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EAPI Eina_Bool elm_atspi_component_highlight_grab(Elm_Interface_Atspi_Component *obj);

/** Clears highlight of accessible widget. returns true if clear has successed,
 * false otherwise.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EAPI Eina_Bool elm_atspi_component_highlight_clear(Elm_Interface_Atspi_Component *obj);

#endif
