#ifndef _EDJE_TYPES_EOT_H_
#define _EDJE_TYPES_EOT_H_

#ifndef _EDJE_TYPES_EOT_TYPES
#define _EDJE_TYPES_EOT_TYPES

/** All available cursor states
 *
 * @ingroup Edje
 */
typedef enum
{
  EDJE_CURSOR_MAIN = 0, /** Main cursor state */
  EDJE_CURSOR_SELECTION_BEGIN, /** Selection begin cursor state */
  EDJE_CURSOR_SELECTION_END, /** Selection end cursor state */
  EDJE_CURSOR_PREEDIT_START, /** Pre-edit start cursor state */
  EDJE_CURSOR_PREEDIT_END, /** Pre-edit end cursor starge */
  EDJE_CURSOR_USER, /** User cursor state */
  EDJE_CURSOR_USER_EXTRA /** User extra cursor state */
} Edje_Cursor;

/** Dragable properties values
 *
 * @ingroup Edje
 */
typedef enum
{
  EDJE_DRAG_DIR_NONE = 0, /** Not dragable value */
  EDJE_DRAG_DIR_X = 1 /* 0 */, /** X dragable value */
  EDJE_DRAG_DIR_Y = 2 /* 0 */, /** Y dragable value */
  EDJE_DRAG_DIR_XY = 3 /* 0 */ /** X and Y dragable value */
} Edje_Drag_Dir;

/** Edje file loading error codes one can get - see edje_load_error_str() too.
 *
 * @ingroup Edje
 */
typedef enum
{
  EDJE_LOAD_ERROR_NONE = 0, /** No error happened, the loading was successful
                             */
  EDJE_LOAD_ERROR_GENERIC = 1 /* 0 */, /** A generic error happened during the
                                        * loading */
  EDJE_LOAD_ERROR_DOES_NOT_EXIST = 2 /* 0 */, /** The file pointed to did not
                                               * exist */
  EDJE_LOAD_ERROR_PERMISSION_DENIED = 3 /* 0 */, /** Permission to read the
                                                  * given file was denied */
  EDJE_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED = 4 /* 0 */, /** Resource
                                                           * allocation failed
                                                           * during the loading
                                                           */
  EDJE_LOAD_ERROR_CORRUPT_FILE = 5 /* 0 */, /** The file pointed to was corrupt
                                             */
  EDJE_LOAD_ERROR_UNKNOWN_FORMAT = 6 /* 0 */, /** The file pointed to had an
                                               * unknown format */
  EDJE_LOAD_ERROR_INCOMPATIBLE_FILE = 7 /* 0 */, /** The file pointed to is
                                                  * incompatible, i.e., it
                                                  * doesn't match the library's
                                                  * current version's format */
  EDJE_LOAD_ERROR_UNKNOWN_COLLECTION = 8 /* 0 */, /** The group/collection set
                                                   * to load from was not found
                                                   * in the file */
  EDJE_LOAD_ERROR_RECURSIVE_REFERENCE = 9 /* 0 */ /** The group/collection set
                                                   * to load from had
                                                   * <b>recursive
                                                   * references</b> on its
                                                   * components */
} Edje_Load_Error;

/** All Text auto capital mode type values
 *
 * @ingroup Edje_Text
 */
typedef enum
{
  EDJE_TEXT_AUTOCAPITAL_TYPE_NONE = 0, /** None mode value */
  EDJE_TEXT_AUTOCAPITAL_TYPE_WORD, /** Word mode value */
  EDJE_TEXT_AUTOCAPITAL_TYPE_SENTENCE, /** Sentence mode value */
  EDJE_TEXT_AUTOCAPITAL_TYPE_ALLCHARACTER /** All characters mode value */
} Edje_Text_Autocapital_Type;

typedef enum
{
  EDJE_INPUT_HINT_NONE = 0, /** No active hints
                             *
                             * @since 1.12 */
  EDJE_INPUT_HINT_AUTO_COMPLETE = 1 /* 0 << 0 */, /** Suggest word auto
                                                   * completion
                                                   *
                                                   * @since 1.12 */
  EDJE_INPUT_HINT_SENSITIVE_DATA = 2 /* 0 << 0 */ /** Typed text should not be
                                                   * stored.
                                                   *
                                                   * @since 1.12 */
} Edje_Input_Hints;

typedef enum
{
  EDJE_INPUT_PANEL_LANG_AUTOMATIC = 0, /** Automatic
                                        *
                                        * @since 1.2 */
  EDJE_INPUT_PANEL_LANG_ALPHABET /** Alphabet
                                  *
                                  * @since 1.2 */
} Edje_Input_Panel_Lang;

typedef enum
{
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT = 0, /** Default
                                                 *
                                                 * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_DONE, /** Done
                                          *
                                          * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_GO, /** Go
                                        *
                                        * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_JOIN, /** Join
                                          *
                                          * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_LOGIN, /** Login
                                           *
                                           * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_NEXT, /** Next
                                          *
                                          * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_SEARCH, /** Search or magnifier icon
                                            *
                                            * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_SEND, /** Send
                                          *
                                          * @since 1.2 */
  EDJE_INPUT_PANEL_RETURN_KEY_TYPE_SIGNIN /** Sign-in
                                           *
                                           * @since 1.8 */
} Edje_Input_Panel_Return_Key_Type;

typedef enum
{
  EDJE_INPUT_PANEL_LAYOUT_NORMAL = 0, /** Default layout */
  EDJE_INPUT_PANEL_LAYOUT_NUMBER, /** Number layout */
  EDJE_INPUT_PANEL_LAYOUT_EMAIL, /** Email layout */
  EDJE_INPUT_PANEL_LAYOUT_URL, /** URL layout */
  EDJE_INPUT_PANEL_LAYOUT_PHONENUMBER, /** Phone Number layout */
  EDJE_INPUT_PANEL_LAYOUT_IP, /** IP layout */
  EDJE_INPUT_PANEL_LAYOUT_MONTH, /** Month layout */
  EDJE_INPUT_PANEL_LAYOUT_NUMBERONLY, /** Number Only layout */
  EDJE_INPUT_PANEL_LAYOUT_INVALID, /** Never use this */
  EDJE_INPUT_PANEL_LAYOUT_HEX, /** Hexadecimal layout
                                *
                                * @since 1.2 */
  EDJE_INPUT_PANEL_LAYOUT_TERMINAL, /** Command-line terminal layout including
                                     * esc, alt, ctrl key, so on (no
                                     * auto-correct, no auto-capitalization)
                                     *
                                     * @since 1.2 */
  EDJE_INPUT_PANEL_LAYOUT_PASSWORD, /** Like normal, but no auto-correct, no
                                     * auto-capitalization etc.
                                     *
                                     * @since 1.2 */
  EDJE_INPUT_PANEL_LAYOUT_DATETIME, /** Date and time layout
                                     *
                                     * @since 1.8 */
  EDJE_INPUT_PANEL_LAYOUT_EMOTICON, /** Emoticon layout
                                     *
                                     * @since 1.10 */
  EDJE_INPUT_PANEL_LAYOUT_VOICE /** Voice layout, but if the IME does not
                                 * support voice layout, then normal layout
                                 * will be shown.
                                 *
                                 * @since 1.19 */
} Edje_Input_Panel_Layout;

/** The possible types the parameters of an EXTERNAL part can be.
 *
 * @ingroup Edje_External
 */
typedef enum
{
  EDJE_EXTERNAL_PARAM_TYPE_INT = 0, /** Parameter value is an integer. */
  EDJE_EXTERNAL_PARAM_TYPE_DOUBLE, /** Parameter value is a double. */
  EDJE_EXTERNAL_PARAM_TYPE_STRING, /** Parameter value is a string. */
  EDJE_EXTERNAL_PARAM_TYPE_BOOL, /** Parameter value is boolean. */
  EDJE_EXTERNAL_PARAM_TYPE_CHOICE, /** Parameter value is one of a set of
                                    * predefined string choices. */
  EDJE_EXTERNAL_PARAM_TYPE_MAX /** Sentinel. Don't use. */
} Edje_External_Param_Type;

/** Struct that holds parameters for parts of type EXTERNAL.
 *
 * @ingroup Edje_External
 */
typedef struct _Edje_External_Param
{
  const char *name; /** The name of the parameter. */
  Edje_External_Param_Type type; /** The type of the parameter. This defines
                                  * which of the next three variables holds the
                                  * value for it. */
  int i; /** Used by both integer and boolean */
  double d; /** Used by double */
  const char *s; /** Used by both string and choice */
} Edje_External_Param;

/** Identifiers of Edje message types, which can be sent back and forth code
 * and a given Edje object's theme file/group. @ref edje_object_message_send,
 * @ref edje_object_message_handler_set.
 *
 * @ingroup Edje
 */
typedef enum
{
  EDJE_MESSAGE_NONE = 0,
  EDJE_MESSAGE_SIGNAL = 1 /* 0 */, /** DONT USE THIS */
  EDJE_MESSAGE_STRING = 2 /* 0 */, /** A message with a string as value. Use
                                    * #Edje_Message_String structs as message
                                    * body, for this type. */
  EDJE_MESSAGE_INT = 3 /* 0 */, /** A message with an integer number as value.
                                 * Use #Edje_Message_Int structs as message
                                 * body, for this type. */
  EDJE_MESSAGE_FLOAT = 4 /* 0 */, /** A message with a floating pointer number
                                   * as value. Use #Edje_Message_Float structs
                                   * as message body, for this type. */
  EDJE_MESSAGE_STRING_SET = 5 /* 0 */, /** A message with a list of strings as
                                        * value. Use #Edje_Message_String_Set
                                        * structs as message body, for this
                                        * type. */
  EDJE_MESSAGE_INT_SET = 6 /* 0 */, /** A message with a list of integer
                                     * numbers as value. Use
                                     * #Edje_Message_Int_Set structs as message
                                     * body, for this type. */
  EDJE_MESSAGE_FLOAT_SET = 7 /* 0 */, /** A message with a list of floating
                                       * point numbers as value. Use
                                       * #Edje_Message_Float_Set structs as
                                       * message body, for this type. */
  EDJE_MESSAGE_STRING_INT = 8 /* 0 */, /** A message with a struct containing a
                                        * string and an integer number as
                                        * value. Use #Edje_Message_String_Int
                                        * structs as message body, for this
                                        * type. */
  EDJE_MESSAGE_STRING_FLOAT = 9 /* 0 */, /** A message with a struct containing
                                          * a string and a floating point
                                          * number as value. Use
                                          * #Edje_Message_String_Float structs
                                          * as message body, for this type. */
  EDJE_MESSAGE_STRING_INT_SET = 10 /* 0 */, /** A message with a struct
                                             * containing a string and list of
                                             * integer numbers as value. Use
                                             * #Edje_Message_String_Int_Set
                                             * structs as message body, for
                                             * this type. */
  EDJE_MESSAGE_STRING_FLOAT_SET = 11 /* 0 */ /** A message with a struct
                                              * containing a string and list of
                                              * floating point numbers as
                                              * value. Use
                                              * #Edje_Message_String_Float_Set
                                              * structs as message body, for
                                              * this type. */
} Edje_Message_Type;

/** Perspective info for maps inside edje objects
 *
 * @ingroup Edje
 */
typedef struct _Edje_Perspective Edje_Perspective;


#endif

#endif
