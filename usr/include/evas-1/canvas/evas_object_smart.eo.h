#ifndef _EVAS_OBJECT_SMART_EO_H_
#define _EVAS_OBJECT_SMART_EO_H_

#ifndef _EVAS_OBJECT_SMART_EO_CLASS_TYPE
#define _EVAS_OBJECT_SMART_EO_CLASS_TYPE

typedef Eo Evas_Object_Smart;

#endif

#ifndef _EVAS_OBJECT_SMART_EO_TYPES
#define _EVAS_OBJECT_SMART_EO_TYPES


#endif
#define EVAS_OBJECT_SMART_CLASS evas_object_smart_class_get()

EAPI const Eo_Class *evas_object_smart_class_get(void) EINA_CONST;

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
 * See also @ref evas_obj_smart_need_recalculate_get,
 * @ref evas_obj_smart_calculate and @ref evas_smart_objects_calculate().
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] value whether one wants to set ($true) or to unset ($false) the
 * flag.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_need_recalculate_set(Eina_Bool value);

/**
 * @brief Get the value of the flag signalling that a given smart object needs
 * to get recalculated.
 *
 * @note this flag will be unset during the rendering phase, when the
 * @c calculate() smart function is called, if one is provided. If it's not
 * provided, then the flag will be left unchanged after the rendering phase.
 *
 * See also @ref evas_obj_smart_need_recalculate_set, for more details.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return whether one wants to set ($true) or to unset ($false) the flag.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI Eina_Bool  evas_obj_smart_need_recalculate_get(void);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] clip
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_clip_set(Evas_Object *clip);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] r
 * @param[in] g
 * @param[in] b
 * @param[in] a
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_color_set(int r, int g, int b, int a);

/**
 * @brief Store a pointer to user data for a given smart object.
 *
 * This data is stored independently of the one set by evas_object_data_set(),
 * naturally.
 *
 * See also @ref evas_obj_smart_data_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data A pointer to user data.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_data_set(void *data);

/**
 * @brief Retrieves the list of the member objects of a given Evas smart
 * object.
 *
 * The returned list should be freed with @c eina_list_free() when you no
 * longer need it.
 *
 * This function will return @c null when a non-smart object is passed.
 *
 * See also @ref evas_obj_smart_member_add, @ref evas_obj_smart_member_del and
 * @ref evas_obj_smart_iterator_new.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Returns the list of the member objects of @c obj.
 *
 * @since 1.7
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI Eina_List * evas_obj_smart_members_get(void);

/**
 * @brief Get the @ref Evas_Smart from which @c obj smart object was created.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return the @ref Evas_Smart handle or @c null, on errors.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI Evas_Smart * evas_obj_smart_get(void);

/** No description supplied by the EAPI.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_show(void);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] y
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_move(Evas_Coord x, Evas_Coord y);

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
EOAPI Eina_Bool  evas_obj_smart_callbacks_descriptions_set(const Evas_Smart_Cb_Description *descriptions);

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
EOAPI void  evas_obj_smart_callbacks_descriptions_get(const Evas_Smart_Cb_Description ***class_descriptions, unsigned int *class_count, const Evas_Smart_Cb_Description ***instance_descriptions, unsigned int *instance_count);

/**
 * @brief Retrieves an iterator of the member objects of a given Evas smart
 * object.
 *
 * See also @ref evas_obj_smart_member_add and @ref evas_obj_smart_member_del
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return Returns the iterator of the member objects of @c obj.
 *
 * @since 1.8
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI Eina_Iterator * evas_obj_smart_iterator_new(void);

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
EOAPI void  evas_obj_smart_callback_description_find(const char *name, const Evas_Smart_Cb_Description **class_description, const Evas_Smart_Cb_Description **instance_description);

/** No description supplied by the EAPI.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_hide(void);

/**
 * @brief Call the calculate() smart function immediately on a given smart
 * object.
 *
 * This will force immediate calculations (see #Evas_Smart_Class) needed for
 * renderization of this object and, besides, unset the flag on it telling it
 * needs recalculation for the next rendering phase.
 *
 * See also @ref evas_obj_smart_need_recalculate_set
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_calculate(void);

/**
 * @brief Instantiates a new smart object described by @c s.
 *
 * This is the function one should use when defining the public function adding
 * an instance of the new smart object to a given canvas. It will take care of
 * setting all of its internals to work as they should, if the user set things
 * properly, as seem on the #EVAS_SMART_SUBCLASS_NEW, for example.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_add(void);

/**
 * @brief Set an Evas object as a member of a given smart object.
 *
 * Members will automatically be stacked and layered together with the smart
 * object. The various stacking functions will operate on members relative to
 * the other members instead of the entire canvas, since they now live on an
 * exclusive layer (see evas_object_stack_above(), for more details).
 *
 * Any @c smart_obj object's specific implementation of the @c member_add()
 * smart function will take place too, naturally.
 *
 * See also @ref evas_obj_smart_member_del.
 *
 * @param[in] sub_obj The member object.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_member_add(Evas_Object *sub_obj);

/**
 * @brief No description supplied by the EAPI.
 *
 * @param[in] h
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_resize(Evas_Coord w, Evas_Coord h);

/** No description supplied by the EAPI.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_clip_unset(void);

/**
 * @brief Mark smart object as changed, dirty.
 *
 * This will flag the given object as needing recalculation, forcefully. As an
 * effect, on the next rendering cycle its calculate() (see #Evas_Smart_Class)
 * smart function will be called.
 *
 * See also @ref evas_obj_smart_need_recalculate_set and
 * @ref evas_obj_smart_calculate.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_changed(void);

/**
 * @brief Removes a member object from a given smart object.
 *
 * This removes a member object from a smart object, if it was added to any.
 * The object will still be on the canvas, but no longer associated with
 * whichever smart object it was associated with.
 *
 * See also @ref evas_obj_smart_member_add for more details.
 *
 * @param[in] sub_obj the member object.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_member_del(Evas_Object *sub_obj);

/** Deletes a smart object.
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_del(void);

/**
 * @brief Attach a given smart data to a given smart object.
 *
 * @param[in] s
 *
 * @ingroup Evas_Object_Smart
 */
EOAPI void  evas_obj_smart_attach(Evas_Smart *s);


#endif
