F0066C0C: 9de3bf98                 save    %sp, -0x68, %sp
F0066C10: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0066C14: d0040000                 ld      [%l0], %o0
F0066C18: 80a22000                 cmp     %o0, 0
F0066C1C: 12bffffe                 bne     loc_F0066C14
F0066C20: 01000000                 nop
F0066C24: 4000c0a1                 call    _simple_lock_try
F0066C28: 90100010                 mov     %l0, %o0
F0066C2C: 80a22000                 cmp     %o0, 0
F0066C30: 02bffff9                 be      loc_F0066C14
F0066C34: 01000000                 nop
F0066C38: d0062068                 ld      [%i0+0x68], %o0
F0066C3C: 80a22000                 cmp     %o0, 0
F0066C40: 02800004                 be      loc_F0066C50
F0066C44: 92102000                 mov     0, %o1
F0066C48: 7ffffaf6                 call    _ipc_kobject_set
F0066C4C: 94102000                 mov     0, %o2
F0066C50: c0262064                 clr     [%i0+0x64]
F0066C54: 81c7e008                 ret
F0066C58: 81e80000                 restore
