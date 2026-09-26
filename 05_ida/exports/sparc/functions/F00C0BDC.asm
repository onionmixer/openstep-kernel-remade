F00C0BDC: 9de3bf88                 save    %sp, -0x78, %sp
F00C0BE0: 073c04cb                 sethi   %hi(dword_F0132FF0), %g3
F00C0BE4: f600e3f0                 ld      [%g3+%lo(dword_F0132FF0)], %i3
F00C0BE8: b8100019                 mov     %i1, %i4
F00C0BEC: ba10001a                 mov     %i2, %i5
F00C0BF0: 80a6e005                 cmp     %i3, 5
F00C0BF4: 0280000d                 be      locret_F00C0C28
F00C0BF8: 8406e001                 add     %i3, 1, %g2
F00C0BFC: f027bff0                 st      %i0, [%fp+var_10]
F00C0C00: c02fbff4                 clrb    [%fp+var_10+4]
F00C0C04: f83fbfe8                 std     %i4, [%fp+var_18]
F00C0C08: c420e3f0                 st      %g2, [%g3+%lo(dword_F0132FF0)]
F00C0C0C: 073c04cb8610e3a0         set     qword_F0132FA0, %g3
F00C0C14: 852ee004                 sll     %i3, 4, %g2
F00C0C18: f8388003                 std     %i4, [%g2+%g3]
F00C0C1C: f01fbff0                 ldd     [%fp+var_10], %i0
F00C0C20: 84008003                 add     %g2, %g3, %g2
F00C0C24: f038a008                 std     %i0, [%g2+8]
F00C0C28: 81c7e008                 ret
F00C0C2C: 81e80000                 restore
