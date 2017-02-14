#ifndef _ELM_BG_EO_H_
#define _ELM_BG_EO_H_

#ifndef _ELM_BG_EO_CLASS_TYPE
#define _ELM_BG_EO_CLASS_TYPE

typedef Eo Elm_Bg;

#endif

#ifndef _ELM_BG_EO_TYPES
#define _ELM_BG_EO_TYPES

/**
 * @brief Identifiers on how a background widget is to display its image -- if
 * it was set to use an image file.
 *
 * See also @ref elm_obj_bg_option_set, @ref elm_obj_bg_option_get.
 *
 * @ingroup Elm_Bg
 */
typedef enum
{
  ELM_BG_OPTION_CENTER = 0, /** Center the background image. */
  ELM_BG_OPTION_SCALE, /** Scale the background image, retaining aspect ratio
                        * (default). */
  ELM_BG_OPTION_STRETCH, /** Stretch the background image to fill the widget's
                          * area. */
  ELM_BG_OPTION_TILE, /** Tile background image at its original size. */
  ELM_BG_OPTION_LAST /** Sentinel value, also used to indicate errors. */
} Elm_Bg_Option;


#endif
#define ELM_BG_CLASS elm_bg_class_get()

EAPI const Eo_Class *elm_bg_class_get(void) EINA_CONST;

/**
 * @brief Set the mode of display for a given background widget's image
 *
 * This sets how the background widget will display its image. This will only
 * work if the @ref efl_file_set was previously called with an image file on
 * @c obj. The image can be display tiled, scaled, centered or stretched.
 * @ref Elm_Bg_Option.ELM_BG_OPTION_SCALE by default.
 *
 * See also @ref elm_obj_bg_option_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] option The desired background option(See @ref Elm_Bg_Option)
 *
 * @ingroup Elm_Bg
 */
EOAPI void  elm_obj_bg_option_set(Elm_Bg_Option option);

/**
 * @brief Get the mode of display for a given background widget's image.
 *
 * See also @ref elm_obj_bg_option_set for more details
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The desired background option(See @ref Elm_Bg_Option)
 *
 * @ingroup Elm_Bg
 */
EOAPI Elm_Bg_Option  elm_obj_bg_option_get(void);

/**
 * @brief Set the color on a given background widget
 *
 * This sets the color used for the background rectangle, in RGB format. Each
 * color component's range is from 0 to 255.
 *
 * @note You probably only want to use this function if you haven't previously
 * called @ref efl_file_set, so that you just want a solid color background.
 *
 * @note You can reset the color by setting @c r, @c g, @c b as -1, -1, -1.
 *
 * See also @ref elm_obj_bg_color_get
 *
 * @param[in] r The red color component's value
 * @param[in] g The green color component's value
 * @param[in] b The blue color component's value
 * @param[in] a The blue color component's value
 *
 * @ingroup Elm_Bg
 */
EOAPI void  elm_obj_bg_color_set(int r, int g, int b, int a);

/**
 * @brief Get the color set on a given background widget
 *
 * @note Use @c null pointers on the file components you're not interested in:
 * they'll be ignored by the function.
 *
 * See also @ref elm_obj_bg_color_get for more details
 *
 * @param[out] r The red color component's value
 * @param[out] g The green color component's value
 * @param[out] b The blue color component's value
 * @param[out] a The blue color component's value
 *
 * @ingroup Elm_Bg
 */
EOAPI void  elm_obj_bg_color_get(int *r, int *g, int *b, int *a);

/**
 * @brief Set the size of the pixmap representation of the image set on a given
 * background widget.
 *
 * @warning This function just makes sense if an image file was set on @c obj,
 * with @ref efl_file_set
 *
 * This function sets a new size for pixmap representation of the given bg
 * image. It allows for the image to be loaded already in the specified size,
 * reducing the memory usage and load time (for example, when loading a big
 * image file with its load size set to a smaller size)
 *
 * @note This is just a hint for the underlying system. The real size of the
 * pixmap may differ depending on the type of image being loaded, being bigger
 * than requested.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] w The new width of the image pixmap representation.
 * @param[in] h The new height of the image pixmap representation.
 *
 * @ingroup Elm_Bg
 */
EOAPI void  elm_obj_bg_load_size_set(Evas_Coord w, Evas_Coord h);


#endif
