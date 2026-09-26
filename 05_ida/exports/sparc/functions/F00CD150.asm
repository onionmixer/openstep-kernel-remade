F00CD150: 9de3bf90                 save    %sp, -0x70, %sp
F00CD154: d2062128                 ld      [%i0+0x128], %o1
F00CD158: 80a26000                 cmp     %o1, 0
F00CD15C: 0280001d                 be      loc_F00CD1D0
F00CD160: 113c0506                 sethi   -0xFEBE800, %o0
F00CD164: 90062128                 add     %i0, 0x128, %o0
F00CD168: 80a20009                 cmp     %o0, %o1
F00CD16C: 22800019                 be,a    loc_F00CD1D0
F00CD170: 113c0506                 sethi   -0xFEBE800, %o0
F00CD174: a0100008                 mov     %o0, %l0
F00CD178: d0062128                 ld      [%i0+0x128], %o0
F00CD17C: d6022014                 ld      [%o0+0x14], %o3
F00CD180: 80a4000b                 cmp     %l0, %o3
F00CD184: 12800004                 bne     loc_F00CD194
F00CD188: d4022018                 ld      [%o0+0x18], %o2
F00CD18C: 10800003                 ba      loc_F00CD198
F00CD190: 92100010                 mov     %l0, %o1
F00CD194: 9202e014                 add     %o3, 0x14, %o1
F00CD198: 80a4000a                 cmp     %l0, %o2
F00CD19C: 12800004                 bne     loc_F00CD1AC
F00CD1A0: d4226004                 st      %o2, [%o1+4]
F00CD1A4: 10800003                 ba      loc_F00CD1B0
F00CD1A8: 92100010                 mov     %l0, %o1
F00CD1AC: 9202a014                 add     %o2, 0x14, %o1
F00CD1B0: d6224000                 st      %o3, [%o1]
F00CD1B4: 7fffe364                 call    _IOFree
F00CD1B8: 92102020                 mov     0x20, %o1 ! ' '
F00CD1BC: d0062128                 ld      [%i0+0x128], %o0
F00CD1C0: 80a40008                 cmp     %l0, %o0
F00CD1C4: 32bfffef                 bne,a   loc_F00CD180
F00CD1C8: d6022014                 ld      [%o0+0x14], %o3
F00CD1CC: 113c0506                 sethi   -0xFEBE800, %o0! id
F00CD1D0: d2022138                 ld      [%o0+0x138], %o1! SEL
F00CD1D4: 400091a7                 call    _objc_msgSend
F00CD1D8: 90100018                 mov     %i0, %o0
F00CD1DC: 153c04bb                 sethi   %hi(dword_F012ECE8), %o2
F00CD1E0: d202a0e8                 ld      [%o2+%lo(dword_F012ECE8)], %o1
F00CD1E4: 92027fff                 inc     -1, %o1
F00CD1E8: 80a20009                 cmp     %o0, %o1
F00CD1EC: 22800002                 be,a    loc_F00CD1F4
F00CD1F0: d022a0e8                 st      %o0, [%o2+%lo(dword_F012ECE8)]
F00CD1F4: f027bff0                 st      %i0, [%fp+var_10]
F00CD1F8: 133c0508                 sethi   %hi(stru_F014213C.super_class), %o1
F00CD1FC: d4026140                 ld      [%o1+%lo(stru_F014213C.super_class)], %o2
F00CD200: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CD204: 133c0503                 sethi   %hi(paFree), %o1
F00CD208: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CD20C: 400091dc                 call    _objc_msgSendSuper
F00CD210: d427bff4                 st      %o2, [%fp+var_C]
F00CD214: 81c7e008                 ret
F00CD218: 91e80008                 restore %g0, %o0, %o0
