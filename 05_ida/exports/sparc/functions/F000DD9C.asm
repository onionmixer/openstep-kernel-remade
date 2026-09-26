F000DD9C: 9de3bf98                 save    %sp, -0x68, %sp
F000DDA0: 113c04d3                 sethi   %hi(_u_thread_zone), %o0
F000DDA4: d0022290                 ld      [%o0+%lo(_u_thread_zone)], %o0
F000DDA8: 4001ad0a                 call    _zfree
F000DDAC: 92100018                 mov     %i0, %o1
F000DDB0: 81c7e008                 ret
F000DDB4: 81e80000                 restore
