F006A14C: 9de3bf98                 save    %sp, -0x68, %sp
F006A150: a2100018                 mov     %i0, %l1
F006A154: d0046010                 ld      [%l1+0x10], %o0
F006A158: a0102000                 mov     0, %l0
F006A15C: 80a40008                 cmp     %l0, %o0
F006A160: 1a800013                 bcc     loc_F006A1AC
F006A164: b004601c                 add     %l1, 0x1C, %i0
F006A168: d0060000                 ld      [%i0], %o0
F006A16C: 80a22001                 cmp     %o0, 1
F006A170: 3280000a                 bne,a   loc_F006A198
F006A174: d2062004                 ld      [%i0+4], %o1
F006A178: 90062008                 add     %i0, 8, %o0! __s1
F006A17C: 92100019                 mov     %i1, %o1! __s2
F006A180: 7ffe78da                 call    _strncmp
F006A184: 94102010                 mov     0x10, %o2
F006A188: 80a22000                 cmp     %o0, 0
F006A18C: 02800009                 be      locret_F006A1B0
F006A190: 01000000                 nop
F006A194: d2062004                 ld      [%i0+4], %o1
F006A198: a0042001                 inc     %l0
F006A19C: d0046010                 ld      [%l1+0x10], %o0
F006A1A0: 80a40008                 cmp     %l0, %o0
F006A1A4: 0abffff1                 bcs     loc_F006A168
F006A1A8: b0060009                 add     %i0, %o1, %i0
F006A1AC: b0102000                 mov     0, %i0
F006A1B0: 81c7e008                 ret
F006A1B4: 81e80000                 restore
