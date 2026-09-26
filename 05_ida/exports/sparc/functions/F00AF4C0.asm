F00AF4C0: 9de3bf98                 save    %sp, -0x68, %sp
F00AF4C4: 313c04c5                 sethi   %hi(dword_F0131688), %i0
F00AF4C8: d0062288                 ld      [%i0+%lo(dword_F0131688)], %o0
F00AF4CC: 80a22000                 cmp     %o0, 0
F00AF4D0: 12800005                 bne     locret_F00AF4E4
F00AF4D4: 01000000                 nop
F00AF4D8: 7fffffe8                 call    _prom_nextnode
F00AF4DC: 90102000                 mov     0, %o0
F00AF4E0: d0262288                 st      %o0, [%i0+%lo(dword_F0131688)]
F00AF4E4: 81c7e008                 ret
F00AF4E8: 91e80008                 restore %g0, %o0, %o0
