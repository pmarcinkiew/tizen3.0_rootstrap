#ifndef _ELM_GESTURE_LAYER_EO_LEGACY_H_
#define _ELM_GESTURE_LAYER_EO_LEGACY_H_

#ifndef _ELM_GESTURE_LAYER_EO_CLASS_TYPE
#define _ELM_GESTURE_LAYER_EO_CLASS_TYPE

typedef Eo Elm_Gesture_Layer;

#endif

#ifndef _ELM_GESTURE_LAYER_EO_TYPES
#define _ELM_GESTURE_LAYER_EO_TYPES


#endif

/**
 * @brief Control step value for zoom action.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] step The zoom step value.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_zoom_step_set(Elm_Gesture_Layer *obj, double step);

/**
 * @brief Control step value for zoom action.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The zoom step value.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI double elm_gesture_layer_zoom_step_get(const Elm_Gesture_Layer *obj);

/**
 * @brief This function sets the gesture layer finger-size for taps.
 *
 * If not set, it's taken from elm_config. Set to 0 if you want GLayer to use
 * the system finger size value (default).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] sz The finger size.
 *
 * @since 1.8
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_tap_finger_size_set(Elm_Gesture_Layer *obj, Evas_Coord sz);

/**
 * @brief This function returns the gesture layer finger-size for taps
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The finger size.
 *
 * @since 1.8
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI Evas_Coord elm_gesture_layer_tap_finger_size_get(const Elm_Gesture_Layer *obj);

/**
 * @brief This function makes gesture-layer repeat events.
 *
 * Set this if you like to get the raw events only if gestures were not
 * detected.
 *
 * Clear this if you like gesture layer to forward events as testing gestures.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] hold_events
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_hold_events_set(Elm_Gesture_Layer *obj, Eina_Bool hold_events);

/**
 * @brief Get the repeat-events setting.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI Eina_Bool elm_gesture_layer_hold_events_get(const Elm_Gesture_Layer *obj);

/**
 * @brief This function sets the step value for rotate action.
 *
 * Set to 0 to cancel step setting.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] step New rotate step value.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_rotate_step_set(Elm_Gesture_Layer *obj, double step);

/**
 * @brief This function returns step-value for rotate action.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return New rotate step value.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI double elm_gesture_layer_rotate_step_get(const Elm_Gesture_Layer *obj);

/**
 * @brief Set the gesture state change callback.
 *
 * When all callbacks for the gesture are set to @c null, it means this gesture
 * is disabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] idx The gesture you want to track state of.
 * @param[in] cb_type The event the callback tracks (START, MOVE, END, ABORT).
 * @param[in] cb The callback itself.
 * @param[in] data Custom data to be passed.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_cb_set(Elm_Gesture_Layer *obj, Elm_Gesture_Type idx, Elm_Gesture_State cb_type, Elm_Gesture_Event_Cb cb, void *data);

/**
 * @brief Attach a gesture layer widget to an Evas object (setting the widget's
 * target).
 *
 * A gesture layer's target may be any Evas object. This object will be used to
 * listen to mouse and key events.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] target The object to attach.
 *
 * @return @c true on success, @c false otherwise.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI Eina_Bool elm_gesture_layer_attach(Elm_Gesture_Layer *obj, Evas_Object *target);

/**
 * @brief Remove a gesture callback.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cb_type The event the callback tracks (START, MOVE, END, ABORT).
 * @param[in] cb The callback itself.
 * @param[in] data Custom callback data.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_cb_del(Elm_Gesture_Layer *obj, Elm_Gesture_Type idx, Elm_Gesture_State cb_type, Elm_Gesture_Event_Cb cb, void *data);

/**
 * @brief Add a gesture state change callback.
 *
 * When all callbacks for the gesture are set to @c null, it means this gesture
 * is disabled.
 *
 * If a function was already set for this gesture/type/state, it will be
 * replaced by the new one. For ABI compat, callbacks added by
 * @ref elm_gesture_layer_cb_add will be removed. It is recommended to use only
 * one of these functions for a gesture object.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] cb_type The event the callback tracks (START, MOVE, END, ABORT).
 * @param[in] cb The callback itself.
 * @param[in] data Custom data to be passed.
 *
 * @ingroup Elm_Gesture_Layer
 */
EAPI void elm_gesture_layer_cb_add(Elm_Gesture_Layer *obj, Elm_Gesture_Type idx, Elm_Gesture_State cb_type, Elm_Gesture_Event_Cb cb, void *data);

#endif
