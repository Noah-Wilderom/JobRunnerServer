#include "./Headers/ServerHeader.h"

using json = nlohmann::json;
namespace RunnerServer {

    void Http::init(json& config)
    {
        this->apiKey = Http::initializeApiKey(config["api"]["key"]);

        std::string url = config["api"]["url"];

        this->heartBeatApiUrl = url + "/heartbeat?key=" + this->apiKey;
        this->jobsApiUrl = "http://127.0.0.1:8000/api/jobs?key=" + this->apiKey;

        this->sendHeartbeat();
    }

    std::string Http::initializeApiKey(std::string value)
    {
        std::cout << "\033[0;32mApiKey has been set\033[0m" << std::endl;

        return value;
    }

    bool Http::sendHeartbeat()
    {
        cpr::Response r = cpr::Get(cpr::Url{this->heartBeatApiUrl});

        if(r.status_code != 200)
        {
            if(r.status_code == 0) {
                std::cout << "API url is invalid: " << this->heartBeatApiUrl << std::endl;
                exit(1);
            } else if(r.status_code == 403) std::cout << "API Auth denied." << std::endl;

            std::cout << "API heartbeat response status code " << r.status_code << std::endl;
            return false;
        }

        json text = json::parse(r.text);

        if(!text["status"])
        {
            std::cout << "Api Unavailable" << std::endl;
        }

        return text["status"];
    }

    json Http::getJobs()
    {
        cpr::Response r = cpr::Get(cpr::Url{this->jobsApiUrl});
        std::cout << "Getting jobs..." << std::endl;

        if(r.status_code != 200)
        {
            if(r.status_code == 0) {
                std::cout << "API url is invalid: " << this->heartBeatApiUrl << std::endl;
                exit(1);
            } else if(r.status_code == 403) std::cout << "API Auth denied." << std::endl;

            std::cout << "API heartbeat response status code " << r.status_code << std::endl;
            return false;
        }

        json text = json::parse(r.text);
        std::cout << "Fetched " << std::end(text["jobs"]) - std::begin(text["jobs"]) << " jobs..." << std::endl;
        return text["jobs"];
    }

}