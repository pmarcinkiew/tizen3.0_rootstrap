#ifndef _ELM_CHECK_EO_H_
#define _ELM_CHECK_EO_H_

#ifndef _ELM_CHECK_EO_CLASS_TYPE
#define _ELM_CHECK_EO_CLASS_TYPE

typedef Eo Elm_Check;

#endif

#ifndef _ELM_CHECK_EO_TYPES
#define _ELM_CHECK_EO_TYPES


#endif
#define ELM_CHECK_CLASS elm_check_class_get()

EAPI const Eo_Class *elm_check_class_get(void) EINA_CONST;

/**
 * @brief Set the on/off state of the check object
 *
 * This sets the state of the check. If set with
 * @ref elm_obj_check_state_pointer_set, the state of that variable is also
 * changed. Calling this doesn't cause the "changed" signal to be emitted.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] state The state to use (1 == on, 0 == off)
 *
 * @ingroup Elm_Check
 */
EOAPI void  elm_obj_check_state_set(Eina_Bool state);

/**
 * @brief Get the state of the check object
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The state to use (1 == on, 0 == off)
 *
 * @ingroup Elm_Check
 */
EOAPI Eina_Bool  elm_obj_check_state_get(void);

/**
 * @brief Set a convenience pointer to a boolean to change
 *
 * This sets a pointer to a boolean, that, in addition to the check objects
 * state will also be modified directly. To stop setting the object pointed to
 * simply use null as the "statep" parameter. If "statep" is not null, then
 * when this is called, the check objects state will also be modified to
 * reflect the value of the boolean "statep" points to, just like calling
 * @ref elm_obj_check_state_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] statep Pointer to the boolean to modify
 *
 * @ingroup Elm_Check
 */
EOAPI void  elm_obj_check_state_pointer_set(Eina_Bool *statep);

EOAPI extern const Eo_Event_Description _ELM_CHECK_EVENT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CHECK_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CHECK_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_CHECK_EVENT_CHANGED (&(_ELM_CHECK_EVENT_CHANGED))

/**
 * No description
 */
#define ELM_CHECK_EVENT_LANGUAGE_CHANGED (&(_ELM_CHECK_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_CHECK_EVENT_ACCESS_CHANGED (&(_ELM_CHECK_EVENT_ACCESS_CHANGED))

#endif
