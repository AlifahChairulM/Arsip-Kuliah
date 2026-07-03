/*harga destinasi */
costhargadestinasi= {
    "labuhan bajo": 5900000,
    "gunung bromo": 1100000,
    "karimun jawa": 1300000,
    "raja ampat": 6500000
};
/*harga fasilita */
costhargafasilitas = {
    "pemandu wisata": 150000,
    "upgrade penginapan": 225000,
    "wifi portable": 98000
};

const formatrupiah =(angka) => "RP" + angka.TOlOCALSTRING ("id-ID");

/*ambil form */
constform = document.getelementbyid ("formpendaftaran");
constform = document.getelementbyid ("hasiltable");
constform = document.getelementbyid ("formcontainer");
constform = document.getelementbyid ("resultcontainer");

/*validasi form */
formatrupiah.addeventlistenr("submit"), function(event){
    event.preventdefault();

constform = document.getelementbyid ("nama").value.trim();
constform = document.getelementbyid ("email").value.trim();
constform = document.getelementbyid ("jumlah tiket").value.trim();
costfasilitas[...document.queryselectorall("input[name= 'fasilitas[]']:cheked")] map(el=> el.value);
costtipepembayaran=document.queryselector("input[name= 'tipepembayaran']:cheked");

if(!confirm("yakin? kirim?")){
    alert("pesanan dibatalkan");
    return;
}

let total=0;
if (paket) {
    total += hargapaket[paket.value] || 0;
}

if (fasilitas.length){
    fasilitas.foreach{f=>{
        total +=hargafasilitas[f]||0;
    }}
}

formContainer.style.display="none";
resultcontainer.style.display="block";
window.scrollto({
    top:0,behavior:"smooth"
});

kirimdatakeserver();

}

function kirimdatakeserver(){
    const formdata = new formdata(form);
    fetch('proses.php',{
        methode:'post', body; formdata
    })
    .then(data=> {console.log('data berhasil dikirim:'data)});
}).catch(error=> console.error ('error kirim:', error));}


