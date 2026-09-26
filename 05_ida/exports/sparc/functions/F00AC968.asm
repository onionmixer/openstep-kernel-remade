F00AC968: 9de3bf90                 save    %sp, -0x70, %sp
F00AC96C: 90100018                 mov     %i0, %o0
F00AC970: f2222020                 st      %i1, [%o0+0x20]
F00AC974: 133c0254921262d8         set     __fp_read_pfreg, %o1
F00AC97C: d2222014                 st      %o1, [%o0+0x14]
F00AC980: 133c0254921262ec         set     __fp_write_pfreg, %o1
F00AC988: d2222018                 st      %o1, [%o0+0x18]
F00AC98C: f627bff4                 st      %i3, [%fp+var_C]
F00AC990: 9207bff4                 add     %fp, var_C, %o1
F00AC994: 7ffffe61                 call    sub_F00AC318
F00AC998: 9410001a                 mov     %i2, %o2
F00AC99C: 81c7e008                 ret
F00AC9A0: 91e80008                 restore %g0, %o0, %o0
