F0063BDC: 9de3bf98                 save    %sp, -0x68, %sp
F0063BE0: 113c04d0                 sethi   %hi(_active_threads), %o0
F0063BE4: 80a62000                 cmp     %i0, 0
F0063BE8: 12800005                 bne     loc_F0063BFC
F0063BEC: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0063BF0: 113c043e                 sethi   %hi(aException), %o0! "exception"
F0063BF4: 7ffec55f                 call    _panic
F0063BF8: 901220c0                 bset    %lo(aException), %o0! "exception"
F0063BFC: f6246038                 st      %i3, [%l1+0x38]
F0063C00: a00460a8                 add     %l1, 0xA8, %l0
F0063C04: d0040000                 ld      [%l0], %o0
F0063C08: 80a22000                 cmp     %o0, 0
F0063C0C: 12bffffe                 bne     loc_F0063C04
F0063C10: 01000000                 nop
F0063C14: 4000cca5                 call    _simple_lock_try
F0063C18: 90100010                 mov     %l0, %o0
F0063C1C: 80a22000                 cmp     %o0, 0
F0063C20: 02bffff9                 be      loc_F0063C04
F0063C24: 01000000                 nop
F0063C28: f60460b4                 ld      [%l1+0xB4], %i3
F0063C2C: 80a6e000                 cmp     %i3, 0
F0063C30: 02800004                 be      loc_F0063C40
F0063C34: 80a6ffff                 cmp     %i3, -1
F0063C38: 12800005                 bne     loc_F0063C4C
F0063C3C: 01000000                 nop
F0063C40: c02460a8                 clr     [%l1+0xA8]
F0063C44: 10800012                 ba      loc_F0063C8C
F0063C48: 90100018                 mov     %i0, %o0
F0063C4C: d006c000                 ld      [%i3], %o0
F0063C50: 80a22000                 cmp     %o0, 0
F0063C54: 12bffffe                 bne     loc_F0063C4C
F0063C58: 01000000                 nop
F0063C5C: 4000cc93                 call    _simple_lock_try
F0063C60: 9010001b                 mov     %i3, %o0
F0063C64: 80a22000                 cmp     %o0, 0
F0063C68: 02bffff9                 be      loc_F0063C4C
F0063C6C: 01000000                 nop
F0063C70: c02460a8                 clr     [%l1+0xA8]
F0063C74: d006e008                 ld      [%i3+8], %o0
F0063C78: 80a22000                 cmp     %o0, 0
F0063C7C: 26800008                 bl,a    loc_F0063C9C
F0063C80: d006e004                 ld      [%i3+4], %o0
F0063C84: c026c000                 clr     [%i3]
F0063C88: 90100018                 mov     %i0, %o0
F0063C8C: 92100019                 mov     %i1, %o1
F0063C90: 400000b4                 call    _exception_try_task
F0063C94: 9410001a                 mov     %i2, %o2
F0063C98: 30800016                 ba,a    locret_F0063CF0
F0063C9C: 90022001                 inc     %o0
F0063CA0: d026e004                 st      %o0, [%i3+4]
F0063CA4: d006e01c                 ld      [%i3+0x1C], %o0
F0063CA8: 90022001                 inc     %o0
F0063CAC: d026e01c                 st      %o0, [%i3+0x1C]
F0063CB0: c026c000                 clr     [%i3]
F0063CB4: f02460c8                 st      %i0, [%l1+0xC8]
F0063CB8: f22460cc                 st      %i1, [%l1+0xCC]
F0063CBC: f42460d0                 st      %i2, [%l1+0xD0]
F0063CC0: 40000cf9                 call    _retrieve_thread_self_fast
F0063CC4: 90100011                 mov     %l1, %o0
F0063CC8: a0100008                 mov     %o0, %l0
F0063CCC: 40000cce                 call    _retrieve_task_self_fast
F0063CD0: d004600c                 ld      [%l1+0xC], %o0
F0063CD4: 94100008                 mov     %o0, %o2! task
F0063CD8: 9010001b                 mov     %i3, %o0! exception_port
F0063CDC: 92100010                 mov     %l0, %o1! thread
F0063CE0: 96100018                 mov     %i0, %o3! exception
F0063CE4: 98100019                 mov     %i1, %o4! code
F0063CE8: 400000eb                 call    _exception_raise
F0063CEC: 9a10001a                 mov     %i2, %o5
F0063CF0: 81c7e008                 ret
F0063CF4: 81e80000                 restore
