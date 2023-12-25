#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cau trúc mang
struct Mang {
  int n;
  int *a;
};

// Ham nhap mang
void NhapMang(struct Mang *m) {
  printf("Nhap so luong phan tu cua mang: ");
  scanf("%d", &m->n);
  m->a = (int *)malloc(m->n * sizeof(int));
  for (int i = 0; i < m->n; i++) {
    printf("Nhap phan tu a[%d]: ", i);
    scanf("%d", &m->a[i]);
  }
}

// Ham ghi mang vao file
void GhiMangVaoFile(struct Mang *m, char *tenfile) {
  FILE *f;
  f = fopen(tenfile, "w");
  if (f == NULL) {
    printf("Khong mo duoc file.");
    exit(1);
  }
  fprintf(f, "%d\n", m->n);
  for (int i = 0; i < m->n; i++) {
    fprintf(f, "%d ", m->a[i]);
  }
  fclose(f);
}

// Ham tinh tong mang
int TinhTongMang(struct Mang *m) {
  int tong = 0;
  for (int i = 0; i < m->n; i++) {
    tong += m->a[i];
  }
  return tong;
}

// Ham tim phan tu lon nhat cua mang
int TimMaxMang(struct Mang *m) {
  int max = m->a[0];
  for (int i = 1; i < m->n; i++) {
    if (m->a[i] > max) {
      max = m->a[i];
    }
  }
  return max;
}

// Ham tim phan tu nho nhat cua mang
int TimMinMang(struct Mang *m) {
  int min = m->a[0];
  for (int i = 1; i < m->n; i++) {
    if (m->a[i] < min) {
      min = m->a[i];
    }
  }
  return min;
}

// Ham dcc noi dung file ra man hinh
void DocFileRaManHinh(char *tenfile) {
  FILE *f;
  f = fopen(tenfile, "r");
  if (f == NULL) {
    printf("Khong mo duoc file.");
    exit(1);
  }
  int n;
  fscanf(f, "%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    fscanf(f, "%d", &x);
    printf("%d ", x);
  }
  fclose(f);
}

// Ham chinh
int main() {
  struct Mang m;
  char tenfile[100];

  // Nhap mang
  NhapMang(&m);

  // Ghi mang vao file
  printf("Nhap ten file: ");
  scanf("%s", tenfile);
  GhiMangVaoFile(&m, tenfile);

  // Tinh tong, tìm phan tu max, min
  int tong = TinhTongMang(&m);
  int max = TimMaxMang(&m);
  int min = TimMinMang(&m);

  // Ghi ket qua vao file
  FILE *f;
  f = fopen(tenfile, "a");
  if (f == NULL) {
    printf("Khong mo duoc file.");
    exit(1);
  }
  fprintf(f, "\nTong mang: %d\n", tong);
  fprintf(f, "Phan tu lon nhat: %d\n", max);
  fprintf(f, "Phan tu nho nhat: %d\n", min);
  fclose(f);
}

