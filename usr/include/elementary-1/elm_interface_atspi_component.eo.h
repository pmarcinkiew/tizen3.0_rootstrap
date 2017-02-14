#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_H_
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Component;

#endif

#ifndef _ELM_INTERFACE_ATSPI_COMPONENT_EO_TYPES
#define _ELM_INTERFACE_ATSPI_COMPONENT_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_COMPONENT_MIXIN elm_interface_atspi_component_mixin_get()

EAPI const Eo_Class *elm_interface_atspi_component_mixin_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Sets size of accessible widget.
 *
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_size_set(int w, int h);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets size of accessible widget.
 *
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI void  elm_interface_atspi_component_size_get(int *w, int *h);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/** Sets evas layer of accessible widget.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI int  elm_interface_atspi_component_layer_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets alpha of accessible widget.
 *
 * @return alpha value in [0, 1] range.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI double  elm_interface_atspi_component_alpha_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/** Gets the depth at which the component is shown in relation to other
 * components in the same container.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI int  elm_interface_atspi_component_z_order_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Sets geometry of accessible widget.
 *
 * @param[in] screen_coords If true x and y values will be relative to screen
 * origin, otherwise relative to canvas
 * @param[in] x
 * @param[in] y
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_extents_set(Eina_Bool screen_coords, int x, int y, int w, int h);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets geometry of accessible widget.
 *
 * @param[in] screen_coords If true x and y values will be relative to screen
 * origin, otherwise relative to canvas
 * @param[out] x
 * @param[out] y
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI void  elm_interface_atspi_component_extents_get(Eina_Bool screen_coords, int *x, int *y, int *w, int *h);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Sets position of accessible widget.
 *
 * @param[in] screen_coords If true x and y values will be relative to screen
 * origin, otherwise relative to canvas
 * @param[in] x
 * @param[in] y
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_position_set(Eina_Bool screen_coords, int x, int y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets position of accessible widget.
 *
 * @param[in] screen_coords If true x and y values will be relative to screen
 * origin, otherwise relative to canvas
 * @param[out] x
 * @param[out] y
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI void  elm_interface_atspi_component_position_get(Eina_Bool screen_coords, int *x, int *y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Sets position of socket offset.
 *
 * @param[in] x
 * @param[in] y
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI void  elm_interface_atspi_component_socket_offset_set(int x, int y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets position of socket offset.
 *
 * @param[out] x
 * @param[out] y
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI void  elm_interface_atspi_component_socket_offset_get(int *x, int *y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
EOAPI Eina_Bool  elm_interface_atspi_component_contains(Eina_Bool screen_coords, int x, int y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Focuses accessible widget.
 *
 * @return true if focus grab focus has successed, false otherwise.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_focus_grab(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/**
 * @brief Gets top component object occupying space at given coordinates.
 *
 * @param[in] x
 * @param[in] y
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eo * elm_interface_atspi_component_accessible_at_point_get(Eina_Bool screen_coords, int x, int y);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/** Highlights accessible widget. returns true if highlight grab has successed,
 * false otherwise.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_highlight_grab(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_COMPONENT_PROTECTED
/** Clears highlight of accessible widget. returns true if clear has successed,
 * false otherwise.
 *
 * @ingroup Elm_Interface_Atspi_Component
 */
EOAPI Eina_Bool  elm_interface_atspi_component_highlight_clear(void);
#endif


#endif
