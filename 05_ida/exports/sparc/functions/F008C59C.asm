F008C59C: 9de3bf90                 save    %sp, -0x70, %sp
F008C5A0: 113c04f6                 sethi   %hi(_IOTask_kern), %o0
F008C5A4: d00221b8                 ld      [%o0+%lo(_IOTask_kern)], %o0
F008C5A8: 92100018                 mov     %i0, %o1
F008C5AC: 94102006                 mov     6, %o2
F008C5B0: 96102000                 mov     0, %o3
F008C5B4: 7fff6e15                 call    _object_copyin
F008C5B8: 9807bff4                 add     %fp, var_C, %o4
F008C5BC: 80a22000                 cmp     %o0, 0
F008C5C0: 02800003                 be      locret_F008C5CC
F008C5C4: b0102000                 mov     0, %i0
F008C5C8: f007bff4                 ld      [%fp+var_C], %i0
F008C5CC: 81c7e008                 ret
F008C5D0: 81e80000                 restore
