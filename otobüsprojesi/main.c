#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char isim[25], soyad[30], otobusismi[50], baslangicsehir[50], varissehri[50];
int x = 30, koltukno[50], otobuskapasite[50], otono[50], biletparasi[50], baslangicsaat[50];
int baslangicdk[50], varissaat[50], toplamhasilat[50], seferno[50], sayac = 0, sayac2 = 0, rezno[50], sefersec[50];
int i, y, d, k, j, t, a, sayi, koltuksecimi, sefersaati, tercih3, ana_islem, firma, rezervasyonno;

int main() {
  int firma;
  ana_menu();
  firmagirismenusu();
  musterigirismenusu();
  seferlerilistele();
  rezervasyonyap();
  rezervasyongoster();
  return 0;
}
int ana_menu() {

  anamenu:

    printf("*ANA MENU*\n1.Firma Girisi\n2.Musteri Girisi\n3.Cikis\n\n");
  printf("Lutfen bir giris yapiniz:->");
  scanf("%d", & ana_islem);

  switch (ana_islem) {
  case 1:
    firmagirismenusu();
    break;
  case 2:
    musterigirismenusu();
    break;
  }
  getchar();

  if (ana_islem > 3) {
    printf("hatali giris yaptiniz!!\n\n");
    goto anamenu;
  }

}
void firmagirismenusu() {

  printf("\n*FIRMA MENUSU*\n");
  printf("1-Otobus ekle\n2-Sefer Bilgisi Ekle\n3-Sefer/Koltuk Bilgisi\n4-Bir Ust Menuye Don\n\n");
  printf("Lutfen bir islem seciniz:->");
  scanf("%d", & firma);

  switch (firma) {
  case 1:
    otobusekle();
    break;
  case 2:
    seferbilgisi();
    break;
  case 3:
    koltukbilgisi();
    break;

  case 4:
    ana_menu();
    break;
  }

}
otobusekle() {
  dongu: printf("Otobus kapasitesi giriniz:");
  scanf("%d", & otobuskapasite[sayac]);
  if (otobuskapasite[sayac] > 30) {
    printf("uzun yol otobusu sectiniz\n");
  } else {
    printf("kisa yol otobusu sectiniz\n");
  }

  printf("otobusun modeli:");
  scanf("%s", & otobusismi[sayac]);

  printf("Otobus numarasini giriniz:");
  scanf("%d", & otono[sayac]);

  if (otobuskapasite[sayac] > 30) {
    printf("otobuste 3 kisi personel olarak gorevlendirilecektir.\n");
  } else {
    printf("otobuste 2 kisi personel olarak gorevlendirilecektir.\n");
  }
  int tercih;
  printf("1-Otobus ekle\n2-Ana menuye don\n3-Firma Menusune don\n");
  printf("Lutfen bir islem seciniz:->");
  scanf("%d", & tercih);
  switch (tercih) {
  case 1:
    sayac++;
    goto dongu;
    break;
  case 2:

    ana_menu();
    break;
  case 3:
    firmagirismenusu();
    break;

  }

}
int seferbilgisi() {
  printf("Sefer numaraniz:30");
  srand(time(NULL));
  for (i = 0; i < 4; i++) {
    sayi = rand() % 15;
    printf("%X", sayi);
  }

  printf("dir.\nSefer numarasini dogrulayiniz:");
  scanf("%X", & seferno[sayac2]);
  printf("\nHangi otobusu kullanmak istiyorsunuz:");
  scanf("%d", & y);

  //baslangic saati
  printf("Sefer baslangic saatini giriniz:");
  scanf("%d", & baslangicsaat[sayac2]);
  printf("Sefer baslangic dk giriniz:");
  scanf("%d", & baslangicdk[sayac2]);

  if (baslangicdk[sayac2] != 30) {
    printf("Bu saatte sefer gerceklestirilemez.\n");
    printf("Sefer%d:30 saatinde baslayacaktir\n", baslangicsaat[sayac2]);

  } else {
    printf("Sefer %d:30 saatinde baslayacaktir\n", baslangicsaat[sayac2]);
  }
  //varis saati

  dongu2:
    printf("Varis saatini giriniz:");
  scanf("%d", & varissaat[sayac2]);
  printf("Otobus kapasite:%d\n", otobuskapasite[y - 1]);
  sefersaati = varissaat[sayac2] - baslangicsaat[sayac2];
  if (sefersaati > 4) {
    if (otobuskapasite[y - 1] < 30) {

      printf("Kisa yol otobusuyle bu sefer yapilamaz.\n");
      goto dongu2;
    } else {
      printf("Sefer yaklasik %d saat surecektir.\n", sefersaati);

    }
  } else {
    printf("Sefer yaklasik %d saat surecektir.\n", sefersaati);
  }

  //sehir ve hasýlat
  printf("Baslangic sehrini giriniz:");
  scanf("%s", & baslangicsehir);
  printf("Varis sehrini giriniz:");
  scanf("%s", & varissehri);
  printf("Istenilen toplam hasilati giriniz:");
  scanf("%d", & toplamhasilat[sayac2]);
  //bilet parasý
  biletparasi[sayac2] = toplamhasilat[sayac2] / otobuskapasite[y - 1];
  printf("Bilet parasi:%d\n", biletparasi[sayac2]);
  int tercih2;
  printf("1-Firma giris menusu\n2-Yeni sefer olustur\n3-Musteri Menusu\n");
  printf("Lutfen bir islem seciniz:->");
  scanf("%d", & tercih2);

  switch (tercih2) {
  case 1:
    sayac++;
    firmagirismenusu();
    break;
  case 2:
    sayac2++;
    seferbilgisi();
    break;
  case 3:
    sayac2++;
    musterigirismenusu();
    break;
  }

}
int koltukbilgisi() {
  k = sayac2 + 1;
  for (i = 0; i < k; i++) {
    printf("\nSefer numarasi:30%X", seferno[i]);
  }

  printf("\nSefer no sec:");
  scanf("%d", & d);
  printf("Otobus sec:");
  scanf("%d", & t);
  int e, f, m, p;

  printf("\nuygun koltuklar asagida listelenmistir\n\n");
  m = (otobuskapasite[t - 1]) / 4;
  f = m + 1;
  for (p = 0; p < f; p++) {
    printf("  \t\t   [] []     [] []       ");
    printf("\t\n");
  }
  bilgilendirme();
  printf("\n1-Ana menuye don\n2-Firma Menusune don\n");
  printf("Lutfen bir islem seciniz:->");
  scanf("%d", & tercih3);
  switch (tercih3) {
  case 1:
    sayac++;
    ana_menu();
    break;
  case 2:
    firmagirismenusu();
    break;
  }

}

int bilgilendirme() {
  printf("\n\n*BILGILENDIRME KISMI*\n\n");
  printf("Sefer no:%X\n", seferno[d - 1]);
  printf("Balangic-Varis Sehri:%s-%s\n", baslangicsehir, varissehri);
  printf("Otobus kalkis-Varis saatleri:%d:30-%d:30\n", baslangicsaat[d - 1], varissaat[d - 1]);
  printf("Otobus no:%d\n", otono[d - 1]);
}
int musterigirismenusu() {
  int islem2;
  printf("MUSTERI MENUSU\n");
  printf("1-Seferleri Listele\n2-Sefer Rezervasyon Yap\n3-Bir Ust Menuye Don\n4-Rezervasyon Goster\n");
  printf("lutfen yapacaginiz islemi seciniz->");
  scanf("%d", & islem2);
  switch (islem2) {
  case 1:

    seferlerilistele();
    break;
  case 2:

    rezervasyonyap();
    break;
  case 3:
    ana_menu();
    break;
  case 4:
    rezervasyongoster();
    break;
  }

}
void seferlerilistele() {

  a = sayac2 + 2;

  for (i = 0; i < a; i++) {
    for (j = 0; j < a; j++) {
      if (seferno[i] <= seferno[j]) {
        t = seferno[i];
        seferno[i] = seferno[j];
        seferno[j] = t;

      }

    }
  }
  printf("Sefer Numarasi         Otono   Guzergah    Kalkis-Varis Saati       Ucret\n ");

  for (i = 1; i < a; i++) {
    printf("\nSefer numarasi:%X\t %d\t %s-%s\t     %d:30-%d:30\t     %d ", seferno[i], otono[i - 1], baslangicsehir, varissehri, baslangicsaat[i - 1], varissaat[i - 1], biletparasi[i - 1]);

  }
  printf("\n1-Rezervasyon Yap\n2-Ana Menu\n");
  printf("lutfen yapacaginiz islemi seciniz->");
  int tercih5;
  scanf("%d", & tercih5);
  switch (tercih5) {
  case 1:
    rezervasyonyap();
    break;
  case 2:
    ana_menu();
    break;
  }
}

int rezervasyonyap() {
  char onay;
  int f, e, p, m;

  a = sayac2 + 2;
  for (i = 1; i < a; i++) {
    printf("\nSefer numaralari:%X", seferno[i]);
  }
  printf("\nSefer seciniz-->");
  scanf("%d", & sefersec[0]);
  printf("\nuygun koltuklar asagida listelenmistir\n\n");
  m = (otobuskapasite[sefersec[0] - 1]) / 4;
  f = m + 1;
  for (p = 0; p < f; p++) {
    printf("  \t\t   [] []     [] []       ");
    printf("\t\n");
  }
  printf("Lutfen isim bilgilerini giriniz:");
  scanf("%s", & isim);
  printf("Lutfen soyisim bilgilerini giriniz:");
  scanf("%s", & soyad);
  printf("lutfen koltuk numaranizi seciniz:");
  scanf("%d", & koltuksecimi);
  printf("\nSeferno:%X\nAD:%s Soyad:%s\nKoltuk numarasi:%d\n", seferno[sefersec[0]], isim, soyad, koltuksecimi);
  printf("Rezervasyonu Onayliyor musunuz?\n\t\t\tE/H\n");
  scanf("%s", & onay);
  switch (onay) {
  case 'E':
    goto rezno;
    break;
  case 'e':
    goto rezno;
    break;
  case 'h':
    musterigirismenusu();
    break;
  case 'H':
    musterigirismenusu();
    break;
  }

  rezno:
    printf("rezervasyon numaraniz:");
  srand(time(NULL));
  for (i = 0; i < 8; i++) {
    sayi = rand() % 15;
    printf("%X", sayi);
  }
  printf("'dir.\n");
  printf("Rezervasyon numaranizi dogrulayiniz:");
  scanf("%X", & rezno[50]);
  int tercih4;
  printf("1-Rezervasyon Goster\n2-Musteri Menusu\n");
  printf("lutfen yapacaginiz islemi seciniz->");
  scanf("%d", & tercih4);
  switch (tercih4) {
  case 1:
    rezervasyongoster();
    break;
  case 2:
    musterigirismenusu();
    break;
  }

}
int rezervasyongoster() {

  printf("lutfen rezervasyon numaranizi giriniz:\n");
  scanf("%X", & rezervasyonno);
  if (rezervasyonno == rezno[50]) {
    printf("AD:%s\t SOYAD:%s dir\n", isim, soyad);
    printf("Koltuk numaraniz %d dir\n", koltuksecimi);
    printf("sefer numaraniz %X dir.", seferno[sefersec[0]]);
  } else {
    printf("yanlis rezervasyon numarasini tusladiniz...\n");

  }

}
