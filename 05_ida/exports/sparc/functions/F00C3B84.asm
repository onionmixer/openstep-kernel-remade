F00C3B84: 9de3bf98                 save    %sp, -0x68, %sp
F00C3B88: a4100018                 mov     %i0, %l2
F00C3B8C: 113c048590122050         set     _static_KERNBOOTSTRUCT, %o0
F00C3B94: 1300000492126128         set     0x1128, %o1
F00C3B9C: b0020009                 add     %o0, %o1, %i0
F00C3BA0: d04a0009                 ldsb    [%o0+%o1], %o0
F00C3BA4: 80a22000                 cmp     %o0, 0
F00C3BA8: 12800007                 bne     loc_F00C3BC4
F00C3BAC: a2102000                 mov     0, %l1
F00C3BB0: 113c04ba                 sethi   %hi(aWarningNoConfi), %o0! "WARNING: No config table in KERNBOOTSTR"...
F00C3BB4: 40000950                 call    _IOLog
F00C3BB8: 90122148                 bset    %lo(aWarningNoConfi), %o0! "WARNING: No config table in KERNBOOTSTR"...
F00C3BBC: 10800018                 ba      locret_F00C3C1C
F00C3BC0: b0102000                 mov     0, %i0
F00C3BC4: a0102000                 mov     0, %l0
F00C3BC8: 80a40012                 cmp     %l0, %l2
F00C3BCC: 16800014                 bge     locret_F00C3C1C
F00C3BD0: 27000030                 sethi   0xC000, %l3
F00C3BD4: 7ffd0e19                 call    _strlen
F00C3BD8: 90100018                 mov     %i0, %o0
F00C3BDC: 92046001                 add     %l1, 1, %o1
F00C3BE0: a2024008                 add     %o1, %o0, %l1
F00C3BE4: 92022001                 add     %o0, 1, %o1
F00C3BE8: 80a22000                 cmp     %o0, 0
F00C3BEC: 02bffff4                 be      loc_F00C3BBC
F00C3BF0: b0060009                 add     %i0, %o1, %i0
F00C3BF4: 80a44013                 cmp     %l1, %l3
F00C3BF8: 34800009                 bg,a    locret_F00C3C1C
F00C3BFC: b0102000                 mov     0, %i0
F00C3C00: d04e0000                 ldsb    [%i0], %o0
F00C3C04: 80a22000                 cmp     %o0, 0
F00C3C08: 02bfffed                 be      loc_F00C3BBC
F00C3C0C: a0042001                 inc     %l0
F00C3C10: 80a40012                 cmp     %l0, %l2
F00C3C14: 06bffff0                 bl      loc_F00C3BD4
F00C3C18: 01000000                 nop
F00C3C1C: 81c7e008                 ret
F00C3C20: 81e80000                 restore
