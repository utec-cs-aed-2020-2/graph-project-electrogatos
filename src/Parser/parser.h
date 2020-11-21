#ifndef PARSER_H
#define PARSER_H

#include <math.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
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

        // For Test
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
    unordered_map<int, Airport> airports;

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph){
        // Create Vertexes 
        for (auto& element : data) {
            Airport a;
            a.id = element["Airport ID"]; int id_int = stoi(a.id);
            a.name = element["Name"];
            a.city = element["City"];
            a.country = element["Country"];
            string la = element["Latitude"]; a.latitude = stod(la);
            string lo = element["Longitude"]; a.longitude = stod(lo);            

            // tempGraph.insertVertex(id_int, a.name);
            tempGraph.insertVertex(id_int, a.id); // For simplicity
            this->airports[id_int] = a;
        }
        // Create Edges 
        for (auto& element : data) { 
            string id_origen = element["Airport ID"];
            Airport origen = this->airports.at(stoi(id_origen));
            cout << "Origen: " << id_origen << " " << origen.name << " " << origen.latitude << " " << origen.longitude << endl;

            for (auto dest : element["destinations"]) {
                string id_dest = dest;
                double de;
                try {
                    Airport destination = this->airports.at(stoi(id_dest));
                    cout << "  Dest: " << id_dest << " " << destination.name << " " << destination.latitude << " " << destination.longitude << "  ";
                    de = sqrt( pow( ( destination.latitude - origen.latitude ) , 2.0) + pow( ( destination.longitude - origen.longitude ) , 2.0) );
                    cout << "Deuclidiana: " << de << endl;
                    tempGraph.createEdge(stoi(id_origen), stoi(id_dest), de);
                } catch(const out_of_range &e) {
                    // cerr << "Exception at " << e.what() << endl;
                    cout << "  Destination not found!!!" << endl;
                }
            }
        }
        // For test
        // for (auto ar : this->airports) {
        //     cout << ar.first << " " << ar.second.name << " " << ar.second.latitude << " " << ar.second.longitude << endl;
        // }
    };
};

class CityParser : JsonParser {
   public:
    CityParser(string jsonPath) : JsonParser(jsonPath){};
};

#endif  // PARSER_H