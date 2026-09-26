F009BF28: 9de3bf98                 save    %sp, -0x68, %sp
F009BF2C: f2262034                 st      %i1, [%i0+0x34]
F009BF30: 7fffe284                 call    _save_context
F009BF34: 90100018                 mov     %i0, %o0
F009BF38: 80a22000                 cmp     %o0, 0
F009BF3C: 22800004                 be,a    loc_F009BF4C
F009BF40: 113c04d0                 sethi   -0xFECC000, %o0
F009BF44: 10800021                 ba      locret_F009BFC8
F009BF48: b0100008                 mov     %o0, %i0
F009BF4C: f4222260                 st      %i2, [%o0+0x260]
F009BF50: d206a02c                 ld      [%i2+0x2C], %o1
F009BF54: 113c04f0                 sethi   %hi(_active_stacks), %o0
F009BF58: d2222058                 st      %o1, [%o0+%lo(_active_stacks)]
F009BF5C: d206a028                 ld      [%i2+0x28], %o1
F009BF60: d406a00c                 ld      [%i2+0xC], %o2
F009BF64: 113c0428                 sethi   %hi(_active_pcb), %o0
F009BF68: d606200c                 ld      [%i0+0xC], %o3
F009BF6C: 80a2800b                 cmp     %o2, %o3
F009BF70: 0280000d                 be      loc_F009BFA4
F009BF74: d2222024                 st      %o1, [%o0+%lo(_active_pcb)]
F009BF78: d002e00c                 ld      [%o3+0xC], %o0
F009BF7C: 92100018                 mov     %i0, %o1
F009BF80: d0022024                 ld      [%o0+0x24], %o0
F009BF84: 40000de9                 call    _pmap_deactivate
F009BF88: 94102000                 mov     0, %o2
F009BF8C: d006a00c                 ld      [%i2+0xC], %o0
F009BF90: d002200c                 ld      [%o0+0xC], %o0
F009BF94: 9210001a                 mov     %i2, %o1
F009BF98: d0022024                 ld      [%o0+0x24], %o0
F009BF9C: 40000d99                 call    _pmap_activate
F009BFA0: 94102000                 mov     0, %o2
F009BFA4: 80a62000                 cmp     %i0, 0
F009BFA8: 32800006                 bne,a   loc_F009BFC0
F009BFAC: 9010001a                 mov     %i2, %o0
F009BFB0: 113c045e                 sethi   %hi(aSwitchContextO), %o0! "switch_context(), old == THREAD_NULL\n"
F009BFB4: 7ffde46f                 call    _panic
F009BFB8: 901222e0                 bset    %lo(aSwitchContextO), %o0! "switch_context(), old == THREAD_NULL\n"
F009BFBC: 9010001a                 mov     %i2, %o0
F009BFC0: 7fffe2ae                 call    _load_context
F009BFC4: 92100018                 mov     %i0, %o1
F009BFC8: 81c7e008                 ret
F009BFCC: 81e80000                 restore
