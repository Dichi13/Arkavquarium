--Kelas Aquarium
Kelas yang merepresentasi aquarium
Kelas ini menyimpan ukuran aquarium dan objek-objek yang ada pada aquarium yaitu Guppy, Piranha, Koin, Pellet, dan Siput

--Kelas AquariumObject
Semua objek yang berada di aquarium, memiliki atribut koordinat objek dan kecepatan objek

--Kelas HewanAir
Kelas semua hewan air pada aquarium, memiliki atribut hadapan objek (kanan/kiri) dan arah yang dihadap
Memiliki method pursue untuk bergerak ke suatu objek (mengubah directionnya)
dan consume untuk "mengonsumsi" suatu objek lain (saat guppy makan pellet, piranha makan guppy, atau snail mengambil koin)

--Kelas Ikan
Kelas untuk representasi guppy dan piranha.
Memiliki atribut timer lapar dan mati.
Memiliki method untuk menjatuhkan koin dan bergerak acak.

--Kelas Guppy
Kelas Guppy merepresentasi guppy.
Memiliki atribut tahap pertumbuhan guppy, jumlah pellet yang sudah dimakan (untuk perubahan tahap), dan timer penjatuhan koin.
Memiliki method untuk menambahkan jumlah pellet yang sudah dimakan dengan overloading operator ++

--Kelas Piranha
Kelas Piranha merepresentasikan Piranha.
Memiliki method untuk menjatuhkan koin, untuk bergerak, untuk mengejar makanan, dan untuk memakan makanan.

--Kelas Siput
Kelas Siput merepresentasikan Siput.
Memiliki method untuk bergerak, untuk mengejar makanan ("makanan" siput adalah koin), dan memakan "makanan".

--Kelas Koin
Kelas Koin merepresentasikan koin yang dihasilkan oleh ikan.
Koin memiliki atribut nilai dari koin itu sendiri.
Memiliki method untuk bergerak (jatuh), dan getter-setter untuk atribut nilai.

--Kelas Pellet
Kelas Pellet merepresentasikan pakan ikan yang dimakan oleh guppy.

--Kelas List
Kelas List merepresentasikan linked list generik.
Atributnya berupa pointer yang menunjuk ke elemen pertama dari list.
Memiliki method-method dasar yang disebutkan di dalam spesifikasi, ditambah dengan operator overloading
untuk menambahkan elemen ke dalam list.

--Kelas ElmtList
Kelas yang merepresentasikan elemen dari list.
Memiliki atribut value (nilai) dari elemen list dan alamat ke elemen list berikutnya.