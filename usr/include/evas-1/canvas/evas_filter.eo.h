#ifndef _EVAS_FILTER_EO_H_
#define _EVAS_FILTER_EO_H_

#ifndef _EVAS_FILTER_EO_CLASS_TYPE
#define _EVAS_FILTER_EO_CLASS_TYPE

typedef Eo Evas_Filter;

#endif

#ifndef _EVAS_FILTER_EO_TYPES
#define _EVAS_FILTER_EO_TYPES


#endif
#define EVAS_FILTER_MIXIN evas_filter_mixin_get()

EAPI const Eo_Class *evas_filter_mixin_get(void) EINA_CONST;

#ifdef EVAS_FILTER_PROTECTED
/** Called by Evas.Filter to determine whether the input is alpha or rgba.
 *
 * @ingroup Evas_Filter
 */
EOAPI Eina_Bool  evas_filter_input_alpha(void);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Called by Evas.Filter when the parent class must render the input. ;
 *
 * @param[in] drawctx
 * @param[in] l
 * @param[in] r
 * @param[in] t
 * @param[in] b
 * @param[in] do_async
 *
 * @return Indicates success from the object render function.
 *
 * @ingroup Evas_Filter
 */
EOAPI Eina_Bool  evas_filter_input_render(void *filter, void *drawctx, int l, int r, int t, int b, Eina_Bool do_async);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Called when the filter changes must trigger a redraw of the object.
 *
 * Virtual, to be implemented in the parent class.
 *
 * @ingroup Evas_Filter
 */
EOAPI void  evas_filter_dirty(void);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Marks this filter as changed.
 *
 * @param[in] val
 *
 * @ingroup Evas_Filter
 */
EOAPI void  evas_filter_changed_set(Eina_Bool val);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Marks this filter as invalid.
 *
 * @param[in] val
 *
 * @ingroup Evas_Filter
 */
EOAPI void  evas_filter_invalid_set(Eina_Bool val);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Retrieve cached output buffer, if any.
 *
 * Does not increment the reference count.
 *
 * @ingroup Evas_Filter
 */
EOAPI void * evas_filter_output_buffer_get(void);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Initialize the Evas.Filter mixin.
 *
 * Should be called in a parent's class constructor.
 *
 * @ingroup Evas_Filter
 */
EOAPI void  evas_filter_constructor(void);
#endif

#ifdef EVAS_FILTER_PROTECTED
/**
 * @brief Release all data held by this Evas.Filter.
 *
 * This may include image buffers allocated by the Evas engine. This should be
 * called at the beginning of a parent's class destructor.
 *
 * @ingroup Evas_Filter
 */
EOAPI void  evas_filter_destructor(void);
#endif


#endif
