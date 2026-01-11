# 🧠 Sistemas, memoria y el coste de la abstracción

> *Este repositorio no trata sobre aprender un lenguaje de programación.*
> *Trata sobre comprender qué sucede realmente cuando se ejecuta un software.*

---

## 📌 ¿Qué es este repositorio?

Este repositorio es una **exploración profunda de los sistemas informáticos**, utilizando **C como herramienta**, no como un objetivo final.

Existe para responder preguntas que la mayor parte del desarrollo de software moderno **oculta por diseño**:

* ¿Qué es realmente la memoria?
* ¿Por qué existen errores incluso cuando el código "parece correcto"?
* ¿Qué significa realmente el *comportamiento indefinido*?
* ¿Cómo fallan las abstracciones?
* ¿Dónde se encuentra el software con la física?

Esto **no** es una colección de frameworks.

Esto **no** se trata de trucos de productividad.

Esto **no** se trata de crear aplicaciones atractivas.

Esto se trata de **comprender los sistemas desde cero**.

---

## 🧩 Motivación

El desarrollo moderno facilita la creación de proyectos, pero dificulta su comprensión.

Los frameworks, los entornos de ejecución y los lenguajes administrados nos protegen de:

* errores de memoria
* límites de hardware
* riesgos de concurrencia
* restricciones físicas

Esa protección es útil, pero tiene un coste:

> **Pérdida de comprensión.**

Este repositorio existe para recuperar esa comprensión.

---

## ⚙️ ¿Por qué C?

C no se elige por ser antiguo, rápido o popular.

C se elige por ser **honesto**.

* La memoria es explícita
* Los errores son tu responsabilidad
* El compilador no te protege
* El sistema hace exactamente lo que le dices, incluso cuando está mal

C te obliga a confrontar:

* Cómo se distribuyen los datos en la memoria
* Cómo el tiempo y la vida útil afectan la corrección
* Cómo se construyen las abstracciones (y cómo se filtran)

En resumen:

> **C elimina la ilusión.**

---

## 🧠 Filosofía central

* Una computadora no "entiende" el código; transiciona estados físicos
* Los bits son abstracciones impuestas sobre una realidad física inestable
* Los lenguajes son acuerdos superpuestos al hardware
* Los errores no son accidentes; son violaciones de los modelos mentales
* La complejidad debe justificarse, no acumularse

> **Si no puedes explicar lo que sucede en la memoria, no entiendes el sistema.**

---

## 🗺️ La hoja de ruta

Este repositorio sigue una hoja de ruta estructurada centrada en **conceptos, modos de fallo y sistemas comportamiento**, no sintaxis.

### Fase 0 — Preparación Mental

* El sistema no te debe nada
* El compilador no es tu amigo
* Si falla, es tu culpa

---

### Fase 1 — Qué es realmente la memoria

* Memoria como direcciones, no como variables
* Pila vs. montón
* Alineación y orden de bytes
* Vida útil y propiedad de los datos

---

### Fase 2 — Comportamiento indefinido

* Qué significa realmente UB
* Por qué "funciona" no significa nada
* Fuera de límites, desbordamiento, aliasing
* Cómo las optimizaciones explotan las suposiciones

---

### Fase 3 — Tiempo, pila y montón

* Marcos de pila y llamadas a funciones
* Malloc/free y fragmentación
* Fugas de memoria y doble liberación
* Vida útil como una dimensión de corrección

---

### Fase 4 — Construyendo tus propias abstracciones

* Matrices dinámicas
* Cadenas
* Grupos de memoria
* Simple Asignadores

Comprender *por qué* existen las abstracciones estándar mediante su reconstrucción.

---

### Fase 5 — Manejo de errores (sin excepciones)

* Errores como estados explícitos
* Códigos de retorno y errno
* Diseño de API que fallan correctamente
* Reversión y fallo parcial

---

### Fase 6 — Concurrencia y estado compartido

* Condiciones de carrera
* Visibilidad y ordenamiento
* Bloqueos y atomicidad
* Fallos no deterministas

---

### Fase 7 — C cerca del hardware

* Cómo C se convierte en ensamblador
* Convenciones de llamada y ABI
* Registros y llamadas al sistema
* Superando los límites usuario/kernel

---

### Fase 8 — Lectura de sistemas reales

* SQLite
* Redis
* Git
* Kernel de Linux (partes seleccionadas)

Aprendizaje mediante el estudio de sistemas que sobrevivieron a la realidad.

---

### Fase 9 — Filosofía de Sistemas

* Complejidad esencial vs. accidental
* Límites físicos de la computación
* Coste de control y seguridad
* Minimalismo en el diseño de sistemas

---

### Fase 10 — Proyecto de Integración

Un sistema no trivial, construido sin frameworks:

* Un asignador de memoria
* Un tiempo de ejecución mínimo
* Un servidor TCP sin procesar
* Un intérprete simple

---

## 🚫 Qué no es este repositorio

* No es un tutorial para principiantes
* No es una referencia de sintaxis de C
* No está basado en frameworks
* No se centra en resultados rápidos

Este repositorio valora:

* La corrección sobre la comodidad
* La comprensión sobre la productividad
* La profundidad sobre la velocidad

---

## 🎯 ¿A quién va dirigido?

* Desarrolladores que creen que el software moderno es "demasiado mágico"
* Ingenieros que quieren comprender el fracaso, no solo el éxito
* Personas que quieren pensar en sistemas, no en herramientas
* Cualquiera dispuesto a pasar por momentos incómodos para aprender algo real

---

## 🧠 Reflexión final

> **Programar no se trata de escribir código.
> Se trata de imponer una estructura al caos y comprender el coste de hacerlo.**

Si esto te resuena, bienvenido.
Si no, no te preocupes: este camino no es para todos.

---

## 📎 Licencia

MIT: porque comprender debería ser gratis.

---

*La memoria no es magia. La abstracción tiene un coste. Los sistemas no perdonan.*
