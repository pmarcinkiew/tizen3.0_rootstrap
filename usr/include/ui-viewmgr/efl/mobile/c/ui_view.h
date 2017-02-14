#ifndef _UI_VIEW_CAPI_H_
#define _UI_VIEW_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_VIEW UI View
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_view.
 * @{
 */

/**
 * @brief The ui_view event callback function signature.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view instance
 * @param[in] degree Current view's degree
 * @param[in] data The user data to be passed to the given @a event_callback functions
 *
 * @return This is reserved
 *
 * @see ui_view_event_type_e
 * @see ui_view_set_event_cb
 */
typedef bool (*ui_view_event_cb)(ui_view *view, void *user_data);

/**
 * @brief Enumeration for ui_view event type.
 * @since_tizen 3.0
 */
typedef enum
{
	UI_VIEW_EVENT_LOAD = 0,          /**< Load */
	UI_VIEW_EVENT_UNLOAD,            /**< Unload */
	UI_VIEW_EVENT_PAUSE,             /**< Pause */
	UI_VIEW_EVENT_RESUME,            /**< Resume */
	UI_VIEW_EVENT_ACTIVATE,          /**< Activate */
	UI_VIEW_EVENT_DEACTIVATE,        /**< Deactivate */
	UI_VIEW_EVENT_DESTROY,           /**< Destroy */

	UI_VIEW_EVENT_LOAD_POST,         /**< Load post */
	UI_VIEW_EVENT_UNLOAD_POST,       /**< Unload post */
	UI_VIEW_EVENT_PAUSE_POST,        /**< Pause post */
	UI_VIEW_EVENT_RESUME_POST,       /**< Resume post */
	UI_VIEW_EVENT_ACTIVATE_POST,     /**< Activate post */
	UI_VIEW_EVENT_DEACTIVATE_POST,   /**< Deactivate post */
	UI_VIEW_EVENT_DESTROY_POST,      /**< Destroy post */

	UI_VIEW_EVENT_ROTATE,            /**< Rotate */
	UI_VIEW_EVENT_PORTRAIT,          /**< Portrait */
	UI_VIEW_EVENT_LANDSCAPE,         /**< Landscape */
	UI_VIEW_EVENT_BACK,              /**< Back */
	UI_VIEW_EVENT_MENU,              /**< Menu */

	UI_VIEW_EVENT_ROTATE_POST,       /**< Rotate post */
	UI_VIEW_EVENT_PORTRAIT_POST,     /**< Portrait post */
	UI_VIEW_EVENT_LANDSCAPE_POST,    /**< Landscape post */
	UI_VIEW_EVENT_BACK_POST,         /**< Back post */
	UI_VIEW_EVENT_MENU_POST          /**< Menu post */
} ui_view_event_type_e;

/**
 * @brief Creates an ui_view.
 * @since_tizen 3.0
 * @remarks if you don't set a view name, you could not look up the view with it's name.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] name view name
 *
 * @return The ui_view instance. @c NULL if failed
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_OUT_OF_MEMORY Fail to create new instance
 *
 * @see ui_view_destroy()
 * @see ui_viewmgr_get_view_by_name()
 * @see get_last_result()
 */
EAPI ui_view *ui_view_create(const char *name);

/**
 * @brief Replaces or set a content of ui_view.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view instance
 * @param[in] content A new content. It allows @c NULL for canceling the previous content
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 *
 * @see ui_view_get_content()
 * @see ui_view_unset_content()
 */
EAPI int ui_view_set_content(ui_view *view, Eo *content);

/**
 * @brief Returns a content of this view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return content of @a view. If no contents set yet, @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_set_content()
 * @see ui_view_unset_content()
 * @see get_last_result()
 */
EAPI Eo *ui_view_get_content(const ui_view *view);

/**
 * @brief Unsets a ui_view content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_set_content()
 * @see ui_view_get_content()
 * @see get_last_result()
 */
EAPI Eo *ui_view_unset_content(ui_view *view);

/**
 * @brief Sets callback functions for handling view events.
 * @since_tizen 3.0
 * @remarks To unset the events, you can pass @c NULL to @a event_cb.
 *
 * @param[in] view An ui_view instance
 * @param[in] event_type ui_view event type
 * @param[in] event_cb The set of callback functions to handle view events
 * @param[in] user_data The user data to be passed to the given @a event_callback functions
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 *
 * @see ui_view_event_type_e
 */
EAPI int ui_view_set_event_cb(ui_view *view, ui_view_event_type_e event_type, ui_view_event_cb event_cb, void *user_data);

/**
 * @brief Gets a base object of ui_view.
 * @since_tizen 3.0
 * @remarks Normally, this base object can be used for a parent of a view content.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return The base object of ui_view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see get_last_result()
 */
EAPI Eo* ui_view_get_base(const ui_view *view);

/**
 * @brief Sets the indicator mode of a ui_view.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view instance
 * @param[in] indicator The mode to set, one of #ui_view_indicator
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER Invalid Parameters
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED Current view manager system is not set up
 *
 * @see ui_view_indicator
 * @see ui_view_get_indicator()
 */
EAPI int ui_view_set_indicator(ui_view *view, ui_view_indicator indicator);

/**
 * @brief Returns the indicator mode of this view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param view An ui_view instance
 *
 * @return indicator state of the given @a view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_get_indicator()
 * @see get_last_result()
 */
EAPI ui_view_indicator ui_view_get_indicator(const ui_view *view);

/**
 * @brief Sets the array of view's available rotations.
 * @since_tizen 3.0
 * @remarks Set an array of rotation values.
 *          For instance, {0, 90, 180, 270}. These rotation values depends on the system support.
 *
 * @param[in] view An ui_view instance
 * @param[in] rotations The array of rotation values
 * @param[in] count The number of arrays of rotations
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER If @a view is invalid or @a count is less than 1 or @a rotations is invalid pointer
 * @retval #UI_VIEWMGR_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED Current view manager system is not set up
 *
 * @see ui_view_get_available_rotations()
 */
EAPI int ui_view_set_available_rotations(ui_view *view, const int *rotations, unsigned int count);

/**
 * @brief Gets the array of view's available rotations.
 * @since_tizen 3.0
 * @remarks @c NULL will be returned if @a view or @a count is invalid.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 * @param[out] count The number of arrays of rotations
 *
 * @return The array of rotation values
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_set_available_rotations()
 * @see get_last_result()
 */
EAPI const int *ui_view_get_available_rotations(const ui_view *view, unsigned int *count);

/**
 * @brief Sets content removable.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view instance
 * @param[in] removable if @a removable is @c true, content of this view will be removed on unload state. @c false otherwise
 *
 * @warning You should not remove a view content manually on unload status if removable content is set
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER If @a view is invalid or @a count is less than 1 or @a rotations is invalid pointer
 *
 * @see ui_view_get_removable_content()
 */
EAPI int ui_view_set_removable_content(ui_view *view, bool removable);

/**
 * @brief Returns a state of removable content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return @c true if the view's content is removable, otherwise @c false
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_get_removable_content()
 * @see get_last_result()
 */
EAPI bool ui_view_get_removable_content(const ui_view *view);

/**
 * @brief Gets the current view's degree.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return Current rotation degree, -1 if it fails to get degree information
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see get_last_result()
 */
EAPI int ui_view_get_degree(const ui_view *view);

/**
 * @brief Gets current view's orientation mode.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return Current orientation mode, one of #ui_view_orientation_mode
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_orientation_mode
 * @see get_last_result()
 */
EAPI ui_view_orientation_mode ui_view_get_orientation_mode(const ui_view *view);

/**
 * @brief Sets transition style of a view.
 * @since_tizen 3.0
 *
 * @remarks @a style is reserved for supporting various kinds of view transition effects.
 *          The actual behaviors with this transition style is up to your frameworks. Default value of the style is NULL.
 *          and "none" represents none transition. If you don't like give any transition effects to this view, you can pass "none" as @a style.
 *
 * @param[in] view An ui_view instance
 * @param[in] style a transition style name
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid or @a style is not supported
 *
 * @see ui_view_get_transition_style()
 */
EAPI int ui_view_set_transition_style(ui_view *view, const char *style);

/**
 * @brief Returns a style name of this view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return style name of view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_set_transition_style()
 * @see get_last_result()
 */
EAPI const char *ui_view_get_transition_style(const ui_view *view);

/**
 * @brief Gets a ui_menu instance.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return The ui_menu that connected with given @a view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see get_last_result()
 */
EAPI ui_menu *ui_view_get_menu(const ui_view *view);

/**
 * @brief Returns a name of this view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return name of @a view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see get_last_result()
 */
EAPI const char *ui_view_get_name(const ui_view *view);

/**
 * @brief Returns a state of this view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_view instance
 *
 * @return current state of @a view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_state
 * @see get_last_result()
 */
EAPI ui_view_state ui_view_get_state(const ui_view *view);

/**
 * @brief Destroys an ui_view.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view instance
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_view_create()
 * @see ui_standard_view_create()
 */
EAPI int ui_view_destroy(ui_view *view);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _UI_VIEW_CAPI_H_ */
