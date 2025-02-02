#ifndef JSON_PARSE_HPP
#define JSON_PARSE_HPP

#include <boost/json.hpp>

boost::json::value parseJson(const std::string &file);

#endif