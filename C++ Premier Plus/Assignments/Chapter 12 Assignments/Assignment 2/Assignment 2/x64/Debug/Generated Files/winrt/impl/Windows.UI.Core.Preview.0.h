// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#ifndef WINRT_Windows_UI_Core_Preview_0_H
#define WINRT_Windows_UI_Core_Preview_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct Deferral;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
WINRT_EXPORT namespace winrt::Windows::UI::WindowManagement
{
    struct AppWindow;
}
WINRT_EXPORT namespace winrt::Windows::UI::Core::Preview
{
    struct ICoreAppWindowPreview;
    struct ICoreAppWindowPreviewStatics;
    struct ISystemNavigationCloseRequestedPreviewEventArgs;
    struct ISystemNavigationManagerPreview;
    struct ISystemNavigationManagerPreviewStatics;
    struct CoreAppWindowPreview;
    struct SystemNavigationCloseRequestedPreviewEventArgs;
    struct SystemNavigationManagerPreview;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreviewStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::CoreAppWindowPreview>{ using type = class_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<winrt::Windows::UI::Core::Preview::SystemNavigationManagerPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::CoreAppWindowPreview> = L"Windows.UI.Core.Preview.CoreAppWindowPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> = L"Windows.UI.Core.Preview.SystemNavigationCloseRequestedPreviewEventArgs";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::SystemNavigationManagerPreview> = L"Windows.UI.Core.Preview.SystemNavigationManagerPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview> = L"Windows.UI.Core.Preview.ICoreAppWindowPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreviewStatics> = L"Windows.UI.Core.Preview.ICoreAppWindowPreviewStatics";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs> = L"Windows.UI.Core.Preview.ISystemNavigationCloseRequestedPreviewEventArgs";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview> = L"Windows.UI.Core.Preview.ISystemNavigationManagerPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreviewStatics> = L"Windows.UI.Core.Preview.ISystemNavigationManagerPreviewStatics";
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview>{ 0xA4F6E665,0x365E,0x5FDE,{ 0x87,0xA5,0x95,0x43,0xC3,0xA1,0x5A,0xA8 } }; // A4F6E665-365E-5FDE-87A5-9543C3A15AA8
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreviewStatics>{ 0x33AC21BE,0x423B,0x5DB6,{ 0x8A,0x8E,0x4D,0xC8,0x73,0x53,0xB7,0x5B } }; // 33AC21BE-423B-5DB6-8A8E-4DC87353B75B
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>{ 0x83D00DE1,0xCBE5,0x4F31,{ 0x84,0x14,0x36,0x1D,0xA0,0x46,0x51,0x8F } }; // 83D00DE1-CBE5-4F31-8414-361DA046518F
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview>{ 0xEC5F0488,0x6425,0x4777,{ 0xA5,0x36,0xCB,0x56,0x34,0x42,0x7F,0x0D } }; // EC5F0488-6425-4777-A536-CB5634427F0D
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>{ 0x0E971360,0xDF74,0x4BCE,{ 0x84,0xCB,0xBD,0x11,0x81,0xAC,0x0A,0x71 } }; // 0E971360-DF74-4BCE-84CB-BD1181AC0A71
    template <> struct default_interface<winrt::Windows::UI::Core::Preview::CoreAppWindowPreview>{ using type = winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview; };
    template <> struct default_interface<winrt::Windows::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs>{ using type = winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs; };
    template <> struct default_interface<winrt::Windows::UI::Core::Preview::SystemNavigationManagerPreview>{ using type = winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview; };
    template <> struct abi<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetIdFromWindow(void*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_CloseRequested(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CloseRequested(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ICoreAppWindowPreview
    {
    };
    template <> struct consume<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreview>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ICoreAppWindowPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ICoreAppWindowPreviewStatics
    {
        auto GetIdFromWindow(winrt::Windows::UI::WindowManagement::AppWindow const& window) const;
    };
    template <> struct consume<winrt::Windows::UI::Core::Preview::ICoreAppWindowPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ICoreAppWindowPreviewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs
    {
        [[nodiscard]] auto Handled() const;
        auto Handled(bool value) const;
        auto GetDeferral() const;
    };
    template <> struct consume<winrt::Windows::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview
    {
        auto CloseRequested(winrt::Windows::Foundation::EventHandler<winrt::Windows::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const;
        using CloseRequested_revoker = impl::event_revoker<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview, &impl::abi_t<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview>::remove_CloseRequested>;
        [[nodiscard]] auto CloseRequested(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const;
        auto CloseRequested(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreview>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreviewStatics
    {
        auto GetForCurrentView() const;
    };
    template <> struct consume<winrt::Windows::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreviewStatics<D>;
    };
}
#endif
