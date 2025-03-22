#include <stdio.h>
#include "mqtt_socket.h"

int main() {
    printf("Iniciando servidor MQTT...\n");

    if (create_socket_server() != 0) {
        printf("Error al iniciar el servidor.\n");
        return 1;
    }

    return 0;
}

