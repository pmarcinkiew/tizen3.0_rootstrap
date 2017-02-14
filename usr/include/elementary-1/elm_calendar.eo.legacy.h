#ifndef _ELM_CALENDAR_EO_LEGACY_H_
#define _ELM_CALENDAR_EO_LEGACY_H_

#ifndef _ELM_CALENDAR_EO_CLASS_TYPE
#define _ELM_CALENDAR_EO_CLASS_TYPE

typedef Eo Elm_Calendar;

#endif

#ifndef _ELM_CALENDAR_EO_TYPES
#define _ELM_CALENDAR_EO_TYPES

/**
 * @brief Event periodicity, used to define if a mark should be repeated beyond
 * event's day. It's set when a mark is added.
 *
 * So, for a mark added to 13th May with periodicity set to WEEKLY, there will
 * be marks every week after this date. Marks will be displayed at 13th, 20th,
 * 27th, 3rd June ...
 *
 * Values don't work as bitmask, only one can be chosen.
 *
 * See also @ref elm_calendar_mark_add.
 *
 * @ingroup Elm_Calendar_Mark_Repeat
 */
typedef enum
{
  ELM_CALENDAR_UNIQUE = 0, /** Default value. Marks will be displayed only on
                            * event day. */
  ELM_CALENDAR_DAILY, /** Marks will be displayed every day after event day
                       * (inclusive). */
  ELM_CALENDAR_WEEKLY, /** Marks will be displayed every week after event day
                        * (inclusive) - i.e. each seven days. */
  ELM_CALENDAR_MONTHLY, /** Marks will be displayed every month day that
                         * coincides to event day. E.g.: if an event is set to
                         * 30th Jan, no marks will be displayed on Feb, but
                         * will be displayed on 30th Mar. */
  ELM_CALENDAR_ANNUALLY, /** Marks will be displayed every year that coincides
                          * to event day (and month). E.g. an event added to
                          * 30th Jan 2012 will be repeated on 30th Jan 2013. */
  ELM_CALENDAR_LAST_DAY_OF_MONTH, /** Marks will be displayed every last day of
                                   * month after event day (inclusive).
                                   *
                                   * @since 1.7 */
  ELM_CALENDAR_REVERSE_DAILY /** Marks will be displayed every day before event
                              * day.
                              *
                              * @since 1.19 */
} Elm_Calendar_Mark_Repeat_Type;

/**
 * @brief A weekday
 *
 * See also @ref elm_calendar_first_day_of_week_set.
 *
 * @ingroup Elm_Calendar
 */
typedef enum
{
  ELM_DAY_SUNDAY = 0,
  ELM_DAY_MONDAY,
  ELM_DAY_TUESDAY,
  ELM_DAY_WEDNESDAY,
  ELM_DAY_THURSDAY,
  ELM_DAY_FRIDAY,
  ELM_DAY_SATURDAY,
  ELM_DAY_LAST
} Elm_Calendar_Weekday;

/**
 * @brief The mode, who determine how user could select a day
 *
 * See also @ref elm_calendar_select_mode_set()
 *
 * @ingroup Elm_Calendar_Select
 */
typedef enum
{
  ELM_CALENDAR_SELECT_MODE_DEFAULT = 0, /** Default value. a day is always
                                         * selected. */
  ELM_CALENDAR_SELECT_MODE_ALWAYS, /** A day is always selected. */
  ELM_CALENDAR_SELECT_MODE_NONE, /** None of the days can be selected. */
  ELM_CALENDAR_SELECT_MODE_ONDEMAND /** User may have selected a day or not. */
} Elm_Calendar_Select_Mode;

/**
 * @brief A bitmask used to define which fields of a @c tm struct will be taken
 * into account, when elm_calendar_selected_time_set() is invoked.
 *
 * See also @ref elm_calendar_selectable_set,
 * @ref elm_calendar_selected_time_set.
 *
 * @since 1.8
 *
 * @ingroup Elm_Calendar
 */
typedef enum
{
  ELM_CALENDAR_SELECTABLE_NONE = 0,
  ELM_CALENDAR_SELECTABLE_YEAR = 1 /* 0 << 0 */,
  ELM_CALENDAR_SELECTABLE_MONTH = 2 /* 0 << 0 */,
  ELM_CALENDAR_SELECTABLE_DAY = 4 /* 0 << 0 */
} Elm_Calendar_Selectable;


#endif

/**
 * @brief @MOBILE_ONLY
 *
 * Set the first day of week to use on calendar widgets'.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] day An int which correspond to the first day of the week (Sunday
 * = 0, Monday = 1, ..., Saturday = 6).
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_first_day_of_week_set(Elm_Calendar *obj, Elm_Calendar_Weekday day);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the first day of week, who are used on calendar widgets'.
 *
 * See also  @ref elm_calendar_first_day_of_week_set for more details.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return An int which correspond to the first day of the week (Sunday = 0,
 * Monday = 1, ..., Saturday = 6).
 *
 * @ingroup Elm_Calendar
 */
EAPI Elm_Calendar_Weekday elm_calendar_first_day_of_week_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Define which fields of a tm struct will be taken into account, when
 * Elm.Calendar.selected_time.set is invoked.
 *
 * By Default the bitmask is set to use all fields of a tm struct (year, month
 * and day of the month).
 *
 * See also @ref elm_calendar_selected_time_set.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] selectable A bitmask of Elm_Calendar_Selectable
 *
 * @since 1.8
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_selectable_set(Elm_Calendar *obj, Elm_Calendar_Selectable selectable);

/**
 * @brief @MOBILE_ONLY
 *
 * Get how elm_calendar_selected_time_set manage a date
 *
 * See also @ref elm_calendar_selectable_set,
 * @ref elm_calendar_selected_time_set.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return A bitmask of Elm_Calendar_Selectable
 *
 * @since 1.8
 *
 * @ingroup Elm_Calendar
 */
EAPI Elm_Calendar_Selectable elm_calendar_selectable_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the interval on time updates for an user mouse button hold on calendar
 * widgets' month/year selection.
 *
 * This interval value is decreased while the user holds the mouse pointer
 * either selecting next or previous month/year.
 *
 * This helps the user to get to a given month distant from the current one
 * easier/faster, as it will start to change quicker and quicker on mouse
 * button holds.
 *
 * The calculation for the next change interval value, starting from the one
 * set with this call, is the previous interval divided by 1.05, so it
 * decreases a little bit.
 *
 * The default starting interval value for automatic changes is 0.85 seconds.
 *
 * See also @ref elm_calendar_interval_get.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] interval The (first) interval value in seconds
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_interval_set(Elm_Calendar *obj, double interval);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the interval on time updates for an user mouse button hold on calendar
 * widgets' month/year selection.
 *
 * See also @ref elm_calendar_interval_set for more details.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The (first) interval value in seconds
 *
 * @ingroup Elm_Calendar
 */
EAPI double elm_calendar_interval_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set weekdays names to be displayed by the calendar.
 *
 * By default, weekdays abbreviations get from system are displayed: E.g. for
 * an en_US locale: "Sun, Mon, Tue, Wed, Thu, Fri, Sat"
 *
 * The first string should be related to Sunday, the second to Monday...
 *
 * See also @ref elm_calendar_weekdays_names_get.
 *
 * @ref calendar_example_02.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] weekdays Array of seven strings to be used as weekday names.
 * Warning: It must have 7 elements, or it will access invalid memory. Warning:
 * The strings must be @c null terminated ('@\0').
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_weekdays_names_set(Elm_Calendar *obj, const char **weekdays);

/**
 * @brief @MOBILE_ONLY
 *
 * Get weekdays names displayed by the calendar.
 *
 * By default, weekdays abbreviations get from system are displayed: E.g. for
 * an en_US locale: "Sun, Mon, Tue, Wed, Thu, Fri, Sat" The first string is
 * related to Sunday, the second to Monday...
 *
 * See also @ref elm_calendar_weekdays_names_set.
 *
 * @ref calendar_example_05.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return Array of seven strings to be used as weekday names. Warning: It must
 * have 7 elements, or it will access invalid memory. Warning: The strings must
 * be @c null terminated ('@\0').
 *
 * @ingroup Elm_Calendar
 */
EAPI const char **elm_calendar_weekdays_names_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set select day mode to use.
 *
 * Set the day selection mode used.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] mode The select mode to use.
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_select_mode_set(Elm_Calendar *obj, Elm_Calendar_Select_Mode mode);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the select day mode used.
 *
 * Get the day selection mode used.
 *
 * See also @ref elm_calendar_select_mode_set for more details.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The select mode to use.
 *
 * @ingroup Elm_Calendar
 */
EAPI Elm_Calendar_Select_Mode elm_calendar_select_mode_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set the minimum and maximum values for the year
 *
 * Maximum must be greater than minimum, except if you don't want to set
 * maximum year. Default values are 1902 and -1.
 *
 * If the maximum year is a negative value, it will be limited depending on the
 * platform architecture (year 2037 for 32 bits);
 *
 * See also @ref elm_calendar_min_max_year_get.
 *
 * @ref calendar_example_03.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] min The minimum year, greater than 1901;
 * @param[in] max The maximum year;
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_min_max_year_set(Elm_Calendar *obj, int min, int max);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the minimum and maximum values for the year
 *
 * Default values are 1902 and -1.
 *
 * See also @ref elm_calendar_min_max_year_set for more details.
 *
 * @ref calendar_example_05.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[out] min The minimum year, greater than 1901;
 * @param[out] max The maximum year;
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_min_max_year_get(const Elm_Calendar *obj, int *min, int *max);

/**
 * @brief @MOBILE_ONLY
 *
 * Set a function to format the string that will be used to display month and
 * year;
 *
 * By default it uses strftime with "%B %Y" format string. It should allocate
 * the memory that will be used by the string, that will be freed by the widget
 * after usage. A pointer to the string and a pointer to the time struct will
 * be provided.
 *
 * @ref calendar_example_02.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] format_function Function to set the month-year string given the
 * selected date.
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_format_function_set(Elm_Calendar *obj, Elm_Calendar_Format_Cb format_function);

/**
 * @brief @MOBILE_ONLY
 *
 * Get a list of all the calendar marks.
 *
 * See also @ref elm_calendar_mark_add, @ref elm_calendar_mark_del(),
 * @ref elm_calendar_marks_clear.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Calendar
 */
EAPI const Eina_List *elm_calendar_marks_get(const Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Set selected date to be highlighted on calendar.
 *
 * Set the selected date, changing the displayed month if needed. Selected date
 * changes when the user goes to next/previous month or select a day pressing
 * over it on calendar.
 *
 * See also @ref elm_calendar_selected_time_get.
 *
 * @ref calendar_example_04
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] selected_time A tm struct to represent the selected date.
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_selected_time_set(Elm_Calendar *obj, Elm_Calendar_Time *selected_time);

/**
 * @brief @MOBILE_ONLY
 *
 * Get selected date.
 *
 * Get date selected by the user or set by function
 * @ref elm_calendar_selected_time_set(). Selected date changes when the user
 * goes to next/previous month or select a day pressing over it on calendar.
 *
 * See also @ref elm_calendar_selected_time_get.
 *
 * @ref calendar_example_05.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in,out] selected_time A tm struct to point to selected date.
 *
 * @ingroup Elm_Calendar
 */
EAPI Eina_Bool elm_calendar_selected_time_get(const Elm_Calendar *obj, Elm_Calendar_Time *selected_time);

/**
 * @brief @MOBILE_ONLY
 *
 * Add a new mark to the calendar
 *
 * Add a mark that will be drawn in the calendar respecting the insertion time
 * and periodicity. It will emit the type as signal to the widget theme.
 * Default theme supports "holiday" and "checked", but it can be extended.
 *
 * It won't immediately update the calendar, drawing the marks. For this,
 * @ref elm_calendar_marks_draw(). However, when user selects next or previous
 * month calendar forces marks drawn.
 *
 * Marks created with this method can be deleted with @ref
 * elm_calendar_mark_del().
 *
 * See also @ref elm_calendar_marks_draw, @ref elm_calendar_mark_del().
 *
 * @ref calendar_example_06
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] mark_time A time struct to represent the date of inclusion of the
 * mark. For marks that repeats it will just be displayed after the inclusion
 * date in the calendar.
 * @param[in] repeat Repeat the event following this periodicity. Can be a
 * unique mark (that don't repeat), daily, weekly, monthly or annually.
 *
 * @ingroup Elm_Calendar
 */
EAPI Elm_Calendar_Mark *elm_calendar_mark_add(Elm_Calendar *obj, const char *mark_type, Elm_Calendar_Time *mark_time, Elm_Calendar_Mark_Repeat_Type repeat);

/**
 * @brief @MOBILE_ONLY
 *
 * Remove all calendar's marks
 *
 * See also  @ref elm_calendar_mark_add, @ref elm_calendar_mark_del().
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_marks_clear(Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Draw calendar marks.
 *
 * Should be used after adding, removing or clearing marks. It will go through
 * the entire marks list updating the calendar. If lots of marks will be added,
 * add all the marks and then call this function.
 *
 * When the month is changed, i.e. user selects next or previous month, marks
 * will be drawn.
 *
 * See also  @ref elm_calendar_mark_add, @ref elm_calendar_mark_del(),
 * @ref elm_calendar_marks_clear.
 *
 * @ref calendar_example_06
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Calendar
 */
EAPI void elm_calendar_marks_draw(Elm_Calendar *obj);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the current time displayed in the widget
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in,out] displayed_time A tm struct to point to displayed date.
 *
 * @since 1.8
 *
 * @ingroup Elm_Calendar
 */
EAPI Eina_Bool elm_calendar_displayed_time_get(const Elm_Calendar *obj, Elm_Calendar_Time *displayed_time);

#endif
