#ifndef _ELM_VIDEO_EO_LEGACY_H_
#define _ELM_VIDEO_EO_LEGACY_H_

#ifndef _ELM_VIDEO_EO_CLASS_TYPE
#define _ELM_VIDEO_EO_CLASS_TYPE

typedef Eo Elm_Video;

#endif

#ifndef _ELM_VIDEO_EO_TYPES
#define _ELM_VIDEO_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief Set the audio level of an Elm_Video object.
 *
 * @param[in] volume The audio level.
 *
 * @ingroup Elm_Video
 */
EAPI void elm_video_audio_level_set(Elm_Video *obj, double volume);

/**
 * @internal
 *
 * @brief Get the audio level of the current video.
 *
 * @return The audio level.
 *
 * @ingroup Elm_Video
 */
EAPI double elm_video_audio_level_get(const Elm_Video *obj);

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
EAPI void elm_video_remember_position_set(Elm_Video *obj, Eina_Bool remember);

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
EAPI Eina_Bool elm_video_remember_position_get(const Elm_Video *obj);

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
EAPI void elm_video_play_position_set(Elm_Video *obj, double position);

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
EAPI double elm_video_play_position_get(const Elm_Video *obj);

/**
 * @internal
 *
 * @brief Change the mute state of the Elm_Video object.
 *
 * @param[in] mute The mute state.
 *
 * @ingroup Elm_Video
 */
EAPI void elm_video_audio_mute_set(Elm_Video *obj, Eina_Bool mute);

/**
 * @internal
 *
 * @brief Get whether audio is muted.
 *
 * @return The mute state.
 *
 * @ingroup Elm_Video
 */
EAPI Eina_Bool elm_video_audio_mute_get(const Elm_Video *obj);

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
EAPI Eina_Bool elm_video_is_playing_get(const Elm_Video *obj);

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
EAPI double elm_video_play_length_get(const Elm_Video *obj);

/**
 * @internal
 *
 * @brief Get the underlying Emotion object.
 *
 * @return the underlying Emotion object.
 *
 * @ingroup Elm_Video
 */
EAPI Evas_Object *elm_video_emotion_get(const Elm_Video *obj);

/**
 * @internal
 *
 * @brief Is it possible to seek inside the video.
 *
 * @return true if is possible to seek inside the video.
 *
 * @ingroup Elm_Video
 */
EAPI Eina_Bool elm_video_is_seekable_get(const Elm_Video *obj);

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
EAPI const char *elm_video_title_get(const Elm_Video *obj);

/**
 * @internal
 *
 * Start playing a video.
 *
 * @ingroup Elm_Video
 */
EAPI void elm_video_play(Elm_Video *obj);

/**
 * @internal
 *
 * Pause a video.
 *
 * @ingroup Elm_Video
 */
EAPI void elm_video_pause(Elm_Video *obj);

/**
 * @internal
 *
 * Stop a video.
 *
 * @ingroup Elm_Video
 */
EAPI void elm_video_stop(Elm_Video *obj);

#endif
