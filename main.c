#include <stdio.h>
#include <string.h>
#include "strutil.h"

void main(void) 
{
    char *s = malloc(1024);
    snprintf(s, 1024, "asdfghjk_key_qwert_val_zxcv\nmnbvcxz_val_mnb-key\n");
    printf("%s\n", s);

    char *ss = str_replace(s,"key", "KKEEYY");
    printf("%s\n", ss);

    // char *sss = str_replace(ss,"val", "VL");
    char *sss = str_replace(ss,"val", "あいう");
    printf("%s\n", sss);

    free(sss);
}
