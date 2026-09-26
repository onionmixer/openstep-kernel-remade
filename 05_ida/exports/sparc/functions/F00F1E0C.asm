F00F1E0C: 9de3bf98                 save    %sp, -0x68, %sp
F00F1E10: 113c04bc                 sethi   %hi(dword_F012F12C), %o0
F00F1E14: d002212c                 ld      [%o0+%lo(dword_F012F12C)], %o0! table
F00F1E18: 7fffef61                 call    _NXHashRemove
F00F1E1C: 92100018                 mov     %i0, %o1
F00F1E20: 81c7e008                 ret
F00F1E24: 81e80000                 restore
