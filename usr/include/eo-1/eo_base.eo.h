#ifndef _EO_BASE_EO_H_
#define _EO_BASE_EO_H_

#ifndef _EO_BASE_EO_CLASS_TYPE
#define _EO_BASE_EO_CLASS_TYPE

typedef Eo Eo_Base;

#endif

#ifndef _EO_BASE_EO_TYPES
#define _EO_BASE_EO_TYPES

/** This struct holds the description of a specific event.
 *
 * @ingroup Eo
 */
typedef struct _Eo_Event_Description
{
  const char *name; /** name of the event. */
  Eina_Bool unfreezable; /** Eina_True if the event cannot be frozen. */
  Eina_Bool legacy_is; /** Internal use: if is a legacy event. */
} Eo_Event_Description;

/**
 * @brief An item in an array of callback desc/func.
 *
 * See also @ref eo_event_callback_array_add.
 *
 * @ingroup Eo
 */
typedef struct _Eo_Callback_Array_Item
{
  const Eo_Event_Description *desc; /** The event description. */
  Eo_Event_Cb func; /** The callback function. */
} Eo_Callback_Array_Item;

/** The structure for the debug info used by Eo.
 *
 * @ingroup Eo
 */
typedef struct _Eo_Dbg_Info
{
  Eina_Stringshare *name; /** The name of the part (stringshare). */
  Eina_Value value; /** The value. */
} Eo_Dbg_Info;

/**
 * @brief Callback priority value. Range is -32k - 32k. The lower the number,
 * the higher the priority.
 *
 * See @ref EO_CALLBACK_PRIORITY_AFTER, @ref EO_CALLBACK_PRIORITY_BEFORE @ref
 * EO_CALLBACK_PRIORITY_DEFAULT
 *
 * @ingroup Eo
 */
typedef short Eo_Callback_Priority;


#endif
#define EO_BASE_CLASS eo_base_class_get()

EAPI const Eo_Class *eo_base_class_get(void) EINA_CONST;

/**
 * @brief Set the parent of an object.
 *
 * Parents keep references to their children so in order to delete objects that
 * have parents you need to set parent to NULL or use eo_del() that does that
 * for you (and also unrefs the object).
 *
 * @param[in] parent the new parent
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_parent_set(Eo_Base *parent);

/**
 * @brief Get the parent of an object
 *
 * @return the new parent
 *
 * @ingroup Eo_Base
 */
EOAPI Eo_Base * eo_parent_get(void);

/**
 * @brief Return freeze events of object.
 *
 * Return event freeze count.
 *
 * @return The event freeze count of the object
 *
 * @ingroup Eo_Base
 */
EOAPI int  eo_event_global_freeze_count_get(void);

/**
 * @brief Return freeze events of object.
 *
 * Return event freeze count.
 *
 * @return The event freeze count of the object
 *
 * @ingroup Eo_Base
 */
EOAPI int  eo_event_freeze_count_get(void);

/** True if the object is already finalized, false otherwise.
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Bool  eo_finalized_get(void);

/**
 * @brief Call the object's constructor.
 *
 * Should not be used with #eo_do. Only use it with #eo_do_super.
 *
 * @return The new object created, can be NULL if aborting
 *
 * @ingroup Eo_Base
 */
EOAPI Eo_Base * eo_constructor(void);

/**
 * @brief Call the object's destructor.
 *
 * Should not be used with #eo_do. Only use it with #eo_do_super.
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_destructor(void);

/**
 * @brief Called at the end of #eo_add. Should not be called, just overridden.
 *
 * @return The new object created, can be NULL if aborting
 *
 * @ingroup Eo_Base
 */
EOAPI Eo_Base * eo_finalize(void);

/**
 * @brief Add a new weak reference to obj.
 *
 * This function registers the object handle pointed by wref to obj so when obj
 * is deleted it'll be updated to NULL. This functions should be used when you
 * want to keep track of an object in a safe way, but you don't want to prevent
 * it from being freed.
 *
 * @param[out] wref
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_wref_add(Eo_Base **wref);

/**
 * @brief Delete the weak reference passed.
 *
 * @param[in] wref
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_wref_del(Eo_Base **wref);

/**
 * @brief Set generic data to object.
 *
 * The user is in change to free the data.
 *
 * @param[in] data the data to set
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_key_data_set(const char *key, const void *data);

/**
 * @brief Get generic data from object.
 *
 * @param[in] key the key associated with the data
 *
 * @return the data for the key
 *
 * @ingroup Eo_Base
 */
EOAPI void * eo_key_data_get(const char *key);

/**
 * @brief Del generic data from object.
 *
 * @param[in] key the key associated with the data
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_key_data_del(const char *key);

/**
 * @brief thaw events of object.
 *
 * Lets event callbacks be called for the object.
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_thaw(void);

/**
 * @brief freeze events of object.
 *
 * Prevents event callbacks from being called for the object.
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_freeze(void);

/**
 * @brief thaw events of object.
 *
 * Lets event callbacks be called for the object.
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_global_thaw(void);

/**
 * @brief freeze events of object.
 *
 * Prevents event callbacks from being called for the object.
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_global_freeze(void);

/**
 * @brief Add a callback for an event with a specific priority.
 *
 * callbacks of the same priority are called in reverse order of creation.
 *
 * @param[in] priority The priority of the callback
 * @param[in] cb the callback to call
 * @param[in] data additional data to pass to the callback
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_priority_add(const Eo_Event_Description *desc, Eo_Callback_Priority priority, Eo_Event_Cb cb, const void *data);

/**
 * @brief Del a callback with a specific data associated to it for an event.
 *
 * @param[in] func the callback to delete
 * @param[in] user_data The data to compare
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_del(const Eo_Event_Description *desc, Eo_Event_Cb func, const void *user_data);

/**
 * @brief Add a callback array for an event with a specific priority.
 *
 * callbacks of the same priority are called in reverse order of creation.
 *
 * @param[in] priority The priority of the callback
 * @param[in] data additional data to pass to the callback
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_array_priority_add(const Eo_Callback_Array_Item *array, Eo_Callback_Priority priority, const void *data);

/**
 * @brief Del a callback array with a specific data associated to it for an
 * event.
 *
 * @param[in] user_data The data to compare
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_array_del(const Eo_Callback_Array_Item *array, const void *user_data);

/**
 * @brief Call the callbacks for an event of an object.
 *
 * @param[in] event_info Extra event info to pass to the callbacks
 *
 * @return @c true if one of the callbacks aborted the call, @c false otherwise
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Bool  eo_event_callback_call(const Eo_Event_Description *desc, void *event_info);

/**
 * @brief Add an event callback forwarder for an event and an object.
 *
 * @param[in] new_obj The object to emit events from
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_forwarder_add(const Eo_Event_Description *desc, Eo_Base *new_obj);

/**
 * @brief Remove an event callback forwarder for an event and an object.
 *
 * @param[in] new_obj The object to emit events from
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_event_callback_forwarder_del(const Eo_Event_Description *desc, Eo_Base *new_obj);

/**
 * @brief Get dbg information from the object.
 *
 * @param[in] root_node node of the tree
 *
 * @ingroup Eo_Base
 */
EOAPI void  eo_dbg_info_get(Eo_Dbg_Info *root_node);

/** Get an iterator on all childrens
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Iterator * eo_children_iterator_new(void);

#ifdef EO_BASE_BETA
/**
 * @brief Make an object a composite object of another.
 *
 * The class of comp_obj must be part of the extensions of the class of the
 * parent. It is not possible to attach more then 1 composite of the same
 * class. This functions also sets the parent of comp_obj to parent.
 *
 * See @ref eo_composite_detach, @ref eo_composite_part_is.
 *
 * @param[in] comp_obj the object that will be used to composite the parent.
 *
 * @return @c true if successful. @c false otherwise.
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Bool  eo_composite_attach(Eo_Base *comp_obj);
#endif

#ifdef EO_BASE_BETA
/**
 * @brief Detach a composite object from another object.
 *
 * This functions also sets the parent of comp_obj to @c null.
 *
 * See @ref eo_composite_attach, @ref eo_composite_part_is.
 *
 * @param[in] comp_obj the object that will be removed from the parent.
 *
 * @return @c true if successful. @c false otherwise.
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Bool  eo_composite_detach(Eo_Base *comp_obj);
#endif

#ifdef EO_BASE_BETA
/**
 * @brief Check if an object is part of a composite object.
 *
 * See @ref eo_composite_attach, @ref eo_composite_part_is.
 *
 * @return @c true if it is. @c false otherwise.
 *
 * @ingroup Eo_Base
 */
EOAPI Eina_Bool  eo_composite_part_is(void);
#endif

EOAPI extern const Eo_Event_Description _EO_BASE_EVENT_CALLBACK_ADD;
EOAPI extern const Eo_Event_Description _EO_BASE_EVENT_CALLBACK_DEL;
EOAPI extern const Eo_Event_Description _EO_BASE_EVENT_DEL;

/** A callback was added.
 *
 * @ingroup Eo_Base
 */
#define EO_BASE_EVENT_CALLBACK_ADD (&(_EO_BASE_EVENT_CALLBACK_ADD))

/** A callback was deleted.
 *
 * @ingroup Eo_Base
 */
#define EO_BASE_EVENT_CALLBACK_DEL (&(_EO_BASE_EVENT_CALLBACK_DEL))

/** Obj is being deleted.
 *
 * @ingroup Eo_Base
 */
#define EO_BASE_EVENT_DEL (&(_EO_BASE_EVENT_DEL))

#endif
