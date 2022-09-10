#! /bin/bash

ID_PRACTICA="$1"
#MINIENTREGA_CONF -> definida en declare -x MINIENTREGA_CONF=./conf

#Voy a crear una función auxiliar para escribir los errores más rápido ya que todos deben seguir una misma estructura
error() {
    TEXT="minientrega.sh: $@"
    echo "$TEXT">&2;
}

#1) Comprobar si el mandato dato es help
if [ $ID_PRACTICA = "-h" ] || [ $ID_PRACTICA = "--help" ]; then
        echo "minientrega.sh: Uso: minientrega.sh 'ID_PRACTICA'"
        echo "minientrega.sh: realiza la entrega de la práctica indicada por parámetro: 'ID_PRACTICA'"
        exit 0
fi


#2) COMPROBAR QUE EXISTE MINIENTREGA_CONF Y QUE ES UN DIRECTORIO
[ -d "$MINIENTREGA_CONF" ]
if [ $? -eq 1 ]; then
    error "Error, no se pudo realizar la entrega"
    error "no es accesible el directorio \""$MINIENTREGA_CONF"\""
    exit 64
fi

#3) Existe el directorio, comprobar:
    #3.1) El número argumentos es correcto
if [ $# -ne 1 ]; then
    error "Error(EX_USAGE), uso incorrecto del mandato. "Success""
    #Distinguimos entre lo sucedido para mandar un mensaje u otro
    if [ $# -lt 1 ]; then 
        error "Numero de argumentos insuficientes"
    else
        error "El script ha sido invocado con más de un argumento" 
    fi
    exit 65

else
    #Comprobamos que el archivo es válido
    [ -f "$MINIENTREGA_CONF/$ID_PRACTICA" ]
    Existe=$? #En esta variable guardamos el resultado del test
    if [ $Existe -eq 1 ]; then
        error "Error, no se pudo realizar la entrega"
        error "no es accesible el fichero /"$MINIENTREGA_CONF"/"$ID_PRACTICA""
        exit 66
    fi
fi

#EXISTE LA CARPETA con EL FICHERO CON LA ID 
    #1) Acceder al archivo
    . $MINIENTREGA_CONF/$ID_PRACTICA
    #Con source del $ID_Practica -> MINIENTREGA_FICHEROS MINIENTREGA_DESTINO

    #2) Comprueba los archivos
    for FILES in $MINIENTREGA_FICHEROS; 
    do
        if [ ! -r "$FILES" ]; then
            error "Error, no se pudo realizar la entrega"
            error "no es accesible el fichero \"$FILES\""
            exit 66
        fi
    done

    #3) Comprueba si existe o puede crear el directorio destino
    RUTA="$MINIENTREGA_DESTINO/${USER}"

    if [ ! -d $RUTA ]
        then #Intenta crear el directorio y si no devuelve error
        if ! mkdir $RUTA >/dev/null 2>&1  ;then    
            error "Error, no se pudo realizar la entrega"
            error "no se pudo crear el subdirectorio de entrega en \"$MINIENTREGA_DESTINO\""
            exit 73
        fi
    fi
    
    #4) Finalmente lleva los archivos previamente comprobandos al destino

    cp $MINIENTREGA_FICHEROS $RUTA
    
    #echo "Ficheros en la carpeta $RUTA: ";ls $RUTA

exit 0;