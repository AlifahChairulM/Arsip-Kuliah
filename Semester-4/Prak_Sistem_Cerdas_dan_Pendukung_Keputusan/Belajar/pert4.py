import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt


st.set_page_config(page_title="Belajar Streamlit", layout="wide")

#judul
st.title("belajar streamlit")
st.header("Belajar Streamlit")
st.subheader("Belajar Streamlit")

#garis
st.divider()
st.write("tampilin **teks ** *biasa*") #BOLD BINTANG 2, BIASA BINTANG1
st.markdown("tampilin teks ")
st.text("tampilin teks dgn text ")
st.caption("teks keterangan ")

#kode
st.write("tampilin kode")
st.code("print('hello world')", language = "python")
st.write("ini rumus")
st.latex(r"E=mc^2")

#widget
st.title("2.dasar widget di streamlit")
st.write("widget biar bisa interaksi sama user")
st.drivider()

nama = st.text_input("sapa namanya??") # kotak input
umur = st.number_input("umurmu piro", min_value=0, max_value=100, step=1) #min, maxberapa banyak yg ditambah
pesan = st.text_area("katakan saje")

st.drivider()
gender= st.radio("pilih jenis kelamin", ["laki-laki", "perempuan","custom"])

if gender =='custom':
    gender = st.text_input("karepmu")

st.write("gender:" , gender)
hobi =st.selectbox("hobi kamu",["dengerin musik", "ngoding" ])

aslab = st.multiselect("aslab favoritmu (bisa >1)", ["hawla", "khatama", "alip", "dimas" ])
st.divider()

#slider dan checkbox
kepuasan =st.slider("berapa puas dengan aslab?", min_value=0, max_value=10, step=1)
setuju = st.checkbox("setuju dengan pernyataan ini")

#button
if st.button("simpan data", disabled=not setuju):
    st.success (f"halo,{nama}, {umur} tahun")
    st.info(f"hobi: {hobi} | tingkat kepuasan: {kepuasan} %")

#------dasar layout
#sidebar
with st.sidebar: #klo mau masukin pake st yak
    st.header("ini sidebar")
    st.button("tombol di sidebar")

#tab
tab1,tab2,tab3= st.tabs(["tab pertama", "tab kedua", "tab ketiga"])
with tab1: #buat isi yak
    st.subheader("ini tab pertama")

with tab2: #buat isi yak
    st.subheader("ini tab kedua")
    #column
    column1, column2, column3 = st.columns(3)
    st.columns(3) # kolom bagi rata
    #st.columns([3,1,1]) # kolom 1 lebih besar

    with column1:
        st.success("kolom 1 (kiri)")
    with column2:
        st.success("kolom 2 (tengah)")
    with column3:
        st.success("kolom 3 (kanan)")

with tab3: #buat isi yak
    st.subheader("ini tab ketiga")

    #expander
    with st.expander("klik disini untuk melihat kelanjutan"):
        st.write("ini expander")
        st.image("kasih link gambare")
        st.markdown("kata gambar..") 
        st.container()
        st.write("text dalam container")
        st.write("fungsi untuk membingkai beberapa elemen")
    st.write("diluar container")
st.divider()
#----------------------------------
#masuk no file data hp
df = pd.read_csv("data_hp.csv")

st.write("tampilkan data set")
st.write(df) 

st.write("Visualisasi Đata:") 
plt.figure(figsize=(18, 5))

plt.bar(df['ID_HP'], df['Terjual_Bulan_Ini'],color='skyblue')
plt.title("Total Penjualan Smartphone Bulan Ini")
plt.xlabel("ID Smartphone")
plt.ylabel("Jumlah Terjual(unit)")
plt.show

st.pyplot(plt)