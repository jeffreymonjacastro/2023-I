#include "curl/curl.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    CURL *curl;
    CURLcode res;
    std::string url = "https://example.com/example.txt";
    std::ofstream outfile("/home/user/Downloads/example.txt", std::ofstream::binary);
    if (outfile.fail()) {
        std::cout << "Error: could not create file" << std::endl;
        return 1;
    }
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outfile);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cout << "Error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    outfile.close();
    return 0;
}
