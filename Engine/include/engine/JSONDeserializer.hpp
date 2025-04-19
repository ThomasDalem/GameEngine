#ifndef JSON_DESERIALIZER_HPP
#define JSON_DESERIALIZER_HPP

#include <boost/json.hpp>
#include <iostream>
#include "components/Position.hpp"
#include "components/Circle.hpp"

Engine::Position deserializePosition(const boost::json::object &obj);
Engine::Circle deserializeCircle(const boost::json::object &obj);

#endif