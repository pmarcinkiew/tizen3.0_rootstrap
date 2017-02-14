#ifndef _ELM_SYSTRAY_EO_LEGACY_H_
#define _ELM_SYSTRAY_EO_LEGACY_H_

#ifndef _ELM_SYSTRAY_EO_CLASS_TYPE
#define _ELM_SYSTRAY_EO_CLASS_TYPE

typedef Eo Elm_Systray;

#endif

#ifndef _ELM_SYSTRAY_EO_TYPES
#define _ELM_SYSTRAY_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief Set the id of the Status Notifier Item.
 *
 * @param[in] id
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_id_set(Elm_Systray *obj, const char *id);

/**
 * @internal
 *
 * Get the id of the Status Notifier Item.
 *
 * @ingroup Elm_Systray
 */
EAPI const char *elm_systray_id_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the category of the Status Notifier Item.
 *
 * @param[in] cat Category
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_category_set(Elm_Systray *obj, Elm_Systray_Category cat);

/**
 * @internal
 *
 * @brief Get the category of the Status Notifier Item.
 *
 * @return Category
 *
 * @ingroup Elm_Systray
 */
EAPI Elm_Systray_Category elm_systray_category_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the path to the theme where the icons can be
 * found. Set this value to "" to use the default path.
 *
 * @param[in] icon_theme_path
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_icon_theme_path_set(Elm_Systray *obj, const char *icon_theme_path);

/**
 * @internal
 *
 * Get the path to the icon's theme currently in use.
 *
 * @ingroup Elm_Systray
 */
EAPI const char *elm_systray_icon_theme_path_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the object path of the D-Bus Menu that is to be
 * show when the Status Notifier Item is activated by the user.
 *
 * @param[in] menu
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_menu_set(Elm_Systray *obj, const Eo *menu);

/**
 * @internal
 *
 * Get the object path of the D-Bus Menu currently in use.
 *
 * @ingroup Elm_Systray
 */
EAPI const Eo *elm_systray_menu_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the name of the attention icon to be used by
 * the Status Notifier Item.
 *
 * @param[in] att_icon_name
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_att_icon_name_set(Elm_Systray *obj, const char *att_icon_name);

/**
 * @internal
 *
 * Get the name of the attention icon used by the Status Notifier Item.
 *
 * @ingroup Elm_Systray
 */
EAPI const char *elm_systray_att_icon_name_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the status of the Status Notifier Item.
 *
 * @param[in] st Status
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_status_set(Elm_Systray *obj, Elm_Systray_Status st);

/**
 * @internal
 *
 * @brief Get the status of the Status Notifier Item.
 *
 * @return Status
 *
 * @ingroup Elm_Systray
 */
EAPI Elm_Systray_Status elm_systray_status_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the name of the icon to be used by the Status
 * Notifier Item.
 *
 * @param[in] icon_name
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_icon_name_set(Elm_Systray *obj, const char *icon_name);

/**
 * @internal
 *
 * Get the name of the icon used by the Status Notifier Item.
 *
 * @ingroup Elm_Systray
 */
EAPI const char *elm_systray_icon_name_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * @brief Set the title of the Status Notifier Item.
 *
 * @param[in] title
 *
 * @ingroup Elm_Systray
 */
EAPI void elm_systray_title_set(Elm_Systray *obj, const char *title);

/**
 * @internal
 *
 * Get the title of the Status Notifier Item.
 *
 * @ingroup Elm_Systray
 */
EAPI const char *elm_systray_title_get(const Elm_Systray *obj);

/**
 * @internal
 *
 * Register this Status Notifier Item in the System Tray Watcher. This
 * function should only be called after the event #ELM_EVENT_SYSTRAY_READY is
 * emitted.
 *
 * @ingroup Elm_Systray
 */
EAPI Eina_Bool elm_systray_register(Elm_Systray *obj);

#endif
