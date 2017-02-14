#ifndef _ELM_BUBBLE_EO_LEGACY_H_
#define _ELM_BUBBLE_EO_LEGACY_H_

#ifndef _ELM_BUBBLE_EO_CLASS_TYPE
#define _ELM_BUBBLE_EO_CLASS_TYPE

typedef Eo Elm_Bubble;

#endif

#ifndef _ELM_BUBBLE_EO_TYPES
#define _ELM_BUBBLE_EO_TYPES

/**
 * @brief Defines the corner values for a bubble.
 *
 * The corner will be used to determine where the arrow of the bubble points
 * to.
 *
 * @ingroup Elm_Bubble
 */
typedef enum
{
  ELM_BUBBLE_POS_INVALID = -1 /* -0 */, /** Invalid corner. */
  ELM_BUBBLE_POS_TOP_LEFT, /** The arrow of the bubble points to the top left
                            * corner. */
  ELM_BUBBLE_POS_TOP_RIGHT, /** The arrow of the bubble points to the top right
                             * corner. */
  ELM_BUBBLE_POS_BOTTOM_LEFT, /** The arrow of the bubble points to the bottom
                               * left corner. */
  ELM_BUBBLE_POS_BOTTOM_RIGHT /** The arrow of the bubble points to the bottom
                               * right corner. */
} Elm_Bubble_Pos;


#endif

/**
 * @internal
 *
 * @brief Set the corner of the bubble
 *
 * This function sets the corner of the bubble. The corner will be used to
 * determine where the arrow in the frame points to and where label, icon and
 * info are shown.
 *
 * @param[in] pos The given corner for the bubble.
 *
 * @ingroup Elm_Bubble
 */
EAPI void elm_bubble_pos_set(Elm_Bubble *obj, Elm_Bubble_Pos pos);

/**
 * @internal
 *
 * @brief Get the corner of the bubble
 *
 * This function gets the selected corner of the bubble.
 *
 * @return The given corner for the bubble.
 *
 * @ingroup Elm_Bubble
 */
EAPI Elm_Bubble_Pos elm_bubble_pos_get(const Elm_Bubble *obj);

#endif
