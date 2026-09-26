F007F968: 9de3bf98                 save    %sp, -0x68, %sp
F007F96C: d0062004                 ld      [%i0+4], %o0
F007F970: 80a22018                 cmp     %o0, 0x18
F007F974: 12800007                 bne     loc_F007F990
F007F978: 90103ed0                 mov     -0x130, %o0
F007F97C: d0060000                 ld      [%i0], %o0
F007F980: 80a22000                 cmp     %o0, 0
F007F984: 16800005                 bge     loc_F007F998
F007F988: 01000000                 nop
F007F98C: 90103ed0                 mov     -0x130, %o0
F007F990: 10800012                 ba      locret_F007F9D8
F007F994: d026601c                 st      %o0, [%i1+0x1C]
F007F998: 7fff9ff7                 call    _convert_port_to_space
F007F99C: d0062008                 ld      [%i0+8], %o0
F007F9A0: a0100008                 mov     %o0, %l0
F007F9A4: 7fff8ec8                 call    _port_set_allocate
F007F9A8: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007F9AC: d026601c                 st      %o0, [%i1+0x1C]
F007F9B0: 7fffa081                 call    _space_deallocate
F007F9B4: 90100010                 mov     %l0, %o0
F007F9B8: d006601c                 ld      [%i1+0x1C], %o0
F007F9BC: 80a22000                 cmp     %o0, 0
F007F9C0: 12800006                 bne     locret_F007F9D8
F007F9C4: 90102028                 mov     0x28, %o0 ! '('
F007F9C8: d0266004                 st      %o0, [%i1+4]
F007F9CC: 113c0445                 sethi   %hi(dword_F0111454), %o0
F007F9D0: d0022054                 ld      [%o0+%lo(dword_F0111454)], %o0
F007F9D4: d0266020                 st      %o0, [%i1+0x20]
F007F9D8: 81c7e008                 ret
F007F9DC: 81e80000                 restore
