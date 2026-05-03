#pragma once

#include <chrono>

class Timer {
public:
    Timer(std::chrono::milliseconds start, std::chrono::milliseconds period)\
        : prev_{start}
        , period_{period}
    {}

    bool timeHasCome(std::chrono::milliseconds now) const;
private:
    mutable std::chrono::milliseconds prev_{0};
    std::chrono::milliseconds period_{1000};
};
