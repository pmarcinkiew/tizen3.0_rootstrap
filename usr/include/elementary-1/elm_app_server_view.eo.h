#ifndef _ELM_APP_SERVER_VIEW_EO_H_
#define _ELM_APP_SERVER_VIEW_EO_H_

#ifndef _ELM_APP_SERVER_VIEW_EO_CLASS_TYPE
#define _ELM_APP_SERVER_VIEW_EO_CLASS_TYPE

typedef Eo Elm_App_Server_View;

#endif

#ifndef _ELM_APP_SERVER_VIEW_EO_TYPES
#define _ELM_APP_SERVER_VIEW_EO_TYPES


#endif
#define ELM_APP_SERVER_VIEW_CLASS elm_app_server_view_class_get()

EAPI const Eo_Class *elm_app_server_view_class_get(void) EINA_CONST;

EOAPI void  elm_app_server_view_progress_set(short progress);

EOAPI short  elm_app_server_view_progress_get(void);

EOAPI void  elm_app_server_view_new_events_set(int events);

EOAPI int  elm_app_server_view_new_events_get(void);

EOAPI void  elm_app_server_view_icon_set(const char *icon);

EOAPI const char * elm_app_server_view_icon_get(void);

EOAPI void  elm_app_server_view_title_set(const char *title);

EOAPI const char * elm_app_server_view_title_get(void);

EOAPI void  elm_app_server_view_window_set(Evas_Object *win);

EOAPI void  elm_app_server_view_id_set(const char *ret);

EOAPI const char * elm_app_server_view_id_get(void);

EOAPI Elm_App_View_State  elm_app_server_view_state_get(void);

EOAPI const char * elm_app_server_view_path_get(void);

/**
 * @brief Set icon to application, using the raw pixels of image.
 *
 * @param[in] w
 * @param[in] h
 * @param[in] has_alpha
 * @param[in] pixels
 *
 * @ingroup Elm_App_Server_View
 */
EOAPI void  elm_app_server_view_pixels_set(unsigned int w, unsigned int h, Eina_Bool has_alpha, const unsigned char *pixels);

/**
 * @brief Get application raw icon.
 *
 * @param[out] w
 * @param[out] h
 * @param[out] has_alpha
 * @param[out] pixels
 *
 * @ingroup Elm_App_Server_View
 */
EOAPI void  elm_app_server_view_pixels_get(unsigned int *w, unsigned int *h, Eina_Bool *has_alpha, const unsigned char **pixels);

EOAPI void  elm_app_server_view_pause(void);

EOAPI void  elm_app_server_view_resume(void);

EOAPI void  elm_app_server_view_shallow(void);

EOAPI void  elm_app_server_view_close(void);

EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_VIEW_EVENT_RESUMED;
EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_VIEW_EVENT_PAUSED;
EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_VIEW_EVENT_CLOSED;
EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_VIEW_EVENT_SHALLOW;
EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_VIEW_EVENT_SAVE;

/** Called when view must be resumed
 *
 * @ingroup Elm_App_Server_View
 */
#define ELM_APP_SERVER_VIEW_EVENT_RESUMED (&(_ELM_APP_SERVER_VIEW_EVENT_RESUMED))

/** Called when view must be paused
 *
 * @ingroup Elm_App_Server_View
 */
#define ELM_APP_SERVER_VIEW_EVENT_PAUSED (&(_ELM_APP_SERVER_VIEW_EVENT_PAUSED))

/** Called when view must be closed
 *
 * @ingroup Elm_App_Server_View
 */
#define ELM_APP_SERVER_VIEW_EVENT_CLOSED (&(_ELM_APP_SERVER_VIEW_EVENT_CLOSED))

/** Called when view state is set to shallow
 *
 * @ingroup Elm_App_Server_View
 */
#define ELM_APP_SERVER_VIEW_EVENT_SHALLOW (&(_ELM_APP_SERVER_VIEW_EVENT_SHALLOW))

/** Called when view state should be saved
 *
 * @ingroup Elm_App_Server_View
 */
#define ELM_APP_SERVER_VIEW_EVENT_SAVE (&(_ELM_APP_SERVER_VIEW_EVENT_SAVE))

#endif
