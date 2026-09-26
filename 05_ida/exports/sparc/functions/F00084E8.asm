F00084E8: 9de3bfc0                 save    %sp, -0x40, %sp
F00084EC: 80a6a008                 cmp     %i2, 8
F00084F0: 268000cf                 bl,a    loc_F000882C
F00084F4: b0260019                 sub     %i0, %i1, %i0
F00084F8: 808e2003                 btst    3, %i0
F00084FC: 0280000f                 be      loc_F0008538
F0008500: b68e6003                 andcc   %i1, 3, %i3
F0008504: b4a6a001                 deccc   %i2
F0008508: 0c8000a9                 bneg    locret_F00087AC
F000850C: 01000000                 nop
F0008510: f84e0000                 ldsb    [%i0], %i4
F0008514: fa4e4000                 ldsb    [%i1], %i5
F0008518: b0062001                 inc     %i0
F000851C: 80a7001d                 cmp     %i4, %i5
F0008520: 128000bc                 bne     loc_F0008810
F0008524: b2066001                 inc     %i1
F0008528: 80970000                 tst     %i4
F000852C: 12bffff4                 bne     loc_F00084FC
F0008530: 808e2003                 btst    3, %i0
F0008534: 3080009e                 ba,a    locret_F00087AC
F0008538: 2d1fbfbfac15a2ff         set     0x7EFEFEFF, %l6
F0008540: 2f204040ae15e100         set     -0x7EFEFF00, %l7
F0008548: 213fc000                 sethi   -0x1000000, %l0
F000854C: 23003fc0                 sethi   0xFF0000, %l1
F0008550: a5346008                 srl     %l1, 8, %l2
F0008554: 02800079                 be      loc_F0008738
F0008558: 80a6e002                 cmp     %i3, 2
F000855C: 02800051                 be      loc_F00086A0
F0008560: 80a6e001                 cmp     %i3, 1
F0008564: fa0e4000                 ldub    [%i1], %i5
F0008568: b2066001                 inc     %i1
F000856C: 02800025                 be      loc_F0008600
F0008570: bb2f6018                 sll     %i5, 24, %i5
F0008574: b0260019                 sub     %i0, %i1, %i0
F0008578: b4a6a004                 deccc   4, %i2
F000857C: 16800006                 bge     loc_F0008594
F0008580: f6064000                 ld      [%i1], %i3
F0008584: b2266001                 dec     %i1
F0008588: b0062001                 inc     %i0
F000858C: 108000a8                 ba      loc_F000882C
F0008590: b406a004                 inc     4, %i2
F0008594: f8060019                 ld      [%i0+%i1], %i4
F0008598: b2066004                 inc     4, %i1
F000859C: a936e008                 srl     %i3, 8, %l4
F00085A0: ba15001d                 bset    %l4, %i5
F00085A4: 80a7001d                 cmp     %i4, %i5
F00085A8: 02800003                 be      loc_F00085B4
F00085AC: a6070016                 add     %i4, %l6, %l3
F00085B0: 30800081                 ba,a    loc_F00087B4
F00085B4: a61cc01c                 btog    %i4, %l3
F00085B8: a60cc017                 and     %l3, %l7, %l3
F00085BC: 80a4c017                 cmp     %l3, %l7
F00085C0: 22bfffee                 be,a    loc_F0008578
F00085C4: bb2ee018                 sll     %i3, 24, %i5
F00085C8: 808f0010                 btst    %l0, %i4
F00085CC: 3080007a                 ba,a    loc_F00087B4
F00085D0: 12800003                 bne     loc_F00085DC
F00085D4: 808f0011                 btst    %l1, %i4
F00085D8: 30800075                 ba,a    locret_F00087AC
F00085DC: 12800003                 bne     loc_F00085E8
F00085E0: 808f0012                 btst    %l2, %i4
F00085E4: 30800072                 ba,a    locret_F00087AC
F00085E8: 12800003                 bne     loc_F00085F4
F00085EC: 808f20ff                 btst    0xFF, %i4
F00085F0: 3080006f                 ba,a    locret_F00087AC
F00085F4: 12bfffe1                 bne     loc_F0008578
F00085F8: bb2ee018                 sll     %i3, 24, %i5
F00085FC: 3080006c                 ba,a    locret_F00087AC
F0008600: a8100000                 clr     %l4
F0008604: e8164000                 lduh    [%i1], %l4
F0008608: b2066002                 inc     2, %i1
F000860C: a92d2008                 sll     %l4, 8, %l4
F0008610: ba174014                 bset    %l4, %i5
F0008614: b0260019                 sub     %i0, %i1, %i0
F0008618: b4a6a004                 deccc   4, %i2
F000861C: 16800006                 bge     loc_F0008634
F0008620: f6064000                 ld      [%i1], %i3
F0008624: b2266003                 dec     3, %i1
F0008628: b0062003                 inc     3, %i0
F000862C: 10800080                 ba      loc_F000882C
F0008630: b406a004                 inc     4, %i2
F0008634: f8060019                 ld      [%i0+%i1], %i4
F0008638: b2066004                 inc     4, %i1
F000863C: a936e018                 srl     %i3, 24, %l4
F0008640: ba15001d                 bset    %l4, %i5
F0008644: 80a7001d                 cmp     %i4, %i5
F0008648: 02800003                 be      loc_F0008654
F000864C: a6070016                 add     %i4, %l6, %l3
F0008650: 30800059                 ba,a    loc_F00087B4
F0008654: a61cc01c                 btog    %i4, %l3
F0008658: a60cc017                 and     %l3, %l7, %l3
F000865C: 80a4c017                 cmp     %l3, %l7
F0008660: 22bfffee                 be,a    loc_F0008618
F0008664: bb2ee008                 sll     %i3, 8, %i5
F0008668: 808f0010                 btst    %l0, %i4
F000866C: 30800052                 ba,a    loc_F00087B4
F0008670: 12800003                 bne     loc_F000867C
F0008674: 808f0011                 btst    %l1, %i4
F0008678: 3080004d                 ba,a    locret_F00087AC
F000867C: 12800003                 bne     loc_F0008688
F0008680: 808f0012                 btst    %l2, %i4
F0008684: 3080004a                 ba,a    locret_F00087AC
F0008688: 12800003                 bne     loc_F0008694
F000868C: 808f20ff                 btst    0xFF, %i4
F0008690: 30800047                 ba,a    locret_F00087AC
F0008694: 12bfffe1                 bne     loc_F0008618
F0008698: bb2ee008                 sll     %i3, 8, %i5
F000869C: 30800044                 ba,a    locret_F00087AC
F00086A0: fa164000                 lduh    [%i1], %i5
F00086A4: b2066002                 inc     2, %i1
F00086A8: bb2f6010                 sll     %i5, 16, %i5
F00086AC: b0260019                 sub     %i0, %i1, %i0
F00086B0: b4a6a004                 deccc   4, %i2
F00086B4: 16800006                 bge     loc_F00086CC
F00086B8: f6064000                 ld      [%i1], %i3
F00086BC: b2266002                 dec     2, %i1
F00086C0: b0062002                 inc     2, %i0
F00086C4: 1080005a                 ba      loc_F000882C
F00086C8: b406a004                 inc     4, %i2
F00086CC: f8064018                 ld      [%i1+%i0], %i4
F00086D0: b2066004                 inc     4, %i1
F00086D4: a936e010                 srl     %i3, 16, %l4
F00086D8: ba15001d                 bset    %l4, %i5
F00086DC: 80a7001d                 cmp     %i4, %i5
F00086E0: 02800003                 be      loc_F00086EC
F00086E4: a6070016                 add     %i4, %l6, %l3
F00086E8: 30800033                 ba,a    loc_F00087B4
F00086EC: a61cc01c                 btog    %i4, %l3
F00086F0: a60cc017                 and     %l3, %l7, %l3
F00086F4: 80a4c017                 cmp     %l3, %l7
F00086F8: 22bfffee                 be,a    loc_F00086B0
F00086FC: bb2ee010                 sll     %i3, 16, %i5
F0008700: 808f0010                 btst    %l0, %i4
F0008704: 3080002c                 ba,a    loc_F00087B4
F0008708: 12800003                 bne     loc_F0008714
F000870C: 808f0011                 btst    %l1, %i4
F0008710: 30800027                 ba,a    locret_F00087AC
F0008714: 12800003                 bne     loc_F0008720
F0008718: 808f0012                 btst    %l2, %i4
F000871C: 30800024                 ba,a    locret_F00087AC
F0008720: 12800003                 bne     loc_F000872C
F0008724: 808f20ff                 btst    0xFF, %i4
F0008728: 30800021                 ba,a    locret_F00087AC
F000872C: 12bfffe1                 bne     loc_F00086B0
F0008730: bb2ee010                 sll     %i3, 16, %i5
F0008734: 3080001e                 ba,a    locret_F00087AC
F0008738: b0260019                 sub     %i0, %i1, %i0
F000873C: fa064000                 ld      [%i1], %i5
F0008740: b4a6a004                 deccc   4, %i2
F0008744: 2c80003a                 bneg,a  loc_F000882C
F0008748: b406a004                 inc     4, %i2
F000874C: f8064018                 ld      [%i1+%i0], %i4
F0008750: 80a7001d                 cmp     %i4, %i5
F0008754: b2066004                 inc     4, %i1
F0008758: 02800003                 be      loc_F0008764
F000875C: a6070016                 add     %i4, %l6, %l3
F0008760: 30800015                 ba,a    loc_F00087B4
F0008764: a61cc01c                 btog    %i4, %l3
F0008768: a60cc017                 and     %l3, %l7, %l3
F000876C: 80a4c017                 cmp     %l3, %l7
F0008770: 22bffff4                 be,a    loc_F0008740
F0008774: fa064000                 ld      [%i1], %i5
F0008778: 808f0010                 btst    %l0, %i4
F000877C: 3080000e                 ba,a    loc_F00087B4
F0008780: 12800003                 bne     loc_F000878C
F0008784: 808f0011                 btst    %l1, %i4
F0008788: 30800009                 ba,a    locret_F00087AC
F000878C: 12800003                 bne     loc_F0008798
F0008790: 808f0012                 btst    %l2, %i4
F0008794: 30800006                 ba,a    locret_F00087AC
F0008798: 12800003                 bne     loc_F00087A4
F000879C: 808f20ff                 btst    0xFF, %i4
F00087A0: 30800003                 ba,a    locret_F00087AC
F00087A4: 32bfffe7                 bne,a   loc_F0008740
F00087A8: fa064000                 ld      [%i1], %i5
F00087AC: 81c7e008                 ret
F00087B0: 91e80000                 restore %g0, %g0, %o0
F00087B4: a93f2018                 sra     %i4, 24, %l4
F00087B8: ab3f6018                 sra     %i5, 24, %l5
F00087BC: b0a50015                 subcc   %l4, %l5, %i0
F00087C0: 12800019                 bne     locret_F0008824
F00087C4: 808d20ff                 btst    0xFF, %l4
F00087C8: 02bffff9                 be      locret_F00087AC
F00087CC: a92f2008                 sll     %i4, 8, %l4
F00087D0: ab2f6008                 sll     %i5, 8, %l5
F00087D4: a93d2018                 sra     %l4, 24, %l4
F00087D8: ab3d6018                 sra     %l5, 24, %l5
F00087DC: b0a50015                 subcc   %l4, %l5, %i0
F00087E0: 12800011                 bne     locret_F0008824
F00087E4: 808d20ff                 btst    0xFF, %l4
F00087E8: 02bffff1                 be      locret_F00087AC
F00087EC: a92f2010                 sll     %i4, 16, %l4
F00087F0: ab2f6010                 sll     %i5, 16, %l5
F00087F4: a93d2018                 sra     %l4, 24, %l4
F00087F8: ab3d6018                 sra     %l5, 24, %l5
F00087FC: b0a50015                 subcc   %l4, %l5, %i0
F0008800: 12800009                 bne     locret_F0008824
F0008804: 808d20ff                 btst    0xFF, %l4
F0008808: 02bfffe9                 be      locret_F00087AC
F000880C: 01000000                 nop
F0008810: a92f2018                 sll     %i4, 24, %l4
F0008814: ab2f6018                 sll     %i5, 24, %l5
F0008818: a93d2018                 sra     %l4, 24, %l4
F000881C: ab3d6018                 sra     %l5, 24, %l5
F0008820: b0a50015                 subcc   %l4, %l5, %i0
F0008824: 81c7e008                 ret
F0008828: 91ee0000                 restore %i0, %g0, %o0
F000882C: b4a6a001                 deccc   %i2
F0008830: 0cbfffdf                 bneg    locret_F00087AC
F0008834: 01000000                 nop
F0008838: f84e4018                 ldsb    [%i1+%i0], %i4
F000883C: fa4e4000                 ldsb    [%i1], %i5
F0008840: b2066001                 inc     %i1
F0008844: 80a7001d                 cmp     %i4, %i5
F0008848: 12bffff2                 bne     loc_F0008810
F000884C: 80970000                 tst     %i4
F0008850: 12bffff8                 bne     loc_F0008830
F0008854: b4a6a001                 deccc   %i2
F0008858: 30bfffd5                 ba,a    locret_F00087AC
