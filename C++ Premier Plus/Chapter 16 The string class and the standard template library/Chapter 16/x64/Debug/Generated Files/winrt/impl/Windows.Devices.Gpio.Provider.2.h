// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#ifndef WINRT_Windows_Devices_Gpio_Provider_2_H
#define WINRT_Windows_Devices_Gpio_Provider_2_H
#include "winrt/impl/Windows.Devices.Gpio.Provider.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Gpio::Provider
{
    struct __declspec(empty_bases) GpioPinProviderValueChangedEventArgs : winrt::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs
    {
        GpioPinProviderValueChangedEventArgs(std::nullptr_t) noexcept {}
        GpioPinProviderValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs(ptr, take_ownership_from_abi) {}
        explicit GpioPinProviderValueChangedEventArgs(winrt::Windows::Devices::Gpio::Provider::ProviderGpioPinEdge const& edge);
    };
}
#endif
