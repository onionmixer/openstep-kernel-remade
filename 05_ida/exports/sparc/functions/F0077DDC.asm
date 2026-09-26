F0077DDC: 9de3bf98                 save    %sp, -0x68, %sp
F0077DE0: 98100018                 mov     %i0, %o4
F0077DE4: e0032008                 ld      [%o4+8], %l0
F0077DE8: 80a42000                 cmp     %l0, 0
F0077DEC: 32800004                 bne,a   loc_F0077DFC
F0077DF0: d0042004                 ld      [%l0+4], %o0
F0077DF4: 1080004f                 ba      locret_F0077F30
F0077DF8: b0102000                 mov     0, %i0
F0077DFC: 80a20019                 cmp     %o0, %i1
F0077E00: 0a800006                 bcs     loc_F0077E18
F0077E04: 9010000c                 mov     %o4, %o0
F0077E08: 7fffff3f                 call    sub_F0077B04
F0077E0C: 92100010                 mov     %l0, %o1
F0077E10: 10800048                 ba      locret_F0077F30
F0077E14: b0100010                 mov     %l0, %i0
F0077E18: d0032010                 ld      [%o4+0x10], %o0
F0077E1C: d2032018                 ld      [%o4+0x18], %o1
F0077E20: 91364008                 srl     %i1, %o0, %o0
F0077E24: 80a20009                 cmp     %o0, %o1
F0077E28: 04800003                 ble     loc_F0077E34
F0077E2C: 94100008                 mov     %o0, %o2
F0077E30: 94100009                 mov     %o1, %o2
F0077E34: 80a28009                 cmp     %o2, %o1
F0077E38: d0032014                 ld      [%o4+0x14], %o0
F0077E3C: 932aa004                 sll     %o2, 4, %o1
F0077E40: 90020009                 add     %o0, %o1, %o0
F0077E44: 16800019                 bge     loc_F0077EA8
F0077E48: 96023ff0                 add     %o0, -0x10, %o3
F0077E4C: e002c000                 ld      [%o3], %l0
F0077E50: 80a42000                 cmp     %l0, 0
F0077E54: 22800011                 be,a    loc_F0077E98
F0077E58: 9402a001                 inc     %o2
F0077E5C: d2040000                 ld      [%l0], %o1
F0077E60: 80a26000                 cmp     %o1, 0
F0077E64: 22800032                 be,a    loc_F0077F2C
F0077E68: d222c000                 st      %o1, [%o3]
F0077E6C: d4042004                 ld      [%l0+4], %o2
F0077E70: d0026004                 ld      [%o1+4], %o0
F0077E74: 80a2000a                 cmp     %o0, %o2
F0077E78: 2280002d                 be,a    loc_F0077F2C
F0077E7C: d222c000                 st      %o1, [%o3]
F0077E80: d2024000                 ld      [%o1], %o1
F0077E84: 80a26000                 cmp     %o1, 0
F0077E88: 32bffffb                 bne,a   loc_F0077E74
F0077E8C: d0026004                 ld      [%o1+4], %o0
F0077E90: 10800027                 ba      loc_F0077F2C
F0077E94: d222c000                 st      %o1, [%o3]
F0077E98: d0032018                 ld      [%o4+0x18], %o0
F0077E9C: 80a28008                 cmp     %o2, %o0
F0077EA0: 06bfffeb                 bl      loc_F0077E4C
F0077EA4: 9602e010                 inc     0x10, %o3
F0077EA8: e002c000                 ld      [%o3], %l0
F0077EAC: 80a42000                 cmp     %l0, 0
F0077EB0: 02800020                 be      locret_F0077F30
F0077EB4: b0100010                 mov     %l0, %i0
F0077EB8: d0042004                 ld      [%l0+4], %o0
F0077EBC: 80a20019                 cmp     %o0, %i1
F0077EC0: 1a80000e                 bcc     loc_F0077EF8
F0077EC4: f0040000                 ld      [%l0], %i0
F0077EC8: 80a62000                 cmp     %i0, 0
F0077ECC: 02800019                 be      locret_F0077F30
F0077ED0: 01000000                 nop
F0077ED4: d0062004                 ld      [%i0+4], %o0
F0077ED8: 80a20019                 cmp     %o0, %i1
F0077EDC: 1a800015                 bcc     locret_F0077F30
F0077EE0: 01000000                 nop
F0077EE4: f0060000                 ld      [%i0], %i0
F0077EE8: 80a62000                 cmp     %i0, 0
F0077EEC: 32bffffb                 bne,a   loc_F0077ED8
F0077EF0: d0062004                 ld      [%i0+4], %o0
F0077EF4: 3080000f                 ba,a    locret_F0077F30
F0077EF8: 80a62000                 cmp     %i0, 0
F0077EFC: 2280000c                 be,a    loc_F0077F2C
F0077F00: f022c000                 st      %i0, [%o3]
F0077F04: d2032004                 ld      [%o4+4], %o1
F0077F08: d0062004                 ld      [%i0+4], %o0
F0077F0C: 80a20009                 cmp     %o0, %o1
F0077F10: 3a800007                 bcc,a   loc_F0077F2C
F0077F14: f022c000                 st      %i0, [%o3]
F0077F18: f0060000                 ld      [%i0], %i0
F0077F1C: 80a62000                 cmp     %i0, 0
F0077F20: 32bffffb                 bne,a   loc_F0077F0C
F0077F24: d0062004                 ld      [%i0+4], %o0
F0077F28: f022c000                 st      %i0, [%o3]
F0077F2C: b0100010                 mov     %l0, %i0
F0077F30: 81c7e008                 ret
F0077F34: 81e80000                 restore
