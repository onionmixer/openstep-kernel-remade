F008CD68: 9de3bf90                 save    %sp, -0x70, %sp
F008CD6C: 80a6a000                 cmp     %i2, 0
F008CD70: 0280000f                 be      loc_F008CDAC
F008CD74: 133c0506                 sethi   %hi(stru_F0141B9C.ext), %o1
F008CD78: f027bff0                 st      %i0, [%fp+var_10]
F008CD7C: d40263c8                 ld      [%o1+%lo(stru_F0141B9C.ext)], %o2
F008CD80: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CD84: 133c0504                 sethi   %hi(paInit), %o1
F008CD88: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008CD8C: 400192fc                 call    _objc_msgSendSuper
F008CD90: d427bff4                 st      %o2, [%fp+var_C]
F008CD94: f4262004                 st      %i2, [%i0+4]
F008CD98: f6262008                 st      %i3, [%i0+8]
F008CD9C: 90102001                 mov     1, %o0
F008CDA0: d026200c                 st      %o0, [%i0+0xC]
F008CDA4: 1080000a                 ba      locret_F008CDCC
F008CDA8: f82e2010                 stb     %i4, [%i0+0x10]
F008CDAC: f027bff0                 st      %i0, [%fp+var_10]
F008CDB0: d40263c8                 ld      [%o1+0x3C8], %o2
F008CDB4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CDB8: 133c0503                 sethi   %hi(paFree), %o1
F008CDBC: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008CDC0: 400192ef                 call    _objc_msgSendSuper
F008CDC4: d427bff4                 st      %o2, [%fp+var_C]
F008CDC8: b0100008                 mov     %o0, %i0
F008CDCC: 81c7e008                 ret
F008CDD0: 81e80000                 restore
