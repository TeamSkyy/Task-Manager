// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#ifndef WINRT_Windows_Phone_UI_Input_2_H
#define WINRT_Windows_Phone_UI_Input_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Phone.UI.Input.1.h"
WINRT_EXPORT namespace winrt::Windows::Phone::UI::Input
{
    struct __declspec(empty_bases) BackPressedEventArgs : winrt::Windows::Phone::UI::Input::IBackPressedEventArgs
    {
        BackPressedEventArgs(std::nullptr_t) noexcept {}
        BackPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::UI::Input::IBackPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraEventArgs : winrt::Windows::Phone::UI::Input::ICameraEventArgs
    {
        CameraEventArgs(std::nullptr_t) noexcept {}
        CameraEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::UI::Input::ICameraEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct HardwareButtons
    {
        HardwareButtons() = delete;
        static auto BackPressed(winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::BackPressedEventArgs> const& handler);
        using BackPressed_revoker = impl::factory_event_revoker<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics, &impl::abi_t<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics>::remove_BackPressed>;
        [[nodiscard]] static auto BackPressed(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::BackPressedEventArgs> const& handler);
        static auto BackPressed(winrt::event_token const& token);
        static auto CameraHalfPressed(winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        using CameraHalfPressed_revoker = impl::factory_event_revoker<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2, &impl::abi_t<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2>::remove_CameraHalfPressed>;
        [[nodiscard]] static auto CameraHalfPressed(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        static auto CameraHalfPressed(winrt::event_token const& token);
        static auto CameraPressed(winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        using CameraPressed_revoker = impl::factory_event_revoker<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2, &impl::abi_t<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2>::remove_CameraPressed>;
        [[nodiscard]] static auto CameraPressed(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        static auto CameraPressed(winrt::event_token const& token);
        static auto CameraReleased(winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        using CameraReleased_revoker = impl::factory_event_revoker<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2, &impl::abi_t<winrt::Windows::Phone::UI::Input::IHardwareButtonsStatics2>::remove_CameraReleased>;
        [[nodiscard]] static auto CameraReleased(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Phone::UI::Input::CameraEventArgs> const& handler);
        static auto CameraReleased(winrt::event_token const& token);
    };
}
#endif
