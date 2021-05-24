#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int jmlhkata, char *kata[])
{
    if(jmlhkata != 3){
        printf("Login Gagal!");
        printf("\nPetunjuk Login: ./NamaFileProgram, Username, Password");
        return EXIT_FAILURE;
    }

    char nameinput[20], passinput[20];
    strcpy(nameinput, kata[1]);
    strcpy(passinput, kata[2]);

    FILE *fpw; 
    if((fpw=fopen("DataBase/login.bin", "rb")) == NULL){
        printf("Gagal");
        return EXIT_FAILURE;
    }

    char akun[20];
    fread(akun, sizeof(char),sizeof(akun)/sizeof(char),fpw);
    fclose(fpw);
    
    char *isi[3];
    char username[20], password[20];
    int banyakkata = 0;

    isi[0] = strtok(akun, "@");
    while(isi[banyakkata++] != NULL){
        isi[banyakkata] = strtok (NULL, "@");
    }

    strcpy(username,isi[0]);
    strcpy(password,isi[1]);
    
    if((strcmp(nameinput, username) == 0) && strcmp(passinput, password) == 0) {
        printf("Login Berhasil!\n\n");
        goto soal;
    }
    else {
        printf("Login Gagal!\nUsername atau Password Salah!");
        return EXIT_FAILURE;
    }

    int nilai[5];
    int jawaban[5];

    soal:
    printf("Selamat Datang di Quiz Tepat dan Cerdas!\n\n");
    printf("Soal 1: Apakah nama ibukota Indonesia?\n");
    printf("(1). Jakarta  (2). Bandung  (3). Aceh  (4). Surabaya\n");
    printf("Jawaban anda (1/2/3 atau 4): ");
    scanf("%d", &jawaban[0]);
    if(jawaban[0] == 1){
        printf("Jawaban Anda Benar!\n");
        nilai[0] = 20;    
    }
    else{
        printf("Jawaban Anda Salah!\n");
        nilai[0] = 0;
    }

    printf("\nSoal 2: Berapakah jumlah provinsi di Indonesia?\n");
    printf("(1). 30  (2). 29  (3). 34  (4). 36\n");
    printf("Jawaban anda (1/2/3 atau 4): ");
    scanf("%d", &jawaban[1]);
    if(jawaban[1] == 3){
        printf("Jawaban Anda Benar!\n");
        nilai[1] = 20;    
    }
    else{
        printf("Jawaban Anda Salah!\n");
        nilai[1] = 0;
    }

    printf("\nSoal 3: Siapakah Presiden Indonesia sekarang?\n");
    printf("(1). Joko Widodo  (2). Megawati  (3). Ridwan Kamil  (4). SBY\n");
    printf("Jawaban anda (1/2/3 atau 4): ");
    scanf("%d", &jawaban[2]);
    if(jawaban[2] == 1){
        printf("Jawaban Anda Benar!\n");
        nilai[2] = 20;    
    }
    else{
        printf("Jawaban Anda Salah!\n");
        nilai[2] = 0;
    }

    printf("\nSoal 4: Hasil dari 13 x 3?\n");
    printf("(1). 37  (2). 38  (3). 40  (4). 39\n");
    printf("Jawaban anda (1/2/3 atau 4): ");
    scanf("%d", &jawaban[3]);
    if(jawaban[3] == 4){
        printf("Jawaban Anda Benar!\n");
        nilai[3] = 20;    
    }
    else{
        printf("Jawaban Anda Salah!\n");
        nilai[3] = 0;
    }

    printf("\nSoal 5: Apa julukan bagi negara Indonesia?\n");
    printf("(1). Negeri Tirai Besi  (2). Thousand Islands  (3). Negeri Matador  (4). Negeri Paman Sam\n");
    printf("Jawaban anda (1/2/3 atau 4): ");
    scanf("%d", &jawaban[4]);
    if(jawaban[4] == 2){
        printf("Jawaban Anda Benar!\n");
        nilai[4] = 20;    
    }
    else{
        printf("Jawaban Anda Salah!\n");
        nilai[4] = 0;
    }

    int nilai_akhir = nilai[0] + nilai[1] + nilai[2] + nilai[3] + nilai[4];

    printf("\nSelamat! Anda Telah Menyelesaikan Kuis!\n");
    printf("Nilai Akhir Anda: %d Poin!", nilai_akhir);

    return 0;
}