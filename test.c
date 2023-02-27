#include <stdio.h>
#include <string.h>
#include "twofish.h"

int main(void) {
    // Initialize the Twofish implementation
    Twofish_initialise();

    // Define a key and a message to encrypt
    Twofish_Byte key[32] = {0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe,
                            0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x0f,
                            0xed, 0xcb, 0xa9, 0x87, 0x65, 0x43, 0x21, 0x1e,
                            0x3c, 0x5a, 0x78, 0x96, 0xb4, 0xd2, 0xf0, 0xef};
    Twofish_Byte message[32] = "Hello, cipher World!";

    // Prepare the key for encryption
    Twofish_key enc_key;
    Twofish_prepare_key(key, 32, &enc_key);

    printf("Key: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    // Encrypt the message
    Twofish_Byte ciphertext[32];
    Twofish_encrypt(&enc_key, message, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // Prepare the key for decryption
    Twofish_key dec_key;
    Twofish_prepare_key(key, 32, &dec_key);

    // Decrypt the ciphertext
    Twofish_Byte decrypted[32];
    Twofish_decrypt(&dec_key, ciphertext, decrypted);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    // Check if the decrypted message matches the original message
    if (strcmp((char*)message, (char*)decrypted) == 0) {
        printf("Decryption successful!\n");
    } else {
        printf("Decryption failed.\n");
    }

    return 0;
}
