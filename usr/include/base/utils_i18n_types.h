/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *	  Licensed under the Apache License, Version 2.0 (the "License");
 *	  you may not use this file except in compliance with the License.
 *	  You may obtain a copy of the License at
 *
 *		  http://www.apache.org/licenses/LICENSE-2.0
 *
 *	  Unless required by applicable law or agreed to in writing, software
 *	  distributed under the License is distributed on an "AS IS" BASIS,
 *	  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	  See the License for the specific language governing permissions and
 *	  limitations under the License.
 *
 * Copyright (C) 1999-2012, International Business Machines
 * Corporation and others.	All Rights Reserved.
 */



#ifndef __UTILS_I18N_TYPES_H__
#define __UTILS_I18N_TYPES_H__

#include <inttypes.h>
#include <tizen.h>
#include <wchar.h>

/**
 * @file utils_i18n_types.h
 * @version 0.1
 * @brief utils_i18n_types
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MODULE
 * @{
 */

/**
 * @brief Enumeration for error codes to replace exception handlings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_ERROR_NONE							= TIZEN_ERROR_NONE,					  /**< No error, no warning */
					  I18N_ERROR_MISSING_RESOURCE				= TIZEN_ERROR_UTILITY_ICU | 0x01,	  /**< The requested resource cannot be found */
							   I18N_ERROR_INVALID_FORMAT				= TIZEN_ERROR_UTILITY_ICU | 0x02,	  /**< Data format is not what is expected */
										  I18N_ERROR_FILE_ACCESS					= TIZEN_ERROR_UTILITY_ICU | 0x03,	  /**< The requested file cannot be found */
													   I18N_ERROR_INTERNAL_PROGRAM				= TIZEN_ERROR_UTILITY_ICU | 0x04,	  /**< Indicates a bug in the library code */
																I18N_ERROR_OUT_OF_MEMORY				= TIZEN_ERROR_OUT_OF_MEMORY,		  /**< Out of memory */
																			I18N_ERROR_INDEX_OUTOFBOUNDS			= TIZEN_ERROR_UTILITY_ICU | 0x05,	  /**< Trying to access the index that is out of bounds */
																					 I18N_ERROR_INVALID_CHAR_FOUND			= TIZEN_ERROR_UTILITY_ICU | 0x06,	  /**< Character conversion: Unmappable input sequence. In other APIs: Invalid character */
																							 I18N_ERROR_BUFFER_OVERFLOW				= TIZEN_ERROR_UTILITY_ICU | 0x07,	  /**< A result would not fit in the supplied buffer */
																									   I18N_ERROR_NOT_SUPPORTED				= TIZEN_ERROR_NOT_SUPPORTED,		  /**< Requested operation is not supported in the current context */
																												   I18N_ERROR_COLLATOR_VERSION_MISMATCH	= TIZEN_ERROR_UTILITY_ICU | 0x08,	  /**< Collator version is not compatible with the base version */
																													  I18N_ERROR_USELESS_COLLATOR				= TIZEN_ERROR_UTILITY_ICU | 0x09,	  /**< Collator is options only and no base is specified */
																															   I18N_ERROR_NO_WRITE_PERMISSION			= TIZEN_ERROR_UTILITY_ICU | 0x0A,	  /**< Attempt to modify read-only or constant data */
																																	  I18N_ERROR_RESOURCE_TYPE_MISMATCH		= TIZEN_ERROR_UTILITY_ICU | 0x0B,	  /**< An operation is requested over a resource that does not support it */
																																		   I18N_ERROR_TOO_MANY_ALIASES				= TIZEN_ERROR_UTILITY_ICU | 0x0C,	  /**< Too many aliases in the path to the requested resource  */
																																					I18N_ERROR_INVALID_PARAMETER			= TIZEN_ERROR_INVALID_PARAMETER,	  /**< Invalid function parameter */
																																							 I18N_ERROR_PERMISSION_DENIED			= TIZEN_ERROR_PERMISSION_DENIED,	  /**< Permission denied */

																																									  I18N_ERROR_MESSAGE_PARSE				= TIZEN_ERROR_UTILITY_ICU | 0x0D,	  /**< Unable to parse a message (message format). @if MOBILE (Since 2.3.1) @endif*/
																																												  I18N_ERROR_PARSE						= TIZEN_ERROR_UTILITY_ICU | 0x0E,	  /**< Equivalent to Java ParseException. @if MOBILE (Since 2.3.1) @endif*/
																																																	I18N_ERROR_TRUNCATED_CHAR_FOUND			= TIZEN_ERROR_UTILITY_ICU | 0x0F,	  /**< Character conversion: Incomplete input sequence. @if MOBILE (Since 2.3.1) @endif*/
																																																		  I18N_ERROR_ILLEGAL_CHAR_FOUND			= TIZEN_ERROR_UTILITY_ICU | 0x10,	  /**< Character conversion: Illegal input sequence/combination of input units. @if MOBILE (Since 2.3.1) @endif*/
																																																				  I18N_ERROR_INVALID_TABLE_FORMAT			= TIZEN_ERROR_UTILITY_ICU | 0x11,	  /**< Conversion table file found, but corrupted. @if MOBILE (Since 2.3.1) @endif*/
																																																						I18N_ERROR_INVALID_TABLE_FILE			= TIZEN_ERROR_UTILITY_ICU | 0x12,	  /**< Conversion table file not found. @if MOBILE (Since 2.3.1) @endif*/
																																																								I18N_ERROR_ILLECAL_ESCAPE_SEQUENCE		= TIZEN_ERROR_UTILITY_ICU | 0x13,	  /**< ISO-2022 illegal escape sequence. @if MOBILE (Since 2.3.1) @endif*/
																																																									I18N_ERROR_UNSUPPORTED_ESCAPE_SEQUENCE	= TIZEN_ERROR_UTILITY_ICU | 0x14,	  /**< ISO-2022 unsupported escape sequence. @if MOBILE (Since 2.3.1) @endif*/
																																																									 I18N_ERROR_NO_SPACE_AVAILABLE			= TIZEN_ERROR_UTILITY_ICU | 0x15,	  /**< No space available for in-buffer expansion for Arabic shaping. @if MOBILE (Since 2.3.1) @endif*/
																																																											 I18N_ERROR_CE_NOT_FOUND					= TIZEN_ERROR_UTILITY_ICU | 0x16,	  /**< Currently used only while setting variable top, but can be used generally. @if MOBILE (Since 2.3.1) @endif*/
																																																														 I18N_ERROR_PRIMARY_TOO_LONG				= TIZEN_ERROR_UTILITY_ICU | 0x17,	  /**< User tried to set variable top to a primary that is longer than two bytes. @if MOBILE (Since 2.3.1) @endif*/
																																																																  I18N_ERROR_STATE_TOO_OLD				= TIZEN_ERROR_UTILITY_ICU | 0x18,	  /**< ICU cannot construct a service from this state, as it is no longer supported. @if MOBILE (Since 2.3.1) @endif*/
																																																																			  I18N_ERROR_ENUM_OUT_OF_SYNC				= TIZEN_ERROR_UTILITY_ICU | 0x19,	  /**< UEnumeration out of sync with underlying collection. @if MOBILE (Since 2.3.1) @endif*/
																																																																					   I18N_ERROR_INVARIANT_CONVERSION			= TIZEN_ERROR_UTILITY_ICU | 0x1A,	  /**< Unable to convert a UChar* string to char* with the invariant converter. @if MOBILE (Since 2.3.1) @endif*/
																																																																							 I18N_ERROR_INVALID_STATE				= TIZEN_ERROR_UTILITY_ICU | 0x1B,	  /**< Requested operation can not be completed with ICU in its current state. @if MOBILE (Since 2.3.1) @endif*/
																																																																										 I18N_ERROR_MALFORMED_SET				= TIZEN_ERROR_UTILITY_ICU | 0x1C,	  /**< A UnicodeSet pattern is invalid. @if MOBILE (Since 2.3.1) @endif*/
																																																																													 I18N_WARNING_STRING_NOT_TERMINATED		= TIZEN_ERROR_UTILITY_ICU | 0x1D,	  /**< String not terminated with NULL. @if MOBILE (Since 2.3.1) @endif*/
																																																																														 I18N_ERROR_STD3_ASCII_RULES				= TIZEN_ERROR_UTILITY_ICU | 0x1E,	  /**< Argument does not satisfy STD3 rules. @if MOBILE (Since 2.3.1) @endif*/
																																																																																  I18N_ERROR_UNASSIGNED					= TIZEN_ERROR_UTILITY_ICU | 0x1F,	  /**< Unassigned code points are found. @if MOBILE (Since 2.3.1) @endif*/
																																																																																				I18N_WARNING_SORT_KEY_TOO_SHORT			= TIZEN_ERROR_UTILITY_ICU | 0x20,	  /**< Number of levels requested in getBound is higher than the number of levels in the sort key. @if MOBILE (Since 2.3.1) @endif*/
																																																																																					  I18N_ERROR_UNKNOWN						= TIZEN_ERROR_UNKNOWN,				  /**< Unknown error. @if MOBILE (Since 2.3.1) @endif*/
}
i18n_error_code_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE
 * @{
 */

#define I18N_U_MASK(x)						  ((uint32_t)1<<(x)) /**< Get a single-bit bit set (a flag) from a bit number 0..31. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/

#define I18N_U_GC_CN_MASK					  I18N_U_MASK(I18N_UCHAR_U_GENERAL_OTHER_TYPES)		/**< U_GC_XX_MASK constants are bit flags corresponding to Unicode general category values. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LU_MASK					  I18N_U_MASK(I18N_UCHAR_U_UPPERCASE_LETTER)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LL_MASK					  I18N_U_MASK(I18N_UCHAR_U_LOWERCASE_LETTER)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LT_MASK					  I18N_U_MASK(I18N_UCHAR_U_TITLECASE_LETTER)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LM_MASK					  I18N_U_MASK(I18N_UCHAR_U_MODIFIER_LETTER)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LO_MASK					  I18N_U_MASK(I18N_UCHAR_U_OTHER_LETTER)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_MN_MASK					  I18N_U_MASK(I18N_UCHAR_U_NON_SPACING_MARK)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ME_MASK					  I18N_U_MASK(I18N_UCHAR_U_ENCLOSING_MARK)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_MC_MASK					  I18N_U_MASK(I18N_UCHAR_U_COMBINING_SPACING_MARK)	/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ND_MASK					  I18N_U_MASK(I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER)	/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_NL_MASK					  I18N_U_MASK(I18N_UCHAR_U_LETTER_NUMBER)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_NO_MASK					  I18N_U_MASK(I18N_UCHAR_U_OTHER_NUMBER)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZS_MASK					  I18N_U_MASK(I18N_UCHAR_U_SPACE_SEPARATOR)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZL_MASK					  I18N_U_MASK(I18N_UCHAR_U_LINE_SEPARATOR)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZP_MASK					  I18N_U_MASK(I18N_UCHAR_U_PARAGRAPH_SEPARATOR)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CC_MASK					  I18N_U_MASK(I18N_UCHAR_U_CONTROL_CHAR)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CF_MASK					  I18N_U_MASK(I18N_UCHAR_U_FORMAT_CHAR)				/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CO_MASK					  I18N_U_MASK(I18N_UCHAR_U_PRIVATE_USE_CHAR)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CS_MASK					  I18N_U_MASK(I18N_UCHAR_U_SURROGATE)				/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PD_MASK					  I18N_U_MASK(I18N_UCHAR_U_DASH_PUNCTUATION)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PS_MASK					  I18N_U_MASK(I18N_UCHAR_U_START_PUNCTUATION)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PE_MASK					  I18N_U_MASK(I18N_UCHAR_U_END_PUNCTUATION)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PC_MASK					  I18N_U_MASK(I18N_UCHAR_U_CONNECTOR_PUNCTUATION)	/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PO_MASK					  I18N_U_MASK(I18N_UCHAR_U_OTHER_PUNCTUATION)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SM_MASK					  I18N_U_MASK(I18N_UCHAR_U_MATH_SYMBOL)				/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SC_MASK					  I18N_U_MASK(I18N_UCHAR_U_CURRENCY_SYMBOL)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SK_MASK					  I18N_U_MASK(I18N_UCHAR_U_MODIFIER_SYMBOL)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SO_MASK					  I18N_U_MASK(I18N_UCHAR_U_OTHER_SYMBOL)			/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PI_MASK					  I18N_U_MASK(I18N_UCHAR_U_INITIAL_PUNCTUATION)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PF_MASK					  I18N_U_MASK(I18N_UCHAR_U_FINAL_PUNCTUATION)		/**< Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_L_MASK					  (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK|I18N_U_GC_LM_MASK|I18N_U_GC_LO_MASK)	/**<Mask constant for multiple #i18n_uchar_category_e bits (L Letters). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LC_MASK					  (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK)		 /**< Mask constant for multiple #i18n_uchar_category_e bits (LC Cased Letters). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_M_MASK					  (I18N_U_GC_MN_MASK|I18N_U_GC_ME_MASK|I18N_U_GC_MC_MASK)		 /**< Mask constant for multiple #i18n_uchar_category_e bits (M Marks). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_N_MASK					  (I18N_U_GC_ND_MASK|I18N_U_GC_NL_MASK|I18N_U_GC_NO_MASK)		 /**< Mask constant for multiple #i18n_uchar_category_e bits (N Numbers). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_Z_MASK					  (I18N_U_GC_ZS_MASK|I18N_U_GC_ZL_MASK|I18N_U_GC_ZP_MASK)		 /**< Mask constant for multiple #i18n_uchar_category_e bits (Z Separators). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_C_MASK					  (I18N_U_GC_CN_MASK|I18N_U_GC_CC_MASK|I18N_U_GC_CF_MASK|I18N_U_GC_CO_MASK|I18N_U_GC_CS_MASK)		 /**<Mask constant for multiple #i18n_uchar_category_e bits (C Others). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_P_MASK					  (I18N_U_GC_PD_MASK|I18N_U_GC_PS_MASK|I18N_U_GC_PE_MASK|I18N_U_GC_PC_MASK|I18N_U_GC_PO_MASK|I18N_U_GC_PI_MASK|I18N_U_GC_PF_MASK)	/**<Mask constant for multiple #i18n_uchar_category_e bits (P Punctuation). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_S_MASK					  (I18N_U_GC_SM_MASK|I18N_U_GC_SC_MASK|I18N_U_GC_SK_MASK|I18N_U_GC_SO_MASK)			/**<Mask constant for multiple #i18n_uchar_category_e bits (S Symbols). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif	*/

#define I18N_U_NO_NUMERIC_VALUE				  ((double)-123456789.)			/**< Special value that is returned by i18n_uchar_get_numeric_value()(not implemented yet) when no numeric value is defined for a code point. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif	 */

#define I18N_U_GET_GC_MASK(c)				  I18N_U_MASK(u_charType(c))	/**< Get a single-bit bit set for the general category of a character. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif  */

/**
 * @brief Option value for case folding: use default mappings defined in CaseFolding.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */
#define I18N_U_FOLD_CASE_DEFAULT 0

/**
 * @brief Option value for case folding: \n
 *		  Use the modified set of mappings provided in CaseFolding.txt to handle dotted I and dotless i appropriately for Turkic languages (tr, az).\n
 *		  Before Unicode 3.2, CaseFolding.txt contains mappings marked with 'I' that are to be included for default mappings and excluded for the Turkic-specific mappings.\n
 *		  Unicode 3.2 CaseFolding.txt instead contains mappings marked with 'T' that are to be excluded for default mappings and included for the Turkic-specific mappings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_U_FOLD_CASE_EXCLUDE_SPECIAL_I 1


/**
 * @brief DONE is returned by i18n_usearch_previous() and i18n_usearch_next() after all valid matches have been returned,
 *		  and by, i18n_usearch_first() and i18n_usearch_last() if there are no matches at all.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USEARCH_DONE					  -1


#if !defined(U_WCHAR_IS_UTF16) && !defined(U_WCHAR_IS_UTF32)
#	ifdef __STDC_ISO_10646__
#		if (U_SIZEOF_WCHAR_T == 2)
#			define U_WCHAR_IS_UTF16
#		elif (U_SIZEOF_WCHAR_T == 4)
#			define	U_WCHAR_IS_UTF32
#		endif
#	elif defined __UCS2__
#		if (U_PF_OS390 <= U_PLATFORM && U_PLATFORM <= U_PF_OS400) && (U_SIZEOF_WCHAR_T == 2)
#			define U_WCHAR_IS_UTF16
#		endif
#	elif defined(__UCS4__) || (U_PLATFORM == U_PF_OS400 && defined(__UTF32__))
#		if (U_SIZEOF_WCHAR_T == 4)
#			define U_WCHAR_IS_UTF32
#		endif
#	elif U_PLATFORM_IS_DARWIN_BASED || (U_SIZEOF_WCHAR_T == 4 && U_PLATFORM_IS_LINUX_BASED)
#		define U_WCHAR_IS_UTF32
#	elif U_PLATFORM_HAS_WIN32_API
#		define U_WCHAR_IS_UTF16
#	endif
#endif
#define U_SIZEOF_UCHAR 2

/**
 * @brief i18n_uchar.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#if defined(UCHAR_TYPE)
typedef UCHAR_TYPE i18n_uchar;
/* Not #elif U_HAVE_CHAR16_T -- because that is type-incompatible with pre-C++11 callers
	typedef char16_t i18n_uchar;  */
#elif U_SIZEOF_WCHAR_T == 2
typedef wchar_t i18n_uchar;
#elif defined(__CHAR16_TYPE__)
typedef __CHAR16_TYPE__ i18n_uchar;
#else
typedef uint16_t i18n_uchar;
#endif


/**
 * @brief i18n_uchar32.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef int32_t i18n_uchar32;

/**
 * @brief i18n_ubool.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef int8_t i18n_ubool;

/**
 * @brief Enumeration of constants for Unicode properties.
 *		  The properties APIs are intended to reflect Unicode properties as defined in the
 *		  Unicode Character Database (UCD) and Unicode Technical Reports (UTR).
 *		  For details about the properties see http://www.unicode.org/ucd/ .
 *		  For names of Unicode properties see the UCD file PropertyAliases.txt.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_ALPHABETIC					   = 0,
	/**< Binary property Alphabetic. \n
		 Lu+Ll+Lt+Lm+Lo+Nl+Other_Alphabetic
	 */
	I18N_UCHAR_BINARY_START					   = I18N_UCHAR_ALPHABETIC,
	/**< First constant for binary Unicode properties. */
	I18N_UCHAR_ASCII_HEX_DIGIT,
	/**< Binary property ASCII_Hex_Digit. \n
		 0-9 A-F a-f
	 */
	I18N_UCHAR_BIDI_CONTROL,
	/**< Binary property Bidi_Control. \n
	 Format controls which have specific functions in the Bidi Algorithm.
	 */
	I18N_UCHAR_BIDI_MIRRORED,
	/**< Binary property Bidi_Mirrored. \n
		 Characters that may change display in RTL text. See Bidi Algorithm, UTR 9.
	 */
	I18N_UCHAR_DASH,
	/**< Binary property Dash. \n
		 Variations of dashes.
	 */
	I18N_UCHAR_DEFAULT_IGNORABLE_CODE_POINT,
	/**< Binary property Default_Ignorable_Code_Point (new in Unicode 3.2). \n
		 Ignorable in most processing. &lt;2060..206F, FFF0..FFFB, E0000..E0FFF&gt;+Other_Default_Ignorable_Code_Point+(Cf+Cc+Cs-White_Space)
	 */
	I18N_UCHAR_DEPRECATED,
	/**< Binary property Deprecated (new in Unicode 3.2). \n
		 The usage of deprecated characters is strongly discouraged.
	 */
	I18N_UCHAR_DIACRITIC,
	/**< Binary property Diacritic. \n
		 Characters that linguistically modify the meaning of another character to which they apply.
	 */
	I18N_UCHAR_EXTENDER,
	/**< Binary property Extender. \n
		 Extend the value or shape of a preceding alphabetic character, e.g. length and iteration marks.
	 */
	I18N_UCHAR_FULL_COMPOSITION_EXCLUSION,
	/**< Binary property Full_Composition_Exclusion. \n
		 CompositionExclusions.txt+Singleton Decompositions+ Non-Starter Decompositions.
	 */
	I18N_UCHAR_GRAPHEME_BASE,
	/**< Binary property Grapheme_Base (new in Unicode 3.2). \n
		 For programmatic determination of grapheme cluster boundaries. [0..10FFFF]-Cc-Cf-Cs-Co-Cn-Zl-Zp-Grapheme_Link-Grapheme_Extend-CGJ
	 */
	I18N_UCHAR_GRAPHEME_EXTEND,
	/**< Binary property Grapheme_Extend (new in Unicode 3.2). \n
		 For programmatic determination of grapheme cluster boundaries. Me+Mn+Mc+Other_Grapheme_Extend-Grapheme_Link-CGJ
	 */
	I18N_UCHAR_GRAPHEME_LINK,
	/**< Binary property Grapheme_Link (new in Unicode 3.2). \n
		 For programmatic determination of grapheme cluster boundaries.
	 */
	I18N_UCHAR_HEX_DIGIT,
	/**< Binary property Hex_Digit. \n
		 Characters commonly used for hexadecimal numbers.
	 */
	I18N_UCHAR_HYPHEN,
	/**< Binary property Hyphen. \n
		 Dashes used to mark connections between pieces of words, plus the Katakana middle dot.
	 */
	I18N_UCHAR_ID_CONTINUE,
	/**< Binary property ID_Continue. \n
		 Characters that can continue an identifier. DerivedCoreProperties.txt also says "NOTE: Cf characters should be filtered out." ID_Start+Mn+Mc+Nd+Pc
	 */
	I18N_UCHAR_ID_START,
	/**< Binary property ID_Start. \n
		 Characters that can start an identifier. Lu+Ll+Lt+Lm+Lo+Nl
	 */
	I18N_UCHAR_IDEOGRAPHIC,
	/**< Binary property Ideographic. \n
		 CJKV ideographs.
	 */
	I18N_UCHAR_IDS_BINARY_OPERATOR,
	/**< Binary property IDS_Binary_Operator (new in Unicode 3.2). \n
		 For programmatic determination of Ideographic Description Sequences.
	 */
	I18N_UCHAR_IDS_TRINARY_OPERATOR,
	/**< Binary property IDS_Trinary_Operator (new in Unicode 3.2). \n
		 For programmatic determination of Ideographic Description Sequences.
	 */
	I18N_UCHAR_JOIN_CONTROL,
	/**< Binary property Join_Control. \n
		 Format controls for cursive joining and ligation.
	 */
	I18N_UCHAR_LOGICAL_ORDER_EXCEPTION,
	/**< Binary property Logical_Order_Exception (new in Unicode 3.2). \n
		 Characters that do not use logical order and require special handling in most processing.
	 */
	I18N_UCHAR_LOWERCASE,
	/**< Binary property Lowercase. \n
		 Ll+Other_Lowercase
	 */
	I18N_UCHAR_MATH,
	/**< Binary property Math. \n
		 Sm+Other_Math
	 */
	I18N_UCHAR_NONCHARACTER_CODE_POINT,
	/**< Binary property Noncharacter_Code_Point. \n
		 Code points that are explicitly defined as illegal for the encoding of characters.
	 */
	I18N_UCHAR_QUOTATION_MARK,
	/**< Binary property Quotation_Mark. \n
	 */
	I18N_UCHAR_RADICAL,
	/**< Binary property Radical (new in Unicode 3.2). \n
		 For programmatic determination of Ideographic Description Sequences.
	 */
	I18N_UCHAR_SOFT_DOTTED,
	/**< Binary property Soft_Dotted (new in Unicode 3.2). \n
		 Characters with a "soft dot", like i or j. An accent placed on these characters causes the dot to disappear.
	 */
	I18N_UCHAR_TERMINAL_PUNCTUATION,
	/**< Binary property Terminal_Punctuation. \n
		 Punctuation characters that generally mark the end of textual units.
	 */
	I18N_UCHAR_UNIFIED_IDEOGRAPH,
	/**< Binary property Unified_Ideograph (new in Unicode 3.2). \n
		 For programmatic determination of Ideographic Description Sequences.
	 */
	I18N_UCHAR_UPPERCASE,
	/**< Binary property Uppercase. \n
		 Lu+Other_Uppercase
	 */
	I18N_UCHAR_WHITE_SPACE,
	/**< Binary property White_Space. \n
		 Space characters+TAB+CR+LF-ZWSP-ZWNBSP
	 */
	I18N_UCHAR_XID_CONTINUE,
	/**< Binary property XID_Continue. \n
		 ID_Continue modified to allow closure under normalization forms NFKC and NFKD.
	 */
	I18N_UCHAR_XID_START,
	/**< Binary property XID_Start. \n
		 ID_Start modified to allow closure under normalization forms NFKC and NFKD.
	 */
	I18N_UCHAR_CASE_SENSITIVE,
	/**< Binary property Case_Sensitive. \n
		 Either the source of a case mapping or <em>in</em> the target of a case mapping. Not the same as the general category Cased_Letter.
	 */
	I18N_UCHAR_S_TERM,
	/**< Binary property STerm (new in Unicode 4.0.1). \n
	 */
	I18N_UCHAR_VARIATION_SELECTOR,
	/**< Binary property Variation_Selector (new in Unicode 4.0.1). \n
		 Indicates all those characters that qualify as Variation Selectors.
			  */
	I18N_UCHAR_NFD_INERT,
	/**< Binary property NFD_Inert. \n
		 ICU-specific property for characters that are inert under NFD, i.e., they do not interact with adjacent characters.
	 */
	I18N_UCHAR_NFKD_INERT,
	/**< Binary property NFKD_Inert. \n
		 ICU-specific property for characters that are inert under NFKD, i.e., they do not interact with adjacent characters.
	 */
	I18N_UCHAR_NFC_INERT,
	/**< Binary property NFC_Inert. \n
		 ICU-specific property for characters that are inert under NFC, i.e., they do not interact with adjacent characters.
	 */
	I18N_UCHAR_NFKC_INERT,
	/**< Binary property NFKC_Inert. \n
		 ICU-specific property for characters that are inert under NFKC, i.e., they do not interact with adjacent characters.
	 */
	I18N_UCHAR_SEGMENT_STARTER,
	/**< Binary Property Segment_Starter. \n
		 Property for characters that are starters in terms of Unicode normalization and combining character sequences.
		 They have ccc=0 and do not occur in non-initial position of the canonical decomposition of any character
		 (like a-umlaut in NFD and a Jamo T in an NFD(Hangul LVT)).
	 */
	I18N_UCHAR_PATTERN_SYNTAX,
	/**< Binary property Pattern_Syntax (new in Unicode 4.1). \n
	 */
	I18N_UCHAR_PATTERN_WHITE_SPACE,
	/**< Binary property Pattern_White_Space (new in Unicode 4.1). \n
	 */
	I18N_UCHAR_POSIX_ALNUM,
	/**< Binary property alnum (a C/POSIX character class).*/
	I18N_UCHAR_POSIX_BLANK,
	/**< Binary property blank (a C/POSIX character class).*/
	I18N_UCHAR_POSIX_GRAPH,
	/**< Binary property graph (a C/POSIX character class). */
	I18N_UCHAR_POSIX_PRINT,
	/**< Binary property print (a C/POSIX character class). */
	I18N_UCHAR_POSIX_XDIGIT,
	/**< Binary property xdigit (a C/POSIX character class). */
	I18N_UCHAR_CASED,
	/**< Binary property Cased. \n
		 For Lowercase, Uppercase and Titlecase characters.
	 */
	I18N_UCHAR_CASE_IGNORABLE,
	/**< Binary property Case_Ignorable. \n
		 Used in context-sensitive case mappings.
	 */
	I18N_UCHAR_CHANGES_WHEN_LOWERCASED,
	/**< Binary property Changes_When_Lowercased. */
	I18N_UCHAR_CHANGES_WHEN_UPPERCASED,
	/**< Binary property Changes_When_Uppercased. */
	I18N_UCHAR_CHANGES_WHEN_TITLECASED,
	/**< Binary property Changes_When_Titlecased. */
	I18N_UCHAR_CHANGES_WHEN_CASEFOLDED,
	/**< Binary property Changes_When_Casefolded. */
	I18N_UCHAR_CHANGES_WHEN_CASEMAPPED,
	/**< Binary property Changes_When_Casemapped. */
	I18N_UCHAR_CHANGES_WHEN_NFKC_CASEFOLDED,
	/**< Binary property Changes_When_NFKC_Casefolded. */
	I18N_UCHAR_BINARY_LIMIT,
	/**< One more than the last constant for binary Unicode properties. */
	I18N_UCHAR_BIDI_CLASS					   = 0x1000,
	/**< Enumerated property Bidi_Class. \n
		 Same as u_charDirection, returns #i18n_uchar_direction_e values.
	 */
	I18N_UCHAR_INT_START					   = I18N_UCHAR_BIDI_CLASS,
	/**< First constant for enumerated/integer Unicode properties. */
	I18N_UCHAR_BLOCK,
	/**< Enumerated property Block. \n
		 Returns #i18n_uchar_ublock_code_e values.
	 */
	I18N_UCHAR_CANONICAL_COMBINING_CLASS,
	/**< Enumerated property Canonical_Combining_Class. \n
		 Returns 8-bit numeric values.
	 */
	I18N_UCHAR_DECOMPOSITION_TYPE,
	/**< Enumerated property Decomposition_Type. \n
		 Returns #i18n_uchar_u_decomposition_type_e values.
	 */
	I18N_UCHAR_EAST_ASIAN_WIDTH,
	/**< Enumerated property East_Asian_Width. \n
		  Returns #i18n_uchar_u_east_asian_width_e values.
	 */
	I18N_UCHAR_GENERAL_CATEGORY,
	/**< Enumerated property General_Category. \n
		 Returns #i18n_uchar_category_e values.
	 */
	I18N_UCHAR_JOINING_GROUP,
	/**< Enumerated property Joining_Group. \n
		 Returns #i18n_uchar_u_joining_group_e values.
	 */
	I18N_UCHAR_JOINING_TYPE,
	/**< Enumerated property Joining_Type. \n
		 Returns #i18n_uchar_u_joining_type_e values.
	 */
	I18N_UCHAR_LINE_BREAK,
	/**< Enumerated property Line_Break. \n
		 Returns #i18n_uchar_u_line_break_e values.
	 */
	I18N_UCHAR_NUMERIC_TYPE,
	/**< Enumerated property Numeric_Type. \n
		 Returns #i18n_uchar_u_numeric_type_e values.
	 */
	I18N_UCHAR_SCRIPT,
	/**< Enumerated property Script. \n
		 Returns #i18n_uscript_code_e values.
	 */
	I18N_UCHAR_HANGUL_SYLLABLE_TYPE,
	/**< Enumerated property Hangul_Syllable_Type, new in Unicode 4. \n
		 Returns #i18n_uchar_u_hangul_syllable_type_e values.
	 */
	I18N_UCHAR_NFD_QUICK_CHECK,
	/**< Enumerated property NFD_Quick_Check. \n
		 Returns #i18n_unormalization_check_result_e values.
	 */
	I18N_UCHAR_NFKD_QUICK_CHECK,
	/**< Enumerated property NFKD_Quick_Check. \n
		 Returns #i18n_unormalization_check_result_e values.
	 */
	I18N_UCHAR_NFC_QUICK_CHECK,
	/**< Enumerated property NFC_Quick_Check. \n
		 Returns #i18n_unormalization_check_result_e values.
	 */
	I18N_UCHAR_NFKC_QUICK_CHECK,
	/**< Enumerated property NFKC_Quick_Check. \n
		 Returns #i18n_unormalization_check_result_e values.
	 */
	I18N_UCHAR_LEAD_CANONICAL_COMBINING_CLASS,
	/**< Enumerated property Lead_Canonical_Combining_Class. \n
		 Returns 8-bit numeric values.
	 */
	I18N_UCHAR_TRAIL_CANONICAL_COMBINING_CLASS,
	/**< Enumerated property Trail_Canonical_Combining_Class. \n
		 Returns 8-bit numeric values.
	 */
	I18N_UCHAR_GRAPHEME_CLUSTER_BREAK,
	/**< Enumerated property Grapheme_Cluster_Break (new in Unicode 4.1). \n
		 Returns #i18n_uchar_u_grapheme_cluster_break_e values.
	 */
	I18N_UCHAR_SENTENCE_BREAK,
	/**< Enumerated property Sentence_Break (new in Unicode 4.1). \n
		 Returns #i18n_uchar_u_sentence_break_e values.
	 */
	I18N_UCHAR_WORD_BREAK,
	/**< Enumerated property Word_Break (new in Unicode 4.1). \n
		 Returns #i18n_uchar_u_word_break_values_e values.
	 */
	I18N_UCHAR_BIDI_PAIRED_BRACKET_TYPE,
	/**< Enumerated property Bidi_Paired_Bracket_Type. \n
		 Returns #i18n_uchar_u_bidi_paired_bracket_type_e values .
	 */
	I18N_UCHAR_INT_LIMIT,
	/**< One more than the last constant for enumerated/integer Unicode properties. */
	I18N_UCHAR_GENERAL_CATEGORY_MASK		   = 0x2000,
	/**< Bitmask property General_Category_Mask. \n
		 Mask values should be cast to uint32_t.
	 */
	I18N_UCHAR_MASK_START					   = I18N_UCHAR_GENERAL_CATEGORY_MASK,
	/**< First constant for bit-mask Unicode properties. */
	I18N_UCHAR_MASK_LIMIT,
	/**< One more than the last constant for bit-mask Unicode properties. */
	I18N_UCHAR_NUMERIC_VALUE				   = 0x3000,
	/**< Double property Numeric_Value. */
	I18N_UCHAR_DOUBLE_START					   = I18N_UCHAR_NUMERIC_VALUE,
	/**< First constant for double Unicode properties. */
	I18N_UCHAR_DOUBLE_LIMIT,
	/**< One more than the last constant for double Unicode properties. */
	I18N_UCHAR_AGE							   = 0x4000,
	/**< String property Age. */
	I18N_UCHAR_STRING_START					   = I18N_UCHAR_AGE,
	/**< First constant for string Unicode properties. */
	I18N_UCHAR_BIDI_MIRRORING_GLYPH,
	/**< String property Bidi_Mirroring_Glyph. */
	I18N_UCHAR_CASE_FOLDING,
	/**< String property Case_Folding. */
	I18N_UCHAR_LOWERCASE_MAPPING			   = 0x4004,
	/**< String property Lowercase_Mapping. */
	I18N_UCHAR_NAME,
	/**< String property Name. */
	I18N_UCHAR_SIMPLE_CASE_FOLDING,
	/**< String property Simple_Case_Folding. */
	I18N_UCHAR_SIMPLE_LOWERCASE_MAPPING,
	/**< String property Simple_Lowercase_Mapping. */
	I18N_UCHAR_SIMPLE_TITLECASE_MAPPING,
	/**< String property Simple_Titlecase_Mapping. */
	I18N_UCHAR_SIMPLE_UPPERCASE_MAPPING,
	/**< String property Simple_Uppercase_Mapping. */
	I18N_UCHAR_TITLECASE_MAPPING,
	/**< String property Titlecase_Mapping. */
	I18N_UCHAR_UPPERCASE_MAPPING			   = 0x400C,
	/**< String property Uppercase_Mapping. */
	I18N_UCHAR_BIDI_PAIRED_BRACKET				  = 0x400D,
	/**< String property Bidi_Paired_Bracket. */
	I18N_UCHAR_STRING_LIMIT,
	/**< One more than the last constant for string Unicode properties. */
	I18N_UCHAR_SCRIPT_EXTENSIONS			   = 0x7000,
	/**< Provisional property Script_Extensions (new in Unicode 6.0). */
	I18N_UCHAR_OTHER_PROPERTY_START			   = I18N_UCHAR_SCRIPT_EXTENSIONS,
	/**< First constant for Unicode properties with unusual value types. */
	I18N_UCHAR_OTHER_PROPERTY_LIMIT,
	/**< One more than the last constant for Unicode properties with unusual value types. */
	I18N_UCHAR_INVALID_CODE					   = -1
												 /**< Represents a nonexistent or invalid property or property value. */
} i18n_uchar_uproperty_e;

/**
 * @brief Bidi Paired Bracket Type constants.
 * @since_tizen 3.0
 * @see I18N_UCHAR_BIDI_PAIRED_BRACKET_TYPE
 *
 */
typedef enum {
	I18N_UCHAR_U_BPT_NONE,	  /**< Not a paired bracket. */

	I18N_UCHAR_U_BPT_OPEN,	  /**< Open paired bracket. */

	I18N_UCHAR_U_BPT_CLOSE,	  /**< Close paired bracket. */

	I18N_UCHAR_U_BPT_COUNT /**< Count */
} i18n_uchar_u_bidi_paired_bracket_type_e;

/**
 * @brief Constants for Unicode blocks, see the Unicode Data file Blocks.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */
typedef enum {
	I18N_UCHAR_UBLOCK_NO_BLOCK,													 /**< No Block */
	I18N_UCHAR_UBLOCK_BASIC_LATIN,												 /**< Basic Latin */
	I18N_UCHAR_UBLOCK_LATIN_1_SUPPLEMENT,										 /**< Latin_1 Supplement */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_A,											 /**< Latin Extended A */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_B,											 /**< Latin Extended B */
	I18N_UCHAR_UBLOCK_IPA_EXTENSIONS,											 /**< IPA Extensions */
	I18N_UCHAR_UBLOCK_SPACING_MODIFIER_LETTERS,									 /**< Spacing Modifier Letters */
	I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS,								 /**< Combining Diacritical Marks */
	I18N_UCHAR_UBLOCK_GREEK,													 /**< Greek */
	I18N_UCHAR_UBLOCK_CYRILLIC,													 /**< Cyrillic */
	I18N_UCHAR_UBLOCK_ARMENIAN,													 /**< Armenian */
	I18N_UCHAR_UBLOCK_HEBREW,													 /**< Hebrew */
	I18N_UCHAR_UBLOCK_ARABIC,													 /**< Arabic */
	I18N_UCHAR_UBLOCK_SYRIAC,													 /**< Syriac */
	I18N_UCHAR_UBLOCK_THAANA,													 /**< Thaana */
	I18N_UCHAR_UBLOCK_DEVANAGARI,												 /**< Devanagari */
	I18N_UCHAR_UBLOCK_BENGALI,													 /**< Bengali */
	I18N_UCHAR_UBLOCK_GURMUKHI,													 /**< Gurmukhi */
	I18N_UCHAR_UBLOCK_GUJARATI,													 /**< Gujarati */
	I18N_UCHAR_UBLOCK_ORIYA,													 /**< Oriya */
	I18N_UCHAR_UBLOCK_TAMIL,													 /**< Tamil */
	I18N_UCHAR_UBLOCK_TELUGU,													 /**< Telugu */
	I18N_UCHAR_UBLOCK_KANNADA,													 /**< Kannada */
	I18N_UCHAR_UBLOCK_MALAYALAM,												 /**< Malayalam */
	I18N_UCHAR_UBLOCK_SINHALA,													 /**< Sinhala */
	I18N_UCHAR_UBLOCK_THAI,														 /**< Thai */
	I18N_UCHAR_UBLOCK_LAO,														 /**< Lao */
	I18N_UCHAR_UBLOCK_TIBETAN,													 /**< Tibetan */
	I18N_UCHAR_UBLOCK_MYANMAR,													 /**< Myanmar */
	I18N_UCHAR_UBLOCK_GEORGIAN,													 /**< Georgian */
	I18N_UCHAR_UBLOCK_HANGUL_JAMO,												 /**< Hangul Jamo */
	I18N_UCHAR_UBLOCK_ETHIOPIC,													 /**< Ethiopic */
	I18N_UCHAR_UBLOCK_CHEROKEE,													 /**< Cherokee */
	I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,					 /**< Unified Canadian Aboriginal Syllabics */
	I18N_UCHAR_UBLOCK_OGHAM,													 /**< Ogham */
	I18N_UCHAR_UBLOCK_RUNIC,													 /**< Runic */
	I18N_UCHAR_UBLOCK_KHMER,													 /**< Khmer */
	I18N_UCHAR_UBLOCK_MONGOLIAN,												 /**< Mongolian */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_ADDITIONAL,								 /**< Latin Extended Additional */
	I18N_UCHAR_UBLOCK_GREEK_EXTENDED,											 /**< Greek Extended */
	I18N_UCHAR_UBLOCK_GENERAL_PUNCTUATION,										 /**< General Punctuation */
	I18N_UCHAR_UBLOCK_SUPERSCRIPTS_AND_SUBSCRIPTS,								 /**< Superscripts And Subscripts */
	I18N_UCHAR_UBLOCK_CURRENCY_SYMBOLS,											 /**< Currency Symbols */
	I18N_UCHAR_UBLOCK_COMBINING_MARKS_FOR_SYMBOLS,								 /**< Combining Marks For Symbols */
	I18N_UCHAR_UBLOCK_LETTERLIKE_SYMBOLS,										 /**< Letterlike Symbols */
	I18N_UCHAR_UBLOCK_NUMBER_FORMS,												 /**< Number Forms */
	I18N_UCHAR_UBLOCK_ARROWS,													 /**< Arrows */
	I18N_UCHAR_UBLOCK_MATHEMATICAL_OPERATORS,									 /**< Mathematical Operators */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_TECHNICAL,									 /**< Miscellaneous Technical */
	I18N_UCHAR_UBLOCK_CONTROL_PICTURES,											 /**< Control Pictures */
	I18N_UCHAR_UBLOCK_OPTICAL_CHARACTER_RECOGNITION,							 /**< Optical Character Recognition */
	I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERICS,									 /**< Enclosed Alphanumerics */
	I18N_UCHAR_UBLOCK_BOX_DRAWING,												 /**< Box Drawing */
	I18N_UCHAR_UBLOCK_BLOCK_ELEMENTS,											 /**< Block Elements */
	I18N_UCHAR_UBLOCK_GEOMETRIC_SHAPES,											 /**< Geometric Shapes */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS,									 /**< Miscellaneous Symbols */
	I18N_UCHAR_UBLOCK_DINGBATS,													 /**< Dingbats */
	I18N_UCHAR_UBLOCK_BRAILLE_PATTERNS,											 /**< Braille Patterns */
	I18N_UCHAR_UBLOCK_CJK_RADICALS_SUPPLEMENT,									 /**< CJK Radicals Supplement */
	I18N_UCHAR_UBLOCK_KANGXI_RADICALS,											 /**< Kangxi Radicals */
	I18N_UCHAR_UBLOCK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS,						 /**< Ideographic Description Characters */
	I18N_UCHAR_UBLOCK_CJK_SYMBOLS_AND_PUNCTUATION,								 /**< CJK Symbols And Punctuation */
	I18N_UCHAR_UBLOCK_HIRAGANA,													 /**< Hiragana */
	I18N_UCHAR_UBLOCK_KATAKANA,													 /**< Katakana */
	I18N_UCHAR_UBLOCK_BOPOMOFO,													 /**< Bopomofo */
	I18N_UCHAR_UBLOCK_HANGUL_COMPATIBILITY_JAMO,								 /**< Hangul Compatibility Jamo */
	I18N_UCHAR_UBLOCK_KANBUN,													 /**< Kanbun */
	I18N_UCHAR_UBLOCK_BOPOMOFO_EXTENDED,										 /**< Bopomofo Extended */
	I18N_UCHAR_UBLOCK_ENCLOSED_CJK_LETTERS_AND_MONTHS,							 /**< Enclosed CJK Letters And Months */
	I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY,										 /**< CJK Compatibility */
	I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,						 /**< CJK Unified Ideographs Extension A */
	I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS,									 /**< CJK Unified Ideographs */
	I18N_UCHAR_UBLOCK_YI_SYLLABLES,												 /**< Yi Syllables */
	I18N_UCHAR_UBLOCK_YI_RADICALS,												 /**< Yi Radicals */
	I18N_UCHAR_UBLOCK_HANGUL_SYLLABLES,											 /**< Hangul Syllables */
	I18N_UCHAR_UBLOCK_HIGH_SURROGATES,											 /**< High Surrogates */
	I18N_UCHAR_UBLOCK_HIGH_PRIVATE_USE_SURROGATES,								 /**< High Private Use Surrogates */
	I18N_UCHAR_UBLOCK_LOW_SURROGATES,											 /**< Low Surrogates */
	I18N_UCHAR_UBLOCK_PRIVATE_USE_AREA,											 /**< Private Use Area */
	I18N_UCHAR_UBLOCK_PRIVATE_USE,												 /**< Private Use */
	I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS,								 /**< CJK Compatibility Ideographs */

	I18N_UCHAR_UBLOCK_ALPHABETIC_PRESENTATION_FORMS,							 /**< Alphabetic Presentation Forms */
	I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_A,								 /**< Arabic Presentation Forms A */
	I18N_UCHAR_UBLOCK_COMBINING_HALF_MARKS,										 /**< Combining Half Marks */
	I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_FORMS,									 /**< CJK Compatibility Forms */
	I18N_UCHAR_UBLOCK_SMALL_FORM_VARIANTS,										 /**< Small Form Variants */
	I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_B,								 /**< Arabic Presentation Forms B */
	I18N_UCHAR_UBLOCK_SPECIALS,													 /**< Specials */
	I18N_UCHAR_UBLOCK_HALFWIDTH_AND_FULLWIDTH_FORMS,							 /**< Halfwidth And Fullwidth Forms */
	I18N_UCHAR_UBLOCK_OLD_ITALIC,												 /**< Old Italic */
	I18N_UCHAR_UBLOCK_GOTHIC,													 /**< Gothic */
	I18N_UCHAR_UBLOCK_DESERET,													 /**< Deseret */
	I18N_UCHAR_UBLOCK_BYZANTINE_MUSICAL_SYMBOLS,								 /**< Byzantine Musical Symbols */
	I18N_UCHAR_UBLOCK_MUSICAL_SYMBOLS,											 /**< Musical Symbols */
	I18N_UCHAR_UBLOCK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS,						 /**< Mathematical Alphanumeric Symbols */
	I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,						 /**< CJK Unified Ideographs Extension B */
	I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,					 /**< CJK Compatibility Ideographs Supplement */
	I18N_UCHAR_UBLOCK_TAGS,														 /**< Tags */
	I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENT,										 /**< Cyrillic Supplement */
	I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENTARY,									 /**< Cyrillic Supplementary */
	I18N_UCHAR_UBLOCK_TAGALOG,													 /**< Tagalog */
	I18N_UCHAR_UBLOCK_HANUNOO,													 /**< Hanunoo */
	I18N_UCHAR_UBLOCK_BUHID,													 /**< Buhid */
	I18N_UCHAR_UBLOCK_TAGBANWA,													 /**< Tagbanwa */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,						 /**< Miscellaneous Mathematical Symbols A */
	I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_A,									 /**< Supplemental Arrows A */
	I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_B,									 /**< Supplemental Arrows B */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,						 /**< Miscellaneous Mathematical Symbols B */
	I18N_UCHAR_UBLOCK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS,						 /**< Supplemental Mathematical Operators */
	I18N_UCHAR_UBLOCK_KATAKANA_PHONETIC_EXTENSIONS,								 /**< Katakana Phonetic Extensions */
	I18N_UCHAR_UBLOCK_VARIATION_SELECTORS,										 /**< Variation Selectors */
	I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_A,							 /**< Supplementary Private Use Area A */
	I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_B,							 /**< Supplementary Private Use Area B */
	I18N_UCHAR_UBLOCK_LIMBU,													 /**< Limbu */
	I18N_UCHAR_UBLOCK_TAI_LE,													 /**< Tai Le */
	I18N_UCHAR_UBLOCK_KHMER_SYMBOLS,											 /**< Khmer Symbols */
	I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS,										 /**< Phonetic Extensions */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_ARROWS,							 /**< Miscellaneous Symbols And Arrows */
	I18N_UCHAR_UBLOCK_YIJING_HEXAGRAM_SYMBOLS,									 /**< Yijing Hexagram Symbols */
	I18N_UCHAR_UBLOCK_LINEAR_B_SYLLABARY,										 /**< Linear B Syllabary */
	I18N_UCHAR_UBLOCK_LINEAR_B_IDEOGRAMS,										 /**< Linear B Ideograms */
	I18N_UCHAR_UBLOCK_AEGEAN_NUMBERS,											 /**< Aegean Numbers */
	I18N_UCHAR_UBLOCK_UGARITIC,													 /**< Ugaritic */
	I18N_UCHAR_UBLOCK_SHAVIAN,													 /**< Shavian */
	I18N_UCHAR_UBLOCK_OSMANYA,													 /**< Osmanya */
	I18N_UCHAR_UBLOCK_CYPRIOT_SYLLABARY,										 /**< Cypriot Syllabary */
	I18N_UCHAR_UBLOCK_TAI_XUAN_JING_SYMBOLS,									 /**< Tai Xuan Jing Symbols */
	I18N_UCHAR_UBLOCK_VARIATION_SELECTORS_SUPPLEMENT,							 /**< Variation Selectors Supplement */
	I18N_UCHAR_UBLOCK_ANCIENT_GREEK_MUSICAL_NOTATION,							 /**< Ancient Greek Musical Notation */
	I18N_UCHAR_UBLOCK_ANCIENT_GREEK_NUMBERS,									 /**< Ancient Greek Numbers */
	I18N_UCHAR_UBLOCK_ARABIC_SUPPLEMENT,										 /**< Arabic Supplement */
	I18N_UCHAR_UBLOCK_BUGINESE,													 /**< Buginese */
	I18N_UCHAR_UBLOCK_CJK_STROKES,												 /**< CJK Strokes */
	I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,					 /**< Combining Diacritical Marks Supplement */
	I18N_UCHAR_UBLOCK_COPTIC,													 /**< Coptic */
	I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED,										 /**< Ethiopic Extended */
	I18N_UCHAR_UBLOCK_ETHIOPIC_SUPPLEMENT,										 /**< Ethiopic Supplement */
	I18N_UCHAR_UBLOCK_GEORGIAN_SUPPLEMENT,										 /**< Georgian Supplement */
	I18N_UCHAR_UBLOCK_GLAGOLITIC,												 /**< Glagolitic */
	I18N_UCHAR_UBLOCK_KHAROSHTHI,												 /**< Kharoshthi */
	I18N_UCHAR_UBLOCK_MODIFIER_TONE_LETTERS,									 /**< Modifier Tone Letters */
	I18N_UCHAR_UBLOCK_NEW_TAI_LUE,												 /**< New Tai Lue */
	I18N_UCHAR_UBLOCK_OLD_PERSIAN,												 /**< Old Persian */
	I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS_SUPPLEMENT,							 /**< Phonetic Extensions Supplement */
	I18N_UCHAR_UBLOCK_SUPPLEMENTAL_PUNCTUATION,									 /**< Supplemental Punctuation */
	I18N_UCHAR_UBLOCK_SYLOTI_NAGRI,												 /**< Syloti Nagri */
	I18N_UCHAR_UBLOCK_TIFINAGH,													 /**< Tifinagh */
	I18N_UCHAR_UBLOCK_VERTICAL_FORMS,											 /**< Vertical Forms */
	I18N_UCHAR_UBLOCK_NKO,														 /**< Nko */
	I18N_UCHAR_UBLOCK_BALINESE,													 /**< Balinese */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_C,											 /**< Latin Extended C */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_D,											 /**< Latin Extended D */
	I18N_UCHAR_UBLOCK_PHAGS_PA,													 /**< Phags Pa */
	I18N_UCHAR_UBLOCK_PHOENICIAN,												 /**< Phoenician */
	I18N_UCHAR_UBLOCK_CUNEIFORM,												 /**< Cuneiform */
	I18N_UCHAR_UBLOCK_CUNEIFORM_NUMBERS_AND_PUNCTUATION,						 /**< Cuneiform Numbers And Punctuation */
	I18N_UCHAR_UBLOCK_COUNTING_ROD_NUMERALS,									 /**< Counting Rod Numerals */
	I18N_UCHAR_UBLOCK_SUNDANESE,												 /**< Sundanese */
	I18N_UCHAR_UBLOCK_LEPCHA,													 /**< Lepcha */
	I18N_UCHAR_UBLOCK_OL_CHIKI,													 /**< Ol Chiki */
	I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_A,										 /**< Cyrillic Extended A */
	I18N_UCHAR_UBLOCK_VAI,														 /**< Vai */
	I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_B,										 /**< Cyrillic Extended B */
	I18N_UCHAR_UBLOCK_SAURASHTRA,												 /**< Saurashtra */
	I18N_UCHAR_UBLOCK_KAYAH_LI,													 /**< Kayah Li */
	I18N_UCHAR_UBLOCK_REJANG,													 /**< Rejang */
	I18N_UCHAR_UBLOCK_CHAM,														 /**< Cham */
	I18N_UCHAR_UBLOCK_ANCIENT_SYMBOLS,											 /**< Ancient Symbols */
	I18N_UCHAR_UBLOCK_PHAISTOS_DISC,											 /**< Phaistos Disc */
	I18N_UCHAR_UBLOCK_LYCIAN,													 /**< Lycian */
	I18N_UCHAR_UBLOCK_CARIAN,													 /**< Carian */
	I18N_UCHAR_UBLOCK_LYDIAN,													 /**< Lydian */
	I18N_UCHAR_UBLOCK_MAHJONG_TILES,											 /**< Mahjong Tiles */
	I18N_UCHAR_UBLOCK_DOMINO_TILES,												 /**< Domino Tiles */
	I18N_UCHAR_UBLOCK_SAMARITAN,												 /**< Samaritan */
	I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,			 /**< Unified Canadian Aboriginal Syllabics Extended */
	I18N_UCHAR_UBLOCK_TAI_THAM,													 /**< Tai Tham */
	I18N_UCHAR_UBLOCK_VEDIC_EXTENSIONS,											 /**< Vedic Extensions */
	I18N_UCHAR_UBLOCK_LISU,														 /**< Lisu */
	I18N_UCHAR_UBLOCK_BAMUM,													 /**< Bamum */
	I18N_UCHAR_UBLOCK_COMMON_INDIC_NUMBER_FORMS,								 /**< Common Indic Number Forms */
	I18N_UCHAR_UBLOCK_DEVANAGARI_EXTENDED,										 /**< Devanagari Extended */
	I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_A,									 /**< Hangul Jamo Extended A */
	I18N_UCHAR_UBLOCK_JAVANESE,													 /**< Javanese */
	I18N_UCHAR_UBLOCK_MYANMAR_EXTENDED_A,										 /**< Myanmar Extended A */
	I18N_UCHAR_UBLOCK_TAI_VIET,													 /**< Tai Viet */
	I18N_UCHAR_UBLOCK_MEETEI_MAYEK,												 /**< Meetei Mayek */
	I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_B,									 /**< Hangul Jamo Extended B */
	I18N_UCHAR_UBLOCK_IMPERIAL_ARAMAIC,											 /**< Imperial Aramaic */
	I18N_UCHAR_UBLOCK_OLD_SOUTH_ARABIAN,										 /**< Old South Arabian */
	I18N_UCHAR_UBLOCK_AVESTAN,													 /**< Avestan */
	I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PARTHIAN,									 /**< Inscriptional Parthian */
	I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PAHLAVI,									 /**< Inscriptional Pahlavi */
	I18N_UCHAR_UBLOCK_OLD_TURKIC,												 /**< Old Turkic */
	I18N_UCHAR_UBLOCK_RUMI_NUMERAL_SYMBOLS,										 /**< Rumi Numeral Symbols */
	I18N_UCHAR_UBLOCK_KAITHI,													 /**< Kaithi */
	I18N_UCHAR_UBLOCK_EGYPTIAN_HIEROGLYPHS,										 /**< Egyptian Hieroglyphs */
	I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT,							 /**< Enclosed Alphanumeric Supplement */
	I18N_UCHAR_UBLOCK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,							 /**< Enclosed Ideographic Supplement */
	I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,						 /**< CJK Unified Ideographs Extension C */
	I18N_UCHAR_UBLOCK_MANDAIC,													 /**< Mandaic */
	I18N_UCHAR_UBLOCK_BATAK,													 /**< Batak */
	I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED_A,										 /**< Ethiopic Extended A */
	I18N_UCHAR_UBLOCK_BRAHMI,													 /**< Brahmi */
	I18N_UCHAR_UBLOCK_BAMUM_SUPPLEMENT,											 /**< Bamum Supplement */
	I18N_UCHAR_UBLOCK_KANA_SUPPLEMENT,											 /**< Kana Supplement */
	I18N_UCHAR_UBLOCK_PLAYING_CARDS,											 /**< Playing Cards */
	I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,					 /**< Miscellaneous Symbols And Pictographs */
	I18N_UCHAR_UBLOCK_EMOTICONS,												 /**< Emoticons */
	I18N_UCHAR_UBLOCK_TRANSPORT_AND_MAP_SYMBOLS,								 /**< Transport And Map Symbols */
	I18N_UCHAR_UBLOCK_ALCHEMICAL_SYMBOLS,										 /**< Alchemical Symbols */
	I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,						 /**< CJK Unified Ideographs Extension D */
	I18N_UCHAR_UBLOCK_BASSA_VAH = 221,											 /**< Bassa Vah (Since 3.0) */
	I18N_UCHAR_UBLOCK_CAUCASIAN_ALBANIAN = 222,									 /**< Caucasian Albanian (Since 3.0) */
	I18N_UCHAR_UBLOCK_COPTIC_EPACT_NUMBERS = 223,								 /**< Coptic Epact Numbers (Since 3.0) */
	I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS_EXTENDED = 224,				 /**< Combining Diacritical Marks Extended (Since 3.0) */
	I18N_UCHAR_UBLOCK_DUPLOYAN = 225,											 /**< Duployan (Since 3.0) */
	I18N_UCHAR_UBLOCK_ELBASAN = 226,											 /**< Elbasan (Since 3.0) */
	I18N_UCHAR_UBLOCK_GEOMETRIC_SHAPES_EXTENDED = 227,							 /**< Geometric Shapes Extended (Since 3.0) */
	I18N_UCHAR_UBLOCK_GRANTHA = 228,											 /**< Grantha (Since 3.0) */
	I18N_UCHAR_UBLOCK_KHOJKI = 229,												 /**< Khojki (Since 3.0) */
	I18N_UCHAR_UBLOCK_KHUDAWADI = 230,											 /**< Khudawadi (Since 3.0) */
	I18N_UCHAR_UBLOCK_LATIN_EXTENDED_E = 231,									 /**< Latin Extended E (Since 3.0) */
	I18N_UCHAR_UBLOCK_LINEAR_A = 232,											 /**< Linear A (Since 3.0) */
	I18N_UCHAR_UBLOCK_MAHAJANI = 233,											 /**< Mahajani (Since 3.0) */
	I18N_UCHAR_UBLOCK_MANICHAEAN = 234,											 /**< Manichaean (Since 3.0) */
	I18N_UCHAR_UBLOCK_MENDE_KIKAKUI = 235,										 /**< Mende Kikakui (Since 3.0) */
	I18N_UCHAR_UBLOCK_MODI = 236,												 /**< Modi (Since 3.0) */
	I18N_UCHAR_UBLOCK_MRO = 237,												 /**< Mro (Since 3.0) */
	I18N_UCHAR_UBLOCK_MYANMAR_EXTENDED_B = 238,									 /**< Myanmar Extended B (Since 3.0) */
	I18N_UCHAR_UBLOCK_NABATAEAN = 239,											 /**< Nabataean (Since 3.0) */
	I18N_UCHAR_UBLOCK_OLD_NORTH_ARABIAN = 240,									 /**< Old North Arabian (Since 3.0) */
	I18N_UCHAR_UBLOCK_OLD_PERMIC = 241,											 /**< Old Permic (Since 3.0) */
	I18N_UCHAR_UBLOCK_ORNAMENTAL_DINGBATS = 242,								 /**< Ornamental Dingbats (Since 3.0) */
	I18N_UCHAR_UBLOCK_PAHAWH_HMONG = 243,										 /**< Pahawh Hmong (Since 3.0) */
	I18N_UCHAR_UBLOCK_PALMYRENE = 244,											 /**< Palmyrene (Since 3.0) */
	I18N_UCHAR_UBLOCK_PAU_CIN_HAU = 245,										 /**< Pau Cin Hau (Since 3.0) */
	I18N_UCHAR_UBLOCK_PSALTER_PAHLAVI = 246,									 /**< Psalter Pahlavi (Since 3.0) */
	I18N_UCHAR_UBLOCK_SHORTHAND_FORMAT_CONTROLS = 247,							 /**< Shorthand Format Controls (Since 3.0) */
	I18N_UCHAR_UBLOCK_SIDDHAM = 248,											 /**< Siddham (Since 3.0) */
	I18N_UCHAR_UBLOCK_SINHALA_ARCHAIC_NUMBERS = 249,							 /**< Sinhala Archaic Numbers (Since 3.0) */
	I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_C = 250,								 /**< Supplemental Arrows C (Since 3.0) */
	I18N_UCHAR_UBLOCK_TIRHUTA = 251,											 /**< Tirhuta (Since 3.0) */
	I18N_UCHAR_UBLOCK_WARANG_CITI = 252,										 /**< Warang Citi (Since 3.0) */
	I18N_UCHAR_UBLOCK_COUNT,													 /**< Count */
	I18N_UCHAR_UBLOCK_INVALID_CODE = -1											 /**< Invalid Code */
} i18n_uchar_ublock_code_e;

/**
 * @brief Enumeration for the language directional property of a character set.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_LEFT_TO_RIGHT,										 /**< L */
	I18N_UCHAR_U_RIGHT_TO_LEFT,										 /**< R */
	I18N_UCHAR_U_EUROPEAN_NUMBER,									 /**< EN */
	I18N_UCHAR_U_EUROPEAN_NUMBER_SEPARATOR,							 /**< ES */
	I18N_UCHAR_U_EUROPEAN_NUMBER_TERMINATOR,						 /**< ET */
	I18N_UCHAR_U_ARABIC_NUMBER,										 /**< AN */
	I18N_UCHAR_U_COMMON_NUMBER_SEPARATOR,							 /**< CS */
	I18N_UCHAR_U_BLOCK_SEPARATOR,									 /**< B */
	I18N_UCHAR_U_SEGMENT_SEPARATOR,									 /**< S */
	I18N_UCHAR_U_WHITE_SPACE_NEUTRAL,								 /**< WS */
	I18N_UCHAR_U_OTHER_NEUTRAL,										 /**< ON */
	I18N_UCHAR_U_LEFT_TO_RIGHT_EMBEDDING,							 /**< LRE */
	I18N_UCHAR_U_LEFT_TO_RIGHT_OVERRIDE,							 /**< LRO */
	I18N_UCHAR_U_RIGHT_TO_LEFT_ARABIC,								 /**< AL */
	I18N_UCHAR_U_RIGHT_TO_LEFT_EMBEDDING,							 /**< RLE */
	I18N_UCHAR_U_RIGHT_TO_LEFT_OVERRIDE,							 /**< RLO */
	I18N_UCHAR_U_POP_DIRECTIONAL_FORMAT,							 /**< PDF */
	I18N_UCHAR_U_DIR_NON_SPACING_MARK,								 /**< NSM */
	I18N_UCHAR_U_BOUNDARY_NEUTRAL,									 /**< BN */
	I18N_UCHAR_U_FIRST_STRONG_ISOLATE,								 /**< FSI (Since 3.0) */
	I18N_UCHAR_U_LEFT_TO_RIGHT_ISOLATE,								 /**< FSI (Since 3.0) */
	I18N_UCHAR_U_RIGHT_TO_LEFT_ISOLATE,								 /**< RLI (Since 3.0) */
	I18N_UCHAR_U_POP_DIRECTIONAL_ISOLATE,							 /**< PDI (Since 3.0) */
	I18N_UCHAR_U_CHAR_DIRECTION_COUNT								 /**< Count */
} i18n_uchar_direction_e;

/**
 * @brief Enumeration for Decomposition Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_DT_NONE,			/**< [none] */
	I18N_UCHAR_U_DT_CANONICAL,		/**< [can] */
	I18N_UCHAR_U_DT_COMPAT,			/**< [com] */
	I18N_UCHAR_U_DT_CIRCLE,			/**< [enc] */
	I18N_UCHAR_U_DT_FINAL,			/**< [fin] */
	I18N_UCHAR_U_DT_FONT,			/**< [font] */
	I18N_UCHAR_U_DT_FRACTION,		/**< [fra] */
	I18N_UCHAR_U_DT_INITIAL,		/**< [init] */
	I18N_UCHAR_U_DT_ISOLATED,		/**< [iso] */
	I18N_UCHAR_U_DT_MEDIAL,			/**< [med] */
	I18N_UCHAR_U_DT_NARROW,			/**< [nar] */
	I18N_UCHAR_U_DT_NOBREAK,		/**< [nb] */
	I18N_UCHAR_U_DT_SMALL,			/**< [sml] */
	I18N_UCHAR_U_DT_SQUARE,			/**< [sqr] */
	I18N_UCHAR_U_DT_SUB,			/**< [sub] */
	I18N_UCHAR_U_DT_SUPER,			/**< [sup] */
	I18N_UCHAR_U_DT_VERTICAL,		/**< [vert] */
	I18N_UCHAR_U_DT_WIDE,			/**< [wide] */
	I18N_UCHAR_U_DT_COUNT			/**< 18 */
} i18n_uchar_u_decomposition_type_e;

/**
 * @brief Enumeration for East Asian Width constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_EA_NEUTRAL,		 /**< [N] */
	I18N_UCHAR_U_EA_AMBIGUOUS,		 /**< [A] */
	I18N_UCHAR_U_EA_HALFWIDTH,		 /**< [H] */
	I18N_UCHAR_U_EA_FULLWIDTH,		 /**< [F] */
	I18N_UCHAR_U_EA_NARROW,			 /**< [Na] */
	I18N_UCHAR_U_EA_WIDE,			 /**< [W] */
	I18N_UCHAR_U_EA_COUNT
} i18n_uchar_u_east_asian_width_e;

/**
 * @brief Enumeration for Unicode general category types.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_UNASSIGNED,						/**< Non-category for unassigned and non-character code points */
	I18N_UCHAR_U_GENERAL_OTHER_TYPES = 0,			/**< Cn "Other, Not Assigned (no characters in [UnicodeData.txt] have this property)" (same as #I18N_UCHAR_U_UNASSIGNED!) */
	I18N_UCHAR_U_UPPERCASE_LETTER,					/**< Lu */
	I18N_UCHAR_U_LOWERCASE_LETTER,					/**< Ll */
	I18N_UCHAR_U_TITLECASE_LETTER,					/**< Lt */
	I18N_UCHAR_U_MODIFIER_LETTER,					/**< Lm */
	I18N_UCHAR_U_OTHER_LETTER,						/**< Lo */
	I18N_UCHAR_U_NON_SPACING_MARK,					/**< Mn */
	I18N_UCHAR_U_ENCLOSING_MARK,					/**< Me */
	I18N_UCHAR_U_COMBINING_SPACING_MARK,			/**< Mc */
	I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER,				/**< Nd */
	I18N_UCHAR_U_LETTER_NUMBER,						/**< Nl */
	I18N_UCHAR_U_OTHER_NUMBER,						/**< No */
	I18N_UCHAR_U_SPACE_SEPARATOR,					/**< Zs */
	I18N_UCHAR_U_LINE_SEPARATOR,					/**< Zl */
	I18N_UCHAR_U_PARAGRAPH_SEPARATOR,				/**< Zp */
	I18N_UCHAR_U_CONTROL_CHAR,						/**< Cc */
	I18N_UCHAR_U_FORMAT_CHAR,						/**< Cf */
	I18N_UCHAR_U_PRIVATE_USE_CHAR,					/**< Co */
	I18N_UCHAR_U_SURROGATE,							/**< Cs */
	I18N_UCHAR_U_DASH_PUNCTUATION,					/**< Pd */
	I18N_UCHAR_U_START_PUNCTUATION,					/**< Ps */
	I18N_UCHAR_U_END_PUNCTUATION,					/**< Pe */
	I18N_UCHAR_U_CONNECTOR_PUNCTUATION,				/**< Pc */
	I18N_UCHAR_U_OTHER_PUNCTUATION,					/**< Po */
	I18N_UCHAR_U_MATH_SYMBOL,						/**< Sm */
	I18N_UCHAR_U_CURRENCY_SYMBOL,					/**< Sc */
	I18N_UCHAR_U_MODIFIER_SYMBOL,					/**< Sk */
	I18N_UCHAR_U_OTHER_SYMBOL,						/**< So */
	I18N_UCHAR_U_INITIAL_PUNCTUATION,				/**< Pi */
	I18N_UCHAR_U_FINAL_PUNCTUATION,					/**< Pf */
	I18N_UCHAR_U_CHAR_CATEGORY_COUNT				/**< One higher than the last enum #i18n_uchar_category_e constant */
} i18n_uchar_category_e;

/**
 * @brief Enumeration for Joining Group constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_JG_NO_JOINING_GROUP,											   /**< No Joining Group */
	I18N_UCHAR_U_JG_AIN,														   /**< Ain */
	I18N_UCHAR_U_JG_ALAPH,														   /**< Alaph */
	I18N_UCHAR_U_JG_ALEF,														   /**< Alef */
	I18N_UCHAR_U_JG_BEH,														   /**< Beh */
	I18N_UCHAR_U_JG_BETH,														   /**< Beth */
	I18N_UCHAR_U_JG_DAL,														   /**< Dal */
	I18N_UCHAR_U_JG_DALATH_RISH,												   /**< Dalath Rish */
	I18N_UCHAR_U_JG_E,															   /**< E */
	I18N_UCHAR_U_JG_FEH,														   /**< Feh */
	I18N_UCHAR_U_JG_FINAL_SEMKATH,												   /**< Final Semkath */
	I18N_UCHAR_U_JG_GAF,														   /**< Gaf */
	I18N_UCHAR_U_JG_GAMAL,														   /**< Gamal */
	I18N_UCHAR_U_JG_HAH,														   /**< Hah */
	I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,											   /**< Teh Marbuta Goal */
	I18N_UCHAR_U_JG_HAMZA_ON_HEH_GOAL = I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,		   /**< Hamza On Heh Goal */
	I18N_UCHAR_U_JG_HE,															   /**< He */
	I18N_UCHAR_U_JG_HEH,														   /**< Heh */
	I18N_UCHAR_U_JG_HEH_GOAL,													   /**< Heh Goal */
	I18N_UCHAR_U_JG_HETH,														   /**< Heth */
	I18N_UCHAR_U_JG_KAF,														   /**< Kaf */
	I18N_UCHAR_U_JG_KAPH,														   /**< Kaph */
	I18N_UCHAR_U_JG_KNOTTED_HEH,												   /**< Knotted Heh */
	I18N_UCHAR_U_JG_LAM,														   /**< Lam */
	I18N_UCHAR_U_JG_LAMADH,														   /**< Lamadh */
	I18N_UCHAR_U_JG_MEEM,														   /**< Meem */
	I18N_UCHAR_U_JG_MIM,														   /**< Mim */
	I18N_UCHAR_U_JG_NOON,														   /**< Noon */
	I18N_UCHAR_U_JG_NUN,														   /**< Nun */
	I18N_UCHAR_U_JG_PE,															   /**< Pe */
	I18N_UCHAR_U_JG_QAF,														   /**< Qaf */
	I18N_UCHAR_U_JG_QAPH,														   /**< Qaph */
	I18N_UCHAR_U_JG_REH,														   /**< Reh */
	I18N_UCHAR_U_JG_REVERSED_PE,												   /**< Reversed Pe */
	I18N_UCHAR_U_JG_SAD,														   /**< Sad */
	I18N_UCHAR_U_JG_SADHE,														   /**< Sadhe */
	I18N_UCHAR_U_JG_SEEN,														   /**< Seen */
	I18N_UCHAR_U_JG_SEMKATH,													   /**< Semkath */
	I18N_UCHAR_U_JG_SHIN,														   /**< Shin */
	I18N_UCHAR_U_JG_SWASH_KAF,													   /**< Swash Kaf */
	I18N_UCHAR_U_JG_SYRIAC_WAW,													   /**< Syriac Waw */
	I18N_UCHAR_U_JG_TAH,														   /**< Tah */
	I18N_UCHAR_U_JG_TAW,														   /**< Taw */
	I18N_UCHAR_U_JG_TEH_MARBUTA,												   /**< Teh Marbuta */
	I18N_UCHAR_U_JG_TETH,														   /**< Teth */
	I18N_UCHAR_U_JG_WAW,														   /**< Waw */
	I18N_UCHAR_U_JG_YEH,														   /**< Yeh */
	I18N_UCHAR_U_JG_YEH_BARREE,													   /**< Yeh Barree */
	I18N_UCHAR_U_JG_YEH_WITH_TAIL,												   /**< Yeh With Tail */
	I18N_UCHAR_U_JG_YUDH,														   /**< Yudh */
	I18N_UCHAR_U_JG_YUDH_HE,													   /**< Yudh He */
	I18N_UCHAR_U_JG_ZAIN,														   /**< Zain */
	I18N_UCHAR_U_JG_FE,															   /**< Fe */
	I18N_UCHAR_U_JG_KHAPH,														   /**< Khaph */
	I18N_UCHAR_U_JG_ZHAIN,														   /**< Zhain */
	I18N_UCHAR_U_JG_BURUSHASKI_YEH_BARREE,										   /**< Burushaski Yeh Barree */
	I18N_UCHAR_U_JG_FARSI_YEH,													   /**< Farsi Yeh */
	I18N_UCHAR_U_JG_NYA,														   /**< Nya */
	I18N_UCHAR_U_JG_ROHINGYA_YEH,												   /**< Rohingya Yeh */
	I18N_UCHAR_U_JG_MANICHAEAN_ALEPH,											   /**< Manichaean Aleph (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_AYIN,											   /**< Manichaean Ayin (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_BETH,											   /**< Manichaean Beth (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_DALETH,											   /**< Manichaean Daleth (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_DHAMEDH,											   /**< Manichaean Dhamedh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_FIVE,											   /**< Manichaean Five (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_GIMEL,											   /**< Manichaean Gimel (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_HETH,											   /**< Manichaean Heth (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_HUNDRED,											   /**< Manichaean Hundred (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_KAPH,											   /**< Manichaean Kaph (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_LAMEDH,											   /**< Manichaean Lamedh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_MEM,												   /**< Manichaean Mem (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_NUN,												   /**< Manichaean Nun (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_ONE,												   /**< Manichaean One (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_PE,												   /**< Manichaean Pe (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_QOPH,											   /**< Manichaean Qoph (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_RESH,											   /**< Manichaean Resh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_SADHE,											   /**< Manichaean Sadhe (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_SAMEKH,											   /**< Manichaean Samekh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_TAW,												   /**< Manichaean Taw (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_TEN,												   /**< Manichaean Ten (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_TETH,											   /**< Manichaean Teth (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_THAMEDH,											   /**< Manichaean Thamedh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_TWENTY,											   /**< Manichaean Twenty (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_WAW,												   /**< Manichaean Waw (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_YODH,											   /**< Manichaean Yodh (Since 3.0) */
	I18N_UCHAR_U_JG_MANICHAEAN_ZAYIN,											   /**< Manichaean Zayin (Since 3.0) */
	I18N_UCHAR_U_JG_STRAIGHT_WAW,												   /**< Manichaean Waw (Since 3.0) */
	I18N_UCHAR_U_JG_COUNT														   /**< Count */
} i18n_uchar_u_joining_group_e;

/**
 * @brief Enumeration for Joining Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_JT_NON_JOINING,		/**< [U] */
	I18N_UCHAR_U_JT_JOIN_CAUSING,		/**< [C] */
	I18N_UCHAR_U_JT_DUAL_JOINING,		/**< [D] */
	I18N_UCHAR_U_JT_LEFT_JOINING,		/**< [L] */
	I18N_UCHAR_U_JT_RIGHT_JOINING,		/**< [R] */
	I18N_UCHAR_U_JT_TRANSPARENT,		/**< [T] */
	I18N_UCHAR_U_JT_COUNT				/**< 6 */
} i18n_uchar_u_joining_type_e;

/**
 * @brief Enumeration for Line Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_LB_UNKNOWN,														 /**< [XX] */
	I18N_UCHAR_U_LB_AMBIGUOUS,														 /**< [AI] */
	I18N_UCHAR_U_LB_ALPHABETIC,														 /**< [AL] */
	I18N_UCHAR_U_LB_BREAK_BOTH,														 /**< [B2] */
	I18N_UCHAR_U_LB_BREAK_AFTER,													 /**< [BA] */
	I18N_UCHAR_U_LB_BREAK_BEFORE,													 /**< [BB] */
	I18N_UCHAR_U_LB_MANDATORY_BREAK,												 /**< [BK] */
	I18N_UCHAR_U_LB_CONTINGENT_BREAK,												 /**< [CB] */
	I18N_UCHAR_U_LB_CLOSE_PUNCTUATION,												 /**< [CL] */
	I18N_UCHAR_U_LB_COMBINING_MARK,													 /**< [CM] */
	I18N_UCHAR_U_LB_CARRIAGE_RETURN,												 /**< [CR] */
	I18N_UCHAR_U_LB_EXCLAMATION,													 /**< [EX] */
	I18N_UCHAR_U_LB_GLUE,															 /**< [GL] */
	I18N_UCHAR_U_LB_HYPHEN,															 /**< [HY] */
	I18N_UCHAR_U_LB_IDEOGRAPHIC,													 /**< [ID] */
	I18N_UCHAR_U_LB_INSEPARABLE,													 /**< [IN] */
	I18N_UCHAR_U_LB_INSEPERABLE = I18N_UCHAR_U_LB_INSEPARABLE,
	I18N_UCHAR_U_LB_INFIX_NUMERIC,													 /**< [IS] */
	I18N_UCHAR_U_LB_LINE_FEED,														 /**< [LF] */
	I18N_UCHAR_U_LB_NONSTARTER,														 /**< [NS] */
	I18N_UCHAR_U_LB_NUMERIC,														 /**< [NU] */
	I18N_UCHAR_U_LB_OPEN_PUNCTUATION,												 /**< [OP] */
	I18N_UCHAR_U_LB_POSTFIX_NUMERIC,												 /**< [PO] */
	I18N_UCHAR_U_LB_PREFIX_NUMERIC,													 /**< [PR] */
	I18N_UCHAR_U_LB_QUOTATION,														 /**< [QU] */
	I18N_UCHAR_U_LB_COMPLEX_CONTEXT,												 /**< [SA] */
	I18N_UCHAR_U_LB_SURROGATE,														 /**< [SG] */
	I18N_UCHAR_U_LB_SPACE,															 /**< [SP] */
	I18N_UCHAR_U_LB_BREAK_SYMBOLS,													 /**< [SY] */
	I18N_UCHAR_U_LB_ZWSPACE,														 /**< [ZW] */
	I18N_UCHAR_U_LB_NEXT_LINE,														 /**< [NL] */
	I18N_UCHAR_U_LB_WORD_JOINER,													 /**< [WJ] */
	I18N_UCHAR_U_LB_H2,																 /**< [H2] */
	I18N_UCHAR_U_LB_H3,																 /**< [H3] */
	I18N_UCHAR_U_LB_JL,																 /**< [JL] */
	I18N_UCHAR_U_LB_JT,																 /**< [JT] */
	I18N_UCHAR_U_LB_JV,																 /**< [JV] */
	I18N_UCHAR_U_LB_CLOSE_PARENTHESIS,												 /**< [CP] */
	I18N_UCHAR_U_LB_COUNT
} i18n_uchar_u_line_break_e;

/**
 * @brief Enumeration for Numeric Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_NT_NONE,		  /**< [None] */
	I18N_UCHAR_U_NT_DECIMAL,	  /**< [de] */
	I18N_UCHAR_U_NT_DIGIT,		  /**< [di] */
	I18N_UCHAR_U_NT_NUMERIC,	  /**< [nu] */
	I18N_UCHAR_U_NT_COUNT		  /**<	*/
} i18n_uchar_u_numeric_type_e;

/**
 * @brief Enumeration for Hangul Syllable Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_HST_NOT_APPLICABLE,	 /**< [NA] */
	I18N_UCHAR_U_HST_LEADING_JAMO,		 /**< [L] */
	I18N_UCHAR_U_HST_VOWEL_JAMO,		 /**< [V] */
	I18N_UCHAR_U_HST_TRAILING_JAMO,		 /**< [T] */
	I18N_UCHAR_U_HST_LV_SYLLABLE,		 /**< [LV] */
	I18N_UCHAR_U_HST_LVT_SYLLABLE,		 /**< [LVT] */
	I18N_UCHAR_U_HST_COUNT				 /**<  */
} i18n_uchar_u_hangul_syllable_type_e;

/**
 * @brief Enumeration for Sentence Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_SB_OTHER,		   /**< [XX] */
	I18N_UCHAR_U_SB_ATERM,		   /**< [AT] */
	I18N_UCHAR_U_SB_CLOSE,		   /**< [CL] */
	I18N_UCHAR_U_SB_FORMAT,		   /**< [FO] */
	I18N_UCHAR_U_SB_LOWER,		   /**< [LO] */
	I18N_UCHAR_U_SB_NUMERIC,	   /**< [NU] */
	I18N_UCHAR_U_SB_OLETTER,	   /**< [LE] */
	I18N_UCHAR_U_SB_SEP,		   /**< [SE] */
	I18N_UCHAR_U_SB_SP,			   /**< [SP] */
	I18N_UCHAR_U_SB_STERM,		   /**< [ST] */
	I18N_UCHAR_U_SB_UPPER,		   /**< [UP] */
	I18N_UCHAR_U_SB_CR,			   /**< [CR] */
	I18N_UCHAR_U_SB_EXTEND,		   /**< [EX] */
	I18N_UCHAR_U_SB_LF,			   /**< [LF] */
	I18N_UCHAR_U_SB_SCONTINUE,	   /**< [SC] */
	I18N_UCHAR_U_SB_COUNT		   /**<	 */
} i18n_uchar_u_sentence_break_e;

/**
 * @brief Enumeration for Word Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_WB_OTHER,				/**< [XX] */
	I18N_UCHAR_U_WB_ALETTER,			/**< [LE] */
	I18N_UCHAR_U_WB_FORMAT,				/**< [FO] */
	I18N_UCHAR_U_WB_KATAKANA,			/**< [KA] */
	I18N_UCHAR_U_WB_MIDLETTER,			/**< [ML] */
	I18N_UCHAR_U_WB_MIDNUM,				/**< [MN] */
	I18N_UCHAR_U_WB_NUMERIC,			/**< [NU] */
	I18N_UCHAR_U_WB_EXTENDNUMLET,		/**< [EX] */
	I18N_UCHAR_U_WB_CR,					/**< [CR] */
	I18N_UCHAR_U_WB_EXTEND,				/**< [Extend] */
	I18N_UCHAR_U_WB_LF,					/**< [LF] */
	I18N_UCHAR_U_WB_MIDNUMLET,			/**< [MB] */
	I18N_UCHAR_U_WB_NEWLINE,			/**< [NL] */
	I18N_UCHAR_U_WB_REGIONAL_INDICATOR, /**< [RI] (Since 3.0) */
	I18N_UCHAR_U_WB_HEBREW_LETTER,		/**< [HL] (Since 3.0) */
	I18N_UCHAR_U_WB_SINGLE_QUOTE,		/**< [SQ] (Since 3.0) */
	I18N_UCHAR_U_WB_DOUBLE_QUOTE,		/**< [DQ] (Since 3.0) */
	I18N_UCHAR_U_WB_COUNT				/**<  */
} i18n_uchar_u_word_break_values_e;

/**
 * @brief Enumeration for Grapheme Cluster Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCHAR_U_GCB_OTHER,					   /**< [XX] */
	I18N_UCHAR_U_GCB_CONTROL,				   /**< [CN] */
	I18N_UCHAR_U_GCB_CR,					   /**< [CR] */
	I18N_UCHAR_U_GCB_EXTEND,				   /**< [EX] */
	I18N_UCHAR_U_GCB_L,						   /**< [L] */
	I18N_UCHAR_U_GCB_LF,					   /**< [LF] */
	I18N_UCHAR_U_GCB_LV,					   /**< [LV] */
	I18N_UCHAR_U_GCB_LVT,					   /**< [LVT] */
	I18N_UCHAR_U_GCB_T,						   /**< [T] */
	I18N_UCHAR_U_GCB_V,						   /**< [V] */
	I18N_UCHAR_U_GCB_SPACING_MARK,			   /**< [SM] */
	I18N_UCHAR_U_GCB_PREPEND,				   /**< [PP] */
	I18N_UCHAR_UCHAR_U_GCB_COUNT			   /**<	 */
} i18n_uchar_u_grapheme_cluster_break_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE
 * @{
 */

/**
 * @brief Structure representing a collator object instance.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_ucollator_h;

/**
 * @brief Enumeration for attributes that collation service understands.
 *		  All the attributes can take #I18N_UCOLLATOR_DEFAULT value, as well as the values specific to each one.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCOLLATOR_FRENCH_COLLATION,											/**< Attribute for direction of secondary weights - used in Canadian French. Acceptable values are #I18N_UCOLLATOR_ON, which results in secondary weights being considered backwards, and #I18N_UCOLLATOR_OFF which treats secondary weights in the order they appear */
	I18N_UCOLLATOR_ALTERNATE_HANDLING,											/**< Attribute for handling variable elements. Acceptable values are #I18N_UCOLLATOR_NON_IGNORABLE (default) which treats all the codepoints with non-ignorable primary weights in the same way, and #I18N_UCOLLATOR_SHIFTED which causes codepoints with primary weights that are equal or below the variable top value to be ignored at the primary level and moved to the quaternary level */
	I18N_UCOLLATOR_CASE_FIRST,													/**< Controls the ordering of upper and lower case letters. Acceptable values are #I18N_UCOLLATOR_OFF (default), which orders upper and lower case letters in accordance to their tertiary weights, #I18N_UCOLLATOR_UPPER_FIRST which forces upper case letters to sort before lower case letters, and #I18N_UCOLLATOR_LOWER_FIRST which does the opposite */
	I18N_UCOLLATOR_CASE_LEVEL,													/**< Controls whether an extra case level (positioned before the third level) is generated or not. Acceptable values are #I18N_UCOLLATOR_OFF (default), when case level is not generated, and #I18N_UCOLLATOR_ON which causes the case level to be generated. Contents of the case level are affected by the value of the #I18N_UCOLLATOR_CASE_FIRST attribute. A simple way to ignore accent differences in a string is to set the strength to #I18N_UCOLLATOR_PRIMARY and enable case level */
	I18N_UCOLLATOR_NORMALIZATION_MODE,											/**< Controls whether the normalization check and necessary normalizations are performed. When set to #I18N_UCOLLATOR_OFF (default) no normalization check is performed. The correctness of the result is guaranteed only if the input data is in so-called FCD form (see users manual for more info). When set to #I18N_UCOLLATOR_ON, an incremental check is performed to see whether the input data is in the FCD form. If the data is not in the FCD form, incremental NFD normalization is performed */
	I18N_UCOLLATOR_DECOMPOSITION_MODE = I18N_UCOLLATOR_NORMALIZATION_MODE,		/**< An alias for the #I18N_UCOLLATOR_NORMALIZATION_MODE attribute */
	I18N_UCOLLATOR_STRENGTH,													/**< The strength attribute. Can be either #I18N_UCOLLATOR_PRIMARY, #I18N_UCOLLATOR_SECONDARY, #I18N_UCOLLATOR_TERTIARY, #I18N_UCOLLATOR_QUATERNARY, or #I18N_UCOLLATOR_IDENTICAL. The usual strength for most locales (except Japanese) is tertiary. Quaternary strength is useful when combined with shifted setting for the alternate handling attribute and for JIS X 4061 collation, when it is used to distinguish between Katakana and Hiragana. Otherwise, quaternary level is affected only by the number of non-ignorable code points in the string. Identical strength is rarely useful, as it amounts to codepoints of the NFD form of the string */
	I18N_UCOLLATOR_NUMERIC_COLLATION = I18N_UCOLLATOR_STRENGTH + 2,				/**< When turned on, this attribute makes substrings of digits that are sort according to their numeric values. This is a way to get '100' to sort AFTER '2'. Note that the longest digit substring that can be treated as a single unit is 254 digits (not counting leading zeros). If a digit substring is longer than that, the digits beyond the limit will be treated as a separate digit substring. A "digit" in this sense is a code point with General_Category=Nd, which does not include circled numbers, roman numerals, and so on. Only a contiguous digit substring is considered, that is, non-negative integers without separators. There is no support for plus/minus signs, decimals, exponents, and so on */
	I18N_UCOLLATOR_ATTRIBUTE_COUNT												/**< The number of i18n_ucollator_attribute_e constants */
} i18n_ucollator_attribute_e;

/**
 * @brief Enumeration containing attribute values for controlling collation behavior.
 *		  Here are all the allowable values. Not every attribute can take every value.
 *		  The only universal value is #I18N_UCOLLATOR_DEFAULT, which resets the attribute value to the predefined value for that locale.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCOLLATOR_DEFAULT			 = -1,							/**< Accepted by most attributes */
	I18N_UCOLLATOR_PRIMARY			 = 0,							/**< Primary collation strength */
	I18N_UCOLLATOR_SECONDARY		 = 1,							/**< Secondary collation strength */
	I18N_UCOLLATOR_TERTIARY			 = 2,							/**< Tertiary collation strength */
	I18N_UCOLLATOR_DEFAULT_STRENGTH	 = I18N_UCOLLATOR_TERTIARY,		/**< Default collation strength */
	I18N_UCOLLATOR_CE_STRENGTH_LIMIT,
	I18N_UCOLLATOR_QUATERNARY		 = 3,							/**< Quaternary collation strength */
	I18N_UCOLLATOR_IDENTICAL		 = 15,							/**< Identical collation strength */
	I18N_UCOLLATOR_STRENGTH_LIMIT,

	I18N_UCOLLATOR_OFF				 = 16,							/**< Turn the feature off - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */
	I18N_UCOLLATOR_ON				 = 17,							/**< Turn the feature on - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */

	I18N_UCOLLATOR_SHIFTED			 = 20,							/**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be shifted. */
	I18N_UCOLLATOR_NON_IGNORABLE	 = 21,							/**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be non ignorable. */
	I18N_UCOLLATOR_LOWER_FIRST		 = 24,							/**< Valid for #I18N_UCOLLATOR_CASE_FIRST - lower case sorts before upper case. */
	I18N_UCOLLATOR_UPPER_FIRST		 = 25,							/**< Upper case sorts before lower case. */
	I18N_UCOLLATOR_ATTRIBUTE_VALUE_COUNT
} i18n_ucollator_attribute_value_e;

/**
 * @brief Enumeration in which the base letter represents a primary difference. Set comparison level to #I18N_UCOLLATOR_PRIMARY to ignore secondary and tertiary differences. Use this to set the strength of an #i18n_ucollator_h. Example of primary difference, "abc" < "abd"
 *		  Diacritical differences on the same base letter represent a secondary difference. Set comparison level to #I18N_UCOLLATOR_SECONDARY to ignore tertiary differences. Use this to set the strength of an #i18n_ucollator_h. Example of secondary difference, "&auml;" >> "a".
 *		  Uppercase and lowercase versions of the same character represent a tertiary difference. Set comparison level to #I18N_UCOLLATOR_TERTIARY to include all comparison differences. Use this to set the strength of an #i18n_ucollator_h. Example of tertiary difference, "abc" <<< "ABC".
 *		  Two characters are considered "identical" when they have the same unicode spellings. #I18N_UCOLLATOR_IDENTICAL. For example, "&auml;" == "&auml;".
 *		  #i18n_ucollator_strength_e is also used to determine the strength of sort keys generated from #i18n_ucollator_h. These values can now be found in the #i18n_ucollator_attribute_value_e enum.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef i18n_ucollator_attribute_value_e i18n_ucollator_strength_e;

/**
 * @brief Enumeration for source and target string comparison result.
 *		  #I18N_UCOLLATOR_LESS is returned if the source string is compared to be less than the target string in the {@link i18n_ucollator_str_collator() } method.
 *		  #I18N_UCOLLATOR_EQUAL is returned if the source string is compared to be equal to the target string in the {@link i18n_ucollator_str_collator() } method.
 *		  #I18N_UCOLLATOR_GREATER is returned if the source string is compared to be greater than the target string in the {@link #i18n_ucollator_str_collator() } method.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCOLLATOR_EQUAL	 = 0,	 /**< string a == string b */
	I18N_UCOLLATOR_GREATER	 = 1,	 /**< string a > string b */
	I18N_UCOLLATOR_LESS		 = -1	 /**< string a < string b */
} i18n_ucollator_result_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE
 * @{
 */


/**
 * @brief i18n_unormalizer_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */

typedef const void *i18n_unormalizer_h;

/**
 * @brief Enumeration of constants for normalization modes.
 *		  For details about standard Unicode normalization forms and about the algorithms which are also used with custom mapping tables see http://www.unicode.org/unicode/reports/tr15/
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UNORMALIZATION_COMPOSE,			  /**< Decomposition followed by composition. Same as standard NFC when using an "nfc" instance. Same as standard NFKC when using an "nfkc" instance.
												   For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
	I18N_UNORMALIZATION_DECOMPOSE,			  /**< Map and reorder canonically. Same as standard NFD when using an "nfc" instance. Same as standard NFKD when using an "nfkc" instance.
												   For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
	I18N_UNORMALIZATION_FCD,				  /**< "Fast C or D" form. If a string is in this form, then further decomposition without reordering would yield the same form as DECOMPOSE.
												   Text in "Fast C or D" form can be processed efficiently with data tables that are "canonically closed",
												   that is, that provide equivalent data for equivalent text, without having to be fully normalized.
												   Not a standard Unicode normalization form. Not a unique form: Different FCD strings can be canonically equivalent.
												   For details see http://www.unicode.org/notes/tn5/#FCD  */
	I18N_UNORMALIZATION_COMPOSE_CONTIGUOUS	  /**< Compose only contiguously. Also known as "FCC" or "Fast C Contiguous". The result will often but not always be in NFC.
												   The result will conform to FCD which is useful for processing. Not a standard Unicode normalization form.
												   For details see http://www.unicode.org/notes/tn5/#FCC  */
} i18n_unormalization_mode_e;

/**
 * @brief Result values for normalization quick check functions.
 *
 * @since_tizen 2.4
 */
typedef enum {
	I18N_UNORMALIZATION_NO,		/**< The input string is not in the normalization form. */
	I18N_UNORMALIZATION_YES,	/**< The input string is in the normalization form. */
	I18N_UNORMALIZATION_MAYBE	/**< The input string may or may not be in the normalization form. */
} i18n_unormalization_check_result_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USEARCH_MODULE
 * @{
 */

/**
 * @brief i18n_usearch_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_usearch_h;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE
 * @{
 */

/**
 * @brief i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_ucalendar_h;

/**
 * @brief The time zone ID reserved for unknown time zone.
 * @since_tizen 2.3.1
 */
#define I18N_UCALENDAR_UNKNOWN_ZONE_ID "Etc/Unknown"

/**
 * @brief Enumeration for possible fields in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_ERA,									/**< Field number indicating the era, e.g., AD or BC in the Gregorian (Julian) calendar */
	I18N_UCALENDAR_YEAR,								/**< Field number indicating the year */
	I18N_UCALENDAR_MONTH,								/**< Field number indicating the month. This is a calendar-specific value. \n The first month of the year is JANUARY;
															 the last depends on the number of months in a year */
	I18N_UCALENDAR_WEEK_OF_YEAR,						/**< Field number indicating the week number within the current year. \n
															 The first week of the year, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1.
															 Subclasses define the value of #I18N_UCALENDAR_WEEK_OF_YEAR for days before the first week of the year */
	I18N_UCALENDAR_WEEK_OF_MONTH,						/**< Field number indicating the week number within the current month. \n
															 The first week of the month, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1.
															 Subclasses define the value of WEEK_OF_MONTH for days before the first week of the month */
	I18N_UCALENDAR_DATE,								/**< Field number indicating the day of the month.	\n This is a synonym for DAY_OF_MONTH. The first day of the month has value 1  */
	I18N_UCALENDAR_DAY_OF_YEAR,							/**< Field number indicating the day number within the current year. \n The first day of the year has value 1. */
	I18N_UCALENDAR_DAY_OF_WEEK,							/**< Field number indicating the day of the week.	\n
															 This field takes values "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", and "Saturday" */
	I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH,				/**< Field number indicating the ordinal number of the day of the week within the current month.  \n
															 Together with the "day of week" field, this uniquely specifies a day within a month.
															 "day of month" 1 through 7 always correspond to "day of week in month" 1; 8 through 15 correspond to "day of week in month" 2, and so on.
															 "day of week in month" 0 indicates the week before "day of week in month" 1.
															 Negative values count back from the end of the month, so the last Sunday of a month is specified as "day of week" = "Sunday",
															 "day of week in month" = -1. Because negative values count backward they will usually be aligned differently within the month than positive values.
															 For example, if a month has 31 days, "day of week in month" -1 will overlap "day of week in month" 5 and the end of 4 */
	I18N_UCALENDAR_AM_PM,								/**< Field number indicating whether the "hour" is before or after noon.  \n E.g., at 10:04:15.250 PM the AM_PM is PM */
	I18N_UCALENDAR_HOUR,								/**< Field number indicating the hour of the morning or afternoon.	\n "hour" is used for the 12-hour clock. E.g., at 10:04:15.250 PM the "Hour" is 10 */
	I18N_UCALENDAR_HOUR_OF_DAY,							/**< Field number indicating the hour of the day.  \n "Hour of day" is used for the 24-hour clock. E.g., at 10:04:15.250 PM the "Hour of day" is 22 */
	I18N_UCALENDAR_MINUTE,								/**< Field number indicating the minute within the hour.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MINUTE is 4 */
	I18N_UCALENDAR_SECOND,								/**< Field number indicating the second within the minute.	\n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_SECOND is 15 */
	I18N_UCALENDAR_MILLISECOND,							/**< Field number indicating the millisecond within the second.	 \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MILLISECOND is 250 */
	I18N_UCALENDAR_ZONE_OFFSET,							/**< Field number indicating the raw offset from GMT in milliseconds  */
	I18N_UCALENDAR_DST_OFFSET,							/**< Field number indicating the daylight savings offset in milliseconds  */
	I18N_UCALENDAR_YEAR_WOY,							/**< Field number indicating the extended year corresponding to the #I18N_UCALENDAR_WEEK_OF_YEAR field. \n
															 This may be one greater or less than the value of #I18N_UCALENDAR_EXTENDED_YEAR */
	I18N_UCALENDAR_DOW_LOCAL,							/**< Field number indicating the localized day of the week. \n
															 This will be a value from 1 to 7 inclusive, with 1 being the localized first day of the week */
	I18N_UCALENDAR_EXTENDED_YEAR,						/**< Year of this calendar system, encompassing all supra-year fields. \n
															 For example, in Gregorian/Julian calendars, positive Extended Year values indicate years AD, 1 BC = 0 extended, 2 BC = -1 extended, and so on */
	I18N_UCALENDAR_JULIAN_DAY,							/**< Field number indicating the modified Julian day number. \n
															 This is different from the conventional Julian day number in two regards.
															 First, it demarcates days at local zone midnight, rather than noon GMT. Second, it is a local number; that is, it depends on the local time zone.
															 It can be thought of as a single number that encompasses all the date-related fields */
	I18N_UCALENDAR_MILLISECONDS_IN_DAY,					/**< Ranges from 0 to 23:59:59.999 (regardless of DST). \n
															 This field behaves exactly like a composite of all time-related fields, not including the zone fields.
															 As such, it also reflects discontinuities in those fields on DST transition days. On a day of DST onset, it will jump forward.
															 On a day of DST cessation, it will jump backward.
															 This reflects the fact that it must be combined with the DST offset field to obtain a unique local time value */
	I18N_UCALENDAR_IS_LEAP_MONTH,						/**< Whether or not the current month is a leap month (0 or 1) */
	I18N_UCALENDAR_FIELD_COUNT,							/**< Number of enumerators */
	I18N_UCALENDAR_DAY_OF_MONTH = I18N_UCALENDAR_DATE	/**< Field number indicating the day of the month.	\n This is a synonym for #I18N_UCALENDAR_DATE. The first day of the month has value 1 */
} i18n_ucalendar_date_fields_e;

/**
 * @brief Enumeration for possible months in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_TRADITIONAL,								/**< Despite the name, #I18N_UCALENDAR_TRADITIONAL designates the locale's default calendar, which may be the Gregorian calendar or some other calendar */
	I18N_UCALENDAR_DEFAULT = I18N_UCALENDAR_TRADITIONAL,	/**< A better name for #I18N_UCALENDAR_TRADITIONAL	*/
	I18N_UCALENDAR_GREGORIAN								/**< Unambiguously designates the Gregorian calendar for the locale */
} i18n_ucalendar_type_e;

/**
 * @brief Enumeration for possible months in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_JANUARY,			/**< January */
	I18N_UCALENDAR_FEBRUARY,		/**< February */
	I18N_UCALENDAR_MARCH,			/**< March */
	I18N_UCALENDAR_APRIL,			/**< April */
	I18N_UCALENDAR_MAY,				/**< May */
	I18N_UCALENDAR_JUNE,			/**< June */
	I18N_UCALENDAR_JULY,			/**< July */
	I18N_UCALENDAR_AUGUST,			/**< August */
	I18N_UCALENDAR_SEPTEMBER,		/**< September */
	I18N_UCALENDAR_OCTOBER,			/**< October */
	I18N_UCALENDAR_NOVEMBER,		/**< November */
	I18N_UCALENDAR_DECEMBER			/**< December */
} i18n_ucalendar_months_e;

/**
 * @brief Enumeration for possible formats of an #i18n_ucalendar_h's display name.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_STANDARD,		  /**< Standard display name */
	I18N_UCALENDAR_SHORT_STANDARD,	  /**< Short standard display name */
	I18N_UCALENDAR_DST,				  /**< Daylight savings display name */
	I18N_UCALENDAR_SHORT_DST		  /**< Short daylight savings display name */
} i18n_ucalendar_displayname_type_e;

/**
 * @brief Enumeration for types of #i18n_ucalendar_h attributes.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_LENIENT,						  /**< Lenient parsing */
	I18N_UCALENDAR_FIRST_DAY_OF_WEEK,			  /**< First day of the week */
	I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK	  /**< Minimum number of days in the first week */
} i18n_ucalendar_attribute_e;

/**
 * @brief System time zone type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UCALENDAR_ZONE_TYPE_ANY,					/**< Any system zones. */
	I18N_UCALENDAR_ZONE_TYPE_CANONICAL,				/**< Canonical system zones. */
	I18N_UCALENDAR_ZONE_TYPE_CANONICAL_LOCATION		/**< Canonical system zones associated with actual locations. */
} i18n_system_timezone_type_e;

/**
 * @brief Possible limit values for an #i18n_ucalendar_h.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UCALENDAR_MINIMUM,				/**< Minimum value */
	I18N_UCALENDAR_MAXIMUM,				/**< Maximum value */
	I18N_UCALENDAR_GREATEST_MINIMUM,	/**< Greatest minimum value */
	I18N_UCALENDAR_LEAST_MAXIMUM,		/**< Least maximum value */
	I18N_UCALENDAR_ACTUAL_MINIMUM,		/**< Actual minimum value */
	I18N_UCALENDAR_ACTUAL_MAXIMUM		/**< Actual maximum value */
} i18n_ucalendar_limit_type_e;

/**
 * @brief Weekday types, as returned by i18n_ucalendar_get_day_of_week_type().
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UCALENDAR_WEEKDAY,			  /**< Designates a full weekday (no part of the day is included in the weekend). */
	I18N_UCALENDAR_WEEKEND,			  /**< Designates a full weekend day (the entire day is included in the weekend). */
	I18N_UCALENDAR_WEEKEND_ONSET,	  /**< Designates a day that starts as a weekday and transitions to the weekend.
										   Call i18n_ucalendar_get_weekend_transition() to get the time of transition. */
	I18N_UCALENDAR_WEEKEND_CEASE,	  /**< Designates a day that starts as the weekend and transitions to a weekday.
										   Call i18n_ucalendar_get_weekend_transition() to get the time of transition. */
} i18n_ucalendar_weekday_type_e;

/**
 * @brief Useful constants for days of week.
 * @details Note: Calendar day-of-week is 1-based. Clients who create locale resources for the field of first-day-of-week should be aware of this.
 *			For instance, in US locale, first-day-of-week is set to 1, i.e., #I18N_UCALENDAR_SUNDAY. Possible days of the week in an #i18n_ucalendar_h.
 * @since_tizen 2.3.1
 */
typedef enum  {
	I18N_UCALENDAR_SUNDAY = 1,	  /**< Sunday */
	I18N_UCALENDAR_MONDAY,		  /**< Monday */
	I18N_UCALENDAR_TUESDAY,		  /**< Tuesday */
	I18N_UCALENDAR_WEDNESDAY,	  /**< Wednesday */
	I18N_UCALENDAR_THURSDAY,	  /**< Thursday */
	I18N_UCALENDAR_FRIDAY,		  /**< Friday */
	I18N_UCALENDAR_SATURDAY		  /**< Saturday */
} i18n_ucalendar_days_of_week_e;

/**
 * @brief Time zone transition types for i18n_ucalendar_get_timezone_transition_date().
 * @since_tizen 2.3.1
 *
 * @see i18n_ucalendar_get_timezone_transition_date()
 */
typedef enum {
	I18N_UCALENDAR_TZ_TRANSITION_NEXT,					 /**< Get the next transition after the current date, i.e. excludes the current date  */
	I18N_UCALENDAR_TZ_TRANSITION_NEXT_INCLUSIVE,		 /**< Get the next transition on or after the current date, i.e. may include the current date */
	I18N_UCALENDAR_TZ_TRANSITION_PREVIOUS,				 /**< Get the previous transition before the current date, i.e. excludes the current date */
	I18N_UCALENDAR_TZ_TRANSITION_PREVIOUS_INCLUSIVE,	 /**< Get the previous transition on or before the current date, i.e. may include the current date */
} i18n_utimezone_transition_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATE_MODULE
 * @{
 */

/**
 * @brief Date and Time data type. \n This is a primitive data type that holds the date and time as the number of milliseconds since 1970-jan-01, 00:00 UTC. UTC leap seconds are ignored.
 */

/**
 * @brief Date and Time data type.
 * @details This is a primitive data type that holds the date and time as the number of milliseconds since 1970-jan-01, 00:00 UTC. UTC leap seconds are ignored.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef double i18n_udate;

/**
 * @brief A date formatter.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_udate_format_h;

/**
 * @brief A struct representing a range of text containing a specific field.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef struct {
	int32_t field;				/**< The field. */
	int32_t beginIndex;			/**< The start of the text range containing field.*/
	int32_t endIndex;			/**< The limit of the text range containing field.*/
} i18n_ufield_position_s;

/**
 * @brief Handle to struct representing a range of text containing a specific field.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef i18n_ufield_position_s *i18n_ufield_position_h;

/**
 * @brief Enumeration for the possible date/time format styles.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UDATE_FULL,														 /**< Full style */
	I18N_UDATE_LONG,														 /**< Long style */
	I18N_UDATE_MEDIUM,														 /**< Medium style */
	I18N_UDATE_SHORT,														 /**< Short style */
	I18N_UDATE_DEFAULT			 = I18N_UDATE_MEDIUM,						 /**< Default style */
	I18N_UDATE_RELATIVE			 = (1 << 7),								 /**< Bitfield for relative date */
	I18N_UDATE_FULL_RELATIVE	 = I18N_UDATE_FULL	 | I18N_UDATE_RELATIVE,	 /**< #I18N_UDATE_FULL | #I18N_UDATE_RELATIVE */
	I18N_UDATE_LONG_RELATIVE	 = I18N_UDATE_LONG	 | I18N_UDATE_RELATIVE,	 /**< #I18N_UDATE_LONG | #I18N_UDATE_RELATIVE */
	I18N_UDATE_MEDIUM_RELATIVE	 = I18N_UDATE_MEDIUM | I18N_UDATE_RELATIVE,	 /**< #I18N_UDATE_MEDIUM | #I18N_UDATE_RELATIVE */
	I18N_UDATE_SHORT_RELATIVE	 = I18N_UDATE_SHORT	 | I18N_UDATE_RELATIVE,	 /**< #I18N_UDATE_SHORT | #I18N_UDATE_RELATIVE */
	I18N_UDATE_NONE				 = -1,										 /**< No style */
	I18N_UDATE_PATTERN			 = -2										 /**< Use the pattern given in the parameter to i18n_udate_create(). */
} i18n_udate_format_style_e;

/**
 * @brief Enumeration for format fields.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDATE_FORMAT_ERA_FIELD,						   /**< Era field */
	I18N_UDATE_FORMAT_YEAR_FIELD,						   /**< Year field */
	I18N_UDATE_FORMAT_MONTH_FIELD,						   /**< Month field */
	I18N_UDATE_FORMAT_DATE_FIELD,						   /**< Date field */
	I18N_UDATE_FORMAT_HOUR_OF_DAY1_FIELD,				   /**< Hour of day1 field */
	I18N_UDATE_FORMAT_HOUR_OF_DAY0_FIELD,				   /**< Hour of day0 field */
	I18N_UDATE_FORMAT_MINUTE_FIELD,						   /**< Minute field */
	I18N_UDATE_FORMAT_SECOND_FIELD,						   /**< Second field */
	I18N_UDATE_FORMAT_FRACTIONAL_SECOND_FIELD,			   /**< Fractional second field */
	I18N_UDATE_FORMAT_DAY_OF_WEEK_FIELD,				   /**< Day of week field */
	I18N_UDATE_FORMAT_DAY_OF_YEAR_FIELD,				   /**< Day of year field */
	I18N_UDATE_FORMAT_DAY_OF_WEEK_IN_MONTH_FIELD,		   /**< Day of week in month field */
	I18N_UDATE_FORMAT_WEEK_OF_YEAR_FIELD,				   /**< Week of year field */
	I18N_UDATE_FORMAT_WEEK_OF_MONTH_FIELD,				   /**< Week of month field */
	I18N_UDATE_FORMAT_AM_PM_FIELD,						   /**< a.m. / p.m. field */
	I18N_UDATE_FORMAT_HOUR1_FIELD,						   /**< Hour1 field */
	I18N_UDATE_FORMAT_HOUR0_FIELD,						   /**< Hour0 field */
	I18N_UDATE_FORMAT_TIMEZONE_FIELD,					   /**< Timezone field */
	I18N_UDATE_FORMAT_YEAR_WOY_FIELD,					   /**< Year woy field */
	I18N_UDATE_FORMAT_DOW_LOCAL_FIELD,					   /**< Dow local field */
	I18N_UDATE_FORMAT_EXTENDED_YEAR_FIELD,				   /**< Extended year field */
	I18N_UDATE_FORMAT_JULIAN_DAY_FIELD,					   /**< Julian day field */
	I18N_UDATE_FORMAT_MILLISECONDS_IN_DAY_FIELD,		   /**< Milliseconds in day field */
	I18N_UDATE_FORMAT_TIMEZONE_RFC_FIELD,				   /**< Timezone RFC field */
	I18N_UDATE_FORMAT_TIMEZONE_GENERIC_FIELD,			   /**< Timezone generic field */
	I18N_UDATE_FORMAT_STANDALONE_DAY_FIELD,				   /**< Standalone day field */
	I18N_UDATE_FORMAT_STANDALONE_MONTH_FIELD,			   /**< Standalone month field */
	I18N_UDATE_FORMAT_QUARTER_FIELD,					   /**< Quarter field */
	I18N_UDATE_FORMAT_STANDALONE_QUARTER_FIELD,			   /**< Standalone quarter field */
	I18N_UDATE_FORMAT_TIMEZONE_SPECIAL_FIELD,			   /**< Timezone special field */
	I18N_UDATE_FORMAT_YEAR_NAME_FIELD,					   /**< Year name field */
	I18N_UDATE_FORMAT_TIMEZONE_LOCALIZED_GMT_OFFSET_FIELD, /**< Timezone localized gmt offset field */
	I18N_UDATE_FORMAT_TIMEZONE_ISO_FIELD,				   /**< Timezone ISO field */
	I18N_UDATE_FORMAT_TIMEZONE_ISO_LOCAL_FIELD,			   /**< Timezone ISO local field */
	I18N_UDATE_FORMAT_FIELD_COUNT						   /**< Field count */
} i18n_udate_format_field_e;

/**
 * @brief Enumeration for symbol types.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDATE_FORMAT_SYMBOL_TYPE_ERAS,						   /**< Eras */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_MONTHS,					   /**< Months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_MONTHS,				   /**< Short months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_WEEKDAYS,					   /**< Weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_WEEKDAYS,			   /**< Short weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_AM_PMS,					   /**< AM PMs */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_LOCALIZED_CHARS,			   /**< Localized chars */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_ERA_NAMES,				   /**< Era names */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_NARROW_MONTHS,			   /**< Narrow months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_NARROW_WEEKDAYS,			   /**< Narrow weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_MONTHS,		   /**< Standalone months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_MONTHS,	   /**< Standalone short months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_NARROW_MONTHS,	   /**< Standalone narrow months */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_WEEKDAYS,		   /**< Standalone weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_WEEKDAYS,   /**< Standalone short weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_NARROW_WEEKDAYS,  /**< Standalone narrow weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_QUARTERS,					   /**< Quarters */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_QUARTERS,			   /**< Short quarters */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_QUARTERS,		   /**< Standalone quarters */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_QUARTERS,   /**< Standalone short quarters */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORTER_WEEKDAYS,			   /**< Shorter weekdays */
	I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORTER_WEEKDAYS, /**< Standalone shorter weekdays */
} i18n_udate_format_symbol_type_e;

/**
 * @brief Display context types, for getting values of a particular setting.
 * @details Note, the specific numeric values are internal and may change.
 * @since_tizen 2.3.1

 */
typedef enum {
	I18N_UDISPCTX_TYPE_DIALECT_HANDLING,		/**<Type to retrieve the dialect handling setting, e.g. UDISPCTX_STANDARD_NAMES or UDISPCTX_DIALECT_NAMES.	 */
	I18N_UDISPCTX_TYPE_CAPITALIZATION,			/**<Type to retrieve the capitalization context setting, e.g. UDISPCTX_CAPITALIZATION_NONE, UDISPCTX_CAPITALIZATION_FOR_MIDDLE_OF_SENTENCE, UDISPCTX_CAPITALIZATION_FOR_BEGINNING_OF_SENTENCE, etc.	  */
#ifndef U_HIDE_DRAFT_API
	I18N_UDISPCTX_TYPE_DISPLAY_LENGTH			/**<Type to retrieve the display length setting, e.g. UDISPCTX_LENGTH_FULL, UDISPCTX_LENGTH_SHORT.	*/
#endif /* U_HIDE_DRAFT_API */
} i18n_udisplay_context_type_e;

/**
 * @brief Enumeration for display context.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDISPLAY_CONTEXT_STANDARD_NAMES						   = (I18N_UDISPCTX_TYPE_DIALECT_HANDLING<<8) + 0, /**< Standard names */
	I18N_UDISPLAY_CONTEXT_DIALECT_NAMES							   = (I18N_UDISPCTX_TYPE_DIALECT_HANDLING<<8) + 1, /**< Dialect names */
	I18N_UDISPLAY_CONTEXT_CAPITALIZATION_NONE					   = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 0,   /**< Capitalization: None */
	I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_MIDDLE_OF_SENTENCE	   = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 1,   /**< Capitalization: For middle of sentence */
	I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_BEGINNING_OF_SENTENCE = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 2,   /**< Capitalization: For beginning of sentence */
	I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_UI_LIST_OR_MENU	   = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 3,   /**< Capitalization: For UI list or menu */
	I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_STANDALONE			   = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 4,   /**< Capitalization: For standalone */
} i18n_udisplay_context_e;

/* Skeletons for dates. */

/**
 * @brief Constant for date skeleton with year.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_YEAR						  "y"

/**
 * @brief Constant for date skeleton with quarter.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_QUARTER					  "QQQQ"

/**
 * @brief Constant for date skeleton with abbreviated quarter.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_ABBR_QUARTER				  "QQQ"

/**
 * @brief Constant for date skeleton with year and quarter.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_YEAR_QUARTER				  "yQQQQ"

/**
 * @brief Constant for date skeleton with year and abbreviated quarter.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_YEAR_ABBR_QUARTER		  "yQQQ"

/**
 * @brief Constant for date skeleton with month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_MONTH					  "MMMM"

/**
 * @brief Constant for date skeleton with abbreviated month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */

#define I18N_UDATE_ABBR_MONTH				  "MMM"

/**
 * @brief Constant for date skeleton with numeric month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_NUM_MONTH				  "M"

/**
 * @brief Constant for date skeleton with year and month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_MONTH				  "yMMMM"

/**
 * @brief Constant for date skeleton with year and abbreviated month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_ABBR_MONTH			  "yMMM"

/**
 * @brief Constant for date skeleton with year and numeric month.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_NUM_MONTH			  "yM"

/**
 * @brief Constant for date skeleton with day.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_DAY						  "d"

/**
 * @brief Constant for date skeleton with year, month, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_MONTH_DAY			  "yMMMMd"

/**
 * @brief Constant for date skeleton with year, abbreviated month, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_ABBR_MONTH_DAY		  "yMMMd"

/**
 * @brief Constant for date skeleton with year, numeric month, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_NUM_MONTH_DAY		  "yMd"

/**
 * @brief Constant for date skeleton with weekday.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_WEEKDAY					  "EEEE"

/**
 * @brief Constant for date skeleton with abbreviated weekday.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_ABBR_WEEKDAY				  "E"

/**
 * @brief Constant for date skeleton with year, month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_MONTH_WEEKDAY_DAY	  "yMMMMEEEEd"

/**
 * @brief Constant for date skeleton with year, abbreviated month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_ABBR_MONTH_WEEKDAY_DAY "yMMMEd"

/**
 * @brief Constant for date skeleton with year, numeric month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_YEAR_NUM_MONTH_WEEKDAY_DAY "yMEd"

/**
 * @brief Constant for date skeleton with long month and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_MONTH_DAY				  "MMMMd"

/**
 * @brief Constant for date skeleton with abbreviated month and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_ABBR_MONTH_DAY			  "MMMd"

/**
 * @brief Constant for date skeleton with numeric month and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_NUM_MONTH_DAY			  "Md"

/**
 * @brief Constant for date skeleton with month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_MONTH_WEEKDAY_DAY		  "MMMMEEEEd"

/**
 * @brief Constant for date skeleton with abbreviated month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_ABBR_MONTH_WEEKDAY_DAY	  "MMMEd"

/**
 * @brief Constant for date skeleton with numeric month, weekday, and day.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_NUM_MONTH_WEEKDAY_DAY	  "MEd"

/* Skeletons for times. */

/**
 * @brief Constant for date skeleton with hour, with the locale's preferred hour format (12 or 24).
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR						  "j"

/**
 * @brief Constant for date skeleton with hour in 24-hour presentation.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR24					  "H"

/**
 * @brief Constant for date skeleton with minute.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_MINUTE					  "m"

/**
 * @brief Constant for date skeleton with hour and minute, with the locale's preferred hour format (12 or 24).
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR_MINUTE				  "jm"

/**
 * @brief Constant for date skeleton with hour and minute in 24-hour presentation.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR24_MINUTE			  "Hm"

/**
 * @brief Constant for date skeleton with second.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_SECOND					  "s"

/**
 * @brief Constant for date skeleton with hour, minute, and second,
 * with the locale's preferred hour format (12 or 24).
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR_MINUTE_SECOND		  "jms"

/**
 * @brief Constant for date skeleton with hour, minute, and second in
 * 24-hour presentation.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_HOUR24_MINUTE_SECOND		  "Hms"

/**
 * @brief Constant for date skeleton with minute and second.
 * @details Used in combinations date + time, date + time + zone, or time + zone.
 * @since_tizen 3.0
 * @see i18n_udatepg_get_best_pattern()
 */
#define I18N_UDATE_MINUTE_SECOND			  "ms"

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATEPG_MODULE
 * @{
 */

/**
 * @brief Handle for a date/time pattern generator object.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_udatepg_h;

/**
 * @brief Enumeration for field number constants for i18n_udatepg_get_append_item_format() and similar functions.
 * @details These constants are separate from #i18n_udate_format_field_e despite semantic overlap because some fields are merged for the date/time pattern generator.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDATEPG_ERA_FIELD,					 /**< Era field */
	I18N_UDATEPG_YEAR_FIELD,				 /**< Year field */
	I18N_UDATEPG_QUARTER_FIELD,				 /**< Quarter field */
	I18N_UDATEPG_MONTH_FIELD,				 /**< Month field */
	I18N_UDATEPG_WEEK_OF_YEAR_FIELD,		 /**< Week of year field */
	I18N_UDATEPG_WEEK_OF_MONTH_FIELD,		 /**< Week of month field */
	I18N_UDATEPG_WEEKDAY_FIELD,				 /**< Weekday field */
	I18N_UDATEPG_DAY_OF_YEAR_FIELD,			 /**< Day of year field */
	I18N_UDATEPG_DAY_OF_WEEK_IN_MONTH_FIELD, /**< Day of week in month field */
	I18N_UDATEPG_DAY_FIELD,					 /**< Day field */
	I18N_UDATEPG_DAYPERIOD_FIELD,			 /**< Day period field */
	I18N_UDATEPG_HOUR_FIELD,				 /**< Hour field */
	I18N_UDATEPG_MINUTE_FIELD,				 /**< Minute field */
	I18N_UDATEPG_SECOND_FIELD,				 /**< Second field */
	I18N_UDATEPG_FRACTIONAL_SECOND_FIELD,	 /**< Fractional second field */
	I18N_UDATEPG_ZONE_FIELD,				 /**< Zone field */
	I18N_UDATEPG_FIELD_COUNT				 /**< Field count */
} i18n_udatepg_date_time_pattern_field_e;

/**
 * @brief Enumeration for masks to control forcing the length of specified fields in the returned pattern to match those in the skeleton (when this would not happen otherwise).\n
 * @details These may be combined to force the length of multiple fields.
 *			Used with i18n_udatepg_get_best_pattern_with_options(), i18n_udatepg_replace_field_types_with_options().
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDATEPG_MATCH_NO_OPTIONS		 = 0,									/**< No options */
	I18N_UDATEPG_MATCH_HOUR_FIELD_LENGTH = 1 << I18N_UDATEPG_HOUR_FIELD,		/**< Hour field length */
	I18N_UDATEPG_MATCH_ALL_FIELDS_LENGTH = (1 << I18N_UDATEPG_FIELD_COUNT) - 1, /**< All fields length */
} i18n_udatepg_date_time_pattern_match_options_e;

/**
 * @brief Enumeration for status return values from i18n_udatepg_add_pattern().
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UDATEPG_NO_CONFLICT,	 /**< No conflict */
	I18N_UDATEPG_BASE_CONFLICT,	 /**< Base conflict */
	I18N_UDATEPG_CONFLICT,		 /**< Conflict */
	I18N_UDATEPG_CONFLICT_COUNT, /**< Number of status return values */
} i18n_udatepg_date_time_pattern_conflict_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNUMBER_MODULE
 * @{
 */

/**
 * @brief A number formatter.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_unumber_format_h;

/**
 * @brief Definition of context length.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_U_PARSE_CONTEXT_LEN 16

/**
 * @brief Struct used to returned detailed information about parsing errors.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef struct {
	int32_t	   line;									/**< The line on which the error occured. */
	int32_t	   offset;									/**< The character offset to the error */
	i18n_uchar preContext[I18N_U_PARSE_CONTEXT_LEN];	/**< Textual context before the error */
	i18n_uchar postContext[I18N_U_PARSE_CONTEXT_LEN];	/**< The error itself and/or textual context after the error */
} i18n_uparse_error_s;

/**
 * @brief Enumeration for the possible number format styles.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UNUMBER_PATTERN_DECIMAL	  = 0,	/**< Decimal format defined by a pattern string */
	I18N_UNUMBER_DECIMAL			  = 1,	/**< Decimal format ("normal" style) */
	I18N_UNUMBER_CURRENCY,					/**< Currency format with a currency symbol, e.g., "$1.00" */
	I18N_UNUMBER_PERCENT,					/**< Percent format */
	I18N_UNUMBER_SCIENTIFIC,				/**< Scientific format */
	I18N_UNUMBER_SPELLOUT,					/**< Spellout rule-based format */
	I18N_UNUMBER_ORDINAL,					/**< Ordinal rule-based format */
	I18N_UNUMBER_DURATION,					/**< Duration rule-based format */
	I18N_UNUMBER_NUMBERING_SYSTEM,			/**< Numbering system rule-based format */
	I18N_UNUMBER_PATTERN_RULEBASED,			/**< Rule-based format defined by a pattern string */
	I18N_UNUMBER_CURRENCY_ISO,				/**< Currency format with an ISO currency code, e.g., "USD1.00" */
	I18N_UNUMBER_CURRENCY_PLURAL,			/**< Currency format with a pluralized currency name, e.g., "1.00 US dollar" and "3.00 US dollars" */

	I18N_UNUMBER_FORMAT_STYLE_COUNT,										/**< One more than the highest number format style constant */
	I18N_UNUMBER_DEFAULT			  = I18N_UNUMBER_DECIMAL,				/**< Default format */
	I18N_UNUMBER_IGNORE				  = I18N_UNUMBER_PATTERN_DECIMAL		/**< Alias for #I18N_UNUMBER_PATTERN_DECIMAL */
} i18n_unumber_format_style_e;

/**
 * @brief Enumeration of constants for specifying a number format symbol.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_UNUMBER_DECIMAL_SEPARATOR_SYMBOL			 = 0,		/**< The decimal separator */
	I18N_UNUMBER_GROUPING_SEPARATOR_SYMBOL			 = 1,		/**< The grouping separator */
	I18N_UNUMBER_PATTERN_SEPARATOR_SYMBOL			 = 2,		/**< The pattern separator */
	I18N_UNUMBER_PERCENT_SYMBOL						 = 3,		/**< The percent sign */
	I18N_UNUMBER_ZERO_DIGIT_SYMBOL					 = 4,		/**< Zero */
	I18N_UNUMBER_DIGIT_SYMBOL						 = 5,		/**< Character representing a digit in the pattern.*/
	I18N_UNUMBER_MINUS_SIGN_SYMBOL					 = 6,		/**< The minus sign */
	I18N_UNUMBER_PLUS_SIGN_SYMBOL					 = 7,		/**< The plus sign */
	I18N_UNUMBER_CURRENCY_SYMBOL					 = 8,		/**< The currency symbol */
	I18N_UNUMBER_INTL_CURRENCY_SYMBOL				 = 9,		/**< The international currency symbol */
	I18N_UNUMBER_MONETARY_SEPARATOR_SYMBOL			 = 10,		/**< The monetary separator */
	I18N_UNUMBER_EXPONENTIAL_SYMBOL					 = 11,		/**< The exponential symbol */
	I18N_UNUMBER_PERMILL_SYMBOL						 = 12,		/**< Per mill symbol */
	I18N_UNUMBER_PAD_ESCAPE_SYMBOL					 = 13,		/**< Escape padding character */
	I18N_UNUMBER_INFINITY_SYMBOL					 = 14,		/**< Infinity symbol */
	I18N_UNUMBER_NAN_SYMBOL							 = 15,		/**< NAN symbol */
	I18N_UNUMBER_SIGNIFICANT_DIGIT_SYMBOL			 = 16,		/**< Significant digit symbol */
	I18N_UNUMBER_MONETARY_GROUPING_SEPARATOR_SYMBOL	 = 17,		/**< The monetary grouping separator */
	I18N_UNUMBER_ONE_DIGIT_SYMBOL					 = 18,		/**< One */
	I18N_UNUMBER_TWO_DIGIT_SYMBOL					 = 19,		/**< Two */
	I18N_UNUMBER_THREE_DIGIT_SYMBOL					 = 20,		/**< Three */
	I18N_UNUMBER_FOUR_DIGIT_SYMBOL					 = 21,		/**< Four */
	I18N_UNUMBER_FIVE_DIGIT_SYMBOL					 = 22,		/**< Five */
	I18N_UNUMBER_SIX_DIGIT_SYMBOL					 = 23,		/**< Six */
	I18N_UNUMBER_SEVEN_DIGIT_SYMBOL					 = 24,		/**< Seven */
	I18N_UNUMBER_EIGHT_DIGIT_SYMBOL					 = 25,		/**< Eight */
	I18N_UNUMBER_NINE_DIGIT_SYMBOL					 = 26,		/**< Nine */
	I18N_UNUMBER_FORMAT_SYMBOL_COUNT							/**< Number of enumerators */
} i18n_unumber_format_symbol_e;

/**
 * @brief Enumeration for the possible unumber_format numeric attributes.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UNUMBER_PARSE_INT_ONLY,				   /**< Parse integers only */
	I18N_UNUMBER_GROUPING_USED,					   /**< Use grouping separator */
	I18N_UNUMBER_DECIMAL_ALWAYS_SHOWN,			   /**< Always show decimal point */
	I18N_UNUMBER_MAX_INTEGER_DIGITS,			   /**< Maximum integer digits */
	I18N_UNUMBER_MIN_INTEGER_DIGITS,			   /**< Minimum integer digits */
	I18N_UNUMBER_INTEGER_DIGITS,				   /**< Integer digits */
	I18N_UNUMBER_MAX_FRACTION_DIGITS,			   /**< Maximum fraction digits */
	I18N_UNUMBER_MIN_FRACTION_DIGITS,			   /**< Minimum fraction digits */
	I18N_UNUMBER_FRACTION_DIGITS,				   /**< Fraction digits */
	I18N_UNUMBER_MULTIPLIER,					   /**< Multiplier */
	I18N_UNUMBER_GROUPING_SIZE,					   /**< Grouping size */
	I18N_UNUMBER_ROUNDING_MODE,					   /**< Rounding Mode */
	I18N_UNUMBER_ROUNDING_INCREMENT,			   /**< Rounding increment */
	I18N_UNUMBER_FORMAT_WIDTH,					   /**< The width to which the output of format() is padded */
	I18N_UNUMBER_PADDING_POSITION,				   /**< The position at which padding will take place */
	I18N_UNUMBER_SECONDARY_GROUPING_SIZE,		   /**< Secondary grouping size */
	I18N_UNUMBER_SIGNIFICANT_DIGITS_USED,		   /**< Use significant digits */
	I18N_UNUMBER_MIN_SIGNIFICANT_DIGITS,		   /**< Minimum significant digits */
	I18N_UNUMBER_MAX_SIGNIFICANT_DIGITS,		   /**< Maximum significant digits */
	I18N_UNUMBER_LENIENT_PARSE,					   /**< Lenient parse mode used by rule-based formats */
	I18N_UNUM_SCALE = I18N_UNUMBER_LENIENT_PARSE + 2,			/**< Scale, which adjusts the position of the decimal point when formatting.
																	Amounts will be multiplied by 10 ^ (scale) before they are formatted. The default value for the scale is 0 ( no adjustment ).
																	Example: setting the scale to 3, 123 formats as "123,000"
																	Example: setting the scale to -4, 123 formats as "0.0123" */
	I18N_UNUM_FORMAT_FAIL_IF_MORE_THAN_MAX_DIGITS  = 0x1000,	/**< If 1, specifies that if setting the "max integer digits" attribute would truncate a value, set an error status rather than silently truncating.
																	For example, formatting the value 1234 with 4 max int digits would succeed, but formatting 12345 would fail.
																	There is no effect on parsing. Default: 0 (not set) */
	I18N_UNUM_PARSE_NO_EXPONENT,								/**< If this attribute is set to 1, specifies that, if the pattern doesn't contain an exponent,
																	the exponent will not be parsed. If the pattern does contain an exponent, this attribute has no effect.
																	Has no effect on formatting. Default: 0 (unset) */
} i18n_unumber_format_attribute_e;

/**
 * @brief Enumeration for the possible values of the #I18N_UNUMBER_PADDING_POSITION attribute.
 * @since_tizen 3.0
 */
typedef enum {
	I18N_UNUMBER_PAD_BEFORE_PREFIX,
	I18N_UNUMBER_PAD_AFTER_PREFIX,
	I18N_UNUMBER_PAD_BEFORE_SUFFIX,
	I18N_UNUMBER_PAD_AFTER_SUFFIX,
} i18n_unumber_pad_position_e;

/**
 * @brief The possible #i18n_unumber_format_h text attributes.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_UNUMBER_POSITIVE_PREFIX,	   /**< Positive prefix */
	I18N_UNUMBER_POSITIVE_SUFFIX,	   /**< Positive suffix */
	I18N_UNUMBER_NEGATIVE_PREFIX,	   /**< Negative prefix */
	I18N_UNUMBER_NEGATIVE_SUFFIX,	   /**< Negative suffix */
	I18N_UNUMBER_PADDING_CHARACTER,	   /**< The character used to pad to the format width */
	I18N_UNUMBER_CURRENCY_CODE,		   /**< The ISO currency code */
	I18N_UNUMBER_DEFAULT_RULESET,	   /**< The default rule set, such as "%spellout-numbering-year:", "%spellout-cardinal:",
										 "%spellout-ordinal-masculine-plural:", "%spellout-ordinal-feminine:"
										 or "%spellout-ordinal-neuter:".
										 The available public rulesets can be listed using i18n_unumber_get_text_attribute()
										 with #I18N_UNUMBER_PUBLIC_RULESETS. This is only available with rule-based formatters */
	I18N_UNUMBER_PUBLIC_RULESETS,	   /**< The public rule sets. This is only available with rule-based formatters. This is a read-only attribute.
										 The public rulesets are returned as a single string, with each ruleset name delimited by ';' (semicolon).
										 See the CLDR LDML spec for more information about RBNF rulesets:
										 http://www.unicode.org/reports/tr35/tr35-numbers.html#Rule-Based_Number_Formatting */
} i18n_unumber_format_text_attribute_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ULOCALE_MODULE
 * @{
 */

#define I18N_ULOCALE_CHINESE				   "zh"			/**< Useful constant for zh. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ENGLISH				   "en"			/**< Useful constant for en. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_FRENCH					   "fr"			/**< Useful constant for fr. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_GERMAN					   "de"			/**< Useful constant for de. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ITALIAN				   "it"			/**< Useful constant for it. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_JAPANESE				   "ja"			/**< Useful constant for ja. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_KOREAN					   "ko"			/**< Useful constant for ko. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_SIMPLIFIED_CHINESE		   "zh_CN"		/**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_TRADITIONAL_CHINESE	   "zh_TW"		/**< Useful constant for zh_TW. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CANADA					   "en_CA"		/**< Useful constant for en_CA. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CANADA_FRENCH			   "fr_CA"		/**< Useful constant for fr_CA. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CHINA					   "zh_CN"		/**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_PRC					   "zh_CN"		/**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_FRANCE					   "fr_FR"		/**< Useful constant for fr_FR. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_GERMANY				   "de_DE"		/**< Useful constant for de_DE. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ITALY					   "it_IT"		/**< Useful constant for it_IT. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_JAPAN					   "ja_JP"		/**< Useful constant for ja_JP. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_KOREA					   "ko_KR"		/**< Useful constant for ko_KR. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_TAIWAN					   "zh_TW"		/**< Useful constant for zh_TW. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_UK						   "en_GB"		/**< Useful constant for en_GB. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_US						   "en_US"		/**< Useful constant for en_US. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/

/**
 * @brief Useful constant for the maximum size of the language part of a locale ID.
 * (including the terminating NULL).
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 * @see i18n_ulocale_get_language()
 */
#define I18N_ULOCALE_LANG_CAPACITY 12

/**
 * @brief Useful constant for the maximum size of the country part of a locale ID
 * (including the terminating NULL).
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 * @see i18n_ulocale_get_country()
 */
#define I18N_ULOCALE_COUNTRY_CAPACITY 4
/**
 * @brief Useful constant for the maximum size of the whole locale ID
 * (including the terminating NULL and all keywords).
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_FULLNAME_CAPACITY 157

/**
 * @brief Useful constant for the maximum size of the script part of a locale ID
 * (including the terminating NULL).
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 * @see i18n_ulocale_get_script()
 */
#define I18N_ULOCALE_SCRIPT_CAPACITY 6

/**
 * @brief Useful constant for the maximum size of keywords in a locale
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORDS_CAPACITY 96

/**
 * @brief Useful constant for the maximum total size of keywords and their values in a locale
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_AND_VALUES_CAPACITY 100

/**
 * @brief Invariant character separating keywords from the locale string
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_SEPARATOR '@'

/**
 * @brief Unicode code point for '@' separating keywords from the locale string.
 * @since_tizen 3.0
 * @see #I18N_ULOCALE_KEYWORD_SEPARATOR
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_SEPARATOR_UNICODE 0x40

/**
 * @brief Invariant character for assigning value to a keyword
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_ASSIGN '='

/**
 * @brief Unicode code point for '=' for assigning value to a keyword.
 * @since_tizen 3.0
 * @see #I18N_ULOCALE_KEYWORD_ASSIGN
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_ASSIGN_UNICODE 0x3D

/**
 * @brief Invariant character separating keywords
 * @since_tizen 3.0
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_ITEM_SEPARATOR ';'

/**
 * @brief Unicode code point for ';' separating keywords
 * @since_tizen 3.0
 * @see #I18N_ULOCALE_KEYWORD_ITEM_SEPARATOR
 * @see i18n_ulocale_get_keyword_value()
 */
#define I18N_ULOCALE_KEYWORD_ITEM_SEPARATOR_UNICODE 0x3B

/**
 * @brief Enumeration for the 'out_result' parameter return value
 * @since_tizen 2.3.1
 *
 * @see i18n_ulocale_accept_language_from_http()
 * @see i18n_ulocale_accept_language()
 */
typedef enum {
	I18N_ULOCALE_ACCEPT_FAILED	 = 0,  /**< No exact match was found */
	I18N_ULOCALE_ACCEPT_VALID	 = 1,  /**< An exact match was found */
	I18N_ULOCALE_ACCEPT_FALLBACK = 2,  /**< A fallback was found, for example,
										  accept list contained 'ja_JP' which matched available locale 'ja' */
} i18n_ulocale_accept_result_e;

/**
 * @brief Enumeration for data locale types.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_ULOCALE_DATA_LOCALE_TYPE_ACTUAL_LOCALE, /**< Actual locale */
	I18N_ULOCALE_DATA_LOCALE_TYPE_VALID_LOCALE,	 /**< Valid locale */
	I18N_ULOCALE_DATA_LOCALE_TYPE_LIMIT = 3,	 /**< Locale type limit */
} i18n_ulocale_data_locale_type_e;

/**
 * @brief Enumeration for the return value for the character and line orientation functions.
 * @since_tizen 2.3.1
 */
typedef enum {
	I18N_ULOCALE_LAYOUT_LTR		= 0,  /**< Left-to-right */
	I18N_ULOCALE_LAYOUT_RTL		= 1,  /**< Right-to-left */
	I18N_ULOCALE_LAYOUT_TTB		= 2,  /**< Top-to-bottom */
	I18N_ULOCALE_LAYOUT_BTT		= 3,  /**< Bottom-to-top */
	I18N_ULOCALE_LAYOUT_UNKNOWN		  /**< Unknown		 */
} i18n_ulocale_layout_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USTRING_MODULE
 * @{
 */

/**
 * @brief Callback function for i18n_ustring_unescape_at() that returns a character of the source text given an offset and a context pointer.\n
 *		  The context pointer will be whatever is passed into i18n_ustring_unescape_at().
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in]	offset		pointer to the offset that will be passed to i18n_ustring_unescape_at().
 * @param[in]	context		an opaque pointer passed directly into i18n_ustring_unescape_at()
 *
 * @retval	character	the character represented by the escape sequence at offset
 *
 * @see i18n_ustring_unescape_at()
 */
typedef i18n_uchar(*i18n_ustring_unescape_char_at_cb)(int32_t offset, void *context);

/**
 * @brief Option value for case folding: use default mappings defined in CaseFolding.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_FOLD_CASE_DEFAULT 0


/**
 * @brief Option bit i18n_ustring_case_compare_with_length(), i18n_ustring_case_compare(), etc: Compare strings in code point order instead of code unit order.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_COMPARE_CODE_POINT_ORDER	 0x8000

/**
 * @brief Option value for case folding: \n
 * Use the modified set of mappings provided in CaseFolding.txt to handle dotted I and dotless i appropriately for Turkic languages (tr, az).\n
 * Before Unicode 3.2, CaseFolding.txt contains mappings marked with 'I' that are to be included for default mappings and excluded for the Turkic-specific mappings.\n
 * Unicode 3.2 CaseFolding.txt instead contains mappings marked with 'T' that are to be excluded for default mappings and included for the Turkic-specific mappings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_FOLD_CASE_EXCLUDE_SPECIAL_I 1

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE
 * @{
 */

/**
 * @brief handle for object that represents a time zone offset, and also figures out daylight savings..
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_timezone_h;

/**
 * @brief Callback function for i18n_timezone_foreach_timezone_id(), i18n_timezone_foreach_timezone_id_with_offset(), and i18n_timezone_foreach_timezone_id_by_country()
 *		  that returns an enumeration over all recognized time zone IDs.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] timezone_id	time zone ID
 * @param[in] user_data		the user data passed to the callback function
 *
 * @return @c true to continue with the next iteration of the loop, otherwise @c false to break out of the loop.
 *
 * @see i18n_ustring_unescape_at()
 */
typedef bool (*i18n_timezone_id_cb)(const char *timezone_id, void *user_data);

/**
 * @brief Enumeration for use with i18n_timezone_get_display_name(), i18n_timezone_get_display_name_with_locale(), and i18n_timezone_get_display_name_with_type().
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
	I18N_TIMEZONE_DISPLAY_TYPE_SHORT = 1,			/**< Selector for short display name */
	I18N_TIMEZONE_DISPLAY_TYPE_LONG,				/**< Selector for long display name */
	I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GENERIC,		/**< Selector for short generic display name */
	I18N_TIMEZONE_DISPLAY_TYPE_LONG_GENERIC,		/**< Selector for long generic display name */
	I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GMT,			/**< Selector for short display name derived */
	I18N_TIMEZONE_DISPLAY_TYPE_LONG_GMT,			/**< Selector for long display name derived from time zone offset */
	I18N_TIMEZONE_DISPLAY_TYPE_SHORT_COMMONLY_USED, /**< Selector for short display name derived from the time zone's fallback name */
	I18N_TIMEZONE_DISPLAY_TYPE_GENERIC_LOCATION		/**< Selector for long display name derived from the time zone's fallback name */
} i18n_timezone_display_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UBRK_MODULE
 * @{
 */

/**
 * @brief i18n_ubreak_iterator_s.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_ubreak_iterator_s;

/**
 * @brief i18n_ubreak_iterator_h.
 * @since_tizen 2.3.1
 */
typedef void *i18n_ubreak_iterator_h;

/**
 * @deprecated Deprecated since Tizen 3.0
 * @brief A recommended size (in bytes) for the memory buffer to be passed to i18n_ubrk_safe_clone().
 * @since_tizen 2.3.1
 */
#define I18N_U_BRK_SAFECLONE_BUFFERSIZE 528

/**
 * @brief Value indicating all text boundaries have been returned.
 * @since_tizen 2.3.1
 */
#define I18N_UBRK_DONE	 ((int32_t) -1)

/**
 * @brief The possible types of text boundaries.
 * @since_tizen 2.3.1
 *
 */
typedef enum {
	I18N_UBRK_CHARACTER = 0,	 /**< Character breaks */
	I18N_UBRK_WORD		= 1,	 /**< Word breaks */
	I18N_UBRK_LINE		= 2,	 /**< Line breaks */
	I18N_UBRK_SENTENCE	= 3,	 /**< Sentence breaks */
} i18n_ubreak_iterator_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USET_MODULE
 * @{
 */

/**
 * @brief An #i18n_uset_h handle.
 * @details Use the @c i18n_uset_* API to manipulate. Create with @c i18n_uset_create*, and destroy with i18n_uset_destroy().
 * @since_tizen 2.3.1
 */
typedef void *i18n_uset_h;

/**
 * @brief Capacity of #i18n_userialized_set_s::static_array.
 *		  Enough for any single-code point set.
 * @since_tizen 2.3.1
 *
 * @see #i18n_userialized_set_s
 */
#define I18N_USET_SERIALIZED_STATIC_ARRAY_CAPACITY 8

/**
 * @brief  A serialized form of a Unicode set.
 * @since_tizen 2.3.1
 */
typedef struct {
	const uint16_t *array;														  /**< The serialized Unicode Set. */
	int32_t			bmp_length;													  /**< The length of the array that contains BMP characters. */
	int32_t			length;														  /**< The total length of the array. */
	uint16_t		static_array[I18N_USET_SERIALIZED_STATIC_ARRAY_CAPACITY];	  /**< A small buffer for the array to reduce memory allocations. */
} i18n_userialized_set_s;


/**
 * @brief Enumeration for span conditions.
 * @since_tizen 2.3.1
 *
 * @see i18n_uset_span()
 * @see i18n_uset_span_back()
 * @see i18n_uset_span_utf8()
 * @see i18n_uset_span_back_utf8()
 */
typedef enum {
	I18N_USET_SPAN_NOT_CONTAINED = 0,	/**< Continue a span() while there is no set element at the current position.
											 Stops before the first set element (character or string).
											 (For code points only, this is like while contains(current)==false).

											 When span() returns, the substring between where it started and the position
											 it returned consists only of characters that are not in the set,
											 and none of its strings overlap with the span. */
	I18N_USET_SPAN_CONTAINED = 1,		/**< Continue a span() while there is a set element at the current position.
											 (For characters only, this is like while contains(current)==true).

											 When span() returns, the substring between where it started and the position
											 it returned consists only of set elements (characters or strings) that are in the set.

											 If a set contains strings, then the span will be the longest substring
											 matching any of the possible concatenations of set elements (characters or strings).
											 (There must be a single, non-overlapping concatenation of characters or strings.)
											 This is equivalent to a POSIX regular expression for (OR of each set element). */
	I18N_USET_SPAN_SIMPLE = 2,			/**< Continue a span() while there is a set element at the current position.
											 (For characters only, this is like while contains(current)==true).

											 When span() returns, the substring between where it started and the position
											 it returned consists only of set elements (characters or strings) that are in the set.

											 If a set only contains single characters, then this is the same
											 as #I18N_USET_SPAN_CONTAINED.

											 If a set contains strings, then the span will be the longest substring
											 with a match at each position with the longest single set element (character or string). */
	I18N_USET_SPAN_CONDITION_COUNT		/**< One more than the last span condition.	 */
} i18n_uset_span_condition_e;


/**
 * @brief Enumeration for bitmask values to be passed to i18n_uset_pattern_options_create() or i18n_uset_apply_pattern() taking an option parameter.
 * @since_tizen 2.3.1
 */
enum {
	I18N_USET_IGNORE_SPACE = 1,			/**< Ignore white space within patterns unless quoted or escaped. */
	I18N_USET_CASE_INSENSITIVE = 2,		/**< Enable case insensitive matching.
											 E.g., "[ab]" with this flag will match 'a', 'A', 'b', and 'B'.
											 "[^ab]" with this flag will match all except 'a', 'A', 'b', and 'B'.
											 This performs a full closure over case mappings, e.g. U+017F for s.

											 The resulting set is a superset of the input for the code points but not for the strings.
											 It performs a case mapping closure of the code points and adds full case folding strings for the code points,
											 and reduces strings of the original set to their full case folding equivalents.

											 This is designed for case-insensitive matches, for example in regular expressions.
											 The full code point case closure allows checking of an input character directly against the closure set.
											 Strings are matched by comparing the case-folded form from the closure
											 set with an incremental case folding of the string in question.

											 The closure set will also contain single code points if the original
											 set contained case-equivalent strings (like U+00DF for "ss" or "Ss" etc.).
											 This is not necessary (that is, redundant) for the above matching method
											 but results in the same closure sets regardless of whether the original
											 set contained the code point or a string. */

	I18N_USET_ADD_CASE_MAPPINGS = 4		/**< Enable case insensitive matching.
											 E.g., "[ab]" with this flag will match 'a', 'A', 'b', and 'B'.
											 "[^ab]" with this flag will match all except 'a', 'A', 'b', and 'B'.
											 This adds the lower-, title-, and uppercase mappings as well as the case folding of each existing element in the set. */
};

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE
 * @{
 */

/**
 * @brief Structure representing an enumeration.
 * @details For usage in C programs.
 * @since_tizen 2.3.1
 */
typedef void *i18n_uenumeration_h;

/**
 * @}
 */


/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE
 * @{
 */

/**
 * @brief Constants for ISO 15924 script codes.
 * @since_tizen 2.4
 */
typedef enum {
	I18N_USCRIPT_INVALID_CODE = -1,
	I18N_USCRIPT_COMMON		  =	 0,	 /**< Zyyy */
	I18N_USCRIPT_INHERITED	  =	 1,	 /**< Zinh, "Code for inherited script", for non-spacing combining marks; also Qaai */
	I18N_USCRIPT_ARABIC		  =	 2,	 /**< Arab */
	I18N_USCRIPT_ARMENIAN	  =	 3,	 /**< Armn */
	I18N_USCRIPT_BENGALI	  =	 4,	 /**< Beng */
	I18N_USCRIPT_BOPOMOFO	  =	 5,	 /**< Bopo */
	I18N_USCRIPT_CHEROKEE	  =	 6,	 /**< Cher */
	I18N_USCRIPT_COPTIC		  =	 7,	 /**< Copt */
	I18N_USCRIPT_CYRILLIC	  =	 8,	 /**< Cyrl */
	I18N_USCRIPT_DESERET	  =	 9,	 /**< Dsrt */
	I18N_USCRIPT_DEVANAGARI	  = 10,	 /**< Deva */
	I18N_USCRIPT_ETHIOPIC	  = 11,	 /**< Ethi */
	I18N_USCRIPT_GEORGIAN	  = 12,	 /**< Geor */
	I18N_USCRIPT_GOTHIC		  = 13,	 /**< Goth */
	I18N_USCRIPT_GREEK		  = 14,	 /**< Grek */
	I18N_USCRIPT_GUJARATI	  = 15,	 /**< Gujr */
	I18N_USCRIPT_GURMUKHI	  = 16,	 /**< Guru */
	I18N_USCRIPT_HAN		  = 17,	 /**< Hani */
	I18N_USCRIPT_HANGUL		  = 18,	 /**< Hang */
	I18N_USCRIPT_HEBREW		  = 19,	 /**< Hebr */
	I18N_USCRIPT_HIRAGANA	  = 20,	 /**< Hira */
	I18N_USCRIPT_KANNADA	  = 21,	 /**< Knda */
	I18N_USCRIPT_KATAKANA	  = 22,	 /**< Kana */
	I18N_USCRIPT_KHMER		  = 23,	 /**< Khmr */
	I18N_USCRIPT_LAO		  = 24,	 /**< Laoo */
	I18N_USCRIPT_LATIN		  = 25,	 /**< Latn */
	I18N_USCRIPT_MALAYALAM	  = 26,	 /**< Mlym */
	I18N_USCRIPT_MONGOLIAN	  = 27,	 /**< Mong */
	I18N_USCRIPT_MYANMAR	  = 28,	 /**< Mymr */
	I18N_USCRIPT_OGHAM		  = 29,	 /**< Ogam */
	I18N_USCRIPT_OLD_ITALIC	  = 30,	 /**< Ital */
	I18N_USCRIPT_ORIYA		  = 31,	 /**< Orya */
	I18N_USCRIPT_RUNIC		  = 32,	 /**< Runr */
	I18N_USCRIPT_SINHALA	  = 33,	 /**< Sinh */
	I18N_USCRIPT_SYRIAC		  = 34,	 /**< Syrc */
	I18N_USCRIPT_TAMIL		  = 35,	 /**< Taml */
	I18N_USCRIPT_TELUGU		  = 36,	 /**< Telu */
	I18N_USCRIPT_THAANA		  = 37,	 /**< Thaa */
	I18N_USCRIPT_THAI		  = 38,	 /**< Thai */
	I18N_USCRIPT_TIBETAN	  = 39,	 /**< Tibt */
	I18N_USCRIPT_CANADIAN_ABORIGINAL = 40,	/**< Cans, Canadian_Aboriginal script. */
	I18N_USCRIPT_UCAS		  = I18N_USCRIPT_CANADIAN_ABORIGINAL, /**< Canadian_Aboriginal script (alias). */
	I18N_USCRIPT_YI			  = 41,	 /**< Yiii */
	I18N_USCRIPT_TAGALOG	  = 42,	 /**< Tglg */
	I18N_USCRIPT_HANUNOO	  = 43,	 /**< Hano */
	I18N_USCRIPT_BUHID		  = 44,	 /**< Buhd */
	I18N_USCRIPT_TAGBANWA	  = 45,	 /**< Tagb */
	I18N_USCRIPT_BRAILLE	  = 46,	 /**< Brai */
	I18N_USCRIPT_CYPRIOT	  = 47,	 /**< Cprt */
	I18N_USCRIPT_LIMBU		  = 48,	 /**< Limb */
	I18N_USCRIPT_LINEAR_B	  = 49,	 /**< Linb */
	I18N_USCRIPT_OSMANYA	  = 50,	 /**< Osma */
	I18N_USCRIPT_SHAVIAN	  = 51,	 /**< Shaw */
	I18N_USCRIPT_TAI_LE		  = 52,	 /**< Tale */
	I18N_USCRIPT_UGARITIC	  = 53,	 /**< Ugar */
	I18N_USCRIPT_KATAKANA_OR_HIRAGANA = 54,/**<Hrkt */
	I18N_USCRIPT_BUGINESE	   = 55, /**< Bugi */
	I18N_USCRIPT_GLAGOLITIC	   = 56, /**< Glag */
	I18N_USCRIPT_KHAROSHTHI	   = 57, /**< Khar */
	I18N_USCRIPT_SYLOTI_NAGRI  = 58, /**< Sylo */
	I18N_USCRIPT_NEW_TAI_LUE   = 59, /**< Talu */
	I18N_USCRIPT_TIFINAGH	   = 60, /**< Tfng */
	I18N_USCRIPT_OLD_PERSIAN   = 61, /**< Xpeo */
	I18N_USCRIPT_BALINESE					   = 62, /**< Bali */
	I18N_USCRIPT_BATAK						   = 63, /**< Batk */
	I18N_USCRIPT_BLISSYMBOLS				   = 64, /**< Blis */
	I18N_USCRIPT_BRAHMI						   = 65, /**< Brah */
	I18N_USCRIPT_CHAM						   = 66, /**< Cham */
	I18N_USCRIPT_CIRTH						   = 67, /**< Cirt */
	I18N_USCRIPT_OLD_CHURCH_SLAVONIC_CYRILLIC  = 68, /**< Cyrs */
	I18N_USCRIPT_DEMOTIC_EGYPTIAN			   = 69, /**< Egyd */
	I18N_USCRIPT_HIERATIC_EGYPTIAN			   = 70, /**< Egyh */
	I18N_USCRIPT_EGYPTIAN_HIEROGLYPHS		   = 71, /**< Egyp */
	I18N_USCRIPT_KHUTSURI					   = 72, /**< Geok */
	I18N_USCRIPT_SIMPLIFIED_HAN				   = 73, /**< Hans */
	I18N_USCRIPT_TRADITIONAL_HAN			   = 74, /**< Hant */
	I18N_USCRIPT_PAHAWH_HMONG				   = 75, /**< Hmng */
	I18N_USCRIPT_OLD_HUNGARIAN				   = 76, /**< Hung */
	I18N_USCRIPT_HARAPPAN_INDUS				   = 77, /**< Inds */
	I18N_USCRIPT_JAVANESE					   = 78, /**< Java */
	I18N_USCRIPT_KAYAH_LI					   = 79, /**< Kali */
	I18N_USCRIPT_LATIN_FRAKTUR				   = 80, /**< Latf */
	I18N_USCRIPT_LATIN_GAELIC				   = 81, /**< Latg */
	I18N_USCRIPT_LEPCHA						   = 82, /**< Lepc */
	I18N_USCRIPT_LINEAR_A					   = 83, /**< Lina */
	I18N_USCRIPT_MANDAIC					   = 84, /**< Mand */
	I18N_USCRIPT_MANDAEAN					   = I18N_USCRIPT_MANDAIC,
	I18N_USCRIPT_MAYAN_HIEROGLYPHS			   = 85, /**< Maya */
	I18N_USCRIPT_MEROITIC_HIEROGLYPHS		   = 86, /**< Mero */
	I18N_USCRIPT_MEROITIC					   = I18N_USCRIPT_MEROITIC_HIEROGLYPHS,
	I18N_USCRIPT_NKO						   = 87, /**< Nkoo */
	I18N_USCRIPT_ORKHON						   = 88, /**< Orkh */
	I18N_USCRIPT_OLD_PERMIC					   = 89, /**< Perm */
	I18N_USCRIPT_PHAGS_PA					   = 90, /**< Phag */
	I18N_USCRIPT_PHOENICIAN					   = 91, /**< Phnx */
	I18N_USCRIPT_PHONETIC_POLLARD			   = 92, /**< Plrd */
	I18N_USCRIPT_RONGORONGO					   = 93, /**< Roro */
	I18N_USCRIPT_SARATI						   = 94, /**< Sara */
	I18N_USCRIPT_ESTRANGELO_SYRIAC			   = 95, /**< Syre */
	I18N_USCRIPT_WESTERN_SYRIAC				   = 96, /**< Syrj */
	I18N_USCRIPT_EASTERN_SYRIAC				   = 97, /**< Syrn */
	I18N_USCRIPT_TENGWAR					   = 98, /**< Teng */
	I18N_USCRIPT_VAI						   = 99, /**< Vaii */
	I18N_USCRIPT_VISIBLE_SPEECH				   = 100,/**< Visp */
	I18N_USCRIPT_CUNEIFORM					   = 101,/**< Xsux */
	I18N_USCRIPT_UNWRITTEN_LANGUAGES		   = 102,/**< Zxxx */
	I18N_USCRIPT_UNKNOWN					   = 103,/**< Zzzz, Unknown="Code for uncoded script", for unassigned code points */
	I18N_USCRIPT_CARIAN						   = 104,/**< Cari */
	I18N_USCRIPT_JAPANESE					   = 105,/**< Jpan */
	I18N_USCRIPT_LANNA						   = 106,/**< Lana */
	I18N_USCRIPT_LYCIAN						   = 107,/**< Lyci */
	I18N_USCRIPT_LYDIAN						   = 108,/**< Lydi */
	I18N_USCRIPT_OL_CHIKI					   = 109,/**< Olck */
	I18N_USCRIPT_REJANG						   = 110,/**< Rjng */
	I18N_USCRIPT_SAURASHTRA					   = 111,/**< Saur */
	I18N_USCRIPT_SIGN_WRITING				   = 112,/**< Sgnw */
	I18N_USCRIPT_SUNDANESE					   = 113,/**< Sund */
	I18N_USCRIPT_MOON						   = 114,/**< Moon */
	I18N_USCRIPT_MEITEI_MAYEK				   = 115,/**< Mtei */
	I18N_USCRIPT_IMPERIAL_ARAMAIC			   = 116,/**< Armi */
	I18N_USCRIPT_AVESTAN					   = 117,/**< Avst */
	I18N_USCRIPT_CHAKMA						   = 118,/**< Cakm */
	I18N_USCRIPT_KOREAN						   = 119,/**< Kore */
	I18N_USCRIPT_KAITHI						   = 120,/**< Kthi */
	I18N_USCRIPT_MANICHAEAN					   = 121,/**< Mani */
	I18N_USCRIPT_INSCRIPTIONAL_PAHLAVI		   = 122,/**< Phli */
	I18N_USCRIPT_PSALTER_PAHLAVI			   = 123,/**< Phlp */
	I18N_USCRIPT_BOOK_PAHLAVI				   = 124,/**< Phlv */
	I18N_USCRIPT_INSCRIPTIONAL_PARTHIAN		   = 125,/**< Prti */
	I18N_USCRIPT_SAMARITAN					   = 126,/**< Samr */
	I18N_USCRIPT_TAI_VIET					   = 127,/**< Tavt */
	I18N_USCRIPT_MATHEMATICAL_NOTATION		   = 128,/**< Zmth */
	I18N_USCRIPT_SYMBOLS					   = 129,/**< Zsym */
	I18N_USCRIPT_BAMUM						   = 130,/**< Bamu */
	I18N_USCRIPT_LISU						   = 131,/**< Lisu */
	I18N_USCRIPT_NAKHI_GEBA					   = 132,/**< Nkgb */
	I18N_USCRIPT_OLD_SOUTH_ARABIAN			   = 133,/**< Sarb */
	I18N_USCRIPT_BASSA_VAH					   = 134,/**< Bass */
	I18N_USCRIPT_DUPLOYAN_SHORTAND			   = 135,/**< Dupl */
	I18N_USCRIPT_ELBASAN					   = 136,/**< Elba */
	I18N_USCRIPT_GRANTHA					   = 137,/**< Gran */
	I18N_USCRIPT_KPELLE						   = 138,/**< Kpel */
	I18N_USCRIPT_LOMA						   = 139,/**< Loma */
	I18N_USCRIPT_MENDE						   = 140,/**< Mend */
	I18N_USCRIPT_MEROITIC_CURSIVE			   = 141,/**< Merc */
	I18N_USCRIPT_OLD_NORTH_ARABIAN			   = 142,/**< Narb */
	I18N_USCRIPT_NABATAEAN					   = 143,/**< Nbat */
	I18N_USCRIPT_PALMYRENE					   = 144,/**< Palm */
	I18N_USCRIPT_SINDHI						   = 145,/**< Sind */
	I18N_USCRIPT_WARANG_CITI				   = 146,/**< Wara */
	I18N_USCRIPT_AFAKA						   = 147,/**< Afak */
	I18N_USCRIPT_JURCHEN					   = 148,/**< Jurc */
	I18N_USCRIPT_MRO						   = 149,/**< Mroo */
	I18N_USCRIPT_NUSHU						   = 150,/**< Nshu */
	I18N_USCRIPT_SHARADA					   = 151,/**< Shrd */
	I18N_USCRIPT_SORA_SOMPENG				   = 152,/**< Sora */
	I18N_USCRIPT_TAKRI						   = 153,/**< Takr */
	I18N_USCRIPT_TANGUT						   = 154,/**< Tang */
	I18N_USCRIPT_WOLEAI						   = 155,/**< Wole */
	I18N_USCRIPT_ANATOLIAN_HIEROGLYPHS		   = 156,/**< Hluw */
	I18N_USCRIPT_KHOJKI						   = 157,/**< Khoj */
	I18N_USCRIPT_TIRHUTA					   = 158,/**< Tirh */
	I18N_USCRIPT_CODE_LIMIT					   = 159 /**< Count of i18n_uscript_code_e enumerators*/
} i18n_uscript_code_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_FORMAT_MODULE
 * @{
 */

/**
 * @brief Handle to the object of base class for all formats.
 * @since_tizen 3.0
 */
typedef void *i18n_format_h;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MEASURE_FORMAT_MODULE
 * @{
 */

/**
 * @brief Handle to the object that represents a formatter for measure objects.
 * @since_tizen 3.0
 */
typedef void *i18n_measure_format_h;

/**
 * @brief Enumeration for various widths.
 * @since_tizen 3.0
 */
typedef enum {
	I18N_UMEASFMT_WIDTH_WIDE = 0,	  /**< Spell out measure units */
	I18N_UMEASFMT_WIDTH_SHORT = 1,	  /**< Abbreviate measure units */
	I18N_UMEASFMT_WIDTH_NARROW = 2,	  /**< Use symbols for measure units when possible */
	I18N_UMEASFMT_WIDTH_NUMERIC = 3,  /**< Completely omit measure units when possible
									  For example, format '5 hours, 37 minutes' as '5:37' */
	I18N_UMEASFMT_WIDTH_COUNT = 4,	  /**< Count of values in this enumeration */
} i18n_umeasure_format_width_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE
 * @{
 */

/**
 * @brief Handle to the object of class used for formatting #i18n_format_h and its subclasses.
 * @since_tizen 3.0
 */
typedef void *i18n_formattable_h;

/**
 * @brief Enumeration for the flavor of data type contained within an #i18n_formattable_h object.
 * @since_tizen 3.0
 */
typedef enum {
	I18N_FORMATTABLE_TYPE_DATE = 0,	   /**< Selector indicating an #i18n_udate value */
	I18N_FORMATTABLE_TYPE_DOUBLE = 1,  /**< Selector indicating a double value */
	I18N_FORMATTABLE_TYPE_LONG = 2,	   /**< Selector indicating a 32-bit integer value */
	I18N_FORMATTABLE_TYPE_STRING = 3,  /**< Selector indicating a string value */
	I18N_FORMATTABLE_TYPE_ARRAY = 4,   /**< Selector indicating an array of #i18n_formattable_h */
	I18N_FORMATTABLE_TYPE_INT64 = 5,   /**< Selector indicating a 64-bit integer value */
	I18N_FORMATTABLE_TYPE_OBJECT = 6,  /**< Selector indicating a generic object value.
											In the current version of the API, such objects
											are not supported and cannot be used. This value
											was added for completeness and possible future extensions. */
} i18n_formattable_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MEASURE_MODULE
 * @{
 */

/**
 * @brief Handle to the object that represents an amount of a specified unit.
 * @since_tizen 3.0
 */
typedef void *i18n_measure_h;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE
 * @{
 */

/**
 * @brief Handle to the object that represents a unit such as length, mass, volume, currency, etc.
 * @since_tizen 3.0
 */
typedef void *i18n_measure_unit_h;

/**
 * @brief Callback function for the i18n_measure_unit_get_available_types()
 *		  that returns an enumeration over all recognized types.
 * @since_tizen 3.0
 *
 * @param[in] type_id	 The type ID
 * @param[in] user_data	 The user data passed to the callback function
 *
 * @return @c true to continue with the next iteration of the loop,
 *		   otherwise @c false to break out of the loop.
 */
typedef bool (*i18n_measure_unit_types_cb)(const char *type_id, void *user_data);

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ALPHA_IDX_MODULE
 * @{
 */

/**
 * @brief The Alphabetic index handle.
 * @since_tizen 3.0
 */
typedef void *i18n_alpha_idx_h;

/**
 * @brief Enumeration for alphabetic index label types.
 * @since_tizen 3.0
 *
 * @see i18n_alpha_idx_get_bucket_label_type()
 */
typedef enum {
	/**
	 * Normal Label, typically the starting letter of the names in the bucket with this label.
	 */
	I18N_ALPHA_IDX_NORMAL,

	/**
	 * Underflow Label.
	 *
	 * The bucket with this label contains names in scripts that sort before any
	 * of the bucket labels in this index.
	 */
	I18N_ALPHA_IDX_UNDERFLOW,

	/**
	 * Inflow Label.
	 *
	 * The bucket with this label contains names in scripts that sort between
	 * two of the bucket labels in this index. Inflow labels are created when
	 * an index contains normal labels for multiple scripts, and skips other
	 * scripts that sort between some of the included scripts.
	 */
	I18N_ALPHA_IDX_INFLOW,

	/**
	 * Overflow Label.
	 *
	 * The bucket with this label contains names in scripts that sort after
	 * all of the bucket labels in this index.
	 */
	I18N_ALPHA_IDX_OVERFLOW,
} i18n_alpha_idx_label_type_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_FIELD_POSITION_MODULE
 * @{
 */

/**
 * @brief Handle to the object of class used by the #i18n_format_h and its subclasses to identify fields in a formatted output.
 * @since_tizen 3.0
 */
typedef void *i18n_field_position_h;

/**
 * @brief DONT_CARE may be specified as the field to indicate that the caller doesn't need to specify a field.
 * @since_tizen 3.0
 */
typedef enum {
	I18N_FIELD_POSITION_DONT_CARE = -1,
} i18n_field_position_dont_care_e;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_PARSE_POSITION_MODULE
 * @{
 */

/**
 * @brief Handle to the object used by the Format and its subtypes to keep track of the current position during parsing.
 * @since_tizen 3.0
 */
typedef void *i18n_parse_position_h;

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USHAPE_MODULE
 * @{
 */

/**
 * @brief Memory option: allow the result to have a different length than the source.
 * @details Affects: LamAlef options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LENGTH_GROW_SHRINK				0

/**
 * @brief Memory option: allow the result to have a different length than the source.
 * @details Affects: LamAlef options
 *
 *			This option is an alias to #I18N_USHAPE_LENGTH_GROW_SHRINK.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_RESIZE					0

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces next to modified characters.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LENGTH_FIXED_SPACES_NEAR		1

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces next to modified characters.
 *
 *			Affects: LamAlef options
 *
 *			This option is an alias to #I18N_USHAPE_LENGTH_FIXED_SPACES_NEAR.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_NEAR					1

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces at the end of the text.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LENGTH_FIXED_SPACES_AT_END		2

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces at the end of the text.
 *
 *			Affects: LamAlef options
 *
 *			This option is an alias to #I18N_USHAPE_LENGTH_FIXED_SPACES_AT_END.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_END						2

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces at the beginning of the text.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LENGTH_FIXED_SPACES_AT_BEGINNING 3

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details If more room is necessary, then try to consume spaces at the beginning of the text.
 *
 *			Affects: LamAlef options
 *
 *			This option is an alias to #i18N_USHAPE_LENGTH_FIXED_SPACES_AT_BEGINNING.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_BEGIN					 3

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping Mode: For each LAMALEF character found, expand LAMALEF using space at end.
 *				 If there is no space at end, use spaces at beginning of the buffer. If there
 *				 is no space at beginning of the buffer, use spaces at the near (i.e. the space
 *				 after the LAMALEF character).
 *				 If there are no spaces found, an #I18N_ERROR_NO_SPACE_AVAILABLE error will be
 *				 returned by the i18n_ushape_shape_arabic() function.
 *
 *			Deshaping Mode: Perform the same function as the flag equals #I18N_USHAPE_LAMALEF_END.
 *
 *			Affects: LamAlef options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_AUTO					 0x10000

/**
 * @brief Bit mask for memory options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LENGTH_MASK						 0x10003

/**
 * @brief Bit mask for LamAlef memory options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LAMALEF_MASK					 0x10003

/**
 * @brief Direction indicator: the source is in logical (keyboard) order.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TEXT_DIRECTION_LOGICAL			0

/**
 * @brief Direction indicator: the source is in visual RTL order,
 *		  the rightmost displayed character stored first.
 *
 *		  This option is an alias to #I18N_USHAPE_TEXT_DIRECTION_LOGICAL.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TEXT_DIRECTION_VISUAL_RTL		0

/**
 * @brief Direction indicator: the source is in visual LTR order,
 *		  the leftmost displayed character stored first.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TEXT_DIRECTION_VISUAL_LTR		4

/**
 * @brief Bit mask for direction indicators.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TEXT_DIRECTION_MASK				4

/**
 * @brief Letter shaping option: do not perform letter shaping.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LETTERS_NOOP					0

/**
 * @brief Letter shaping option: replace abstract letter characters by "shaped" ones.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LETTERS_SHAPE					8

/**
 * @brief Letter shaping option: replace "shaped" letter characters by abstract ones.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LETTERS_UNSHAPE					0x10

/**
 * @brief Letter shaping option: replace abstract letter characters by "shaped" ones.
 * @details The only difference with #I18N_USHAPE_LETTERS_SHAPE is that Tashkeel letters
 *			are always "shaped" into the isolated form instead of the medial form
 *			(selecting code points from the Arabic Presentation Forms-B block).
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LETTERS_SHAPE_TASHKEEL_ISOLATED 0x18

/**
 * @brief Bit mask for letter shaping options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_LETTERS_MASK					0x18

/**
 * @brief Digit shaping option: do not perform digit shaping.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_NOOP						0

/**
 * @brief Digit shaping option: replace European digits (U+0030...) by Arabic-Indic digits.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_EN2AN					0x20

/**
 * @brief Digit shaping option: replace Arabic-Indic digits by European digits (U+0030...).
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_AN2EN					0x40

/**
 * @brief Digit shaping option: replace European digits (U+0030...) by Arabic-Indic digits
 *		  if the most recent strongly directional character is an Arabic letter.
 *
 * @details The direction of "preceding" depends on the direction indicator option.
 *			For the first characters, the preceding strongly directional character
 *			(initial state) is assumed to be not an Arabic letter
 *			(it is #I18N_UCHAR_U_LEFT_TO_RIGHT [L] or #I18N_UCHAR_U_RIGHT_TO_LEFT [R]).
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_ALEN2AN_INIT_LR			0x60

/**
 * @brief Digit shaping option: replace European digits (U+0030...) by Arabic-Indic digits
 *		  if the most recent strongly directional character is an Arabic letter.
 *
 * @details The direction of "preceding" depends on the direction indicator option.
 *			For the first characters, the preceding strongly directional character
 *			(initial state) is assumed to be an Arabic letter.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_ALEN2AN_INIT_AL			0x80

/**
 * @brief Not a valid option value. May be replaced by a new option.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_RESERVED					0xa0

/**
 * @brief Bit mask for digit shaping options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGITS_MASK						0xe0

/**
 * @brief Digit type option: Use Arabic-Indic digits (U+0660...U+0669).
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGIT_TYPE_AN					0

/**
 * @brief Digit type option: Use Eastern (Extended) Arabic-Indic digits (U+06f0...U+06f9).
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGIT_TYPE_AN_EXTENDED			0x100

/**
 * @brief Not a valid option value. May be replaced by a new option.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGIT_TYPE_RESERVED				0x200

/**
 * @brief Bit mask for digit type options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_DIGIT_TYPE_MASK					0x300

/**
 * @brief Tashkeel aggregation option: replace any combination of U+0651 with one of
 *		  U+064C, U+064D, U+064E, U+064F, U+0650 with
 *		  U+FC5E, U+FC5F, U+FC60, U+FC61, U+FC62 consecutively.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_AGGREGATE_TASHKEEL				0x4000

/**
 * @brief Tashkeel aggregation option: do not aggregate tashkeels.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_AGGREGATE_TASHKEEL_NOOP			0

/**
 * @brief Bit mask for tashkeel aggregation.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_AGGREGATE_TASHKEEL_MASK			0x4000

/**
 * @brief Presentation form option: don't replace Arabic Presentation Forms-A and
 *		  Arabic Presentation Forms-B characters with 0+06xx characters, before shaping.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_PRESERVE_PRESENTATION			0x8000

/**
 * @brief Presentation form option: replace Arabic Presentation Forms-A and
 *		  Arabic Presentationo Forms-B with their unshaped correspondants in range 0+06xx,
 *		  before shaping.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_PRESERVE_PRESENTATION_NOOP		0

/**
 * @brief Bit mask for preserve presentation form.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_PRESERVE_PRESENTATION_MASK		0x8000


/* Seen Tail options */

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping mode: The SEEN family character will expand into two characters using space near
 *						  the SEEN family character (i.e. the space after the character).
 *
 *			If there are no spaces found, an #I18N_ERROR_NO_SPACE_AVAILABLE error will be
 *			returned by the i18n_ushape_shape_arabic() function.
 *
 *			De-shaping mode: Any Seen character followed by Tail character will be
 *							 replaced by one cell Seen and a space will replace the Tail.
 *
 *			Affects: Seen options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_SEEN_TWOCELL_NEAR	  0x200000

/**
 * @brief Bit mask for Seen memory options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_SEEN_MASK			  0x700000


/* YehHamza options */

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping mode: The YEHHAMZA character will expand into two characters using space near it
 *						  (i.e. the space after the character).
 *
 *			If there are no spaces found, an #I18N_ERROR_NO_SPACE_AVAILABLE error will be
 *			returned by the i18n_ushape_shape_arabic() function.
 *
 *			De-shaping mode: Any Yeh (final or isolated) character followed by Hamza character will
 *			be replaced by one cell YehHamza and space will replace the Hamza.
 *
 *			Affects: YehHamza options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_YEHHAMZA_TWOCELL_NEAR	   0x1000000

/**
 * @brief Bit mask for YehHamza memory options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_YEHHAMZA_MASK			   0x3800000


/* New Tashkeel options */

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping mode: Tashkeel characters will be replaced by spaces.
 *						  Spaces will be placed at beginning of the buffer.
 *
 *			De-shaping mode: N/A
 *
 *			Affects: Tashkeel options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TASHKEEL_BEGIN						0x40000

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping mode: Tashkeel characters will be replaced by spaces.
 *						  Spaces will be placed at end of the buffer.
 *
 *			De-shaping mode: N/A
 *
 *			Affects: Tashkeel options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TASHKEEL_END						0x60000

/**
 * @brief Memory option: allow the result to have a different length than the source.
 * @details Shaping mode: Tashkeel characters will be removed, buffer length will shrink.
 *
 *			De-shaping mode: N/A
 *
 *			Affect: Tashkeel options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TASHKEEL_RESIZE						0x80000

/**
 * @brief Memory option: the result must have the same length as the source.
 * @details Shaping mode: Tashkeel characters will be replaced by Tatweel if it is connected to
 *						  adjacent characters (i.e. shaped on Tatweel) or replaced by space if it
 *						  is not connected.
 *
 *			De-shaping mode: N/A
 *
 *			Affects: YehHamza options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TASHKEEL_REPLACE_BY_TATWEEL			0xC0000

/**
 * @brief Bit mask for Tashkeel replacement with Space or Tatweel memory options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TASHKEEL_MASK						0xE0000


/* Space location control options */

/**
 * @brief This option affect the meaning of BEGIN and END options.
 * @details If this option is not used the default for BEGIN and END will be as following:
 *			The Default (for both Visual LTR, Visual RTL and Logical Text)
 *				1. BEGIN always refers to the start address of physical memory.
 *				2. END always refers to the end address of physical memory.
 *
 *			If this option is used it will swap the meaning of BEGIN and END only for Visual LTR
 *			text.
 *
 *			The effect on BEGIN and END Memory Options will be as following:
 *				A. BEGIN For Visual LTR text: This will be the beginning (right side) of the visual
 *				   text (corresponding to the physical memory address end for Visual LTR text,
 *				   Same as END in default behavior).
 *				B. BEGIN For Logical text: Same as BEGIN in default behavior.
 *				C. END For Visual LTR text: This will be the end (left side) of the visual text
 *				   (corresponding to the physical memory address beginning for Visual LTR text,
 *				   Same as BEGIN in default behavior).
 *				D. END For Logical text: Same as END in default behavior.
 *
 *			Affects: All LamAlef BEGIN, END and AUTO options.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_SPACES_RELATIVE_TO_TEXT_BEGIN_END 0x4000000

/**
 * @brief Bit mask for swapping BEGIN and END for Visual LTR text.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_SPACES_RELATIVE_TO_TEXT_MASK	  0x4000000

/**
 * @brief If this option is used, shaping will use the new Unicode code point for TAIL (i.e. 0xFE73).
 * @details If this option is not specified (Default), old unofficial Unicode TAIL code point is
 *			used (i.e. 0x200B).
 *
 *			De-shaping will not use this option as it will always search for both the new Unicode
 *			code point for the TAIL (i.e. 0xFE73) or the old unofficial Unicode TAIL code point
 *			(i.e. 0x200B) and de-shape the Seen-Family letter accordingly.
 *
 *			Shaping Mode: Only shaping.
 *
 *			De-shaping Mode: N/A.
 *
 *			Affects: All Seen options
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TAIL_NEW_UNICODE		0x8000000

/**
 * @brief Bit mask for new Unicode Tail option.
 * @since_tizen 3.0
 */
#define I18N_USHAPE_TAIL_TYPE_MASK			0x8000000

/**
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UTMSCALE_MODULE
 * @{
 */

/**
 * @brief Enumeration for the values used to specify the time scale used for conversion into or out of the universal time scale.
 * @since_tizen 3.0
 */
typedef enum {
	I18N_UTMSCALE_JAVA_TIME = 0,				/**< Used in the JDK. Data is a Java long (int64_t). Value is milliseconds since January 1, 1970.*/
	I18N_UTMSCALE_UNIX_TIME,					/**< Used on Unix systems. Data is an int32_t or int64_t. Value is seconds since January 1, 1970.*/
	I18N_UTMSCALE_ICU4C_TIME,					/**< Used in ICU4C. Data is a double. Value is milliseconds since January 1, 1970.*/
	I18N_UTMSCALE_WINDOWS_FILE_TIME,			/**< Used in Windows for file times. Data is an int64_t. Value is ticks (1 tick == 100 nanoseconds) since January 1, 1601.*/
	I18N_UTMSCALE_DOTNET_DATE_TIME,				/**< Used in the .NET framework's System.DateTime structure. Data is an int64_t. Value is ticks (1 tick == 100 nanoseconds) since January 1, 0001.*/
	I18N_UTMSCALE_MAC_OLD_TIME,					/**< Used in older Macintosh systems. Data is an int32_t or int64_t. Value is seconds since January 1, 1904.*/
	I18N_UTMSCALE_MAC_TIME,						/**< Used in newer Macintosh systems. Data is a double. Value is seconds since January 1, 2001.*/
	I18N_UTMSCALE_EXCEL_TIME,					/**< Used in Excel. Value is days since December 31, 1899.*/
	I18N_UTMSCALE_DB2_TIME,						/**< Used in DB2. Value is days since December 31, 1899.*/
	I18N_UTMSCALE_UNIX_MICROSECONDS_TIME,		/**< Data is a long. Value is microseconds since January 1, 1970. Similar to Unix time (linear value from 1970) and struct timeval (microseconds resolution).*/
	I18N_UTMSCALE_MAX_SCALE						/**< The first unused time scale value. The limit of this enum */
} i18n_utmscale_scale_e;


/**
 * @brief Enumeration for the values used to specify the time scale values to i18n_utmscale_get_time_scale_value().
 * @since_tizen 3.0
 *
 * @see i18n_utmscale_get_time_scale_value()
 */
typedef enum {
	I18N_UTMSCALE_VALUE_UNITS = 0,				/**< The constant used to select the units value for a time scale. */
	I18N_UTMSCALE_VALUE_EPOCH_OFFSET = 1,		/**< The constant used to select the epoch offset value for a time scale. */
	I18N_UTMSCALE_VALUE_FROM_MIN = 2,			/**< The constant used to select the minimum from value for a time scale. */
	I18N_UTMSCALE_VALUE_FROM_MAX = 3,			/**< The constant used to select the maximum from value for a time scale. */
	I18N_UTMSCALE_VALUE_TO_MIN = 4,				/**< The constant used to select the minimum to value for a time scale. */
	I18N_UTMSCALE_VALUE_TO_MAX = 5,				/**< The constant used to select the maximum to value for a time scale. */
	I18N_UTMSCALE_VALUE_MAX						/**< The number of time scale values, in other words limit of this enum.*/
} i18n_utmscale_value_e;

/**
 * @}
 */


/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UBIDI_MODULE
 * @{
 */

/**
 * @brief Value returned by i18n_ubidi_class_cb() callbacks when there is no need to override the standard ubidi class for a given code point.
 * @since_tizen 3.0
 */
#define I18N_UBIDI_CLASS_DEFAULT			I18N_UCHAR_U_CHAR_DIRECTION_COUNT

/**
 * @brief Paragraph level setting: Constant indicating that the base direction depends on the first
 *		  strong directional character in the text according to the Unicode Bidirectional Algorithm.
 *		  If no strong directional character is present, then set the paragraph level to 0
 *		  (left-to-right).
 * @details If this value is used in conjunction with reordering modes
 *			#I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT or #I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL,
 *			the text to reorder is assumed to be visual LTR, and the text after reordering is
 *			required to be the corresponding logical string with appropriate contextual direction.
 *			The direction of the result string will be RTL if either the rightmost or leftmost
 *			strong character of the source text is RTL or Arabic Letter, the direction will be LTR
 *			otherwise.
 *
 *			If reordering option #I18N_UBIDI_OPTION_INSERT_MARKS is set, an RLM may be
 *			added at the beginning of the result string to ensure round trip (that the result
 *			string, when reordered back to visual, will produce the original source text).
 * @since_tizen 3.0
 * @see I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT
 * @see I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL
 */
#define I18N_UBIDI_DEFAULT_LTR				0xfe

/**
 * @brief Paragraph level setting:
 *
 *		  Constant indicating that the base direction depends on the first
 *		  strong directional character in the text according to the Unicode Bidirectional Algorithm.
 *		  If no strong directional character is present, then set the paragraph level to 1
 *		  (right-to-left).
 * @details If this value is used in conjunction with reordering modes
 *			#I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT or #I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL,
 *			the text to reorder is assumed to be visual LTR, and the text after reordering is
 *			required to be the corresponding logical string with appropriate contextual direction.
 *			The direction of the result string will be RTL if either the rightmost or leftmost
 *			strong character of the source text is RTL or Arabic Letter, or if the text contains no
 *			strong character; the direction will be LTR otherwise.
 *
 *			If reordering option
 *			#I18N_UBIDI_OPTION_INSERT_MARKS is set, an RLM may be added at the beginning of the
 *			result string to ensure round trip (that the result string, when reordered back to
 *			visual, will produce the original source text).
 * @since_tizen 3.0
 * @see I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT
 * @see I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL
 */
#define I18N_UBIDI_DEFAULT_RTL			   0xff

/**
 * @brief Option bit for i18n_ubidi_write_reordered(): replace characters with the "mirrored"
 *		  property in RTL runs by their mirror-image mappings.
 * @since_tizen 3.0
 * @see i18n_ubidi_write_reordered()
 */
#define I18N_UBIDI_DO_MIRRORING				2

/**
 * @brief Option bit for i18n_ubidi_write_reordered(): surround the run with LRMs if necessary;
 *		  this is part of the approximate "inverse ubidi" algorithm.
 * @details This option does not imply corresponding adjustment of the index mappings.
 * @since_tizen 3.0
 * @see i18n_ubidi_set_inverse()
 * @see i18n_ubidi_write_reordered()
 */
#define I18N_UBIDI_INSERT_LRM_FOR_NUMERIC	4

/**
 * @brief Option bit for i18n_ubidi_write_reordered(): keep combining characters after their base
 *		  characters in RTL runs.
 * @since_tizen 3.0
 * @see i18n_ubidi_write_reordered()
 */
#define I18N_UBIDI_KEEP_BASE_COMBINING		1

/**
 * @brief Bit flag for level input.
 * @details Overrides directional properties.
 * @since_tizen 3.0
 */
#define I18N_UBIDI_LEVEL_OVERRIDE			0x80

/**
 * @brief Special value which can be returned by the mapping functions when a logical index has no
 *		  corresponding visual index or vice-versa.
 * @details This may happen for the logical-to-visual mapping of a ubidi control when option
 *			#I18N_UBIDI_OPTION_REMOVE_CONTROLS is specified. This can also happen for the
 *			visual-to-logical mapping of a ubidi mark (LRM or RLM) inserted by option
 *			#I18N_UBIDI_OPTION_INSERT_MARKS.
 * @since_tizen 3.0
 * @see i18n_ubidi_get_visual_index()
 * @see i18n_ubidi_get_visual_map()
 * @see i18n_ubidi_get_logical_index()
 * @see i18n_ubidi_get_logical_map()
 */
#define I18N_UBIDI_MAP_NOWHERE				(-1)

/**
 * @brief Maximum explicit embedding level.
 * @details The maximum resolved level can be up to #I18N_UBIDI_MAX_EXPLICIT_LEVEL + 1.
 * @since_tizen 3.0
 */
#define I18N_UBIDI_MAX_EXPLICIT_LEVEL		125

/**
 * @brief Option bit for i18n_ubidi_write_reordered(): write the output in reverse order.
 * @details This has the same effect as calling i18n_ubidi_write_reordered() first without this
 *			option, and then calling i18n_ubidi_write_reordered() without mirroring. Doing this
 *			in the same step is faster and avoids a temporary buffer. An example for using this
 *			option is output to a character terminal that is designed for RTL scripts and stores
 *			text in reverse order.
 * @since_tizen 3.0
 * @see i18n_ubidi_write_reordered()
 */
#define I18N_UBIDI_OUTPUT_REVERSE			16

/**
 * @brief Option bit for i18n_ubidi_write_reordered(): remove ubidi control characters (this does
 *		  not affect #I18N_UBIDI_INSERT_LRM_FOR_NUMERIC).
 * @details This option does not imply corresponding adjustment of the index mappings.
 * @since_tizen 3.0
 * @see i18n_ubidi_write_reordered()
 */
#define I18N_UBIDI_REMOVE_BIDI_CONTROLS		8

/**
 * @brief An #i18n_ubidi_h handle.
 * @details Use i18n_ubidi_* functions to operate on Ubidi objects.
 * @since_tizen 3.0
 */
typedef void *i18n_ubidi_h;

/**
 * @brief Callback type declaration for overriding default ubidi class values with custom ones.
 * @details Usually, the function pointer will be propagated to an #i18n_ubidi_h handle by calling
 *			the i18n_ubidi_set_class_cb() function; then the callback will be invoked by the UBA
 *			implementation any time the class of a character is to be determined.
 * @since_tizen 3.0
 *
 * @param[in]  context	 A pointer to the callback private data
 * @param[in]  c		 The code point to get a ubidi class for
 *
 * @retval direction	 The directional property / ubidi class for the given code point @a c if
 *						 the default class has been overridden, or #I18N_UBIDI_CLASS_DEFAULT if
 *						 the standard ubidi class value for code point @a c is to be used.
 *
 * @see i18n_ubidi_set_class_cb()
 * @see i18n_ubidi_get_class_cb()
 */
typedef i18n_uchar_direction_e(*i18n_ubidi_class_cb)(const void *context, i18n_uchar32 c);

/**
 * @brief The type of the level values in this ubidi implementation.
 * @details It holds an embedding level and indicates the visual direction by its bit 0
 *			(even/odd value).
 *
 *			It can also hold non-level values for the @c para_level and @c embedding_levels
 *			arguments of i18n_ubidi_set_para(); there:
 *			- bit 7 of an @c embedding_levels[] value indicates whether the using application is
 *			specifying the level of a character to override whatever the ubidi implementation would
 *			resolve it to.
 *			- @c para_level can be set to the pseudo-level values #I18N_UBIDI_DEFAULT_LTR and
 *			#I18N_UBIDI_DEFAULT_RTL.
 *
 *			The related constants are not real, valid level values. I18N_UBIDI_DEFAULT_XXX can be
 *			used to specify a default for the paragraph level for when the i18n_ubidi_set_para()
 *			function shall determine it but there is no strongly typed character in the input.
 *
 *			Note that the value for #I18N_UBIDI_DEFAULT_LTR is even and the one for
 *			#I18N_UBIDI_DEFAULT_RTL is odd, just like with normal LTR and RTL level values - these
 *			special values are designed that way. Also, the implementation assumes that
 *			#I18N_UBIDI_MAX_EXPLICIT_LEVEL is odd.
 *
 * @see i18n_ubidi_set_para()
 * @see I18N_UBIDI_DEFAULT_LTR
 * @see I18N_UBIDI_DEFAULT_RTL
 * @see I18N_UBIDI_LEVEL_OVERRIDE
 * @see I18N_UBIDI_MAX_EXPLICIT_LEVEL
 */
typedef uint8_t i18n_ubidi_level_t;


/**
 * @brief Enumeration for text direction.
 * @since_tizen 3.0
 */
typedef enum {
	/**
	 * Left-to-right text. This is a 0 value.
	 * - As return value for i18n_ubidi_get_direction(), it means that the source string contains
	 * no right-to-left characters, or that the source string is empty and the paragraph level is
	 * even.
	 * - As return value for i18n_ubidi_get_base_direction(), it means that the first strong
	 * character of the source string has a left-to-right direction.
	 */
	I18N_UBIDI_LTR,

	/**
	 * Right-to-left text. This is a 1 value.
	 * - As return value for i18n_ubidi_get_direction(), it means that the source string contains
	 * no left-to-right characters, or that the source string is empty and the paragraph level is odd.
	 * - As return value for i18n_ubidi_get_base_direction(), it means that the first strong character
	 * of the source string has a right-to-left direction.
	 */
	I18N_UBIDI_RTL,

	/**
	 * Mixed-directional text.
	 *
	 * As return value for i18n_ubidi_get_direction(), it means that the
	 * source string contains both left-to-right and right-to-left characters.
	 */
	I18N_UBIDI_MIXED,

	/**
	 * No strongly directional text.
	 *
	 * As return value for i18n_ubidi_get_direction(), it means that
	 * the source string is missing or empty, or contains neither left-to-right nor right-to-left
	 * characters.
	 */
	I18N_UBIDI_NEUTRAL
} i18n_ubidi_direction_e;


/**
 * @brief Enumeration for reordering mode.
 * @details These values indicate which variant of the ubidi algorithm to use.
 * @since_tizen 3.0
 * @see i18n_ubidi_set_reordering_mode()
 * @see i18n_ubidi_set_inverse()
 */
typedef enum {
	/**
	 * Regular Logical to Visual ubidi algorithm according to Unicode. This is a 0 value.
	 */
	I18N_UBIDI_REORDER_DEFAULT = 0,

	/**
	 * Logical to Visual algorithm which handles numbers in a way which mimicks the behavior of
	 * Windows XP.
	 */
	I18N_UBIDI_REORDER_NUMBERS_SPECIAL,

	/**
	 * Logical to Visual algorithm grouping numbers with adjacent R characters (reversible
	 * algorithm).
	 */
	I18N_UBIDI_REORDER_GROUP_NUMBERS_WITH_R,

	/**
	 * Reorder runs only to transform a Logical LTR string to the Logical RTL string with the same
	 * display, or vice-versa.
	 *
	 * If this mode is set together with option #I18N_UBIDI_OPTION_INSERT_MARKS, some ubidi
	 * controls in the source text may be removed and other controls may be added to produce the
	 * minimum combination which has the required display.
	 */
	I18N_UBIDI_REORDER_RUNS_ONLY,

	/**
	 * Visual to Logical algorithm which handles numbers like L (same algorithm as selected by
	 * i18n_ubidi_set_inverse(true).
	 */
	I18N_UBIDI_REORDER_INVERSE_NUMBERS_AS_L,

	/**
	 * Visual to Logical algorithm equivalent to the regular Logical to Visual algorithm.
	 */
	I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT,

	/**
	 * Inverse ubidi (Visual to Logical) algorithm for the #I18N_UBIDI_REORDER_NUMBERS_SPECIAL
	 * ubidi algorithm.
	 */
	I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL,

	/**
	 * Number of values for reordering mode.
	 */
	I18N_UBIDI_REORDER_COUNT
} i18n_ubidi_reordering_mode_e;


/**
 * @brief Enumeration for reordering options.
 * @details These values indicate which options are specified to affect the ubidi algorithm.
 * @since_tizen 3.0
 * @see i18n_ubidi_set_reordering_options()
 * @see i18n_ubidi_set_inverse()
 */
typedef enum {
	/**
	 * Option value for i18n_ubidi_set_reordering_options(): disable all the options which can be set
	 * with this function.
	 */
	I18N_UBIDI_OPTION_DEFAULT = 0,

	/**
	 * Option bit for i18n_ubidi_set_reordering_options(): insert ubidi marks (LRM or RLM) when
	 * needed to ensure correct result of a reordering to a Logical order. This option must be set
	 * or reset before calling i18n_ubidi_set_para().
	 *
	 * This option is significant only with reordering modes which generate a result with Logical
	 * order, specifically:
	 *	   - #I18N_UBIDI_REORDER_RUNS_ONLY
	 *	   - #I18N_UBIDI_REORDER_INVERSE_NUMBERS_AS_L
	 *	   - #I18N_UBIDI_REORDER_INVERSE_LIKE_DIRECT
	 *	   - #I18N_UBIDI_REORDER_INVERSE_FOR_NUMBERS_SPECIAL
	 *
	 * If this option is set in conjunction with reordering mode
	 * #I18N_UBIDI_REORDER_INVERSE_NUMBERS_AS_L or with calling i18n_ubidi_set_inverse(true), it
	 * implies option #I18N_UBIDI_INSERT_LRM_FOR_NUMERIC in calls to function
	 * i18n_ubidi_write_reordered().
	 *
	 * For other reordering modes, a minimum number of LRM or RLM characters will be added to the
	 * source text after reordering it so as to ensure round trip, i.e. when applying the inverse
	 * reordering mode on the resulting logical text with removal of ubidi marks (option
	 * #I18N_UBIDI_OPTION_REMOVE_CONTROLS set before calling i18n_ubidi_set_para() or option
	 * #I18N_UBIDI_REMOVE_BIDI_CONTROLS in i18n_ubidi_write_reordered(), the result will be identical
	 * to the source text in the first transformation.
	 *
	 * This option will be ignored if specified together with option
	 * #I18N_UBIDI_OPTION_REMOVE_CONTROLS. It inhibits option #I18N_UBIDI_REMOVE_BIDI_CONTROLS in
	 * calls to function i18n_ubidi_write_reordered() and it implies option
	 * #I18N_UBIDI_INSERT_LRM_FOR_NUMERIC in calls to function i18n_ubidi_write_reordered() if the
	 * reordering mode is #I18N_UBIDI_REORDER_INVERSE_NUMBERS_AS_L.
	 *
	 * @see i18n_ubidi_set_reordering_mode()
	 * @see i18n_ubidi_set_reordering_options()
	 */
	I18N_UBIDI_OPTION_INSERT_MARKS = 1,

	/**
	 * Option bit for i18n_ubidi_set_reordering_options(): remove ubidi control characters.
	 *
	 * This option must be set or reset before calling i18n_ubidi_set_para().
	 *
	 * This option nullifies option #I18N_UBIDI_OPTION_INSERT_MARKS. It inhibits option
	 * #I18N_UBIDI_INSERT_LRM_FOR_NUMERIC in calls to function i18n_write_reordered() and it implies
	 * option #I18N_UBIDI_REMOVE_BIDI_CONTROLS in calls to that function.
	 *
	 * @see i18n_ubidi_set_reordering_mode()
	 * @see i18n_ubidi_set_reordering_options()
	 */
	I18N_UBIDI_OPTION_REMOVE_CONTROLS = 2,

	/**
	 * Option bit for i18n_ubidi_set_reordering_options(): process the output as part of a stream
	 * to be continued.
	 *
	 * This option must be set or reset before calling i18n_ubidi_set_para().
	 *
	 * This option specifies that the caller is interested in processing large text object in parts.
	 * The results of the successive calls are expected to be concatenated by the caller. Only the
	 * call for the last part will have this option bit off.
	 *
	 * When this option bit is on, i18n_ubidi_set_para() may process less than the full source text
	 * in order to truncate the text at a meaningful boundary. The caller should call
	 * i18n_ubidi_get_processed_length() immediately after calling i18n_ubidi_set_para()
	 * in order to determine how much of the source text has been processed.
	 * Source text beyond that length should be resubmitted in following calls to
	 * i18n_ubidi_set_para().
	 * The processed length may be less than the length of the source text if a character preceding
	 * the last character of the source text constitutes a reasonable boundary (like a block
	 * separator) for text to be continued. If the last character of the source text constitutes a
	 * reasonable boundary, the whole text will be processed at once.
	 * If nowhere in the source text there exists such a reasonable boundary, the processed length
	 * will be zero.
	 * The caller should check for such an occurrence and do one of the following:
	 *	   - submit a larger amount of text with a better chance to include a reasonable boundary.
	 *	   - resubmit the same text after turning off option #I18N_UBIDI_OPTION_STREAMING.
	 *
	 * In all cases, this option should be turned off before processing the last part of the text.
	 *
	 * When the #I18N_UBIDI_OPTION_STREAMING option is used, it is recommended to call
	 * i18n_ubidi_order_paragraphs_ltr() with argument order_paragraphs_ltr set to true before
	 * calling i18n_ubidi_set_para() so that later paragraphs may be concatenated to previous
	 * paragraphs on the right.
	 *
	 * @see i18n_ubidi_set_reordering_mode()
	 * @see i18n_ubidi_set_reordering_options()
	 * @see i18n_ubidi_get_processed_length()
	 * @see i18n_ubidi_order_paragraphs_ltr()
	 */
	I18N_UBIDI_OPTION_STREAMING = 4
} i18n_ubidi_reordering_option_e;

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	  /* __UTILS_I18N_TYPES_H__*/
