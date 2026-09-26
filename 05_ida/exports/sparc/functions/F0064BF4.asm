F0064BF4: 9de3bf98                 save    %sp, -0x68, %sp
F0064BF8: 80a62000                 cmp     %i0, 0
F0064BFC: 12800004                 bne     loc_F0064C0C
F0064C00: a2102000                 mov     0, %l1
F0064C04: 1080003c                 ba      locret_F0064CF4
F0064C08: b0102004                 mov     4, %i0
F0064C0C: a0102000                 mov     0, %l0
F0064C10: 113c04d194122360         set     _machine_slot, %o2
F0064C18: 92102000                 mov     0, %o1
F0064C1C: d002400a                 ld      [%o1+%o2], %o0
F0064C20: 80a22000                 cmp     %o0, 0
F0064C24: 32800002                 bne,a   loc_F0064C2C
F0064C28: a2046001                 inc     %l1
F0064C2C: a0042001                 inc     %l0
F0064C30: 80a42000                 cmp     %l0, 0
F0064C34: 04bffffa                 ble     loc_F0064C1C
F0064C38: 92026020                 inc     0x20, %o1 ! ' '
F0064C3C: 80a46000                 cmp     %l1, 0
F0064C40: 12800004                 bne     loc_F0064C50
F0064C44: 113c043e                 sethi   %hi(aHostProcessors), %o0! "host_processors"
F0064C48: 7ffec14a                 call    _panic
F0064C4C: 901220f8                 bset    %lo(aHostProcessors), %o0! "host_processors"
F0064C50: 40000d08                 call    _kalloc
F0064C54: 912c6002                 sll     %l1, 2, %o0
F0064C58: 98920000                 orcc    %o0, %g0, %o4
F0064C5C: 12800004                 bne     loc_F0064C6C
F0064C60: 9410000c                 mov     %o4, %o2
F0064C64: 10800024                 ba      locret_F0064CF4
F0064C68: b0102006                 mov     6, %i0
F0064C6C: a0102000                 mov     0, %l0
F0064C70: 113c04d184122360         set     _machine_slot, %g2
F0064C78: 113c04d29a1221b0         set     _processor_ptr, %o5
F0064C80: 96102000                 mov     0, %o3
F0064C84: 92102000                 mov     0, %o1
F0064C88: d0024002                 ld      [%o1+%g2], %o0
F0064C8C: 80a22000                 cmp     %o0, 0
F0064C90: 22800006                 be,a    loc_F0064CA8
F0064C94: 9602e004                 inc     4, %o3
F0064C98: d002c00d                 ld      [%o3+%o5], %o0
F0064C9C: d0228000                 st      %o0, [%o2]
F0064CA0: 9402a004                 inc     4, %o2
F0064CA4: 9602e004                 inc     4, %o3
F0064CA8: a0042001                 inc     %l0
F0064CAC: 80a42000                 cmp     %l0, 0
F0064CB0: 04bffff6                 ble     loc_F0064C88
F0064CB4: 92026020                 inc     0x20, %o1 ! ' '
F0064CB8: e2268000                 st      %l1, [%i2]
F0064CBC: d8264000                 st      %o4, [%i1]
F0064CC0: a0102000                 mov     0, %l0
F0064CC4: 80a40011                 cmp     %l0, %l1
F0064CC8: 1a80000a                 bcc     loc_F0064CF0
F0064CCC: 9410000c                 mov     %o4, %o2
F0064CD0: b010000a                 mov     %o2, %i0
F0064CD4: d0060000                 ld      [%i0], %o0
F0064CD8: 40000208                 call    _convert_processor_to_port
F0064CDC: a0042001                 inc     %l0
F0064CE0: d0260000                 st      %o0, [%i0]
F0064CE4: 80a40011                 cmp     %l0, %l1
F0064CE8: 0abffffb                 bcs     loc_F0064CD4
F0064CEC: b0062004                 inc     4, %i0
F0064CF0: b0102000                 mov     0, %i0
F0064CF4: 81c7e008                 ret
F0064CF8: 81e80000                 restore
