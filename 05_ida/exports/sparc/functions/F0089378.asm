F0089378: 9de3bf98                 save    %sp, -0x68, %sp
F008937C: 7ffffec3                 call    _vm_page_remove
F0089380: 90100018                 mov     %i0, %o0
F0089384: d206201c                 ld      [%i0+0x1C], %o1
F0089388: 11000004                 sethi   0x1000, %o0
F008938C: 808a4008                 btst    %o0, %o1
F0089390: 12800004                 bne     locret_F00893A0
F0089394: 01000000                 nop
F0089398: 40000004                 call    _vm_page_addfree
F008939C: 90100018                 mov     %i0, %o0
F00893A0: 81c7e008                 ret
F00893A4: 81e80000                 restore
