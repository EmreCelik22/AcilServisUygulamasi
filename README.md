# Acil Servis Yönetim Sistemi

Bu proje, **C programlama dili** kullanılarak geliştirilen bir Acil Servis Yönetim Sistemi uygulamasıdır. Uygulama, hasta kayıtlarını ve reçete işlemlerini kolayca yönetmek için tasarlanmıştır. Komut satırında çalışan bu program, kullanıcının çeşitli işlemleri gerçekleştirmesine olanak tanır.

## Özellikler

- Yeni hasta ekleme
- Mevcut hastaları listeleme
- Hasta için reçete oluşturma
- Tüm reçeteleri listeleme

## Kullanılan Yapılar

1. **Hasta Bilgileri**
   - Hasta kimliği (ID)
   - İsim ve soyisim
   - Yaş
   - Cinsiyet
   - İletişim bilgileri
   - Öncelik durumu (Acil/Orta/Düşük)
   - 11 haneli kimlik numarası (TC)

2. **Reçete Bilgileri**
   - Reçete numarası (6 haneli rastgele)
   - Hasta kimliği
   - İlaç adı
   - Miktar (Kutu sayısı)
   - Günlük doz
   - Tarih (GG/AA/YYYY)

## Nasıl Kullanılır

1. **Proje Dosyasını İndirin**
   - GitHub üzerinden projeyi indirin veya kopyalayın.

2. **Derleyin ve Çalıştırın**
   - Bir C derleyici (örneğin GCC) kullanarak programı derleyin: 
   - Derlenen dosyayı çalıştırın:

3. **Menü Seçeneklerini Kullanın**
   - Program açıldığında aşağıdaki menüyü göreceksiniz:
     ```
     Acil Servis Yonetim Sistemi
     1. Yeni Hasta Ekle
     2. Hastaları Listele
     3. Reçete Oluştur
     4. Reçeteleri Listele
     5. Çıkış
     ```
   - Belirtilen adımları takip ederek işlemlerinizi gerçekleştirebilirsiniz.

## Önemli Notlar

- **Rastgele Reçete Numarası:** Reçete numarası, 6 haneli rastgele bir sayı olarak atanır.
- **Kimlik Numarası Kontrolü:** Aynı kimlik numarasına sahip birden fazla hasta eklenemez.
- **Hasta ID Kontrolü:** Reçete eklerken geçerli bir hasta ID girilmelidir.

## Geliştirme Ortamı

- **Dil:** C
- **Geliştirici Araçları:** GCC derleyicisi
- **İşletim Sistemi:** Çoğu işletim sisteminde (Windows, Linux, MacOS) çalışır.
