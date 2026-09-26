F00C2C34: 9de3bf90                 save    %sp, -0x70, %sp
F00C2C38: 1310019d92126008         set     0x40067408, %o1
F00C2C40: a207bff0                 add     %fp, var_10, %l1
F00C2C44: 94100011                 mov     %l1, %o2
F00C2C48: d8166038                 lduh    [%i1+0x38], %o4
F00C2C4C: 96102000                 mov     0, %o3
F00C2C50: 992b2010                 sll     %o4, 16, %o4
F00C2C54: a13b2010                 sra     %o4, 16, %l0
F00C2C58: 99332018                 srl     %o4, 24, %o4
F00C2C5C: 912b2001                 sll     %o4, 1, %o0
F00C2C60: 9002000c                 add     %o0, %o4, %o0
F00C2C64: 912a2002                 sll     %o0, 2, %o0
F00C2C68: 9022000c                 sub     %o0, %o4, %o0
F00C2C6C: 912a2002                 sll     %o0, 2, %o0
F00C2C70: 193c0472981321f0         set     _cdevsw, %o4
F00C2C78: b202000c                 add     %o0, %o4, %i1
F00C2C7C: d8066010                 ld      [%i1+0x10], %o4
F00C2C80: 9fc30000                 call    %o4
F00C2C84: 90100010                 mov     %l0, %o0
F00C2C88: 98920000                 orcc    %o0, %g0, %o4
F00C2C8C: 02800015                 be      loc_F00C2CE0
F00C2C90: 901020e0                 mov     0xE0, %o0
F00C2C94: d0062024                 ld      [%i0+0x24], %o0
F00C2C98: 80a2200c                 cmp     %o0, 0xC
F00C2C9C: 113c0484                 sethi   %hi(aMouseBaudRateC), %o0! "mouse baud rate change from %s to %s er"...
F00C2CA0: 12800005                 bne     loc_F00C2CB4
F00C2CA4: 921222d8                 or      %o0, %lo(aMouseBaudRateC), %o1! "mouse baud rate change from %s to %s er"...
F00C2CA8: 113c0484                 sethi   %hi(aB4800), %o0! "B4800"
F00C2CAC: 10800004                 ba      loc_F00C2CBC
F00C2CB0: 94122308                 or      %o0, %lo(aB4800), %o2! "B4800"
F00C2CB4: 113c048494122310         set     aB1200, %o2! "B1200"
F00C2CBC: d04fbff0                 ldsb    [%fp+var_10], %o0
F00C2CC0: 80a2200c                 cmp     %o0, 0xC
F00C2CC4: 12800005                 bne     loc_F00C2CD8
F00C2CC8: 113c0484                 sethi   -0xFEDF000, %o0
F00C2CCC: 113c0484                 sethi   %hi(aB4800_0), %o0! "B4800"
F00C2CD0: 10800025                 ba      loc_F00C2D64
F00C2CD4: 96122318                 or      %o0, %lo(aB4800_0), %o3! "B4800"
F00C2CD8: 10800023                 ba      loc_F00C2D64
F00C2CDC: 96122320                 or      %o0, 0x320, %o3
F00C2CE0: d037bff4                 sth     %o0, [%fp+var_C]
F00C2CE4: 7fffffca                 call    sub_F00C2C0C
F00C2CE8: d0062024                 ld      [%i0+0x24], %o0
F00C2CEC: d02fbff1                 stb     %o0, [%fp+var_F]
F00C2CF0: d02fbff0                 stb     %o0, [%fp+var_10]
F00C2CF4: 90100010                 mov     %l0, %o0
F00C2CF8: 1320019d92126009         set     -0x7FF98BF7, %o1
F00C2D00: 94100011                 mov     %l1, %o2
F00C2D04: d8066010                 ld      [%i1+0x10], %o4
F00C2D08: 9fc30000                 call    %o4
F00C2D0C: 96102000                 mov     0, %o3
F00C2D10: 98920000                 orcc    %o0, %g0, %o4
F00C2D14: 02800017                 be      loc_F00C2D70
F00C2D18: 113c0484                 sethi   -0xFEDF000, %o0
F00C2D1C: d0062024                 ld      [%i0+0x24], %o0
F00C2D20: 80a2200c                 cmp     %o0, 0xC
F00C2D24: 113c0484                 sethi   %hi(aMouseBaudRateC_0), %o0! "mouse baud rate change from %s to %s er"...
F00C2D28: 12800005                 bne     loc_F00C2D3C
F00C2D2C: 92122328                 or      %o0, %lo(aMouseBaudRateC_0), %o1! "mouse baud rate change from %s to %s er"...
F00C2D30: 113c0484                 sethi   %hi(aB4800_1), %o0! "B4800"
F00C2D34: 10800004                 ba      loc_F00C2D44
F00C2D38: 94122358                 or      %o0, %lo(aB4800_1), %o2! "B4800"
F00C2D3C: 113c048494122360         set     aB1200_0, %o2! "B1200"
F00C2D44: d04fbff0                 ldsb    [%fp+var_10], %o0
F00C2D48: 80a2200c                 cmp     %o0, 0xC
F00C2D4C: 12800005                 bne     loc_F00C2D60
F00C2D50: 113c0484                 sethi   -0xFEDF000, %o0
F00C2D54: 113c0484                 sethi   %hi(aB4800_2), %o0! "B4800"
F00C2D58: 10800003                 ba      loc_F00C2D64
F00C2D5C: 96122368                 or      %o0, %lo(aB4800_2), %o3! "B4800"
F00C2D60: 96122370                 or      %o0, 0x370, %o3
F00C2D64: 7ffd4694                 call    _log
F00C2D68: 90102005                 mov     5, %o0
F00C2D6C: 30800020                 ba,a    locret_F00C2DEC
F00C2D70: d0022130                 ld      [%o0+0x130], %o0
F00C2D74: 80a22000                 cmp     %o0, 0
F00C2D78: 22800017                 be,a    loc_F00C2DD4
F00C2D7C: d24fbff0                 ldsb    [%fp+var_10], %o1
F00C2D80: d0062024                 ld      [%i0+0x24], %o0
F00C2D84: 80a2200c                 cmp     %o0, 0xC
F00C2D88: 113c0484                 sethi   %hi(aMouseBaudRateC_1), %o0! "mouse baud rate change from %s to %s.\n"
F00C2D8C: 12800005                 bne     loc_F00C2DA0
F00C2D90: 92122378                 or      %o0, %lo(aMouseBaudRateC_1), %o1! "mouse baud rate change from %s to %s.\n"
F00C2D94: 113c0484                 sethi   %hi(aB4800_3), %o0! "B4800"
F00C2D98: 10800004                 ba      loc_F00C2DA8
F00C2D9C: 941223a0                 or      %o0, %lo(aB4800_3), %o2! "B4800"
F00C2DA0: 113c0484941223a8         set     aB1200_1, %o2! "B1200"
F00C2DA8: d04fbff0                 ldsb    [%fp+var_10], %o0
F00C2DAC: 80a2200c                 cmp     %o0, 0xC
F00C2DB0: 12800005                 bne     loc_F00C2DC4
F00C2DB4: 113c0484                 sethi   -0xFEDF000, %o0
F00C2DB8: 113c0484                 sethi   %hi(aB4800_4), %o0! "B4800"
F00C2DBC: 10800003                 ba      loc_F00C2DC8
F00C2DC0: 961223b0                 or      %o0, %lo(aB4800_4), %o3! "B4800"
F00C2DC4: 961223b8                 or      %o0, 0x3B8, %o3
F00C2DC8: 7ffd467b                 call    _log
F00C2DCC: 90102005                 mov     5, %o0
F00C2DD0: d24fbff0                 ldsb    [%fp+var_10], %o1
F00C2DD4: 90100018                 mov     %i0, %o0
F00C2DD8: d2222024                 st      %o1, [%o0+0x24]
F00C2DDC: 92102001                 mov     1, %o1
F00C2DE0: d2222028                 st      %o1, [%o0+0x28]
F00C2DE4: 7ffffe2d                 call    sub_F00C2698
F00C2DE8: c0222030                 clr     [%o0+0x30]
F00C2DEC: 81c7e008                 ret
F00C2DF0: 81e80000                 restore
