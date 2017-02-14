#ifndef _ELM_SEPARATOR_EO_H_
#define _ELM_SEPARATOR_EO_H_

#ifndef _ELM_SEPARATOR_EO_CLASS_TYPE
#define _ELM_SEPARATOR_EO_CLASS_TYPE

typedef Eo Elm_Separator;

#endif

#ifndef _ELM_SEPARATOR_EO_TYPES
#define _ELM_SEPARATOR_EO_TYPES


#endif
#define ELM_SEPARATOR_CLASS elm_separator_class_get()

EAPI const Eo_Class *elm_separator_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Set the horizontal mode of a separator object
 *
 * @param[in] horizontal If true, the separator is horizontal
 *
 * @ingroup Elm_Separator
 */
EOAPI void  elm_obj_separator_horizontal_set(Eina_Bool horizontal);

/**
 * @internal
 *
 * @brief Get the horizontal mode of a separator object
 *
 * @return If true, the separator is horizontal
 *
 * @ingroup Elm_Separator
 */
EOAPI Eina_Bool  elm_obj_separator_horizontal_get(void);


#endif
