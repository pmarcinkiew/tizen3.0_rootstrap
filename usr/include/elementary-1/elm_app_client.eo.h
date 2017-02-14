#ifndef _ELM_APP_CLIENT_EO_H_
#define _ELM_APP_CLIENT_EO_H_

#ifndef _ELM_APP_CLIENT_EO_CLASS_TYPE
#define _ELM_APP_CLIENT_EO_CLASS_TYPE

typedef Eo Elm_App_Client;

#endif

#ifndef _ELM_APP_CLIENT_EO_TYPES
#define _ELM_APP_CLIENT_EO_TYPES


#endif
#define ELM_APP_CLIENT_CLASS elm_app_client_class_get()

EAPI const Eo_Class *elm_app_client_class_get(void) EINA_CONST;

/**
 * @brief Return a iterator with all views of application.
 *
 * @return The iterator with all views, must be freed after use.
 *
 * @ingroup Elm_App_Client
 */
EOAPI Eina_Iterator * elm_app_client_views_get(void);

/**
 * @brief Return the application package.
 *
 * @return application package
 *
 * @ingroup Elm_App_Client
 */
EOAPI const char * elm_app_client_package_get(void);

/**
 * @brief Class constructor of elm_app_client.
 *
 * @param[in] package Package of application
 *
 * @ingroup Elm_App_Client
 */
EOAPI void  elm_app_client_constructor(const char *package);

/** Close all views of application.
 *
 * @ingroup Elm_App_Client
 */
EOAPI void  elm_app_client_view_all_close(void);

/** Terminate application.
 *
 * @ingroup Elm_App_Client
 */
EOAPI void  elm_app_client_terminate(void);

/**
 * @brief Open an application view.
 *
 * @param[in] view_open_cb callback to be called when view open
 * @param[in] data callback user data
 *
 * @return handler to cancel the view opening if it takes to long
 *
 * @ingroup Elm_App_Client
 */
EOAPI Elm_App_Client_Pending * elm_app_client_view_open(Eina_Value *args, Elm_App_Client_Open_View_Cb view_open_cb, const void *data);

/**
 * @brief Cancel a pending elm_app_client_view_open().
 *
 * @param[in] pending the view open handler
 *
 * @ingroup Elm_App_Client
 */
EOAPI void  elm_app_client_view_open_cancel(Elm_App_Client_Pending *pending);

EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_EVENT_VIEW_CREATED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_EVENT_VIEW_DELETED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_EVENT_VIEW_LIST_LOADED;
EOAPI extern const Eo_Event_Description _ELM_APP_CLIENT_EVENT_APPLICATION_TERMINATED;

/** Called when a view of this application is created.
 *
 * @ingroup Elm_App_Client
 */
#define ELM_APP_CLIENT_EVENT_VIEW_CREATED (&(_ELM_APP_CLIENT_EVENT_VIEW_CREATED))

/** Called when a view of this application is deleted.
 *
 * @ingroup Elm_App_Client
 */
#define ELM_APP_CLIENT_EVENT_VIEW_DELETED (&(_ELM_APP_CLIENT_EVENT_VIEW_DELETED))

/** Called when list of view is loaded.
 *
 * @ingroup Elm_App_Client
 */
#define ELM_APP_CLIENT_EVENT_VIEW_LIST_LOADED (&(_ELM_APP_CLIENT_EVENT_VIEW_LIST_LOADED))

/** Called when application is terminated.
 *
 * @ingroup Elm_App_Client
 */
#define ELM_APP_CLIENT_EVENT_APPLICATION_TERMINATED (&(_ELM_APP_CLIENT_EVENT_APPLICATION_TERMINATED))

#endif
