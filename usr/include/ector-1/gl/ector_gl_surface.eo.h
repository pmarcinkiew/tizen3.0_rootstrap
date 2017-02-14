#ifndef _ECTOR_GL_SURFACE_EO_H_
#define _ECTOR_GL_SURFACE_EO_H_

#ifndef _ECTOR_GL_SURFACE_EO_CLASS_TYPE
#define _ECTOR_GL_SURFACE_EO_CLASS_TYPE

typedef Eo Ector_Gl_Surface;

#endif

#ifndef _ECTOR_GL_SURFACE_EO_TYPES
#define _ECTOR_GL_SURFACE_EO_TYPES


#endif
#define ECTOR_GL_SURFACE_CLASS ector_gl_surface_class_get()

EAPI const Eo_Class *ector_gl_surface_class_get(void) EINA_CONST;

EOAPI void  ector_gl_surface_context_info_set(int width, int height, int rotation, Eina_Rectangle *clip, Eina_Bool clear);

EOAPI void  ector_gl_surface_vg_info_set(Eina_Rectangle *geom, int color);

EOAPI void  ector_gl_surface_draw_begin(void);

EOAPI void  ector_gl_surface_draw_end(void);


#endif
