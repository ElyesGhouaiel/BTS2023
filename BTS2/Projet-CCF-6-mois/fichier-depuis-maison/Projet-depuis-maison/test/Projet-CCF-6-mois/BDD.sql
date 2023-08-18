#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Employes
#------------------------------------------------------------

CREATE TABLE Employes(
        Id_Employes Int  Auto_increment  NOT NULL ,
        Nom_E       Varchar (255) NOT NULL ,
        Prenom      Varchar (255) NOT NULL ,
        Password    Varchar (50) NOT NULL
	,CONSTRAINT Employes_PK PRIMARY KEY (Id_Employes)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Afficheurs
#------------------------------------------------------------

CREATE TABLE Afficheurs(
        Id_Afficheurs Int  Auto_increment  NOT NULL ,
        Contenu       Varchar (255) NOT NULL ,
        Emplacement   Varchar (255) NOT NULL
	,CONSTRAINT Afficheurs_PK PRIMARY KEY (Id_Afficheurs)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Message_Register
#------------------------------------------------------------

CREATE TABLE Message_Register(
        Id_Message_Register Int  Auto_increment  NOT NULL ,
        Contenu             Varchar (255) NOT NULL ,
        Type                Varchar (10) NOT NULL
	,CONSTRAINT Message_Register_PK PRIMARY KEY (Id_Message_Register)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: HistoriqueMess
#------------------------------------------------------------

CREATE TABLE HistoriqueMess(
        Id_HistoriqueMess   Int  Auto_increment  NOT NULL ,
        Date                Date NOT NULL ,
        Id_Message_Register Int NOT NULL ,
        Id_Afficheurs       Int NOT NULL ,
        Id_Employes         Int NOT NULL
	,CONSTRAINT HistoriqueMess_PK PRIMARY KEY (Id_HistoriqueMess)

	,CONSTRAINT HistoriqueMess_Message_Register_FK FOREIGN KEY (Id_Message_Register) REFERENCES Message_Register(Id_Message_Register)
	,CONSTRAINT HistoriqueMess_Afficheurs0_FK FOREIGN KEY (Id_Afficheurs) REFERENCES Afficheurs(Id_Afficheurs)
	,CONSTRAINT HistoriqueMess_Employes1_FK FOREIGN KEY (Id_Employes) REFERENCES Employes(Id_Employes)
)ENGINE=InnoDB;

