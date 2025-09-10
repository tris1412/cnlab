#include <stdio.h>

// Function to print binary of a number with fixed bits
void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to calculate 1's complement
int onescompl(int num, int bits) {
    return (~num) & ((1 << bits) - 1);
}

int main() {
    int n, bits;
    int sum = 0;
    printf("Enter no of values: ");
    scanf("%d", &n);
    int data[n];

    printf("Enter your data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }

    printf("\nEnter the no of bits to represent the data: ");
    scanf("%d", &bits);

    int checksum = onescompl(sum, bits);

    printf("\n--- Sender Side ---\n");
    printf("Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d(", data[i]);
        printBinary(data[i], bits);
        printf(") ");
    }
    printf("\nSum = %d (", sum);
    printBinary(sum, bits);
    printf(")\nChecksum = %d (", checksum);
    printBinary(checksum, bits);
    printf(")\n");

    int recvsum = 0;
    for (int i = 0; i < n; i++) recvsum += data[i];
    recvsum += checksum;

    int wrapped = recvsum & ((1 << bits) - 1);
    int final = onescompl(wrapped, bits);

    printf("\n--- Receiver Side ---\n");
    printf("Received Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d(", data[i]);
        printBinary(data[i], bits);
        printf(") ");
    }
    printf("%d(", checksum);
    printBinary(checksum, bits);
    printf(")\n");

    printf("Sum of received + checksum = %d (", recvsum);
    printBinary(recvsum, bits);
    printf(")\n");

    printf("Wrapped sum (%d bits) = %d (", bits, wrapped);
    printBinary(wrapped, bits);
    printf(")\n");

    printf("1's complement of wrapped sum = %d (", final);
    printBinary(final, bits);
    printf(")\n");

    printf(final ? "Error detected.\n" : "No error detected.\n");

    return 0;
}
