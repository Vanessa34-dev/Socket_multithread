#include<iostream>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
    const int PORT=2025;

    // declaration of address struture
    struct sockaddr_in server_address;

    // initialize all field to 0 for this address
    std::memset(&server_address,0,sizeof(server_address));

    // set the address family to IPv4
    server_address.sin_family=AF_INET;

    server_address.sin_port=htons(PORT);

    //set an IP address to an available network interface
    server_address.sin_addr.s_addr= INADDR_ANY;
  
    //creation of TCP socket
    int server_socket= socket(AF_INET,SOCK_STREAM,0);
    if(server_socket==-1)
    {
        std::cerr<< "Socket error";
        return 1;
    }else
    {
        std::cout<< "Socket is ok\n";
    }

    if(bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0)
    {
        std::cout<<"error bind\n";
        close(server_socket);
        return 1;
    }else{
        std::cout<< "Bind() is ok\n";
    }
    if(listen(server_socket,1)<0){
        std::cout<<"error listening on socket";
    }else{
        std::cout<<"listen() is OK, I'm wating for a connection"<<std::endl;
    }
   
}