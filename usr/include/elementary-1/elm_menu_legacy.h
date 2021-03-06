/**
 * @internal
 *
 * @brief Add a new menu to the parent
 *
 * @param parent The parent object.
 * @return The new object or NULL if it cannot be created.
 *
 * @ingroup Menu
 */
EAPI Evas_Object                 *elm_menu_add(Evas_Object *parent);

/**
 * @internal
 *
 * @brief Set the parent for the given menu widget
 *
 * @param obj The menu object.
 * @param parent The new parent.
 *
 * @ingroup Menu
 */
EAPI void                         elm_menu_parent_set(Evas_Object *obj, Evas_Object *parent);

/**
 * @internal
 *
 * @brief Get the parent for the given menu widget
 *
 * @param obj The menu object.
 * @return The parent.
 *
 * @see elm_menu_parent_set()
 *
 * @ingroup Menu
 */
EAPI Evas_Object                 *elm_menu_parent_get(const Evas_Object *obj);

#include "elm_menu_item.eo.legacy.h"
#include "elm_menu.eo.legacy.h"
