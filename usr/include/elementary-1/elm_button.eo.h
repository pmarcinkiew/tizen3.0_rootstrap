#ifndef _ELM_BUTTON_EO_H_
#define _ELM_BUTTON_EO_H_

#ifndef _ELM_BUTTON_EO_CLASS_TYPE
#define _ELM_BUTTON_EO_CLASS_TYPE

typedef Eo Elm_Button;

#endif

#ifndef _ELM_BUTTON_EO_TYPES
#define _ELM_BUTTON_EO_TYPES


#endif
#define ELM_BUTTON_CLASS elm_button_class_get()

EAPI const Eo_Class *elm_button_class_get(void) EINA_CONST;

/**
 * @brief Set the initial timeout before the autorepeat event is generated
 *
 * Sets the timeout, in seconds, since the button is pressed until the first
 * @c repeated signal is emitted. If @c t is 0.0 or less, there won't be any
 * delay and the event will be fired the moment the button is pressed.
 *
 * See also @ref elm_obj_button_autorepeat_set,
 * @ref elm_obj_button_autorepeat_gap_timeout_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] t Timeout in seconds
 *
 * @ingroup Elm_Button
 */
EOAPI void  elm_obj_button_autorepeat_initial_timeout_set(double t);

/**
 * @brief Get the initial timeout before the autorepeat event is generated
 *
 * See also @ref elm_obj_button_autorepeat_initial_timeout_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Timeout in seconds
 *
 * @ingroup Elm_Button
 */
EOAPI double  elm_obj_button_autorepeat_initial_timeout_get(void);

/**
 * @brief Set the interval between each generated autorepeat event
 *
 * After the first @c repeated event is fired, all subsequent ones will follow
 * after a delay of @c t seconds for each.
 *
 * See also @ref elm_obj_button_autorepeat_initial_timeout_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] t Interval in seconds
 *
 * @ingroup Elm_Button
 */
EOAPI void  elm_obj_button_autorepeat_gap_timeout_set(double t);

/**
 * @brief Get the interval between each generated autorepeat event
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Interval in seconds
 *
 * @ingroup Elm_Button
 */
EOAPI double  elm_obj_button_autorepeat_gap_timeout_get(void);

/**
 * @brief Turn on/off the autorepeat event generated when the button is kept
 * pressed
 *
 * When off, no autorepeat is performed and buttons emit a normal @c clicked
 * signal when they are clicked.
 *
 * When on, keeping a button pressed will continuously emit a @c repeated
 * signal until the button is released. The time it takes until it starts
 * emitting the signal is given by
 * @ref elm_obj_button_autorepeat_initial_timeout_set, and the time between
 * each new emission by @ref elm_obj_button_autorepeat_gap_timeout_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] on A bool to turn on/off the event
 *
 * @ingroup Elm_Button
 */
EOAPI void  elm_obj_button_autorepeat_set(Eina_Bool on);

/**
 * @brief Get whether the autorepeat feature is enabled ($true if autorepeat is
 * on, @c false otherwise)
 *
 * See also @ref elm_obj_button_autorepeat_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A bool to turn on/off the event
 *
 * @ingroup Elm_Button
 */
EOAPI Eina_Bool  elm_obj_button_autorepeat_get(void);

/** Get whether the button supports autorepeat.
 *
 * @ingroup Elm_Button
 */
EOAPI Eina_Bool  elm_obj_button_admits_autorepeat_get(void);


#endif
