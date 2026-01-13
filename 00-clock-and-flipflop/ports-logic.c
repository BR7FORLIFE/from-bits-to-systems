//puertas logicas AND , OR, NOT

/**
 * En la vida real los modelos logicos funcionan con fluctuaciones electricas traducidos por medio de 
 * transistores, lo cuales toman estas señales y nosotros como humanos definimos las reglas para que 
 * signifique algo
 * 
 * AND -> dos input que proporcionen corriente al mismo tiempo produce una unica salida con corriente,
 * nosotros como humanos lo definimos (true/false) o (0 / 1 ) puede ser cualquier cosa lo importante es saber 
 * representar ese estado logico
 * 
 * OR -> dos input se les proporcionan corriente. Pero el output es "true" si algunos de esos dos input envia la señal y la otra no
 * 
 * NOT -> la negacion o la interpretacion contraria a una salida logica !AND = NOT o viceversa. 
 *
 * MODELA CAUSALIDAD MAS NO MEMORIA
 */
int AND(int a, int b){
    return a&&b;
}  

int OR(int a, int b){
    return a || b;
}

int NOT(int input){
    return !input;
}


/**
 * LOGICA COMBINACIONAL
 * 
 * conectás salidas a entradas - imponés invariantes - restringís combinaciones posibles
 */

int XOR(int a, int b) {
    return OR(AND(a, NOT(b)), AND(NOT(a), b));
}
