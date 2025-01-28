#include "../includes/cub3d.h"

int display_error(char *context, char *message, int return_code) {
    if (context)
        fprintf(stderr, "[%s] ", context);
    fprintf(stderr, "%s\n", message);
    return return_code;
}
