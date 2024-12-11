#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <string>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>

class Connection {
  
public:
  Connection(const std::string &serverName, int port);

  void Connection::sendRequest();
  std::string readResponse ();

  ~Connection();

private:
  SSL_CTX *ctx;
  SSL *ssl;
  int sockfd;
  struct hostent *host;
  struct sockaddr_in serverAddr;
};


#endif // CONNECTION_H
