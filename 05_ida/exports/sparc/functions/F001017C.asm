F001017C: 9de3bf88                 save    %sp, -0x78, %sp! int
F0010180: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0010184: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010188: e2026024                 ld      [%o1+0x24], %l1
F001018C: d6044000                 ld      [%l1], %o3
F0010190: 80a2e005                 cmp     %o3, 5
F0010194: 18800059                 bgu     loc_F00102F8
F0010198: 981421dc                 or      %l0, %lo(dword_F0133DDC), %o4
F001019C: 9207bff0                 add     %fp, var_10, %o1! int
F00101A0: 94102008                 mov     8, %o2! int
F00101A4: 972ae003                 sll     %o3, 3, %o3
F00101A8: d8033ffc                 ld      [%o4-4], %o4! int
F00101AC: 9602e260                 inc     0x260, %o3! int
F00101B0: d0046004                 ld      [%l1+4], %o0! int
F00101B4: 40021fa9                 call    _copyin
F00101B8: a403000b                 add     %o4, %o3, %l2
F00101BC: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F00101C0: d02a6038                 stb     %o0, [%o1+0x38]
F00101C4: d00421dc                 ld      [%l0+0x1DC], %o0
F00101C8: d04a2038                 ldsb    [%o0+0x38], %o0
F00101CC: 80a22000                 cmp     %o0, 0
F00101D0: 12800050                 bne     locret_F0010310
F00101D4: d007bff0                 ld      [%fp+var_10], %o0
F00101D8: d204a004                 ld      [%l2+4], %o1
F00101DC: 80a20009                 cmp     %o0, %o1
F00101E0: 14800005                 bg      loc_F00101F4
F00101E4: d007bff4                 ld      [%fp+var_C], %o0
F00101E8: 80a20009                 cmp     %o0, %o1
F00101EC: 24800008                 ble,a   loc_F001020C
F00101F0: d0044000                 ld      [%l1], %o0
F00101F4: 7ffffdde                 call    _suser
F00101F8: 01000000                 nop
F00101FC: 80a22000                 cmp     %o0, 0
F0010200: 02800044                 be      locret_F0010310
F0010204: 01000000                 nop
F0010208: d0044000                 ld      [%l1], %o0
F001020C: 80a22003                 cmp     %o0, 3
F0010210: 3280003d                 bne,a   loc_F0010304
F0010214: d007bff0                 ld      [%fp+var_10], %o0
F0010218: de07bff0                 ld      [%fp+var_10], %o7
F001021C: da048000                 ld      [%l2], %o5
F0010220: 80a3c00d                 cmp     %o7, %o5
F0010224: 0480001b                 ble     loc_F0010290
F0010228: 9207bfec                 add     %fp, var_14, %o1! address
F001022C: 113c04d0                 sethi   %hi(_page_mask), %o0
F0010230: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0010234: 053c04cf                 sethi   %hi(_active_u), %g2
F0010238: da00a1d8                 ld      [%g2+%lo(_active_u)], %o5
F001023C: a010a1d8                 or      %g2, %lo(_active_u), %l0
F0010240: d4048000                 ld      [%l2], %o2
F0010244: 98380008                 xnor    %g0, %o0, %o4
F0010248: 9603c008                 add     %o7, %o0, %o3
F001024C: 860ac00c                 and     %o3, %o4, %g3
F0010250: 94028008                 add     %o2, %o0, %o2
F0010254: d6034000                 ld      [%o5], %o3
F0010258: 113c04d0                 sethi   %hi(_active_threads), %o0
F001025C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0010260: 940a800c                 and     %o2, %o4, %o2
F0010264: d602e084                 ld      [%o3+0x84], %o3
F0010268: 9420c00a                 sub     %g3, %o2, %o2! size
F001026C: d002200c                 ld      [%o0+0xC], %o0
F0010270: 9622c00f                 sub     %o3, %o7, %o3
F0010274: 960ac00c                 and     %o3, %o4, %o3! flags
F0010278: d627bfec                 st      %o3, [%fp+var_14]
F001027C: d002200c                 ld      [%o0+0xC], %o0! target_task
F0010280: 4001e968                 call    _vm_allocate
F0010284: 96102000                 mov     0, %o3
F0010288: 10800019                 ba      loc_F00102EC
F001028C: 80a22000                 cmp     %o0, 0
F0010290: 113c04d0                 sethi   %hi(_page_mask), %o0
F0010294: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F0010298: 193c04cf                 sethi   %hi(_active_u), %o4
F001029C: d20321d8                 ld      [%o4+%lo(_active_u)], %o1
F00102A0: a01321d8                 or      %o4, %lo(_active_u), %l0
F00102A4: d0048000                 ld      [%l2], %o0
F00102A8: 9638000a                 xnor    %g0, %o2, %o3
F00102AC: 9002000a                 add     %o0, %o2, %o0
F00102B0: 860a000b                 and     %o0, %o3, %g3
F00102B4: 9403c00a                 add     %o7, %o2, %o2
F00102B8: d0024000                 ld      [%o1], %o0
F00102BC: 940a800b                 and     %o2, %o3, %o2
F00102C0: d2022084                 ld      [%o0+0x84], %o1
F00102C4: 9420c00a                 sub     %g3, %o2, %o2! size
F00102C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00102CC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00102D0: 9222400d                 sub     %o1, %o5, %o1
F00102D4: d002200c                 ld      [%o0+0xC], %o0
F00102D8: 920a400b                 and     %o1, %o3, %o1! address
F00102DC: d002200c                 ld      [%o0+0xC], %o0! target_task
F00102E0: 4001e970                 call    _vm_deallocate
F00102E4: d227bfec                 st      %o1, [%fp+var_14]
F00102E8: 80a22000                 cmp     %o0, 0
F00102EC: 02800006                 be      loc_F0010304
F00102F0: d007bff0                 ld      [%fp+var_10], %o0
F00102F4: d2042004                 ld      [%l0+4], %o1
F00102F8: 90102016                 mov     0x16, %o0
F00102FC: 10800005                 ba      locret_F0010310
F0010300: d02a6038                 stb     %o0, [%o1+0x38]
F0010304: d0248000                 st      %o0, [%l2]
F0010308: d007bff4                 ld      [%fp+var_C], %o0
F001030C: d024a004                 st      %o0, [%l2+4]
F0010310: 81c7e008                 ret
F0010314: 81e80000                 restore
