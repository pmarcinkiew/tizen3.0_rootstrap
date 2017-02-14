#ifndef _ELM_SLIDER_EO_LEGACY_H_
#define _ELM_SLIDER_EO_LEGACY_H_

#ifndef _ELM_SLIDER_EO_CLASS_TYPE
#define _ELM_SLIDER_EO_CLASS_TYPE

typedef Eo Elm_Slider;

#endif

#ifndef _ELM_SLIDER_EO_TYPES
#define _ELM_SLIDER_EO_TYPES


#endif

/**
 * @brief Set the orientation of a given slider widget.
 *
 * Use this function to change how your slider is to be disposed: vertically or
 * horizontally.
 *
 * By default it's displayed horizontally.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_horizontal_set(Elm_Slider *obj, Eina_Bool horizontal);

/**
 * @brief Get the orientation of a given slider widget.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Slider
 */
EAPI Eina_Bool elm_slider_horizontal_get(const Elm_Slider *obj);

/**
 * @brief Set the value the slider displays.
 *
 * Value will be presented on the unit label following format specified with
 * @ref elm_slider_unit_format_set and on indicator with
 * @ref elm_slider_indicator_format_set.
 *
 * @note The value must to be between min and max values. This values are set
 * by @ref elm_slider_min_max_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] val The value to be displayed.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_value_set(Elm_Slider *obj, double val);

/**
 * @brief Get the value displayed by the slider.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The value to be displayed.
 *
 * @ingroup Elm_Slider
 */
EAPI double elm_slider_value_get(const Elm_Slider *obj);

/**
 * @brief Set the format string for the indicator label.
 *
 * The slider may display its value somewhere else then unit label, for
 * example, above the slider knob that is dragged around. This function sets
 * the format string used for this.
 *
 * If @c null, indicator label won't be visible. If not it sets the format
 * string for the label text. To the label text is provided a floating point
 * value, so the label text can display up to 1 floating point value. Note that
 * this is optional.
 *
 * Use a format string such as "%1.2f meters" for example, and it will display
 * values like: "3.14 meters" for a value equal to 3.14159.
 *
 * Default is indicator label disabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] indicator The format string for the indicator display.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_indicator_format_set(Elm_Slider *obj, const char *indicator);

/**
 * @brief Get the indicator label format of the slider.
 *
 * The slider may display its value somewhere else then unit label, for
 * example, above the slider knob that is dragged around. This function gets
 * the format string used for this.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The format string for the indicator display.
 *
 * @ingroup Elm_Slider
 */
EAPI const char *elm_slider_indicator_format_get(const Elm_Slider *obj);

/**
 * @brief Invert a given slider widget's displaying values order
 *
 * A slider may be inverted, in which state it gets its values inverted, with
 * high vales being on the left or top and low values on the right or bottom,
 * as opposed to normally have the low values on the former and high values on
 * the latter, respectively, for horizontal and vertical modes.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] inverted Use @c true to make @c obj inverted, @c false to bring
 * it back to default, non-inverted values.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_inverted_set(Elm_Slider *obj, Eina_Bool inverted);

/**
 * @brief Get whether a given slider widget's displaying values are inverted or
 * not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Use @c true to make @c obj inverted, @c false to bring it back to
 * default, non-inverted values.
 *
 * @ingroup Elm_Slider
 */
EAPI Eina_Bool elm_slider_inverted_get(const Elm_Slider *obj);

/**
 * @brief Set whether to enlarge slider indicator (augmented knob) or not.
 *
 * By default, indicator will be bigger while dragged by the user.
 *
 * @warning It won't display values set with
 * @ref elm_slider_indicator_format_set if you disable indicator.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] show @c true will make it enlarge, @c false will let the knob
 * always at default size.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_indicator_show_set(Elm_Slider *obj, Eina_Bool show);

/**
 * @brief Get whether a given slider widget's enlarging indicator or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true will make it enlarge, @c false will let the knob always at
 * default size.
 *
 * @ingroup Elm_Slider
 */
EAPI Eina_Bool elm_slider_indicator_show_get(const Elm_Slider *obj);

/**
 * @brief Set the minimum and maximum values for the slider.
 *
 * Define the allowed range of values to be selected by the user.
 *
 * If actual value is less than @c min, it will be updated to @c min. If it is
 * bigger then @c max, will be updated to @c max. Actual value can be get with
 * @ref elm_slider_value_get,get.
 *
 * By default, min is equal to 0.0, and max is equal to 1.0.
 *
 * @warning maximum must be greater than minimum, otherwise behavior is
 * undefined.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] min The minimum value.
 * @param[in] max The maximum value.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_min_max_set(Elm_Slider *obj, double min, double max);

/**
 * @brief Get the minimum and maximum values of the slider.
 *
 * @note If only one value is needed, the other pointer can be passed as
 * @c null.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] min The minimum value.
 * @param[out] max The maximum value.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_min_max_get(const Elm_Slider *obj, double *min, double *max);

/**
 * @brief Set the format string for the unit label.
 *
 * Unit label is displayed all the time, if set, after slider's bar. In
 * horizontal mode, at right and in vertical mode, at bottom.
 *
 * If @c null, unit label won't be visible. If not it sets the format string
 * for the label text. To the label text is provided a floating point value, so
 * the label text can display up to 1 floating point value. Note that this is
 * optional.
 *
 * Use a format string such as "%1.2f meters" for example, and it will display
 * values like: "3.14 meters" for a value equal to 3.14159.
 *
 * Default is unit label disabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] units The format string for the unit display.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_unit_format_set(Elm_Slider *obj, const char *units);

/**
 * @brief Get the unit label format of the slider.
 *
 * Unit label is displayed all the time, if set, after slider's bar. In
 * horizontal mode, at right and in vertical mode, at bottom.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The format string for the unit display.
 *
 * @ingroup Elm_Slider
 */
EAPI const char *elm_slider_unit_format_get(const Elm_Slider *obj);

/**
 * @brief Show the indicator of slider on focus.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] flag
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_indicator_show_on_focus_set(Elm_Slider *obj, Eina_Bool flag);

/**
 * @brief Get whether the indicator of the slider is set or not.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Elm_Slider
 */
EAPI Eina_Bool elm_slider_indicator_show_on_focus_get(const Elm_Slider *obj);

/**
 * @brief Set the (exact) length of the bar region of a given slider widget.
 *
 * This sets the minimum width (when in horizontal mode) or height (when in
 * vertical mode) of the actual bar area of the slider @c obj. This in turn
 * affects the object's minimum size. Use this when you're not setting other
 * size hints expanding on the given direction (like weight and alignment
 * hints) and you would like it to have a specific size.
 *
 * @note Icon, end, label, indicator and unit text around @c obj will require
 * their own space, which will make @c obj to require more the @c size,
 * actually.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] size The length of the slider's bar region.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_span_size_set(Elm_Slider *obj, Evas_Coord size);

/**
 * @brief Get the length set for the bar region of a given slider widget
 *
 * If that size was not set previously, with @ref elm_slider_span_size_set,
 * this call will return $0.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The length of the slider's bar region.
 *
 * @ingroup Elm_Slider
 */
EAPI Evas_Coord elm_slider_span_size_get(const Elm_Slider *obj);

/**
 * @brief Set the step by which slider indicator will move.
 *
 * This value is used when draggable object is moved automatically i.e., in
 * case of key event when up/down/left/right key is pressed or in case when
 * accessibility is set and flick event is used to inc/dec slider values. By
 * default step value is equal to 0.05.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] step The step value.
 *
 * @since 1.8
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_step_set(Elm_Slider *obj, double step);

/**
 * @brief Get the step by which slider indicator moves.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The step value.
 *
 * @since 1.8
 *
 * @ingroup Elm_Slider
 */
EAPI double elm_slider_step_get(const Elm_Slider *obj);

/**
 * @brief Set the visible mode of indicator.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] indicator_visible_mode The indicator visible mode.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_indicator_visible_mode_set(Elm_Slider *obj, Elm_Slider_Indicator_Visible_Mode indicator_visible_mode);

/**
 * @brief Get the visible mode of indicator.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The indicator visible mode.
 *
 * @ingroup Elm_Slider
 */
EAPI Elm_Slider_Indicator_Visible_Mode elm_slider_indicator_visible_mode_get(const Elm_Slider *obj);

/**
 * @brief Set the format function pointer for the indicator label
 *
 * Set the callback function to format the indicator string.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] func The indicator format function.
 * @param[in] free_func The freeing function for the format string.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_indicator_format_function_set(Elm_Slider *obj, slider_func_type func, slider_freefunc_type free_func);

/**
 * @brief Set the format function pointer for the units label
 *
 * Set the callback function to format the units string.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] func The units format function.
 * @param[in] free_func The freeing function for the format string.
 *
 * @ingroup Elm_Slider
 */
EAPI void elm_slider_units_format_function_set(Elm_Slider *obj, slider_func_type func, slider_freefunc_type free_func);

#endif
