#pragma once

namespace sapp
{
using i8 = std::int8_t; // Note: signed char, NOT char
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using f32 = float;
using f64 = double;
// using f128 = long double; // not guaranteed - 96 on 32-bit GCC/Clang, 64 on MSVC altogether

// use when representing unsigned in char arrays
using uchar = unsigned char;

using size_t = std::size_t;
using ptrdiff_t = std::ptrdiff_t;

using Handle = void*;

template <class Ret, class... Args>
using Function = std::function<Ret(Args...)>;

using StringList = std::vector<std::string>;

template <typename T, typename U>
using HashMap = std::unordered_map<T, U>;

template <typename T>
using Dictionary = HashMap<std::string, T>;
}