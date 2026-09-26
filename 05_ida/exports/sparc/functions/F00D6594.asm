F00D6594: 9de3bf80                 save    %sp, -0x80, %sp
F00D6598: 94102001                 mov     1, %o2
F00D659C: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D65A0: 133c0505                 sethi   %hi(paSetcharkeyacti), %o1
F00D65A4: d2026250                 ld      [%o1+%lo(paSetcharkeyacti)], %o1! SEL
F00D65A8: 40006cb2                 call    _objc_msgSend
F00D65AC: ae10200b                 mov     0xB, %l7
F00D65B0: 912ee018                 sll     %i3, 24, %o0
F00D65B4: 913a2018                 sra     %o0, 24, %o0
F00D65B8: 80a22001                 cmp     %o0, 1
F00D65BC: 22800002                 be,a    loc_F00D65C4
F00D65C0: ae10200a                 mov     0xA, %l7
F00D65C4: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D65C8: 133c0505                 sethi   %hi(paEventflags), %o1! SEL
F00D65CC: 40006ca9                 call    _objc_msgSend
F00D65D0: d2026238                 ld      [%o1+%lo(paEventflags)], %o1
F00D65D4: a6100008                 mov     %o0, %l3
F00D65D8: 912ea002                 sll     %i2, 2, %o0
F00D65DC: 90020018                 add     %o0, %i0, %o0
F00D65E0: e00220d0                 ld      [%o0+0xD0], %l0
F00D65E4: e4562004                 ldsh    [%i0+4], %l2
F00D65E8: 80a42000                 cmp     %l0, 0
F00D65EC: 028000db                 be      loc_F00D6958
F00D65F0: 9134e010                 srl     %l3, 16, %o0
F00D65F4: 80a4a000                 cmp     %l2, 0
F00D65F8: 22800005                 be,a    loc_F00D660C
F00D65FC: d40c0000                 ldub    [%l0], %o2
F00D6600: d4540000                 ldsh    [%l0], %o2
F00D6604: 10800003                 ba      loc_F00D6610
F00D6608: a0042002                 inc     2, %l0
F00D660C: a0042001                 inc     %l0
F00D6610: 80a2a000                 cmp     %o2, 0
F00D6614: 02800017                 be      loc_F00D6670
F00D6618: 80a22000                 cmp     %o0, 0
F00D661C: 02800015                 be      loc_F00D6670
F00D6620: 80a4a000                 cmp     %l2, 0
F00D6624: 02800003                 be      loc_F00D6630
F00D6628: 92102002                 mov     2, %o1
F00D662C: 92102004                 mov     4, %o1
F00D6630: d6062088                 ld      [%i0+0x88], %o3
F00D6634: a2102000                 mov     0, %l1
F00D6638: 80a4400b                 cmp     %l1, %o3
F00D663C: 1480000e                 bg      loc_F00D6674
F00D6640: 80a4a000                 cmp     %l2, 0
F00D6644: 808aa001                 btst    1, %o2
F00D6648: 02800005                 be      loc_F00D665C
F00D664C: 808a2001                 btst    1, %o0
F00D6650: 32800002                 bne,a   loc_F00D6658
F00D6654: a0040009                 add     %l0, %o1, %l0
F00D6658: 932a6001                 sll     %o1, 1, %o1
F00D665C: 953aa001                 sra     %o2, 1, %o2
F00D6660: a2046001                 inc     %l1
F00D6664: 80a4400b                 cmp     %l1, %o3
F00D6668: 04bffff7                 ble     loc_F00D6644
F00D666C: 913a2001                 sra     %o0, 1, %o0
F00D6670: 80a4a000                 cmp     %l2, 0
F00D6674: 22800005                 be,a    loc_F00D6688
F00D6678: c40c0000                 ldub    [%l0], %g2
F00D667C: c4540000                 ldsh    [%l0], %g2
F00D6680: 10800003                 ba      loc_F00D668C
F00D6684: a0042002                 inc     2, %l0
F00D6688: a0042001                 inc     %l0
F00D668C: 80a4a000                 cmp     %l2, 0
F00D6690: 22800003                 be,a    loc_F00D669C
F00D6694: da0c0000                 ldub    [%l0], %o5
F00D6698: da540000                 ldsh    [%l0], %o5
F00D669C: 912ea002                 sll     %i2, 2, %o0
F00D66A0: 90020018                 add     %o0, %i0, %o0
F00D66A4: e00220d0                 ld      [%o0+0xD0], %l0
F00D66A8: 80a4a000                 cmp     %l2, 0
F00D66AC: 9134e010                 srl     %l3, 16, %o0
F00D66B0: 02800005                 be      loc_F00D66C4
F00D66B4: 900a2003                 and     %o0, 3, %o0
F00D66B8: d4540000                 ldsh    [%l0], %o2
F00D66BC: 10800004                 ba      loc_F00D66CC
F00D66C0: a0042002                 inc     2, %l0
F00D66C4: d40c0000                 ldub    [%l0], %o2
F00D66C8: a0042001                 inc     %l0
F00D66CC: 80a2a000                 cmp     %o2, 0
F00D66D0: 02800017                 be      loc_F00D672C
F00D66D4: 80a22000                 cmp     %o0, 0
F00D66D8: 02800015                 be      loc_F00D672C
F00D66DC: 80a4a000                 cmp     %l2, 0
F00D66E0: 02800003                 be      loc_F00D66EC
F00D66E4: 92102002                 mov     2, %o1
F00D66E8: 92102004                 mov     4, %o1
F00D66EC: d6062088                 ld      [%i0+0x88], %o3
F00D66F0: a2102000                 mov     0, %l1
F00D66F4: 80a4400b                 cmp     %l1, %o3
F00D66F8: 1480000e                 bg      loc_F00D6730
F00D66FC: 80a4a000                 cmp     %l2, 0
F00D6700: 808aa001                 btst    1, %o2
F00D6704: 02800005                 be      loc_F00D6718
F00D6708: 808a2001                 btst    1, %o0
F00D670C: 32800002                 bne,a   loc_F00D6714
F00D6710: a0040009                 add     %l0, %o1, %l0
F00D6714: 932a6001                 sll     %o1, 1, %o1
F00D6718: 953aa001                 sra     %o2, 1, %o2
F00D671C: a2046001                 inc     %l1
F00D6720: 80a4400b                 cmp     %l1, %o3
F00D6724: 04bffff7                 ble     loc_F00D6700
F00D6728: 913a2001                 sra     %o0, 1, %o0
F00D672C: 80a4a000                 cmp     %l2, 0
F00D6730: 22800005                 be,a    loc_F00D6744
F00D6734: c60c0000                 ldub    [%l0], %g3
F00D6738: c6540000                 ldsh    [%l0], %g3
F00D673C: 10800003                 ba      loc_F00D6748
F00D6740: a0042002                 inc     2, %l0
F00D6744: a0042001                 inc     %l0
F00D6748: 80a4a000                 cmp     %l2, 0
F00D674C: 22800003                 be,a    loc_F00D6758
F00D6750: d20c0000                 ldub    [%l0], %o1
F00D6754: d2540000                 ldsh    [%l0], %o1
F00D6758: 02800008                 be      loc_F00D6778
F00D675C: 1100003f                 sethi   0xFC00, %o0
F00D6760: 901223ff                 bset    0x3FF, %o0
F00D6764: 80a08008                 cmp     %g2, %o0
F00D6768: 02800008                 be      loc_F00D6788
F00D676C: 912b6002                 sll     %o5, 2, %o0
F00D6770: 10800070                 ba      loc_F00D6930
F00D6774: 94100017                 mov     %l7, %o2
F00D6778: 80a0a0ff                 cmp     %g2, 0xFF
F00D677C: 1280006d                 bne     loc_F00D6930
F00D6780: 94100017                 mov     %l7, %o2
F00D6784: 912b6002                 sll     %o5, 2, %o0
F00D6788: 90020018                 add     %o0, %i0, %o0
F00D678C: e00222d4                 ld      [%o0+0x2D4], %l0
F00D6790: a2102000                 mov     0, %l1
F00D6794: 80a4a000                 cmp     %l2, 0
F00D6798: 02800005                 be      loc_F00D67AC
F00D679C: b2100013                 mov     %l3, %i1
F00D67A0: ea540000                 ldsh    [%l0], %l5
F00D67A4: 10800004                 ba      loc_F00D67B4
F00D67A8: a0042002                 inc     2, %l0
F00D67AC: ea0c0000                 ldub    [%l0], %l5
F00D67B0: a0042001                 inc     %l0
F00D67B4: 80a44015                 cmp     %l1, %l5
F00D67B8: 1680004d                 bge     loc_F00D68EC
F00D67BC: 80a4c019                 cmp     %l3, %i1
F00D67C0: 912ee018                 sll     %i3, 24, %o0
F00D67C4: a93a2018                 sra     %o0, 24, %l4
F00D67C8: 2d3c0505                 sethi   -0xFEBEC00, %l6
F00D67CC: 90100011                 mov     %l1, %o0
F00D67D0: 7ffcc036                 call    _rem
F00D67D4: 9210200a                 mov     0xA, %o1
F00D67D8: 80a22009                 cmp     %o0, 9
F00D67DC: 12800005                 bne     loc_F00D67F0
F00D67E0: 80a4a000                 cmp     %l2, 0
F00D67E4: 7ffe6fb7                 call    _thread_block
F00D67E8: 01000000                 nop
F00D67EC: 80a4a000                 cmp     %l2, 0
F00D67F0: 22800005                 be,a    loc_F00D6804
F00D67F4: c40c0000                 ldub    [%l0], %g2
F00D67F8: c4540000                 ldsh    [%l0], %g2
F00D67FC: 10800003                 ba      loc_F00D6808
F00D6800: a0042002                 inc     2, %l0
F00D6804: a0042001                 inc     %l0
F00D6808: 80a0a0ff                 cmp     %g2, 0xFF
F00D680C: 12800023                 bne     loc_F00D6898
F00D6810: 80a4a000                 cmp     %l2, 0
F00D6814: 80a52001                 cmp     %l4, 1
F00D6818: 1280001c                 bne     loc_F00D6888
F00D681C: 80a4a000                 cmp     %l2, 0
F00D6820: 22800008                 be,a    loc_F00D6840
F00D6824: d00c0000                 ldub    [%l0], %o0
F00D6828: d0540000                 ldsh    [%l0], %o0
F00D682C: 90022010                 inc     0x10, %o0
F00D6830: 912d0008                 sll     %l4, %o0, %o0
F00D6834: a614c008                 bset    %o0, %l3
F00D6838: 10800006                 ba      loc_F00D6850
F00D683C: a0042002                 inc     2, %l0
F00D6840: 90022010                 inc     0x10, %o0
F00D6844: 912d0008                 sll     %l4, %o0, %o0
F00D6848: a614c008                 bset    %o0, %l3
F00D684C: a0042001                 inc     %l0
F00D6850: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6854: 133c0505                 sethi   %hi(paDeviceflags), %o1! SEL
F00D6858: 40006c06                 call    _objc_msgSend
F00D685C: d2026254                 ld      [%o1+%lo(paDeviceflags)], %o1
F00D6860: 9410200c                 mov     0xC, %o2
F00D6864: 96100008                 mov     %o0, %o3
F00D6868: 9810001a                 mov     %i2, %o4
F00D686C: d00624f8                 ld      [%i0+0x4F8], %o0
F00D6870: 9a102000                 mov     0, %o5
F00D6874: d205a234                 ld      [%l6+0x234], %o1
F00D6878: c023a05c                 clr     [%sp+0x80+var_24]
F00D687C: c023a060                 clr     [%sp+0x80+var_20]
F00D6880: 10800014                 ba      loc_F00D68D0
F00D6884: c023a064                 clr     [%sp+0x80+var_1C]
F00D6888: 22800014                 be,a    loc_F00D68D8
F00D688C: a0042001                 inc     %l0
F00D6890: 10800012                 ba      loc_F00D68D8
F00D6894: a0042002                 inc     2, %l0
F00D6898: 22800005                 be,a    loc_F00D68AC
F00D689C: da0c0000                 ldub    [%l0], %o5
F00D68A0: da540000                 ldsh    [%l0], %o5
F00D68A4: 10800003                 ba      loc_F00D68B0
F00D68A8: a0042002                 inc     2, %l0
F00D68AC: a0042001                 inc     %l0
F00D68B0: 94100017                 mov     %l7, %o2
F00D68B4: 96100013                 mov     %l3, %o3
F00D68B8: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D68BC: 9810001a                 mov     %i2, %o4
F00D68C0: d205a234                 ld      [%l6+0x234], %o1! SEL
F00D68C4: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00D68C8: da23a060                 st      %o5, [%sp+0x80+var_20]
F00D68CC: c423a064                 st      %g2, [%sp+0x80+var_1C]
F00D68D0: 40006be8                 call    _objc_msgSend
F00D68D4: 01000000                 nop
F00D68D8: a2046001                 inc     %l1
F00D68DC: 80a44015                 cmp     %l1, %l5
F00D68E0: 06bfffbc                 bl      loc_F00D67D0
F00D68E4: 90100011                 mov     %l1, %o0
F00D68E8: 80a4c019                 cmp     %l3, %i1
F00D68EC: 0280001b                 be      loc_F00D6958
F00D68F0: 133c0505                 sethi   %hi(paDeviceflags), %o1
F00D68F4: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D68F8: d2026254                 ld      [%o1+%lo(paDeviceflags)], %o1! SEL
F00D68FC: 40006bdd                 call    _objc_msgSend
F00D6900: a6100019                 mov     %i1, %l3
F00D6904: 9410200c                 mov     0xC, %o2
F00D6908: 96100008                 mov     %o0, %o3
F00D690C: 9810001a                 mov     %i2, %o4
F00D6910: 9a102000                 mov     0, %o5
F00D6914: d00624f8                 ld      [%i0+0x4F8], %o0
F00D6918: 133c0505                 sethi   %hi(paKeyboardeventF), %o1
F00D691C: d2026234                 ld      [%o1+%lo(paKeyboardeventF)], %o1
F00D6920: c023a05c                 clr     [%sp+0x80+var_24]
F00D6924: c023a060                 clr     [%sp+0x80+var_20]
F00D6928: 1080000a                 ba      loc_F00D6950
F00D692C: c023a064                 clr     [%sp+0x80+var_1C]
F00D6930: 96100013                 mov     %l3, %o3
F00D6934: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6938: 9810001a                 mov     %i2, %o4
F00D693C: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00D6940: d223a060                 st      %o1, [%sp+0x80+var_20]
F00D6944: 133c0505                 sethi   %hi(paKeyboardeventF), %o1
F00D6948: d2026234                 ld      [%o1+%lo(paKeyboardeventF)], %o1! SEL
F00D694C: c623a064                 st      %g3, [%sp+0x80+var_1C]
F00D6950: 40006bc8                 call    _objc_msgSend
F00D6954: 01000000                 nop
F00D6958: 9006001a                 add     %i0, %i2, %o0
F00D695C: d00a2006                 ldub    [%o0+6], %o0
F00D6960: 808a2040                 btst    0x40, %o0 ! '@'
F00D6964: 02800046                 be      locret_F00D6A7C
F00D6968: a2102000                 mov     0, %l1
F00D696C: 912ee018                 sll     %i3, 24, %o0
F00D6970: a13a2018                 sra     %o0, 24, %l0
F00D6974: 113fffbfa41223ff         set     -0x10001, %l2
F00D697C: 92100018                 mov     %i0, %o1
F00D6980: d01264d8                 lduh    [%o1+0x4D8], %o0
F00D6984: 80a68008                 cmp     %i2, %o0
F00D6988: 3280003a                 bne,a   loc_F00D6A70
F00D698C: a2046001                 inc     %l1
F00D6990: 94100017                 mov     %l7, %o2
F00D6994: 96100013                 mov     %l3, %o3
F00D6998: 9810001a                 mov     %i2, %o4
F00D699C: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D69A0: 133c0505                 sethi   %hi(paKeyboardspecia), %o1
F00D69A4: d2026230                 ld      [%o1+%lo(paKeyboardspecia)], %o1! SEL
F00D69A8: 40006bb2                 call    _objc_msgSend
F00D69AC: 9a100011                 mov     %l1, %o5
F00D69B0: 80a46004                 cmp     %l1, 4
F00D69B4: 12800032                 bne     locret_F00D6A7C
F00D69B8: 01000000                 nop
F00D69BC: d006208c                 ld      [%i0+0x8C], %o0
F00D69C0: 80a22000                 cmp     %o0, 0
F00D69C4: 1280002e                 bne     locret_F00D6A7C
F00D69C8: 80a42001                 cmp     %l0, 1
F00D69CC: 1280002c                 bne     locret_F00D6A7C
F00D69D0: 133c0505                 sethi   %hi(paDeviceflags), %o1! SEL
F00D69D4: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D69D8: 40006ba6                 call    _objc_msgSend
F00D69DC: d2026254                 ld      [%o1+%lo(paDeviceflags)], %o1
F00D69E0: b6100008                 mov     %o0, %i3
F00D69E4: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D69E8: 133c0505                 sethi   %hi(paAlphalock), %o1! SEL
F00D69EC: 40006ba1                 call    _objc_msgSend
F00D69F0: d2026248                 ld      [%o1+%lo(paAlphalock)], %o1
F00D69F4: 912a2018                 sll     %o0, 24, %o0
F00D69F8: 80a00008                 cmp     %g0, %o0
F00D69FC: 133c0505                 sethi   %hi(paSetalphalock), %o1
F00D6A00: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6A04: a0603fff                 subc    %g0, -1, %l0
F00D6A08: d2026244                 ld      [%o1+%lo(paSetalphalock)], %o1! SEL
F00D6A0C: 40006b99                 call    _objc_msgSend
F00D6A10: 94100010                 mov     %l0, %o2
F00D6A14: 80a42000                 cmp     %l0, 0
F00D6A18: 02800004                 be      loc_F00D6A28
F00D6A1C: 11000040                 sethi   0x10000, %o0
F00D6A20: 10800003                 ba      loc_F00D6A2C
F00D6A24: b616c008                 bset    %o0, %i3
F00D6A28: b60ec012                 and     %i3, %l2, %i3
F00D6A2C: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6A30: 133c0505                 sethi   %hi(paSetdeviceflags), %o1
F00D6A34: d2026240                 ld      [%o1+%lo(paSetdeviceflags)], %o1! SEL
F00D6A38: 40006b8e                 call    _objc_msgSend
F00D6A3C: 9410001b                 mov     %i3, %o2
F00D6A40: 9410200c                 mov     0xC, %o2
F00D6A44: 9610001b                 mov     %i3, %o3
F00D6A48: 9810001a                 mov     %i2, %o4
F00D6A4C: 9a102000                 mov     0, %o5
F00D6A50: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6A54: 133c0505                 sethi   %hi(paKeyboardeventF), %o1
F00D6A58: d2026234                 ld      [%o1+%lo(paKeyboardeventF)], %o1! SEL
F00D6A5C: c023a05c                 clr     [%sp+0x80+var_24]
F00D6A60: c023a060                 clr     [%sp+0x80+var_20]
F00D6A64: 40006b83                 call    _objc_msgSend
F00D6A68: c023a064                 clr     [%sp+0x80+var_1C]
F00D6A6C: 30800004                 ba,a    locret_F00D6A7C
F00D6A70: 80a46006                 cmp     %l1, 6
F00D6A74: 04bfffc3                 ble     loc_F00D6980
F00D6A78: 92026002                 inc     2, %o1
F00D6A7C: 81c7e008                 ret
F00D6A80: 81e80000                 restore
