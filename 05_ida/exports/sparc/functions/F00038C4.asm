F00038C4: 818c2020                 saved
F00038C8: 01000000                 nop
F00038CC: 01000000                 nop
F00038D0: 01000000                 nop
F00038D4: 0b3c04288a116024         set     _active_pcb, %g5
F00038DC: ca014000                 ld      [%g5], %g5
F00038E0: 40029420                 call    _syscall
F00038E4: 90016234                 add     %g5, 0x234, %o0
F00038E8: 30bffeee                 ba,a    sys_rtt
