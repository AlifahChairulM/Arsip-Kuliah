import streamlit as st
import numpy as np
import skfuzzy as fuzz
import skfuzzy.control as ctrl
import matplotlib.pyplot as plt

st.set_page_config(page_title="Fuzzy Control Suhu & Kelembaban", layout="wide")
st.title("Sistem Kontrol Suhu & Kelembaban dengan Logika Fuzzy Mamdani")
st.markdown("**Tugas 4 | Alifah Chairul Munawar | 123240234**")

# Var input
suhu_luar = ctrl.Antecedent(np.arange(0, 11, 1), 'suhu_luar')
suhu_dalam = ctrl.Antecedent(np.arange(0, 11, 1), 'suhu_dalam')
kelembaban = ctrl.Antecedent(np.arange(0, 11, 1), 'kelembaban')

# Var output
kipas = ctrl.Consequent(np.arange(0, 26, 1), 'kipas')
ac = ctrl.Consequent(np.arange(0, 26, 1), 'ac')
pemanas = ctrl.Consequent(np.arange(0, 26, 1), 'pemanas')

# keanggotaan input
suhu_luar['dingin'] = fuzz.trimf(suhu_luar.universe, [0, 0, 5])
suhu_luar['sejuk']  = fuzz.trapmf(suhu_luar.universe, [0, 4, 6, 10])
suhu_luar['hangat'] = fuzz.trimf(suhu_luar.universe, [5, 10, 10])

suhu_dalam['sejuk']  = fuzz.trimf(suhu_dalam.universe, [0, 0, 5])
suhu_dalam['nyaman'] = fuzz.trapmf(suhu_dalam.universe, [0, 3, 7, 10])
suhu_dalam['hangat'] = fuzz.trimf(suhu_dalam.universe, [5, 10, 10])

kelembaban['kering'] = fuzz.trimf(kelembaban.universe, [0, 0, 5])
kelembaban['sedang'] = fuzz.trapmf(kelembaban.universe, [0, 4, 6, 10])
kelembaban['lembab'] = fuzz.trimf(kelembaban.universe, [5, 10, 10])

# keanggotaan output
kipas['lambat'] = fuzz.trimf(kipas.universe, [0, 0, 12])
kipas['sedang'] = fuzz.trimf(kipas.universe, [0, 12, 25])
kipas['cepat']  = fuzz.trimf(kipas.universe, [12, 25, 25])

ac['sedikit'] = fuzz.trimf(ac.universe, [0, 0, 12])
ac['sedang']  = fuzz.trimf(ac.universe, [0, 12, 25])
ac['banyak']  = fuzz.trimf(ac.universe, [12, 25, 25])

pemanas['rendah'] = fuzz.trimf(pemanas.universe, [0, 0, 12])
pemanas['sedang'] = fuzz.trimf(pemanas.universe, [0, 12, 25])
pemanas['tinggi'] = fuzz.trimf(pemanas.universe, [12, 25, 25])

#2. inferensi/aturan
rule1_kipas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['kering'], kipas['lambat'])
rule2_kipas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['nyaman'] & kelembaban['sedang'], kipas['sedang'])
rule3_kipas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['hangat'] & kelembaban['lembab'], kipas['cepat'])
rule4_kipas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['sejuk'] & kelembaban['sedang'], kipas['lambat'])
rule5_kipas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['sedang'], kipas['cepat'])
rule6_kipas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['nyaman'] & kelembaban['lembab'], kipas['sedang'])
rule7_kipas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['sejuk'] & kelembaban['kering'], kipas['sedang'])
rule8_kipas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['hangat'] & kelembaban['lembab'], kipas['cepat'])
rule9_kipas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['lembab'], kipas['lambat'])
rule10_kipas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['kering'], kipas['cepat'])

rule1_ac = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['kering'], ac['sedikit'])
rule2_ac = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['nyaman'] & kelembaban['sedang'], ac['sedang'])
rule3_ac = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['hangat'] & kelembaban['lembab'], ac['sedikit'])
rule4_ac = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['sejuk'] & kelembaban['sedang'], ac['banyak'])
rule5_ac = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['sedang'], ac['sedang'])
rule6_ac = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['nyaman'] & kelembaban['lembab'], ac['sedang'])
rule7_ac = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['sejuk'] & kelembaban['kering'], ac['banyak'])
rule8_ac = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['hangat'] & kelembaban['lembab'], ac['sedikit'])
rule9_ac = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['lembab'], ac['sedang'])
rule10_ac = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['kering'], ac['banyak'])

rule1_pemanas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['kering'], pemanas['tinggi'])
rule2_pemanas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['nyaman'] & kelembaban['sedang'], pemanas['rendah'])
rule3_pemanas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['hangat'] & kelembaban['lembab'], pemanas['rendah'])
rule4_pemanas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['sejuk'] & kelembaban['sedang'], pemanas['sedang'])
rule5_pemanas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['sedang'], pemanas['rendah'])
rule6_pemanas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['nyaman'] & kelembaban['lembab'], pemanas['tinggi'])
rule7_pemanas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['sejuk'] & kelembaban['kering'], pemanas['rendah'])
rule8_pemanas = ctrl.Rule(suhu_luar['sejuk'] & suhu_dalam['hangat'] & kelembaban['lembab'], pemanas['rendah'])
rule9_pemanas = ctrl.Rule(suhu_luar['dingin'] & suhu_dalam['sejuk'] & kelembaban['lembab'], pemanas['tinggi'])
rule10_pemanas = ctrl.Rule(suhu_luar['hangat'] & suhu_dalam['nyaman'] & kelembaban['kering'], pemanas['rendah'])

# 3. agregasi
sistem_kipas = ctrl.ControlSystem([rule1_kipas, rule2_kipas, rule3_kipas, rule4_kipas, rule5_kipas,
                                   rule6_kipas, rule7_kipas, rule8_kipas, rule9_kipas, rule10_kipas])
sistem_ac = ctrl.ControlSystem([rule1_ac, rule2_ac, rule3_ac, rule4_ac, rule5_ac,
                                rule6_ac, rule7_ac, rule8_ac, rule9_ac, rule10_ac])
sistem_pemanas = ctrl.ControlSystem([rule1_pemanas, rule2_pemanas, rule3_pemanas, rule4_pemanas, rule5_pemanas,
                                     rule6_pemanas, rule7_pemanas, rule8_pemanas, rule9_pemanas, rule10_pemanas])

sim_kipas = ctrl.ControlSystemSimulation(sistem_kipas)
sim_ac = ctrl.ControlSystemSimulation(sistem_ac)
sim_pemanas = ctrl.ControlSystemSimulation(sistem_pemanas)

st.header("Silahkan Input Nilai")

col_x, col_y, col_z = st.columns(3)
with col_x:
    x_val = st.number_input("x (Suhu Luar)", min_value=0.0, max_value=10.0, value=5.0, step=0.5, help="0-10°C")
with col_y:
    y_val = st.number_input("y (Suhu Dalam)", min_value=0.0, max_value=10.0, value=5.0, step=0.5, help="0-10°C")
with col_z:
    z_val = st.number_input("z (Kelembaban)", min_value=0.0, max_value=10.0, value=5.0, step=0.5, help="0-10")

hitung = st.button("Hitung", type="primary", use_container_width=True)
st.divider()

# PROSES INFERENSI
if hitung:
    suhu_luar_val = x_val
    suhu_dalam_val = y_val
    kelembaban_val = z_val
    
    try:
        # 1. fuzzifikasi
        sim_kipas.input['suhu_luar'] = suhu_luar_val
        sim_kipas.input['suhu_dalam'] = suhu_dalam_val
        sim_kipas.input['kelembaban'] = kelembaban_val

        sim_ac.input['suhu_luar'] = suhu_luar_val
        sim_ac.input['suhu_dalam'] = suhu_dalam_val
        sim_ac.input['kelembaban'] = kelembaban_val

        sim_pemanas.input['suhu_luar'] = suhu_luar_val
        sim_pemanas.input['suhu_dalam'] = suhu_dalam_val
        sim_pemanas.input['kelembaban'] = kelembaban_val

        # 4. defuzifikasi
        sim_kipas.compute()
        sim_ac.compute()
        sim_pemanas.compute()
        
        hasil_kipas = sim_kipas.output['kipas']
        hasil_ac = sim_ac.output['ac']
        hasil_pemanas = sim_pemanas.output['pemanas']
        
        st.session_state['hasil_kipas'] = hasil_kipas
        st.session_state['hasil_ac'] = hasil_ac
        st.session_state['hasil_pemanas'] = hasil_pemanas
        st.session_state['suhu_luar_val'] = suhu_luar_val
        st.session_state['suhu_dalam_val'] = suhu_dalam_val
        st.session_state['kelembaban_val'] = kelembaban_val
        st.session_state['hitung_done'] = True
        
    except Exception as e:
        st.error(f"Error: {e}")
        st.session_state['hitung_done'] = False

def plot_membership_with_fill(var, nama, input_val=None):
    fig, ax = plt.subplots(figsize=(8, 5))
    
    x = var.universe
    colors = ['#1f77b4', '#ff7f0e', '#2ca02c']
    
    for i, term_name in enumerate(var.terms):
        y = var[term_name].mf
        color = colors[i % len(colors)]
   
        ax.plot(x, y, label=term_name, linewidth=2, color=color)
        ax.fill_between(x, 0, y, alpha=0.2, color=color)

    if input_val is not None:
        ax.axvline(x=input_val, color='red', linestyle='--', linewidth=2, label=f'Nilai = {input_val}')
    
    ax.set_xlabel('Nilai')
    ax.set_ylabel('Derajat Keanggotaan')
    ax.set_title(nama)
    ax.legend(loc='upper right')
    ax.grid(True, alpha=0.3)
    ax.set_xlim([x.min(), x.max()])
    ax.set_ylim([-0.05, 1.05])
    
    st.pyplot(fig)
    plt.close()

if st.session_state.get('hitung_done', False):
    hasil_kipas = st.session_state['hasil_kipas']
    hasil_ac = st.session_state['hasil_ac']
    hasil_pemanas = st.session_state['hasil_pemanas']
    suhu_luar_val = st.session_state['suhu_luar_val']
    suhu_dalam_val = st.session_state['suhu_dalam_val']
    kelembaban_val = st.session_state['kelembaban_val']
    
    st.header("Hasil Kontrol")
    col1, col2, col3 = st.columns(3)
    col1.metric("Kipas Angin", f"{hasil_kipas:.2f}", help="Skala 0-25")
    col2.metric("Pendingin Udara (AC)", f"{hasil_ac:.2f}", help="Skala 0-25")
    col3.metric("Pemanas", f"{hasil_pemanas:.2f}", help="Skala 0-25")
    
    #visaual
    st.header("Visualisasi Fungsi Keanggotaan (Canvas)")
    
    st.subheader("Input Variables")
    col_in1, col_in2, col_in3 = st.columns(3)
    
    with col_in1:
        st.write("**Suhu Udara Luar**")
        plot_membership_with_fill(suhu_luar, "Suhu Luar", suhu_luar_val)
    
    with col_in2:
        st.write("**Suhu Udara Dalam**")
        plot_membership_with_fill(suhu_dalam, "Suhu Dalam", suhu_dalam_val)
    
    with col_in3:
        st.write("**Kelembaban**")
        plot_membership_with_fill(kelembaban, "Kelembaban", kelembaban_val)
    
    st.subheader("Output Variables")
    col_out1, col_out2, col_out3 = st.columns(3)
    
    with col_out1:
        st.write("**Kipas Angin**")
        plot_membership_with_fill(kipas, "Kipas Angin", hasil_kipas)
    
    with col_out2:
        st.write("**Pendingin Udara (AC)**")
        plot_membership_with_fill(ac, "AC", hasil_ac)
    
    with col_out3:
        st.write("**Pemanas**")
        plot_membership_with_fill(pemanas, "Pemanas", hasil_pemanas)

    # fuzzifikasi (detail perhitungan manual)
    with st.expander("Detail Perhitungan Derajat Keanggotaan"):
        st.write("### Nilai Input")
        st.write(f"- Suhu Luar: **{suhu_luar_val}** °C")
        st.write(f"- Suhu Dalam: **{suhu_dalam_val}** °C")
        st.write(f"- Kelembaban: **{kelembaban_val}** %")
        
        st.write("### Derajat Keanggotaan Input")
        st.write("**Suhu Luar:**")
        for mf_name in ['dingin', 'sejuk', 'hangat']:
            val = fuzz.interp_membership(suhu_luar.universe, suhu_luar[mf_name].mf, suhu_luar_val)
            st.write(f"  - {mf_name}: {val:.3f}")
        
        st.write("**Suhu Dalam:**")
        for mf_name in ['sejuk', 'nyaman', 'hangat']:
            val = fuzz.interp_membership(suhu_dalam.universe, suhu_dalam[mf_name].mf, suhu_dalam_val)
            st.write(f"  - {mf_name}: {val:.3f}")
        
        st.write("**Kelembaban:**")
        for mf_name in ['kering', 'sedang', 'lembab']:
            val = fuzz.interp_membership(kelembaban.universe, kelembaban[mf_name].mf, kelembaban_val)
            st.write(f"  - {mf_name}: {val:.3f}")
        
        st.write("### Hasil Defuzzifikasi (Centroid)")
        st.write(f"- Kipas Angin: **{hasil_kipas:.2f}**")
        st.write(f"- Pendingin Udara (AC): **{hasil_ac:.2f}**")
        st.write(f"- Pemanas: **{hasil_pemanas:.2f}**")
else:
    st.info("Masukkan nilai x, y, z lalu tekan tombol Hitung untuk melihat hasil")