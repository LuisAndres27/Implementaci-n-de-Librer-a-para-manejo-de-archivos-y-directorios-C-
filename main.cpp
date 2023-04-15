#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();

using namespace std;

int main()
{
    int cantidad;
    cout << "-----------------------------------------" << endl;
    cout << "Bienvenido calcularemos tu IMC" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Se creara un archivo con tu IMC y tus datos " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Cuantos archivos quiere crear? " << endl;
    cout << "-----------------------------------------" << endl;
    cin >> cantidad;
    crearArchivos(cantidad);
    cout << contarArchivosDeDirectorio();
    cout << endl;
    listarArchivosDeDirectorio();
    mostrarDetalles();

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    int i= cantidad;

    double peso, altura, IMC;
    string tipoObesidad;
    cout << "Ingrese tu peso en kg: " << endl;
    cin >> peso;

    cout << "Ingrese tu altura en metros (decimales ejem 1.80): " << endl,
    cin >> altura;

    IMC = peso / (altura * altura);

    if (IMC < 18.5) {
        tipoObesidad = "Bajo peso";
    } else if (IMC < 25) {
        tipoObesidad = "Normal";
    } else if (IMC < 30) {
        tipoObesidad = "Sobrepeso";
    } else if (IMC < 35) {
        tipoObesidad = "Obesidad tipo I";
    } else if (IMC < 40) {
        tipoObesidad = "Obesidad tipo II" ;
    } else {
        tipoObesidad = "Obesidad tipo III";
    }

    for(i=0; i<cantidad; i++){
        ofstream file;
        file.open("C:/Users/luis2/OneDrive/Documentos/progra/" + nombreArchivo + to_string(i) +".txt");
        file << "-----------------------------------------------------"  << endl;
        file << "Su altura es de: " << altura << endl;
        file << "-----------------------------------------------------"  << endl;
        file << "Su peso es de: " << peso << endl;
        file << "-----------------------------------------------------"  << endl;
        file << "Su indice de masa corporal es: " << IMC << endl;
        file << "-----------------------------------------------------"  << endl;
        file << "Su tipo de obesidad es de: " << tipoObesidad << endl;
        file << "-----------------------------------------------------"  << endl;
        file.close();
    }
    cout << "-----------------------------------------" << endl;
    cout<<"Archivos creados : " + to_string(i) << endl;
    cout << "-----------------------------------------" << endl;
}









void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:/Users/luis2/OneDrive/Documentos/progra/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n'; //El primer archivo
        // Listamos todos los archivos

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/luis2/OneDrive/Documentos/progra/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:/Users/luis2/OneDrive/Documentos/progra/");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
        }
    }
}

