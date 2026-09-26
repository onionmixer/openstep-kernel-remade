F00CE744: 9de3bf90                 save    %sp, -0x70, %sp
F00CE748: 90100018                 mov     %i0, %o0! id
F00CE74C: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CE750: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CE754: 40008c47                 call    _objc_msgSend
F00CE758: 94102000                 mov     0, %o2
F00CE75C: a2100008                 mov     %o0, %l1
F00CE760: 90102007                 mov     7, %o0
F00CE764: d0244000                 st      %o0, [%l1]
F00CE768: d2046020                 ld      [%l1+0x20], %o1
F00CE76C: 11200000                 sethi   0x80000000, %o0
F00CE770: 902a4008                 andn    %o1, %o0, %o0
F00CE774: d0246020                 st      %o0, [%l1+0x20]
F00CE778: d006218c                 ld      [%i0+0x18C], %o0
F00CE77C: a0102000                 mov     0, %l0
F00CE780: 80a40008                 cmp     %l0, %o0
F00CE784: 1680000b                 bge     loc_F00CE7B0
F00CE788: 90100018                 mov     %i0, %o0! id
F00CE78C: 253c0505                 sethi   -0xFEBEC00, %l2
F00CE790: d204a3d0                 ld      [%l2+0x3D0], %o1! SEL
F00CE794: 40008c37                 call    _objc_msgSend
F00CE798: 94100011                 mov     %l1, %o2
F00CE79C: d006218c                 ld      [%i0+0x18C], %o0
F00CE7A0: a0042001                 inc     %l0
F00CE7A4: 80a40008                 cmp     %l0, %o0
F00CE7A8: 06bffffa                 bl      loc_F00CE790
F00CE7AC: 90100018                 mov     %i0, %o0! id
F00CE7B0: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CE7B4: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CE7B8: 40008c2e                 call    _objc_msgSend
F00CE7BC: 94100011                 mov     %l1, %o2
F00CE7C0: d2062188                 ld      [%i0+0x188], %o1
F00CE7C4: 11000020                 sethi   0x8000, %o0
F00CE7C8: 808a4008                 btst    %o0, %o1
F00CE7CC: 02800008                 be      loc_F00CE7EC
F00CE7D0: 133c0505                 sethi   %hi(paReleasetargetL), %o1
F00CE7D4: d0062184                 ld      [%i0+0x184], %o0! id
F00CE7D8: d20263dc                 ld      [%o1+%lo(paReleasetargetL)], %o1! SEL
F00CE7DC: d40e2188                 ldub    [%i0+0x188], %o2
F00CE7E0: d60e2189                 ldub    [%i0+0x189], %o3
F00CE7E4: 40008c23                 call    _objc_msgSend
F00CE7E8: 98100018                 mov     %i0, %o4
F00CE7EC: 113c0503                 sethi   %hi(paFree), %o0
F00CE7F0: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00CE7F4: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CE7F8: 40008c1e                 call    _objc_msgSend
F00CE7FC: 92100010                 mov     %l0, %o1! SEL
F00CE800: f027bff0                 st      %i0, [%fp+var_10]
F00CE804: 113c03ec                 sethi   %hi(aIodisk), %o0! "IODisk"
F00CE808: 40008395                 call    _objc_getOrigClass
F00CE80C: 90122398                 bset    %lo(aIodisk), %o0! "IODisk"
F00CE810: d027bff4                 st      %o0, [%fp+var_C]
F00CE814: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CE818: 40008c59                 call    _objc_msgSendSuper
F00CE81C: 92100010                 mov     %l0, %o1
F00CE820: 81c7e008                 ret
F00CE824: 91e80008                 restore %g0, %o0, %o0
