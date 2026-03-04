#include <iostream>
#include <cstdio> 
long long myAtoi(const char* str) {
    long long result = 0;
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main() {
    FILE* file;
    errno_t err = fopen_s(&file, "in.txt", "r");
    char line[256];
    long long sum = 0;   

    while (fgets(line, sizeof(line), file) != nullptr) {
        long long number = myAtoi(line);
        sum += number;
    }

    fclose(file);
    printf("%lld", sum);
    return 0;
}
