#ifndef _ELM_FLIPSELECTOR_EO_H_
#define _ELM_FLIPSELECTOR_EO_H_

#ifndef _ELM_FLIPSELECTOR_EO_CLASS_TYPE
#define _ELM_FLIPSELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Flipselector;

#endif

#ifndef _ELM_FLIPSELECTOR_EO_TYPES
#define _ELM_FLIPSELECTOR_EO_TYPES


#endif
#define ELM_FLIPSELECTOR_CLASS elm_flipselector_class_get()

EAPI const Eo_Class *elm_flipselector_class_get(void) EINA_CONST;

/**
 * @brief @MOBILE_ONLY
 *
 * Set the interval on time updates for a user mouse button hold on a flip
 * selector widget.
 *
 * This interval value is decreased while the user holds the mouse pointer
 * either flipping up or flipping down a given flip selector.
 *
 * This helps the user to get to a given item distant from the current one
 * easier/faster, as it will start to flip quicker and quicker on mouse button
 * holds.
 *
 * The calculation for the next flip interval value, starting from the one set
 * with this call, is the previous interval divided by 1.05, so it decreases a
 * little bit.
 *
 * The default starting interval value for automatic flips is 0.85 seconds.
 *
 * See also @ref elm_obj_flipselector_first_interval_get.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] interval The (first) interval value in seconds.
 *
 * @ingroup Elm_Flipselector
 */
EOAPI void  elm_obj_flipselector_first_interval_set(double interval);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the interval on time updates for an user mouse button hold on a flip
 * selector widget.
 *
 * See also @ref elm_obj_flipselector_first_interval_set for more details.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The (first) interval value in seconds.
 *
 * @ingroup Elm_Flipselector
 */
EOAPI double  elm_obj_flipselector_first_interval_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the internal list of items in a given flip selector widget.
 *
 * This list is not to be modified in any way and must not be freed. Use the
 * list members with functions like @ref elm_object_item_text_set, @ref
 * elm_object_item_text_get, @ref elm_object_item_del, @ref
 * elm_flipselector_item_selected_get, @ref elm_flipselector_item_selected_set.
 *
 * @warning This list is only valid until @c obj object's internal items list
 * is changed. It should be fetched again with another call to this function
 * when changes happen.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Flipselector
 */
EOAPI const Eina_List * elm_obj_flipselector_items_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the first item in the given flip selector widget's list of items.
 *
 * See also @ref elm_obj_flipselector_item_append,
 * @ref elm_obj_flipselector_last_item_get.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The first item or @c null, if it has no items (and on errors).
 *
 * @ingroup Elm_Flipselector
 */
EOAPI Elm_Widget_Item * elm_obj_flipselector_first_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the last item in the given flip selector widget's list of items.
 *
 * See also @ref elm_obj_flipselector_item_prepend,
 * @ref elm_obj_flipselector_first_item_get.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The last item or @c null, if it has no items (and on errors).
 *
 * @ingroup Elm_Flipselector
 */
EOAPI Elm_Widget_Item * elm_obj_flipselector_last_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Get the currently selected item in a flip selector widget.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @return The selected item or @c null, if the widget has no items (and on
 * errors).
 *
 * @ingroup Elm_Flipselector
 */
EOAPI Elm_Widget_Item * elm_obj_flipselector_selected_item_get(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Prepend a (text) item to a flip selector widget
 *
 * The widget's list of labels to show will be prepended with the given value.
 * If the user wishes so, a callback function pointer can be passed, which will
 * get called when this same item is selected.
 *
 * @note The current selection won't be modified by prepending an element to
 * the list.
 *
 * @note The maximum length of the text label is going to be determined by the
 * widget's theme. Strings larger than that value are going to be truncated.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] func Convenience callback function to take place when item is
 * selected.
 * @param[in] data Data passed to @c func, above.
 *
 * @ingroup Elm_Flipselector
 */
EOAPI Elm_Widget_Item * elm_obj_flipselector_item_prepend(const char *label, Evas_Smart_Cb func, void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Programmatically select the next item of a flip selector widget
 *
 * @note The selection will be animated. Also, if it reaches the end of its
 * list of member items, it will continue with the first one onwards.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Flipselector
 */
EOAPI void  elm_obj_flipselector_flip_next(void);

/**
 * @brief @MOBILE_ONLY
 *
 * Append a (text) item to a flip selector widget
 *
 * The widget's list of labels to show will be appended with the given value.
 * If the user wishes so, a callback function pointer can be passed, which will
 * get called when this same item is selected.
 *
 * @note The current selection won't be modified by appending an element to the
 * list.
 *
 * @note The maximum length of the text label is going to be determined by the
 * widget's theme. Strings larger than that value are going to be truncated.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] func Convenience callback function to take place when item is
 * selected.
 * @param[in] data Data passed to @c func, above.
 *
 * @ingroup Elm_Flipselector
 */
EOAPI Elm_Widget_Item * elm_obj_flipselector_item_append(const char *label, Evas_Smart_Cb func, const void *data);

/**
 * @brief @MOBILE_ONLY
 *
 * Programmatically select the previous item of a flip selector widget
 *
 * @note The selection will be animated. Also, if it reaches the beginning of
 * its list of member items, it will continue with the last one backwards.
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @ingroup Elm_Flipselector
 */
EOAPI void  elm_obj_flipselector_flip_prev(void);

EOAPI extern const Eo_Event_Description _ELM_FLIPSELECTOR_EVENT_UNDERFLOWED;
EOAPI extern const Eo_Event_Description _ELM_FLIPSELECTOR_EVENT_OVERFLOWED;
EOAPI extern const Eo_Event_Description _ELM_FLIPSELECTOR_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_FLIPSELECTOR_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_FLIPSELECTOR_EVENT_UNDERFLOWED (&(_ELM_FLIPSELECTOR_EVENT_UNDERFLOWED))

/**
 * No description
 */
#define ELM_FLIPSELECTOR_EVENT_OVERFLOWED (&(_ELM_FLIPSELECTOR_EVENT_OVERFLOWED))

/**
 * No description
 */
#define ELM_FLIPSELECTOR_EVENT_LANGUAGE_CHANGED (&(_ELM_FLIPSELECTOR_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_FLIPSELECTOR_EVENT_ACCESS_CHANGED (&(_ELM_FLIPSELECTOR_EVENT_ACCESS_CHANGED))

#endif
