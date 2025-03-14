# Binary Search Tree dengan Linked List

Nama : Tasya Zahrani
NPM : 2308107010006
Mata Kuliah : Strktur Data dan Algoritma D

## Deskripsi
Program ini merupakan implementasi Binary Search Tree (BST) dengan Linked List untuk mengelompokkan kata-kata dalam sebuah file teks berdasarkan huruf awalnya. Kata-kata akan disusun dalam BST dengan setiap simpul menyimpan huruf pertama kata-kata tersebut. Kata-kata yang memiliki huruf awal yang sama akan disimpan dalam Linked List yang terhubung ke simpul BST.

## Struktur Folder
```
Tugas02/
│── bst.c                  
│── bst.exe                 
│── dbterms.txt        
│── README.md                
```

## Fitur Program
- Membaca file teks dan mengelompokkan kata berdasarkan huruf awalnya ke dalam BST dan Linked List.
- Menampilkan kata-kata berdasarkan huruf awal yang dimasukkan oleh pengguna.
- Menampilkan statistik jumlah kata berdasarkan huruf awalnya secara berurutan (ascending).
- Membebaskan semua memori yang digunakan agar tidak terjadi memory leak.

## Struktur Data yang Digunakan
- BSTNode: Menyimpan huruf awal, pointer ke Linked List, jumlah kata, dan pointer kiri/kanan BST.
- ListNode: Menyimpan kata dan baris tempat kata ditemukan dalam file.

## Catatan
- File teks dbterms.txt yang berisi daftar kata

Dapat juga dilihat di github melalui link berikut ini https://github.com/tasyazahrani/BinarySearchTree.git 

(c) 2025 - tasyazahrani
