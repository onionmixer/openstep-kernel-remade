F00EC670: 9de3bf90                 save    %sp, -0x70, %sp
F00EC674: d006200c                 ld      [%i0+0xC], %o0
F00EC678: 40000022                 call    sub_F00EC700
F00EC67C: 9210001a                 mov     %i2, %o1
F00EC680: 80a22000                 cmp     %o0, 0
F00EC684: 12800009                 bne     locret_F00EC6A8
F00EC688: 01000000                 nop
F00EC68C: f0062008                 ld      [%i0+8], %i0
F00EC690: 80a62000                 cmp     %i0, 0
F00EC694: 02800005                 be      locret_F00EC6A8
F00EC698: 01000000                 nop
F00EC69C: 90100018                 mov     %i0, %o0
F00EC6A0: 40000030                 call    sub_F00EC760
F00EC6A4: 9210001a                 mov     %i2, %o1
F00EC6A8: 81c7e008                 ret
F00EC6AC: 91e80008                 restore %g0, %o0, %o0
