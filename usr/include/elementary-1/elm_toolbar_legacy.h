/**
 * @MOBILE_ONLY
 *
 * Add a new toolbar widget to the given parent Elementary
 * (container) object.
 *
 * @param parent The parent object.
 * @return a new toolbar widget handle or @c NULL, on errors.
 *
 * This function inserts a new toolbar widget on the canvas.
 *
 * @ingroup Toolbar
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI Evas_Object                 *elm_toolbar_add(Evas_Object *parent);

/**
 * @MOBILE_ONLY
 *
 * Set reorder mode
 *
 * @param obj The toolbar object
 * @param reorder_mode The reorder mode
 * (@c EINA_TRUE = on, @c EINA_FALSE = off)
 *
 * @ingroup Toolbar
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI void                          elm_toolbar_reorder_mode_set(Evas_Object *obj, Eina_Bool reorder_mode);

/**
 * @MOBILE_ONLY
 *
 * Get the reorder mode
 *
 * @param obj The toolbar object
 * @return The reorder mode
 * (@c EINA_TRUE = on, @c EINA_FALSE = off)
 *
 * @ingroup Toolbar
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI Eina_Bool                     elm_toolbar_reorder_mode_get(const Evas_Object *obj);

/**
 * @MOBILE_ONLY
 *
 * Set the item's transverse expansion of a given toolbar widget @p obj.
 *
 * @param obj The toolbar object.
 * @param transverse_expanded The transverse expansion of the item.
 * (@c EINA_TRUE = on, @c EINA_FALSE = off, default = @c EINA_FALSE)
 *
 * This will expand the transverse length of the item according the transverse length of the toolbar.
 * The default is what the transverse length of the item is set according its min value.
 *
 * @ingroup Toolbar
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI void                         elm_toolbar_transverse_expanded_set(Evas_Object *obj, Eina_Bool transverse_expanded);

/**
 * @MOBILE_ONLY
 *
 * Get the transverse expansion of toolbar @p obj.
 *
 * @param obj The toolbar object.
 * @return The transverse expansion of the item.
 * (@c EINA_TRUE = on, @c EINA_FALSE = off, default = @c EINA_FALSE)
 *
 * @see elm_toolbar_transverse_expand_set() for details.
 *
 * @ingroup Toolbar
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI Eina_Bool                    elm_toolbar_transverse_expanded_get(const Evas_Object *obj);

#include "elm_toolbar_item.eo.legacy.h"
#include "elm_toolbar.eo.legacy.h"
