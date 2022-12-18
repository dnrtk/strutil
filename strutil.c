#include "strutil.h"

// orgにはmallocで確保した領域のポインタを渡すこと
// (org領域を解放して新たにmallocで領域確保するため)
char* str_replace(char *org, char *src, char *dst) {
    size_t org_len = strlen(org) + 1;
    size_t src_len = strlen(src);
    size_t dst_len = strlen(dst);

    // 置換後の文字列長を計算
    size_t new_len = org_len;
    char *org_pos = org;
    while ((org_pos = strstr(org_pos, src)) != NULL) {
        org_len += dst_len - src_len;
    }
    // 置換後の文字列長で新領域を確保
    char *new = realloc(org, new_len);
    if (NULL == new) {
        printf("[%s] realloc faied. new_len=%ld\n", __func__, new_len);
        free(org);
        return NULL;
    }
    // 置換処理
    char *org_base = org;
    while ((org_pos = strstr(org_base, src)) != NULL) {
        *org_pos = '\0';
        strcat(new, org_base);
        strcat(new, dst);
    }
    strcat(new, org_base);
    free(org);
    return new;
}
