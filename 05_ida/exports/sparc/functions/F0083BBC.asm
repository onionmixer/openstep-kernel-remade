F0083BBC: 9de3bf98                 save    %sp, -0x68, %sp
F0083BC0: 90100018                 mov     %i0, %o0
F0083BC4: 193c04f4                 sethi   %hi(_kernel_object), %o4
F0083BC8: 92100019                 mov     %i1, %o1
F0083BCC: 9410001a                 mov     %i2, %o2
F0083BD0: 96102001                 mov     1, %o3
F0083BD4: d8032340                 ld      [%o4+%lo(_kernel_object)], %o4
F0083BD8: 7ffffe56                 call    sub_F0083530
F0083BDC: 9a10001b                 mov     %i3, %o5
F0083BE0: 81c7e008                 ret
F0083BE4: 91e80008                 restore %g0, %o0, %o0
