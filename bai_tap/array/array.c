#include <stdio.h>

// CAC HAM TIEN ICH

void inMang(int a[], int n) {
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

// CAC HAM LOGIC MANG 1 CHIEU   

void tinhTongTB(int a[], int n) {
    int tong = 0;
    for(int i=0; i<n; i++) tong += a[i];
    printf("Tong: %d, Trung binh: %.2f\n", tong, (float)tong/n);
}

void timMax(int a[], int n) {
    int max = a[0], idx = 0;
    for(int i=1; i<n; i++) {
        if(a[i] > max) { max = a[i]; idx = i; }
    }
    printf("Max: %d (index %d)\n", max, idx);
}

// Tim xem x co trong mang khong
void timGiaTriX(int a[], int n, int x) {
    int tim_thay = 0;
    printf("Tim so %d: ", x);
    for(int i=0; i<n; i++) {
        if(a[i] == x) {
            printf("Thay tai vi tri %d ", i);
            tim_thay = 1;
        }
    }
    if(!tim_thay) printf("Khong co trong mang");
    printf("\n");
}

// Tinh tong cac phan tu o vi tri chan 
void tongViTriChan(int a[], int n) {
    int sum = 0;
    for(int i=0; i<n; i+=2) sum += a[i];
    printf("Tong cac so o vi tri chan: %d\n", sum);
}

void demChanLe(int a[], int n) {
    int c=0, l=0;
    for(int i=0; i<n; i++) (a[i]%2==0) ? c++ : l++;
    printf("Chan: %d, Le: %d\n", c, l);
}

void daoNguoc(int a[], int n) {
    for(int i=0; i<n/2; i++) {
        int tmp = a[i]; a[i] = a[n-1-i]; a[n-1-i] = tmp;
    }
}

void sapXep(int a[], int n) {
    for(int i=0; i<n-1; i++) 
        for(int j=i+1; j<n; j++) 
            if(a[i] > a[j]) { int tmp=a[i]; a[i]=a[j]; a[j]=tmp; }
}

//  Gop 2 mang a va b thanh mang c
void gopMang(int a[], int nA, int b[], int nB) {
    int c[200]; // Mang ket qua
    int nC = nA + nB;
    for(int i=0; i<nA; i++) c[i] = a[i];
    for(int i=0; i<nB; i++) c[nA + i] = b[i];
    
    printf("Mang sau khi gop A va B: ");
    inMang(c, nC);
}

void xoaPhanTu(int a[], int *n, int k) {
    if(k<0 || k>=*n) return;
    for(int i=k; i < *n-1; i++) a[i] = a[i+1];
    (*n)--;
}

void chenPhanTu(int a[], int *n, int k, int val) {
    for(int i=*n; i > k; i--) a[i] = a[i-1];
    a[k] = val;
    (*n)++;
}

void timXuatHienNhieu(int a[], int n) {
    int val = a[0], max_dem = 0;
    for(int i=0; i<n; i++) {
        int dem = 0;
        for(int j=0; j<n; j++) if(a[j] == a[i]) dem++;
        if(dem > max_dem) { max_dem = dem; val = a[i]; }
    }
    printf("So xuat hien nhieu nhat: %d (%d lan)\n", val, max_dem);
}

void locTrung(int a[], int n) {
    printf("Unique elements: ");
    for(int i=0; i<n; i++) {
        int ok = 1;
        for(int j=0; j<i; j++) if(a[i] == a[j]) { ok = 0; break; }
        if(ok) printf("%d ", a[i]);
    }
    printf("\n");
}

// --- CAC HAM LOGIC MA TRAN ---

void xuLyMaTranCoBan() {
    printf("\n--- MA TRAN CO BAN ---\n");
    int mt[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    int chinh=0, phu=0;
    for(int i=0; i<3; i++) {
        chinh += mt[i][i];
        phu += mt[i][3-1-i];
    }
    printf("Tong cheo chinh: %d, phu: %d\n", chinh, phu);
}

// Kiem tra ma tran doi xung
void kiemTraDoiXung() {
    // Thu tao ma tran doi xung de test
    int mt[3][3] = {
        {1, 5, 9},
        {5, 2, 6},
        {9, 6, 3}
    };
    int doi_xung = 1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<i; j++) {
            if(mt[i][j] != mt[j][i]) { doi_xung = 0; break; }
        }
    }
    printf("Ma tran test co doi xung khong? -> %s\n", doi_xung ? "Co" : "Khong");
}

//  Cong 2 ma tran
void congMaTran() {
    printf("Cong 2 ma tran A va B:\n");
    int A[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
    int B[3][3] = {{2,2,2}, {3,3,3}, {4,4,4}};
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }
}

// --- MAIN ---

int main() {
    int a[100] = {10, 5, 2, 8, 5, 3, 1, 4, 5, 6};
    int n = 10;
    
    printf("Mang goc: "); inMang(a, n); printf("\n");

    // Goi cac ham xu ly mang
    tinhTongTB(a, n);
    timMax(a, n);
    demChanLe(a, n);
    tongViTriChan(a, n);  
    timGiaTriX(a, n, 8);  
    
    daoNguoc(a, n);
    printf("Dao nguoc: "); inMang(a, n);
    daoNguoc(a, n);

    sapXep(a, n);
    printf("Sap xep: "); inMang(a, n);

    xoaPhanTu(a, &n, 2);
    printf("Xoa index 2: "); inMang(a, n);

    chenPhanTu(a, &n, 1, 99);
    printf("Chen 99 vao index 1: "); inMang(a, n);

    // Test gop mang 
    int b[5] = {100, 200, 300};
    gopMang(a, n, b, 3); 
    timXuatHienNhieu(a, n);
    locTrung(a, n);

    // Phan ma tran
    xuLyMaTranCoBan();
    kiemTraDoiXung(); 
    congMaTran();     

    return 0;
}