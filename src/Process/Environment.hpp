#pragma once

namespace sapp
{
namespace Environment
{
std::string get(const char* inName);
bool set(const char* inName, const std::string& inValue);
};
}
