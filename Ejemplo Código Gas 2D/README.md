## Aquí encontrará dos programas en C++  que simulan un gas ideal 2D.:
*  Gas2D_animacion.cpp    realiza una animación en gnuplot
*    Gas2D_datos.cpp   imprime las velocidades de las moléculas, y puede ser usado para construir la distribución de velocidades V o la distribución de la componente Vx de las velocidades en dirección x. Para correrlos necesita instalar g++ y gnuplot

Coloque todos los archivos en una sola carpeta.

> Para ver la animación, compile primero Gas2D_animacion.cpp usando el comando

> > g++ Gas2D_animacion.cpp

> y luego corra el programa haciendo pipeline con gnuplot, así:

> ./a.out | gnuplot


> Para tomar datos,compile  use Gas2D_datos con

> g++ Gas2D_datos.cpp

> y luego corra y guarde los datos en un archivo datos.dat, así:

> ./a.out > datos.dat
