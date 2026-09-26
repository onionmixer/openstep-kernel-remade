F004629C: 9de3bf98                 save    %sp, -0x68, %sp
F00462A0: b4100018                 mov     %i0, %i2
F00462A4: c406a010                 ld      [%i2+0x10], %g2
F00462A8: f006a00c                 ld      [%i2+0xC], %i0
F00462AC: c606a014                 ld      [%i2+0x14], %g3
F00462B0: 84008019                 add     %g2, %i1, %g2
F00462B4: b0060003                 add     %i0, %g3, %i0
F00462B8: 80a08018                 cmp     %g2, %i0
F00462BC: 34800006                 bg,a    locret_F00462D4
F00462C0: b0102000                 mov     0, %i0
F00462C4: c426a00c                 st      %g2, [%i2+0xC]
F00462C8: 84260002                 sub     %i0, %g2, %g2
F00462CC: c426a014                 st      %g2, [%i2+0x14]
F00462D0: b0102001                 mov     1, %i0
F00462D4: 81c7e008                 ret
F00462D8: 81e80000                 restore
