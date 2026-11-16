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

class RecursividadMatriz
{
    private:

    public:
        //26. Cargar una matriz
        //Cargar los elementos de una matriz F×C mediante llamadas recursivas.
        //Ejemplo de entrada F = 2; C = 3; datos por filas: 1, 2, 3, 4, 5, 6
        //Salida esperada
        //Matriz cargada:
        //1 2 3
        //4 5 6    
        void cargar(int m[][100], int filas, int columnas, int f, int c)
        {
            if(f == filas) return;

            if(c == columnas)
            {
                cargar(m, filas, columnas, f+1, 0);
                return;
            }

            cout << "Posicion [" << f << "][" << c << "]: ";
            cin >> m[f][c];

            cargar(m, filas, columnas, f, c+1);
        }
        //27. Mostrar una matriz
        //Mostrar recursivamente la matriz respetando filas y columnas.
        //Ejemplo de entrada F = 2; C = 3; M = [[3, 1, 4], [2, 5, 6]]
        //Salida esperada 3 1 4
        //2 5 6
        void mostrar(int m[][100], int filas, int columnas, int f, int c)
        {
            if(f == filas) return;

            if(c == columnas)
            {
                cout << endl;
                mostrar(m, filas, columnas, f+1, 0);
                return;
            }

            cout << m[f][c] << " ";

            mostrar(m, filas, columnas, f, c+1);
        }
        //28. Sumar todos los elementos
        //Calcular la suma total de una matriz.
        //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
        //Salida esperada Suma total: 21
        int sumarM(int m[][100],int filas, int columnas, int f, int c) 
        {
            if (f==filas) return 0;

            if (c==columnas)
            {
                return sumarM(m, filas, columnas,f+1,0);
            }
            return m[f][c] + sumarM(m, filas, columnas, f, c + 1);
        }

        //29. Contar pares e impares
        //Contar todos los valores pares e impares de la matriz.
        //Ejemplo de entrada F = 2; C = 3; M = [[2, 3, 4], [5, 6, 7]]
        //Salida esperada Pares: 3; impares: 3
        void contarParImparM(int m[][100], int filas, int columnas, int f, int c, int &Cpar, int &Cimpar)
        {
            if(f==filas)return ;
            if(c==columnas)
            {
                contarParImparM(m, filas, columnas, f+1, 0, Cpar, Cimpar);
                return;
            }
            if(m[f][c]%2==0)
            {
                Cpar++;
            }
            else
            {
                Cimpar++;
            }
            contarParImparM(m, filas, columnas, f, c + 1, Cpar, Cimpar);
        }
        
        //30. Encontrar el mayor
        //Obtener el mayor valor de una matriz no vacía.
        //Ejemplo de entrada F = 2; C = 3; M = [[-5, -1, -9], [-3, -7, -2]]
        //Salida esperada Mayor: -1
        void elMayor(int m[][100], int filas, int columnas, int f, int c, int &mayor)
        {
            if(filas==f)return;
            
            if(columnas==c)
            {
                elMayor(m, filas, columnas, f+1, 0, mayor);
                return;
            }
            
            if (f == 0 && c == 0) 
            {
                mayor = m[0][0];
            }
            else if(m[f][c]>mayor)
            {
                mayor=m[f][c];

            }
            elMayor(m, filas, columnas, f, c+1, mayor);
        }
        //31. Encontrar el menor
        //Calcular el mínimo e indicar primera fila y columna donde aparece.
        //Ejemplo de entrada F = 3; C = 3; M = [[5, 2, 8], [1, 7, 6], [1, 4, 9]]
        //Salida esperada Menor: 1; fila: 1; columna: 0
        void elMenor(int m[][100], int filas, int columnas, int f, int c, int &menor, int &PosicionF, int &PosicionC)
        {
            if(filas==f)return;
            
            if(columnas==c)
            {
                elMenor(m, filas, columnas, f+1, 0, menor, PosicionF ,PosicionC);
                return;
            }
            
            if (f == 0 && c == 0) 
            {
                menor = m[0][0];
                PosicionC=0;
                PosicionF=0;
            }
            else if(m[f][c]<menor)
            {
                menor=m[f][c];
                PosicionF=f;
                PosicionC=c;

            }
            elMenor(m, filas, columnas, f, c+1, menor, PosicionF, PosicionC);
        }
        //32. Contar positivos, negativos y ceros
        //Contar los valores positivos, negativos e iguales a cero.
        //Ejemplo de entrada F = 2; C = 4; M = [[-1, 0, 2, 5], [0, -3, 4, -2]]
        //Salida esperada Positivos: 3; negativos: 3; ceros: 2
        void contarPosNegCer(int m[][100], int filas, int columnas, int f, int c, int &ceros, int &posi, int &nega)
        {
            if(f==filas)return;
            if(c==columnas)
            {
                contarPosNegCer(m, filas, columnas, f+1, 0,ceros,posi,nega);
                return;
            }

            if(m[f][c]==0)
            {
                ceros++;
            }
            else if(m[f][c]<0)
            {
                nega++;
            }
            else
            {
                posi++;
            }
            contarPosNegCer(m, filas, columnas, f, c+1,ceros,posi,nega);
                
        }
        //33. Buscar un elemento
        //Encontrar las coordenadas de la primera aparición en recorrido por filas.
        //Ejemplo de entrada F = 2; C = 3; M = [[4, 8, 2], [7, 8, 5]]; X = 8
        //Salida esperada Encontrado en fila 0, columna 1
        void encontrar1Aparicion(int m[][100], int filas, int columnas, int f, int c, int &posicionF, int &posicionC, int x)
        {
            if(f==filas)return;
            if(c==columnas)
            {
                encontrar1Aparicion(m, filas, columnas, f+1, 0, posicionF, posicionC, x);
                return;
            }
            
            if (m[f][c] == x) 
            {
                posicionF = f;
                posicionC = c;
                return;
            }
            encontrar1Aparicion(m, filas, columnas, f, c+1, posicionF, posicionC, x);
        }
        //34. Sumar cada fila
        //Mostrar una suma independiente para cada fila.
        //Ejemplo de entrada F = 3; C = 3; M = [[2, 4, 6], [1, 3, 5], [7, 8, 9]]
        //Salida esperada
        //Fila 0: 12
        //Fila 1: 9
        //Fila 2: 24
        int sumarFilaAux(int m[][100], int filas, int columnas, int f, int c)
        {
            if (c == columnas) return 0;
            
            return m[f][c] + sumarFilaAux(m, filas, columnas, f, c + 1);
        }
        void sumarCadaFila(int m[][100], int filas, int columnas, int f)
        {
            if (f == filas) return;
            
            int sumaF = sumarFilaAux(m, filas, columnas, f, 0);

            cout << "Fila " << f << ": " << sumaF << endl;
            sumarCadaFila(m, filas, columnas, f + 1);
        }

        //35. Sumar cada columna
        //Mostrar una suma independiente para cada columna.
        //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
        //Salida esperada
        //Columna 0: 5
        //Columna 1: 7
        //Columna 2: 9
        int sumarColumnaAux(int m[][100], int filas, int columnas, int f, int c)
        {
            if(f==filas)return 0;

            return m[f][c]+sumarColumnaAux(m, filas, columnas, f+1, c);
        }
        void sumarCadaColumna(int m[][100], int filas, int columnas, int c)
        {
            if(c==columnas)return;
            int sumaC=  sumarColumnaAux(m, filas, columnas, 0, c);

            cout<<"Columna "<< c <<": "<<sumaC <<endl;
            sumarCadaColumna(m, filas, columnas, c+1);
        }

        //36. Diagonal principal
        //Sumar los elementos M[i][i] de una matriz cuadrada.
        //Ejemplo de entrada N = 3; M = [[3, 5, 7], [2, 8, 4], [1, 6, 9]]
        //Salida esperada Suma diagonal principal: 20
        int diagonalPrincipal(int m[][100], int n, int i ) 
        {
            if (i == n) return 0;

            return m[i][i] + diagonalPrincipal(m, n, i+1);
        }
        //37. Diagonal secundaria
        //Sumar los elementos M[i][N-1-i].
        //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        //Salida esperada Suma diagonal secundaria: 15
        int diagonalSecundaria(int m[][100], int n, int i ) 
        {
            if (i == n) return 0;

            return m[i][n-1-i] + diagonalSecundaria(m, n, i+1);
        }

        //38. Sumar sobre y debajo de la diagonal
        //Obtener las sumas de valores estrictamente encima y debajo de la diagonal principal.
        //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        //Salida esperada Encima: 11 (2+3+6); debajo: 19 (4+7+8)
        void sumarEncimaDebajo(int m[][100], int n, int f, int c, int &sumaEncima, int &sumaDebajo)
        {
            if (f == n) return;

            if (c == n) 
            {
                sumarEncimaDebajo(m, n, f + 1, 0, sumaEncima, sumaDebajo);
                return; 
            }
            if (f < c) 
            {
                sumaEncima += m[f][c]; 
            } 
            else if (f > c) 
            {
                sumaDebajo += m[f][c]; 
            }
            sumarEncimaDebajo(m, n, f, c + 1, sumaEncima, sumaDebajo);
        }
        //39. Mostrar el borde
        //Mostrar los valores del borde en orden por filas, sin incluir los internos.
        //Ejemplo de entrada F = 3; C = 4; M = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
        //Salida esperada Borde por filas: 1 2 3 4 5 8 9 10 11 12 
        void mostrarBorde(int m[][100], int filas, int columnas, int f, int c)
        {

            if (f == filas) return;

            if (c == columnas) 
            {
                mostrarBorde(m, filas, columnas, f + 1, 0);
                return; 
            }

            if (f == 0 || f == filas - 1 || c == 0 || c == columnas - 1) 
            {
                cout << m[f][c] << " ";
            }
            mostrarBorde(m, filas, columnas, f, c + 1);
        }
        //40. Sumar el borde
        //Sumar los valores del borde, contando las esquinas una sola vez.
        //Ejemplo de entrada F = 3; C = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        //Salida esperada Suma del borde: 40
        int sumarBorde(int m[][100], int filas, int columnas, int f, int c)
        {
            if (f == filas) return 0;
            if (c == columnas)
            {
                return sumarBorde(m, filas, columnas, f + 1, 0);
            }
            int valorActual = 0;
            if (f == 0 || f == filas - 1 || c == 0 || c == columnas - 1) 
            {
                valorActual = m[f][c];
            }
            return valorActual + sumarBorde(m, filas, columnas, f, c + 1);
        }
        //41. Mostrar la transpuesta
        //Mostrar la transpuesta de una matriz rectangular sin crear otra matriz.
        //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
        //Salida esperada
        //Transpuesta (3×2):
        //1 4
        //2 5
        //3 6
        void mostrarTranspuesta(int m[][100], int filas, int columnas, int i, int j)
        {
            if (i == columnas) return;

            if (j == filas) {
                cout << endl;
                mostrarTranspuesta(m, filas, columnas, i + 1, 0);
                return;
            }

            cout << m[j][i] << " ";
            mostrarTranspuesta(m, filas, columnas, i, j + 1);
        }
        //42. Mayor de cada fila
        //Mostrar el máximo de cada fila recursivamente.
        //Ejemplo de entrada F = 3; C = 3; M = [[2, 9, 4], [8, 1, 5], [3, 7, 6]]
        //Salida esperada
        //Fila 0: 9
        //Fila 1: 8
        //Fila 2: 7
        //Nivel avanzado · Ejercicios 43–50
        int mayorFilaAux(int m[][100], int columnas, int i, int j)
        {
            if (j == columnas - 1) 
            {
                return m[i][j];
            }
            int mayorResto = mayorFilaAux(m, columnas, i, j + 1);
            if (m[i][j] > mayorResto) 
            {
                return m[i][j];
            } 
            else 
            {
                return mayorResto;
            }
        }
        void mayorDeCadaFila(int m[][100], int filas, int columnas, int i)
        {
            if (i == filas) return;

            int mayorF = mayorFilaAux(m, columnas, i, 0);
            cout << "Fila " << i << ": " << mayorF << endl;
            
            mayorDeCadaFila(m, filas, columnas, i + 1);
        }
        //43. Verificar matriz simétrica
        //Comprobar si M[i][j] es igual a M[j][i] en toda matriz cuadrada.
        //Ejemplo de entrada N = 3; M = [[1, 2, 3], [2, 4, 5], [3, 5, 6]]
        //Salida esperada ¿Es simétrica?: Sí
        bool esSimetrica(int m[][100], int n, int f, int c)
        {
            // Caso base global: si ya recorrimos todas las filas y ninguna falló, es simétrica
            if (f == n) return true;

            // Si se acabaron las columnas de esta fila, saltamos a la siguiente fila (columna 0)
            if (c == n) {
                return esSimetrica(m, n, f + 1, 0);
            }

            // Si encontramos un elemento que NO coincide con su reflejo, rompemos retornando false
            if (m[f][c] != m[c][f]) {
                return false;
            }

            // Llamada recursiva avanzando a la siguiente columna de la misma fila
            return esSimetrica(m, n, f, c + 1);
        }

        //44. Rotar 90 grados
        //Mostrar la matriz cuadrada rotada 90° en sentido horario.
        //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        //Salida esperada
        //Rotada:
        //7 4 1
        //8 5 2
        //9 6 3
        void rotar90(int m[][100], int n, int f, int c)
        {
            if (f == n) return;

            if (c == n) 
            {
                cout << endl;
                rotar90(m, n, f + 1, 0);
                return; 
            }

            cout << m[n - 1 - c][f] << " ";
            rotar90(m, n, f, c + 1);
        }
        //45. Recorrido en espiral
        //Mostrar los elementos de una matriz en espiral, desde esquina superior izquierda hacia la derecha.
        //Ejemplo de entrada F = 4; C = 4; M =
        //[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
        //Salida esperada 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
        void espiral(int m[][100], int filas, int columnas, int fInicio, int fFin, int cInicio, int cFin)
        {
            if (fInicio >= fFin || cInicio >= cFin) return;

            for (int j = cInicio; j < cFin; j++) 
            {
                cout << m[fInicio][j] << " ";
            }
            for (int i = fInicio + 1; i < fFin; i++) 
            {
                cout << m[i][cFin - 1] << " ";
            }
            if (fInicio < fFin - 1) 
            {
                for (int j = cFin - 2; j >= cInicio; j--) 
                {
                    cout << m[fFin - 1][j] << " ";
                }
            }
            if (cInicio < cFin - 1) 
            {
                for (int i = fFin - 2; i > fInicio; i--) 
                {
                    cout << m[i][cInicio] << " ";
                }
            }
            espiral(m, filas, columnas, fInicio + 1, fFin - 1, cInicio + 1, cFin - 1);
        }
        //46. Matriz triangular superior
        //Comprobar que los elementos debajo de la diagonal principal sean cero.   
        //Ejemplo de entrada N = 3; M = [[2, 3, 4], [0, 5, 6], [0, 0, 7]]
        //Salida esperada ¿Triangular superior?: Sí
        bool esTriangularSuperior(int m[][100], int n, int f, int c)
        {
            if (f == n) return true;
            if (c == n) 
            {
                return esTriangularSuperior(m, n, f + 1, 0);
            }
            if (f > c && m[f][c] != 0) 
            {
                return false;
            }
            return esTriangularSuperior(m, n, f, c + 1);
        }
        
        //47. Sumar regiones triangulares
        //Sumar elementos con i≤j y con i≥j; la diagonal se incluye en ambas sumas.
        //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        //Salida esperada Triángulo superior: 26; triángulo inferior: 34
        void sumarRegionesTriangulares(int m[][100], int n, int f, int c, int &sumaSuperior, int &sumaInferior)
        {
            if (f == n) return;
            if (c == n) 
            {
                sumarRegionesTriangulares(m, n, f + 1, 0, sumaSuperior, sumaInferior);
                return; 
            }

            if (f < c) 
            {
                sumaSuperior += m[f][c];
            }
            else if (f > c) {
                sumaInferior += m[f][c];
            }
            else {
                sumaSuperior += m[f][c];
                sumaInferior += m[f][c];
            }
            sumarRegionesTriangulares(m, n, f, c + 1, sumaSuperior, sumaInferior);
        }
        //48. Encontrar punto de silla
        //Buscar elemento mínimo de su fila y máximo de su columna; mostrar coordenadas.
        //Ejemplo de entrada F = 2; C = 2; M = [[3, 1], [4, 2]]
        //Salida esperada Punto de silla: valor 2; fila 1; columna 1
        void puntoSilla(int m[][100], int filas, int columnas, int f, int c, int &valorSilla, int &posicionF, int &posicionC)
        {
            if (f == filas) return;

            if (c == columnas) 
            {
                puntoSilla(m, filas, columnas, f + 1, 0, valorSilla, posicionF, posicionC);
                return; 
            }
            int minFila = m[f][0];
            for (int j = 1; j < columnas; j++) 
            {
                if (m[f][j] < minFila) 
                {
                    minFila = m[f][j];
                }
            }
            bool esMaxColumna = true;
            for (int i = 0; i < filas; i++) 
            {
                if (m[i][c] > minFila) 
                {
                    esMaxColumna = false;
                    break;
                }
            }
            if (minFila == m[f][c] && esMaxColumna) 
            {
                valorSilla = minFila;
                posicionF = f;
                posicionC = c;
                return;
            }
            puntoSilla(m, filas, columnas, f, c + 1, valorSilla, posicionF, posicionC);
        }
        //49. Buscar secuencias consecutivas
        //Verificar si hay K elementos iguales seguidos horizontal, vertical o diagonalmente.
        //Ejemplo de entrada F = 3; C = 3; M = [[5, 1, 2], [4, 5, 3], [7, 8, 5]]; K = 3
        //Salida esperada Sí existe: diagonal principal [5, 5, 5]
        bool verificarCamino(int m[][100], int filas, int columnas, int f, int c, int df, int dc, int k, int valorOriginal)
        {
            if (k == 0) return true;

            if (f < 0 || f >= filas || c < 0 || c >= columnas || m[f][c] != valorOriginal) {
                return false;
            }
            return verificarCamino(m, filas, columnas, f + df, c + dc, df, dc, k - 1, valorOriginal);
        }
        bool buscarSecuencias(int m[][100], int filas, int columnas, int f, int c, int k)
        {
            if(f == filas) return false;

            if(c == columnas) 
            {
                return buscarSecuencias(m, filas, columnas, f + 1, 0, k);
            }

            int valorActual = m[f][c];

            if(verificarCamino(m, filas, columnas, f, c, 0, 1, k, valorActual) ||   
                verificarCamino(m, filas, columnas, f, c, 1, 0, k, valorActual) ||   
                verificarCamino(m, filas, columnas, f, c, 1, 1, k, valorActual) ||   
                verificarCamino(m, filas, columnas, f, c, 1, -1, k, valorActual)) 
            { 
                return true;
            }
            return buscarSecuencias(m, filas, columnas, f, c + 1, k);
        }
        //50. Camino de suma máxima
        //Desde (0,0) hasta (F-1,C-1), avanzar únicamente derecha o abajo y maximizar la suma.
        //Ejemplo de entrada F = 3; C = 3; M = [[5, 1, 2], [4, 8, 3], [1, 9, 6]]
        //Salida esperada Suma máxima: 32; camino: 5 → 4 → 8 → 9 → 6
        int sumaMaxima(int m[][100], int filas, int columnas, int f, int c) 
        {
            if (f == filas || c == columnas) return -1;
            
            if (f == filas - 1 && c == columnas - 1) return m[f][c];

            int abajo = sumaMaxima(m, filas, columnas, f + 1, c);
            int derecha = sumaMaxima(m, filas, columnas, f, c + 1);

            return m[f][c] + max(abajo, derecha);
        }

        void mostrarCaminoMaximo(int m[][100], int filas, int columnas, int f, int c) 
        {
            cout << m[f][c];

            if (f == filas - 1 && c == columnas - 1) return;
            
            cout << "--> ";

            if (f == filas - 1) 
            {
                mostrarCaminoMaximo(m, filas, columnas, f, c + 1);
            }
            else if (c == columnas - 1) 
            {
                mostrarCaminoMaximo(m, filas, columnas, f + 1, c);
            }
            else 
            {
                int sumaAbajo = sumaMaxima(m, filas, columnas, f + 1, c);
                int sumaDerecha = sumaMaxima(m, filas, columnas, f, c + 1);
                
                if (sumaAbajo >= sumaDerecha) 
                {
                    mostrarCaminoMaximo(m, filas, columnas, f + 1, c);
                } 
                else 
                {
                    mostrarCaminoMaximo(m, filas, columnas, f, c + 1);
                }
            }
        }    
        
        
};

int main()
{
    Recursividad v1;

/*
    int tamanoVec=0;
    int v[100];
    cout<<"ingrese el tamano del vector: ";
    cin>>tamanoVec;

    //1.-CARGAR UN VECTOR
    v1.cargar(v,tamanoVec,0);
    //2.-MOSTRAR UN VECTOR 
    v1.mostrar(v,tamanoVec,0);
    cout<<endl; 
*/    
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

    //25. Máxima suma de segmento consecutivo
    int resultado = v1.maximaSumaSegmento(v, tamanoVec);

    cout << "Suma maxima: " << resultado  << endl;
*/
    RecursividadMatriz m1;
    int m[100][100];
    int filasT=0, columnasT=0;
    cout<<"ingrese el tamano de la matriz f,c: "; 
    cin>>filasT>>columnasT;
    //26. Cargar una matriz
    //Cargar los elementos de una matriz F×C mediante llamadas recursivas.
    //Ejemplo de entrada F = 2; C = 3; datos por filas: 1, 2, 3, 4, 5, 6
    //Salida esperada
    //Matriz cargada:
    //1 2 3
    //4 5 6
    m1.cargar(m, filasT, columnasT, 0, 0);
    //27. Mostrar una matriz
    //Mostrar recursivamente la matriz respetando filas y columnas.
    //Ejemplo de entrada F = 2; C = 3; M = [[3, 1, 4], [2, 5, 6]]
    //Salida esperada 3 1 4
    //2 5 6
    m1.mostrar(m, filasT, columnasT, 0, 0);
/*
    //28. Sumar todos los elementos
    //Calcular la suma total de una matriz.
    //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
    //Salida esperada Suma total: 21
    cout<<"suma total: "<<m1.sumarM(m, filasT, columnasT, 0, 0)<<endl;

    //29. Contar pares e impares
    //Contar todos los valores pares e impares de la matriz.
    //Ejemplo de entrada F = 2; C = 3; M = [[2, 3, 4], [5, 6, 7]]
    //Salida esperada Pares: 3; impares: 3
    int par=0, impar=0;
    m1.contarParImparM(m,filasT,columnasT,0,0, par, impar);

    cout<<"pares: "<< par<<endl;
    cout<<"impares:"<< impar<<endl;

    //30. Encontrar el mayor
    //Obtener el mayor valor de una matriz no vacía.
    //Ejemplo de entrada F = 2; C = 3; M = [[-5, -1, -9], [-3, -7, -2]]
    //Salida esperada Mayor: -1
    int mayor=0;
    m1.elMayor(m ,filasT,columnasT,0,0,mayor);

    cout<<"el mayor es: "<<mayor<<endl;
    //31. Encontrar el menor
    //Calcular el mínimo e indicar primera fila y columna donde aparece.
    //Ejemplo de entrada F = 3; C = 3; M = [[5, 2, 8], [1, 7, 6], [1, 4, 9]]
    //Salida esperada Menor: 1; fila: 1; columna: 0
    int menor=0;
    int PosFila=0, PosColumna=0;

    m1.elMenor(m ,filasT,columnasT, 0, 0, menor, PosFila, PosColumna);

    cout<<"el menor es: "<<menor<<endl;
    cout<<"pos fila: "<<PosFila<<endl;
    cout<<"pos columna: "<<PosColumna<<endl;

    //32. Contar positivos, negativos y ceros
    //Contar los valores positivos, negativos e iguales a cero.
    //Ejemplo de entrada F = 2; C = 4; M = [[-1, 0, 2, 5], [0, -3, 4, -2]]
    //Salida esperada Positivos: 3; negativos: 3; ceros: 2
    int pos=0, nega=0, cero=0;
    m1.contarPosNegCer(m, filasT, columnasT, 0, 0, cero, nega, pos);

    cout<<"cant ceros: "<<cero<<endl;
    cout<<"cant nega: "<<nega<<endl;
    cout<<"cant posi: "<<pos<<endl;

    //33. Buscar un elemento
    //Encontrar las coordenadas de la primera aparición en recorrido por filas.
    //Ejemplo de entrada F = 2; C = 3; M = [[4, 8, 2], [7, 8, 5]]; X = 8
    //Salida esperada Encontrado en fila 0, columna 1
    int x=0, PosFila=0, PosColumna=0;
    cout<<"agregue x a buscar: "<<endl;
    cin>>x;
    m1.encontrar1Aparicion(m, filasT, columnasT, 0, 0, PosFila ,PosColumna, x);
    cout<<"pos fila: "<<PosFila<<endl;
    cout<<"pos columna: "<<PosColumna<<endl;

    //34. Sumar cada fila
    //Mostrar una suma independiente para cada fila.
    //Ejemplo de entrada F = 3; C = 3; M = [[2, 4, 6], [1, 3, 5], [7, 8, 9]]
    //Salida esperada
    //Fila 0: 12
    //Fila 1: 9
    //Fila 2: 24

    m1.sumarCadaFila(m, filasT, columnasT, 0);

    //35. Sumar cada columna
    //Mostrar una suma independiente para cada columna.
    //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
    //Salida esperada
    //Columna 0: 5
    //Columna 1: 7
    //Columna 2: 9
    m1.sumarCadaColumna(m,filasT,columnasT,0);

    //36. Diagonal principal
    //Sumar los elementos M[i][i] de una matriz cuadrada.
    //Ejemplo de entrada N = 3; M = [[3, 5, 7], [2, 8, 4], [1, 6, 9]]
    //Salida esperada Suma diagonal principal: 20
    int n=0;
    if(filasT==columnasT)
    {
        n=filasT;
        int resultado = m1.diagonalPrincipal(m, n, 0);
        cout << "Suma diagonal principal: " << resultado << endl;
    }
    else
    {
        cout<<" no es simetrica "<<endl;
    }
 
    //37. Diagonal secundaria
    //Sumar los elementos M[i][N-1-i].
    //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    //Salida esperada Suma diagonal secundaria: 15
    int n=0;
    if(filasT==columnasT)
    {
        n=filasT;
        int resultado = m1.diagonalSecundaria(m, n, 0);
        cout << "Suma diagonal secundaria: " << resultado << endl;
    }
    else
    {
        cout<<" no es simetrica "<<endl;
    }

    //38. Sumar sobre y debajo de la diagonal
    //Obtener las sumas de valores estrictamente encima y debajo de la diagonal principal.
    //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    //Salida esperada Encima: 11 (2+3+6); debajo: 19 (4+7+8)
    int sumaEncima = 0;
    int sumaDebajo = 0;
    int n=0;
    if(filasT==columnasT)
    {
        n=filasT;
        m1.sumarEncimaDebajo(m, n, 0, 0, sumaEncima, sumaDebajo);

        cout << "Encima: " << sumaEncima << "debajo: " << sumaDebajo << endl;
    }
    else
    {
        cout<<" no es simetrica "<<endl;
    }
    
    //39. Mostrar el borde
    //Mostrar los valores del borde en orden por filas, sin incluir los internos.
    //Ejemplo de entrada F = 3; C = 4; M = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    //Salida esperada Borde por filas: 1 2 3 4 5 8 9 10 11 12 
    cout<<"resultado"<<endl;
    m1.mostrarBorde(m, filasT, columnasT, 0, 0);

    //40. Sumar el borde
    //Sumar los valores del borde, contando las esquinas una sola vez.
    //Ejemplo de entrada F = 3; C = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    //Salida esperada Suma del borde: 40
    cout<<"resultado: "<<m1.sumarBorde(m,filasT,columnasT,0,0)<<endl;
   
    //41. Mostrar la transpuesta
    //Mostrar la transpuesta de una matriz rectangular sin crear otra matriz.
    //Ejemplo de entrada F = 2; C = 3; M = [[1, 2, 3], [4, 5, 6]]
    //Salida esperada
    //Transpuesta (3×2):
    //1 4
    //2 5
    //3 6
    m1.mostrarTranspuesta(m, filasT, columnasT, 0, 0);

    //42. Mayor de cada fila
    //Mostrar el máximo de cada fila recursivamente.
    //Ejemplo de entrada F = 3; C = 3; M = [[2, 9, 4], [8, 1, 5], [3, 7, 6]]
    //Salida esperada
    //Fila 0: 9
    //Fila 1: 8
    //Fila 2: 7

    cout << "Salida esperada:" << endl;
    m1.mayorDeCadaFila(m, filasT, columnasT, 0);

    //43. Verificar matriz simétrica
    //Comprobar si M[i][j] es igual a M[j][i] en toda matriz cuadrada.
    //Ejemplo de entrada N = 3; M = [[1, 2, 3], [2, 4, 5], [3, 5, 6]]
    //Salida esperada ¿Es simétrica?: Sí
    int n = 0;
    
    if (filasT == columnasT)
    {
        n = filasT;
        // Llamamos a la función y evaluamos el booleano resultante
        bool resultado = m1.esSimetrica(m, n, 0, 0);

        if (resultado) 
        {
            cout << "si" << endl;
        } 
        else 
        {
            cout << "no" << endl;
        }
    }
    else
    {
        cout << "no la matriz no es cuadrada"<<endl;
    }
   
    //44. Rotar 90 grados
    //Mostrar la matriz cuadrada rotada 90° en sentido horario.
    //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    //Salida esperada
    //Rotada:
    //7 4 1
    //8 5 2
    //9 6 3
    int n=0;
    cout<<"ingrese n: "<<endl;
    cin>>n;
    cout << "rotada:" << endl;
    m1.rotar90(m,n,0,0);

    //45. Recorrido en espiral
    //Mostrar los elementos de una matriz en espiral, desde esquina superior izquierda hacia la derecha.
    //Ejemplo de entrada F = 4; C = 4; M =
    //[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    //Salida esperada 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
    cout<<"recorrido en espiral: "<<endl;
    m1.espiral(m, filasT, columnasT, 0, filasT, 0, columnasT);

    //46. Matriz triangular superior
    //Comprobar que los elementos debajo de la diagonal principal sean cero.   
    //Ejemplo de entrada N = 3; M = [[2, 3, 4], [0, 5, 6], [0, 0, 7]]
    //Salida esperada ¿Triangular superior?: Sí
    int n=0;
    if(filasT==columnasT)
    {
        n=filasT;
        bool resultado = m1.esTriangularSuperior(m, n, 0, 0);
        if (resultado) 
        {
            cout << "si" << endl;
        } 
        else 
        {
            cout << "no" << endl;
        }
    }
    else
    {
        cout<<" no es simetrica "<<endl;
    }

    //47. Sumar regiones triangulares
    //Sumar elementos con i≤j y con i≥j; la diagonal se incluye en ambas sumas.
    //Ejemplo de entrada N = 3; M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    //Salida esperada Triángulo superior: 26; triángulo inferior: 34
    int sumaSuperior = 0;
    int sumaInferior = 0;
    int n = 3;
    m1.sumarRegionesTriangulares(m, n, 0, 0, sumaSuperior, sumaInferior);

    cout << "Triángulo superior: " << sumaSuperior << "; triángulo inferior: " << sumaInferior << endl;
   
    //48. Encontrar punto de silla
    //Buscar elemento mínimo de su fila y máximo de su columna; mostrar coordenadas.
    //Ejemplo de entrada F = 2; C = 2; M = [[3, 1], [4, 2]]
    //Salida esperada Punto de silla: valor 2; fila 1; columna 1
    int valorSilla = -1;
    int posicionF = -1;
    int posicionC = -1;
    m1.puntoSilla(m, filasT, columnasT, 0, 0, valorSilla, posicionF, posicionC);
    cout << "Punto de silla: valor " << valorSilla << "; fila " << posicionF << "; columna " << posicionC << endl;
    
    //49. Buscar secuencias consecutivas
    //Verificar si hay K elementos iguales seguidos horizontal, vertical o diagonalmente.
    //Ejemplo de entrada F = 3; C = 3; M = [[5, 1, 2], [4, 5, 3], [7, 8, 5]]; K = 3
    //Salida esperada Sí existe: diagonal principal [5, 5, 5]
    int k=0;
    cout<<"ingrese k: "<<endl;
    cin>>k;    
    bool existe = m1.buscarSecuencias(m, filasT, columnasT, 0, 0, k);

    if(existe) 
    {
        cout << "si" << k << endl;
    } 
    else 
    {
        cout << "no" << endl;
    }
*/
    //50. Camino de suma máxima
    //Desde (0,0) hasta (F-1,C-1), avanzar únicamente derecha o abajo y maximizar la suma.
    //Ejemplo de entrada F = 3; C = 3; M = [[5, 1, 2], [4, 8, 3], [1, 9, 6]]
    //Salida esperada Suma máxima: 32; camino: 5 → 4 → 8 → 9 → 6
    int sumaMax = m1.sumaMaxima(m, filasT, columnasT, 0, 0);
    cout << "Suma máxima: " << sumaMax << endl;

    m1.mostrarCaminoMaximo(m, filasT, columnasT, 0, 0);

    return 0;
}