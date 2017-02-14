#ifndef _ELM_NOTIFY_EO_H_
#define _ELM_NOTIFY_EO_H_

#ifndef _ELM_NOTIFY_EO_CLASS_TYPE
#define _ELM_NOTIFY_EO_CLASS_TYPE

typedef Eo Elm_Notify;

#endif

#ifndef _ELM_NOTIFY_EO_TYPES
#define _ELM_NOTIFY_EO_TYPES


#endif
#define ELM_NOTIFY_CLASS elm_notify_class_get()

EAPI const Eo_Class *elm_notify_class_get(void) EINA_CONST;

/**
 * @brief Set the alignment of the notify object
 *
 * Sets the alignment in which the notify will appear in its parent.
 *
 * @note To fill the notify box in the parent area, please pass the
 * ELM_NOTIFY_ALIGN_FILL to horizontal and vertical.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal The horizontal alignment of the notification
 * @param[in] vertical The vertical alignment of the notification
 *
 * @since 1.8
 *
 * @ingroup Elm_Notify
 */
EOAPI void  elm_obj_notify_align_set(double horizontal, double vertical);

/**
 * @brief Get the alignment of the notify object
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] horizontal The horizontal alignment of the notification
 * @param[out] vertical The vertical alignment of the notification
 *
 * @since 1.8
 *
 * @ingroup Elm_Notify
 */
EOAPI void  elm_obj_notify_align_get(double *horizontal, double *vertical);

/**
 * @brief Sets whether events should be passed to by a click outside its area.
 *
 * When true if the user clicks outside the window the events will be caught by
 * the others widgets, else the events are blocked.
 *
 * @note The default value is true.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] allow true if events are allowed, otherwise false
 *
 * @ingroup Elm_Notify
 */
EOAPI void  elm_obj_notify_allow_events_set(Eina_Bool allow);

/**
 * @brief Return true if events are allowed below the notify object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return true if events are allowed, otherwise false
 *
 * @ingroup Elm_Notify
 */
EOAPI Eina_Bool  elm_obj_notify_allow_events_get(void);

/**
 * @brief Set the time interval after which the notify window is going to be
 * hidden.
 *
 * This function sets a timeout and starts the timer controlling when the
 * notify is hidden. Since calling evas_object_show() on a notify restarts the
 * timer controlling when the notify is hidden, setting this before the notify
 * is shown will in effect mean starting the timer when the notify is shown.
 *
 * @note Set a value <= 0.0 to disable a running timer.
 *
 * @note If the value > 0.0 and the notify is previously visible, the timer
 * will be started with this value, canceling any running timer.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] timeout The timeout in seconds
 *
 * @ingroup Elm_Notify
 */
EOAPI void  elm_obj_notify_timeout_set(double timeout);

/**
 * @brief Return the timeout value (in seconds)
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The timeout in seconds
 *
 * @ingroup Elm_Notify
 */
EOAPI double  elm_obj_notify_timeout_get(void);

/**
 * @brief Dismiss a notify object.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Notify
 */
EOAPI void  elm_obj_notify_dismiss(void);

EOAPI extern const Eo_Event_Description _ELM_NOTIFY_EVENT_BLOCK_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_NOTIFY_EVENT_TIMEOUT;
EOAPI extern const Eo_Event_Description _ELM_NOTIFY_EVENT_DISMISSED;
EOAPI extern const Eo_Event_Description _ELM_NOTIFY_EVENT_SHOW_FINISHED;

/**
 * No description
 */
#define ELM_NOTIFY_EVENT_BLOCK_CLICKED (&(_ELM_NOTIFY_EVENT_BLOCK_CLICKED))

/**
 * No description
 */
#define ELM_NOTIFY_EVENT_TIMEOUT (&(_ELM_NOTIFY_EVENT_TIMEOUT))

/**
 * No description
 */
#define ELM_NOTIFY_EVENT_DISMISSED (&(_ELM_NOTIFY_EVENT_DISMISSED))

/**
 * No description
 */
#define ELM_NOTIFY_EVENT_SHOW_FINISHED (&(_ELM_NOTIFY_EVENT_SHOW_FINISHED))

#endif
