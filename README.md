# مشروع إدارة القوائم والأشكال (C++)  
## Multi-List ASCII Shape Manager (C++)

---

# 🇦🇪 القسم العربي

## 📘 وصف المشروع

هذا المشروع عبارة عن تطبيق يعمل على سطر الأوامر (Console) بلغة ++C،  
ويستخدم **قوائم مرتبطة (Linked Lists)** بدون أي هياكل بيانات جاهزة مثل `vector` أو `list`.

يقدّم البرنامج:

- قائمة رئيسية تحتوي على عدة "عُقد" (Lists) تظهر على جهة اليسار.
- كل عُقدة تحتوي على **قائمة أشكال** (مثلث، مستطيل، نجمة).
- على الجهة اليمنى يتم رسم الأشكال باستخدام ASCII داخل مصفوفة شاشة.
- يدعم وضعين:
  - **وضع القوائم**: التنقّل بين القوائم، حذف قائمة، الدخول لوضع الأشكال.
  - **وضع الأشكال**: التنقّل بين الأشكال، تحريك الشكل، حذف شكل.

كما يمكن:

- تحميل البيانات من ملف `veri.txt`
- أو إنشاء أشكال عشوائية عند بدء التطبيق
- حفظ كل التغييرات في ملف `veri.txt` عند الخروج

---

## 🎯 ميزات المشروع

- تطبيق كامل بدون أي STL Containers.
- قوائم مرتبطة يدوياً (Linked Lists).
- أشكال ASCII:
  - Triangle
  - Rectangle
  - Star
- دعم تحريك الأشكال داخل الشاشة.
- دعم اختيار الشكل التالي/السابق.
- حذف القوائم أو الأشكال.
- حفظ تلقائي على ملف نصي.

---

## ⌨️ التحكم عبر لوحة المفاتيح

### 🟦 وضع القوائم (List Mode)

```
w → للأعلى  
s → للأسفل  
f → الدخول إلى أول شكل داخل القائمة  
c → حذف القائمة  
x → خروج وحفظ  
```

---

### 🟩 وضع الأشكال (Shape Mode)

```
a → تحريك الشكل يسار  
d → تحريك الشكل يمين  
w → للأعلى  
s → للأسفل  
q → الشكل السابق  
e → الشكل التالي  
c → حذف الشكل  
g → العودة لوضع القوائم  
x → خروج وحفظ  
```

يتم تمييز الشكل النشط بعلامة `@`.

---

## 📂 هيكلية الملفات

```
include/
src/
lib/
bin/
veri.txt
makefile
README.md
```

---

## 🛠️ أوامر الترجمة والتشغيل

```
mingw32-make
```

تشغيل:

```
mingw32-make run
```

---

# 🇬🇧 English Section

## 📘 Project Description

This project is a **Console-based ASCII Shape Manager** written in C++  
using fully manual **Linked Lists**, with **no STL containers** allowed.

The program includes:

- A **main list** displayed on the left side of the console.
- Each list node contains its own **shape list**.
- Shapes (Triangle, Rectangle, Star) are drawn as ASCII characters on the right side.
- Two working modes:
  - **List Mode:** Navigate lists, delete a list, enter shape mode.
  - **Shape Mode:** Navigate shapes, move shapes, delete shapes.

The program can:

- Load data from `veri.txt`.
- Or generate random shapes at startup.
- Save all changes back to `veri.txt` on exit.

---

## 🎯 Features

- No STL (vector/list) used.
- Fully manual Linked Lists.
- ASCII Shapes:
  - Triangle  
  - Rectangle  
  - Star  
- Move shapes on screen.
- Navigate previous/next shapes.
- Delete shapes or entire lists.
- Auto Save to text file.

---

## ⌨️ Keyboard Controls

### 🟦 List Mode

```
w → up  
s → down  
f → enter shape mode  
c → delete list  
x → exit & save  
```

### 🟩 Shape Mode

```
a → move left  
d → move right  
w → move up  
s → move down  
q → previous shape  
e → next shape  
c → delete shape  
g → return to list mode  
x → exit & save  
```

Active shape is marked with `@`.

---

## 📂 Project Structure

```
include/
src/
lib/
bin/
veri.txt
makefile
README.md
```

---

## 🛠️ Build & Run

Build:

```
mingw32-make
```

Run:

```
mingw32-make run
```

---

#
