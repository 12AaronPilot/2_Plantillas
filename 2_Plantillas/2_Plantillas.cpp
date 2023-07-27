#include <iostream>
#include <fstream>


//class plantilla para guardar datos
template <typename T>
class DataHelper {
    T data;

public:
    DataHelper(T newdata) 
    {
        data = newdata;
    }

    void print() 
    {
        std::cout << data << "\n";
    }

    //imprime al archivo dado por la ruta
    void printFile(const char* filename, bool binary = false)
    {
      if (!binary)
      {
        std::fstream myfile(filename, std::ios_base::out);
        if (myfile.is_open())
        {
            myfile << sizeof (T) << data;
            myfile.close();
        }
        else
        {
            std::cout << "no se puede abrir el archivo" << "\n";
        }
      }
      else
      {
          std::fstream myfile(filename, std::ios_base::out | std::ios_base::binary);
          if (myfile.is_open())
          {
              myfile << sizeof(T) << data;
              myfile.close();
          }
      }
    }
};


int main()
{
    std::cout << "Tamanos\n";
    std::cout << "int : " << sizeof(int) << "\n";
    std::cout << "float : " << sizeof(float) << "\n";
    std::cout << "double : " << sizeof(double) << "\n";
    std::cout << "int : " << sizeof(int) << "\n";
    std::cout << "char : " << sizeof(char) << "\n";
    std::cout << "string : " << sizeof(int) << "\n";

    DataHelper<char>* mychar = new DataHelper<char>('w');
    DataHelper<float>* myfloat = new DataHelper<float>(3.14159);

    DataHelper<char* >*  mychars = new DataHelper<char*>((char*)"Hola mundooo");




    mychar->print();
    myfloat->print();
    mychars->print();

    myfloat->printFile("float.txt");
    myfloat->printFile("float.bin", true);

    //abrir archivo
    std::fstream archivo("criper.bmp", std::ios_base::in| std::ios_base::out);
    if (archivo.is_open())
    {

        //buffer  de 8 bytes
        char* buffer = new char[8];
        // mientras no termine el archivo, imprimir en bloques de 8 bytes.
        while (!archivo.eof())
        {
            archivo.read(buffer, 8);
            std::cout << std::hex << (int*)buffer << "\n";
        }
    }

}