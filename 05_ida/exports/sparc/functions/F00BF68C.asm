F00BF68C: 9de3bf90                 save    %sp, -0x70, %sp
F00BF690: d01e8000                 ldd     [%i2], %o0
F00BF694: d03e2158                 std     %o0, [%i0+0x158]
F00BF698: d006a008                 ld      [%i2+8], %o0
F00BF69C: 80a2207f                 cmp     %o0, 0x7F
F00BF6A0: 02800032                 be      locret_F00BF768
F00BF6A4: 80a22063                 cmp     %o0, 0x63 ! 'c'
F00BF6A8: 22800019                 be,a    loc_F00BF70C
F00BF6AC: 92102002                 mov     2, %o1
F00BF6B0: 18800008                 bgu     loc_F00BF6D0
F00BF6B4: 80a22013                 cmp     %o0, 0x13
F00BF6B8: 02800014                 be      loc_F00BF708
F00BF6BC: 80a2204c                 cmp     %o0, 0x4C ! 'L'
F00BF6C0: 02800013                 be      loc_F00BF70C
F00BF6C4: 92102001                 mov     1, %o1
F00BF6C8: 10800011                 ba      loc_F00BF70C
F00BF6CC: 92102000                 mov     0, %o1
F00BF6D0: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00BF6D4: 0280000e                 be      loc_F00BF70C
F00BF6D8: 92102008                 mov     8, %o1
F00BF6DC: 18800006                 bgu     loc_F00BF6F4
F00BF6E0: 80a2206e                 cmp     %o0, 0x6E ! 'n'
F00BF6E4: 0280000a                 be      loc_F00BF70C
F00BF6E8: 92102004                 mov     4, %o1
F00BF6EC: 10800008                 ba      loc_F00BF70C
F00BF6F0: 92102000                 mov     0, %o1
F00BF6F4: 80a2207a                 cmp     %o0, 0x7A ! 'z'
F00BF6F8: 02800005                 be      loc_F00BF70C
F00BF6FC: 92102010                 mov     0x10, %o1
F00BF700: 10800003                 ba      loc_F00BF70C
F00BF704: 92102000                 mov     0, %o1
F00BF708: 92102020                 mov     0x20, %o1 ! ' '
F00BF70C: d04ea00c                 ldsb    [%i2+0xC], %o0
F00BF710: 80a22000                 cmp     %o0, 0
F00BF714: 02800004                 be      loc_F00BF724
F00BF718: d0062148                 ld      [%i0+0x148], %o0
F00BF71C: 10800003                 ba      loc_F00BF728
F00BF720: 90120009                 bset    %o1, %o0
F00BF724: 902a0009                 bclr    %o1, %o0
F00BF728: d0262148                 st      %o0, [%i0+0x148]
F00BF72C: d0062124                 ld      [%i0+0x124], %o0! id
F00BF730: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BF734: 4000c84f                 call    _objc_msgSend
F00BF738: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BF73C: d0062128                 ld      [%i0+0x128], %o0! id
F00BF740: 133c0504                 sethi   %hi(paDokeyboardeven), %o1
F00BF744: d202628c                 ld      [%o1+%lo(paDokeyboardeven)], %o1! SEL
F00BF748: d406a008                 ld      [%i2+8], %o2
F00BF74C: d64ea00c                 ldsb    [%i2+0xC], %o3
F00BF750: 4000c848                 call    _objc_msgSend
F00BF754: 98062134                 add     %i0, 0x134, %o4
F00BF758: d0062124                 ld      [%i0+0x124], %o0! id
F00BF75C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BF760: 4000c844                 call    _objc_msgSend
F00BF764: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BF768: 81c7e008                 ret
F00BF76C: 81e80000                 restore
