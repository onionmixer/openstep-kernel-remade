F0059AFC: 9de3bf98                 save    %sp, -0x68, %sp
F0059B00: 92067ffb                 add     %i1, -5, %o1
F0059B04: 80a26010                 cmp     %o1, 0x10! switch 17 cases
F0059B08: 18800060                 bgu     def_F0059B1C! jumptable F0059B1C default case, cases 2-10
F0059B0C: 932a6002                 sll     %o1, 2, %o1
F0059B10: 113c016690122324         set     jpt_F0059B1C, %o0
F0059B18: d0024008                 ld      [%o1+%o0], %o0
F0059B1C: 81c20000                 jmp     %o0! switch jump
F0059B20: 01000000                 nop
F0059B68: d0060000                 ld      [%i0], %o0! jumptable F0059B1C cases 0,11
F0059B6C: 80a22000                 cmp     %o0, 0
F0059B70: 12bffffe                 bne     loc_F0059B68! jumptable F0059B1C cases 0,11
F0059B74: 01000000                 nop
F0059B78: 4000f4cc                 call    _simple_lock_try
F0059B7C: 90100018                 mov     %i0, %o0
F0059B80: 80a22000                 cmp     %o0, 0
F0059B84: 02bffff9                 be      loc_F0059B68! jumptable F0059B1C cases 0,11
F0059B88: 01000000                 nop
F0059B8C: c0262018                 clr     [%i0+0x18]
F0059B90: c0262010                 clr     [%i0+0x10]
F0059B94: c026200c                 clr     [%i0+0xC]
F0059B98: c0260000                 clr     [%i0]
F0059B9C: 3080003e                 ba,a    locret_F0059C94! jumptable F0059B1C cases 12,13
F0059BA0: d0060000                 ld      [%i0], %o0! jumptable F0059B1C cases 1,14
F0059BA4: 80a22000                 cmp     %o0, 0
F0059BA8: 12bffffe                 bne     loc_F0059BA0! jumptable F0059B1C cases 1,14
F0059BAC: 01000000                 nop
F0059BB0: 4000f4be                 call    _simple_lock_try
F0059BB4: 90100018                 mov     %i0, %o0
F0059BB8: 80a22000                 cmp     %o0, 0
F0059BBC: 02bffff9                 be      loc_F0059BA0! jumptable F0059B1C cases 1,14
F0059BC0: 01000000                 nop
F0059BC4: d0062008                 ld      [%i0+8], %o0
F0059BC8: 80a22000                 cmp     %o0, 0
F0059BCC: 36800006                 bge,a   loc_F0059BE4
F0059BD0: d0062004                 ld      [%i0+4], %o0
F0059BD4: d006201c                 ld      [%i0+0x1C], %o0
F0059BD8: 90022001                 inc     %o0
F0059BDC: d026201c                 st      %o0, [%i0+0x1C]
F0059BE0: d0062004                 ld      [%i0+4], %o0
F0059BE4: 90022001                 inc     %o0
F0059BE8: d0262004                 st      %o0, [%i0+4]
F0059BEC: c0260000                 clr     [%i0]
F0059BF0: 30800029                 ba,a    locret_F0059C94! jumptable F0059B1C cases 12,13
F0059BF4: d0060000                 ld      [%i0], %o0! jumptable F0059B1C case 15
F0059BF8: 80a22000                 cmp     %o0, 0
F0059BFC: 12bffffe                 bne     loc_F0059BF4! jumptable F0059B1C case 15
F0059C00: 01000000                 nop
F0059C04: 4000f4a9                 call    _simple_lock_try
F0059C08: 90100018                 mov     %i0, %o0
F0059C0C: 80a22000                 cmp     %o0, 0
F0059C10: 02bffff9                 be      loc_F0059BF4! jumptable F0059B1C case 15
F0059C14: 01000000                 nop
F0059C18: d0062004                 ld      [%i0+4], %o0
F0059C1C: 90022001                 inc     %o0
F0059C20: d0262004                 st      %o0, [%i0+4]
F0059C24: d0062018                 ld      [%i0+0x18], %o0
F0059C28: 90022001                 inc     %o0
F0059C2C: d0262018                 st      %o0, [%i0+0x18]
F0059C30: d006201c                 ld      [%i0+0x1C], %o0
F0059C34: c0260000                 clr     [%i0]
F0059C38: 90022001                 inc     %o0
F0059C3C: 10800016                 ba      locret_F0059C94! jumptable F0059B1C cases 12,13
F0059C40: d026201c                 st      %o0, [%i0+0x1C]
F0059C44: d0060000                 ld      [%i0], %o0! jumptable F0059B1C case 16
F0059C48: 80a22000                 cmp     %o0, 0
F0059C4C: 12bffffe                 bne     loc_F0059C44! jumptable F0059B1C case 16
F0059C50: 01000000                 nop
F0059C54: 4000f495                 call    _simple_lock_try
F0059C58: 90100018                 mov     %i0, %o0
F0059C5C: 80a22000                 cmp     %o0, 0
F0059C60: 02bffff9                 be      loc_F0059C44! jumptable F0059B1C case 16
F0059C64: 01000000                 nop
F0059C68: d0062004                 ld      [%i0+4], %o0
F0059C6C: 90022001                 inc     %o0
F0059C70: d0262004                 st      %o0, [%i0+4]
F0059C74: d0062020                 ld      [%i0+0x20], %o0
F0059C78: 90022001                 inc     %o0
F0059C7C: d0262020                 st      %o0, [%i0+0x20]
F0059C80: c0260000                 clr     [%i0]
F0059C84: 30800004                 ba,a    locret_F0059C94! jumptable F0059B1C cases 12,13
F0059C88: 113c043d                 sethi   %hi(aIpcObjectCopyi_0), %o0! jumptable F0059B1C default case, cases 2-10
F0059C8C: 7ffeed39                 call    _panic
F0059C90: 90122210                 bset    %lo(aIpcObjectCopyi_0), %o0! "ipc_object_copyin_from_kernel: strange "...
F0059C94: 81c7e008                 ret! jumptable F0059B1C cases 12,13
F0059C98: 81e80000                 restore
