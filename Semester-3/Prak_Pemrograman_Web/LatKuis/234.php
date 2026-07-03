//123240234
//php jaya yeah
<?php
if ($_POST) {
    $nama = $_POST['nama'];
    $email = $_POST['email'];
    $paket = $_POST['paket'];
    
    echo "<h1>Pendaftaran Berhasil!</h1>";
    echo "<p>Nama: $nama</p>";
    echo "<p>Email: $email</p>"; 
    echo "<p>Paket: $paket</p>";
    echo "<a href='234.html'>Kembali</a>";
}
?>

<!--HTML punya -->

<!DOCTYPE html>
<html lang="id">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Form Pendaftaran Bimbel</title>
  <link rel="stylesheet" href="234.css">
</head>
<body>

<!----------------- SIGN IN ------------------->
<div class="container" id="container"> 
    <div class="form-container sign-in"> 
        <form id="loginForm">
            <h1>BIMBEL JAYAMAHE</h1> 
            <input type="text" placeholder="Name" id="loginName" required>
            <input type="email" placeholder="Email" id="loginEmail" required>
            <a href="#" id="clearLoginInput">Click to clear the name and email</a>
            <button type="submit">Sign In</button>
        </form>
    </div>

    <div class="toggle-container"> 
        <div class="toggle">
            <div class="toggle-panel toggle-right">
                <h2>Selamat Datang</h2><br>
                <p>Silahkan buat akun terlebih dahulu untuk masuk</p> <br>
            </div>
        </div>
    </div>
</div> 

<!----------------- FORM PENDAFTARAN ----------------->
<div class="container" id="formContainer" style="display:none;"> <!--sembunyikan form sebelum sign in--> 
    <h1>Form Pendaftaran Bimbingan Belajar</h1>
    <form id="formPendaftaran" method="POST" action="process.php"> <!--register form
  
      <!-- Nama -->
      <label for="nama"><b>Nama Lengkap <span class="wajib">*</span></b></label> <!-- tanda bintang wajib diisi -->
      <input type="text" id="nama" name="nama" required>
      
      <!-- Email -->
      <label for="email"><b>Email <span class="wajib">*</span></b></label>
      <input type="email" id="email" name="email" required>
      
      <!-- Tanggal Pendaftaran -->
      <label for="tanggal"><b>Tanggal Pendaftaran <span class="wajib">*</span></b></label>
      <input type="date" id="tanggal" name="tanggal" required>


      <!-- Paket Bimbingan -->
      <label><b>Paket Bimbingan <span class="wajib">*</span></b></label>
      <div class="form-radio-group horizontal">
        <label><input type="radio" name="paket" value="Paket Reguler">Paket Reguler (500k)</label>
        <label><input type="radio" name="paket" value="Paket Intensif UTBK">Paket Intensif UTBK (750k)</label>
        <label><input type="radio" name="paket" value="Paket Supercamp SBMPTN">Paket Supercamp SBMPTN (1.000k)</label>
      </div>
      <br>
      
      <!-- Fasilitas Tambahan -->
      <label><b>Fasilitas Tambahan (opsional)</b></label>
      <div class="form-checkbox-group vertical">
        <label><input type="checkbox" name="fasilitas[]" value="Modul Cetak Lengkap">Modul Cetak Lengkap (50k)</label>
        <label><input type="checkbox" name="fasilitas[]" value="Modul PDF">Modul PDF (25K)</label>
        <label><input type="checkbox" name="fasilitas[]" value="Video Rekaman">Video Rekaman (75k)</label>
        <label><input type="checkbox" name="fasilitas[]" value="Grup Diskusi Telegram">Grup Diskusi Telegram (40k)</label>
      </div>
      <br>
      
      <!-- Lokasi Cabang -->
      <label for="lokasi"><b>Lokasi Cabang <span class="wajib">*</span></b></label>
      <select id="lokasi" name="lokasi" required>
        <option value="">-- Pilih Lokasi --</option>
        <option value="Jakarta Pusat">Jakarta Pusat (100k)</option>
        <option value="Surabaya">Surabaya (150k)</option>
        <option value="Yogyakarta">Yogyakarta (80k)</option>
        <option value="Makassar">Makassar (115k)</option>
        <option value="Aceh">Aceh (120k)</option>
      </select>
      
      <!-- Metode Pembayaran -->
      <label><b>Metode Pembayaran <span class="wajib">*</span></b></label>
      <div class="form-radio-group horizontal">
        <label><input type="radio" name="metode" value="Transfer Bank">Transfer Bank (+ 3k)</label>
        <label><input type="radio" name="metode" value="E-Wallet">E-Wallet (+ 2k)</label>
        <label><input type="radio" name="metode" value="Tunai">Tunai (+ 0k)</label>
      </div>
      <br>
      
      <!-- Catatan Tambahan -->
      <label for="catatan"><b>Catatan Tambahan</b></label>
      <textarea id="catatan" name="catatan" placeholder="Write your additional note here"></textarea>
      
      <!-- Tombol submit - reset -->
      <div class="button-group">
        <button type="submit" name="submit">Submit</button>
        <button type="reset">Reset</button>
      </div>
    </form>
</div>

<!----------------- DETAIL PENDAFTARAN/RESULT & TENCU ----------------->
<div class="container" id="resultContainer" style="display:none;"> <!--sembunyikan detail sebelum submit-->
    <h1>Detail Pendaftaran Bimbel Jayamahe</h1>
    <table border="1" width="100%" cellpadding="8" cellspacing="0">
      <tbody id="hasilTable"></tbody>
    </table><br>
    <!-- tencu -->
    <h1 style="color: #b795e6; margin-bottom:20px;">Terima Kasih!</h1>
    <h4>Anda telah berhasil mendaftar Bimbel Jayamahe 🎉</h4>
    <p style="margin:20px 0; font-size:16px; color:#333;">Kode pembayaran akan dikirimkan ke email yang Anda daftarkan.</p>  
</div>
<script src="234.js"></script>
</body>
</html>