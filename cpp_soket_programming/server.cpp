#include <iostream>
#include <cstdio>
#include <thread>
#include <chrono>
#include <string>
#include <winsock2.h>
#include <vector>

using namespace std;

#define SERVER_PORT 11235  // server port number
#define BUF_SIZE 1024
#define IPAddress "127.0.0.1" // server IP address

void send_msg(SOCKET sock) {
    while(1) {
        char msg[BUF_SIZE] = {0};
        fflush(stdin);
        fgets(msg, BUF_SIZE, stdin);
        if(strcmp(msg, "exit\n") == 0) {
            shutdown(sock, SD_BOTH);
            break;
        }
        int n = send(sock, msg, BUF_SIZE, 0);
    }
}
 
void recv_msg(SOCKET sock) {
    while(1) {
        char buf[BUF_SIZE] = {0};
        int n = recv(sock, buf, BUF_SIZE, 0);
        if (n <= 0) {
            shutdown(sock, SD_BOTH);
            printf("Got nothing\n");
            break; 
        }
        buf[n] = 0; // make a string
        cout << "Received: " << buf;
    }
}

int main(void) {
    WSADATA wsaData;
    SOCKADDR_IN servAddr, cliAddr; //Socket address information
    int bytesSent;
    char buf[BUF_SIZE];
 
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup error " << WSAGetLastError() << endl;
        WSACleanup();
        return false;
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET; // address family Internet
    servAddr.sin_port = htons(SERVER_PORT); //Port to connect on
    //servAddr.sin_addr.s_addr = inet_addr(IPAddress); //Target IP
 
 
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
    if (s == INVALID_SOCKET) {
        cout << "Socket error " << WSAGetLastError() << endl;
        WSACleanup();
        return false; //Couldn't create the socket
    }
 
    if (bind(s, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        cout << "Binding failed. Error code: " << WSAGetLastError() << endl;
        WSACleanup();
        return false; //Couldn't connect
    }
 
    cout << "Waiting for client..." << endl;
 
    if(listen(s, 5) != 0) {
        cout << "listen() error : " << WSAGetLastError() << endl;
        WSACleanup();
        return 0; //Couldn't create the socket
    }

    int xx = sizeof(cliAddr);
    SOCKET s2 = accept(s, (SOCKADDR*)&cliAddr, &xx);
    if (s2 == INVALID_SOCKET) {
        cout << "socket() error : "<< WSAGetLastError() << endl;
        WSACleanup();
        return 0; //Couldn't create the socket
    }
    cout << "Connection established. New socket num is " << s2 << endl;

    thread t1(send_msg, s2);
    thread t2(recv_msg, s2);

    t1.join();
    t2.join();
 
    closesocket(s);
    WSACleanup();
 
    return 0;
 
}