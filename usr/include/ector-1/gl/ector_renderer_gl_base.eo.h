#ifndef _ECTOR_RENDERER_GL_BASE_EO_H_
#define _ECTOR_RENDERER_GL_BASE_EO_H_

#ifndef _ECTOR_RENDERER_GL_BASE_EO_CLASS_TYPE
#define _ECTOR_RENDERER_GL_BASE_EO_CLASS_TYPE

typedef Eo Ector_Renderer_Gl_Base;

#endif

#ifndef _ECTOR_RENDERER_GL_BASE_EO_TYPES
#define _ECTOR_RENDERER_GL_BASE_EO_TYPES


#endif
#define ECTOR_RENDERER_GL_BASE_CLASS ector_renderer_gl_base_class_get()

EAPI const Eo_Class *ector_renderer_gl_base_class_get(void) EINA_CONST;

EOAPI Eina_Bool  ector_renderer_gl_base_fill(void);


#endif
