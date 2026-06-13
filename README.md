# C Dilinde NDP Benzetimi ve Nüfus Simülasyonu

Bu proje, Sakarya Üniversitesi Bilgisayar Mühendisliği Programlama Dillerinin Prensipleri dersi kapsamında geliştirilmiştir. Projenin temel amacı, C programlama dilinde Nesne Yönelimli Programlama (NDP) kavramlarını (kalıtım, soyutlama, kurucu/yıkıcı metotlar ve `this` referansı) yapı (struct) ve fonksiyon göstericileri (function pointers) kullanılarak simüle etmektir.

## 📌 Proje Hakkında

Yazılım, başlangıçta kullanıcıdan alınan bir string dizisi (iki basamaklı sayılar) ve tur sayısı üzerinden çalışan hiyerarşik bir yerleşim simülasyonudur.

Verilen her iki basamaklı sayının:
- **Kendisi:** Şehrin başlangıç nüfusunu temsil eder.
- **Onlar Basamağı:** İlçe sayısını temsil eder.
- **Birler Basamağı:** Mahalle sayısını temsil eder.

### Temel Kurallar
1. Mahalle sayısı her ilçede eşit olacak şekilde dağıtılır.
2. Toplam nüfus her mahallede eşit olacak şekilde dağıtılır.
3. Simülasyonun her turunda kişiler 1 yıl yaşlanır ve şehir nüfusu belirli bir katsayıya göre artar.
4. Bir şehrin nüfusu 4 basamaklı sayılara (1000 ve üzeri) ulaştığında hiyerarşik bölünme algoritması devreye girer; ilçeler yeni şehirlere paylaştırılır ve fazlalık eski şehirde kalır.

---

## 🏗 Mimari ve Tasarım

Gerçek NDP dillerindeki modüler yapıyı C üzerinde sağlayabilmek için sistem altı ana klasörde organize edilmiştir:

- **`araclar/`**: Karmaşık hesaplamaları ve girdi işlemlerini yürüten yardımcı yapılar.
- **`main/`**: Programın giriş noktasını barındırır.
- **`modeller/`**: Veriyi tutan ve kendi iş mantığını (bölünme, nüfus artışı vb.) yöneten hiyerarşik nesneler (`Sehir`, `Ilce`, `Mahalle`, `Kisi`, `Yerlesim`).
- **`motor/`**: Ana oyun döngüsünün ve simülasyon mantığının koşturulduğu yöneticidir.
- **`servisler/`**: Oyun yapısının yükünü hafifleten ve modülerlik sağlayan alt servisler.
- **`Sahte Veri/`**: İsimlendirme atamaları için kullanılan, `java-faker` ile önceden üretilmiş veri dosyaları.

> **Not:** Dosya okuma işlemleri (I/O) maliyetli olduğu için `SahteVeriUretici` yalnızca programın başında bir kez başlatılır ve bellekten (RAM) rastgele okuma yapar. Simülasyon sonunda tüm tahsis edilen dinamik bellekler (heap) iade edilerek bellek sızıntıları (memory leak) önlenmiştir.

---

## ⚙️ Gereksinimler

- C Derleyicisi (GCC / MinGW önerilir)
  
---

## 🚀 Derleme ve Çalıştırma

Proje, derleme sürecini yönetmek etmek için bir `Makefile` içermektedir. Terminal üzerinden proje kök dizinine giderek aşağıdaki komutları kullanabilirsiniz.

### 1. Derleme
Projeyi derlemek ve nesne (`.o`) dosyalarını oluşturmak için:

```bash
mingw32-make derle
```
*Çıktılar `lib/` klasörüne, çalıştırılabilir dosya ise `bin/program.exe` yoluna kaydedilir.*

### 2. Çalıştırma
Derlenmiş projeyi başlatmak için:

```bash
mingw32-make calistir
```
*(Alternatif olarak doğrudan `./bin/program.exe` komutunu da kullanabilirsiniz.)*

### 3. Hızlı Başlatım
Projeyi tek bir komutla hem derleyip hem çalıştırmak isterseniz:

```bash
mingw32-make hepsi
```

---

## 👨‍💻 Geliştirici

**Ahmet Faruk İKİZ**
Sakarya Üniversitesi - Bilgisayar Mühendisliği (B241210040)
