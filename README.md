# **Canlılar Savaşı Simülasyonu**

**Sümeyye Karataş**  
B221210005 – 1.Öğretim B Grubu  

## **Özet**

Canlılar Savaşı Simülasyonu projesinde, canlılar arasındaki etkileşimleri görselleştirmek ve bir savaş ortamında nasıl davranacaklarını göstermek amaçlanmıştır. Projenin yaklaşımı, her canlı türünün belirli bir stratejiye sahip olduğu gerçekçi bir savaş ortamı oluşturmaktır. Bunun için, her canlı türünün savaş alanında nasıl hareket edeceğini, saldırı ve savunma stratejilerini ve diğer canlılarla olan etkileşimlerini modellemesi gerekmektedir. Bu modelleme süreci, dosya işlemleriyle okunan verilere dayanır ve çeşitli veri yapıları kullanılarak gerçekleştirilir. Projeyi gerçeklemek için C programlama dili kullanılmıştır.

**Anahtar Kelimeler**: canlı, savaş, etkileşim, simülasyon  

---

## **Geliştirilen Yazılım**

Proje, C programlama dilinde nesne yönelimli benzetme ve soyut benzetme yaklaşımları kullanılarak geliştirilmiştir. Geliştirme sürecinde, projenin gereksinimleri detaylı bir şekilde incelenmiş ve uygun algoritma oluşturulmuştur. Algoritmanın uygulanması için adım adım bir plan oluşturulmuştur. Raporun bu bölümünde adımların her biri detaylı bir şekilde ele alınacaktır. C dilinde nesne yönelimli benzetme yapıldığı için sınıf vb. terimler kullanılmıştır.

### **Algoritma Gerçekleme Adımları**

#### **1.1.1 Kalıtım Hiyerarşisine Uygun Canlı Türlerinin Oluşturulması**

Projede istenilen kalıtım hiyerarşisi dikkate alınarak, öncelikle "Canli" sınıfı oluşturuldu. "Canli" sınıfından kalıtım alan "Bocek" ve "Bitki" sınıfları tanımlanmıştır. "Sinek" ve "Pire" ise "Bocek" sınıfından kalıtım alarak türetilmiştir.

#### **1.1.2 İşlem Yapmak İçin Matrislerin Oluşturulması**

Canlı türleri tanımlandıktan sonra işlemleri gerçekleştirmek için iki matris oluşturuldu. İlk matris, ".txt" uzantılı dosyadaki sayısal verilerin okunmasıyla elde edilmiştir. Bu matris kullanılarak belirli değer aralıklarına göre canlı türleri belirlenmiş ve bu türlerinin yazımında kullanılan harflerle karakter matrisi oluşturulmuştur.

#### **1.1.3 Matrislerden Üzerinde Canlıların Oluşturulması ve Savaş Alanı**

Canlı türlerinin savaşması için matris üzerinde iç içe döngüler kullanılarak savaş alanında dolaşılır. Her adımda, kazanan belirlenir ve ilgili canlıların işlevleri çağrılır. Karakter matrisinde kazanan ve kaybedenler her adımda güncellenir.

#### **1.1.4 Sonuç Yazdırma**

İşlemler sonucunda kazanan belirlenir ve sonuçlar ekrana yazdırılırken, karakter matrisinde "X" olmayan canlı ve konumu belirtilir.

### **Algoritma Akış Şeması**

![image](https://github.com/user-attachments/assets/78d04133-f8d2-468f-8d62-a394cff1b197)

### **Sınıflar ve Açıklamaları**

#### **1.3.1 Canli.h / Canli.c**

"Canli" yapısında, her bir canlının türünü belirtmek için enum yapısında "CanliTuru" oluşturuldu. Ayrıca her bir canlının konumunu belirlemek için struct tipinde "Konum" değişkeni oluşturuldu. Bütün canlı türlerinin kullanabileceği karakter matrisini yazdırmak için "gorunum" fonksiyonu, canlı nesneleri serbest bırakmak için "delete_Canli" fonksiyonu, yeni canlı nesneleri oluşturmak için "new_Canli" ve canlının türüne göre içeriğin değişeceği soyut "yemek" fonksiyonu tanımlanmıştır.  

Bu yapı, proje içerisinde farklı canlı türlerinin ortak özelliklerini ve işlevlerini kapsamak üzere tasarlanmıştır. "Canli" sınıfı, projenin temel yapı taşını oluşturarak kodun modülerliğini artırmayı hedeflemektedir.

#### **1.3.2 Bitki.h / Bitki.c**

Bitki yapısı, projede bitki türlerini temsil etmek için kullanılır. Her bir bitki nesnesi, belirli bir konumda bulunur ve özel davranışlar sergiler. new_Bitki fonksiyonu, bir bitki nesnesi oluşturur ve ilgili fonksiyon işaretçilerini atan konum bilgisine dayanarak başlatır. yemek_Bitki fonksiyonu, bir bitkinin yemek alışkanlığını modellemektedir. Bu fonksiyon, matris üzerindeki belirli birimleri kontrol eder ve bitkinin davranışını günceller. Örneğin, bir böcek tarafından yenildiğinde, bitkinin türünü değiştirir ve matris üzerinde ilgili karakterleri günceller. delete_Bitki fonksiyonu, bir bitki nesnesini bellekten temizler ve ona ait kaynakları serbest bırakır.  

Tüm bu yapı ve fonksiyonlar, bitki türlerini etkili bir şekilde modeller ve davranışlarını temsil eder.

#### **1.3.3 Bocek.h / Bocek.c**

“Bocek” yapısı, projenin içerisindeki böcek türlerini modeller. Her bir Bocek nesnesi, bir konuma sahip olup, belirli davranışları gerçekleştirebilir. new_Bocek fonksiyonu, bir böcek nesnesi oluştururken, verilen konum bilgisini kullanarak bu nesneyi başlatır. Ayrıca, bu nesneye ait olan diğer fonksiyonları ilgili işaretçilere atanır. yemek_Bocek fonksiyonu, bir böceğin yemek davranışını simüle eder. Bu fonksiyon, matris üzerinde belirli birimleri kontrol eder ve böceğin yemek tercihlerine göre davranışını günceller. Son olarak, delete_Bocek fonksiyonu, bir böcek nesnesini bellekten temizler. Bu işlev, böcek nesnesinin yanı sıra ona ait olan diğer kaynakları da serbest bırakır. Tüm bu yapı ve fonksiyonlar, projenin böcek türlerini modelleyerek, bunların özelliklerini ve davranışlarını temsil eder.

#### **1.3.3 Sinek.h / Sinek.c**

“Sinek” yapısı, böcek türlerini temsil eder ve bu türlerin özelliklerini ifade eder. Her bir Sinek örneği, bir böcekten kalıtım alır ve belirli bir konumda bulunur. new_Sinek fonksiyonu, verilen konum bilgisine dayanarak bir sinek nesnesi oluşturur ve ilgili fonksiyon işaretçilerini atanır. yemek_Sinek fonksiyonu, sineklerin beslenme alışkanlıklarını simüle eder ve matris üzerindeki belirli elemanları kontrol eder. delete_Sinek fonksiyonu, bir sinek nesnesini bellekten temizler ve ona ait kaynakları serbest bırakır.

#### **1.3.3 Pire.h / Pire.c**

Pire yapısı, böcek türlerini temsil eder ve bu türlerin özelliklerini içerir. Her bir Pire örneği, bir böcekten kalıtım alır ve belirli bir konumda bulunur. new_Pire fonksiyonu, verilen konum bilgisine dayanarak bir pire nesnesi oluşturur ve ilgili fonksiyon işaretçilerini atar. yemek_Pire fonksiyonu, pirelerin beslenme alışkanlıklarını simüle eder ve matris üzerindeki belirli elemanları kontrol eder. delete_Pire fonksiyonu, bir pire nesnesini bellekten temizler ve ona ait kaynakları serbest bırakır.

---

## **Çıktılar**

Yazılımın çıktıları, farklı senaryoların simülasyonuyla elde edildi. Her bir canlı türünün etkileşimi detaylı bir şekilde incelendi. Özellikle, bitki, böcek, sinek ve pire türlerinin birbirleriyle olan etkileşimleri farklı verilerle simüle edildi ve sonuçlar karşılaştırıldı. Bu sayede yazılımın her durumda nasıl tepki verdiği ve farklı girdi koşullarında nasıl davrandığı detaylı bir şekilde analiz edildi.

---

## **Sonuç**

Bu çalışma, canlı türlerinin etkileşimlerini modelleyen bir yazılımın başarılı bir şekilde geliştirilmesini sağlamıştır. Farklı canlı türlerinin birbirleriyle olan ilişkileri simüle edilmiş ve bu simülasyonlar başarılı sonuçlar vermiştir. Bu yazılım, biyolojik sistemlerin anlaşılmasına katkı sağlayarak çeşitli alanlarda kullanılabilir. Özellikle biyoloji, çevre bilimleri ve tarım gibi alanlarda bu çalışmanın sonuçlarından faydalanılabilir. Bu bağlamda, yazılımın gerçek hayattaki çeşitli problemlere çözüm üretebilecek potansiyeli bulunmaktadır.
