#include "./include/mbedtls/sha256.h"
#include <string.h>

#define MODE SHA512
void encrypt_password(char password[]){
	unsigned char digest[64] = { 0 };
	mbedtls_sha256((unsigned char *)password, strlen(password), digest,0);
	strcpy(password,digest);
}