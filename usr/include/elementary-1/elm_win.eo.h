#ifndef _ELM_WIN_EO_H_
#define _ELM_WIN_EO_H_

#ifndef _ELM_WIN_EO_CLASS_TYPE
#define _ELM_WIN_EO_CLASS_TYPE

typedef Eo Elm_Win;

#endif

#ifndef _ELM_WIN_EO_TYPES
#define _ELM_WIN_EO_TYPES

/**
 * @brief Defines the types of window that can be created
 *
 * These are hints set on the window so that a running Window Manager knows how
 * the window should be handled and/or what kind of decorations it should have.
 *
 * Currently, only the X11 backed engines use them.
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_UNKNOWN = 0,
  ELM_WIN_BASIC, /** A normal window. Indicates a normal, top-level window.
                  * Almost every window will be created with this type. */
  ELM_WIN_DIALOG_BASIC, /** Used for simple dialog windows. */
  ELM_WIN_DESKTOP, /** For special desktop windows, like a background window
                    * holding desktop icons. */
  ELM_WIN_DOCK, /** The window is used as a dock or panel. Usually would be
                 * kept on top of any other window by the Window Manager. */
  ELM_WIN_TOOLBAR, /** The window is used to hold a floating toolbar, or
                    * similar. */
  ELM_WIN_MENU, /** Similar to #ELM_WIN_TOOLBAR. */
  ELM_WIN_UTILITY, /** A persistent utility window, like a toolbox or palette.
                    */
  ELM_WIN_SPLASH, /** Splash window for a starting up application. */
  ELM_WIN_DROPDOWN_MENU, /** The window is a dropdown menu, as when an  entry
                          * in a menubar is clicked. Typically used with
                          * @ref elm_obj_win_override_set. This hint exists for
                          * completion only, as the EFL way of implementing a
                          * menu would not normally use a separate window for
                          * its contents. */
  ELM_WIN_POPUP_MENU, /** Like #ELM_WIN_DROPDOWN_MENU, but for the menu
                       * triggered by right-clicking an object. */
  ELM_WIN_TOOLTIP, /** The window is a tooltip. A short piece of explanatory
                    * text that typically appear after the mouse cursor hovers
                    * over an object for a while. Typically used with
                    * @ref elm_obj_win_override_set and also not very commonly
                    * used in the EFL. */
  ELM_WIN_NOTIFICATION, /** A notification window, like a warning about battery
                         * life or a new E-Mail received. */
  ELM_WIN_COMBO, /** A window holding the contents of a combo box. Not usually
                  * used in the EFL. */
  ELM_WIN_DND, /** Used to indicate the window is a representation of an object
                * being dragged across different windows, or even applications.
                * Typically used with elm_win_override_set(). */
  ELM_WIN_INLINED_IMAGE, /** The window is rendered onto an image buffer. No
                          * actual window is created for this type, instead the
                          * window and all of its contents will be rendered to
                          * an image buffer. This allows to have children
                          * window inside a parent one just like any other
                          * object would be, and do other things like applying
                          * @ref Evas_Map effects to it. This is the only type
                          * of window that requires the parent parameter of
                          * @ref elm_win_add to be a valid @ref Evas_Object. */
  ELM_WIN_SOCKET_IMAGE, /** The window is rendered onto an image buffer and can
                         * be shown other process's plug image object. No
                         * actual window is created for this type, instead the
                         * window and all of its contents will be rendered to
                         * an image buffer and can be shown other process's
                         * plug image object. */
  ELM_WIN_FAKE = 18 /* 0 */ /** This window was created using a pre-existing
                             * canvas. The window widget can be deleted, but
                             * the canvas must be managed externally.
                             *
                             * @since 1.13 */
} Elm_Win_Type;

/**
 * @brief The different layouts that can be requested for the virtual keyboard.
 *
 * When the application window is being managed by Illume, it may request any
 * of the following layouts for the virtual keyboard.
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_KEYBOARD_UNKNOWN = 0, /** Unknown keyboard state */
  ELM_WIN_KEYBOARD_OFF, /** Request to deactivate the keyboard */
  ELM_WIN_KEYBOARD_ON, /** Enable keyboard with default layout */
  ELM_WIN_KEYBOARD_ALPHA, /** Alpha (a-z) keyboard layout */
  ELM_WIN_KEYBOARD_NUMERIC, /** Numeric keyboard layout */
  ELM_WIN_KEYBOARD_PIN, /** PIN keyboard layout */
  ELM_WIN_KEYBOARD_PHONE_NUMBER, /** Phone keyboard layout */
  ELM_WIN_KEYBOARD_HEX, /** Hexadecimal numeric keyboard layout */
  ELM_WIN_KEYBOARD_TERMINAL, /** Full (QWERTY) keyboard layout */
  ELM_WIN_KEYBOARD_PASSWORD, /** Password keyboard layout */
  ELM_WIN_KEYBOARD_IP, /** IP keyboard layout */
  ELM_WIN_KEYBOARD_HOST, /** Host keyboard layout */
  ELM_WIN_KEYBOARD_FILE, /** File keyboard layout */
  ELM_WIN_KEYBOARD_URL, /** URL keyboard layout */
  ELM_WIN_KEYBOARD_KEYPAD, /** Keypad layout */
  ELM_WIN_KEYBOARD_J2ME /** J2ME keyboard layout */
} Elm_Win_Keyboard_Mode;

/**
 * @brief In some environments, like phones, you may have an indicator that
 * shows battery status, reception, time etc. This is the indicator.
 *
 * Sometimes you don't want it because you provide the same functionality
 * inside your app, so this will request that the indicator is hidden in this
 * circumstance if you use ELM_ILLUME_INDICATOR_HIDE. The default is to have
 * the indicator shown.
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_INDICATOR_UNKNOWN = 0, /** Unknown indicator state */
  ELM_WIN_INDICATOR_HIDE, /** Hides the indicator */
  ELM_WIN_INDICATOR_SHOW /** Shows the indicator */
} Elm_Win_Indicator_Mode;

/** Defines the opacity modes of indicator that can be shown
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_INDICATOR_OPACITY_UNKNOWN = 0, /** Unknown indicator opacity mode */
  ELM_WIN_INDICATOR_OPAQUE, /** Opacifies the indicator */
  ELM_WIN_INDICATOR_TRANSLUCENT, /** Be translucent the indicator */
  ELM_WIN_INDICATOR_TRANSPARENT, /** Transparentizes the indicator */
  ELM_WIN_INDICATOR_BG_TRANSPARENT /** Bg Transparentizes the indicator */
} Elm_Win_Indicator_Opacity_Mode;

/** Define the keygrab modes of window. A window may send commands to the
 * Keyrouter according this mode, and perform different actions.
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_KEYGRAB_UNKNOWN = 0, /** Unknown keygrab mode */
  ELM_WIN_KEYGRAB_SHARED = 256 /* 0 << 0 */, /** Getting the grabbed-key
                                              * together with the other client
                                              * windows */
  ELM_WIN_KEYGRAB_TOPMOST = 512 /* 0 << 0 */, /** Getting the grabbed-key only
                                               * when window is top of the
                                               * stack */
  ELM_WIN_KEYGRAB_EXCLUSIVE = 1024 /* 0 << 0 */, /** Getting the grabbed-key
                                                  * exclusively regardless of
                                                  * window's position */
  ELM_WIN_KEYGRAB_OVERRIDE_EXCLUSIVE = 2048 /* 0 << 0 */ /** Getting the
                                                          * grabbed-key
                                                          * exclusively
                                                          * regardless of
                                                          * window's position.
                                                          * Being overrided the
                                                          * grab by the other
                                                          * client window */
} Elm_Win_Keygrab_Mode;

/**
 * @brief List of window effect.
 *
 * These list indicates types of window effect. When the effect started or
 * done, the Elm_Win is notified with type information of window effect.
 *
 * @ingroup Elm_Win_Effect
 */
typedef enum
{
  ELM_WIN_EFFECT_TYPE_UNKNOWN = 0,
  ELM_WIN_EFFECT_TYPE_SHOW,
  ELM_WIN_EFFECT_TYPE_HIDE,
  ELM_WIN_EFFECT_TYPE_RESTACK
} Elm_Win_Effect_Type;

/**
 * @brief Available commands that can be sent to the Illume manager.
 *
 * When running under an Illume session, a window may send commands to the
 * Illume manager to perform different actions.
 *
 * @ingroup Elm
 */
typedef enum
{
  ELM_ILLUME_COMMAND_FOCUS_BACK = 0, /** Reverts focus to the previous window
                                      */
  ELM_ILLUME_COMMAND_FOCUS_FORWARD, /** Sends focus to the next window in the
                                     * list */
  ELM_ILLUME_COMMAND_FOCUS_HOME, /** Hides all windows to show the Home screen
                                  */
  ELM_ILLUME_COMMAND_CLOSE /** Closes the currently active window */
} Elm_Illume_Command;

/**
 * @brief Define the move or resize mode of window.
 *
 * The user can request the display server to start moving or resizing the
 * window by combining these modes. However, only limited combinations are
 * allowed.
 *
 * Currently, only the following 9 combinations are allowed, and possibly more
 * combinations may be added in the future: 1. move, 2. top, 3. bottom, 4.
 * left, 5. right, 6. top | left, 7. top | right, 8. bottom | left, 9. bottom |
 * right.
 *
 * @ingroup Elm_Win
 */
typedef enum
{
  ELM_WIN_MOVE_RESIZE_MOVE = 1 /* 0 */, /** Start moving window */
  ELM_WIN_MOVE_RESIZE_TOP = 2 /* 0 << 0 */, /** Start resizing window to the
                                             * top */
  ELM_WIN_MOVE_RESIZE_BOTTOM = 4 /* 0 << 0 */, /** Start resizing window to the
                                                * bottom */
  ELM_WIN_MOVE_RESIZE_LEFT = 8 /* 0 << 0 */, /** Start resizing window to the
                                              * left */
  ELM_WIN_MOVE_RESIZE_RIGHT = 16 /* 0 << 0 */ /** Start resizing window to the
                                               * right */
} Elm_Win_Move_Resize_Mode;


#endif
#define ELM_WIN_CLASS elm_win_class_get()

EAPI const Eo_Class *elm_win_class_get(void) EINA_CONST;

/**
 * @brief Sets whether the window is a keyboard.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] is_keyboard If true, the window is a virtual keyboard.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_keyboard_win_set(Eina_Bool is_keyboard);

/**
 * @brief Get whether the window is a keyboard.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return If true, the window is a virtual keyboard.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_keyboard_win_get(void);

/**
 * @brief Set the window's autodel state.
 *
 * When closing the window in any way outside of the program control, like
 * pressing the X button in the titlebar or using a command from the Window
 * Manager, a "delete,request" signal is emitted to indicate that this event
 * occurred and the developer can take any action, which may include, or not,
 * destroying the window object.
 *
 * When the @c autodel parameter is set, the window will be automatically
 * destroyed when this event occurs, after the signal is emitted. If @c autodel
 * is @c false, then the window will not be destroyed and is up to the program
 * to do so when it's required.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] autodel If true, the window will automatically delete itself when
 * closed.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_autodel_set(Eina_Bool autodel);

/**
 * @brief Get the window's autodel state.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window will automatically delete itself when closed.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_autodel_get(void);

/**
 * @brief Window's autohide state.
 *
 * This property works similarly to @ref elm_obj_win_autodel_get, automatically
 * handling "delete,request" signals when set to @c trze, with the difference
 * that it will hide the window, instead of destroying it.
 *
 * It is specially designed to work together with
 * @c ELM_POLICY_QUIT_LAST_WINDOW_HIDDEN which allows exiting Elementary's main
 * loop when all the windows are hidden.
 *
 * @note @ref elm_obj_win_autodel_get and @c autohide are not mutually
 * exclusive. The window will be deleted if both are set to @c true.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] autohide If true, the window will automatically hide itself when
 * closed.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_autohide_set(Eina_Bool autohide);

/**
 * @brief Window's autohide state.
 *
 * This property works similarly to @ref elm_obj_win_autodel_get, automatically
 * handling "delete,request" signals when set to @c trze, with the difference
 * that it will hide the window, instead of destroying it.
 *
 * It is specially designed to work together with
 * @c ELM_POLICY_QUIT_LAST_WINDOW_HIDDEN which allows exiting Elementary's main
 * loop when all the windows are hidden.
 *
 * @note @ref elm_obj_win_autodel_get and @c autohide are not mutually
 * exclusive. The window will be deleted if both are set to @c true.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return If true, the window will automatically hide itself when closed.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_autohide_get(void);

/**
 * @brief Set the override state of a window.
 *
 * A window with @c override set to true will not be managed by the Window
 * Manager. This means that no decorations of any kind will be shown for it,
 * moving and resizing must be handled by the application, as well as the
 * window visibility.
 *
 * This should not be used for normal windows, and even for not so normal ones,
 * it should only be used when there's a good reason and with a lot of care.
 * Mishandling override windows may result situations that disrupt the normal
 * workflow of the end user.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] override If true, the window is overridden.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_override_set(Eina_Bool override);

/**
 * @brief Get the override state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return If true, the window is overridden.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_override_get(void);

/**
 * @brief Set the iconified state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] iconified If true, the window is iconified.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_iconified_set(Eina_Bool iconified);

/**
 * @brief Get the iconified state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is iconified.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_iconified_get(void);

/**
 * @brief Set the array of available window rotations.
 *
 * This function is used to set the available rotations to give the hints to
 * WM. WM will refer this hints and set the orientation window properly.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] rotations The array of rotation value.
 * @param[in] count The size of the rotations array.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_wm_available_rotations_set(const int *rotations, unsigned int count);

/**
 * @brief Get the array of available window rotations.
 *
 * This function is used to get the available rotations.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] rotations The array of rotation value.
 * @param[out] count The size of the rotations array.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_wm_available_rotations_get(int **rotations, unsigned int *count);

/**
 * @brief Set which zone this quickpanel should appear in.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] zone The requested zone for this quickpanel.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_quickpanel_zone_set(int zone);

/**
 * @brief Get which zone this quickpanel should appear in.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return The requested zone for this quickpanel.
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_quickpanel_zone_get(void);

/**
 * @brief Set the maximized state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] maximized If true, the window is maximized.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_maximized_set(Eina_Bool maximized);

/**
 * @brief Get the maximized state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is maximized.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_maximized_get(void);

/**
 * @brief Set the modal state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] modal If true, the window is modal.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_modal_set(Eina_Bool modal);

/**
 * @brief Get the modal state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is modal.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_modal_get(void);

/**
 * @brief Set the icon name of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] icon_name The icon name to set.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_icon_name_set(const char *icon_name);

/**
 * @brief Get the icon name of the window.
 *
 * The returned string is an internal one and should not be freed or modified.
 * It will also be invalid if a new icon name is set or if the window is
 * destroyed.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The icon name to set.
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_icon_name_get(void);

/**
 * @brief Set the withdrawn state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] withdrawn If true, the window is withdrawn.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_withdrawn_set(Eina_Bool withdrawn);

/**
 * @brief Get the withdrawn state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is withdrawn.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_withdrawn_get(void);

/**
 * @brief Set the role of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] role The role to set.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_role_set(const char *role);

/**
 * @brief Get the role of the window.
 *
 * The returned string is an internal one and should not be freed or modified.
 * It will also be invalid if a new role is set or if the window is destroyed.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The role to set.
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_role_get(void);

/**
 * @brief Set the window stepping used with sizing calculation.
 *
 * Base size + stepping is what is calculated for window sizing restrictions.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] w The stepping width (0 disables).
 * @param[in] h The stepping height (0 disables).
 *
 * @since 1.7
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_size_step_set(int w, int h);

/**
 * @brief Get the stepping of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] w The stepping width (0 disables).
 * @param[out] h The stepping height (0 disables).
 *
 * @since 1.7
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_size_step_get(int *w, int *h);

/**
 * @brief Set the style for the focus highlight on this window.
 *
 * Sets the style to use for theming the highlight of focused objects on the
 * given window. If @c style is NULL, the default will be used.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] style The style or @c null if none.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_focus_highlight_style_set(const char *style);

/**
 * @brief Get the style set for the focus highlight object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The style or @c null if none.
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_focus_highlight_style_get(void);

/**
 * @brief Set the borderless state of a window.
 *
 * This function requests the Window Manager to not draw any decoration around
 * the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] borderless If true, the window is borderless.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_borderless_set(Eina_Bool borderless);

/**
 * @brief Get the borderless state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is borderless.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_borderless_get(void);

/**
 * @brief Set the border style of a window.
 *
 * Sets the specific style of border to decorate window.
 *
 * @param[in] style The style or @c null if none.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_border_style_set(const char *style);

/**
 * @brief Get the border style of a window.
 *
 * @return The style or @c null if none.
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_border_style_get(void);

/**
 * @brief Constrain the maximum width and height of a window to the width and
 * height of its screen.
 *
 * When @c constrain is @c true, @c obj will never resize larger than the
 * screen.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] constrain @c true to restrict the window's maximum size.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_screen_constrain_set(Eina_Bool constrain);

/**
 * @brief Get the constraints on the maximum width and height of a window
 * relative to the width and height of its screen.
 *
 * When this function returns @c true, @c obj will never resize larger than the
 * screen.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true to restrict the window's maximum size.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_screen_constrain_get(void);

/**
 * @brief Set the array of available profiles to a window.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] profiles The string array of available profiles.
 * @param[in] count The number of members in profiles.
 *
 * @since 1.8
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_available_profiles_set(const char **profiles, unsigned int count);

/**
 * @brief Get the array of available profiles of a window.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[out] profiles The string array of available profiles.
 * @param[out] count The number of members in profiles.
 *
 * @since 1.8
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_available_profiles_get(char ***profiles, unsigned int *count);

/**
 * @brief Set the enabled status for the focus highlight in a window.
 *
 * This function will enable or disable the focus highlight only for the given
 * window, regardless of the global setting for it.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] enabled The enabled value for the highlight.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_focus_highlight_enabled_set(Eina_Bool enabled);

/**
 * @brief Get the enabled value of the focus highlight for this window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The enabled value for the highlight.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_focus_highlight_enabled_get(void);

/**
 * @brief Set the title of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] title The title.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_title_set(const char *title);

/**
 * @brief Get the title of the window.
 *
 * The returned string is an internal one and should not be freed or modified.
 * It will also be invalid if a new title is set or if the window is destroyed.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The title.
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_title_get(void);

/**
 * @brief Set the alpha channel state of a window.
 *
 * If @c alpha is true, the alpha channel of the canvas will be enabled
 * possibly making parts of the window completely or partially transparent.
 * This is also subject to the underlying system supporting it, like for
 * example, running under a compositing manager. If no compositing is
 * available, enabling this option will instead fallback to using shaped
 * windows, with @ref elm_obj_win_shaped_set.
 *
 * @note Alpha window can be enabled automatically by window theme style's
 * property. If "alpha" data.item is "1" or "true" in window style(eg.
 * elm/win/base/default), the window is switched to alpha automatically without
 * the explicit api call.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] alpha @c true if the window alpha channel is enabled, @c false
 * otherwise.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_alpha_set(Eina_Bool alpha);

/**
 * @brief Get the alpha channel state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true if the window alpha channel is enabled, @c false otherwise.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_alpha_get(void);

/**
 * @brief Set the urgent state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] urgent If true, the window is urgent.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_urgent_set(Eina_Bool urgent);

/**
 * @brief Get the urgent state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is urgent.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_urgent_get(void);

/**
 * @brief Set the rotation of the window.
 *
 * Most engines only work with multiples of 90.
 *
 * This function is used to set the orientation of the window @c obj to match
 * that of the screen. The window itself will be resized to adjust to the new
 * geometry of its contents. If you want to keep the window size, see
 * @ref elm_obj_win_rotation_with_resize_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] rotation The rotation of the window, in degrees (0-360),
 * counter-clockwise.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_rotation_set(int rotation);

/**
 * @brief Get the rotation of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The rotation of the window, in degrees (0-360), counter-clockwise.
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_rotation_get(void);

/**
 * @brief Set a window object's icon.
 *
 * This sets an image to be used as the icon for the given window, in the
 * window manager decoration part. The exact pixel dimensions of the object
 * (not object size) will be used, and the image pixels will be used as-is when
 * this function is called. If the image object has been updated, then call
 * this function again to source the image pixels and put them on the window's
 * icon. Note that only Evas image objects are allowed.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] icon The Evas image object to use for an icon.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_icon_object_set(Evas_Object *icon);

/**
 * @brief Get the icon object used for the window.
 *
 * The object returns is the one marked by @ref elm_obj_win_icon_object_set as
 * the object to use for the window icon.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The Evas image object to use for an icon.
 *
 * @ingroup Elm_Win
 */
EOAPI const Evas_Object * elm_obj_win_icon_object_get(void);

/**
 * @brief Set the minor priority of a quickpanel window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] priority The minor priority for this quickpanel.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_quickpanel_priority_minor_set(int priority);

/**
 * @brief Get the minor priority of a quickpanel window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return The minor priority for this quickpanel.
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_quickpanel_priority_minor_get(void);

/**
 * @brief Set the sticky state of the window.
 *
 * Hints the Window Manager that the window in @c obj should be left fixed at
 * its position even when the virtual desktop it's on moves or changes.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] sticky If true, the window's sticky state is enabled.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_sticky_set(Eina_Bool sticky);

/**
 * @brief Get the sticky state of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return If true, the window's sticky state is enabled.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_sticky_get(void);

/**
 * @brief Sets the keyboard mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] mode The mode, one of #Elm_Win_Keyboard_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_keyboard_mode_set(Elm_Win_Keyboard_Mode mode);

/**
 * @brief Get the keyboard mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The mode, one of #Elm_Win_Keyboard_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI Elm_Win_Keyboard_Mode  elm_obj_win_keyboard_mode_get(void);

/**
 * @brief Set the animate status for the focus highlight for this window.
 *
 * This function will enable or disable the animation of focus highlight only
 * for the given window, regardless of the global setting for it.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] animate The enabled value for the highlight animation.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_focus_highlight_animate_set(Eina_Bool animate);

/**
 * @brief Get the animate value of the focus highlight for this window.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The enabled value for the highlight animation.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_focus_highlight_animate_get(void);

/**
 * @brief Set the aspect ratio of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] aspect If 0, the window has no aspect limits, otherwise it is
 * width divided by height.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_aspect_set(double aspect);

/**
 * @brief Get the aspect ratio of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If 0, the window has no aspect limits, otherwise it is width divided
 * by height.
 *
 * @ingroup Elm_Win
 */
EOAPI double  elm_obj_win_aspect_get(void);

/**
 * @brief Set the major priority of a quickpanel window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] priority The major priority for this quickpanel or -1.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_quickpanel_priority_major_set(int priority);

/**
 * @brief Get the major priority of a quickpanel window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return The major priority for this quickpanel or -1.
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_quickpanel_priority_major_get(void);

/**
 * @brief Sets the indicator opacity mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] mode The mode, one of #Elm_Win_Indicator_Opacity_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_indicator_opacity_set(Elm_Win_Indicator_Opacity_Mode mode);

/**
 * @brief Get the indicator opacity mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The mode, one of #Elm_Win_Indicator_Opacity_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI Elm_Win_Indicator_Opacity_Mode  elm_obj_win_indicator_opacity_get(void);

/**
 * @brief Set the demand_attention state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] demand_attention If true, the window is demand_attention.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_demand_attention_set(Eina_Bool demand_attention);

/**
 * @brief Get the demand_attention state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return If true, the window is demand_attention.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_demand_attention_get(void);

/**
 * @brief Set the preferred rotation value.
 *
 * This function is used to set the orientation of window @c obj to spicific
 * angle fixed.
 *
 * @param[in] rotation The preferred rotation of the window in degrees (0-360),
 * counter-clockwise.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_wm_preferred_rotation_set(int rotation);

/**
 * @brief Get the preferred rotation value.
 *
 * This function is used to get the preferred rotoation value.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The preferred rotation of the window in degrees (0-360),
 * counter-clockwise.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_wm_preferred_rotation_get(void);

/**
 * @brief Set the layer of the window.
 *
 * What this means exactly will depend on the underlying engine used.
 *
 * In the case of X11 backed engines, the value in @c layer has the following
 * meanings - less than 3 means that the window will be placed below all
 * others, more than 5 means that the window will be placed above all others,
 * and anything else means that the window will be placed in the default layer.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] layer The layer of the window.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_layer_set(int layer);

/**
 * @brief Get the layer of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The layer of the window.
 *
 * @ingroup Elm_Win
 */
EOAPI int  elm_obj_win_layer_get(void);

/**
 * @brief Set the profile of a window.
 *
 * @if MOBILE @since_tizen 2.4 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] profile The string value of a window profile.
 *
 * @since 1.8
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_profile_set(const char *profile);

/**
 * @brief Get the profile of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The string value of a window profile.
 *
 * @since 1.8
 *
 * @ingroup Elm_Win
 */
EOAPI const char * elm_obj_win_profile_get(void);

/**
 * @brief Set the shaped state of a window.
 *
 * Shaped windows, when supported, will render the parts of the window that has
 * no content, transparent.
 *
 * If @c shaped is false, then it is strongly advised to have some background
 * object or cover the entire window in any other way, or the parts of the
 * canvas that have no data will show framebuffer artifacts.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] shaped If @c true, the window is shaped.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_shaped_set(Eina_Bool shaped);

/**
 * @brief Get the shaped state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return If @c true, the window is shaped.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_shaped_get(void);

/**
 * @brief Set the fullscreen state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] fullscreen If @c true, the window is fullscreen.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_fullscreen_set(Eina_Bool fullscreen);

/**
 * @brief Get the fullscreen state of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return If @c true, the window is fullscreen.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_fullscreen_get(void);

/**
 * @brief Set the manual rotation done mode.
 *
 * This function is used to set or reset the manual rotation done mode. the
 * message of rotation done is sent to WM after rendering its canvas in
 * Ecore_Evas. but if set the manual rotation done mode, it's disabled and user
 * should call this explicitly to sends the message.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] set @c true to set manual rotation done mode, @c false otherwise.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_wm_manual_rotation_done_set(Eina_Bool set);

/**
 * @brief Get the state of manual rotation done mode.
 *
 * This function is used to get the state of manual rotation done mode.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return @c true to set manual rotation done mode, @c false otherwise.
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_wm_manual_rotation_done_get(void);

/**
 * @brief Sets the indicator mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] mode The mode, one of #Elm_Win_Indicator_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_indicator_mode_set(Elm_Win_Indicator_Mode mode);

/**
 * @brief Get the indicator mode of the window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The mode, one of #Elm_Win_Indicator_Mode.
 *
 * @ingroup Elm_Win
 */
EOAPI Elm_Win_Indicator_Mode  elm_obj_win_indicator_mode_get(void);

/**
 * @brief Set if this window is an illume conformant window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] conformant The conformant flag.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_conformant_set(Eina_Bool conformant);

/**
 * @brief Get if this window is an illume conformant window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The conformant flag.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_conformant_get(void);

/**
 * @brief Set the base window size used with stepping calculation
 *
 * Base size + stepping is what is calculated for window sizing restrictions.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] w The base width.
 * @param[in] h The base height.
 *
 * @since 1.7
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_size_base_set(int w, int h);

/**
 * @brief Get the base size of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] w The base width.
 * @param[out] h The base height.
 *
 * @since 1.7
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_size_base_get(int *w, int *h);

/**
 * @brief Set a window to be an illume quickpanel window.
 *
 * By default window objects are not quickpanel windows.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] quickpanel The quickpanel flag.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_quickpanel_set(Eina_Bool quickpanel);

/**
 * @brief Get if this window is a quickpanel or not.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @return The quickpanel flag.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_quickpanel_get(void);

/**
 * @brief Rotates the window and resizes it.
 *
 * Like @ref elm_obj_win_rotation_set, but it also resizes the window's
 * contents so that they fit inside the current window geometry.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] rotation The rotation of the window in degrees (0-360),
 * counter-clockwise.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_rotation_with_resize_set(int rotation);

/**
 * @brief Set the window to be skipped by keyboard focus.
 *
 * This sets the window to be skipped by normal keyboard input. This means a
 * window manager will be asked to not focus this window as well as omit it
 * from things like the taskbar, pager, "alt-tab" list etc. etc.
 *
 * Call this and enable it on a window BEFORE you show it for the first time,
 * otherwise it may have no effect.
 *
 * Use this for windows that have only output information or might only be
 * interacted with by the mouse or fingers, and never for typing input. Be
 * careful that this may have side-effects like making the window
 * non-accessible in some cases unless the window is specially handled. Use
 * this with care.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] skip The skip flag state ($true if it is to be skipped).
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_prop_focus_skip_set(Eina_Bool skip);

/**
 * @brief Get the screen position of a window.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x The int to store the x coordinate to.
 * @param[out] y The int to store the y coordinate to.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_screen_position_get(int *x, int *y);

/**
 * @brief Query whether window manager supports window rotation or not.
 *
 * The window manager rotation allows the WM to controls the rotation of
 * application windows. It is designed to support synchronized rotation for the
 * multiple application windows at same time.
 *
 * See also @ref elm_obj_win_wm_preferred_rotation_get,
 * @ref elm_obj_win_wm_available_rotations_get,
 * @ref elm_obj_win_wm_manual_rotation_done_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_wm_rotation_supported_get(void);

/**
 * @internal
 *
 * Get the Ecore_X_Window of an Evas_Object.
 *
 * @ingroup Elm_Win
 */
EOAPI Ecore_X_Window  elm_obj_win_xwindow_get(void);

/**
 * @brief Get whether a window has focus.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_focus_get(void);

/**
 * @brief Get screen geometry details for the screen that a window is on.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] x Where to return the horizontal offset value. May be @c null.
 * @param[out] y Where to return the vertical offset value. May be @c null.
 * @param[out] w Where to return the width value. May be @c null.
 * @param[out] h Where to return the height value. May be @c null.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_screen_size_get(int *x, int *y, int *w, int *h);

/**
 * @internal
 *
 * @brief Get the Main Menu of a window.
 *
 * @return The Main Menu of the window ($null on error).
 *
 * @ingroup Elm_Win
 */
EOAPI Evas_Object * elm_obj_win_main_menu_get(void);

/**
 * @internal
 *
 * @brief Get the Ecore_Wl_Window of an Evas_Object.
 *
 * @return The Ecore_Wl_Window of @c obj.
 *
 * @ingroup Elm_Win
 */
EOAPI Ecore_Wl_Window * elm_obj_win_wl_window_get(void);

/**
 * @brief Get the Ecore_Cocoa_Window of an Evas.Object.
 *
 * @return The Ecore_Cocoa_Window of @c obj.
 *
 * @ingroup Elm_Win
 */
EOAPI Ecore_Cocoa_Window * elm_obj_win_cocoa_window_get(void);

/**
 * @brief Get the Ecore_Win32_Window of an Evas_Object
 *
 * @return The Ecore_Win32_Window of @c obj.
 *
 * @since 1.16
 *
 * @ingroup Elm_Win
 */
EOAPI Ecore_Win32_Window * elm_obj_win_win32_window_get(void);

/**
 * @internal
 *
 * @brief Get the Ecore_Window of an Evas_Object
 *
 * When Elementary is using a Wayland engine, this function will return the
 * surface id of the elm window's surface.
 *
 * @return The Ecore_Window of an Evas_Object.
 *
 * @since 1.8
 *
 * @ingroup Elm_Win
 */
EOAPI Ecore_Window  elm_obj_win_window_id_get(void);

/**
 * @brief Get screen dpi for the screen that a window is on.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] xdpi Pointer to value to store return horizontal dpi. May be
 * @c null.
 * @param[out] ydpi Pointer to value to store return vertical dpi. May be
 * @c null.
 *
 * @since 1.7
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_screen_dpi_get(int *xdpi, int *ydpi);

/**
 * @brief Get the inlined image object handle
 *
 * When you create a window with elm_win_add() of type #ELM_WIN_INLINED_IMAGE,
 * then the window is in fact an evas image object inlined in the parent
 * canvas. You can get this object (be careful to not manipulate it as it is
 * under control of elementary), and use it to do things like get pixel data,
 * save the image to a file, etc.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The inlined image object or @c null if none exists.
 *
 * @ingroup Elm_Win
 */
EOAPI Evas_Object * elm_obj_win_inlined_image_object_get(void);

/**
 * @brief The window name.
 *
 * The meaning of name depends on the underlying windowing system.
 *
 * The window name is a constructing property that need to be set at creation
 * within @ref eo_add.
 *
 * @note Once set, it can NOT be modified afterward.
 *
 * Can only be used at creation time, within @ref eo_add.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] name
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_name_set(const char *name);

/**
 * @brief The type of the window.
 *
 * It is a hint of how the Window Manager should handle it.
 *
 * The window type is a constructing property that need to be set at creation
 * within @ref eo_add.
 *
 * @note Once set, it can NOT be modified afterward.
 *
 * Can only be used at creation time, within @ref eo_add.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] type
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_type_set(Elm_Win_Type type);

/**
 * @brief The type of the window.
 *
 * It is a hint of how the Window Manager should handle it.
 *
 * The window type is a constructing property that need to be set at creation
 * within @ref eo_add.
 *
 * @note Once set, it can NOT be modified afterward.
 *
 * If the object is not window object, return #ELM_WIN_UNKNOWN.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Win
 */
EOAPI Elm_Win_Type  elm_obj_win_type_get(void);

/**
 * @brief Set the noblank property of a window.
 *
 * The "noblank" property is a way to request the display on which the windowis
 * shown does not blank, screensave or otherwise hide or obscure the window. It
 * is intended for uses such as media playback on a television where a user may
 * not want to be interrupted by an idle screen. The noblank property may have
 * no effect if the window is iconified/minimized or hidden.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] noblank If true, the window is set to noblank.
 *
 * @since 1.11
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_noblank_set(Eina_Bool noblank);

/**
 * @brief Get the noblank property of a window.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return If true, the window is set to noblank.
 *
 * @since 1.11
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_noblank_get(void);

/**
 * @brief Get the trap data associated with a window.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @return The trap data of the window.
 *
 * @since 1.12
 *
 * @ingroup Elm_Win
 */
EOAPI void * elm_obj_win_trap_data_get(void);

#ifdef ELM_WIN_PROTECTED
/**
 * @brief Internal. Used to completent the fake window type.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] oee
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_fake_canvas_set(Ecore_Evas *oee);
#endif

/**
 * @brief To notify the rotation done to WM manually.
 *
 * This function is used to notify the rotation done to WM manually.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @since 1.9
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_wm_manual_rotation_done_manual(void);

/**
 * @brief Create a socket to provide the service for Plug widget.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] svcnum A number (any value, 0 being the common default) to
 * differentiate multiple instances of services with the same name.
 * @param[in] svcsys A boolean that if true, specifies to create a system-wide
 * service all users can connect to, otherwise the service is private to the
 * user id that created the service.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_socket_listen(const char *svcname, int svcnum, Eina_Bool svcsys);

/**
 * @brief Send a command to the windowing environment
 *
 * This is intended to work in touchscreen or small screen device environments
 * where there is a more simplistic window management policy in place. This
 * uses the window object indicated to select which part of the environment to
 * control (the part that this window lives in), and provides a command and an
 * optional parameter structure (use NULL for this if not needed).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] params Optional parameters for the command.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_illume_command_send(Elm_Illume_Command command, void *params);

/**
 * @brief Activate a window object.
 *
 * This function sends a request to the Window Manager to activate the window
 * pointed by @c obj. If honored by the WM, the window will receive the
 * keyboard focus.
 *
 * @note This is just a request that a Window Manager may ignore, so calling
 * this function does not ensure in any way that the window will be the active
 * one after it.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_activate(void);

/**
 * @brief Add @c subobj as a resize object of window @c obj.
 *
 * Setting an object as a resize object of the window means that the @c subobj
 * child's size and position will be controlled by the window directly. That
 * is, the object will be resized to match the window size and should never be
 * moved or resized manually by the developer.
 *
 * In addition, resize objects of the window control what the minimum size of
 * it will be, as well as whether it can or not be resized by the user.
 *
 * For the end user to be able to resize a window by dragging the handles or
 * borders provided by the Window Manager, or using any other similar
 * mechanism, all of the resize objects in the window should have their @ref
 * evas_object_size_hint_weight_set set to EVAS_HINT_EXPAND.
 *
 * Also notice that the window can get resized to the current size of the
 * object if the EVAS_HINT_EXPAND is set after the call to this. So if the
 * object should get resized to the size of the window, set this hint before
 * adding it as a resize object (this happens because the size of the window
 * and the object are evaluated as soon as the object is added to the window).
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The resize object to add.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_resize_object_add(Evas_Object *subobj);

/**
 * @brief Raise a window object.
 *
 * Places the window pointed by @c obj at the top of the stack, so that it's
 * not covered by any other window.
 *
 * If @ref elm_obj_win_override_set is not set, the Window Manager may ignore
 * this request.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_raise(void);

/**
 * @brief Lower a window object.
 *
 * Places the window pointed by @c obj at the bottom of the stack, so that no
 * other window is covered by it.
 *
 * If @ref elm_obj_win_override_set is not set, the Window Manager may ignore
 * this request.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_lower(void);

/**
 * @brief Delete @c subobj as a resize object of window @c obj.
 *
 * This function removes the object @c subobj from the resize objects of the
 * window @c obj. It will not delete the object itself, which will be left
 * unmanaged and should be deleted by the developer, manually handled or set as
 * child of some other container.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] subobj The resize object to add.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_resize_object_del(Evas_Object *subobj);

/**
 * @brief Center a window on its screen
 *
 * This function centers window @c obj horizontally and/or vertically based on
 * the values of @c h and @c v.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 * @deprecated Deprecated since Tizen 2.4
 *
 * @param[in] v If true, center vertically. If false, do not change vertical
 * location.
 *
 * @ingroup Elm_Win
 */
EOAPI void  elm_obj_win_center(Eina_Bool h, Eina_Bool v);

/**
 * @internal
 *
 * @brief Set keygrab value of the window
 *
 * This function grabs the @c key of window using @c grab_mode.
 *
 * @param[in] modifiers This is for the keymask feature. Currently this feature
 * is not supported.
 * @param[in] not_modifiers This is for the keymask feature. Currently this
 * feature is not supported.
 * @param[in] proirity This is for the priority of keygrab. Currently this
 * feature is not supported.
 * @param[in] grab_mode According to the grabmode, it can grab key differently.
 *
 * @return @c true = success, @c false = error
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_keygrab_set(const char *key, Evas_Modifier_Mask modifiers, Evas_Modifier_Mask not_modifiers, int proirity, Elm_Win_Keygrab_Mode grab_mode);

/**
 * @internal
 *
 * @brief Unset keygrab value of the window
 *
 * This function unset keygrab value. Ungrab @c key of window.
 *
 * @param[in] modifiers This is for the keymask feature. Currently this feature
 * is not supported.
 * @param[in] not_modifiers This is for the keymask feature. Currently this
 * feature is not supported.
 *
 * @return @c true = success, @c false = error
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_keygrab_unset(const char *key, Evas_Modifier_Mask modifiers, Evas_Modifier_Mask not_modifiers);

/**
 * @internal
 *
 * @brief Start moving or resizing the window.
 *
 * The user can request the display server to start moving or resizing the
 * window by combining modes from Elm.Win.Move_Resize_Mode. This API can only
 * be called if none of the following conditions is true:
 *
 * 1. Called in the absence of a pointer down event, 2. Called more than once
 * before a pointer up event, 3. Called when the window is already being
 * resized or moved, 4. Called with an unsupported combination of modes.
 *
 * Right usage: 1. Pointer (mouse or touch) down event, 2.
 * elm_win_move_resize_start called only once with a supported mode, 3. Pointer
 * (mouse or touch) up event.
 *
 * If a pointer up event occurs after calling the function, it automatically
 * ends the window move and resize operation.
 *
 * Currently, only the following 9 combinations are allowed, and possibly more
 * combinations may be added in the future:
 *
 * 1. ELM_WIN_MOVE_RESIZE_MOVE 2. ELM_WIN_MOVE_RESIZE_TOP 3.
 * ELM_WIN_MOVE_RESIZE_BOTTOM 4. ELM_WIN_MOVE_RESIZE_LEFT 5.
 * ELM_WIN_MOVE_RESIZE_RIGHT 6. ELM_WIN_MOVE_RESIZE_TOP |
 * ELM_WIN_MOVE_RESIZE_LEFT 7. ELM_WIN_MOVE_RESIZE_TOP |
 * ELM_WIN_MOVE_RESIZE_RIGHT 8. ELM_WIN_MOVE_RESIZE_BOTTOM |
 * ELM_WIN_MOVE_RESIZE_LEFT 9. ELM_WIN_MOVE_RESIZE_BOTTOM |
 * ELM_WIN_MOVE_RESIZE_RIGHT
 *
 * In particular move and resize can not happen simultaneously.
 *
 * @note the result of this API can only guarantee that the request has been
 * forwarded to the server, but there is no guarantee that the request can be
 * processed by the display server.
 *
 * @param[in] mode The requested move or resize mode.
 *
 * @return @c true if the request was successfully sent to the display server,
 * @c false in case of error.
 *
 * @ingroup Elm_Win
 */
EOAPI Eina_Bool  elm_obj_win_move_resize_start(Elm_Win_Move_Resize_Mode mode);

EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_DELETE_REQUEST;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_MOVED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_WITHDRAWN;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_ICONIFIED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_NORMAL;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_STICK;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_UNSTICK;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_FULLSCREEN;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_UNFULLSCREEN;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_MAXIMIZED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_UNMAXIMIZED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_IOERR;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_INDICATOR_PROP_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_ROTATION_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_PROFILE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_WM_ROTATION_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_ANIMATOR_TICK;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_THEME_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_WIN_EVENT_ELM_ACTION_BLOCK_MENU;

/**
 * No description
 */
#define ELM_WIN_EVENT_DELETE_REQUEST (&(_ELM_WIN_EVENT_DELETE_REQUEST))

/**
 * No description
 */
#define ELM_WIN_EVENT_MOVED (&(_ELM_WIN_EVENT_MOVED))

/**
 * No description
 */
#define ELM_WIN_EVENT_WITHDRAWN (&(_ELM_WIN_EVENT_WITHDRAWN))

/**
 * No description
 */
#define ELM_WIN_EVENT_ICONIFIED (&(_ELM_WIN_EVENT_ICONIFIED))

/**
 * No description
 */
#define ELM_WIN_EVENT_NORMAL (&(_ELM_WIN_EVENT_NORMAL))

/**
 * No description
 */
#define ELM_WIN_EVENT_STICK (&(_ELM_WIN_EVENT_STICK))

/**
 * No description
 */
#define ELM_WIN_EVENT_UNSTICK (&(_ELM_WIN_EVENT_UNSTICK))

/**
 * No description
 */
#define ELM_WIN_EVENT_FULLSCREEN (&(_ELM_WIN_EVENT_FULLSCREEN))

/**
 * No description
 */
#define ELM_WIN_EVENT_UNFULLSCREEN (&(_ELM_WIN_EVENT_UNFULLSCREEN))

/**
 * No description
 */
#define ELM_WIN_EVENT_MAXIMIZED (&(_ELM_WIN_EVENT_MAXIMIZED))

/**
 * No description
 */
#define ELM_WIN_EVENT_UNMAXIMIZED (&(_ELM_WIN_EVENT_UNMAXIMIZED))

/**
 * No description
 */
#define ELM_WIN_EVENT_IOERR (&(_ELM_WIN_EVENT_IOERR))

/**
 * No description
 */
#define ELM_WIN_EVENT_INDICATOR_PROP_CHANGED (&(_ELM_WIN_EVENT_INDICATOR_PROP_CHANGED))

/**
 * No description
 */
#define ELM_WIN_EVENT_ROTATION_CHANGED (&(_ELM_WIN_EVENT_ROTATION_CHANGED))

/**
 * No description
 */
#define ELM_WIN_EVENT_PROFILE_CHANGED (&(_ELM_WIN_EVENT_PROFILE_CHANGED))

/**
 * No description
 */
#define ELM_WIN_EVENT_WM_ROTATION_CHANGED (&(_ELM_WIN_EVENT_WM_ROTATION_CHANGED))

/**
 * No description
 */
#define ELM_WIN_EVENT_ANIMATOR_TICK (&(_ELM_WIN_EVENT_ANIMATOR_TICK))

/**
 * No description
 */
#define ELM_WIN_EVENT_THEME_CHANGED (&(_ELM_WIN_EVENT_THEME_CHANGED))

/**
 * No description
 */
#define ELM_WIN_EVENT_ELM_ACTION_BLOCK_MENU (&(_ELM_WIN_EVENT_ELM_ACTION_BLOCK_MENU))

#endif
