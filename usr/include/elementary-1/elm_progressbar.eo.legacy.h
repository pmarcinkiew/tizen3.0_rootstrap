#ifndef _ELM_PROGRESSBAR_EO_LEGACY_H_
#define _ELM_PROGRESSBAR_EO_LEGACY_H_

#ifndef _ELM_PROGRESSBAR_EO_CLASS_TYPE
#define _ELM_PROGRESSBAR_EO_CLASS_TYPE

typedef Eo Elm_Progressbar;

#endif

#ifndef _ELM_PROGRESSBAR_EO_TYPES
#define _ELM_PROGRESSBAR_EO_TYPES


#endif

/**
 * @brief Control the (exact) length of the bar region of a given progress bar
 * widget
 *
 * This sets the minimum width (when in horizontal mode) or height (when in
 * vertical mode) of the actual bar area of the progress bar @c obj. This in
 * turn affects the object's minimum size. Use this when you're not setting
 * other size hints expanding on the given direction (like weight and alignment
 * hints) and you would like it to have a specific size.
 *
 * @note Icon, label and unit text around @c obj will require their own space,
 * which will make @c obj to require more the @c size, actually.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] size The length of the progress bar's bar region
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_span_size_set(Elm_Progressbar *obj, Evas_Coord size);

/**
 * @brief Control the (exact) length of the bar region of a given progress bar
 * widget
 *
 * This sets the minimum width (when in horizontal mode) or height (when in
 * vertical mode) of the actual bar area of the progress bar @c obj. This in
 * turn affects the object's minimum size. Use this when you're not setting
 * other size hints expanding on the given direction (like weight and alignment
 * hints) and you would like it to have a specific size.
 *
 * @note Icon, label and unit text around @c obj will require their own space,
 * which will make @c obj to require more the @c size, actually.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The length of the progress bar's bar region
 *
 * @ingroup Elm_Progressbar
 */
EAPI Evas_Coord elm_progressbar_span_size_get(const Elm_Progressbar *obj);

/**
 * @brief Control whether a given progress bar widget is at "pulsing mode" or
 * not.
 *
 * By default, progress bars will display values from the low to high value
 * boundaries. There are, though, contexts in which the progress of a given
 * task is unknown. For such cases, one can set a progress bar widget to a
 * "pulsing state", to give the user an idea that some computation is being
 * held, but without exact progress values. In the default theme, it will
 * animate its bar with the contents filling in constantly and back to
 * non-filled, in a loop. To start and stop this pulsing animation, one has to
 * explicitly call elm_progressbar_pulse().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] pulse @c true to put @c obj in pulsing mode, @c false to put it
 * back to its default one
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_pulse_set(Elm_Progressbar *obj, Eina_Bool pulse);

/**
 * @brief Control whether a given progress bar widget is at "pulsing mode" or
 * not.
 *
 * By default, progress bars will display values from the low to high value
 * boundaries. There are, though, contexts in which the progress of a given
 * task is unknown. For such cases, one can set a progress bar widget to a
 * "pulsing state", to give the user an idea that some computation is being
 * held, but without exact progress values. In the default theme, it will
 * animate its bar with the contents filling in constantly and back to
 * non-filled, in a loop. To start and stop this pulsing animation, one has to
 * explicitly call elm_progressbar_pulse().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true to put @c obj in pulsing mode, @c false to put it back to
 * its default one
 *
 * @ingroup Elm_Progressbar
 */
EAPI Eina_Bool elm_progressbar_pulse_get(const Elm_Progressbar *obj);

/**
 * @brief Control the progress value (in percentage) on a given progress bar
 * widget
 *
 * Use this call to set progress bar levels.
 *
 * @note If you passes a value out of the specified range for @c val, it will
 * be interpreted as the closest of the boundary values in the range.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] val The progress value (must be between $0.0 and 1.0)
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_value_set(Elm_Progressbar *obj, double val);

/**
 * @brief Control the progress value (in percentage) on a given progress bar
 * widget
 *
 * Use this call to set progress bar levels.
 *
 * @note If you passes a value out of the specified range for @c val, it will
 * be interpreted as the closest of the boundary values in the range.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The progress value (must be between $0.0 and 1.0)
 *
 * @ingroup Elm_Progressbar
 */
EAPI double elm_progressbar_value_get(const Elm_Progressbar *obj);

/**
 * @brief Invert a given progress bar widget's displaying values order
 *
 * A progress bar may be inverted, in which state it gets its values inverted,
 * with high values being on the left or top and low values on the right or
 * bottom, as opposed to normally have the low values on the former and high
 * values on the latter, respectively, for horizontal and vertical modes.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] inverted Use @c true to make @c obj inverted, @c false to bring
 * it back to default, non-inverted values.
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_inverted_set(Elm_Progressbar *obj, Eina_Bool inverted);

/**
 * @brief Invert a given progress bar widget's displaying values order
 *
 * A progress bar may be inverted, in which state it gets its values inverted,
 * with high values being on the left or top and low values on the right or
 * bottom, as opposed to normally have the low values on the former and high
 * values on the latter, respectively, for horizontal and vertical modes.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Use @c true to make @c obj inverted, @c false to bring it back to
 * default, non-inverted values.
 *
 * @ingroup Elm_Progressbar
 */
EAPI Eina_Bool elm_progressbar_inverted_get(const Elm_Progressbar *obj);

/**
 * @brief Control the orientation of a given progress bar widget
 *
 * Use this function to change how your progress bar is to be disposed:
 * vertically or horizontally.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal Use @c true to make @c obj to be horizontal, @c false
 * to make it vertical
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_horizontal_set(Elm_Progressbar *obj, Eina_Bool horizontal);

/**
 * @brief Control the orientation of a given progress bar widget
 *
 * Use this function to change how your progress bar is to be disposed:
 * vertically or horizontally.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Use @c true to make @c obj to be horizontal, @c false to make it
 * vertical
 *
 * @ingroup Elm_Progressbar
 */
EAPI Eina_Bool elm_progressbar_horizontal_get(const Elm_Progressbar *obj);

/**
 * @brief Control the format string for a given progress bar widget's units
 * label
 *
 * If @c NULL is passed on @c format, it will make @c obj's units area to be
 * hidden completely. If not, it'll set the <b>format string</b> for the units
 * label's text. The units label is provided a floating point value, so the
 * units text is up display at most one floating point value. Note that the
 * units label is optional. Use a format string such as "%1.2f meters" for
 * example.
 *
 * @note The default format string for a progress bar is an integer percentage,
 * as in $"%.0f %%".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] units The format string for @c obj's units label
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_unit_format_set(Elm_Progressbar *obj, const char *units);

/**
 * @brief Control the format string for a given progress bar widget's units
 * label
 *
 * If @c NULL is passed on @c format, it will make @c obj's units area to be
 * hidden completely. If not, it'll set the <b>format string</b> for the units
 * label's text. The units label is provided a floating point value, so the
 * units text is up display at most one floating point value. Note that the
 * units label is optional. Use a format string such as "%1.2f meters" for
 * example.
 *
 * @note The default format string for a progress bar is an integer percentage,
 * as in $"%.0f %%".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The format string for @c obj's units label
 *
 * @ingroup Elm_Progressbar
 */
EAPI const char *elm_progressbar_unit_format_get(const Elm_Progressbar *obj);

/**
 * @brief Set the format function pointer for the units label
 *
 * Set the callback function to format the unit string.
 *
 * See: @ref elm_progressbar_unit_format_set for more info on how this works.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] func The unit format function
 * @param[in] free_func The freeing function for the format string.
 *
 * @since 1.7
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_unit_format_function_set(Elm_Progressbar *obj, progressbar_func_type func, progressbar_freefunc_type free_func);

/**
 * @brief Set the progress value (in percentage) on a given progress bar widget
 * for the given part name
 *
 * Use this call to set progress bar status for more than one progress status .
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] val The progress value (must be between $0.0 and 1.0)
 *
 * @since 1.8
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_part_value_set(Elm_Progressbar *obj, const char *part, double val);

/**
 * @brief Get the progress value (in percentage) on a given progress bar widget
 * for a particular part
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] part The part name of the progress bar
 *
 * @return The value of the progressbar
 *
 * @since 1.8
 *
 * @ingroup Elm_Progressbar
 */
EAPI double elm_progressbar_part_value_get(const Elm_Progressbar *obj, const char *part);

/**
 * @brief Start/stop a given progress bar "pulsing" animation, if its under
 * that mode
 *
 * @note This call won't do anything if @c obj is not under "pulsing mode".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] state @c true, to start the pulsing animation, @c false to stop
 * it
 *
 * @ingroup Elm_Progressbar
 */
EAPI void elm_progressbar_pulse(Elm_Progressbar *obj, Eina_Bool state);

#endif
