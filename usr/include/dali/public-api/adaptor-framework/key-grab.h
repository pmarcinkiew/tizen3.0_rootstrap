#ifndef __DALI_KEY_GRAB_H__
#define __DALI_KEY_GRAB_H__

/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
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

// INTERNAL INCLUDES
#include <dali/public-api/common/dali-common.h>
#include <dali/public-api/common/dali-vector.h>
#include "key.h"

namespace Dali
{
/**
 * @addtogroup dali_adaptor_framework
 * @{
 */

class Window;

/**
 * @brief Key grab functions.
 * @SINCE_1_0.0
 */
namespace KeyGrab
{

/**
 * @brief Grabs the key specfied by @a key for @a window only when @a window is the topmost window.
 *
 * This function can be used for following example scenarios:
 * - Mobile - Using volume up/down as zoom up/down in camera apps.
 *
 * @SINCE_1_0.0
 * @param[in] window The window to set
 * @param[in] daliKey The key code to grab (defined in key.h)
 * @return true if the grab succeeds.
 */
DALI_IMPORT_API bool GrabKeyTopmost( Window window, Dali::KEY daliKey );

/**
 * @brief Ungrabs the key specfied by @a key for @a window.
 *
 * @SINCE_1_0.0
 * @param[in] window The window to set
 * @param[in] daliKey The key code to ungrab (defined in key.h)
 * @return true if the ungrab succeeds.
 * @note If this function is called between key down and up events of a grabbed key,
 * an application doesn't receive the key up event.
 */
DALI_IMPORT_API bool UngrabKeyTopmost( Window window, Dali::KEY daliKey );

/**
 * @brief Key grab mode for platform-level APIs.
 * @SINCE_1_0.0
 */
enum KeyGrabMode
{
  TOPMOST = 0,             ///< Grab a key only when on the top of the grabbing-window stack mode. @SINCE_1_0.0
  SHARED,                  ///< Grab a key together with the other client window(s) mode. @SINCE_1_0.0
  OVERRIDE_EXCLUSIVE,      ///< Grab a key exclusively regardless of the grabbing-window's position on the window stack with the possibility of overriding the grab by the other client window mode. @SINCE_1_0.0
  EXCLUSIVE                ///< Grab a key exclusively regardless of the grabbing-window's position on the window stack mode. @SINCE_1_0.0
};

/**
 * @PLATFORM
 * @brief Grabs the key specfied by @a key for @a window in @a grabMode.
 *
 * @details This function can be used for following example scenarios:
 * - TV - A user might want to change the volume or channel of the background TV contents while focusing on the foregrund app.
 * - Mobile - When a user presses Home key, the homescreen appears regardless of current foreground app.
 * - Mobile - Using volume up/down as zoom up/down in camera apps.
 *
 * @SINCE_1_0.0
 * @PRIVLEVEL_PLATFORM
 * @PRIVILEGE_KEYGRAB
 * @param[in] window The window to set
 * @param[in] daliKey The key code to grab (defined in key.h)
 * @param[in] grabMode The grab mode for the key
 * @return true if the grab succeeds.
 */
DALI_IMPORT_API bool GrabKey( Window window, Dali::KEY daliKey, KeyGrabMode grabMode );

/**
 * @PLATFORM
 * @brief Ungrabs the key specfied by @a key for @a window.
 *
 * @SINCE_1_0.0
 * @PRIVLEVEL_PLATFORM
 * @PRIVILEGE_KEYGRAB
 * @param[in] window The window to set
 * @param[in] daliKey The key code to ungrab (defined in key.h)
 * @return true if the ungrab succeeds.
 * @note If this function is called between key down and up events of a grabbed key,
 * an application doesn't receive the key up event.
 */
DALI_IMPORT_API bool UngrabKey( Window window, Dali::KEY daliKey );


/**
 * @PLATFORM
 * @brief Grabs the list of keys specfied by Dali::Vector of keys for @a window in Vector of grabModes.
 *
 * @details This function can be used for following example scenarios:
 * - TV - A user might want to change the volume or channel of the background TV contents while focusing on the foregrund app.
 * - Mobile - When a user presses Home key, the homescreen appears regardless of current foreground app.
 * - Mobile - Using volume up/down as zoom up/down in camera apps.
 *
 * @SINCE_1_2.0
 * @PRIVLEVEL_PLATFORM
 * @PRIVILEGE_KEYGRAB
 * @param[in] window The window to set
 * @param[in] daliKeyVector The Dali::Vector of key codes to grab (defined in key.h)
 * @param[in] grabModeVector The Dali::Vector of grab modes for the keys
 * @return Dali::Vector Size is zero when error occurs, true/false if the grab succeeds/fails.
 */
DALI_IMPORT_API Dali::Vector<bool> GrabKeyList( Window window, const Dali::Vector<Dali::KEY>& daliKeyVector, const Dali::Vector<KeyGrabMode>& grabModeVector);


/**
 * @PLATFORM
 * @brief Ungrabs the list of keys specfied by Dali::Vector of keys for @a window.
 *
 * @SINCE_1_2.0
 * @PRIVLEVEL_PLATFORM
 * @PRIVILEGE_KEYGRAB
 * @param[in] window The window to set
 * @param[in] daliKeyVector The Dali::Vector of key codes to ungrab (defined in key.h)
 * @return Dali::Vector Size is zero when error occurs, true/false if the ungrab succeeds/fails.
 * @note If this function is called between key down and up events of a grabbed key,
 * an application doesn't receive the key up event.
 */
DALI_IMPORT_API Dali::Vector<bool> UngrabKeyList( Window window, const Dali::Vector<Dali::KEY>& daliKeyVector );


} // namespace KeyGrab

/**
 * @}
 */
} // namespace Dali

#endif // __DALI_KEY_GRAB_H__
