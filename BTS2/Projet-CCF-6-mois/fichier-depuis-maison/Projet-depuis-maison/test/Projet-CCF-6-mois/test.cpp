#include <iostream>
#include <mysql/mysql.h>
using namespace std;

int main() {
    // Déclaration des variables de connexion
    MYSQL* connection;
    MYSQL_ROW row;
    MYSQL_RES* result;
    const char* server = "localhost";
    const char* user = "root";
    const char* password = "admin";
    const char* database = "BDDPrincipal";

    // Initialisation de la connexion
    connection = mysql_init(NULL);

    // Connexion à la base de données
    if (!mysql_real_connect(connection, server, user, password, database, 0, NULL, 0)) {
        cerr << "Impossible de se connecter à la base de données : " << mysql_error(connection) << endl;
        return 1;
    }

    // Exécution de la requête SQL
    if (mysql_query(connection, "SELECT * FROM ma_table")) {
        cerr << "Erreur lors de l'exécution de la requête SQL : " << mysql_error(connection) << endl;
        return 1;
    }

    // Récupération des résultats de la requête
    result = mysql_store_result(connection);

    // Parcours des résultats
    while ((row = mysql_fetch_row(result))) {
        // Affichage des valeurs récupérées
        cout << row[0] << ", " << row[1] << ", " << row[2] << endl;
    }

    // Libération de la mémoire utilisée par les résultats de la requête
    mysql_free_result(result);

    // Fermeture de la connexion
    mysql_close(connection);

    return 0;
}
