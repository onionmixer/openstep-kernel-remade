F00435EC: 9de3bf60                 save    %sp, -0xA0, %sp
F00435F0: c037bfd6                 clrh    [%fp+var_2A]
F00435F4: 113c04bd                 sethi   %hi(word_F012F52C), %o0
F00435F8: d012212c                 lduh    [%o0+%lo(word_F012F52C)], %o0
F00435FC: 80a22000                 cmp     %o0, 0
F0043600: 1280000f                 bne     loc_F004363C
F0043604: a2102000                 mov     0, %l1
F0043608: 113c04bd90122136         set     unk_F012F536, %o0
F0043610: 96103fff                 mov     -1, %o3
F0043614: 9410200f                 mov     0xF, %o2
F0043618: 9210201e                 mov     0x1E, %o1
F004361C: d6324008                 sth     %o3, [%o1+%o0]
F0043620: 9482bfff                 inccc   -1, %o2
F0043624: 1cbffffe                 bpos    loc_F004361C
F0043628: 92027ffe                 inc     -2, %o1
F004362C: 133c04bd                 sethi   %hi(word_F012F52C), %o1
F0043630: d012612c                 lduh    [%o1+%lo(word_F012F52C)], %o0
F0043634: 90022001                 inc     %o0
F0043638: d032612c                 sth     %o0, [%o1+%lo(word_F012F52C)]
F004363C: 9007bfd8                 add     %fp, var_28, %o0
F0043640: 13000061                 sethi   0x18400, %o1
F0043644: d4060000                 ld      [%i0], %o2
F0043648: 921262a0                 bset    0x2A0, %o1
F004364C: d427bfd8                 st      %o2, [%fp+var_28]
F0043650: d6062004                 ld      [%i0+4], %o3
F0043654: 94102002                 mov     2, %o2
F0043658: d627bfdc                 st      %o3, [%fp+var_24]
F004365C: d8062008                 ld      [%i0+8], %o4
F0043660: 96102004                 mov     4, %o3
F0043664: d827bfe0                 st      %o4, [%fp+var_20]
F0043668: 193c04bd                 sethi   %hi(word_F012F52C), %o4
F004366C: da06200c                 ld      [%i0+0xC], %o5
F0043670: 9813212c                 bset    %lo(word_F012F52C), %o4
F0043674: da27bfe4                 st      %o5, [%fp+var_1C]
F0043678: 9a10206f                 mov     0x6F, %o5 ! 'o'
F004367C: 7ffffcd9                 call    _clntkudp_create
F0043680: da37bfda                 sth     %o5, [%fp+var_28+2]
F0043684: a0920000                 orcc    %o0, %g0, %l0
F0043688: 02800029                 be      locret_F004372C
F004368C: 92102003                 mov     3, %o1
F0043690: f227bfe8                 st      %i1, [%fp+var_18]
F0043694: f427bfec                 st      %i2, [%fp+var_14]
F0043698: f627bff0                 st      %i3, [%fp+var_10]
F004369C: c027bff4                 clr     [%fp+var_C]
F00436A0: 153c010e9412a01c         set     _xdr_pmap, %o2
F00436A8: 9607bfe8                 add     %fp, var_18, %o3
F00436AC: 1b3c0437                 sethi   %hi(dword_F010DD40), %o5
F00436B0: c4036140                 ld      [%o5+%lo(dword_F010DD40)], %g2
F00436B4: 193c0115                 sethi   %hi(_xdr_u_short), %o4
F00436B8: 9a136140                 bset    %lo(dword_F010DD40), %o5
F00436BC: da036004                 ld      [%o5+4], %o5
F00436C0: 981321d4                 bset    %lo(_xdr_u_short), %o4
F00436C4: c427bfc8                 st      %g2, [%fp+var_38]
F00436C8: da27bfcc                 st      %o5, [%fp+var_34]
F00436CC: c4042004                 ld      [%l0+4], %g2
F00436D0: 9a07bfc8                 add     %fp, var_38, %o5
F00436D4: da23a05c                 st      %o5, [%sp+0xA0+var_44]
F00436D8: c4008000                 ld      [%g2], %g2
F00436DC: 9fc08000                 call    %g2
F00436E0: 9a07bfd6                 add     %fp, var_2A, %o5
F00436E4: 80a22000                 cmp     %o0, 0
F00436E8: 22800004                 be,a    loc_F00436F8
F00436EC: d017bfd6                 lduh    [%fp+var_2A], %o0
F00436F0: 10800006                 ba      loc_F0043708
F00436F4: a2102001                 mov     1, %l1
F00436F8: 80a22000                 cmp     %o0, 0
F00436FC: 32800003                 bne,a   loc_F0043708
F0043700: d0362002                 sth     %o0, [%i0+2]
F0043704: a2103fff                 mov     -1, %l1
F0043708: d0040000                 ld      [%l0], %o0
F004370C: d2022020                 ld      [%o0+0x20], %o1
F0043710: d2026010                 ld      [%o1+0x10], %o1
F0043714: 9fc24000                 call    %o1
F0043718: 01000000                 nop
F004371C: d0042004                 ld      [%l0+4], %o0
F0043720: d2022010                 ld      [%o0+0x10], %o1
F0043724: 9fc24000                 call    %o1
F0043728: 90100010                 mov     %l0, %o0
F004372C: 81c7e008                 ret
F0043730: 91e80011                 restore %g0, %l1, %o0
