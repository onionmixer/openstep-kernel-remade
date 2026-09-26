F00976E4: 9de3bf98                 save    %sp, -0x68, %sp
F00976E8: b2067fff                 inc     -1, %i1
F00976EC: 80a67fff                 cmp     %i1, -1
F00976F0: 02800008                 be      loc_F0097710
F00976F4: 86102000                 mov     0, %g3
F00976F8: b2067fff                 inc     -1, %i1
F00976FC: c4160000                 lduh    [%i0], %g2
F0097700: 80a67fff                 cmp     %i1, -1
F0097704: 8600c002                 add     %g3, %g2, %g3
F0097708: 12bffffc                 bne     loc_F00976F8
F009770C: b0062002                 inc     2, %i0
F0097710: 8530e010                 srl     %g3, 16, %g2
F0097714: 8728e010                 sll     %g3, 16, %g3
F0097718: 8730e010                 srl     %g3, 16, %g3
F009771C: 86008003                 add     %g2, %g3, %g3
F0097720: 0500003f8410a3ff         set     0xFFFF, %g2
F0097728: 80a0c002                 cmp     %g3, %g2
F009772C: 34800002                 bg,a    loc_F0097734
F0097730: 8620c002                 sub     %g3, %g2, %g3
F0097734: b128e010                 sll     %g3, 16, %i0
F0097738: b1362010                 srl     %i0, 16, %i0
F009773C: 81c7e008                 ret
F0097740: 81e80000                 restore
