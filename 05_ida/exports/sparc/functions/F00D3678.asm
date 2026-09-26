F00D3678: 9de3bf80                 save    %sp, -0x80, %sp
F00D367C: f627bfe0                 st      %i3, [%fp+var_20]
F00D3680: f427bfe4                 st      %i2, [%fp+var_1C]
F00D3684: f827bfe8                 st      %i4, [%fp+var_18]
F00D3688: 90100018                 mov     %i0, %o0! id
F00D368C: 133c0505                 sethi   %hi(paThreadopcommon), %o1
F00D3690: d20262d4                 ld      [%o1+%lo(paThreadopcommon)], %o1! SEL
F00D3694: 94102002                 mov     2, %o2
F00D3698: 9607bfe0                 add     %fp, var_20, %o3
F00D369C: 40007875                 call    _objc_msgSend
F00D36A0: 98102000                 mov     0, %o4
F00D36A4: 81c7e008                 ret
F00D36A8: 91e80008                 restore %g0, %o0, %o0
