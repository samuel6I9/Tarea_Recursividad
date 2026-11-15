#include <iostream>
using namespace std;

class Recursividad
{
    private:
       
    public:
        //1.-CARGAR UN VECTOR
        void cargar(int v[], int tam, int i)
        {
            if(i == tam) return;

            cout << "Posicion " << i << ": ";
            cin >> v[i];

            cargar(v, tam, i+1);
        }
        //2.-MOSTRAR UN VECTOR 
        void mostrar(int v[], int tam, int i)
        {
            if(i == tam) return;

            cout << v[i] << " ";
            mostrar(v, tam, i+1);
        }
        //3.-MOSTRAR EN ORDEN INVERSO
        void inverso(int v[], int i)
        {
            if(i<0)return;
            cout<<v[i]<<" ";
            inverso(v,i-1);
        }  
        //4.- Sumar elementos
        int sumar(int v[], int tamano, int  i)
        {
            if(i==tamano)return 0;

            return v[i]+sumar(v,tamano,i+1);
        }
        //5.- Contar números pares
        int pares(int v[], int tamano, int i)
        {
            if(i == tamano) return 0;

            if(v[i] % 2 == 0) 
            {
                return 1 + pares(v, tamano, i + 1);
            } 
            else 
            {
                return 0 + pares(v, tamano, i + 1);
            }
        }
        //6.- Contar positivos, negativos y ceros
        void positivosNegativosCeros(int v[],int tamano, int i,int &pos, int &nega, int &ceros)
        {
            if(i==tamano) return;
            if(v[i]==0)
            {
                ceros++;
            }
            else if(v[i]>0)
            {
                pos++;
            }
            else
            {
                nega++;
            }

            positivosNegativosCeros(v,tamano,i+1,pos,nega,ceros);
        }
        //07. Calcular el promedio
        double sumaProm(int v[], int tamano, int i)
        {
            if(i==tamano) return 0;

            return v[i]+sumaProm(v,tamano,i+1);
        }
        //08. Contar múltiplos de un número
        int contarDivisible(int v[], int tamano, int i,int divisible)
        {
            if(i==tamano)return 0;

            if(v[i]%divisible==0)
            {
                return 1+contarDivisible(v,tamano,i+1,divisible);
            }
            else
            {
                return 0+contarDivisible(v,tamano,i+1,divisible);
            }
        }
        //09. Encontrar el mayor
        int mayor(int v[], int tamano, int i)
        {
            if (i == tamano - 1) return v[i];

            int m = mayor(v, tamano, i + 1);
            if (v[i] > m) return v[i];
            return m;
        }
        //10. Encontrar el menor y su posición
        void menorYPosicion(int v[], int tamano, int i, int &men, int &pos)
        {
            if(i == tamano) return;

            if(i == 0 || v[i] < men) 
            { 
                men = v[i];
                pos = i;
            }

            menorYPosicion(v, tamano, i + 1, men, pos);
        }
        //11. Buscar un elemento
        int buscarElemento(int v[], int tamano, int i, int elemento)
        {
            if(i==tamano)return 0;
            if(elemento==v[i])
            {
                return i;
            }
            return buscarElemento(v,tamano,i+1,elemento);
        }
        //12. Contar repeticiones
        void contarRepeticiones(int v[], int tamano, int i, int elemento, int &contador)
        {
            if(i==tamano)return;
            if(elemento==v[i])
            {
                contador=contador+1;
            }
            contarRepeticiones(v, tamano, i+1, elemento, contador);
        }
        //13. Reemplazar elementos
        void reemplazarElementos(int v[], int tamano, int i, int ele, int eleRep)
        {
            if(i==tamano)return;
            if(ele==v[i])
            {
                v[i]=eleRep;
            }
            reemplazarElementos(v, tamano, i+1, ele, eleRep );
        }
        //14. Invertir el vector
        void invertirVector(int v[], int tamano, int i)
        {
            if(i>=tamano/2)return;
            
            int aux=v[i];
            v[i]=v[tamano-1-i];
            v[tamano-1-i]=aux;
            invertirVector(v, tamano, i+1);
        }
        //15. Verificar orden ascendente
        bool ordenAscendente(int v[], int tamano, int i)
        {
            if(i==tamano-1)return true;
            if(v[i]>v[i+1])
            {
                return false;    
            }
            return ordenAscendente(v, tamano, i + 1);
        }
        //16. Sumar posiciones pares e impares
        void sumarParImpar(int v[], int tamano, int i, int &par, int &impar)
        {
            if(i==tamano)return;
            if(i%2==0)
            {
                par=par+v[i];
            }
            else
            {
                impar=impar+v[i];
            }
            sumarParImpar(v, tamano, i+1, par , impar);
        }
        //17. Eliminar un elemento por posición
        void elimiarPosicion(int v[], int tamano, int i, int x)
        {
            if(i>=tamano-1)return;
            
            if(i>=x)
            {
                v[i]=v[i+1];
            }
            elimiarPosicion(v,tamano,i+1,x);
        }
        //18. Ordenamiento por selección recursivo
        int posicionMinimo(int v[], int tamano, int i, int minPos) 
        {
            if (i == tamano) return minPos;
            
            if (v[i] < v[minPos]) 
            {
                minPos = i; // Actualizamos la posición del nuevo mínimo
            }
            
            return posicionMinimo(v, tamano, i + 1, minPos);
        }
        void ordenamientoDescendente(int v[], int tamano, int i) 
        {
            if (i >= tamano - 1) return;
            
            // Hallamos la posición del menor elemento desde la posición i en adelante
            int pMin = posicionMinimo(v, tamano, i + 1, i);
            
            // Intercambiamos el elemento actual v[i] con el menor encontrado v[pMin]
            if (pMin != i) 
            {
                int aux = v[i];
                v[i] = v[pMin];
                v[pMin] = aux;
            }
            
            // Llamada recursiva para la siguiente posición
            ordenamientoDescendente(v, tamano, i + 1);
        }
        //19. Búsqueda binaria recursiva
        int posicionMaxima(int v[], int tamano, int i, int maxPos)
        {
            if(i==tamano)return maxPos;

            if(v[i]<v[maxPos])
            {
                maxPos=i;
            }
            return posicionMaxima(v, tamano, i+1, maxPos);
        }
        void ordenamientoDescendente19(int v[], int tamano, int i)
        {
            if(i>=tamano-1)return;
            
            int pMax=posicionMaxima(v, tamano, i+1,i);

            if(pMax!=i)
            {
                int aux=v[i];
                v[i]=v[pMax];
                v[pMax]=aux;
            }
            ordenamientoDescendente19(v, tamano, i+1);
        }
        int buscarElemento19(int v[], int tamano, int i, int elemento)
        {
            if(i==tamano)return 0;
            if(elemento==v[i])
            {
                return i;
            }
            return buscarElemento19(v,tamano,i+1,elemento);
        }
        //20. Eliminar elementos duplicados
        void desplazar(int v[], int tamano, int i, int p)
        {
            if (i >= tamano - 1) return;
            if (i >= p) 
            {
                v[i] = v[i + 1];
            }
            desplazar(v, tamano, i + 1, p);
        }
        void eliminarRepetidos(int v[], int &tamano, int i, int j)
        {
            if (j >= tamano) return;
            
            if (v[j] == v[i])
            {
                desplazar(v, tamano, i, j);
                tamano--;
                eliminarRepetidos(v, tamano, i, j); // Reevaluamos la misma posición j
            }
            else
            {
                eliminarRepetidos(v, tamano, i, j + 1);
            }
        }
        void eliminarDuplicados(int v[], int tamano, int i)
        {
            if (i >= tamano) return;
            
            eliminarRepetidos(v, tamano, i, i + 1);
            eliminarDuplicados(v, tamano, i + 1);
        }
        void separarAux(int v[], int izq, int der)
        {
            if (izq >= der) return;

            if (v[izq] % 2 == 0)
            {
                separarAux(v, izq + 1, der);
            }
            else if (v[der] % 2 != 0)
            {
                separarAux(v, izq, der - 1);
            }
            else
            {
                int aux = v[izq];
                v[izq] = v[der];
                v[der] = aux;
                separarAux(v, izq + 1, der - 1);
            }
        }
        void separarParesImpares(int v[], int tamano, int i)
        {
            separarAux(v, i, tamano - 1);
        }
        //22. Rotación circular del vector
        void desplazarDerecha(int v[], int tamano, int i, int valAnterior)
        {
            if (i == tamano) return;
            
            int temp = v[i];
            v[i] = valAnterior;
            
            desplazarDerecha(v, tamano, i + 1, temp);
        }

        // 22. Rotación circular del vector
        void rotarCircular(int v[], int tamano, int i, int kpos)
        {
            kpos = kpos % tamano;
            
            if (kpos <= 0 || tamano <= 1) return;
            
            int ultimo = v[tamano - 1];
            
            desplazarDerecha(v, tamano, 1, v[0]);
            
            v[0] = ultimo;
            
            rotarCircular(v, tamano, i, kpos - 1);
        }
        //23. Subsecuencia creciente consecutiva
        void subsecuenciaAux(int v[], int tamano, int i, int &maxLen, int &actLen)
        {
            if (i == tamano) return;
            
            if (i == 0) 
            {
                actLen = 1;
                maxLen = 1;
            } else 
            {
                if (v[i] > v[i - 1]) 
                {
                    actLen++;
                } 
                else 
                {
                    actLen = 1;
                }
        
                if (actLen > maxLen) 
                {
                    maxLen = actLen;
                }
            }
            subsecuenciaAux(v, tamano, i + 1, maxLen, actLen);
        }
        int subsecuenciaCreciente(int v[], int tamano)
        {
            if (tamano <= 0) return 0;
            
            int maxLen = 1;
            int actLen = 1;
            
            subsecuenciaAux(v, tamano, 0, maxLen, actLen);
            
            return maxLen;
        }
        //24. Segundo mayor distinto
         void segundoMayorDistinto(int v[], int tamano, int i, int &may, int &seg)
        {
            if (i == tamano) return;
            
            if (i == 0) 
            {
                may = v[0];
                seg = -1; // Centinela inicial por si aún no hay un segundo distinto
            } 
            else 
            {
                if (v[i] > may) 
                {
                    seg = may;   
                    may = v[i];   
                } 
                else if (v[i] < may && (seg == -1 || v[i] > seg)) 
                {
                    seg = v[i];
                }
            }
            
            segundoMayorDistinto(v, tamano, i + 1, may, seg);
        }
        //25. Máxima suma de segmento consecutivo
         void maxSumaSegmentoAux(int v[], int tamano, int i, int &maxGlobal, int &maxActual)
        {
            
            if (i == tamano) return;

            if (i == 0) 
            {
                maxActual = v[0];
                maxGlobal = v[0];
            } 
            else 
            {
                if (maxActual + v[i] > v[i]) 
                {
                    maxActual = maxActual + v[i];
                } 
                else 
                {
                    maxActual = v[i];
                }
                if (maxActual > maxGlobal) 
                {
                    maxGlobal = maxActual;
                }
            }

            maxSumaSegmentoAux(v, tamano, i + 1, maxGlobal, maxActual);
        }
        int maximaSumaSegmento(int v[], int tamano)
        {
            if (tamano <= 0) return 0;
            int maxGlobal = 0;
            int maxActual = 0;
            maxSumaSegmentoAux(v, tamano, 0, maxGlobal, maxActual);
            return maxGlobal;
        }

};
int main()
{
    Recursividad v1;


    int tamanoVec=0;
    int v[100];
    cout<<"ingrese el tamano del vector: ";
    cin>>tamanoVec;

    //1.-CARGAR UN VECTOR
    v1.cargar(v,tamanoVec,0);
    //2.-MOSTRAR UN VECTOR 
    v1.mostrar(v,tamanoVec,0);
    cout<<endl; 
    
/*
    //3.-MOSTRAR EN ORDEN INVERSO
    v1.inverso(v,tamanoVec-1);
    //4.- Sumar elementos
    cout<<"suma: "<<v1.sumar(v,tamanoVec,0);
    //5.- Contar números pares
    cout<<"cantidad de pares: "<< v1.pares(v,tamanoVec,0);
    //6.- Contar positivos, negativos y ceros  
    int positivos=0, negativos=0, ceros=0;
    v1.positivosNegativosCeros(v,tamanoVec,0,positivos,negativos,ceros);
    cout<<"positivos: "<<positivos<<endl;
    cout<<"negativos: "<<negativos<<endl;
    cout<<"ceros: "<<ceros<<endl;  
    //07. Calcular el promedio
    double promedio=v1.sumaProm(v,tamanoVec,0)/tamanoVec;
    cout<<"Promedio: "<<promedio<<endl;
    //08. Contar múltiplos de un número
    int Ndivi=0;
    cout<<"ingrese el numero divisible: ";
    cin>>Ndivi;
    cout<<"multiplos de "<<Ndivi<<": "<<v1.contarDivisible(v, tamanoVec,0,Ndivi);
   //09. Encontrar el mayor
   cout << "Mayor: " << v1.mayor(v, 5, 0);
    //10. Encontrar el menor y su posición
    int men=0;
    int posicion=0;

    v1.menorYPosicion(v, tamanoVec, 0, men, posicion);
    cout << "Menor: " << men << endl;
    cout << "Posicion: " << posicion << endl; 
    //11. Buscar un elemento
    int x=0;
    cout<<"ingrese elemento a buscar: ";
    cin>>x;
    cout<<"posicion: "<<v1.buscarElemento(v, tamanoVec, 0, x);
    //12. Contar repeticiones
    int x=0, repeticiones=0;
    cout<<"ingrese elemento a buscar: ";
    cin>>x;
    v1.contarRepeticiones(v, tamanoVec, 0, x, repeticiones);
    cout<<"apariciones de "<<x<<": "<<repeticiones;
    //13. Reemplazar elementos
    int x=0, y=0;
    cout<<"ingrese elemento : ";
    cin>>x;
    
    cout<<"ingrese nuevo numero q reemplazara el "<<x<<": ";
    cin>>y;
    v1.reemplazarElementos(v, tamanoVec, 0, x, y);
    cout<<"se reemplazo "<<x<<" por "<<y<<": "<<endl;
    
    v1.mostrar(v,tamanoVec,0);

    //14. Invertir el vector
    cout<<"vector invertido: "<<endl;
    v1.invertirVector(v, tamanoVec, 0);
    v1.mostrar(v,tamanoVec,0);
    //15. Verificar orden ascendente
    if(v1.ordenAscendente(v, tamanoVec, 0))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    //16. Sumar posiciones pares e impares
    
    int pares=0, impares=0;
    v1.sumarParImpar(v,tamanoVec,0,pares,impares);
    cout<<"suma pares: "<<pares<<endl;
    cout<<"suma impares: "<<impares<<endl; 

    //17. Eliminar un elemento por posición    
    int posicion=0;
    cout<<"ingrese la posicion: ";
    cin>>posicion;

    v1.elimiarPosicion(v, tamanoVec, 0, posicion);
    tamanoVec--;
    cout << "R: " << posicion << endl;
    v1.mostrar(v,tamanoVec,0);
    
    // 18. Ordenamiento por selección recursivo
    v1.ordenamientoDescendente(v, tamanoVec, 0);
    cout << "Vector ordenado: ";
    v1.mostrar(v, tamanoVec, 0);

    //19. Búsqueda binaria recursiva
    int x=0;
    cout<<"ingrese elemento a buscar: ";
    cin>>x;
    v1.ordenamientoDescendente19(v, tamanoVec, 0);
    cout << "Vector ordenado: ";
    v1.mostrar(v, tamanoVec, 0);
    cout<<endl;
    cout<<"indice : "<<v1.buscarElemento19(v, tamanoVec, 0, x);    
    //20. Eliminar elementos duplicados
    v1.eliminarDuplicados(v, tamanoVec, 0);

    cout << "N nuevo: " << tamanoVec << endl;
    cout << "Vector logico: ";
    v1.mostrar(v, tamanoVec, 0);
    cout << endl;

    //21. Separar pares e impares
    v1.separarParesImpares(v, tamanoVec, 0);

    cout << "Vector ordenado pares y luego impares: ";
    v1.mostrar(v, tamanoVec, 0);
    cout << endl;  
    //22. Rotación circular del vector
    int k=0;
    cout<<"ingrese k posiciones: ";
    cin>>k;

    v1.rotarCircular(v, tamanoVec, 0, k);
    cout << "Vector rotado k posiciones: ";
    v1.mostrar(v, tamanoVec, 0);
    cout << endl;
    //23. Subsecuencia creciente consecutiva
    int resultado = v1.subsecuenciaCreciente(v, tamanoVec);

    cout << "Longitud maxima: " << resultado << endl;
    //24. Segundo mayor distinto
    int mayor = 0, segundoMayor = 0;
    v1.segundoMayorDistinto(v, tamanoVec, 0, mayor, segundoMayor);
    cout << "Mayor: " << mayor << "; segundo mayor distinto: " << segundoMayor << endl;
    v1.mostrar(v, tamanoVec, 0);
    cout << endl;
*/
    //25. Máxima suma de segmento consecutivo
    int resultado = v1.maximaSumaSegmento(v, tamanoVec);

    cout << "Suma maxima: " << resultado  << endl;








return 0;
}