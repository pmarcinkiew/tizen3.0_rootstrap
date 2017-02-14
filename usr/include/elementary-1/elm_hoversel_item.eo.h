#ifndef _ELM_HOVERSEL_ITEM_EO_H_
#define _ELM_HOVERSEL_ITEM_EO_H_

#ifndef _ELM_HOVERSEL_ITEM_EO_CLASS_TYPE
#define _ELM_HOVERSEL_ITEM_EO_CLASS_TYPE

typedef Eo Elm_Hoversel_Item;

#endif

#ifndef _ELM_HOVERSEL_ITEM_EO_TYPES
#define _ELM_HOVERSEL_ITEM_EO_TYPES


#endif
#define ELM_HOVERSEL_ITEM_CLASS elm_hoversel_item_class_get()

EAPI const Eo_Class *elm_hoversel_item_class_get(void) EINA_CONST;

/**
 * @brief This controls the icon for the given hoversel item.
 *
 * The icon can be loaded from the standard set, from an image file, or from an
 * edje file.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[in] icon_file An image file path on disk to use for the icon or
 * standard icon name
 * @param[in] icon_group The edje group to use if @c icon_file is an edje file.
 * Set this to NULL if the icon is not an edje file
 * @param[in] icon_type The icon type
 *
 * @ingroup Elm_Hoversel_Item
 */
EOAPI void  elm_obj_hoversel_item_icon_set(const char *icon_file, const char *icon_group, Elm_Icon_Type icon_type);

/**
 * @brief This controls the icon for the given hoversel item.
 *
 * The icon can be loaded from the standard set, from an image file, or from an
 * edje file.
 *
 * @MOBILE_ONLY
 *
 * @if MOBILE @since_tizen 2.4 @endif
 *
 * @param[out] icon_file An image file path on disk to use for the icon or
 * standard icon name
 * @param[out] icon_group The edje group to use if @c icon_file is an edje
 * file. Set this to NULL if the icon is not an edje file
 * @param[out] icon_type The icon type
 *
 * @ingroup Elm_Hoversel_Item
 */
EOAPI void  elm_obj_hoversel_item_icon_get(const char **icon_file, const char **icon_group, Elm_Icon_Type *icon_type);


#endif
