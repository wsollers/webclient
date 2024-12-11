#ifndef HTTP_H
#define HTTP_H

#include <string>
#include <vector>

#include "include/HttpVerbs.h"

namespace http {

struct HttpVersion {
  static const char *HTTP_1_0;
  static const char *HTTP_1_1;
};

struct HttpHeader {
  static const char *CONTENT_TYPE;
  static const char *CONTENT_LENGTH;
  static const char *CONNECTION;
  static const char *HOST;
  static const char *USER_AGENT;
  static const char *ACCEPT;
  static const char *ACCEPT_ENCODING;
  static const char *ACCEPT_LANGUAGE;
  static const char *COOKIE;
  static const char *SET_COOKIE;
};

struct HttpRequest {
  std::string verb;
  std::string url;
  std::string version;
  std::string headers;
  std::string body;

  std::vector<std::string> headers_list;
};


} // namespace http

#endif // HTTP_H
