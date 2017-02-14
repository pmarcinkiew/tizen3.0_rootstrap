#ifndef _ELM_WIDGET_EO_H_
#define _ELM_WIDGET_EO_H_

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
#define ELM_WIDGET_CLASS elm_widget_class_get()

EAPI const Eo_Class *elm_widget_class_get(void) EINA_CONST;

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
EOAPI Eina_Bool  elm_obj_widget_focus_direction(const Evas_Object *base, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);

/**
 * @brief 'Virtual' function handling passing focus to sub-objects.
 *
 * @param[out] next
 * @param[out] next_item
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_focus_next(Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);

EOAPI Evas_Object * elm_obj_widget_parent_widget_get(void);

EOAPI void  elm_obj_widget_focus_set(Eina_Bool focus);

EOAPI Eina_Bool  elm_obj_widget_focus_get(void);

EOAPI void  elm_obj_widget_drag_lock_y_set(Eina_Bool lock);

EOAPI Eina_Bool  elm_obj_widget_drag_lock_y_get(void);

/**
 * @brief Control the widget focus highlight style.
 *
 * @param[in] style
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_focus_highlight_style_set(const char *style);

/** Control the widget focus highlight style.
 *
 * @ingroup Elm_Widget
 */
EOAPI const char * elm_obj_widget_focus_highlight_style_get(void);

EOAPI void  elm_obj_widget_tree_unfocusable_set(Eina_Bool tree_unfocusable);

EOAPI Eina_Bool  elm_obj_widget_tree_unfocusable_get(void);

/**
 * @brief Control the widget's mirrored mode.
 *
 * @param[in] mirrored
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_mirrored_set(Eina_Bool mirrored);

/** Control the widget's mirrored mode.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_mirrored_get(void);

EOAPI void  elm_obj_widget_theme_set(Elm_Theme *th);

EOAPI Elm_Theme * elm_obj_widget_theme_get(void);

EOAPI void  elm_obj_widget_disabled_set(Eina_Bool disabled);

EOAPI Eina_Bool  elm_obj_widget_disabled_get(void);

EOAPI void  elm_obj_widget_highlight_ignore_set(Eina_Bool ignore);

EOAPI Eina_Bool  elm_obj_widget_highlight_ignore_get(void);

/**
 * @brief Control the widget's mirrored mode setting.
 *
 * @param[in] automatic
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_mirrored_automatic_set(Eina_Bool automatic);

/** Control the widget's mirrored mode setting.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_mirrored_automatic_get(void);

EOAPI void  elm_obj_widget_orientation_mode_disabled_set(Eina_Bool disabled);

EOAPI Eina_Bool  elm_obj_widget_orientation_mode_disabled_get(void);

EOAPI Elm_Theme_Apply  elm_obj_widget_style_set(const char *style);

EOAPI const char * elm_obj_widget_style_get(void);

EOAPI void  elm_obj_widget_scale_set(double scale);

EOAPI double  elm_obj_widget_scale_get(void);

EOAPI void  elm_obj_widget_focus_custom_chain_set(Eina_List *objs);

EOAPI const Eina_List * elm_obj_widget_focus_custom_chain_get(void);

EOAPI void  elm_obj_widget_can_focus_set(Eina_Bool can_focus);

EOAPI Eina_Bool  elm_obj_widget_can_focus_get(void);

EOAPI void  elm_obj_widget_highlight_in_theme_set(Eina_Bool highlight);

EOAPI Eina_Bool  elm_obj_widget_highlight_in_theme_get(void);

EOAPI void  elm_obj_widget_parent_set(Evas_Object *parent);

EOAPI Evas_Object * elm_obj_widget_parent_get(void);

EOAPI void  elm_obj_widget_access_info_set(const char *txt);

EOAPI const char * elm_obj_widget_access_info_get(void);

EOAPI void  elm_obj_widget_drag_lock_x_set(Eina_Bool lock);

EOAPI Eina_Bool  elm_obj_widget_drag_lock_x_get(void);

EOAPI void  elm_obj_widget_access_highlight_in_theme_set(Eina_Bool highlight);

EOAPI Eina_Bool  elm_obj_widget_access_highlight_in_theme_get(void);

/**
 * @brief Control the focus_region_show mode.
 *
 * @param[in] mode
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_region_show_mode_set(Elm_Focus_Region_Show_Mode mode);

/** Control the focus_region_show mode.
 *
 * @ingroup Elm_Widget
 */
EOAPI Elm_Focus_Region_Show_Mode  elm_obj_widget_focus_region_show_mode_get(void);

EOAPI void  elm_obj_widget_parent_highlight_set(Eina_Bool highlighted);

EOAPI Elm_Theme_Apply  elm_obj_widget_theme_object_set(Evas_Object *edj, const char *wname, const char *welement, const char *wstyle);

EOAPI void  elm_obj_widget_hover_object_set(Evas_Object *sobj);

EOAPI void  elm_obj_widget_display_mode_set(Evas_Display_Mode dispmode);

EOAPI void  elm_obj_widget_on_show_region_hook_set(region_hook_func_type func, void *data);

EOAPI void  elm_obj_widget_domain_part_text_translatable_set(const char *part, const char *domain, Eina_Bool translatable);

EOAPI void  elm_obj_widget_orientation_set(int rotation);

EOAPI void  elm_obj_widget_resize_object_set(Evas_Object *sobj, Eina_Bool sub_obj);

EOAPI void  elm_obj_widget_domain_translatable_part_text_set(const char *part, const char *domain, const char *label);

/**
 * @brief Function to operate on a given widget's scrollabe children when
 * necessary.
 *
 * @warning free the returned list with eina_list_free().
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_List * elm_obj_widget_scrollable_children_get(void);

EOAPI int  elm_obj_widget_scroll_hold_get(void);

EOAPI int  elm_obj_widget_drag_child_locked_y_get(void);

/**
 * @brief Control item loop feature.
 *
 * @param[in] enable
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_item_loop_enabled_set(Eina_Bool enable);

/** Control item loop feature.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_item_loop_enabled_get(void);

EOAPI Eina_Bool  elm_obj_widget_child_can_focus_get(void);

EOAPI int  elm_obj_widget_scroll_freeze_get(void);

EOAPI Eina_Bool  elm_obj_widget_focus_region_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

EOAPI Evas_Object * elm_obj_widget_top_get(void);

EOAPI unsigned int  elm_obj_widget_focus_order_get(void);

EOAPI int  elm_obj_widget_drag_child_locked_x_get(void);

EOAPI Eina_List * elm_obj_widget_can_focus_child_list_get(void);

/** Get the focused widget item.
 *
 * @ingroup Elm_Widget
 */
EOAPI Elm_Widget_Item * elm_obj_widget_focused_item_get(void);

EOAPI void  elm_obj_widget_parents_bounce_get(Eina_Bool *horiz, Eina_Bool *vert);

EOAPI Eina_Bool  elm_obj_widget_highlight_get(void);

EOAPI Evas_Object * elm_obj_widget_focused_object_get(void);

EOAPI void  elm_obj_widget_parent2_set(Evas_Object *parent);

EOAPI Evas_Object * elm_obj_widget_parent2_get(void);

EOAPI void  elm_obj_widget_part_text_set(const char * part, const char *label);

EOAPI const char * elm_obj_widget_part_text_get(const char * part);

/**
 * @brief Sets the widget's focus move policy.
 *
 * @param[in] policy Object's focus move policy.
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_move_policy_set(Elm_Focus_Move_Policy policy);

/**
 * @brief Returns the widget's focus move policy.
 *
 * @return Object's focus move policy.
 *
 * @ingroup Elm_Widget
 */
EOAPI Elm_Focus_Move_Policy  elm_obj_widget_focus_move_policy_get(void);

/**
 * @brief Control the widget's focus_move_policy mode setting.
 *
 * @param[in] automatic @c true to follow system focus move policy change,
 * @c false otherwise
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_move_policy_automatic_set(Eina_Bool automatic);

/**
 * @brief Control the widget's focus_move_policy mode setting.
 *
 * @return @c true to follow system focus move policy change, @c false
 * otherwise
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_focus_move_policy_automatic_get(void);

EOAPI Eina_Bool  elm_obj_widget_class_color_set(const char * color_class, int r, int g, int b, int a);

EOAPI Eina_Bool  elm_obj_widget_class_color_get(const char * color_class, int *r, int *g, int *b, int *a);

EOAPI Eina_Bool  elm_obj_widget_class_color2_set(const char * color_class, int r, int g, int b, int a);

EOAPI Eina_Bool  elm_obj_widget_class_color2_get(const char * color_class, int *r, int *g, int *b, int *a);

EOAPI Eina_Bool  elm_obj_widget_class_color3_set(const char * color_class, int r, int g, int b, int a);

EOAPI Eina_Bool  elm_obj_widget_class_color3_get(const char * color_class, int *r, int *g, int *b, int *a);

EOAPI Evas_Object * elm_obj_widget_newest_focus_order_get(unsigned int *newest_focus_order, Eina_Bool can_focus_only);

EOAPI void  elm_obj_widget_scroll_hold_push(void);

EOAPI void  elm_obj_widget_cursor_add(Elm_Cursor *cur);

/**
 * @brief Set the next object with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @since 1.8
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_next_object_set(Evas_Object *next, Elm_Focus_Direction dir);

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
EOAPI Evas_Object * elm_obj_widget_focus_next_object_get(Elm_Focus_Direction dir);

/**
 * @brief Set the next object item with specific focus direction.
 *
 * @param[in] dir Focus direction
 *
 * @since 1.16
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_next_item_set(Elm_Object_Item *next_item, Elm_Focus_Direction dir);

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
EOAPI Elm_Object_Item * elm_obj_widget_focus_next_item_get(Elm_Focus_Direction dir);

EOAPI void  elm_obj_widget_focus_tree_unfocusable_handle(void);

EOAPI void  elm_obj_widget_focus_custom_chain_prepend(Evas_Object *child, Evas_Object *relative_child);

EOAPI const char * elm_obj_widget_part_text_translate(const char *part, const char *text);

/**
 * @brief Get the focus highlight geometry of widget.
 *
 * @param[in] y
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_highlight_geometry_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief 'Virtual' function to activate widget.
 *
 * @param[in] act
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_activate(Elm_Activate act);

/**
 * @brief 'Virtual' function handling sub objects being added.
 *
 * @param[in] sobj
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_sub_object_add(Evas_Object *sobj);

/** 'Virtual' function which checks if handling of passing focus to sub-objects
 * in given direction is supported by widget.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_focus_direction_manager_is(void);

/**
 * @brief 'Virtual' function handling input events on the widget.
 *
 * @param[in] type
 * @param[in] event_info
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_event(Evas_Object *source, Evas_Callback_Type type, void *event_info);

EOAPI void  elm_obj_widget_event_callback_add(Elm_Event_Cb func, const void *data);

/**
 * @brief 'Virtual' function on the widget being set access.
 *
 * @param[in] acs
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_access(Eina_Bool acs);

/**
 * @brief 'Virtual' function on the widget being set access.
 *
 * @param[in] is_atspi
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_atspi(Eina_Bool is_atspi);

EOAPI void  elm_obj_widget_cursor_del(Elm_Cursor *cur);

EOAPI void * elm_obj_widget_event_callback_del(Elm_Event_Cb func, const void *data);

/**
 * @brief 'Virtual' function handling focus in/out events on the widget.
 *  return true if this widget can handle focus, false otherwise
 *
 * @param[in] item
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_on_focus(Elm_Object_Item *item);

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
EOAPI Eina_Bool  elm_obj_widget_on_focus_region(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

EOAPI void  elm_obj_widget_focus_cycle(Elm_Focus_Direction dir);

EOAPI Eina_Bool  elm_obj_widget_event_propagate(Evas_Callback_Type type, void *event_info, Evas_Event_Flags *event_flags);

EOAPI void  elm_obj_widget_signal_callback_add(const char *emission, const char *source, Edje_Signal_Cb func, void *data);

/** 'Virtual' function which checks if handling of passing focus to sub-objects
 * is supported by widget.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_focus_next_manager_is(void);

EOAPI Evas_Object * elm_obj_widget_name_find(const char *name, int recurse);

EOAPI Eina_Bool  elm_obj_widget_focus_list_direction_get(const Evas_Object *base, const Eina_List *items, list_data_get_func_type list_data_get, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);

EOAPI void  elm_obj_widget_focused_object_clear(void);

EOAPI Eina_Bool  elm_obj_widget_focus_direction_go(double degree);

EOAPI void  elm_obj_widget_show_region_set(Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h, Eina_Bool forceshow);

EOAPI void  elm_obj_widget_show_region_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

EOAPI void  elm_obj_widget_scroll_freeze_pop(void);

EOAPI void  elm_obj_widget_tooltip_del(Elm_Tooltip *tt);

EOAPI Eina_Bool  elm_obj_widget_focus_next_get(Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);

EOAPI const char * elm_obj_widget_translatable_part_text_get(const char *part);

/**
 * @brief Restore the focus state of the sub-tree.
 *
 * This API will restore the focus state of the sub-tree to the latest state.
 * If a sub-tree is unfocused and wants to get back to the latest focus state,
 * this API will be helpful.
 *
 * @ingroup Elm_Widget
 */
EOAPI void  elm_obj_widget_focus_restore(void);

EOAPI void  elm_obj_widget_scroll_hold_pop(void);

/** 'Virtual' function handling language changes on Elementary.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_translate(void);

EOAPI void  elm_obj_widget_scroll_freeze_push(void);

EOAPI void  elm_obj_widget_focus_custom_chain_unset(void);

EOAPI void  elm_obj_widget_focus_steal(Elm_Object_Item *item);

EOAPI void  elm_obj_widget_focus_hide_handle(void);

EOAPI Eina_Bool  elm_obj_widget_focus_list_next_get(const Eina_List *items, list_data_get_func_type list_data_get, Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item);

EOAPI void  elm_obj_widget_focus_mouse_up_handle(void);

/** 'Virtual' function on the widget being re-themed.
 *
 * @ingroup Elm_Widget
 */
EOAPI Elm_Theme_Apply  elm_obj_widget_theme_apply(void);

EOAPI Eina_Bool  elm_obj_widget_focus_direction_get(const Evas_Object *base, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight);

EOAPI void * elm_obj_widget_signal_callback_del(const char *emission, const char *source, Edje_Signal_Cb func);

EOAPI void  elm_obj_widget_signal_emit(const char *emission, const char *source);

/** 'Virtual' function on the widget being disabled.
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_disable(void);

/**
 * @brief 'Virtual' function handling sub objects being removed.
 *
 * @param[in] sobj
 *
 * @ingroup Elm_Widget
 */
EOAPI Eina_Bool  elm_obj_widget_sub_object_del(Evas_Object *sobj);

EOAPI void  elm_obj_widget_tooltip_add(Elm_Tooltip *tt);

EOAPI void  elm_obj_widget_focus_region_show(void);

EOAPI void  elm_obj_widget_focus_disabled_handle(void);

EOAPI void  elm_obj_widget_focus_custom_chain_append(Evas_Object *child, Evas_Object *relative_child);

EOAPI void  elm_obj_widget_focus_reconfigure(void);

/**
 * @brief Get the access object of given part of the widget.
 *
 * @param[in] part The object's part name to get access object
 *
 * @since 1.18
 *
 * @ingroup Elm_Widget
 */
EOAPI Evas_Object * elm_obj_widget_part_access_object_get(const char *part);

EOAPI void  elm_obj_widget_class_color_del(const char *color_class);

EOAPI void  elm_obj_widget_class_color_clear(void);

EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_MOVED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_FOCUSED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_UNFOCUSED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_ATSPI_HIGHLIGHTED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_ATSPI_UNHIGHLIGHTED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIDGET_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_WIDGET_EVENT_MOVED (&(_ELM_WIDGET_EVENT_MOVED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_FOCUSED (&(_ELM_WIDGET_EVENT_FOCUSED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_UNFOCUSED (&(_ELM_WIDGET_EVENT_UNFOCUSED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_ATSPI_HIGHLIGHTED (&(_ELM_WIDGET_EVENT_ATSPI_HIGHLIGHTED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_ATSPI_UNHIGHLIGHTED (&(_ELM_WIDGET_EVENT_ATSPI_UNHIGHLIGHTED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_LANGUAGE_CHANGED (&(_ELM_WIDGET_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_WIDGET_EVENT_ACCESS_CHANGED (&(_ELM_WIDGET_EVENT_ACCESS_CHANGED))

#endif
