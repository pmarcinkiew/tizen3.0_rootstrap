#ifndef _EVAS_OBJECT_SMART_EO_LEGACY_H_
#define _EVAS_OBJECT_SMART_EO_LEGACY_H_

#ifndef _EVAS_OBJECT_SMART_EO_CLASS_TYPE
#define _EVAS_OBJECT_SMART_EO_CLASS_TYPE

typedef Eo Evas_Object_Smart;

#endif

#ifndef _EVAS_OBJECT_SMART_EO_TYPES
#define _EVAS_OBJECT_SMART_EO_TYPES


#endif

/**
 * @brief Set or unset the flag signalling that a given smart object needs to
 * get recalculated.
 *
 * If this flag is set, then the @c calculate() smart function of @c obj will
 * be called, if one is provided, during rendering phase of Evas (see
 * evas_render()), after which this flag will be automatically unset.
 *
 * If that smart function is not provided for the given object, this flag will
 * be left unchanged.
 *
 * @note just setting this flag will not make the canvas' whole scene dirty, by
 * itself, and evas_render() will have no effect. To force that, use
 * evas_object_smart_changed(), that will also call this function
 * automatically, with @c true as parameter.
 *
 * See also @ref evas_object_smart_need_recalculate_get,
 * @ref evas_object_smart_calculate and @ref evas_smart_objects_calculate().
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] value whether one wants to set ($true) or to unset ($false) the
 * flag.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_need_recalculate_set(Evas_Object_Smart *obj, Eina_Bool value);

/**
 * @brief Get the value of the flag signalling that a given smart object needs
 * to get recalculated.
 *
 * @note this flag will be unset during the rendering phase, when the
 * @c calculate() smart function is called, if one is provided. If it's not
 * provided, then the flag will be left unchanged after the rendering phase.
 *
 * See also @ref evas_object_smart_need_recalculate_set, for more details.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return whether one wants to set ($true) or to unset ($false) the flag.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI Eina_Bool evas_object_smart_need_recalculate_get(const Evas_Object_Smart *obj);

/**
 * @brief Store a pointer to user data for a given smart object.
 *
 * This data is stored independently of the one set by evas_object_data_set(),
 * naturally.
 *
 * See also @ref evas_object_smart_data_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data A pointer to user data.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_data_set(Evas_Object_Smart *obj, void *data);

/**
 * @brief Retrieves the list of the member objects of a given Evas smart
 * object.
 *
 * The returned list should be freed with @c eina_list_free() when you no
 * longer need it.
 *
 * This function will return @c null when a non-smart object is passed.
 *
 * See also @ref Evas.Object_Smart.member_add,
 * @ref Evas.Object_Smart.member_del and @ref evas_object_smart_iterator_new.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Returns the list of the member objects of @c obj.
 *
 * @since 1.7
 *
 * @ingroup Evas_Object_Smart
 */
EAPI Eina_List *evas_object_smart_members_get(const Evas_Object_Smart *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Get the @ref Evas_Smart from which @c obj smart object was created.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return the @ref Evas_Smart handle or @c null, on errors.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI Evas_Smart *evas_object_smart_smart_get(const Evas_Object_Smart *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Set an smart object instance's smart callbacks descriptions.
 *
 * These descriptions are hints to be used by introspection and are not
 * enforced in any way.
 *
 * It will not be checked if instance callbacks descriptions have the same name
 * as respective possibly registered in the smart object class. Both are kept
 * in different arrays and users of
 * evas_object_smart_callbacks_descriptions_get() should handle this case as
 * they wish.
 *
 * @note Becase @c descriptions must be @c null terminated, and because a
 * @c null name makes little sense, too, Evas_Smart_Cb_Description.name must
 * not be @c null.
 *
 * @note While instance callbacks descriptions are possible, they are not
 * recommended. Use class callbacks descriptions instead as they make you smart
 * object user's life simpler and will use less memory, as descriptions and
 * arrays will be shared among all instances.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] descriptions @c null terminated array with
 * @ref Evas_Smart_Cb_Description descriptions. Array elements won't be
 * modified at run time, but references to them and their contents will be
 * made, so this array should be kept alive during the whole object's lifetime.
 *
 * @return @c true on success, @c false on failure.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI Eina_Bool evas_object_smart_callbacks_descriptions_set(Evas_Object_Smart *obj, const Evas_Smart_Cb_Description *descriptions);

/**
 * @brief Retrieve an smart object's know smart callback descriptions (both
 * instance and class ones).
 *
 * This call searches for registered callback descriptions for both instance
 * and class of the given smart object. These arrays will be sorted by
 * Evas_Smart_Cb_Description.name and also @c null terminated, so both
 * class_count and instance_count can be ignored, if the caller wishes so. The
 * terminator @c null is not counted in these values.
 *
 * @note If just class descriptions are of interest, try
 * evas_smart_callbacks_descriptions_get() instead.
 *
 * @note Use @c null pointers on the descriptions/counters you're not
 * interested in: they'll be ignored by the function.
 *
 * @ref evas_smart_callbacks_descriptions_get().
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] class_count Returns how many class callbacks descriptions are
 * known.
 * @param[out] instance_descriptions Where to store instance callbacks
 * descriptions array, if any is known. If no descriptions are known, @c null
 * is returned.
 * @param[out] instance_count Returns how many instance callbacks descriptions
 * are known.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_callbacks_descriptions_get(const Evas_Object_Smart *obj, const Evas_Smart_Cb_Description ***class_descriptions, unsigned int *class_count, const Evas_Smart_Cb_Description ***instance_descriptions, unsigned int *instance_count);

/**
 * @brief Retrieves an iterator of the member objects of a given Evas smart
 * object.
 *
 * See also @ref Evas.Object_Smart.member_add and
 * @ref Evas.Object_Smart.member_del
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return Returns the iterator of the member objects of @c obj.
 *
 * @since 1.8
 *
 * @ingroup Evas_Object_Smart
 */
EAPI Eina_Iterator *evas_object_smart_iterator_new(const Evas_Object_Smart *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Find callback description for callback called name or @c null if not
 * found.
 *
 * If parameter is @c null, no search will be done on instance descriptions.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] class_description pointer to return class description or @c null
 * if not found. If parameter is @c null, no search will be done on class
 * descriptions.
 * @param[out] instance_description pointer to return instance description.
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_callback_description_find(const Evas_Object_Smart *obj, const char *name, const Evas_Smart_Cb_Description **class_description, const Evas_Smart_Cb_Description **instance_description) EINA_ARG_NONNULL(2);

/**
 * @brief Call the calculate() smart function immediately on a given smart
 * object.
 *
 * This will force immediate calculations (see #Evas_Smart_Class) needed for
 * renderization of this object and, besides, unset the flag on it telling it
 * needs recalculation for the next rendering phase.
 *
 * See also @ref evas_object_smart_need_recalculate_set
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_calculate(Evas_Object_Smart *obj);

/**
 * @brief Mark smart object as changed, dirty.
 *
 * This will flag the given object as needing recalculation, forcefully. As an
 * effect, on the next rendering cycle its calculate() (see #Evas_Smart_Class)
 * smart function will be called.
 *
 * See also @ref evas_object_smart_need_recalculate_set and
 * @ref evas_object_smart_calculate.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Object_Smart
 */
EAPI void evas_object_smart_changed(Evas_Object_Smart *obj);

#endif
