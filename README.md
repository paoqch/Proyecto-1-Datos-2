# C! IDE

Proyecto 1 Estructura de Datos 2

Consiste en un editor de texto el cual permite ingresar código de C! el cual tiene una sintaxis derivada del lenguaje de programación C.

Se desarrollo usando Qt para realizar la interfaz además sockets propios de C++ además de usar json para la comunicación entre los sockets el cual se usó la biblioteca Json for modern desarrollada por Nlohmaan.

Para descargar e instalar Qt y Qt creator, se descarga el archivo, lo descomprimimos y ejecutamos para instalarlo. Link de descarga https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5.

Para el json basta con descargar el el archivo json.hpp de https://github.com/nlohmann/json/releases y adjuntarlo a los archivos de nuestro proyecto.

Con respecto a los tipos de datos y su sintaxis que admite C! son:

a) int: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final.
Ejemplo: 

```
int a = 5 + 6;
```

b) char: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final, además de un solo único elemento y debe ir entre comillas.
Ejemplo:

```
char b = '1';
```

c) double: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final, además de concordar con un double el cual debe de tener su parte decimal.
Ejemplo: 

```
double c = 2.1;
```

d) float: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final, demás de concordar con un double el cual debe de tener su parte decimal pero sin la necesitas de la f al final.
Ejemplo: 

```
float d = 31.4;
```

e) long: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final.
Ejemplo: 

```
long e = 5311314;
```

f) reference: Debe tener un espacio entre cada elemento de la línea de código y punto y coma al final, además de indicar el tipo de dato (int,char,float,double,long) y antes de la variable a la cual se referencia debe de ir un &.
Ejemplo: 

```
reference <int> f = & a;
```

g) struct: Debe tener un espacio entre cada elemento de la lista, luego de "struct" debe de ir un corchete abierto. En las siguientes líneas de código debe de ir las variable que pertenezcan al struct con su respectiva sintaxis. Para finalizar el struct se cerrará el corchete y seguido de un espacios pondremos los elementos que crearemos con respecto al struct. Si queremos hacer uso de algun dato pondremos "nombre del elemento" + "variable".
Ejemplo:

```
struct {
int e1 = 5;
int e2 = 6;
} obj1 obj2
```

h) cout: Debe tener un espacio entre cada elemento de la lista, además de lo que gustemos imprimir en la consola. Si queremos imprimir alguna variable solo agregariamos el nombre de dicha variable, si lo que queremos es imprimir algun texto o número, va entre comillas simple.
Ejemplo: cout << '5';

i) Bloques de código: están definidos dentro de "{ }", donde las variables dentro de dicho bloque, solo exestirán dentro de ese bloque de código.
Ejemplo:

```
{
int a = 5;
int b = 7;
}

```

Con ejemplo de código sería el siguiente:

```
int a = 5;
int b = 6 + a;
double c = 62.13;
float d = 31.31;
char e = '1';
reference <int> f = & b;
struct {
int dato1 = 10;
int dato2 = 20;
} obj1 obj2
cout << a;
```
  
Reserva de memoria:

En la parte inferior izquierda encontremos un área donde podemos reservar la memoria que gustemos en MB, es decir si queremos reservar 10MB, indicamos la cantidad de 10 y pulsamos el botón reservar.

Ram View:

Se actualizará después de la asignación de cada elemento, para el caso del struct será después de la línea de código donde termina el struct. Se actuliza también cuando cerramos un bloque de código y por último al hacer uso del garbage collector.

Log:

Cada acción que se realizará aparecerá dentro de dicha área, además de los errores.

Botones:

Run y Next: Para iniciar la ejecucción del código primero daremos click al botón run y para avanzar entre las línas usaremos el botón run.
Reset: Reinicia la ejecucción y además borra el RamView
Stop: Reinicia la ejeccucicón pero no borra el RamView

Link Jira:

https://paoqch.atlassian.net/secure/RapidBoard.jspa?rapidView=2&projectKey=PRO1&selectedIssue=PRO1-11&atlOrigin=eyJpIjoiMDhiMWQxZTNjNTY2NDExNmI3Yjg2MGY3YWE5Mjc0MTkiLCJwIjoiaiJ9
