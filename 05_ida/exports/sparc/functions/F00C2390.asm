F00C2390: 9de3bf98                 save    %sp, -0x68, %sp
F00C2394: 153c0484                 sethi   %hi(dword_F0121134), %o2
F00C2398: d002a134                 ld      [%o2+%lo(dword_F0121134)], %o0
F00C239C: 80a22000                 cmp     %o0, 0
F00C23A0: 02800007                 be      locret_F00C23BC
F00C23A4: 92100019                 mov     %i1, %o1
F00C23A8: c022a134                 clr     [%o2+%lo(dword_F0121134)]
F00C23AC: 90100018                 mov     %i0, %o0
F00C23B0: 150008c8                 sethi   0x232000, %o2
F00C23B4: 7fff324e                 call    _IOSendInterrupt
F00C23B8: 9412a325                 bset    0x325, %o2
F00C23BC: 81c7e008                 ret
F00C23C0: 81e80000                 restore
