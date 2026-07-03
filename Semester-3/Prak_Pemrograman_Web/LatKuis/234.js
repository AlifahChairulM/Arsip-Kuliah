//123240234//

//---------- Harga -----------//
const hargaPaket = {
  "Paket Reguler": 750000,
  "Paket Intensif UTBK": 500000,
  "Paket Supercamp SBMPTN": 1000000
};
const hargaFasilitas = {
  "Modul Cetak Lengkap": 50000,
  "Modul PDF": 25000,
  "Video Rekaman": 75000,
  "Grup Diskusi Telegram": 40000
};
const hargaLokasi = {
  "Jakarta Pusat": 100000,
  "Surabaya": 150000,
  "Yogyakarta": 80000,
  "Makassar": 115000,
  "Aceh": 120000
};
const biayaAdmin = {
  "Transfer Bank": 3000,
  "E-Wallet": 2000,
  "Tunai": 0
};
const formatRupiah = (angka) => "Rp" + angka.toLocaleString("id-ID"); //angka ke rp

//tgl otomatis
function setTanggalHariIni() {
    const sekarang = new Date();
    const tahun = sekarang.getFullYear();
    const bulan = String(sekarang.getMonth() + 1).padStart(2, '0');
    const tanggal = String(sekarang.getDate()).padStart(2, '0');
    const tanggalHariIni = `${tahun}-${bulan}-${tanggal}`;
    
    document.getElementById('tanggal').value = tanggalHariIni;
}

//format display
function formatTanggalDisplay(tanggal) {
    const options = { 
        weekday: 'long', 
        year: 'numeric', 
        month: 'long', 
        day: 'numeric' 
    };
    return new Date(tanggal).toLocaleDateString('id-ID', options);
}

// Ambil form
const form = document.getElementById("formPendaftaran");
const hasilTable = document.getElementById("hasilTable");
const formContainer = document.getElementById("formContainer");
const resultContainer = document.getElementById("resultContainer");

// Validasi form pendaftaran
form.addEventListener("submit", function(event) {
  event.preventDefault(); //ga reload

  // Ambil data dari form
  const nama = document.getElementById("nama").value.trim();
  const email = document.getElementById("email").value.trim();
  const tanggal = document.getElementById("tanggal").value;
  const paket = document.querySelector("input[name='paket']:checked");
  const fasilitas = [...document.querySelectorAll("input[name='fasilitas[]']:checked")].map(el => el.value);
  const lokasi = document.getElementById("lokasi").value;
  const metode = document.querySelector("input[name='metode']:checked");
  const catatan = document.getElementById("catatan").value.trim() || "-";
  
  // Validasi input wajib
  if (!nama || !email || !lokasi || !metode) {
    alert("Harap isi semua field wajib (Nama, Email, Lokasi, Metode Pembayaran).");
    return;
  }

  //notif konfir mo submit
  if (!confirm("Apakah Anda yakin ingin mengirim data?")) {
    alert("Pesanan dibatalkan");
    return;
  }

  // Definisikan tanggalDisplay
  const tanggalDisplay = formatTanggalDisplay(tanggal);

  // Paket klo null
  let paketVal = paket ? paket.value : "Undefined (-)";

  //total biaya
  let total = 0;
  if (paket) {
    total += hargaPaket[paket.value] || 0;
  }

  // Fasilitas
  if (fasilitas.length) {
    fasilitas.forEach(f => {
      total += hargaFasilitas[f] || 0;
    });
  }

  // Lokasi
  total += hargaLokasi[lokasi] || 0;

  // Metode Pembayaran
  total += biayaAdmin[metode.value] || 0;

  // Tampilan Tabel Data
  hasilTable.innerHTML = `
      <table style="width:100%; border-collapse:collapse; border:1px solid #ccc;">
    <thead>
      <tr>
        <th colspan="2" style="padding:10px; background:#f4f4f4; text-align:center; font-size:18px;">
          Data Pendaftaran Pelajar
        </th>
      </tr>
    </thead>
    <tbody>
       <tr><td style="padding:10px; background:#f9f9f9; width:30%;"><b>Nama</b></td><td style="padding:10px;">${nama}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Email</b></td><td style="padding:10px;">${email}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Tanggal Pendaftaran</b></td><td style="padding:10px;">${tanggalDisplay}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Paket Bimbel</b></td><td style="padding:10px;">${paketVal}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Lokasi Belajar</b></td><td style="padding:10px;">${lokasi}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Fasilitas Tambahan</b></td><td style="padding:10px;">${fasilitas.length ? fasilitas.join(", ") : "-"}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Metode Pembayaran</b></td><td style="padding:10px;">${metode.value}</td></tr>
      <tr><td style="padding:10px; background:#f9f9f9;"><b>Catatan</b></td><td style="padding:10px;">${catatan}</td></tr>
      <tr>
        <td style="padding:8px; background:#f9f9f9;"><b>Rincian Biaya</b></td>
        <td style="padding:8px;">
          <div style="display: flex; justify-content: space-between; margin-bottom: 8px;">
            <span>Paket ${paketVal}:</span>
            <span style="font-weight: bold;">${formatRupiah(hargaPaket[paketVal] || 0)}</span>
          </div>
          
          <div style="display: flex; justify-content: space-between; margin-bottom: 8px;">
            <span>Lokasi ${lokasi}:</span>
            <span style="font-weight: bold;">${formatRupiah(hargaLokasi[lokasi] || 0)}</span>
          </div>
          
          ${fasilitas.length > 0 ? fasilitas.map(f => `
            <div style="display: flex; justify-content: space-between; margin-bottom: 8px;">
              <span>Fasilitas ${f}:</span>
              <span style="font-weight: bold;">${formatRupiah(hargaFasilitas[f] || 0)}</span>
            </div>
          `).join('') : ''}
          
          <div style="display: flex; justify-content: space-between; margin-bottom: 8px;">
            <span>Biaya Admin (${metode.value}):</span>
            <span style="font-weight: bold;">${formatRupiah(biayaAdmin[metode.value] || 0)}</span>
          </div>
          
          <div style="margin-top: 12px; padding-top: 12px; border-top: 2px solid #000000ff;">
            <div style="display: flex; justify-content: space-between; font-weight: bold; font-size: 16px; color: #f1592fff;">
              <span>Total Bayar:</span>
              <span>${formatRupiah(total)}</span>
            </div>
          </div>
        </td>
      </tr>
      <tr>
        <td colspan="2" style="padding:15px; text-align:center;">
          <button onclick="location.reload()" style="padding:10px 20px; background:#b795e6; color:#fff; border:none; border-radius:5px; cursor:pointer;">
            Daftar Lagi
          </button>
        </td>
      </tr>
    </tbody>
  </table>
  `;

  formContainer.style.display = "none"; //sembunyi form
  resultContainer.style.display = "block"; //tampilkan hasil
  window.scrollTo({ top: 0, behavior: "smooth" });
  
  // Kirim data ke server PHP
  kirimDataKeServer();
});

// otw kirim data ke server
function kirimDataKeServer() {
  const formData = new FormData(form);
  
  fetch('process.php', {
    method: 'POST',
    body: formData
  })
  .then(response => response.text())
  .then(data => {
    console.log('Data berhasil dikirim ke server:', data);
  })
  .catch(error => {
    console.error('Error mengirim data:', error);
  });
}

// sign in sek
document.getElementById("loginForm").addEventListener("submit", function(e) {
  e.preventDefault();
  const name = document.getElementById("loginName").value.trim();
  const email = document.getElementById("loginEmail").value.trim();
  if (!name || !email) {
    alert("Nama dan Email wajib diisi!");
    return;
}

  // alur sign in
  document.getElementById("container").style.display = "none"; //sembunyika sign in
  document.getElementById("formContainer").style.display = "block";
  document.getElementById("nama").value = name;
  document.getElementById("email").value = email;
  setTanggalHariIni(); 
  });

  //clear input sign in
  document.getElementById("clearLoginInput").addEventListener("click", function(e) {  
  e.preventDefault();
  document.getElementById("loginName").value = "";
  document.getElementById("loginEmail").value = "";
  });