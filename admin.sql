-- MySQL dump 10.13  Distrib 5.7.11, for Linux (x86_64)
--
-- Host: localhost    Database: Admin
-- ------------------------------------------------------
-- Server version	5.7.11-0ubuntu6

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Applied`
--

DROP TABLE IF EXISTS `Applied`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Applied` (
  `JobID` int(11) NOT NULL,
  `RollNo` char(9) NOT NULL,
  PRIMARY KEY (`JobID`,`RollNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Applied`
--

LOCK TABLES `Applied` WRITE;
/*!40000 ALTER TABLE `Applied` DISABLE KEYS */;
/*!40000 ALTER TABLE `Applied` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CompanyUsers`
--

DROP TABLE IF EXISTS `CompanyUsers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CompanyUsers` (
  `Username` varchar(30) NOT NULL,
  `Password` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Username`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CompanyUsers`
--

LOCK TABLES `CompanyUsers` WRITE;
/*!40000 ALTER TABLE `CompanyUsers` DISABLE KEYS */;
INSERT INTO `CompanyUsers` VALUES ('1','sssss123*'),('2','bat75^'),('3','mat&239'),('4','hat10&rat'),('5','cat55'),('6','fat0909'),('7','oat7575'),('8','pat44'),('9','sat*123');
/*!40000 ALTER TABLE `CompanyUsers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Offers`
--

DROP TABLE IF EXISTS `Offers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Offers` (
  `CID` int(11) NOT NULL,
  `JobID` int(11) NOT NULL,
  `Verified` char(1) DEFAULT NULL,
  PRIMARY KEY (`JobID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Offers`
--

LOCK TABLES `Offers` WRITE;
/*!40000 ALTER TABLE `Offers` DISABLE KEYS */;
INSERT INTO `Offers` VALUES (1,1,'Y'),(1,2,'Y'),(1,3,'Y'),(7,4,'P'),(2,5,'Y'),(3,6,'Y'),(6,7,'Y'),(7,8,'N'),(5,9,'Y'),(7,10,'Y'),(2,11,'P'),(4,12,'Y'),(2,13,'Y'),(1,14,'P'),(4,15,'P'),(9,16,'Y'),(1,17,'Y'),(8,18,'Y');
/*!40000 ALTER TABLE `Offers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Placed`
--

DROP TABLE IF EXISTS `Placed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Placed` (
  `JobID` int(11) NOT NULL,
  `RollNo` char(9) NOT NULL,
  PRIMARY KEY (`JobID`,`RollNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Placed`
--

LOCK TABLES `Placed` WRITE;
/*!40000 ALTER TABLE `Placed` DISABLE KEYS */;
/*!40000 ALTER TABLE `Placed` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `StudentUsers`
--

DROP TABLE IF EXISTS `StudentUsers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `StudentUsers` (
  `Username` char(9) NOT NULL,
  `Password` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Username`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `StudentUsers`
--

LOCK TABLES `StudentUsers` WRITE;
/*!40000 ALTER TABLE `StudentUsers` DISABLE KEYS */;
INSERT INTO `StudentUsers` VALUES ('CDS15M001','water89'),('CDS15M002','black44*'),('CDS15M003','mobile%23'),('CED15I001','qwert'),('CED15I002','asdf'),('CED15I003','qwert123'),('COE15B001','zxcc1234'),('COE15B002','lkjh0987'),('COE15B003','bat99'),('EDS16M001','aaaaaa00**'),('EDS16M002','bbbbbb11$$'),('EDS16M003','&230i9'),('EVD15I001','cat12'),('EVD15I002','gameofthrones12'),('EVD15I003','apple77'),('MDM15B001','box@77'),('MDM15B002','ghjkl555'),('MDM15B003','books90'),('MDS16M001','mnbv09'),('MDS16M002','plokij23'),('MDS16M003','wires33');
/*!40000 ALTER TABLE `StudentUsers` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-04-22 22:57:05
