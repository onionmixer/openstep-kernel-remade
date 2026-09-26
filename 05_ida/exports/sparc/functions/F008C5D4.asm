F008C5D4: 9de3bf90                 save    %sp, -0x70, %sp
F008C5D8: 113c04d0                 sethi   %hi(_active_threads), %o0
F008C5DC: 92100018                 mov     %i0, %o1
F008C5E0: 94102006                 mov     6, %o2
F008C5E4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008C5E8: 96102000                 mov     0, %o3
F008C5EC: d002200c                 ld      [%o0+0xC], %o0
F008C5F0: 7fff6e06                 call    _object_copyin
F008C5F4: 9807bff4                 add     %fp, var_C, %o4
F008C5F8: 80a22000                 cmp     %o0, 0
F008C5FC: 02800003                 be      locret_F008C608
F008C600: b0102000                 mov     0, %i0
F008C604: f007bff4                 ld      [%fp+var_C], %i0
F008C608: 81c7e008                 ret
F008C60C: 81e80000                 restore
