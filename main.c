#include <stdio.h>
#include <stdlib.h>

#include "cJSON.h"

int main(void){
    int i;
    cJSON *root, *streams;
    char *out;
    int num = 5;

    root = cJSON_CreateObject();
    streams = cJSON_CreateArray();
    cJSON_AddNumberToObject(root, "num", num);
    cJSON_AddItemToObject(root, "streams", streams);
    for(i = 0; i < num; i++){
        cJSON *info = cJSON_CreateObject();
        cJSON_AddStringToObject(info, "stream", "stream++");
        cJSON_AddStringToObject(info, "url", "url++");
        cJSON_AddItemToArray(streams, info);
    }

    out = cJSON_Print(root);
    printf(out);
    cJSON_Delete(root);
    free(out);

    return 0;
}
