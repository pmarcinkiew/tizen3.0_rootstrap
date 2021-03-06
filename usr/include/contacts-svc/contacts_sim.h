/*
 * Contacts Service
 *
 * Copyright (c) 2010 - 2015 Samsung Electronics Co., Ltd. All rights reserved.
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
#ifndef __TIZEN_SOCIAL_CONTACTS_SIM_H__
#define __TIZEN_SOCIAL_CONTACTS_SIM_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @file contacts_sim.h
 */

/**
 * @ingroup CAPI_SOCIAL_CONTACTS_SVC_MODULE
 * @defgroup CAPI_SOCIAL_CONTACTS_SVC_SIM_MODULE SIM
 *
 * @brief The contacts SIM API provides the set of definitions and interfaces that enable application developers to get/set data from/to SIM card.
 *
 * @section CAPI_SOCIAL_CONTACTS_SVC_SIM_MODULE_HEADER Required Header
 *  \#include <contacts.h>
 *
 * @section CAPI_SOCIAL_CONTACTS_SVC_SIM_MODULE_FEATURE Related Features
 * This API is related with the following features:\n
 *  - http://tizen.org/feature/network.telephony\n
 *
 * It is recommended to design feature related codes in your application for reliability.\n
 *
 * You can check if a device supports the related features for this API by using @ref CAPI_SYSTEM_SYSTEM_INFO_MODULE, thereby controlling the procedure of your application.\n
 *
 * To ensure your application is only running on the device with specific features, please define the features in your manifest file using the manifest editor in the SDK.\n
 *
 * More details on featuring your application can be found from <a href="https://developer.tizen.org/development/tools/native-tools/manifest-text-editor#feature"><b>Feature Element</b>.</a>
 * <BR>
 * @{
 */

/**
 * @deprecated Deprecated since 3.0. Use contacts_sim_import_all_contacts_by_sim_slot_no() instead.
 * @brief Imports all contacts from first SIM to the Contacts Database.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/contact.write
 *
 * @return  @c 0 on success,
 *          otherwise a negative error value
 *
 * @retval  #CONTACTS_ERROR_NONE                Successful
 * @retval  #CONTACTS_ERROR_INVALID_PARAMETER   Invalid parameter
 * @retval  #CONTACTS_ERROR_NO_DATA             Requested data does not exist
 * @retval  #CONTACTS_ERROR_PERMISSION_DENIED   Permission denied. This application does not have the privilege to call this method.
 * @retval  #CONTACTS_ERROR_NOT_SUPPORTED       Not supported
 * @retval  #CONTACTS_ERROR_IPC                 Unknown IPC error
 * @retval  #CONTACTS_ERROR_SYSTEM              Internal system module error
 * @retval  #CONTACTS_ERROR_INTERNAL            Implementation Error, Temporary Use
 *
 * @pre  contacts_connect() should be called to open a connection to the contacts service.
 *
 * @see  contacts_connect()
 */
int contacts_sim_import_all_contacts(void) TIZEN_DEPRECATED_API;


/**
 * @deprecated Deprecated since 3.0. Use contacts_sim_get_initialization_status_by_sim_slot_no() instead.
 * @brief Checks whether first SIM initialization is completed.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 3.0 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/contact.read
 *
 * @param[out]  completed    @c true if SIM is initialized,
 *                           otherwise @c false if SIM is not initialized
 *
 * @return  @c 0 on success,
 *          otherwise a negative error value
 *
 * @retval  #CONTACTS_ERROR_NONE                Successful
 * @retval  #CONTACTS_ERROR_INVALID_PARAMETER   Invalid parameter
 * @retval  #CONTACTS_ERROR_PERMISSION_DENIED   Permission denied. This application does not have the privilege to call this method.
 * @retval  #CONTACTS_ERROR_NOT_SUPPORTED       Not supported
 * @retval  #CONTACTS_ERROR_IPC                 Unknown IPC error
 * @retval  #CONTACTS_ERROR_SYSTEM              Internal system module error
 *
 * @pre  contacts_connect() should be called to open a connection to the contacts service.
 *
 * @see  contacts_connect()
 */
int contacts_sim_get_initialization_status(bool *completed) TIZEN_DEPRECATED_API;

/**
 * @brief Called whenever a contact is imported.
 *
 * @since_tizen 3.0
 *
 * @param[in]   total             The number of contacts that will be imported
 * @param[in]   imported_cnt      The number of already imported contacts
 * @param[in]   user_data         The user data passed from the callback registration function
 *
 * @return  @c true to continue with the import of contacts
 *          otherwise @c false to stop the import of contacts
 *
 * @pre contacts_sim_import_all_contacts_by_sim_slot_no() will invoke this callback.
 *
 * @see contacts_sim_import_all_contacts_by_sim_slot_no()
 */
typedef bool (*contacts_sim_import_progress_cb)(int total, int imported_cnt, void *user_data);

/**
 * @brief Imports all contacts from SIM of the given SIM slot number to the Contacts Database.
 *
 * @details This function invokes contacts_sim_import_progress_cb() to indicate the progress of imports whenever a contact is imported.
 *
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/contact.write
 *
 * @param[in]   sim_slot_no         The SIM slot number; 0 means first SIM, 1 means second SIM
 * @param[in]   callback            The callback function to invoke
 * @param[in]   user_data           The user data to be passed to the callback function
 *
 * @return  @c 0 on success,
 *          otherwise a negative error value
 *
 * @retval  #CONTACTS_ERROR_NONE                Successful
 * @retval  #CONTACTS_ERROR_INVALID_PARAMETER   Invalid parameter
 * @retval  #CONTACTS_ERROR_NO_DATA             Requested data does not exist
 * @retval  #CONTACTS_ERROR_PERMISSION_DENIED   Permission denied. This application does not have the privilege to call this method.
 * @retval  #CONTACTS_ERROR_NOT_SUPPORTED       Not supported
 * @retval  #CONTACTS_ERROR_IPC                 Unknown IPC error
 * @retval  #CONTACTS_ERROR_SYSTEM              Internal system module error
 *
 * @pre  contacts_connect() should be called to open a connection to the contacts service.
 *
 * @see  contacts_connect()
 * @see  contacts_sim_import_progress_cb()
 */

int contacts_sim_import_all_contacts_by_sim_slot_no(int sim_slot_no, contacts_sim_import_progress_cb callback, void *user_data);

/**
 * @brief Checks whether SIM of the given SIM slot number is initialized.
 *
 * @since_tizen 3.0
 * @privlevel public
 * @privilege %http://tizen.org/privilege/contact.read
 *
 * @param[in]   sim_slot_no       The SIM slot number; 0 means first SIM, 1 means second SIM
 * @param[out]  completed    @c true if SIM is initialized,
 *                           otherwise @c false if SIM is not initialized
 *
 * @return  @c 0 on success,
 *          otherwise a negative error value
 *
 * @retval  #CONTACTS_ERROR_NONE                Successful
 * @retval  #CONTACTS_ERROR_INVALID_PARAMETER   Invalid parameter
 * @retval  #CONTACTS_ERROR_PERMISSION_DENIED   Permission denied. This application does not have the privilege to call this method.
 * @retval  #CONTACTS_ERROR_NOT_SUPPORTED       Not supported
 * @retval  #CONTACTS_ERROR_IPC                 Unknown IPC error
 * @retval  #CONTACTS_ERROR_SYSTEM              Internal system module error
 *
 * @pre  contacts_connect() should be called to open a connection to the contacts service.
 *
 * @see  contacts_connect()
 */
int contacts_sim_get_initialization_status_by_sim_slot_no(int sim_slot_no, bool *completed);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_SOCIAL_CONTACTS_SIM_H__ */

