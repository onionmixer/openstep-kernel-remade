F00A975C: 9de3bf98                 save    %sp, -0x68, %sp
F00A9760: 80a6e000                 cmp     %i3, 0
F00A9764: 0280000d                 be      loc_F00A9798
F00A9768: 92100018                 mov     %i0, %o1
F00A976C: 80a6e00f                 cmp     %i3, 0xF
F00A9770: 08800009                 bleu    loc_F00A9794
F00A9774: 912ee002                 sll     %i3, 2, %o0
F00A9778: 90023fc0                 inc     -0x40, %o0
F00A977C: 7fff8214                 call    _suword
F00A9780: 90068008                 add     %i2, %o0, %o0
F00A9784: 80a22000                 cmp     %o0, 0
F00A9788: 02800004                 be      loc_F00A9798
F00A978C: b0103fff                 mov     -1, %i0
F00A9790: 30800003                 ba,a    locret_F00A979C
F00A9794: d2264008                 st      %o1, [%i1+%o0]
F00A9798: b0102000                 mov     0, %i0
F00A979C: 81c7e008                 ret
F00A97A0: 81e80000                 restore
