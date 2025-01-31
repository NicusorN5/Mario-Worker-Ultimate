#pragma once

#include <raylib.h>
#include <vector>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits>
#include <array>
#include <filesystem>
#include <span>

#include "Point.hpp"

template<typename N>
concept SignedInteger = std::is_signed_v<N>;

template <SignedInteger T>
int signum(T val)
{
    return (T(0) < val) - (val < T(0));
}