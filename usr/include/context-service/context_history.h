/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
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

#ifndef __TIZEN_CONTEXT_HISTORY_H__
#define __TIZEN_CONTEXT_HISTORY_H__


#include <tizen_error.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup CAPI_CONTEXT_HISTORY_MODULE
 * @{
 */

/**
 * @brief	Definition for the attribute key denoting "application id".
 * @details	This can be used as a key of context_history_record_get_string().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_APP_ID "AppId"

/**
 * @brief	Definition for the attribute key denoting "total count".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_TOTAL_COUNT "TotalCount"

/**
 * @brief	Definition for the attribute key denoting "total amount".
 * @details	This can be used as a key of context_history_record_get_double().
 * @since_tizen 3.0
 */
#define CONTEXT_HISTORY_TOTAL_AMOUNT "TotalAmount"

/**
 * @brief	Definition for the attribute key denoting "total duration".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_TOTAL_DURATION "TotalDuration"

/**
 * @brief	Definition for the attribute key denoting "last time".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_LAST_TIME "LastTime"

/**
 * @brief	Definition for the attribute key denoting "hour of day".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_HOUR_OF_DAY "HourOfDay"

/**
 * @brief	Definition for the attribute key denoting "audio jack status".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_AUDIO_JACK "AudioJack"

/**
 * @brief	Definition for the attribute key denoting "system volume".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_SYSTEM_VOLUME "SystemVolume"

/**
 * @brief	Definition for the attribute key denoting "media volume".
 * @details	This can be used as a key of context_history_record_get_int().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_MEDIA_VOLUME "MediaVolume"

/**
 * @brief	Definition for the attribute key denoting "address".
 * @details	This can be used as a key of context_history_record_get_string().
 * @since_tizen 2.4
 */
#define CONTEXT_HISTORY_ADDRESS "Address"

/**
 * @brief		Enumeration for errors.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_ERROR_NONE = TIZEN_ERROR_NONE,							/**< Successful */
	CONTEXT_HISTORY_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,	/**< Invalid parameter */
	CONTEXT_HISTORY_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED,	/**< Permission denied */
	CONTEXT_HISTORY_ERROR_NOT_SUPPORTED = TIZEN_ERROR_NOT_SUPPORTED,			/**< Not supported */
	CONTEXT_HISTORY_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY,			/**< Memory allocation failed */
	CONTEXT_HISTORY_ERROR_NO_DATA = TIZEN_ERROR_NO_DATA,						/**< No Data */
	CONTEXT_HISTORY_ERROR_OUT_OF_RANGE = (TIZEN_ERROR_CONTEXT | 0x03),		/**< Out of range */
	CONTEXT_HISTORY_ERROR_OPERATION_FAILED = (TIZEN_ERROR_CONTEXT | 0x04),	/**< Operation failed */
} context_history_error_e;

/**
 * @brief		Enumeration for data types of statistics and patterns.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_RECENTLY_USED_APP = 1,	/**< Recently used application.@n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_FREQUENTLY_USED_APP,	/**< Frequently used application.@n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_RARELY_USED_APP,		/**< Rarely used application.@n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_PEAK_TIME_FOR_APP,		/**< Peak time of application use activity.@n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_PEAK_TIME_FOR_MUSIC,		/**< Peak time of music listening activity.@n Privilege : http://tizen.org/privilege/mediahistory.read*/
	CONTEXT_HISTORY_PEAK_TIME_FOR_VIDEO,		/**< Peak time of video watching activity.@n Privilege : http://tizen.org/privilege/mediahistory.read*/
	CONTEXT_HISTORY_COMMON_SETTING_FOR_APP,		/**< Common setting value of application use activity.@n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_COMMON_SETTING_FOR_MUSIC,		/**< Common setting value of music listening activity.@n Privilege : http://tizen.org/privilege/mediahistory.read*/
	CONTEXT_HISTORY_COMMON_SETTING_FOR_VIDEO,		/**< Common setting value of video watching activity.@n Privilege : http://tizen.org/privilege/mediahistory.read*/
	CONTEXT_HISTORY_FREQUENTLY_COMMUNICATED_ADDRESS,		/**< Frequently communicated address.@n Privilege : http://tizen.org/privilege/callhistory.read*/
	CONTEXT_HISTORY_BATTERY_USAGE,		/**< Per-app battery usage in percentage (Since 3.0) @n Privilege : http://tizen.org/privilege/apphistory.read*/
	CONTEXT_HISTORY_RECENT_BATTERY_USAGE,		/**< Per-app battery usage in percentage since last charge (Since 3.0) @n Privilege : http://tizen.org/privilege/apphistory.read*/
} context_history_data_e;

/**
 * @brief		Enumeration for filters of statistics and patterns.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_FILTER_TIME_SPAN = 1,		/**< Time span of data in days*/
	CONTEXT_HISTORY_FILTER_RESULT_SIZE,			/**< Result size of data records*/
	CONTEXT_HISTORY_FILTER_APP_ID,			/**< Application id*/
	CONTEXT_HISTORY_FILTER_DAY_OF_WEEK,			/**<  Weekdays, weekends*/
	CONTEXT_HISTORY_FILTER_START_TIME,			/**< Start time of data in epoch time*/
	CONTEXT_HISTORY_FILTER_END_TIME,			/**< End time of data in epoch time*/
	CONTEXT_HISTORY_FILTER_WIFI_BSSID,			/**< Wi-Fi BSSID value*/
	CONTEXT_HISTORY_FILTER_AUDIO_JACK,			/**< Audio jack status value*/
	CONTEXT_HISTORY_FILTER_COMMUNICATION_TYPE			/**< Type of phone log*/
} context_history_filter_e;

/**
 * @brief		Enumeration for day of week filter.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_FILTER_DAY_OF_WEEK_WEEKDAYS = 1,		/**< Includes only weekdays*/
	CONTEXT_HISTORY_FILTER_DAY_OF_WEEK_WEEKENDS,		/**< Includes only weekends*/
	CONTEXT_HISTORY_FILTER_DAY_OF_WEEK_ALL			/**< Includes all days*/
} context_history_filter_day_of_week_e;

/**
 * @brief		Enumeration for audio jack filter.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_FILTER_AUDIO_JACK_NOT_CONNECTED = 0,		/**< Audio jack is not connected*/
	CONTEXT_HISTORY_FILTER_AUDIO_JACK_CONNECTED			/**< Audio jack is connected*/
} context_history_filter_audio_jack_e;

/**
 * @brief		Enumeration for log type filter.
 * @since_tizen 2.4
 */
typedef enum {
	CONTEXT_HISTORY_FILTER_COMMUNICATION_TYPE_CALL = 1,		/**< Includes only call logs*/
	CONTEXT_HISTORY_FILTER_COMMUNICATION_TYPE_MESSAGE,		/**< Includes only message logs*/
	CONTEXT_HISTORY_FILTER_COMMUNICATION_TYPE_ALL			/**< Includes all logs*/
} context_history_filter_communication_type_e;

/**
 * @brief Retrieving statistics and patterns using context history handle.
 * @since_tizen 2.4
 */
typedef struct _context_history_handle_s* context_history_h;

/**
 * @brief Computing statistics and patterns using history filter handle.
 * @since_tizen 2.4
 */
typedef struct _context_history_filter_handle_s* context_history_filter_h;

/**
 * @brief One or multiple records contained in history list handle.
 * @since_tizen 2.4
 */
typedef struct _context_history_list_handle_s* context_history_list_h;

/**
 * @brief One or multiple attributes contained in history list handle.
 * @since_tizen 2.4
 */
typedef struct _context_history_record_handle_s* context_history_record_h;

/**
 * @brief		Creates a context history handle.
 * @since_tizen 2.4
 * @remarks		The @c handle must be released using context_history_destroy().
 *
 * @param[out] handle    Handle to be initialized
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_OUT_OF_MEMORY			Out of memory
 *
 * @see context_history_destroy()
 */
int context_history_create(context_history_h* handle);

/**
 * @brief		Releases the resources occupied by a handle.
 * @details		This releases the memory allocated for the @c handle.
 *
 * @since_tizen 2.4
 *
 * @param[in]  handle   Handle to be released
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 *
 * @pre	context_history_create()
 */
int context_history_destroy(context_history_h handle);

/**
 * @brief		Creates a history filter.
 * @since_tizen 2.4
 * @remarks		The @c filter must be released using context_history_filter_destroy().
 *
 * @param[out]	filter		Filter handle to be initialized
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_OUT_OF_MEMORY		Memory allocation failed
 *
 * @see		context_history_filter_destroy()
 */
int context_history_filter_create(context_history_filter_h* filter);

/**
 * @brief		Releases the resources occupied by a filter.
 * @details		This releases the memory allocated for the @c filter.
 * @since_tizen 2.4
 *
 * @param[in]	filter		Filter handle to be released
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_filter_create()
 */
int context_history_filter_destroy(context_history_filter_h filter);

/**
 * @brief		Sets an integer value to a filter.
 * @details		This sets the value to a filter.
 * @since_tizen 2.4
 *
 * @param[in]	filter		The filter handle
 * @param[in]	filter_type	The filter type to set
 * @param[in]	value		The value to be set
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_filter_create()
 * @see		context_history_filter_set_string()
  */
int context_history_filter_set_int(context_history_filter_h filter, context_history_filter_e filter_type, int value);

/**
 * @brief		Sets a string to a filter.
 * @details		This sets the value to a filter.
 * @since_tizen 2.4
 *
 * @param[in]	filter		The filter handle
 * @param[in]	filter_type	The filter type to set
 * @param[in]	value		The value to be set
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_filter_create()
 * @see		context_history_filter_set_int()
  */
int context_history_filter_set_string(context_history_filter_h filter, context_history_filter_e filter_type, const char* value);

/**
 * @brief		Reads context statistics or patterns.
 * @details		Retrieves a given type of context statistics or patterns list.
 *				See the programming guide to find available filter type #context_history_filter_e@n
 *				for each context data type #context_history_data_e.
 * @since_tizen 2.4
 *
 * @remarks		The @c list must be released using context_history_list_destroy(). \n
 *              %http://tizen.org/privilege/apphistory.read or %http://tizen.org/privilege/mediahistory.read
 *				is needed to retrieve data. It depends on context data type #context_history_data_e.
 *
 * @param[in]	handle      Handle for controlling the context history data requests
 * @param[in]	data_type	Type of the history data
 * @param[in]	filter		Filter to be used to compute statistics or patterns. This can not be @c NULL
 * @param[out]	list   History data retrieved. This should be freed after use
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_OPERATION_FAILED		Operation failed
 * @retval		#CONTEXT_HISTORY_ERROR_OUT_OF_MEMORY			Out of memory
 * @retval		#CONTEXT_HISTORY_ERROR_NO_DATA			Requested data does not exist
 *
 * @pre context_history_create()
 * @post context_history_list_destroy()
 */
int context_history_get_list(context_history_h handle, context_history_data_e data_type, context_history_filter_h filter, context_history_list_h* list);

/**
 * @brief		Retrieves the number of records in a list.
 * @since_tizen 2.4
 *
 * @param[in]	list    The history data list handle
 * @param[out]	count   The count of the data list
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_OPERATION_FAILED		Operation failed
 *
 * @pre context_history_get_list()
 * @see context_history_list_move_first()
 * @see context_history_list_move_next()
 */
int context_history_list_get_count(context_history_list_h list, int* count);

/**
 * @brief		Retrieves the current record from the history list.
 * @details		The default current record is the first record.
 * @since_tizen 2.4
 * @remarks		The @c record must be released using context_history_record_destroy().
 *
 * @param[in]	list      The context history list handle
 * @param[out]	record   History data record retrieved
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_OPERATION_FAILED		Operation failed
 * @retval		#CONTEXT_HISTORY_ERROR_OUT_OF_MEMORY			Out of memory
 *
 * @pre context_history_get_list()
 * @post context_history_record_destroy()
 */
int context_history_list_get_current(context_history_list_h list, context_history_record_h* record);

/**
 * @brief		Moves a history data list to the first position.
 * @since_tizen 2.4
 *
 * @param[in]	list    The context history list handle
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 *
 * @pre context_history_get_list()
 * @see context_history_list_get_count()
 * @see context_history_list_move_next()
 */
int context_history_list_move_first(context_history_list_h list);

/**
 * @brief		Moves a history data list to the next position.
 * @since_tizen 2.4
 *
 * @param[in]	list    The context history list handle
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 * @retval		#CONTEXT_HISTORY_ERROR_NO_DATA			Requested data does not exist
 *
 * @pre context_history_get_list()
 * @see context_history_list_get_count()
 * @see context_history_list_move_first()
 */
int context_history_list_move_next(context_history_list_h list);

/**
 * @brief		Destroys a history list handle and release all its resources.
 * @since_tizen 2.4
 *
 * @param[in]	list    The context history data handle
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER		Invalid parameter
 *
 * @pre context_history_get_list()
 */
int context_history_list_destroy(context_history_list_h list);

/**
 * @brief		Gets an integer value from a record.
 * @details		See the programming guide to find available attribute keys@n
 *				for each context data #context_history_data_e.
 * @since_tizen 2.4
 *
 * @param[in]	record		The record handle
 * @param[in]	key			The key of attribute to get
 * @param[out]	value		The result value
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_list_get_current()
 * @see		context_history_record_get_double()
 * @see		context_history_record_get_string()
 */
int context_history_record_get_int(context_history_record_h record, const char* key, int* value);

/**
 * @brief		Gets a string from a record.
 * @details		See the programming guide to find available attribute keys@n
 *				for each context data #context_history_data_e.
 * @since_tizen 2.4
 * @remarks		@c value must be released using free().
 *
 * @param[in]	record		The record handle
 * @param[in]	key			The key of attribute to get
 * @param[out]	value		The result value
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_list_get_current()
 * @see		context_history_record_get_int()
 * @see		context_history_record_get_double()
 */
int context_history_record_get_string(context_history_record_h record, const char* key, char** value);

/**
 * @brief		Gets a double-precision value from a record.
 * @details		See the programming guide to find available attribute keys@n
 *				for each context data #context_history_data_e.
 * @since_tizen 3.0
 *
 * @param[in]	record		The record handle
 * @param[in]	key			The key of the attribute to get
 * @param[out]	value		The result value
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_list_get_current()
 * @see		context_history_record_get_int()
 * @see		context_history_record_get_string()
 */
int context_history_record_get_double(context_history_record_h record, const char* key, double* value);

/**
 * @brief		Destroys a record handle and releases all its resources.
 * @since_tizen 2.4
 *
 * @param[in]	record		The record handle
 *
 * @return		@c 0 on success, otherwise a negative error value
 * @retval		#CONTEXT_HISTORY_ERROR_NONE					Successful
 * @retval		#CONTEXT_HISTORY_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @pre		context_history_list_get_current()
 */
int context_history_record_destroy(context_history_record_h record);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
* @}
*/

#endif /* __TIZEN_CONTEXT_HISTORY_H__ */
