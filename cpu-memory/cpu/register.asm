; ASSEMBLY
; mnemonicos de instrucciones -> representan instrucciones maquina reales codificadas en binarios y ejecutadas por la CPU

; --- MOVIMIENTO DE DATOS ---

; mov -> copia bits, no hace matematicas y no toca flags
; movzx -> mueve y extiende con ceros -> unsigned RUST 
; movsx -> mueve y extiende con signo -> signed RUST

; --- ARITMETICA ENTERA ---

; add -> ej: rax + rbx modifica flags (carry, zero, sign)
; sub 
; inc / dec -> incrementar y decremental en 1
; mul / imul -> multiplicacion (mul -> signed / imul -> unsigned)


; --- Logica bit a bit ---
; and
; or
; xor
; not

; --- Comparacionn y flags ---

; cmp -> no guarda resultados, solo ajusta flags internos: ZF (Zero), SF(sign), CF(carry), OF(overflow)
; test -> AND sin guardar resultado, usado para comprobar 0 y flags


; --- Saltos (Control flow) ---

; jmp -> saltos incondicionales
; je -> equal
; jne -> not equal
; jg -> greater (signed)
; jl -> less (signed)
; ja ->  above (unsigned)
; jb -> below (unsigned)

; --- STACK -> manipulan rsp , memoria (ajustan rsp, escriben / leen RAM) ---

; push 
; pop

; --- Llamadas y retornos ---

; call -> guarda rip en stack - salta
; ret -> recupera rip  - vuelve

; --- system / cpu control

; syscall -> salto controlado al kernel
; nop -> no hace nada, usado para: alignment, patching, timing
; hlt -> detiene CPU (modo kernel)



; ¿Que es un registro?
; Un registro es una celda de almacenamiento ultra rapida dentro de la CPU

; rax -> acumulador / return value
; rbx -> general
; rcx -> contador
; rdx -> datos
; rsi -> source
; rdi -> destination
; rsp -> stack pointer
; rbp -> base pointer
; rip -> instruction pointer

; --- flags ---

; bits especiales internos de la cpu que describen el resultado de la ultima operación
; estan en un registro especial llamado (en x86-64) llamado RFLAGS

; flags mas importantes

; ZF -> zero flags (resultado == 0)
; SF -> sign flags (resultado negativo)
; CF -> Carry Flags (overflow unsigned)
; OF -> Overflow Flag (overflow signed)

; --- RIP  ---

; El registro que contiene la direccion de la siguiente instruccion a ejecutar
; "es el dedo de la CPU señalando la proxima linea"
; sin rip no hay control flow, no hay programa y no hay ejecucion secuencial

; --- SYNTAX ---
; .text -> seccion de codigo ejecutable 
; .data -> datos inicializados
; .bss -> datos no inicializados
; .rodata -> constantes
section .text 
global _start ; Punto de entrada real del programa llamado directamente por el KERNEL

; flip flops del sistema
mov rax, 1 ; rax = 1 asigna 1 a rax
mov rbx, 2 ; rbx = 2 asigna 2 a rbx

; CPU: lee rax ALU entrada A y lee rbx ALU entrada B
; ALU -> suma binaria

; resultado se escribe en rax
; flags se actualizan (ZF, CF, etc)


; flujo de programa
; rax = 3 - rbx = 2 (rbx no cambia y rax pierde el valor anterior, la CPU no recuerda que rax fue 1)
add rax, rbx ; rax = 3

; Cableado interno: 
; bits de rax - copiados a flip flops de rcx
mov rcx, rax ; copia el resultado

mov rax, 60; syscall exit

xor rdi , rdi ; codigo 0

syscall



