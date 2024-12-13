// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#ifndef WINRT_Windows_Networking_BackgroundTransfer_2_H
#define WINRT_Windows_Networking_BackgroundTransfer_2_H
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Networking.BackgroundTransfer.1.h"
WINRT_EXPORT namespace winrt::Windows::Networking::BackgroundTransfer
{
    struct BackgroundDownloadProgress
    {
        uint64_t BytesReceived;
        uint64_t TotalBytesToReceive;
        winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.TotalBytesToReceive == right.TotalBytesToReceive && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundTransferFileRange
    {
        uint64_t Offset;
        uint64_t Length;
    };
    inline bool operator==(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return left.Offset == right.Offset && left.Length == right.Length;
    }
    inline bool operator!=(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundUploadProgress
    {
        uint64_t BytesReceived;
        uint64_t BytesSent;
        uint64_t TotalBytesToReceive;
        uint64_t TotalBytesToSend;
        winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.BytesSent == right.BytesSent && left.TotalBytesToReceive == right.TotalBytesToReceive && left.TotalBytesToSend == right.TotalBytesToSend && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) BackgroundDownloader : winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader,
        impl::require<BackgroundDownloader, winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2, winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>
    {
        BackgroundDownloader(std::nullptr_t) noexcept {}
        BackgroundDownloader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader(ptr, take_ownership_from_abi) {}
        BackgroundDownloader();
        explicit BackgroundDownloader(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        static auto GetCurrentDownloadsAsync();
        static auto GetCurrentDownloadsAsync(param::hstring const& group);
        static auto GetCurrentDownloadsForTransferGroupAsync(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedDownloadsAsync(param::async_iterable<winrt::Windows::Networking::BackgroundTransfer::DownloadOperation> const& operations);
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroup : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup
    {
        BackgroundTransferCompletionGroup(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroup(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup(ptr, take_ownership_from_abi) {}
        BackgroundTransferCompletionGroup();
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroupTriggerDetails : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails
    {
        BackgroundTransferCompletionGroupTriggerDetails(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroupTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundTransferContentPart : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart
    {
        BackgroundTransferContentPart(std::nullptr_t) noexcept {}
        BackgroundTransferContentPart(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart(ptr, take_ownership_from_abi) {}
        BackgroundTransferContentPart();
        explicit BackgroundTransferContentPart(param::hstring const& name);
        BackgroundTransferContentPart(param::hstring const& name, param::hstring const& fileName);
    };
    struct BackgroundTransferError
    {
        BackgroundTransferError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) BackgroundTransferGroup : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup
    {
        BackgroundTransferGroup(std::nullptr_t) noexcept {}
        BackgroundTransferGroup(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup(ptr, take_ownership_from_abi) {}
        static auto CreateGroup(param::hstring const& name);
    };
    struct __declspec(empty_bases) BackgroundTransferRangesDownloadedEventArgs : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs
    {
        BackgroundTransferRangesDownloadedEventArgs(std::nullptr_t) noexcept {}
        BackgroundTransferRangesDownloadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundUploader : winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader,
        impl::require<BackgroundUploader, winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader2, winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader3>
    {
        BackgroundUploader(std::nullptr_t) noexcept {}
        BackgroundUploader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader(ptr, take_ownership_from_abi) {}
        BackgroundUploader();
        explicit BackgroundUploader(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        static auto GetCurrentUploadsAsync();
        static auto GetCurrentUploadsAsync(param::hstring const& group);
        static auto GetCurrentUploadsForTransferGroupAsync(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedUploadsAsync(param::async_iterable<winrt::Windows::Networking::BackgroundTransfer::UploadOperation> const& operations);
    };
    struct ContentPrefetcher
    {
        ContentPrefetcher() = delete;
        [[nodiscard]] static auto ContentUris();
        static auto IndirectContentUri(winrt::Windows::Foundation::Uri const& value);
        [[nodiscard]] static auto IndirectContentUri();
        [[nodiscard]] static auto LastSuccessfulPrefetchTime();
    };
    struct __declspec(empty_bases) DownloadOperation : winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation,
        impl::require<DownloadOperation, winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation2, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation3, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation4, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation5>
    {
        DownloadOperation(std::nullptr_t) noexcept {}
        DownloadOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation(ptr, take_ownership_from_abi) {}
        using winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation::RequestedUri;
        using impl::consume_t<DownloadOperation, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation3>::RequestedUri;
    };
    struct __declspec(empty_bases) ResponseInformation : winrt::Windows::Networking::BackgroundTransfer::IResponseInformation
    {
        ResponseInformation(std::nullptr_t) noexcept {}
        ResponseInformation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IResponseInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnconstrainedTransferRequestResult : winrt::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult
    {
        UnconstrainedTransferRequestResult(std::nullptr_t) noexcept {}
        UnconstrainedTransferRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UploadOperation : winrt::Windows::Networking::BackgroundTransfer::IUploadOperation,
        impl::require<UploadOperation, winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, winrt::Windows::Networking::BackgroundTransfer::IUploadOperation2, winrt::Windows::Networking::BackgroundTransfer::IUploadOperation3, winrt::Windows::Networking::BackgroundTransfer::IUploadOperation4>
    {
        UploadOperation(std::nullptr_t) noexcept {}
        UploadOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IUploadOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
