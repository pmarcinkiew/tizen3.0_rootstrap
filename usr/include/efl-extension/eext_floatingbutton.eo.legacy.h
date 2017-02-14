#ifndef _EEXT_FLOATINGBUTTON_EO_LEGACY_H_
#define _EEXT_FLOATINGBUTTON_EO_LEGACY_H_

#ifndef _EEXT_FLOATINGBUTTON_EO_CLASS_TYPE
#define _EEXT_FLOATINGBUTTON_EO_CLASS_TYPE

typedef Eo Eext_Floatingbutton;

#endif

#ifndef _EEXT_FLOATINGBUTTON_EO_TYPES
#define _EEXT_FLOATINGBUTTON_EO_TYPES


#endif

/**
 * @brief Set the floatingbutton position
 *
 * The floatingbutton can be moved among predefined positions (LEFT_OUT, LEFT,
 * CENTER, RIGHT, RIGHT_OUT), eext_floatingbutton_pos_set() moves
 * floatingbutton to a given position immediately (without animation).
 *
 * return EINA_TRUE on success, EINA_FALSE otherwise.
 *
 * @param[in] pos the floatingbutton position
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI Eina_Bool eext_floatingbutton_pos_set(Eext_Floatingbutton *obj, Eext_Floatingbutton_Pos pos);

/**
 * @brief Get the floatingbutton position
 *
 * return Floatingbutton position with Eext_Floatingbutton_Pos enumeration
 *
 * see eext_floatingbutton_pos_set()
 *
 * @return the floatingbutton position
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI Eext_Floatingbutton_Pos eext_floatingbutton_pos_get(const Eext_Floatingbutton *obj);

/**
 * @brief Set whether floatingbutton can be moved or not.
 *
 * By default, floatingbutton are movable by user interaction.
 *
 * @param[in] block the floatingbutton movability
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI void eext_floatingbutton_movement_block_set(Eext_Floatingbutton *obj, Eina_Bool block);

/**
 * @brief Get movability for a given floatingbutton widget.
 *
 * return EINA_TRUE, if obj is set to be unmovable, EINA_FALSE, if it's
 * movable.
 *
 * see eext_floatingbutton_movement_block_set()
 *
 * @return the floatingbutton movability
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI Eina_Bool eext_floatingbutton_movement_block_get(const Eext_Floatingbutton *obj);

/**
 * @brief Set floatingbutton mode.
 *
 * Positions where floatingbutton can stop are restrained by mode.
 *
 * @param[in] mode floatingbutton mode
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI void eext_floatingbutton_mode_set(Eext_Floatingbutton *obj, Eext_Floatingbutton_Mode mode);

/**
 * @brief Get floatingbutton mode.
 *
 * see eext_floatingbutton_mode_set()
 *
 * @return floatingbutton mode
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI Eext_Floatingbutton_Mode eext_floatingbutton_mode_get(const Eext_Floatingbutton *obj);

/**
 * @brief Set the floatingbutton position with animation
 *
 * Move floatingbutton similar to eext_floatingbutton_pos_set(), but with
 * animation.
 *
 * return EINA_TRUE on success, EINA_FALSE otherwise.
 *
 * see eext_floatingbutton_pos_set()
 *
 * @param[in] pos the floatingbutton position
 *
 * @ingroup Eext_Floatingbutton
 */
EAPI Eina_Bool eext_floatingbutton_pos_bring_in(Eext_Floatingbutton *obj, const Eext_Floatingbutton_Pos pos);

#endif
