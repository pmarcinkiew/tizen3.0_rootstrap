/**
 * Add a new box to the parent
 *
 * By default, the box will be in vertical mode and non-homogeneous.
 *
 * @param parent The parent object
 * @return The new object or NULL if it cannot be created
 *
 * @ingroup Box
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI Evas_Object        *elm_box_add(Evas_Object *parent);

#include "elm_box.eo.legacy.h"