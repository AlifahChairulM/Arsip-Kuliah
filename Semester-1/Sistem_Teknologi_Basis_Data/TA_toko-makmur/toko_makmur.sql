-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 11, 2024 at 05:46 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `toko_makmur`
--

-- --------------------------------------------------------

--
-- Table structure for table `pegawai`
--

CREATE TABLE `pegawai` (
  `id_pegawai` int(11) NOT NULL,
  `nama_pegawai` varchar(100) DEFAULT NULL,
  `no_telp_pegawai` char(12) DEFAULT NULL,
  `alamat_pegawai` char(100) DEFAULT NULL,
  `gaji` decimal(15,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pegawai`
--

INSERT INTO `pegawai` (`id_pegawai`, `nama_pegawai`, `no_telp_pegawai`, `alamat_pegawai`, `gaji`) VALUES
(1, 'Aditya Saputra', '081234567001', 'Jl. Merdeka No. 41', 2500000.00),
(2, 'Bella Sari', '081234567002', 'Jl. Kebon Sirih No. 42', 4800000.00),
(3, 'Chandra Pratama', '081234567003', 'Jl. Cikini Raya No. 43', 3000000.00),
(4, 'Diah Lestari', '081234567004', 'Jl. Teuku Umar No. 44', 1500000.00),
(5, 'Edi Santoso', '081234567005', 'Jl. Thamrin No. 45', 4500000.00),
(6, 'Farah Amalia', '081234567006', 'Jl. Proklamasi No. 46', 2500000.00),
(7, 'Ganesh Maulana', '081234567007', 'Jl. Diponegoro No. 47', 2000000.00),
(8, 'Hana Kusuma', '081234567008', 'Jl. Kolonel Sugiono No. 48', 1000000.00),
(9, 'Irfan Ramadhan', '081234567009', 'Jl. Gatot Subroto No. 49', 3500000.00),
(10, 'Jefri Hidayat', '081234567010', 'Jl. Juanda No. 50', 4800000.00),
(11, 'Kartika Dewi', '081234567011', 'Jl. Gajah Mada No. 51', 4000000.00),
(12, 'Leo Pratama', '081234567012', 'Jl. Imam Bonjol No. 52', 5000000.00),
(13, 'Maya Sari', '081234567013', 'Jl. Rasuna Said No. 53', 2000000.00),
(14, 'Nia Anggraini', '081234567014', 'Jl. Bung Karno No. 54', 1000000.00),
(15, 'Oki Wirawan', '081234567015', 'Jl. Slamet Riyadi No. 55', 4500000.00),
(16, 'Putri Ayu', '081234567016', 'Jl. S. Parman No. 56', 3000000.00),
(17, 'Qori Maulida', '081234567017', 'Jl. HR. Rasuna Said No. 57', 4800000.00),
(18, 'Ria Anindya', '081234567018', 'Jl. Merdeka No. 58', 3500000.00),
(19, 'Sinta Maharani', '081234567019', 'Jl. Sudirman No. 59', 5000000.00),
(20, 'Tono Wibowo', '081234567020', 'Jl. Tendean No. 60', 4000000.00),
(21, 'Uli Kurniawan', '081234567021', 'Jl. Imam Bonjol No. 61', 2500000.00),
(22, 'Vina Kartika', '081234567022', 'Jl. Hayam Wuruk No. 62', 1000000.00),
(23, 'Wawan Prasetyo', '081234567023', 'Jl. Cokroaminoto No. 63', 3000000.00),
(24, 'Xena Rahmawati', '081234567024', 'Jl. Gajah Mada No. 64', 4500000.00),
(25, 'Yuni Safitri', '081234567025', 'Jl. Diponegoro No. 65', 2000000.00),
(26, 'Zul Fahmi', '081234567026', 'Jl. Hayam Wuruk No. 66', 4000000.00),
(27, 'Aldi Syahputra', '081234567027', 'Jl. Kebon Sirih No. 67', 4800000.00),
(28, 'Budi Kurniawan', '081234567028', 'Jl. Sisingamangaraja No. 68', 3500000.00),
(29, 'Citra Ayuningtyas', '081234567029', 'Jl. Kolonel Sugiono No. 69', 3000000.00),
(30, 'Dewi Wulandari', '081234567030', 'Jl. Gatot Subroto No. 70', 1000000.00),
(31, 'Firdaus Mahardika', '081234567031', 'Jl. Pahlawan No. 71', 1200000.00),
(32, 'Gilang Prasetya', '081234567032', 'Jl. Jenderal Sudirman No. 72', 2300000.00),
(33, 'Hafiz Suryana', '081234567033', 'Jl. Ir. H. Juanda No. 73', 2900000.00),
(34, 'Inayah Pertiwi', '081234567034', 'Jl. Gajah Mada No. 74', 3400000.00),
(35, 'Joko Priyanto', '081234567035', 'Jl. A. Yani No. 75', 4000000.00),
(36, 'Karina Widjaja', '081234567036', 'Jl. Sisingamangaraja No. 76', 2700000.00),
(37, 'Lutfi Nurjaman', '081234567037', 'Jl. MH. Thamrin No. 77', 1900000.00),
(38, 'Mira Suharti', '081234567038', 'Jl. Gatot Subroto No. 78', 2200000.00),
(39, 'Nando Wijaya', '081234567039', 'Jl. Jendral Gatot Subroto No. 79', 3200000.00),
(40, 'Olivia Maheswari', '081234567040', 'Jl. HOS Cokroaminoto No. 80', 4100000.00),
(41, 'Pandu Prasetyo', '081234567041', 'Jl. Gajah Mada No. 81', 3700000.00),
(42, 'Qaisara Lestari', '081234567042', 'Jl. Medan Merdeka No. 82', 2800000.00),
(43, 'Rizky Pranata', '081234567043', 'Jl. Diponegoro No. 83', 3000000.00),
(44, 'Sari Dewi', '081234567044', 'Jl. Juanda No. 84', 2100000.00),
(45, 'Tegar Maulana', '081234567045', 'Jl. Proklamasi No. 85', 4900000.00),
(46, 'Utami Setyaningrum', '081234567046', 'Jl. Kebon Sirih No. 86', 3600000.00),
(47, 'Vino Aditya', '081234567047', 'Jl. Cokroaminoto No. 87', 2600000.00),
(48, 'Wulan Puspita', '081234567048', 'Jl. Juanda No. 88', 1500000.00),
(49, 'Xaverius Pranowo', '081234567049', 'Jl. A. Yani No. 89', 4000000.00),
(50, 'Yoga Setiawan', '081234567050', 'Jl. Slamet Riyadi No. 90', 2000000.00);

-- --------------------------------------------------------

--
-- Table structure for table `pemasok`
--

CREATE TABLE `pemasok` (
  `id_pemasok` int(11) NOT NULL,
  `email_pemasok` varchar(100) DEFAULT NULL,
  `no_telp_pemasok` varchar(15) DEFAULT NULL,
  `alamat_pemasok` text DEFAULT NULL,
  `nama_pemasok` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pemasok`
--

INSERT INTO `pemasok` (`id_pemasok`, `email_pemasok`, `no_telp_pemasok`, `alamat_pemasok`, `nama_pemasok`) VALUES
(1, 'pemasok1@example.com', '081234567890', 'Jl. Merdeka No. 1', 'PT. Bumi Sejahtera'),
(2, 'pemasok2@example.com', '081234567891', 'Jl. Sudirman No. 2', 'CV. Langgeng Jaya'),
(3, 'pemasok3@example.com', '081234567892', 'Jl. Thamrin No. 3', 'PT. Sentosa Abadi'),
(4, 'pemasok4@example.com', '081234567893', 'Jl. Gatot Subroto No. 4', 'UD. Maju Terus'),
(5, 'pemasok5@example.com', '081234567894', 'Jl. Sisingamangaraja No. 5', 'PT. Sinar Pagi'),
(6, 'pemasok6@example.com', '081234567895', 'Jl. Rasuna Said No. 6', 'CV. Karya Mandiri'),
(7, 'pemasok7@example.com', '081234567896', 'Jl. HR. Rasuna Said No. 7', 'PT. Sukses Bersama'),
(8, 'pemasok8@example.com', '081234567897', 'Jl. Diponegoro No. 8', 'UD. Jaya Makmur'),
(9, 'pemasok9@example.com', '081234567898', 'Jl. MH. Thamrin No. 9', 'PT. Anugerah Abadi'),
(10, 'pemasok10@example.com', '081234567899', 'Jl. Juanda No. 10', 'CV. Citra Indah'),
(11, 'pemasok11@example.com', '081234567800', 'Jl. Gajah Mada No. 11', 'PT. Mega Jaya'),
(12, 'pemasok12@example.com', '081234567801', 'Jl. Hayam Wuruk No. 12', 'CV. Bersama Untung'),
(13, 'pemasok13@example.com', '081234567802', 'Jl. Teuku Umar No. 13', 'PT. Cipta Karya'),
(14, 'pemasok14@example.com', '081234567803', 'Jl. S. Parman No. 14', 'UD. Sejahtera Abadi'),
(15, 'pemasok15@example.com', '081234567804', 'Jl. Slamet Riyadi No. 15', 'PT. Prima Sejahtera'),
(16, 'pemasok16@example.com', '081234567805', 'Jl. Kolonel Sugiono No. 16', 'CV. Jaya Abadi'),
(17, 'pemasok17@example.com', '081234567806', 'Jl. Kebon Sirih No. 17', 'PT. Mandiri Jaya'),
(18, 'pemasok18@example.com', '081234567807', 'Jl. Medan Merdeka No. 18', 'UD. Sumber Makmur'),
(19, 'pemasok19@example.com', '081234567808', 'Jl. Tendean No. 19', 'PT. Unggul Jaya'),
(20, 'pemasok20@example.com', '081234567809', 'Jl. Imam Bonjol No. 20', 'CV. Maju Bersama'),
(21, 'pemasok21@example.com', '081234567810', 'Jl. Cikini Raya No. 21', 'PT. Cahaya Terang'),
(22, 'pemasok22@example.com', '081234567811', 'Jl. Juanda No. 22', 'CV. Karya Sejahtera'),
(23, 'pemasok23@example.com', '081234567812', 'Jl. Bung Karno No. 23', 'PT. Sinar Abadi'),
(24, 'pemasok24@example.com', '081234567813', 'Jl. HOS Cokroaminoto No. 24', 'UD. Jaya Sentosa'),
(25, 'pemasok25@example.com', '081234567814', 'Jl. Proklamasi No. 25', 'PT. Kencana Sakti'),
(26, 'pemasok26@example.com', '081234567815', 'Jl. Diponegoro No. 26', 'CV. Sumber Jaya'),
(27, 'pemasok27@example.com', '081234567816', 'Jl. Sudirman No. 27', 'PT. Sukses Sejahtera'),
(28, 'pemasok28@example.com', '081234567817', 'Jl. Merdeka No. 28', 'UD. Prima Jaya'),
(29, 'pemasok29@example.com', '081234567818', 'Jl. Thamrin No. 29', 'PT. Bintang Mandiri'),
(30, 'pemasok30@example.com', '081234567819', 'Jl. Gatot Subroto No. 30', 'CV. Maju Sukses'),
(31, 'pemasok31@example.com', '081234567820', 'Jl. Sisingamangaraja No. 31', 'PT. Sejahtera Abadi'),
(32, 'pemasok32@example.com', '081234567821', 'Jl. Rasuna Said No. 32', 'UD. Karya Jaya'),
(33, 'pemasok33@example.com', '081234567822', 'Jl. HR. Rasuna Said No. 33', 'PT. Sukses Utama'),
(34, 'pemasok34@example.com', '081234567823', 'Jl. Diponegoro No. 34', 'CV. Bina Karya'),
(35, 'pemasok35@example.com', '081234567824', 'Jl. Thamrin No. 35', 'PT. Anugerah Sejahtera'),
(36, 'pemasok36@example.com', '081234567825', 'Jl. Juanda No. 36', 'UD. Mitra Usaha'),
(37, 'pemasok37@example.com', '081234567826', 'Jl. Hayam Wuruk No. 37', 'PT. Unggul Kencana'),
(38, 'pemasok38@example.com', '081234567827', 'Jl. Kolonel Sugiono No. 38', 'CV. Karya Maju'),
(39, 'pemasok39@example.com', '081234567828', 'Jl. S. Parman No. 39', 'PT. Sejahtera Utama'),
(40, 'pemasok40@example.com', '081234567829', 'Jl. Imam Bonjol No. 40', 'UD. Makmur Abadi'),
(41, 'pemasok41@example.com', '081234567830', 'Jl. Pattimura No. 41', 'PT. Mega Jaya'),
(42, 'pemasok42@example.com', '081234567831', 'Jl. Panglima Polim No. 42', 'CV. Bersama Untung'),
(43, 'pemasok43@example.com', '081234567832', 'Jl. Tanah Abang No. 43', 'PT. Cipta Karya'),
(44, 'pemasok44@example.com', '081234567833', 'Jl. Budi Utomo No. 44', 'UD. Sejahtera Abadi'),
(45, 'pemasok45@example.com', '081234567834', 'Jl. Suryopranoto No. 45', 'PT. Prima Sejahtera'),
(46, 'pemasok46@example.com', '081234567835', 'Jl. Kramat No. 46', 'CV. Jaya Abadi'),
(47, 'pemasok47@example.com', '081234567836', 'Jl. Senen Raya No. 47', 'PT. Mandiri Jaya'),
(48, 'pemasok48@example.com', '081234567837', 'Jl. K.H. Wahid Hasyim No. 48', 'UD. Sumber Makmur'),
(49, 'pemasok49@example.com', '081234567838', 'Jl. Sabang No. 49', 'PT. Unggul Jaya'),
(50, 'pemasok50@example.com', '081234567839', 'Jl. Kebon Kacang No. 50', 'CV. Maju Bersama');

-- --------------------------------------------------------

--
-- Table structure for table `pembeli`
--

CREATE TABLE `pembeli` (
  `id_pembeli` varchar(9) NOT NULL,
  `nama_pembeli` varchar(100) DEFAULT NULL,
  `alamat_pembeli` varchar(100) DEFAULT NULL,
  `no_telp_pembeli` char(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pembeli`
--

INSERT INTO `pembeli` (`id_pembeli`, `nama_pembeli`, `alamat_pembeli`, `no_telp_pembeli`) VALUES
('B000001', 'Alex Johnson', 'Jl. Merdeka No. 1', '081234567890'),
('B000002', 'Bella Kartika', 'Jl. Sudirman No. 2', '081234567891'),
('B000003', 'Charlie Pratama', 'Jl. Thamrin No. 3', '081234567892'),
('B000004', 'Dina Wijaya', 'Jl. Gatot Subroto No. 4', '081234567893'),
('B000005', 'Eko Nugroho', 'Jl. Sisingamangaraja No. 5', '081234567894'),
('B000006', 'Fina Wulandari', 'Jl. Rasuna Said No. 6', '081234567895'),
('B000007', 'Gilang Setiawan', 'Jl. HR. Rasuna Said No. 7', '081234567896'),
('B000008', 'Hana Sari', 'Jl. Diponegoro No. 8', '081234567897'),
('B000009', 'Ivan Mahendra', 'Jl. MH. Thamrin No. 9', '081234567898'),
('B000010', 'Joko Prabowo', 'Jl. Juanda No. 10', '081234567899'),
('B000011', 'Kiki Ramadhani', 'Jl. Kebon Sirih No. 11', '081234567800'),
('B000012', 'Luna Sari', 'Jl. Medan Merdeka No. 12', '081234567801'),
('B000013', 'Maya Lestari', 'Jl. Tendean No. 13', '081234567802'),
('B000014', 'Nino Santoso', 'Jl. Imam Bonjol No. 14', '081234567803'),
('B000015', 'Omar Fadillah', 'Jl. Cikini Raya No. 15', '081234567804'),
('B000016', 'Putri Maheswari', 'Jl. Juanda No. 16', '081234567805'),
('B000017', 'Qori Aulia', 'Jl. Bung Karno No. 17', '081234567806'),
('B000018', 'Rara Pratiwi', 'Jl. HOS Cokroaminoto No. 18', '081234567807'),
('B000019', 'Susi Kartini', 'Jl. Proklamasi No. 19', '081234567808'),
('B000020', 'Tio Surya', 'Jl. Diponegoro No. 20', '081234567809'),
('B000021', 'Uli Puspita', 'Jl. Sudirman No. 21', '081234567810'),
('B000022', 'Vina Wijayanti', 'Jl. Merdeka No. 22', '081234567811'),
('B000023', 'Wawan Nugraha', 'Jl. Thamrin No. 23', '081234567812'),
('B000024', 'Xena Dwi', 'Jl. Gatot Subroto No. 24', '081234567813'),
('B000025', 'Yuni Kurniawati', 'Jl. Sisingamangaraja No. 25', '081234567814'),
('B000026', 'Zulfi Hidayat', 'Jl. Rasuna Said No. 26', '081234567815'),
('B000027', 'Adi Setiawan', 'Jl. HR. Rasuna Said No. 27', '081234567816'),
('B000028', 'Beni Hendra', 'Jl. Juanda No. 28', '081234567817'),
('B000029', 'Cici Anggraini', 'Jl. Kebon Sirih No. 29', '081234567818'),
('B000030', 'Dodi Andrian', 'Jl. Medan Merdeka No. 30', '081234567819'),
('B000031', 'Ema Nuryani', 'Jl. Tendean No. 31', '081234567820'),
('B000032', 'Feri Kurniawan', 'Jl. Imam Bonjol No. 32', '081234567821'),
('B000033', 'Gina Meilani', 'Jl. Cikini Raya No. 33', '081234567822'),
('B000034', 'Hari Prasetyo', 'Jl. Juanda No. 34', '081234567823'),
('B000035', 'Ika Wibowo', 'Jl. Bung Karno No. 35', '081234567824'),
('B000036', 'Jack Wijaya', 'Jl. HOS Cokroaminoto No. 36', '081234567825'),
('B000037', 'Ken Surya', 'Jl. Proklamasi No. 37', '081234567826'),
('B000038', 'Lia Hidayah', 'Jl. Diponegoro No. 38', '081234567827'),
('B000039', 'Miko Nugroho', 'Jl. Sudirman No. 39', '081234567828'),
('B000040', 'Nina Sulastri', 'Jl. Merdeka No. 40', '081234567829'),
('B000041', 'Oka Wijayanto', 'Jl. Thamrin No. 41', '081234567830'),
('B000042', 'Pia Setyowati', 'Jl. Gatot Subroto No. 42', '081234567831'),
('B000043', 'Rian Akbar', 'Jl. Sisingamangaraja No. 43', '081234567832'),
('B000044', 'Sari Dewi', 'Jl. Rasuna Said No. 44', '081234567833'),
('B000045', 'Tara Putri', 'Jl. HR. Rasuna Said No. 45', '081234567834'),
('B000046', 'Umar Santoso', 'Jl. Juanda No. 46', '081234567835'),
('B000047', 'Vero Wijaya', 'Jl. Kebon Sirih No. 47', '081234567836'),
('B000048', 'Wati Susanti', 'Jl. Medan Merdeka No. 48', '081234567837'),
('B000049', 'Xander Syahputra', 'Jl. Tendean No. 49', '081234567838'),
('B000050', 'Yola Indah', 'Jl. Imam Bonjol No. 50', '081234567839');

-- --------------------------------------------------------

--
-- Table structure for table `produk`
--

CREATE TABLE `produk` (
  `id_produk` int(11) NOT NULL,
  `harga_produk` decimal(10,2) DEFAULT NULL,
  `stok_produk` int(11) DEFAULT NULL,
  `nama_produk` varchar(100) DEFAULT NULL,
  `id_pemasok` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `produk`
--

INSERT INTO `produk` (`id_produk`, `harga_produk`, `stok_produk`, `nama_produk`, `id_pemasok`) VALUES
(101, 150000.00, 50, 'Kopi Arabika', 1),
(102, 200000.00, 30, 'Teh Hijau', 2),
(103, 100000.00, 100, 'Gula Pasir', 3),
(104, 75000.00, 150, 'Minyak Goreng', 4),
(105, 120000.00, 80, 'Susu UHT', 5),
(106, 50000.00, 200, 'Beras', 6),
(107, 30000.00, 500, 'Garam', 7),
(108, 250000.00, 20, 'Madu Murni', 8),
(109, 180000.00, 40, 'Kacang Almond', 9),
(110, 140000.00, 60, 'Keju Cheddar', 10),
(111, 85000.00, 70, 'Yogurt', 11),
(112, 90000.00, 90, 'Sereal', 12),
(113, 110000.00, 30, 'Kopi Robusta', 13),
(114, 50000.00, 120, 'Teh Hitam', 14),
(115, 130000.00, 60, 'Minyak Zaitun', 15),
(116, 45000.00, 300, 'Gula Merah', 16),
(117, 120000.00, 100, 'Susu Kedelai', 17),
(118, 25000.00, 400, 'Tepung Terigu', 18),
(119, 160000.00, 40, 'Pasta', 19),
(120, 180000.00, 50, 'Bubuk Coklat', 20),
(121, 220000.00, 25, 'Sirup Maple', 21),
(122, 100000.00, 130, 'Teh Herbal', 22),
(123, 70000.00, 90, 'Jus Jeruk', 23),
(124, 20000.00, 350, 'Garam Laut', 24),
(125, 150000.00, 80, 'Madu Organik', 25),
(126, 30000.00, 200, 'Margarin', 26),
(127, 140000.00, 55, 'Susu Cair', 27),
(128, 85000.00, 150, 'Yogurt Greek', 28),
(129, 120000.00, 45, 'Susu Almond', 29),
(130, 110000.00, 75, 'Kopi Luwak', 30),
(131, 95000.00, 120, 'Teh Oolong', 31),
(132, 155000.00, 80, 'Minyak Kelapa', 32),
(133, 40000.00, 220, 'Gula Kelapa', 33),
(134, 130000.00, 100, 'Susu Beruang', 34),
(135, 20000.00, 500, 'Beras Hitam', 35),
(136, 35000.00, 200, 'Garam Himalaya', 36),
(137, 175000.00, 70, 'Cuka Apel', 37),
(138, 180000.00, 40, 'Kacang Mete', 38),
(139, 150000.00, 60, 'Keju Mozzarella', 39),
(140, 170000.00, 50, 'Biji Chia', 40),
(141, 95000.00, 130, 'Teh Matcha', 41),
(142, 100000.00, 110, 'Jus Apel', 42),
(143, 50000.00, 250, 'Tepung Beras', 43),
(144, 60000.00, 200, 'Minyak Wijen', 44),
(145, 110000.00, 90, 'Susu Evaporasi', 45),
(146, 25000.00, 300, 'Tepung Jagung', 46),
(147, 130000.00, 75, 'Sirup Jagung', 47),
(148, 120000.00, 50, 'Susu Kental Manis', 48),
(149, 70000.00, 100, 'Margarin Mentega', 49),
(150, 160000.00, 40, 'Keju Parmesan', 50);

-- --------------------------------------------------------

--
-- Table structure for table `transaksi`
--

CREATE TABLE `transaksi` (
  `id_transaksi` int(11) NOT NULL,
  `jumlah_dibeli` int(11) DEFAULT NULL,
  `tgl_transaksi` date DEFAULT NULL,
  `jenis_transaksi` varchar(50) DEFAULT NULL,
  `id_pegawai` int(11) DEFAULT NULL,
  `id_pembeli` varchar(9) DEFAULT NULL,
  `id_produk` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `transaksi`
--

INSERT INTO `transaksi` (`id_transaksi`, `jumlah_dibeli`, `tgl_transaksi`, `jenis_transaksi`, `id_pegawai`, `id_pembeli`, `id_produk`) VALUES
(1001, 5, '2024-11-03', 'Penjualan', 1, 'B000001', 101),
(1002, 3, '2024-11-06', 'Pembelian', 2, 'B000002', 102),
(1003, 10, '2024-11-19', 'Penjualan', 3, 'B000003', 103),
(1004, 2, '2024-11-22', 'Pembelian', 4, 'B000004', 104),
(1005, 7, '2024-11-12', 'Penjualan', 5, 'B000005', 105),
(1006, 4, '2024-11-15', 'Pembelian', 6, 'B000006', 106),
(1007, 15, '2024-11-20', 'Penjualan', 7, 'B000007', 107),
(1008, 1, '2024-11-25', 'Pembelian', 8, 'B000008', 108),
(1009, 9, '2024-11-10', 'Penjualan', 9, 'B000009', 109),
(1010, 6, '2024-11-17', 'Pembelian', 10, 'B000010', 110),
(1011, 8, '2024-11-08', 'Penjualan', 11, 'B000011', 111),
(1012, 3, '2024-11-23', 'Pembelian', 12, 'B000012', 112),
(1013, 12, '2024-11-27', 'Penjualan', 13, 'B000013', 113),
(1014, 5, '2024-11-13', 'Pembelian', 14, 'B000014', 114),
(1015, 6, '2024-11-01', 'Penjualan', 15, 'B000015', 115),
(1016, 4, '2024-11-21', 'Pembelian', 16, 'B000016', 116),
(1017, 10, '2024-11-05', 'Penjualan', 17, 'B000017', 117),
(1018, 2, '2024-11-30', 'Pembelian', 18, 'B000018', 118),
(1019, 9, '2024-11-18', 'Penjualan', 19, 'B000019', 119),
(1020, 5, '2024-11-16', 'Pembelian', 20, 'B000020', 120),
(1021, 4, '2024-11-11', 'Penjualan', 21, 'B000021', 121),
(1022, 7, '2024-11-04', 'Pembelian', 22, 'B000022', 122),
(1023, 3, '2024-11-09', 'Penjualan', 23, 'B000023', 123),
(1024, 11, '2024-11-24', 'Pembelian', 24, 'B000024', 124),
(1025, 8, '2024-11-07', 'Penjualan', 25, 'B000025', 125),
(1026, 2, '2024-11-29', 'Pembelian', 26, 'B000026', 126),
(1027, 9, '2024-11-12', 'Penjualan', 27, 'B000027', 127),
(1028, 5, '2024-11-14', 'Pembelian', 28, 'B000028', 128),
(1029, 7, '2024-11-02', 'Penjualan', 29, 'B000029', 129),
(1030, 4, '2024-11-26', 'Pembelian', 30, 'B000030', 130),
(1031, 10, '2024-11-28', 'Penjualan', 31, 'B000031', 131),
(1032, 6, '2024-11-16', 'Pembelian', 32, 'B000032', 132),
(1033, 2, '2024-11-05', 'Penjualan', 33, 'B000033', 133),
(1034, 12, '2024-11-22', 'Pembelian', 34, 'B000034', 134),
(1035, 8, '2024-11-25', 'Penjualan', 35, 'B000035', 135),
(1036, 5, '2024-11-03', 'Pembelian', 36, 'B000036', 136),
(1037, 7, '2024-11-09', 'Penjualan', 37, 'B000037', 137),
(1038, 11, '2024-11-18', 'Pembelian', 38, 'B000038', 138),
(1039, 6, '2024-11-21', 'Penjualan', 39, 'B000039', 139),
(1040, 3, '2024-11-30', 'Pembelian', 40, 'B000040', 140),
(1041, 9, '2024-11-04', 'Penjualan', 41, 'B000041', 141),
(1042, 5, '2024-11-26', 'Pembelian', 42, 'B000042', 142),
(1043, 12, '2024-11-07', 'Penjualan', 43, 'B000043', 143),
(1044, 3, '2024-11-20', 'Pembelian', 44, 'B000044', 144),
(1045, 6, '2024-11-15', 'Penjualan', 45, 'B000045', 145),
(1046, 7, '2024-11-08', 'Pembelian', 46, 'B000046', 146),
(1047, 5, '2024-11-12', 'Penjualan', 47, 'B000047', 147),
(1048, 2, '2024-11-11', 'Pembelian', 48, 'B000048', 148),
(1049, 8, '2024-11-06', 'Penjualan', 49, 'B000049', 149),
(1050, 3, '2024-11-13', 'Pembelian', 50, 'B000050', 150);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD PRIMARY KEY (`id_pegawai`);

--
-- Indexes for table `pemasok`
--
ALTER TABLE `pemasok`
  ADD PRIMARY KEY (`id_pemasok`),
  ADD UNIQUE KEY `email_pemasok` (`email_pemasok`);

--
-- Indexes for table `pembeli`
--
ALTER TABLE `pembeli`
  ADD PRIMARY KEY (`id_pembeli`);

--
-- Indexes for table `produk`
--
ALTER TABLE `produk`
  ADD PRIMARY KEY (`id_produk`),
  ADD KEY `id_pemasok` (`id_pemasok`);

--
-- Indexes for table `transaksi`
--
ALTER TABLE `transaksi`
  ADD PRIMARY KEY (`id_transaksi`),
  ADD KEY `id_pegawai` (`id_pegawai`),
  ADD KEY `id_pembeli` (`id_pembeli`),
  ADD KEY `id_produk` (`id_produk`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `produk`
--
ALTER TABLE `produk`
  ADD CONSTRAINT `produk_ibfk_1` FOREIGN KEY (`id_pemasok`) REFERENCES `pemasok` (`id_pemasok`);

--
-- Constraints for table `transaksi`
--
ALTER TABLE `transaksi`
  ADD CONSTRAINT `transaksi_ibfk_1` FOREIGN KEY (`id_pegawai`) REFERENCES `pegawai` (`id_pegawai`),
  ADD CONSTRAINT `transaksi_ibfk_2` FOREIGN KEY (`id_pembeli`) REFERENCES `pembeli` (`id_pembeli`),
  ADD CONSTRAINT `transaksi_ibfk_3` FOREIGN KEY (`id_produk`) REFERENCES `produk` (`id_produk`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
