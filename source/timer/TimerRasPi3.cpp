#include "timer/TimerRasPi3.h"

void TimerRasPi3::start() {
    this->start = SYS_TIMER[SYS_TIMER_C0];
}

void TimerRasPi3::waitMicro(uint32_t us) {
    uint32_t current = SYS_TIMER[SYS_TIMER_C0];
    uint32_t elapsed = this->start - current;
    
    // If time already elapsed, return
    if (us <= elapsed) {
        return;
    }

    // Add the delay to the current count
    // and, put that into compare 0's register
    sys_timer[SYS_TIMER_C0] = currentCount + us - elapsed;

    // Clear M0
    sys_timer[SYS_TIMER_CS] = 1;

    // Wait until the CS register has a 1 in
    // the 0 position, which happens when the
    // timer expires.
    while (!(SYS_TIMER[SYS_TIMER_CS] & 1));
}
