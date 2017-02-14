#ifndef _UI_STANDARD_VIEW_CAPI_H_
#define _UI_STANDARD_VIEW_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_STANDARD_VIEW UI Standard View
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_standard_view.
 * @{
 */

/**
 * @brief Creates an ui_standard_view.
 * @since_tizen 3.0
 * @remarks if you don't set a view name, you could not look up the view with it's name.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] name view name
 *
 * @return The ui_view instance. NULL if failed
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_OUT_OF_MEMORY Fail to create new instance
 *
 * @see ui_view_destroy()
 * @see ui_viewmgr_get_view_by_name()
 * @see get_last_result()
 */
EAPI ui_standard_view *ui_standard_view_create(const char *name);

/**
 * @brief Sets a title text.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] text The label in the title area
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title()
 */
EAPI int ui_standard_view_set_title(ui_standard_view *view, const char *text);

/**
 * @brief Sets a subtitle text.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] text The label in the subtitle area
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_sub_title()
 */
EAPI int ui_standard_view_set_sub_title(ui_standard_view *view, const char *text);

/**
 * @brief Sets a title badge text.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] badge_text The label in the title badge area
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title_badge()
 */
EAPI int ui_standard_view_set_title_badge(ui_standard_view *view, const char *badge_text);

/**
 * @brief Sets a title_right_btn.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] title_right_btn The button in the right part of title area
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS if @a title_right_btn is same with the existing one
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title_right_btn()
 * @see ui_standard_view_unset_title_right_btn()
 */
EAPI int ui_standard_view_set_title_right_btn(ui_standard_view *view, Elm_Button *title_right_btn);

/**
 * @brief Returns a title right button of the view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 *
 * @return title right button of the view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_standard_view_set_title_right_btn()
 * @see ui_standard_view_unset_title_right_btn()
 * @see get_last_result()
 */
EAPI Elm_Button *ui_standard_view_get_title_right_btn(const ui_standard_view *view);

/**
 * @brief Unsets a title right button of title area.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 * @exception #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title_right_btn()
 * @see ui_standard_view_set_title_right_btn()
 * @see get_last_result()
 */
EAPI Elm_Button *ui_standard_view_unset_title_right_btn(ui_standard_view *view);

/**
 * @brief Sets a title_left_btn.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] title_left_btn The button in the left part of title area
 *
 * @return @c 0 on success, otherwise a negative error value.
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS if @a title_left_btn is same with the existing one
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title_left_btn()
 * @see ui_standard_view_unset_title_left_btn()
 */
EAPI int ui_standard_view_set_title_left_btn(ui_standard_view *view, Elm_Button *title_left_btn);

/**
 * @brief Returns a title left button of the view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @return title left button of the view
 *
 * @see ui_standard_view_set_title_left_btn()
 * @see ui_standard_view_unset_title_left_btn()
 * @see get_last_result()
 */
EAPI Elm_Button *ui_standard_view_get_title_left_btn(const ui_standard_view *view);

/**
 * @brief Unsets a title left button of title area.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 * @exception #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_title_left_btn()
 * @see ui_standard_view_set_title_left_btn()
 * @see get_last_result()
 */
EAPI Elm_Button *ui_standard_view_unset_title_left_btn(ui_standard_view *view);

/**
 * @brief Sets a toolbar below title.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] toolbar Toolbar object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS if @a toolbar is already existing
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 *
 * @see ui_standard_view_get_toolbar()
 * @see ui_standard_view_unset_toolbar()
 * @see get_last_result()
 */
EAPI int ui_standard_view_set_toolbar(ui_standard_view *view, Elm_Toolbar *toolbar);

/**
 * @brief Returns a toolbar of the view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 *
 * @return The toolbar of the given @a view
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_standard_view_set_toolbar()
 * @see ui_standard_view_unset_toolbar()
 * @see get_last_result()
 */
EAPI Elm_Toolbar *ui_standard_view_get_toolbar(const ui_standard_view *view);

/**
 * @brief Unsets a toolbar.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An ui_standard_view instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is invalid
 *
 * @see ui_standard_view_get_toolbar()
 * @see ui_standard_view_set_toolbar()
 * @see get_last_result()
 */
EAPI Elm_Toolbar *ui_standard_view_unset_toolbar(ui_standard_view *view);

/**
 * @brief Controls the title visible state.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_standard_view instance
 * @param[in] visible title state set as visible if the given param is @c true, otherwise title area set as invisible
 * @param[in] anim title area will be shown with animation if the given param is @c true, otherwise title area will be shown without animation
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER if @a view is invalid
 * @retval #UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE Instance is corrupted. Maybe base object is broken
 */
EAPI int ui_standard_view_set_title_visible(ui_standard_view *view, bool visible, bool anim);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _UI_STANDARD_VIEW_CAPI_H_ */
