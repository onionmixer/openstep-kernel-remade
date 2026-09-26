F00A6108: 9de3bf98                 save    %sp, -0x68, %sp
F00A610C: 113fbfe0                 sethi   -0x1008000, %o0
F00A6110: d2020000                 ld      [%o0], %o1
F00A6114: 11100000                 sethi   0x40000000, %o0
F00A6118: 808a4008                 btst    %o0, %o1
F00A611C: 12800006                 bne     loc_F00A6134
F00A6120: 133c0466                 sethi   -0xFEE6800, %o1
F00A6124: 113c0466                 sethi   %hi(aUnknownLevel15), %o0! "unknown level-15 interrupt"
F00A6128: 7ffdbc12                 call    _panic
F00A612C: 90122398                 bset    %lo(aUnknownLevel15), %o0! "unknown level-15 interrupt"
F00A6130: 133c0466                 sethi   -0xFEE6800, %o1
F00A6134: d0026148                 ld      [%o1+0x148], %o0
F00A6138: 80a23fff                 cmp     %o0, -1
F00A613C: 32800005                 bne,a   loc_F00A6150
F00A6140: 133fbfa8                 sethi   -0x1016000, %o1
F00A6144: 90102001                 mov     1, %o0
F00A6148: 1080001e                 ba      locret_F00A61C0
F00A614C: d0226148                 st      %o0, [%o1+0x148]
F00A6150: 113fbfa8                 sethi   -0x1016000, %o0
F00A6154: d6022050                 ld      [%o0+0x50], %o3
F00A6158: 21200000                 sethi   0x80000000, %l0
F00A615C: 808ac010                 btst    %l0, %o3
F00A6160: 02800009                 be      loc_F00A6184
F00A6164: d4026054                 ld      [%o1+0x54], %o2
F00A6168: 113c0466901223b8         set     aAsyncMemoryFau, %o0! "Async memory fault mfsr=0x%x mfar=0x%x"...
F00A6170: 7ffdb93a                 call    _printf
F00A6174: 9210000b                 mov     %o3, %o1
F00A6178: 113c0466                 sethi   %hi(aAsyncMemoryFau_0), %o0! "async memory fault"
F00A617C: 7ffdbbfd                 call    _panic
F00A6180: 901223e0                 bset    %lo(aAsyncMemoryFau_0), %o0! "async memory fault"
F00A6184: 113fbfa8                 sethi   -0x1016000, %o0
F00A6188: d2020000                 ld      [%o0], %o1
F00A618C: 113fbfa8                 sethi   -0x1016000, %o0
F00A6190: 808a4010                 btst    %l0, %o1
F00A6194: 02800008                 be      loc_F00A61B4
F00A6198: d4022004                 ld      [%o0+4], %o2
F00A619C: 113c0466                 sethi   %hi(aAsyncFaultAfsr), %o0! "Async fault afsr=0x%x afar=0x%x\n"
F00A61A0: 7ffdb92e                 call    _printf
F00A61A4: 901223f8                 bset    %lo(aAsyncFaultAfsr), %o0! "Async fault afsr=0x%x afar=0x%x\n"
F00A61A8: 113c0467                 sethi   %hi(aAsyncHardwareF), %o0! "async hardware fault"
F00A61AC: 7ffdbbf1                 call    _panic
F00A61B0: 90122020                 bset    %lo(aAsyncHardwareF), %o0! "async hardware fault"
F00A61B4: 113c0467                 sethi   %hi(aUnknownAsyncFa), %o0! "unknown async fault"
F00A61B8: 7ffdbbee                 call    _panic
F00A61BC: 90122038                 bset    %lo(aUnknownAsyncFa), %o0! "unknown async fault"
F00A61C0: 81c7e008                 ret
F00A61C4: 81e80000                 restore
