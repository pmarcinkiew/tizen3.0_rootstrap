#ifndef _ELM_TABLE_EO_H_
#define _ELM_TABLE_EO_H_

#ifndef _ELM_TABLE_EO_CLASS_TYPE
#define _ELM_TABLE_EO_CLASS_TYPE

typedef Eo Elm_Table;

#endif

#ifndef _ELM_TABLE_EO_TYPES
#define _ELM_TABLE_EO_TYPES


#endif
#define ELM_TABLE_CLASS elm_table_class_get()

EAPI const Eo_Class *elm_table_class_get(void) EINA_CONST;

/**
 * @brief Control the homogenous state in a table.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] homogeneous A boolean to set if the layout is homogeneous in the
 * table.
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_homogeneous_set(Eina_Bool homogeneous);

/**
 * @brief Control the homogenous state in a table.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return A boolean to set if the layout is homogeneous in the table.
 *
 * @ingroup Elm_Table
 */
EOAPI Eina_Bool  elm_obj_table_homogeneous_get(void);

/**
 * @brief Set padding between cells. Default value is 0.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] horizontal The horizontal padding.
 * @param[in] vertical The vertical padding.
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_padding_set(Evas_Coord horizontal, Evas_Coord vertical);

/**
 * @brief Get padding between cells.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] horizontal The horizontal padding.
 * @param[out] vertical The vertical padding.
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_padding_get(Evas_Coord *horizontal, Evas_Coord *vertical);

/**
 * @brief Set alignment of table. Default value is 0.5.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] horizontal The horizontal alignment.
 * @param[in] vertical The vertical alignment.
 *
 * @since 1.13
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_align_set(double horizontal, double vertical);

/**
 * @brief Get alignment of table.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] horizontal The horizontal alignment.
 * @param[out] vertical The vertical alignment.
 *
 * @since 1.13
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_align_get(double *horizontal, double *vertical);

/**
 * @brief Faster way to remove all child objects from a table object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] clear If true, will delete children, else just remove from table.
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_clear(Eina_Bool clear);

/**
 * @brief Get child object of table at given coordinates.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] row Row number of child object.
 *
 * @return Child of object if find if not return @c null.
 *
 * @ingroup Elm_Table
 */
EOAPI Evas_Object * elm_obj_table_child_get(int col, int row);

/**
 * @brief Set the packing location of an existing child of the table
 *
 * Modifies the position of an object already in the table.
 *
 * @note All positioning inside the table is relative to rows and columns, so a
 * value of 0 for col and row, means the top left cell of the table, and a
 * value of 1 for colspan and rowspan means only takes that 1 cell.
 *
 * @param[in] column Column number.
 * @param[in] row Row number.
 * @param[in] colspan
 * @param[in] rowspan
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_pack_set(Evas_Object *subobj, int column, int row, int colspan, int rowspan);

/**
 * @brief Get the packing location of an existing child of the table.
 *
 * @param[out] column Column number.
 * @param[out] row Row number.
 * @param[out] colspan
 * @param[out] rowspan
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_pack_get(Evas_Object *subobj, int *column, int *row, int *colspan, int *rowspan);

/**
 * @brief Remove child from table.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The subobject.
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_unpack(Evas_Object *subobj);

/**
 * @brief Add a subobject on the table with the coordinates passed.
 *
 * @note All positioning inside the table is relative to rows and columns, so a
 * value of 0 for x and y, means the top left cell of the table, and a value of
 * 1 for w and h means @c subobj only takes that 1 cell.
 *
 * @note Columns and rows only guarantee 16bit unsigned values at best. That
 * means that col + colspan AND row + rowspan must fit inside 16bit unsigned
 * values cleanly. You will be warned once values exceed 15bit storage, and
 * attempting to use values not able to fit in 16bits will result in failure.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] column Column number.
 * @param[in] row Row number.
 * @param[in] colspan
 * @param[in] rowspan
 *
 * @ingroup Elm_Table
 */
EOAPI void  elm_obj_table_pack(Evas_Object *subobj, int column, int row, int colspan, int rowspan);


#endif
