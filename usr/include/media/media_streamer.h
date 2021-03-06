/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
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

#ifndef __TIZEN_MEDIASTREAMER_H__
#define __TIZEN_MEDIASTREAMER_H__

#include <tizen.h>
#include <bundle.h>
#include <media_format.h>
#include <media_packet.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
* @file media_streamer.h
* @brief This file contains the capi media streamer API.
*/

/**
* @addtogroup CAPI_MEDIA_STREAMER_MODULE
* @{
*/

/**
 * @brief Media Streamer handle type.
 *
 * @since_tizen 3.0
 */
typedef void *media_streamer_h;

/**
 * @brief Media Streamer node handle type.
 *
 * @since_tizen 3.0
 */
typedef void *media_streamer_node_h;

/**
 * @brief Enumeration for media streamer node type.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_NODE_TYPE_NONE,                 /**<  Not defined type */
	MEDIA_STREAMER_NODE_TYPE_SRC,                  /**<  Src node type. Not available for media_streamer_node_create(). Use media_streamer_node_create_src() */
	MEDIA_STREAMER_NODE_TYPE_SINK,                 /**<  Sink node type. Not available for media_streamer_node_create(). Use media_streamer_node_create_sink() */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_ENCODER,        /**<  Video encoder node type */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_DECODER,        /**<  Video decoder node type */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_ENCODER,        /**<  Audio encoder node type */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_DECODER,        /**<  Audio decoder node type */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_CONVERTER,      /**<  Video converter node type */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_CONVERTER,      /**<  Audio converter node type */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_RESAMPLE,       /**<  Audio resample node type */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_PAY,            /**<  Rtp video payloader */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_PAY,            /**<  Rtp audio payloader */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_DEPAY,          /**<  Rtp video depayloader */
	MEDIA_STREAMER_NODE_TYPE_AUDIO_DEPAY,          /**<  Rtp audio depayloader */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_RATE,           /**<  Rate node type */
	MEDIA_STREAMER_NODE_TYPE_VIDEO_SCALE,          /**<  Scale node type */
	MEDIA_STREAMER_NODE_TYPE_TEXT_OVERLAY,         /**<  Overlay node type */
	MEDIA_STREAMER_NODE_TYPE_PARSER,               /**<  Parser node type */
	MEDIA_STREAMER_NODE_TYPE_FILTER,               /**<  Filter node type, to limit formats of data */
	MEDIA_STREAMER_NODE_TYPE_TEE,                  /**<  Tee node type, splits data to multiple path */
	MEDIA_STREAMER_NODE_TYPE_QUEUE,                /**<  Queue node type */
	MEDIA_STREAMER_NODE_TYPE_MQUEUE,               /**<  Multiple data queue node type */
	MEDIA_STREAMER_NODE_TYPE_MUXER,                /**<  Muxer node type */
	MEDIA_STREAMER_NODE_TYPE_DEMUXER,              /**<  Demuxer node type */
	MEDIA_STREAMER_NODE_TYPE_RTP,                  /**<  Rtp component to send and receive data */
	MEDIA_STREAMER_NODE_TYPE_INPUT_SELECTOR,       /**<  N-to-1 input stream selector */
	MEDIA_STREAMER_NODE_TYPE_OUTPUT_SELECTOR,      /**<  1-to-N output stream selector */
	MEDIA_STREAMER_NODE_TYPE_INTERLEAVE,           /**<  Folds many mono channel into one interleaved audio stream */
	MEDIA_STREAMER_NODE_TYPE_DEINTERLEAVE          /**<  Splits multi channel audio into many mono audio */
} media_streamer_node_type_e;

/**
 * @brief Enumeration for media streamer source node type.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_NODE_SRC_TYPE_NONE,           /**<  Not defined src type */
	MEDIA_STREAMER_NODE_SRC_TYPE_FILE,           /**<  Local file src type */
	MEDIA_STREAMER_NODE_SRC_TYPE_HTTP,           /**<  Http src type, Network internet feature is required */
	MEDIA_STREAMER_NODE_SRC_TYPE_RTSP,           /**<  Rtsp src type, Network internet feature is required */
	MEDIA_STREAMER_NODE_SRC_TYPE_CAMERA,         /**<  Camera src type, Camera feature is required */
	MEDIA_STREAMER_NODE_SRC_TYPE_AUDIO_CAPTURE,  /**<  Audio capture src type, Microphone feature is required */
	MEDIA_STREAMER_NODE_SRC_TYPE_VIDEO_CAPTURE,  /**<  Video capture src type, Camera feature is required */
	MEDIA_STREAMER_NODE_SRC_TYPE_AUDIO_TEST,     /**<  Audio test src type */
	MEDIA_STREAMER_NODE_SRC_TYPE_VIDEO_TEST,     /**<  Video test src type */
	MEDIA_STREAMER_NODE_SRC_TYPE_CUSTOM,         /**<  Custom src type */
	MEDIA_STREAMER_NODE_SRC_TYPE_ADAPTIVE        /**<  Adaptive src type, Network internet feature is required */
} media_streamer_node_src_type_e;

/**
 * @brief Enumeration for media streamer sink node type.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_NODE_SINK_TYPE_NONE,   /**<  Not defined sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_FILE,   /**<  Local file sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_RTSP,   /**<  Rtsp sink type, Network internet feature is required */
	MEDIA_STREAMER_NODE_SINK_TYPE_HTTP,   /**<  Http sink type, Network internet feature is required */
	MEDIA_STREAMER_NODE_SINK_TYPE_AUDIO,  /**<  Audio sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_OVERLAY,/**<  Overlay sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_FAKE,   /**<  Fake sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM, /**<  Custom sink type */
	MEDIA_STREAMER_NODE_SINK_TYPE_ADAPTIVE /**<  Adaptive sink type to generate fragmented files */
} media_streamer_node_sink_type_e;

/**
 * @brief Enumeration for media streamer state.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_STATE_NONE,    /**<  Streamer is not created */
	MEDIA_STREAMER_STATE_IDLE,    /**<  Streamer is created but not prepared */
	MEDIA_STREAMER_STATE_READY,   /**<  Streamer is ready to play */
	MEDIA_STREAMER_STATE_PLAYING, /**<  Streamer is playing */
	MEDIA_STREAMER_STATE_PAUSED,  /**<  Streamer is paused */
	MEDIA_STREAMER_STATE_SEEKING  /**<  Seek is under operation */
} media_streamer_state_e;

/**
 * @brief Enumeration for media streamer error.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_ERROR_NONE = TIZEN_ERROR_NONE,                                        /**< Successful */
	MEDIA_STREAMER_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,              /**< Invalid parameter */
	MEDIA_STREAMER_ERROR_INVALID_OPERATION  = TIZEN_ERROR_INVALID_OPERATION,             /**< Invalid operation */
	MEDIA_STREAMER_ERROR_FILE_NO_SPACE_ON_DEVICE = TIZEN_ERROR_FILE_NO_SPACE_ON_DEVICE,  /**< No space left on the device */
	MEDIA_STREAMER_ERROR_NOT_SUPPORTED  = TIZEN_ERROR_NOT_SUPPORTED,                     /**< The feature is not supported */
	MEDIA_STREAMER_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED,              /**< Permission denied */
	MEDIA_STREAMER_ERROR_INVALID_STATE = TIZEN_ERROR_MEDIA_STREAMER | 0x01,              /**< Invalid state */
	MEDIA_STREAMER_ERROR_CONNECTION_FAILED = TIZEN_ERROR_MEDIA_STREAMER | 0x02,          /**< Connection failed */
	MEDIA_STREAMER_ERROR_RESOURCE_CONFLICT = TIZEN_ERROR_MEDIA_STREAMER | 0x03,          /**< Resource conflict */
	MEDIA_STREAMER_ERROR_SEEK_FAILED = TIZEN_ERROR_MEDIA_STREAMER | 0x04,                /**< Seek operation failure */
} media_streamer_error_e;

/**
 * @brief Enumeration of media streamer buffer status of custom src
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_CUSTOM_BUFFER_UNDERRUN,	/**< Buffer underrun of custom src */
	MEDIA_STREAMER_CUSTOM_BUFFER_OVERFLOW,	/**< Buffer overflow of custom src */
} media_streamer_custom_buffer_status_e;

/**
 * @brief Enumeration for media streamer's interruption type.
 *
 * @since_tizen 3.0
 */
typedef enum {
	MEDIA_STREAMER_INTERRUPTED_BY_RESOURCE_CONFLICT,    /**< Interrupted by a resource conflict */
	MEDIA_STREAMER_INTERRUPTED_BY_SECURITY,             /**< Interrupted by a security policy */
} media_streamer_interrupted_code_e;

/**
 * @brief Definition for "camera-id" parameter of source node.
 * @details Index number of camera to activate.
 *          Data type is integer and default value is 0.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_CAMERA_ID "camera-id"

/**
 * @brief Definition for capture parameter of source node.
 * @details Width for camera size to capture.
 *          Data type is integer and default value is 1600.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_CAPTURE_WIDTH "capture-width"

/**
 * @brief Definition for capture parameter of source node.
 * @details Height for camera size to capture.
 *          Data type is integer and default value is 1200.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_CAPTURE_HEIGHT "capture-height"

/**
 * @brief Definition for is-live parameter of source node.
 * @details Whether to act as a live source.
 *          Data type is boolean and default value is false.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_IS_LIVE_STREAM "is-live"

/**
 * @brief Definition for uri parameter of source node.
 * @details Uri to read from
 *          Data type is string.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_URI "uri"

/**
 * @brief Definition for user-agent parameter of source node
 * @details Value of the User-Agent HTTP request header field.
 *          Data type is string.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_USER_AGENT "user-agent"

/**
 * @brief Definition for stream type parameter of source node
 * @details The type of the push data stream.
 *          0:stream, 1:seekable, 2:random-access (default:0)
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_STREAM_TYPE "stream-type"

/**
 * @brief Definition for port parameter of source or sink node
 * @details The port to receive the packets from.
 *          Data type is integer and default value is 5004.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_PORT "port"

/**
 * @brief Definition for video port parameter of source node
 * @details The port to receive the video packets from.
 *          Data type is integer.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_VIDEO_IN_PORT "video_in_port"

/**
 * @brief Definition for audio port parameter of source node
 * @details The port to receive the audio packets from.
 *          Data type is integer.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_AUDIO_IN_PORT "audio_in_port"

/**
 * @brief Definition for video port parameter of sink node
 * @details The port to send the video packets to.
 *          Data type is integer.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_VIDEO_OUT_PORT "video_out_port"

/**
 * @brief Definition for audio port parameter of sink node
 * @details The port to send the audio packets to.
 *          Data type is integer.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_AUDIO_OUT_PORT "audio_out_port"

/**
 * @brief Definition for IP address parameter of source node
 * @details IP address to send/receive packets for.
 *          Data type is string and default value is "0.0.0.0".
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_IP_ADDRESS "address"

/**
 * @brief Definition for audio device name parameter of source or sink node
 * @details ALSA device, as defined in an asound configuration file.
 *          ex) "hw:0,0", "hw:0,1"
 *          Data type is string and default value is "default".
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_AUDIO_DEVICE "audio_device"

/**
 * @brief Definition for sync parameter of sink node
 * @details Synchronize on the clock
 *          Data type is boolean and default value is true.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_CLOCK_SYNCHRONIZED "sync"

/**
 * @brief Definition for rotate parameter of sink node
 * @details Rotate angle of display output.
 *          0:none/1:rotate 90 degree/2:rotate 180 degree/3:rotate 270 degree
 *          Default value is 3(rotate 270 degree).
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_ROTATE "rotate"

/**
 * @brief Definition for flip parameter of sink node
 * @details Flip for display.
 *          0:none, 1:horizontal, 2:vertical, 3:both
 *          Default value is 0.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_FLIP "flip"

/**
 * @brief Definition for display geometry method parameter of sink node
 * @details Geometrical method for display.
 *          0:Letter box
 *          1:Original size
 *          2:Full-screen
 *          3:Cropped full screen
 *          4:Original size if surface size is larger than video size(width/height),
 *            or Letter box if video size(width/height) is larger than surface size.
 *          5:Custom ROI
 *          Default value is 0(Letter box).
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_DISPLAY_GEOMETRY_METHOD "display-geometry-method"

/**
 * @brief Definition for display parameter of sink node.
 * @details It is a object to draw video frame on.
 *          Data type is Pointer.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_DISPLAY "display"

/**
 * @brief Definition for visible parameter of sink node
 * @details Draws screen or blacks out.
 *          Data type is boolean and default value is true(visible).
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_VISIBLE "visible"

/**
 * @brief Definition for host parameter of sink node
 * @details The host/IP/Multicast group to send the packets to.
 *          Data type is string and default value is "localhost".
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_HOST "host"

/**
 * @brief Definition for segment location parameter of adaptive sink node.
 * @details Path for writing playlist from
 *          Data type is string.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_SEGMENT_LOCATION "location"

/**
 * @brief Definition for playlist location parameter of adaptive sink node.
 * @details Path for writing playlist from. Data type is string.
 * @since_tizen 3.0
 * @see media_streamer_node_get_params
 */
#define MEDIA_STREAMER_PARAM_PLAYLIST_LOCATION "playlist-location"

/**
 * @brief Called when error occurs in media streamer.
 * @details Following error codes can be delivered.
 *          #MEDIA_STREAMER_ERROR_INVALID_OPERATION,
 *          #MEDIA_STREAMER_ERROR_FILE_NO_SPACE_ON_DEVICE,
 *          #MEDIA_STREAMER_ERROR_NOT_SUPPORTED,
 *          #MEDIA_STREAMER_ERROR_CONNECTION_FAILED,
 *          #MEDIA_STREAMER_ERROR_RESOURCE_CONFLICT
 * @since_tizen 3.0
 * @param [in] streamer    Media streamer handle
 * @param [in] error       The error that occurred in media steamer
 * @param [in] user_data   The user data passed from the code where
 *                         media_streamer_set_error_cb() was invoked
 *                         This data will be accessible from @a media_streamer_error_cb
 * @pre Create media streamer handle by calling media_streamer_create() function
 * @see media_streamer_set_error_cb()
 * @see media_streamer_unset_error_cb()
 */
typedef void (*media_streamer_error_cb)(media_streamer_h streamer,
					media_streamer_error_e error, void *user_data);

/**
 * @brief Called when media streamer state is changed.
 * @since_tizen 3.0
 * @param [in] streamer            Media streamer handle
 * @param [in] previous_state      The previous state of the media streamer
 * @param [in] current_state       The current state of media streamer
 * @param [in] user_data           The user data passed from the code where
 *                                 media_streamer_set_state_changed_cb() was invoked
 *                                 This data will be accessible from @a media_streamer_state_changed_cb
 * @pre Create media streamer handle by calling media_streamer_create() function
 * @see media_streamer_set_state_change_cb()
 * @see media_streamer_unset_state_change_cb()
 */
typedef void (*media_streamer_state_changed_cb)(media_streamer_h streamer,
					media_streamer_state_e previous_state, media_streamer_state_e current_state, void *user_data);

/**
 * @brief Called when the custom source needs more data or has enough data.
 * @details This callback will be invoked when the buffer level drops below the threshold of max size
 *          or no free space in custom source buffer.
 * @since_tizen 3.0
 * @remarks Callback can be applied only for MEDIA_STREAMER_NODE_SRC_TYPE_CUSTOM source type
 * @param [in] node      Media streamer source node handle
 * @param [in] user_data The user data passed from the callback registration function
 * @see media_streamer_src_set_buffer_status_cb()
 * @see media_streamer_node_get_param()
 * @see media_streamer_node_set_param()
 */
typedef void (*media_streamer_custom_buffer_status_cb)(media_streamer_node_h node,
					media_streamer_custom_buffer_status_e status, void *user_data);

/**
 * @brief Called when new data is available from custom sink.
 * @details This callback can be applied only to MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM sink type
 * @since_tizen 3.0
 * @param [in] node      Media streamer sink node handle
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_sink_set_data_ready_cb() was invoked
 *                       This data will be accessible from @a media_streamer_sink_data_ready_cb
 * @pre media_streamer_sink_set_data_ready_cb()
 * @see MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM
 * @see media_streamer_sink_set_data_ready_cb()
 * @see media_streamer_sink_unset_data_ready_cb()
 */
typedef void (*media_streamer_sink_data_ready_cb)(media_streamer_node_h node, void *user_data);

/**
 * @brief  Called when the end-of-stream has been reached.
 * @details This callback can be applied only to MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM sink type
 * @since_tizen 3.0
 * @param [in] node      Media streamer sink node handle
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_sink_set_eos_cb() was invoked
 *                       This data will be accessible from @a media_streamer_sink_eos_cb
 * @pre media_streamer_sink_set_eos_cb()
 * @see MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM
 * @see media_streamer_sink_set_eos_cb()
 * @see media_streamer_sink_unset_eos_cb()
 */
typedef void (*media_streamer_sink_eos_cb)(media_streamer_node_h node, void *user_data);

/**
 * @brief Called when the seek operation is completed.
 * @since_tizen 3.0
 * @param[in] user_data     The user data passed from the callback registration function
 * @see media_streamer_set_play_position()
 */
typedef void (*media_streamer_position_changed_cb)(void *user_data);

/**
 * @brief Called when the media streamer is interrupted.
 * @since_tizen 3.0
 * @param[in]	error_code	The interrupted error code
 * @param[in]	user_data	The user data passed from the callback registration function
 * @see media_streamer_set_interrupted_cb()
 * @see media_streamer_unset_interrupted_cb()
 */
typedef void (*media_streamer_interrupted_cb)(media_streamer_interrupted_code_e code, void *user_data);

/**
 * @brief Registers a error callback function to be invoked when an error occurs.
 * @details Following error codes can be delivered by error callback.
 *          #MEDIA_STREAMER_ERROR_INVALID_OPERATION,
 *          #MEDIA_STREAMER_ERROR_FILE_NO_SPACE_ON_DEVICE,
 *          #MEDIA_STREAMER_ERROR_NOT_SUPPORTED,
 *          #MEDIA_STREAMER_ERROR_CONNECTION_FAILED,
 *          #MEDIA_STREAMER_ERROR_RESOURCE_CONFLICT
 * @since_tizen 3.0
 * @param [in] streamer  Media streamer handle
 * @param [in] callback  Callback function pointer
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_set_error_cb() was invoked
 *                       This data will be accessible from @a media_streamer_error_cb
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer handle by calling media_streamer_create() function
 * @post media_streamer_error_cb() will be invoked.
 * @see media_streamer_unset_error_cb()
 * @see media_streamer_error_cb()
 */
int media_streamer_set_error_cb(media_streamer_h streamer, media_streamer_error_cb callback, void *user_data);

/**
 * @brief Unregisters the error callback function.
 * @since_tizen 3.0
 * @param [in] streamer  Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_error_cb()
 */
int media_streamer_unset_error_cb(media_streamer_h streamer);

/**
 * @brief Registers a callback that will be triggered after media streamer state is changed.
 * @since_tizen 3.0
 * @param [in] streamer  Media streamer handle
 * @param [in] callback  Callback function pointer
 * @param [in] user_data The user data passed from the code
 *                       where media_streamer_set_state_change_cb() was invoked
 *                       This data will be accessible from @a media_streamer_state_changed_cb
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer handle by calling media_streamer_create() function
 * @post media_streamer_state_changed_cb() will be invoked.
 * @see media_streamer_unset_state_change_cb()
 * @see media_streamer_state_change_cb()
 */
int media_streamer_set_state_change_cb(media_streamer_h streamer, media_streamer_state_changed_cb callback, void *user_data);

/**
 * @brief Unregisters the state changed callback function.
 * @since_tizen 3.0
 * @param [in] streamer  Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_set_state_change_cb()
 */
int media_streamer_unset_state_change_cb(media_streamer_h streamer);

/**
 * @brief Registers a callback function to be invoked when the media streamer is interrupted.
 * @since_tizen 3.0
 * @param[in] streamer	Media streamer handle
 * @param[in] callback	The callback function to register
 * @param[in] user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @post media_streamer_interrupted_cb() will be invoked.
 * @see media_streamer_unset_interrupted_cb()
 * @see #media_streamer_interrupted_code_e
 */
int media_streamer_set_interrupted_cb(media_streamer_h streamer, media_streamer_interrupted_cb callback, void *user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen 3.0
 * @param[in] streamer Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_set_interrupted_cb()
 */
int media_streamer_unset_interrupted_cb(media_streamer_h streamer);

/**
 * @brief Registers a callback function to be invoked when buffer underrun or overflow is occurred.
 * @details This function can be called only for MEDIA_STREAMER_NODE_SRC_TYPE_CUSTOM source type
 * @since_tizen 3.0
 * @remarks This API is used for media stream playback only.
 * @param [in] source    Media streamer source node handle
 * @param [in] callback  The buffer status callback function to register
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_src_set_buffer_status_cb() was invoked
 *                       This data will be accessible from @a media_streamer_custom_buffer_status_cb()
 * @return @c 0 on success,
 *		   otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer source node handle by calling media_streamer_node_create_src() function
 * @pre Add created media streamer source node to media streamer by calling media_streamer_node_add() function
 * @post media_streamer_custom_buffer_status_cb() will be invoked.
 * @see media_streamer_src_unset_buffer_status_cb()
 * @see media_streamer_custom_buffer_status_cb()
 */
int media_streamer_src_set_buffer_status_cb(media_streamer_node_h source, media_streamer_custom_buffer_status_cb callback, void *user_data);

/**
 * @brief Unregisters the src buffer status callback function.
 * @since_tizen 3.0
 * @param [in] source    Media streamer source node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_src_set_buffer_status_cb()
 */
int media_streamer_src_unset_buffer_status_cb(media_streamer_node_h source);

/**
 * @brief Registers a callback function to be called when the custom sink is ready for data processing.
 * @details This function can be called only for MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM sink type
 * @since_tizen 3.0
 * @param [in] sink      Media streamer sink node handle
 * @param [in] callback  Callback function pointer
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_sink_set_data_ready_cb() was invoked
 *                       This data will be accessible from @a media_streamer_sink_data_ready_cb
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer sink handle by calling media_streamer_node_create_sink() function
 * @pre Add created media streamer sink node to media streamer by calling media_streamer_node_add() function
 * @post media_streamer_sink_data_ready_cb() will be invoked.
 * @see media_streamer_sink_unset_data_ready_cb()
 * @see media_streamer_sink_data_ready_cb()
 */
int media_streamer_sink_set_data_ready_cb(media_streamer_node_h sink, media_streamer_sink_data_ready_cb callback, void *user_data);

/**
 * @brief Unregisters the sink data ready callback function.
 * @since_tizen 3.0
 * @param [in] sink    Media streamer sink node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_sink_set_data_ready_cb()
 */
int media_streamer_sink_unset_data_ready_cb(media_streamer_node_h sink);

/**
 * @brief Registers a callback function to be called when custom sink detect the end-of-stream.
 * @since_tizen 3.0
 * @param [in] sink      Media streamer sink node handle
 * @param [in] callback  Callback function pointer
 * @param [in] user_data The user data passed from the code where
 *                       media_streamer_sink_set_eos_cb() was invoked.
 *                       This data will be accessible from @a media_streamer_sink_eos_cb
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer sink handle by calling media_streamer_node_create_sink() function
 * @pre Add created media streamer sink node to media streamer by calling media_streamer_node_add() function
 * @post media_streamer_sink_eos_cb() will be invoked.
 * @see media_streamer_sink_unset_eos_cb()
 * @see media_streamer_sink_eos_cb()
 */
int media_streamer_sink_set_eos_cb(media_streamer_node_h sink, media_streamer_sink_eos_cb callback, void *user_data);

/**
 * @brief Unregisters the sink end-of-stream callback function.
 * @since_tizen 3.0
 * @param [in] sink    Media streamer sink node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see media_streamer_sink_set_eos_cb()
 */
int media_streamer_sink_unset_eos_cb(media_streamer_node_h sink);

/**
 * @brief Creates an instance of media streamer and
 *        passes the handle to the caller.
 * @since_tizen 3.0
 * @remarks You must release @a streamer using media_streamer_destroy()
 * @param [out] streamer    Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_IDLE.
 * @see media_streamer_destroy()
 */
int media_streamer_create(media_streamer_h *streamer);

/**
 * @brief Sets media streamer state to MEDIA_STREAMER_STATE_READY.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre	The media streamer state must be set to #MEDIA_STREAMER_STATE_IDLE
 *      by calling media_streamer_create() or media_streamer_unprepare().
 * @pre At least one src and one sink should be added and linked in the streamer
 *      by calling media_streamer_node_create_src(), media_streamer_node_create_sink() and media_streamer_node_link().
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_READY.
 * @see media_streamer_unprepare()
 * @see media_streamer_create()
 */
int media_streamer_prepare(media_streamer_h streamer);

/**
 * @brief Sets media streamer state to MEDIA_STREAMER_STATE_IDLE.
 * @details The most recently used media is reset and no longer associated with the media streamer.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state should be higher than #MEDIA_STREAMER_STATE_IDLE.
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_IDLE.
 * @see media_streamer_prepare()
 */
int media_streamer_unprepare(media_streamer_h streamer);

/**
 * @brief Sets media streamer state to MEDIA_STREAMER_STATE_PLAYING.
 * @details Start running the current streamer, or resumes it if paused.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state must be set to #MEDIA_STREAMER_STATE_READY by calling media_streamer_prepare() or
 *      set to #MEDIA_STREAMER_STATE_PAUSED by calling media_streamer_pause().
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_PLAYING.
 * @see media_streamer_create()
 * @see media_streamer_pause()
 * @see media_streamer_stop()
 */
int media_streamer_play(media_streamer_h streamer);

/**
 * @brief Pauses the media streamer.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state must be set to #MEDIA_STREAMER_STATE_PLAYING.
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_READY.
 * @see media_streamer_create()
 * @see media_streamer_play()
 */
int media_streamer_pause(media_streamer_h streamer);

/**
 * @brief Stops the media streamer.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state must be set to #MEDIA_STREAMER_STATE_PLAYING by calling media_streamer_play() or
 *      set to #MEDIA_STREAMER_STATE_PAUSED by calling media_streamer_pause().
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_READY.
 * @see media_streamer_create()
 * @see media_streamer_play()
 * @see media_streamer_pause()
 */
int media_streamer_stop(media_streamer_h streamer);

/**
 * @brief Destroys media streamer.
 * @since_tizen 3.0
 * @remark Nodes in streamer will be removed automatically.
 *         Don't need to remove nodes by calling media_streamer_node_remove().
 *         If you want to change the node without destroying streamer handle,
 *         you can call the media_streamer_node_remove() function
 *         after setting the streamer state to MEDIA_STREAMER_STATE_IDLE state.
 * @param [in] streamer     Media streamer handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer handle by calling media_streamer_create() function
 * @post The media streamer state will be #MEDIA_STREAMER_STATE_NONE.
 * @see media_streamer_create()
 */
int media_streamer_destroy(media_streamer_h streamer);

/**
 * @brief Changes playback position to the defined time value, asynchronously.
 * @since_tizen 3.0
 * @param [in] streamer     Media streamer handle
 * @param [in] time         Time in millisecond
 * @param [in] accurate     If @c true, it will seek to the accurate position, but this might be considerably slower for some formats,
 *                          otherwise @c false, it will seek to the nearest keyframe.
 * @param [in] callback	    The callback function to register
 * @param [in] user_data	The user data to be passed to the callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE    Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_SEEK_FAILED Seek operation failure
 * @pre The media streamer state must be one of these: #MEDIA_STREAMER_STATE_PAUSED, or #MEDIA_STREAMER_STATE_PLAYING.
 * @post It invokes media_streamer_set_play_position() when seek operation completes, if you set a callback.
 * @see media_streamer_get_play_position()
 */
int media_streamer_set_play_position(media_streamer_h streamer, int time,
					bool accurate, media_streamer_position_changed_cb callback, void *user_data);

/**
 * @brief Gets the current position in milliseconds.
 * @since_tizen 3.0
 * @param [in]  streamer     Media streamer handle
 * @param [out] time         The current position in milliseconds
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state must be one of these: #MEDIA_STREAMER_STATE_PAUSED, or #MEDIA_STREAMER_STATE_PLAYING.
 * @see media_streamer_set_play_position()
 */
int media_streamer_get_play_position(media_streamer_h streamer, int *time);

/**
 * @brief Gets the total running time of the associated media.
 * @since_tizen 3.0
 * @remarks The streamer's src node type should be MEDIA_STREAMER_NODE_SRC_TYPE_FILE or MEDIA_STREAMER_NODE_SRC_TYPE_HTTP.
 *          If not, return value will be MEDIA_STREAMER_ERROR_NONE and duration will be -1.
 * @param [in]  streamer     Media streamer handle
 * @param [out] duration     The duration in milliseconds
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre The media streamer state must be one of these: #MEDIA_STREAMER_STATE_PAUSED, or #MEDIA_STREAMER_STATE_PLAYING.
 */
int media_streamer_get_duration(media_streamer_h streamer, int *duration);

/**
 * @brief Gets media streamer state.
 * @since_tizen 3.0
 * @param [in]  streamer     Media streamer handle
 * @param [out] state        Media streamer state
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE    Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a media streamer handle by calling media_streamer_create() function
 * @see #media_streamer_state_e
 */
int media_streamer_get_state(media_streamer_h streamer, media_streamer_state_e *state);

/**
 * @brief Creates media streamer source node.
 * @since_tizen 3.0
 * @remarks The internet privilege(http://tizen.org/privilege/internet) should be added if any URIs are used to play from network.
 *          The camera privilege(http://tizen.org/privilege/camera) should be added if the src node handle the camera device.
 *          The recorder privilege(http://tizen.org/privilege/recorder) should be added if the src node handle the recorder device.
 *          You can release @a source node using media_streamer_node_destroy() function.
 * @param [in]  type     Media streamer source node type
 * @param [out] src      Media streamer source node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_PERMISSION_DENIED Permission denied
 * @retval #MEDIA_STREAMER_ERROR_NOT_SUPPORTED Not supported
 * @see #media_streamer_node_src_type_e
 * @see media_streamer_node_destroy()
 */
int media_streamer_node_create_src(media_streamer_node_src_type_e type, media_streamer_node_h *src);

/**
 * @brief Pushes packet into custom source node.
 * @details This function can be called only for MEDIA_STREAMER_NODE_SRC_TYPE_CUSTOM.
 * @since_tizen 3.0
 * @param [in] src       Media streamer source node handle
 * @param [in] packet    Media packet handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_PERMISSION_DENIED Permission denied
 * @pre Create a source node handle by calling media_streamer_node_create_src() function
 * @pre	The media streamer state must be set to #MEDIA_STREAMER_STATE_IDLE at least.
 * @see #media_packet_h
 */
int media_streamer_node_push_packet(media_streamer_node_h src, media_packet_h packet);

/**
 * @brief Creates media streamer sink node.
 * @since_tizen 3.0
 * @remarks The internet privilege(http://tizen.org/privilege/internet) should be added if any URIs are used to transmit the output data.
 *          You can release @a sink node using media_streamer_node_destroy()
 * @param [in]  type     Type of sink node to be created
 * @param [out] sink     Media streamer sink node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_PERMISSION_DENIED Permission denied
 * @retval #MEDIA_STREAMER_ERROR_NOT_SUPPORTED Not supported
 * @see #media_streamer_node_sink_type_e
 * @see media_streamer_node_destroy()
 */
int media_streamer_node_create_sink(media_streamer_node_sink_type_e type, media_streamer_node_h *sink);

/**
 * @brief Pulls packet from custom sink node.
 * @details This function can be called only for MEDIA_STREAMER_NODE_SINK_TYPE_CUSTOM
 * @since_tizen 3.0
 * @param [in] sink      Media streamer sink node handle
 * @param [out] packet   Media packet handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a sink node handle by calling media_streamer_node_create_sink() function
 * @pre Set media_streamer_data_ready_cb by calling media_streamer_set_data_ready_cb() function.
 * @see #media_packet_h
 * @see media_streamer_node_create_sink()
 */
int media_streamer_node_pull_packet(media_streamer_node_h sink, media_packet_h *packet);

/**
 * @brief Creates media streamer node except MEDIA_STREAMER_NODE_TYPE_SRC and MEDIA_STREAMER_NODE_TYPE_SINK.
 * @details Creates node specific @a type with specific format of input
 *          and output data.
 * @since_tizen 3.0
 * @remarks The node type should not be MEDIA_STREAMER_NODE_TYPE_SRC and MEDIA_STREAMER_NODE_TYPE_SINK.
 *          To create src/sink type node, media_streamer_node_create_src()/media_streamer_node_create_sink() should be called.
 *          You can release @a node using media_streamer_node_destroy() function
 * @param [in]  type      Created node type
 * @param [in]  in_fmt    Media format handle for input data
 * @param [in]  out_fmt   Media format handle for output data
 * @param [out] node      Media streamer node handle to be created
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @see #media_streamer_node_type_e
 * @see #media_format_h
 * @see media_streamer_node_destroy()
 */
int media_streamer_node_create(media_streamer_node_type_e type, media_format_h in_fmt,
					media_format_h out_fmt, media_streamer_node_h *node);

/**
 * @brief Adds node to media streamer.
 * @since_tizen 3.0
 * @param [in] streamer    Media streamer handle
 * @param [in] node        Media streamer node handle to be added
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create media streamer handle by calling media_streamer_create() function
 * @pre Create node handle by calling media_streamer_node_create() function
 * @see media_streamer_create()
 * @see media_streamer_node_create()
 * @see media_streamer_node_create_src()
 * @see media_streamer_node_create_sink()
 */
int media_streamer_node_add(media_streamer_h streamer, media_streamer_node_h node);

/**
 * @brief Destroys media streamer node.
 * @since_tizen 3.0
 * @param [in] node        Media streamer node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create node handle by calling media_streamer_node_create() function
 * @pre If the node was added to media streamer, it have to be removed by calling media_streamer_node_remove() function
 * @see media_streamer_node_create()
 * @see media_streamer_node_create_src()
 * @see media_streamer_node_create_sink()
 * @see media_streamer_node_remove()
 */
int media_streamer_node_destroy(media_streamer_node_h node);

/**
 * @brief Removes media streamer node from streamer.
 * @since_tizen 3.0
 * @remarks To remove node without error posting, the state of streamer should be MEDIA_STREAMER_STATE_IDLE.
 *          If the node is linked, it will be unlinked before removing.
 * @param [in] streamer    Media streamer handle
 * @param [in] node        Media streamer node handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Add node to streamer by calling media_streamer_node_add() function
 * @see media_streamer_node_add()
 */
int media_streamer_node_remove(media_streamer_h streamer, media_streamer_node_h node);

/**
 * @brief Links two media streamer nodes.
 * @since_tizen 3.0
 * @remark Pads are node's input and output, where you can connect other nodes.
 *         (src_node) - (sink_node)
 *         src_node and sink_node is determined relatively.
 *         In case of (A)-(B)-(C),
 *         (B) can be sink_node with (A) or (B) can be src_node with (C).
 *         However, src type node is always src node and sink type node is always sink node.
 *         (A) is src node and can not be sink node at all.
 *         (C) is sink node and can not be src node at all.
 * @param [in] src_node      Media streamer node handle
 * @param [in] src_pad_name  The name of the source pad of the source node
 * @param [in] dest_node     The destination media streamer node handle
 * @param [in] sink_pad_name The name of the sink pad of the destination node
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a source node and a destination node handles
 *      by calling media_streamer_node_create() function
 *      and add the nodes into streamer by calling media_streamer_node_add() function.
 * @see media_streamer_node_create()
 * @see media_streamer_node_add()
 */
int media_streamer_node_link(media_streamer_node_h src_node, const char *src_pad_name,
					media_streamer_node_h dest_node, const char *sink_pad_name);

/**
 * @brief Sets media format for pad of media streamer node.
 * @since_tizen 3.0
 * @param [in] node        Media streamer node handle
 * @param [in] pad_name    Pad name
 * @param [in] fmt         Media format handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a node handle by calling media_streamer_node_createxxx() function
 * @pre Get pad name by calling media_streamer_node_get_pad_name() function
 * @see #media_format_h
 */
int media_streamer_node_set_pad_format(media_streamer_node_h node, const char *pad_name, media_format_h fmt);

/**
 * @brief Gets media format for pad of media streamer node.
 * @since_tizen 3.0
 * @param [in] node        Media streamer node handle
 * @param [in] pad_name    Pad name
 * @param [out] fmt        Media format handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a node handle by calling media_streamer_node_createxxx() function
 * @pre Get pad name by calling media_streamer_node_get_pad_name() function
 * @see #media_format_h
 */
int media_streamer_node_get_pad_format(media_streamer_node_h node, const char *pad_name, media_format_h *fmt);

/**
 * @brief Gets name of node pads.
 * @since_tizen 3.0
 * @remark After using the src_pad_name and sink_pad_name, it have to be free.
 *         src_pad_name or sink_pad_name can be null according to the node type.
 *         In case of src type node, sink_pad_name will be null.
 *         In case of sink type node, src_pad_name will be null.
 * @param [in]  node            Media streamer node handle
 * @param [out] src_pad_name    Array of source pad name
 * @param [out] src_pad_num     The number of source pads
 * @param [out] sink_pad_name   Array of sink pad name
 * @param [out] sink_pad_num    The number of sink pads
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a node handle by calling media_streamer_node_createxxx() function
 * @see media_streamer_node_create()
 * @see media_streamer_node_create_src()
 * @see media_streamer_node_create_sink()
 */
int media_streamer_node_get_pad_name(media_streamer_node_h node, char ***src_pad_name,
					int *src_pad_num, char ***sink_pad_name, int *sink_pad_num);


/**
 * @brief Sets parameters of node.
 * @details Many parameters can be set at one time all together by using bundle.
 * @since_tizen 3.0
 * @remarks The mediastorage privilege(http://tizen.org/privilege/mediastorage) should be added if any video/audio files are written in the internal storage devices.
 *          The externalstorage privilege(http://tizen.org/privilege/externalstorage) should be added if any video/audio files are written in the external storage devices.
 * @param [in] node        Media streamer node handle
 * @param [in] param_list  Key value array of media streamer node parameters
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_PERMISSION_DENIED Permission denied
 * @pre Create a node handle by calling media_streamer_node_createXXX() function.
 * @pre Get param list to set by calling media_streamer_node_get_params() function.
 * @see media_streamer_node_create()
 * @see media_streamer_node_create_src()
 * @see media_streamer_node_create_sink()
 * @see media_streamer_node_get_params()
 */
int media_streamer_node_set_params(media_streamer_node_h node, bundle *param_list);
/**
 * @brief Gets node parameter list.
 * @since_tizen 3.0
 * @remark After using param_list, it have to be free by calling bundle_free() in bundle.h
 *         Refer to the "Parameter information of node" in this file to get info.
 * @param [in]  node         Media streamer node handle
 * @param [out] param_list   Key value array of media streamer node parameters
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a node handle by calling media_streamer_node_createXXX() function
 * @post Set params which are needed to set by calling media_streamer_node_set_params() or media_streamer_node_set_param() function.
 * @see media_streamer_node_create()
 * @see media_streamer_src_create()
 * @see media_streamer_sink_create()
 * @see media_streamer_node_set_params()
 * @see media_streamer_node_set_param()
 */
int media_streamer_node_get_params(media_streamer_node_h node, bundle **param_list);

/**
 * @brief Sets single parameter of node.
 * @details Sets parameter one by one without creating param bundle.
 * @since_tizen 3.0
 * @remarks The mediastorage privilege(http://tizen.org/privilege/mediastorage) should be added if any video/audio files are written in the internal storage devices.
 *          The externalstorage privilege(http://tizen.org/privilege/externalstorage) should be added if any video/audio files are written in the external storage devices.
 * @param [in] node        Media streamer node handle
 * @param [in] param_name  Param name of node
 * @param [in] param_value Param value of node
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @retval #MEDIA_STREAMER_ERROR_PERMISSION_DENIED Permission denied
 * @pre Create a node handle by calling media_streamer_node_createXXX() function.
 * @pre Get param list to set by calling media_streamer_node_get_params() function.
 * @see media_streamer_node_create()
 * @see media_streamer_src_create()
 * @see media_streamer_sink_create()
 * @see media_streamer_node_get_params()
 * @see media_streamer_node_get_param()
 */
int media_streamer_node_set_param(media_streamer_node_h node,
					const char *param_name, const char *param_value);


/**
 * @brief Gets value of parameter.
 * @details Gets parameter one by one without creating param bundle.
 * @since_tizen 3.0
 * @param [in] node         Media streamer node handle
 * @param [in] param_name   Param name of node
 * @param [out] param_value Param value of node
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #MEDIA_STREAMER_ERROR_NONE Successful
 * @retval #MEDIA_STREAMER_ERROR_INVALID_STATE Invalid state
 * @retval #MEDIA_STREAMER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #MEDIA_STREAMER_ERROR_INVALID_OPERATION Invalid operation
 * @pre Create a node handle by calling media_streamer_node_createXXX() function.
 * @pre Get param list to know the param name by calling media_streamer_node_get_params() function.
 * @see media_streamer_node_create()
 * @see media_streamer_src_create()
 * @see media_streamer_sink_create()
 * @see media_streamer_node_get_params()
 * @see media_streamer_node_set_param()
 */
int media_streamer_node_get_param(media_streamer_node_h node,
					const char *param_name, char **param_value);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TIZEN_MEDIASTREAMER_H__ */
