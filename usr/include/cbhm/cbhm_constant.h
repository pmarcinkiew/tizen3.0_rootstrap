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
#ifndef __CLIPBOARD_HISTORY_MANAGER_CONSTANT_H__
#define __CLIPBOARD_HISTORY_MANAGER_CONSTANT_H__


/**
 * @addtogroup CAPI_CBHM_MODULE
 * @{
 */

 
/**
 * @brief Enumeration for Clipboard Data Type.
 * @since_tizen 3.0
 */

typedef enum {
	CBHM_SEL_TYPE_NONE		=  0x0, /** Content is from outside of Elementary */
	CBHM_SEL_TYPE_TEXT		= 0x01, /** Plain unformatted text: Used for things that don't want rich markup */
	CBHM_SEL_TYPE_MARKUP	= 0x02, /** Edje textblock markup, including inline images */
	CBHM_SEL_TYPE_IMAGE		= 0x04, /** Images */
	CBHM_SEL_TYPE_HTML		= 0x08, /** Raw HTML-like data (eg. webkit) */
} cbhm_sel_type_e;


/**
 * @}
 */

#endif /* __CLIPBOARD_HISTORY_MANAGER_CONSTANT_H__ */
