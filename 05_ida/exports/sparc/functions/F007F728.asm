F007F728: 9de3bf98                 save    %sp, -0x68, %sp
F007F72C: d0062004                 ld      [%i0+4], %o0
F007F730: 80a22018                 cmp     %o0, 0x18
F007F734: 12800007                 bne     loc_F007F750
F007F738: 90103ed0                 mov     -0x130, %o0
F007F73C: d0060000                 ld      [%i0], %o0
F007F740: 80a22000                 cmp     %o0, 0
F007F744: 16800005                 bge     loc_F007F758
F007F748: 01000000                 nop
F007F74C: 90103ed0                 mov     -0x130, %o0
F007F750: 10800012                 ba      locret_F007F798
F007F754: d026601c                 st      %o0, [%i1+0x1C]
F007F758: 7fffa087                 call    _convert_port_to_space
F007F75C: d0062008                 ld      [%i0+8], %o0
F007F760: a0100008                 mov     %o0, %l0
F007F764: 7fff8e83                 call    _port_allocate
F007F768: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007F76C: d026601c                 st      %o0, [%i1+0x1C]
F007F770: 7fffa111                 call    _space_deallocate
F007F774: 90100010                 mov     %l0, %o0
F007F778: d006601c                 ld      [%i1+0x1C], %o0
F007F77C: 80a22000                 cmp     %o0, 0
F007F780: 12800006                 bne     locret_F007F798
F007F784: 90102028                 mov     0x28, %o0 ! '('
F007F788: d0266004                 st      %o0, [%i1+4]
F007F78C: 113c0445                 sethi   %hi(dword_F011142C), %o0
F007F790: d002202c                 ld      [%o0+%lo(dword_F011142C)], %o0
F007F794: d0266020                 st      %o0, [%i1+0x20]
F007F798: 81c7e008                 ret
F007F79C: 81e80000                 restore
