#ifndef PARSER_H
#define PARSER_H

#include <math.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <nlohmann/json.hpp>
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
    string id;
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
    // virtual void insertV() = 0;
    // virtual void insertE() = 0;

   public:
    JsonParser(string jsonPath) { // readJSON()
        ifstream file(jsonPath);
        data = json::parse(file);

        // Test
        // for (int i = 0; i < 3; i++) {
        //     Airport a1;
        //     a1.id = data[i]["Airport ID"];
        //     cout << a1.id << endl;
        // }
    }
};

class AirportParser : JsonParser {
   public:
    AirportParser(string jsonPath) : JsonParser(jsonPath){};

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph){
        // Create Vertexes 
        for (auto& element : data) {
            Airport a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            a.name = element["Name"];
            // a.city = element["City"];
            // a.country = element["Country"];
            // // a.latitude = element["Latitude"];
            // // a.longitude = element["Longitude"];
            // cout << id_int << " " << a.name << endl;
            tempGraph.insertVertex(id_int, a.name);
        }
        // Create Edges 
        // Se necesita verificar en la funcion createEdge si existe el edge
        // y si existe los vertices
        // for (auto& element : data) { 
        //     // cout << element["destinations"] << endl;
        //     string idd = element["Airport ID"];
        //     for (auto dest : element["destinations"]) {
        //         string idde = dest;
        //         tempGraph.createEdge(stoi(idd), stoi(idde), 20);
        //     }
        // }
    };
};

class CityParser : JsonParser {
   public:
    CityParser(string jsonPath) : JsonParser(jsonPath){};
};

#endif  // PARSER_H