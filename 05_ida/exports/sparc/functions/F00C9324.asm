F00C9324: 9de3bf90                 save    %sp, -0x70, %sp
F00C9328: f027bff0                 st      %i0, [%fp+var_10]
F00C932C: 133c0507                 sethi   %hi(stru_F0141F5C.ext), %o1
F00C9330: d4026388                 ld      [%o1+%lo(stru_F0141F5C.ext)], %o2
F00C9334: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9338: 133c0504                 sethi   %hi(paInit), %o1
F00C933C: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C9340: 4000a18f                 call    _objc_msgSendSuper
F00C9344: d427bff4                 st      %o2, [%fp+var_C]
F00C9348: 90100018                 mov     %i0, %o0! id
F00C934C: 133c0506                 sethi   %hi(paSetdevicedescr), %o1
F00C9350: d2026104                 ld      [%o1+%lo(paSetdevicedescr)], %o1! SEL
F00C9354: 4000a147                 call    _objc_msgSend
F00C9358: 9410001a                 mov     %i2, %o2
F00C935C: 113c0506                 sethi   %hi(paInitsparc), %o0! id
F00C9360: d2022100                 ld      [%o0+%lo(paInitsparc)], %o1! SEL
F00C9364: 4000a143                 call    _objc_msgSend
F00C9368: 90100018                 mov     %i0, %o0
F00C936C: 7ffff2f1                 call    _IOMalloc
F00C9370: 90102008                 mov     8, %o0
F00C9374: d026211c                 st      %o0, [%i0+0x11C]
F00C9378: c0222004                 clr     [%o0+4]
F00C937C: c0220000                 clr     [%o0]
F00C9380: 81c7e008                 ret
F00C9384: 81e80000                 restore
