/**
 * Add a new index widget to the given parent Elementary
 * (container) object
 *
 * @param parent The parent object
 * @return a new index widget handle or @c NULL, on errors
 *
 * This function inserts a new index widget on the canvas.
 *
 * @ingroup Index
 *
 * @if MOBILE @since_tizen 2.3
 * @elseif WEARABLE @since_tizen 2.3.1
 * @endif
 */
EAPI Evas_Object          *elm_index_add(Evas_Object *parent);

#include "elm_index_item.eo.legacy.h"
#include "elm_index.eo.legacy.h"
