#ifndef _ELM_DAYSELECTOR_EO_LEGACY_H_
#define _ELM_DAYSELECTOR_EO_LEGACY_H_

#ifndef _ELM_DAYSELECTOR_EO_CLASS_TYPE
#define _ELM_DAYSELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Dayselector;

#endif

#ifndef _ELM_DAYSELECTOR_EO_TYPES
#define _ELM_DAYSELECTOR_EO_TYPES

/**
 * @brief Identifies the day of the week. API can call the
 * selection/unselection of day with this as a parameter.
 *
 * See also @ref elm_dayselector_day_selected_set,
 * @ref elm_dayselector_day_selected_get.
 *
 * @ingroup Elm_Dayselector
 */
typedef enum
{
  ELM_DAYSELECTOR_SUN = 0, /** Indicates Sunday. */
  ELM_DAYSELECTOR_MON, /** Indicates Monday. */
  ELM_DAYSELECTOR_TUE, /** Indicates Tuesday. */
  ELM_DAYSELECTOR_WED, /** Indicates Wednesday. */
  ELM_DAYSELECTOR_THU, /** Indicates Thursday. */
  ELM_DAYSELECTOR_FRI, /** Indicates Friday. */
  ELM_DAYSELECTOR_SAT, /** Indicates Saturday. */
  ELM_DAYSELECTOR_MAX /** Sentinel value, don't use. */
} Elm_Dayselector_Day;


#endif

/**
 * @internal
 *
 * @brief Set the starting day of Dayselector.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_week_start_get.
 *
 * @param[in] day Dayselector_Day the first day that the user wants to display.
 *
 * @ingroup Elm_Dayselector
 */
EAPI void elm_dayselector_week_start_set(Elm_Dayselector *obj, Elm_Dayselector_Day day);

/**
 * @internal
 *
 * @brief Get the starting day of Dayselector.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_week_start_set.
 *
 * @return Dayselector_Day the first day that the user wants to display.
 *
 * @ingroup Elm_Dayselector
 */
EAPI Elm_Dayselector_Day elm_dayselector_week_start_get(const Elm_Dayselector *obj);

/**
 * @internal
 *
 * @brief Set the weekend length of Dayselector.
 *
 * See also @ref elm_dayselector_weekend_length_get.
 *
 * @param[in] length Weekend length, number of days as an integer.
 *
 * @ingroup Elm_Dayselector
 */
EAPI void elm_dayselector_weekend_length_set(Elm_Dayselector *obj, unsigned int length);

/**
 * @internal
 *
 * @brief Get the weekend length of Dayselector.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_weekend_length_set.
 *
 * @return Weekend length, number of days as an integer.
 *
 * @ingroup Elm_Dayselector
 */
EAPI unsigned int elm_dayselector_weekend_length_get(const Elm_Dayselector *obj);

/**
 * @internal
 *
 * @brief Set the weekend starting day of Dayselector.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_weekend_start_get.
 *
 * @param[in] day Dayselector_Day the first day from where weekend starts.
 *
 * @ingroup Elm_Dayselector
 */
EAPI void elm_dayselector_weekend_start_set(Elm_Dayselector *obj, Elm_Dayselector_Day day);

/**
 * @internal
 *
 * @brief Get the weekend starting day of Dayselector.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_weekend_start_set.
 *
 * @return Dayselector_Day the first day from where weekend starts.
 *
 * @ingroup Elm_Dayselector
 */
EAPI Elm_Dayselector_Day elm_dayselector_weekend_start_get(const Elm_Dayselector *obj);

/**
 * @internal
 *
 * @brief Set weekdays names to be displayed by the
 * Dayselector.
 *
 * By default or if weekdays is @c null, weekdays abbreviations get from system
 * are displayed: E.g. for an en_US locale: "Sun, Mon, Tue, Wed, Thu, Fri, Sat"
 *
 * The first string should be related to Sunday, the second to Monday...
 *
 * See also @ref elm_dayselector_weekdays_names_get,
 * @ref elm_dayselector_weekend_start_set.
 *
 * @param[in] weekdays Array of seven strings to be used as weekday names.
 * Warning: It must have 7 elements, or it will access invalid memory. Warning:
 * The strings must be NULL terminated ('@\0').
 *
 * @since 1.8
 *
 * @ingroup Elm_Dayselector
 */
EAPI void elm_dayselector_weekdays_names_set(Elm_Dayselector *obj, const char **weekdays);

/**
 * @brief Get weekdays names displayed by the calendar.
 *
 * By default, weekdays abbreviations get from system are displayed: E.g. for
 * an en_US locale: "Sun, Mon, Tue, Wed, Thu, Fri, Sat" The first string is
 * related to Sunday, the second to Monday...
 *
 * See also @ref elm_dayselector_weekdays_names_set.
 *
 * @return A list of seven strings to be used as weekday names.
 *
 * @since 1.8
 *
 * @ingroup Elm_Dayselector
 */
EAPI Eina_List *elm_dayselector_weekdays_names_get(const Elm_Dayselector *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @internal
 *
 * @brief Set the state of given Dayselector_Day.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_day_selected_get.
 *
 * @param[in] selected state of the day. @c true is selected.
 *
 * @ingroup Elm_Dayselector
 */
EAPI void elm_dayselector_day_selected_set(Elm_Dayselector *obj, Elm_Dayselector_Day day, Eina_Bool selected);

/**
 * @brief Get the state of given Dayselector_Day.
 *
 * See also @ref Elm_Dayselector_Day, @ref elm_dayselector_day_selected_set.
 *
 * @param[in] day Dayselector_Day that the user want to know state.
 *
 * @ingroup Elm_Dayselector
 */
EAPI Eina_Bool elm_dayselector_day_selected_get(const Elm_Dayselector *obj, Elm_Dayselector_Day day);

#endif
