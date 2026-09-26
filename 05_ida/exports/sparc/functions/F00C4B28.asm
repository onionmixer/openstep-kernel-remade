F00C4B28: 9de3bf90                 save    %sp, -0x70, %sp
F00C4B2C: d04e2058                 ldsb    [%i0+0x58], %o0
F00C4B30: 80a22000                 cmp     %o0, 0
F00C4B34: 0280000b                 be      loc_F00C4B60
F00C4B38: 92062008                 add     %i0, 8, %o1
F00C4B3C: 113c03ea90122048         set     aRegisteringSAt, %o0! "Registering: %s at %s\n"
F00C4B44: 4000056c                 call    _IOLog
F00C4B48: 94062058                 add     %i0, 0x58, %o2 ! 'X'
F00C4B4C: 30800009                 ba,a    loc_F00C4B70
F00C4B50: e0226004                 st      %l0, [%o1+4]
F00C4B54: d2242008                 st      %o1, [%l0+8]
F00C4B58: 1080001f                 ba      loc_F00C4BD4
F00C4B5C: d224200c                 st      %o1, [%l0+0xC]
F00C4B60: 113c03ea90122060         set     aRegisteringS, %o0! "Registering: %s\n"
F00C4B68: 40000563                 call    _IOLog
F00C4B6C: 92062008                 add     %i0, 8, %o1
F00C4B70: 400004f0                 call    _IOMalloc
F00C4B74: 90102010                 mov     0x10, %o0
F00C4B78: a0100008                 mov     %o0, %l0
F00C4B7C: 113c04cc                 sethi   %hi(dword_F013303C), %o0
F00C4B80: d002203c                 ld      [%o0+%lo(dword_F013303C)], %o0! id
F00C4B84: 133c0504                 sethi   %hi(paLock), %o1
F00C4B88: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C4B8C: 4000b339                 call    _objc_msgSend
F00C4B90: f0240000                 st      %i0, [%l0]
F00C4B94: 133c04cc                 sethi   %hi(dword_F0133030), %o1
F00C4B98: d4026030                 ld      [%o1+%lo(dword_F0133030)], %o2
F00C4B9C: 9002a001                 add     %o2, 1, %o0
F00C4BA0: d0226030                 st      %o0, [%o1+%lo(dword_F0133030)]
F00C4BA4: d4242004                 st      %o2, [%l0+4]
F00C4BA8: 153c04cc                 sethi   %hi(dword_F0133034), %o2
F00C4BAC: d002a034                 ld      [%o2+%lo(dword_F0133034)], %o0
F00C4BB0: 9212a034                 or      %o2, %lo(dword_F0133034), %o1
F00C4BB4: 80a20009                 cmp     %o0, %o1
F00C4BB8: 22bfffe6                 be,a    loc_F00C4B50
F00C4BBC: e022a034                 st      %l0, [%o2+%lo(dword_F0133034)]
F00C4BC0: d0026004                 ld      [%o1+4], %o0
F00C4BC4: d024200c                 st      %o0, [%l0+0xC]
F00C4BC8: d2242008                 st      %o1, [%l0+8]
F00C4BCC: e0226004                 st      %l0, [%o1+4]
F00C4BD0: e0222008                 st      %l0, [%o0+8]
F00C4BD4: 113c04cc                 sethi   %hi(dword_F013303C), %o0
F00C4BD8: d002203c                 ld      [%o0+%lo(dword_F013303C)], %o0! id
F00C4BDC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4BE0: 4000b324                 call    _objc_msgSend
F00C4BE4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C4BE8: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00C4BEC: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00C4BF0: 133c0506                 sethi   %hi(paConnecttoindir), %o1
F00C4BF4: d20261e8                 ld      [%o1+%lo(paConnecttoindir)], %o1! SEL
F00C4BF8: 4000b31e                 call    _objc_msgSend
F00C4BFC: 94100018                 mov     %i0, %o2
F00C4C00: 81c7e008                 ret
F00C4C04: 81e80000                 restore
