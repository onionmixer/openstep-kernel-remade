F00A4A38: 9de3bf98                 save    %sp, -0x68, %sp
F00A4A3C: a0100018                 mov     %i0, %l0
F00A4A40: b2040019                 add     %l0, %i1, %i1
F00A4A44: 80a40019                 cmp     %l0, %i1
F00A4A48: 1a800011                 bcc     locret_F00A4A8C
F00A4A4C: 23000004                 sethi   0x1000, %l1
F00A4A50: 90100018                 mov     %i0, %o0
F00A4A54: 7fffc2ee                 call    _mmu_probe
F00A4A58: 92102000                 mov     0, %o1
F00A4A5C: 80a22000                 cmp     %o0, 0
F00A4A60: 22800008                 be,a    loc_F00A4A80
F00A4A64: a0040011                 add     %l0, %l1, %l0
F00A4A68: 808a2003                 btst    3, %o0
F00A4A6C: 22800005                 be,a    loc_F00A4A80
F00A4A70: a0040011                 add     %l0, %l1, %l0
F00A4A74: 7fffc3e8                 call    _pac_pageflush
F00A4A78: 91322008                 srl     %o0, 8, %o0
F00A4A7C: a0040011                 add     %l0, %l1, %l0
F00A4A80: 80a40019                 cmp     %l0, %i1
F00A4A84: 0abffff4                 bcs     loc_F00A4A54
F00A4A88: 90100018                 mov     %i0, %o0
F00A4A8C: 81c7e008                 ret
F00A4A90: 81e80000                 restore
