#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct
{
	char Ma[10];
	char Hoten[40];
}
Sinhvien;
///-------
void ReadFile(char *FileName);
void WriteFile(char *FileName);
void Search(char *FileName);
int main()
{
	int c;
	for (;;)
	{
		printf("\n \t*_*_*_*_*_*_*_*_*_*_*\n");
		printf("\t 1. Nhap DSSV\n");
		printf("\t 2. In DSSV\n");
		printf("\t 3. Tim kiem\n");
		printf("\t 4. Thoat\n");
		printf("\t Ban chon 1, 2, 3, 4: ");
		scanf("%d",&c);
		fflush(stdin);
		if(c==1)
		{
			WriteFile("SinhVien.txt");
		}
		else if (c==2)
		{
			ReadFile("SinhVien.txt");
		}
		else if (c==3)
		{
			Search("SinhVien.txt");
		}
		else break;
	}
}
void WriteFile(char *FileName)
{
	FILE *f;
	int n, i;
	SinhVien sv;
	f=fopen(FileName,"ab");
	printf("Nhap vao so luong sinh vien ");
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		printf("Sinh vien thu %i\n", i);
		fflush(stdin);
		printf(" - Ho ten: ");
		gets(sv.Hoten);
		fwrite(&sv,sizeof(sv),1,f);											
	}
	fclose(f);
	printf("Bam phim bat ky de tiep tuc");
	getch();
}
void ReadFile(char *FileName)
{
	FILE * f;
	SinhVien sv;
	f = fopen(FileName, "rb");
	printf(" MSSV | Ho va ten\n");
	fread(&sv,sizeof(sv), 1, f);
	while(!feof(f))
	{
		printf("%s | %s\n", sv.Ma,sv.HoTen);
		fread(&sv,sizeof((sv),1,f));
	}
	fclose(f);
	printf("Bam phim bat ky de tiep tuc!");
	getch();
}
