F00CD768: 9de3bf90                 save    %sp, -0x70, %sp
F00CD76C: d0062230                 ld      [%i0+0x230], %o0
F00CD770: 912a2001                 sll     %o0, 1, %o0
F00CD774: b4068008                 add     %i2, %o0, %i2
F00CD778: 7fffe1ee                 call    _IOMalloc
F00CD77C: 9010001a                 mov     %i2, %o0
F00CD780: 92100008                 mov     %o0, %o1
F00CD784: d226c000                 st      %o1, [%i3]
F00CD788: f4270000                 st      %i2, [%i4]
F00CD78C: d0062230                 ld      [%i0+0x230], %o0
F00CD790: 80a22001                 cmp     %o0, 1
F00CD794: 08800006                 bleu    locret_F00CD7AC
F00CD798: b0100009                 mov     %o1, %i0
F00CD79C: b0024008                 add     %o1, %o0, %i0
F00CD7A0: b0063fff                 inc     -1, %i0
F00CD7A4: 90200008                 neg     %o0
F00CD7A8: b00e0008                 and     %i0, %o0, %i0
F00CD7AC: 81c7e008                 ret
F00CD7B0: 81e80000                 restore
