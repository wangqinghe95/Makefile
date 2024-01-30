#include "utils.h"
#include <stdio.h>

const char utils_file_name[10] = "utils.h";

void getUtilsVersion()
{
    printf("%s\n", utils_file_name);
}