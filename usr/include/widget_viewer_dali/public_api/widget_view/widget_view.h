#ifndef __DALI_WIDGET_VIEW_WIDGET_VIEW_H__
#define __DALI_WIDGET_VIEW_WIDGET_VIEW_H__

/*
 * Samsung API
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Flora License, Version 1.1 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://floralicense.org/license/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// EXTERNAL INCLUDES
#include <dali-toolkit/public-api/controls/control.h>

namespace Dali
{

namespace WidgetView
{

namespace Internal DALI_INTERNAL
{
class WidgetView;
}

/**
 * @addtogroup dali_widget_view
 * @{
 */

/**
 * @brief WidgetView is a class for displaying the widget image and controlling the widget.
 * Input events that WidgetView gets are delivered to the widget.
 *
 * Signals
 * | %Signal Name                | Method                                 |
 * |-----------------------------|----------------------------------------|
 * | widgetAdded                 | @ref WidgetAddedSignal()               |
 * | widgetDeleted               | @ref WidgetDeletedSignal()             |
 * | widgetCreationAborted       | @ref WidgetCreationAbortedSignal()     |
 * | widgetContentUpdated        | @ref WidgetContentUpdatedSignal()      |
 * | widgetUpdatePeriodChanged   | @ref WidgetUpdatePeriodChangedSignal() |
 * | widgetFaulted               | @ref WidgetFaultedSignal()             |
 *
 * @since_tizen 3.0
 */
class DALI_IMPORT_API WidgetView : public Toolkit::Control
{
public:

  /**
   * @brief The start and end property ranges for this control.
   * @SINCE_1_0.0
   */
  enum PropertyRange
  {
    PROPERTY_START_INDEX = Control::CONTROL_PROPERTY_END_INDEX + 1,  ///< @SINCE_1_0.0
    PROPERTY_END_INDEX =   PROPERTY_START_INDEX + 1000,              ///< Reserve property indices @SINCE_1_0.0
  };

  /**
   * @brief An enumeration of properties belonging to the WidgetView class.
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @SINCE_1_0.0
   */
  struct Property
  {
    /**
     * @brief An enumeration of properties belonging to the WidgetView class.
     * @privlevel public
     * @privilege %http://tizen.org/privilege/widget.viewer
     * @SINCE_1_0.0
     */
    enum
    {
      // Event side properties

      /**
       * @brief name "widgetId", Get the id of the widget, type string, read-only
       * @SINCE_1_0.0
       */
      WIDGET_ID = PROPERTY_START_INDEX,

      /**
       * @brief name "instanceId", type string, read-only
       * @SINCE_1_0.0
       */
      INSTANCE_ID,

      /**
       * @brief name "contentInfo", type string, read-only
       * @SINCE_1_0.0
       */
      CONTENT_INFO,

      /**
       * @brief name "title", type string, read-only
       * @SINCE_1_0.0
       */
      TITLE,

      /**
       * @brief name "updatePeriod", type float, read-only
       * @SINCE_1_0.0
       */
      UPDATE_PERIOD,

      /**
       * @brief name "preview", type boolean if it is a show/hide flag, map otherwise
       * @SINCE_1_0.0
       */
      PREVIEW,

      /**
       * @brief name "loadingText", type boolean if it is a show/hide flag, map otherwise
       * @SINCE_1_0.0
       */
      LOADING_TEXT,

      /**
       * @brief name "widgetStateFaulted", type boolean
       * @SINCE_1_0.0
       */
      WIDGET_STATE_FAULTED,

      /**
       * @brief name "permanentDelete", type boolean
       * @SINCE_1_0.0
       */
      PERMANENT_DELETE,

    };
  };


  /**
   * @brief Create widget view.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @param[in] widgetId The widget id.
   * @param[in] contentInfo Contents that will be given to the widget instance.
   * @param[in] width The widget width.
   * @param[in] height The widget height.
   * @param[in] updatePeriod The period of updating contents of the widget.
   * @return A handle to WidgetView.
   */
  static WidgetView New( const std::string& widgetId, const std::string& contentInfo, int width, int height, float updatePeriod );

  /**
   * @brief Downcast a handle to WidgetView handle.
   *
   * If the BaseHandle points is a WidgetView the downcast returns a valid handle.
   * If not the returned handle is left empty.
   *
   * @since_tizen 3.0
   * @param[in] handle Handle to an object
   * @return handle to a WidgetView or an empty handle
   */
  static WidgetView DownCast( BaseHandle handle );

  /**
   * @brief Creates an empty handle.
   * @since_tizen 3.0
   */
  WidgetView();

  /**
   * @brief Copy constructor.
   *
   * @since_tizen 3.0
   * @param[in] handle The handle to copy from.
   */
  WidgetView( const WidgetView& handle );

  /**
   * @brief Assignment operator.
   *
   * @since_tizen 3.0
   * @param[in] handle The handle to copy from.
   * @return A reference to this.
   */
  WidgetView& operator=( const WidgetView& handle );

  /**
   * @brief Destructor
   *
   * This is non-virtual since derived Handle types must not contain data or virtual methods.
   * @since_tizen 3.0
   */
  ~WidgetView();

  /**
   * @brief Pauses a given widget.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return true on success, false otherwise.
   */
  bool PauseWidget();

  /**
   * @brief Resume a given widget.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return true on success, false otherwise.
   */
  bool ResumeWidget();

  /**
   * @brief Cancels touch event procedure.
   * If you call this function after feed the touch down event, the widget will get ON_HOLD events.
   * If a widget gets ON_HOLD event, it will not do anything even if you feed touch up event.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return true on success, false otherwise.
   */
  bool CancelTouchEvent();

  /**
   * @brief Activate a widget in faulted state.
   * A widget in faulted state MUST be activated before adding the widget.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   */
  void ActivateFaultedWidget();

public: //Signals

  typedef Signal< void ( WidgetView ) > WidgetViewSignalType;   ///< WidgetView signal type @since_tizen 3.0

  /**
   * @brief This signal is emitted when the widget is added.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetAddedSignal();

  /**
   * @brief This signal is emitted when the widget is deleted.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetDeletedSignal();

  /**
   * @brief This signal is emitted when the widget creation is aborted.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetCreationAbortedSignal();

  /**
   * @brief This signal is emitted when the widget content is updated.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetContentUpdatedSignal();

  /**
   * @brief This signal is emitted when the widget update period is changed.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetUpdatePeriodChangedSignal();

  /**
   * @brief This signal is emitted when the widget process is not running.
   *
   * @since_tizen 3.0
   * @privlevel public
   * @privilege %http://tizen.org/privilege/widget.viewer
   * @return The signal to connect to.
   */
  WidgetViewSignalType& WidgetFaultedSignal();

public: // Not intended for application developers

  /**
   * @internal
   * @brief Creates a handle using the WidgetView::Internal implementation.
   *
   * @since_tizen 3.0
   * @param[in] implementation The WidgetView implementation.
   */
  DALI_INTERNAL WidgetView( Internal::WidgetView& implementation );

  /**
   * @internal
   * @brief Allows the creation of this control from an Internal::CustomActor pointer.
   *
   * @since_tizen 3.0
   * @param[in] internal A pointer to the internal CustomActor.
   */
  DALI_INTERNAL WidgetView( Dali::Internal::CustomActor* internal );
};

/**
 * @}
 */
} // namespace WidgetView

} // namespace Dali

#endif // __DALI_WIDGET_VIEW_WIDGET_VIEW_H__
