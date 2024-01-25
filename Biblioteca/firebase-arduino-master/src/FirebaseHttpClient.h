#ifndef FIREBASE_HTTP_CLIENT_H
#define FIREBASE_HTTP_CLIENT_H

#include <string>

#include "Arduino.h"
#include "Stream.h"

struct HttpStatus
{
  static const int TEMPORARY_REDIRECT = 307;
};

class FirebaseHttpClient
{
public:
  static FirebaseHttpClient *create();

  virtual void setReuseConnection(bool reuse) = 0;
  virtual void begin(const std::string &url) = 0;
  virtual void begin(const std::string &host, const std::string &path) = 0;

  virtual void end() = 0;

  virtual void addHeader(const std::string &name, const std::string &value) = 0;
  virtual void collectHeaders(const char *header_keys[],
                              const int header_key_count) = 0;
  virtual std::string header(const std::string &name) = 0;

  virtual int sendRequest(const std::string &method, const std::string &data) = 0;

  virtual std::string getString() = 0;

  virtual Stream *getStreamPtr() = 0;

  virtual std::string errorToString(int error_code) = 0;

  bool isStreaming() const
  {
    return _streaming != "";
  }
  std::string getStreamingPath() const
  {
    return _streaming;
  }
  void setStreaming(const std::string &path)
  {
    _streaming = path;
  }

protected:
  std::string _streaming = "";

  static const uint16_t kFirebasePort = 443;
};

static const char kFirebaseFingerprint[] =
    "F3 D2 7D C8 CD 6B D0 4D AD D5 DB 2B D2 5C 6C B8 0A 8A 67 EC";

#endif // FIREBASE_HTTP_CLIENT_H
