F0007528: 9de3bfc0                 save    %sp, -0x40, %sp
F000752C: b68e6003                 andcc   %i1, 3, %i3
F0007530: 0280001c                 be      loc_F00075A0
F0007534: b4100018                 mov     %i0, %i2
F0007538: 80a6e002                 cmp     %i3, 2
F000753C: 0280000a                 be      loc_F0007564
F0007540: 80a6e003                 cmp     %i3, 3
F0007544: f60e4000                 ldub    [%i1], %i3
F0007548: b2066001                 inc     %i1
F000754C: f62e0000                 stb     %i3, [%i0]
F0007550: 02800011                 be      loc_F0007594
F0007554: 8096c000                 tst     %i3
F0007558: 12800003                 bne     loc_F0007564
F000755C: b0062001                 inc     %i0
F0007560: 308000d8                 ba,a    locret_F00078C0
F0007564: f6164000                 lduh    [%i1], %i3
F0007568: b2066002                 inc     2, %i1
F000756C: b936e008                 srl     %i3, 8, %i4
F0007570: 80970000                 tst     %i4
F0007574: f82e0000                 stb     %i4, [%i0]
F0007578: 32800003                 bne,a   loc_F0007584
F000757C: f62e2001                 stb     %i3, [%i0+1]
F0007580: 308000d0                 ba,a    locret_F00078C0
F0007584: b68ee0ff                 andcc   %i3, 0xFF, %i3
F0007588: 12800006                 bne     loc_F00075A0
F000758C: b0062002                 inc     2, %i0
F0007590: 308000cc                 ba,a    locret_F00078C0
F0007594: 12800003                 bne     loc_F00075A0
F0007598: b0062001                 inc     %i0
F000759C: 308000c9                 ba,a    locret_F00078C0
F00075A0: 211fbfbfa01422ff         set     0x7EFEFEFF, %l0
F00075A8: 23204040a2146100         set     -0x7EFEFF00, %l1
F00075B0: 253fc000                 sethi   -0x1000000, %l2
F00075B4: 27003fc0                 sethi   0xFF0000, %l3
F00075B8: b68e2003                 andcc   %i0, 3, %i3
F00075BC: 028000ac                 be      loc_F000786C
F00075C0: a934e008                 srl     %l3, 8, %l4
F00075C4: 80a6e002                 cmp     %i3, 2
F00075C8: 02800076                 be      loc_F00077A0
F00075CC: 80a6e003                 cmp     %i3, 3
F00075D0: f6064000                 ld      [%i1], %i3
F00075D4: b2066004                 inc     4, %i1
F00075D8: 0280003a                 be      loc_F00076C0
F00075DC: 808ec012                 btst    %l2, %i3
F00075E0: 12800003                 bne     loc_F00075EC
F00075E4: 808ec013                 btst    %l3, %i3
F00075E8: 308000b8                 ba,a    loc_F00078C8
F00075EC: 12800003                 bne     loc_F00075F8
F00075F0: 808ec014                 btst    %l4, %i3
F00075F4: 3080002e                 ba,a    loc_F00076AC
F00075F8: 12800003                 bne     loc_F0007604
F00075FC: 808ee0ff                 btst    0xFF, %i3
F0007600: 30800029                 ba,a    loc_F00076A4
F0007604: 02800027                 be      loc_F00076A0
F0007608: 9736e018                 srl     %i3, 24, %o3
F000760C: d62e0000                 stb     %o3, [%i0]
F0007610: 9736e008                 srl     %i3, 8, %o3
F0007614: d6362001                 sth     %o3, [%i0+1]
F0007618: b0062003                 inc     3, %i0
F000761C: 9610001b                 mov     %i3, %o3
F0007620: 90102018                 mov     0x18, %o0
F0007624: 10800003                 ba      loc_F0007630
F0007628: 92102008                 mov     8, %o1
F000762C: b0062004                 inc     4, %i0
F0007630: 952ac008                 sll     %o3, %o0, %o2
F0007634: 808a8012                 btst    %l2, %o2
F0007638: 228000a4                 be,a    loc_F00078C8
F000763C: 808a8012                 btst    %l2, %o2
F0007640: d6064000                 ld      [%i1], %o3
F0007644: b2066004                 inc     4, %i1
F0007648: b732c009                 srl     %o3, %o1, %i3
F000764C: b616c00a                 bset    %o2, %i3
F0007650: aa06c010                 add     %i3, %l0, %l5
F0007654: aa1d401b                 btog    %i3, %l5
F0007658: aa0d4011                 and     %l5, %l1, %l5
F000765C: 80a54011                 cmp     %l5, %l1
F0007660: 22bffff3                 be,a    loc_F000762C
F0007664: f6260000                 st      %i3, [%i0]
F0007668: 808ec012                 btst    %l2, %i3
F000766C: 12800003                 bne     loc_F0007678
F0007670: 808ec013                 btst    %l3, %i3
F0007674: 30800095                 ba,a    loc_F00078C8
F0007678: 12800003                 bne     loc_F0007684
F000767C: 808ec014                 btst    %l4, %i3
F0007680: 3080000b                 ba,a    loc_F00076AC
F0007684: 12800003                 bne     loc_F0007690
F0007688: 808ee0ff                 btst    0xFF, %i3
F000768C: 30800006                 ba,a    loc_F00076A4
F0007690: f6260000                 st      %i3, [%i0]
F0007694: 12bfffe7                 bne     loc_F0007630
F0007698: b0062004                 inc     4, %i0
F000769C: 30800089                 ba,a    locret_F00078C0
F00076A0: f62e2003                 stb     %i3, [%i0+3]
F00076A4: 9736e008                 srl     %i3, 8, %o3
F00076A8: d62e2002                 stb     %o3, [%i0+2]
F00076AC: 9736e018                 srl     %i3, 24, %o3
F00076B0: d62e0000                 stb     %o3, [%i0]
F00076B4: 9736e010                 srl     %i3, 16, %o3
F00076B8: 10800082                 ba      locret_F00078C0
F00076BC: d62e2001                 stb     %o3, [%i0+1]
F00076C0: 12800003                 bne     loc_F00076CC
F00076C4: 808ec013                 btst    %l3, %i3
F00076C8: 30800080                 ba,a    loc_F00078C8
F00076CC: 12800003                 bne     loc_F00076D8
F00076D0: 808ec014                 btst    %l4, %i3
F00076D4: 30bffff6                 ba,a    loc_F00076AC
F00076D8: 12800003                 bne     loc_F00076E4
F00076DC: 808ee0ff                 btst    0xFF, %i3
F00076E0: 30bffff1                 ba,a    loc_F00076A4
F00076E4: 02bfffef                 be      loc_F00076A0
F00076E8: 9736e018                 srl     %i3, 24, %o3
F00076EC: d62e0000                 stb     %o3, [%i0]
F00076F0: b0062001                 inc     %i0
F00076F4: 9610001b                 mov     %i3, %o3
F00076F8: 90102008                 mov     8, %o0
F00076FC: 10800003                 ba      loc_F0007708
F0007700: 92102018                 mov     0x18, %o1
F0007704: b0062004                 inc     4, %i0
F0007708: 952ac008                 sll     %o3, %o0, %o2
F000770C: 808a8012                 btst    %l2, %o2
F0007710: 12800003                 bne     loc_F000771C
F0007714: 808a8013                 btst    %l3, %o2
F0007718: 3080006c                 ba,a    loc_F00078C8
F000771C: 12800003                 bne     loc_F0007728
F0007720: 808a8014                 btst    %l4, %o2
F0007724: 30800075                 ba,a    loc_F00078F8
F0007728: 22800078                 be,a    loc_F0007908
F000772C: 808ee0ff                 btst    0xFF, %i3
F0007730: d6064000                 ld      [%i1], %o3
F0007734: b2066004                 inc     4, %i1
F0007738: b732c009                 srl     %o3, %o1, %i3
F000773C: b616c00a                 bset    %o2, %i3
F0007740: aa06c010                 add     %i3, %l0, %l5
F0007744: aa1d401b                 btog    %i3, %l5
F0007748: aa0d4011                 and     %l5, %l1, %l5
F000774C: 80a54011                 cmp     %l5, %l1
F0007750: 22bfffed                 be,a    loc_F0007704
F0007754: f6260000                 st      %i3, [%i0]
F0007758: 808ec012                 btst    %l2, %i3
F000775C: 12800003                 bne     loc_F0007768
F0007760: 808ec013                 btst    %l3, %i3
F0007764: 30800059                 ba,a    loc_F00078C8
F0007768: 12800003                 bne     loc_F0007774
F000776C: 808ec014                 btst    %l4, %i3
F0007770: 30bfffcf                 ba,a    loc_F00076AC
F0007774: 12800003                 bne     loc_F0007780
F0007778: 808ee0ff                 btst    0xFF, %i3
F000777C: 30bfffca                 ba,a    loc_F00076A4
F0007780: f6260000                 st      %i3, [%i0]
F0007784: 12bfffe1                 bne     loc_F0007708
F0007788: b0062004                 inc     4, %i0
F000778C: 3080004d                 ba,a    locret_F00078C0
F0007790: 9736e010                 srl     %i3, 16, %o3
F0007794: d6360000                 sth     %o3, [%i0]
F0007798: 1080004a                 ba      locret_F00078C0
F000779C: f6362002                 sth     %i3, [%i0+2]
F00077A0: f6064000                 ld      [%i1], %i3
F00077A4: b2066004                 inc     4, %i1
F00077A8: 808ec012                 btst    %l2, %i3
F00077AC: 12800003                 bne     loc_F00077B8
F00077B0: 808ec013                 btst    %l3, %i3
F00077B4: 30800045                 ba,a    loc_F00078C8
F00077B8: 12800003                 bne     loc_F00077C4
F00077BC: 808ec014                 btst    %l4, %i3
F00077C0: 30800045                 ba,a    loc_F00078D4
F00077C4: 12800003                 bne     loc_F00077D0
F00077C8: 808ee0ff                 btst    0xFF, %i3
F00077CC: 30800046                 ba,a    loc_F00078E4
F00077D0: 02bffff0                 be      loc_F0007790
F00077D4: 9736e010                 srl     %i3, 16, %o3
F00077D8: d6360000                 sth     %o3, [%i0]
F00077DC: b0062002                 inc     2, %i0
F00077E0: 10800003                 ba      loc_F00077EC
F00077E4: 9610001b                 mov     %i3, %o3
F00077E8: b0062004                 inc     4, %i0
F00077EC: 952ae010                 sll     %o3, 16, %o2
F00077F0: 808a8012                 btst    %l2, %o2
F00077F4: 12800003                 bne     loc_F0007800
F00077F8: 808a8013                 btst    %l3, %o2
F00077FC: 30800033                 ba,a    loc_F00078C8
F0007800: 2280003e                 be,a    loc_F00078F8
F0007804: 808a8013                 btst    %l3, %o2
F0007808: d6064000                 ld      [%i1], %o3
F000780C: b2066004                 inc     4, %i1
F0007810: b732e010                 srl     %o3, 16, %i3
F0007814: b616c00a                 bset    %o2, %i3
F0007818: aa06c010                 add     %i3, %l0, %l5
F000781C: aa1d401b                 btog    %i3, %l5
F0007820: aa0d4011                 and     %l5, %l1, %l5
F0007824: 80a54011                 cmp     %l5, %l1
F0007828: 22bffff0                 be,a    loc_F00077E8
F000782C: f6260000                 st      %i3, [%i0]
F0007830: 808ec012                 btst    %l2, %i3
F0007834: 12800003                 bne     loc_F0007840
F0007838: 808ec013                 btst    %l3, %i3
F000783C: 30800023                 ba,a    loc_F00078C8
F0007840: 12800003                 bne     loc_F000784C
F0007844: 808ec014                 btst    %l4, %i3
F0007848: 30800023                 ba,a    loc_F00078D4
F000784C: 12800003                 bne     loc_F0007858
F0007850: 808ee0ff                 btst    0xFF, %i3
F0007854: 30800024                 ba,a    loc_F00078E4
F0007858: f6260000                 st      %i3, [%i0]
F000785C: 12bfffe4                 bne     loc_F00077EC
F0007860: b0062004                 inc     4, %i0
F0007864: 30800017                 ba,a    locret_F00078C0
F0007868: b0062004                 inc     4, %i0
F000786C: f6064000                 ld      [%i1], %i3
F0007870: b2066004                 inc     4, %i1
F0007874: aa06c010                 add     %i3, %l0, %l5
F0007878: aa1d401b                 btog    %i3, %l5
F000787C: aa0d4011                 and     %l5, %l1, %l5
F0007880: 80a54011                 cmp     %l5, %l1
F0007884: 22bffff9                 be,a    loc_F0007868
F0007888: f6260000                 st      %i3, [%i0]
F000788C: 808ec012                 btst    %l2, %i3
F0007890: 12800003                 bne     loc_F000789C
F0007894: 808ec013                 btst    %l3, %i3
F0007898: 3080000c                 ba,a    loc_F00078C8
F000789C: 12800003                 bne     loc_F00078A8
F00078A0: 808ec014                 btst    %l4, %i3
F00078A4: 3080000c                 ba,a    loc_F00078D4
F00078A8: 12800003                 bne     loc_F00078B4
F00078AC: 808ee0ff                 btst    0xFF, %i3
F00078B0: 3080000d                 ba,a    loc_F00078E4
F00078B4: f6260000                 st      %i3, [%i0]
F00078B8: 12bfffed                 bne     loc_F000786C
F00078BC: b0062004                 inc     4, %i0
F00078C0: 81c7e008                 ret
F00078C4: 91ee8000                 restore %i2, %g0, %o0
F00078C8: c02e0000                 clrb    [%i0]
F00078CC: 81c7e008                 ret
F00078D0: 91ee8000                 restore %i2, %g0, %o0
F00078D4: b936e010                 srl     %i3, 16, %i4
F00078D8: f8360000                 sth     %i4, [%i0]
F00078DC: 81c7e008                 ret
F00078E0: 91ee8000                 restore %i2, %g0, %o0
F00078E4: b936e010                 srl     %i3, 16, %i4
F00078E8: f8360000                 sth     %i4, [%i0]
F00078EC: c02e2002                 clrb    [%i0+2]
F00078F0: 81c7e008                 ret
F00078F4: 91ee8000                 restore %i2, %g0, %o0
F00078F8: b932a010                 srl     %o2, 16, %i4
F00078FC: f8360000                 sth     %i4, [%i0]
F0007900: 81c7e008                 ret
F0007904: 91ee8000                 restore %i2, %g0, %o0
F0007908: b932a010                 srl     %o2, 16, %i4
F000790C: f8360000                 sth     %i4, [%i0]
F0007910: c02e2002                 clrb    [%i0+2]
F0007914: 81c7e008                 ret
F0007918: 91ee8000                 restore %i2, %g0, %o0
