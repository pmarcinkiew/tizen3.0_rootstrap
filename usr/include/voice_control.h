/**
 * Copyright (c) 2011-2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef __VOICE_CONTROL_H__
#define __VOICE_CONTROL_H__

#include <voice_control_command.h>
#include <voice_control_common.h>

/**
 * @addtogroup CAPI_UIX_VOICE_CONTROL_MODULE
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @file voice_control.h
 * @brief This file contains the voice control client API and related callback definitions and enums.
 */

/**
 * @file voice_control_command.h
 * @brief This file contains the command list and command API and related handle definitions and enums.
 */

/**
 * @file voice_control_common.h
 * @brief This file contains the callback function definitions and enums.
 */

/**
 * @brief Definitions for foreground command type.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 */
#define VC_COMMAND_TYPE_FOREGROUND	1

/**
 * @brief Definitions for background command type.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 */
#define VC_COMMAND_TYPE_BACKGROUND	2

/**
 * @brief Definitions for ended dialog.
 * @since_tizen 3.0
 */
#define VC_DIALOG_END		0

/**
 * @brief Definitions for continued dialog.
 * @since_tizen 3.0
 */
#define VC_DIALOG_CONTINUE	1


/**
 * @brief Initializes voice control.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remarks If the function succeeds, @a vc must be released with vc_deinitialize().
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #VC_ERROR_OPERATION_FAILED Operation failure
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @post If this function is called, the state will be #VC_STATE_INITIALIZED.
 *
 * @see vc_deinitialize()
 */
int vc_initialize(void);

/**
 * @brief Deinitializes voice control.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_OPERATION_FAILED Operation failure
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @see vc_deinitialize()
 */
int vc_deinitialize(void);

/**
 * @brief Connects the voice control service.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_OPERATION_FAILED Operation failure
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 * @post If this function is called, the state will be #VC_STATE_READY.
 *
 * @see vc_unprepare()
 */
int vc_prepare(void);

/**
 * @brief Disconnects the voice control service.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 * @post If this function is called, the state will be #VC_STATE_INITIALIZED.
 *
 * @see vc_prepare()
 */
int vc_unprepare(void);

/**
 * @brief Retrieves all supported languages using callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to invoke
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_OPERATION_FAILED Operation failure
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED or #VC_STATE_READY.
 * @post	This function invokes vc_supported_language_cb() repeatedly for getting languages.
 *
 * @see vc_supported_language_cb()
 * @see vc_get_current_language()
 */
int vc_foreach_supported_languages(vc_supported_language_cb callback, void* user_data);

/**
 * @brief Gets current language.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remark If the function succeeds, @a language must be released with free() by you when you no longer need it.
 *
 * @param[out] language A language is specified as an ISO 3166 alpha-2 two letter country-code \n
 *			followed by ISO 639-1 for the two-letter language code. \n
 *			For example, "ko_KR" for Korean, "en_US" for American English.
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #VC_ERROR_OPERATION_FAILED Operation failure
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED or #VC_STATE_READY.
 *
 * @see vc_foreach_supported_languages()
 */
int vc_get_current_language(char** language);

/**
 * @brief Gets current state of voice control client.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[out] state The current state
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @see vc_state_changed_cb()
 * @see vc_set_state_changed_cb()
 */
int vc_get_state(vc_state_e* state);

/**
 * @brief Gets current state of voice control service.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[out] state The current state
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 *
 * @see vc_request_start()
 * @see vc_request_stop()
 * @see vc_request_cancel()
 * @see vc_set_service_state_changed_cb()
 * @see vc_unset_service_state_changed_cb()
 */
int vc_get_service_state(vc_service_state_e* state);

/**
 * @brief Gets the system command list.
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remarks In the system command list, there are system commands predefined by product manufacturers. Those commands have the highest priority.
 *	Therefore, the user can not set any commands same with the system commands. \n
 *	The @a vc_sys_cmd_list must be released using free() when it is no longer required.
 *
 * @param[out] vc_sys_cmd_list System command list handle
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The service state should be #VC_SERVICE_STATE_READY.
 *
 * @see vc_unset_command_list()
 */
int vc_get_system_command_list(vc_cmd_list_h* vc_sys_cmd_list);

/**
 * @brief Sets the invocation name.
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remarks Invocation name is used to activate background commands. The invocation name can be the same as the application name or any other phrase.
 *	For example, an application "Tizen Sample" has a background command, "Play music", and the invocation name of the application is set to "Tizen Sample".
 *	In order to activate the background command, users can say "Tizen Sample, Play music".
 *	The invocation name is dependent on the current language. For example, if the current language is "en_US"(English), the invocation name is also "en_US".
 *	If the current language is "ja_JP"(Japanese) and the invocation name is "en_US", the invocation name will not be recognized.
 *	This function should be called before vc_set_command_list().
 *
 * @param[in] name Invocation name that an application wants to be invoked by
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 *
 * @see vc_set_command_list()
 */
int vc_set_invocation_name(const char* name);

/**
 * @brief Requests to start the dialogue.
 * @details Using this function, the developer can request starting the dialogue to the framework.
 *	When the developer requests the dialogue, two types of texts, @a disp_text and @a utt_text, can be sent by this function.
 *	@a disp_text is a text for displaying, and @a utt_text is that for uttering.
 *	For example, if @a disp_text is "October 10th" and @a utt_text is "Today is October 10th.", "October 10th" will be displayed on the screen and "Today is October 10th." will be spoken.
 *	Also, the developer can set whether the dialogue starts automatically or not, using @a auto_start.
 *	If the developer sets @a auto_start as @c true, the framework will start to record next speech and continue the dialogue.
 *
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remarks If @a auto_start is @c true, the recognition will start again. In this case, it can be restarted up to 4 times.
 *
 * @param[in] disp_text Text to be displayed on the screen
 * @param[in] utt_text Text to be spoken
 * @param[in] auto_start A variable for setting whether the dialog session will be restarted automatically or not
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The service state should be #VC_SERVICE_STATE_READY.
 */
int vc_request_dialog(const char* disp_text, const char* utt_text, bool auto_start);

/**
 * @brief Sets command list.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @remarks The command type is valid for #VC_COMMAND_TYPE_FOREGROUND or #VC_COMMAND_TYPE_BACKGROUND. \n
 *	The matched commands of command list should be set and they should include type and command text at least.
 *
 * @param[in] vc_cmd_list Command list handle
 * @param[in] type Command type
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 *
 * @see vc_unset_command_list()
 */
int vc_set_command_list(vc_cmd_list_h vc_cmd_list, int type);

/**
 * @brief Unsets command list.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] type Command type
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 *
 * @see vc_set_command_list()
 */
int vc_unset_command_list(int type);

/**
 * @brief Gets the recognition result.
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to get recognition result
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_READY.
 *
 * @see vc_result_cb()
 */
int vc_get_result(vc_result_cb callback, void* user_data);

/**
 * @brief Registers a callback function for getting recognition result.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to register
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_result_cb()
 * @see vc_unset_result_cb()
 */
int vc_set_result_cb(vc_result_cb callback, void* user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_set_result_cb()
 */
int vc_unset_result_cb(void);

/**
 * @brief Registers a callback function to be called when state is changed.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to register
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_service_state_changed_cb()
 * @see vc_unset_service_state_changed_cb()
 */
int vc_set_service_state_changed_cb(vc_service_state_changed_cb callback, void* user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_set_service_state_changed_cb()
 */
int vc_unset_service_state_changed_cb(void);

/**
 * @brief Registers a callback function to be called when state is changed.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to register
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_state_changed_cb()
 * @see vc_unset_state_changed_cb()
 */
int vc_set_state_changed_cb(vc_state_changed_cb callback, void* user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_set_state_changed_cb()
 */
int vc_unset_state_changed_cb(void);

/**
 * @brief Registers a callback function to be called when current language is changed.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to register
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_current_language_changed_cb()
 * @see vc_unset_current_language_changed_cb()
 */
int vc_set_current_language_changed_cb(vc_current_language_changed_cb callback, void* user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_set_current_language_changed_cb()
 */
int vc_unset_current_language_changed_cb(void);

/**
 * @brief Registers a callback function to be called when an error occurred.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @param[in] callback Callback function to register
 * @param[in] user_data The user data to be passed to the callback function
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_error_cb()
 * @see vc_unset_error_cb()
 */
int vc_set_error_cb(vc_error_cb callback, void* user_data);

/**
 * @brief Unregisters the callback function.
 * @since_tizen @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/recorder
 *
 * @return 0 on success, otherwise a negative error value
 * @retval #VC_ERROR_NONE Successful
 * @retval #VC_ERROR_INVALID_STATE Invalid state
 * @retval #VC_ERROR_PERMISSION_DENIED Permission denied
 * @retval #VC_ERROR_NOT_SUPPORTED Not supported
 *
 * @pre The state should be #VC_STATE_INITIALIZED.
 *
 * @see vc_set_error_cb()
 */
int vc_unset_error_cb(void);


#ifdef __cplusplus
}
#endif

/**
 * @}@}
 */

#endif /* __VOICE_CONTROL_H__ */
