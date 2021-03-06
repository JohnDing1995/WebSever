//
// Created by Ding Ruiyang on 2018/3/16.
//

#include <IO/IoReader.h>
#include "HeaderParser.h"


void HeaderParser::parseRequestHeader(int fd)
{
    auto reader =  IoReader(fd);
    std::vector<std::string> header;
    reader.getLineSplitedByBlank(header);
    method = header[0];
    uri = header[1];
    version = header[2];
}

std::string HeaderParser::gerVersion() {
    return this->version;
}

std::string HeaderParser::getUri() {
    return this->uri;
}

std::string HeaderParser::getMethod() {
    return this->method;
}
