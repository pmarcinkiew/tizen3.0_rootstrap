#ifndef _ELM_CONTAINER_EO_H_
#define _ELM_CONTAINER_EO_H_

#ifndef _ELM_CONTAINER_EO_CLASS_TYPE
#define _ELM_CONTAINER_EO_CLASS_TYPE

typedef Eo Elm_Container;

#endif

#ifndef _ELM_CONTAINER_EO_TYPES
#define _ELM_CONTAINER_EO_TYPES


#endif
#define ELM_CONTAINER_CLASS elm_container_class_get()

EAPI const Eo_Class *elm_container_class_get(void) EINA_CONST;

/**
 * @brief Swallow the given object into the given part of the container.
 *
 * @param[in] content the object to swallow.
 *
 * @ingroup Elm_Container
 */
EOAPI Eina_Bool  elm_obj_container_content_set(const char *name, Evas_Object *content);

/**
 * @brief Unswallow the object in the given part of the container and return
 * it.
 *
 * @param[in] name
 *
 * @ingroup Elm_Container
 */
EOAPI Evas_Object * elm_obj_container_content_unset(const char *name);

/**
 * @brief Get the object swallowed in the given part of the container.
 *
 * @param[in] name the part in which the object is swallowed.
 *
 * @ingroup Elm_Container
 */
EOAPI Evas_Object * elm_obj_container_content_get(const char *name);

/**
 * @brief Get the list of swallow parts in the object.
 *
 * @return list
 *
 * @ingroup Elm_Container
 */
EOAPI Eina_List * elm_obj_container_content_swallow_list_get(void);


#endif
