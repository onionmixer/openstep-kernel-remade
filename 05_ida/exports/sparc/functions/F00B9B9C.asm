F00B9B9C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9BA0: b00e201f                 and     %i0, 0x1F, %i0
F00B9BA4: 912e2004                 sll     %i0, 4, %o0
F00B9BA8: 90020018                 add     %o0, %i0, %o0
F00B9BAC: 912a2003                 sll     %o0, 3, %o0
F00B9BB0: 133c04fb92126260         set     _zs_tty, %o1
F00B9BB8: 90020009                 add     %o0, %o1, %o0
F00B9BBC: d44a2047                 ldsb    [%o0+0x47], %o2
F00B9BC0: 932aa001                 sll     %o2, 1, %o1
F00B9BC4: 9202400a                 add     %o1, %o2, %o1
F00B9BC8: 932a6004                 sll     %o1, 4, %o1
F00B9BCC: 153c042e9412a0cc         set     _linesw, %o2
F00B9BD4: 9202400a                 add     %o1, %o2, %o1
F00B9BD8: d4026008                 ld      [%o1+8], %o2
F00B9BDC: 9fc28000                 call    %o2
F00B9BE0: 92100019                 mov     %i1, %o1
F00B9BE4: 81c7e008                 ret
F00B9BE8: 81e80000                 restore
