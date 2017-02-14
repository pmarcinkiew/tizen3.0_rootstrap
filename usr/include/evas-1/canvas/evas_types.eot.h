#ifndef _EVAS_TYPES_EOT_H_
#define _EVAS_TYPES_EOT_H_

#ifndef _EVAS_TYPES_EOT_TYPES
#define _EVAS_TYPES_EOT_TYPES

/** An Evas modifier mask type
 *
 * @ingroup Evas
 */
typedef unsigned long long Evas_Modifier_Mask;

/** A type for coordinates
 *
 * @ingroup Evas
 */
typedef int Evas_Coord;

/** Aspect types/policies for scaling size hints, used for
 * evas_object_size_hint_aspect_set()
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_ASPECT_CONTROL_NONE = 0, /** Preference on scaling unset */
  EVAS_ASPECT_CONTROL_NEITHER = 1 /* 0 */, /** Same effect as unset preference
                                            * on scaling */
  EVAS_ASPECT_CONTROL_HORIZONTAL = 2 /* 0 */, /** Use all horizontal container
                                               * space to place an object,
                                               * using the given aspect */
  EVAS_ASPECT_CONTROL_VERTICAL = 3 /* 0 */, /** Use all vertical container
                                             * space to place an object, using
                                             * the given aspect */
  EVAS_ASPECT_CONTROL_BOTH = 4 /* 0 */ /** Use all horizontal and vertical
                                        * container spaces to place an object
                                        * (never growing it out of those
                                        * bounds), using the given aspect */
} Evas_Aspect_Control;

/** How the object should be rendered to output.
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_RENDER_BLEND = 0, /** default op: d = d*(1-sa) + s */
  EVAS_RENDER_BLEND_REL = 1 /* 0 */, /** d = d*(1 - sa) + s*da */
  EVAS_RENDER_COPY = 2 /* 0 */, /** d = s */
  EVAS_RENDER_COPY_REL = 3 /* 0 */, /** d = s*da */
  EVAS_RENDER_ADD = 4 /* 0 */, /** d = d + s */
  EVAS_RENDER_ADD_REL = 5 /* 0 */, /** d = d + s*da */
  EVAS_RENDER_SUB = 6 /* 0 */, /** d = d - s */
  EVAS_RENDER_SUB_REL = 7 /* 0 */, /** d = d - s*da */
  EVAS_RENDER_TINT = 8 /* 0 */, /** d = d*s + d*(1 - sa) + s*(1 - da) */
  EVAS_RENDER_TINT_REL = 9 /* 0 */, /** d = d*(1 - sa + s) */
  EVAS_RENDER_MASK = 10 /* 0 */, /** d = d*sa */
  EVAS_RENDER_MUL = 11 /* 0 */ /** d = d*s */
} Evas_Render_Op;

/**
 * @brief How the mouse pointer should be handled by Evas.
 *
 * In the mode #EVAS_OBJECT_POINTER_MODE_AUTOGRAB, when a mouse button is
 * pressed down over an object and held, with the mouse pointer being moved
 * outside of it, the pointer still behaves as being bound to that object,
 * albeit out of its drawing region. When the button is released, the event
 * will be fed to the object, that may check if the final position is over it
 * or not and do something about it.
 *
 * In the mode #EVAS_OBJECT_POINTER_MODE_NOGRAB, the pointer will always be
 * bound to the object right below it.
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_OBJECT_POINTER_MODE_AUTOGRAB = 0, /** default, X11-like */
  EVAS_OBJECT_POINTER_MODE_NOGRAB, /** pointer always bound to the object right
                                    * below it */
  EVAS_OBJECT_POINTER_MODE_NOGRAB_NO_REPEAT_UPDOWN /** useful on object with
                                                    * "repeat events" enabled,
                                                    * where mouse/touch up and
                                                    * down events WONT be
                                                    * repeated to objects and
                                                    * these objects wont be
                                                    * auto-grabbed.
                                                    *
                                                    * @since 1.2 */
} Evas_Object_Pointer_Mode;

typedef enum
{
  EVAS_DISPLAY_MODE_NONE = 0, /** Default mode */
  EVAS_DISPLAY_MODE_INHERIT = 1 /* 0 */, /** TIZEN_ONLY(20151014): add
                                          * deprecated enum to keep backward
                                          * compatibility */
  EVAS_DISPLAY_MODE_COMPRESS = 2 /* 0 */, /** Use this mode when you want to
                                           * give compress display mode hint to
                                           * an object */
  EVAS_DISPLAY_MODE_EXPAND = 3 /* 0 */, /** Use this mode when you want to give
                                         * expand display mode hint to an
                                         * object */
  EVAS_DISPLAY_MODE_DONT_CHANGE = 4 /* 0 */ /** Use this mode when an object
                                             * should not change its display
                                             * mode */
} Evas_Display_Mode;

typedef enum
{
  EVAS_BIDI_DIRECTION_NATURAL = 0,
  EVAS_BIDI_DIRECTION_NEUTRAL = 0,
  EVAS_BIDI_DIRECTION_LTR,
  EVAS_BIDI_DIRECTION_RTL,
  EVAS_BIDI_DIRECTION_INHERIT
} Evas_BiDi_Direction;

/** Types of styles to be applied on text objects. The
 * EVAS_TEXT_STYLE_SHADOW_DIRECTION_* ones are to be ORed together with others
 * imposing shadow, to change shadow's direction
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_TEXT_STYLE_PLAIN = 0, /** plain, standard text */
  EVAS_TEXT_STYLE_SHADOW, /** text with shadow underneath */
  EVAS_TEXT_STYLE_OUTLINE, /** text with an outline */
  EVAS_TEXT_STYLE_SOFT_OUTLINE, /** text with a soft outline */
  EVAS_TEXT_STYLE_GLOW, /** text with a glow effect */
  EVAS_TEXT_STYLE_OUTLINE_SHADOW, /** text with both outline and shadow effects
                                   */
  EVAS_TEXT_STYLE_FAR_SHADOW, /** text with (far) shadow underneath */
  EVAS_TEXT_STYLE_OUTLINE_SOFT_SHADOW, /** text with outline and soft shadow
                                        * effects combined */
  EVAS_TEXT_STYLE_SOFT_SHADOW, /** text with (soft) shadow underneath */
  EVAS_TEXT_STYLE_FAR_SOFT_SHADOW, /** text with (far soft) shadow underneath
                                    */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_BOTTOM_RIGHT = 0 /* 0 << 0 */, /** shadow growing to bottom right */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_BOTTOM = 16 /* 0 << 0 */, /** shadow growing to the bottom */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_BOTTOM_LEFT = 32 /* 0 << 0 */, /** shadow growing to bottom left */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_LEFT = 48 /* 0 << 0 */, /** shadow growing
                                                            * to the left */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_TOP_LEFT = 64 /* 0 << 0 */, /** shadow growing to top left */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_TOP = 80 /* 0 << 0 */, /** shadow growing to
                                                           * the top */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_TOP_RIGHT = 96 /* 0 << 0 */, /** shadow growing to top right */
  EVAS_TEXT_STYLE_SHADOW_DIRECTION_RIGHT = 112 /* 0 << 0 */ /** shadow growing to the right */
} Evas_Text_Style_Type;

/** A type for font size
 *
 * @ingroup Evas_Font
 */
typedef int Evas_Font_Size;

/** Flags for Font Hinting
 *
 * @ingroup Evas_Font
 */
typedef enum
{
  EVAS_FONT_HINTING_NONE = 0, /** No font hinting */
  EVAS_FONT_HINTING_AUTO, /** Automatic font hinting */
  EVAS_FONT_HINTING_BYTECODE /** Bytecode font hinting */
} Evas_Font_Hinting_Flags;

/**
 * @brief An opaque handle to map points
 *
 * See @ref evas_map_new, @ref evas_map_free, @ref evas_map_dup.
 *
 * @ingroup Evas
 */
typedef struct _Evas_Map Evas_Map;

/** Flags for Mouse Button events
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_BUTTON_NONE = 0, /** No extra mouse button data */
  EVAS_BUTTON_DOUBLE_CLICK = 1 /* 0 << 0 */, /** This mouse button press was
                                              * the 2nd press of a double click
                                              */
  EVAS_BUTTON_TRIPLE_CLICK = 2 /* 0 << 0 */ /** This mouse button press was the
                                             * 3rd press of a triple click */
} Evas_Button_Flags;

/** Flags for Events
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_EVENT_FLAG_NONE = 0, /** No fancy flags set */
  EVAS_EVENT_FLAG_ON_HOLD = 1 /* 0 << 0 */, /** This event is being delivered
                                             * but should be put "on hold"
                                             * until the on hold flag is unset.
                                             * The event should be used for
                                             * informational purposes and maybe
                                             * some indications visually, but
                                             * not actually perform anything */
  EVAS_EVENT_FLAG_ON_SCROLL = 2 /* 0 << 0 */ /** This event flag indicates the
                                              * event occurs while scrolling;
                                              * for example, DOWN event occurs
                                              * during scrolling; the event
                                              * should be used for
                                              * informational purposes and
                                              * maybe some indications
                                              * visually, but not actually
                                              * perform anything */
} Evas_Event_Flags;

/** State of Evas_Coord_Touch_Point
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_TOUCH_POINT_DOWN = 0, /** Touch point is pressed down */
  EVAS_TOUCH_POINT_UP, /** Touch point is released */
  EVAS_TOUCH_POINT_MOVE, /** Touch point is moved */
  EVAS_TOUCH_POINT_STILL, /** Touch point is not moved after pressed */
  EVAS_TOUCH_POINT_CANCEL /** Touch point is cancelled */
} Evas_Touch_Point_State;

/** Identifier of callbacks to be set for Evas canvases or Evas objects.
 *
 * @ingroup Evas
 */
typedef enum
{
  EVAS_CALLBACK_MOUSE_IN = 0, /** Mouse In Event */
  EVAS_CALLBACK_MOUSE_OUT, /** Mouse Out Event */
  EVAS_CALLBACK_MOUSE_DOWN, /** Mouse Button Down Event */
  EVAS_CALLBACK_MOUSE_UP, /** Mouse Button Up Event */
  EVAS_CALLBACK_MOUSE_MOVE, /** Mouse Move Event */
  EVAS_CALLBACK_MOUSE_WHEEL, /** Mouse Wheel Event */
  EVAS_CALLBACK_MULTI_DOWN, /** Multi-touch Down Event */
  EVAS_CALLBACK_MULTI_UP, /** Multi-touch Up Event */
  EVAS_CALLBACK_MULTI_MOVE, /** Multi-touch Move Event */
  EVAS_CALLBACK_FREE, /** Object Being Freed (Called after Del) */
  EVAS_CALLBACK_KEY_DOWN, /** Key Press Event */
  EVAS_CALLBACK_KEY_UP, /** Key Release Event */
  EVAS_CALLBACK_FOCUS_IN, /** Focus In Event */
  EVAS_CALLBACK_FOCUS_OUT, /** Focus Out Event */
  EVAS_CALLBACK_SHOW, /** Show Event */
  EVAS_CALLBACK_HIDE, /** Hide Event */
  EVAS_CALLBACK_MOVE, /** Move Event */
  EVAS_CALLBACK_RESIZE, /** Resize Event */
  EVAS_CALLBACK_RESTACK, /** Restack Event */
  EVAS_CALLBACK_DEL, /** Object Being Deleted (called before Free) */
  EVAS_CALLBACK_HOLD, /** Events go on/off hold */
  EVAS_CALLBACK_CHANGED_SIZE_HINTS, /** Size hints changed event */
  EVAS_CALLBACK_IMAGE_PRELOADED, /** Image has been preloaded */
  EVAS_CALLBACK_CANVAS_FOCUS_IN, /** Canvas got focus as a whole */
  EVAS_CALLBACK_CANVAS_FOCUS_OUT, /** Canvas lost focus as a whole */
  EVAS_CALLBACK_RENDER_FLUSH_PRE, /** Called just before rendering is updated
                                   * on the canvas target */
  EVAS_CALLBACK_RENDER_FLUSH_POST, /** Called just after rendering is updated
                                    * on the canvas target */
  EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_IN, /** Canvas object got focus */
  EVAS_CALLBACK_CANVAS_OBJECT_FOCUS_OUT, /** Canvas object lost focus */
  EVAS_CALLBACK_IMAGE_UNLOADED, /** Image data has been unloaded (by some
                                 * mechanism in Evas that throw out original
                                 * image data) */
  EVAS_CALLBACK_RENDER_PRE, /** Called just before rendering starts on the
                             * canvas target
                             *
                             * @since 1.2 */
  EVAS_CALLBACK_RENDER_POST, /** Called just after rendering stops on the
                              * canvas target
                              *
                              * @since 1.2 */
  EVAS_CALLBACK_IMAGE_RESIZE, /** Image size is changed
                               *
                               * @since 1.8 */
  EVAS_CALLBACK_DEVICE_CHANGED, /** Devices added, removed or changed on canvas
                                 *
                                 * @since 1.8 */
  EVAS_CALLBACK_AXIS_UPDATE, /** Input device changed value on some axis
                              *
                              * @since 1.13 */
  EVAS_CALLBACK_CANVAS_VIEWPORT_RESIZE, /** Canvas viewport resized
                                         *
                                         * @since 1.15 */
  EVAS_CALLBACK_LAST /** kept as last element/sentinel -- not really an event
                      */
} Evas_Callback_Type;

/** An opaque type containing information on which modifier keys are registered
 * in an Evas canvas
 *
 * @ingroup Evas
 */
typedef struct _Evas_Modifier Evas_Modifier;

/** An opaque type containing information on which lock keys are registered in
 * an Evas canvas
 *
 * @ingroup Evas
 */
typedef struct _Evas_Lock Evas_Lock;

/** A generic Evas Engine information structure
 *
 * @ingroup Evas
 */
typedef struct _Evas_Engine_Info Evas_Engine_Info;

/** Details for a single device axis state
 *
 * @since 1.13
 *
 * @ingroup Evas
 */
typedef struct _Evas_Axis Evas_Axis;

/** A type for floating value
 *
 * @ingroup Evas
 */
typedef double Evas_Real;

/** Type of 3D Object
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_OBJECT_TYPE_INVALID = 0,
  EVAS_CANVAS3D_OBJECT_TYPE_SCENE,
  EVAS_CANVAS3D_OBJECT_TYPE_NODE,
  EVAS_CANVAS3D_OBJECT_TYPE_CAMERA,
  EVAS_CANVAS3D_OBJECT_TYPE_LIGHT,
  EVAS_CANVAS3D_OBJECT_TYPE_MODEL,
  EVAS_CANVAS3D_OBJECT_TYPE_MESH,
  EVAS_CANVAS3D_OBJECT_TYPE_TEXTURE,
  EVAS_CANVAS3D_OBJECT_TYPE_MATERIAL,
  EVAS_CANVAS3D_OBJECT_TYPE_PRIMITIVE /** No description supplied.
                                       *
                                       * @since 1.15 */
} Evas_Canvas3D_Object_Type;

/** State of the Evas 3D
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_STATE_MAX = 16 /* 0 */,
  EVAS_CANVAS3D_STATE_ANY = 0,
  EVAS_CANVAS3D_STATE_SCENE_ROOT_NODE = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_SCENE_CAMERA_NODE,
  EVAS_CANVAS3D_STATE_SCENE_BACKGROUND_COLOR,
  EVAS_CANVAS3D_STATE_SCENE_SIZE,
  EVAS_CANVAS3D_STATE_SCENE_SHADOWS_ENABLED,
  EVAS_CANVAS3D_STATE_SCENE_UPDATED, /** No description supplied.
                                      *
                                      * @since 1.14 */
  EVAS_CANVAS3D_STATE_SCENE_SHADOWS_DEPTH,
  EVAS_CANVAS3D_STATE_TEXTURE_DATA = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_TEXTURE_WRAP,
  EVAS_CANVAS3D_STATE_TEXTURE_FILTER,
  EVAS_CANVAS3D_STATE_MATERIAL_ID = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_MATERIAL_COLOR,
  EVAS_CANVAS3D_STATE_MATERIAL_TEXTURE,
  EVAS_CANVAS3D_STATE_MESH_VERTEX_COUNT = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_MESH_FRAME,
  EVAS_CANVAS3D_STATE_MESH_MATERIAL,
  EVAS_CANVAS3D_STATE_MESH_TRANSFORM,
  EVAS_CANVAS3D_STATE_MESH_VERTEX_DATA,
  EVAS_CANVAS3D_STATE_MESH_INDEX_DATA,
  EVAS_CANVAS3D_STATE_MESH_VERTEX_ASSEMBLY,
  EVAS_CANVAS3D_STATE_MESH_SHADE_MODE,
  EVAS_CANVAS3D_STATE_MESH_FOG,
  EVAS_CANVAS3D_STATE_MESH_BLENDING,
  EVAS_CANVAS3D_STATE_MESH_ALPHA_TEST,
  EVAS_CANVAS3D_STATE_MESH_COLOR_PICK,
  EVAS_CANVAS3D_STATE_MESH_SHADOWS_EDGES_FILTERING,
  EVAS_CANVAS3D_STATE_MESH_SHADOWS_CONSTANT_BIAS,
  EVAS_CANVAS3D_STATE_CAMERA_PROJECTION = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_LIGHT_AMBIENT = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_LIGHT_DIFFUSE,
  EVAS_CANVAS3D_STATE_LIGHT_SPECULAR,
  EVAS_CANVAS3D_STATE_LIGHT_SPOT_DIR,
  EVAS_CANVAS3D_STATE_LIGHT_SPOT_EXP,
  EVAS_CANVAS3D_STATE_LIGHT_SPOT_CUTOFF,
  EVAS_CANVAS3D_STATE_LIGHT_ATTENUATION,
  EVAS_CANVAS3D_STATE_LIGHT_PROJECTION,
  EVAS_CANVAS3D_STATE_NODE_TRANSFORM_POSITION = 1 /* 0 */,
  EVAS_CANVAS3D_STATE_NODE_TRANSFORM_ORIENTATION,
  EVAS_CANVAS3D_STATE_NODE_TRANSFORM_SCALE,
  EVAS_CANVAS3D_STATE_NODE_MESH_GEOMETRY,
  EVAS_CANVAS3D_STATE_NODE_MESH_MATERIAL,
  EVAS_CANVAS3D_STATE_NODE_MESH_FRAME,
  EVAS_CANVAS3D_STATE_NODE_MESH_SHADE_MODE,
  EVAS_CANVAS3D_STATE_NODE_MESH_MATERIAL_ID,
  EVAS_CANVAS3D_STATE_NODE_LIGHT,
  EVAS_CANVAS3D_STATE_NODE_CAMERA,
  EVAS_CANVAS3D_STATE_NODE_PARENT_POSITION,
  EVAS_CANVAS3D_STATE_NODE_PARENT_ORIENTATION,
  EVAS_CANVAS3D_STATE_NODE_PARENT_SCALE,
  EVAS_CANVAS3D_STATE_NODE_MEMBER,
  EVAS_CANVAS3D_STATE_NODE_PARENT_BILLBOARD /** No description supplied.
                                             *
                                             * @since 1.14 */
} Evas_Canvas3D_State;

/** Transform space
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_SPACE_LOCAL = 0, /** Local coordinate space */
  EVAS_CANVAS3D_SPACE_PARENT, /** Parent coordinate space */
  EVAS_CANVAS3D_SPACE_WORLD /** World coordinate space */
} Evas_Canvas3D_Space;

/** Types of a node
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_NODE_TYPE_NODE = 0, /** Node with no items */
  EVAS_CANVAS3D_NODE_TYPE_CAMERA, /** Node which can contain camera object */
  EVAS_CANVAS3D_NODE_TYPE_LIGHT, /** Node which can contain light object */
  EVAS_CANVAS3D_NODE_TYPE_MESH /** Node which can contain mesh objects */
} Evas_Canvas3D_Node_Type;

/** Types of node orientation
 *
 * @since 1.13
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_NODE_ORIENTATION_TYPE_NONE = 0, /** Node with no orientation
                                                 * properties */
  EVAS_CANVAS3D_NODE_ORIENTATION_TYPE_LOOK_AT, /** Node orientation is given as
                                                * a point to look at and a
                                                * vector that indicates the
                                                * angle at which the subject is
                                                * looking at the point */
  EVAS_CANVAS3D_NODE_ORIENTATION_TYPE_LOOK_TO, /** Node orientation is given as
                                                * id of another part to look at
                                                * and a vector that indicates
                                                * the angle at which the
                                                * subject is looking at the
                                                * part */
  EVAS_CANVAS3D_NODE_ORIENTATION_TYPE_ANGLE_AXIS, /** Node orientation is given
                                                   * as an angle and an axis to
                                                   * rotate around */
  EVAS_CANVAS3D_NODE_ORIENTATION_TYPE_QUATERNION /** Node orientation is given
                                                  * as a quaternion */
} Evas_Canvas3D_Node_Orientation_Type;

/** Index formats
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_INDEX_FORMAT_NONE = 0, /** Indexing is not used */
  EVAS_CANVAS3D_INDEX_FORMAT_UNSIGNED_BYTE, /** Index is of type unsigned byte
                                             */
  EVAS_CANVAS3D_INDEX_FORMAT_UNSIGNED_SHORT /** Index is of type unsigned short
                                             */
} Evas_Canvas3D_Index_Format;

/** Frustum modes
 *
 * @since 1.12
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_FRUSTUM_MODE_BSPHERE = 0, /** Bounding sphere */
  EVAS_CANVAS3D_FRUSTUM_MODE_AABB, /** Axis-aligned bounding box */
  EVAS_CANVAS3D_FRUSTUM_MODE_CENTRAL_POINT
} Evas_Canvas3D_Frustum_Mode;

/** Vertex assembly modes. Vertex assembly represents how the vertices are
 * organized into geometric primitives.
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_POINTS = 0, /** A vertex is rendered as a point
                                             */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_LINES, /** Two vertices are organized as a line
                                        */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_LINE_STRIP, /** Vertices are organized as a
                                             * connected line path */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_LINE_LOOP, /** Vertices are organized as a
                                            * closed line path */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_TRIANGLES, /** Three vertices are organized as
                                            * a triangle */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_TRIANGLE_STRIP, /** Vertices are organized as
                                                 * connected triangles */
  EVAS_CANVAS3D_VERTEX_ASSEMBLY_TRIANGLE_FAN /** Vertices are organized as a
                                              * triangle fan */
} Evas_Canvas3D_Vertex_Assembly;

/** Comparsion functions for testing(alpha, depth, stencil) in fragment shader
 *
 * @since 1.14
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_COMPARISON_NEVER = 0, /** Never passes */
  EVAS_CANVAS3D_COMPARISON_LESS, /** Passes if the incoming value is less than
                                  * the reference value */
  EVAS_CANVAS3D_COMPARISON_EQUAL, /** Passes if the incoming value is equal to
                                   * the reference value */
  EVAS_CANVAS3D_COMPARISON_LEQUAL, /** Passes if the incoming value is less
                                    * than or equal to the reference value */
  EVAS_CANVAS3D_COMPARISON_GREATER, /** Passes if the incoming value is greater
                                     * than the reference value */
  EVAS_CANVAS3D_COMPARISON_NOTEQUAL, /** Passes if the incoming value is not
                                      * equal to the reference value */
  EVAS_CANVAS3D_COMPARISON_GEQUAL, /** Passes if the incoming value is greater
                                    * than or equal to the reference value */
  EVAS_CANVAS3D_COMPARISON_ALWAYS /** Always passes (initial value) */
} Evas_Canvas3D_Comparison;

/** Wrap modes for texture units
 *
 * @since 1.14
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_WRAP_MODE_CLAMP = 0, /** Values will be clamped to be in range
                                      * (min, max) */
  EVAS_CANVAS3D_WRAP_MODE_REPEAT, /** Values will be repeated */
  EVAS_CANVAS3D_WRAP_MODE_REFLECT /** Values will be repeated in a reflected
                                   * manner */
} Evas_Canvas3D_Wrap_Mode;

/** Filters for texture units
 *
 * @since 1.14
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_TEXTURE_FILTER_NEAREST = 0, /** Samples nearest texel */
  EVAS_CANVAS3D_TEXTURE_FILTER_LINEAR, /** Lineary interpolate nearby texels */
  EVAS_CANVAS3D_TEXTURE_FILTER_NEAREST_MIPMAP_NEAREST, /** Nearest sampling
                                                        * mipmap */
  EVAS_CANVAS3D_TEXTURE_FILTER_LINEAR_MIPMAP_NEAREST, /** Nearest sampling
                                                       * mipmap and interpolate
                                                       */
  EVAS_CANVAS3D_TEXTURE_FILTER_NEAREST_MIPMAP_LINEAR, /** Linear sampling in
                                                       * nearest mipmap */
  EVAS_CANVAS3D_TEXTURE_FILTER_LINEAR_MIPMAP_LINEAR /** Linear sampling in
                                                     * mipmap and interpolate
                                                     */
} Evas_Canvas3D_Texture_Filter;

/** Mesh primitive
 *
 * @since 1.12
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_MESH_PRIMITIVE_NONE = 0, /** An empty space */
  EVAS_CANVAS3D_MESH_PRIMITIVE_SQUARE, /** One sided square */
  EVAS_CANVAS3D_MESH_PRIMITIVE_CUBE,
  EVAS_CANVAS3D_MESH_PRIMITIVE_CYLINDER, /** Cylinder (can use precision and
                                          * texture scale) */
  EVAS_CANVAS3D_MESH_PRIMITIVE_CONE, /** Cone (can use precision and texture
                                      * scale) */
  EVAS_CANVAS3D_MESH_PRIMITIVE_SPHERE, /** Sphere (can use precision and
                                        * texture scale) */
  EVAS_CANVAS3D_MESH_PRIMITIVE_TORUS, /** Torus (can use ratio, precision and
                                       * texture scale) */
  EVAS_CANVAS3D_MESH_PRIMITIVE_SURFACE, /** Custom surface (can use pointer to
                                         * users function, precision and
                                         * texture scale) */
  EVAS_CANVAS3D_MESH_PRIMITIVE_TERRAIN, /** Terrain as surface with pointer to
                                         * perlin's noise function */
  EVAS_CANVAS3D_MESH_PRIMITIVE_COUNT
} Evas_Canvas3D_Mesh_Primitive;

/** Mode of mesh primitive
 *
 * @since 1.15
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_PRIMITIVE_MODE_DEFAULT = 0, /** Default mode of primitive */
  EVAS_CANVAS3D_PRIMITIVE_MODE_WITHOUT_BASE, /** Primitive without base
                                              * (supported for cylinder and
                                              * cone) */
  EVAS_CANVAS3D_PRIMITIVE_MODE_ALTERNATIVE_UV /** Ptimitive with alternative uv
                                               * (supported for sphere) */
} Evas_Canvas3D_Primitive_Mode;

/** Shader shade modes
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_SHADE_MODE_VERTEX_COLOR = 0, /** Shaded using vertex color
                                              * attribute */
  EVAS_CANVAS3D_SHADE_MODE_DIFFUSE, /** Shaded using material diffuse term */
  EVAS_CANVAS3D_SHADE_MODE_FLAT, /** Per-vertex flat lighting */
  EVAS_CANVAS3D_SHADE_MODE_PHONG, /** Per-pixel phong shading */
  EVAS_CANVAS3D_SHADE_MODE_NORMAL_MAP, /** Per-pixel normal map shading */
  EVAS_CANVAS3D_SHADE_MODE_SHADOW_MAP_RENDER, /** Fragment color is defined by
                                               * its z-coord */
  EVAS_CANVAS3D_SHADE_MODE_COLOR_PICK, /** Rendering to additional frame bufer
                                        */
  EVAS_CANVAS3D_SHADE_MODE_PARALLAX_OCCLUSION /** Per-pixel parallax occlusion
                                               * map shading */
} Evas_Canvas3D_Shade_Mode;

/** Vertex attribute IDs
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_VERTEX_ATTRIB_POSITION = 0, /** vertex position */
  EVAS_CANVAS3D_VERTEX_ATTRIB_NORMAL, /** vertex normal */
  EVAS_CANVAS3D_VERTEX_ATTRIB_TANGENT, /** vertex tangent (for normal mapping)
                                        */
  EVAS_CANVAS3D_VERTEX_ATTRIB_COLOR, /** vertex color */
  EVAS_CANVAS3D_VERTEX_ATTRIB_TEXCOORD /** vertex texture coordinate */
} Evas_Canvas3D_Vertex_Attrib;

/** Blending function
 *
 * @since 1.14
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_BLEND_FUNC_ZERO = 0, /** The scale factors for color components
                                      * is (0, 0, 0, 0) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE, /** The scale factors for color components is
                                 * (1, 1, 1, 1) */
  EVAS_CANVAS3D_BLEND_FUNC_SRC_COLOR, /** The scale factors for color
                                       * components is (rs/kr, gs/kg, bs/kb,
                                       * as/ka) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_SRC_COLOR, /** The scale factors for color
                                                 * components is (1, 1, 1, 1) -
                                                 * (rs/kr, gs/kg, bs/kb, as/ka)
                                                 */
  EVAS_CANVAS3D_BLEND_FUNC_DST_COLOR, /** The scale factors for color
                                       * components is (rd/kr, gd/kg, bd/kb,
                                       * ad/ka) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_DST_COLOR, /** The scale factors for color
                                                 * components is (1, 1, 1, 1) -
                                                 * (rd/kr, gd/kg, bd/kb, ad/ka)
                                                 */
  EVAS_CANVAS3D_BLEND_FUNC_SRC_ALPHA, /** The scale factors for color
                                       * components is (as/ka, as/ka, as/ka,
                                       * as/ka) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_SRC_ALPHA, /** The scale factors for color
                                                 * components is (1, 1, 1, 1) -
                                                 * (as/ka, as/ka, as/ka, as/ka)
                                                 */
  EVAS_CANVAS3D_BLEND_FUNC_DST_ALPHA, /** The scale factors for color
                                       * components is (ad/ka, ad/ka, ad/ka,
                                       * ad/ka) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_DST_ALPHA, /** The scale factors for color
                                                 * components is (1, 1, 1, 1) -
                                                 * (ad/ka, ad/ka, ad/ka, ad/ka)
                                                 */
  EVAS_CANVAS3D_BLEND_FUNC_CONSTANT_COLOR, /** The scale factors for color
                                            * components is (rc, gc, bc, ac) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_CONSTANT_COLOR, /** The scale factors for
                                                      * color components is (1,
                                                      * 1, 1, 1) - (rc, gc, bc,
                                                      * ac) */
  EVAS_CANVAS3D_BLEND_FUNC_CONSTANT_ALPHA, /** The scale factors for color
                                            * components is (ac, ac, ac, ac) */
  EVAS_CANVAS3D_BLEND_FUNC_ONE_MINUS_CONSTANT_ALPHA, /** The scale factors for
                                                      * color components is (1,
                                                      * 1, 1, 1) - (ac, ac, ac,
                                                      * ac) */
  EVAS_CANVAS3D_BLEND_FUNC_SRC_ALPHA_SATURATE /** The scale factors for color
                                               * components is (i, i, i, 1)
                                               * where i = min(as, ka, ad)/ka
                                               */
} Evas_Canvas3D_Blend_Func;

/** Material attributes
 *
 * @since 1.10
 *
 * @ingroup Evas_Canvas3D
 */
typedef enum
{
  EVAS_CANVAS3D_MATERIAL_ATTRIB_AMBIENT = 0, /** ambient term */
  EVAS_CANVAS3D_MATERIAL_ATTRIB_DIFFUSE, /** diffuse term */
  EVAS_CANVAS3D_MATERIAL_ATTRIB_SPECULAR, /** specular term */
  EVAS_CANVAS3D_MATERIAL_ATTRIB_EMISSION, /** emission term */
  EVAS_CANVAS3D_MATERIAL_ATTRIB_NORMAL /** Normal map term */
} Evas_Canvas3D_Material_Attrib;


#endif

#endif
