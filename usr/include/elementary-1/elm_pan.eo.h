#ifndef _ELM_PAN_EO_H_
#define _ELM_PAN_EO_H_

#ifndef _ELM_PAN_EO_CLASS_TYPE
#define _ELM_PAN_EO_CLASS_TYPE

typedef Eo Elm_Pan;

#endif

#ifndef _ELM_PAN_EO_TYPES
#define _ELM_PAN_EO_TYPES


#endif
#define ELM_PAN_CLASS elm_pan_class_get()

EAPI const Eo_Class *elm_pan_class_get(void) EINA_CONST;

EOAPI void  elm_obj_pan_pos_set(Evas_Coord x, Evas_Coord y);

EOAPI void  elm_obj_pan_pos_get(Evas_Coord *x, Evas_Coord *y);

EOAPI void  elm_obj_pan_content_size_get(Evas_Coord *w, Evas_Coord *h);

EOAPI void  elm_obj_pan_pos_min_get(Evas_Coord *x, Evas_Coord *y);

EOAPI void  elm_obj_pan_pos_max_get(Evas_Coord *x, Evas_Coord *y);

EOAPI void  elm_obj_pan_pos_adjust(Evas_Coord *x, Evas_Coord *y);

EOAPI extern const Eo_Event_Description _ELM_PAN_EVENT_CHANGED;

/**
 * No description
 */
#define ELM_PAN_EVENT_CHANGED (&(_ELM_PAN_EVENT_CHANGED))

#endif
