/*
 * Copyright (c) 2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Flora License, Version 1.1 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://floralicense.org/license/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __EFL_EXTENSION_H__
#define __EFL_EXTENSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "efl_extension_events.h"
#include "eext_floatingbutton.h"


/**
 * @defgroup EFL_EXTENSION_HARDWARE_KEYEVENT_GROUP Efl Extension Hardware Keyevent
 * @ingroup CAPI_EFL_EXTENSION_MODULE
 * @brief This group provides functionalities to grab hardware key events.
 * @since_tizen 2.4
 *
 * @{
 */

/**
 * @brief Set the keygrab of the Elm_Win object
 *
 * @details This API returns the sucessness of keygrab_set.
 *          Key callback is only called when the window located in topmost(top of the window stack).
 *
 * @param[in] obj object to set the keygrab
 *            The widget type of this object should be elm_win
 * @param[in] key keyname string to set keygrab
 *
 * @return    The result of keygrab set
 *
 * @since_tizen 2.4
 */
EAPI Eina_Bool eext_win_keygrab_set(Elm_Win *obj, const char *key);

/**
 * @brief Unset the keygrab of the Elm_Win object
 *
 * @details This API returns the sucessness of keygrab_unset.
 *
 * @param[in] obj object to unset the keygrab
 *            The widget type of this object should be elm_win
 * @param[in] key keyname string to unset keygrab
 *
 * @return    The result of keygrab unset
 *
 * @since_tizen 2.4
 */
EAPI Eina_Bool eext_win_keygrab_unset(Elm_Win *obj, const char *key);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __EFL_EXTENSION_H__ */

