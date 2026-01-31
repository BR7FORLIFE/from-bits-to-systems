/**
 * ------- RETARDOS DE PROPAGACIÓN ------------
 * 
 * Retardo de propagación es:

    el tiempo físico inevitable entre un cambio en la entrada de un sistema y el momento en que su salida refleja ese cambio
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
#include <stdio.h>

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
    //1. creamos las señales (cables)
    Signal a = {0 , 0};
    Signal b = {0 , 0};
    Signal out = {0, 0};

    //2. crear compuerta AND con retardo
    AndGate g = {
        .delay = 3,
        .remaining = 0,
        .in1 = &a,
        .in2  = &b,
        .out = &out
    };

    //3. cambiar entradas
    a.value = 1;
    b.value = 1;

    //4: simulacion del tiempo
    for (int t = 0; t < 6; t++)
    {
        andgate_eval(&g); // evaluar logica
        tick(&g); // avanzar en el tiempo

        printf(
            "tiempo=%d | signal_a=%d signal_b=%d out=%d remaining=%d\n",
            t, a.value, b.value, out.value, g.remaining
        );
    }
    
    return 0;
}

void andgate_eval(AndGate *g) {
    int desired = g->in1->value && g->in2->value; //int1 -> 1 - int2 -> 1 -> desired = 1

    if (desired != g->out->value) { // desired = 1 != out = 0
        if (g->remaining == 0) { // true -> remaining = 0
            g->remaining = g->delay; // remaining = 3 -> delay = 3
            g->out->nextValue = desired; // out = 0 | out = 1
        }
    }
} 
/*
TICK (remaining) -> 

AndGate g = {
    .delay = 3,
    .remaining = 0,
    .in1 = &a,
    .in2  = &b,
    .out = &out
};

primera ejecucion => ciclo = 0 $ int1 -> 1 && int2 -> 1 && out -> 1  || desired = 1 && remaining 3 && delay = 3

*/

void tick(AndGate *g) {
    if (g->remaining > 0) {
        g->remaining--;
        if (g->remaining == 0) {
            g->out->value = g->out->nextValue;
        }
    }
}
