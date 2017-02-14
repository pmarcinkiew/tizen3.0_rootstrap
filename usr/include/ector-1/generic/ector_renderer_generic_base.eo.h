#ifndef _ECTOR_RENDERER_GENERIC_BASE_EO_H_
#define _ECTOR_RENDERER_GENERIC_BASE_EO_H_

#ifndef _ECTOR_RENDERER_GENERIC_BASE_EO_CLASS_TYPE
#define _ECTOR_RENDERER_GENERIC_BASE_EO_CLASS_TYPE

typedef Eo Ector_Renderer_Generic_Base;

#endif

#ifndef _ECTOR_RENDERER_GENERIC_BASE_EO_TYPES
#define _ECTOR_RENDERER_GENERIC_BASE_EO_TYPES


#endif
#define ECTOR_RENDERER_GENERIC_BASE_CLASS ector_renderer_generic_base_class_get()

EAPI const Eo_Class *ector_renderer_generic_base_class_get(void) EINA_CONST;

EOAPI Eina_Bool  ector_renderer_draw(Ector_Rop op, Eina_Array *clips, unsigned int mul_col);

EOAPI void  ector_renderer_bounds_get(Eina_Rectangle *r);

EOAPI Eina_Bool  ector_renderer_done(void);

EOAPI void  ector_renderer_transformation_set(const Eina_Matrix3 *m);

EOAPI const Eina_Matrix3 * ector_renderer_transformation_get(void);

EOAPI void  ector_renderer_origin_set(double x, double y);

EOAPI void  ector_renderer_origin_get(double *x, double *y);

/**
 * @brief Makes the given Ector renderer visible or invisible.
 *
 * @param[in] v true if to make the object visible, false otherwise
 *
 * @ingroup Ector_Renderer_Generic_Base
 */
EOAPI void  ector_renderer_visibility_set(Eina_Bool v);

/**
 * @brief Retrieves whether or not the given Ector renderer is visible.
 *
 * @return true if to make the object visible, false otherwise
 *
 * @ingroup Ector_Renderer_Generic_Base
 */
EOAPI Eina_Bool  ector_renderer_visibility_get(void);

/**
 * @brief Sets the general/main color of the given Ector renderer to the given
 * one.
 *
 * These color values are expected to be premultiplied by alpha.
 *
 * @param[in] r The red component of the given color.
 * @param[in] g The green component of the given color.
 * @param[in] b The blue component of the given color.
 * @param[in] a The alpha component of the given color.
 *
 * @ingroup Ector_Renderer_Generic_Base
 */
EOAPI void  ector_renderer_color_set(int r, int g, int b, int a);

/**
 * @brief Retrieves the general/main color of the given Ector renderer.
 *
 * Retrieves the main color's RGB component (and alpha channel) values, which
 * range from 0 to 255. For the alpha channel, which defines the object's
 * transparency level, 0 means totally transparent, while 255 means opaque.
 * These color values are premultiplied by the alpha value.
 *
 * Use null pointers on the components you're not interested in, they'll be
 * ignored by the function.
 *
 * @param[out] r The red component of the given color.
 * @param[out] g The green component of the given color.
 * @param[out] b The blue component of the given color.
 * @param[out] a The alpha component of the given color.
 *
 * @ingroup Ector_Renderer_Generic_Base
 */
EOAPI void  ector_renderer_color_get(int *r, int *g, int *b, int *a);

EOAPI void  ector_renderer_mask_set(Ector_Renderer *r);

EOAPI Ector_Renderer * ector_renderer_mask_get(void);

EOAPI void  ector_renderer_quality_set(Ector_Quality q);

EOAPI Ector_Quality  ector_renderer_quality_get(void);

EOAPI unsigned int  ector_renderer_crc_get(void);

EOAPI Eina_Bool  ector_renderer_prepare(void);


#endif
