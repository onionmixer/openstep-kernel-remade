F00038EC: 818c2020                 saved
F00038F0: 01000000                 nop
F00038F4: 01000000                 nop
F00038F8: 01000000                 nop
F00038FC: 0b3c04288a116024         set     _active_pcb, %g5
F0003904: ca014000                 ld      [%g5], %g5
F0003908: 40029542                 call    _machcall
F000390C: 90016234                 add     %g5, 0x234, %o0
F0003910: 30bffee4                 ba,a    sys_rtt
