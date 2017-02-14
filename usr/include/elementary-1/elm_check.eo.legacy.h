#ifndef _ELM_CHECK_EO_LEGACY_H_
#define _ELM_CHECK_EO_LEGACY_H_

#ifndef _ELM_CHECK_EO_CLASS_TYPE
#define _ELM_CHECK_EO_CLASS_TYPE

typedef Eo Elm_Check;

#endif

#ifndef _ELM_CHECK_EO_TYPES
#define _ELM_CHECK_EO_TYPES


#endif

/**
 * @brief Set the on/off state of the check object
 *
 * This sets the state of the check. If set with
 * @ref elm_check_state_pointer_set, the state of that variable is also
 * changed. Calling this doesn't cause the "changed" signal to be emitted.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] state The state to use (1 == on, 0 == off)
 *
 * @ingroup Elm_Check
 */
EAPI void elm_check_state_set(Elm_Check *obj, Eina_Bool state);

/**
 * @brief Get the state of the check object
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The state to use (1 == on, 0 == off)
 *
 * @ingroup Elm_Check
 */
EAPI Eina_Bool elm_check_state_get(const Elm_Check *obj);

/**
 * @brief Set a convenience pointer to a boolean to change
 *
 * This sets a pointer to a boolean, that, in addition to the check objects
 * state will also be modified directly. To stop setting the object pointed to
 * simply use null as the "statep" parameter. If "statep" is not null, then
 * when this is called, the check objects state will also be modified to
 * reflect the value of the boolean "statep" points to, just like calling
 * @ref elm_check_state_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] statep Pointer to the boolean to modify
 *
 * @ingroup Elm_Check
 */
EAPI void elm_check_state_pointer_set(Elm_Check *obj, Eina_Bool *statep);

#endif
