F00EB9E0: 9de3bf90                 save    %sp, -0x70, %sp
F00EB9E4: d0060000                 ld      [%i0], %o0! cls
F00EB9E8: 4000107f                 call    _class_respondsToMethod
F00EB9EC: 9210001a                 mov     %i2, %o1
F00EB9F0: 912a2018                 sll     %o0, 24, %o0
F00EB9F4: b13a2018                 sra     %o0, 24, %i0
F00EB9F8: 81c7e008                 ret
F00EB9FC: 81e80000                 restore
