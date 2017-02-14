#ifndef _ECTOR_SOFTWARE_SURFACE_EO_H_
#define _ECTOR_SOFTWARE_SURFACE_EO_H_

#ifndef _ECTOR_SOFTWARE_SURFACE_EO_CLASS_TYPE
#define _ECTOR_SOFTWARE_SURFACE_EO_CLASS_TYPE

typedef Eo Ector_Software_Surface;

#endif

#ifndef _ECTOR_SOFTWARE_SURFACE_EO_TYPES
#define _ECTOR_SOFTWARE_SURFACE_EO_TYPES


#endif
#define ECTOR_SOFTWARE_SURFACE_CLASS ector_software_surface_class_get()

EAPI const Eo_Class *ector_software_surface_class_get(void) EINA_CONST;

EOAPI void  ector_software_surface_context_set(Software_Rasterizer *ctx);

EOAPI Software_Rasterizer * ector_software_surface_context_get(void);

EOAPI void  ector_software_surface_set(void *pixels, unsigned int width, unsigned int height, unsigned int stride);

EOAPI void  ector_software_surface_get(void **pixels, unsigned int *width, unsigned int *height, unsigned int *stride);


#endif
