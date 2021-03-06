/*
* Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __TIZEN_MEDIA_SOUND_MANAGER_H__
#define __TIZEN_MEDIA_SOUND_MANAGER_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @file sound_manager.h
 * @brief This file contains the Sound Manager API.
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_MODULE
 * @{
 */

/**
 * @brief Enumeration for sound manager's error codes.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_MANAGER_ERROR_NONE              = TIZEN_ERROR_NONE,                    /**< Successful */
	SOUND_MANAGER_ERROR_OUT_OF_MEMORY     = TIZEN_ERROR_OUT_OF_MEMORY,           /**< Out of memory */
	SOUND_MANAGER_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,       /**< Invalid parameter */
	SOUND_MANAGER_ERROR_INVALID_OPERATION = TIZEN_ERROR_INVALID_OPERATION,       /**< Invalid operation */
	SOUND_MANAGER_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED,       /**< Permission denied */
	SOUND_MANAGER_ERROR_NOT_SUPPORTED     = TIZEN_ERROR_NOT_SUPPORTED,           /**< Not supported */
	SOUND_MANAGER_ERROR_NO_DATA           = TIZEN_ERROR_NO_DATA,                 /**< No data */
	SOUND_MANAGER_ERROR_INTERNAL          = TIZEN_ERROR_SOUND_MANAGER | 01,      /**< Internal error inside the sound system */
	SOUND_MANAGER_ERROR_POLICY            = TIZEN_ERROR_SOUND_MANAGER | 02,      /**< Noncompliance with the sound system policy */
	SOUND_MANAGER_ERROR_NO_PLAYING_SOUND  = TIZEN_ERROR_SOUND_MANAGER | 03,      /**< No playing sound */
	SOUND_MANAGER_ERROR_INVALID_STATE     = TIZEN_ERROR_SOUND_MANAGER | 04,      /**< Invalid state (Since 3.0) */
} sound_manager_error_e;

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_VOLUME_MODULE
 * @{
 */

/**
 * @brief Enumeration for sound type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_TYPE_SYSTEM,          /**< Sound type for system */
	SOUND_TYPE_NOTIFICATION,    /**< Sound type for notifications */
	SOUND_TYPE_ALARM,           /**< Sound type for alarm */
	SOUND_TYPE_RINGTONE,        /**< Sound type for ringtones (Since @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif) */
	SOUND_TYPE_MEDIA,           /**< Sound type for media */
	SOUND_TYPE_CALL,            /**< Sound type for call (Since @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif) */
	SOUND_TYPE_VOIP,            /**< Sound type for voip (Since @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif) */
	SOUND_TYPE_VOICE,           /**< Sound type for voice */
} sound_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_STREAM_POLICY_MODULE
 * @{
 */

/**
 * @brief Sound stream information handle.
 * @since_tizen 3.0
 */
typedef struct sound_stream_info_s* sound_stream_info_h;

/**
 * @brief Enumeration for sound stream type.
 * @since_tizen 3.0
 */
typedef enum {
	SOUND_STREAM_TYPE_MEDIA,              /**< Sound stream type for media */
	SOUND_STREAM_TYPE_SYSTEM,             /**< Sound stream type for system */
	SOUND_STREAM_TYPE_ALARM,              /**< Sound stream type for alarm */
	SOUND_STREAM_TYPE_NOTIFICATION,       /**< Sound stream type for notification */
	SOUND_STREAM_TYPE_EMERGENCY,          /**< Sound stream type for emergency */
	SOUND_STREAM_TYPE_VOICE_INFORMATION,  /**< Sound stream type for voice information */
	SOUND_STREAM_TYPE_VOICE_RECOGNITION,  /**< Sound stream type for voice recognition */
	SOUND_STREAM_TYPE_RINGTONE_VOIP,      /**< Sound stream type for ringtone for VoIP */
	SOUND_STREAM_TYPE_VOIP,               /**< Sound stream type for VoIP */
	SOUND_STREAM_TYPE_MEDIA_EXTERNAL_ONLY,/**< Sound stream type for media only for external devices */
} sound_stream_type_e;

/**
 * @brief Enumeration for change reason of sound stream focus state.
 * @since_tizen 3.0
 */
typedef enum {
	SOUND_STREAM_FOCUS_CHANGED_BY_MEDIA,              /**< Changed by the stream type for media */
	SOUND_STREAM_FOCUS_CHANGED_BY_SYSTEM,             /**< Changed by the stream type for system */
	SOUND_STREAM_FOCUS_CHANGED_BY_ALARM,              /**< Changed by the stream type for alarm */
	SOUND_STREAM_FOCUS_CHANGED_BY_NOTIFICATION,       /**< Changed by the stream type for notification */
	SOUND_STREAM_FOCUS_CHANGED_BY_EMERGENCY,          /**< Changed by the stream type for emergency */
	SOUND_STREAM_FOCUS_CHANGED_BY_VOICE_INFORMATION,  /**< Changed by the stream type for voice information */
	SOUND_STREAM_FOCUS_CHANGED_BY_VOICE_RECOGNITION,  /**< Changed by the stream type for voice recognition */
	SOUND_STREAM_FOCUS_CHANGED_BY_RINGTONE,           /**< Changed by the stream type for ringtone */
	SOUND_STREAM_FOCUS_CHANGED_BY_VOIP,               /**< Changed by the stream type for VoIP */
	SOUND_STREAM_FOCUS_CHANGED_BY_CALL,               /**< Changed by the stream type for voice-call or video-call */
	SOUND_STREAM_FOCUS_CHANGED_BY_MEDIA_EXTERNAL_ONLY,/**< Changed by the stream type for media only for external devices */
} sound_stream_focus_change_reason_e;

/**
 * @brief Enumeration for sound stream focus mask.
 * @since_tizen 3.0
 */
typedef enum {
	SOUND_STREAM_FOCUS_FOR_PLAYBACK    = 0x0001,   /**< Mask for playback focus */
	SOUND_STREAM_FOCUS_FOR_RECORDING   = 0x0002,   /**< Mask for recording focus */
	SOUND_STREAM_FOCUS_FOR_BOTH        = 0x0003,   /**< Mask for both playback and recording focus */
} sound_stream_focus_mask_e;

/**
 * @brief Enumeration for sound stream focus state.
 * @since_tizen 3.0
 */
typedef enum {
	SOUND_STREAM_FOCUS_STATE_RELEASED,   /**< Focus state for release */
	SOUND_STREAM_FOCUS_STATE_ACQUIRED,   /**< Focus state for acquisition */
} sound_stream_focus_state_e;

/**
 * @brief Enumeration for sound behavior.
 * @since_tizen 3.0
 * @remarks These values can be combined with bitwise 'or'.
 * @see sound_manager_get_current_playback_focus()
 * @see sound_manager_get_current_recording_focus()
 */
typedef enum {
	SOUND_BEHAVIOR_NONE          = 0x0000,   /**< None (default) */
	SOUND_BEHAVIOR_NO_RESUME     = 0x0001,   /**< No resumption */
	SOUND_BEHAVIOR_FADING        = 0x0002,   /**< Fading effect */
} sound_behavior_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_SESSION_MODULE
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() and sound_stream_type_e instead.
 * @brief Enumeration for session type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_TYPE_MEDIA = 0,      /**< Media type */
	SOUND_SESSION_TYPE_ALARM,          /**< Alarm type */
	SOUND_SESSION_TYPE_NOTIFICATION,   /**< Notification type */
	SOUND_SESSION_TYPE_EMERGENCY,      /**< Emergency type */
	SOUND_SESSION_TYPE_VOIP,           /**< VoIP type */
} sound_session_type_e;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_acquire_focus() or not instead.
 * @brief Enumeration for session option for starting.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_OPTION_MIX_WITH_OTHERS_WHEN_START = 0, /**< This session will be mixed with others when starting (default) */
	SOUND_SESSION_OPTION_PAUSE_OTHERS_WHEN_START,        /**< This session will interrupt other sessions when starting */
} sound_session_option_for_starting_e;

/**
 * @deprecated Deprecated since 3.0. In sound_stream_focus_state_changed_cb, you can choose to stop playing or not.
 * @brief Enumeration for session option during play.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_OPTION_INTERRUPTIBLE_DURING_PLAY = 0,  /**< This session will be interrupted by other sessions during play (default) */
	SOUND_SESSION_OPTION_UNINTERRUPTIBLE_DURING_PLAY,    /**< This session will not be interrupted by other media sessions */
} sound_session_option_for_during_play_e;

/**
 * @deprecated Deprecated since 3.0. In sound_stream_focus_state_changed_cb, you can choose to resume playing or not.
 * @brief Enumeration for session option for resumption.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_OPTION_RESUMPTION_BY_SYSTEM = 0,             /**< This session will be resumed according to system policy (default) */
	SOUND_SESSION_OPTION_RESUMPTION_BY_SYSTEM_OR_MEDIA_PAUSED, /**< This session will be resumed according to system policy and when the media session which interrupted this session is paused */
} sound_session_option_for_resumption_e;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_apply_stream_routing() instead.
 * @brief Enumeration for voip session mode.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_VOIP_MODE_RINGTONE = 0,                /**< voip mode for ringtone */
	SOUND_SESSION_VOIP_MODE_VOICE_WITH_BUILTIN_RECEIVER, /**< voip mode for during call with built-in receiver */
	SOUND_SESSION_VOIP_MODE_VOICE_WITH_BUILTIN_SPEAKER,  /**< voip mode for during call with built-in speaker */
	SOUND_SESSION_VOIP_MODE_VOICE_WITH_AUDIO_JACK,       /**< voip mode for during call with audio jack */
	SOUND_SESSION_VOIP_MODE_VOICE_WITH_BLUETOOTH,        /**< voip mode for during call with bluetooth */
} sound_session_voip_mode_e;

/**
 * @deprecated Deprecated since 3.0. Use sound_stream_focus_state_changed_cb instead.
 * @brief Enumeration for sound session interrupted type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	SOUND_SESSION_INTERRUPTED_COMPLETED = 0,        /**< Interrupt completed*/
	SOUND_SESSION_INTERRUPTED_BY_MEDIA,             /**< Interrupted by media application*/
	SOUND_SESSION_INTERRUPTED_BY_CALL,              /**< Interrupted by an incoming call*/
	SOUND_SESSION_INTERRUPTED_BY_EARJACK_UNPLUG,    /**< Interrupted by unplugging headphones*/
	SOUND_SESSION_INTERRUPTED_BY_RESOURCE_CONFLICT, /**< Interrupted by a resource conflict*/
	SOUND_SESSION_INTERRUPTED_BY_ALARM,             /**< Interrupted by an alarm*/
	SOUND_SESSION_INTERRUPTED_BY_EMERGENCY,         /**< Interrupted by an emergency*/
	SOUND_SESSION_INTERRUPTED_BY_NOTIFICATION,      /**< Interrupted by a notification*/
} sound_session_interrupted_code_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_DEVICE_MODULE
 * @{
 */

/**
 * @brief Sound device handle.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* sound_device_h;

/**
 * @brief Sound device list handle.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* sound_device_list_h;

/**
* @brief Enumeration for sound device type.
* @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
*/
typedef enum {
	SOUND_DEVICE_BUILTIN_SPEAKER,   /**< Built-in speaker */
	SOUND_DEVICE_BUILTIN_RECEIVER,  /**< Built-in receiver */
	SOUND_DEVICE_BUILTIN_MIC,       /**< Built-in mic */
	SOUND_DEVICE_AUDIO_JACK,        /**< Audio jack that can be connected to wired accessory such as headphone, headset, and so on */
	SOUND_DEVICE_BLUETOOTH,         /**< Bluetooth (Deprecated since 3.0) */
	SOUND_DEVICE_BLUETOOTH_MEDIA = SOUND_DEVICE_BLUETOOTH,  /**< Bluetooth device representing media (A2DP) profile (Since 3.0) */
	SOUND_DEVICE_HDMI,              /**< HDMI */
	SOUND_DEVICE_MIRRORING,         /**< MIRRORING (Deprecated since 3.0) */
	SOUND_DEVICE_FORWARDING = SOUND_DEVICE_MIRRORING,       /**< Device for forwarding (Since 3.0) */
	SOUND_DEVICE_USB_AUDIO,         /**< USB Audio */
	SOUND_DEVICE_BLUETOOTH_VOICE,   /**< Bluetooth device representing voice (SCO) profile (Since 3.0) */
} sound_device_type_e;

/**
* @brief Enumeration for sound device direction.
* @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
*/
typedef enum {
	SOUND_DEVICE_IO_DIRECTION_IN,   /**< Input device */
	SOUND_DEVICE_IO_DIRECTION_OUT,  /**< Output device */
	SOUND_DEVICE_IO_DIRECTION_BOTH, /**< Input/output device (both directions are available) */
} sound_device_io_direction_e;


/**
* @brief Enumeration for sound device state.
* @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
*/
typedef enum {
	SOUND_DEVICE_STATE_DEACTIVATED, /**< Deactivated state */
	SOUND_DEVICE_STATE_ACTIVATED,   /**< Activated state */
} sound_device_state_e;

/**
* @brief Enumeration for sound device mask.
* @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
*/
typedef enum {
	SOUND_DEVICE_IO_DIRECTION_IN_MASK      = 0x0001,  /**< Mask for input devices */
	SOUND_DEVICE_IO_DIRECTION_OUT_MASK     = 0x0002,  /**< Mask for output devices */
	SOUND_DEVICE_IO_DIRECTION_BOTH_MASK    = 0x0004,  /**< Mask for input/output devices (both directions are available) */
	SOUND_DEVICE_TYPE_INTERNAL_MASK        = 0x0010,  /**< Mask for built-in devices */
	SOUND_DEVICE_TYPE_EXTERNAL_MASK        = 0x0020,  /**< Mask for external devices */
	SOUND_DEVICE_STATE_DEACTIVATED_MASK    = 0x1000,  /**< Mask for deactivated devices */
	SOUND_DEVICE_STATE_ACTIVATED_MASK      = 0x2000,  /**< Mask for activated devices */
	SOUND_DEVICE_ALL_MASK                  = 0xFFFF,  /**< Mask for all devices */
} sound_device_mask_e;

/**
* @deprecated Deprecated since 3.0. Use sound_manager_add_device_state_changed_cb() instead.
* @brief Enumeration for changed information of sound device.
* @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
*/
typedef enum {
	SOUND_DEVICE_CHANGED_INFO_STATE,                 /**< State of the device was changed */
	SOUND_DEVICE_CHANGED_INFO_IO_DIRECTION,          /**< IO direction of the device was changed */
} sound_device_changed_info_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_VOLUME_MODULE
 * @{
 */

/**
 * @brief Called when the system volume has changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]   type	The sound type of the changed volume
 * @param[in]   volume	The new volume value
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre sound_manager_set_volume() will invoke this callback if you register it using sound_manager_set_volume_changed_cb().
 * @see sound_manager_set_volume_changed_cb()
 * @see sound_manager_unset_volume_changed_cb()
 */
typedef void (*sound_manager_volume_changed_cb) (sound_type_e type, unsigned int volume, void *user_data);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_STREAM_POLICY_MODULE
 * @{
 */

/**
 * @brief Called when the state of focus that belongs to the stream_info is changed.
 * @since_tizen 3.0
 *
 * @remarks	This function is issued in the internal thread of the sound manager.\n
 *	Therefore it is recommended not to call UI update function in this function.
 *
 * @param[in]   stream_info	The handle of stream information
 * @param[in]   focus_mask	The changed focus mask
 * @param[in]   focus_state	The changed focus state
 * @param[in]   reason		The reason for state change of the focus
 * @param[in]   sound_behavior	The requested sound behavior that should be followed, values of #sound_behavior_e combined with bitwise 'or'
 * @param[in]   extra_info	The extra information
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should register this callback using sound_manager_create_stream_information().
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_get_focus_state()
 */
typedef void (*sound_stream_focus_state_changed_cb) (sound_stream_info_h stream_info,
													sound_stream_focus_mask_e focus_mask,
													sound_stream_focus_state_e focus_state,
													sound_stream_focus_change_reason_e reason,
													int sound_behavior,
													const char *extra_info,
													void *user_data);

/**
 * @brief Called when the focus state for each sound stream type is changed regardless of the process.
 * @since_tizen 3.0
 *
 * @remarks	This function is invoked by the internal thread of the sound manager.\n
 *	Therefore it is recommended not to call functions which update the UI from this callback.
 *
 * @param[in]   id		The focus state change watch cb id
 * @param[in]   focus_mask	The changed focus mask
 * @param[in]   focus_state	The changed focus state
 * @param[in]   reason		The reason for state change of the focus
 * @param[in]   extra_info	The extra information
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should register this callback using sound_manager_add_focus_state_watch_cb().
 * @see sound_manager_add_focus_state_watch_cb()
 * @see sound_manager_remove_focus_state_watch_cb()
 */
typedef void (*sound_stream_focus_state_watch_cb) (int id, sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_e focus_state, sound_stream_focus_change_reason_e reason, const char *extra_info, void *user_data);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_SESSION_MODULE
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use sound_stream_focus_state_changed_cb instead.
 * @brief Called when the playing sound session is interrupted.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]   code	The interrupted code
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should register this callback using sound_manager_set_session_interrupted_cb().
 * @see sound_manager_set_session_interrupted_cb()
 * @see sound_manager_unset_session_interrupted_cb()
 */
typedef void (*sound_session_interrupted_cb) (sound_session_interrupted_code_e code, void *user_data);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_DEVICE_MODULE
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use sound_device_connection_changed_cb() instead.
 * @brief Called when the state of connection of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]   sound_device_h	The sound_device
 * @param[in]   is_connected	The state of device connection: (@c true = connected, @c false = disconnected)
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should register this callback using sound_manager_set_device_connected_cb().
 * @see sound_manager_set_device_connected_cb()
 * @see sound_manager_unset_device_connected_cb()
 */
typedef void (*sound_device_connected_cb) (sound_device_h device, bool is_connected, void *user_data);

/**
 * @deprecated Deprecated since 3.0.
 * @brief Called when the information of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]   sound_device_h	The sound_device
 * @param[in]   changed_info	The entry of sound device information
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should register this callback using sound_manager_set_device_information_changed_cb().
 * @see sound_manager_set_device_information_changed_cb()
 * @see sound_manager_unset_device_information_changed_cb()
 */
typedef void (*sound_device_information_changed_cb) (sound_device_h device, sound_device_changed_info_e changed_info, void *user_data);

/**
 * @brief Called when the connection state of a sound device was changed.
 * @since_tizen 3.0
 * @param[in]   device	The sound_device
 * @param[in]   is_connected	The state of device connection: @c true = connected, @c false = disconnected
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should add this callback using sound_manager_add_device_connection_changed_cb().
 * @see sound_manager_add_device_connection_changed_cb()
 * @see sound_manager_remove_device_connection_changed_cb()
 */
typedef void (*sound_device_connection_changed_cb) (sound_device_h device, bool is_connected, void *user_data);

/**
 * @brief Called when the state of a sound device was changed.
 * @since_tizen 3.0
 * @param[in]   device	The sound_device
 * @param[in]   state	The state of the device
 * @param[in]   user_data	The user data passed from the callback registration function
 * @pre You should add this callback using sound_manager_add_device_state_changed_cb().
 * @see sound_manager_add_device_state_changed_cb()
 * @see sound_manager_remove_device_state_changed_cb()
 */
typedef void (*sound_device_state_changed_cb) (sound_device_h device, sound_device_state_e state, void *user_data);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_VOLUME_MODULE
 * @{
 */

/**
 * @brief Gets the maximum volume level supported for a particular sound type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]		type The sound type
 * @param[out]	max	The maximum volume level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_set_volume()
 * @see sound_manager_get_volume()
 */
int sound_manager_get_max_volume(sound_type_e type, int *max);

/**
 * @brief Sets the volume level specified for a particular sound type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/volume.set
 * @param[in]		type The sound type
 * @param[in]		volume	The volume level to be set
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_PERMISSION_DENIED Permission denied
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_max_volume()
 * @see sound_manager_get_volume()
 */
int sound_manager_set_volume(sound_type_e type, int volume);

/**
 * @brief Gets the volume level specified for a particular sound type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]		type The sound type
 * @param[out]	volume	The current volume level
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_max_volume()
 * @see sound_manager_set_volume()
 */
int sound_manager_get_volume(sound_type_e type, int *volume);

/**
 * @deprecated Deprecated since 3.0.
 * @brief Sets the type of the sound being currently played.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]		type The sound type to set
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_current_sound_type()
 * @see sound_manager_unset_current_sound_type()
 */
int sound_manager_set_current_sound_type(sound_type_e type) TIZEN_DEPRECATED_API;

/**
 * @brief Gets the type of the sound being currently played.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[out]	type The current sound type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_PLAYING_SOUND No playing sound
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_current_sound_type()
 * @see sound_manager_unset_current_sound_type()
 */
int sound_manager_get_current_sound_type(sound_type_e *type);

/**
 * @deprecated Deprecated since 3.0.
 * @brief Unsets the type of the sound being currently played.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_current_sound_type()
 * @see sound_manager_get_current_sound_type()
 */
int sound_manager_unset_current_sound_type(void) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_add_volume_changed_cb() instead.
 * @brief Registers a callback function to be invoked when the volume level is changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	callback	Callback function to indicate change in volume
 * @param[in]	user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post sound_manager_volume_changed_cb() will be invoked.
 * @see sound_manager_unset_volume_changed_cb()
 * @see sound_manager_volume_changed_cb()
 */
int sound_manager_set_volume_changed_cb(sound_manager_volume_changed_cb callback, void *user_data) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_remove_volume_changed_cb() instead.
 * @brief Unregisters the volume change callback.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @return 0 on success, otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_volume_changed_cb()
 */
int sound_manager_unset_volume_changed_cb(void) TIZEN_DEPRECATED_API;

/**
 * @brief Adds a callback function to be invoked when the volume level is changed.
 * @since_tizen 3.0
 * @param[in]	callback	Callback function to indicate change in volume
 * @param[in]	user_data	The user data to be passed to the callback function
 * @param[out]	id	The callback id
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post sound_manager_volume_changed_cb() will be invoked.
 * @see sound_manager_remove_volume_changed_cb()
 * @see sound_manager_volume_changed_cb()
 */
int sound_manager_add_volume_changed_cb(sound_manager_volume_changed_cb callback, void *user_data, int *id);

/**
 * @brief Removes the volume change callback.
 * @since_tizen 3.0
 * @param[in]	id	The id of the callback to remove
 * @return 0 on success, otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_add_volume_changed_cb()
 */
int sound_manager_remove_volume_changed_cb(int id);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_STREAM_POLICY_MODULE
 * @{
 */

/**
 * @brief Creates a handle for stream information.
 * @since_tizen 3.0
 *
 * @remarks	The registered callback is issued in the internal thread of the sound manager.\n
 *	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.\n
 *	To apply the stream policy according to this stream information, this handle should be passed to other APIs\n
 *	related to playback or recording.(e.g. player, wav-player, audio-io, etc.)
 *
 * @param[in]	stream_type	The type of stream
 * @param[in]	callback	The focus state change callback function (optional, this can be NULL)
 * @param[in]	user_data	The user data to be passed to the callback function (optional, this can be NULL)
 * @param[out]	stream_info	The handle of stream information
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_NOT_SUPPORTED Not supported
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_add_device_for_stream_routing()
 * @see sound_manager_remove_device_for_stream_routing()
 * @see sound_manager_apply_stream_routing()
 * @see sound_manager_acquire_focus()
 * @see sound_manager_destroy_focus()
 * @see sound_manager_get_focus_state()
 */
int sound_manager_create_stream_information(sound_stream_type_e stream_type, sound_stream_focus_state_changed_cb callback, void *user_data, sound_stream_info_h *stream_info);

/**
 * @brief Destroys the handle for stream information.
 * @since_tizen 3.0
 *
 * @remarks	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.
 *
 * @param[in]	stream_info	The handle of stream information
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_create_stream_information()
 * @see sound_manager_add_device_for_stream_routing()
 * @see sound_manager_remove_device_for_stream_routing()
 * @see sound_manager_apply_stream_routing()
 * @see sound_manager_acquire_focus()
 * @see sound_manager_destroy_focus()
 * @see sound_manager_get_focus_state()
 */
int sound_manager_destroy_stream_information(sound_stream_info_h stream_info);

/**
 * @brief Gets the sound type of the stream information.
 * @since_tizen 3.0
 *
 * @remarks	In case of a @a stream_info made with #SOUND_STREAM_TYPE_EMERGENCY, it'll return #SOUND_MANAGER_ERROR_NO_DATA.\n
 *	The reason is that there is no #sound_type_e matched with this @a stream_info.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[out]	sound_type	The sound type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @pre Call sound_manager_create_stream_information() before calling this function.
 * @see sound_manager_create_stream_information()
 * @see sound_manager_set_volume()
 * @see sound_manager_get_max_volume()
 * @see sound_manager_get_volume()
 */
int sound_manager_get_sound_type(sound_stream_info_h stream_info, sound_type_e *sound_type);

/**
 * @brief Adds the device to the stream information for the stream routing.
 * @since_tizen 3.0
 *
 * @remarks	Use sound_manager_get_device_list() and sound_manager_get_next_device() to get the device.\n
 *	#SOUND_MANAGER_ERROR_POLICY could be returned according to the stream type of the @a stream_info.\n
 *	The available types of the @a stream_info for this function are #SOUND_STREAM_TYPE_VOIP and #SOUND_STREAM_TYPE_MEDIA_EXTERNAL_ONLY.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	device		The device item from sound_device_list_h
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @pre Call sound_manager_create_stream_information() before calling this function.
 * @post You can apply this setting by calling sound_manager_apply_stream_routing().
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_remove_device_for_stream_routing()
 * @see sound_manager_apply_stream_routing()
 */
int sound_manager_add_device_for_stream_routing(sound_stream_info_h stream_info, sound_device_h device);

/**
 * @brief Removes the device to the stream information for the stream routing.
 * @since_tizen 3.0
 *
 * @remarks	Use sound_manager_get_device_list() and sound_manager_get_next_device() to get the device.\n
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	device		The device item from sound_device_list_h
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @pre Call sound_manager_create_stream_information() and sound_manager_add_device_for_stream_routing() before calling this function.
 * @post You can apply this setting by calling sound_manager_apply_stream_routing().
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_add_device_for_stream_routing()
 * @see sound_manager_apply_stream_routing()
 */
int sound_manager_remove_device_for_stream_routing(sound_stream_info_h stream_info, sound_device_h device);

/**
 * @brief Applies the stream routing.
 * @since_tizen 3.0
 *
 * @remarks	If the stream has not been made yet, this setting will be applied when the stream starts to play.\n
 *
 * @param[in]	stream_info	The handle of stream information
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_STATE Invalid state
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @pre Call sound_manager_create_stream_information() and sound_manager_add_device_for_stream_routing() before calling this function.
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_add_device_for_stream_routing()
 * @see sound_manager_remove_device_for_stream_routing()
 */
int sound_manager_apply_stream_routing(sound_stream_info_h stream_info);

/**
 * @brief Acquires the stream focus.
 * @since_tizen 3.0
 *
 * @remarks	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	focus_mask	The focus mask that user wants to acquire
 * @param[in]	sound_behavior	The requesting sound behavior, values of #sound_behavior_e combined with bitwise 'or'
 * @param[in]	extra_info	The extra information for this request (optional, this can be NULL)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_INVALID_STATE Invalid state
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @pre Call sound_manager_create_stream_information() with its parameter for sound_stream_focus_state_changed_cb before calling this function.
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_release_focus()
 * @see sound_manager_get_focus_state()
 */
int sound_manager_acquire_focus(sound_stream_info_h stream_info, sound_stream_focus_mask_e focus_mask, int sound_behavior, const char *extra_info);

/**
 * @brief Releases the acquired focus.
 * @since_tizen 3.0
 *
 * @remarks	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	focus_mask	The focus mask that user wants to release
 * @param[in]	sound_behavior	The requesting sound behavior, values of #sound_behavior_e combined with bitwise 'or'
 * @param[in]	extra_info	The extra information for this request (optional, this can be NULL)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_INVALID_STATE Invalid state
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @pre Call sound_manager_create_stream_information() and sound_manager_acquire_focus() before calling this function.
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_acquire_focus()
 * @see sound_manager_get_focus_state()
 */
int sound_manager_release_focus(sound_stream_info_h stream_info, sound_stream_focus_mask_e focus_mask, int sound_behavior, const char *extra_info);

/**
 * @brief Gets the state of focus.
 * @since_tizen 3.0
 * @param[in]	stream_info	The handle of stream information
 * @param[out]	state_for_playback	The state of playback focus
 * @param[out]	state_for_recording	The state of recording focus
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @pre Call sound_manager_create_stream_information() before calling this function.
 * @see sound_manager_create_stream_information()
 * @see sound_manager_destroy_stream_information()
 * @see sound_manager_acquire_focus()
 * @see sound_manager_release_focus()
 */
int sound_manager_get_focus_state(sound_stream_info_h stream_info, sound_stream_focus_state_e *state_for_playback, sound_stream_focus_state_e *state_for_recording);

/**
 * @brief Sets auto focus reacquisition property.
 * @since_tizen 3.0
 *
 * @remarks	The focus reacquisition is set as default.
 *	If you don't want to reacquire the focus you've lost automatically, disable the focus reacquisition setting by using this function and vice versa.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	enable	The auto focus reacquisition property to set : (@c true = enable, @c false = disable)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @pre Call sound_manager_create_stream_information() before calling this function.
 * @see sound_manager_create_stream_information()
 */
int sound_manager_set_focus_reacquisition(sound_stream_info_h stream_info, bool enable);

/**
 * @brief Gets auto focus reacquisition property.
 * @since_tizen 3.0
 *
 * @remarks	The default value is true.
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[out]	enabled	The value of focus auto reacquisition property : (@c true = enabled, @c false = disabled)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @pre Call sound_manager_create_stream_information() before calling this function.
 * @see sound_manager_create_stream_information()
 */
int sound_manager_get_focus_reacquisition(sound_stream_info_h stream_info, bool *enabled);

/**
 * @brief Checks if the stream information is using the device.
 * @since_tizen 3.0
 *
 * @param[in]	stream_info	The handle of stream information
 * @param[in]	device	The device item
 * @param[out]	is_on	Whether the stream info is using the device or not : (@c true = use, @c false = not use)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_free_device_list()
 */
int sound_manager_is_stream_on_device(sound_stream_info_h stream_info, sound_device_h device, bool *is_on);

/**
 * @brief Gets the current device type for media playback stream.
 * @since_tizen 3.0
 *
 * @param[out]	device_type	The output device type that a media playback stream can go out
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 */
int sound_manager_get_current_media_playback_device_type(sound_device_type_e *device_type);

/**
 * @brief Gets the reason for the current acquired playback focus.
 * @since_tizen 3.0
 *
 * @remarks	If there is no acquired playback focus in this system, it'll return #SOUND_MANAGER_ERROR_NO_DATA.\n
 *	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.\n
 *	The @a extra_info should be released using free().
 *
 * @param[out]	acquired_by	The reason for the current acquired playback focus
 * @param[out]	sound_behavior	The requested sound behavior that should be followed, values of #sound_behavior_e combined with bitwise 'or'
 * @param[out]	extra_info The extra information of the acquired playback focus (optional, this can be NULL)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @see sound_manager_get_current_recording_focus()
 */
int sound_manager_get_current_playback_focus(sound_stream_focus_change_reason_e *acquired_by, int *sound_behavior, char **extra_info);

/**
 * @brief Gets the reason for the current acquired recording focus.
 * @since_tizen 3.0
 *
 * @remarks	If there is no acquired recording focus in this system, it'll return #SOUND_MANAGER_ERROR_NO_DATA.\n
 *	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.\n
 *	The @a extra_info should be released using free().
 *
 * @param[out]	acquired_by	The reason for the current acquired recording focus
 * @param[out]	sound_behavior	The requested sound behavior that should be followed, values of #sound_behavior_e combined with bitwise 'or'
 * @param[out]	extra_info The extra information of the acquired recording focus (optional, this can be NULL)
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @see sound_manager_get_current_playback_focus()
 */
int sound_manager_get_current_recording_focus(sound_stream_focus_change_reason_e *acquired_by, int *sound_behavior, char **extra_info);

/**
 * @brief Registers the watch callback function to be invoked when the focus state for each sound stream type is changed regardless of the process.
 * @since_tizen 3.0
 *
 * @remarks	The registered callback is invoked by the internal thread of the sound manager.\n
 *	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.
 *
 * @param[in]	focus_mask	The focus mask that user wants to watch
 * @param[in]	callback	The focus state change watch callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @param[out]	id		The focus state change watch callback id
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_remove_focus_state_watch_cb()
 */
int sound_manager_add_focus_state_watch_cb(sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_watch_cb callback, void *user_data, int *id);

/**
 * @brief Unregisters the focus state change watch callback.
 * @since_tizen 3.0
 *
 * @remarks	Do not call this function within sound_stream_focus_state_changed_cb() or sound_stream_focus_state_watch_cb(),\n
 *	otherwise #SOUND_MANAGER_ERROR_INVALID_OPERATION will be returned.
 *
 * @param[in]	id		The focus state change watch callback id
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_add_focus_state_watch_cb()
 */
int sound_manager_remove_focus_state_watch_cb(int id);

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_SESSION_MODULE
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Sets the application's sound session type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] type The session type to set
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NOT_SUPPORTED Not supported
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @see sound_manager_get_session_type()
 * @see sound_manager_set_media_session_option()
 * @see sound_manager_get_media_session_option()
 * @see sound_manager_set_media_session_resumption_option()
 * @see sound_manager_get_media_session_resumption_option()
 * @see sound_manager_set_voip_session_mode()
 * @see sound_manager_get_voip_session_mode()
 */
int sound_manager_set_session_type(sound_session_type_e type) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0.
 * @brief Gets the application's sound session type.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] type The session type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_set_session_type()
 * @see sound_manager_set_media_session_option()
 * @see sound_manager_get_media_session_option()
 * @see sound_manager_set_media_session_resumption_option()
 * @see sound_manager_get_media_session_resumption_option()
 * @see sound_manager_set_voip_session_mode()
 * @see sound_manager_get_voip_session_mode()
 */
int sound_manager_get_session_type(sound_session_type_e *type) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Sets the media sound session option.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] s_option The session option for starting
 * @param[in] d_option The session option for during play
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_get_media_session_option()
 * @see sound_manager_set_media_session_resumption_option()
 * @see sound_manager_get_media_session_resumption_option()
 */
int sound_manager_set_media_session_option(sound_session_option_for_starting_e s_option, sound_session_option_for_during_play_e d_option) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Gets the media sound session option.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[out] s_option The session option for starting
 * @param[out] d_option The session option for during play
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_set_media_session_option()
 * @see sound_manager_set_media_session_resumption_option()
 * @see sound_manager_get_media_session_resumption_option()
 */
int sound_manager_get_media_session_option(sound_session_option_for_starting_e *s_option, sound_session_option_for_during_play_e *d_option) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Sets the media sound session resumption option.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] option The session resumption option
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_set_media_session_option()
 * @see sound_manager_get_media_session_option()
 * @see sound_manager_get_media_session_resumption_option()
 */
int sound_manager_set_media_session_resumption_option(sound_session_option_for_resumption_e option) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Gets the media sound session resumption option.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[out] option The session resumption option
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_set_media_session_option()
 * @see sound_manager_get_media_session_option()
 * @see sound_manager_set_media_session_resumption_option()
 */
int sound_manager_get_media_session_resumption_option(sound_session_option_for_resumption_e *option) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Sets the mode of the voip sound session.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in] mode The voip session mode
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NOT_SUPPORTED Not supported
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @pre Call sound_manager_set_session_type(#SOUND_SESSION_TYPE_VOIP) before calling this function.
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_get_voip_session_mode()
*/
int sound_manager_set_voip_session_mode(sound_session_voip_mode_e mode) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Gets the mode of the voip sound session.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[out] mode The voip session mode
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NOT_SUPPORTED Not supported
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @pre Call sound_manager_set_session_type(#SOUND_SESSION_TYPE_VOIP) before calling this function.
 * @see sound_manager_set_session_type()
 * @see sound_manager_get_session_type()
 * @see sound_manager_set_voip_session_mode()
*/
int sound_manager_get_voip_session_mode(sound_session_voip_mode_e *mode) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_create_stream_information() instead.
 * @brief Registers a callback function to be invoked when the sound session being played was interrupted.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	callback	The interrupted callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_POLICY Noncompliance with the sound system policy
 * @post  sound_session_interrupted_cb() will be invoked.
 * @see sound_manager_unset_session_interrupted_cb()
 * @see sound_session_interrupted_cb()
 */
int sound_manager_set_session_interrupted_cb(sound_session_interrupted_cb callback, void *user_data) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0.
 * @brief Unregisters the callback function which is called when the sound session being played is interrupted.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @return 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_session_interrupted_cb()
 */
int sound_manager_unset_session_interrupted_cb(void) TIZEN_DEPRECATED_API;

/**
 * @}
 */

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_DEVICE_MODULE
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_get_device_list() instead.
 * @brief Gets the list consisting of connected devices.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @remarks	@a Calling this API will deallocate previously obtained list and each item.\n
 *	Use sound_manager_get_next_device() to get the first node of the list.
 *
 * @param[in]	device_mask	The mask value
 * @param[out]	device_list	The list of connected devices
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 */
int sound_manager_get_current_device_list(sound_device_mask_e device_mask, sound_device_list_h *device_list) TIZEN_DEPRECATED_API;

/**
 * @addtogroup CAPI_MEDIA_SOUND_MANAGER_DEVICE_MODULE
 * @{
 */

/**
 * @brief Gets the list consisting of connected devices.
 * @since_tizen 3.0
 *
 * @remarks	@a device_list should be freed using sound_manager_free_device_list().\n
 *	Use sound_manager_get_next_device() to get the first node of the list.
 *
 * @param[in]	device_mask	The mask values of #sound_device_mask_e combined with bitwise 'or'
 * @param[out]	device_list	The list of connected devices
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_list(int device_mask, sound_device_list_h *device_list);

/**
 * @brief Frees device list and each item of list.
 * @since_tizen 3.0
 *
 * @remarks	This function will deallocate not only device list itself but also each item.
 *
 * @param[in]	device_list	The device list got with sound_manager_get_device_list.
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 *
 *
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 */
int sound_manager_free_device_list(sound_device_list_h device_list);

/**
 * @brief Gets the next item of the device list.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device_list	The list of connected devices
 * @param[out]	device	The device item
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_next_device(sound_device_list_h device_list, sound_device_h *device);

/**
 * @brief Gets the previous item of the device list.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device_list	The list of connected devices
 * @param[out]	device	The device item
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_NO_DATA No data
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_prev_device(sound_device_list_h device_list, sound_device_h *device);

/**
 * @brief Gets the type of the device.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device	The device item
 * @param[out]	type	The type of the device
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_type(sound_device_h device, sound_device_type_e *type);

/**
 * @brief Gets the io direction of the device.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device	The device item
 * @param[out]	io_direction	The io direction of the device
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_io_direction(sound_device_h device, sound_device_io_direction_e *io_direction);

/**
 * @brief Gets the id of the device.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device	The device item
 * @param[out]	id	The id of the device
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_name()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_id(sound_device_h device, int *id);

/**
 * @brief Gets the name of the device.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device	The device item
 * @param[out]	name	The name of the device
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_state()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_name(sound_device_h device, char **name);

/**
 * @brief Gets the state of the device.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device	The device item
 * @param[out]	state	The state of the device
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see sound_manager_get_device_list()
 * @see sound_manager_get_next_device()
 * @see sound_manager_get_prev_device()
 * @see sound_manager_get_device_type()
 * @see sound_manager_get_device_io_direction()
 * @see sound_manager_get_device_id()
 * @see sound_manager_get_device_name()
 * @see sound_manager_free_device_list()
 */
int sound_manager_get_device_state(sound_device_h device, sound_device_state_e *state);

/**
 * @brief Registers a callback function to be invoked when the state of connection of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @remarks	The initial state of sound devices connected is deactivated.
 *
 * @param[in]	device_mask	The mask value
 * @param[in]	callback	The interrupted callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post  sound_device_connected_cb() will be invoked.
 * @see sound_manager_unset_device_connected_cb()
 * @see sound_device_connected_cb()
 */
int sound_manager_set_device_connected_cb(sound_device_mask_e device_mask, sound_device_connected_cb callback, void *user_data) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_remove_device_connection_changed_cb() instead.
 * @brief Unregisters the callback function which is called when the state of connection of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_device_connected_cb()
 */
int sound_manager_unset_device_connected_cb(void) TIZEN_DEPRECATED_API;

/**
 * @brief Adds a callback function to be invoked when the connection state of a sound device was changed.
 * @since_tizen 3.0
 *
 * @param[in]	device_mask	Device masks for which changes should be tracked, values of #sound_device_mask_e combined with bitwise 'or'
 * @param[in]	callback	The device connection state changed callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @param[out]	id	The callback id
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post  sound_device_connected_cb() will be invoked.
 * @see sound_manager_remove_device_connection_changed_cb()
 * @see sound_device_connection_changed_cb()
 */
int sound_manager_add_device_connection_changed_cb(int device_mask, sound_device_connection_changed_cb callback, void *user_data, int *id);

/**
 * @brief Removes a callback function invoked when the connection of a sound device was changed.
 * @since_tizen 3.0
 *
 * @param[in]	id	The id of the callback to remove
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_add_device_connection_changed_cb()
 */
int sound_manager_remove_device_connection_changed_cb(int id);

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_add_device_state_changed_cb() instead.
 * @brief Registers a callback function to be invoked when the information of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @param[in]	device_mask	The mask value
 * @param[in]	callback	The interrupted callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post  sound_device_information_changed_cb() will be invoked.
 * @see sound_manager_unset_device_information_changed_cb()
 * @see sound_device_information_changed_cb()
 */
int sound_manager_set_device_information_changed_cb(sound_device_mask_e device_mask, sound_device_information_changed_cb callback, void *user_data) TIZEN_DEPRECATED_API;

/**
 * @deprecated Deprecated since 3.0. Use sound_manager_remove_device_state_changed_cb() instead.
 * @brief Unregisters the callback function which is called when the information of a sound device was changed.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_set_device_information_changed_cb()
 */
int sound_manager_unset_device_information_changed_cb(void) TIZEN_DEPRECATED_API;

/**
 * @brief Adds a callback function to be invoked when the state of a sound device was changed.
 * @since_tizen 3.0
 *
 * @param[in]	device_mask	Device masks for which changes should be tracked, values of #sound_device_mask_e combined with bitwise 'or'
 * @param[in]	callback	The device state changed callback function
 * @param[in]	user_data	The user data to be passed to the callback function
 * @param[out]	id	The callback id
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @post  sound_device_state_changed_cb() will be invoked.
 * @see sound_manager_remove_device_state_changed_cb()
 * @see sound_device_state_connected_cb()
 */
int sound_manager_add_device_state_changed_cb(int device_mask, sound_device_state_changed_cb callback, void *user_data, int *id);

/**
 * @brief Removes a callback function invoked when the state of a sound device was changed.
 * @since_tizen 3.0
 *
 * @param[in]	id	The id of the callback to remove
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #SOUND_MANAGER_ERROR_NONE Success
 * @retval #SOUND_MANAGER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #SOUND_MANAGER_ERROR_INTERNAL Internal error inside the sound system
 * @see sound_manager_add_device_state_changed_cb()
 */
int sound_manager_remove_device_state_changed_cb(int id);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_MEDIA_SOUND_MANAGER_H__ */
