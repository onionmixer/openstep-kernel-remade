F00C0EAC: 9de3bf98                 save    %sp, -0x68, %sp
F00C0EB0: d0066040                 ld      [%i1+0x40], %o0
F00C0EB4: 808a2004                 btst    4, %o0
F00C0EB8: 0280000d                 be      locret_F00C0EEC
F00C0EBC: 912e2018                 sll     %i0, 24, %o0
F00C0EC0: d44e6047                 ldsb    [%i1+0x47], %o2
F00C0EC4: 932aa001                 sll     %o2, 1, %o1
F00C0EC8: 9202400a                 add     %o1, %o2, %o1
F00C0ECC: 932a6004                 sll     %o1, 4, %o1
F00C0ED0: 153c042e9412a0cc         set     _linesw, %o2
F00C0ED8: 9202400a                 add     %o1, %o2, %o1
F00C0EDC: d4026014                 ld      [%o1+0x14], %o2
F00C0EE0: 913a2018                 sra     %o0, 24, %o0
F00C0EE4: 9fc28000                 call    %o2
F00C0EE8: 92100019                 mov     %i1, %o1
F00C0EEC: 81c7e008                 ret
F00C0EF0: 81e80000                 restore
