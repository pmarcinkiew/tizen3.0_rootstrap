#ifndef _UI_POPUP_CAPI_H_
#define _UI_POPUP_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_POPUP UI Popup
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_popup.
 * @{
 */

/**
 * @brief Creates an ui_popup.
 * @since_tizen 3.0
 * @remarks The instance of ui_popup is subordinated to the given @a ui_view. If the given @a ui_view is hidden or deactivated, this ui_popup will be also do
 *          same followed to its ui_view behaviors. The instance of ui_popup will be destroyed automatically when the ui_view is destroyed.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] view An instance of ui_view
 *
 * @return An ui_popup instance
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_OUT_OF_MEMORY Fail to create new instance
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_destroy()
 */
EAPI ui_popup *ui_popup_create(ui_view *view);

/**
 * @brief Destroys an ui_popup.
 * @details destroy an @a given ui_popup instance.
 * @since_tizen 3.0
 *
 * @param[in] popup An ui_popup instance
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_create()
 */
EAPI int ui_popup_destroy(ui_popup *popup);

/**
 * @brief Replaces or set a content of an ui_popup.
 * @since_tizen 3.0
 *
 * @param[in] popup An ui_popup instance
 * @param[in] content popup object. It allows @c NULL for canceling the previous content
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid or @a content is not a type of Elm_Popup
 *
 * @see ui_popup_get_content()
 * @see ui_popup_unset_content()
 */
EAPI int ui_popup_set_content(ui_popup *popup, Elm_Popup *content);

/**
 * @brief Returns a content object of ui_popup.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return A content of ui_popup
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_set_content()
 * @see ui_popup_unset_content()
 * @see get_last_result()
 */
EAPI Elm_Popup *ui_popup_get_content(const ui_popup *popup);

/**
 * @brief Unsets an ui_popup content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_get_content()
 * @see ui_popup_set_content()
 * @see get_last_result()
 */
EAPI Elm_Popup *ui_popup_unset_content(ui_popup *popup);

/**
 * @brief Activates an ui_popup.
 * @details It makes ui_popup state as show.
 * @since_tizen 3.0
 *
 * @param[in] popup An ui_popup instance
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED popup instance is not set up yet
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_deactivate()
 * @see ui_popup_get_activated()
 */
EAPI int ui_popup_activate(ui_popup *popup);

/**
 * @brief Deactivates an ui_popup.
 * @details It makes ui_popup state as hide.
 * @since_tizen 3.0
 *
 * @param[in] popup An ui_popup instance
 *
 * @return @c 0 on success, otherwise a negative error value.
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED popup instance is not set up yet
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_activate()
 * @see ui_popup_get_activated()
 */
EAPI int ui_popup_deactivate(ui_popup *popup);

/**
 * @brief Returns the active status of ui_popup.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return @c true if ui_popup is activated, @c false otherwise
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see ui_popup_activate()
 * @see ui_popup_deactivate()
 * @see get_last_result()
 */
EAPI bool ui_popup_get_activated(const ui_popup *popup);

/**
 * @brief Gets a base object of an ui_popup.
 * @details Normally, A base object can be used for a parent of ui_popup content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return base object of popup
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see get_last_result()
 */
EAPI Eo *ui_popup_get_base(const ui_popup *popup);

/**
 * @brief Gets current ui_popup's degree.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return Current rotation degree, -1 if it fails to get degree information
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see get_last_result()
 */
EAPI int ui_popup_get_degree(const ui_popup *popup);

/**
 * @brief Returns a view which is matched with the ui_popup.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] popup An ui_popup instance
 *
 * @return The view which is matched with ui_popup
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a popup is invalid
 *
 * @see get_last_result()
 */
EAPI ui_view *ui_popup_get_view(const ui_popup *popup);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _UI_POPUP_CAPI_H_ */
