#ifndef _ELM_CTXPOPUP_EO_H_
#define _ELM_CTXPOPUP_EO_H_

#ifndef _ELM_CTXPOPUP_EO_CLASS_TYPE
#define _ELM_CTXPOPUP_EO_CLASS_TYPE

typedef Eo Elm_Ctxpopup;

#endif

#ifndef _ELM_CTXPOPUP_EO_TYPES
#define _ELM_CTXPOPUP_EO_TYPES

/** Direction in which to show the popup.
 *
 * @ingroup Elm_Ctxpopup
 */
typedef enum
{
  ELM_CTXPOPUP_DIRECTION_DOWN = 0, /** Ctxpopup show appear below clicked area.
                                    */
  ELM_CTXPOPUP_DIRECTION_RIGHT, /** Ctxpopup show appear to the right of the
                                 * clicked area. */
  ELM_CTXPOPUP_DIRECTION_LEFT, /** Ctxpopup show appear to the left of the
                                * clicked area. */
  ELM_CTXPOPUP_DIRECTION_UP, /** Ctxpopup show appear above the clicked area.
                              */
  ELM_CTXPOPUP_DIRECTION_UNKNOWN /** Ctxpopup does not determine it's direction
                                  * yet. */
} Elm_Ctxpopup_Direction;


#endif
#define ELM_CTXPOPUP_CLASS elm_ctxpopup_class_get()

EAPI const Eo_Class *elm_ctxpopup_class_get(void) EINA_CONST;

/**
 * @brief Change the ctxpopup's orientation to horizontal or vertical.
 *
 * @param[in] horizontal @c true for horizontal mode, @c false for vertical.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_horizontal_set(Eina_Bool horizontal);

/**
 * @brief Get the value of current ctxpopup object's orientation.
 *
 * See also @ref elm_obj_ctxpopup_horizontal_set.
 *
 * @return @c true for horizontal mode, @c false for vertical.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI Eina_Bool  elm_obj_ctxpopup_horizontal_get(void);

/**
 * @brief Set ctxpopup auto hide mode triggered by ctxpopup policy.
 *
 * Use this function when user wants ctxpopup not to hide automatically. By
 * default, ctxpopup is dismissed whenever mouse clicked its background area,
 * language is changed, and its parent geometry is updated(changed). Not to
 * hide ctxpopup automatically, disable auto hide function by calling this API,
 * then ctxpopup won't be dismissed in those scenarios.
 *
 * Default value of disabled is @c false.
 *
 * See also @ref elm_obj_ctxpopup_auto_hide_disabled_get.
 *
 * @param[in] disabled auto hide enable/disable.
 *
 * @since 1.9
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_auto_hide_disabled_set(Eina_Bool disabled);

/**
 * @brief Get ctxpopup auto hide mode triggered by ctxpopup policy.
 *
 * See also @ref elm_obj_ctxpopup_auto_hide_disabled_set for more information.
 *
 * @return auto hide enable/disable.
 *
 * @since 1.9
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI Eina_Bool  elm_obj_ctxpopup_auto_hide_disabled_get(void);

/**
 * @brief Set the Ctxpopup's parent
 *
 * Set the parent object.
 *
 * @note @ref elm_ctxpopup_add will automatically call this function with its
 * @c parent argument.
 *
 * See also @ref elm_ctxpopup_add, @ref elm_hover_parent_set.
 *
 * @param[in] parent The parent to use.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_hover_parent_set(Evas_Object *parent);

/**
 * @brief Get the Ctxpopup's parent
 *
 * See also @ref elm_obj_ctxpopup_hover_parent_set for more information
 *
 * @return The parent to use.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI Evas_Object * elm_obj_ctxpopup_hover_parent_get(void);

/**
 * @brief Set the direction priority of a ctxpopup.
 *
 * This functions gives a chance to user to set the priority of ctxpopup
 * showing direction. This doesn't guarantee the ctxpopup will appear in the
 * requested direction.
 *
 * See also @ref Elm_Ctxpopup_Direction.
 *
 * @param[in] first 1st priority of direction
 * @param[in] second 2nd priority of direction
 * @param[in] third 3th priority of direction
 * @param[in] fourth 4th priority of direction
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_direction_priority_set(Elm_Ctxpopup_Direction first, Elm_Ctxpopup_Direction second, Elm_Ctxpopup_Direction third, Elm_Ctxpopup_Direction fourth);

/**
 * @brief Get the direction priority of a ctxpopup.
 *
 * See also @ref elm_obj_ctxpopup_direction_priority_set for more information.
 *
 * @param[out] first 1st priority of direction
 * @param[out] second 2nd priority of direction
 * @param[out] third 3th priority of direction
 * @param[out] fourth 4th priority of direction
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_direction_priority_get(Elm_Ctxpopup_Direction *first, Elm_Ctxpopup_Direction *second, Elm_Ctxpopup_Direction *third, Elm_Ctxpopup_Direction *fourth);

/**
 * @brief Get the current direction of a ctxpopup.
 *
 * @warning Once the ctxpopup showed up, the direction would be determined
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI Elm_Ctxpopup_Direction  elm_obj_ctxpopup_direction_get(void);

/**
 * @brief Dismiss a ctxpopup object
 *
 * Use this function to simulate clicking outside of the ctxpopup to dismiss
 * it. In this way, the ctxpopup will be hidden and the "clicked" signal will
 * be emitted.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_dismiss(void);

/** Clear all items in the given ctxpopup object.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI void  elm_obj_ctxpopup_clear(void);

/**
 * @brief Add a new item to a ctxpopup object.
 *
 * Warning:Ctxpopup can't hold both an item list and a content at the same
 * time. When an item is added, any previous content will be removed.
 *
 * See also @ref elm_object_content_set.
 *
 * @param[in] icon Icon to be set on new item
 * @param[in] func Convenience function called when item selected
 * @param[in] data Data passed to @c func
 *
 * @return A handle to the item added or @c null, on errors.
 *
 * @ingroup Elm_Ctxpopup
 */
EOAPI Elm_Widget_Item * elm_obj_ctxpopup_item_append(const char *label, Evas_Object *icon, Evas_Smart_Cb func, const void *data);

EOAPI extern const Eo_Event_Description _ELM_CTXPOPUP_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CTXPOPUP_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_CTXPOPUP_EVENT_FOCUSED;
EOAPI extern const Eo_Event_Description _ELM_CTXPOPUP_EVENT_UNFOCUSED;
EOAPI extern const Eo_Event_Description _ELM_CTXPOPUP_EVENT_DISMISSED;

/**
 * No description
 */
#define ELM_CTXPOPUP_EVENT_LANGUAGE_CHANGED (&(_ELM_CTXPOPUP_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_CTXPOPUP_EVENT_ACCESS_CHANGED (&(_ELM_CTXPOPUP_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_CTXPOPUP_EVENT_FOCUSED (&(_ELM_CTXPOPUP_EVENT_FOCUSED))

/**
 * No description
 */
#define ELM_CTXPOPUP_EVENT_UNFOCUSED (&(_ELM_CTXPOPUP_EVENT_UNFOCUSED))

/**
 * No description
 */
#define ELM_CTXPOPUP_EVENT_DISMISSED (&(_ELM_CTXPOPUP_EVENT_DISMISSED))

#endif
