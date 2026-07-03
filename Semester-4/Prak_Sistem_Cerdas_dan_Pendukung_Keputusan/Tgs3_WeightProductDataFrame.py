import streamlit as st
import pandas as pd
import numpy as np

st.set_page_config(page_title="Tugas 3 SCPK - Weighted Product", layout="wide")

st.title("Tugas 3 SCPK")
st.header("Weight Product Data Frame")
st.subheader("123240234 - ALIFAH CHAIRUL MUNAWAR")

# Inisialisasi State =data ga ilang pindah tab
if 'kriteria_data' not in st.session_state:
    st.session_state.kriteria_data = []
if 'alternatif_nama' not in st.session_state:
    st.session_state.alternatif_nama = []
if 'matrix_data' not in st.session_state:
    st.session_state.matrix_data = {}

# Tab Menu
tab1, tab2, tab3 = st.tabs(["Kriteria", "Alternatif", "Matriks"])
# KRITERIA
with tab1:
    st.write("### Input Data Kriteria")
    num_kriteria = st.number_input("Masukkan Jumlah Kriteria", min_value=3, max_value=10, value=3)
    
    kriteria_list = []
    cols = st.columns([3, 2, 2])
    cols[0].write("**Nama Kriteria**")
    cols[1].write("**Bobot (1-5)**")
    cols[2].write("**Keterangan (Atribut)**")

    for i in range(num_kriteria):
        col1, col2, col3 = st.columns([3, 2, 2])
        nama = col1.text_input(f"Kriteria {i+1}", key=f"nama_k_{i}", placeholder="Contoh: Harga")
        bobot = col2.number_input(f"Bobot {i+1}", min_value=1, max_value=5, value=1, key=f"bobot_{i}")
        atribut = col3.selectbox(f"Jenis {i+1}", ["Benefit", "Cost"], key=f"attr_{i}")
        kriteria_list.append({"nama": nama, "bobot": bobot, "atribut": atribut})
    
    st.session_state.kriteria_data = kriteria_list

# ALTERNATIF
with tab2:
    st.write("### Input Data Alternatif")
    num_alternatif = st.number_input("Masukkan Jumlah Alternatif", min_value=3, max_value=10, value=3)
    
    alternatif_list = []
    for i in range(num_alternatif):
        nama_alt = st.text_input(f"Alternatif {i+1}", key=f"alt_{i}", placeholder=f"Contoh: Alternatif {i+1}")
        alternatif_list.append(nama_alt)
    
    st.session_state.alternatif_nama = alternatif_list

# MATRIKS
with tab3:
    st.write("### Matriks Alternatif")
    
    if not all(st.session_state.kriteria_data) or not all(st.session_state.alternatif_nama):
        st.warning("Silakan lengkapi data Nama Kriteria dan Nama Alternatif terlebih dahulu!")
    else:
        # form input matriks
        matrix_input = []
        
        # Header Kriteria
        header_cols = st.columns([2] + [1] * len(st.session_state.kriteria_data))
        header_cols[0].write("**Alternatif**")
        for idx, k in enumerate(st.session_state.kriteria_data):
            header_cols[idx+1].write(f"**{k['nama']}**")

        # Input Nilai
        for i, alt in enumerate(st.session_state.alternatif_nama):
            row_cols = st.columns([2] + [1] * len(st.session_state.kriteria_data))
            row_cols[0].write(alt)
            row_values = []
            for j in range(len(st.session_state.kriteria_data)):
                val = row_cols[j+1].number_input(f"v_{i}_{j}", min_value=0.0, step=0.1, label_visibility="collapsed")
                row_values.append(val)
            matrix_input.append(row_values)

        # Data Frame
        if st.button("Buat Data Frame"):
            df = pd.DataFrame(matrix_input, 
                              index=st.session_state.alternatif_nama, 
                              columns=[k['nama'] for k in st.session_state.kriteria_data])
            st.write("#### Data Matriks:")
            st.dataframe(df)
            st.session_state.current_df = df

        # Temukan Alternatif Terbaik (WP)
        if st.button("Temukan Alternatif Terbaik"):
            try:
                # Bobot dan Perbaikan Bobot (ΣW = 1)
                weights = np.array([k['bobot'] for k in st.session_state.kriteria_data])
                attrs = [k['atribut'] for k in st.session_state.kriteria_data]
                
                sum_weights = sum(weights)
                w_norm = weights / sum_weights
                
                # Sesuaikan pangkat berdasarkan B/C
                w_final = []
                for i in range(len(w_norm)):
                    if attrs[i] == "Cost":
                        w_final.append(-w_norm[i])
                    else:
                        w_final.append(w_norm[i])
                
                # itung Vektor S
                S = []
                for row in matrix_input:
                    val_s = 1
                    for i in range(len(row)):
                        val_s *= (row[i] ** w_final[i])
                    S.append(val_s)
                
                # itung Vektor V
                sum_S = sum(S)
                V = [s / sum_S for s in S]
                
                # Tampil Hasil
                results_df = pd.DataFrame({
                    "Alternatif": st.session_state.alternatif_nama,
                    "Vektor S": S,
                    "Vektor V (Skor)": V
                })
                
                results_df = results_df.sort_values(by="Vektor V (Skor)", ascending=False)
                
                st.success("Perhitungan Selesai!")
                st.write("#### Hasil Perankingan:")
                st.table(results_df)
                
                best_alt = results_df.iloc[0]['Alternatif']
                st.info(f"Kesimpulan: Alternatif terbaik adalah **{best_alt}**")
                
            except Exception as e:
                st.error(f"Terjadi kesalahan perhitungan. Pastikan semua nilai matriks diisi (tidak nol untuk pembagi).")
