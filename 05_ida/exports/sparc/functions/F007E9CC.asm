F007E9CC: 9de3bf90                 save    %sp, -0x70, %sp
F007E9D0: d0062004                 ld      [%i0+4], %o0
F007E9D4: 80a22020                 cmp     %o0, 0x20 ! ' '
F007E9D8: 1280000e                 bne     loc_F007EA10
F007E9DC: 90103ed0                 mov     -0x130, %o0
F007E9E0: d0060000                 ld      [%i0], %o0
F007E9E4: 23200000                 sethi   0x80000000, %l1
F007E9E8: 808a0011                 btst    %l1, %o0
F007E9EC: 12800009                 bne     loc_F007EA10
F007E9F0: 90103ed0                 mov     -0x130, %o0
F007E9F4: d0062018                 ld      [%i0+0x18], %o0
F007E9F8: 133c0444                 sethi   %hi(dword_F0111380), %o1
F007E9FC: d2026380                 ld      [%o1+%lo(dword_F0111380)], %o1
F007EA00: 80a20009                 cmp     %o0, %o1
F007EA04: 02800005                 be      loc_F007EA18
F007EA08: 01000000                 nop
F007EA0C: 90103ed0                 mov     -0x130, %o0
F007EA10: 10800019                 ba      locret_F007EA74
F007EA14: d026601c                 st      %o0, [%i1+0x1C]
F007EA18: 7fffa3b7                 call    _convert_port_to_task
F007EA1C: d0062008                 ld      [%i0+8], %o0
F007EA20: a0100008                 mov     %o0, %l0
F007EA24: d206201c                 ld      [%i0+0x1C], %o1
F007EA28: 40002e14                 call    _task_by_unix_pid
F007EA2C: 9407bff4                 add     %fp, var_C, %o2
F007EA30: d026601c                 st      %o0, [%i1+0x1C]
F007EA34: 7fffd19d                 call    _task_deallocate
F007EA38: 90100010                 mov     %l0, %o0
F007EA3C: d006601c                 ld      [%i1+0x1C], %o0
F007EA40: 80a22000                 cmp     %o0, 0
F007EA44: 1280000c                 bne     locret_F007EA74
F007EA48: 92102028                 mov     0x28, %o1 ! '('
F007EA4C: d0064000                 ld      [%i1], %o0
F007EA50: d2266004                 st      %o1, [%i1+4]
F007EA54: 90120011                 bset    %l1, %o0
F007EA58: d0264000                 st      %o0, [%i1]
F007EA5C: 113c0444                 sethi   %hi(dword_F0111384), %o0
F007EA60: d2022384                 ld      [%o0+%lo(dword_F0111384)], %o1
F007EA64: d007bff4                 ld      [%fp+var_C], %o0
F007EA68: 7fffa425                 call    _convert_task_to_port
F007EA6C: d2266020                 st      %o1, [%i1+0x20]
F007EA70: d0266024                 st      %o0, [%i1+0x24]
F007EA74: 81c7e008                 ret
F007EA78: 81e80000                 restore
