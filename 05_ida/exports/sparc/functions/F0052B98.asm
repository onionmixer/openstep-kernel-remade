F0052B98: 9de3bf88                 save    %sp, -0x78, %sp
F0052B9C: 9007bff4                 add     %fp, var_C, %o0
F0052BA0: 92100019                 mov     %i1, %o1
F0052BA4: 94102000                 mov     0, %o2
F0052BA8: 96102000                 mov     0, %o3
F0052BAC: 98102000                 mov     0, %o4
F0052BB0: e0062030                 ld      [%i0+0x30], %l0
F0052BB4: 9a10001a                 mov     %i2, %o5
F0052BB8: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F0052BBC: 7fffe256                 call    _direnter
F0052BC0: 90100010                 mov     %l0, %o0
F0052BC4: d2142044                 lduh    [%l0+0x44], %o1
F0052BC8: 808a6046                 btst    0x46, %o1 ! 'F'
F0052BCC: 0280001d                 be      loc_F0052C40
F0052BD0: b0100008                 mov     %o0, %i0
F0052BD4: 90126008                 or      %o1, 8, %o0
F0052BD8: d0342044                 sth     %o0, [%l0+0x44]
F0052BDC: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052BE0: 40006e7c                 call    _microtime
F0052BE4: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052BE8: d0142044                 lduh    [%l0+0x44], %o0
F0052BEC: 808a2004                 btst    4, %o0
F0052BF0: 02800003                 be      loc_F0052BFC
F0052BF4: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052BF8: d0242074                 st      %o0, [%l0+0x74]
F0052BFC: d0142044                 lduh    [%l0+0x44], %o0
F0052C00: 808a2002                 btst    2, %o0
F0052C04: 02800003                 be      loc_F0052C10
F0052C08: d0066148                 ld      [%i1+0x148], %o0
F0052C0C: d024207c                 st      %o0, [%l0+0x7C]
F0052C10: d0142044                 lduh    [%l0+0x44], %o0
F0052C14: 808a2040                 btst    0x40, %o0 ! '@'
F0052C18: 22800006                 be,a    loc_F0052C30
F0052C1C: d2142044                 lduh    [%l0+0x44], %o1
F0052C20: c024204c                 clr     [%l0+0x4C]
F0052C24: d0066148                 ld      [%i1+0x148], %o0
F0052C28: d0242084                 st      %o0, [%l0+0x84]
F0052C2C: d2142044                 lduh    [%l0+0x44], %o1
F0052C30: 1100003f901223b9         set     0xFFB9, %o0
F0052C38: 920a4008                 and     %o1, %o0, %o1
F0052C3C: d2342044                 sth     %o1, [%l0+0x44]
F0052C40: 80a62000                 cmp     %i0, 0
F0052C44: 12800026                 bne     loc_F0052CDC
F0052C48: 80a62011                 cmp     %i0, 0x11
F0052C4C: e007bff4                 ld      [%fp+var_C], %l0
F0052C50: 9004200c                 add     %l0, 0xC, %o0
F0052C54: d026c000                 st      %o0, [%i3]
F0052C58: d0142044                 lduh    [%l0+0x44], %o0
F0052C5C: 808a2046                 btst    0x46, %o0 ! 'F'
F0052C60: 0280001c                 be      loc_F0052CD0
F0052C64: 90122008                 bset    8, %o0
F0052C68: d0342044                 sth     %o0, [%l0+0x44]
F0052C6C: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052C70: 40006e58                 call    _microtime
F0052C74: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052C78: d0142044                 lduh    [%l0+0x44], %o0
F0052C7C: 808a2004                 btst    4, %o0
F0052C80: 02800003                 be      loc_F0052C8C
F0052C84: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052C88: d0242074                 st      %o0, [%l0+0x74]
F0052C8C: d0142044                 lduh    [%l0+0x44], %o0
F0052C90: 808a2002                 btst    2, %o0
F0052C94: 02800003                 be      loc_F0052CA0
F0052C98: d0066148                 ld      [%i1+0x148], %o0
F0052C9C: d024207c                 st      %o0, [%l0+0x7C]
F0052CA0: d0142044                 lduh    [%l0+0x44], %o0
F0052CA4: 808a2040                 btst    0x40, %o0 ! '@'
F0052CA8: 22800006                 be,a    loc_F0052CC0
F0052CAC: d2142044                 lduh    [%l0+0x44], %o1
F0052CB0: c024204c                 clr     [%l0+0x4C]
F0052CB4: d0066148                 ld      [%i1+0x148], %o0
F0052CB8: d0242084                 st      %o0, [%l0+0x84]
F0052CBC: d2142044                 lduh    [%l0+0x44], %o1
F0052CC0: 1100003f901223b9         set     0xFFB9, %o0
F0052CC8: 920a4008                 and     %o1, %o0, %o1
F0052CCC: d2342044                 sth     %o1, [%l0+0x44]
F0052CD0: 7ffff0fe                 call    _iunlock
F0052CD4: 90100010                 mov     %l0, %o0
F0052CD8: 30800005                 ba,a    locret_F0052CEC
F0052CDC: 12800004                 bne     locret_F0052CEC
F0052CE0: 01000000                 nop
F0052CE4: 7fffed2d                 call    _iput
F0052CE8: d007bff4                 ld      [%fp+var_C], %o0
F0052CEC: 81c7e008                 ret
F0052CF0: 81e80000                 restore
