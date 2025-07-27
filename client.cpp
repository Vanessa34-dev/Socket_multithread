#include<iostream>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
    //create a socket
    int client_socket= socket(AF_INET,SOCK_STREAM,0);
    if(client_socket==-1)
    {
        std::cerr<< "Socket error";
        return 1;
    }else
    {
        std::cout<< "Socket is ok\n";
    }

    const int PORT=2025;
    const char* SERVER_IP="127.0.0.1"; // define server IP Address

    // declaration of address struture
    struct sockaddr_in server_address;

    // initialize all field to 0 for this address
    std::memset(&server_address,0,sizeof(server_address));

    // set the address family to IPv4
    server_address.sin_family=AF_INET;

    server_address.sin_port=htons(PORT);
    
    //convert string IP to binary format
    if(inet_pton(AF_INET,SERVER_IP,&server_address.sin_addr)<=0){
        std::cerr << "invalide IP address\n";
        close(client_socket);
        return 1;
    }

    //connexion to a server
    if(connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0)
    {
        perror("connect");
        std::cerr<<"failed to connect";
        close(client_socket);
        return 1;
    }

    std::cout<< "connected to a server";
    close(client_socket);
}