{
    int n, bits;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int data[n];
    int sum = 0;

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }

    printf("Enter the number of bits to represent the data: ");
    scanf("%d", &bits);

    // Calculate checksum
    int checksum = onesComplement(sum, bits);

    printf("\nAt sender's side:\n");
    printf("Data: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\nSum = %d", sum);
    printf("\nChecksum = %d\n", checksum);

    // At receiver
    int newSum = sum + checksum;
    int wrappedSum = newSum & ((1 << bits) - 1); // wrap around extra bits
    int final = onesComplement(wrappedSum, bits);

    printf("\nAt receiver's side:\n");
    printf("Received Data: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("%d (checksum)\n", checksum);
    printf("Sum of received data + checksum = %d\n", newSum);
    printf("Wrapped sum (within %d bits) = %d\n", bits, wrappedSum);
    printf("1's complement of wrapped sum = %d\n", final);

    if (final == 0)
        printf("No error detected.\n");
    else
        printf("Error detected.\n");

    return 0;
}
