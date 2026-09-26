F003EC78: 9de3bf98                 save    %sp, -0x68, %sp
F003EC7C: 213c04bd                 sethi   %hi(dword_F012F4F0), %l0
F003EC80: d00420f0                 ld      [%l0+%lo(dword_F012F4F0)], %o0
F003EC84: 80a22000                 cmp     %o0, 0
F003EC88: 12800006                 bne     locret_F003ECA0
F003EC8C: 90102001                 mov     1, %o0
F003EC90: d02420f0                 st      %o0, [%l0+%lo(dword_F012F4F0)]
F003EC94: 7ffffa11                 call    _rflush
F003EC98: 90100018                 mov     %i0, %o0
F003EC9C: c02420f0                 clr     [%l0+%lo(dword_F012F4F0)]
F003ECA0: 81c7e008                 ret
F003ECA4: 91e82000                 restore %g0, 0, %o0
