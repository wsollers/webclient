
  // Creat#include <string>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>

#include "include/Connection.h"
#include <iostream>

Connection::Connection (const std::string &serverName, int port) {
  // Initialize OpenSSL
  SSL_library_init();
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();

  const SSL_METHOD *method = TLS_client_method();
  if (!method) {
    std::cerr << "Unable to get SSL method\n";
    return;
  }

  ctx = SSL_CTX_new(method);
  if (!ctx) {
    std::cerr << "Unable to create SSL context\n";
    ERR_print_errors_fp(stderr);
    return;
  }

  // Resolve the server address
  host = gethostbyname(serverName.c_str());
  if (!host) {
    std::cerr << "Error resolving hostname\n";
    SSL_CTX_free(ctx);
    return;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    std::cerr << "Error creating socket\n";
    SSL_CTX_free(ctx);
    return;
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr = *((struct in_addr *)host->h_addr);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    std::cerr << "Error connecting to server\n";
    close(sockfd);
    SSL_CTX_free(ctx);
    return;
  }

  // Create SSL object
  SSL *ssl = SSL_new(ctx);
  if (!ssl) {
    std::cerr << "Error creating SSL object\n";
    ERR_print_errors_fp(stderr);
  }
}

Connection::~Connection() {
  // Clean up
  SSL_CTX_free(ctx);
  SSL_free(ssl);
  close(sockfd);
}
