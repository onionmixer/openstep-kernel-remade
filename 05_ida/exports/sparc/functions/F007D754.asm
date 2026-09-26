F007D754: 9de3bf98                 save    %sp, -0x68, %sp
F007D758: d0062004                 ld      [%i0+4], %o0
F007D75C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D760: 1280000c                 bne     loc_F007D790
F007D764: 90103ed0                 mov     -0x130, %o0
F007D768: d0060000                 ld      [%i0], %o0
F007D76C: 80a22000                 cmp     %o0, 0
F007D770: 06800007                 bl      loc_F007D78C
F007D774: 133c0444                 sethi   %hi(dword_F011121C), %o1
F007D778: d0062018                 ld      [%i0+0x18], %o0
F007D77C: d202621c                 ld      [%o1+%lo(dword_F011121C)], %o1! name
F007D780: 80a20009                 cmp     %o0, %o1
F007D784: 02800005                 be      loc_F007D798
F007D788: 01000000                 nop
F007D78C: 90103ed0                 mov     -0x130, %o0
F007D790: 1080000a                 ba      locret_F007D7B8
F007D794: d026601c                 st      %o0, [%i1+0x1C]
F007D798: 7fffa877                 call    _convert_port_to_space
F007D79C: d0062008                 ld      [%i0+8], %o0! task
F007D7A0: a0100008                 mov     %o0, %l0
F007D7A4: 7fff9326                 call    _mach_port_destroy
F007D7A8: d206201c                 ld      [%i0+0x1C], %o1
F007D7AC: d026601c                 st      %o0, [%i1+0x1C]
F007D7B0: 7fffa901                 call    _space_deallocate
F007D7B4: 90100010                 mov     %l0, %o0
F007D7B8: 81c7e008                 ret
F007D7BC: 81e80000                 restore
