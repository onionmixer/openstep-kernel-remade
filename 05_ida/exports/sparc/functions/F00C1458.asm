F00C1458: 9de3bf98                 save    %sp, -0x68, %sp
F00C145C: f027a044                 st      %i0, [%fp+arg_44]
F00C1460: 7ffffea5                 call    sub_F00C0EF4
F00C1464: 9007a044                 add     %fp, arg_44, %o0
F00C1468: 133c0476                 sethi   %hi(_keytables), %o1
F00C146C: 80a22000                 cmp     %o0, 0
F00C1470: 02800005                 be      loc_F00C1484
F00C1474: f002623c                 ld      [%o1+%lo(_keytables)], %i0
F00C1478: 80a62000                 cmp     %i0, 0
F00C147C: 12800004                 bne     loc_F00C148C
F00C1480: 808e6080                 btst    0x80, %i1
F00C1484: 10800019                 ba      locret_F00C14E8
F00C1488: b0102000                 mov     0, %i0
F00C148C: 02800004                 be      loc_F00C149C
F00C1490: 808e6800                 btst    0x800, %i1
F00C1494: 10800015                 ba      locret_F00C14E8
F00C1498: f0062018                 ld      [%i0+0x18], %i0
F00C149C: 02800004                 be      loc_F00C14AC
F00C14A0: 808e6030                 btst    0x30, %i1 ! '0'
F00C14A4: 10800011                 ba      locret_F00C14E8
F00C14A8: f0062010                 ld      [%i0+0x10], %i0
F00C14AC: 02800004                 be      loc_F00C14BC
F00C14B0: 808e6200                 btst    0x200, %i1
F00C14B4: 1080000d                 ba      locret_F00C14E8
F00C14B8: f0062014                 ld      [%i0+0x14], %i0
F00C14BC: 02800004                 be      loc_F00C14CC
F00C14C0: 808e600e                 btst    0xE, %i1
F00C14C4: 10800009                 ba      locret_F00C14E8
F00C14C8: f006200c                 ld      [%i0+0xC], %i0
F00C14CC: 02800004                 be      loc_F00C14DC
F00C14D0: 808e6001                 btst    1, %i1
F00C14D4: 10800005                 ba      locret_F00C14E8
F00C14D8: f0062004                 ld      [%i0+4], %i0
F00C14DC: 32800003                 bne,a   locret_F00C14E8
F00C14E0: f0062008                 ld      [%i0+8], %i0
F00C14E4: f0060000                 ld      [%i0], %i0
F00C14E8: 81c7e008                 ret
F00C14EC: 81e80000                 restore
