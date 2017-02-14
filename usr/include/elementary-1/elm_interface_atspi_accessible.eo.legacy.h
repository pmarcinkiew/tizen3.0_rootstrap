#ifndef _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_LEGACY_H_
#define _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_LEGACY_H_

#ifndef _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Accessible;

#endif

#ifndef _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_TYPES
#define _ELM_INTERFACE_ATSPI_ACCESSIBLE_EO_TYPES

/** The accessible Reading information type that can be read.
 *
 * @ingroup Elm_Accessible_Reading_Info
 */
typedef enum
{
  ELM_ACCESSIBLE_READING_INFO_TYPE_NAME = 1 /* 0 << 0 */, /** Name should be
                                                           * read */
  ELM_ACCESSIBLE_READING_INFO_TYPE_ROLE = 2 /* 0 << 0 */, /** Role should be
                                                           * read */
  ELM_ACCESSIBLE_READING_INFO_TYPE_DESCRIPTION = 4 /* 0 << 0 */, /** description should be read. */
  ELM_ACCESSIBLE_READING_INFO_TYPE_STATE = 8 /* 0 << 0 */ /** State should be
                                                           * read. */
} Elm_Accessible_Reading_Info_Type;


#endif

/**
 * @brief Defines the relationship between two accessible objects.
 *
 * Adds unique relation between source object and relation_object of a given
 * type.
 *
 * Relationships can be queried by Assistive Technology clients to provide
 * customized feedback, improving overall user experience.
 *
 * Relationship_append API is asymmetric, which means that appending, for
 * example, relation ELM_ATSPI_RELATION_FLOWS_TO from object A to B, do NOT
 * append relation ELM_ATSPI_RELATION_FLOWS_FROM from object B to object A.
 *
 * return: EINA_TRUE is relationship was successfully appended, EINA_FALSE
 * otherwise
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] relation_object
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Eina_Bool elm_atspi_accessible_relationship_append(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_Relation_Type type, const Elm_Interface_Atspi_Accessible *relation_object);

/**
 * @brief Removes the relationship between two accessible objects.
 *
 * If relation_object is NULL function removes all relations of given type.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] relation_object
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_relationship_remove(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_Relation_Type type, const Elm_Interface_Atspi_Accessible *relation_object);

/**
 * @brief Gets the translation domain of "name" and "description" properties.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return translation domain
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI const char *elm_atspi_accessible_translation_domain_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Sets the translation domain of "name" and "description" properties.
 *
 * Translation domain should be set if application wants to support i18n for
 * accessibily "name" and "description" properties.
 *
 * When translation domain is set values of "name" and "description" properties
 * will be translated with dgettext function using current translation domain
 * as "domainname" parameter.
 *
 * It is application developer responsibility to ensure that translation files
 * are loaded and binded to translation domain when accessibility is enabled.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] domain translation domain
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_translation_domain_set(Elm_Interface_Atspi_Accessible *obj, const char *domain);

/** Gets an localized string describing ATSPI widget role name.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI const char *elm_atspi_accessible_localized_role_name_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] name obj name
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_name_set(Elm_Interface_Atspi_Accessible *obj, const char *name);

/**
 * @brief Gets an string describing ATSPI widget role name.  Should be free by
 * a user.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return obj name
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI const char *elm_atspi_accessible_name_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Sets name information callback about widget.
 *
 * @param[in] name_cb
 * @param[in] data
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_name_cb_set(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_Reading_Info_Cb name_cb, const void *data);

/** Gets an string describing ATSPI widget role name. Lists and elements Should
 * be free by a user.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Atspi_Relation_Set elm_atspi_accessible_relation_set_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] role
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_role_set(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_Role role);

/**
 * @brief Gets the role of the widget in ATSPI Accessibility domain.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Atspi_Role elm_atspi_accessible_role_get(const Elm_Interface_Atspi_Accessible *obj);

/** Gets widget's accessible children.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Eina_List *elm_atspi_accessible_children_get(const Elm_Interface_Atspi_Accessible *obj);

/** Gets human-readable string indentifying widget accessibility role.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI const char *elm_atspi_accessible_role_name_get(const Elm_Interface_Atspi_Accessible *obj);

/** Gets key-value pairs identifying widget extra attributes. Must be free by a
 * user.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Eina_List *elm_atspi_accessible_attributes_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Gets reading information of an accessible object.
 *
 * @param[in] reading_info Access Reading information type
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_reading_info_type_set(Elm_Interface_Atspi_Accessible *obj, Elm_Accessible_Reading_Info_Type reading_info);

/**
 * @brief Gets reading information of an accessible object.
 *
 * @return Access Reading information type
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Accessible_Reading_Info_Type elm_atspi_accessible_reading_info_type_get(const Elm_Interface_Atspi_Accessible *obj);

/** Gets index of the child in parent's children list.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI int elm_atspi_accessible_index_in_parent_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Sets contextual information about widget.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] description
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_description_set(Elm_Interface_Atspi_Accessible *obj, const char *description);

/**
 * @brief Gets widget contextual information.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI const char *elm_atspi_accessible_description_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Sets contextual information callback about widget.
 *
 * @param[in] description_cb
 * @param[in] data
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_description_cb_set(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_Reading_Info_Cb description_cb, const void *data);

/**
 * @brief Sets widget accessible parent.
 *
 * @param[in] parent
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_parent_set(Elm_Interface_Atspi_Accessible *obj, Elm_Interface_Atspi_Accessible *parent);

/** Gets widget accessible parent.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Interface_Atspi_Accessible *elm_atspi_accessible_parent_get(const Elm_Interface_Atspi_Accessible *obj);

/** Gets set describing widget accessible states.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Atspi_State_Set elm_atspi_accessible_state_set_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Sets highlightable to given widget.
 *
 * @param[in] can_highlight
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_can_highlight_set(Elm_Interface_Atspi_Accessible *obj, Eina_Bool can_highlight);

/** Gets highlightable of given widget.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Eina_Bool elm_atspi_accessible_can_highlight_get(const Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Add key-value pair identifying widget extra attribute
 *
 * @param[in] value
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_attribute_append(Elm_Interface_Atspi_Accessible *obj, const char *key, const char *value);

/** Removes all attributes in accessible object.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_attributes_clear(Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Register accessibility event listener
 *
 * @param[in] data data
 *
 * @return Event handler
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI Elm_Atspi_Event_Handler *elm_atspi_accessible_event_handler_add(Eo_Event_Cb cb, void *data);

/**
 * @brief Deregister accessibility event listener
 *
 * @param[in] handler Event handler
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_event_handler_del(Elm_Atspi_Event_Handler *handler);
EAPI void elm_atspi_accessible_event_emit(Elm_Interface_Atspi_Accessible *accessible, const Eo_Event_Description *event, void *event_info);

/** Removes all relationships in accessible object.
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_relationships_clear(Elm_Interface_Atspi_Accessible *obj);

/**
 * @brief Notifies accessibility clients about current state of the accessibile
 * object.
 *
 * Function limits information broadcast to clients to types specified by
 * state_types_mask parameter.
 *
 * if recursive parameter is set, function will traverse all accessible
 * children and call state_notify function on them.
 *
 * @param[in] recursive
 *
 * @ingroup Elm_Interface_Atspi_Accessible
 */
EAPI void elm_atspi_accessible_state_notify(Elm_Interface_Atspi_Accessible *obj, Elm_Atspi_State_Set state_types_mask, Eina_Bool recursive);

#endif
