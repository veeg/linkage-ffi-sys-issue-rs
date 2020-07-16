#include <dlfcn.h>
#include <stdio.h>

int test_symbol_in_shared_library(char *relative_path) {
    void *handle = dlopen(relative_path, RTLD_NOW | RTLD_LOCAL);
    if (handle == NULL) {
        printf("error on dlopen: %s\n", dlerror());
        return -1;
    }

    void *symbol = dlsym(handle, "plugin_version");
    if (symbol == NULL) {
        printf("error on dlsym: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    dlclose(handle);
    return 0;
}

int main() {
    printf("# Running shared library symbol loading test\n");

    int c = test_symbol_in_shared_library("./build/libplugin_user_c.so");
    int rust = test_symbol_in_shared_library("./build/libplugin_user_rs.so");

    if (c == 0 && rust == 0) {
        printf("SUCCESS: both c and rust library loaded symbol\n");
    } else if (c == 0 && rust == -1) {
        printf("FAILURE: only c loaded symbol\n");
    } else {
        printf("FAILURE: neither language loaded symbol\n");
    }

    return 0;
}
