/*
 *  Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License
 */
/*
 * @file csr-content-screening-types.h
 * @author Dongsun Lee (ds73.lee@samsung.com)
 * @version 1.0
 * @brief Content screening CAPI enums, handles and callbacks
 */
#ifndef __CSR_CONTENT_SCREENING_TYPES_H_
#define __CSR_CONTENT_SCREENING_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_CSR_FRAMEWORK_CS_MODULE
 * @{
 */


/**
 * @partner
 * @brief Enumeration for severity level of a detected malware.
 * @since_tizen 3.0
 */
typedef enum {
	CSR_CS_SEVERITY_LOW = 0x01, /**< Low Severity. User can choose how to handle between skip, ignore and remove. */
	CSR_CS_SEVERITY_MEDIUM = 0x02, /**< Medium Severity. User can choose how to handle between skip, ignore and remove. */
	CSR_CS_SEVERITY_HIGH = 0x03 /**< High Severity. User can choose how to handle between skip and remove. */
} csr_cs_severity_level_e;


/**
 * @partner
 * @brief Enumeration for the option of asking user about handling a detected malware.
 * @since_tizen 3.0
 */
typedef enum {
	CSR_CS_ASK_USER_NO = 0x00, /**< Do not ask the user even if malicious contents were found.*/
	CSR_CS_ASK_USER_YES = 0x01 /**< Ask the user when malicious contents were found. */
} csr_cs_ask_user_e;


/**
 * @partner
 * @brief Enumeration for the user response from popup.
 * @since_tizen 3.0
 */
typedef enum {
	CSR_CS_USER_RESPONSE_USER_NOT_ASKED = 0x00, /**< No response from user. */
	CSR_CS_USER_RESPONSE_REMOVE = 0x01, /**< A user decided to remove a detected malicious content and it was removed. */
	CSR_CS_USER_RESPONSE_PROCESSING_ALLOWED = 0x02, /**< A user decided to process a detected malware. */
	CSR_CS_USER_RESPONSE_PROCESSING_DISALLOWED = 0x03, /**< A user decided not to process a detected malware. */
} csr_cs_user_response_e;


/**
 * @partner
 * @brief Enumeration for the action types for the detected malware files.
 * @since_tizen 3.0
 */
typedef enum {
	CSR_CS_ACTION_REMOVE = 0x00, /**< Remove the detected malware file. */
	CSR_CS_ACTION_IGNORE = 0x01, /**< Ignore the detected malware file. */
	CSR_CS_ACTION_UNIGNORE = 0x02 /**< Unignore the previously ignored file. */
} csr_cs_action_e;


/**
 * @partner
 * @brief Enumeration for maximum core usage during scanning.
 * @since_tizen 3.0
 */
typedef enum {
	CSR_CS_CORE_USAGE_DEFAULT = 0x00, /**< Use default setting value. */
	CSR_CS_CORE_USAGE_ALL = 0x01, /**< Use all cores during scanning. */
	CSR_CS_CORE_USAGE_HALF = 0x02, /**< Use half cores during scanning. */
	CSR_CS_CORE_USAGE_SINGLE = 0x03 /**< Use a single core during scanning. */
} csr_cs_core_usage_e;


/**
 * @partner
 * @brief Content screening APIs context handle.
 * @since_tizen 3.0
 */
typedef struct __csr_cs_context_s *csr_cs_context_h;


/**
 * @partner
 * @brief Detected malware handle.
 * @since_tizen 3.0
 */
typedef struct __csr_cs_malware_s *csr_cs_malware_h;


/**
 * @partner
 * @brief Detected malware list handle.
 * @since_tizen 3.0
 */
typedef struct __csr_cs_malware_list_s *csr_cs_malware_list_h;


/**
 * @partner
 * @brief Engine info handle.
 * @since_tizen 3.0
 */
typedef struct __csr_cs_engine_s *csr_cs_engine_h;


/**
 * @partner
 * @brief Called when each file scanning is done without malware.
 * @since_tizen 3.0
 * @remarks Only for asynchronous scan functions.
 * @remarks Called for each file or application which is not detected malware.
 * @param[in] file_path A path of the file scanned. It would be package path if it's in application
 * @param[in] user_data A pointer of a user data. It's provided by client when calling asyncronous scanning method
 * @see csr_cs_set_file_scanned_cb()
 * @see csr_cs_scan_files_async()
 * @see csr_cs_scan_dir_async()
 * @see csr_cs_scan_dirs_async()
 */
typedef void (*csr_cs_file_scanned_cb)(const char *file_path, void *user_data);


/**
 * @partner
 * @brief Called when each file scanning is done with malware.
 * @since_tizen 3.0
 * @remarks Only for asynchronous scan functions.
 * @remarks Called for each file or application which is detected malware.
 * @remarks @a malware will be released when a context is released using csr_cs_context_destroy().
 * @param[in] malware The detected malware handle.
 * @param[in] user_data A pointer of a user data. It's provided by client when calling asyncronous scanning method.
 * @see csr_cs_set_detected_cb()
 * @see csr_cs_scan_files_async()
 * @see csr_cs_scan_dir_async()
 * @see csr_cs_scan_dirs_async()
 */
typedef void (*csr_cs_detected_cb)(csr_cs_malware_h malware, void *user_data);


/**
 * @partner
 * @brief Called when scanning is finished successfully.
 * @since_tizen 3.0
 * @remarks Only for asynchronous scan functions.
 * @remarks Called only once at the end of scanning when success.
 * @param[in] user_data  A pointer of a user data. It's provided by client when calling asyncronous scanning method
 * @see csr_cs_set_completed_cb()
 * @see csr_cs_scan_files_async()
 * @see csr_cs_scan_dir_async()
 * @see csr_cs_scan_dirs_async()
 */
typedef void (*csr_cs_completed_cb)(void *user_data);


/**
 * @partner
 * @brief Called when scanning is cancelled by csr_cs_cancel_scanning().
 * @since_tizen 3.0
 * @remarks Only for asynchronous scan functions.
 * @remarks Called only once at the end of scanning by being canceled.
 * @param[in] user_data A pointer of a user data. It's provided by client when calling asyncronous scanning method
 * @see csr_cs_set_cancelled_cb()
 * @see csr_cs_cancel_scanning()
 * @see csr_cs_scan_files_async()
 * @see csr_cs_scan_dir_async()
 * @see csr_cs_scan_dirs_async()
 */
typedef void (*csr_cs_cancelled_cb)(void *user_data);


/**
 * @partner
 * @brief Called when scanning is stopped with an error.
 * @details The following error codes can be delivered.\n
 *          #CSR_ERROR_FILE_DO_NOT_EXIST,\n
 *          #CSR_ERROR_SOCKET,\n
 *          #CSR_ERROR_SERVER,\n
 *          #CSR_ERROR_ENGINE_NOT_EXIST,\n
 *          #CSR_ERROR_ENGINE_DISABLED,\n
 *          #CSR_ERROR_ENGINE_NOT_ACTIVATED,\n
 *          #CSR_ERROR_ENGINE_PERMISSION,\n
 *          #CSR_ERROR_ENGINE_INTERNAL
 * @since_tizen 3.0
 * @remarks Only for asynchronous scan functions.
 * @remarks Called only once at the end of scanning when failed with error.
 * @param[in] error_code Error code of #csr_error_e defined in csr-error.h
 * @param[in] user_data A pointer of a user data. It's provided by client when calling asynchronous scanning method
 * @see csr_cs_set_error_cb()
 * @see csr_cs_scan_files_async()
 * @see csr_cs_scan_dir_async()
 * @see csr_cs_scan_dirs_async()
 */
typedef void (*csr_cs_error_cb)(int error_code, void *user_data);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
