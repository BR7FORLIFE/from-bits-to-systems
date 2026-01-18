0\. Prerrequisito implícito (si esto no está, todo lo demás es teatro)
----------------------------------------------------------------------

Antes de hablar de lógica secuencial, tenés que aceptar esto como verdad operativa:

*   el tiempo físico es continuo
    
*   las señales no cambian instantáneamente
    
*   el feedback sin control produce oscilación o caos
    
*   el “estado” no existe naturalmente
    

Si no aceptás esto, la lógica secuencial se vuelve mística.

1\. Retardos, propagación y feedback (antes de “estado”)
--------------------------------------------------------

**Objetivo**: entender por qué el combinacional puro es insuficiente.

Temas:

*   retardos de propagación
    
*   glitches
    
*   bucles combinacionales
    
*   osciladores accidentales
    
*   dependencia del orden físico
    

Experimento:

*   simular una red combinacional con retardos variables
    
*   observar oscilación no prevista
    

Modelo mental:

> sin tiempo explícito, no hay causalidad controlable

2\. Realimentación como intento fallido de memoria
--------------------------------------------------

**Objetivo**: ver cómo la memoria _casi_ aparece sola.

Temas:

*   biestables sin reloj
    
*   realimentación cruzada
    
*   múltiples puntos de equilibrio
    
*   metastabilidad
    

Experimento:

*   latch SR sin reloj
    
*   entradas cambiando “a la vez”
    
*   observar indeterminación
    

Modelo mental:

> la memoria emerge, pero es inestable

3\. Metastabilidad: el estado que no debería existir (pero existe)
------------------------------------------------------------------

**Objetivo**: romper el modelo binario ingenuo.

Temas:

*   estados intermedios reales
    
*   tiempos de resolución
    
*   probabilidad, no certeza
    
*   MTBF como concepto
    

Experimento:

*   modelar un latch con ruido
    
*   forzar cambios cerca del borde
    

Modelo mental:

> el bit no es un valor, es una decisión forzada

4\. El reloj como imposición externa
------------------------------------

**Objetivo**: entender que el reloj no coordina, domina.

Temas:

*   flanco vs nivel
    
*   duty cycle
    
*   skew
    
*   jitter
    
*   violación de setup/hold
    

Experimento:

*   simular flancos imperfectos
    
*   variar skew entre flip-flops
    

Modelo mental:

> el reloj crea tiempo lógico donde no lo hay

5\. Flip-flops como contrato, no como objeto
--------------------------------------------

**Objetivo**: dejar de pensar en “guardar un bit”.

Temas:

*   edge-triggered vs level-sensitive
    
*   ventanas de captura
    
*   colapso de estado
    
*   irreversibilidad práctica
    

Experimento:

*   implementar flip-flop como FSM explícita
    
*   introducir fallos aleatorios
    

Modelo mental:

> un flip-flop es un evento, no una cosa

6\. Separación cálculo / actualización
--------------------------------------

**Objetivo**: entender por qué existe el “next state”.

Temas:

*   doble buffer lógico
    
*   evaluación estable
    
*   commit de estado
    
*   eliminación de feedback inmediato
    

Experimento:

*   comparar actualización inmediata vs diferida
    

Modelo mental:

> sin separación, no hay secuencia, hay caos

7\. Máquinas de estados finitos (FSM) reales
--------------------------------------------

**Objetivo**: abandonar FSMs de pizarra.

Temas:

*   estados físicos vs estados conceptuales
    
*   codificación de estados
    
*   estados ilegales
    
*   reset como acto violento
    

Experimento:

*   FSM con estados corruptos
    
*   observar recuperación o colapso
    

Modelo mental:

> los estados no son ideas, son patrones eléctricos

8\. Composición de sistemas secuenciales
----------------------------------------

**Objetivo**: ver cómo aparece la complejidad real.

Temas:

*   pipelines
    
*   backpressure
    
*   dependencias temporales
    
*   latencias no uniformes
    

Experimento:

*   pipeline con stalls
    
*   reloj único vs múltiple
    

Modelo mental:

> componer secuencia no preserva orden trivialmente

9\. Concurrencia y asincronía
-----------------------------

**Objetivo**: romper la ilusión de orden global.

Temas:

*   dominios de reloj
    
*   sincronizadores
    
*   eventos asincrónicos
    
*   pérdida de causalidad global
    

Experimento:

*   dos relojes con relación irracional
    
*   comunicación entre dominios
    

Modelo mental:

> el orden es local, no universal

10\. Lógica secuencial como base de la computación
--------------------------------------------------

**Objetivo**: conectar con CPUs y software.

Temas:

*   ciclo de instrucción
    
*   microarquitectura
    
*   interrupciones
    
*   excepciones
    

Experimento:

*   CPU mínima con estado explícito
    
*   ejecutar “programas” como secuencias de estados
    

Modelo mental:

> un programa es una trayectoria en un espacio de estados

11\. Simulación en C (sin mentir)
---------------------------------

**Objetivo**: usar C como lenguaje de modelos.

Reglas:

*   estado explícito
    
*   tiempo explícito
    
*   nada implícito
    
*   nada “magia del lenguaje”
    

Experimento:

*   simular flip-flops, FSM, CPU
    
*   introducir errores temporales
    

Modelo mental:

> C no ejecuta sistemas, los describe mal si no sos cuidadoso

12\. Donde la mayoría se pierde (advertencia final)
---------------------------------------------------

Errores típicos:

*   creer que FSM = switch-case
    
*   confundir orden de código con orden temporal
    
*   pensar que el reloj garantiza corrección
    
*   asumir estados imposibles como imposibles
    

👉 La lógica secuencial **no es limpia**.Es **un pacto frágil con la física**.