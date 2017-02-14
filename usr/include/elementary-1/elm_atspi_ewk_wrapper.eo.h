#ifndef _ELM_ATSPI_EWK_WRAPPER_EO_H_
#define _ELM_ATSPI_EWK_WRAPPER_EO_H_

#ifndef _ELM_ATSPI_EWK_WRAPPER_EO_CLASS_TYPE
#define _ELM_ATSPI_EWK_WRAPPER_EO_CLASS_TYPE

typedef Eo Elm_Atspi_Ewk_Wrapper;

#endif

#ifndef _ELM_ATSPI_EWK_WRAPPER_EO_TYPES
#define _ELM_ATSPI_EWK_WRAPPER_EO_TYPES


#endif
#define ELM_ATSPI_EWK_WRAPPER_CLASS elm_atspi_ewk_wrapper_class_get()

EAPI const Eo_Class *elm_atspi_ewk_wrapper_class_get(void) EINA_CONST;

EOAPI Evas_Object * elm_obj_atspi_ewk_wrapper_ewk_view_get(void);

EOAPI void  elm_obj_atspi_ewk_wrapper_constructor(Evas_Object *ewk);

EOAPI void  elm_obj_atspi_ewk_wrapper_connection_init(void);

EOAPI void  elm_obj_atspi_ewk_wrapper_a11y_init(Evas_Object *parent, Evas_Object *ewk);


#endif
