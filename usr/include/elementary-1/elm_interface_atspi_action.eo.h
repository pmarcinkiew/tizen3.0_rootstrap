#ifndef _ELM_INTERFACE_ATSPI_ACTION_EO_H_
#define _ELM_INTERFACE_ATSPI_ACTION_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_ACTION_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_ACTION_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Action;

#endif

#ifndef _ELM_INTERFACE_ATSPI_ACTION_EO_TYPES
#define _ELM_INTERFACE_ATSPI_ACTION_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_ACTION_MIXIN elm_interface_atspi_action_mixin_get()

EAPI const Eo_Class *elm_interface_atspi_action_mixin_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Performs action on given widget.
 *
 * @param[in] id
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI Eina_Bool  elm_interface_atspi_action_do(int id);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Gets configured keybinding for specific action and widget.
 *
 * @param[in] id
 *
 * @return Should be freed by the user.
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI char * elm_interface_atspi_action_keybinding_get(int id);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Gets action name for given id
 *
 * @param[in] id
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI const char * elm_interface_atspi_action_name_get(int id);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
EOAPI void  elm_interface_atspi_action_name_set(int id, const char *name);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Gets action description for given id
 *
 * @param[in] id
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI const char * elm_interface_atspi_action_description_get(int id);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Sets action description for given id
 *
 * @param[in] id
 * @param[in] description
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI Eina_Bool  elm_interface_atspi_action_description_set(int id, const char *description);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Get list of available widget actions
 *
 * @return contains statically allocated strings
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI Eina_List * elm_interface_atspi_action_actions_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_ACTION_PROTECTED
/**
 * @brief Gets localized action name for given id
 *
 * @param[in] id
 *
 * @ingroup Elm_Interface_Atspi_Action
 */
EOAPI const char * elm_interface_atspi_action_localized_name_get(int id);
#endif


#endif
