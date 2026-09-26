F0071A48: 9de3bf98                 save    %sp, -0x68, %sp
F0071A4C: 113c04f0                 sethi   %hi(_sched_tick), %o0
F0071A50: d2022298                 ld      [%o0+%lo(_sched_tick)], %o1
F0071A54: d0062070                 ld      [%i0+0x70], %o0
F0071A58: d2262070                 st      %o1, [%i0+0x70]
F0071A5C: a2224008                 sub     %o1, %o0, %l1
F0071A60: d206210c                 ld      [%i0+0x10C], %o1
F0071A64: d00620f8                 ld      [%i0+0xF8], %o0
F0071A68: 80a24008                 cmp     %o1, %o0
F0071A6C: 02800007                 be      loc_F0071A88
F0071A70: d40620f0                 ld      [%i0+0xF0], %o2
F0071A74: 900620f0                 add     %i0, 0xF0, %o0
F0071A78: 40001808                 call    _timer_delta
F0071A7C: 92062108                 add     %i0, 0x108, %o1
F0071A80: 10800005                 ba      loc_F0071A94
F0071A84: a0100008                 mov     %o0, %l0
F0071A88: d0062108                 ld      [%i0+0x108], %o0
F0071A8C: a0228008                 sub     %o2, %o0, %l0
F0071A90: d4262108                 st      %o2, [%i0+0x108]
F0071A94: d2062104                 ld      [%i0+0x104], %o1
F0071A98: d00620e8                 ld      [%i0+0xE8], %o0
F0071A9C: 80a24008                 cmp     %o1, %o0
F0071AA0: 02800007                 be      loc_F0071ABC
F0071AA4: d40620e0                 ld      [%i0+0xE0], %o2
F0071AA8: 900620e0                 add     %i0, 0xE0, %o0
F0071AAC: 400017fb                 call    _timer_delta
F0071AB0: 92062100                 add     %i0, 0x100, %o1
F0071AB4: 10800006                 ba      loc_F0071ACC
F0071AB8: a0040008                 add     %l0, %o0, %l0
F0071ABC: d0062100                 ld      [%i0+0x100], %o0
F0071AC0: 90228008                 sub     %o2, %o0, %o0
F0071AC4: a0040008                 add     %l0, %o0, %l0
F0071AC8: d4262100                 st      %o2, [%i0+0x100]
F0071ACC: d0062110                 ld      [%i0+0x110], %o0
F0071AD0: d2062190                 ld      [%i0+0x190], %o1
F0071AD4: 90020010                 add     %o0, %l0, %o0
F0071AD8: d0262110                 st      %o0, [%i0+0x110]
F0071ADC: d2026178                 ld      [%o1+0x178], %o1
F0071AE0: 7ffe5288                 call    _umul
F0071AE4: 90100010                 mov     %l0, %o0
F0071AE8: d2062114                 ld      [%i0+0x114], %o1
F0071AEC: 92024008                 add     %o1, %o0, %o1
F0071AF0: 80a4601e                 cmp     %l1, 0x1E
F0071AF4: 08800005                 bleu    loc_F0071B08
F0071AF8: d2262114                 st      %o1, [%i0+0x114]
F0071AFC: c0262068                 clr     [%i0+0x68]
F0071B00: 1080002d                 ba      loc_F0071BB4
F0071B04: c026206c                 clr     [%i0+0x6C]
F0071B08: d0062068                 ld      [%i0+0x68], %o0
F0071B0C: d4062110                 ld      [%i0+0x110], %o2
F0071B10: 972c6003                 sll     %l1, 3, %o3
F0071B14: d206206c                 ld      [%i0+0x6C], %o1
F0071B18: 9002000a                 add     %o0, %o2, %o0
F0071B1C: d0262068                 st      %o0, [%i0+0x68]
F0071B20: 113c04419a122038         set     _wait_shift, %o5
F0071B28: d4062114                 ld      [%i0+0x114], %o2
F0071B2C: 9802c00d                 add     %o3, %o5, %o4
F0071B30: 9202400a                 add     %o1, %o2, %o1
F0071B34: d226206c                 st      %o1, [%i0+0x6C]
F0071B38: d4032004                 ld      [%o4+4], %o2
F0071B3C: 80a2a000                 cmp     %o2, 0
F0071B40: 0480000f                 ble     loc_F0071B7C
F0071B44: d0062068                 ld      [%i0+0x68], %o0
F0071B48: d202c00d                 ld      [%o3+%o5], %o1
F0071B4C: 93320009                 srl     %o0, %o1, %o1
F0071B50: 9132000a                 srl     %o0, %o2, %o0
F0071B54: 92024008                 add     %o1, %o0, %o1
F0071B58: d406206c                 ld      [%i0+0x6C], %o2
F0071B5C: d2262068                 st      %o1, [%i0+0x68]
F0071B60: d002c00d                 ld      [%o3+%o5], %o0
F0071B64: d2032004                 ld      [%o4+4], %o1
F0071B68: 91328008                 srl     %o2, %o0, %o0
F0071B6C: 95328009                 srl     %o2, %o1, %o2
F0071B70: 9002000a                 add     %o0, %o2, %o0
F0071B74: 10800010                 ba      loc_F0071BB4
F0071B78: d026206c                 st      %o0, [%i0+0x6C]
F0071B7C: d202c00d                 ld      [%o3+%o5], %o1
F0071B80: 9420000a                 neg     %o2
F0071B84: 93320009                 srl     %o0, %o1, %o1
F0071B88: 9132000a                 srl     %o0, %o2, %o0
F0071B8C: 92224008                 sub     %o1, %o0, %o1
F0071B90: d406206c                 ld      [%i0+0x6C], %o2
F0071B94: d2262068                 st      %o1, [%i0+0x68]
F0071B98: d202c00d                 ld      [%o3+%o5], %o1
F0071B9C: d0032004                 ld      [%o4+4], %o0
F0071BA0: 93328009                 srl     %o2, %o1, %o1
F0071BA4: 90200008                 neg     %o0
F0071BA8: 95328008                 srl     %o2, %o0, %o2
F0071BAC: 9222400a                 sub     %o1, %o2, %o1
F0071BB0: d226206c                 st      %o1, [%i0+0x6C]
F0071BB4: c0262110                 clr     [%i0+0x110]
F0071BB8: d0062060                 ld      [%i0+0x60], %o0
F0071BBC: 80a22002                 cmp     %o0, 2
F0071BC0: 0280000d                 be      locret_F0071BF4
F0071BC4: c0262114                 clr     [%i0+0x114]
F0071BC8: d0062064                 ld      [%i0+0x64], %o0
F0071BCC: 80a22000                 cmp     %o0, 0
F0071BD0: 16800009                 bge     locret_F0071BF4
F0071BD4: 01000000                 nop
F0071BD8: d006206c                 ld      [%i0+0x6C], %o0
F0071BDC: d2062050                 ld      [%i0+0x50], %o1
F0071BE0: 91322019                 srl     %o0, 25, %o0
F0071BE4: 92a24008                 subcc   %o1, %o0, %o1
F0071BE8: 2c800002                 bneg,a  loc_F0071BF0
F0071BEC: 92102000                 mov     0, %o1
F0071BF0: d2262058                 st      %o1, [%i0+0x58]
F0071BF4: 81c7e008                 ret
F0071BF8: 81e80000                 restore
