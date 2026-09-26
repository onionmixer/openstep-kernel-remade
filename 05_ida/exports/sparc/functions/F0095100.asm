F0095100: 9b480000                 rdhpr   %hpstate, %o5
F0095104: 19000004                 sethi   0x1000, %o4
F0095108: 808b000d                 btst    %o5, %o4
F009510C: 02800008                 be      locret_F009512C
F0095110: 1b3c04f6                 sethi   %hi(_fptraprp), %o5
F0095114: d60361d0                 ld      [%o5+%lo(_fptraprp)], %o3
F0095118: d02361d0                 st      %o0, [%o5+%lo(_fptraprp)]
F009511C: 193c044a                 sethi   %hi(dword_F01128CC), %o4
F0095120: c12b20cc                 st      %fsr, [%o4+%lo(dword_F01128CC)]
F0095124: 81c3e008                 retl
F0095128: d62361d0                 st      %o3, [%o5+%lo(_fptraprp)]
F009512C: 81c3e008                 retl
