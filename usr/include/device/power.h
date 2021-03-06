/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
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


#ifndef __TIZEN_SYSTEM_POWER_H__
#define __TIZEN_SYSTEM_POWER_H__

#include <stdbool.h>
#include "device-error.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup CAPI_SYSTEM_DEVICE_POWER_MODULE
 * @{
 */

/**
 * @brief Enumeration for lock type.
 * @details Each enum ensures that the suitable device is on
 *          until all the lock requests have been released or after a timeout. \n
 *
 * <TABLE>
 * <TR><TH>Enum Type</TH><TH>CPU</TH><TH>Brightness(Display)</TH></TR> 
 * <TR><TD>POWER_LOCK_CPU</TD><TD>ON</TD><TD>OFF</TD></TR>
 * <TR><TD>POWER_LOCK_DISPLAY</TD><TD>ON</TD><TD>ON(Normal)</TD></TR>
 * <TR><TD>POWER_LOCK_DISPLAY_DIM</TD><TD>ON</TD><TD>ON(Dim)</TD></TR>
 * </TABLE>
 *          The POWER_LOCK_DISPLAY and POWER_LOCK_DISPLAY_DIM types were deprecated in Tizen @if Mobile 2.4 @elseif WEARABLE 3.0 @endif.\n
 *          Please use below api set instead of these types.\n
 *          int efl_util_set_window_screen_mode(Evas_Object *window, efl_util_screen_mode_e mode);\n
 *          int efl_util_get_window_screen_mode(Evas_Object *window, efl_util_screen_mode_e *mode);
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @remarks An application can lock the specific type.
 * @remarks These enums are mutually exclusive.
 * @remarks You cannot combine with an enum below.
 *
 */
typedef enum {
    POWER_LOCK_CPU,         /**< CPU lock */
    POWER_LOCK_DISPLAY,     /**< Display normal lock (Deprecated since @if Mobile 2.4 @elseif WEARABLE 3.0 @endif. Use efl_util_set_window_screen_mode() instead) */
    POWER_LOCK_DISPLAY_DIM, /**< Display dim lock (Deprecated since @if Mobile 2.4 @elseif WEARABLE 3.0 @endif. Use efl_util_set_window_screen_mode() instead) */
} power_lock_e;

/**
 * @brief Locks the given lock state for a specified time.
 * @details After the given @a timeout_ms (in milliseconds), unlock the given lock state automatically.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/display
 *
 * @remarks If the process dies, then every lock will be removed.
 *
 * @param[in] type          The power type to request lock
 * @param[in] timeout_ms    The positive number in milliseconds or @c 0 for permanent lock \n
 *                          So you must release the permanent lock of power state with #device_power_release_lock() if @a timeout_ms is zero.
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 *
 * @retval #DEVICE_ERROR_NONE               Successful
 * @retval #DEVICE_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #DEVICE_ERROR_PERMISSION_DENIED  Permission denied
 * @retval #DEVICE_ERROR_OPERATION_FAILED   Operation failed
 *
 * @see device_power_release_lock()
 */
int device_power_request_lock(power_lock_e type, int timeout_ms);

/**
 * @brief Releases the given lock state locked before.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/display
 *
 * @param[in] type The power type to release lock
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 *
 * @retval #DEVICE_ERROR_NONE               Successful
 * @retval #DEVICE_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #DEVICE_ERROR_PERMISSION_DENIED  Permission denied
 * @retval #DEVICE_ERROR_OPERATION_FAILED   Operation failed
 *
 * @see device_power_request_lock()
 */
int device_power_release_lock(power_lock_e type);

/**
 * @deprecated Deprecated Since @if WEARABLE 3.0 @else 2.4 @endif
 * @brief Changes the current power state to the normal/dim state.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @privlevel public
 * @privilege %http://tizen.org/privilege/display
 *
 * @remarks This API triggers turn on process and then updates the status when it completes. While the operation is on-going, the device_display_get_state() function returns previous display state
 *
 * @param[in] dim Set @c true to set the dim state,
 *                otherwise set @c false to not set the dim state
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 *
 * @retval #DEVICE_ERROR_NONE               Successful
 * @retval #DEVICE_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #DEVICE_ERROR_PERMISSION_DENIED  Permission denied
 * @retval #DEVICE_ERROR_OPERATION_FAILED   Operation failed
 *
 * @post The device will be in #DISPLAY_STATE_NORMAL state.
 */
int device_power_wakeup(bool dim) TIZEN_DEPRECATED_API;

/**
 * @platform
 * @brief Reboots the device.
 * @details Will not return if the reboot is successful. \n
 *          It operates asynchronously.
 *
 * @since_tizen 2.3.1
 * @privlevel platform
 * @privilege %http://tizen.org/privilege/reboot
 *
 * @param[in] reason Pass to the platform and kernel to request special reboot reason, or null.
 *
 * @return @c 0 on success,
 *         otherwise a negative error value
 *
 * @retval #DEVICE_ERROR_NONE               Successful
 * @retval #DEVICE_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #DEVICE_ERROR_PERMISSION_DENIED  Permission denied
 * @retval #DEVICE_ERROR_OPERATION_FAILED   Operation failed
 */
int device_power_reboot(const char *reason);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  // __TIZEN_SYSTEM_POWER_H__
