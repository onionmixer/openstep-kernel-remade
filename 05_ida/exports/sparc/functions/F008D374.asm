F008D374: 9de3bf90                 save    %sp, -0x70, %sp
F008D378: 80a6a000                 cmp     %i2, 0
F008D37C: 02800014                 be      loc_F008D3CC
F008D380: 133c0506                 sethi   %hi(stru_F0141B4C.ext), %o1
F008D384: f027bff0                 st      %i0, [%fp+var_10]
F008D388: d4026378                 ld      [%o1+%lo(stru_F0141B4C.ext)], %o2
F008D38C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D390: 133c0504                 sethi   %hi(paInit), %o1
F008D394: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008D398: 40019179                 call    _objc_msgSendSuper
F008D39C: d427bff4                 st      %o2, [%fp+var_C]
F008D3A0: f4262008                 st      %i2, [%i0+8]
F008D3A4: d006c000                 ld      [%i3], %o0
F008D3A8: d026200c                 st      %o0, [%i0+0xC]
F008D3AC: d206e004                 ld      [%i3+4], %o1
F008D3B0: 90020009                 add     %o0, %o1, %o0
F008D3B4: d0262010                 st      %o0, [%i0+0x10]
F008D3B8: 90102001                 mov     1, %o0
F008D3BC: d0262014                 st      %o0, [%i0+0x14]
F008D3C0: f82e2018                 stb     %i4, [%i0+0x18]
F008D3C4: 1080000a                 ba      locret_F008D3EC
F008D3C8: c026201c                 clr     [%i0+0x1C]
F008D3CC: f027bff0                 st      %i0, [%fp+var_10]
F008D3D0: d4026378                 ld      [%o1+0x378], %o2
F008D3D4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D3D8: 133c0503                 sethi   %hi(paFree), %o1
F008D3DC: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D3E0: 40019167                 call    _objc_msgSendSuper
F008D3E4: d427bff4                 st      %o2, [%fp+var_C]
F008D3E8: b0100008                 mov     %o0, %i0
F008D3EC: 81c7e008                 ret
F008D3F0: 81e80000                 restore
