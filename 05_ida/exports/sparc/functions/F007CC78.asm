F007CC78: 9de3bf98                 save    %sp, -0x68, %sp
F007CC7C: d0062004                 ld      [%i0+4], %o0
F007CC80: 80a22028                 cmp     %o0, 0x28 ! '('
F007CC84: 12800012                 bne     loc_F007CCCC
F007CC88: 90103ed0                 mov     -0x130, %o0
F007CC8C: d0060000                 ld      [%i0], %o0
F007CC90: 80a22000                 cmp     %o0, 0
F007CC94: 0680000d                 bl      loc_F007CCC8
F007CC98: 133c0444                 sethi   %hi(dword_F01110DC), %o1
F007CC9C: d0062018                 ld      [%i0+0x18], %o0
F007CCA0: d20260dc                 ld      [%o1+%lo(dword_F01110DC)], %o1
F007CCA4: 80a20009                 cmp     %o0, %o1
F007CCA8: 12800009                 bne     loc_F007CCCC
F007CCAC: 90103ed0                 mov     -0x130, %o0
F007CCB0: d0062020                 ld      [%i0+0x20], %o0
F007CCB4: 133c0444                 sethi   %hi(dword_F01110E0), %o1
F007CCB8: d20260e0                 ld      [%o1+%lo(dword_F01110E0)], %o1
F007CCBC: 80a20009                 cmp     %o0, %o1
F007CCC0: 02800005                 be      loc_F007CCD4
F007CCC4: 01000000                 nop
F007CCC8: 90103ed0                 mov     -0x130, %o0
F007CCCC: 1080000b                 ba      locret_F007CCF8
F007CCD0: d026601c                 st      %o0, [%i1+0x1C]
F007CCD4: 7fffab08                 call    _convert_port_to_task
F007CCD8: d0062008                 ld      [%i0+8], %o0
F007CCDC: d206201c                 ld      [%i0+0x1C], %o1
F007CCE0: a0100008                 mov     %o0, %l0
F007CCE4: 7fffdc7f                 call    _task_priority
F007CCE8: d4062024                 ld      [%i0+0x24], %o2
F007CCEC: d026601c                 st      %o0, [%i1+0x1C]
F007CCF0: 7fffd8ee                 call    _task_deallocate
F007CCF4: 90100010                 mov     %l0, %o0
F007CCF8: 81c7e008                 ret
F007CCFC: 81e80000                 restore
