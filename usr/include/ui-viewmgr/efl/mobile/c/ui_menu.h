#ifndef _UI_MENU_CAPI_H_
#define _UI_MENU_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_MENU UI Menu
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_menu.
 * @{
 */

/**
 * @brief Replaces or set a content of an ui_menu.
 * @since_tizen 3.0
 *
 * @param[in] menu An ui_menu object
 * @param[in] content ctxpopup object. It allows @c NULL for canceling the previous content
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid or @a content is not a type of Elm_Ctxpopup
 *
 * @see ui_menu_get_content()
 * @see ui_menu_unset_content()
 */
EAPI int ui_menu_set_content(ui_menu *menu, Elm_Ctxpopup *content);

/**
 * @brief Returns an ui_menu content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return A content of ui_menu
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see ui_menu_set_content()
 * @see ui_menu_unset_content()
 * @see get_last_result()
 */
EAPI Elm_Ctxpopup *ui_menu_get_content(const ui_menu *menu);

/**
 * @brief Unsets an ui_menu content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return A previous content. If it wasn't, return @c NULL
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see ui_menu_set_content()
 * @see ui_menu_get_content()
 * @see get_last_result()
 */
EAPI Elm_Ctxpopup *ui_menu_unset_content(ui_menu *menu);

/**
 * @brief Activates an ui_menu.
 * @details It makes ui_menu state as show.
 * @since_tizen 3.0
 *
 * @param[in] menu An ui_menu instance
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED menu instance is not set up yet
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see ui_menu_deactivate()
 */
EAPI int ui_menu_activate(ui_menu *menu);

/**
 * @brief Deactivates an ui_menu.
 * @details It makes ui_menu state as hide.
 * @since_tizen 3.0
 *
 * @param[in] menu An ui_menu instance
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED menu instance is not set up yet
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see ui_menu_activate()
 */
EAPI int ui_menu_deactivate(ui_menu *menu);

/**
 * @brief Returns the active status of ui_menu.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return @c true if menu is activated, @c false otherwise
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see ui_menu_activate()
 * @see ui_menu_deactivate()
 * @see get_last_result()
 */
EAPI bool ui_menu_get_activated(const ui_menu *menu);

/**
 * @brief Gets a base object of an ui_menu.
 * @details Normally, A base object can be used for a parent of ui_menu content.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return base object of ui_menu
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see get_last_result()
 */
EAPI Eo *ui_menu_get_base(const ui_menu *menu);

/**
 * @brief Gets a current ui_menu's degree.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return Current rotation degree, -1 if it fails to get degree information
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see get_last_result()
 */
EAPI int ui_menu_get_degree(const ui_menu *menu);

/**
 * @brief Returns a view which is matched with this ui_menu.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] menu An ui_menu instance
 *
 * @return The view which is matched with ui_menu
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a menu is invalid
 *
 * @see get_last_result()
 */
EAPI ui_view *ui_menu_get_view(const ui_menu *menu);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _UI_MENU_CAPI_H_ */
