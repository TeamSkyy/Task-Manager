// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#ifndef WINRT_Windows_Storage_Provider_2_H
#define WINRT_Windows_Storage_Provider_2_H
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Storage.1.h"
#include "winrt/impl/Windows.Storage.Provider.1.h"
WINRT_EXPORT namespace winrt::Windows::Storage::Provider
{
    struct StorageProviderKnownFolderSyncRequestedHandler : winrt::Windows::Foundation::IUnknown
    {
        StorageProviderKnownFolderSyncRequestedHandler(std::nullptr_t = nullptr) noexcept {}
        StorageProviderKnownFolderSyncRequestedHandler(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> StorageProviderKnownFolderSyncRequestedHandler(L lambda);
        template <typename F> StorageProviderKnownFolderSyncRequestedHandler(F* function);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(O* object, M method);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::Storage::Provider::StorageProviderKnownFolderSyncRequestArgs const& args) const;
    };
    struct CachedFileUpdater
    {
        CachedFileUpdater() = delete;
        static auto SetUpdateInformation(winrt::Windows::Storage::IStorageFile const& file, param::hstring const& contentId, winrt::Windows::Storage::Provider::ReadActivationMode const& readMode, winrt::Windows::Storage::Provider::WriteActivationMode const& writeMode, winrt::Windows::Storage::Provider::CachedFileOptions const& options);
    };
    struct __declspec(empty_bases) CachedFileUpdaterUI : winrt::Windows::Storage::Provider::ICachedFileUpdaterUI,
        impl::require<CachedFileUpdaterUI, winrt::Windows::Storage::Provider::ICachedFileUpdaterUI2>
    {
        CachedFileUpdaterUI(std::nullptr_t) noexcept {}
        CachedFileUpdaterUI(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::ICachedFileUpdaterUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequest : winrt::Windows::Storage::Provider::IFileUpdateRequest,
        impl::require<FileUpdateRequest, winrt::Windows::Storage::Provider::IFileUpdateRequest2>
    {
        FileUpdateRequest(std::nullptr_t) noexcept {}
        FileUpdateRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IFileUpdateRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequestDeferral : winrt::Windows::Storage::Provider::IFileUpdateRequestDeferral
    {
        FileUpdateRequestDeferral(std::nullptr_t) noexcept {}
        FileUpdateRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IFileUpdateRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequestedEventArgs : winrt::Windows::Storage::Provider::IFileUpdateRequestedEventArgs
    {
        FileUpdateRequestedEventArgs(std::nullptr_t) noexcept {}
        FileUpdateRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IFileUpdateRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageProviderFileTypeInfo : winrt::Windows::Storage::Provider::IStorageProviderFileTypeInfo
    {
        StorageProviderFileTypeInfo(std::nullptr_t) noexcept {}
        StorageProviderFileTypeInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderFileTypeInfo(ptr, take_ownership_from_abi) {}
        StorageProviderFileTypeInfo(param::hstring const& fileExtension, param::hstring const& iconResource);
    };
    struct __declspec(empty_bases) StorageProviderGetContentInfoForPathResult : winrt::Windows::Storage::Provider::IStorageProviderGetContentInfoForPathResult
    {
        StorageProviderGetContentInfoForPathResult(std::nullptr_t) noexcept {}
        StorageProviderGetContentInfoForPathResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderGetContentInfoForPathResult(ptr, take_ownership_from_abi) {}
        StorageProviderGetContentInfoForPathResult();
    };
    struct __declspec(empty_bases) StorageProviderGetPathForContentUriResult : winrt::Windows::Storage::Provider::IStorageProviderGetPathForContentUriResult
    {
        StorageProviderGetPathForContentUriResult(std::nullptr_t) noexcept {}
        StorageProviderGetPathForContentUriResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderGetPathForContentUriResult(ptr, take_ownership_from_abi) {}
        StorageProviderGetPathForContentUriResult();
    };
    struct StorageProviderItemProperties
    {
        StorageProviderItemProperties() = delete;
        static auto SetAsync(winrt::Windows::Storage::IStorageItem const& item, param::async_iterable<winrt::Windows::Storage::Provider::StorageProviderItemProperty> const& itemProperties);
    };
    struct __declspec(empty_bases) StorageProviderItemProperty : winrt::Windows::Storage::Provider::IStorageProviderItemProperty
    {
        StorageProviderItemProperty(std::nullptr_t) noexcept {}
        StorageProviderItemProperty(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderItemProperty(ptr, take_ownership_from_abi) {}
        StorageProviderItemProperty();
    };
    struct __declspec(empty_bases) StorageProviderItemPropertyDefinition : winrt::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition
    {
        StorageProviderItemPropertyDefinition(std::nullptr_t) noexcept {}
        StorageProviderItemPropertyDefinition(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition(ptr, take_ownership_from_abi) {}
        StorageProviderItemPropertyDefinition();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderEntry : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderEntry
    {
        StorageProviderKnownFolderEntry(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderEntry(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderEntry(ptr, take_ownership_from_abi) {}
        StorageProviderKnownFolderEntry();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderSyncInfo : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderSyncInfo
    {
        StorageProviderKnownFolderSyncInfo(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderSyncInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderSyncInfo(ptr, take_ownership_from_abi) {}
        StorageProviderKnownFolderSyncInfo();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderSyncRequestArgs : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderSyncRequestArgs
    {
        StorageProviderKnownFolderSyncRequestArgs(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderSyncRequestArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderKnownFolderSyncRequestArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageProviderMoreInfoUI : winrt::Windows::Storage::Provider::IStorageProviderMoreInfoUI
    {
        StorageProviderMoreInfoUI(std::nullptr_t) noexcept {}
        StorageProviderMoreInfoUI(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderMoreInfoUI(ptr, take_ownership_from_abi) {}
        StorageProviderMoreInfoUI();
    };
    struct __declspec(empty_bases) StorageProviderQuotaUI : winrt::Windows::Storage::Provider::IStorageProviderQuotaUI
    {
        StorageProviderQuotaUI(std::nullptr_t) noexcept {}
        StorageProviderQuotaUI(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderQuotaUI(ptr, take_ownership_from_abi) {}
        StorageProviderQuotaUI();
    };
    struct __declspec(empty_bases) StorageProviderStatusUI : winrt::Windows::Storage::Provider::IStorageProviderStatusUI
    {
        StorageProviderStatusUI(std::nullptr_t) noexcept {}
        StorageProviderStatusUI(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderStatusUI(ptr, take_ownership_from_abi) {}
        StorageProviderStatusUI();
    };
    struct __declspec(empty_bases) StorageProviderSyncRootInfo : winrt::Windows::Storage::Provider::IStorageProviderSyncRootInfo,
        impl::require<StorageProviderSyncRootInfo, winrt::Windows::Storage::Provider::IStorageProviderSyncRootInfo2, winrt::Windows::Storage::Provider::IStorageProviderSyncRootInfo3>
    {
        StorageProviderSyncRootInfo(std::nullptr_t) noexcept {}
        StorageProviderSyncRootInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Storage::Provider::IStorageProviderSyncRootInfo(ptr, take_ownership_from_abi) {}
        StorageProviderSyncRootInfo();
    };
    struct StorageProviderSyncRootManager
    {
        StorageProviderSyncRootManager() = delete;
        static auto Register(winrt::Windows::Storage::Provider::StorageProviderSyncRootInfo const& syncRootInformation);
        static auto Unregister(param::hstring const& id);
        static auto GetSyncRootInformationForFolder(winrt::Windows::Storage::IStorageFolder const& folder);
        static auto GetSyncRootInformationForId(param::hstring const& id);
        static auto GetCurrentSyncRoots();
        static auto IsSupported();
    };
}
#endif
