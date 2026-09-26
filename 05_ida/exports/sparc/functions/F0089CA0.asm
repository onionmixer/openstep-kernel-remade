F0089CA0: 9de3bf98                 save    %sp, -0x68, %sp
F0089CA4: a2102001                 mov     1, %l1
F0089CA8: 80a62000                 cmp     %i0, 0
F0089CAC: 02800044                 be      loc_F0089DBC
F0089CB0: a4102000                 mov     0, %l2
F0089CB4: a0062010                 add     %i0, 0x10, %l0
F0089CB8: d0040000                 ld      [%l0], %o0
F0089CBC: 80a22000                 cmp     %o0, 0
F0089CC0: 12bffffe                 bne     loc_F0089CB8
F0089CC4: 01000000                 nop
F0089CC8: 40003478                 call    _simple_lock_try
F0089CCC: 90100010                 mov     %l0, %o0
F0089CD0: 80a22000                 cmp     %o0, 0
F0089CD4: 02bffff9                 be      loc_F0089CB8
F0089CD8: 01000000                 nop
F0089CDC: e0060000                 ld      [%i0], %l0
F0089CE0: 80a60010                 cmp     %i0, %l0
F0089CE4: 2280001b                 be,a    loc_F0089D50
F0089CE8: d0062014                 ld      [%i0+0x14], %o0
F0089CEC: d0042018                 ld      [%l0+0x18], %o0
F0089CF0: 80a20019                 cmp     %o0, %i1
F0089CF4: 2a800013                 bcs,a   loc_F0089D40
F0089CF8: e0042008                 ld      [%l0+8], %l0
F0089CFC: 80a2001a                 cmp     %o0, %i2
F0089D00: 3a800010                 bcc,a   loc_F0089D40
F0089D04: e0042008                 ld      [%l0+8], %l0
F0089D08: 90100018                 mov     %i0, %o0
F0089D0C: 7fffff61                 call    sub_F0089A90
F0089D10: 92100010                 mov     %l0, %o1
F0089D14: 80a22001                 cmp     %o0, 1
F0089D18: 22800009                 be,a    loc_F0089D3C
F0089D1C: a2102000                 mov     0, %l1
F0089D20: 2a800008                 bcs,a   loc_F0089D40
F0089D24: e0042008                 ld      [%l0+8], %l0
F0089D28: 80a22002                 cmp     %o0, 2
F0089D2C: 32800005                 bne,a   loc_F0089D40
F0089D30: e0042008                 ld      [%l0+8], %l0
F0089D34: 10bfffeb                 ba      loc_F0089CE0
F0089D38: e0060000                 ld      [%i0], %l0
F0089D3C: e0042008                 ld      [%l0+8], %l0
F0089D40: 80a60010                 cmp     %i0, %l0
F0089D44: 32bfffeb                 bne,a   loc_F0089CF0
F0089D48: d0042018                 ld      [%l0+0x18], %o0
F0089D4C: d0062014                 ld      [%i0+0x14], %o0
F0089D50: 80a22000                 cmp     %o0, 0
F0089D54: 02800005                 be      loc_F0089D68
F0089D58: b4268019                 sub     %i2, %i1, %i2
F0089D5C: 80a68008                 cmp     %i2, %o0
F0089D60: 38800002                 bgu,a   loc_F0089D68
F0089D64: b4100008                 mov     %o0, %i2
F0089D68: d2062024                 ld      [%i0+0x24], %o1
F0089D6C: d0062020                 ld      [%i0+0x20], %o0
F0089D70: b2064009                 add     %i1, %o1, %i1
F0089D74: 92100019                 mov     %i1, %o1
F0089D78: 7fffffca                 call    sub_F0089CA0
F0089D7C: 9402401a                 add     %o1, %i2, %o2
F0089D80: 80a22000                 cmp     %o0, 0
F0089D84: 32800002                 bne,a   loc_F0089D8C
F0089D88: a4102005                 mov     5, %l2
F0089D8C: c0262010                 clr     [%i0+0x10]
F0089D90: 90100018                 mov     %i0, %o0
F0089D94: 92102000                 mov     0, %o1
F0089D98: 7fff9c99                 call    _thread_wakeup_prim
F0089D9C: 94102000                 mov     0, %o2
F0089DA0: 80a4a005                 cmp     %l2, 5
F0089DA4: 02800004                 be      loc_F0089DB4
F0089DA8: 80a46000                 cmp     %l1, 0
F0089DAC: 12800005                 bne     locret_F0089DC0
F0089DB0: b0102000                 mov     0, %i0
F0089DB4: 10800003                 ba      locret_F0089DC0
F0089DB8: b0102005                 mov     5, %i0
F0089DBC: b0102000                 mov     0, %i0
F0089DC0: 81c7e008                 ret
F0089DC4: 81e80000                 restore
