#include <cstdlib>
#include <iostream>

#include "http/http.h"
#include "http/include/Connection.h"

std::string get_url(char **argv) {
  if (argv[1] == nullptr) {
    std::cerr << "Usage: " << argv[0] << " <url>" << std::endl;
    exit(EXIT_FAILURE);
  }
  return argv[1];
}

int main(int argc, char **argv) {
  std::cout << "[webclient] initializing..." << std::endl;
  std::string url = get_url(argv);
  std::cout << "[webclient] url: " << url << std::endl;

  Connection conn(url, 443);

  http::HttpRequest httpRequest;
  httpRequest.verb = http::HttpVerbs::GET;

  std::string path = "/";
  httpRequest.url = path;
  httpRequest.version = http::HttpVersion::HTTP_1_1;
  std::stringstream ss;
  ss << http::HttpHeader::CONNECTION << ": close"; 
  httpRequest.headers.push_back(ss.str());
  
  conn.send(httpRequest);

  exit(EXIT_SUCCESS);
}
