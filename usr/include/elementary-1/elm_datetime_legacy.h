/**
 * @brief Adds a new datetime Widget
 *
 * The default datetime format and corresponding strings are based on current locale.
 *
 * @param parent The parent object
 * @return The new object or NULL if it cannot be created
 *
 * This function inserts a new datetime widget on the canvas.
 *
 * @ingroup Datetime
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI Evas_Object *elm_datetime_add(Evas_Object *parent);

#include "elm_datetime.eo.legacy.h"
