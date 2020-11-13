#ifndef PARSER_H
#define PARSER_H

#include <math.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct City {
    int id;
    string name;
    double latitude;
    double longitude;
};

struct Airport {
    int id;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
};

class JsonParser {
   protected:
    string jsonPath;
    json data;
    virtual void insertV() = 0;
    virtual void insertE() = 0;

   public:
    JsonParser(string jsonPath) {
        ifstream file(jsonPath);
        data = json::parse(file);
    }
};

class AirportParser : JsonParser {
   public:
    AirportParser(string jsonPath) : JsonParser(jsonPath){};
};

class CityParser : JsonParser {
   public:
    CityParser(string jsonPath) : JsonParser(jsonPath){};
};

#endif  // PARSER_H