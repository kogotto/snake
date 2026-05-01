#include <Timer.hpp>


bool Timer::timeHasCome(std::chrono::milliseconds now) const {
    if (now <= prev_ + period_) {
        prev_ = now;
        return true;
    }
    return false;
}
