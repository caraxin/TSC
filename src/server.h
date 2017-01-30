#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include "connection.h"
#include "config_opts.h"

namespace http {
namespace server {

class server 
{
public:
  server(const server&) = delete;
  server& operator=(const server&) = delete;

  explicit server(const config_opts& server_config);

  void run();

private:

  void do_accept();

  boost::asio::io_service io_service_;

  boost::asio::ip::tcp::acceptor acceptor_;

  boost::asio::ip::tcp::socket socket_;
};


} // namespace server
} // namespace server

#endif // HTTP_SERVER_HPP
