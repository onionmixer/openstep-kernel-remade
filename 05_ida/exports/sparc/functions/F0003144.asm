F0003144: 4000076e                 call    _flush_user_windows
F0003148: 01000000                 nop
F000314C: 40000760                 call    _reset_windows
F0003150: 01000000                 nop
F0003154: 2f3c0428ae15e024         set     _active_pcb, %l7
F000315C: ee05c000                 ld      [%l7], %l7
F0003160: e005e234                 ld      [%l7+0x234], %l0
F0003164: dc05e2a0                 ld      [%l7+0x2A0], %sp
F0003168: 108000ce                 ba      sys_rtt
F000316C: e023a05c                 st      %l0, [%sp+arg_5C]
