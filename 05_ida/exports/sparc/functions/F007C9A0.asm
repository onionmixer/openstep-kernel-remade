F007C9A0: 9de3bf98                 save    %sp, -0x68, %sp
F007C9A4: d0062004                 ld      [%i0+4], %o0
F007C9A8: 80a22020                 cmp     %o0, 0x20 ! ' '
F007C9AC: 1280000c                 bne     loc_F007C9DC
F007C9B0: 90103ed0                 mov     -0x130, %o0
F007C9B4: d0060000                 ld      [%i0], %o0
F007C9B8: 80a22000                 cmp     %o0, 0
F007C9BC: 06800007                 bl      loc_F007C9D8
F007C9C0: 133c0444                 sethi   %hi(dword_F01110BC), %o1
F007C9C4: d0062018                 ld      [%i0+0x18], %o0
F007C9C8: d20260bc                 ld      [%o1+%lo(dword_F01110BC)], %o1! assign_threads
F007C9CC: 80a20009                 cmp     %o0, %o1
F007C9D0: 02800005                 be      loc_F007C9E4
F007C9D4: 01000000                 nop
F007C9D8: 90103ed0                 mov     -0x130, %o0
F007C9DC: 1080000a                 ba      locret_F007CA04
F007C9E0: d026601c                 st      %o0, [%i1+0x1C]
F007C9E4: 7fffabc4                 call    _convert_port_to_task
F007C9E8: d0062008                 ld      [%i0+8], %o0! task
F007C9EC: a0100008                 mov     %o0, %l0
F007C9F0: 7fffdd29                 call    _task_assign_default
F007C9F4: d206201c                 ld      [%i0+0x1C], %o1
F007C9F8: d026601c                 st      %o0, [%i1+0x1C]
F007C9FC: 7fffd9ab                 call    _task_deallocate
F007CA00: 90100010                 mov     %l0, %o0
F007CA04: 81c7e008                 ret
F007CA08: 81e80000                 restore
