#ifndef _ELM_WIDGET_EO_LEGACY_H_
#define _ELM_WIDGET_EO_LEGACY_H_

#ifndef _ELM_WIDGET_EO_CLASS_TYPE
#define _ELM_WIDGET_EO_CLASS_TYPE

typedef Eo Elm_Widget;

#endif

#ifndef _ELM_WIDGET_EO_TYPES
#define _ELM_WIDGET_EO_TYPES

typedef enum
{
  ELM_THEME_APPLY_FAILED = 0,
  ELM_THEME_APPLY_DEFAULT = 1 /* 0 */,
  ELM_THEME_APPLY_SUCCESS = 3 /* 0 */
} Elm_Theme_Apply;


#endif

/**
 * @brief 'Virtual' function handling passing focus to sub-objects given a
 * direction, in degrees.
 *
 * @param[in] degree
 * @param[out] direction
 * @param[out] direction_item
 * @param[out] weight
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_focus_direction(Elm_Widget *obj, const Evas_Object *base, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);

/**
 * @brief 'Virtual' function handling passing focus to sub-objects.
 *
 * @param[out] next
 * @param[out] next_item
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_focus_next(Elm_Widget *obj, Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);
EAPI void elm_widget_focus_set(Elm_Widget *obj, Eina_Bool focus);
EAPI Eina_Bool elm_widget_focus_get(const Elm_Widget *obj);
EAPI void elm_widget_drag_lock_y_set(Elm_Widget *obj, Eina_Bool lock);
EAPI Eina_Bool elm_widget_drag_lock_y_get(const Elm_Widget *obj);

/**
 * @brief Control the widget focus highlight style.
 *
 * @param[in] style
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_focus_highlight_style_set(Elm_Widget *obj, const char *style);

/** Control the widget focus highlight style.
 *
 * @ingroup Elm_Widget
 */
EAPI const char *elm_widget_focus_highlight_style_get(const Elm_Widget *obj);
EAPI void elm_widget_tree_unfocusable_set(Elm_Widget *obj, Eina_Bool tree_unfocusable);
EAPI Eina_Bool elm_widget_tree_unfocusable_get(const Elm_Widget *obj);

/**
 * @brief Control the widget's mirrored mode.
 *
 * @param[in] mirrored
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_mirrored_set(Elm_Widget *obj, Eina_Bool mirrored);

/** Control the widget's mirrored mode.
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_mirrored_get(const Elm_Widget *obj);
EAPI void elm_widget_theme_set(Elm_Widget *obj, Elm_Theme *th);
EAPI Elm_Theme *elm_widget_theme_get(const Elm_Widget *obj);
EAPI void elm_widget_disabled_set(Elm_Widget *obj, Eina_Bool disabled);
EAPI Eina_Bool elm_widget_disabled_get(const Elm_Widget *obj);
EAPI void elm_widget_highlight_ignore_set(Elm_Widget *obj, Eina_Bool ignore);
EAPI Eina_Bool elm_widget_highlight_ignore_get(const Elm_Widget *obj);

/**
 * @brief Control the widget's mirrored mode setting.
 *
 * @param[in] automatic
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_mirrored_automatic_set(Elm_Widget *obj, Eina_Bool automatic);

/** Control the widget's mirrored mode setting.
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_mirrored_automatic_get(const Elm_Widget *obj);
EAPI void elm_widget_orientation_mode_disabled_set(Elm_Widget *obj, Eina_Bool disabled);
EAPI Eina_Bool elm_widget_orientation_mode_disabled_get(const Elm_Widget *obj);
EAPI Elm_Theme_Apply elm_widget_style_set(Elm_Widget *obj, const char *style);
EAPI const char *elm_widget_style_get(const Elm_Widget *obj);
EAPI void elm_widget_scale_set(Elm_Widget *obj, double scale);
EAPI double elm_widget_scale_get(const Elm_Widget *obj);
EAPI void elm_widget_focus_custom_chain_set(Elm_Widget *obj, Eina_List *objs);
EAPI const Eina_List *elm_widget_focus_custom_chain_get(const Elm_Widget *obj);
EAPI void elm_widget_can_focus_set(Elm_Widget *obj, Eina_Bool can_focus);
EAPI Eina_Bool elm_widget_can_focus_get(const Elm_Widget *obj);
EAPI void elm_widget_highlight_in_theme_set(Elm_Widget *obj, Eina_Bool highlight);
EAPI Eina_Bool elm_widget_highlight_in_theme_get(const Elm_Widget *obj);
EAPI void elm_widget_parent_set(Elm_Widget *obj, Evas_Object *parent);
EAPI Evas_Object *elm_widget_parent_get(const Elm_Widget *obj);
EAPI void elm_widget_access_info_set(Elm_Widget *obj, const char *txt);
EAPI const char *elm_widget_access_info_get(const Elm_Widget *obj);
EAPI void elm_widget_drag_lock_x_set(Elm_Widget *obj, Eina_Bool lock);
EAPI Eina_Bool elm_widget_drag_lock_x_get(const Elm_Widget *obj);
EAPI void elm_widget_access_highlight_in_theme_set(Elm_Widget *obj, Eina_Bool highlight);
EAPI Eina_Bool elm_widget_access_highlight_in_theme_get(const Elm_Widget *obj);

/**
 * @brief Control the focus_region_show mode.
 *
 * @param[in] mode
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_region_show_mode_set(Elm_Widget *obj, Elm_Focus_Region_Show_Mode mode);

/** Control the focus_region_show mode.
 *
 * @ingroup Elm_Widget
 */
EAPI Elm_Focus_Region_Show_Mode elm_widget_focus_region_show_mode_get(const Elm_Widget *obj);
EAPI void elm_widget_parent_highlight_set(Elm_Widget *obj, Eina_Bool highlighted);
EAPI Elm_Theme_Apply elm_widget_theme_object_set(Elm_Widget *obj, Evas_Object *edj, const char *wname, const char *welement, const char *wstyle);
EAPI void elm_widget_hover_object_set(Elm_Widget *obj, Evas_Object *sobj);
EAPI void elm_widget_display_mode_set(Elm_Widget *obj, Evas_Display_Mode dispmode);
EAPI void elm_widget_on_show_region_hook_set(Elm_Widget *obj, region_hook_func_type func, void *data);
EAPI void elm_widget_domain_part_text_translatable_set(Elm_Widget *obj, const char *part, const char *domain, Eina_Bool translatable);
EAPI void elm_widget_orientation_set(Elm_Widget *obj, int rotation);
EAPI void elm_widget_resize_object_set(Elm_Widget *obj, Evas_Object *sobj, Eina_Bool sub_obj);
EAPI void elm_widget_domain_translatable_part_text_set(Elm_Widget *obj, const char *part, const char *domain, const char *label);

/**
 * @brief Function to operate on a given widget's scrollabe children when
 * necessary.
 *
 * @warning free the returned list with eina_list_free().
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_List *elm_widget_scrollable_children_get(const Elm_Widget *obj) EINA_WARN_UNUSED_RESULT;
EAPI int elm_widget_scroll_hold_get(const Elm_Widget *obj);
EAPI int elm_widget_drag_child_locked_y_get(const Elm_Widget *obj);

/**
 * @brief Control item loop feature.
 *
 * @param[in] enable
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_item_loop_enabled_set(Elm_Widget *obj, Eina_Bool enable);

/** Control item loop feature.
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_item_loop_enabled_get(const Elm_Widget *obj);
EAPI Eina_Bool elm_widget_child_can_focus_get(const Elm_Widget *obj);
EAPI int elm_widget_scroll_freeze_get(const Elm_Widget *obj);
EAPI Eina_Bool elm_widget_focus_region_get(const Elm_Widget *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);
EAPI Evas_Object *elm_widget_top_get(const Elm_Widget *obj);
EAPI unsigned int elm_widget_focus_order_get(const Elm_Widget *obj);
EAPI int elm_widget_drag_child_locked_x_get(const Elm_Widget *obj);
EAPI Eina_List *elm_widget_can_focus_child_list_get(const Elm_Widget *obj) EINA_WARN_UNUSED_RESULT;

/** Get the focused widget item.
 *
 * @ingroup Elm_Widget
 */
EAPI Elm_Widget_Item *elm_widget_focused_item_get(const Elm_Widget *obj);
EAPI void elm_widget_parents_bounce_get(const Elm_Widget *obj, Eina_Bool *horiz, Eina_Bool *vert);
EAPI Eina_Bool elm_widget_highlight_get(const Elm_Widget *obj);
EAPI Evas_Object *elm_widget_focused_object_get(const Elm_Widget *obj);
EAPI void elm_widget_parent2_set(Elm_Widget *obj, Evas_Object *parent);
EAPI Evas_Object *elm_widget_parent2_get(const Elm_Widget *obj);
EAPI void elm_widget_part_text_set(Elm_Widget *obj, const char * part, const char *label);
EAPI const char *elm_widget_part_text_get(const Elm_Widget *obj, const char * part);

/**
 * @brief Sets the widget's focus move policy.
 *
 * @param[in] policy Object's focus move policy.
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_move_policy_set(Elm_Widget *obj, Elm_Focus_Move_Policy policy);

/**
 * @brief Returns the widget's focus move policy.
 *
 * @return Object's focus move policy.
 *
 * @ingroup Elm_Widget
 */
EAPI Elm_Focus_Move_Policy elm_widget_focus_move_policy_get(const Elm_Widget *obj);

/**
 * @brief Control the widget's focus_move_policy mode setting.
 *
 * @param[in] automatic @c true to follow system focus move policy change,
 * @c false otherwise
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_move_policy_automatic_set(Elm_Widget *obj, Eina_Bool automatic);

/**
 * @brief Control the widget's focus_move_policy mode setting.
 *
 * @return @c true to follow system focus move policy change, @c false
 * otherwise
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_focus_move_policy_automatic_get(const Elm_Widget *obj);
EAPI Eina_Bool elm_widget_class_color_set(Elm_Widget *obj, const char * color_class, int r, int g, int b, int a);
EAPI Eina_Bool elm_widget_class_color_get(const Elm_Widget *obj, const char * color_class, int *r, int *g, int *b, int *a);
EAPI Eina_Bool elm_widget_class_color2_set(Elm_Widget *obj, const char * color_class, int r, int g, int b, int a);
EAPI Eina_Bool elm_widget_class_color2_get(const Elm_Widget *obj, const char * color_class, int *r, int *g, int *b, int *a);
EAPI Eina_Bool elm_widget_class_color3_set(Elm_Widget *obj, const char * color_class, int r, int g, int b, int a);
EAPI Eina_Bool elm_widget_class_color3_get(const Elm_Widget *obj, const char * color_class, int *r, int *g, int *b, int *a);
EAPI Evas_Object *elm_widget_newest_focus_order_get(const Elm_Widget *obj, unsigned int *newest_focus_order, Eina_Bool can_focus_only);
EAPI void elm_widget_scroll_hold_push(Elm_Widget *obj);
EAPI void elm_widget_cursor_add(Elm_Widget *obj, Elm_Cursor *cur);

/**
 * @brief Set the next object with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @since 1.8
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_next_object_set(Elm_Widget *obj, Evas_Object *next, Elm_Focus_Direction dir);

/**
 * @brief Get the next object with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @return Focus next object
 *
 * @since 1.8
 *
 * @ingroup Elm_Widget
 */
EAPI Evas_Object *elm_widget_focus_next_object_get(const Elm_Widget *obj, Elm_Focus_Direction dir);

/**
 * @brief Set the next object item with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @since 1.16
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_next_item_set(Elm_Widget *obj, Elm_Object_Item *next_item, Elm_Focus_Direction dir);

/**
 * @brief Get the next object item with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @return Focus next object item
 *
 * @since 1.16
 *
 * @ingroup Elm_Widget
 */
EAPI Elm_Object_Item *elm_widget_focus_next_item_get(const Elm_Widget *obj, Elm_Focus_Direction dir);
EAPI void elm_widget_focus_tree_unfocusable_handle(Elm_Widget *obj);
EAPI void elm_widget_focus_custom_chain_prepend(Elm_Widget *obj, Evas_Object *child, Evas_Object *relative_child);
EAPI const char *elm_widget_part_text_translate(Elm_Widget *obj, const char *part, const char *text);

/**
 * @brief Get the focus highlight geometry of widget.
 *
 * @param[in] y
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_highlight_geometry_get(const Elm_Widget *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief 'Virtual' function handling sub objects being added.
 *
 * @param[in] sobj
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_sub_object_add(Elm_Widget *obj, Evas_Object *sobj);

/**
 * @brief 'Virtual' function handling input events on the widget.
 *
 * @param[in] type
 * @param[in] event_info
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_event(Elm_Widget *obj, Evas_Object *source, Evas_Callback_Type type, void *event_info);
EAPI void elm_widget_event_callback_add(Elm_Widget *obj, Elm_Event_Cb func, const void *data);
EAPI void elm_widget_cursor_del(Elm_Widget *obj, Elm_Cursor *cur);
EAPI void *elm_widget_event_callback_del(Elm_Widget *obj, Elm_Event_Cb func, const void *data);

/**
 * @brief 'Virtual' function handling focus in/out events on the widget.
 *  return true if this widget can handle focus, false otherwise
 *
 * @param[in] item
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_on_focus(Elm_Widget *obj, Elm_Object_Item *item);

/**
 * @brief 'Virtual' function returning an inner area of a widget that should be
 * brought into the visible area of a broader viewport, may this context arise.
 *
 * @param[out] y
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_on_focus_region(Elm_Widget *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);
EAPI void elm_widget_focus_cycle(Elm_Widget *obj, Elm_Focus_Direction dir);
EAPI Eina_Bool elm_widget_event_propagate(Elm_Widget *obj, Evas_Callback_Type type, void *event_info, Evas_Event_Flags *event_flags);
EAPI void elm_widget_signal_callback_add(Elm_Widget *obj, const char *emission, const char *source, Edje_Signal_Cb func, void *data);

/** 'Virtual' function which checks if handling of passing focus to sub-objects
 * is supported by widget.
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_focus_next_manager_is(Elm_Widget *obj);
EAPI Evas_Object *elm_widget_name_find(const Elm_Widget *obj, const char *name, int recurse);
EAPI Eina_Bool elm_widget_focus_list_direction_get(const Elm_Widget *obj, const Evas_Object *base, const Eina_List *items, list_data_get_func_type list_data_get, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);
EAPI void elm_widget_focused_object_clear(Elm_Widget *obj);
EAPI Eina_Bool elm_widget_focus_direction_go(Elm_Widget *obj, double degree);
EAPI void elm_widget_show_region_set(Elm_Widget *obj, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h, Eina_Bool forceshow);
EAPI void elm_widget_show_region_get(const Elm_Widget *obj, Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);
EAPI void elm_widget_scroll_freeze_pop(Elm_Widget *obj);
EAPI void elm_widget_tooltip_del(Elm_Widget *obj, Elm_Tooltip *tt);
EAPI Eina_Bool elm_widget_focus_next_get(const Elm_Widget *obj, Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);
EAPI const char *elm_widget_translatable_part_text_get(const Elm_Widget *obj, const char *part);

/**
 * @brief Restore the focus state of the sub-tree.
 *
 * This API will restore the focus state of the sub-tree to the latest state.
 * If a sub-tree is unfocused and wants to get back to the latest focus state,
 * this API will be helpful.
 *
 * @ingroup Elm_Widget
 */
EAPI void elm_widget_focus_restore(Elm_Widget *obj);
EAPI void elm_widget_scroll_hold_pop(Elm_Widget *obj);
EAPI void elm_widget_scroll_freeze_push(Elm_Widget *obj);
EAPI void elm_widget_focus_custom_chain_unset(Elm_Widget *obj);
EAPI void elm_widget_focus_steal(Elm_Widget *obj, Elm_Object_Item *item);
EAPI void elm_widget_focus_hide_handle(Elm_Widget *obj);
EAPI Eina_Bool elm_widget_focus_list_next_get(const Elm_Widget *obj, const Eina_List *items, list_data_get_func_type list_data_get, Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);

/** 'Virtual' function on the widget being re-themed.
 *
 * @ingroup Elm_Widget
 */
EAPI Elm_Theme_Apply elm_widget_theme_apply(Elm_Widget *obj);
EAPI Eina_Bool elm_widget_focus_direction_get(const Elm_Widget *obj, const Evas_Object *base, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);
EAPI void *elm_widget_signal_callback_del(Elm_Widget *obj, const char *emission, const char *source, Edje_Signal_Cb func);
EAPI void elm_widget_signal_emit(Elm_Widget *obj, const char *emission, const char *source);

/** 'Virtual' function on the widget being disabled.
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_disable(Elm_Widget *obj);

/**
 * @brief 'Virtual' function handling sub objects being removed.
 *
 * @param[in] sobj
 *
 * @ingroup Elm_Widget
 */
EAPI Eina_Bool elm_widget_sub_object_del(Elm_Widget *obj, Evas_Object *sobj);
EAPI void elm_widget_tooltip_add(Elm_Widget *obj, Elm_Tooltip *tt);
EAPI void elm_widget_focus_region_show(const Elm_Widget *obj);
EAPI void elm_widget_focus_disabled_handle(Elm_Widget *obj);
EAPI void elm_widget_focus_custom_chain_append(Elm_Widget *obj, Evas_Object *child, Evas_Object *relative_child);
EAPI void elm_widget_focus_reconfigure(Elm_Widget *obj);

/**
 * @brief Get the access object of given part of the widget.
 *
 * @param[in] part The object's part name to get access object
 *
 * @since 1.18
 *
 * @ingroup Elm_Widget
 */
EAPI Evas_Object *elm_widget_part_access_object_get(const Elm_Widget *obj, const char *part);
EAPI void elm_widget_class_color_del(Elm_Widget *obj, const char *color_class);
EAPI void elm_widget_class_color_clear(Elm_Widget *obj);

#endif
