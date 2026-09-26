F00F2900: 9de3bf98                 save    %sp, -0x68, %sp
F00F2904: a2100018                 mov     %i0, %l1
F00F2908: a0102000                 mov     0, %l0
F00F290C: d0046010                 ld      [%l1+0x10], %o0
F00F2910: 80a40008                 cmp     %l0, %o0
F00F2914: 1a800015                 bcc     loc_F00F2968
F00F2918: b004601c                 add     %l1, 0x1C, %i0
F00F291C: 253c03f4                 sethi   -0xFF03000, %l2
F00F2920: d0060000                 ld      [%i0], %o0
F00F2924: 80a22001                 cmp     %o0, 1
F00F2928: 3280000a                 bne,a   loc_F00F2950
F00F292C: d0062004                 ld      [%i0+4], %o0
F00F2930: 90062008                 add     %i0, 8, %o0! __s1
F00F2934: 9214a0c8                 or      %l2, 0xC8, %o1! __s2
F00F2938: 7ffc56ec                 call    _strncmp
F00F293C: 94102010                 mov     0x10, %o2
F00F2940: 80a22000                 cmp     %o0, 0
F00F2944: 0280000a                 be      locret_F00F296C
F00F2948: 01000000                 nop
F00F294C: d0062004                 ld      [%i0+4], %o0
F00F2950: b0060008                 add     %i0, %o0, %i0
F00F2954: a0042001                 inc     %l0
F00F2958: d0046010                 ld      [%l1+0x10], %o0
F00F295C: 80a40008                 cmp     %l0, %o0
F00F2960: 2abffff1                 bcs,a   loc_F00F2924
F00F2964: d0060000                 ld      [%i0], %o0
F00F2968: b0102000                 mov     0, %i0
F00F296C: 81c7e008                 ret
F00F2970: 81e80000                 restore
