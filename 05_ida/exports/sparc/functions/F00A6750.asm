F00A6750: 9de3bf98                 save    %sp, -0x68, %sp
F00A6754: 900e6700                 and     %i1, 0x700, %o0
F00A6758: 95322008                 srl     %o0, 8, %o2
F00A675C: 80a2a005                 cmp     %o2, 5
F00A6760: a8102000                 mov     0, %l4
F00A6764: 1100003f90122300         set     0xFF00, %o0
F00A676C: 900e0008                 and     %i0, %o0, %o0
F00A6770: 91322008                 srl     %o0, 8, %o0
F00A6774: 133c046792126228         set     _ecc_syndrome_tab, %o1
F00A677C: e64a0009                 ldsb    [%o0+%o1], %l3
F00A6780: b00e20f0                 and     %i0, 0xF0, %i0
F00A6784: 14800005                 bg      loc_F00A6798
F00A6788: b1362004                 srl     %i0, 4, %i0
F00A678C: 80a2a004                 cmp     %o2, 4
F00A6790: 36800002                 bge,a   loc_F00A6798
F00A6794: a92e2003                 sll     %i0, 3, %l4
F00A6798: 80a4e047                 cmp     %l3, 0x47 ! 'G'
F00A679C: 1880001d                 bgu     loc_F00A6810
F00A67A0: b40ebff8                 and     %i2, -8, %i2
F00A67A4: 80a4e03f                 cmp     %l3, 0x3F ! '?'
F00A67A8: 18800004                 bgu     loc_F00A67B8
F00A67AC: 9134e003                 srl     %l3, 3, %o0
F00A67B0: 10800004                 ba      loc_F00A67C0
F00A67B4: 92052007                 add     %l4, 7, %o1
F00A67B8: 92052007                 add     %l4, 7, %o1
F00A67BC: 900ce007                 and     %l3, 7, %o0
F00A67C0: a8224008                 sub     %o1, %o0, %l4
F00A67C4: 90068014                 add     %i2, %l4, %o0
F00A67C8: 9fc6c000                 call    %i3
F00A67CC: 920e600f                 and     %i1, 0xF, %o1! __src
F00A67D0: a4920000                 orcc    %o0, %g0, %l2
F00A67D4: 1280001f                 bne     loc_F00A6850
F00A67D8: a2102000                 mov     0, %l1
F00A67DC: 113c046a                 sethi   %hi(aSimmDecodeFunc), %o0! "simm decode function failed\n"
F00A67E0: 7ffdb79e                 call    _printf
F00A67E4: 90122328                 bset    %lo(aSimmDecodeFunc), %o0! "simm decode function failed\n"
F00A67E8: 1080001a                 ba      loc_F00A6850
F00A67EC: a2102000                 mov     0, %l1
F00A67F0: a0040019                 add     %l0, %i1, %l0
F00A67F4: 90100010                 mov     %l0, %o0! __dst
F00A67F8: 7ffd834c                 call    _strcpy
F00A67FC: 92100012                 mov     %l2, %o1
F00A6800: d0042008                 ld      [%l0+8], %o0
F00A6804: 90022001                 inc     %o0
F00A6808: 1080003a                 ba      loc_F00A68F0
F00A680C: d0242008                 st      %o0, [%l0+8]
F00A6810: a2102000                 mov     0, %l1
F00A6814: b4068014                 add     %i2, %l4, %i2
F00A6818: 213c046a                 sethi   -0xFEE5800, %l0
F00A681C: 90068011                 add     %i2, %l1, %o0! char *
F00A6820: 9fc6c000                 call    %i3
F00A6824: 920e600f                 and     %i1, 0xF, %o1! __s2
F00A6828: a4920000                 orcc    %o0, %g0, %l2
F00A682C: 32800005                 bne,a   loc_F00A6840
F00A6830: a2046001                 inc     %l1
F00A6834: 7ffdb789                 call    _printf
F00A6838: 90142348                 or      %l0, 0x348, %o0
F00A683C: a2046001                 inc     %l1
F00A6840: 80a46007                 cmp     %l1, 7
F00A6844: 04bffff7                 ble     loc_F00A6820
F00A6848: 90068011                 add     %i2, %l1, %o0
F00A684C: a2102000                 mov     0, %l1
F00A6850: 113c0467b2122328         set     _mem_ce_simm, %i1
F00A6858: 353c046a                 sethi   -0xFEE5800, %i2
F00A685C: 373c046a                 sethi   -0xFEE5800, %i3
F00A6860: 2b3c0466                 sethi   -0xFEE6800, %l5
F00A6864: a0102000                 mov     0, %l0
F00A6868: d04c0019                 ldsb    [%l0+%i1], %o0
F00A686C: 80a22000                 cmp     %o0, 0
F00A6870: 02bfffe0                 be      loc_F00A67F0
F00A6874: 90100012                 mov     %l2, %o0! __s1
F00A6878: b0040019                 add     %l0, %i1, %i0
F00A687C: 7ffd864c                 call    _strcmp
F00A6880: 92100018                 mov     %i0, %o1
F00A6884: 80a22000                 cmp     %o0, 0
F00A6888: 32800017                 bne,a   loc_F00A68E4
F00A688C: a2046001                 inc     %l1
F00A6890: d0062008                 ld      [%i0+8], %o0! char *
F00A6894: 90022001                 inc     %o0
F00A6898: 80a220ff                 cmp     %o0, 0xFF
F00A689C: 08800015                 bleu    loc_F00A68F0
F00A68A0: d0262008                 st      %o0, [%i0+8]
F00A68A4: 7ffdb76d                 call    _printf
F00A68A8: 9016a368                 or      %i2, 0x368, %o0! char *
F00A68AC: d2062008                 ld      [%i0+8], %o1
F00A68B0: 7ffdb76a                 call    _printf
F00A68B4: 9016e380                 or      %i3, 0x380, %o0
F00A68B8: 113c046a901223a0         set     aFromSimmS, %o0! "from SIMM %s\n"
F00A68C0: 7ffdb766                 call    _printf
F00A68C4: 92100012                 mov     %l2, %o1
F00A68C8: 113c046a                 sethi   %hi(aConsiderReplac), %o0! "Consider replacing the SIMM.\n"
F00A68CC: 7ffdb763                 call    _printf
F00A68D0: 901223b0                 bset    %lo(aConsiderReplac), %o0! "Consider replacing the SIMM.\n"
F00A68D4: c0262008                 clr     [%i0+8]
F00A68D8: 90102001                 mov     1, %o0
F00A68DC: 10800005                 ba      loc_F00A68F0
F00A68E0: d0256154                 st      %o0, [%l5+0x154]
F00A68E4: 80a460ff                 cmp     %l1, 0xFF
F00A68E8: 04bfffe0                 ble     loc_F00A6868
F00A68EC: a004200c                 inc     0xC, %l0
F00A68F0: 80a460ff                 cmp     %l1, 0xFF
F00A68F4: 04800004                 ble     loc_F00A6904
F00A68F8: 113c046a                 sethi   %hi(aSofterrorMemCe), %o0! "Softerror: mem_ce_simm[] out of space."...
F00A68FC: 7ffdb757                 call    _printf
F00A6900: 901223d0                 bset    %lo(aSofterrorMemCe), %o0! "Softerror: mem_ce_simm[] out of space."...
F00A6904: 113c0466                 sethi   %hi(_log_ce_error), %o0
F00A6908: d0022154                 ld      [%o0+%lo(_log_ce_error)], %o0
F00A690C: 80a22000                 cmp     %o0, 0
F00A6910: 02800034                 be      locret_F00A69E0
F00A6914: 80a4e047                 cmp     %l3, 0x47 ! 'G'
F00A6918: 18800004                 bgu     loc_F00A6928
F00A691C: 113c046a                 sethi   %hi(aCorrectedSimmA), %o0! "\tCorrected SIMM at: %s\n"
F00A6920: 10800004                 ba      loc_F00A6930
F00A6924: 901223f8                 bset    %lo(aCorrectedSimmA), %o0! "\tCorrected SIMM at: %s\n"
F00A6928: 113c046b90122010         set     aPossibleCorrec, %o0! "\tPossible Corrected SIMM at: %s\n"
F00A6930: 7ffdb74a                 call    _printf
F00A6934: 92100012                 mov     %l2, %o1
F00A6938: 113c046b90122038         set     aOffsetIsD, %o0! "\toffset is %d\n"
F00A6940: 7ffdb746                 call    _printf
F00A6944: 92100014                 mov     %l4, %o1
F00A6948: 80a4e03f                 cmp     %l3, 0x3F ! '?'
F00A694C: 18800006                 bgu     loc_F00A6964
F00A6950: 113c046b                 sethi   %hi(aBit2dWasCorrec), %o0! "\tBit %2d was corrected\n"
F00A6954: 90122048                 bset    %lo(aBit2dWasCorrec), %o0! "\tBit %2d was corrected\n"
F00A6958: 7ffdb740                 call    _printf
F00A695C: 92100013                 mov     %l3, %o1
F00A6960: 30800020                 ba,a    locret_F00A69E0
F00A6964: 80a4e047                 cmp     %l3, 0x47 ! 'G'
F00A6968: 18800006                 bgu     loc_F00A6980
F00A696C: 113c046b                 sethi   %hi(aEccBit2dWasCor), %o0! "\tECC Bit %2d was corrected\n"
F00A6970: 90122060                 bset    %lo(aEccBit2dWasCor), %o0! "\tECC Bit %2d was corrected\n"
F00A6974: 7ffdb739                 call    _printf
F00A6978: 9204ffc0                 add     %l3, -0x40, %o1
F00A697C: 30800019                 ba,a    locret_F00A69E0
F00A6980: 80a4e049                 cmp     %l3, 0x49 ! 'I'
F00A6984: 0280000f                 be      loc_F00A69C0
F00A6988: 113c046b                 sethi   -0xFEE5400, %o0
F00A698C: 18800005                 bgu     loc_F00A69A0
F00A6990: 80a4e048                 cmp     %l3, 0x48 ! 'H'
F00A6994: 02800009                 be      loc_F00A69B8
F00A6998: 113c046b                 sethi   -0xFEE5400, %o0
F00A699C: 30800011                 ba,a    locret_F00A69E0
F00A69A0: 80a4e04a                 cmp     %l3, 0x4A ! 'J'
F00A69A4: 02800009                 be      loc_F00A69C8
F00A69A8: 80a4e04b                 cmp     %l3, 0x4B ! 'K'
F00A69AC: 0280000a                 be      loc_F00A69D4
F00A69B0: 113c046b                 sethi   -0xFEE5400, %o0
F00A69B4: 3080000b                 ba,a    locret_F00A69E0
F00A69B8: 10800008                 ba      loc_F00A69D8
F00A69BC: 90122080                 bset    0x80, %o0
F00A69C0: 10800006                 ba      loc_F00A69D8
F00A69C4: 901220a0                 bset    0xA0, %o0
F00A69C8: 113c046b                 sethi   %hi(aFourBitsWereCo), %o0! "\tFour bits were corrected\n"
F00A69CC: 10800003                 ba      loc_F00A69D8
F00A69D0: 901220c0                 bset    %lo(aFourBitsWereCo), %o0! "\tFour bits were corrected\n"
F00A69D4: 901220e0                 bset    0xE0, %o0! char *
F00A69D8: 7ffdb720                 call    _printf
F00A69DC: 01000000                 nop
F00A69E0: 81c7e008                 ret
F00A69E4: 81e80000                 restore
