F006CCCC: 9de3bf58                 save    %sp, -0xA8, %sp
F006CCD0: 90100018                 mov     %i0, %o0
F006CCD4: d402201c                 ld      [%o0+0x1C], %o2
F006CCD8: 133c04cf                 sethi   %hi(_active_u), %o1
F006CCDC: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F006CCE0: d602a014                 ld      [%o2+0x14], %o3
F006CCE4: d402601c                 ld      [%o1+0x1C], %o2
F006CCE8: 9fc2c000                 call    %o3
F006CCEC: 9207bfb8                 add     %fp, var_48, %o1
F006CCF0: f007bfd0                 ld      [%fp+var_30], %i0
F006CCF4: 81c7e008                 ret
F006CCF8: 81e80000                 restore
