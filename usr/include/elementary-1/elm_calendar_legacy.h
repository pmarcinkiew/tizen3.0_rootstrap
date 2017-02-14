/**
 * @MOBILE_ONLY
 *
 * Add a new calendar widget to the given parent Elementary
 * (container) object.
 *
 * @param parent The parent object.
 * @return a new calendar widget handle or @c NULL, on errors.
 *
 * This function inserts a new calendar widget on the canvas.
 *
 * @ref calendar_example_01
 *
 * @ingroup Calendar
 *
 * @if MOBILE @since_tizen 2.4
 * @endif
 */
EAPI Evas_Object         *elm_calendar_add(Evas_Object *parent);

#include "elm_calendar.eo.legacy.h"