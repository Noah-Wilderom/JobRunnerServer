#include "./Headers/ServerHeader.h"

using json = nlohmann::json;
namespace RunnerServer
{
    Server::Server() {
        std::ifstream file;
        file.open("./../config.json");

        if(file) {
            this->config = json::parse(file);
        } else {
            std::cout << "Config file could not be found!" << std::endl;
            exit(1);
        }

        this->started = false;

        Http httpObject;
        this->http = httpObject;
        this->http.init(this->config);
    }

    void Server::Run() {
        this->started = true;

        while(this->started)
        {
            if(!this->http.sendHeartbeat()) this->started = false;

            json jobList = this->http.getJobs();
            if((std::end(jobList) - std::begin(jobList)) > 1)
            {
                for(auto job: jobList)
                {
                    std::cout << job["uuid"] << std::endl;
                }
            }

            sleep(10);
        }
    }
}

