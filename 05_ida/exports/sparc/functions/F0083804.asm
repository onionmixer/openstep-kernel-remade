F0083804: 9de3bf98                 save    %sp, -0x68, %sp
F0083808: 90100018                 mov     %i0, %o0
F008380C: 193c04f4                 sethi   %hi(_kernel_object), %o4
F0083810: 92100019                 mov     %i1, %o1
F0083814: 9410001a                 mov     %i2, %o2
F0083818: 96102001                 mov     1, %o3
F008381C: d8032340                 ld      [%o4+%lo(_kernel_object)], %o4
F0083820: 7fffff44                 call    sub_F0083530
F0083824: 9a102001                 mov     1, %o5
F0083828: 81c7e008                 ret
F008382C: 91e80008                 restore %g0, %o0, %o0
