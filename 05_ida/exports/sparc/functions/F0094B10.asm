F0094B10: 80a2a009                 cmp     %o2, 9
F0094B14: 04800062                 ble     loc_F0094C9C
F0094B18: 9a8a2003                 andcc   %o0, 3, %o5
F0094B1C: 02800013                 be      loc_F0094B68
F0094B20: 80a36002                 cmp     %o5, 2
F0094B24: 0280000a                 be      loc_F0094B4C
F0094B28: 80a36003                 cmp     %o5, 3
F0094B2C: d60a0000                 ldub    [%o0], %o3
F0094B30: 90022001                 inc     %o0
F0094B34: d62a4000                 stb     %o3, [%o1]
F0094B38: 92026001                 inc     %o1
F0094B3C: 12800004                 bne     loc_F0094B4C
F0094B40: 9422a001                 dec     %o2
F0094B44: 1080000a                 ba      loc_F0094B6C
F0094B48: 9a8a6003                 andcc   %o1, 3, %o5
F0094B4C: d6120000                 lduh    [%o0], %o3
F0094B50: 90022002                 inc     2, %o0
F0094B54: 9932e008                 srl     %o3, 8, %o4
F0094B58: d82a4000                 stb     %o4, [%o1]
F0094B5C: d62a6001                 stb     %o3, [%o1+1]
F0094B60: 92026002                 inc     2, %o1
F0094B64: 9422a002                 dec     2, %o2
F0094B68: 9a8a6003                 andcc   %o1, 3, %o5
F0094B6C: 0280003c                 be      loc_F0094C5C
F0094B70: 80a36002                 cmp     %o5, 2
F0094B74: 02800027                 be      loc_F0094C10
F0094B78: 80a36003                 cmp     %o5, 3
F0094B7C: d8020000                 ld      [%o0], %o4
F0094B80: 90022004                 inc     4, %o0
F0094B84: 9b332018                 srl     %o4, 24, %o5
F0094B88: da2a4000                 stb     %o5, [%o1]
F0094B8C: 12800010                 bne     loc_F0094BCC
F0094B90: 92026001                 inc     %o1
F0094B94: 9422a001                 dec     %o2
F0094B98: 962aa003                 andn    %o2, 3, %o3
F0094B9C: 90220009                 sub     %o0, %o1, %o0
F0094BA0: 832b2008                 sll     %o4, 8, %g1
F0094BA4: d8020009                 ld      [%o0+%o1], %o4
F0094BA8: 96a2e004                 deccc   4, %o3
F0094BAC: 9b332018                 srl     %o4, 24, %o5
F0094BB0: 82134001                 bset    %o5, %g1
F0094BB4: c2224000                 st      %g1, [%o1]
F0094BB8: 12bffffa                 bne     loc_F0094BA0
F0094BBC: 92026004                 inc     4, %o1
F0094BC0: 90222003                 dec     3, %o0
F0094BC4: 1080003a                 ba      loc_F0094CAC
F0094BC8: 940aa003                 and     %o2, 3, %o2
F0094BCC: 9b332008                 srl     %o4, 8, %o5
F0094BD0: da324000                 sth     %o5, [%o1]
F0094BD4: 92026002                 inc     2, %o1
F0094BD8: 9422a003                 dec     3, %o2
F0094BDC: 962aa003                 andn    %o2, 3, %o3
F0094BE0: 90220009                 sub     %o0, %o1, %o0
F0094BE4: 832b2018                 sll     %o4, 24, %g1
F0094BE8: d8020009                 ld      [%o0+%o1], %o4
F0094BEC: 96a2e004                 deccc   4, %o3
F0094BF0: 9b332008                 srl     %o4, 8, %o5
F0094BF4: 82134001                 bset    %o5, %g1
F0094BF8: c2224000                 st      %g1, [%o1]
F0094BFC: 12bffffa                 bne     loc_F0094BE4
F0094C00: 92026004                 inc     4, %o1
F0094C04: 90222001                 dec     %o0
F0094C08: 10800029                 ba      loc_F0094CAC
F0094C0C: 940aa003                 and     %o2, 3, %o2
F0094C10: d8020000                 ld      [%o0], %o4
F0094C14: 90022004                 inc     4, %o0
F0094C18: 9b332010                 srl     %o4, 16, %o5
F0094C1C: da324000                 sth     %o5, [%o1]
F0094C20: 92026002                 inc     2, %o1
F0094C24: 9422a002                 dec     2, %o2
F0094C28: 962aa003                 andn    %o2, 3, %o3
F0094C2C: 90220009                 sub     %o0, %o1, %o0
F0094C30: 832b2010                 sll     %o4, 16, %g1
F0094C34: d8020009                 ld      [%o0+%o1], %o4
F0094C38: 96a2e004                 deccc   4, %o3
F0094C3C: 9b332010                 srl     %o4, 16, %o5
F0094C40: 82134001                 bset    %o5, %g1
F0094C44: c2224000                 st      %g1, [%o1]
F0094C48: 12bffffa                 bne     loc_F0094C30
F0094C4C: 92026004                 inc     4, %o1
F0094C50: 90222002                 dec     2, %o0
F0094C54: 10800016                 ba      loc_F0094CAC
F0094C58: 940aa003                 and     %o2, 3, %o2
F0094C5C: 80a2a200                 cmp     %o2, 0x200
F0094C60: 06800006                 bl      loc_F0094C78
F0094C64: 808a2007                 btst    7, %o0
F0094C68: 12800004                 bne     loc_F0094C78
F0094C6C: 808a6007                 btst    7, %o1
F0094C70: 22800014                 be,a    loc_F0094CC0
F0094C74: 96102100                 mov     0x100, %o3
F0094C78: 90220009                 sub     %o0, %o1, %o0
F0094C7C: 962aa003                 andn    %o2, 3, %o3
F0094C80: d8020009                 ld      [%o0+%o1], %o4
F0094C84: 96a2e004                 deccc   4, %o3
F0094C88: d8224000                 st      %o4, [%o1]
F0094C8C: 14bffffd                 bg      loc_F0094C80
F0094C90: 92026004                 inc     4, %o1
F0094C94: 10800006                 ba      loc_F0094CAC
F0094C98: 940aa003                 and     %o2, 3, %o2
F0094C9C: 10800004                 ba      loc_F0094CAC
F0094CA0: 90220009                 sub     %o0, %o1, %o0
F0094CA4: d82a4000                 stb     %o4, [%o1]
F0094CA8: 92026001                 inc     %o1
F0094CAC: 94a2a001                 deccc   %o2
F0094CB0: 36bffffd                 bge,a   loc_F0094CA4
F0094CB4: d80a0009                 ldub    [%o0+%o1], %o4
F0094CB8: 81c3e008                 retl
F0094CBC: 90102000                 mov     0, %o0
F0094CC0: 9de3bfa0                 save    %sp, -0x60, %sp
F0094CC4: e01e20f8                 ldd     [%i0+0xF8], %l0
F0094CC8: e41e20f0                 ldd     [%i0+0xF0], %l2
F0094CCC: e81e20e8                 ldd     [%i0+0xE8], %l4
F0094CD0: ec1e20e0                 ldd     [%i0+0xE0], %l6
F0094CD4: e03e60f8                 std     %l0, [%i1+0xF8]
F0094CD8: e43e60f0                 std     %l2, [%i1+0xF0]
F0094CDC: e83e60e8                 std     %l4, [%i1+0xE8]
F0094CE0: ec3e60e0                 std     %l6, [%i1+0xE0]
F0094CE4: e01e20d8                 ldd     [%i0+0xD8], %l0
F0094CE8: e41e20d0                 ldd     [%i0+0xD0], %l2
F0094CEC: e81e20c8                 ldd     [%i0+0xC8], %l4
F0094CF0: ec1e20c0                 ldd     [%i0+0xC0], %l6
F0094CF4: e03e60d8                 std     %l0, [%i1+0xD8]
F0094CF8: e43e60d0                 std     %l2, [%i1+0xD0]
F0094CFC: e83e60c8                 std     %l4, [%i1+0xC8]
F0094D00: ec3e60c0                 std     %l6, [%i1+0xC0]
F0094D04: e01e20b8                 ldd     [%i0+0xB8], %l0
F0094D08: e41e20b0                 ldd     [%i0+0xB0], %l2
F0094D0C: e81e20a8                 ldd     [%i0+0xA8], %l4
F0094D10: ec1e20a0                 ldd     [%i0+0xA0], %l6
F0094D14: e03e60b8                 std     %l0, [%i1+0xB8]
F0094D18: e43e60b0                 std     %l2, [%i1+0xB0]
F0094D1C: e83e60a8                 std     %l4, [%i1+0xA8]
F0094D20: ec3e60a0                 std     %l6, [%i1+0xA0]
F0094D24: e01e2098                 ldd     [%i0+0x98], %l0
F0094D28: e41e2090                 ldd     [%i0+0x90], %l2
F0094D2C: e81e2088                 ldd     [%i0+0x88], %l4
F0094D30: ec1e2080                 ldd     [%i0+0x80], %l6
F0094D34: e03e6098                 std     %l0, [%i1+0x98]
F0094D38: e43e6090                 std     %l2, [%i1+0x90]
F0094D3C: e83e6088                 std     %l4, [%i1+0x88]
F0094D40: ec3e6080                 std     %l6, [%i1+0x80]
F0094D44: e01e2078                 ldd     [%i0+0x78], %l0
F0094D48: e41e2070                 ldd     [%i0+0x70], %l2
F0094D4C: e81e2068                 ldd     [%i0+0x68], %l4
F0094D50: ec1e2060                 ldd     [%i0+0x60], %l6
F0094D54: e03e6078                 std     %l0, [%i1+0x78]
F0094D58: e43e6070                 std     %l2, [%i1+0x70]
F0094D5C: e83e6068                 std     %l4, [%i1+0x68]
F0094D60: ec3e6060                 std     %l6, [%i1+0x60]
F0094D64: e01e2058                 ldd     [%i0+0x58], %l0
F0094D68: e41e2050                 ldd     [%i0+0x50], %l2
F0094D6C: e81e2048                 ldd     [%i0+0x48], %l4
F0094D70: ec1e2040                 ldd     [%i0+0x40], %l6
F0094D74: e03e6058                 std     %l0, [%i1+0x58]
F0094D78: e43e6050                 std     %l2, [%i1+0x50]
F0094D7C: e83e6048                 std     %l4, [%i1+0x48]
F0094D80: ec3e6040                 std     %l6, [%i1+0x40]
F0094D84: e01e2038                 ldd     [%i0+0x38], %l0
F0094D88: e41e2030                 ldd     [%i0+0x30], %l2
F0094D8C: e81e2028                 ldd     [%i0+0x28], %l4
F0094D90: ec1e2020                 ldd     [%i0+0x20], %l6
F0094D94: e03e6038                 std     %l0, [%i1+0x38]
F0094D98: e43e6030                 std     %l2, [%i1+0x30]
F0094D9C: e83e6028                 std     %l4, [%i1+0x28]
F0094DA0: ec3e6020                 std     %l6, [%i1+0x20]
F0094DA4: e01e2018                 ldd     [%i0+0x18], %l0
F0094DA8: e41e2010                 ldd     [%i0+0x10], %l2
F0094DAC: e81e2008                 ldd     [%i0+8], %l4
F0094DB0: ec1e0000                 ldd     [%i0], %l6
F0094DB4: e03e6018                 std     %l0, [%i1+0x18]
F0094DB8: e43e6010                 std     %l2, [%i1+0x10]
F0094DBC: e83e6008                 std     %l4, [%i1+8]
F0094DC0: ec3e4000                 std     %l6, [%i1]
F0094DC4: b426801b                 sub     %i2, %i3, %i2
F0094DC8: b006001b                 add     %i0, %i3, %i0
F0094DCC: 80a6a100                 cmp     %i2, 0x100
F0094DD0: 16bfffbd                 bge     loc_F0094CC4
F0094DD4: b206401b                 add     %i1, %i3, %i1
F0094DD8: 81e80000                 restore
F0094DDC: 80a2a009                 cmp     %o2, 9
F0094DE0: 04bfffb3                 ble     loc_F0094CAC
F0094DE4: 90220009                 sub     %o0, %o1, %o0
F0094DE8: 10bfffa6                 ba      loc_F0094C80
F0094DEC: 962aa003                 andn    %o2, 3, %o3
