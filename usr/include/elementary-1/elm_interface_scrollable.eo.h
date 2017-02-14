#ifndef _ELM_INTERFACE_SCROLLABLE_EO_H_
#define _ELM_INTERFACE_SCROLLABLE_EO_H_

#ifndef _ELM_INTERFACE_SCROLLABLE_EO_CLASS_TYPE
#define _ELM_INTERFACE_SCROLLABLE_EO_CLASS_TYPE

typedef Eo Elm_Interface_Scrollable;

#endif

#ifndef _ELM_INTERFACE_SCROLLABLE_EO_TYPES
#define _ELM_INTERFACE_SCROLLABLE_EO_TYPES


#endif
#define ELM_INTERFACE_SCROLLABLE_MIXIN elm_interface_scrollable_mixin_get()

EAPI const Eo_Class *elm_interface_scrollable_mixin_get(void) EINA_CONST;

/**
 * @brief Control scrolling gravity on the scrollable
 *
 * The gravity defines how the scroller will adjust its view when the size of
 * the scroller contents increases.
 *
 * The scroller will adjust the view to glue itself as follows.
 *
 * x=0.0, for staying where it is relative to the left edge of the content
 * x=1.0, for staying where it is relative to the rigth edge of the content
 * y=0.0, for staying where it is relative to the top edge of the content
 * y=1.0, for staying where it is relative to the bottom edge of the content
 *
 * Default values for x and y are 0.0
 *
 * @param[in] x Horizontal scrolling gravity
 * @param[in] y Vertical scrolling gravity
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_gravity_set(double x, double y);

/**
 * @brief Control scrolling gravity on the scrollable
 *
 * The gravity defines how the scroller will adjust its view when the size of
 * the scroller contents increases.
 *
 * The scroller will adjust the view to glue itself as follows.
 *
 * x=0.0, for staying where it is relative to the left edge of the content
 * x=1.0, for staying where it is relative to the rigth edge of the content
 * y=0.0, for staying where it is relative to the top edge of the content
 * y=1.0, for staying where it is relative to the bottom edge of the content
 *
 * Default values for x and y are 0.0
 *
 * @param[out] x Horizontal scrolling gravity
 * @param[out] y Vertical scrolling gravity
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_gravity_get(double *x, double *y);

/**
 * @brief Bouncing behavior
 *
 * When scrolling, the scroller may "bounce" when reaching an edge of the
 * content object. This is a visual way to indicate the end has been reached.
 * This is enabled by default for both axis. This API will set if it is enabled
 * for the given axis with the boolean parameters for each axis.
 *
 * @param[in] horiz Horizontal bounce policy.
 * @param[in] vert Vertical bounce policy.
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_bounce_allow_set(Eina_Bool horiz, Eina_Bool vert);

/**
 * @brief Bouncing behavior
 *
 * When scrolling, the scroller may "bounce" when reaching an edge of the
 * content object. This is a visual way to indicate the end has been reached.
 * This is enabled by default for both axis. This API will set if it is enabled
 * for the given axis with the boolean parameters for each axis.
 *
 * @param[out] horiz Horizontal bounce policy.
 * @param[out] vert Vertical bounce policy.
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_bounce_allow_get(Eina_Bool *horiz, Eina_Bool *vert);

/**
 * @brief Control Wheel disable Enable or disable mouse wheel to be used to
 * scroll the scroller content. heel is enabled by default.
 *
 * @param[in] disabled
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_wheel_disabled_set(Eina_Bool disabled);

/** Control Wheel disable Enable or disable mouse wheel to be used to scroll
 * the scroller content. heel is enabled by default.
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI Eina_Bool  elm_interface_scrollable_wheel_disabled_get(void);

/**
 * @brief Blocking of scrolling (per axis)
 *
 * This function will block scrolling movement (by input of a user) in a given
 * direction. One can disable movements in the X axis, the Y axis or both. The
 * default value is #ELM_SCROLLER_MOVEMENT_NO_BLOCK, where movements are
 * allowed in both directions.
 *
 * What makes this function different from freeze_push(), hold_push() and
 * lock_x_set() (or lock_y_set()) is that it doesn't propagate its effects to
 * any parent or child widget of @c obj. Only the target scrollable widget will
 * be locked with regard to scrolling.
 *
 * @param[in] block Which axis (or axes) to block
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_movement_block_set(Elm_Scroller_Movement_Block block);

/**
 * @brief Blocking of scrolling (per axis)
 *
 * This function will block scrolling movement (by input of a user) in a given
 * direction. One can disable movements in the X axis, the Y axis or both. The
 * default value is #ELM_SCROLLER_MOVEMENT_NO_BLOCK, where movements are
 * allowed in both directions.
 *
 * What makes this function different from freeze_push(), hold_push() and
 * lock_x_set() (or lock_y_set()) is that it doesn't propagate its effects to
 * any parent or child widget of @c obj. Only the target scrollable widget will
 * be locked with regard to scrolling.
 *
 * @return Which axis (or axes) to block
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI Elm_Scroller_Movement_Block  elm_interface_scrollable_movement_block_get(void);

EOAPI void  elm_interface_scrollable_momentum_animator_disabled_set(Eina_Bool disabled);

EOAPI Eina_Bool  elm_interface_scrollable_momentum_animator_disabled_get(void);

/**
 * @brief Scrollbar visibility policy
 *
 * #ELM_SCROLLER_POLICY_AUTO means the scrollbar is made visible if it is
 * needed, and otherwise kept hidden. #ELM_SCROLLER_POLICY_ON turns it on all
 * the time, and #ELM_SCROLLER_POLICY_OFF always keeps it off. This applies
 * respectively for the horizontal and vertical scrollbars.
 *
 * @param[in] hbar Horizontal scrollbar policy
 * @param[in] vbar Vertical scrollbar policy
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_policy_set(Elm_Scroller_Policy hbar, Elm_Scroller_Policy vbar);

/**
 * @brief Scrollbar visibility policy
 *
 * #ELM_SCROLLER_POLICY_AUTO means the scrollbar is made visible if it is
 * needed, and otherwise kept hidden. #ELM_SCROLLER_POLICY_ON turns it on all
 * the time, and #ELM_SCROLLER_POLICY_OFF always keeps it off. This applies
 * respectively for the horizontal and vertical scrollbars.
 *
 * @param[out] hbar Horizontal scrollbar policy
 * @param[out] vbar Vertical scrollbar policy
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_policy_get(Elm_Scroller_Policy *hbar, Elm_Scroller_Policy *vbar);

/**
 * @brief Currently visible content region
 *
 * This gets the current region in the content object that is visible through
 * the scroller. The region co-ordinates are returned in the @c x, @c y, @c w,
 * @c h values pointed to.
 *
 * @note All coordinates are relative to the content.
 *
 * See: @ref elm_interface_scrollable_content_region_show.
 *
 * @param[in] x X coordinate of the region
 * @param[in] y Y coordinate of the region
 * @param[in] w Width of the region
 * @param[in] h Height of the region
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_region_set(Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Currently visible content region
 *
 * This gets the current region in the content object that is visible through
 * the scroller. The region co-ordinates are returned in the @c x, @c y, @c w,
 * @c h values pointed to.
 *
 * @note All coordinates are relative to the content.
 *
 * See: @ref elm_interface_scrollable_content_region_show.
 *
 * @param[out] x X coordinate of the region
 * @param[out] y Y coordinate of the region
 * @param[out] w Width of the region
 * @param[out] h Height of the region
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_region_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief It decides whether the scrollable object propagates the events to
 * content object or not.
 *
 * @param[in] repeat_events
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_repeat_events_set(Eina_Bool repeat_events);

/** It decides whether the scrollable object propagates the events to content
 * object or not.
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI Eina_Bool  elm_interface_scrollable_repeat_events_get(void);

/**
 * @brief Scroll page size relative to viewport size.
 *
 * The scroller is capable of limiting scrolling by the user to "pages". That
 * is to jump by and only show a "whole page" at a time as if the continuous
 * area of the scroller content is split into page sized pieces. This sets the
 * size of a page relative to the viewport of the scroller. 1.0 is "1 viewport"
 * is size (horizontally or vertically). 0.0 turns it off in that axis. This is
 * mutually exclusive with page size (see
 * @ref elm_interface_scrollable_page_size_get for more information). Likewise
 * 0.5 is "half a viewport". Sane usable values are normally between 0.0 and
 * 1.0 including 1.0. If you only want 1 axis to be page "limited", use 0.0 for
 * the other axis.
 *
 * @param[in] x The horizontal page relative size
 * @param[in] y The vertical page relative size
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_size_set(Evas_Coord x, Evas_Coord y);

/**
 * @brief Scroll page size relative to viewport size.
 *
 * The scroller is capable of limiting scrolling by the user to "pages". That
 * is to jump by and only show a "whole page" at a time as if the continuous
 * area of the scroller content is split into page sized pieces. This sets the
 * size of a page relative to the viewport of the scroller. 1.0 is "1 viewport"
 * is size (horizontally or vertically). 0.0 turns it off in that axis. This is
 * mutually exclusive with page size (see
 * @ref elm_interface_scrollable_page_size_get for more information). Likewise
 * 0.5 is "half a viewport". Sane usable values are normally between 0.0 and
 * 1.0 including 1.0. If you only want 1 axis to be page "limited", use 0.0 for
 * the other axis.
 *
 * @param[out] x The horizontal page relative size
 * @param[out] y The vertical page relative size
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_size_get(Evas_Coord *x, Evas_Coord *y);

EOAPI void  elm_interface_scrollable_bounce_animator_disabled_set(Eina_Bool disabled);

EOAPI Eina_Bool  elm_interface_scrollable_bounce_animator_disabled_get(void);

EOAPI void  elm_interface_scrollable_page_scroll_limit_set(int page_limit_h, int page_limit_v);

EOAPI void  elm_interface_scrollable_page_scroll_limit_get(int *page_limit_h, int *page_limit_v);

/**
 * @brief Page snapping behavior
 *
 * When scrolling, if a scroller is paged (see elm_scroller_page_size_set() and
 * elm_scroller_page_relative_set()), the scroller may snap to pages when being
 * scrolled, i.e., even if it had momentum to scroll further, it will stop at
 * the next page boundaries. This is disabled, by default, for both axis. This
 * function will set if it that is enabled or not, for each axis.
 *
 * @note If @c obj is not set to have pages, nothing will happen after this
 * call.
 *
 * @param[in] horiz Allow snap horizontally
 * @param[in] vert Allow snap vertically
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_snap_allow_set(Eina_Bool horiz, Eina_Bool vert);

/**
 * @brief Page snapping behavior
 *
 * When scrolling, if a scroller is paged (see elm_scroller_page_size_set() and
 * elm_scroller_page_relative_set()), the scroller may snap to pages when being
 * scrolled, i.e., even if it had momentum to scroll further, it will stop at
 * the next page boundaries. This is disabled, by default, for both axis. This
 * function will set if it that is enabled or not, for each axis.
 *
 * @note If @c obj is not set to have pages, nothing will happen after this
 * call.
 *
 * @param[out] horiz Allow snap horizontally
 * @param[out] vert Allow snap vertically
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_snap_allow_get(Eina_Bool *horiz, Eina_Bool *vert);

EOAPI void  elm_interface_scrollable_paging_set(double pagerel_h, double pagerel_v, Evas_Coord pagesize_h, Evas_Coord pagesize_v);

EOAPI void  elm_interface_scrollable_paging_get(double *pagerel_h, double *pagerel_v, Evas_Coord *pagesize_h, Evas_Coord *pagesize_v);

/**
 * @brief Single direction scroll configuration
 *
 * This makes it possible to restrict scrolling to a single direction, with a
 * "soft" or "hard" behavior.
 *
 * The hard behavior restricts the scrolling to a single direction all of the
 * time while the soft one will restrict depending on factors such as the
 * movement angle. If the user scrolls roughly in one direction only, it will
 * only move according to it while if the move was clearly wanted on both axes,
 * it will happen on both of them.
 *
 * @param[in] single_dir The single direction scroll policy
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_single_direction_set(Elm_Scroller_Single_Direction single_dir);

/**
 * @brief Single direction scroll configuration
 *
 * This makes it possible to restrict scrolling to a single direction, with a
 * "soft" or "hard" behavior.
 *
 * The hard behavior restricts the scrolling to a single direction all of the
 * time while the soft one will restrict depending on factors such as the
 * movement angle. If the user scrolls roughly in one direction only, it will
 * only move according to it while if the move was clearly wanted on both axes,
 * it will happen on both of them.
 *
 * @return The single direction scroll policy
 *
 * @since 1.8
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI Elm_Scroller_Single_Direction  elm_interface_scrollable_single_direction_get(void);

EOAPI void  elm_interface_scrollable_step_size_set(Evas_Coord x, Evas_Coord y);

EOAPI void  elm_interface_scrollable_step_size_get(Evas_Coord *x, Evas_Coord *y);

/**
 * @brief Controls an infinite loop for a scroller.
 *
 * @param[in] loop_h The scrolling horizontal loop
 * @param[in] loop_v The scrolling vertical loop
 *
 * @since 1.14
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_loop_set(Eina_Bool loop_h, Eina_Bool loop_v);

/**
 * @brief Controls an infinite loop for a scroller.
 *
 * @param[out] loop_h The scrolling horizontal loop
 * @param[out] loop_v The scrolling vertical loop
 *
 * @since 1.14
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_loop_get(Eina_Bool *loop_h, Eina_Bool *loop_v);

/**
 * @brief Set the callback to run when the content has been moved up.
 *
 * @param[in] scroll_up_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_scroll_up_cb_set(Elm_Interface_Scrollable_Cb scroll_up_cb);

/**
 * @brief Set the callback to run when the horizontal scrollbar is dragged.
 *
 * @param[in] hbar_drag_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_hbar_drag_cb_set(Elm_Interface_Scrollable_Cb hbar_drag_cb);

/**
 * @brief Set the callback to run when dragging of the contents has started.
 *
 * @param[in] drag_start_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_drag_start_cb_set(Elm_Interface_Scrollable_Cb drag_start_cb);

EOAPI void  elm_interface_scrollable_freeze_set(Eina_Bool freeze);

/**
 * @brief When the viewport is resized, the callback is called.
 *
 * @param[in] viewport_resize_cb
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_viewport_resize_cb_set(Elm_Interface_Scrollable_Resize_Cb viewport_resize_cb);

/**
 * @brief Set the callback to run when the content has been moved to the left
 *
 * @param[in] scroll_left_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_scroll_left_cb_set(Elm_Interface_Scrollable_Cb scroll_left_cb);

/**
 * @brief Set the callback to run when the vertical scrollbar is pressed.
 *
 * @param[in] vbar_press_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_vbar_press_cb_set(Elm_Interface_Scrollable_Cb vbar_press_cb);

/**
 * @brief Set the callback to run when the horizontal scrollbar is pressed.
 *
 * @param[in] hbar_press_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_hbar_press_cb_set(Elm_Interface_Scrollable_Cb hbar_press_cb);

/**
 * @brief Set the callback to run when the horizontal scrollbar is unpressed.
 *
 * @param[in] hbar_unpress_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_hbar_unpress_cb_set(Elm_Interface_Scrollable_Cb hbar_unpress_cb);

/**
 * @brief Set the callback to run when dragging of the contents has stopped.
 *
 * @param[in] drag_stop_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_drag_stop_cb_set(Elm_Interface_Scrollable_Cb drag_stop_cb);

EOAPI void  elm_interface_scrollable_extern_pan_set(Evas_Object *pan);

/**
 * @brief Set the callback to run when the visible page changes.
 *
 * @param[in] page_change_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_change_cb_set(Elm_Interface_Scrollable_Cb page_change_cb);

EOAPI void  elm_interface_scrollable_hold_set(Eina_Bool hold);

/**
 * @brief Set the callback to run when the scrolling animation has started.
 *
 * @param[in] animate_start_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_animate_start_cb_set(Elm_Interface_Scrollable_Cb animate_start_cb);

/**
 * @brief Set the callback to run when the content has been moved down.
 *
 * @param[in] scroll_down_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_scroll_down_cb_set(Elm_Interface_Scrollable_Cb scroll_down_cb);

/**
 * @brief Set scroll page size relative to viewport size.
 *
 * @param[in] h_pagerel
 * @param[in] v_pagerel
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_relative_set(double h_pagerel, double v_pagerel);

/**
 * @brief Set the callback to run when the content has been moved.
 *
 * @param[in] scroll_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_scroll_cb_set(Elm_Interface_Scrollable_Cb scroll_cb);

/**
 * @brief Set the callback to run when the scrolling animation has stopped.
 *
 * @param[in] animate_stop_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_animate_stop_cb_set(Elm_Interface_Scrollable_Cb animate_stop_cb);

EOAPI void  elm_interface_scrollable_mirrored_set(Eina_Bool mirrored);

EOAPI void  elm_interface_scrollable_content_min_limit_cb_set(Elm_Interface_Scrollable_Min_Limit_Cb min_limit_cb);

/**
 * @brief Set the callback to run when the content has been moved to the right.
 *
 * @param[in] scroll_right_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_scroll_right_cb_set(Elm_Interface_Scrollable_Cb scroll_right_cb);

EOAPI void  elm_interface_scrollable_content_set(Evas_Object *content);

/**
 * @brief Set the callback to run when the left edge of the content has been
 * reached.
 *
 * @param[in] edge_left_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_edge_left_cb_set(Elm_Interface_Scrollable_Cb edge_left_cb);

/**
 * @brief Set the callback to run when the horizontal scrollbar is dragged.
 *
 * @param[in] vbar_drag_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_vbar_drag_cb_set(Elm_Interface_Scrollable_Cb vbar_drag_cb);

/**
 * @brief Set the callback to run when the horizontal scrollbar is unpressed.
 *
 * @param[in] vbar_unpress_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_vbar_unpress_cb_set(Elm_Interface_Scrollable_Cb vbar_unpress_cb);

/**
 * @brief Set the callback to run when the bottom edge of the content has been
 * reached.
 *
 * @param[in] edge_bottom_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_edge_bottom_cb_set(Elm_Interface_Scrollable_Cb edge_bottom_cb);

/**
 * @brief Set the callback to run when the right edge of the content has been
 * reached.
 *
 * @param[in] edge_right_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_edge_right_cb_set(Elm_Interface_Scrollable_Cb edge_right_cb);

/**
 * @brief Set the callback to run when the top edge of the content has been
 * reached.
 *
 * @param[in] edge_top_cb The callback
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_edge_top_cb_set(Elm_Interface_Scrollable_Cb edge_top_cb);

EOAPI void  elm_interface_scrollable_objects_set(Evas_Object *edje_object, Evas_Object *hit_rectangle);

/**
 * @brief Get scroll last page number.
 *
 * The page number starts from 0. 0 is the first page. This returns the last
 * page number among the pages.
 *
 * See: @ref elm_interface_scrollable_current_page_get,
 * @ref elm_interface_scrollable_page_show and
 * @ref elm_interface_scrollable_page_bring_in.
 *
 * @param[out] pagenumber_h The horizontal page number
 * @param[out] pagenumber_v The vertical page number
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_last_page_get(int *pagenumber_h, int *pagenumber_v);

/**
 * @brief Get scroll current page number.
 *
 * The page number starts from 0. 0 is the first page. Current page means the
 * page which meets the top-left of the viewport. If there are two or more
 * pages in the viewport, it returns the number of the page which meets the
 * top-left of the viewport.
 *
 * See: @ref elm_interface_scrollable_last_page_get,
 * @ref elm_interface_scrollable_page_show and
 * @ref elm_interface_scrollable_page_bring_in.
 *
 * @param[out] pagenumber_h The horizontal page number
 * @param[out] pagenumber_v The vertical page number
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_current_page_get(int *pagenumber_h, int *pagenumber_v);

EOAPI void  elm_interface_scrollable_content_viewport_geometry_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Get the size of the content object
 *
 * This gets the size of the content object of the scroller.
 *
 * @param[out] w Width of the content object.
 * @param[out] h Height of the content object.
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_size_get(Evas_Coord *w, Evas_Coord *h);

EOAPI void  elm_interface_scrollable_content_pos_set(Evas_Coord x, Evas_Coord y, Eina_Bool sig);

EOAPI void  elm_interface_scrollable_content_pos_get(Evas_Coord *x, Evas_Coord *y);

/**
 * @brief Show a specific virtual region within the scroller content object by
 * page number.
 *
 * 0, 0 of the indicated page is located at the top-left of the viewport. This
 * will jump to the page directly without animation.
 *
 * See @ref elm_interface_scrollable_page_bring_in.
 *
 * @param[in] pagenumber_v The vertical page number
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_show(int pagenumber_h, int pagenumber_v);

/**
 * @brief Show a specific virtual region within the scroller content object.
 *
 * This will ensure all (or part if it does not fit) of the designated region
 * in the virtual content object (0, 0 starting at the top-left of the virtual
 * content object) is shown within the scroller. Unlike
 * elm_scroller_region_show(), this allows the scroller to "smoothly slide" to
 * this location (if configuration in general calls for transitions). It may
 * not jump immediately to the new location and make take a while and show
 * other content along the way.
 *
 * See @ref elm_interface_scrollable_content_region_show
 *
 * @param[in] y Y coordinate of the region
 * @param[in] w Width of the region
 * @param[in] h Height of the region
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_region_bring_in(Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Show a specific virtual region within the scroller content object by
 * page number.
 *
 * 0, 0 of the indicated page is located at the top-left of the viewport. This
 * will slide to the page with animation.
 *
 * @ref elm_interface_scrollable_page_show
 *
 * @param[in] pagenumber_v The vertical page number
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_page_bring_in(int pagenumber_h, int pagenumber_v);

/**
 * @brief Show a specific virtual region within the scroller content object
 *
 * This will ensure all (or part if it does not fit) of the designated region
 * in the virtual content object (0, 0 starting at the top-left of the virtual
 * content object) is shown within the scroller.
 *
 * @param[in] y Y coordinate of the region
 * @param[in] w Width of the region
 * @param[in] h Height of the region
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_region_show(Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h);

/**
 * @brief Prevent the scrollable from being smaller than the minimum size of
 * the content.
 *
 * By default the scroller will be as small as its design allows, irrespective
 * of its content. This will make the scroller minimum size the right size
 * horizontally and/or vertically to perfectly fit its content in that
 * direction.
 *
 * @param[in] h whether to limit the minimum vertical size
 *
 * @ingroup Elm_Interface_Scrollable
 */
EOAPI void  elm_interface_scrollable_content_min_limit(Eina_Bool w, Eina_Bool h);

EOAPI void  elm_interface_scrollable_wanted_region_set(Evas_Coord x, Evas_Coord y);

EOAPI extern const Eo_Event_Description _ELM_INTERFACE_SCROLLABLE_EVENT_CHANGED;

/**
 * No description
 */
#define ELM_INTERFACE_SCROLLABLE_EVENT_CHANGED (&(_ELM_INTERFACE_SCROLLABLE_EVENT_CHANGED))

#endif
