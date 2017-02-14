#ifndef _ELM_RADIO_EO_H_
#define _ELM_RADIO_EO_H_

#ifndef _ELM_RADIO_EO_CLASS_TYPE
#define _ELM_RADIO_EO_CLASS_TYPE

typedef Eo Elm_Radio;

#endif

#ifndef _ELM_RADIO_EO_TYPES
#define _ELM_RADIO_EO_TYPES


#endif
#define ELM_RADIO_CLASS elm_radio_class_get()

EAPI const Eo_Class *elm_radio_class_get(void) EINA_CONST;

/**
 * @brief Set the integer value that this radio object represents
 *
 * This sets the value of the radio.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] value The value to use if this radio object is selected
 *
 * @ingroup Elm_Radio
 */
EOAPI void  elm_obj_radio_state_value_set(int value);

/**
 * @brief Get the integer value that this radio object represents
 *
 * This gets the value of the radio.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The value to use if this radio object is selected
 *
 * @ingroup Elm_Radio
 */
EOAPI int  elm_obj_radio_state_value_get(void);

/**
 * @brief Set the value of the radio group.
 *
 * This sets the value of the radio group and will also set the value if
 * pointed to, to the value supplied, but will not call any callbacks.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] value The value to use for the group
 *
 * @ingroup Elm_Radio
 */
EOAPI void  elm_obj_radio_value_set(int value);

/**
 * @brief Get the value of the radio group
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The value to use for the group
 *
 * @ingroup Elm_Radio
 */
EOAPI int  elm_obj_radio_value_get(void);

/**
 * @brief Set a convenience pointer to a integer to change when radio group
 * value changes.
 *
 * This sets a pointer to a integer, that, in addition to the radio objects
 * state will also be modified directly. To stop setting the object pointed to
 * simply use NULL as the valuep argument. If valuep is not NULL, then when
 * this is called, the radio objects state will also be modified to reflect the
 * value of the integer valuep points to, just like calling
 * elm_radio_value_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] valuep Pointer to the integer to modify
 *
 * @ingroup Elm_Radio
 */
EOAPI void  elm_obj_radio_value_pointer_set(int *valuep);

/**
 * @brief Get the selected radio object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The selected radio object
 *
 * @ingroup Elm_Radio
 */
EOAPI Evas_Object * elm_obj_radio_selected_object_get(void);

/**
 * @brief Add this radio to a group of other radio objects
 *
 * Radio objects work in groups. Each member should have a different integer
 * value assigned. In order to have them work as a group, they need to know
 * about each other. This adds the given radio object to the group of which the
 * group object indicated is a member.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] group Any radio object whose group the obj is to join.
 *
 * @ingroup Elm_Radio
 */
EOAPI void  elm_obj_radio_group_add(Elm_Radio *group);

EOAPI extern const Eo_Event_Description _ELM_RADIO_EVENT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_RADIO_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_RADIO_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_RADIO_EVENT_CHANGED (&(_ELM_RADIO_EVENT_CHANGED))

/**
 * No description
 */
#define ELM_RADIO_EVENT_LANGUAGE_CHANGED (&(_ELM_RADIO_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_RADIO_EVENT_ACCESS_CHANGED (&(_ELM_RADIO_EVENT_ACCESS_CHANGED))

#endif
