#ifndef CPP_WEBSOCKET_SERVER_SERVERHEADER_H
#define CPP_WEBSOCKET_SERVER_SERVERHEADER_H
#include "../../Helpers/Headers/HelperHeader.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <array>
#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

namespace RunnerServer
{
    class Http
    {
    public:
        static std::string testApiUrl;

        std::string heartBeatApiUrl;
        std::string jobsApiUrl;

        std::string apiKey;
        static std::string initializeApiKey(std::string path);

        bool sendHeartbeat();

        nlohmann::json getJobs();

        void init(nlohmann::json& config);
    };

    class Server
    {
    public:
        bool started;
        nlohmann::json config;

        Server();
        void Run();

        Http http;
    };


}
#endif //CPP_WEBSOCKET_SERVER_SERVERHEADER_H
