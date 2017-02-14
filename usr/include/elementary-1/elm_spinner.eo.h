#ifndef _ELM_SPINNER_EO_H_
#define _ELM_SPINNER_EO_H_

#ifndef _ELM_SPINNER_EO_CLASS_TYPE
#define _ELM_SPINNER_EO_CLASS_TYPE

typedef Eo Elm_Spinner;

#endif

#ifndef _ELM_SPINNER_EO_TYPES
#define _ELM_SPINNER_EO_TYPES


#endif
#define ELM_SPINNER_CLASS elm_spinner_class_get()

EAPI const Eo_Class *elm_spinner_class_get(void) EINA_CONST;

/**
 * @brief Control the minimum and maximum values for the spinner.
 *
 * Define the allowed range of values to be selected by the user.
 *
 * If actual value is less than @c min, it will be updated to @c min. If it is
 * bigger then @c max, will be updated to @c max. Actual value can be get with
 * @ref elm_obj_spinner_value_get.
 *
 * By default, min is equal to 0, and max is equal to 100.
 *
 * @warning Maximum must be greater than minimum.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] min The minimum value.
 * @param[in] max The maximum value.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_min_max_set(double min, double max);

/**
 * @brief Control the minimum and maximum values for the spinner.
 *
 * Define the allowed range of values to be selected by the user.
 *
 * If actual value is less than @c min, it will be updated to @c min. If it is
 * bigger then @c max, will be updated to @c max. Actual value can be get with
 * @ref elm_obj_spinner_value_get.
 *
 * By default, min is equal to 0, and max is equal to 100.
 *
 * @warning Maximum must be greater than minimum.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] min The minimum value.
 * @param[out] max The maximum value.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_min_max_get(double *min, double *max);

/**
 * @brief Control the step used to increment or decrement the spinner value.
 *
 * This value will be incremented or decremented to the displayed value. It
 * will be incremented while the user keep right or top arrow pressed, and will
 * be decremented while the user keep left or bottom arrow pressed.
 *
 * The interval to increment / decrement can be set with
 * @ref elm_obj_spinner_interval_set.
 *
 * By default step value is equal to 1.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] step The step value.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_step_set(double step);

/**
 * @brief Control the step used to increment or decrement the spinner value.
 *
 * This value will be incremented or decremented to the displayed value. It
 * will be incremented while the user keep right or top arrow pressed, and will
 * be decremented while the user keep left or bottom arrow pressed.
 *
 * The interval to increment / decrement can be set with
 * @ref elm_obj_spinner_interval_set.
 *
 * By default step value is equal to 1.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The step value.
 *
 * @ingroup Elm_Spinner
 */
EOAPI double  elm_obj_spinner_step_get(void);

/**
 * @brief Control whether the spinner should wrap when it reaches its minimum
 * or maximum value.
 *
 * Disabled by default. If disabled, when the user tries to increment the
 * value, but displayed value plus step value is bigger than maximum value, the
 * new value will be the maximum value. The same happens when the user tries to
 * decrement it, but the value less step is less than minimum value. In this
 * case, the new displayed value will be the minimum value.
 *
 * When wrap is enabled, when the user tries to increment the value, but
 * displayed value plus step value is bigger than maximum value, the new value
 * will be the minimum value. When the the user tries to decrement it, but the
 * value less step is less than minimum value, the new displayed value will be
 * the maximum value.
 *
 * E.g.: @c min = 10 @c max = 50 @c step = 20 @c displayed = 20
 *
 * When the user decrement value (using left or bottom arrow), it will displays
 * $50.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] wrap @c true to enable wrap or @c false to disable it.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_wrap_set(Eina_Bool wrap);

/**
 * @brief Control whether the spinner should wrap when it reaches its minimum
 * or maximum value.
 *
 * Disabled by default. If disabled, when the user tries to increment the
 * value, but displayed value plus step value is bigger than maximum value, the
 * new value will be the maximum value. The same happens when the user tries to
 * decrement it, but the value less step is less than minimum value. In this
 * case, the new displayed value will be the minimum value.
 *
 * When wrap is enabled, when the user tries to increment the value, but
 * displayed value plus step value is bigger than maximum value, the new value
 * will be the minimum value. When the the user tries to decrement it, but the
 * value less step is less than minimum value, the new displayed value will be
 * the maximum value.
 *
 * E.g.: @c min = 10 @c max = 50 @c step = 20 @c displayed = 20
 *
 * When the user decrement value (using left or bottom arrow), it will displays
 * $50.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true to enable wrap or @c false to disable it.
 *
 * @ingroup Elm_Spinner
 */
EOAPI Eina_Bool  elm_obj_spinner_wrap_get(void);

/**
 * @brief Control the interval on time updates for an user mouse button hold on
 * spinner widgets' arrows.
 *
 * This interval value is decreased while the user holds the mouse pointer
 * either incrementing or decrementing spinner's value.
 *
 * This helps the user to get to a given value distant from the current one
 * easier/faster, as it will start to change quicker and quicker on mouse
 * button holds.
 *
 * The calculation for the next change interval value, starting from the one
 * set with this call, is the previous interval divided by $1.05, so it
 * decreases a little bit.
 *
 * The default starting interval value for automatic changes is $0.85 seconds.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] interval The (first) interval value in seconds.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_interval_set(double interval);

/**
 * @brief Control the interval on time updates for an user mouse button hold on
 * spinner widgets' arrows.
 *
 * This interval value is decreased while the user holds the mouse pointer
 * either incrementing or decrementing spinner's value.
 *
 * This helps the user to get to a given value distant from the current one
 * easier/faster, as it will start to change quicker and quicker on mouse
 * button holds.
 *
 * The calculation for the next change interval value, starting from the one
 * set with this call, is the previous interval divided by $1.05, so it
 * decreases a little bit.
 *
 * The default starting interval value for automatic changes is $0.85 seconds.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The (first) interval value in seconds.
 *
 * @ingroup Elm_Spinner
 */
EOAPI double  elm_obj_spinner_interval_get(void);

/**
 * @brief Control the round value for rounding
 *
 * Sets the rounding value used for value rounding in the spinner.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] rnd The rounding value
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_round_set(int rnd);

/**
 * @brief Control the round value for rounding
 *
 * Sets the rounding value used for value rounding in the spinner.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The rounding value
 *
 * @ingroup Elm_Spinner
 */
EOAPI int  elm_obj_spinner_round_get(void);

/**
 * @brief Control whether the spinner can be directly edited by the user or
 * not.
 *
 * Spinner objects can have edition disabled, in which state they will be
 * changed only by arrows. Useful for contexts where you don't want your users
 * to interact with it writing the value. Specially when using special values,
 * the user can see real value instead of special label on edition.
 *
 * It's enabled by default.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] editable @c true to allow users to edit it or @c false to don't
 * allow users to edit it directly.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_editable_set(Eina_Bool editable);

/**
 * @brief Control whether the spinner can be directly edited by the user or
 * not.
 *
 * Spinner objects can have edition disabled, in which state they will be
 * changed only by arrows. Useful for contexts where you don't want your users
 * to interact with it writing the value. Specially when using special values,
 * the user can see real value instead of special label on edition.
 *
 * It's enabled by default.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true to allow users to edit it or @c false to don't allow users
 * to edit it directly.
 *
 * @ingroup Elm_Spinner
 */
EOAPI Eina_Bool  elm_obj_spinner_editable_get(void);

/**
 * @brief Control the base for rounding
 *
 * Rounding works as follows:
 *
 * rounded_val = base + (double)(((value - base) / round) * round)
 *
 * Where rounded_val, value and base are doubles, and round is an integer.
 *
 * This means that things will be rounded to increments (or decrements) of
 * "round" starting from value @c base. The default base for rounding is 0.
 *
 * Example: round = 3, base = 2 Values: ..., -2, 0, 2, 5, 8, 11, 14, ...
 *
 * Example: round = 2, base = 5.5 Values: ..., -0.5, 1.5, 3.5, 5.5, 7.5, 9.5,
 * 11.5, ...
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] base The base value
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_base_set(double base);

/**
 * @brief Control the base for rounding
 *
 * Rounding works as follows:
 *
 * rounded_val = base + (double)(((value - base) / round) * round)
 *
 * Where rounded_val, value and base are doubles, and round is an integer.
 *
 * This means that things will be rounded to increments (or decrements) of
 * "round" starting from value @c base. The default base for rounding is 0.
 *
 * Example: round = 3, base = 2 Values: ..., -2, 0, 2, 5, 8, 11, 14, ...
 *
 * Example: round = 2, base = 5.5 Values: ..., -0.5, 1.5, 3.5, 5.5, 7.5, 9.5,
 * 11.5, ...
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The base value
 *
 * @ingroup Elm_Spinner
 */
EOAPI double  elm_obj_spinner_base_get(void);

/**
 * @brief Control the value the spinner displays.
 *
 * Value will be presented on the label following format specified with
 * elm_spinner_format_set().
 *
 * Warning The value must to be between min and max values. This values are set
 * by elm_spinner_min_max_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] val The value to be displayed.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_value_set(double val);

/**
 * @brief Control the value the spinner displays.
 *
 * Value will be presented on the label following format specified with
 * elm_spinner_format_set().
 *
 * Warning The value must to be between min and max values. This values are set
 * by elm_spinner_min_max_set().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The value to be displayed.
 *
 * @ingroup Elm_Spinner
 */
EOAPI double  elm_obj_spinner_value_get(void);

/**
 * @brief Control the format string of the displayed label.
 *
 * If @c NULL, this sets the format to "%.0f". If not it sets the format string
 * for the label text. The label text is provided a floating point value, so
 * the label text can display up to 1 floating point value. Note that this is
 * optional.
 *
 * Use a format string such as "%1.2f meters" for example, and it will display
 * values like: "3.14 meters" for a value equal to 3.14159.
 *
 * Default is "%0.f".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] fmt The format string for the label display.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_label_format_set(const char *fmt);

/**
 * @brief Control the format string of the displayed label.
 *
 * If @c NULL, this sets the format to "%.0f". If not it sets the format string
 * for the label text. The label text is provided a floating point value, so
 * the label text can display up to 1 floating point value. Note that this is
 * optional.
 *
 * Use a format string such as "%1.2f meters" for example, and it will display
 * values like: "3.14 meters" for a value equal to 3.14159.
 *
 * Default is "%0.f".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The format string for the label display.
 *
 * @ingroup Elm_Spinner
 */
EOAPI const char * elm_obj_spinner_label_format_get(void);

/**
 * @brief Control special string to display in the place of the numerical
 * value.
 *
 * It's useful for cases when a user should select an item that is better
 * indicated by a label than a value. For example, weekdays or months.
 *
 * @note If another label was previously set to @c value, it will be replaced
 * by the new label.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] label The label to be used.
 *
 * @ingroup Elm_Spinner
 */
EOAPI void  elm_obj_spinner_special_value_add(double value, const char *label);

EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_DELAY_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_SPINNER_DRAG_START;
EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_SPINNER_DRAG_STOP;
EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_SPINNER_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_SPINNER_EVENT_CHANGED (&(_ELM_SPINNER_EVENT_CHANGED))

/**
 * No description
 */
#define ELM_SPINNER_EVENT_DELAY_CHANGED (&(_ELM_SPINNER_EVENT_DELAY_CHANGED))

/**
 * No description
 */
#define ELM_SPINNER_EVENT_SPINNER_DRAG_START (&(_ELM_SPINNER_EVENT_SPINNER_DRAG_START))

/**
 * No description
 */
#define ELM_SPINNER_EVENT_SPINNER_DRAG_STOP (&(_ELM_SPINNER_EVENT_SPINNER_DRAG_STOP))

/**
 * No description
 */
#define ELM_SPINNER_EVENT_LANGUAGE_CHANGED (&(_ELM_SPINNER_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_SPINNER_EVENT_ACCESS_CHANGED (&(_ELM_SPINNER_EVENT_ACCESS_CHANGED))

#endif
