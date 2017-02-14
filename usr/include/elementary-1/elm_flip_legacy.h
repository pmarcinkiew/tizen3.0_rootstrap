/**
 * @MOBILE_ONLY
 *
 * @brief Add a new flip to the parent
 *
 * @param parent The parent object
 * @return The new object or NULL if it cannot be created
 *
 * @ingroup Flip
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI Evas_Object *elm_flip_add(Evas_Object *parent);

/**
 * @MOBILE_ONLY
 *
 * @brief Set flip perspective
 *
 * @param obj The flip object
 * @param foc The coordinate to set the focus on
 * @param x The X coordinate
 * @param y The Y coordinate
 *
 * @warning This function currently does nothing.
 *
 * @ingroup Flip
 *
 * @if MOBILE @since_tizen 2.3
 * @endif
 */
EAPI void                 elm_flip_perspective_set(Evas_Object *obj, Evas_Coord foc, Evas_Coord x, Evas_Coord y);

#include "elm_flip.eo.legacy.h"
