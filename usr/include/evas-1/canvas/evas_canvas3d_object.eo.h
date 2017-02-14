#ifndef _EVAS_CANVAS3D_OBJECT_EO_H_
#define _EVAS_CANVAS3D_OBJECT_EO_H_

#ifndef _EVAS_CANVAS3D_OBJECT_EO_CLASS_TYPE
#define _EVAS_CANVAS3D_OBJECT_EO_CLASS_TYPE

typedef Eo Evas_Canvas3D_Object;

#endif

#ifndef _EVAS_CANVAS3D_OBJECT_EO_TYPES
#define _EVAS_CANVAS3D_OBJECT_EO_TYPES


#endif
#define EVAS_CANVAS3D_OBJECT_CLASS evas_canvas3d_object_class_get()

EAPI const Eo_Class *evas_canvas3d_object_class_get(void) EINA_CONST;

/**
 * @brief Pure virtual update_notify function.
 *
 * Update request for the object.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_update_notify(void);

/**
 * @brief Pure virtual change_notify function.
 *
 * Update request for the object.
 *
 * @param[in] ref The Object that caused the change.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_change_notify(Evas_Canvas3D_State state, Evas_Canvas3D_Object *ref);

/**
 * @brief Pure virtual register samrt callback function.
 *
 * @param[in] data User data.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_callback_register(const char *event, const void *data);

/**
 * @brief Pure virtual unregister smart callback function.
 *
 * @param[in] event Event type.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_callback_unregister(const char *event);

/**
 * @brief Notify the object regarding its  state change.
 *
 * @param[in] ref The Object that caused the change.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_change(Evas_Canvas3D_State state, Evas_Canvas3D_Object *ref);

/** Returns the type of the object.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI Evas_Canvas3D_Object_Type  evas_canvas3d_object_type_get(void);

/**
 * @brief Returns the type of the object.
 *
 * @param[in] type
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_type_set(Evas_Canvas3D_Object_Type type);

/**
 * @brief Returns the status of a particular state of the object.
 *
 * @param[in] state State whose status is being asked.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI Eina_Bool  evas_canvas3d_object_dirty_get(Evas_Canvas3D_State state);

/** Update request for the object.
 *
 * @ingroup Evas_Canvas3D_Object
 */
EOAPI void  evas_canvas3d_object_update(void);

EOAPI extern const Eo_Event_Description _EVAS_CANVAS3D_OBJECT_EVENT_CLICKED;
EOAPI extern const Eo_Event_Description _EVAS_CANVAS3D_OBJECT_EVENT_COLLISION;

/** Clicked Event.
 *
 * @ingroup Evas_Canvas3D_Object
 */
#define EVAS_CANVAS3D_OBJECT_EVENT_CLICKED (&(_EVAS_CANVAS3D_OBJECT_EVENT_CLICKED))

/** Collision Event.
 *
 * @ingroup Evas_Canvas3D_Object
 */
#define EVAS_CANVAS3D_OBJECT_EVENT_COLLISION (&(_EVAS_CANVAS3D_OBJECT_EVENT_COLLISION))

#endif
