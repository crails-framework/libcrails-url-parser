#ifndef  CRAILS_DATA_PARSER_HPP
# define CRAILS_DATA_PARSER_HPP

# include <crails/request_parser.hpp>

namespace Crails
{
  class RequestUrlParser : public RequestParser
  {
  public:
    void operator()(Connection&, BuildingResponse&, Params&, std::function<void(RequestParser::Status)>) const override;
  };
}

#endif
