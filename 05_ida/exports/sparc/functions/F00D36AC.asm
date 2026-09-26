F00D36AC: 9de3bf80                 save    %sp, -0x80, %sp
F00D36B0: f627bfe0                 st      %i3, [%fp+var_20]
F00D36B4: f427bfe4                 st      %i2, [%fp+var_1C]
F00D36B8: f827bfe8                 st      %i4, [%fp+var_18]
F00D36BC: 90100018                 mov     %i0, %o0! id
F00D36C0: 133c0505                 sethi   %hi(paThreadopcommon), %o1
F00D36C4: d20262d4                 ld      [%o1+%lo(paThreadopcommon)], %o1! SEL
F00D36C8: 94102002                 mov     2, %o2
F00D36CC: 9607bfe0                 add     %fp, var_20, %o3
F00D36D0: 40007868                 call    _objc_msgSend
F00D36D4: 98102001                 mov     1, %o4
F00D36D8: 81c7e008                 ret
F00D36DC: 81e80000                 restore
