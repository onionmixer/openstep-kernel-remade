F0025AE0: 9de3bf98                 save    %sp, -0x68, %sp
F0025AE4: 113c0430                 sethi   %hi(_doingcache), %o0
F0025AE8: d0022090                 ld      [%o0+%lo(_doingcache)], %o0! __s
F0025AEC: 80a22000                 cmp     %o0, 0
F0025AF0: 12800004                 bne     loc_F0025B00
F0025AF4: 01000000                 nop
F0025AF8: 1080004a                 ba      locret_F0025C20
F0025AFC: b0102000                 mov     0, %i0
F0025B00: 7fff864e                 call    _strlen
F0025B04: 90100019                 mov     %i1, %o0
F0025B08: 96100008                 mov     %o0, %o3
F0025B0C: 80a2e020                 cmp     %o3, 0x20 ! ' '
F0025B10: 04800008                 ble     loc_F0025B30
F0025B14: 133c04d5                 sethi   %hi(_ncstats), %o1
F0025B18: 921261f0                 bset    %lo(_ncstats), %o1
F0025B1C: d0026014                 ld      [%o1+0x14], %o0
F0025B20: b0102000                 mov     0, %i0
F0025B24: 90022001                 inc     %o0
F0025B28: 1080003e                 ba      locret_F0025C20
F0025B2C: d0226014                 st      %o0, [%o1+0x14]
F0025B30: 9002c019                 add     %o3, %i1, %o0
F0025B34: d44a3fff                 ldsb    [%o0-1], %o2
F0025B38: 9810001a                 mov     %i2, %o4
F0025B3C: d24e4000                 ldsb    [%i1], %o1
F0025B40: 90100018                 mov     %i0, %o0
F0025B44: 9202400a                 add     %o1, %o2, %o1
F0025B48: 9202400b                 add     %o1, %o3, %o1
F0025B4C: 92024008                 add     %o1, %o0, %o1
F0025B50: b00a603f                 and     %o1, 0x3F, %i0
F0025B54: 92100019                 mov     %i1, %o1
F0025B58: 9410000b                 mov     %o3, %o2
F0025B5C: 400000d9                 call    sub_F0025EC0
F0025B60: 96100018                 mov     %i0, %o3
F0025B64: 94920000                 orcc    %o0, %g0, %o2
F0025B68: 12800008                 bne     loc_F0025B88
F0025B6C: 133c04d5                 sethi   %hi(_ncstats), %o1
F0025B70: 921261f0                 bset    %lo(_ncstats), %o1
F0025B74: d0026004                 ld      [%o1+4], %o0
F0025B78: b0102000                 mov     0, %i0
F0025B7C: 90022001                 inc     %o0
F0025B80: 10800028                 ba      locret_F0025C20
F0025B84: d0226004                 st      %o0, [%o1+4]
F0025B88: d00261f0                 ld      [%o1+0x1F0], %o0
F0025B8C: 90022001                 inc     %o0
F0025B90: d02261f0                 st      %o0, [%o1+0x1F0]
F0025B94: d202a00c                 ld      [%o2+0xC], %o1
F0025B98: d002a008                 ld      [%o2+8], %o0
F0025B9C: d0226008                 st      %o0, [%o1+8]
F0025BA0: d202a008                 ld      [%o2+8], %o1
F0025BA4: d002a00c                 ld      [%o2+0xC], %o0
F0025BA8: d022600c                 st      %o0, [%o1+0xC]
F0025BAC: 113c04d5                 sethi   %hi(dword_F01355DC), %o0
F0025BB0: d00221dc                 ld      [%o0+%lo(dword_F01355DC)], %o0
F0025BB4: d2022008                 ld      [%o0+8], %o1
F0025BB8: d4222008                 st      %o2, [%o0+8]
F0025BBC: d222a008                 st      %o1, [%o2+8]
F0025BC0: d422600c                 st      %o2, [%o1+0xC]
F0025BC4: d022a00c                 st      %o0, [%o2+0xC]
F0025BC8: 932e2003                 sll     %i0, 3, %o1
F0025BCC: 113c04d4901223d0         set     _nc_hash, %o0
F0025BD4: d602a004                 ld      [%o2+4], %o3
F0025BD8: 92024008                 add     %o1, %o0, %o1
F0025BDC: 80a2c009                 cmp     %o3, %o1
F0025BE0: 22800010                 be,a    locret_F0025C20
F0025BE4: f002a010                 ld      [%o2+0x10], %i0
F0025BE8: d0028000                 ld      [%o2], %o0
F0025BEC: d6222004                 st      %o3, [%o0+4]
F0025BF0: d202a004                 ld      [%o2+4], %o1
F0025BF4: d0028000                 ld      [%o2], %o0
F0025BF8: d0224000                 st      %o0, [%o1]
F0025BFC: d002a004                 ld      [%o2+4], %o0
F0025C00: d2022004                 ld      [%o0+4], %o1
F0025C04: d0024000                 ld      [%o1], %o0
F0025C08: d0228000                 st      %o0, [%o2]
F0025C0C: d222a004                 st      %o1, [%o2+4]
F0025C10: d0024000                 ld      [%o1], %o0
F0025C14: d4222004                 st      %o2, [%o0+4]
F0025C18: d4224000                 st      %o2, [%o1]
F0025C1C: f002a010                 ld      [%o2+0x10], %i0
F0025C20: 81c7e008                 ret
F0025C24: 81e80000                 restore
