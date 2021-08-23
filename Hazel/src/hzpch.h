#pragma once

#include "Hazel/Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Hazel/Core/Base.h"

#include "Hazel/Core/Log.h"



#ifdef  HZ_PLATFORM_WINDOWS
	#include <Windows.h>
#endif //  HZ_PLATFORM_WINDOWS
