#ifndef _ELM_INWIN_EO_H_
#define _ELM_INWIN_EO_H_

#ifndef _ELM_INWIN_EO_CLASS_TYPE
#define _ELM_INWIN_EO_CLASS_TYPE

typedef Eo Elm_Inwin;

#endif

#ifndef _ELM_INWIN_EO_TYPES
#define _ELM_INWIN_EO_TYPES


#endif
#define ELM_INWIN_CLASS elm_inwin_class_get()

EAPI const Eo_Class *elm_inwin_class_get(void) EINA_CONST;

/**
 * @brief Activates an inwin object, ensuring its visibility
 *
 * This function will make sure that the inwin @c obj is completely visible by
 * calling evas_object_show() and evas_object_raise() on it, to bring it to the
 * front. It also sets the keyboard focus to it, which will be passed onto its
 * content.
 *
 * The object's theme will also receive the signal "elm,action,show" with
 * source "elm".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Inwin
 */
EOAPI void  elm_obj_win_inwin_activate(void);


#endif
