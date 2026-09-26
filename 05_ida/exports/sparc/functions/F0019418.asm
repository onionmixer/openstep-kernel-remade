F0019418: 9de3bf88                 save    %sp, -0x78, %sp
F001941C: 40000733                 call    _ttynty
F0019420: 90100018                 mov     %i0, %o0
F0019424: aa100008                 mov     %o0, %l5
F0019428: ae102000                 mov     0, %l7
F001942C: ac102000                 mov     0, %l6
F0019430: 4001f5e2                 call    _spltty
F0019434: e606203c                 ld      [%i0+0x3C], %l3
F0019438: a4100008                 mov     %o0, %l2
F001943C: 11080000                 sethi   0x20000000, %o0
F0019440: 808cc008                 btst    %o0, %l3
F0019444: 02800004                 be      loc_F0019454
F0019448: 01000000                 nop
F001944C: 7ffffaf9                 call    _ttypend
F0019450: 90100018                 mov     %i0, %o0
F0019454: 4001f634                 call    _splx
F0019458: 90100012                 mov     %l2, %o0
F001945C: d4062040                 ld      [%i0+0x40], %o2
F0019460: 808aa010                 btst    0x10, %o2
F0019464: 12800020                 bne     loc_F00194E4
F0019468: 233c04cf                 sethi   %hi(_active_u), %l1
F001946C: d0056010                 ld      [%l5+0x10], %o0
F0019470: 13000020                 sethi   0x8000, %o1
F0019474: 808a0009                 btst    %o1, %o0
F0019478: 3280001c                 bne,a   loc_F00194E8
F001947C: d40461d8                 ld      [%l1+%lo(_active_u)], %o2
F0019480: 21000008                 sethi   0x2000, %l0
F0019484: 233c04cf                 sethi   -0xFECC400, %l1
F0019488: 25000010                 sethi   0x4000, %l2
F001948C: 808a8009                 btst    %o1, %o2
F0019490: 02800050                 be      loc_F00195D0
F0019494: 808a8010                 btst    %l0, %o2
F0019498: 02800007                 be      loc_F00194B4
F001949C: d00461d8                 ld      [%l1+0x1D8], %o0
F00194A0: d0020000                 ld      [%o0], %o0
F00194A4: d0022014                 ld      [%o0+0x14], %o0
F00194A8: b0102023                 mov     0x23, %i0 ! '#'
F00194AC: 108000e9                 ba      loc_F0019850
F00194B0: 808a0012                 btst    %l2, %o0
F00194B4: 90100018                 mov     %i0, %o0! unsigned int
F00194B8: 7fffe470                 call    _sleep
F00194BC: 9210201c                 mov     0x1C, %o1
F00194C0: d4062040                 ld      [%i0+0x40], %o2
F00194C4: 808aa010                 btst    0x10, %o2
F00194C8: 12800006                 bne     loc_F00194E0
F00194CC: 13000020                 sethi   0x8000, %o1
F00194D0: d0056010                 ld      [%l5+0x10], %o0
F00194D4: 808a0009                 btst    %o1, %o0
F00194D8: 02bfffee                 be      loc_F0019490
F00194DC: 808a8009                 btst    %o1, %o2
F00194E0: 233c04cf                 sethi   -0xFECC400, %l1
F00194E4: d40461d8                 ld      [%l1+0x1D8], %o2
F00194E8: e0028000                 ld      [%o2], %l0
F00194EC: d2042014                 ld      [%l0+0x14], %o1
F00194F0: 11000010                 sethi   0x4000, %o0
F00194F4: 808a4008                 btst    %o0, %o1
F00194F8: 22800021                 be,a    loc_F001957C
F00194FC: d002a164                 ld      [%o2+0x164], %o0
F0019500: 7fffd588                 call    _get_posix_proc
F0019504: d0542030                 ldsh    [%l0+0x30], %o0
F0019508: d20461d8                 ld      [%l1+0x1D8], %o1
F001950C: d2026164                 ld      [%o1+0x164], %o1
F0019510: 80a60009                 cmp     %i0, %o1
F0019514: 12800038                 bne     loc_F00195F4
F0019518: 01000000                 nop
F001951C: d4022010                 ld      [%o0+0x10], %o2
F0019520: d0562044                 ldsh    [%i0+0x44], %o0
F0019524: d602a00c                 ld      [%o2+0xC], %o3
F0019528: 80a2c008                 cmp     %o3, %o0
F001952C: 02800032                 be      loc_F00195F4
F0019530: 13000400                 sethi   0x100000, %o1
F0019534: d0042020                 ld      [%l0+0x20], %o0
F0019538: 808a0009                 btst    %o1, %o0
F001953C: 32800133                 bne,a   locret_F0019A08
F0019540: b0102005                 mov     5, %i0
F0019544: d004201c                 ld      [%l0+0x1C], %o0
F0019548: 808a0009                 btst    %o1, %o0
F001954C: 3280012f                 bne,a   locret_F0019A08
F0019550: b0102005                 mov     5, %i0
F0019554: d002a010                 ld      [%o2+0x10], %o0
F0019558: 80a22000                 cmp     %o0, 0
F001955C: 0280001d                 be      loc_F00195D0
F0019560: 11000004                 sethi   0x1000, %o0
F0019564: d2042028                 ld      [%l0+0x28], %o1
F0019568: 808a4008                 btst    %o0, %o1
F001956C: 32800127                 bne,a   locret_F0019A08
F0019570: b0102005                 mov     5, %i0
F0019574: 10800019                 ba      loc_F00195D8
F0019578: 9010000b                 mov     %o3, %o0
F001957C: 80a60008                 cmp     %i0, %o0
F0019580: 1280001d                 bne     loc_F00195F4
F0019584: 01000000                 nop
F0019588: d454202e                 ldsh    [%l0+0x2E], %o2
F001958C: d0562044                 ldsh    [%i0+0x44], %o0
F0019590: 80a28008                 cmp     %o2, %o0
F0019594: 02800018                 be      loc_F00195F4
F0019598: 13000400                 sethi   0x100000, %o1
F001959C: d0042020                 ld      [%l0+0x20], %o0
F00195A0: 808a0009                 btst    %o1, %o0
F00195A4: 32800119                 bne,a   locret_F0019A08
F00195A8: b0102005                 mov     5, %i0
F00195AC: d004201c                 ld      [%l0+0x1C], %o0
F00195B0: 808a0009                 btst    %o1, %o0
F00195B4: 32800115                 bne,a   locret_F0019A08
F00195B8: b0102005                 mov     5, %i0
F00195BC: d2042028                 ld      [%l0+0x28], %o1
F00195C0: 11000004                 sethi   0x1000, %o0
F00195C4: 808a4008                 btst    %o0, %o1
F00195C8: 02800004                 be      loc_F00195D8
F00195CC: 9010000a                 mov     %o2, %o0
F00195D0: 1080010e                 ba      locret_F0019A08
F00195D4: b0102005                 mov     5, %i0
F00195D8: 7fffdfc1                 call    _gsignal
F00195DC: 92102015                 mov     0x15, %o1
F00195E0: 113c04d190122350         set     _lbolt, %o0! unsigned int
F00195E8: 7fffe424                 call    _sleep
F00195EC: 9210201c                 mov     0x1C, %o1
F00195F0: 30bfff90                 ba,a    loc_F0019430
F00195F4: 4001f571                 call    _spltty
F00195F8: 01000000                 nop
F00195FC: 808ce022                 btst    0x22, %l3 ! '"'
F0019600: 0280006e                 be      loc_F00197B8
F0019604: a4100008                 mov     %o0, %l2
F0019608: e00d6016                 ldub    [%l5+0x16], %l0
F001960C: a8100018                 mov     %i0, %l4
F0019610: 80a42000                 cmp     %l0, 0
F0019614: 12800007                 bne     loc_F0019630
F0019618: d40d6015                 ldub    [%l5+0x15], %o2
F001961C: d0060000                 ld      [%i0], %o0
F0019620: 80a2000a                 cmp     %o0, %o2
F0019624: 2680006a                 bl,a    loc_F00197CC
F0019628: d0062040                 ld      [%i0+0x40], %o0
F001962C: 30800091                 ba,a    loc_F0019870
F0019630: 912c2001                 sll     %l0, 1, %o0
F0019634: 90020010                 add     %o0, %l0, %o0
F0019638: 932a2006                 sll     %o0, 6, %o1
F001963C: 90020009                 add     %o0, %o1, %o0
F0019640: 912a2002                 sll     %o0, 2, %o0
F0019644: 90020010                 add     %o0, %l0, %o0
F0019648: 912a2002                 sll     %o0, 2, %o0
F001964C: 90020010                 add     %o0, %l0, %o0
F0019650: 80a2a000                 cmp     %o2, 0
F0019654: 04800025                 ble     loc_F00196E8
F0019658: a12a2005                 sll     %o0, 5, %l0
F001965C: d0060000                 ld      [%i0], %o0
F0019660: 80a22000                 cmp     %o0, 0
F0019664: 04800059                 ble     loc_F00197C8
F0019668: 80a2000a                 cmp     %o0, %o2
F001966C: 16800081                 bge     loc_F0019870
F0019670: 80a5a000                 cmp     %l6, 0
F0019674: 12800004                 bne     loc_F0019684
F0019678: 80a2001a                 cmp     %o0, %i2
F001967C: 10800004                 ba      loc_F001968C
F0019680: ac102001                 mov     1, %l6
F0019684: 04800006                 ble     loc_F001969C
F0019688: 01000000                 nop
F001968C: 7fffe640                 call    _getthetime
F0019690: 9007bff0                 add     %fp, var_10, %o0
F0019694: 10800013                 ba      loc_F00196E0
F0019698: a2100010                 mov     %l0, %l1
F001969C: 7fffe63c                 call    _getthetime
F00196A0: 9007bfe8                 add     %fp, var_18, %o0
F00196A4: d407bfe8                 ld      [%fp+var_18], %o2
F00196A8: d007bff0                 ld      [%fp+var_10], %o0
F00196AC: 94228008                 sub     %o2, %o0, %o2
F00196B0: 932aa005                 sll     %o2, 5, %o1
F00196B4: 9222400a                 sub     %o1, %o2, %o1
F00196B8: 912a6006                 sll     %o1, 6, %o0
F00196BC: 90220009                 sub     %o0, %o1, %o0
F00196C0: 912a2003                 sll     %o0, 3, %o0
F00196C4: d207bfec                 ld      [%fp+var_14], %o1
F00196C8: 9002000a                 add     %o0, %o2, %o0
F00196CC: d407bff4                 ld      [%fp+var_C], %o2
F00196D0: 912a2006                 sll     %o0, 6, %o0
F00196D4: 9222400a                 sub     %o1, %o2, %o1
F00196D8: 90020009                 add     %o0, %o1, %o0
F00196DC: a2240008                 sub     %l0, %o0, %l1
F00196E0: 1080001e                 ba      loc_F0019758
F00196E4: f4050000                 ld      [%l4], %i2
F00196E8: d0060000                 ld      [%i0], %o0
F00196EC: 80a22000                 cmp     %o0, 0
F00196F0: 14800060                 bg      loc_F0019870
F00196F4: 80a5a000                 cmp     %l6, 0
F00196F8: 12800007                 bne     loc_F0019714
F00196FC: 01000000                 nop
F0019700: ac102001                 mov     1, %l6
F0019704: 7fffe622                 call    _getthetime
F0019708: 9007bff0                 add     %fp, var_10, %o0
F001970C: 10800013                 ba      loc_F0019758
F0019710: a2100010                 mov     %l0, %l1
F0019714: 7fffe61e                 call    _getthetime
F0019718: 9007bfe8                 add     %fp, var_18, %o0
F001971C: d407bfe8                 ld      [%fp+var_18], %o2
F0019720: d007bff0                 ld      [%fp+var_10], %o0
F0019724: 94228008                 sub     %o2, %o0, %o2
F0019728: 932aa005                 sll     %o2, 5, %o1
F001972C: 9222400a                 sub     %o1, %o2, %o1
F0019730: 912a6006                 sll     %o1, 6, %o0
F0019734: 90220009                 sub     %o0, %o1, %o0
F0019738: 912a2003                 sll     %o0, 3, %o0
F001973C: d207bfec                 ld      [%fp+var_14], %o1
F0019740: 9002000a                 add     %o0, %o2, %o0
F0019744: d407bff4                 ld      [%fp+var_C], %o2
F0019748: 912a2006                 sll     %o0, 6, %o0
F001974C: 9222400a                 sub     %o1, %o2, %o1
F0019750: 90020009                 add     %o0, %o1, %o0
F0019754: a2240008                 sub     %l0, %o0, %l1
F0019758: 80a46000                 cmp     %l1, 0
F001975C: 04800045                 ble     loc_F0019870
F0019760: 113c043e                 sethi   %hi(_hz), %o0
F0019764: d20223e0                 ld      [%o0+%lo(_hz)], %o1
F0019768: 7fffb366                 call    _umul
F001976C: 90100011                 mov     %l1, %o0
F0019770: 130003d09212623f         set     0xF423F, %o1
F0019778: 90020009                 add     %o0, %o1, %o0! int
F001977C: 130003d0                 sethi   0xF4000, %o1! int
F0019780: 7fffb3a2                 call    _div
F0019784: 92126240                 bset    0x240, %o1
F0019788: a2100008                 mov     %o0, %l1
F001978C: 213c004ba01421e8         set     _wakeup, %l0
F0019794: 90100010                 mov     %l0, %o0
F0019798: 7fffc22f                 call    _untimeout
F001979C: 92100014                 mov     %l4, %o1
F00197A0: 90100010                 mov     %l0, %o0! int
F00197A4: 92100014                 mov     %l4, %o1
F00197A8: 7fffc220                 call    _timeout
F00197AC: 94100011                 mov     %l1, %o2
F00197B0: 10800007                 ba      loc_F00197CC
F00197B4: d0062040                 ld      [%i0+0x40], %o0
F00197B8: d006200c                 ld      [%i0+0xC], %o0
F00197BC: 80a22000                 cmp     %o0, 0
F00197C0: 1480002c                 bg      loc_F0019870
F00197C4: a806200c                 add     %i0, 0xC, %l4
F00197C8: d0062040                 ld      [%i0+0x40], %o0
F00197CC: 808a2010                 btst    0x10, %o0
F00197D0: 12800007                 bne     loc_F00197EC
F00197D4: 94102000                 mov     0, %o2
F00197D8: d2056010                 ld      [%l5+0x10], %o1
F00197DC: 11000020                 sethi   0x8000, %o0
F00197E0: 808a4008                 btst    %o0, %o1
F00197E4: 02800004                 be      loc_F00197F4
F00197E8: 80a2a000                 cmp     %o2, 0
F00197EC: 94102001                 mov     1, %o2
F00197F0: 80a2a000                 cmp     %o2, 0
F00197F4: 3280000a                 bne,a   loc_F001981C
F00197F8: d2062040                 ld      [%i0+0x40], %o1
F00197FC: d0062040                 ld      [%i0+0x40], %o0
F0019800: 808a2004                 btst    4, %o0
F0019804: 22800006                 be,a    loc_F001981C
F0019808: d2062040                 ld      [%i0+0x40], %o1
F001980C: 4001f546                 call    _splx
F0019810: 90100012                 mov     %l2, %o0
F0019814: 1080007d                 ba      locret_F0019A08
F0019818: b0102000                 mov     0, %i0
F001981C: 11000008                 sethi   0x2000, %o0
F0019820: 808a4008                 btst    %o0, %o1
F0019824: 0280000e                 be      loc_F001985C
F0019828: 90100018                 mov     %i0, %o0
F001982C: 4001f53e                 call    _splx
F0019830: 90100012                 mov     %l2, %o0
F0019834: 113c04cf                 sethi   %hi(_active_u), %o0
F0019838: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001983C: d0020000                 ld      [%o0], %o0
F0019840: d2022014                 ld      [%o0+0x14], %o1
F0019844: b0102023                 mov     0x23, %i0 ! '#'
F0019848: 11000010                 sethi   0x4000, %o0! unsigned int
F001984C: 808a4008                 btst    %o0, %o1
F0019850: 3280006e                 bne,a   locret_F0019A08
F0019854: b010200b                 mov     0xB, %i0
F0019858: 3080006c                 ba,a    locret_F0019A08
F001985C: 7fffe387                 call    _sleep
F0019860: 9210201c                 mov     0x1C, %o1
F0019864: 4001f530                 call    _splx
F0019868: 90100012                 mov     %l2, %o0
F001986C: 30bffef1                 ba,a    loc_F0019430
F0019870: 4001f52d                 call    _splx
F0019874: 90100012                 mov     %l2, %o0! FILE *
F0019878: a2102001                 mov     1, %l1
F001987C: 40000b93                 call    _getc
F0019880: 90100014                 mov     %l4, %o0
F0019884: a0920000                 orcc    %o0, %g0, %l0
F0019888: 0680003b                 bl      loc_F0019974
F001988C: 920c20ff                 and     %l0, 0xFF, %o1
F0019890: 80a260ff                 cmp     %o1, 0xFF
F0019894: 02800020                 be      loc_F0019914
F0019898: 90100010                 mov     %l0, %o0
F001989C: d00e2056                 ldub    [%i0+0x56], %o0
F00198A0: 80a24008                 cmp     %o1, %o0
F00198A4: 12800013                 bne     loc_F00198F0
F00198A8: 80a260ff                 cmp     %o1, 0xFF
F00198AC: 808ce020                 btst    0x20, %l3 ! ' '
F00198B0: 12800010                 bne     loc_F00198F0
F00198B4: 80a260ff                 cmp     %o1, 0xFF
F00198B8: d0056010                 ld      [%l5+0x10], %o0
F00198BC: 808a2008                 btst    8, %o0
F00198C0: 0280000c                 be      loc_F00198F0
F00198C4: 80a260ff                 cmp     %o1, 0xFF
F00198C8: d0562044                 ldsh    [%i0+0x44], %o0
F00198CC: 7fffdf04                 call    _gsignal
F00198D0: 92102012                 mov     0x12, %o1
F00198D4: 80a46000                 cmp     %l1, 0
F00198D8: 02800027                 be      loc_F0019974
F00198DC: 90100018                 mov     %i0, %o0! unsigned int
F00198E0: 7fffe366                 call    _sleep
F00198E4: 9210201c                 mov     0x1C, %o1
F00198E8: 10bffed2                 ba      loc_F0019430
F00198EC: ac102000                 mov     0, %l6
F00198F0: 02800009                 be      loc_F0019914
F00198F4: 90100010                 mov     %l0, %o0
F00198F8: d00e2053                 ldub    [%i0+0x53], %o0
F00198FC: 80a24008                 cmp     %o1, %o0
F0019900: 12800005                 bne     loc_F0019914
F0019904: 90100010                 mov     %l0, %o0
F0019908: 808ce022                 btst    0x22, %l3 ! '"'
F001990C: 2280001b                 be,a    loc_F0019978
F0019910: d0060000                 ld      [%i0], %o0
F0019914: 7fffe2d0                 call    _ureadc
F0019918: 92100019                 mov     %i1, %o1
F001991C: ae920000                 orcc    %o0, %g0, %l7
F0019920: 32800016                 bne,a   loc_F0019978
F0019924: d0060000                 ld      [%i0], %o0
F0019928: d0066014                 ld      [%i1+0x14], %o0
F001992C: 80a22000                 cmp     %o0, 0
F0019930: 02800011                 be      loc_F0019974
F0019934: 808ce022                 btst    0x22, %l3 ! '"'
F0019938: 12bfffd1                 bne     loc_F001987C
F001993C: a2102000                 mov     0, %l1
F0019940: 80a4200a                 cmp     %l0, 0xA
F0019944: 2280000d                 be,a    loc_F0019978
F0019948: d0060000                 ld      [%i0], %o0
F001994C: d00e2053                 ldub    [%i0+0x53], %o0
F0019950: 80a40008                 cmp     %l0, %o0
F0019954: 02800006                 be      loc_F001996C
F0019958: 80a420ff                 cmp     %l0, 0xFF
F001995C: d00e2054                 ldub    [%i0+0x54], %o0
F0019960: 80a40008                 cmp     %l0, %o0
F0019964: 12bfffc6                 bne     loc_F001987C
F0019968: 80a420ff                 cmp     %l0, 0xFF
F001996C: 02bfffc4                 be      loc_F001987C
F0019970: a2102000                 mov     0, %l1
F0019974: d0060000                 ld      [%i0], %o0
F0019978: 80a220cb                 cmp     %o0, 0xCB
F001997C: 34800023                 bg,a    locret_F0019A08
F0019980: b0100017                 mov     %l7, %i0
F0019984: 4001f48d                 call    _spltty
F0019988: 01000000                 nop
F001998C: d4062040                 ld      [%i0+0x40], %o2
F0019990: 13002000                 sethi   0x800000, %o1
F0019994: 922a8009                 andn    %o2, %o1, %o1
F0019998: 4001f4e3                 call    _splx
F001999C: d2262040                 st      %o1, [%i0+0x40]
F00199A0: d0062040                 ld      [%i0+0x40], %o0
F00199A4: 13004001                 sethi   0x1000400, %o1! FILE *
F00199A8: 900a0009                 and     %o0, %o1, %o0
F00199AC: 80a22400                 cmp     %o0, 0x400
F00199B0: 32800016                 bne,a   locret_F0019A08
F00199B4: b0100017                 mov     %l7, %i0
F00199B8: d00e2051                 ldub    [%i0+0x51], %o0
F00199BC: 80a220ff                 cmp     %o0, 0xFF
F00199C0: 22800012                 be,a    locret_F0019A08
F00199C4: b0100017                 mov     %l7, %i0
F00199C8: 912a2018                 sll     %o0, 24, %o0
F00199CC: 913a2018                 sra     %o0, 24, %o0! int
F00199D0: 40000c60                 call    _putc
F00199D4: 92062018                 add     %i0, 0x18, %o1
F00199D8: 80a22000                 cmp     %o0, 0
F00199DC: 3280000b                 bne,a   locret_F0019A08
F00199E0: b0100017                 mov     %l7, %i0
F00199E4: 4001f475                 call    _spltty
F00199E8: 01000000                 nop
F00199EC: d2062040                 ld      [%i0+0x40], %o1
F00199F0: 920a7bff                 and     %o1, -0x401, %o1
F00199F4: 4001f4cc                 call    _splx
F00199F8: d2262040                 st      %o1, [%i0+0x40]
F00199FC: 7ffff45f                 call    _ttstart
F0019A00: 90100018                 mov     %i0, %o0
F0019A04: b0100017                 mov     %l7, %i0
F0019A08: 81c7e008                 ret
F0019A0C: 81e80000                 restore
