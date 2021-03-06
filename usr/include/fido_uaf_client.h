/*
 * Copyright (c) 2014 - 2015 Samsung Electronics Co., Ltd. All rights reserved.
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
 *
 */

#ifndef __TIZEN_FIDO_UAF_CLIENT_H__
#define __TIZEN_FIDO_UAF_CLIENT_H__

#include <fido_uaf_types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @file fido_uaf_client.h
 * @brief The FIDO UAF Client APIs.
 */

/**
 * @addtogroup CAPI_FIDO_MODULE
 * @{
 */

/**
 * @brief Gets the FIDO client vendor name.
 * @since_tizen 3.0
 *
 * @remarks		The @a vendor_name should be released using free().
 * @param[out] vendor_name The vendor name
 *
 * @return     @c 0 on success,
 *             otherwise a negative error value
 * @retval     #FIDO_ERROR_NONE               Successful
 * @retval     #FIDO_ERROR_OUT_OF_MEMORY      Out of Memory
 * @retval     #FIDO_ERROR_INVALID_PARAMETER  Invalid parameter
 */
int fido_get_client_vendor(char **vendor_name);

/**
 * @brief Gets the FIDO client vendor version information.
 * @since_tizen 3.0
 *
 * @param[out] client_major_version The FIDO client major version
 * @param[out] client_minor_version The FIDO client minor version
 *
 * @return     @c 0 on success,
 *             otherwise a negative error value
 * @retval     #FIDO_ERROR_NONE               Successful
 * @retval     #FIDO_ERROR_OUT_OF_MEMORY      Out of Memory
 * @retval     #FIDO_ERROR_INVALID_PARAMETER  Invalid parameter
 */
int fido_get_client_version(int *client_major_version, int *client_minor_version);

/**
 * @}
 */

/**
 * @addtogroup CAPI_FIDO_UAF_MESSAGES_MODULE
 * @{
 */

/**
 * @brief Checks whether the FIDO message can be processed.
 * @since_tizen 3.0
 * @privlevel  public
 * @privilege  %http://tizen.org/privilege/fido.client
 *
 * @param[in] uaf_message_json The FIDO message in JSON format which is received from the relying party server
 * @param[out] is_supported True if the message can be handled by the device, else false
 *
 * @return     @c 0 on success,
 *             otherwise a negative error value
 * @retval     #FIDO_ERROR_NONE                   Successful
 * @retval     #FIDO_ERROR_OUT_OF_MEMORY          Out of Memory
 * @retval     #FIDO_ERROR_INVALID_PARAMETER      Invalid parameter
 * @retval     #FIDO_ERROR_NOT_SUPPORTED          FIDO is not supported
 * @retval     #FIDO_ERROR_PERMISSION_DENIED      The application does not have permission to call this function.
 * @retval     #FIDO_ERROR_UNSUPPORTED_VERSION    The UAF Message does not specify a protocol version supported by this FIDO UAF Client.
 * @retval     #FIDO_ERROR_NO_SUITABLE_AUTHENTICATOR No suitable authenticators found.
 * @retval     #FIDO_ERROR_PROTOCOL_ERROR         The interaction may have timed out, or the UAF message is malformed.
 * @retval     #FIDO_ERROR_UNTRUSTED_FACET_ID     The caller's id is not allowed to use this operation.
 *
 */
int fido_uaf_is_supported(const char *uaf_message_json, bool *is_supported);

/**
 * @brief Called when fido_uaf_get_response_message() response comes.
 * @details The following error codes can be delivered:
 * <pre>
 * #FIDO_ERROR_NONE                        Successful
 * #FIDO_ERROR_OUT_OF_MEMORY               Out of Memory
 * #FIDO_ERROR_USER_ACTION_IN_PROGRESS     User action is in progress.
 * #FIDO_ERROR_USER_CANCELLED              User has cancelled the operation.
 * #FIDO_ERROR_PERMISSION_DENIED           The application does not have permission to call this
 *                                         function.
 * #FIDO_ERROR_UNSUPPORTED_VERSION         The UAF Message does not specify a protocol version
 *                                         supported by this FIDO UAF Client.
 * #FIDO_ERROR_NO_SUITABLE_AUTHENTICATOR   No suitable authenticators found.
 * #FIDO_ERROR_PROTOCOL_ERROR              The interaction may have timed out, or the UAF message
 *                                         is malformed.
 * #FIDO_ERROR_UNTRUSTED_FACET_ID          The caller's id is not allowed to use this operation.
 * </pre>
 * @since_tizen 3.0
 *
 * @param[in] tizen_error_code Tizen platform error code
 * @param[in] uaf_response_json FIDO response message in JSON format
 * @param[in] user_data The user data passed from the callback function
 *
 * @pre fido_uaf_get_response_message() must be called to get this callback invoked.
 * @see fido_uaf_get_response_message()
 */
typedef void (*fido_uaf_response_message_cb) (fido_error_e tizen_error_code, const char *uaf_response_json, void *user_data);

/**
 * @brief Processes the given FIDO UAF message.
 * @details This function is asynchronous. The response is delivered via fido_uaf_response_message_cb().
 * Depending on the FIDO message type, this may involve user interactions.
 *
 * @since_tizen 3.0
 * @privlevel  public
 * @privilege  %http://tizen.org/privilege/fido.client
 *
 * @param[in] uaf_request_json The FIDO UAF message in JSON format which is received from the relying party server
 * @param[in] channel_binding The channel binding data in JSON format which is received from the relying party server
 * @param[in] callback The callback to receive response
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return     @c 0 on success,
 *             otherwise a negative error value
 * @retval     #FIDO_ERROR_NONE                   Successful
 * @retval     #FIDO_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval     #FIDO_ERROR_NOT_SUPPORTED          FIDO is not supported
 *
 * @see fido_uaf_response_message_cb()
 */
int fido_uaf_get_response_message(const char *uaf_request_json, const char *channel_binding,
	fido_uaf_response_message_cb callback, void *user_data);

/**
 * @brief Notifies the FIDO client about the server result. FIDO Server sends the result of processing a UAF message to FIDO client.
 * @remarks This is especially important for cases when a new registration may be considered by the client to be in a pending state
 * until it is communicated that the server accepted it.
 *
 * @since_tizen 3.0
 * @privlevel  public
 * @privilege  %http://tizen.org/privilege/fido.client
 *
 * @param[in] response_code The status code received from Server, #FIDO_SERVER_STATUS_CODE_OK implies success
 * @param[in] uaf_response_json The FIDO response message sent to server in JSON format
 *
 * @return     @c 0 on success,
 *             otherwise a negative error value
 * @retval     #FIDO_ERROR_NONE                   Successful
 * @retval     #FIDO_ERROR_OUT_OF_MEMORY          Out of Memory
 * @retval     #FIDO_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval     #FIDO_ERROR_NOT_SUPPORTED          FIDO is not supported
 * @retval     #FIDO_ERROR_PERMISSION_DENIED      The application does not have permission to call this function.
 * @retval     #FIDO_ERROR_UNSUPPORTED_VERSION    The UAF Message does not specify a protocol version supported by this FIDO UAF Client.
 * @retval     #FIDO_ERROR_NO_SUITABLE_AUTHENTICATOR No suitable authenticators found.
 * @retval     #FIDO_ERROR_PROTOCOL_ERROR         The interaction may have timed out, or the UAF message is malformed.
 * @retval     #FIDO_ERROR_UNTRUSTED_FACET_ID     The caller's id is not allowed to use this operation.
 *
 * @see fido_uaf_response_message_cb()
 */
int fido_uaf_set_server_result(int response_code, const char *uaf_response_json);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* FIDO_UAF_CLIENT_H_ */
