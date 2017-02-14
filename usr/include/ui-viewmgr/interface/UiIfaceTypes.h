/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
#ifndef _UI_IFACE_TYPES_H_
#define _UI_IFACE_TYPES_H_

/**
 * @addtogroup CAPI_UI_VIEWMGR_MODULE
 * @{
 */

/**
 * @brief Enumerations of error code for UI VIEWMGR
 */
typedef enum
{
	UI_VIEWMGR_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
	UI_VIEWMGR_ERROR_NOT_PERMITTED = TIZEN_ERROR_NOT_PERMITTED, /**< Operation not permitted */
	UI_VIEWMGR_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Out of memory */
	UI_VIEWMGR_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
	UI_VIEWMGR_ERROR_RESULT_OUT_OF_RANGE = TIZEN_ERROR_RESULT_OUT_OF_RANGE, /**< Result not representable */
	UI_VIEWMGR_ERROR_ALREADY_IN_PROGRESS = TIZEN_ERROR_ALREADY_IN_PROGRESS, /**< Operation already in progress */
	UI_VIEWMGR_ERROR_UNKNOWN = TIZEN_ERROR_UNKNOWN /** Framework internal operation failed */
} ui_viewmgr_error_e;


/**
 * @brief Possible values for indicator state.
 * @since_tizen 3.0
 */
typedef enum UiViewIndicator
{
	UI_VIEW_INDICATOR_UNKNOWN = 0, /**< Unknown state (Exceptional case) */
	UI_VIEW_INDICATOR_DEFAULT,     /**< Opaque indicator */
	UI_VIEW_INDICATOR_OPTIMAL,     /**< Transparent indicator */
	UI_VIEW_INDICATOR_OVERLAP,     /**< Overlap indicator */
	UI_VIEW_INDICATOR_HIDE,        /**< Indicator hide */
	UI_VIEW_INDICATOR_SHOW         /**< Indicator show */
} ui_view_indicator;

/**
 * @brief Possible values for view state.
 * @since_tizen 3.0
 */
typedef enum UiViewState
{
	UI_VIEW_STATE_UNKNOWN = 0,     /**< Unknown state (Exceptional case) */
	UI_VIEW_STATE_LOAD,            /**< Load state */
	UI_VIEW_STATE_UNLOAD,          /**< Unload state */
	UI_VIEW_STATE_ACTIVATE,        /**< Activate state */
	UI_VIEW_STATE_DEACTIVATE,      /**< Deactivate state */
	UI_VIEW_STATE_PAUSE,           /**< Pause state */
	UI_VIEW_STATE_DESTROY          /**< Destroy state */
} ui_view_state;

/**
 * @brief Possible values for view orientation mode.
 * @since_tizen 3.0
 */
typedef enum UiViewOrientationMode
{
	UI_VIEW_ORIENTATION_MODE_UNKNOWN = 0, /**< Unknown state (Exceptional case) */
	UI_VIEW_ORIENTATION_MODE_PORTRAIT,    /**< Portrait state */
	UI_VIEW_ORIENTATION_MODE_LANDSCAPE   /**< Landscape state */
} ui_view_orientation_mode;

/**
 * @}
 */


#endif /* _UI_IFACE_TYPES_H_ */
