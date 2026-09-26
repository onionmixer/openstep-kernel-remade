F00EE2E0: 9de3bf98                 save    %sp, -0x68, %sp
F00EE2E4: 7ffc6455                 call    _strlen
F00EE2E8: 90100018                 mov     %i0, %o0
F00EE2EC: 92022001                 add     %o0, 1, %o1! __src
F00EE2F0: d4066004                 ld      [%i1+4], %o2
F00EE2F4: 9fc28000                 call    %o2
F00EE2F8: 90100019                 mov     %i1, %o0! __dst
F00EE2FC: 7ffc648b                 call    _strcpy
F00EE300: 92100018                 mov     %i0, %o1
F00EE304: 81c7e008                 ret
F00EE308: 91e80008                 restore %g0, %o0, %o0
