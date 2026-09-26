F004DA80: 9de3bf98                 save    %sp, -0x68, %sp
F004DA84: d206200c                 ld      [%i0+0xC], %o1
F004DA88: 80a26000                 cmp     %o1, 0
F004DA8C: 1680000c                 bge     locret_F004DABC
F004DA90: 11200000                 sethi   0x80000000, %o0
F004DA94: 902a4008                 andn    %o1, %o0, %o0
F004DA98: d026200c                 st      %o0, [%i0+0xC]
F004DA9C: 133c04eb                 sethi   %hi(dword_F013AD9C), %o1
F004DAA0: d002619c                 ld      [%o1+%lo(dword_F013AD9C)], %o0
F004DAA4: 80a22000                 cmp     %o0, 0
F004DAA8: 02800005                 be      locret_F004DABC
F004DAAC: 9212619c                 bset    %lo(dword_F013AD9C), %o1
F004DAB0: d2027ffc                 ld      [%o1-4], %o1
F004DAB4: 9fc24000                 call    %o1
F004DAB8: 90100018                 mov     %i0, %o0
F004DABC: 81c7e008                 ret
F004DAC0: 81e80000                 restore
