-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mar. 18 jan. 2022 à 13:06
-- Version du serveur : 5.7.33
-- Version de PHP : 7.4.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `biblio`
--

-- --------------------------------------------------------

--
-- Structure de la table `emprunt`
--

CREATE TABLE `emprunt` (
  `numpersonne` int(11) NOT NULL,
  `numlivre` int(11) NOT NULL,
  `date` date NOT NULL,
  `retour` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `emprunt`
--

INSERT INTO `emprunt` (`numpersonne`, `numlivre`, `date`, `retour`) VALUES
(1, 3, '1999-03-03', '1999-03-30'),
(2, 11, '1999-03-18', NULL),
(3, 3, '1999-03-30', '1999-04-15'),
(3, 4, '1999-03-30', NULL),
(4, 14, '1999-01-01', '1999-03-30'),
(7, 9, '1999-03-05', '1999-03-21'),
(8, 1, '1999-04-02', NULL),
(8, 7, '1999-03-31', '1999-04-18');

-- --------------------------------------------------------

--
-- Structure de la table `livre`
--

CREATE TABLE `livre` (
  `numlivre` int(11) NOT NULL,
  `titre` varchar(255) NOT NULL,
  `auteur` varchar(255) NOT NULL,
  `genre` enum('roman','poésie','nouvelles','autres') NOT NULL,
  `prix` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `livre`
--

INSERT INTO `livre` (`numlivre`, `titre`, `auteur`, `genre`, `prix`) VALUES
(1, 'Les chouans', 'Balzak', 'roman', 80),
(2, 'Germinal', 'Zola', 'roman', 75),
(3, 'L’assommoir', 'Zola', 'roman', 95),
(4, 'humaine', 'Zola', 'roman', 70),
(5, 'Les misérables', 'Hugo', 'roman', 105),
(6, 'La peste', 'Camus', 'roman', 112),
(7, 'Les lettres persanes', 'Maupassant', 'roman', 140),
(8, 'Bel ami', 'Maupassant', 'roman', 76),
(9, 'Les lettres de mon moulin', 'Daudet', 'roman', 100),
(10, 'César', 'Pagnol', 'roman', 100),
(11, 'Marius', 'Pagnol', 'roman', 65),
(12, 'Fanny', 'Pagnol', 'roman', 72),
(13, 'Les fleurs du mal', 'Baudelaire', 'poésie', 130),
(14, 'Paroles', 'Prévert', 'poésie', 120),
(15, 'Les raisins de la colère', 'Steinbeck', 'roman', 135);

-- --------------------------------------------------------

--
-- Structure de la table `personne`
--

CREATE TABLE `personne` (
  `numpersonne` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `ville` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `personne`
--

INSERT INTO `personne` (`numpersonne`, `nom`, `prenom`, `ville`) VALUES
(1, 'Durand', 'Jean-Pierre', 'Toulouse'),
(2, 'Brieusel', 'Chantai', 'Colomiers'),
(3, 'Riols', 'Jacques', 'Jacques'),
(4, 'Denayville', 'Hélêne', 'Toulouse'),
(5, 'Planchon', 'André', 'Muret'),
(6, 'Pêne', 'Gérôme', 'GérômeAlbi'),
(7, 'Bert', 'Jean-Pierre', 'St Orens'),
(8, 'Gonzales', 'Alain', 'Toulouse'),
(9, 'Martin', 'François', 'Balma'),
(10, 'Jourda', 'Véronique', 'Colomiers');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `emprunt`
--
ALTER TABLE `emprunt`
  ADD PRIMARY KEY (`numpersonne`,`numlivre`,`date`),
  ADD KEY `numlivre` (`numlivre`);

--
-- Index pour la table `livre`
--
ALTER TABLE `livre`
  ADD PRIMARY KEY (`numlivre`);

--
-- Index pour la table `personne`
--
ALTER TABLE `personne`
  ADD PRIMARY KEY (`numpersonne`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `livre`
--
ALTER TABLE `livre`
  MODIFY `numlivre` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT pour la table `personne`
--
ALTER TABLE `personne`
  MODIFY `numpersonne` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `emprunt`
--
ALTER TABLE `emprunt`
  ADD CONSTRAINT `emprunt_ibfk_1` FOREIGN KEY (`numpersonne`) REFERENCES `personne` (`numpersonne`),
  ADD CONSTRAINT `emprunt_ibfk_2` FOREIGN KEY (`numlivre`) REFERENCES `livre` (`numlivre`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
