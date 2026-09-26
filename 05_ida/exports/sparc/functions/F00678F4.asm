F00678F4: 9de3bf98                 save    %sp, -0x68, %sp
F00678F8: 80a62000                 cmp     %i0, 0
F00678FC: 0280001c                 be      locret_F006796C
F0067900: a0102000                 mov     0, %l0
F0067904: 80a63fff                 cmp     %i0, -1
F0067908: 02800019                 be      locret_F006796C
F006790C: 01000000                 nop
F0067910: d0060000                 ld      [%i0], %o0
F0067914: 80a22000                 cmp     %o0, 0
F0067918: 12bffffe                 bne     loc_F0067910
F006791C: 01000000                 nop
F0067920: 4000bd62                 call    _simple_lock_try
F0067924: 90100018                 mov     %i0, %o0
F0067928: 80a22000                 cmp     %o0, 0
F006792C: 02bffff9                 be      loc_F0067910
F0067930: 01000000                 nop
F0067934: d2062008                 ld      [%i0+8], %o1
F0067938: 80a26000                 cmp     %o1, 0
F006793C: 1680000b                 bge     loc_F0067968
F0067940: 01000000                 nop
F0067944: 1100003f901223ff         set     0xFFFF, %o0
F006794C: 900a4008                 and     %o1, %o0, %o0
F0067950: 80a22002                 cmp     %o0, 2
F0067954: 12800005                 bne     loc_F0067968
F0067958: 01000000                 nop
F006795C: e0062014                 ld      [%i0+0x14], %l0
F0067960: 40002e01                 call    _task_reference
F0067964: 90100010                 mov     %l0, %o0
F0067968: c0260000                 clr     [%i0]
F006796C: 81c7e008                 ret
F0067970: 91e80010                 restore %g0, %l0, %o0
