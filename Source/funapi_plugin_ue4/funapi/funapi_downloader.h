// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

/** @file */

#ifndef SRC_FUNAPI_DOWNLOADER_H_
#define SRC_FUNAPI_DOWNLOADER_H_

namespace fun {

enum DownloadResult {
  kDownloadSuccess,
  kDownloadFailed,
};


class FunapiHttpDownloaderImpl;
class FunapiHttpDownloader {
 public:
   typedef std::function<void(const std::string&,const long,const long,const int)> OnUpdate;
   typedef std::function<void(const int)> OnFinished;

  FunapiHttpDownloader(const char *target_path,
      const OnUpdate &cb1, const OnFinished &cb2);
  ~FunapiHttpDownloader();

  bool StartDownload(const char *hostname_or_ip, uint16_t port,
      const char *list_filename, bool https = false);
  bool StartDownload(const char *url);
  void Stop();
  bool Connected() const;

 private:
   FunapiHttpDownloaderImpl *impl_;
};

}  // namespace fun

#endif  // SRC_FUNAPI_DOWNLOADER_H_