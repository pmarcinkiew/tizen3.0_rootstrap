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


#ifndef __TIZEN_NETWORK_HTTP_H__
#define __TIZEN_NETWORK_HTTP_H__


#include <tizen.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


#ifndef TIZEN_ERROR_HTTP
#define TIZEN_ERROR_HTTP -0x03000000
#endif


/**
 * @file http.h
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_MODULE
 * @{
 */


/**
 * @brief The HTTP Session handle.
 * @since_tizen 3.0
 */
typedef void * http_session_h;


/**
 * @brief The HTTP Transaction handle.
 * @since_tizen 3.0
 */
typedef void * http_transaction_h;


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_SESSION_MODULE
 * @{
 */


/**
 * @brief Enumeration for the HTTP session.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_SESSION_MODE_NORMAL, /**< The Normal Mode */
	HTTP_SESSION_MODE_PIPELINING, /**< The Pipelining mode */
} http_session_mode_e;


/**
 * @}
 */


/**
* @addtogroup CAPI_NETWORK_HTTP_MODULE
* @{
*/


/**
 * @brief Enumeration for the HTTP method.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_METHOD_GET = 0x40, /**< The HTTP GET Method */
	HTTP_METHOD_OPTIONS = 0x41, /**< The HTTP OPTIONS Method */
	HTTP_METHOD_HEAD = 0x42, /**< The HTTP HEAD Method */
	HTTP_METHOD_DELETE = 0x43, /**< The HTTP DELETE Method */
	HTTP_METHOD_TRACE = 0x44, /**< The HTTP TRACE Method */
	HTTP_METHOD_POST = 0x60, /**< The HTTP POST Method */
	HTTP_METHOD_PUT = 0x61, /**< The HTTP PUT Method */
	HTTP_METHOD_CONNECT = 0x70, /**< The HTTP CONNECT Method */
} http_method_e;


/**
 * @brief Enumeration for the HTTP version.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_VERSION_1_0, /**< HTTP version 1.0 */
	HTTP_VERSION_1_1 /**< HTTP version 1.1 */
} http_version_e;


/**
 * @brief Enumeration for transfer pause state.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_PAUSE_RECV = 1 << 0, /**< Pause receiving data */
	HTTP_PAUSE_SEND = 1 << 2, /**< Pause sending data */
	HTTP_PAUSE_ALL = HTTP_PAUSE_RECV | HTTP_PAUSE_SEND /**< Pause both directions */
} http_pause_type_e;


/**
 * @brief Enumeration for the HTTP error code.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
	HTTP_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Out of memory */
	HTTP_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED, /**< Permission denied */
	HTTP_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
	HTTP_ERROR_INVALID_OPERATION = TIZEN_ERROR_INVALID_OPERATION, /**< Invalid operation */
	HTTP_ERROR_OPERATION_FAILED = TIZEN_ERROR_HTTP|0x01, /**< Operation failed */
	HTTP_ERROR_COULDNT_RESOLVE_HOST = TIZEN_ERROR_HTTP|0x06, /**< Couldn't resolve host */
	HTTP_ERROR_COULDNT_CONNECT = TIZEN_ERROR_HTTP|0x07, /**< Couldn't Connect to host */
	HTTP_ERROR_OPERATION_TIMEDOUT = TIZEN_ERROR_HTTP|0x28, /**< Timeout */
	HTTP_ERROR_SSL_CONNECT_ERROR = TIZEN_ERROR_HTTP|0x35, /**< SSL Error */
	HTTP_ERROR_CANCELED = TIZEN_ERROR_CANCELED, /**< Operation Canceled */
	HTTP_ERROR_NOT_SUPPORTED = TIZEN_ERROR_NOT_SUPPORTED, /**< API is not supported */
} http_error_code_e;


/**
 * @brief Enumeration for the HTTP status code.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_STATUS_UNDEFINED = 0, /**< The undefined status */
	HTTP_STATUS_CONTINUE = 100, /**< The status code: 100 Continue */
	HTTP_STATUS_SWITCHING_PROTOCOLS = 101, /**< The status code: 101 Switching Protocols */
	HTTP_STATUS_OK = 200, /**< The status code: 200 OK */
	HTTP_STATUS_CREATED = 201, /**< The status code: 201 Created */
	HTTP_STATUS_ACCEPTED = 202, /**< The status code: 202 Accepted */
	HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION = 203, /**< The status code: 203 Non-Authoritative Information */
	HTTP_STATUS_NO_CONTENT = 204, /**< The status code: 204 No %Content */
	HTTP_STATUS_RESET_CONTENT = 205, /**< The status code: 205 Reset %Content */
	HTTP_STATUS_PARTIAL_CONTENT = 206, /**< The status code: 206 Partial %Content */

	HTTP_STATUS_MULTIPLE_CHOICE = 300, /**< The status code: 300 Multiple Choices */
	HTTP_STATUS_MOVED_PERMANENTLY = 301, /**< The status code: 301 Moved Permanently */
	HTTP_STATUS_MOVED_TEMPORARILY = 302, /**< The status code: 302 Found */
	HTTP_STATUS_SEE_OTHER = 303, /**< The status code: 303 See Other */
	HTTP_STATUS_NOT_MODIFIED = 304, /**< The status code: 304 Not Modified */
	HTTP_STATUS_USE_PROXY = 305, /**< The status code: 305 Use Proxy */

	HTTP_STATUS_BAD_REQUEST = 400, /**< The status code: 400 Bad Request */
	HTTP_STATUS_UNAUTHORIZED = 401, /**< The status code: 401 Unauthorized */
	HTTP_STATUS_PAYMENT_REQUIRED = 402, /**< The status code: 402 Payment Required */
	HTTP_STATUS_FORBIDDEN = 403, /**< The status code: 403 Forbidden */
	HTTP_STATUS_NOT_FOUND = 404, /**< The status code: 404 Not Found */
	HTTP_STATUS_METHOD_NOT_ALLOWED = 405, /**< The status code: 405 Method Not Allowed */
	HTTP_STATUS_NOT_ACCEPTABLE = 406, /**< The status code: 406 Not Acceptable */
	HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED = 407, /**< The status code: 407 Proxy Authentication Required */
	HTTP_STATUS_REQUEST_TIME_OUT = 408, /**< The status code: 408 Request Timeout (not used) */
	HTTP_STATUS_CONFLICT = 409, /**< The status code: 409 Conflict */
	HTTP_STATUS_GONE = 410, /**< The status code: 410 Gone */
	HTTP_STATUS_LENGTH_REQUIRED = 411, /**< The status code: 411 Length Required */
	HTTP_STATUS_PRECONDITION_FAILED = 412, /**< The status code: 412 Precondition Failed */
	HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE = 413, /**< The status code: 413 Request Entity Too Large (not used) */
	HTTP_STATUS_REQUEST_URI_TOO_LARGE = 414, /**< The status code: 414 Request-URI Too Long (not used) */
	HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE = 415, /**< The status code: 415 Unsupported %Media Type */

	HTTP_STATUS_INTERNAL_SERVER_ERROR = 500, /**< The status code: 500 Internal Server Error */
	HTTP_STATUS_NOT_IMPLEMENTED = 501, /**< The status code: 501 Not Implemented */
	HTTP_STATUS_BAD_GATEWAY = 502, /**< The status code: 502 Bad Gateway */
	HTTP_STATUS_SERVICE_UNAVAILABLE = 503, /**< The status code: 503 Service Unavailable */
	HTTP_STATUS_GATEWAY_TIME_OUT = 504, /**< The status code: 504 Gateway Timeout */
	HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED = 505 /**< The status code: 505 HTTP Version Not Supported */
} http_status_code_e;


/**
 * @brief Enumeration for the HTTP authentication schemes.
 * @since_tizen 3.0
 */
typedef enum {
	HTTP_AUTH_NONE = 0, /**< No authentication type */
	HTTP_AUTH_PROXY_BASIC = 1, /**< The authentication type is Proxy Basic Authentication */
	HTTP_AUTH_PROXY_MD5 = 2, /**< The authentication type is Proxy Digest Authentication */
	HTTP_AUTH_WWW_BASIC = 3, /**< The authentication Type is HTTP Basic Authentication */
	HTTP_AUTH_WWW_MD5 = 4, /**< The authentication type is HTTP Digest Authentication */
	HTTP_AUTH_PROXY_NTLM = 5, /**< The authentication type is Proxy NTLM Authentication */
	HTTP_AUTH_WWW_NTLM = 7, /**< The authentication type is NTLM Authentication */
	HTTP_AUTH_WWW_NEGOTIATE = 8 /**< The authentication type is Negotiate Authentication */
} http_auth_scheme_e;


/**
 * @brief Called when the HTTP header is received.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] header The header information of HTTP Transaction
 * @param[in] header_len The length of the HTTP Transaction header
 * @param[in] user_data The user data
 * @see http_transaction_set_received_header_cb()
 */
typedef void (*http_transaction_header_cb)(http_transaction_h http_transaction, char *header, size_t header_len, void *user_data);


/**
 * @brief Called when the HTTP response is received.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] body Response information of HTTP Transaction
 * @param[in] size Size in bytes of each element to be written
 * @param[in] count Number of elements, each one with a size of size bytes
 * @param[in] user_data The user data
 * @see http_transaction_set_received_body_cb()
 */
typedef void (*http_transaction_body_cb)(http_transaction_h http_transaction, char *body, size_t size, size_t count, void *user_data);


/**
 * @brief Called when the HTTP ready to write event is received.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] recommended_chunk_size Recommended chunk length(bytes) of the HTTP transaction
 * @param[in] user_data The user data
 * @see http_transaction_set_uploaded_cb()
 */
typedef void (*http_transaction_write_cb)(http_transaction_h http_transaction, int recommended_chunk_size, void *user_data);


/**
 * @brief Called when the HTTP transaction is completed.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] user_data The user data
 * @see http_transaction_set_completed_cb()
 */
typedef void (*http_transaction_completed_cb)(http_transaction_h http_transaction, void *user_data);


/**
 * @brief Called when the HTTP transaction is aborted.
 * @details Following error codes can be delivered. \n
 *		    #HTTP_ERROR_OPERATION_FAILED, \n
 *		    #HTTP_ERROR_COULDNT_RESOLVE_HOST, \n
 *		    #HTTP_ERROR_COULDNT_CONNECT, \n
 *		    #HTTP_ERROR_OPERATION_TIMEDOUT, \n
 *		    #HTTP_ERROR_SSL_CONNECT_ERROR.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] error The error code about aborted reason
 * @param[in] user_data The user data
 * @see http_transaction_set_aborted_cb()
 */
typedef void (*http_transaction_aborted_cb)(http_transaction_h http_transaction, http_error_code_e error, void *user_data);


/**
 * @brief Called to notify when the content body of the response message is being downloaded or uploaded.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] download_total The total length of the data (in bytes) to download
 * @param[in] download_now The current length of the downloaded data (in bytes)
 * @param[in] upload_total The total length of the data (in bytes) to upload
 * @param[in] upload_now The current length of the uploaded data (in bytes)
 * @param[in] user_data The user data
 * @see http_transaction_set_progress_cb()
 */
typedef void (*http_transaction_progress_cb)(http_transaction_h http_transaction, double download_total, double download_now, double upload_total, double upload_now, void *user_data);


/**
 * @brief Initializes the HTTP module.
 * @since_tizen 3.0
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_OPERATION_FAILED Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_deinit()
 */
int http_init(void);


/**
 * @brief Deinitializes the HTTP module.
 * @since_tizen 3.0
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_OPERATION_FAILED Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_init()
 */
int http_deinit(void);


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_SESSION_MODULE
 * @{
 */


/**
 * @brief Creates the HTTP session handle.
 * @since_tizen 3.0
 * @remarks The @a http_session should be released using http_session_destroy().
 *			Opened transactions can't be submitted after destroying session handle.
 * @param[in] mode The HTTP session mode
 * @param[out] http_session	The HTTP session handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_session_destroy()
 */
int http_session_create(http_session_mode_e mode, http_session_h *http_session);


/**
 * @brief Destroys the HTTP session handle.
 * @since_tizen 3.0
 * @remarks http_session should be set to NULL after using it
 * @param[in] http_session The HTTP session handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_session_create()
 */
int http_session_destroy(http_session_h http_session);


/**
 * @brief Opens HTTP transaction from the HTTP Session.
 * @since_tizen 3.0
 * @remarks The @a http_transaction should be released using http_transaction_destroy().
 * @param[in] http_session The HTTP session handle
 * @param[in] method The HTTP request method
 * @param[out] http_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_session_open_transaction(http_session_h http_session, http_method_e method, http_transaction_h *http_transaction);


/**
 * @brief Sets the value to redirect the HTTP request automatically.
 * @since_tizen 3.0
 * @param[in] http_session The HTTP session handle
 * @param[in] auto_redirection The value which determines whether allow redirection or not
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_session_get_auto_redirection()
 */
int http_session_set_auto_redirection(http_session_h http_session, bool auto_redirection);


/**
 * @brief Gets the auto redirection for the HTTP request.
 * @since_tizen 3.0
 * @param[in] http_session The HTTP session handle
 * @param[out] auto_redirect The value of auto redirect
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_session_set_auto_redirection()
 */
int http_session_get_auto_redirection(http_session_h http_session, bool *auto_redirect);


/**
 * @brief Gets the number of active transactions in the current session.
 * @since_tizen 3.0
 * @param[in] http_session The HTTP session handle
 * @param[out] active_transaction_count	The number of activated transactions
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_session_get_active_transaction_count(http_session_h http_session, int *active_transaction_count);


/**
 * @brief Gets the maximum number of transactions for the current session.
 * @since_tizen 3.0
 * @param[in] http_session The HTTP session handle
 * @param[out] transaction_count The maximum transaction count
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_session_get_max_transaction_count(http_session_h http_session, int *transaction_count);


/**
 * @brief Destroys all transactions.
 * @since_tizen 3.0
 * @remarks All http_transactions should be set to NULL after using it
 * @param[in] http_session The HTTP session handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OPERATION_FAILED Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_session_destroy_all_transactions(http_session_h http_session);


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_TRANSACTION_MODULE
 * @{
 */


/**
 * @brief Submits the HTTP request.
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/internet \n
 *			  %http://tizen.org/privilege/network.get
 * @param[in] http_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @retval #HTTP_ERROR_PERMISSION_DENIED Permission denied
 */
int http_transaction_submit(http_transaction_h http_transaction);


/**
 * @brief Closes the HTTP transaction handle.
 * @since_tizen 3.0
 * @remarks The @a transaction is released by http_transaction_destroy().
 *			http_transaction should be set to NULL after using it.
 * @param[in] http_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 * @see http_transaction_create()
 */
int http_transaction_destroy(http_transaction_h http_transaction);


/**
 * @brief Registers callback called when receives header.
 * @since_tizen 3.0
 * @param[in] http_transaction	The HTTP transaction handle
 * @param[in] header_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_received_header_cb(http_transaction_h http_transaction, http_transaction_header_cb header_cb, void* user_data);


/**
 * @brief Registers callback called when receives body.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] body_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_received_body_cb(http_transaction_h http_transaction, http_transaction_body_cb body_cb, void* user_data);


/**
 * @brief Registers callback called when writes data.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] write_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_uploaded_cb(http_transaction_h http_transaction, http_transaction_write_cb write_cb, void* user_data);


/**
 * @brief Registers callback called when transaction is completed.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] completed_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_completed_cb(http_transaction_h http_transaction, http_transaction_completed_cb completed_cb, void* user_data);


/**
 * @brief Registers callback called when transaction is aborted.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] aborted_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_aborted_cb(http_transaction_h http_transaction, http_transaction_aborted_cb aborted_cb, void* user_data);


/**
 * @brief Registers the progress callbacks.
 * @details Registers callback that is called when data is uploaded/downloaded.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] progress_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_progress_cb(http_transaction_h http_transaction, http_transaction_progress_cb progress_cb, void* user_data);


/**
 * @brief Sets the timeout in seconds that is the timeout for waiting the transaction.
 * @details Sets the timeout in seconds that is the timeout for waiting the transaction. \n
 *          A timeout value of zero means an infinite timeout.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] timeout The timeout in seconds
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_timeout(http_transaction_h http_transaction, int timeout);


/**
 * @brief Gets the timeout in seconds for the transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] timeout The timeout in seconds
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_timeout(http_transaction_h http_transaction, int *timeout);


/**
 * @brief Resumes the transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OPERATION_FAILED Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_resume(http_transaction_h http_transaction);


/**
 * @brief Pauses the transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] pause_type The pause type of the connection
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OPERATION_FAILED Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_pause(http_transaction_h http_transaction, http_pause_type_e pause_type);

/**
 * @brief Cancels the transaction.
 * @details This function cancels the transaction.\n
 *			The aborted callback is invoked after using it.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE  Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION  Invalid operation
 * @retval #HTTP_ERROR_OPERATION_FAILED  Operation failed
 * @retval #HTTP_ERROR_NOT_SUPPORTED  Not Supported
 */
int http_transaction_cancel(http_transaction_h http_transaction);

/**
 * @brief Sets ready to write event for a transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] read_to_write Enable/disable ready to write
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_ready_to_write(http_transaction_h http_transaction, bool read_to_write);


/**
 * @brief Sets the interface name.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] interface_name The interface name to use as outgoing network interface
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_interface_name(http_transaction_h http_transaction, const char *interface_name);


/**
 * @brief Gets the interface name.
 * @since_tizen 3.0
 * @remarks The @a interface_name should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] interface_name The interface name
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_interface_name(http_transaction_h http_transaction, char **interface_name);


/**
 * @brief Sets the flag to verify a server certificate.
 * @details The verify determines whether verifies the peer's certificate.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] verify The flag to verify a server certificate; true means verifies; false means it doesn't.
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_server_certificate_verification(http_transaction_h http_transaction, bool verify);


/**
 * @brief Gets the flag to verify a server certificate.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] verify The flag to verify a server certificate; true means verifies; false means it doesn't.
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_server_certificate_verification(http_transaction_h http_transaction, bool* verify);


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_HEADER_MODULE
 * @{
 */


/**
 * @brief Adds a named field to header.
 * @details Adds a named field, which is a <@c fieldName, @c fieldValue> pair, to the current instance of HTTP Transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] field_name The HTTP Header Field name
 * @param[in] field_value The HTTP Header Field value
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_header_add_field(http_transaction_h http_transaction, const char *field_name, const char* field_value);


/**
 * @brief Removes the named field from header.
 * @details Remove the named field, which is a <@c fieldName, @c fieldValue> pair, from the current instance of HTTP Transaction.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] field_name The HTTP Header Field name
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_header_remove_field(http_transaction_h http_transaction, const char *field_name);


/**
 * @brief Gets the HTTP Header Field value from custom header.
 * @since_tizen 3.0
 * @remarks The @a field_value should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] field_name The HTTP Header Field name
 * @param[out] field_value The HTTP Header Field value
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_header_get_field_value(http_transaction_h http_transaction, const char *field_name, char **field_value);


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_REQUEST_MODULE
 * @{
 */


/**
 * @brief Sets an HTTP method of the request header.
 * @details Sets an HTTP method such as GET, POST, PUT and etc.
 * @since_tizen 3.0
 * @remarks The default method is GET.
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] method The HTTP method
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_set_method(http_transaction_h http_transaction, http_method_e method);


/**
 * @brief Gets the HTTP method from request header.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] method The HTTP method
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_get_method(http_transaction_h http_transaction, http_method_e *method);


/**
 * @brief Sets an HTTP version of the request header.
 * @since_tizen 3.0
 * @remarks The default version is HTTP 1.1.
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] version The HTTP version
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_set_version(http_transaction_h http_transaction, http_version_e version);


/**
 * @brief Gets the HTTP version from request header.
 * @details Gets the HTTP version.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] version The HTTP version
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_get_version(http_transaction_h http_transaction, http_version_e *version);


/**
 * @brief Sets a URI of the request header.
 * @details Sets a URI of the request header.
 * @since_tizen 3.0
 * @remarks It should be used before http_transaction_submit().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] host_uri The URI to use in the request
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_set_uri(http_transaction_h http_transaction, const char *host_uri);


/**
 * @brief Gets the URI.
 * @since_tizen 3.0
 * @remarks The @a host_uri should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] host_uri The host URI
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_get_uri(http_transaction_h http_transaction, char **host_uri);


/**
 * @brief Sets the Accept-Encoding header field of HTTP Request.
 * @details The Accept-Encoding header enables automatic decompression of HTTP downloads.
 * @since_tizen 3.0
 * @remarks If empty string is set, an Accept-Encoding header contains all supported built-in compressions.
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] encoding The encoding algorithms (e.g. gzip, deflate)
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_set_accept_encoding(http_transaction_h http_transaction, const char *encoding);


/**
 * @brief Gets the Accept-Encoding header field of HTTP Request.
 * @since_tizen 3.0
 * @remarks The @a encoding should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] encoding The encoding algorithms
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_get_accept_encoding(http_transaction_h http_transaction, char **encoding);


/**
 * @brief Sets a cookie in the HTTP request.
 * @since_tizen 3.0
 * @remarks The format of string should be NME=CONTENTS (e.g. "name1=hello; name2=tizen;")
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] cookie The cookie
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_set_cookie(http_transaction_h http_transaction, const char *cookie);


/**
 * @brief Gets a cookie in the HTTP request.
 * @since_tizen 3.0
 * @remarks The @a cookie should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] cookie The cookie
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_get_cookie(http_transaction_h http_transaction, char **cookie);


/**
 * @brief Writes the request message body.
 * @details This function writes the request message body in the internal queue. \n
 *			The written queue for request body is uploaded after invoking http_transaction_submit().
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] body The message body data
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_request_write_body(http_transaction_h http_transaction, const char *body);

/**
 * @brief Sets the file path for uploading a file.
 * @since_tizen 3.0
 * @remarks It is used with #HTTP_METHOD_PUT. \n
 *          http://tizen.org/privilege/mediastorage is needed if input or output path are relevant to media storage. \n
 *          http://tizen.org/privilege/externalstorage is needed if input or output path are relevant to external storage.
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] file_path The path for file
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE  Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION  Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED  Not Supported
 */
int http_transaction_request_set_upload_file(http_transaction_h http_transaction, const char *file_path);

/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_RESPONSE_MODULE
 * @{
 */


/**
 * @brief Gets the HTTP status code from HTTP Response.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] status_code The HTTP status code
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_response_get_status_code(http_transaction_h http_transaction, http_status_code_e *status_code);


/**
 * @brief Gets the HTTP status text from HTTP Response.
 * @since_tizen 3.0
 * @remarks The @a status_text should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] status_text The HTTP status text
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_response_get_status_text(http_transaction_h http_transaction, char **status_text);


/**
 * @brief Gets the HTTP version from HTTP Response.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] version The HTTP version
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_response_get_version(http_transaction_h http_transaction, http_version_e *version);


/**
 * @}
 */


/**
 * @addtogroup CAPI_NETWORK_HTTP_AUTHENTICATION_MODULE
 * @{
 */


/**
 * @brief Opens HTTP transaction with authentication information.
 * @since_tizen 3.0
 * @remarks The @a http_auth_transaction should be released using http_transaction_destroy().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] http_auth_transaction The HTTP transaction handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_open_authentication(http_transaction_h http_transaction, http_transaction_h *http_auth_transaction);


/**
 * @brief Sets an HTTP credentials.
 * @details Sets an HTTP authentication scheme such as username and password.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] user_name The HTTP user name
 * @param[in] password The HTTP password
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_credentials(http_transaction_h http_transaction, const char *user_name, const char *password);


/**
 * @brief Gets the username & password for the HTTP credential.
 * @since_tizen 3.0
 * @remarks The @a user_name & @a password should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] user_name The HTTP credential user name
 * @param[out] password The HTTP credential password
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_credentials(http_transaction_h http_transaction, char **user_name, char **password);


/**
 * @brief Sets an HTTP authentication scheme.
 * @details Set an HTTP authentication scheme such as BASIC, MD5, NTLM and etc.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[in] auth_scheme The HTTP authentication scheme
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_set_http_auth_scheme(http_transaction_h http_transaction, http_auth_scheme_e auth_scheme);


/**
 * @brief Gets the HTTP authentication scheme.
 * @since_tizen 3.0
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] auth_scheme The HTTP auth scheme value
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_http_auth_scheme(http_transaction_h http_transaction, http_auth_scheme_e *auth_scheme);


/**
 * @brief Gets the HTTP authentication realm.
 * @since_tizen 3.0
 * @remarks The @a realm should be freed using free().
 * @param[in] http_transaction The HTTP transaction handle
 * @param[out] realm The HTTP authentication realm value
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #HTTP_ERROR_NONE Successful
 * @retval #HTTP_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #HTTP_ERROR_INVALID_OPERATION Invalid operation
 * @retval #HTTP_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #HTTP_ERROR_NOT_SUPPORTED Not Supported
 */
int http_transaction_get_realm(http_transaction_h http_transaction, char **realm);


/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __TIZEN_NETWORK_HTTP_H__ */
