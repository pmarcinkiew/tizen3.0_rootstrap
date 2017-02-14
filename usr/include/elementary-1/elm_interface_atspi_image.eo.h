#ifndef _ELM_INTERFACE_ATSPI_IMAGE_EO_H_
#define _ELM_INTERFACE_ATSPI_IMAGE_EO_H_

#ifndef _ELM_INTERFACE_ATSPI_IMAGE_EO_CLASS_TYPE
#define _ELM_INTERFACE_ATSPI_IMAGE_EO_CLASS_TYPE

typedef Eo Elm_Interface_Atspi_Image;

#endif

#ifndef _ELM_INTERFACE_ATSPI_IMAGE_EO_TYPES
#define _ELM_INTERFACE_ATSPI_IMAGE_EO_TYPES


#endif
#define ELM_INTERFACE_ATSPI_IMAGE_MIXIN elm_interface_atspi_image_mixin_get()

EAPI const Eo_Class *elm_interface_atspi_image_mixin_get(void) EINA_CONST;

#ifdef ELM_INTERFACE_ATSPI_IMAGE_PROTECTED
/**
 * @brief Gets an image extents.
 *
 * @param[in] screen_coords
 * @param[out] x
 * @param[out] y
 * @param[out] width
 * @param[out] height
 *
 * @ingroup Elm_Interface_Atspi_Image
 */
EOAPI void  elm_interface_atspi_image_extents_get(Eina_Bool screen_coords, int *x, int *y, int *width, int *height);
#endif

#ifdef ELM_INTERFACE_ATSPI_IMAGE_PROTECTED
EOAPI void  elm_interface_atspi_image_description_set(const char *description);
#endif

#ifdef ELM_INTERFACE_ATSPI_IMAGE_PROTECTED
/** Gets textual description of image
 *
 * @ingroup Elm_Interface_Atspi_Image
 */
EOAPI const char * elm_interface_atspi_image_description_get(void);
#endif

#ifdef ELM_INTERFACE_ATSPI_IMAGE_PROTECTED
/** Gets locale of the image description.
 *
 * @ingroup Elm_Interface_Atspi_Image
 */
EOAPI const char * elm_interface_atspi_image_locale_get(void);
#endif


#endif
