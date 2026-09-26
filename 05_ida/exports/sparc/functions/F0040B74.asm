F0040B74: 9de3bf50                 save    %sp, -0xB0, %sp
F0040B78: d0062040                 ld      [%i0+0x40], %o0
F0040B7C: a6100008                 mov     %o0, %l3
F0040B80: d004e01c                 ld      [%l3+0x1C], %o0
F0040B84: d2022080                 ld      [%o0+0x80], %o1
F0040B88: e404e030                 ld      [%l3+0x30], %l2
F0040B8C: 9fc24000                 call    %o1
F0040B90: 90100013                 mov     %l3, %o0
F0040B94: d2060000                 ld      [%i0], %o1
F0040B98: 808a6001                 btst    1, %o1
F0040B9C: 0280002a                 be      loc_F0040C44
F0040BA0: a2100008                 mov     %o0, %l1
F0040BA4: d0062024                 ld      [%i0+0x24], %o0
F0040BA8: 7fff1656                 call    _umul
F0040BAC: 92100011                 mov     %l1, %o1
F0040BB0: 94100008                 mov     %o0, %o2
F0040BB4: d2062020                 ld      [%i0+0x20], %o1
F0040BB8: 90100013                 mov     %l3, %o0
F0040BBC: d6062014                 ld      [%i0+0x14], %o3
F0040BC0: 98062028                 add     %i0, 0x28, %o4 ! '('
F0040BC4: da04a070                 ld      [%l2+0x70], %o5
F0040BC8: 8407bfb8                 add     %fp, var_48, %g2
F0040BCC: 7ffffa7a                 call    sub_F003F5B4
F0040BD0: c423a05c                 st      %g2, [%sp+0xB0+var_54]
F0040BD4: d036201c                 sth     %o0, [%i0+0x1C]
F0040BD8: 912a2010                 sll     %o0, 16, %o0
F0040BDC: a13a2010                 sra     %o0, 16, %l0
F0040BE0: 80a42000                 cmp     %l0, 0
F0040BE4: 12800041                 bne     loc_F0040CE8
F0040BE8: 01000000                 nop
F0040BEC: d2062028                 ld      [%i0+0x28], %o1! size_t
F0040BF0: 80a26000                 cmp     %o1, 0
F0040BF4: 02800008                 be      loc_F0040C14
F0040BF8: d0062014                 ld      [%i0+0x14], %o0
F0040BFC: d4062020                 ld      [%i0+0x20], %o2
F0040C00: 90220009                 sub     %o0, %o1, %o0! void *
F0040C04: 40015095                 call    _bzero
F0040C08: 90028008                 add     %o2, %o0, %o0
F0040C0C: d2062028                 ld      [%i0+0x28], %o1
F0040C10: d0062014                 ld      [%i0+0x14], %o0
F0040C14: 80a24008                 cmp     %o1, %o0
F0040C18: 12800034                 bne     loc_F0040CE8
F0040C1C: 80a42000                 cmp     %l0, 0
F0040C20: d0062024                 ld      [%i0+0x24], %o0
F0040C24: 7fff1637                 call    _umul
F0040C28: 92100011                 mov     %l1, %o1
F0040C2C: d204a098                 ld      [%l2+0x98], %o1
F0040C30: 80a20009                 cmp     %o0, %o1
F0040C34: 3a80002c                 bcc,a   loc_F0040CE4
F0040C38: a0103f9e                 mov     -0x62, %l0
F0040C3C: 1080002b                 ba      loc_F0040CE8
F0040C40: 80a42000                 cmp     %l0, 0
F0040C44: d054a062                 ldsh    [%l2+0x62], %o0
F0040C48: 80a22000                 cmp     %o0, 0
F0040C4C: 12800024                 bne     loc_F0040CDC
F0040C50: 92100008                 mov     %o0, %o1
F0040C54: d0062024                 ld      [%i0+0x24], %o0
F0040C58: 7fff162a                 call    _umul
F0040C5C: 92100011                 mov     %l1, %o1
F0040C60: d204a098                 ld      [%l2+0x98], %o1
F0040C64: d4062014                 ld      [%i0+0x14], %o2
F0040C68: 96224008                 sub     %o1, %o0, %o3
F0040C6C: 80a2800b                 cmp     %o2, %o3
F0040C70: 0a800003                 bcs     loc_F0040C7C
F0040C74: a010000a                 mov     %o2, %l0
F0040C78: a010000b                 mov     %o3, %l0
F0040C7C: 80a42000                 cmp     %l0, 0
F0040C80: 36800006                 bge,a   loc_F0040C98
F0040C84: d0062024                 ld      [%i0+0x24], %o0
F0040C88: 113c0435                 sethi   %hi(aDoBioWriteCoun), %o0! "do_bio: write count < 0"
F0040C8C: 7fff5139                 call    _panic
F0040C90: 90122328                 bset    %lo(aDoBioWriteCoun), %o0! "do_bio: write count < 0"
F0040C94: d0062024                 ld      [%i0+0x24], %o0
F0040C98: 7fff161a                 call    _umul
F0040C9C: 92100011                 mov     %l1, %o1
F0040CA0: 94100008                 mov     %o0, %o2
F0040CA4: d2062020                 ld      [%i0+0x20], %o1
F0040CA8: 90100013                 mov     %l3, %o0
F0040CAC: d804a070                 ld      [%l2+0x70], %o4
F0040CB0: 7ffff9cc                 call    _nfswrite
F0040CB4: 96100010                 mov     %l0, %o3
F0040CB8: 94100008                 mov     %o0, %o2
F0040CBC: d436201c                 sth     %o2, [%i0+0x1C]
F0040CC0: 912a2010                 sll     %o0, 16, %o0
F0040CC4: d2060000                 ld      [%i0], %o1
F0040CC8: 808a6100                 btst    0x100, %o1
F0040CCC: 02800006                 be      loc_F0040CE4
F0040CD0: a13a2010                 sra     %o0, 16, %l0
F0040CD4: 10800004                 ba      loc_F0040CE4
F0040CD8: d434a062                 sth     %o2, [%l2+0x62]
F0040CDC: d236201c                 sth     %o1, [%i0+0x1C]
F0040CE0: a0100008                 mov     %o0, %l0
F0040CE4: 80a42000                 cmp     %l0, 0
F0040CE8: 0280000f                 be      loc_F0040D24
F0040CEC: 80a43f9e                 cmp     %l0, -0x62
F0040CF0: 0280000d                 be      loc_F0040D24
F0040CF4: 01000000                 nop
F0040CF8: d0060000                 ld      [%i0], %o0
F0040CFC: 90122004                 bset    4, %o0
F0040D00: d0260000                 st      %o0, [%i0]
F0040D04: d204c000                 ld      [%l3], %o1
F0040D08: 80a26000                 cmp     %o1, 0
F0040D0C: 02800006                 be      loc_F0040D24
F0040D10: 01000000                 nop
F0040D14: d0026034                 ld      [%o1+0x34], %o0
F0040D18: 80a22000                 cmp     %o0, 0
F0040D1C: 22800002                 be,a    loc_F0040D24
F0040D20: e0226034                 st      %l0, [%o1+0x34]
F0040D24: 7fff90eb                 call    _biodone
F0040D28: 90100018                 mov     %i0, %o0
F0040D2C: 81c7e008                 ret
F0040D30: 91e80010                 restore %g0, %l0, %o0
