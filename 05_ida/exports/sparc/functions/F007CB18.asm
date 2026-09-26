F007CB18: 9de3bf98                 save    %sp, -0x68, %sp
F007CB1C: d0062004                 ld      [%i0+4], %o0
F007CB20: 80a22028                 cmp     %o0, 0x28 ! '('
F007CB24: 12800012                 bne     loc_F007CB6C
F007CB28: 90103ed0                 mov     -0x130, %o0
F007CB2C: d0060000                 ld      [%i0], %o0
F007CB30: 80a22000                 cmp     %o0, 0
F007CB34: 0680000d                 bl      loc_F007CB68
F007CB38: 133c0444                 sethi   %hi(dword_F01110D0), %o1
F007CB3C: d0062018                 ld      [%i0+0x18], %o0
F007CB40: d20260d0                 ld      [%o1+%lo(dword_F01110D0)], %o1
F007CB44: 80a20009                 cmp     %o0, %o1
F007CB48: 12800009                 bne     loc_F007CB6C
F007CB4C: 90103ed0                 mov     -0x130, %o0
F007CB50: d0062020                 ld      [%i0+0x20], %o0
F007CB54: 133c0444                 sethi   %hi(dword_F01110D4), %o1
F007CB58: d20260d4                 ld      [%o1+%lo(dword_F01110D4)], %o1
F007CB5C: 80a20009                 cmp     %o0, %o1
F007CB60: 02800005                 be      loc_F007CB74
F007CB64: 01000000                 nop
F007CB68: 90103ed0                 mov     -0x130, %o0
F007CB6C: 1080000b                 ba      locret_F007CB98
F007CB70: d026601c                 st      %o0, [%i1+0x1C]
F007CB74: 7fffabc2                 call    _convert_port_to_thread
F007CB78: d0062008                 ld      [%i0+8], %o0
F007CB7C: d206201c                 ld      [%i0+0x1C], %o1
F007CB80: a0100008                 mov     %o0, %l0
F007CB84: 7fffe415                 call    _thread_priority
F007CB88: d4062024                 ld      [%i0+0x24], %o2
F007CB8C: d026601c                 st      %o0, [%i1+0x1C]
F007CB90: 7fffde07                 call    _thread_deallocate
F007CB94: 90100010                 mov     %l0, %o0
F007CB98: 81c7e008                 ret
F007CB9C: 81e80000                 restore
