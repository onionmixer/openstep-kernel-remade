F003E4CC: 9de3bdf8                 save    %sp, -0x208, %sp! int
F003E4D0: a0100018                 mov     %i0, %l0
F003E4D4: d004200c                 ld      [%l0+0xC], %o0
F003E4D8: 808a2040                 btst    0x40, %o0 ! '@'
F003E4DC: 02800004                 be      loc_F003E4EC
F003E4E0: c027be64                 clr     [%fp+var_19C]
F003E4E4: 108000e4                 ba      locret_F003E874
F003E4E8: b0102000                 mov     0, %i0
F003E4EC: 9010001a                 mov     %i2, %o0! int
F003E4F0: 9207be70                 add     %fp, var_190, %o1! int
F003E4F4: 400166d9                 call    _copyin
F003E4F8: 94102034                 mov     0x34, %o2 ! '4'! int
F003E4FC: b0920000                 orcc    %o0, %g0, %i0
F003E500: 128000d6                 bne     loc_F003E858
F003E504: d007be70                 ld      [%fp+var_190], %o0! int
F003E508: b407bfc8                 add     %fp, var_38, %i2
F003E50C: 9210001a                 mov     %i2, %o1! int
F003E510: 400166d2                 call    _copyin
F003E514: 94102010                 mov     0x10, %o2! int
F003E518: b0920000                 orcc    %o0, %g0, %i0
F003E51C: 128000cf                 bne     loc_F003E858
F003E520: d057bfc8                 ldsh    [%fp+var_38], %o0
F003E524: 80a22002                 cmp     %o0, 2
F003E528: 128000cb                 bne     loc_F003E854
F003E52C: b010202e                 mov     0x2E, %i0 ! '.'
F003E530: d007be74                 ld      [%fp+var_18C], %o0! int
F003E534: 9207bfd8                 add     %fp, var_28, %o1! int
F003E538: 400166c8                 call    _copyin
F003E53C: 94102020                 mov     0x20, %o2 ! ' '
F003E540: b0920000                 orcc    %o0, %g0, %i0
F003E544: 128000c5                 bne     loc_F003E858
F003E548: d007be78                 ld      [%fp+var_188], %o0
F003E54C: 808a2020                 btst    0x20, %o0 ! ' '
F003E550: 0280000b                 be      loc_F003E57C
F003E554: d007be8c                 ld      [%fp+var_174], %o0
F003E558: 9207bfa8                 add     %fp, var_58, %o1
F003E55C: 94102020                 mov     0x20, %o2 ! ' '
F003E560: 400165f1                 call    _copyinstr
F003E564: 9607be6c                 add     %fp, var_194, %o3
F003E568: b0920000                 orcc    %o0, %g0, %i0
F003E56C: 128000bb                 bne     loc_F003E858
F003E570: 01000000                 nop
F003E574: 10800006                 ba      loc_F003E58C
F003E578: d207be78                 ld      [%fp+var_188], %o1
F003E57C: 9010001a                 mov     %i2, %o0
F003E580: 400001f0                 call    sub_F003ED40
F003E584: 9207bfa8                 add     %fp, var_58, %o1
F003E588: d207be78                 ld      [%fp+var_188], %o1
F003E58C: 11000004                 sethi   0x1000, %o0
F003E590: 808a4008                 btst    %o0, %o1
F003E594: 02800008                 be      loc_F003E5B4
F003E598: d007bea0                 ld      [%fp+var_160], %o0
F003E59C: 9207bea8                 add     %fp, var_158, %o1
F003E5A0: 94102100                 mov     0x100, %o2
F003E5A4: 400165e0                 call    _copyinstr
F003E5A8: 9607be68                 add     %fp, var_198, %o3
F003E5AC: 10800005                 ba      loc_F003E5C0
F003E5B0: 9007be64                 add     %fp, var_19C, %o0
F003E5B4: 90103fff                 mov     -1, %o0
F003E5B8: d027be68                 st      %o0, [%fp+var_198]
F003E5BC: 9007be64                 add     %fp, var_19C, %o0
F003E5C0: 92100010                 mov     %l0, %o1
F003E5C4: 9407bfc8                 add     %fp, var_38, %o2
F003E5C8: d607be68                 ld      [%fp+var_198], %o3
F003E5CC: 9a07bea8                 add     %fp, var_158, %o5
F003E5D0: d623a05c                 st      %o3, [%sp+0x208+var_1AC]
F003E5D4: d807be78                 ld      [%fp+var_188], %o4
F003E5D8: 9607bfd8                 add     %fp, var_28, %o3
F003E5DC: d823a060                 st      %o4, [%sp+0x208+var_1A8]
F003E5E0: 400000a7                 call    sub_F003E87C
F003E5E4: 9807bfa8                 add     %fp, var_58, %o4
F003E5E8: b0920000                 orcc    %o0, %g0, %i0
F003E5EC: 128000a2                 bne     locret_F003E874
F003E5F0: d007be64                 ld      [%fp+var_19C], %o0
F003E5F4: d0022024                 ld      [%o0+0x24], %o0
F003E5F8: f4022128                 ld      [%o0+0x128], %i2
F003E5FC: d206a014                 ld      [%i2+0x14], %o1
F003E600: 15020000                 sethi   0x8000000, %o2
F003E604: d007be78                 ld      [%fp+var_188], %o0
F003E608: 942a400a                 andn    %o1, %o2, %o2
F003E60C: 91322007                 srl     %o0, 7, %o0
F003E610: 900a2001                 and     %o0, 1, %o0
F003E614: 912a201b                 sll     %o0, 27, %o0
F003E618: 94128008                 bset    %o0, %o2
F003E61C: d426a014                 st      %o2, [%i2+0x14]
F003E620: 13010000                 sethi   0x4000000, %o1
F003E624: d007be78                 ld      [%fp+var_188], %o0
F003E628: 922a8009                 andn    %o2, %o1, %o1
F003E62C: 9132200d                 srl     %o0, 13, %o0
F003E630: 900a2001                 and     %o0, 1, %o0
F003E634: 912a201a                 sll     %o0, 26, %o0
F003E638: 92124008                 bset    %o0, %o1
F003E63C: d226a014                 st      %o1, [%i2+0x14]
F003E640: d007be78                 ld      [%fp+var_188], %o0
F003E644: 808a2010                 btst    0x10, %o0
F003E648: 02800007                 be      loc_F003E664
F003E64C: d007be88                 ld      [%fp+var_178], %o0
F003E650: d026a030                 st      %o0, [%i2+0x30]
F003E654: d007be88                 ld      [%fp+var_178], %o0
F003E658: 80a22000                 cmp     %o0, 0
F003E65C: 2680007e                 bl,a    loc_F003E854
F003E660: b0102016                 mov     0x16, %i0
F003E664: d007be78                 ld      [%fp+var_188], %o0
F003E668: 808a2008                 btst    8, %o0
F003E66C: 02800007                 be      loc_F003E688
F003E670: d007be84                 ld      [%fp+var_17C], %o0
F003E674: d026a02c                 st      %o0, [%i2+0x2C]
F003E678: d007be84                 ld      [%fp+var_17C], %o0
F003E67C: 80a22000                 cmp     %o0, 0
F003E680: 24800075                 ble,a   loc_F003E854
F003E684: b0102016                 mov     0x16, %i0
F003E688: d007be78                 ld      [%fp+var_188], %o0
F003E68C: 808a2004                 btst    4, %o0
F003E690: 0280000d                 be      loc_F003E6C4
F003E694: 808a2002                 btst    2, %o0
F003E698: d207be80                 ld      [%fp+var_180], %o1
F003E69C: 80a26000                 cmp     %o1, 0
F003E6A0: 2480006d                 ble,a   loc_F003E854
F003E6A4: b0102016                 mov     0x16, %i0
F003E6A8: d006a01c                 ld      [%i2+0x1C], %o0
F003E6AC: 80a20009                 cmp     %o0, %o1
F003E6B0: 34800002                 bg,a    loc_F003E6B8
F003E6B4: 90100009                 mov     %o1, %o0
F003E6B8: d026a01c                 st      %o0, [%i2+0x1C]
F003E6BC: d007be78                 ld      [%fp+var_188], %o0
F003E6C0: 808a2002                 btst    2, %o0
F003E6C4: 0280000d                 be      loc_F003E6F8
F003E6C8: d007be78                 ld      [%fp+var_188], %o0
F003E6CC: d207be7c                 ld      [%fp+var_184], %o1
F003E6D0: 80a26000                 cmp     %o1, 0
F003E6D4: 34800004                 bg,a    loc_F003E6E4
F003E6D8: d006a020                 ld      [%i2+0x20], %o0
F003E6DC: 1080005e                 ba      loc_F003E854
F003E6E0: b0102016                 mov     0x16, %i0
F003E6E4: 80a20009                 cmp     %o0, %o1
F003E6E8: 34800002                 bg,a    loc_F003E6F0
F003E6EC: 90100009                 mov     %o1, %o0
F003E6F0: d026a020                 st      %o0, [%i2+0x20]
F003E6F4: d007be78                 ld      [%fp+var_188], %o0
F003E6F8: 808a2100                 btst    0x100, %o0
F003E6FC: 02800012                 be      loc_F003E744
F003E700: d007be90                 ld      [%fp+var_170], %o0
F003E704: 80a22000                 cmp     %o0, 0
F003E708: 16800004                 bge     loc_F003E718
F003E70C: 01000000                 nop
F003E710: 1080000c                 ba      loc_F003E740
F003E714: 90102e10                 mov     0xE10, %o0
F003E718: 12800008                 bne     loc_F003E738
F003E71C: 01000000                 nop
F003E720: b0102016                 mov     0x16, %i0
F003E724: 113c0435                 sethi   %hi(aNfsMountAcregm), %o0! "nfs_mount: acregmin == 0\n"
F003E728: 7fff57cc                 call    _printf
F003E72C: 90122128                 bset    %lo(aNfsMountAcregm), %o0! "nfs_mount: acregmin == 0\n"
F003E730: 1080004a                 ba      loc_F003E858
F003E734: 80a62000                 cmp     %i0, 0
F003E738: 7fff5b71                 call    _min
F003E73C: 92102e10                 mov     0xE10, %o1
F003E740: d026a060                 st      %o0, [%i2+0x60]
F003E744: d007be78                 ld      [%fp+var_188], %o0
F003E748: 808a2200                 btst    0x200, %o0
F003E74C: 02800018                 be      loc_F003E7AC
F003E750: 808a2400                 btst    0x400, %o0
F003E754: d207be94                 ld      [%fp+var_16C], %o1
F003E758: 80a26000                 cmp     %o1, 0
F003E75C: 36800005                 bge,a   loc_F003E770
F003E760: d006a060                 ld      [%i2+0x60], %o0
F003E764: 11000023                 sethi   0x8C00, %o0
F003E768: 1080000e                 ba      loc_F003E7A0
F003E76C: 901220a0                 bset    0xA0, %o0
F003E770: 80a24008                 cmp     %o1, %o0
F003E774: 1a800007                 bcc     loc_F003E790
F003E778: 113c0435                 sethi   %hi(aNfsMountAcregm_0), %o0! "nfs_mount: acregmax < acregmin\n"
F003E77C: b0102016                 mov     0x16, %i0
F003E780: 7fff57b6                 call    _printf
F003E784: 90122148                 bset    %lo(aNfsMountAcregm_0), %o0! "nfs_mount: acregmax < acregmin\n"
F003E788: 10800034                 ba      loc_F003E858
F003E78C: 80a62000                 cmp     %i0, 0
F003E790: 90100009                 mov     %o1, %o0
F003E794: 13000023                 sethi   0x8C00, %o1
F003E798: 7fff5b59                 call    _min
F003E79C: 921260a0                 bset    0xA0, %o1
F003E7A0: d026a064                 st      %o0, [%i2+0x64]
F003E7A4: d007be78                 ld      [%fp+var_188], %o0
F003E7A8: 808a2400                 btst    0x400, %o0
F003E7AC: 02800012                 be      loc_F003E7F4
F003E7B0: d007be98                 ld      [%fp+var_168], %o0
F003E7B4: 80a22000                 cmp     %o0, 0
F003E7B8: 16800004                 bge     loc_F003E7C8
F003E7BC: 01000000                 nop
F003E7C0: 1080000c                 ba      loc_F003E7F0
F003E7C4: 90102e10                 mov     0xE10, %o0
F003E7C8: 12800008                 bne     loc_F003E7E8
F003E7CC: 01000000                 nop
F003E7D0: b0102016                 mov     0x16, %i0
F003E7D4: 113c0435                 sethi   %hi(aNfsMountAcdirm), %o0! "nfs_mount: acdirmin == 0\n"
F003E7D8: 7fff57a0                 call    _printf
F003E7DC: 90122168                 bset    %lo(aNfsMountAcdirm), %o0! "nfs_mount: acdirmin == 0\n"
F003E7E0: 1080001e                 ba      loc_F003E858
F003E7E4: 80a62000                 cmp     %i0, 0
F003E7E8: 7fff5b45                 call    _min
F003E7EC: 92102e10                 mov     0xE10, %o1
F003E7F0: d026a068                 st      %o0, [%i2+0x68]
F003E7F4: d007be78                 ld      [%fp+var_188], %o0
F003E7F8: 808a2800                 btst    0x800, %o0
F003E7FC: 02800017                 be      loc_F003E858
F003E800: 80a62000                 cmp     %i0, 0
F003E804: d207be9c                 ld      [%fp+var_164], %o1
F003E808: 80a26000                 cmp     %o1, 0
F003E80C: 36800005                 bge,a   loc_F003E820
F003E810: d006a068                 ld      [%i2+0x68], %o0
F003E814: 11000023                 sethi   0x8C00, %o0
F003E818: 1080000e                 ba      loc_F003E850
F003E81C: 901220a0                 bset    0xA0, %o0
F003E820: 80a24008                 cmp     %o1, %o0
F003E824: 1a800007                 bcc     loc_F003E840
F003E828: 113c0435                 sethi   %hi(aNfsMountAcdirm_0), %o0! "nfs_mount: acdirmax < acdirmin\n"
F003E82C: b0102016                 mov     0x16, %i0
F003E830: 7fff578a                 call    _printf
F003E834: 90122188                 bset    %lo(aNfsMountAcdirm_0), %o0! "nfs_mount: acdirmax < acdirmin\n"
F003E838: 10800008                 ba      loc_F003E858
F003E83C: 80a62000                 cmp     %i0, 0
F003E840: 90100009                 mov     %o1, %o0
F003E844: 13000023                 sethi   0x8C00, %o1
F003E848: 7fff5b2d                 call    _min
F003E84C: 921260a0                 bset    0xA0, %o1
F003E850: d026a06c                 st      %o0, [%i2+0x6C]
F003E854: 80a62000                 cmp     %i0, 0
F003E858: 02800007                 be      locret_F003E874
F003E85C: d007be64                 ld      [%fp+var_19C], %o0
F003E860: 80a22000                 cmp     %o0, 0
F003E864: 02800004                 be      locret_F003E874
F003E868: 01000000                 nop
F003E86C: 7fffa8be                 call    _vn_rele
F003E870: 01000000                 nop
F003E874: 81c7e008                 ret
F003E878: 81e80000                 restore
