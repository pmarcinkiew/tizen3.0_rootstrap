#ifndef _ELM_APP_CLIENT_VIEW_EO_H_
#define _ELM_APP_CLIENT_VIEW_EO_H_

#ifndef _ELM_APP_CLIENT_VIEW_EO_CLASS_TYPE
#define _ELM_APP_CLIENT_VIEW_EO_CLASS_TYPE

typedef Eo Elm_App_Client_View;

#endif

#ifndef _ELM_APP_CLIENT_VIEW_EO_TYPES
#define _ELM_APP_CLIENT_VIEW_EO_TYPES


#endif
#define ELM_APP_CLIENT_VIEW_CLASS elm_app_client_view_class_get()

EAPI const Eo_Class *elm_app_client_view_class_get(void) EINA_CONST;

/**
 * @brief Get state of view
 *
 * @return state of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI Elm_App_View_State  elm_app_client_view_state_get(void);

/**
 * @brief Get new events of view
 *
 * @return number of events of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI int  elm_app_client_view_new_events_get(void);

/**
 * @brief Get window of view
 *
 * @return window of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI int  elm_app_client_view_window_get(void);

/**
 * @brief Get icon pixels of view, view could have a icon  in raw format not
 * saved in disk.
 *
 * @param[out] w icon width
 * @param[out] h icon height
 * @param[out] has_alpha if icon have alpha channel
 * @param[out] pixels uchar array, with all bytes of icon
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI void  elm_app_client_view_icon_pixels_get(unsigned int *w, unsigned int *h, Eina_Bool *has_alpha, const unsigned char **pixels);

/**
 * @brief Get DBus path of view
 *
 * @return DBus path of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI Eina_Stringshare * elm_app_client_view_path_get(void);

/**
 * @brief Get application package
 *
 * @return Package of application
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI const char * elm_app_client_view_package_get(void);

/**
 * @brief Get icon path of view
 *
 * @return icon path of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI const char * elm_app_client_view_icon_get(void);

/**
 * @brief Get progress of view, should be -1 if there nothing in progress  or
 * something between 0-100
 *
 * @return progress of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI unsigned short  elm_app_client_view_progress_get(void);

/**
 * @brief Get title of view
 *
 * @return title of view
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI const char * elm_app_client_view_title_get(void);

EOAPI void  elm_app_client_view_path_set(const char *path);

/**
 * @brief Pause view
 *
 * @param[in] data callback user data
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI void  elm_app_client_view_pause(Elm_App_Client_View_Cb cb, const void *data);

/**
 * @brief Resume view
 *
 * @param[in] data callback user data
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI void  elm_app_client_view_resume(Elm_App_Client_View_Cb cb, const void *data);

/**
 * @brief Close view
 *
 * @param[in] data callback user data
 *
 * @ingroup Elm_App_Client_View
 */
EOAPI void  elm_app_client_view_close(Elm_App_Client_View_Cb cb, const void *data);

EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_STATE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_TITLE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_ICON_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_ICON_PIXELS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_NEW_EVENTS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_PROGRESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_WINDOW_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_VIEW_EVENT_PROPERTY_CHANGED;

/** State of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_STATE_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_STATE_CHANGED))

/** Title of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_TITLE_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_TITLE_CHANGED))

/** Icon of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_ICON_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_ICON_CHANGED))

/** Icons pixels of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_ICON_PIXELS_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_ICON_PIXELS_CHANGED))

/** New events of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_NEW_EVENTS_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_NEW_EVENTS_CHANGED))

/** Progress of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_PROGRESS_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_PROGRESS_CHANGED))

/** Window of view changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_WINDOW_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_WINDOW_CHANGED))

/** One of view properties changed.
 *
 * @ingroup Elm_App_Client_View
 */
#define ELM_APP_CLIENT_VIEW_EVENT_PROPERTY_CHANGED (&(_ELM_APP_CLIENT_VIEW_EVENT_PROPERTY_CHANGED))

#endif
