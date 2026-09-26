F00D3588: 9de3bf90                 save    %sp, -0x70, %sp
F00D358C: d0062214                 ld      [%i0+0x214], %o0! id
F00D3590: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D3594: 400078b7                 call    _objc_msgSend
F00D3598: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D359C: d04e2212                 ldsb    [%i0+0x212], %o0
F00D35A0: 80a22001                 cmp     %o0, 1
F00D35A4: 02800010                 be      loc_F00D35E4
F00D35A8: 94102001                 mov     1, %o2
F00D35AC: 133c0504                 sethi   %hi(paUnlock), %o1
F00D35B0: d0062214                 ld      [%i0+0x214], %o0! id
F00D35B4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D35B8: 400078ae                 call    _objc_msgSend
F00D35BC: d42e2212                 stb     %o2, [%i0+0x212]
F00D35C0: 90100018                 mov     %i0, %o0! id
F00D35C4: 133c0505                 sethi   %hi(paSendiothreadas), %o1
F00D35C8: 153c0505                 sethi   %hi(paPerformkickeve), %o2
F00D35CC: d20262fc                 ld      [%o1+%lo(paSendiothreadas)], %o1! SEL
F00D35D0: 96100018                 mov     %i0, %o3
F00D35D4: d402a2d8                 ld      [%o2+%lo(paPerformkickeve)], %o2
F00D35D8: 400078a6                 call    _objc_msgSend
F00D35DC: 98102000                 mov     0, %o4
F00D35E0: 30800005                 ba,a    locret_F00D35F4
F00D35E4: d0062214                 ld      [%i0+0x214], %o0! id
F00D35E8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D35EC: 400078a1                 call    _objc_msgSend
F00D35F0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D35F4: 81c7e008                 ret
F00D35F8: 81e80000                 restore
