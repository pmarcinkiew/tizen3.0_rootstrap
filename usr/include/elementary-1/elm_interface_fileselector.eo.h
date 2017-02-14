#ifndef _ELM_INTERFACE_FILESELECTOR_EO_H_
#define _ELM_INTERFACE_FILESELECTOR_EO_H_

#ifndef _ELM_INTERFACE_FILESELECTOR_EO_CLASS_TYPE
#define _ELM_INTERFACE_FILESELECTOR_EO_CLASS_TYPE

typedef Eo Elm_Interface_Fileselector;

#endif

#ifndef _ELM_INTERFACE_FILESELECTOR_EO_TYPES
#define _ELM_INTERFACE_FILESELECTOR_EO_TYPES

/** Defines how a file selector widget is to layout its contents (file system
 * entries).
 *
 * @ingroup Elm_Fileselector
 */
typedef enum
{
  ELM_FILESELECTOR_LIST = 0, /** Layout as a list. */
  ELM_FILESELECTOR_GRID, /** Layout as a grid. */
  ELM_FILESELECTOR_LAST /** Sentinel (helper) value, not used. */
} Elm_Fileselector_Mode;

typedef enum
{
  ELM_FILESELECTOR_SORT_BY_FILENAME_ASC = 0,
  ELM_FILESELECTOR_SORT_BY_FILENAME_DESC,
  ELM_FILESELECTOR_SORT_BY_TYPE_ASC,
  ELM_FILESELECTOR_SORT_BY_TYPE_DESC,
  ELM_FILESELECTOR_SORT_BY_SIZE_ASC,
  ELM_FILESELECTOR_SORT_BY_SIZE_DESC,
  ELM_FILESELECTOR_SORT_BY_MODIFIED_ASC,
  ELM_FILESELECTOR_SORT_BY_MODIFIED_DESC,
  ELM_FILESELECTOR_SORT_LAST /** Sentinel (helper) value, not used. */
} Elm_Fileselector_Sort;


#endif
#define ELM_INTERFACE_FILESELECTOR_INTERFACE elm_interface_fileselector_interface_get()

EAPI const Eo_Class *elm_interface_fileselector_interface_get(void) EINA_CONST;

/**
 * @brief Enable/disable folder-only view for a given file selector widget
 *
 * @param[in] only
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_folder_only_set(Eina_Bool only);

/** Get whether folder-only view is set for a given file selector
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_folder_only_get(void);

/**
 * @brief Set, programmatically, the currently selected file/directory in the
 * given file selector widget
 *
 * @param[in] path
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_selected_set(const char *path);

/** Get the currently selected item's (full) path, in the given file the given
 * file selector widget
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI const char * elm_interface_fileselector_selected_get(void);

/**
 * @brief Set the size for the thumbnail of the file selector widget's view.
 *
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_thumbnail_size_set(Evas_Coord w, Evas_Coord h);

/**
 * @brief Get the size for the thumbnail of a given file selector widget
 *
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_thumbnail_size_get(Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Enable or disable visibility of hidden files/directories in the file
 * selector widget.
 *
 * @param[in] multi
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_hidden_visible_set(Eina_Bool multi);

/** Get if hiden files/directories in the file selector are visible or not.
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_hidden_visible_get(void);

/**
 * @brief Set the sort method of the file selector widget.
 *
 * @param[in] sort
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_sort_method_set(Elm_Fileselector_Sort sort);

/** Get the sort method of the file selector widget.
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Elm_Fileselector_Sort  elm_interface_fileselector_sort_method_get(void);

/**
 * @brief Enable or disable multi-selection in the fileselector
 *
 * @param[in] multi
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_multi_select_set(Eina_Bool multi);

/** Gets if multi-selection in fileselector is enabled or disabled.
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_multi_select_get(void);

/**
 * @brief Enable/disable a tree view in the given file selector widget, <b>if
 * it's in
 *
 * @param[in] expand
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_expandable_set(Eina_Bool expand);

/** Get whether tree view is enabled for the given file selector
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_expandable_get(void);

/**
 * @brief Set, programmatically, the directory that a given file selector
 * widget will display contents from
 *
 * @param[in] path
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_path_set(const char *path);

/** Get the parent directory's path that a given file selector selector widget
 * will display contents from
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI const char * elm_interface_fileselector_path_get(void);

/**
 * @brief Set the mode in which a given file selector widget will display
 * (layout) file system entries in its view
 *
 * @param[in] mode
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_mode_set(Elm_Fileselector_Mode mode);

/** Get the mode in which a given file selector widget is displaying
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Elm_Fileselector_Mode  elm_interface_fileselector_mode_get(void);

/**
 * @brief Enable/disable the file name entry box where the user can type in a
 * name for a file, in a given file selector widget
 *
 * @param[in] is_save
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_is_save_set(Eina_Bool is_save);

/** Get whether the given file selector is in "saving dialog" mode
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_is_save_get(void);

/** Get a list of selected paths in the fileselector.
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI const Eina_List * elm_interface_fileselector_selected_paths_get(void);

EOAPI void  elm_interface_fileselector_current_name_set(const char *name);

EOAPI const char * elm_interface_fileselector_current_name_get(void);

/**
 * @brief Append custom filter into filter list
 *
 * @param[in] data
 * @param[in] filter_name
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_custom_filter_append(Elm_Fileselector_Filter_Func func, void *data, const char *filter_name);

/** Clear all filters registered
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI void  elm_interface_fileselector_filters_clear(void);

/**
 * @brief Append mime type based filter into filter list
 *
 * @param[in] filter_name
 *
 * @ingroup Elm_Interface_Fileselector
 */
EOAPI Eina_Bool  elm_interface_fileselector_mime_types_filter_append(const char *mime_types, const char *filter_name);


#endif
