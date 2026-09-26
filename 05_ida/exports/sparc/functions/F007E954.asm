F007E954: 9de3bf98                 save    %sp, -0x68, %sp
F007E958: d0062004                 ld      [%i0+4], %o0
F007E95C: 80a22018                 cmp     %o0, 0x18
F007E960: 12800007                 bne     loc_F007E97C
F007E964: 90103ed0                 mov     -0x130, %o0
F007E968: d0060000                 ld      [%i0], %o0
F007E96C: 80a22000                 cmp     %o0, 0
F007E970: 16800005                 bge     loc_F007E984
F007E974: 01000000                 nop
F007E978: 90103ed0                 mov     -0x130, %o0
F007E97C: 10800012                 ba      locret_F007E9C4
F007E980: d026601c                 st      %o0, [%i1+0x1C]
F007E984: 7fffa41d                 call    _convert_port_to_map
F007E988: d0062008                 ld      [%i0+8], %o0
F007E98C: a0100008                 mov     %o0, %l0
F007E990: 40002ffe                 call    _vm_statistics
F007E994: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007E998: d026601c                 st      %o0, [%i1+0x1C]
F007E99C: 4000161c                 call    _vm_map_deallocate
F007E9A0: 90100010                 mov     %l0, %o0
F007E9A4: d006601c                 ld      [%i1+0x1C], %o0
F007E9A8: 80a22000                 cmp     %o0, 0
F007E9AC: 12800006                 bne     locret_F007E9C4
F007E9B0: 90102058                 mov     0x58, %o0 ! 'X'
F007E9B4: d0266004                 st      %o0, [%i1+4]
F007E9B8: 113c0444                 sethi   %hi(dword_F011137C), %o0
F007E9BC: d002237c                 ld      [%o0+%lo(dword_F011137C)], %o0
F007E9C0: d0266020                 st      %o0, [%i1+0x20]
F007E9C4: 81c7e008                 ret
F007E9C8: 81e80000                 restore
