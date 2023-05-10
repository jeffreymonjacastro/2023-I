#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

using namespace std;

int main() {
    // URL a leer
    string url = "https://norvig.com/y10k.html";

    // Extraemos el hostname y el path de la URL
    string hostname = url.substr(url.find("://") + 3);
    string path = hostname.substr(hostname.find("/"));
    hostname = hostname.substr(0, hostname.find("/"));

    // Resolvemos el hostname a una dirección IP
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(hostname.c_str(), "80", &hints, &res);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ip, INET_ADDRSTRLEN);

    // Abrimos una conexión TCP al servidor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Enviamos la solicitud HTTP GET al servidor
    stringstream ss;
    ss << "GET " << path << " HTTP/1.1\r\n";
    ss << "Host: " << hostname << "\r\n";
    ss << "Connection: close\r\n";
    ss << "\r\n";
    string request = ss.str();
    write(sockfd, request.c_str(), request.length());

    // Leemos la respuesta del servidor
    stringstream response;
    char buffer[1024];
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        response.write(buffer, n);
    }

    // Cerramos la conexión TCP
    close(sockfd);

    // Extraemos el cuerpo del mensaje HTTP
    string html = response.str();
    html = html.substr(html.find("\r\n\r\n") + 4);

    // Guardamos el HTML en un archivo
    ofstream file("output.html");
    file << html;
    file.close();

    return 0;
}
