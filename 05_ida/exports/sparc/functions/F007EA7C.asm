F007EA7C: 9de3bf98                 save    %sp, -0x68, %sp
F007EA80: d0062004                 ld      [%i0+4], %o0
F007EA84: 80a22018                 cmp     %o0, 0x18
F007EA88: 12800007                 bne     loc_F007EAA4
F007EA8C: 90103ed0                 mov     -0x130, %o0
F007EA90: d0060000                 ld      [%i0], %o0
F007EA94: 80a22000                 cmp     %o0, 0
F007EA98: 16800005                 bge     loc_F007EAAC
F007EA9C: 01000000                 nop
F007EAA0: 90103ed0                 mov     -0x130, %o0
F007EAA4: 10800012                 ba      locret_F007EAEC
F007EAA8: d026601c                 st      %o0, [%i1+0x1C]
F007EAAC: 7fffa392                 call    _convert_port_to_task
F007EAB0: d0062008                 ld      [%i0+8], %o0
F007EAB4: a0100008                 mov     %o0, %l0
F007EAB8: 40002de0                 call    _unix_pid
F007EABC: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007EAC0: d026601c                 st      %o0, [%i1+0x1C]
F007EAC4: 7fffd179                 call    _task_deallocate
F007EAC8: 90100010                 mov     %l0, %o0
F007EACC: d006601c                 ld      [%i1+0x1C], %o0
F007EAD0: 80a22000                 cmp     %o0, 0
F007EAD4: 12800006                 bne     locret_F007EAEC
F007EAD8: 90102028                 mov     0x28, %o0 ! '('
F007EADC: d0266004                 st      %o0, [%i1+4]
F007EAE0: 113c0444                 sethi   %hi(dword_F0111388), %o0
F007EAE4: d0022388                 ld      [%o0+%lo(dword_F0111388)], %o0
F007EAE8: d0266020                 st      %o0, [%i1+0x20]
F007EAEC: 81c7e008                 ret
F007EAF0: 81e80000                 restore
