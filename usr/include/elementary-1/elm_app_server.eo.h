#ifndef _ELM_APP_SERVER_EO_H_
#define _ELM_APP_SERVER_EO_H_

#ifndef _ELM_APP_SERVER_EO_CLASS_TYPE
#define _ELM_APP_SERVER_EO_CLASS_TYPE

typedef Eo Elm_App_Server;

#endif

#ifndef _ELM_APP_SERVER_EO_TYPES
#define _ELM_APP_SERVER_EO_TYPES


#endif
#define ELM_APP_SERVER_CLASS elm_app_server_class_get()

EAPI const Eo_Class *elm_app_server_class_get(void) EINA_CONST;

EOAPI void  elm_app_server_icon_set(Eina_Stringshare *icon);

EOAPI Eina_Stringshare * elm_app_server_icon_get(void);

/**
 * @brief Return a iterator with all views of application
 *
 * @return Iterator with all views of application, you must free iterator after
 * use
 *
 * @ingroup Elm_App_Server
 */
EOAPI Eina_Iterator * elm_app_server_views_get(void);

EOAPI const char * elm_app_server_path_get(void);

EOAPI Eina_Stringshare * elm_app_server_package_get(void);

/**
 * @brief Set icon to application, using the raw pixels of image.
 *
 * @param[in] w
 * @param[in] h
 * @param[in] has_alpha
 * @param[in] pixels
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_pixels_set(unsigned int w, unsigned int h, Eina_Bool has_alpha, const unsigned char *pixels);

/**
 * @brief Get application raw icon.
 *
 * @param[out] w
 * @param[out] h
 * @param[out] has_alpha
 * @param[out] pixels
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_pixels_get(unsigned int *w, unsigned int *h, Eina_Bool *has_alpha, const unsigned char **pixels);

/**
 * @brief Class constructor of elm_app_server
 *
 * @param[in] create_view_cb callback to be called when user wants to open some
 * application view
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_constructor(const char *packageid, Elm_App_Server_Create_View_Cb create_view_cb);

/** Close all views of application
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_close_all(void);

/**
 * @brief If view id is available and unique, return the full DBus object path
 * of view
 *
 * @param[in] id view identifier
 *
 * @return true if id is valid or false if not
 *
 * @ingroup Elm_App_Server
 */
EOAPI Eina_Bool  elm_app_server_view_check(const char *id);

/**
 * @brief Add a view to elm_app_server. This should only be used if the
 * application open a view that was not requested by create_view_cb.
 *
 * @param[in] view elm_app_server_view
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_view_add(Elm_App_Server_View *view);

/**
 * @brief Set a title to application.
 *
 * @param[in] title title of application
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_title_set(const char *title);

/**
 * @brief Get title of application
 *
 * @return title of application
 *
 * @ingroup Elm_App_Server
 */
EOAPI Eina_Stringshare * elm_app_server_title_get(void);

/** Save the state of all views
 *
 * @ingroup Elm_App_Server
 */
EOAPI void  elm_app_server_save(void);

EOAPI extern const Eo_Event_Description _ELM_APP_SERVER_EVENT_TERMINATE;

/** Called when application must be terminated.
 *
 * @ingroup Elm_App_Server
 */
#define ELM_APP_SERVER_EVENT_TERMINATE (&(_ELM_APP_SERVER_EVENT_TERMINATE))

#endif
