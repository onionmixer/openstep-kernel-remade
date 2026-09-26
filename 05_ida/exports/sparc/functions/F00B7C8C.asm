F00B7C8C: 9de3bf88                 save    %sp, -0x78, %sp
F00B7C90: d20e2030                 ldub    [%i0+0x30], %o1
F00B7C94: e807a05c                 ld      [%fp+arg_5C], %l4
F00B7C98: e207a060                 ld      [%fp+arg_60], %l1
F00B7C9C: e407a064                 ld      [%fp+arg_64], %l2
F00B7CA0: e607a068                 ld      [%fp+arg_68], %l3
F00B7CA4: 113c047b                 sethi   %hi(aEspD_0), %o0! "esp%d:\t"
F00B7CA8: e007a06c                 ld      [%fp+arg_6C], %l0
F00B7CAC: 7ffd726b                 call    _printf
F00B7CB0: 901220b8                 bset    %lo(aEspD_0), %o0! "esp%d:\t"
F00B7CB4: e223a05c                 st      %l1, [%sp+0x78+var_1C]
F00B7CB8: e43ba060                 std     %l2, [%sp+0x78+var_18]
F00B7CBC: e023a068                 st      %l0, [%sp+0x78+var_10]
F00B7CC0: 90100019                 mov     %i1, %o0! char *
F00B7CC4: 9210001a                 mov     %i2, %o1
F00B7CC8: 9410001b                 mov     %i3, %o2
F00B7CCC: 9610001c                 mov     %i4, %o3
F00B7CD0: 9810001d                 mov     %i5, %o4
F00B7CD4: 7ffd7261                 call    _printf
F00B7CD8: 9a100014                 mov     %l4, %o5
F00B7CDC: 81c7e008                 ret
F00B7CE0: 81e80000                 restore
