// ConsoleTpSQLite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include "sqlite3.h"
using namespace std;
// Create a callback function  
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
	
using namespace std;

	
int main()
	{
        // Pointer to SQLite connection
        sqlite3* db;
        int reponse;
        // Save any error messages
        char* zErrMsg = 0;

        // Save the result of opening the file
        int rc;

        // Save any SQL
        string EmailLue,NomLue,PrenomLue,dateNaissanceLue, sql;

        // Save the result of opening the file
        rc = sqlite3_open("classe.db", &db);

        if (rc) {
            // Show an error message
            cout << "DB Error: " << sqlite3_errmsg(db) << endl;
            // Close the connection
            sqlite3_close(db);
            // Return an error
            return(1);
        }
        else {
            cout << "insertion ok "<<endl;
        }

        // Save SQL to create a table
        sql = "CREATE TABLE IF NOT EXISTS Etudiant(emailEtudiant VARCHAR(255) PRIMARY KEY,nom VARCHAR(255) NOT NULL,prenom VARCHAR(255) NOT NULL,dateNaissance VARCHAR(255) NOT NULL);";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

        cout << "Combien d'etudiants voulez-vous rentrer ?" << endl;

        cin >> reponse;

        if (reponse > 0 && reponse <= 3) {

            cout << "Insertion d'enregistrement dans la table ..." << endl;

            cout << "Email : " << endl;

            cin >> EmailLue;

            cout << "Nom : " << endl;

            cin >> NomLue;

            cout << "Prenom : " << endl;

            cin >> PrenomLue;

            cout << "dateNaissance : " << endl;

            cin >> dateNaissanceLue;

            sql = "INSERT INTO Etudiant(emailEtudiant,nom,prenom,dateNaissance) VALUES('" + EmailLue+ "','" + NomLue + "','" + PrenomLue + "','" + dateNaissanceLue + "');";

            rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
            if (rc) {
                // Show an error message
                cout << "DB Error: " << sqlite3_errmsg(db) << endl;
                // Close the connection
                sqlite3_close(db);
                // Return an error
                return(1);
            }
            else {
                cout << "insertion ok "<<endl;
                // afichage de la table
                sql = "Select * from Etudiant;";
                rc = sqlite3_exec(db, sql.c_str(), callback, 0, NULL);
            }
        }

        // Close the SQL connection

        sqlite3_close(db);

        return 0;

}

