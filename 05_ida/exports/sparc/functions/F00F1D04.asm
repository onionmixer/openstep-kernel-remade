F00F1D04: 9de3bf70                 save    %sp, -0x90, %sp
F00F1D08: a0100018                 mov     %i0, %l0
F00F1D0C: e027bfd8                 st      %l0, [%fp+var_28]
F00F1D10: 253c04bc                 sethi   %hi(dword_F012F12C), %l2
F00F1D14: a207bfd0                 add     %fp, var_30, %l1
F00F1D18: d004a12c                 ld      [%l2+%lo(dword_F012F12C)], %o0! table
F00F1D1C: 7fffee68                 call    _NXHashGet
F00F1D20: 92100011                 mov     %l1, %o1
F00F1D24: b0920000                 orcc    %o0, %g0, %i0
F00F1D28: 1280000b                 bne     locret_F00F1D54
F00F1D2C: 113c04bc                 sethi   %hi(off_F012F148), %o0
F00F1D30: d2022148                 ld      [%o0+%lo(off_F012F148)], %o1! data
F00F1D34: 9fc24000                 call    %o1
F00F1D38: 90100010                 mov     %l0, %o0
F00F1D3C: 80a22000                 cmp     %o0, 0
F00F1D40: 02800005                 be      locret_F00F1D54
F00F1D44: d004a12c                 ld      [%l2+%lo(dword_F012F12C)], %o0! table
F00F1D48: 7fffee5d                 call    _NXHashGet
F00F1D4C: 92100011                 mov     %l1, %o1
F00F1D50: b0100008                 mov     %o0, %i0
F00F1D54: 81c7e008                 ret
F00F1D58: 81e80000                 restore
