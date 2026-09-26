F00EC6B0: 9de3bf90                 save    %sp, -0x70, %sp
F00EC6B4: d0062010                 ld      [%i0+0x10], %o0
F00EC6B8: 40000012                 call    sub_F00EC700
F00EC6BC: 9210001a                 mov     %i2, %o1
F00EC6C0: 80a22000                 cmp     %o0, 0
F00EC6C4: 12800009                 bne     locret_F00EC6E8
F00EC6C8: 01000000                 nop
F00EC6CC: f0062008                 ld      [%i0+8], %i0
F00EC6D0: 80a62000                 cmp     %i0, 0
F00EC6D4: 02800005                 be      locret_F00EC6E8
F00EC6D8: 01000000                 nop
F00EC6DC: 90100018                 mov     %i0, %o0
F00EC6E0: 40000043                 call    sub_F00EC7EC
F00EC6E4: 9210001a                 mov     %i2, %o1
F00EC6E8: 81c7e008                 ret
F00EC6EC: 91e80008                 restore %g0, %o0, %o0
