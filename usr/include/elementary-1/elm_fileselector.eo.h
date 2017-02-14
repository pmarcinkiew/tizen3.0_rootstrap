#ifndef _ELM_FILESELECTOR_EO_H_
#define _ELM_FILESELECTOR_EO_H_

#ifndef _ELM_FILESELECTOR_EO_CLASS_TYPE
#define _ELM_FILESELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Fileselector;

#endif

#ifndef _ELM_FILESELECTOR_EO_TYPES
#define _ELM_FILESELECTOR_EO_TYPES


#endif
#define ELM_FILESELECTOR_CLASS elm_fileselector_class_get()

EAPI const Eo_Class *elm_fileselector_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Enable/disable the "ok" and "cancel" buttons on a
 * given file selector widget
 *
 * @note A file selector without those buttons will never emit the "done" smart
 * event, and is only usable if one is just hooking to the other two events.
 *
 * See also @ref elm_obj_fileselector_buttons_ok_cancel_get.
 *
 * @param[in] visible true to show buttons, false to hide.
 *
 * @ingroup Elm_Fileselector
 */
EOAPI void  elm_obj_fileselector_buttons_ok_cancel_set(Eina_Bool visible);

/**
 * @internal
 *
 * @brief Get whether the "ok" and "cancel" buttons on a
 * given file selector widget are being shown.
 *
 * See also @ref elm_obj_fileselector_buttons_ok_cancel_set for more details.
 *
 * @return true to show buttons, false to hide.
 *
 * @ingroup Elm_Fileselector
 */
EOAPI Eina_Bool  elm_obj_fileselector_buttons_ok_cancel_get(void);

EOAPI extern const Eo_Event_Description _ELM_FILESELECTOR_EVENT_DONE;
EOAPI extern const Eo_Event_Description _ELM_FILESELECTOR_EVENT_ACTIVATED;
EOAPI extern const Eo_Event_Description _ELM_FILESELECTOR_EVENT_SELECTED_INVALID;
EOAPI extern const Eo_Event_Description _ELM_FILESELECTOR_EVENT_DIRECTORY_OPEN;

/**
 * No description
 */
#define ELM_FILESELECTOR_EVENT_DONE (&(_ELM_FILESELECTOR_EVENT_DONE))

/**
 * No description
 */
#define ELM_FILESELECTOR_EVENT_ACTIVATED (&(_ELM_FILESELECTOR_EVENT_ACTIVATED))

/**
 * No description
 */
#define ELM_FILESELECTOR_EVENT_SELECTED_INVALID (&(_ELM_FILESELECTOR_EVENT_SELECTED_INVALID))

/**
 * No description
 */
#define ELM_FILESELECTOR_EVENT_DIRECTORY_OPEN (&(_ELM_FILESELECTOR_EVENT_DIRECTORY_OPEN))

#endif
