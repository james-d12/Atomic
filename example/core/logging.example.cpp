#include <iostream>
#include <atomic/core.hpp>

int main()
{
    atomic::detail::log("general log");
    atomic::detail::trace("Trace stuff");
    atomic::detail::info("Info stuff");
    atomic::detail::warn("Warning stuff");
    atomic::detail::error("Error bad ting");

    std::cout << atomic::detail::out_of_bounds(100, 50) << std::endl;

    return 0;
}