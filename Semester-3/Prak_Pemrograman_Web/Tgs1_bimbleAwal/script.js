const registerBtn = document.getElementById('register'); /*tombol sign up*/
const loginBtn = document.getElementById('login'); /*tombol sign in*/
const loginForm = document.getElementById('loginForm'); /*form login*/
const signUpForm = document.getElementById('signUpForm'); /*form sign up*/
const bimbelFormContainer = document.getElementById('bimbelFormContainer'); /*form bimbel*/
const container = document.getElementById('container'); /*container utama*/

// Sign Up logic
if (signUpForm) {
    signUpForm.addEventListener('submit', function(e) {
        e.preventDefault();
        const name = document.getElementById('signUpName').value.trim();
        const email = document.getElementById('signUpEmail').value.trim();
        if (!name || !email) {
            alert('Nama dan Email wajib diisi!');
            return;
        }
        
        // Simpan ke localStorage
        localStorage.setItem('bimbelUser', JSON.stringify({ email, name }));
        alert('Sign Up berhasil! Silakan Sign In.');
        container.classList.remove("active");
        signUpForm.reset();
    });
}

// Sign In logic
if (loginForm) {
    loginForm.addEventListener('submit', function(e) {
        e.preventDefault();
        const email = document.getElementById('loginEmail').value.trim();
        const name = document.getElementById('loginName').value.trim();
        const user = JSON.parse(localStorage.getItem('bimbelUser') || '{}');
        if (email === user.email && name === user.name) {

            // Sembunyikan form login, tampilkan form bimbel
            container.style.display = 'none';
            bimbelFormContainer.style.display = 'block';
            window.scrollTo({
                top: bimbelFormContainer.offsetTop - 20,
                behavior: 'smooth'
            });
        } else {
            alert('Email atau Nama tidak cocok! Silakan Sign Up terlebih dahulu.');
        }
    });
}

// Validasi form bimbel
const bimbelForm = document.getElementById('bimbelForm');
const thankYouPage = document.getElementById('thankYouPage');

if (bimbelForm) {
    bimbelForm.addEventListener('submit', function(e) {
        e.preventDefault();
        const nama = document.getElementById('nama').value.trim();
        const email = document.getElementById('email').value.trim();
        const note = document.getElementById('note').value.trim(); 

        // Validasi input
        if (!nama) {
            alert('Nama wajib diisi!');
            return;
        }
        if (!email) {
            alert('Email wajib diisi!');
            return;
        }
        if (!note) {
            alert('Catatan tambahan wajib diisi!');
            return;
        }

        // Sembunyikan form, tampilkan halaman Thank You
        bimbelFormContainer.style.display = 'none';
        thankYouPage.style.display = 'block';
        window.scrollTo({ top: 0, behavior: 'smooth' });
    });
}
/*reset*/
const clearLoginInput = document.getElementById('clearLoginInput');

if (clearLoginInput) {
    clearLoginInput.addEventListener('click', function(e) {
        e.preventDefault();
        /*kosongkanin input*/
        document.getElementById('loginName').value = '';
        document.getElementById('loginEmail').value = '';
    });
}
