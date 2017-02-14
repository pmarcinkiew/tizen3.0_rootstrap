#ifndef DALI_TOOLKIT_PROPERTY_INDEX_RANGES_H
#define DALI_TOOLKIT_PROPERTY_INDEX_RANGES_H

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

// EXTERNAL INCLUDES
#include <dali/public-api/object/property-index-ranges.h>

namespace Dali
{

namespace Toolkit
{

/**
 * @brief The start and end property ranges.
 * @SINCE_1_1.45
 */
enum PropertyRanges
{
  VISUAL_PROPERTY_BASE_START_INDEX  = CORE_PROPERTY_MAX_INDEX + 1,             ///< Visual Property Base Start Index. @SINCE_1_1.45
  VISUAL_PROPERTY_BASE_END_INDEX   = VISUAL_PROPERTY_BASE_START_INDEX + 100,   ///< Visual Property Base End Index. @SINCE_1_1.45
  VISUAL_PROPERTY_START_INDEX = VISUAL_PROPERTY_BASE_END_INDEX + 1,            ///< Visual Property Start Index. @SINCE_1_1.45
  VISUAL_PROPERTY_END_INDEX   = VISUAL_PROPERTY_START_INDEX + 100000,          ///< Visual Property End Index. @SINCE_1_1.45
};

} // namespace Toolkit

} // namespace Dali

#endif // DALI_TOOLKIT_PROPERTY_INDEX_RANGES_H
