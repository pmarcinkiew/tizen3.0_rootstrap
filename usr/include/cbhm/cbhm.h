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
#ifndef __CLIPBOARD_HISTORY_MANAGER_H__
#define __CLIPBOARD_HISTORY_MANAGER_H__

#include <stddef.h>
#include "cbhm_constant.h"
#include "cbhm_error.h"


/**
 * @addtogroup CAPI_CBHM_MODULE
 * @brief This module provides functionalities about clipboard.
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Clipboard handle.
 * @since_tizen 3.0
 */
typedef struct cbhm* cbhm_h;


/**
 * @brief Creates and initializes clipboard handle.
 * @since_tizen 3.0
 * @param[out] cbhm_handle Clipboard handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @retval #CBHM_ERROR_OUT_OF_MEMORY Out of memory
 * @see cbhm_close_service()
 */
int cbhm_open_service(cbhm_h *cbhm_handle);


/**
 * @brief Closes clipboard handle.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @see cbhm_open_service()
 */
int cbhm_close_service(cbhm_h cbhm_handle);


/**
 * @brief Shows clipboard.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @see cbhm_hide()
 */
int cbhm_show(cbhm_h cbhm_handle);


/**
 * @brief Hides clipboard.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @see cbhm_show()
 */
int cbhm_hide(cbhm_h cbhm_handle);


/**
 * @brief Sets clipboard selection type.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[in] type Selection type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @see cbhm_selection_type_get()
 */
int cbhm_selection_type_set(cbhm_h cbhm_handle, cbhm_sel_type_e type);


/**
 * @brief Gets clipboard selection type.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[out] type Selection type
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @see cbhm_selection_type_set()
 */
int cbhm_selection_type_get(cbhm_h cbhm_handle, cbhm_sel_type_e *type);


/**
 * @brief Event callback signature of selecting a clipboard item.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[in] user_data User data to be passed to the given event callback function
 * @return This is reserved
 * @see cbhm_item_selected_callabck_add()
 */
typedef int (*cbhm_selected_cb)(cbhm_h cbhm_handle, void *user_data);


/**
 * @brief Adds event callback function of selecting a clipboard item.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[in] callback Callback function called when a clipboard item is selected
 * @param[in] user_data User data to be passed to the given event callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @retval #CBHM_ERROR_OUT_OF_MEMORY Out of memory
 */
int cbhm_item_selected_callback_add(cbhm_h cbhm_handle, cbhm_selected_cb callback, void *user_data);


/**
 * @brief Event callback signature of receiving data from clipboard.
 * @since_tizen 3.0
 * @param[in] Clipboard handle
 * @param[out] buf Buffer for receiving data
 * @param[in] len The length of buffer
 * @param[in] user_data User data to be passed to the given event callback function
 * @return This is reserved
 * @see cbhm_item_selected_callabck_add()
 */
typedef int (*cbhm_selection_data_cb)(cbhm_h cbhm_handle, const char *buf, size_t len, void *user_data);


/**
 * @brief Sends data to clipboard.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[in] type Selection type
 * @param[in] data Data to be sent
 * @param[in] len The length of data
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @retval #CBHM_ERROR_OUT_OF_MEMORY Out of memory
 * @see cbhm_selection_get()
 */
int cbhm_selection_set(cbhm_h cbhm_handle, cbhm_sel_type_e type, const void *data, size_t len);


/**
 * @brief Receives data from clipboard.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @param[in] type Selection type
 * @param[in] callback Callback function receiving data from clipboard
 * @param[in] user_data User data to be passed to the given event callback function
 * @return @c 0 on success,
 *         otherwise a negative error value
 * @retval #CBHM_ERROR_NONE Successful
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 * @retval #CBHM_ERROR_NO_DATA No data available
 * @see cbhm_selection_set()
 */
int cbhm_selection_get(cbhm_h cbhm_handle, cbhm_sel_type_e type, cbhm_selection_data_cb callback, void *user_data);


/**
 * @brief Gets the count of clipboard items.
 * @since_tizen 3.0
 * @param[in] cbhm_handle Clipboard handle
 * @return The count of clipboard items
 * @retval #CBHM_ERROR_INVALID_PARAMETER Invalid function parameters
 */
int cbhm_item_count_get(cbhm_h cbhm_handle);

#ifdef __cplusplus
}
#endif


/**
 * @}
 */

#endif /* __CLIPBOARD_HISTORY_MANAGER_H__ */
