#ifndef _ELM_PAN_EO_LEGACY_H_
#define _ELM_PAN_EO_LEGACY_H_

#ifndef _ELM_PAN_EO_CLASS_TYPE
#define _ELM_PAN_EO_CLASS_TYPE

typedef Eo Elm_Pan;

#endif

#ifndef _ELM_PAN_EO_TYPES
#define _ELM_PAN_EO_TYPES


#endif
EAPI void elm_pan_pos_set(Elm_Pan *obj, Evas_Coord x, Evas_Coord y);
EAPI void elm_pan_pos_get(const Elm_Pan *obj, Evas_Coord *x, Evas_Coord *y);
EAPI void elm_pan_content_size_get(const Elm_Pan *obj, Evas_Coord *w, Evas_Coord *h);
EAPI void elm_pan_pos_min_get(const Elm_Pan *obj, Evas_Coord *x, Evas_Coord *y);
EAPI void elm_pan_pos_max_get(const Elm_Pan *obj, Evas_Coord *x, Evas_Coord *y);
EAPI void elm_pan_pos_adjust(Elm_Pan *obj, Evas_Coord *x, Evas_Coord *y);

#endif
