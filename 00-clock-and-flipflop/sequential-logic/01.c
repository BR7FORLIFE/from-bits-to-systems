/**
 * ------- RETARDOS DE PROPAGACIÓN ------------
 * 
 *  SON: 
 *      - Tiempos para cargar capacitancias
 *      - Tiempo para descargar nodos
 *      - Tiempo para que un campo eléctrico se propague
 *      - Tiempo para que un transistor salga de región lineal
 *  
 *  CADA PUERTA LOGICA:
 *      - Tiene un retardo distinto
 *      - Es dependiente de la carga
 *      - Dependiente de la temperatura
 *      - Dependiente de historia previa 
 * 
 * 
 * EJEMPLO: 
 *     - Tienes dos caminos logicos
 * 
 *   A ──┐
 *       AND ── Y
 *   B ──┘
 *
 *   A ── NOT ──┐
 *              OR ── Z
 *   B ─────────┘
 *  
 * Aunque logicamente todo sea determinista(eventos estan causados por eventos anteriores)
 * los cambios llegan en momentos distintos, ademas el sistema pasa por estados que nunca se espera
 */


/**
 * TIPOS DE RETARDOS EN PROGRAMACIÓN
 * 
 *  - RETARDO INGENUO ->  NO RECOMENDADO (bloquea el programa, no modela concurrencia, no modela propagación)
 *  - RETARDO LOGICO (Tiempo discreto) -> El tiempo avanza en ticks,las señales no cambian constantemente, cada 
 *      componente tarda N en reaccionar
 *  - 
 * 
 */

//retardo logico
typedef struct {
    int value; // estado actla
    int nextValue; // el valor futuro que será
} Signal;

//modelo de puerta con retardo
typedef struct {
    int delay;
    int remaining;
    Signal *in1;
    Signal *in2;
    Signal *out;
} AndGate;

void andgate_eval(AndGate *g);
void tick(AndGate *g);

// retardo ingenuo
int main(){
    sleep(1); // retarno ingenuo NO RECOMENDADO! bloque el programa
    return 0;
}

void andgate_eval(AndGate *g) {
    int desired = g->in1->value && g->in2->value;

    if (desired != g->out->value) {
        if (g->remaining == 0) {
            g->remaining = g->delay;
            g->out->nextValue = desired;
        }
    }
}

void tick(AndGate *g) {
    if (g->remaining > 0) {
        g->remaining--;
        if (g->remaining == 0) {
            g->out->value = g->out->nextValue;
        }
    }
}
