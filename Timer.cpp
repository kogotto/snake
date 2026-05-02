#include <Timer.hpp>


bool Timer::timeHasCome(std::chrono::milliseconds now) const {
    if ( prev_ + period_<= now ) {
        prev_ = now;
        return true;
    }
    return false;
}
