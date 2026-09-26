F00081AC: 9de3bfc0                 save    %sp, -0x40, %sp
F00081B0: 808e2003                 btst    3, %i0
F00081B4: 0280000d                 be      loc_F00081E8
F00081B8: b68e6003                 andcc   %i1, 3, %i3
F00081BC: f84e0000                 ldsb    [%i0], %i4
F00081C0: fa4e4000                 ldsb    [%i1], %i5
F00081C4: b0062001                 inc     %i0
F00081C8: 80a7001d                 cmp     %i4, %i5
F00081CC: 128000c0                 bne     loc_F00084CC
F00081D0: b2066001                 inc     %i1
F00081D4: 80970000                 tst     %i4
F00081D8: 12bffff7                 bne     loc_F00081B4
F00081DC: 808e2003                 btst    3, %i0
F00081E0: 108000a2                 ba      locret_F0008468
F00081E4: b0102000                 mov     0, %i0
F00081E8: 2d1fbfbfac15a2ff         set     0x7EFEFEFF, %l6
F00081F0: 2f204040ae15e100         set     -0x7EFEFF00, %l7
F00081F8: 213fc000                 sethi   -0x1000000, %l0
F00081FC: 23003fc0                 sethi   0xFF0000, %l1
F0008200: a5346008                 srl     %l1, 8, %l2
F0008204: 0280007f                 be      loc_F0008400
F0008208: 80a6e002                 cmp     %i3, 2
F000820C: 02800055                 be      loc_F0008360
F0008210: 80a6e001                 cmp     %i3, 1
F0008214: fa0e4000                 ldub    [%i1], %i5
F0008218: b6103f00                 mov     -0x100, %i3
F000821C: b617401b                 bset    %i5, %i3
F0008220: b2066001                 inc     %i1
F0008224: 02800025                 be      loc_F00082B8
F0008228: bb2f6018                 sll     %i5, 24, %i5
F000822C: b0260019                 sub     %i0, %i1, %i0
F0008230: 8206c016                 add     %i3, %l6, %g1
F0008234: 8218401b                 btog    %i3, %g1
F0008238: 82084017                 and     %g1, %l7, %g1
F000823C: 80a04017                 cmp     %g1, %l7
F0008240: 32800003                 bne,a   loc_F000824C
F0008244: b6100000                 clr     %i3
F0008248: f6064000                 ld      [%i1], %i3
F000824C: f8060019                 ld      [%i0+%i1], %i4
F0008250: b2066004                 inc     4, %i1
F0008254: a936e008                 srl     %i3, 8, %l4
F0008258: ba15001d                 bset    %l4, %i5
F000825C: 80a7001d                 cmp     %i4, %i5
F0008260: 02800003                 be      loc_F000826C
F0008264: a6070016                 add     %i4, %l6, %l3
F0008268: 30800082                 ba,a    loc_F0008470
F000826C: a61cc01c                 btog    %i4, %l3
F0008270: a60cc017                 and     %l3, %l7, %l3
F0008274: 80a4c017                 cmp     %l3, %l7
F0008278: 22bfffee                 be,a    loc_F0008230
F000827C: bb2ee018                 sll     %i3, 24, %i5
F0008280: 808f0010                 btst    %l0, %i4
F0008284: 3080007b                 ba,a    loc_F0008470
F0008288: 12800003                 bne     loc_F0008294
F000828C: 808f0011                 btst    %l1, %i4
F0008290: 30800076                 ba,a    locret_F0008468
F0008294: 12800003                 bne     loc_F00082A0
F0008298: 808f0012                 btst    %l2, %i4
F000829C: 30800073                 ba,a    locret_F0008468
F00082A0: 12800003                 bne     loc_F00082AC
F00082A4: 808f20ff                 btst    0xFF, %i4
F00082A8: 30800070                 ba,a    locret_F0008468
F00082AC: 12bfffe1                 bne     loc_F0008230
F00082B0: bb2ee018                 sll     %i3, 24, %i5
F00082B4: 3080006d                 ba,a    locret_F0008468
F00082B8: a8100000                 clr     %l4
F00082BC: e8164000                 lduh    [%i1], %l4
F00082C0: b72ee010                 sll     %i3, 16, %i3
F00082C4: b615001b                 bset    %l4, %i3
F00082C8: b2066002                 inc     2, %i1
F00082CC: a92d2008                 sll     %l4, 8, %l4
F00082D0: ba174014                 bset    %l4, %i5
F00082D4: b0260019                 sub     %i0, %i1, %i0
F00082D8: 8206c016                 add     %i3, %l6, %g1
F00082DC: 8218401b                 btog    %i3, %g1
F00082E0: 82084017                 and     %g1, %l7, %g1
F00082E4: 80a04017                 cmp     %g1, %l7
F00082E8: 32800003                 bne,a   loc_F00082F4
F00082EC: b6100000                 clr     %i3
F00082F0: f6064000                 ld      [%i1], %i3
F00082F4: f8060019                 ld      [%i0+%i1], %i4
F00082F8: b2066004                 inc     4, %i1
F00082FC: a936e018                 srl     %i3, 24, %l4
F0008300: ba15001d                 bset    %l4, %i5
F0008304: 80a7001d                 cmp     %i4, %i5
F0008308: 02800003                 be      loc_F0008314
F000830C: a6070016                 add     %i4, %l6, %l3
F0008310: 30800058                 ba,a    loc_F0008470
F0008314: a61cc01c                 btog    %i4, %l3
F0008318: a60cc017                 and     %l3, %l7, %l3
F000831C: 80a4c017                 cmp     %l3, %l7
F0008320: 22bfffee                 be,a    loc_F00082D8
F0008324: bb2ee008                 sll     %i3, 8, %i5
F0008328: 808f0010                 btst    %l0, %i4
F000832C: 30800051                 ba,a    loc_F0008470
F0008330: 12800003                 bne     loc_F000833C
F0008334: 808f0011                 btst    %l1, %i4
F0008338: 3080004c                 ba,a    locret_F0008468
F000833C: 12800003                 bne     loc_F0008348
F0008340: 808f0012                 btst    %l2, %i4
F0008344: 30800049                 ba,a    locret_F0008468
F0008348: 12800003                 bne     loc_F0008354
F000834C: 808f20ff                 btst    0xFF, %i4
F0008350: 30800046                 ba,a    locret_F0008468
F0008354: 12bfffe1                 bne     loc_F00082D8
F0008358: bb2ee008                 sll     %i3, 8, %i5
F000835C: 30800043                 ba,a    locret_F0008468
F0008360: fa164000                 lduh    [%i1], %i5
F0008364: 373fffc0b617401b         set     -0x10000, %i3
F000836C: b2066002                 inc     2, %i1
F0008370: bb2f6010                 sll     %i5, 16, %i5
F0008374: b0260019                 sub     %i0, %i1, %i0
F0008378: 8206c016                 add     %i3, %l6, %g1
F000837C: 8218401b                 btog    %i3, %g1
F0008380: 82084017                 and     %g1, %l7, %g1
F0008384: 80a04017                 cmp     %g1, %l7
F0008388: 32800003                 bne,a   loc_F0008394
F000838C: b6100000                 clr     %i3
F0008390: f6064000                 ld      [%i1], %i3
F0008394: f8064018                 ld      [%i1+%i0], %i4
F0008398: b2066004                 inc     4, %i1
F000839C: a936e010                 srl     %i3, 16, %l4
F00083A0: ba15001d                 bset    %l4, %i5
F00083A4: 80a7001d                 cmp     %i4, %i5
F00083A8: 02800003                 be      loc_F00083B4
F00083AC: a6070016                 add     %i4, %l6, %l3
F00083B0: 30800030                 ba,a    loc_F0008470
F00083B4: a61cc01c                 btog    %i4, %l3
F00083B8: a60cc017                 and     %l3, %l7, %l3
F00083BC: 80a4c017                 cmp     %l3, %l7
F00083C0: 22bfffee                 be,a    loc_F0008378
F00083C4: bb2ee010                 sll     %i3, 16, %i5
F00083C8: 808f0010                 btst    %l0, %i4
F00083CC: 30800029                 ba,a    loc_F0008470
F00083D0: 12800003                 bne     loc_F00083DC
F00083D4: 808f0011                 btst    %l1, %i4
F00083D8: 30800024                 ba,a    locret_F0008468
F00083DC: 12800003                 bne     loc_F00083E8
F00083E0: 808f0012                 btst    %l2, %i4
F00083E4: 30800021                 ba,a    locret_F0008468
F00083E8: 12800003                 bne     loc_F00083F4
F00083EC: 808f20ff                 btst    0xFF, %i4
F00083F0: 3080001e                 ba,a    locret_F0008468
F00083F4: 12bfffe1                 bne     loc_F0008378
F00083F8: bb2ee010                 sll     %i3, 16, %i5
F00083FC: 3080001b                 ba,a    locret_F0008468
F0008400: b0260019                 sub     %i0, %i1, %i0
F0008404: fa064000                 ld      [%i1], %i5
F0008408: f8064018                 ld      [%i1+%i0], %i4
F000840C: 80a7001d                 cmp     %i4, %i5
F0008410: b2066004                 inc     4, %i1
F0008414: 02800003                 be      loc_F0008420
F0008418: a6070016                 add     %i4, %l6, %l3
F000841C: 30800015                 ba,a    loc_F0008470
F0008420: a61cc01c                 btog    %i4, %l3
F0008424: a60cc017                 and     %l3, %l7, %l3
F0008428: 80a4c017                 cmp     %l3, %l7
F000842C: 22bffff7                 be,a    loc_F0008408
F0008430: fa064000                 ld      [%i1], %i5
F0008434: 808f0010                 btst    %l0, %i4
F0008438: 3080000e                 ba,a    loc_F0008470
F000843C: 12800003                 bne     loc_F0008448
F0008440: 808f0011                 btst    %l1, %i4
F0008444: 30800009                 ba,a    locret_F0008468
F0008448: 12800003                 bne     loc_F0008454
F000844C: 808f0012                 btst    %l2, %i4
F0008450: 30800006                 ba,a    locret_F0008468
F0008454: 12800003                 bne     loc_F0008460
F0008458: 808f20ff                 btst    0xFF, %i4
F000845C: 30800003                 ba,a    locret_F0008468
F0008460: 32bfffea                 bne,a   loc_F0008408
F0008464: fa064000                 ld      [%i1], %i5
F0008468: 81c7e008                 ret
F000846C: 91e80000                 restore %g0, %g0, %o0
F0008470: a93f2018                 sra     %i4, 24, %l4
F0008474: ab3f6018                 sra     %i5, 24, %l5
F0008478: b0a50015                 subcc   %l4, %l5, %i0
F000847C: 12800019                 bne     locret_F00084E0
F0008480: 808d20ff                 btst    0xFF, %l4
F0008484: 02bffff9                 be      locret_F0008468
F0008488: a92f2008                 sll     %i4, 8, %l4
F000848C: ab2f6008                 sll     %i5, 8, %l5
F0008490: a93d2018                 sra     %l4, 24, %l4
F0008494: ab3d6018                 sra     %l5, 24, %l5
F0008498: b0a50015                 subcc   %l4, %l5, %i0
F000849C: 12800011                 bne     locret_F00084E0
F00084A0: 808d20ff                 btst    0xFF, %l4
F00084A4: 02bffff1                 be      locret_F0008468
F00084A8: a92f2010                 sll     %i4, 16, %l4
F00084AC: ab2f6010                 sll     %i5, 16, %l5
F00084B0: a93d2018                 sra     %l4, 24, %l4
F00084B4: ab3d6018                 sra     %l5, 24, %l5
F00084B8: b0a50015                 subcc   %l4, %l5, %i0
F00084BC: 12800009                 bne     locret_F00084E0
F00084C0: 808d20ff                 btst    0xFF, %l4
F00084C4: 02bfffe9                 be      locret_F0008468
F00084C8: 01000000                 nop
F00084CC: a92f2018                 sll     %i4, 24, %l4
F00084D0: ab2f6018                 sll     %i5, 24, %l5
F00084D4: a93d2018                 sra     %l4, 24, %l4
F00084D8: ab3d6018                 sra     %l5, 24, %l5
F00084DC: b0250015                 sub     %l4, %l5, %i0
F00084E0: 81c7e008                 ret
F00084E4: 91ee0000                 restore %i0, %g0, %o0
