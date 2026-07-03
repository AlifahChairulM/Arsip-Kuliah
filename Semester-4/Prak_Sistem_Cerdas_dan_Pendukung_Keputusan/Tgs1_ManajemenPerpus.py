# 123240234_AlifahChairulMunawar_PSCPK_IF-I
#REVISI 
# 1. FUNGSI TOTAL BUKU? X  
# 2. tekan untuk lanjut only enter(ini bisa angka)X
# 3. undonya otomatis? ga bisa milih?X
# 4. pahami kode tambahkan detail komen di edit, hapus, undoX
# 5. sorting yg dah diinput

daftar_buku = []
history_undo = []  # Stack untuk undo

#ben judul e rapi
def tampilkan_header(judul):
    print("=" * 35)
    print(judul)
    print("=" * 35)

# lanjut fitur
def lanjut_fitur():
    input("\nTekan Enter untuk melanjutkan...")  #apa aja, tetap lanjut

#FITURtambah buku
def tambah_buku():
    tampilkan_header("TAMBAH BUKU")
    
    # sek perlu input data buku
    id_buku = input("ID Buku\t\t: ")
    nama_buku = input("Nama Buku\t: ")
    nama_penulis = input("Nama Penulis\t: ")
    kategori = input("Kategori Buku\t: ")
    penerbit = input("Penerbit\t: ")
    
    # Cek ID sudah terdaftar blm? (Asik dapet Bonus yahuuuu)
    id_terdaftar = False
    for buku in daftar_buku:
        if buku['id'] == id_buku:
            id_terdaftar = True # klo nemu langsung stop
            break
    
    if id_terdaftar: #biar ga double yak klo dah ada id ga iso ditambah
        print("\n ID Buku sudah terdaftar! Silahkan input ID lain.")
    else:
        # siimpan data buku
        buku_baru = {
            'id': id_buku,
            'nama': nama_buku,
            'penulis': nama_penulis,
            'kategori': kategori,
            'penerbit': penerbit
        }
        
        daftar_buku.append(buku_baru) #tambah daftar baru
        print("\nBuku berhasil ditambahkan!")
    
    lanjut_fitur()

#FITUR lihat buku
def lihat_buku():
    tampilkan_header("DAFTAR BUKU PERPUSTAKAAN")
    
    if len(daftar_buku) == 0: #cek ada buku ndak
        print("\nTidak ada buku dalam perpustakaan.")
    else:
        print("\n" + "=" * 80) #ben tabel e rapi
        print(f"{'ID':<10} {'Nama Buku':<20} {'Penulis':<15} {'Kategori':<15} {'Penerbit':<15}")
        print("=" * 80)
        
        for buku in daftar_buku: # cari id sesuai 
            print(f"{buku['id']:<10} {buku['nama']:<20} {buku['penulis']:<15} {buku['kategori']:<15} {buku['penerbit']:<15}")
                   
        print("=" * 80)
        print(f"Total buku: {len(daftar_buku)}")
    
    lanjut_fitur()

#fITUR cari buku
def cari_buku():
    tampilkan_header("CARI BUKU")
    
    if len(daftar_buku) == 0: #kada buku ndak?
        print("\nTidak ada buku dalam perpustakaan.")
        lanjut_fitur()
        return
    
    kata_kunci = input("Masukkan nama buku yang dicari: ").lower() #tak ubah kecil all ben gampang cari
    
    # penampung hasil cari buku 
    hasil_cari = []
    for buku in daftar_buku:
        if kata_kunci in buku['nama'].lower():
            hasil_cari.append(buku) # selama ada kata kunci dia muncul
    
    if len(hasil_cari) > 0:
        print(f"\nDitemukan {len(hasil_cari)} buku:")  #nemu di tampilin di tabel yak
        print("=" * 80)
        print(f"{'ID':<10} {'Nama Buku':<20} {'Penulis':<15} {'Kategori':<15} {'Penerbit':<15}")
        print("=" * 80)
        
        for buku in hasil_cari:
            print(f"{buku['id']:<10} {buku['nama']:<20} {buku['penulis']:<15} {buku['kategori']:<15} {buku['penerbit']:<15}")
    else:
        print(f"\nBuku dengan nama '{kata_kunci}' tidak ditemukan.") # klo ga nemu
    
    lanjut_fitur()

#FITUR apus buku
def hapus_buku():
    tampilkan_header("HAPUS BUKU")
    
    if not daftar_buku:
        print("\n Tidak ada buku dalam perpustakaan.")
        lanjut_fitur()
        return
    
    print("\nDaftar ID Buku yang tersedia:")
    for buku in daftar_buku: # nampilin id yg ada dulu
        print(f"- {buku['id']}: {buku['nama']}")
    
    id_hapus = input("\nMasukkan ID Buku yang akan dihapus: ")
    
    for i in range(len(daftar_buku)):
        if daftar_buku[i]['id'] == id_hapus:
            buku_terhapus = daftar_buku.pop(i)
            
            # SIMPAN KE HISTORY (FITUR UNDO)
            simpan_history('hapus', buku_terhapus, i)
            
            print(f"\nBuku '{buku_terhapus['nama']}' berhasil dihapus!")
            print("Gunakan menu UNDO untuk mengembalikan")
            lanjut_fitur()
            return
    
    print(f"\n Buku dengan ID {id_hapus} tidak ditemukan.")
    lanjut_fitur()

#pendukung edit buku
def simpan_history(tipe, data, index=None, sebelum=None):
    history_undo.append({
        'tipe': tipe,
        'data': data,
        'index': index,
        'sebelum': sebelum
    })

#FITUR edit buku
def edit_buku():
    tampilkan_header("EDIT BUKU")
    
    # Cek apakah ada buku
    if not daftar_buku:
        print("\nBelum ada buku yang bisa di edit (Daftar buku kosong).")
        lanjut_fitur()
        return
    
    # Tampilin daftar ID biar user tau
    print("\nDaftar ID Buku:")
    for buku in daftar_buku:
        print(f"   - {buku['id']}: {buku['nama']}")
    
    id_edit = input("\nMasukkan ID Buku yang mau diedit: ")
    
    # Cari buku berdasarkan ID
    for i in range(len(daftar_buku)):
        if daftar_buku[i]['id'] == id_edit:
            # Simpen data lama buat history (copy biar ga keubah)
            data_lama = daftar_buku[i].copy()
            
            print("\nData saat ini:")
            print(f"   ID      : {daftar_buku[i]['id']}")
            print(f"   Judul   : {daftar_buku[i]['nama']}")
            print(f"   Penulis : {daftar_buku[i]['penulis']}")
            print(f"   Kategori: {daftar_buku[i]['kategori']}")
            print(f"   Penerbit: {daftar_buku[i]['penerbit']}")
            
            print("\nMasukkan data baru (Enter aja kalo ga diubah):")
            
            # Input data baru 
            id_baru = input(f"ID Baru [{daftar_buku[i]['id']}]: ").strip()
            nama_baru = input(f"Judul Baru [{daftar_buku[i]['nama']}]: ").strip()
            penulis_baru = input(f"Penulis Baru [{daftar_buku[i]['penulis']}]: ").strip()
            kategori_baru = input(f"Kategori Baru [{daftar_buku[i]['kategori']}]: ").strip()
            penerbit_baru = input(f"Penerbit Baru [{daftar_buku[i]['penerbit']}]: ").strip()
            
            # Cek ID baru kalo diisi biar ga dobel
            if id_baru and id_baru != data_lama['id']:
                for buku in daftar_buku:
                    if buku['id'] == id_baru and buku != daftar_buku[i]:
                        print("\nID udah dipake buku lain!")
                        lanjut_fitur()
                        return
            
            # Update data klo dah input
            if id_baru:
                daftar_buku[i]['id'] = id_baru
            if nama_baru:
                daftar_buku[i]['nama'] = nama_baru
            if penulis_baru:
                daftar_buku[i]['penulis'] = penulis_baru
            if kategori_baru:
                daftar_buku[i]['kategori'] = kategori_baru
            if penerbit_baru:
                daftar_buku[i]['penerbit'] = penerbit_baru
            
            # Simpen ke history undo
            simpan_history('edit', daftar_buku[i].copy(), i, data_lama)
            
            print("\nBuku berhasil diedit!")
            lanjut_fitur()
            return
    
    # Kalo ID ga ketemu
    print(f"\nBuku dengan ID {id_edit} ga ketemu.")
    lanjut_fitur()


#FITUR undo
def undo():
    tampilkan_header("UNDO")
    
    # Cek apa ada yang bisa di-undo
    if not history_undo:
        print("Belum ada data buku yang bisa di-undo (Daftar buku kosong).")
        lanjut_fitur()
        return
    
    #history dipisah sesuai tipe
    history_hapus = [h for h in history_undo if h['tipe'] == 'hapus']
    history_edit = [h for h in history_undo if h['tipe'] == 'edit']
    
    print("\n Pilih jenis undo:")
    if history_hapus:
        print(f"   1. Undo HAPUS buku ({len(history_hapus)} operasi)")
    else:
        print("   1. Undo HAPUS buku (Tidak ada)")
    
    if history_edit:
        print(f"   2. Undo EDIT buku ({len(history_edit)} operasi)")
    else:
        print("   2. Undo EDIT buku (Tidak ada)")
    print("   0. Batal")
    
    pilihan = input("\nPilih jenis undo (0/1/2): ").strip()
    
    if pilihan == '0':
        print("\n⏭Undo dibatalkan.")
        lanjut_fitur()
        return
    
    elif pilihan == '1':
        if not history_hapus:
            print("\nTidak ada operasi hapus yang bisa di-undo.")
            lanjut_fitur()
            return
        
        # Cari operasi hapus terakhir di history_undo asli
        for i in range(len(history_undo)-1, -1, -1):
            if history_undo[i]['tipe'] == 'hapus':
                operasi = history_undo.pop(i)
                
                # Kembalikan buku
                daftar_buku.insert(operasi['index'], operasi['data'])
                print(f"\nBuku '{operasi['data']['nama']}' berhasil dikembalikan!")
                break
    
    elif pilihan == '2':
        if not history_edit:
            print("\nTidak ada operasi edit yang bisa di-undo.")
            lanjut_fitur()
            return
        
        # Cari operasi edit terakhir di history_undo asli
        for i in range(len(history_undo)-1, -1, -1):
            if history_undo[i]['tipe'] == 'edit':
                operasi = history_undo.pop(i)
                
                # Kembalikan ke data sebelum edit
                daftar_buku[operasi['index']] = operasi['sebelum']
                print(f"\nEdit buku '{operasi['sebelum']['nama']}' dibatalkan!")
                break
    
    else:
        print("\nPilihan tidak valid!")
    
    print(f"\n   Sisa operasi yang bisa di-undo: {len(history_undo)}")
    lanjut_fitur()

#FITUR opsi
def menu_utama():
    while True:
        tampilkan_header("PERPUSTAKAAN ALIP". center(35))
        print("1. Tambah Buku")
        print("2. Lihat Daftar Buku")
        print("3. Cari Buku")
        print("4. Hapus Buku")
        print("5. Edit Buku")  
        print("6. Undo (edit / hapus)")      
        print("7. Keluar") 
        print("=" * 35)
        
        if len(daftar_buku) > 0:
            print(f"\nTotal buku: {len(daftar_buku)}")

        pilihan = input("Pilih menu (1-7): ")
        
        if pilihan == '1':
            tambah_buku()
        elif pilihan == '2':
            lihat_buku()
        elif pilihan == '3':
            cari_buku()
        elif pilihan == '4':
            hapus_buku()
        elif pilihan == '5':
            edit_buku()
        elif pilihan == '6':
            undo()
        elif pilihan == '7':
            print("\nMatur Thankyou telah menggunakan program ini")
            print("=" * 35)
            break

# Menjalankan program
if __name__ == "__main__":
    menu_utama()
daftar_buku = []
history_undo = []  # Stack untuk undo

#ben judul e rapi
def tampilkan_header(judul):
    print("=" * 35)
    print(judul)
    print("=" * 35)

# lanjut fitur
def lanjut_fitur():
    input("\nTekan Enter untuk melanjutkan...")  #apa aja, tetap lanjut

#FITURtambah buku
def tambah_buku():
    tampilkan_header("TAMBAH BUKU")
    
    # sek perlu input data buku
    id_buku = input("ID Buku\t\t: ")
    nama_buku = input("Nama Buku\t: ")
    nama_penulis = input("Nama Penulis\t: ")
    kategori = input("Kategori Buku\t: ")
    penerbit = input("Penerbit\t: ")
    
    # Cek ID sudah terdaftar blm? (Asik dapet Bonus yahuuuu)
    id_terdaftar = False
    for buku in daftar_buku:
        if buku['id'] == id_buku:
            id_terdaftar = True # klo nemu langsung stop
            break
    
    if id_terdaftar: #biar ga double yak klo dah ada id ga iso ditambah
        print("\n ID Buku sudah terdaftar! Silahkan input ID lain.")
    else:
        # siimpan data buku
        buku_baru = {
            'id': id_buku,
            'nama': nama_buku,
            'penulis': nama_penulis,
            'kategori': kategori,
            'penerbit': penerbit
        }
        
        daftar_buku.append(buku_baru) #tambah daftar baru
        print("\nBuku berhasil ditambahkan!")
    
    lanjut_fitur()

#FITUR lihat buku
def lihat_buku():
    tampilkan_header("DAFTAR BUKU PERPUSTAKAAN")
    
    if len(daftar_buku) == 0: #cek ada buku ndak
        print("\nTidak ada buku dalam perpustakaan.")
    else:
        print("\n" + "=" * 80) #ben tabel e rapi
        print(f"{'ID':<10} {'Nama Buku':<20} {'Penulis':<15} {'Kategori':<15} {'Penerbit':<15}")
        print("=" * 80)
        
        for buku in daftar_buku: # cari id sesuai 
            print(f"{buku['id']:<10} {buku['nama']:<20} {buku['penulis']:<15} {buku['kategori']:<15} {buku['penerbit']:<15}")
                   
        print("=" * 80)
        print(f"Total buku: {len(daftar_buku)}")
    
    lanjut_fitur()

#fITUR cari buku
def cari_buku():
    tampilkan_header("CARI BUKU")
    
    if len(daftar_buku) == 0: #kada buku ndak?
        print("\nTidak ada buku dalam perpustakaan.")
        lanjut_fitur()
        return
    
    kata_kunci = input("Masukkan nama buku yang dicari: ").lower() #tak ubah kecil all ben gampang cari
    
    # penampung hasil cari buku 
    hasil_cari = []
    for buku in daftar_buku:
        if kata_kunci in buku['nama'].lower():
            hasil_cari.append(buku) # selama ada kata kunci dia muncul
    
    if len(hasil_cari) > 0:
        print(f"\nDitemukan {len(hasil_cari)} buku:")  #nemu di tampilin di tabel yak
        print("=" * 80)
        print(f"{'ID':<10} {'Nama Buku':<20} {'Penulis':<15} {'Kategori':<15} {'Penerbit':<15}")
        print("=" * 80)
        
        for buku in hasil_cari:
            print(f"{buku['id']:<10} {buku['nama']:<20} {buku['penulis']:<15} {buku['kategori']:<15} {buku['penerbit']:<15}")
    else:
        print(f"\nBuku dengan nama '{kata_kunci}' tidak ditemukan.") # klo ga nemu
    
    lanjut_fitur()

#FITUR apus buku
def hapus_buku():
    tampilkan_header("HAPUS BUKU")
    
    if not daftar_buku:
        print("\n Tidak ada buku dalam perpustakaan.")
        lanjut_fitur()
        return
    
    print("\nDaftar ID Buku yang tersedia:")
    for buku in daftar_buku: # nampilin id yg ada dulu
        print(f"- {buku['id']}: {buku['nama']}")
    
    id_hapus = input("\nMasukkan ID Buku yang akan dihapus: ")
    
    for i in range(len(daftar_buku)):
        if daftar_buku[i]['id'] == id_hapus:
            buku_terhapus = daftar_buku.pop(i)
            
            # SIMPAN KE HISTORY (FITUR UNDO)
            simpan_history('hapus', buku_terhapus, i)
            
            print(f"\nBuku '{buku_terhapus['nama']}' berhasil dihapus!")
            print("Gunakan menu UNDO untuk mengembalikan")
            lanjut_fitur()
            return
    
    print(f"\n Buku dengan ID {id_hapus} tidak ditemukan.")
    lanjut_fitur()

#pendukung edit buku
def simpan_history(tipe, data, index=None, sebelum=None):
    history_undo.append({
        'tipe': tipe,
        'data': data,
        'index': index,
        'sebelum': sebelum
    })

#FITUR edit buku
def edit_buku():
    tampilkan_header("EDIT BUKU")
    
    # Cek apakah ada buku
    if not daftar_buku:
        print("\nBelum ada buku yang bisa di edit (Daftar buku kosong).")
        lanjut_fitur()
        return
    
    # Tampilin daftar ID biar user tau
    print("\nDaftar ID Buku:")
    for buku in daftar_buku:
        print(f"   - {buku['id']}: {buku['nama']}")
    
    id_edit = input("\nMasukkan ID Buku yang mau diedit: ")
    
    # Cari buku berdasarkan ID
    for i in range(len(daftar_buku)):
        if daftar_buku[i]['id'] == id_edit:
            # Simpen data lama buat history (copy biar ga keubah)
            data_lama = daftar_buku[i].copy()
            
            print("\nData saat ini:")
            print(f"   ID      : {daftar_buku[i]['id']}")
            print(f"   Judul   : {daftar_buku[i]['nama']}")
            print(f"   Penulis : {daftar_buku[i]['penulis']}")
            print(f"   Kategori: {daftar_buku[i]['kategori']}")
            print(f"   Penerbit: {daftar_buku[i]['penerbit']}")
            
            print("\nMasukkan data baru (Enter aja kalo ga diubah):")
            
            # Input data baru 
            id_baru = input(f"ID Baru [{daftar_buku[i]['id']}]: ").strip()
            nama_baru = input(f"Judul Baru [{daftar_buku[i]['nama']}]: ").strip()
            penulis_baru = input(f"Penulis Baru [{daftar_buku[i]['penulis']}]: ").strip()
            kategori_baru = input(f"Kategori Baru [{daftar_buku[i]['kategori']}]: ").strip()
            penerbit_baru = input(f"Penerbit Baru [{daftar_buku[i]['penerbit']}]: ").strip()
            
            # Cek ID baru kalo diisi biar ga dobel
            if id_baru and id_baru != data_lama['id']:
                for buku in daftar_buku:
                    if buku['id'] == id_baru and buku != daftar_buku[i]:
                        print("\nID udah dipake buku lain!")
                        lanjut_fitur()
                        return
            
            # Update data klo dah input
            if id_baru:
                daftar_buku[i]['id'] = id_baru
            if nama_baru:
                daftar_buku[i]['nama'] = nama_baru
            if penulis_baru:
                daftar_buku[i]['penulis'] = penulis_baru
            if kategori_baru:
                daftar_buku[i]['kategori'] = kategori_baru
            if penerbit_baru:
                daftar_buku[i]['penerbit'] = penerbit_baru
            
            # Simpen ke history undo
            simpan_history('edit', daftar_buku[i].copy(), i, data_lama)
            
            print("\nBuku berhasil diedit!")
            lanjut_fitur()
            return
    
    # Kalo ID ga ketemu
    print(f"\nBuku dengan ID {id_edit} ga ketemu.")
    lanjut_fitur()


#FITUR undo
def undo():
    tampilkan_header("UNDO")
    
    # Cek apa ada yang bisa di-undo
    if not history_undo:
        print("Belum ada data buku yang bisa di-undo (Daftar buku kosong).")
        lanjut_fitur()
        return
    
    #history dipisah sesuai tipe
    history_hapus = [h for h in history_undo if h['tipe'] == 'hapus']
    history_edit = [h for h in history_undo if h['tipe'] == 'edit']
    
    print("\n Pilih jenis undo:")
    if history_hapus:
        print(f"   1. Undo HAPUS buku ({len(history_hapus)} operasi)")
    else:
        print("   1. Undo HAPUS buku (Tidak ada)")
    
    if history_edit:
        print(f"   2. Undo EDIT buku ({len(history_edit)} operasi)")
    else:
        print("   2. Undo EDIT buku (Tidak ada)")
    print("   0. Batal")
    
    pilihan = input("\nPilih jenis undo (0/1/2): ").strip()
    
    if pilihan == '0':
        print("\n⏭Undo dibatalkan.")
        lanjut_fitur()
        return
    
    elif pilihan == '1':
        if not history_hapus:
            print("\nTidak ada operasi hapus yang bisa di-undo.")
            lanjut_fitur()
            return
        
        # Cari operasi hapus terakhir di history_undo asli
        for i in range(len(history_undo)-1, -1, -1):
            if history_undo[i]['tipe'] == 'hapus':
                operasi = history_undo.pop(i)
                
                # Kembalikan buku
                daftar_buku.insert(operasi['index'], operasi['data'])
                print(f"\nBuku '{operasi['data']['nama']}' berhasil dikembalikan!")
                break
    
    elif pilihan == '2':
        if not history_edit:
            print("\nTidak ada operasi edit yang bisa di-undo.")
            lanjut_fitur()
            return
        
        # Cari operasi edit terakhir di history_undo asli
        for i in range(len(history_undo)-1, -1, -1):
            if history_undo[i]['tipe'] == 'edit':
                operasi = history_undo.pop(i)
                
                # Kembalikan ke data sebelum edit
                daftar_buku[operasi['index']] = operasi['sebelum']
                print(f"\nEdit buku '{operasi['sebelum']['nama']}' dibatalkan!")
                break
    
    else:
        print("\nPilihan tidak valid!")
    
    print(f"\n   Sisa operasi yang bisa di-undo: {len(history_undo)}")
    lanjut_fitur()

#FITUR opsi
def menu_utama():
    while True:
        tampilkan_header("PERPUSTAKAAN ALIP". center(35))
        print("1. Tambah Buku")
        print("2. Lihat Daftar Buku")
        print("3. Cari Buku")
        print("4. Hapus Buku")
        print("5. Edit Buku")  
        print("6. Undo (edit / hapus)")      
        print("7. Keluar") 
        print("=" * 35)
        
        if len(daftar_buku) > 0:
            print(f"\nTotal buku: {len(daftar_buku)}")

        pilihan = input("Pilih menu (1-7): ")
        
        if pilihan == '1':
            tambah_buku()
        elif pilihan == '2':
            lihat_buku()
        elif pilihan == '3':
            cari_buku()
        elif pilihan == '4':
            hapus_buku()
        elif pilihan == '5':
            edit_buku()
        elif pilihan == '6':
            undo()
        elif pilihan == '7':
            print("\nMatur Thankyou telah menggunakan program ini")
            print("=" * 35)
            break

# Menjalankan program
if __name__ == "__main__":
    menu_utama()