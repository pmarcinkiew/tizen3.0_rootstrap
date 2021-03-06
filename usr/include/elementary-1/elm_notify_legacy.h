/**
 * @brief Add a new notify to the parent
 *
 * @param parent The parent object
 * @return The new object or NULL if it cannot be created
 *
 * @ingroup Notify
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI Evas_Object                 *elm_notify_add(Evas_Object *parent);

/**
 * @brief Set the notify parent
 *
 * @param obj The notify object
 * @param parent The new parent
 *
 * Once the parent object is set, a previously set one will be disconnected
 * and replaced.
 *
 * @ingroup Notify
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI void                         elm_notify_parent_set(Evas_Object *obj, Evas_Object *parent);

/**
 * @brief Get the notify parent
 *
 * @param obj The notify object
 * @return The parent
 *
 * @see elm_notify_parent_set()
 *
 * @ingroup Notify
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI Evas_Object                 *elm_notify_parent_get(const Evas_Object *obj);

#include "elm_notify.eo.legacy.h"