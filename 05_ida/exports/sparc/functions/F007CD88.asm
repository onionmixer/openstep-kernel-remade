F007CD88: 9de3bf98                 save    %sp, -0x68, %sp
F007CD8C: d0062004                 ld      [%i0+4], %o0
F007CD90: 80a22028                 cmp     %o0, 0x28 ! '('
F007CD94: 12800012                 bne     loc_F007CDDC
F007CD98: 90103ed0                 mov     -0x130, %o0
F007CD9C: d0060000                 ld      [%i0], %o0
F007CDA0: 80a22000                 cmp     %o0, 0
F007CDA4: 0680000d                 bl      loc_F007CDD8
F007CDA8: 133c0444                 sethi   %hi(dword_F01110EC), %o1
F007CDAC: d0062018                 ld      [%i0+0x18], %o0
F007CDB0: d20260ec                 ld      [%o1+%lo(dword_F01110EC)], %o1
F007CDB4: 80a20009                 cmp     %o0, %o1
F007CDB8: 12800009                 bne     loc_F007CDDC
F007CDBC: 90103ed0                 mov     -0x130, %o0
F007CDC0: d0062020                 ld      [%i0+0x20], %o0
F007CDC4: 133c0444                 sethi   %hi(dword_F01110F0), %o1
F007CDC8: d20260f0                 ld      [%o1+%lo(dword_F01110F0)], %o1
F007CDCC: 80a20009                 cmp     %o0, %o1
F007CDD0: 02800005                 be      loc_F007CDE4
F007CDD4: 01000000                 nop
F007CDD8: 90103ed0                 mov     -0x130, %o0
F007CDDC: 1080000b                 ba      locret_F007CE08
F007CDE0: d026601c                 st      %o0, [%i1+0x1C]
F007CDE4: 7fffab26                 call    _convert_port_to_thread
F007CDE8: d0062008                 ld      [%i0+8], %o0! thr_act
F007CDEC: d206201c                 ld      [%i0+0x1C], %o1! policy
F007CDF0: a0100008                 mov     %o0, %l0
F007CDF4: 7fffe3ec                 call    _thread_policy
F007CDF8: d4062024                 ld      [%i0+0x24], %o2
F007CDFC: d026601c                 st      %o0, [%i1+0x1C]
F007CE00: 7fffdd6b                 call    _thread_deallocate
F007CE04: 90100010                 mov     %l0, %o0
F007CE08: 81c7e008                 ret
F007CE0C: 81e80000                 restore
