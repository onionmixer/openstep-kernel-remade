F006DB94: 9de3bf98                 save    %sp, -0x68, %sp
F006DB98: 7ffffb83                 call    _mfs_uncache
F006DB9C: 90100018                 mov     %i0, %o0
F006DBA0: 113c04d2                 sethi   %hi(_vm_info_zone), %o0
F006DBA4: d0022250                 ld      [%o0+%lo(_vm_info_zone)], %o0
F006DBA8: 40002d8a                 call    _zfree
F006DBAC: d2060000                 ld      [%i0], %o1
F006DBB0: 81c7e008                 ret
F006DBB4: 81e80000                 restore
