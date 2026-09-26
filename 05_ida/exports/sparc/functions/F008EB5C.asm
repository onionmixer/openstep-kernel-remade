F008EB5C: 9de3bf98                 save    %sp, -0x68, %sp
F008EB60: 7ffff77f                 call    _KernLockAcquire
F008EB64: d0062030                 ld      [%i0+0x30], %o0
F008EB68: d4062060                 ld      [%i0+0x60], %o2
F008EB6C: 11300000                 sethi   -0x40000000, %o0
F008EB70: 808a8008                 btst    %o0, %o2
F008EB74: 02800008                 be      loc_F008EB94
F008EB78: 01000000                 nop
F008EB7C: d0062030                 ld      [%i0+0x30], %o0
F008EB80: 1308000092128009         set     0x20000000, %o1
F008EB88: 7ffff786                 call    _KernLockRelease
F008EB8C: d2262060                 st      %o1, [%i0+0x60]
F008EB90: 3080000e                 ba,a    locret_F008EBC8
F008EB94: 7ffff783                 call    _KernLockRelease
F008EB98: d0062030                 ld      [%i0+0x30], %o0
F008EB9C: 7fff2ab5                 call    _ipc_object_release
F008EBA0: d006202c                 ld      [%i0+0x2C], %o0
F008EBA4: 7fff2ab3                 call    _ipc_object_release
F008EBA8: d006202c                 ld      [%i0+0x2C], %o0
F008EBAC: d0062030                 ld      [%i0+0x30], %o0! id
F008EBB0: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008EBB4: 40018b2f                 call    _objc_msgSend
F008EBB8: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F008EBBC: 90100018                 mov     %i0, %o0
F008EBC0: 7fff6578                 call    _kfree
F008EBC4: 92102068                 mov     0x68, %o1 ! 'h'
F008EBC8: 81c7e008                 ret
F008EBCC: 81e80000                 restore
