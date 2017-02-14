#ifndef _TZSH_QUICKPANEL_H_
#define _TZSH_QUICKPANEL_H_

/**
 * @addtogroup TIZEN_WS_SHELL_QUICKPANEL_MODULE
 * @{
 */

#include <tzsh.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @brief Tizen event type for the quickpanel visible state
 * @since_tizen 3.0
 * @remarks This event occurs when the visible state of the quickpanel service window is changed.
 *          The value identifying this event type is generated and written to the
 *          TZSH_QUICKPANEL_EVENT_VISIBLE global variable upon tzsh_quickpanel_create() call.
 *          Then this variable can be used to identify a type when setting a callback and checking
 *          event type in a callback.
 */
extern int TZSH_QUICKPANEL_EVENT_VISIBLE;

/**
 * @brief Tizen event type for the quickpanel orientation
 * @since_tizen 3.0
 * @remarks This event occurs when the orientation of the quickpanel service window is changed.
 *          The value identifying this event type is generated and written to the
 *          TZSH_QUICKPANEL_EVENT_ORIENTATION global variable upon tzsh_quickpanel_create() call.
 *          Then this variable can be used to identify a type when setting a callback and checking
 *          event type in a callback.
 */
extern int TZSH_QUICKPANEL_EVENT_ORIENTATION;


/**
 * @brief Handle for the Tizen quickpanel client.
 * @since_tizen 3.0
 */
typedef struct _tzsh_quickpanel_s *tzsh_quickpanel_h;

/**
 * @brief Handle for the event handler of the quickpanel.
 * @since_tizen 3.0
 */
typedef struct _tzsh_event_handler_s *tzsh_quickpanel_event_handler_h;

/**
 * @brief Handle for the event information of the quickpanel.
 * @since_tizen 3.0
 * @see tzsh_quickpanel_event_visible_get
 * @see tzsh_quickpanel_event_orientation_get
 */
typedef struct _tzsh_quickpanel_event_info_s *tzsh_quickpanel_event_info_h;

/**
 * @brief Enumeration for visible state of quickpanel.
 * @since_tizen 3.0
 */
typedef enum
{
   TZSH_QUICKPANEL_STATE_VISIBLE_UNKNOWN = 0x0, /**< Unknown state. There is no quickpanel service. */
   TZSH_QUICKPANEL_STATE_VISIBLE_SHOWN = 0x1, /**< Shown state. */
   TZSH_QUICKPANEL_STATE_VISIBLE_HIDDEN = 0x2, /**< Hidden state. */
} tzsh_quickpanel_state_visible_e;

/**
 * @brief Enumeration for scrollable state of quickpanel.
 * @since_tizen 3.0
 */
typedef enum
{
   TZSH_QUICKPANEL_STATE_SCROLLABLE_UNKNOWN = 0x0, /**< Unknown state. There is no quickpanel service. */
   TZSH_QUICKPANEL_STATE_SCROLLABLE_SET = 0x1, /**< Scrollable state. */
   TZSH_QUICKPANEL_STATE_SCROLLABLE_UNSET = 0x2, /**< Not scrollable state. */
} tzsh_quickpanel_state_scrollable_e;

/**
 * @brief Enumeration for orientation state of quickpanel.
 * @since_tizen 3.0
 */
typedef enum
{
   TZSH_QUICKPANEL_STATE_ORIENTATION_UNKNOWN = 0x0, /**< Unknown state. There is no quickpanel service. */
   TZSH_QUICKPANEL_STATE_ORIENTATION_0 = 0x1, /**< 0 */
   TZSH_QUICKPANEL_STATE_ORIENTATION_90 = 0x2, /**< 90 */
   TZSH_QUICKPANEL_STATE_ORIENTATION_180 = 0x3, /**< 180 */
   TZSH_QUICKPANEL_STATE_ORIENTATION_270 = 0x4, /**< 270 */
} tzsh_quickpanel_state_orientation_e;

/**
 * @brief Called when a quickpanel event occurs.
 * @since_tizen 3.0
 * @remarks The @a event handle is only valid until the callbacks exits.
 *          After the callback exits, the @a event_info handle is not valid and should not be used.
 * @param[in] type The event type (#TZSH_QUICKPANEL_EVENT_VISIBLE, #TZSH_QUICKPANEL_EVENT_ORIENTATION)
 * @param[in] event_info The #tzsh_quickpanel_event_info_h handle
 * @param[in] user_data The user data
 * @par Example
 * @code
 *  #include <tzsh_quickpanel.h>
 *
 *  tzsh_quickpanel_h qp = NULL;
 *  tzsh_quickpanel_event_handler_h handler[2] = {NULL, NULL};
 *
 *  static void _cb_vis_changed (int type, tzsh_quickpanel_event_info_h ev_info, void *data)
 *  {
 *      tzsh_quickpanel_state_visible_e state;
 *
 *      if (type != TZSH_QUICKPANEL_EVENT_VISIBLE)
 *      {
 *          return;
 *      }
 *
 *      tzsh_quickpanel_event_visible_get(ev_info, &state);
 *      if (state == TZSH_QUICKPANEL_STATE_VISIBLE_SHOWN)
 *      {
 *          // quick panel is shown
 *      }
 *      else if (state == TZSH_QUICKPANEL_STATE_VISIBLE_HIDDEN)
 *      {
 *          // quick panel is hidden
 *      }
 *      else
 *      {
 *          // quick panel's state is unknown
 *      }
 *  }
 *
 *  static void _cb_orientation_changed(int type, tzsh_quickpanel_event_info_h ev_info, void *data)
 *  {
 *      tzsh_quickpanel_state_orientation_e state;
 *
 *      if (type != TZSH_QUICKPANEL_EVENT_ORIENTATION)
 *      {
 *          return;
 *      }
 *
 *      tzsh_quickpanel_event_orientation_get(ev_info, &state);
 *      switch (state)
 *      {
 *          case TZSH_QUICKPANEL_STATE_ORIENTATION_0:
 *              // quickpanel is 0 degree
 *              break;
 *
 *          case TZSH_QUICKPANEL_STATE_ORIENTATION_90:
 *              // quickpanel is 90 degree
 *              break;
 *
 *          case TZSH_QUICKPANEL_STATE_ORIENTATION_180:
 *              // quickpanel is 180 degree
 *              break;
 *
 *          case TZSH_QUICKPANEL_STATE_ORIENTATION_270:
 *              // quickpanel is 270 degree
 *              break;
 *
 *          default:
 *              // quickpanel's degree is unknown
 *              break;
 *      }
 *  }
 *
 *  void create_window(void)
 *  {
 *      ...
 *
 *      qp = tzsh_quickpanel_create(tzsh, tz_win);
 *      ...
 *
 *     handler[0] = tzsh_quickpanel_event_handler_add(qp, TZSH_QUICKPANEL_EVENT_VISIBLE, _cb_vis_changed, NULL);
 *     handler[1] = tzsh_quickpanel_event_handler_add(qp, TZSH_QUICKPANEL_EVENT_ORIENTATION, _cb_orientation_changed, NULL);
 *     ...
 *  }
 * @endcode
 */
 typedef void (*tzsh_quickpanel_event_cb)(int type,
                                          tzsh_quickpanel_event_info_h event_info,
                                          void *user_data);

/**
 * @brief Creates a #tzsh_quickpanel_h object which handles the quickpanel service.
 * @since_tizen 3.0
 * @remarks The returned handle should be released using tzsh_quickpanel_destroy().
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 * @param[in] tzsh The #tzsh_h instance
 * @param[in] win The native window
 * @return #tzsh_quickpanel_h object on success, @c NULL otherwise
 * @exception #TZSH_ERROR_NONE Successful
 * @exception #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @pre You have to create a #tzsh_h instance using tzsh_create() before calling this API.
 *      You can get the #tzsh_window instance using the toolkit API such as elm_win_window_id_get().
 * @see tzsh_create()
 * @see tzsh_quickpanel_destroy()
 * @par Example
 * @code
 *  #include <tzsh_quickpanel.h>
 *
 *  tzsh_h tzsh = NULL;
 *  tzsh_quickpanel_h qp = NULL;
 *  Evas_Object *win;
 *
 *  void init_tzsh(void)
 *  {
 *      tzsh = tzsh_create(TZSH_TOOLKIT_TYPE_EFL);
 *      ...
 *  }
 *
 *  void create_window(void)
 *  {
 *      tzsh_window tz_win;
 *
 *      win = elm_win_add(NULL, "sample", ELM_WIN_BASIC);
 *      ...
 *
 *      tz_win = elm_win_window_id_get(win);
 *      ...
 *
 *      qp = tzsh_quickpanel_create(tzsh, tz_win);
 *      ...
 *  }
 * @endcode
 */
tzsh_quickpanel_h tzsh_quickpanel_create(tzsh_h tzsh,
                                         tzsh_window win);

/**
 * @brief Destroys the given #tzsh_quickpanel_h object.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object to be destroyed
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @see tzsh_quickpanel_create()
 * @par Example
 * @code
 *  #include <tzsh_quickpanel.h>
 *
 *  tzsh_h tzsh = NULL;
 *  tzsh_quickpanel_h qp = NULL;
 *  Evas_Object *win;
 *
 *  void create_window(void)
 *  {
 *      tzsh_window tz_win;
 *
 *      win = elm_win_add(NULL, "sample", ELM_WIN_BASIC);
 *      ...
 *
 *      tz_win = elm_win_window_id_get(win);
 *      ...
 *
 *      qp = tzsh_quickpanel_create(tzsh, tz_win);
 *      ...
 *  }
 *
 *  void destroy_window(void)
 *  {
 *      ...
 *      tzsh_quickpanel_destroy(qp);
 *      qp = NULL;
 *      ...
 *  }
 * @endcode
 */
int tzsh_quickpanel_destroy(tzsh_quickpanel_h quickpanel);

/**
 * @brief Shows the quickpanel service window if it is currently scrollable.
 * @since_tizen 3.0
 * @remarks If the quickpanel is not scrollable, nothing will happen.
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_show(tzsh_quickpanel_h quickpanel);

/**
 * @brief Hides the quickpanel service window.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_hide(tzsh_quickpanel_h quickpanel);

/**
 * @brief Gets the visible state of the quickpanel.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[out] visible The visible state of the quickpanel service window
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_visible_get(tzsh_quickpanel_h quickpanel,
                                tzsh_quickpanel_state_visible_e *visible);

/**
 * @brief Sets the scrollable state of a quickpanel service window.
 * @details This API is useful when the application does not need to show the quickpanel service
 *          window. If the application set the @a scrollable to @c false, the quickpanel service
 *          window does not show on the display as long as the application window is shown.
 *          Default scrollable state of the window is @a true.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[in] scrollable The scrollable state
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_scrollable_set(tzsh_quickpanel_h quickpanel,
                                   bool scrollable);

/**
 * @brief Checks if the quickpanel service window is scrollable.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[out] scrollable The scrollable state of the quickpanel service window
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_scrollable_get(tzsh_quickpanel_h quickpanel,
                                   tzsh_quickpanel_state_scrollable_e *scrollable);

/**
 * @brief Gets the orientation of the quickpanel.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[out] orientation The orientation of the quickpanel service window
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #TZSH_ERROR_NO_SERVICE Service does not exist
 */
int tzsh_quickpanel_orientation_get(tzsh_quickpanel_h quickpanel,
                                    tzsh_quickpanel_state_orientation_e *orientation);

/**
 * @brief Adds an event handler.
 * @since_tizen 3.0
 * @remarks The returned #tzsh_quickpanel_event_handler_h object should be released using
 *          tzsh_quickpanel_event_handler_del(). The @a type parameter is the integer of the event
 *          type that will trigger this callback to be called. The callback @a func is called when
 *          this event is processed and will be passed the event type, a pointer to the private
 *          event structure that is specific to that event type, and a data pointer that is
 *          provided in this call as the @a user_data parameter.
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[in] type The event type (#TZSH_QUICKPANEL_EVENT_VISIBLE, #TZSH_QUICKPANEL_EVENT_ORIENTATION)
 * @param[in] func The callback function to be called
 * @param[in] user_data The data passed to the callback function
 * @return #tzsh_quickpanel_event_handler_h instance on success, @c NULL otherwise
 * @pre tzsh_quickpanel_create() should be called, to generate event type IDs
 * @see TZSH_QUICKPANEL_EVENT_VISIBLE
 * @see TZSH_QUICKPANEL_EVENT_ORIENTATION
 * @see tzsh_quickpanel_event_cb()
 * @see tzsh_quickpanel_event_handler_del()
 */
tzsh_quickpanel_event_handler_h tzsh_quickpanel_event_handler_add(tzsh_quickpanel_h quickpanel,
                                                                  int type,
                                                                  tzsh_quickpanel_event_cb func,
                                                                  void *user_data);

/**
 * @brief Removes the registered event handler.
 * @since_tizen 3.0
 * @param[in] quickpanel The #tzsh_quickpanel_h object
 * @param[in] event_handler The #tzsh_quickpanel_event_handler_h object
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @see tzsh_quickpanel_event_handler_add()
 */
int tzsh_quickpanel_event_handler_del(tzsh_quickpanel_h quickpanel,
                                      tzsh_quickpanel_event_handler_h event_handler);

/**
 * @brief Gets the visible state from given event info.
 * @since_tizen 3.0
 * @remarks This will be used in the event handler for the #TZSH_QUICKPANEL_EVENT_VISIBLE event.
 * @param[in] event_info The #tzsh_quickpanel_event_info_h object
 * @param[out] visible The visible state of quickpanel
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @see TZSH_QUICKPANEL_EVENT_VISIBLE
 */
int tzsh_quickpanel_event_visible_get(tzsh_quickpanel_event_info_h event_info,
                                      tzsh_quickpanel_state_visible_e *visible);

/**
 * @brief Gets the orientation state from given event info.
 * @since_tizen 3.0
 * @remarks This will be used in the event handler for the #TZSH_QUICKPANEL_EVENT_ORIENTATION event.
 * @param[in] event_info The #tzsh_quickpanel_event_info_h object
 * @param[out] orientation The orientation state of quickpanel
 * @return @c 0 on success, otherwise a negative error value
 * @retval #TZSH_ERROR_NONE Successful
 * @retval #TZSH_ERROR_INVALID_PARAMETER Invalid parameter
 * @see TZSH_QUICKPANEL_EVENT_ORIENTATION
 */
int tzsh_quickpanel_event_orientation_get(tzsh_quickpanel_event_info_h event_info,
                                          tzsh_quickpanel_state_orientation_e *orientation);

#ifdef  __cplusplus
}
#endif

/**
 * @}
 */

#endif
