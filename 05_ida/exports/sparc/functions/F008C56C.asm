F008C56C: 9de3bf90                 save    %sp, -0x70, %sp
F008C570: 7fff6e49                 call    _port_reference
F008C574: 90100018                 mov     %i0, %o0
F008C578: 113c04f6                 sethi   %hi(_IOTask_kern), %o0
F008C57C: 92100018                 mov     %i0, %o1
F008C580: 94102006                 mov     6, %o2
F008C584: d00221b8                 ld      [%o0+%lo(_IOTask_kern)], %o0
F008C588: 7fff6e2b                 call    _object_copyout
F008C58C: 9607bff4                 add     %fp, var_C, %o3
F008C590: f007bff4                 ld      [%fp+var_C], %i0
F008C594: 81c7e008                 ret
F008C598: 81e80000                 restore
