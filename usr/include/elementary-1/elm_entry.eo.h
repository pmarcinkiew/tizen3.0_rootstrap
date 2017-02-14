#ifndef _ELM_ENTRY_EO_H_
#define _ELM_ENTRY_EO_H_

#ifndef _ELM_ENTRY_EO_CLASS_TYPE
#define _ELM_ENTRY_EO_CLASS_TYPE

typedef Eo Elm_Entry;

#endif

#ifndef _ELM_ENTRY_EO_TYPES
#define _ELM_ENTRY_EO_TYPES

/**
 * @brief Text Format types.
 *
 * See also @ref elm_obj_entry_file_text_format_set.
 *
 * @ingroup Elm
 */
typedef enum
{
  ELM_TEXT_FORMAT_PLAIN_UTF8 = 0, /** Plain UTF8 type */
  ELM_TEXT_FORMAT_MARKUP_UTF8 /** Markup UTF8 type */
} Elm_Text_Format;

/** Input panel (virtual keyboard) layout types. Type of input panel (virtual
 * keyboard) to use - this is a hint and may not provide exactly what is
 * desired. See also @ref elm_obj_entry_input_panel_layout_set.
 *
 * @ingroup Elm_Input_Panel
 */
typedef enum
{
  ELM_INPUT_PANEL_LAYOUT_NORMAL = 0, /** Default layout. */
  ELM_INPUT_PANEL_LAYOUT_NUMBER, /** Number layout. */
  ELM_INPUT_PANEL_LAYOUT_EMAIL, /** Email layout. */
  ELM_INPUT_PANEL_LAYOUT_URL, /** URL layout. */
  ELM_INPUT_PANEL_LAYOUT_PHONENUMBER, /** Phone Number layout. */
  ELM_INPUT_PANEL_LAYOUT_IP, /** IP layout. */
  ELM_INPUT_PANEL_LAYOUT_MONTH, /** Month layout. */
  ELM_INPUT_PANEL_LAYOUT_NUMBERONLY, /** Number Only layout. */
  ELM_INPUT_PANEL_LAYOUT_INVALID, /** Never use this. */
  ELM_INPUT_PANEL_LAYOUT_HEX, /** Hexadecimal layout. */
  ELM_INPUT_PANEL_LAYOUT_TERMINAL, /** Command-line terminal layout including
                                    * esc, alt, ctrl key, so on (no
                                    * auto-correct, no auto-capitalization). */
  ELM_INPUT_PANEL_LAYOUT_PASSWORD, /** Like normal, but no auto-correct, no
                                    * auto-capitalization etc. */
  ELM_INPUT_PANEL_LAYOUT_DATETIME, /** Date and time layout
                                    *
                                    * @since 1.8 */
  ELM_INPUT_PANEL_LAYOUT_EMOTICON, /** Emoticon layout
                                    *
                                    * @since 1.10 */
  ELM_INPUT_PANEL_LAYOUT_VOICE /** Voice layout, but if the IME does not
                                * support voice layout, then normal layout will
                                * be shown.
                                *
                                * @since 1.19 */
} Elm_Input_Panel_Layout;

/**
 * @brief Input panel (virtual keyboard) language modes.
 *
 * See also @ref elm_obj_entry_input_panel_language_set.
 *
 * @ingroup Elm_Input_Panel
 */
typedef enum
{
  ELM_INPUT_PANEL_LANG_AUTOMATIC = 0, /** Automatic */
  ELM_INPUT_PANEL_LANG_ALPHABET /** Alphabet */
} Elm_Input_Panel_Lang;

/**
 * @brief Autocapitalization Types. Choose method of auto-capitalization.
 *
 * See also @ref elm_obj_entry_autocapital_type_set.
 *
 * @ingroup Elm_Autocapital
 */
typedef enum
{
  ELM_AUTOCAPITAL_TYPE_NONE = 0, /** No auto-capitalization when typing. */
  ELM_AUTOCAPITAL_TYPE_WORD, /** Autocapitalize each word typed. */
  ELM_AUTOCAPITAL_TYPE_SENTENCE, /** Autocapitalize the start of each sentence.
                                  */
  ELM_AUTOCAPITAL_TYPE_ALLCHARACTER /** Autocapitalize all letters. */
} Elm_Autocapital_Type;

/** "Return" Key types on the input panel (virtual keyboard). See also
 * @ref elm_obj_entry_input_panel_return_key_type_set.
 *
 * @ingroup Elm_Input_Panel_Return_Key
 */
typedef enum
{
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT = 0, /** Default. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_DONE, /** Done. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_GO, /** Go. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_JOIN, /** Join. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_LOGIN, /** Login. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_NEXT, /** Next. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEARCH, /** Search string or magnifier icon.
                                           */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_SEND, /** Send. */
  ELM_INPUT_PANEL_RETURN_KEY_TYPE_SIGNIN /** Sign-in
                                          *
                                          * @since 1.8 */
} Elm_Input_Panel_Return_Key_Type;

/** Enumeration that defines the types of Input Hints.
 *
 * @since 1.12
 *
 * @ingroup Elm_Input
 */
typedef enum
{
  ELM_INPUT_HINT_NONE = 0, /** No active hints
                            *
                            * @since 1.12 */
  ELM_INPUT_HINT_AUTO_COMPLETE = 1 /* 0 << 0 */, /** Suggest word auto
                                                  * completion
                                                  *
                                                  * @since 1.12 */
  ELM_INPUT_HINT_SENSITIVE_DATA = 2 /* 0 << 0 */ /** Typed text should not be
                                                  * stored.
                                                  *
                                                  * @since 1.12 */
} Elm_Input_Hints;


#endif
#define ELM_ENTRY_CLASS elm_entry_class_get()

EAPI const Eo_Class *elm_entry_class_get(void) EINA_CONST;

/**
 * @brief Enable or disable scrolling in entry
 *
 * Normally the entry is not scrollable unless you enable it with this call.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] scroll @c true if it is to be scrollable, @c false otherwise.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_scrollable_set(Eina_Bool scroll);

/**
 * @brief Get the scrollable state of the entry
 *
 * Normally the entry is not scrollable. This gets the scrollable state of the
 * entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true if it is to be scrollable, @c false otherwise.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_scrollable_get(void);

/**
 * @brief Set the attribute to show the input panel in case of only an user's
 * explicit Mouse Up event. It doesn't request to show the input panel even
 * though it has focus.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] ondemand If true, the input panel will be shown in case of only
 * Mouse up event. (Focus event will be ignored.)
 *
 * @since 1.9
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_show_on_demand_set(Eina_Bool ondemand);

/**
 * @brief Get the attribute to show the input panel in case of only an user's
 * explicit Mouse Up event.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the input panel will be shown in case of only Mouse up
 * event. (Focus event will be ignored.)
 *
 * @since 1.9
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_input_panel_show_on_demand_get(void);

/**
 * @brief This disables the entry's contextual (longpress) menu.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] disabled If @c true, the menu is disabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_context_menu_disabled_set(Eina_Bool disabled);

/**
 * @brief This returns whether the entry's contextual (longpress) menu is
 * disabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If @c true, the menu is disabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_context_menu_disabled_get(void);

/**
 * @brief Control pasting of text and images for the widget.
 *
 * Normally the entry allows both text and images to be pasted. By setting
 * cnp_mode to be #ELM_CNP_MODE_NO_IMAGE, this prevents images from being copy
 * or past. By setting cnp_mode to be #ELM_CNP_MODE_PLAINTEXT, this remove all
 * tags in text .
 *
 * @note This only changes the behaviour of text.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] cnp_mode One of #Elm_Cnp_Mode: #ELM_CNP_MODE_MARKUP,
 * #ELM_CNP_MODE_NO_IMAGE, #ELM_CNP_MODE_PLAINTEXT.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cnp_mode_set(Elm_Cnp_Mode cnp_mode);

/**
 * @brief Getting elm_entry text paste/drop mode.
 *
 * Normally the entry allows both text and images to be pasted. This gets the
 * copy & paste mode of the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return One of #Elm_Cnp_Mode: #ELM_CNP_MODE_MARKUP, #ELM_CNP_MODE_NO_IMAGE,
 * #ELM_CNP_MODE_PLAINTEXT.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Cnp_Mode  elm_obj_entry_cnp_mode_get(void);

/**
 * @brief Text format used to load and save the file, which could be plain text
 * or markup text.
 *
 * Default is @c ELM_TEXT_FORMAT_PLAIN_UTF8, if you want to use
 * @c ELM_TEXT_FORMAT_MARKUP_UTF8 then you need to set the text format before
 * calling @ref efl_file_set.
 *
 * You could also set it before a call to @ref elm_obj_entry_file_save in order
 * to save with the given format.
 *
 * Use it before calling @ref efl_file_set or @ref elm_obj_entry_file_save.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] format The file format
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_file_text_format_set(Elm_Text_Format format);

/**
 * @brief Set the language mode of the input panel.
 *
 * This API can be used if you want to show the alphabet keyboard mode.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lang language to be set to the input panel.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_language_set(Elm_Input_Panel_Lang lang);

/**
 * @brief Get the language mode of the input panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return language to be set to the input panel.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Input_Panel_Lang  elm_obj_entry_input_panel_language_get(void);

/**
 * @brief This disabled the entry's selection handlers.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] disabled If @c true, the selection handlers are disabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_selection_handler_disabled_set(Eina_Bool disabled);

/**
 * @brief This returns whether the entry's selection handlers are disabled.
 *
 * @return If @c true, the selection handlers are disabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_selection_handler_disabled_get(void);

/**
 * @brief Set the input panel layout variation of the entry
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] variation layout variation type.
 *
 * @since 1.8
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_layout_variation_set(int variation);

/**
 * @brief Get the input panel layout variation of the entry
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return layout variation type.
 *
 * @since 1.8
 *
 * @ingroup Elm_Entry
 */
EOAPI int  elm_obj_entry_input_panel_layout_variation_get(void);

/**
 * @brief Set the autocapitalization type on the immodule.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] autocapital_type The type of autocapitalization.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_autocapital_type_set(Elm_Autocapital_Type autocapital_type);

/**
 * @brief Get the autocapitalization type on the immodule.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The type of autocapitalization.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Autocapital_Type  elm_obj_entry_autocapital_type_get(void);

/**
 * @brief Sets if the entry is to be editable or not.
 *
 * By default, entries are editable and when focused, any text input by the
 * user will be inserted at the current cursor position. But calling this
 * function with @c editable as @c false will prevent the user from inputting
 * text into the entry.
 *
 * The only way to change the text of a non-editable entry is to use @ref
 * elm_object_text_set, @ref elm_entry_entry_insert and other related
 * functions.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] editable If @c true, user input will be inserted in the entry, if
 * not, the entry is read-only and no user input is allowed.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_editable_set(Eina_Bool editable);

/**
 * @brief Get whether the entry is editable or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If @c true, user input will be inserted in the entry, if not, the
 * entry is read-only and no user input is allowed.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_editable_get(void);

/**
 * @brief Set the style that the hover should use
 *
 * When creating the popup hover, entry will request that it's themed according
 * to @c style.
 *
 * Setting style no @c null means disabling automatic hover.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style The style to use for the underlying hover.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_anchor_hover_style_set(const char *style);

/**
 * @brief Get the style that the hover should use.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The style to use for the underlying hover.
 *
 * @ingroup Elm_Entry
 */
EOAPI const char * elm_obj_entry_anchor_hover_style_get(void);

/**
 * @brief Sets the entry to single line mode.
 *
 * In single line mode, entries don't ever wrap when the text reaches the edge,
 * and instead they keep growing horizontally. Pressing the @c Enter key will
 * generate an $"activate" event instead of adding a new line.
 *
 * When @c single_line is @c false, line wrapping takes effect again and
 * pressing enter will break the text into a different line without generating
 * any events.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] single_line If true, the text in the entry will be on a single
 * line.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_single_line_set(Eina_Bool single_line);

/**
 * @brief Get whether the entry is set to be single line.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the text in the entry will be on a single line.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_single_line_get(void);

/**
 * @brief Sets the entry to password mode.
 *
 * In password mode, entries are implicitly single line and the display of any
 * text in them is replaced with asterisks (*).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] password If true, password mode is enabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_password_set(Eina_Bool password);

/**
 * @brief Get whether the entry is set to password mode.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, password mode is enabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_password_get(void);

/**
 * @brief Set the return key on the input panel to be disabled.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] disabled The state to put in in: @c true for disabled, @c false
 * for enabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_return_key_disabled_set(Eina_Bool disabled);

/**
 * @brief Get whether the return key on the input panel should be disabled or
 * not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The state to put in in: @c true for disabled, @c false for enabled.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_input_panel_return_key_disabled_get(void);

/**
 * @brief This sets the entry object to 'autosave' the loaded text file or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] auto_save Autosave the loaded file or not.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_autosave_set(Eina_Bool auto_save);

/**
 * @brief This gets the entry object's 'autosave' status.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Autosave the loaded file or not.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_autosave_get(void);

/**
 * @brief Set the parent of the hover popup
 *
 * Sets the parent object to use by the hover created by the entry when an
 * anchor is clicked.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] parent The object to use as parent for the hover.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_anchor_hover_parent_set(Evas_Object *parent);

/**
 * @brief Get the parent of the hover popup
 *
 * Get the object used as parent for the hover created by the entry widget. If
 * no parent is set, the same entry object will be used.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The object to use as parent for the hover.
 *
 * @ingroup Elm_Entry
 */
EOAPI Evas_Object * elm_obj_entry_anchor_hover_parent_get(void);

/**
 * @brief Set whether the entry should allow to use the text prediction.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] prediction Whether the entry should allow to use the text
 * prediction.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_prediction_allow_set(Eina_Bool prediction);

/**
 * @brief Get whether the entry should allow to use the text prediction.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Whether the entry should allow to use the text prediction.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_prediction_allow_get(void);

/**
 * @brief Sets the input hint which allows input methods to fine-tune their
 * behavior.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] hints Input hint.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_hint_set(Elm_Input_Hints hints);

/**
 * @brief Gets the value of input hint.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Input hint.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Input_Hints  elm_obj_entry_input_hint_get(void);

/**
 * @brief Set the input panel layout of the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] layout layout type.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_layout_set(Elm_Input_Panel_Layout layout);

/**
 * @brief Get the input panel layout of the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return layout type.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Input_Panel_Layout  elm_obj_entry_input_panel_layout_get(void);

/**
 * @brief Set the "return" key type. This type is used to set string or icon on
 * the "return" key of the input panel.
 *
 * An input panel displays the string or icon associated with this type.
 *
 * Regardless of return key type, "activated" event will be generated when
 * pressing return key in single line entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] return_key_type The type of "return" key on the input panel.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_return_key_type_set(Elm_Input_Panel_Return_Key_Type return_key_type);

/**
 * @brief Get the "return" key type.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The type of "return" key on the input panel.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Input_Panel_Return_Key_Type  elm_obj_entry_input_panel_return_key_type_get(void);

/**
 * @brief Sets the attribute to show the input panel automatically.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] enabled If true, the input panel is appeared when entry is
 * clicked or has a focus.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_enabled_set(Eina_Bool enabled);

/**
 * @brief Get the attribute to show the input panel automatically.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the input panel is appeared when entry is clicked or has a
 * focus.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_input_panel_enabled_get(void);

/**
 * @brief Set the line wrap type to use on multi-line entries.
 *
 * Sets the wrap type used by the entry to any of the specified in
 * Elm_Wrap_Type. This tells how the text will be implicitly cut into a new
 * line (without inserting a line break or paragraph separator) when it reaches
 * the far edge of the widget.
 *
 * Note that this only makes sense for multi-line entries. A widget set to be
 * single line will never wrap.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] wrap The wrap mode to use. See Elm_Wrap_Type for details on them.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_line_wrap_set(Elm_Wrap_Type wrap);

/**
 * @brief Get the wrap mode the entry was set to use.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The wrap mode to use. See Elm_Wrap_Type for details on them.
 *
 * @ingroup Elm_Entry
 */
EOAPI Elm_Wrap_Type  elm_obj_entry_line_wrap_get(void);

/**
 * @brief Sets the cursor position in the entry to the given value
 *
 * The value in @c pos is the index of the character position within the
 * contents of the string as returned by @ref elm_obj_entry_cursor_pos_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] pos The position of the cursor.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_pos_set(int pos);

/**
 * @brief Get the current position of the cursor in the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The position of the cursor.
 *
 * @ingroup Elm_Entry
 */
EOAPI int  elm_obj_entry_cursor_pos_get(void);

/**
 * @brief Sets the visibility of the left-side widget of the entry, set by @ref
 * elm_object_part_content_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] setting @c true if the object should be displayed, @c false if
 * not.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_icon_visible_set(Eina_Bool setting);

/**
 * @brief This moves the cursor to the end of the current line.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_line_end_set(void);

/**
 * @brief This selects a region of text within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] start The starting position.
 * @param[in] end The end position.
 *
 * @since 1.9
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_select_region_set(int start, int end);

/**
 * @brief Get the current position of the selection cursors in the entry.
 *
 * @param[out] start The starting position.
 * @param[out] end The end position.
 *
 * @since 1.18
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_select_region_get(int *start, int *end);

/**
 * @brief Set whether the return key on the input panel is disabled
 * automatically when entry has no text.
 *
 * If @c enabled is @c true, The return key on input panel is disabled when the
 * entry has no text. The return key on the input panel is automatically
 * enabled when the entry has text. The default value is @c false.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] enabled If @c enabled is true, the return key is automatically
 * disabled when the entry has no text.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_return_key_autoenabled_set(Eina_Bool enabled);

/**
 * @internal
 *
 * @brief Sets the visibility of the end widget of the entry,
 * set by @ref elm_object_part_content_set(ent, "end", content).
 *
 * @param[in] setting true if the object should be displayed, false if not.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_end_visible_set(Eina_Bool setting);

/**
 * @brief This moves the cursor to the beginning of the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_begin_set(void);

/**
 * @brief This moves the cursor to the beginning of the current line.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_line_begin_set(void);

/**
 * @brief This moves the cursor to the end of the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_end_set(void);

/**
 * @brief Returns the actual textblock object of the entry.
 *
 * This function exposes the internal textblock object that actually contains
 * and draws the text. This should be used for low-level manipulations that are
 * otherwise not possible.
 *
 * Changing the textblock directly from here will not notify edje/elm to
 * recalculate the textblock size automatically, so any modifications done to
 * the textblock returned by this function should be followed by a call to @ref
 * elm_entry_calc_force.
 *
 * The return value is marked as const as an additional warning. One should not
 * use the returned object with any of the generic evas functions
 * (geometry_get/resize/move and etc), but only with the textblock functions;
 * The former will either not work at all, or break the correct functionality.
 *
 * IMPORTANT: Many functions may change (i.e delete and create a new one) the
 * internal textblock object. Do NOT cache the returned object, and try not to
 * mix calls on this object with regular elm_entry calls (which may change the
 * internal textblock object). This applies to all cursors returned from
 * textblock calls, and all the other derivative values.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Evas_Object * elm_obj_entry_textblock_get(void);

/**
 * @brief This function returns the geometry of the cursor.
 *
 * It's useful if you want to draw something on the cursor (or where it is), or
 * for example in the case of scrolled entry where you want to show the cursor.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x returned geometry.
 * @param[out] y returned geometry.
 * @param[out] w returned geometry.
 * @param[out] h returned geometry.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_geometry_get(Evas_Coord *x, Evas_Coord *y, Evas_Coord *w, Evas_Coord *h);

/**
 * @brief Returns the input method context of the entry.
 *
 * This function exposes the internal input method context.
 *
 * IMPORTANT: Many functions may change (i.e delete and create a new one) the
 * internal input method context. Do NOT cache the returned object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void * elm_obj_entry_imf_context_get(void);

/**
 * @brief Get whether a format node exists at the current cursor position.
 *
 * A format node is anything that defines how the text is rendered. It can be a
 * visible format node, such as a line break or a paragraph separator, or an
 * invisible one, such as bold begin or end tag. This function returns whether
 * any format node exists at the current cursor position.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_is_format_get(void);

/**
 * @brief Get the character pointed by the cursor at its current position.
 *
 * This function returns a string with the utf8 character stored at the current
 * cursor position. Only the text is returned, any format that may exist will
 * not be part of the return value. You must free the string when done with
 * @ref free.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI char * elm_obj_entry_cursor_content_get(void);

/**
 * @brief Get any selected text within the entry.
 *
 * If there's any selected text in the entry, this function returns it as a
 * string in markup format. @c null is returned if no selection exists or if an
 * error occurred.
 *
 * The returned value points to an internal string and should not be freed or
 * modified in any way. If the @c entry object is deleted or its contents are
 * changed, the returned pointer should be considered invalid.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI const char * elm_obj_entry_selection_get(void);

/**
 * @brief Get if the current cursor position holds a visible format node.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_is_visible_format_get(void);

/**
 * @brief Allow selection in the entry.
 *
 * @param[in] allow If @c allow is true, the text selection is allowed.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_select_allow_set(Eina_Bool allow);

/**
 * @brief Returns whether selection in the entry is allowed.
 *
 * @return If @c allow is true, the text selection is allowed.
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_select_allow_get(void);

/**
 * @brief This moves the cursor one place to the left within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_prev(void);

/**
 * @brief Remove the style in the top of user style stack.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @since 1.7
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_text_style_user_pop(void);

/**
 * @brief This prepends a custom item provider to the list for that entry
 *
 * This prepends the given callback.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data The data passed to @c func.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_item_provider_prepend(Elm_Entry_Item_Provider_Cb func, void *data);

/**
 * @brief Show the input panel (virtual keyboard) based on the input panel
 * property of entry such as layout, autocapital types, and so on.
 *
 * Note that input panel is shown or hidden automatically according to the
 * focus state of entry widget. This API can be used in the case of manually
 * controlling by using @ref elm_obj_entry_input_panel_enabled_set(en,
 * @c false).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_show(void);

/**
 * @brief Reset the input method context of the entry if needed.
 *
 * This can be necessary in the case where modifying the buffer would confuse
 * on-going input method behavior. This will typically cause the Input Method
 * Context to clear the preedit state.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_imf_context_reset(void);

/**
 * @brief Forces calculation of the entry size and text layouting.
 *
 * This should be used after modifying the textblock object directly. See
 * @ref elm_obj_entry_textblock_get for more information.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_calc_force(void);

/**
 * @brief Ends the hover popup in the entry
 *
 * When an anchor is clicked, the entry widget will create a hover object to
 * use as a popup with user provided content. This function terminates this
 * popup, returning the entry to its normal state.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_anchor_hover_end(void);

/**
 * @brief This begins a selection within the entry as though the user were
 * holding down the mouse button to make a selection.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_selection_begin(void);

/**
 * @brief This moves the cursor one line down within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_down(void);

/**
 * @brief This function writes any changes made to the file set with @ref
 * elm_entry_file_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_file_save(void);

/**
 * @brief This executes a "copy" action on the selected text in the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_selection_copy(void);

/**
 * @brief Push the style to the top of user style stack. If there is styles in
 * the user style stack, the properties in the top style of user style stack
 * will replace the properties in current theme. The input style is specified
 * in format tag='property=value' (i.e. DEFAULT='font=Sans
 * font_size=60'hilight=' + font_weight=Bold').
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style The style user to push.
 *
 * @since 1.7
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_text_style_user_push(const char *style);

/**
 * @brief This removes a custom item provider to the list for that entry
 *
 * This removes the given callback. See @ref elm_obj_entry_item_provider_append
 * for more information
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data The data passed to @c func.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_item_provider_remove(Elm_Entry_Item_Provider_Cb func, void *data);

/**
 * @brief Get the style on the top of user style stack.
 *
 * See also @ref elm_obj_entry_text_style_user_push.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @since 1.7
 *
 * @ingroup Elm_Entry
 */
EOAPI const char * elm_obj_entry_text_style_user_peek(void);

/**
 * @brief This clears and frees the items in a entry's contextual (longpress)
 * menu.
 *
 * See also @ref elm_obj_entry_context_menu_item_add.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_context_menu_clear(void);

/**
 * @brief This moves the cursor one line up within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_up(void);

/**
 * @brief Inserts the given text into the entry at the current cursor position.
 *
 * This inserts text at the cursor position as if it was typed by the user
 * (note that this also allows markup which a user can't just "type" as it
 * would be converted to escaped text, so this call can be used to insert
 * things like emoticon items or bold push/pop tags, other font and color
 * change tags etc.)
 *
 * If any selection exists, it will be replaced by the inserted text.
 *
 * The inserted text is subject to any filters set for the widget.
 *
 * See also @ref elm_obj_entry_markup_filter_append.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] entry The text to insert.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_insert(const char *entry);

/**
 * @brief Set the input panel-specific data to deliver to the input panel.
 *
 * This API is used by applications to deliver specific data to the input
 * panel. The data format MUST be negotiated by both application and the input
 * panel. The size and format of data are defined by the input panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] len The length of data, in bytes, to send to the input panel.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_imdata_set(const void *data, int len);

/**
 * @brief Get the specific data of the current input panel.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] len The length of data.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_imdata_get(void *data, int *len);

/**
 * @brief This executes a "paste" action in the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_selection_paste(void);

/**
 * @brief This moves the cursor one place to the right within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_cursor_next(void);

/**
 * @brief This drops any existing text selection within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_select_none(void);

/**
 * @brief Hide the input panel (virtual keyboard).
 *
 * Note that input panel is shown or hidden automatically according to the
 * focus state of entry widget. This API can be used in the case of manually
 * controlling by using @ref elm_obj_entry_input_panel_enabled_set(en,
 * @c false)
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_input_panel_hide(void);

/**
 * @brief This selects all text within the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_select_all(void);

/**
 * @brief This ends a selection within the entry as though the user had just
 * released the mouse button while making a selection.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_cursor_selection_end(void);

/**
 * @brief This executes a "cut" action on the selected text in the entry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_selection_cut(void);

/**
 * @brief Get whether the entry is empty.
 *
 * Empty means no text at all. If there are any markup tags, like an item tag
 * for which no provider finds anything, and no text is displayed, this
 * function still returns @c false.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Entry
 */
EOAPI Eina_Bool  elm_obj_entry_is_empty(void);

/**
 * @brief Remove a markup filter from the list
 *
 * Removes the given callback from the filter list. See
 * @ref elm_obj_entry_markup_filter_append for more information.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data The user data passed when adding the function.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_markup_filter_remove(Elm_Entry_Filter_Cb func, void *data);

/**
 * @brief This appends a custom item provider to the list for that entry
 *
 * This appends the given callback. The list is walked from beginning to end
 * with each function called given the item href string in the text. If the
 * function returns an object handle other than @c null (it should create an
 * object to do this), then this object is used to replace that item. If not
 * the next provider is called until one provides an item object, or the
 * default provider in entry does.
 *
 * See also @ref entry-items.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data The data passed to @c func.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_item_provider_append(Elm_Entry_Item_Provider_Cb func, void *data);

/**
 * @brief Append a markup filter function for text inserted in the entry
 *
 * Append the given callback to the list. This functions will be called
 * whenever any text is inserted into the entry, with the text to be inserted
 * as a parameter. The type of given text is always markup. The callback
 * function is free to alter the text in any way it wants, but it must remember
 * to free the given pointer and update it. If the new text is to be discarded,
 * the function can free it and set its text parameter to @c null. This will
 * also prevent any following filters from being called.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data User data to pass to @c func.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_markup_filter_append(Elm_Entry_Filter_Cb func, void *data);

/**
 * @brief Appends @c str to the text of the entry.
 *
 * Adds the text in @c str to the end of any text already present in the
 * widget.
 *
 * The appended text is subject to any filters set for the widget.
 *
 * See also @ref elm_obj_entry_markup_filter_append.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] str The text to be appended.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_append(const char *str);

/**
 * @brief This adds an item to the entry's contextual menu.
 *
 * A longpress on an entry will make the contextual menu show up, if this
 * hasn't been disabled with @ref elm_obj_entry_context_menu_disabled_set. By
 * default, this menu provides a few options like enabling selection mode,
 * which is useful on embedded devices that need to be explicit about it, and
 * when a selection exists it also shows the copy and cut actions.
 *
 * With this function, developers can add other options to this menu to perform
 * any action they deem necessary.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] icon_file The item's icon file.
 * @param[in] icon_type The item's icon type.
 * @param[in] func The callback to execute when the item is clicked.
 * @param[in] data The data to associate with the item for related functions.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_context_menu_item_add(const char *label, const char *icon_file, Elm_Icon_Type icon_type, Evas_Smart_Cb func, const void *data);

/**
 * @brief Prepend a markup filter function for text inserted in the entry
 *
 * Prepend the given callback to the list.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] data User data to pass to @c func.
 *
 * @ingroup Elm_Entry
 */
EOAPI void  elm_obj_entry_markup_filter_prepend(Elm_Entry_Filter_Cb func, void *data);

EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ACCESS_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ACTIVATED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_CHANGED_USER;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_VALIDATE;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_CONTEXT_OPEN;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_REJECTED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_MAXLENGTH_REACHED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_PREEDIT_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_PRESS;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_REDO_REQUEST;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_UNDO_REQUEST;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_TEXT_SET_DONE;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ABORTED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_DOWN;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_HOVER_OPENED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_IN;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_OUT;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_ANCHOR_UP;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_CURSOR_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_ENTRY_EVENT_CURSOR_CHANGED_MANUAL;

/**
 * No description
 */
#define ELM_ENTRY_EVENT_LANGUAGE_CHANGED (&(_ELM_ENTRY_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ACCESS_CHANGED (&(_ELM_ENTRY_EVENT_ACCESS_CHANGED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ACTIVATED (&(_ELM_ENTRY_EVENT_ACTIVATED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_CHANGED (&(_ELM_ENTRY_EVENT_CHANGED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_CHANGED_USER (&(_ELM_ENTRY_EVENT_CHANGED_USER))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_VALIDATE (&(_ELM_ENTRY_EVENT_VALIDATE))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_CONTEXT_OPEN (&(_ELM_ENTRY_EVENT_CONTEXT_OPEN))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_CLICKED (&(_ELM_ENTRY_EVENT_ANCHOR_CLICKED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_REJECTED (&(_ELM_ENTRY_EVENT_REJECTED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_MAXLENGTH_REACHED (&(_ELM_ENTRY_EVENT_MAXLENGTH_REACHED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_PREEDIT_CHANGED (&(_ELM_ENTRY_EVENT_PREEDIT_CHANGED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_PRESS (&(_ELM_ENTRY_EVENT_PRESS))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_REDO_REQUEST (&(_ELM_ENTRY_EVENT_REDO_REQUEST))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_UNDO_REQUEST (&(_ELM_ENTRY_EVENT_UNDO_REQUEST))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_TEXT_SET_DONE (&(_ELM_ENTRY_EVENT_TEXT_SET_DONE))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ABORTED (&(_ELM_ENTRY_EVENT_ABORTED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_DOWN (&(_ELM_ENTRY_EVENT_ANCHOR_DOWN))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_HOVER_OPENED (&(_ELM_ENTRY_EVENT_ANCHOR_HOVER_OPENED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_IN (&(_ELM_ENTRY_EVENT_ANCHOR_IN))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_OUT (&(_ELM_ENTRY_EVENT_ANCHOR_OUT))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_ANCHOR_UP (&(_ELM_ENTRY_EVENT_ANCHOR_UP))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_CURSOR_CHANGED (&(_ELM_ENTRY_EVENT_CURSOR_CHANGED))

/**
 * No description
 */
#define ELM_ENTRY_EVENT_CURSOR_CHANGED_MANUAL (&(_ELM_ENTRY_EVENT_CURSOR_CHANGED_MANUAL))

#endif
