F00943C0: 9de3bf90                 save    %sp, -0x70, %sp
F00943C4: 90100018                 mov     %i0, %o0! void *
F00943C8: 80a66007                 cmp     %i1, 7
F00943CC: 0880001e                 bleu    locret_F0094444
F00943D0: 9207bff0                 add     %fp, var_10, %o1! void *
F00943D4: 400001cf                 call    _bcopy
F00943D8: 94102008                 mov     8, %o2
F00943DC: d207bff0                 ld      [%fp+var_10], %o1
F00943E0: 11004000                 sethi   0x1000000, %o0
F00943E4: 808a4008                 btst    %o0, %o1
F00943E8: 02800017                 be      locret_F0094444
F00943EC: 113f8000                 sethi   -0x2000000, %o0
F00943F0: 920a4008                 and     %o1, %o0, %o1
F00943F4: 11068000                 sethi   0x1A000000, %o0
F00943F8: 80a24008                 cmp     %o1, %o0
F00943FC: 02800005                 be      loc_F0094410
F0094400: 11058000                 sethi   0x16000000, %o0
F0094404: 80a24008                 cmp     %o1, %o0
F0094408: 1280000f                 bne     locret_F0094444
F009440C: 01000000                 nop
F0094410: 153c04f1                 sethi   %hi(byte_F013C416), %o2
F0094414: d60aa016                 ldub    [%o2+%lo(byte_F013C416)], %o3
F0094418: d00fbff1                 ldub    [%fp+var_10+1], %o0
F009441C: 80a2000b                 cmp     %o0, %o3
F0094420: 02800006                 be      loc_F0094438
F0094424: 9812a016                 or      %o2, %lo(byte_F013C416), %o4
F0094428: 11058000                 sethi   0x16000000, %o0
F009442C: 80a24008                 cmp     %o1, %o0
F0094430: 12800005                 bne     locret_F0094444
F0094434: 01000000                 nop
F0094438: c0232002                 clr     [%o4+2]
F009443C: 9002e001                 add     %o3, 1, %o0
F0094440: d02aa016                 stb     %o0, [%o2+0x16]
F0094444: 81c7e008                 ret
F0094448: 81e80000                 restore
