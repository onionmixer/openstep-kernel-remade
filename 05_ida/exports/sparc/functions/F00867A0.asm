F00867A0: 9de3bf98                 save    %sp, -0x68, %sp
F00867A4: 113c04f6                 sethi   %hi(_vm_object_zone), %o0
F00867A8: 7fffca49                 call    _zalloc
F00867AC: d0022098                 ld      [%o0+%lo(_vm_object_zone)], %o0
F00867B0: a0100008                 mov     %o0, %l0
F00867B4: 90100018                 mov     %i0, %o0
F00867B8: 40000004                 call    __vm_object_allocate
F00867BC: 92100010                 mov     %l0, %o1
F00867C0: 81c7e008                 ret
F00867C4: 91e80010                 restore %g0, %l0, %o0
