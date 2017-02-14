#ifndef _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_H_
#define _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Editable_Text;

#endif

#ifndef _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_TYPES
#define _ELM_INTERFACE_ATSPI_EDITABLE_TEXT_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_EDITABLE_TEXT_INTERFACE elm_interface_atspi_editable_text_interface_get()

EAPI const Eo_Class *elm_interface_atspi_editable_text_interface_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_content_set(const char *string);
#endif

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_insert(const char *string, int position);
#endif

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_copy(int start, int end);
#endif

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_cut(int start, int end);
#endif

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_delete(int start, int end);
#endif

#ifdef ELM_INTERFACE_ATSPI_EDITABLE_TEXT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_editable_text_paste(int position);
#endif


#endif
