F00AF110: 9de3bf98                 save    %sp, -0x68, %sp
F00AF114: 253c04c5                 sethi   %hi(dword_F0131564), %l2
F00AF118: d004a164                 ld      [%l2+%lo(dword_F0131564)], %o0
F00AF11C: 80a22000                 cmp     %o0, 0
F00AF120: 12800026                 bne     loc_F00AF1B8
F00AF124: 113c04c5                 sethi   -0xFECEC00, %o0
F00AF128: 400000d4                 call    _prom_nextnode
F00AF12C: 90102000                 mov     0, %o0
F00AF130: a2100008                 mov     %o0, %l1
F00AF134: 80a47fff                 cmp     %l1, -1
F00AF138: 32800005                 bne,a   loc_F00AF14C
F00AF13C: 90100011                 mov     %l1, %o0
F00AF140: 113c0470                 sethi   %hi(aPromGetidpromC), %o0! "prom_getidprom: can't get root node!\n"
F00AF144: 1080000b                 ba      loc_F00AF170
F00AF148: 901221f0                 bset    %lo(aPromGetidpromC), %o0! "prom_getidprom: can't get root node!\n"
F00AF14C: 133c0470                 sethi   %hi(aIdprom), %o1! "idprom"
F00AF150: 7fffffa3                 call    _prom_getproplen
F00AF154: 92126218                 bset    %lo(aIdprom), %o1! "idprom"
F00AF158: a0100008                 mov     %o0, %l0
F00AF15C: 80a43fff                 cmp     %l0, -1
F00AF160: 12800007                 bne     loc_F00AF17C
F00AF164: 80a42020                 cmp     %l0, 0x20 ! ' '
F00AF168: 113c047090122220         set     aMissingIdpromP, %o0! "Missing idprom property.\n"
F00AF170: 40000182                 call    _prom_printf
F00AF174: b0102000                 mov     0, %i0
F00AF178: 30800015                 ba,a    locret_F00AF1CC
F00AF17C: 08800007                 bleu    loc_F00AF198
F00AF180: 113c0470                 sethi   %hi(aPromGetidpromP), %o0! "prom_getidprom: property size <%d> too "...
F00AF184: 90122240                 bset    %lo(aPromGetidpromP), %o0! "prom_getidprom: property size <%d> too "...
F00AF188: 4000017c                 call    _prom_printf
F00AF18C: 92100010                 mov     %l0, %o1
F00AF190: 1080000f                 ba      locret_F00AF1CC
F00AF194: b0102000                 mov     0, %i0
F00AF198: 90100011                 mov     %l1, %o0
F00AF19C: 133c047092126270         set     aIdprom_0, %o1! "idprom"
F00AF1A4: 153c04c5                 sethi   %hi(unk_F0131568), %o2
F00AF1A8: 7fffff97                 call    _prom_getprop
F00AF1AC: 9412a168                 bset    %lo(unk_F0131568), %o2! size_t
F00AF1B0: e024a164                 st      %l0, [%l2+0x164]
F00AF1B4: 113c04c5                 sethi   -0xFECEC00, %o0
F00AF1B8: 90122168                 bset    0x168, %o0! void *
F00AF1BC: 92100018                 mov     %i0, %o1! void *
F00AF1C0: 7fff9654                 call    _bcopy
F00AF1C4: 94100019                 mov     %i1, %o2
F00AF1C8: f04e0000                 ldsb    [%i0], %i0
F00AF1CC: 81c7e008                 ret
F00AF1D0: 81e80000                 restore
