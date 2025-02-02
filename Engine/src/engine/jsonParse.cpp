#include "engine/jsonParse.hpp"
#include <fstream>
#include <iostream>

boost::json::value parseJson(const std::string &file)
{
    std::ifstream stream{file, std::ios::binary};

    if (!stream.is_open())
    {
        std::cerr << "Could not open " << file << "\n";
        throw "FileOpenError";
    }

    boost::json::stream_parser parser;
    boost::system::error_code ec;

    do
    {
        char buffer[4096];
        stream.read(buffer, sizeof(buffer));
        parser.write(buffer, stream.gcount(), ec);

    } while (!stream.eof());

    if (ec)
    {
        std::cerr << ec.what() << "\n";
        throw "FileReadError";
    }
    parser.finish(ec);
    if (ec)
    {
        std::cerr << ec.what() << "\n";
        throw "ParseError";
    }
    return parser.release();
}
