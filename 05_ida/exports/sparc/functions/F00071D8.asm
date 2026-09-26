F00071D8: 80a2a00f                 cmp     %o2, 0xF
F00071DC: 053c001c8410a220         set     loc_F0007220, %g2
F00071E4: 0480000a                 ble     loc_F000720C
F00071E8: 872aa002                 sll     %o2, 2, %g3
F00071EC: 82100008                 mov     %o0, %g1
F00071F0: 81e80000                 restore
F00071F4: 81c08003                 jmp     %g2+%g3
F00071F8: 10800002                 ba      loc_F0007200
F0007200: 81e00000                 save
F0007204: 81c3e008                 retl
F0007208: 01000000                 nop
F000720C: 2f3c0429ae15e3c0         set     unk_F010A7C0, %l7
F0007214: 81c08003                 jmp     %g2+%g3
F0007218: 81c3e008                 retl
