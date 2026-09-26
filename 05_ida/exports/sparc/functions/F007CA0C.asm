F007CA0C: 9de3bf90                 save    %sp, -0x70, %sp
F007CA10: d0062004                 ld      [%i0+4], %o0
F007CA14: 80a22018                 cmp     %o0, 0x18
F007CA18: 12800008                 bne     loc_F007CA38
F007CA1C: 90103ed0                 mov     -0x130, %o0
F007CA20: d0060000                 ld      [%i0], %o0
F007CA24: 23200000                 sethi   0x80000000, %l1
F007CA28: 808a0011                 btst    %l1, %o0
F007CA2C: 02800005                 be      loc_F007CA40
F007CA30: 01000000                 nop
F007CA34: 90103ed0                 mov     -0x130, %o0
F007CA38: 10800018                 ba      locret_F007CA98
F007CA3C: d026601c                 st      %o0, [%i1+0x1C]
F007CA40: 7fffabad                 call    _convert_port_to_task
F007CA44: d0062008                 ld      [%i0+8], %o0! task
F007CA48: a0100008                 mov     %o0, %l0
F007CA4C: 7fffdd1a                 call    _task_get_assignment
F007CA50: 9207bff4                 add     %fp, var_C, %o1
F007CA54: d026601c                 st      %o0, [%i1+0x1C]
F007CA58: 7fffd994                 call    _task_deallocate
F007CA5C: 90100010                 mov     %l0, %o0
F007CA60: d006601c                 ld      [%i1+0x1C], %o0
F007CA64: 80a22000                 cmp     %o0, 0
F007CA68: 1280000c                 bne     locret_F007CA98
F007CA6C: 92102028                 mov     0x28, %o1 ! '('
F007CA70: d0064000                 ld      [%i1], %o0
F007CA74: d2266004                 st      %o1, [%i1+4]
F007CA78: 90120011                 bset    %l1, %o0
F007CA7C: d0264000                 st      %o0, [%i1]
F007CA80: 113c0444                 sethi   %hi(dword_F01110C0), %o0
F007CA84: d20220c0                 ld      [%o0+%lo(dword_F01110C0)], %o1
F007CA88: d007bff4                 ld      [%fp+var_C], %o0
F007CA8C: 7fffa2b7                 call    _convert_pset_name_to_port
F007CA90: d2266020                 st      %o1, [%i1+0x20]
F007CA94: d0266024                 st      %o0, [%i1+0x24]
F007CA98: 81c7e008                 ret
F007CA9C: 81e80000                 restore
