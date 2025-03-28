#ifndef MQTT_SOCKET_H
#define MQTT_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // close(), read(), write(), etc.
#include <arpa/inet.h>      // inet_ntoa(), htons(), etc.
#include <sys/socket.h>     // socket(), bind(), listen(), accept()
#include <pthread.h>        // pthread_create(), pthread_t, etc.

#define PORT 2000
#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048


// Inicia el servidor socket que acepta múltiples clientes
int create_socket_server(void);

#endif

