#include <stdio.h>
#include <math.h>

// Hàm in nhị phân để dễ debug (nếu cần xem bit)
void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    int val = 0, n = 0;

    printf("\n--- TEST THAO TAC BIT ---\n");

    // 1. Bật bit (Set bit)
    val = 0; n = 2;
    val |= (1 << n);
    printf("Bat bit %d cua 0 -> KQ: %d\n", n, val);

    // 2. Tắt bit (Clear bit)
    val = 7; n = 1;
    val &= ~(1 << n);
    printf("Tat bit %d cua 7 -> KQ: %d\n", n, val);

    // 3. Đảo bit (Toggle)
    val = 5; n = 0;
    val ^= (1 << n);
    printf("Dao bit %d cua 5 -> KQ: %d\n", n, val);

    // 4. Kiểm tra bit bật hay tắt
    val = 4; n = 2;
    int is_on = (val & (1 << n)) != 0;
    printf("Bit %d cua 4 co bat khong? -> %s\n", n, is_on ? "Co" : "Khong");


    printf("\n--- TEST LOGIC ---\n");

    // 5. Swap 2 số không dùng biến tạm
    int a = 5, b = 9;
    printf("Truoc swap: a = %d, b = %d\n", a, b);
    a ^= b; b ^= a; a ^= b;
    printf("Sau swap:   a = %d, b = %d\n", a, b);

    // 6. Kiểm tra lũy thừa của 2
    int num = 16;
    if (num > 0 && ((num & (num - 1)) == 0)) {
        printf("%d la luy thua cua 2\n", num);
    }

    // 7. Kiểm tra chẵn lẻ
    num = 11;
    if (num & 1) printf("%d la so Le\n", num);
    else printf("%d la so Chan\n", num);

    // 8. Bù 2 (Two's complement)
    num = 5;
    printf("Bu 2 cua %d la: %d\n", num, (~num + 1));

    // 9. So sánh bằng nhau (không dùng ==)
    int x = 10, y = 10;
    if (!(x ^ y)) printf("Hai so %d va %d bang nhau\n", x, y);


    printf("\n--- TEST MSB/LSB & TRICK ---\n");

    // 10. Tìm vị trí bit cao nhất (MSB) 
    num = 10; // 1010
    printf("Vi tri MSB cua %d la: %d\n", num, (int)log2(num));

    // 11. Tìm vị trí bit thấp nhất (LSB)
    num = 12; // 1100
    printf("Vi tri LSB cua %d la: %d\n", num, (int)log2(num & -num));

    // 12. Tắt bit 1 thấp nhất (Remove last set bit)
    num = 12;
    printf("12 sau khi tat bit 1 thap nhat: %d\n", num & (num - 1));

    // 13. Lấy riêng bit 1 thấp nhất (Isolate rightmost bit)
    num = 10;
    printf("Lay rieng bit 1 cuoi cung cua 10: %d\n", num & -num);

    // 14. Kiểm tra bội số của 8
    num = 16;
    if ((num & 7) == 0) printf("%d chia het cho 8\n", num);

    return 0;
}