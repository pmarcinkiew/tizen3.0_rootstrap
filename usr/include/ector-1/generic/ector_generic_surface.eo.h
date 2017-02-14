#ifndef _ECTOR_GENERIC_SURFACE_EO_H_
#define _ECTOR_GENERIC_SURFACE_EO_H_

#ifndef _ECTOR_GENERIC_SURFACE_EO_CLASS_TYPE
#define _ECTOR_GENERIC_SURFACE_EO_CLASS_TYPE

typedef Eo Ector_Generic_Surface;

#endif

#ifndef _ECTOR_GENERIC_SURFACE_EO_TYPES
#define _ECTOR_GENERIC_SURFACE_EO_TYPES


#endif
#define ECTOR_GENERIC_SURFACE_CLASS ector_generic_surface_class_get()

EAPI const Eo_Class *ector_generic_surface_class_get(void) EINA_CONST;

EOAPI Ector_Renderer * ector_surface_renderer_factory_new(const Eo_Class *type);

/**
 * @brief This define where is (0,0) in pixels coordinate inside the surface
 *
 * @param[in] x
 * @param[in] y
 *
 * @ingroup Ector_Generic_Surface
 */
EOAPI void  ector_surface_reference_point_set(int x, int y);

/**
 * @brief Changes the size of the given Evas object.
 *
 * @param[in] w
 * @param[in] h
 *
 * @ingroup Ector_Generic_Surface
 */
EOAPI void  ector_surface_size_set(int w, int h);

/**
 * @brief Retrieves the (rectangular) size of the given Evas object.
 *
 * @param[out] w
 * @param[out] h
 *
 * @ingroup Ector_Generic_Surface
 */
EOAPI void  ector_surface_size_get(int *w, int *h);


#endif
