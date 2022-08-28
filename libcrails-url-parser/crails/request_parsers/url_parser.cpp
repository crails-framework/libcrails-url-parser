#include "url_parser.hpp"
#include <crails/context.hpp>
#include <crails/url.hpp>

using namespace std;
using namespace Crails;

void RequestUrlParser::operator()(Context& context, function<void(RequestParser::Status)> callback) const
{
  {
    const auto&  request    = context.connection->get_request();
    const string destination(request.target());
    const char*  get_params = strrchr(destination.c_str(), '?');
    string       uri = destination;

    // Setting Headers parameters
    {
      for (const auto& header : request.base())
        context.params["headers"][std::string(header.name_string())] = std::string(header.value());
    }

    // Getting get parameters
    if (get_params != 0)
    {
      std::string str_params(get_params);

      uri.erase(uri.size() - str_params.size());
      str_params.erase(0, 1);
      cgi2params(context.params.as_data(), str_params);
    }
  
    context.params["uri"]    = uri;
    context.params["method"] = boost::beast::http::to_string(request.method());
  }
  callback(RequestParser::Continue);
}
