F00F1D5C: 9de3bf70                 save    %sp, -0x90, %sp
F00F1D60: f027bfd8                 st      %i0, [%fp+var_28]
F00F1D64: 113c04bc                 sethi   %hi(dword_F012F12C), %o0
F00F1D68: d002212c                 ld      [%o0+%lo(dword_F012F12C)], %o0! table
F00F1D6C: 7fffee54                 call    _NXHashGet
F00F1D70: 9207bfd0                 add     %fp, var_30, %o1
F00F1D74: 81c7e008                 ret
F00F1D78: 91e80008                 restore %g0, %o0, %o0
