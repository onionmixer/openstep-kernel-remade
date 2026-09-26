F006E88C: 9de3bf98                 save    %sp, -0x68, %sp
F006E890: 213c0440                 sethi   %hi(dword_F0110060), %l0
F006E894: d0042060                 ld      [%l0+%lo(dword_F0110060)], %o0
F006E898: 80a22000                 cmp     %o0, 0
F006E89C: 1280000e                 bne     locret_F006E8D4
F006E8A0: 01000000                 nop
F006E8A4: 40009802                 call    _PMConnect
F006E8A8: 01000000                 nop
F006E8AC: 80a22000                 cmp     %o0, 0
F006E8B0: 12800006                 bne     loc_F006E8C8
F006E8B4: 113c04be                 sethi   -0xFED0800, %o0
F006E8B8: 90102000                 mov     0, %o0
F006E8BC: 7fffffdc                 call    _power_callout
F006E8C0: 92102000                 mov     0, %o1
F006E8C4: 113c04be                 sethi   -0xFED0800, %o0
F006E8C8: c0222128                 clr     [%o0+0x128]
F006E8CC: 90102001                 mov     1, %o0
F006E8D0: d0242060                 st      %o0, [%l0+0x60]
F006E8D4: 81c7e008                 ret
F006E8D8: 81e80000                 restore
