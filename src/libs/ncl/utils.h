#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <utility>
#include <sstream>

// Helper function to convert ranges to string
inline std::string RangesToString(const std::vector<std::pair<int, int>>& ranges)
{
    std::string result;
    for (const auto& range : ranges)
    {
        if (!result.empty())
        {
            result += ", ";
        }
        if (range.first == range.second)
        {
            result += std::to_string(range.first);
        }
        else
        {
            result += std::to_string(range.first) + "-" + std::to_string(range.second);
        }
    }
    return result;
}

// Helper function to expand ranges into individual numbers
inline std::string ExpandRanges(const std::vector<std::pair<int, int>>& ranges)
{
    std::string result = "(";
    for (const auto& range : ranges)
    {
        for (int i = range.first; i <= range.second; ++i)
        {
            if (result.length() > 1) // Skip initial bracket
            {
                result += " ";
            }
            result += std::to_string(i);
        }
    }
    result += ")";
    return result;
}

#endif // UTILS_H
