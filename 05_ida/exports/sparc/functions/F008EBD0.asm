F008EBD0: 9de3bf98                 save    %sp, -0x68, %sp
F008EBD4: 7fff2a97                 call    _ipc_object_reference
F008EBD8: d006202c                 ld      [%i0+0x2C], %o0
F008EBDC: 7ffff760                 call    _KernLockAcquire
F008EBE0: d0062030                 ld      [%i0+0x30], %o0
F008EBE4: 13200000                 sethi   0x80000000, %o1
F008EBE8: d0062060                 ld      [%i0+0x60], %o0
F008EBEC: a0100018                 mov     %i0, %l0
F008EBF0: 922a0009                 andn    %o0, %o1, %o1
F008EBF4: 11080000                 sethi   0x20000000, %o0
F008EBF8: 808a4008                 btst    %o0, %o1
F008EBFC: 02800007                 be      loc_F008EC18
F008EC00: d2262060                 st      %o1, [%i0+0x60]
F008EC04: 7ffff767                 call    _KernLockRelease
F008EC08: d0062030                 ld      [%i0+0x30], %o0
F008EC0C: 7fffffd4                 call    sub_F008EB5C
F008EC10: 90100018                 mov     %i0, %o0
F008EC14: 30800003                 ba,a    locret_F008EC20
F008EC18: 7ffff762                 call    _KernLockRelease
F008EC1C: d0042030                 ld      [%l0+0x30], %o0
F008EC20: 81c7e008                 ret
F008EC24: 81e80000                 restore
