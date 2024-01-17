#pragma once

namespace sapp::priv
{
template <typename... Args>
constexpr void unused(Args&&... args)
{
	(static_cast<void>(std::forward<Args>(args)), ...);
}
}

#define UNUSED(...) sapp::priv::unused(__VA_ARGS__)
