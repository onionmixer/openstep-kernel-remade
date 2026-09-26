F0025C98: 9de3bf98                 save    %sp, -0x68, %sp
F0025C9C: 133c04d5921261f0         set     _ncstats, %o1
F0025CA4: d002601c                 ld      [%o1+0x1C], %o0
F0025CA8: 90022001                 inc     %o0
F0025CAC: d022601c                 st      %o0, [%o1+0x1C]
F0025CB0: 113c04d4                 sethi   -0xFECB000, %o0
F0025CB4: 901223d0                 bset    0x3D0, %o0
F0025CB8: 92022200                 add     %o0, 0x200, %o1
F0025CBC: 80a20009                 cmp     %o0, %o1
F0025CC0: 1a800017                 bcc     locret_F0025D1C
F0025CC4: 153c0430                 sethi   -0xFEF4000, %o2
F0025CC8: e0020000                 ld      [%o0], %l0
F0025CCC: 80a40008                 cmp     %l0, %o0
F0025CD0: 02800010                 be      loc_F0025D10
F0025CD4: 90022008                 inc     8, %o0
F0025CD8: d0042014                 ld      [%l0+0x14], %o0
F0025CDC: 80a22000                 cmp     %o0, 0
F0025CE0: 02800006                 be      loc_F0025CF8
F0025CE4: 01000000                 nop
F0025CE8: d0042010                 ld      [%l0+0x10], %o0! char *
F0025CEC: 80a22000                 cmp     %o0, 0
F0025CF0: 12800004                 bne     loc_F0025D00
F0025CF4: 01000000                 nop
F0025CF8: 7fffbd1e                 call    _panic
F0025CFC: 9012a098                 or      %o2, 0x98, %o0
F0025D00: 4000003e                 call    sub_F0025DF8
F0025D04: 90100010                 mov     %l0, %o0
F0025D08: 10bfffeb                 ba      loc_F0025CB4
F0025D0C: 113c04d4                 sethi   -0xFECB000, %o0
F0025D10: 80a20009                 cmp     %o0, %o1
F0025D14: 2abfffee                 bcs,a   loc_F0025CCC
F0025D18: e0020000                 ld      [%o0], %l0
F0025D1C: 81c7e008                 ret
F0025D20: 81e80000                 restore
