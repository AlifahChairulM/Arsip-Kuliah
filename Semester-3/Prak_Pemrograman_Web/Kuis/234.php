<?php 
if ($_post) {
    $nama = $nama= $_post ['nama'];
    $nama = $email= $_post ['email'];
    $nama = $paket= $_post ['paket'];

    echo " <h1> pendaftran berhasil cihuy </h1>";
    echo " <p> nama: $nama </P>";
    echo " <p> nama: $nama </P>";
    echo " <p> nama: $nama </P>";
    echo " <a herf = "234.html">kembali</a>";}
    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pemesanan paket wisata IF</title>
    <link rel = "stylesheet"href= "234.css" > 
</head>
<body>
    <div class = "container" id=" container">
        <div class="form-container sign-in">
            form id = "login form"> requirend>
            <h1> Wisata IF </h1>
            <input type = "text" placeholder ="name" id + "loginname">
            <input type = "email" placeholder ="name" id + "loginemail">
            <a href = "#" id = "clean login input"> click to clear</a>
            <button type = "submit">sign in </button> </form>
        </div>
    </div>



    <!--form-->
     <div class = "container" id="form container">
       style= "display: none;"><h1> form dolan</h1>
       <form id=" "form pendaftaran" metode="post"action= "proses.php"></form>

       <!--nama-->
       <label for=" nama"><b> namalengkap <span> class= "wajib">*</span></b></label>
       <input type =" text" id ="nama" name ="nama"requirend>
       <input type =" email" id ="email" name ="email"requirend>

       <!--email-->
       <label for=" email"><b> email<span> class= "wajib">*</span></b></label>
       <input type =" email" id ="email" name ="email"requirend>

       <!--destinasi wisata-->
       <label for=" destinasi"><b> destinasi wisata <span> class= "wajib">*</span></b></label>
       <select id =" destinasi" name = "destinasi" requirend>
            <option value ="" >--milih ges--</option>
            <option value ="default" ></option>
            <option value ="labuhan bajo" ></option>
            <option value ="gunung bromo" ></option>
            <option value ="karimun jawa" ></option>
            <option value ="raja ampat" ></option>
       </select>

        <!--jumlah tiket-->
       <label for="jumlah tiket"><b> jumlah tiket</b></label>
       <input type ="number" id ="jumlah tiket" name ="jumlah tiket"requirend>

        <!--fasilitas tambahan-->
        <label for="fasilitas"><b>fasilitas <span> class= "wajib">*</span></b></label>
            <div class = "form-checkbox" name = "fasilitas[] "value= "pemandu wisata"</label>
            <div class = "form-checkbox" name = "fasilitas[] "value= "upgrate penginapan" </label>
            <div class = "form-checkbox" name = "fasilitas[] "value= "wifi portable" </label>
        </div>

        <!--tipe pembayaran-->
        <label for="tipe pembayaran"><b>tipe pembayaran <span> class= "wajib">*</span></b></label>
            <div class = "form-checkbox" name = "fasilitas[] "value= "dp(50%)"</label>
            <div class = "form-checkbox" name = "fasilitas[] "value= "full payment" </label>
        </div>
        
        <!--tombol-->
        <div class="button-grup">
        <button type="submit" name "submit" >submit</button>
        <button type ="reset"> reset </button>
        </div>
    </form>
    </div>

    <!--result-->
     <div class = "container" id="form container">
       style= "display: none;"><h1> detail pesanan</h1>
       <tabel broder="1"width="100%" cellpadding="8"
       cellspacing="0 "><tbody id= "hasil tabel"></tabel></tbody></tabel><br>

        <!--tencu-->

<script src ="234.js"></script>  
</body>
</html>