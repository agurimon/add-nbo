#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 0;
    }

    FILE *fp1, *fp2;
    if((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("file1 error\n");
        return 0;
    }
    if((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("file2 error\n");
        return 0;
    }

    size_t n;
    uint32_t net1, net2, sum;
    if(!(n = fread(&net1, sizeof(uint32_t), 1, fp1))) {
        printf("file1 read error\n");
        return 0; 
    }
    if(!(n = fread(&net2, sizeof(uint32_t), 1, fp2))) {
        printf("file2 read error\n");
        return 0; 
    }

    net1 = ntohl(net1);
    net2 = ntohl(net2);
    sum = net1 + net2;
    
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", net1, net1, net2, net2, sum, sum);

    fclose(fp2);
    fclose(fp1);
}