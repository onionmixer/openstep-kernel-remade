F0045760: 9de3bf98                 save    %sp, -0x68, %sp
F0045764: 80a6a000                 cmp     %i2, 0
F0045768: 02800039                 be      loc_F004584C
F004576C: 92100019                 mov     %i1, %o1
F0045770: a08ea003                 andcc   %i2, 3, %l0
F0045774: 02800003                 be      loc_F0045780
F0045778: 90102004                 mov     4, %o0
F004577C: a0220010                 sub     %o0, %l0, %l0
F0045780: d0060000                 ld      [%i0], %o0
F0045784: 80a22001                 cmp     %o0, 1
F0045788: 12800014                 bne     loc_F00457D8
F004578C: 80a22000                 cmp     %o0, 0
F0045790: d4062004                 ld      [%i0+4], %o2
F0045794: d602a008                 ld      [%o2+8], %o3
F0045798: 90100018                 mov     %i0, %o0
F004579C: 9fc2c000                 call    %o3
F00457A0: 9410001a                 mov     %i2, %o2
F00457A4: 80a22000                 cmp     %o0, 0
F00457A8: 12800005                 bne     loc_F00457BC
F00457AC: 80a42000                 cmp     %l0, 0
F00457B0: 113c0437                 sethi   %hi(aXdrOpaqueDecod), %o0! "xdr_opaque: decode FAILED\n"
F00457B4: 10800023                 ba      loc_F0045840
F00457B8: 90122348                 bset    %lo(aXdrOpaqueDecod), %o0! "xdr_opaque: decode FAILED\n"
F00457BC: 02800024                 be      loc_F004584C
F00457C0: 90100018                 mov     %i0, %o0
F00457C4: d4022004                 ld      [%o0+4], %o2
F00457C8: 133c04bd                 sethi   %hi(unk_F012F55C), %o1
F00457CC: d602a008                 ld      [%o2+8], %o3
F00457D0: 10800015                 ba      loc_F0045824
F00457D4: 9212615c                 bset    %lo(unk_F012F55C), %o1
F00457D8: 12800017                 bne     loc_F0045834
F00457DC: 80a22002                 cmp     %o0, 2
F00457E0: d4062004                 ld      [%i0+4], %o2
F00457E4: d602a00c                 ld      [%o2+0xC], %o3
F00457E8: 90100018                 mov     %i0, %o0
F00457EC: 9fc2c000                 call    %o3
F00457F0: 9410001a                 mov     %i2, %o2
F00457F4: 80a22000                 cmp     %o0, 0
F00457F8: 12800005                 bne     loc_F004580C
F00457FC: 80a42000                 cmp     %l0, 0
F0045800: 113c0437                 sethi   %hi(aXdrOpaqueEncod), %o0! "xdr_opaque: encode FAILED\n"
F0045804: 1080000f                 ba      loc_F0045840
F0045808: 90122368                 bset    %lo(aXdrOpaqueEncod), %o0! "xdr_opaque: encode FAILED\n"
F004580C: 02800010                 be      loc_F004584C
F0045810: 90100018                 mov     %i0, %o0
F0045814: d4022004                 ld      [%o0+4], %o2
F0045818: 133c0437                 sethi   %hi(unk_F010DE90), %o1
F004581C: d602a00c                 ld      [%o2+0xC], %o3
F0045820: 92126290                 bset    %lo(unk_F010DE90), %o1
F0045824: 9fc2c000                 call    %o3
F0045828: 94100010                 mov     %l0, %o2
F004582C: 10800009                 ba      locret_F0045850
F0045830: b0100008                 mov     %o0, %i0
F0045834: 02800006                 be      loc_F004584C
F0045838: 113c0437                 sethi   %hi(aXdrOpaqueBadOp), %o0! "xdr_opaque: bad op FAILED\n"
F004583C: 90122388                 bset    %lo(aXdrOpaqueBadOp), %o0! "xdr_opaque: bad op FAILED\n"
F0045840: 7fff3b86                 call    _printf
F0045844: b0102000                 mov     0, %i0
F0045848: 30800002                 ba,a    locret_F0045850
F004584C: b0102001                 mov     1, %i0
F0045850: 81c7e008                 ret
F0045854: 81e80000                 restore
