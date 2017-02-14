#ifndef _ELM_INTERFACE_ATSPI_SELECTION_EO_H_
#define _ELM_INTERFACE_ATSPI_SELECTION_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_SELECTION_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_SELECTION_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Selection;

#endif

#ifndef _ELM_INTERFACE_ATSPI_SELECTION_EO_TYPES
#define _ELM_INTERFACE_ATSPI_SELECTION_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_SELECTION_INTERFACE elm_interface_atspi_selection_interface_get()

EAPI const Eo_Class *elm_interface_atspi_selection_interface_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/** Gets the number of currently selected children
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI int  elm_interface_atspi_selection_selected_children_count_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/**
 * @brief Gets child for given child index
 *
 * @param[in] selected_child_index index of selected child
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eo * elm_interface_atspi_selection_selected_child_get(int selected_child_index);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/**
 * @brief Adds selection for given child index
 *
 * @param[in] child_index
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_child_select(int child_index);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/**
 * @brief Removes selection for given child index
 *
 * @param[in] child_index
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_selected_child_deselect(int child_index);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/**
 * @brief Determines if child specified by index is selected
 *
 * @param[in] child_index
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_is_child_selected(int child_index);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/** Adds selection for all children
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_all_children_select(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/** Clears the current selection
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_clear(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_SELECTION_PROTECTED
/**
 * @brief Removes selection for given child index
 *
 * @param[in] child_index
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
EOAPI Eina_Bool  elm_interface_atspi_selection_child_deselect(int child_index);
#endif

EOAPI extern const Eo_Event_Description _ELM_INTERFACE_ATSPI_SELECTION_EVENT_SELECTION_CHANGED;

/** Called when selection has been changed.
 *
 * @ingroup Elm_Interface_Atspi_Selection
 */
#define ELM_INTERFACE_ATSPI_SELECTION_EVENT_SELECTION_CHANGED (&(_ELM_INTERFACE_ATSPI_SELECTION_EVENT_SELECTION_CHANGED))

#endif
