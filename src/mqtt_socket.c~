#include "mqtt_socket.h"

void *handle_client(void *client_socket_ptr) {
    int client_sock = *(int *)client_socket_ptr;
    free(client_socket_ptr);

    char client_message[2000];
    char server_message[2000];
    memset(client_message, 0, sizeof(client_message));
    memset(server_message, 0, sizeof(server_message));

    if (recv(client_sock, client_message, sizeof(client_message), 0) < 0) {
        printf("No se pudo recibir mensaje del cliente\n");
        close(client_sock);
        return NULL;
    }

    printf("Mensaje del cliente: %s\n", client_message);

    strcpy(server_message, "Este es el mensaje del servidor.");
    if (send(client_sock, server_message, strlen(server_message), 0) < 0) {
        printf("No se pudo enviar mensaje\n");
    }

    shutdown(client_sock, SHUT_RDWR);
    close(client_sock);
    printf("Conexión con cliente cerrada\n");
    return NULL;
}

int create_socket_server() {
    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        printf("Error al crear el socket\n");
        return -1;
    }
    printf("Socket creado correctamente\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int opt = 1;
    setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("No se pudo enlazar al puerto\n");
        close(socket_desc);
        return -1;
    }
    printf("Bind completado\n");

    if (listen(socket_desc, MAX_CLIENTS) < 0) {
        printf("Error al escuchar\n");
        close(socket_desc);
        return -1;
    }
    printf("Esperando conexiones en el puerto %d...\n", PORT);

    while (1) {
        client_size = sizeof(client_addr);
        int *client_sock = malloc(sizeof(int));
        *client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);

        if (*client_sock < 0) {
            printf("Error al aceptar conexión\n");
            free(client_sock);
            continue;
        }

        printf("Cliente conectado desde %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, client_sock) != 0) {
            printf("Error al crear hilo para cliente\n");
            close(*client_sock);
            free(client_sock);
        } else {
            pthread_detach(tid);
        }
    }

    close(socket_desc);
    return 0;
}

