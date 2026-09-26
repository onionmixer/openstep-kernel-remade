F00A8554: 9de3bf90                 save    %sp, -0x70, %sp
F00A8558: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A855C: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F00A8560: 80a42000                 cmp     %l0, 0
F00A8564: 1280000b                 bne     loc_F00A8590
F00A8568: f427a04c                 st      %i2, [%fp+arg_4C]
F00A856C: 113c046e                 sethi   %hi(aKernelTrapCall), %o0! "kernel_trap() called with current_threa"...
F00A8570: 7ffdb03a                 call    _printf
F00A8574: 901223c8                 bset    %lo(aKernelTrapCall), %o0! "kernel_trap() called with current_threa"...
F00A8578: 90100018                 mov     %i0, %o0
F00A857C: 92100019                 mov     %i1, %o1
F00A8580: d407a04c                 ld      [%fp+arg_4C], %o2
F00A8584: 9610001b                 mov     %i3, %o3
F00A8588: 7ffffc26                 call    _badtrap
F00A858C: 9810001c                 mov     %i4, %o4
F00A8590: 113c04cf                 sethi   %hi(_active_u), %o0
F00A8594: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F00A8598: d0024000                 ld      [%o1], %o0
F00A859C: 80a22000                 cmp     %o0, 0
F00A85A0: 02800006                 be      loc_F00A85B8
F00A85A4: 80a62009                 cmp     %i0, 9
F00A85A8: d0026174                 ld      [%o1+0x174], %o0
F00A85AC: d027bff0                 st      %o0, [%fp+var_10]
F00A85B0: d0026178                 ld      [%o1+0x178], %o0
F00A85B4: d027bff4                 st      %o0, [%fp+var_C]
F00A85B8: 0280005d                 be      loc_F00A872C
F00A85BC: 80a62009                 cmp     %i0, 9
F00A85C0: 18800011                 bgu     loc_F00A8604
F00A85C4: 80a62002                 cmp     %i0, 2
F00A85C8: 22800025                 be,a    loc_F00A865C
F00A85CC: 98102002                 mov     2, %o4
F00A85D0: 18800006                 bgu     loc_F00A85E8
F00A85D4: 80a62001                 cmp     %i0, 1
F00A85D8: 02800036                 be      loc_F00A86B0
F00A85DC: 113c0464                 sethi   -0xFEE7000, %o0
F00A85E0: 10800019                 ba      loc_F00A8644
F00A85E4: 90100018                 mov     %i0, %o0
F00A85E8: 80a62007                 cmp     %i0, 7
F00A85EC: 0280001f                 be      loc_F00A8668
F00A85F0: 80a62008                 cmp     %i0, 8
F00A85F4: 028000a4                 be      loc_F00A8884
F00A85F8: 113c046e                 sethi   -0xFEE4800, %o0
F00A85FC: 10800012                 ba      loc_F00A8644
F00A8600: 90100018                 mov     %i0, %o0
F00A8604: 80a6202b                 cmp     %i0, 0x2B ! '+'
F00A8608: 0280001c                 be      loc_F00A8678
F00A860C: 113c0464                 sethi   -0xFEE7000, %o0
F00A8610: 18800008                 bgu     loc_F00A8630
F00A8614: 80a62021                 cmp     %i0, 0x21 ! '!'
F00A8618: 02800026                 be      loc_F00A86B0
F00A861C: 80a62029                 cmp     %i0, 0x29 ! ')'
F00A8620: 02800044                 be      loc_F00A8730
F00A8624: 113c04f8                 sethi   -0xFEC2000, %o0
F00A8628: 10800007                 ba      loc_F00A8644
F00A862C: 90100018                 mov     %i0, %o0
F00A8630: 80a62081                 cmp     %i0, 0x81
F00A8634: 028000a5                 be      loc_F00A88C8
F00A8638: 80a62088                 cmp     %i0, 0x88
F00A863C: 028000a7                 be      loc_F00A88D8
F00A8640: 90100018                 mov     %i0, %o0
F00A8644: 92100019                 mov     %i1, %o1
F00A8648: d407a04c                 ld      [%fp+arg_4C], %o2
F00A864C: 9610001b                 mov     %i3, %o3
F00A8650: 7ffffbf4                 call    _badtrap
F00A8654: 9810001c                 mov     %i4, %o4
F00A8658: 98102002                 mov     2, %o4
F00A865C: d4066004                 ld      [%i1+4], %o2
F00A8660: 108000a6                 ba      loc_F00A88F8
F00A8664: 96102002                 mov     2, %o3
F00A8668: 98102001                 mov     1, %o4
F00A866C: d4066004                 ld      [%i1+4], %o2
F00A8670: 108000a2                 ba      loc_F00A88F8
F00A8674: 96102304                 mov     0x304, %o3
F00A8678: d00222b0                 ld      [%o0+0x2B0], %o0
F00A867C: 80a22000                 cmp     %o0, 0
F00A8680: 12800009                 bne     loc_F00A86A4
F00A8684: 98102001                 mov     1, %o4
F00A8688: 9010202b                 mov     0x2B, %o0 ! '+'
F00A868C: 92100019                 mov     %i1, %o1
F00A8690: d407a04c                 ld      [%fp+arg_4C], %o2
F00A8694: 9610001b                 mov     %i3, %o3
F00A8698: 7ffffc52                 call    _check_fsr
F00A869C: 9810001c                 mov     %i4, %o4
F00A86A0: 98102001                 mov     1, %o4
F00A86A4: d407a04c                 ld      [%fp+arg_4C], %o2
F00A86A8: 10800094                 ba      loc_F00A88F8
F00A86AC: 96102306                 mov     0x306, %o3
F00A86B0: d00222b0                 ld      [%o0+0x2B0], %o0
F00A86B4: 80a22000                 cmp     %o0, 0
F00A86B8: 12800009                 bne     loc_F00A86DC
F00A86BC: 113c04f8                 sethi   -0xFEC2000, %o0
F00A86C0: 90100018                 mov     %i0, %o0
F00A86C4: 92100019                 mov     %i1, %o1
F00A86C8: d407a04c                 ld      [%fp+arg_4C], %o2
F00A86CC: 9610001b                 mov     %i3, %o3
F00A86D0: 7ffffc44                 call    _check_fsr
F00A86D4: 9810001c                 mov     %i4, %o4
F00A86D8: 113c04f8                 sethi   -0xFEC2000, %o0
F00A86DC: d0022120                 ld      [%o0+0x120], %o0
F00A86E0: 80a22080                 cmp     %o0, 0x80
F00A86E4: 3280000f                 bne,a   loc_F00A8720
F00A86E8: 98102001                 mov     1, %o4
F00A86EC: 9136e00a                 srl     %i3, 10, %o0
F00A86F0: 808a20ff                 btst    0xFF, %o0
F00A86F4: 0280000a                 be      loc_F00A871C
F00A86F8: 90102000                 mov     0, %o0
F00A86FC: 9210001b                 mov     %i3, %o1
F00A8700: d407a04c                 ld      [%fp+arg_4C], %o2
F00A8704: 96100018                 mov     %i0, %o3
F00A8708: 7fffba8b                 call    _ebe_handler
F00A870C: 98100019                 mov     %i1, %o4
F00A8710: 80a23fff                 cmp     %o0, -1
F00A8714: 1280007d                 bne     locret_F00A8908
F00A8718: 01000000                 nop
F00A871C: 98102001                 mov     1, %o4
F00A8720: d407a04c                 ld      [%fp+arg_4C], %o2
F00A8724: 10800075                 ba      loc_F00A88F8
F00A8728: 96102301                 mov     0x301, %o3
F00A872C: 113c04f8                 sethi   -0xFEC2000, %o0
F00A8730: d0022120                 ld      [%o0+0x120], %o0
F00A8734: 80a22080                 cmp     %o0, 0x80
F00A8738: 1280000f                 bne     loc_F00A8774
F00A873C: 9007a04c                 add     %fp, arg_4C, %o0
F00A8740: 9136e00a                 srl     %i3, 10, %o0
F00A8744: 808a20ff                 btst    0xFF, %o0
F00A8748: 0280000a                 be      loc_F00A8770
F00A874C: 90102000                 mov     0, %o0
F00A8750: 9210001b                 mov     %i3, %o1
F00A8754: d407a04c                 ld      [%fp+arg_4C], %o2
F00A8758: 96100018                 mov     %i0, %o3
F00A875C: 7fffba76                 call    _ebe_handler
F00A8760: 98100019                 mov     %i1, %o4
F00A8764: 80a23fff                 cmp     %o0, -1
F00A8768: 12800068                 bne     locret_F00A8908
F00A876C: 01000000                 nop
F00A8770: 9007a04c                 add     %fp, arg_4C, %o0
F00A8774: 92100019                 mov     %i1, %o1
F00A8778: 9410001c                 mov     %i4, %o2
F00A877C: 7fffb40b                 call    _module_wkaround
F00A8780: 9610001b                 mov     %i3, %o3
F00A8784: 113c0464                 sethi   %hi(_small_4m), %o0
F00A8788: d00222b0                 ld      [%o0+%lo(_small_4m)], %o0
F00A878C: 80a22000                 cmp     %o0, 0
F00A8790: 12800008                 bne     loc_F00A87B0
F00A8794: 90100018                 mov     %i0, %o0
F00A8798: 92100019                 mov     %i1, %o1
F00A879C: d407a04c                 ld      [%fp+arg_4C], %o2
F00A87A0: 9610001b                 mov     %i3, %o3
F00A87A4: 7ffffc0f                 call    _check_fsr
F00A87A8: 9810001c                 mov     %i4, %o4
F00A87AC: 90100018                 mov     %i0, %o0
F00A87B0: 92100019                 mov     %i1, %o1
F00A87B4: d407a04c                 ld      [%fp+arg_4C], %o2
F00A87B8: 9610001b                 mov     %i3, %o3
F00A87BC: 7ffffbe6                 call    _get_faulttype
F00A87C0: 9810001c                 mov     %i4, %o4
F00A87C4: 80a42000                 cmp     %l0, 0
F00A87C8: 02800005                 be      loc_F00A87DC
F00A87CC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00A87D0: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00A87D4: e24a2038                 ldsb    [%o0+0x38], %l1
F00A87D8: c02a2038                 clrb    [%o0+0x38]
F00A87DC: d407a04c                 ld      [%fp+arg_4C], %o2
F00A87E0: 113bffff901223ff         set     -0x10000001, %o0
F00A87E8: 80a28008                 cmp     %o2, %o0
F00A87EC: 08800008                 bleu    loc_F00A880C
F00A87F0: 80a72002                 cmp     %i4, 2
F00A87F4: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A87F8: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00A87FC: 96102001                 mov     1, %o3
F00A8800: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00A8804: 10800007                 ba      loc_F00A8820
F00A8808: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00A880C: d004200c                 ld      [%l0+0xC], %o0
F00A8810: 133c04d0                 sethi   %hi(_page_mask), %o1
F00A8814: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F00A8818: 96102001                 mov     1, %o3
F00A881C: d002200c                 ld      [%o0+0xC], %o0
F00A8820: 12800003                 bne     loc_F00A882C
F00A8824: 922a8009                 andn    %o2, %o1, %o1
F00A8828: 96102003                 mov     3, %o3
F00A882C: 9410000b                 mov     %o3, %o2
F00A8830: 96102000                 mov     0, %o3
F00A8834: 7fff6296                 call    _vm_fault
F00A8838: 98102000                 mov     0, %o4
F00A883C: 80a42000                 cmp     %l0, 0
F00A8840: 02800005                 be      loc_F00A8854
F00A8844: 92100008                 mov     %o0, %o1! int
F00A8848: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00A884C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00A8850: e22a2038                 stb     %l1, [%o0+0x38]
F00A8854: 80a26000                 cmp     %o1, 0
F00A8858: 0280002c                 be      locret_F00A8908
F00A885C: 01000000                 nop
F00A8860: d0042074                 ld      [%l0+0x74], %o0! jmp_buf
F00A8864: 80a22000                 cmp     %o0, 0
F00A8868: 02800004                 be      loc_F00A8878
F00A886C: 98102001                 mov     1, %o4
F00A8870: 7fffb93d                 call    _longjmp
F00A8874: c0242074                 clr     [%l0+0x74]
F00A8878: d407a04c                 ld      [%fp+arg_4C], %o2
F00A887C: 1080001f                 ba      loc_F00A88F8
F00A8880: 96100009                 mov     %o1, %o3
F00A8884: d0022008                 ld      [%o0+8], %o0
F00A8888: 80a22000                 cmp     %o0, 0
F00A888C: 0280000b                 be      loc_F00A88B8
F00A8890: 113c046e                 sethi   %hi(_tudebugfpe), %o0
F00A8894: d0022010                 ld      [%o0+%lo(_tudebugfpe)], %o0
F00A8898: 80a22000                 cmp     %o0, 0
F00A889C: 02800007                 be      loc_F00A88B8
F00A88A0: 90102008                 mov     8, %o0
F00A88A4: 92100019                 mov     %i1, %o1
F00A88A8: d407a04c                 ld      [%fp+arg_4C], %o2
F00A88AC: 96102000                 mov     0, %o3
F00A88B0: 400002d2                 call    _showregs
F00A88B4: 98102000                 mov     0, %o4
F00A88B8: 98102003                 mov     3, %o4
F00A88BC: d407a04c                 ld      [%fp+arg_4C], %o2
F00A88C0: 1080000e                 ba      loc_F00A88F8
F00A88C4: 96102008                 mov     8, %o3
F00A88C8: 98102006                 mov     6, %o4
F00A88CC: d4066004                 ld      [%i1+4], %o2
F00A88D0: 1080000a                 ba      loc_F00A88F8
F00A88D4: 96102081                 mov     0x81, %o3
F00A88D8: d4066004                 ld      [%i1+4], %o2
F00A88DC: 98102006                 mov     6, %o4
F00A88E0: d2066008                 ld      [%i1+8], %o1
F00A88E4: 96102081                 mov     0x81, %o3
F00A88E8: d0066008                 ld      [%i1+8], %o0
F00A88EC: d2266004                 st      %o1, [%i1+4]
F00A88F0: 90022004                 inc     4, %o0
F00A88F4: d0266008                 st      %o0, [%i1+8]
F00A88F8: 9010000c                 mov     %o4, %o0
F00A88FC: 9210000b                 mov     %o3, %o1
F00A8900: 7fff2043                 call    _kdp_raise_exception
F00A8904: 96100019                 mov     %i1, %o3
F00A8908: 81c7e008                 ret
F00A890C: 81e80000                 restore
