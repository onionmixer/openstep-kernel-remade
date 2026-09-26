F006AF04: 9de3bf90                 save    %sp, -0x70, %sp
F006AF08: d006600c                 ld      [%i1+0xC], %o0
F006AF0C: 80a22000                 cmp     %o0, 0
F006AF10: 12800005                 bne     loc_F006AF24
F006AF14: 113c04d0                 sethi   %hi(_active_threads), %o0
F006AF18: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F006AF1C: 1080000d                 ba      loc_F006AF50
F006AF20: d027bff4                 st      %o0, [%fp+var_C]
F006AF24: d0022260                 ld      [%o0+0x260], %o0
F006AF28: d002200c                 ld      [%o0+0xC], %o0! parent_task
F006AF2C: 40002476                 call    _thread_create
F006AF30: 9207bff4                 add     %fp, var_C, %o1
F006AF34: 80a22000                 cmp     %o0, 0
F006AF38: 02800004                 be      loc_F006AF48
F006AF3C: 01000000                 nop
F006AF40: 1080002a                 ba      locret_F006AFE8
F006AF44: b0102007                 mov     7, %i0
F006AF48: 40002519                 call    _thread_deallocate
F006AF4C: d007bff4                 ld      [%fp+var_C], %o0
F006AF50: a0062008                 add     %i0, 8, %l0
F006AF54: d4062004                 ld      [%i0+4], %o2
F006AF58: 92100010                 mov     %l0, %o1
F006AF5C: d007bff4                 ld      [%fp+var_C], %o0
F006AF60: 40000024                 call    sub_F006AFF0
F006AF64: 9402bff8                 inc     -8, %o2
F006AF68: 80a22000                 cmp     %o0, 0
F006AF6C: 3280001f                 bne,a   locret_F006AFE8
F006AF70: b0100008                 mov     %o0, %i0
F006AF74: d006600c                 ld      [%i1+0xC], %o0
F006AF78: 80a22000                 cmp     %o0, 0
F006AF7C: 12800015                 bne     loc_F006AFD0
F006AF80: 92100010                 mov     %l0, %o1
F006AF84: 96066008                 add     %i1, 8, %o3
F006AF88: d4062004                 ld      [%i0+4], %o2
F006AF8C: 233c04d0                 sethi   %hi(_active_threads), %l1
F006AF90: d0046260                 ld      [%l1+%lo(_active_threads)], %o0
F006AF94: 40000031                 call    sub_F006B058
F006AF98: 9402bff8                 inc     -8, %o2
F006AF9C: 80a22000                 cmp     %o0, 0
F006AFA0: 32800012                 bne,a   locret_F006AFE8
F006AFA4: b0100008                 mov     %o0, %i0
F006AFA8: 92100010                 mov     %l0, %o1
F006AFAC: d4062004                 ld      [%i0+4], %o2
F006AFB0: 96066004                 add     %i1, 4, %o3
F006AFB4: d0046260                 ld      [%l1+%lo(_active_threads)], %o0! target_act
F006AFB8: 40000043                 call    sub_F006B0C4
F006AFBC: 9402bff8                 inc     -8, %o2
F006AFC0: 80a22000                 cmp     %o0, 0
F006AFC4: 02800005                 be      loc_F006AFD8
F006AFC8: b0100008                 mov     %o0, %i0
F006AFCC: 30800007                 ba,a    locret_F006AFE8
F006AFD0: 40002972                 call    _thread_resume
F006AFD4: d007bff4                 ld      [%fp+var_C], %o0
F006AFD8: d006600c                 ld      [%i1+0xC], %o0
F006AFDC: b0102000                 mov     0, %i0
F006AFE0: 90022001                 inc     %o0
F006AFE4: d026600c                 st      %o0, [%i1+0xC]
F006AFE8: 81c7e008                 ret
F006AFEC: 81e80000                 restore
