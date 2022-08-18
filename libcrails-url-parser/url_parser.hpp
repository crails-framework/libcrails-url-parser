#ifndef  CRAILS_DATA_PARSER_HPP
# define CRAILS_DATA_PARSER_HPP

# include <crails/request_parser.hpp>

namespace Crails
{
  class RequestUrlParser : public RequestParser
  {
  public:
    void operator()(Context&, std::function<void(RequestParser::Status)>) const override;
  };
}

#endif
