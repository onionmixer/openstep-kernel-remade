F00B9BEC: 9de3bf98                 save    %sp, -0x68, %sp
F00B9BF0: b00e201f                 and     %i0, 0x1F, %i0
F00B9BF4: 912e2004                 sll     %i0, 4, %o0
F00B9BF8: 90020018                 add     %o0, %i0, %o0
F00B9BFC: 912a2003                 sll     %o0, 3, %o0
F00B9C00: 133c04fb92126260         set     _zs_tty, %o1
F00B9C08: 90020009                 add     %o0, %o1, %o0
F00B9C0C: d44a2047                 ldsb    [%o0+0x47], %o2
F00B9C10: 932aa001                 sll     %o2, 1, %o1
F00B9C14: 9202400a                 add     %o1, %o2, %o1
F00B9C18: 932a6004                 sll     %o1, 4, %o1
F00B9C1C: 153c042e9412a0cc         set     _linesw, %o2
F00B9C24: 9202400a                 add     %o1, %o2, %o1
F00B9C28: d402600c                 ld      [%o1+0xC], %o2
F00B9C2C: 9fc28000                 call    %o2
F00B9C30: 92100019                 mov     %i1, %o1
F00B9C34: 81c7e008                 ret
F00B9C38: 81e80000                 restore
