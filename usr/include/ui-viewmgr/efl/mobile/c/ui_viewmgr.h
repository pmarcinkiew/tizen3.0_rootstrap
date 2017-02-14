#ifndef _UI_VIEWMGR_CAPI_H_
#define _UI_VIEWMGR_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CAPI_UI_VIEWMGR UI Viewmgr
 * @ingroup CAPI_UI_VIEWMGR_MODULE
 * @brief This module provides functionalities about ui_viewmgr.
 * @{
 */

/**
 * @brief Pushs a new view into ui_viewmgr. This function is used for when application switches a current view to a new one.
 * @details Normally, the current view will be hidden by a new view. In default, when user calls this API, view will be switched to @a view instantly,
 *          only when ui_viewmgr state is activated. Otherwise, the @a view will be shown later when ui_viewmgr is activated. ui_viewmgr_view_push() is designed
 *          for providing view transition effect. If you want push view instantly without any transition, you could use ui_viewmgr_view_push_insert_before() or
 *          ui_viewmgr_view_push_insert_after(). If you want to pop the current view, the please use ui_viewmgr_view_pop().
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view to insert in the ui_viewmgr view list
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is not valid
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED @a view was already inserted
 *
 * @see ui_viewmgr_activate()
 * @see ui_viewmgr_insert_view_before()
 * @see ui_viewmgr_insert_view_after()
 * @see ui_viewmgr_pop_view()
 */
EAPI int ui_viewmgr_push_view(ui_view *view);

/**
 * @brief Inserts a view in the ui_viewmgr view list. Specifically, insert a given @a view right before of the given view, @a before.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view to insert in the ui_viewmgr view list
 * @param[in] before An ui_view that will be just inserted after @a view. If you pass @c NULL, @a view will be inserted at the front of the view list
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED @a view was already inserted
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is not valid
 *
 * @see ui_viewmgr_insert_view_after()
 */
EAPI int ui_viewmgr_insert_view_before(ui_view *view, ui_view *before);

/**
 * @brief Inserts a view in the ui_viewmgr view list. Specifically, insert a given @a view right after of the given view, @a after.
 * @since_tizen 3.0
 *
 * @param[in] view An ui_view to insert in the ui_viewmgr view list
 * @param[in] after An ui_view that will be just inserted before the @a view. If you pass @c NULL, @a view will be inserted at the end of the view list
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED @a view was already inserted
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is not valid
 *
 * @see ui_viewmgr_insert_view_before()
 */
EAPI int ui_viewmgr_insert_view_after(ui_view *view, ui_view *after);

/**
 * @brief Pops the top(last) view from the ui_viewmgr view list.
 *        This function is used when application switches the current view back to the previous view.
 *        The top view will be removed from the view stack and then it will be deleted by ui_viewmgr.
 * @since_tizen 3.0
 * @remarks If the view is just one left, then ui_viewmgr would be deactivated automatically since the ui application might be invalid anymore. Otherwise,
 *          the application will be terminated. It's up to system configuration.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED No more views to pop
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS On a certain profile, it may not allow to pop multiple views at the same time
 *
 * @see ui_viewmgr_deactivate()
 * @see ui_viewmgr_push_view()
 */
EAPI int ui_viewmgr_pop_view(void);

/**
 * @brief Activates this view manager.
 * @since_tizen 3.0
 * @remarks ui_viewmgr window and views will be shown once this function is called.
 *          Usually this should be called after applications set their all views on initialization time.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS Already activated
 * @retval #UI_VIEWMGR_ERROR_NOT_PERMITTED Can't be activated. (ie, view manager has zero views.)
 *
 * @see ui_viewmgr_deactivate()
 */
EAPI int ui_viewmgr_activate(void);

/**
 * @brief Deactivates this view manager.
 * @since_tizen 3.0
 * @remarks ui_viewmgr window and views will be hidden once this function is called.
 *          this behavior is up ui system, but usually it hides(unmap)
 *          current window in order that application go background.
 *
 * @return @c 0 on success, otherwise a negative error value.
 * @retval #UI_VIEWMGR_ERROR_NONE Successful
 * @retval #UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS Already deactivated
 *
 * @see ui_viewmgr_activate()
 */
EAPI int ui_viewmgr_deactivate(void);

/**
 * @brief Gets a window object of ui_viewmgr.
 * @since_tizen 3.0
 *
 * @return The window object of ui_viewmgr
 */
EAPI Elm_Win *ui_viewmgr_get_window(void);

/**
 * @brief Returns a last(top) view.
 * @since_tizen 3.0
 * @remarks The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @return The view which is last view of the ui_viewmgr view list. NULL on error
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_NOT_PERMITTED @a viewmgr has no view
 *
 * @see get_last_result()
 */
EAPI ui_view *ui_viewmgr_get_last_view(void);

/**
 * @brief Returns a view which is matched with the index @a idx.
 * @since_tizen 3.0
 * @remarks You could use the index as the page numbers of the views.
 *          the index number of views are variable since the view list is variable.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] idx A index of the view which you are looking for
 *
 * @return The view which index is matched with @a idx
 *         If there were no views with index @a idx, @c NULL will be returned
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER Wrong index
 *
 * @see ui_viewmgr_get_view_index()
 * @see ui_viewmgr_get_view_count()
 * @see get_last_result()
 */
EAPI ui_view *ui_viewmgr_get_view_by_idx(int idx);

/**
 * @brief Returns a view which is matched with the @a name.
 * @since_tizen 3.0
 * @remarks Every view have their names as their own identifiers.
 *          The specific error code can be obtained using the get_last_result() method.
 *          Error codes are described in Exception section.
 *
 * @param[in] name The name of the view which you are looking for
 *
 * @return The view which name is matched with @a name
 *         If there were no views name matched, @c NULL will be returned
 * @exception #UI_VIEWMGR_ERROR_NONE Successfully added
 * @exception #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a name is NULL, otherwise there is no matched name
 *
 * @see ui_view_create()
 * @see ui_standard_view_create()
 * @see get_last_result()
 */
EAPI ui_view *ui_viewmgr_get_view_by_name(const char *name);

/**
 * @brief Gets a base object of a ui_viewmgr.
 * @since_tizen 3.0
 * @remarks Normally, a base object can be used for adding additional objects.
 *
 * @return The base object of ui_viewmgr
 */
EAPI Eo *ui_viewmgr_get_base(void);

/**
 * @brief Returns a view index(page) number of the given view.
 *        You could use this function to query the given @a view list order.
 * @since_tizen 3.0
 * @remarks The index number of views are variable since the view list is variable
 *
 * @param[in] view An ui_view to query the index.
 *
 * @return An index of the given @a view on success, otherwise a negative error value
 * @retval #UI_VIEWMGR_ERROR_INVALID_PARAMETER @a view is not valid
 */
EAPI int ui_viewmgr_get_view_index(const ui_view *view);

/**
 * @brief Returns the number of views which of ui_viewmgr.
 * @since_tizen 3.0
 *
 * @return the count of views
 */
EAPI int ui_viewmgr_get_view_count(void);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _UI_VIEWMGR_CAPI_H_ */
