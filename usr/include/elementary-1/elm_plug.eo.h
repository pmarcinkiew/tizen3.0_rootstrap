#ifndef _ELM_PLUG_EO_H_
#define _ELM_PLUG_EO_H_

#ifndef _ELM_PLUG_EO_CLASS_TYPE
#define _ELM_PLUG_EO_CLASS_TYPE

typedef Eo Elm_Plug;

#endif

#ifndef _ELM_PLUG_EO_TYPES
#define _ELM_PLUG_EO_TYPES


#endif
#define ELM_PLUG_CLASS elm_plug_class_get()

EAPI const Eo_Class *elm_plug_class_get(void) EINA_CONST;

/**
 * @brief Get the basic Evas_Image object from this object (widget).
 *
 * This function allows one to get the underlying Evas object of type Image
 * from this elementary widget. It can be useful to do things like get the
 * pixel data, save the image to a file, etc.
 *
 * @note Be careful to not manipulate it, as it is under control of elementary.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The inlined image object or @c null.
 *
 * @ingroup Elm_Plug
 */
EOAPI Evas_Object * elm_obj_plug_image_object_get(void);

/**
 * @brief Connect a plug widget to service provided by socket image.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] svcnum The service number to connect to (set up by socket).
 * @param[in] svcsys Boolean to set if the service is a system one or not (set
 * up by socket).
 *
 * @return @c true on success, @c false on error.
 *
 * @ingroup Elm_Plug
 */
EOAPI Eina_Bool  elm_obj_plug_connect(const char *svcname, int svcnum, Eina_Bool svcsys);

EOAPI extern const Eo_Event_Description _ELM_PLUG_EVENT_IMAGE_DELETED;
EOAPI extern const Eo_Event_Description _ELM_PLUG_EVENT_IMAGE_RESIZED;

/**
 * No description
 */
#define ELM_PLUG_EVENT_IMAGE_DELETED (&(_ELM_PLUG_EVENT_IMAGE_DELETED))

/** ii
 *
 * @ingroup Elm_Plug
 */
#define ELM_PLUG_EVENT_IMAGE_RESIZED (&(_ELM_PLUG_EVENT_IMAGE_RESIZED))

#endif
