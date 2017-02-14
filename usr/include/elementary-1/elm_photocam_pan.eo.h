#ifndef _ELM_PHOTOCAM_PAN_EO_H_
#define _ELM_PHOTOCAM_PAN_EO_H_

#ifndef _ELM_PHOTOCAM_PAN_EO_CLASS_TYPE
#define _ELM_PHOTOCAM_PAN_EO_CLASS_TYPE

typedef Eo Elm_Photocam_Pan;

#endif

#ifndef _ELM_PHOTOCAM_PAN_EO_TYPES
#define _ELM_PHOTOCAM_PAN_EO_TYPES


#endif
#define ELM_PHOTOCAM_PAN_CLASS elm_photocam_pan_class_get()

EAPI const Eo_Class *elm_photocam_pan_class_get(void) EINA_CONST;

EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_LOAD;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_LOADED;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_LOAD_DETAIL;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_LOADED_DETAIL;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_START;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_PROGRESS;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_DONE;
EOAPI extern const Eo_Event_Description _ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_ERROR;

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_LOAD (&(_ELM_PHOTOCAM_PAN_EVENT_LOAD))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_LOADED (&(_ELM_PHOTOCAM_PAN_EVENT_LOADED))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_LOAD_DETAIL (&(_ELM_PHOTOCAM_PAN_EVENT_LOAD_DETAIL))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_LOADED_DETAIL (&(_ELM_PHOTOCAM_PAN_EVENT_LOADED_DETAIL))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_START (&(_ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_START))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_PROGRESS (&(_ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_PROGRESS))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_DONE (&(_ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_DONE))

/**
 * No description
 */
#define ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_ERROR (&(_ELM_PHOTOCAM_PAN_EVENT_DOWNLOAD_ERROR))

#endif
