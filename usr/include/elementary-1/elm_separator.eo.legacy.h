#ifndef _ELM_SEPARATOR_EO_LEGACY_H_
#define _ELM_SEPARATOR_EO_LEGACY_H_

#ifndef _ELM_SEPARATOR_EO_CLASS_TYPE
#define _ELM_SEPARATOR_EO_CLASS_TYPE

typedef Eo Elm_Separator;

#endif

#ifndef _ELM_SEPARATOR_EO_TYPES
#define _ELM_SEPARATOR_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief Set the horizontal mode of a separator object
 *
 * @param[in] horizontal If true, the separator is horizontal
 *
 * @ingroup Elm_Separator
 */
EAPI void elm_separator_horizontal_set(Elm_Separator *obj, Eina_Bool horizontal);

/**
 * @internal
 *
 * @brief Get the horizontal mode of a separator object
 *
 * @return If true, the separator is horizontal
 *
 * @ingroup Elm_Separator
 */
EAPI Eina_Bool elm_separator_horizontal_get(const Elm_Separator *obj);

#endif
