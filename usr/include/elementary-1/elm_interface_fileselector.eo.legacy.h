#ifndef _ELM_INTERFACE_FILESELECTOR_EO_LEGACY_H_
#define _ELM_INTERFACE_FILESELECTOR_EO_LEGACY_H_

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

#endif
