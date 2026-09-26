F00D01AC: 9de3bf90                 save    %sp, -0x70, %sp
F00D01B0: d406a018                 ld      [%i2+0x18], %o2
F00D01B4: 80a2a000                 cmp     %o2, 0
F00D01B8: 0280000d                 be      loc_F00D01EC
F00D01BC: 113c0505                 sethi   %hi(paCompletetransf), %o0! id
F00D01C0: d2022378                 ld      [%o0+%lo(paCompletetransf)], %o1! SEL
F00D01C4: d606a028                 ld      [%i2+0x28], %o3
F00D01C8: d806a024                 ld      [%i2+0x24], %o4
F00D01CC: 400085a9                 call    _objc_msgSend
F00D01D0: 90100018                 mov     %i0, %o0
F00D01D4: 90100018                 mov     %i0, %o0! id
F00D01D8: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00D01DC: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00D01E0: 400085a4                 call    _objc_msgSend
F00D01E4: 9410001a                 mov     %i2, %o2
F00D01E8: 30800006                 ba,a    locret_F00D0200
F00D01EC: d006a01c                 ld      [%i2+0x1C], %o0! id
F00D01F0: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00D01F4: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00D01F8: 4000859e                 call    _objc_msgSend
F00D01FC: 94102001                 mov     1, %o2
F00D0200: 81c7e008                 ret
F00D0204: 81e80000                 restore
