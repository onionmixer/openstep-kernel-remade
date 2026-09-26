F0091C5C: 9de3bf90                 save    %sp, -0x70, %sp
F0091C60: d0062004                 ld      [%i0+4], %o0
F0091C64: 80a22028                 cmp     %o0, 0x28 ! '('
F0091C68: 1280001b                 bne     loc_F0091CD4
F0091C6C: 90103ed0                 mov     -0x130, %o0
F0091C70: d0060000                 ld      [%i0], %o0
F0091C74: 80a22000                 cmp     %o0, 0
F0091C78: 36800004                 bge,a   loc_F0091C88
F0091C7C: d0062018                 ld      [%i0+0x18], %o0
F0091C80: 10800015                 ba      loc_F0091CD4
F0091C84: 90103ed0                 mov     -0x130, %o0
F0091C88: 133c0448                 sethi   %hi(dword_F01122EC), %o1
F0091C8C: d20262ec                 ld      [%o1+%lo(dword_F01122EC)], %o1
F0091C90: 80a20009                 cmp     %o0, %o1
F0091C94: 12800010                 bne     loc_F0091CD4
F0091C98: 90103ed0                 mov     -0x130, %o0
F0091C9C: d0062020                 ld      [%i0+0x20], %o0
F0091CA0: 133c0448                 sethi   %hi(dword_F01122F0), %o1
F0091CA4: d20262f0                 ld      [%o1+%lo(dword_F01122F0)], %o1
F0091CA8: 80a20009                 cmp     %o0, %o1
F0091CAC: 22800004                 be,a    loc_F0091CBC
F0091CB0: d006201c                 ld      [%i0+0x1C], %o0
F0091CB4: 10800008                 ba      loc_F0091CD4
F0091CB8: 90103ed0                 mov     -0x130, %o0
F0091CBC: d027bff4                 st      %o0, [%fp+var_C]
F0091CC0: 7fff4d73                 call    _convert_port_to_host
F0091CC4: d0062008                 ld      [%i0+8], %o0
F0091CC8: d4062024                 ld      [%i0+0x24], %o2
F0091CCC: 7fff7304                 call    _kern_PMSetPowerState
F0091CD0: 9207bff4                 add     %fp, var_C, %o1
F0091CD4: d026601c                 st      %o0, [%i1+0x1C]
F0091CD8: 81c7e008                 ret
F0091CDC: 81e80000                 restore
