#ifndef _ELM_BOX_EO_H_
#define _ELM_BOX_EO_H_

#ifndef _ELM_BOX_EO_CLASS_TYPE
#define _ELM_BOX_EO_CLASS_TYPE

typedef Eo Elm_Box;

#endif

#ifndef _ELM_BOX_EO_TYPES
#define _ELM_BOX_EO_TYPES


#endif
#define ELM_BOX_CLASS elm_box_class_get()

EAPI const Eo_Class *elm_box_class_get(void) EINA_CONST;

/**
 * @brief Set the box to arrange its children homogeneously
 *
 * If enabled, homogeneous layout makes all items the same size, according to
 * the size of the largest of its children.
 *
 * @note This flag is ignored if a custom layout function is set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] homogeneous The homogeneous flag
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_homogeneous_set(Eina_Bool homogeneous);

/**
 * @brief Get whether the box is using homogeneous mode or not ($true if it's
 * homogeneous, @c false otherwise)
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The homogeneous flag
 *
 * @ingroup Elm_Box
 */
EOAPI Eina_Bool  elm_obj_box_homogeneous_get(void);

/**
 * @brief Set the alignment of the whole bounding box of contents.
 *
 * Sets how the bounding box containing all the elements of the box, after
 * their sizes and position has been calculated, will be aligned within the
 * space given for the whole box widget.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal The horizontal alignment of elements
 * @param[in] vertical The vertical alignment of elements
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_align_set(double horizontal, double vertical);

/**
 * @brief Get the alignment of the whole bounding box of contents.
 *
 * See also @ref elm_obj_box_align_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] horizontal The horizontal alignment of elements
 * @param[out] vertical The vertical alignment of elements
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_align_get(double *horizontal, double *vertical);

/**
 * @brief Set the horizontal orientation
 *
 * By default, box object arranges their contents vertically from top to
 * bottom. By calling this function with @c horizontal as @c true, the box will
 * become horizontal, arranging contents from left to right.
 *
 * @note This flag is ignored if a custom layout function is set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal The horizontal flag
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_horizontal_set(Eina_Bool horizontal);

/**
 * @brief Get the horizontal orientation ($true if the box is set to horizontal
 * mode, @c false otherwise)
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The horizontal flag
 *
 * @ingroup Elm_Box
 */
EOAPI Eina_Bool  elm_obj_box_horizontal_get(void);

/**
 * @brief Set the space (padding) between the box's elements.
 *
 * Extra space in pixels that will be added between a box child and its
 * neighbors after its containing cell has been calculated. This padding is set
 * for all elements in the box, besides any possible padding that individual
 * elements may have through their size hints.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal The horizontal space between elements
 * @param[in] vertical The vertical space between elements
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_padding_set(Evas_Coord horizontal, Evas_Coord vertical);

/**
 * @brief Get the space (padding) between the box's elements.
 *
 * See also @ref elm_obj_box_padding_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] horizontal The horizontal space between elements
 * @param[out] vertical The vertical space between elements
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_padding_get(Evas_Coord *horizontal, Evas_Coord *vertical);

/**
 * @brief Set the layout defining function to be used by the box
 *
 * Whenever anything changes that requires the box in @c obj to recalculate the
 * size and position of its elements, the function @c cb will be called to
 * determine what the layout of the children will be.
 *
 * Once a custom function is set, everything about the children layout is
 * defined by it. The flags set by @ref elm_obj_box_horizontal_set and
 * @ref elm_obj_box_homogeneous_set no longer have any meaning, and the values
 * given by @ref elm_obj_box_padding_set and @ref elm_obj_box_align_set are up
 * to this layout function to decide if they are used and how. These last two
 * will be found in the @c priv parameter, of type @c Evas_Object_Box_Data,
 * passed to @c cb. The @c Evas_Object the function receives is not the
 * Elementary widget, but the internal Evas Box it uses, so none of the
 * functions described here can be used on it.
 *
 * Any of the layout functions in @c Evas can be used here, as well as the
 * special @ref elm_box_layout_transition.
 *
 * The final @c data argument received by @c cb is the same @c data passed
 * here, and the @c free_data function will be called to free it whenever the
 * box is destroyed or another layout function is set.
 *
 * Setting @c cb to @c null will revert back to the default layout function.
 *
 * See also @ref elm_box_layout_transition.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] cb The callback function used for layout
 * @param[in] data Data that will be passed to layout function
 * @param[in] free_data Function called to free @c data
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_layout_set(Evas_Object_Box_Layout cb, const void *data, Ecore_Cb free_data);

/**
 * @brief Get a list of the objects packed into the box
 *
 * Returns a new @c list with a pointer to @c Evas_Object in its nodes. The
 * order of the list corresponds to the packing order the box uses.
 *
 * You must free this list with eina_list_free() once you are done with it.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Box
 */
EOAPI Eina_List * elm_obj_box_children_get(void);

/**
 * @brief Add an object at the end of the pack list
 *
 * Pack @c subobj into the box @c obj, placing it last in the list of children
 * objects. The actual position the object will get on screen depends on the
 * layout used. If no custom layout is set, it will be at the bottom or right,
 * depending if the box is vertical or horizontal, respectively.
 *
 * See also @ref elm_obj_box_pack_start, @ref elm_obj_box_pack_before,
 * @ref elm_obj_box_pack_after, @ref elm_obj_box_unpack,
 * @ref elm_obj_box_unpack_all, @ref elm_obj_box_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The object to add to the box
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_pack_end(Evas_Object *subobj);

/**
 * @brief Remove all items from the box, without deleting them
 *
 * Clear the box from all children, but don't delete the respective objects. If
 * no other references of the box children exist, the objects will never be
 * deleted, and thus the application will leak the memory. Make sure when using
 * this function that you hold a reference to all the objects in the box
 * @c obj.
 *
 * See also @ref elm_obj_box_clear, @ref elm_obj_box_unpack.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_unpack_all(void);

/**
 * @brief Unpack a box item
 *
 * Remove the object given by @c subobj from the box @c obj without deleting
 * it.
 *
 * See also @ref elm_obj_box_unpack_all, @ref elm_obj_box_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The object to unpack
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_unpack(Evas_Object *subobj);

/**
 * @brief Adds an object to the box after the indicated object
 *
 * This will add the @c subobj to the box indicated after the object indicated
 * with @c after. If @c after is not already in the box, results are undefined.
 * After means either to the right of the indicated object or below it
 * depending on orientation.
 *
 * See also @ref elm_obj_box_pack_start, @ref elm_obj_box_pack_end,
 * @ref elm_obj_box_pack_before, @ref elm_obj_box_unpack,
 * @ref elm_obj_box_unpack_all, @ref elm_obj_box_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] after The object after which to add it
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_pack_after(Evas_Object *subobj, Evas_Object *after);

/**
 * @brief Add an object to the beginning of the pack list
 *
 * Pack @c subobj into the box @c obj, placing it first in the list of children
 * objects. The actual position the object will get on screen depends on the
 * layout used. If no custom layout is set, it will be at the top or left,
 * depending if the box is vertical or horizontal, respectively.
 *
 * See also @ref elm_obj_box_pack_end, @ref elm_obj_box_pack_before,
 * @ref elm_obj_box_pack_after, @ref elm_obj_box_unpack,
 * @ref elm_obj_box_unpack_all, @ref elm_obj_box_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The object to add to the box
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_pack_start(Evas_Object *subobj);

/**
 * @brief Force the box to recalculate its children packing.
 *
 * If any children was added or removed, box will not calculate the values
 * immediately rather leaving it to the next main loop iteration. While this is
 * great as it would save lots of recalculation, whenever you need to get the
 * position of a just added item you must force recalculate before doing so.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_recalculate(void);

/**
 * @brief Adds an object to the box before the indicated object
 *
 * This will add the @c subobj to the box indicated before the object indicated
 * with @c before. If @c before is not already in the box, results are
 * undefined. Before means either to the left of the indicated object or above
 * it depending on orientation.
 *
 * See also @ref elm_obj_box_pack_start, @ref elm_obj_box_pack_end,
 * @ref elm_obj_box_pack_after, @ref elm_obj_box_unpack,
 * @ref elm_obj_box_unpack_all, @ref elm_obj_box_clear.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] before The object before which to add it
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_pack_before(Evas_Object *subobj, Evas_Object *before);

/**
 * @brief Clear the box of all children
 *
 * Remove all the elements contained by the box, deleting the respective
 * objects.
 *
 * See also @ref elm_obj_box_unpack, @ref elm_obj_box_unpack_all.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Box
 */
EOAPI void  elm_obj_box_clear(void);

EOAPI extern const Eo_Event_Description _ELM_BOX_EVENT_CHILD_ADDED;
EOAPI extern const Eo_Event_Description _ELM_BOX_EVENT_CHILD_REMOVED;

/**
 * No description
 */
#define ELM_BOX_EVENT_CHILD_ADDED (&(_ELM_BOX_EVENT_CHILD_ADDED))

/**
 * No description
 */
#define ELM_BOX_EVENT_CHILD_REMOVED (&(_ELM_BOX_EVENT_CHILD_REMOVED))

#endif
