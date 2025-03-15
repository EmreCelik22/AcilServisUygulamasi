#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Rastgele sayı üretimi

// Hasta bilgileri yapısı
typedef struct {
    int id;
    char isim[50];
    char soyisim[50];
    int yas;
    char cinsiyet[10];
    char iletisim[15];
    char oncelik[20];
    char tc_kimlik[12]; // 11 haneli + null karakter
} Hasta;

// Ilac bilgileri yapısı
typedef struct {
    int recete_id;
    int hasta_id;
    char ilac_adi[50];
    int miktar;
    float gunluk_doz;
    char tarih[11];
} Recete;

// Hasta kayıtları ve reçeteler için diziler
#define MAX_HASTA 100
#define MAX_RECETE 100

Hasta hastalar[MAX_HASTA];
Recete receteler[MAX_RECETE];

int hasta_sayisi = 0;
int recete_sayisi = 0;

// Yeni hasta kaydı fonksiyonu
void yeniHastaEkle() {
    if (hasta_sayisi >= MAX_HASTA) {
        printf("Maksimum hasta kapasitesine ulasildi.\n");
        return;
    }
    Hasta yeni;
    yeni.id = hasta_sayisi + 1;
    printf("Hasta ismini girin: ");
    scanf("%49s", yeni.isim);
    printf("Hasta soyismini girin: ");
    scanf("%49s", yeni.soyisim);
    printf("Yasi girin: ");
    scanf("%d", &yeni.yas);
    printf("Cinsiyeti girin (E/K): ");
    scanf("%9s", yeni.cinsiyet);
    printf("Iletisim bilgilerini girin (Telefon Numarasi): ");
    scanf("%14s", yeni.iletisim);
    printf("Oncelik durumu (Acil/Orta/Dusuk): ");
    scanf("%19s", yeni.oncelik);
    printf("Kimlik numarasi (11 haneli): ");
    scanf("%11s", yeni.tc_kimlik);

    // Benzersiz kimlik kontrolü
    for (int i = 0; i < hasta_sayisi; i++) {
        if (strcmp(hastalar[i].tc_kimlik, yeni.tc_kimlik) == 0) {
            printf("Bu kimlik numarasi zaten kayitli!\n");
            return;
        }
    }

    hastalar[hasta_sayisi++] = yeni;
    printf("Hasta basariyla eklendi.\n");
}

// Hastaları listeleme fonksiyonu
void hastalariListele() {
    if (hasta_sayisi == 0) {
        printf("Kayitli hasta yok.\n");
        return;
    }
    for (int i = 0; i < hasta_sayisi; i++) {
        printf("ID: %d, Isim: %s, Soyisim: %s, Yas: %d, Cinsiyet: %s, Iletisim: %s, Oncelik: %s, Kimlik: %s\n",
               hastalar[i].id, hastalar[i].isim, hastalar[i].soyisim, hastalar[i].yas,
               hastalar[i].cinsiyet, hastalar[i].iletisim, hastalar[i].oncelik, hastalar[i].tc_kimlik);
    }
}

// 6 haneli rastgele reçete numarası üretme fonksiyonu
int uretilenReceteNo() {
    return 100000 + rand() % 900000; // 6 haneli rastgele bir sayı
}

// Reçete oluşturma fonksiyonu
void receteOlustur() {
    if (recete_sayisi >= MAX_RECETE) {
        printf("Maksimum recete kapasitesine ulasildi.\n");
        return;
    }
    Recete yeniRecete;
    yeniRecete.recete_id = uretilenReceteNo(); // 6 haneli reçete numarası atanıyor
    printf("Hangi hasta icin recete olusturuluyor (Hasta ID girin): ");
    scanf("%d", &yeniRecete.hasta_id);

    // Hasta ID kontrolü
    int hastaVar = 0;
    for (int i = 0; i < hasta_sayisi; i++) {
        if (hastalar[i].id == yeniRecete.hasta_id) {
            hastaVar = 1;
            break;
        }
    }
    if (!hastaVar) {
        printf("Gecersiz Hasta ID! Lutfen listeyi kontrol edip gecerli bir ID girin.\n");
        return;
    }

    printf("Ilac adini girin: ");
    scanf("%49s", yeniRecete.ilac_adi);
    printf("Miktari girin (Kutu sayisi): ");
    scanf("%d", &yeniRecete.miktar);
    printf("Ilac gunde kac defa alinacak: ");
    scanf("%f", &yeniRecete.gunluk_doz);
    printf("Recete tarihini girin (GG/AA/YYYY): ");
    scanf("%10s", yeniRecete.tarih);

    receteler[recete_sayisi++] = yeniRecete;
    printf("Recete basariyla olusturuldu. Recete No: %d\n", yeniRecete.recete_id);
}

// Tüm reçeteleri listeleme fonksiyonu
void receteleriListele() {
    if (recete_sayisi == 0) {
        printf("Kayitli recete yok.\n");
        return;
    }
    for (int i = 0; i < recete_sayisi; i++) {
        printf("Recete No: %d, Hasta ID: %d, Ilac: %s, Miktar: %d, Gunluk Doz: %.2f, Tarih: %s\n",
               receteler[i].recete_id, receteler[i].hasta_id, receteler[i].ilac_adi,
               receteler[i].miktar, receteler[i].gunluk_doz, receteler[i].tarih
               );
    }
}

int main() {
    srand(time(NULL)); // Rastgele sayı üretimini başlatmak için
    int secim;
    do {
        printf("\nAcil Servis Yonetim Sistemi\n");
        printf("1. Yeni Hasta Ekle\n");
        printf("2. Hastalari Listele\n");
        printf("3. Recete Olustur\n");
        printf("4. Receteleri Listele\n");
        printf("5. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yeniHastaEkle();
                break;
            case 2:
                hastalariListele();
                break;
            case 3:
                receteOlustur();
                break;
            case 4:
                receteleriListele();
                break;
            case 5:
                printf("Cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 5);

    return 0;
}

