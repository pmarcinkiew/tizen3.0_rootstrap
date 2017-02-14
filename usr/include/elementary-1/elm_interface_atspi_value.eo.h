#ifndef _ELM_INTERFACE_ATSPI_VALUE_EO_H_
#define _ELM_INTERFACE_ATSPI_VALUE_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_VALUE_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_VALUE_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Value;

#endif

#ifndef _ELM_INTERFACE_ATSPI_VALUE_EO_TYPES
#define _ELM_INTERFACE_ATSPI_VALUE_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_VALUE_INTERFACE elm_interface_atspi_value_interface_get()

EAPI const Eo_Class *elm_interface_atspi_value_interface_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_VALUE_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_value_and_text_set(double value, const char *text);
#endif

#ifdef ELM_INTERFACE_ATSPI_VALUE_PROTECTED
/**
 * @brief Gets value displayed by a accessible widget.
 *
 * @param[out] value Value of widget casted to floating point number.
 * @param[out] text string describing value in given context eg. small, enough
 *
 * @ingroup Elm_Interface_Atspi_Value
 */
EOAPI void  elm_interface_atspi_value_and_text_get(double *value, const char **text);
#endif

#ifdef ELM_INTERFACE_ATSPI_VALUE_PROTECTED
/**
 * @brief Gets a range of all possible values and its description
 *
 * @param[out] lower_limit
 * @param[out] upper_limit
 * @param[out] description
 *
 * @ingroup Elm_Interface_Atspi_Value
 */
EOAPI void  elm_interface_atspi_value_range_get(double *lower_limit, double *upper_limit, const char **description);
#endif

#ifdef ELM_INTERFACE_ATSPI_VALUE_PROTECTED
/** Gets an minimal incrementation value
 *
 * @ingroup Elm_Interface_Atspi_Value
 */
EOAPI double  elm_interface_atspi_value_increment_get(void);
#endif


#endif
