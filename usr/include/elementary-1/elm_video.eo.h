#ifndef _ELM_VIDEO_EO_H_
#define _ELM_VIDEO_EO_H_

#ifndef _ELM_VIDEO_EO_CLASS_TYPE
#define _ELM_VIDEO_EO_CLASS_TYPE

typedef Eo Elm_Video;

#endif

#ifndef _ELM_VIDEO_EO_TYPES
#define _ELM_VIDEO_EO_TYPES


#endif
#define ELM_VIDEO_CLASS elm_video_class_get()

EAPI const Eo_Class *elm_video_class_get(void) EINA_CONST;

/**
 * @internal
 *
 * @brief Set the audio level of an Elm_Video object.
 *
 * @param[in] volume The audio level.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_audio_level_set(double volume);

/**
 * @internal
 *
 * @brief Get the audio level of the current video.
 *
 * @return The audio level.
 *
 * @ingroup Elm_Video
 */
EOAPI double  elm_obj_video_audio_level_get(void);

/**
 * @internal
 *
 * @brief Set whether the object can remember the last played
 * position.
 *
 * @note This API only serves as indication. System support is required.
 *
 * @param[in] remember The value.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_remember_position_set(Eina_Bool remember);

/**
 * @internal
 *
 * @brief Set whether the object can remember the last played
 * position.
 *
 * @note This API only serves as indication. System support is required.
 *
 * @return The value.
 *
 * @ingroup Elm_Video
 */
EOAPI Eina_Bool  elm_obj_video_remember_position_get(void);

/**
 * @internal
 *
 * @brief Set the current position (in seconds) to be played
 * in the Elm_Video object.
 *
 * @param[in] position The time (in seconds) since the beginning of the media
 * file.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_play_position_set(double position);

/**
 * @internal
 *
 * @brief Get the current position (in seconds) being played
 * in the Elm_Video object.
 *
 * @return The time (in seconds) since the beginning of the media file.
 *
 * @ingroup Elm_Video
 */
EOAPI double  elm_obj_video_play_position_get(void);

/**
 * @internal
 *
 * @brief Change the mute state of the Elm_Video object.
 *
 * @param[in] mute The mute state.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_audio_mute_set(Eina_Bool mute);

/**
 * @internal
 *
 * @brief Get whether audio is muted.
 *
 * @return The mute state.
 *
 * @ingroup Elm_Video
 */
EOAPI Eina_Bool  elm_obj_video_audio_mute_get(void);

/**
 * @internal
 *
 * @brief Is the video actually playing.
 *
 * You should consider watching event on the object instead of polling the
 * object state.
 *
 * @ingroup Elm_Video
 */
EOAPI Eina_Bool  elm_obj_video_is_playing_get(void);

/**
 * @internal
 *
 * @brief Get the total playing time (in seconds) of the
 * Elm_Video object.
 *
 * @return The total duration (in seconds) of the media file.
 *
 * @ingroup Elm_Video
 */
EOAPI double  elm_obj_video_play_length_get(void);

/**
 * @internal
 *
 * @brief Get the underlying Emotion object.
 *
 * @return the underlying Emotion object.
 *
 * @ingroup Elm_Video
 */
EOAPI Evas_Object * elm_obj_video_emotion_get(void);

/**
 * @internal
 *
 * @brief Is it possible to seek inside the video.
 *
 * @return true if is possible to seek inside the video.
 *
 * @ingroup Elm_Video
 */
EOAPI Eina_Bool  elm_obj_video_is_seekable_get(void);

/**
 * @internal
 *
 * @brief Get the title (for instance DVD title) from this
 * emotion object.
 *
 * This function is only useful when playing a DVD.
 *
 * @note Don't change or free the string returned by this function.
 *
 * @return A string containing the title.
 *
 * @ingroup Elm_Video
 */
EOAPI const char * elm_obj_video_title_get(void);

/**
 * @internal
 *
 * Start playing a video.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_play(void);

/**
 * @internal
 *
 * Pause a video.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_pause(void);

/**
 * @internal
 *
 * Stop a video.
 *
 * @ingroup Elm_Video
 */
EOAPI void  elm_obj_video_stop(void);


#endif
