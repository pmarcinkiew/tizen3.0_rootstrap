#ifndef _CAPI_UI_APPLICATION_H_
#define _CAPI_UI_APPLICATION_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_APPLICATION UI Application
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_application.
 * @{
 */

/**
 * @brief The ui_application event callback function signature.
 * @since_tizen 3.0
 *
 * @param[in] user_data The user data to be passed to the given @a event_callback functions
 * @param[in] event_info Event Information data. (It can casts to app_control_h in app_control())
 *
 * @return This is reserved
 *
 * @see ui_application_event_type_e
 * @see ui_application_event_s
 * @see ui_application_run()
 */
typedef bool (*ui_application_event_cb)(void *user_data, void *event_info);

/**
 * @brief Enumeration for ui_application event type.
 * @remarks PRE events are designed for overriding the default behavior of the events.
 *          Normally, ui_application triggers ui_viewmgr actions on those event time.
 *          To ignore them, you can use PRE event callbacks.
 * @since_tizen 3.0
 */
typedef enum {
	UI_APPLICATION_EVENT_CREATE = 0,      /**< App create */
	UI_APPLICATION_EVENT_TERMINATE,       /**< App terminate */
	UI_APPLICATION_EVENT_PAUSE ,          /**< App pause */
	UI_APPLICATION_EVENT_RESUME,          /**< App resume */
	UI_APPLICATION_EVENT_CONTROL,         /**< App control */

	UI_APPLICATION_EVENT_CREATE_PRE,      /**< Prior to App create. ui_application initializes viewmgr on App create. */
	UI_APPLICATION_EVENT_TERMINATE_PRE,   /**< Prior to App terminate. ui_application releases viewmgr on App terminate. */
	UI_APPLICATION_EVENT_PAUSE_PRE,       /**< Prior to App pause. ui_application deactivates of viewmgr on App pause. */
	UI_APPLICATION_EVENT_RESUME_PRE,      /**< Prior to App resume. ui_application activates of viewmgr on App resume. */
	UI_APPLICATION_EVENT_CONTROL_PRE      /**< Prior to App control. ui_application activates of viewmgr on App control. */
} ui_application_event_type_e;

/**
 * @brief Struct for ui_application event.
 * @since_tizen 3.0
 */
typedef struct
{
	ui_application_event_type_e event_type;  /**< Type of events */
	ui_application_event_cb event_cb;        /**< Callback function */
} ui_application_event_s;

/**
 * @brief Initializes ui_application.
 * @details This function initializes ui_application and ui_viewmgr.
 * @since_tizen 3.0
 * @remarks Before exit application, call ui_application_term().
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS Initialization was already done
 * @retval #UI_VIEWMGR_ERROR_OUT_OF_MEMORY Fails to allocate memory
 *
 * @see ui_application_term()
 * @see ui_application_run()
 */
EAPI int ui_application_init();

/**
 * @brief Runs ui_application. This triggers application main loop.
 * @remarks This wraps ui_app_main() function. You don't need to call it manually.
 * @since_tizen 3.0
 *
 * @param[in] argc The argument count
 * @param[in] argv The argument vector
 * @param[in] events Event callback list
 * @param[in] count Event callback count
 * @param[in] user_data User data for event callbacks
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER Invalid parameters
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS The main loop already starts
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED If Initialization was not performed yet
 *
 * @pre Call ui_application_init() before calling this function.
 *
 * @warning Don't call ui_app_main() additionally.
 *
 * @see ui_application_event_s
 * @see ui_app_main()
 * @see ui_application_init()
 * @see ui_application_term()
 */
EAPI int ui_application_run(int argc, char **argv, ui_application_event_s *events, int count, void *user_data);

/**
 * @brief Deinitializes ui_application.
 * @remarks This wraps ui_app_exit() function. You don't need to call it manually.
 * @since_tizen 3.0
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 *
 * @pre Call ui_application_init() before calling this function.
 *
 * @warning Don't call ui_app_exit() additionally.
 *
 * @see ui_application_init()
 * @see ui_application_run()
 */
EAPI int ui_application_term(void);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _CAPI_UI_APPLICATION_H_ */
