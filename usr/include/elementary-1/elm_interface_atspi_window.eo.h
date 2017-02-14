#ifndef _ELM_INTERFACE_ATSPI_WINDOW_EO_H_
#define _ELM_INTERFACE_ATSPI_WINDOW_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_WINDOW_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_WINDOW_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Window;

#endif

#ifndef _ELM_INTERFACE_ATSPI_WINDOW_EO_TYPES
#define _ELM_INTERFACE_ATSPI_WINDOW_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_WINDOW_INTERFACE elm_interface_atspi_window_interface_get()

EAPI const Eo_Class *elm_interface_atspi_window_interface_get(void) EINA_CONST;

EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_CREATED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DESTROYED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_ACTIVATED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DEACTIVATED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MAXIMIZED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MINIMIZED;
EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_RESTORED;

/** Called when new window has been created.
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_CREATED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_CREATED))

/** Called when window has been destroyed.
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DESTROYED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DESTROYED))

/** Called when window has been activated. (unfocused)
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_ACTIVATED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_ACTIVATED))

/** Called when window has been deactivated (unfocused).
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DEACTIVATED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_DEACTIVATED))

/** Called when window has been maximmized
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MAXIMIZED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MAXIMIZED))

/** Called when window has been minimized
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MINIMIZED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_MINIMIZED))

/** Called when window has been restored
 *
 * @ingroup Elm_Interface_Atspi_Window
 */
#define ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_RESTORED (&(_ELM_INTERFACE_ATSPI_WINDOW_EVENT_WINDOW_RESTORED))

#endif
