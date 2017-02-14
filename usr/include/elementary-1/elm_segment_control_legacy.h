/**
 * @MOBILE_ONLY
 *
 * Add a new segment control widget to the given parent Elementary
 * (container) object.
 *
 * @param parent The parent object.
 * @return a new segment control widget handle or @c NULL, on errors.
 *
 * This function inserts a new segment control widget on the canvas.
 *
 * @ingroup SegmentControl
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI Evas_Object      *elm_segment_control_add(Evas_Object *parent);

#include "elm_segment_control_item.eo.legacy.h"
#include "elm_segment_control.eo.legacy.h"
