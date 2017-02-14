#ifndef _ELM_CLOCK_EO_H_
#define _ELM_CLOCK_EO_H_

#ifndef _ELM_CLOCK_EO_CLASS_TYPE
#define _ELM_CLOCK_EO_CLASS_TYPE

typedef Eo Elm_Clock;

#endif

#ifndef _ELM_CLOCK_EO_TYPES
#define _ELM_CLOCK_EO_TYPES

/**
 * @brief Identifiers for which clock digits should be editable, when a clock
 * widget is in edition mode. Values may be OR-ed together to make a mask,
 * naturally.
 *
 * See also @ref elm_obj_clock_edit_set, @ref elm_obj_clock_edit_mode_set.
 *
 * @ingroup Elm_Clock
 */
typedef enum
{
  ELM_CLOCK_EDIT_DEFAULT = 0, /** Default value. Means that all digits are
                               * editable, when in edition mode. */
  ELM_CLOCK_EDIT_HOUR_DECIMAL = 1 /* 0 << 0 */, /** Decimal digit of hours
                                                 * value should be editable. */
  ELM_CLOCK_EDIT_HOUR_UNIT = 2 /* 0 << 0 */, /** Unit digit of hours value
                                              * should be editable. */
  ELM_CLOCK_EDIT_MIN_DECIMAL = 4 /* 0 << 0 */, /** Decimal digit of minutes
                                                * value should be editable. */
  ELM_CLOCK_EDIT_MIN_UNIT = 8 /* 0 << 0 */, /** Unit digit of minutes value
                                             * should be editable. */
  ELM_CLOCK_EDIT_SEC_DECIMAL = 16 /* 0 << 0 */, /** Decimal digit of seconds
                                                 * value should be editable. */
  ELM_CLOCK_EDIT_SEC_UNIT = 32 /* 0 << 0 */, /** Unit digit of seconds value
                                              * should be editable. */
  ELM_CLOCK_EDIT_ALL = 63 /* (0 << 0) - 0 */ /** All digits should be editable.
                                              */
} Elm_Clock_Edit_Mode;


#endif
#define ELM_CLOCK_CLASS elm_clock_class_get()

EAPI const Eo_Class *elm_clock_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Set if the given clock widget must show hours in
 * military or am/pm mode
 *
 * This function sets if the clock must show hours in military or am/pm mode.
 * In some countries like Brazil the military mode (00-24h-format) is used, in
 * opposition to the USA, where the am/pm mode is more commonly used.
 *
 * See also @ref elm_obj_clock_show_am_pm_get.
 *
 * @param[in] am_pm @c true to put it in am/pm mode, @c false to military mode
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_show_am_pm_set(Eina_Bool am_pm);

/**
 * @internal
 *
 * @brief Get if the given clock widget shows hours in
 * military or am/pm mode
 *
 * This function gets if the clock shows hours in military or am/pm mode.
 *
 * See also @ref elm_obj_clock_show_am_pm_set for more details.
 *
 * @return @c true to put it in am/pm mode, @c false to military mode
 *
 * @ingroup Elm_Clock
 */
EOAPI Eina_Bool  elm_obj_clock_show_am_pm_get(void);

/**
 * @internal
 *
 * @brief Set the first interval on time updates for a user
 * mouse button hold on clock widgets' time edition.
 *
 * This interval value is decreased while the user holds the mouse pointer
 * either incrementing or decrementing a given the clock digit's value.
 *
 * This helps the user to get to a given time distant from the current one
 * easier/faster, as it will start to flip quicker and quicker on mouse button
 * holds.
 *
 * The calculation for the next flip interval value, starting from the one set
 * with this call, is the previous interval divided by 1.05, so it decreases a
 * little bit.
 *
 * The default starting interval value for automatic flips is 0.85 seconds.
 *
 * See also @ref elm_obj_clock_first_interval_get.
 *
 * @param[in] interval The first interval value in seconds
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_first_interval_set(double interval);

/**
 * @internal
 *
 * @brief Get the first interval on time updates for a user
 * mouse button hold on clock widgets' time edition.
 *
 * See also @ref elm_obj_clock_first_interval_set for more details.
 *
 * @return The first interval value in seconds
 *
 * @ingroup Elm_Clock
 */
EOAPI double  elm_obj_clock_first_interval_get(void);

/**
 * @internal
 *
 * @brief Set if the given clock widget must show time with
 * seconds or not
 *
 * This function sets if the given clock must show or not elapsed seconds. By
 * default, they are not shown.
 *
 * See also @ref elm_obj_clock_show_seconds_get.
 *
 * @param[in] seconds @c true to show seconds, @c false otherwise.
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_show_seconds_set(Eina_Bool seconds);

/**
 * @internal
 *
 * @brief Get whether the given clock widget is showing time
 * with seconds or not
 *
 * This function gets whether @c obj is showing or not the elapsed seconds.
 *
 * See also @ref elm_obj_clock_show_seconds_set.
 *
 * @return @c true to show seconds, @c false otherwise.
 *
 * @ingroup Elm_Clock
 */
EOAPI Eina_Bool  elm_obj_clock_show_seconds_get(void);

/**
 * @internal
 *
 * @brief Set whether a given clock widget is under edition
 * mode or under (default) displaying-only mode.
 *
 * This function makes a clock's time to be editable or not by user
 * interaction. When in edition mode, clocks stop ticking, until one brings
 * them back to canonical mode. The @ref elm_obj_clock_edit_mode_set function
 * will influence which digits of the clock will be editable.
 *
 * @note am/pm sheets, if being shown, will always be editable under edition
 * mode.
 *
 * See also @ref elm_obj_clock_edit_get.
 *
 * @param[in] edit @c true to put it in edition, @c false to put it back to
 * "displaying only" mode
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_edit_set(Eina_Bool edit);

/**
 * @internal
 *
 * @brief Get whether a given clock widget is under editing
 * mode or under (default) displaying-only mode.
 *
 * This function retrieves whether the clock's time can be edited or not by
 * user interaction.
 *
 * See also @ref elm_obj_clock_edit_set for more details
 *
 * @return @c true to put it in edition, @c false to put it back to "displaying
 * only" mode
 *
 * @ingroup Elm_Clock
 */
EOAPI Eina_Bool  elm_obj_clock_edit_get(void);

/**
 * @internal
 *
 * @brief Set whether the given clock widget should be paused
 * or not.
 *
 * This function pauses or starts the clock widget.
 *
 * See also @ref elm_obj_clock_pause_get.
 *
 * @param[in] paused @c true to pause clock, @c false otherwise
 *
 * @since 1.9
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_pause_set(Eina_Bool paused);

/**
 * @internal
 *
 * @brief Get whether the given clock widget is paused.
 *
 * This function gets whether the clock is paused or not.
 *
 * See also @ref elm_obj_clock_pause_set.
 *
 * @return @c true to pause clock, @c false otherwise
 *
 * @since 1.9
 *
 * @ingroup Elm_Clock
 */
EOAPI Eina_Bool  elm_obj_clock_pause_get(void);

/**
 * @internal
 *
 * @brief Set a clock widget's time, programmatically
 *
 * This function updates the time that is showed by the clock widget.
 *
 * Values must be set within 0-23 for hours and 0-59 for minutes and seconds,
 * even if the clock is not in "military" mode.
 *
 * @warning The behavior for values set out of those ranges is undefined.
 *
 * @param[in] hrs The hours to set
 * @param[in] min The minutes to set
 * @param[in] sec The seconds to set
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_time_set(int hrs, int min, int sec);

/**
 * @internal
 *
 * @brief Get a clock widget's time values
 *
 * This function gets the time set for @c obj, returning it on the variables
 * passed as the arguments to function
 *
 * @note Use @c null pointers on the time values you're not interested in:
 * they'll be ignored by the function.
 *
 * @param[out] hrs The hours to set
 * @param[out] min The minutes to set
 * @param[out] sec The seconds to set
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_time_get(int *hrs, int *min, int *sec);

/**
 * @internal
 *
 * @brief Set what digits of the given clock widget should be
 * editable when in edition mode.
 *
 * See also @ref elm_obj_clock_edit_mode_get.
 *
 * @param[in] digedit Bit mask indicating the digits to be editable (values in
 * #Elm_Clock_Edit_Mode).
 *
 * @ingroup Elm_Clock
 */
EOAPI void  elm_obj_clock_edit_mode_set(Elm_Clock_Edit_Mode digedit);

/**
 * @internal
 *
 * @brief Get what digits of the given clock widget should be
 * editable when in edition mode.
 *
 * See also @ref elm_obj_clock_edit_mode_set for more details.
 *
 * @return Bit mask indicating the digits to be editable (values in
 * #Elm_Clock_Edit_Mode).
 *
 * @ingroup Elm_Clock
 */
EOAPI Elm_Clock_Edit_Mode  elm_obj_clock_edit_mode_get(void);

EOAPI extern const Eo_Event_Description _ELM_CLOCK_EVENT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CLOCK_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CLOCK_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_CLOCK_EVENT_CHANGED (&(_ELM_CLOCK_EVENT_CHANGED))

/**
 * No description
 */
#define ELM_CLOCK_EVENT_LANGUAGE_CHANGED (&(_ELM_CLOCK_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_CLOCK_EVENT_ACCESS_CHANGED (&(_ELM_CLOCK_EVENT_ACCESS_CHANGED))

#endif
