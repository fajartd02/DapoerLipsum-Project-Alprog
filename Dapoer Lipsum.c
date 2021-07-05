/*
 *                  KELOMPOK 1 (Sorted by ID):
 *                  - MARCELLO OCTAVYO ANUGRAHANTO      2440028804
 *                  - FAZA MUTTAQIEN                    2440103060
 *                  - GAFILIANO GAPILI                  2440113591
 *                  - FAJAR MUHAMMAD HAMKA              2440113616
 *
 *  APLIKASI PENCARI RESEP MAKANAN
 *  SORTING ALGORITHM USING     "Quick Sort"
 *  SEARCHING ALGORITHM USING   "Binary Search"
 * 
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define FOODCALORIE "kalorimakanan.txt"
#define UNAMEPWD "user.txt"
#define ENTER 13
#define TAB 9
#define BKSP 8

struct Person
{
    char uname[101];
    char password[101];
};
struct Foodcal
{
    char judulResep[101];
    unsigned kkal;
} dat[1001];

unsigned foodcalsize = 0;

int partition(struct Person data[], int low, int high)
{
    struct Person temp[3];
    struct Person pivot = data[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (strcmp(data[j].uname, pivot.uname) < 0)
        {
            i++;
            temp[0] = data[i];
            data[i] = data[j];
            data[j] = temp[0];
        }
    }
    temp[1] = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp[1];

    return (i + 1);
}
void quickSort(struct Person data[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}
int partition2(struct Foodcal dat[], int low, int high)
{
    struct Foodcal temp[3];
    struct Foodcal pivot = dat[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (strcmp(dat[j].judulResep, pivot.judulResep) < 0)
        {
            i++;
            temp[0] = dat[i];
            dat[i] = dat[j];
            dat[j] = temp[0];
        }
    }
    temp[1] = dat[i + 1];
    dat[i + 1] = dat[high];
    dat[high] = temp[1];

    return (i + 1);
}
void quickSort2(struct Foodcal dat[], int low, int high)
{
    if (low < high)
    {
        int pi = partition2(dat, low, high);
        quickSort2(dat, low, pi - 1);
        quickSort2(dat, pi + 1, high);
    }
}
int partitionCal(struct Foodcal dat[], int low, int high)
{
    struct Foodcal temp[3];
    struct Foodcal pivot = dat[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (dat[j].kkal > pivot.kkal)
        {
            i++;
            temp[0] = dat[i];
            dat[i] = dat[j];
            dat[j] = temp[0];
        }
    }
    temp[1] = dat[i + 1];
    dat[i + 1] = dat[high];
    dat[high] = temp[1];

    return (i + 1);
}
void quickSortCal(struct Foodcal dat[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionCal(dat, low, high);
        quickSortCal(dat, low, pi - 1);
        quickSortCal(dat, pi + 1, high);
    }
}
int binarySearch(int left, int right, char username[], char password[], struct Person data[])
{
    int mid = (left + right) / 2;

    if (right < left)
    {
        return -1;
    }
    if (strcmp(username, data[mid].uname) == 0)
    {
        if (strcmp(password, data[mid].password) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(username, data[mid].uname) < 0)
    {
        return binarySearch(left, mid - 1, username, password, data);
    }
    else if (strcmp(username, data[mid].uname) > 0)
    {
        return binarySearch(mid + 1, right, username, password, data);
    }
    return 0;
}

void catatan()
{
    printf("\nCatatan Penting :\n"
           "Jika Ingin Menurunkan Berat Badan : Kalori Anda - 500\n"
           "Jika Ingin Menaikkan Berat Badan : Kalori Anda + 500\n"
           "\nTekan Apapun Untuk Kembali ke Menu");
    getchar();
}
void kalori()
{
    int gender;
    system("cls");
    printf("1. Laki - Laki\n"
           "2. Perempuan\n"
           "Masukkan Jenis Kelamin Anda\n"
           ">> ");
    scanf("%d", &gender);
    getchar();

    float tinggi, berat, umur, rumus;
    printf("Masukkan Tinggi Badan Anda (cm): ");
    scanf("%f", &tinggi);
    getchar();
    printf("Masukkan Berat Badan Anda (kg): ");
    scanf("%f", &berat);
    getchar();
    printf("Masukkan Usia Anda (Tahun): ");
    scanf("%f", &umur);
    getchar();
    printf(
        "\nAktivitas Anda \n"
        "1. Aktif (Olahraga 5 - 7 kali/Minggu)\n"
        "2. Sedang (Olahraga 3 - 4 kali/Minggu)\n"
        "3. Tidak Aktif (Olahraga 0 - 2 kali/Minggu)\n"
        "\nPilihan Anda\n"
        ">> ");
    int pil;
    scanf("%d", &pil);
    getchar();
    printf("Kalori Harian Anda  = ");
    if (gender == 1)
    {
        rumus = (88.4 + (13.4 * berat)) + (4.8 * tinggi) - (5.68 * umur);
    }

    else if (gender == 2)
    {
        rumus = (447.6 + (9.25 * berat)) + (3.10 * tinggi) - (4.33 * umur);
    }

    if (pil == 1)
    {
        printf("%.2f\n", rumus * 1.9);
        catatan();
    }
    else if (pil == 2)
    {
        printf("%.2f\n", rumus * 1.55);
        catatan();
    }
    else if (pil == 3)
    {
        printf("%.2f\n", rumus * 1.2);
        catatan();
    }
}
void tambahresep()
{
    system("cls");
    char judul[50], deskripsi[1000], bahan[100], langkah[1000], nameBuffer[100];
    unsigned porsi, menit, kaloriMakanan;

    printf("\n\t\t\t\t======Bagikan Resepmu Kepada Orang Lain======\n\n"
           "Nama Masakan: ");
    scanf("%50[^\n]", judul);
    fflush(stdin);

    printf("Deskripsi singkat masakan: ");
    scanf("%1000[^\n]", deskripsi);
    fflush(stdin);

    printf("Porsi (orang): ");
    scanf("%u", &porsi);
    fflush(stdin);

    printf("Lama memasak (menit): ");
    scanf("%u", &menit);
    fflush(stdin);

    printf("Kalori makanan (kkal): ");
    scanf("%u", &kaloriMakanan);
    fflush(stdin);

    sprintf(nameBuffer, "daftarResep/%s.txt", judul);

    FILE *f = fopen(nameBuffer, "w");
    fprintf(f, "\n\t\t\t\t===== %s =====\n\n", judul);
    fprintf(f, "Deskripsi:\n%s\n\n", deskripsi);
    fprintf(f, "Jumlah Porsi\t: %u Orang\n", porsi);
    fprintf(f, "Lama memasak\t: %u Menit\n", menit);
    fprintf(f, "Jumlah kalori\t: %u kkal\n\n", kaloriMakanan);

    FILE *fp = fopen(FOODCALORIE, "a");
    fprintf(fp, "%s,%u\n", judul, kaloriMakanan);
    fclose(fp);
    
    printf("\nAlat dan Bahan: (JIKA SUDAH KETIK \"sudah\")\n");
    unsigned num = 1;
    fprintf(f, "Alat dan Bahan: \n");
    int i = 1;
    do
    {
        printf("%u. ", num++);
        scanf("%100[^\n]", bahan);
        fflush(stdin);
        if (strcmp(bahan, "sudah") == 0 || strcmp(bahan, "Sudah") == 0)
        {
            break;
        }
        else
        {
            fprintf(f, "%d. %s\n", i, bahan);
        }
        i++;
    } while (1);
    fprintf(f, "\n");

    printf("\nLangkah-langkah: (JIKA SUDAH KETIK \"sudah\")\n");
    fprintf(f, "Langkah-langkah: \n");
    num = 1;
    int j = 1;
    do
    {
        printf("%u. ", num++);
        scanf("%1000[^\n]", langkah);
        fflush(stdin);
        if (strcmp(langkah, "sudah") == 0 || strcmp(bahan, "Sudah") == 0)
        {
            break;
        }
        else
        {
            fprintf(f, "%d. %s\n", j, langkah);
        }
        j++;
    } while (1);
    fprintf(f, "\n");
    fclose(f);
    printf("\nTekan ENTER Untuk Kembali ke Menu Utama...");
    getchar();
}
int displayDIR(int choice)
{
    system("cls");
    FILE *fp = fopen(FOODCALORIE, "r");
    int i = 0, j;

    if (fp == NULL)
    {
        return i;
    }
    else
    {
        printf("\tDaftar Resep yang Ada:\n");
        while (fscanf(fp, " %[^,],%u\n", dat[i].judulResep, &dat[i].kkal) != EOF)
        {
            i++;
        }
        fclose(fp);
        foodcalsize = i;

        if (choice == 0)
        {
            quickSort2(dat, 0, i - 1);
            printf("\t\t\t\t+================================+\n");
            for (j = 0; j < i; j++)
            {
                printf("\t\t\t\t| %-20s | %u kkal|\n", dat[j].judulResep, dat[j].kkal);
            }
            printf("\t\t\t\t+================================+\n");
        }
        else if (choice == 1)
        {
            quickSort2(dat, 0, i - 1);
            printf("\t\t\t\t+================================+\n");
            for (j = i - 1; j >= 0; j--)
            {
                printf("\t\t\t\t| %-20s | %u kkal|\n", dat[j].judulResep, dat[j].kkal);
            }
            printf("\t\t\t\t+================================+\n");
        }
        else if (choice == 2)
        {
            quickSortCal(dat, 0, i - 1);
            printf("\t\t\t\t+================================+\n");
            for (j = 0; j < i; j++)
            {
                printf("\t\t\t\t| %-20s | %u kkal|\n", dat[j].judulResep, dat[j].kkal);
            }
            printf("\t\t\t\t+================================+\n");
        }
        else if (choice == 3)
        {
            quickSortCal(dat, 0, i - 1);
            printf("\t\t\t\t+================================+\n");
            for (j = i - 1; j >= 0; j--)
            {
                printf("\t\t\t\t| %-20s | %u kkal|\n", dat[j].judulResep, dat[j].kkal);
            }
            printf("\t\t\t\t+================================+\n");
        }
    }
    return i;
}
void view()
{
    int check = displayDIR(0);
    if (check == 0)
    {
        printf("No Data!\n");
        getchar();
        return;
    }

    printf(
        "\n"
        "\t1. Urut berdasarkan nama\n"
        "\t2. Urut berdasarkan kalori\n"
        "\t3. Pilih resep\n"
        "\t>> ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1)
    {
        printf(
            "\n"
            "\t1. A - Z\n"
            "\t2. Z - A\n"
            "\t>> ");
        int choice1;
        scanf("%d", &choice1);
        getchar();
        choice1 == 1 ? displayDIR(0) : displayDIR(1);
    }
    else if (choice == 2)
    {
        printf(
            "\n"
            "\t1. Tinggi - Rendah\n"
            "\t2. Rendah - Tinggi\n"
            "\t>> ");
        int choice2;
        scanf("%d", &choice2);
        getchar();
        choice2 == 1 ? displayDIR(2) : displayDIR(3);
    }

    char resep[100];
    char judul[50];
    printf("\tMasukkan Resep Yang Anda Inginkan: ");
    scanf("%100[^\n]", judul);
    fflush(stdin);

    sprintf(resep, "daftarResep/%s.txt", judul);
    system("cls");
    char temp[1981];
    FILE *file = fopen(resep, "r");
    while (fgets(temp, 1981, file) != NULL)
    {
        //puts(temp);
        printf("%s", temp);
    }
    fclose(file);
    printf("\tTekan ENTER Untuk Kembali ke Menu Utama...\n");
    getchar();
}
void hapusresep()
{
    system("cls");
    unsigned i;
    char hapusfile[101], judulmakanan[101];
    char full[120] = "./daftarResep/";

    printf("\t\t\t\t======Hapus Resep======\n");

    int check = displayDIR(0);
    if (check == 0)
    {
        printf("No Data!\n");
        getchar();
        return;
    }

    printf("\n\tKetik nama resep yang ingin dihapus: ");
    scanf("%100[^\n]", hapusfile);
    fflush(stdin);
    strcpy(judulmakanan, hapusfile);

    strcat(hapusfile, ".txt");
    strcat(full, hapusfile);

    if (remove(full) == 0)
    {
        printf("\t%s berhasil dihapus.\n", hapusfile);
        remove(FOODCALORIE);

        FILE *fp = fopen(FOODCALORIE, "a");
        for (i = 0; i < foodcalsize; i++)
        {
            if (strcmp(judulmakanan, dat[i].judulResep) == 0)
            {
                continue;
            }
            fprintf(fp, "%s,%u\n", dat[i].judulResep, dat[i].kkal);
            printf("%s %u\n", dat[i].judulResep, dat[i].kkal);
        }
        fclose(fp);

        printf("\n\tTekan ENTER Untuk Kembali ke Menu Utama...");
        getchar();
    }
    else
    {
        printf("\n\tTidak dapat menghapus %s", hapusfile);
        perror("\n\tError");
        printf("\n\n\tTekan ENTER Untuk Kembali ke Menu Utama...");
        getchar();
    }
}
void registerr()
{
    system("cls");
    char print[100001];
    FILE *file = fopen("login.txt", "r");
    while ((fscanf(file, " %[^\n]", print)) != EOF)
    {
        printf("\t\t\t\t%s\n", print);
    }
    fclose(file);
    printf("\t\t\t\tSilakan memilih menu: 2\n");
    fflush(stdin);
    char username[11] = {"\0"}, password[16] = {"\0"};
    printf("\t\t\t\tMasukkan Username Anda: ");
    scanf("%s", username);
    fflush(stdin);
    if (strlen(username) < 3 || strlen(username) > 10)
    {
        printf("\n\n\t\t\t\tUsername harus memiliki panjang 3 sampai 10 karakter!\n\t\t\t\tTekan ENTER...");
        getchar();
        registerr();
    }
    else
    {
        printf("\t\t\t\tMasukkan Password Anda: ");
        scanf("%s", password);
        fflush(stdin);
        if (strlen(password) < 5 || strlen(password) > 15)
        {
            printf("\n\n\t\t\t\tPassword harus memiliki panjang 5 sampai 15 karakter\n\t\t\t\tTekan ENTER...");
            getchar();
            registerr();
        }
        else
        {
            FILE *file = fopen(UNAMEPWD, "a");
            fprintf(file, "%s,%s\n", username, password);
            fclose(file);

            printf("\n\t\t\t\tTerima kasih telah mengisi data!\n");
            printf("\t\t\t\tTekan ENTER untuk kembali ke menu...\n");
            getchar();
        }
    }
}
int login()
{
    fflush(stdin);
    FILE *file = fopen(UNAMEPWD, "r");
    struct Person data[1001];
    int validation = 0;
    int i = 0;
    while (fscanf(file, " %[^,],%[^\n]\n", data[i].uname, data[i].password) != EOF)
    {
        i++;
    }
    fclose(file);
    quickSort(data, 0, i - 1);

    char username[11], password[16];
    printf("\t\t\t\tMasukkan Username Anda: ");
    scanf(" %s", username);
    fflush(stdin);
    printf("\t\t\t\tMasukkan Password Anda: ");
    
    int j = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            password[j] = '\0';
            break;
        }
        else if (ch == BKSP)
        {
            if (j > 0)
            {
                j--;
                printf("\b \b");
            }
        }
        else
        {
            password[j++] = ch;
            printf("* \b");
        }
    }
    
//     scanf("%s", password);
//     fflush(stdin);

    int check = binarySearch(0, i - 1, username, password, data);
    if (check == 1)
    {
        validation = 1;
    }
    return validation;
}
void keluar()
{
    printf("\n");
    char xit[] = "\t\t\t       Terima kasih telah menggunakan aplikasi ini.";
    char xit2[] = "\t\t       Semoga harimu menyenangkan!  ";
    char xit3[] = "\t\t\t\t      Created by Dapoer Lipsum Team";

    for (int i = 0; i < strlen(xit); i++)
    {
        printf("%c", xit[i]);
        _sleep(60);
    }
    _sleep(800);
    for (int i = 0; i < strlen(xit); i++)
    {
        printf("\b \b");
        _sleep(40);
    }
    for (int i = 0; i < strlen(xit2); i++)
    {
        printf("%c", xit2[i]);
        _sleep(60);
    }
    _sleep(800);
    printf("\r");
    for (int i = 0; i < strlen(xit3); i++)
    {
        printf("%c", xit3[i]);
        _sleep(60);
    }
    _sleep(2000);
    exit(0);
}
int main()
{
    system("color f0");
    char print[100001];
    fflush(stdin);
    int choice;

    while (1)
    {
        system("cls");
        FILE *file = fopen("login.txt", "r");
        while ((fscanf(file, " %[^\n]", print)) != EOF)
        {
            printf("\t\t\t\t%s\n", print);
        }
        fclose(file);
        printf("\t\t\t\tSilakan memilih menu: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1)
        {
            int valid = login();
            if (valid == 1)
            {
                int choose;
                while (1)
                {
                    system("cls");
                    FILE *file = fopen("menu.txt", "r");
                    while ((fscanf(file, " %[^\n]", print)) != EOF)
                    {
                        printf("\t\t\t\t%s\n", print);
                    }
                    fclose(file);
                    printf("\t\t\t\tSilakan memilih menu: ");
                    scanf("%d", &choose);
                    getchar();
                    switch (choose)
                    {
                    case 1:
                        view();
                        break;
                    case 2:
                        tambahresep();
                        break;
                    case 3:
                        hapusresep();
                        break;
                    case 4:
                        kalori();
                        break;
                    case 5:
                        main();
                        break;
                    }
                }
            }
            else
            {
                printf("\nPassword / Username anda salah!\nPerhatikan huruf kapital saat mengisi data!\nJika belum pernah login, silakan melakukan registrasi!");
                getchar();
            }
        }

        else if (choice == 2)
        {
            registerr();
        }

        else if (choice == 3)
        {
            int choose;
            while (1)
            {
                system("cls");
                FILE *file = fopen("menuguest.txt", "r");
                while ((fscanf(file, " %[^\n]", print)) != EOF)
                {
                    printf("\t\t\t\t%s\n", print);
                }
                fclose(file);
                printf("\t\t\t\tSilakan memilih menu: ");
                scanf("%d", &choose);
                fflush(stdin);
                switch (choose)
                {
                case 1:
                    view();
                    break;
                case 2:
                    kalori();
                    break;
                case 3:
                    keluar();
                    break;
                }
            }
        }

        else if (choice == 4)
        {
            keluar();
        }
    }
    return 0;
}
