F00919C8: 9de3bf98                 save    %sp, -0x68, %sp
F00919CC: d4062004                 ld      [%i0+4], %o2
F00919D0: 80a2a023                 cmp     %o2, 0x23 ! '#'
F00919D4: 0880001e                 bleu    loc_F0091A4C
F00919D8: 90103ed0                 mov     -0x130, %o0
F00919DC: d0060000                 ld      [%i0], %o0
F00919E0: 80a22000                 cmp     %o0, 0
F00919E4: 36800004                 bge,a   loc_F00919F4
F00919E8: d0062018                 ld      [%i0+0x18], %o0
F00919EC: 10800018                 ba      loc_F0091A4C
F00919F0: 90103ed0                 mov     -0x130, %o0
F00919F4: 900a200c                 and     %o0, 0xC, %o0
F00919F8: 80a2200c                 cmp     %o0, 0xC
F00919FC: 12800014                 bne     loc_F0091A4C
F0091A00: 90103ed0                 mov     -0x130, %o0
F0091A04: d206201c                 ld      [%i0+0x1C], %o1
F0091A08: 1100020090122008         set     0x80008, %o0
F0091A10: 80a24008                 cmp     %o1, %o0
F0091A14: 1280000e                 bne     loc_F0091A4C
F0091A18: 90103ed0                 mov     -0x130, %o0
F0091A1C: d0062020                 ld      [%i0+0x20], %o0
F0091A20: 90022003                 inc     3, %o0
F0091A24: 900a3ffc                 and     %o0, -4, %o0
F0091A28: 90022024                 inc     0x24, %o0 ! '$'
F0091A2C: 80a28008                 cmp     %o2, %o0
F0091A30: 12800007                 bne     loc_F0091A4C
F0091A34: 90103ed0                 mov     -0x130, %o0
F0091A38: 7fff4e15                 call    _convert_port_to_host
F0091A3C: d0062008                 ld      [%i0+8], %o0
F0091A40: d4062020                 ld      [%i0+0x20], %o2
F0091A44: 7ffffc38                 call    _kern_IOProbeDriver
F0091A48: 92062024                 add     %i0, 0x24, %o1 ! '$'
F0091A4C: d026601c                 st      %o0, [%i1+0x1C]
F0091A50: 81c7e008                 ret
F0091A54: 81e80000                 restore
