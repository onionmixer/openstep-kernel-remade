F005D68C: 9de3bf98                 save    %sp, -0x68, %sp
F005D690: e4068000                 ld      [%i2], %l2
F005D694: e206a008                 ld      [%i2+8], %l1
F005D698: 80a46000                 cmp     %l1, 0
F005D69C: 0280001d                 be      loc_F005D710
F005D6A0: e006a004                 ld      [%i2+4], %l0
F005D6A4: 90100018                 mov     %i0, %o0
F005D6A8: 92100010                 mov     %l0, %o1
F005D6AC: 94100019                 mov     %i1, %o2
F005D6B0: 7ffff9fd                 call    _ipc_right_check
F005D6B4: 9610001a                 mov     %i2, %o3
F005D6B8: 80a22000                 cmp     %o0, 0
F005D6BC: 0280000f                 be      loc_F005D6F8
F005D6C0: 11001000                 sethi   0x400000, %o0
F005D6C4: 808c8008                 btst    %o0, %l2
F005D6C8: 02800008                 be      loc_F005D6E8
F005D6CC: 90100018                 mov     %i0, %o0
F005D6D0: 9210001b                 mov     %i3, %o1
F005D6D4: 7fffd9e9                 call    _ipc_entry_dealloc
F005D6D8: 9410001c                 mov     %i4, %o2
F005D6DC: c0262008                 clr     [%i0+8]
F005D6E0: 10800066                 ba      locret_F005D878
F005D6E4: b010200f                 mov     0xF, %i0
F005D6E8: e4068000                 ld      [%i2], %l2
F005D6EC: a2102000                 mov     0, %l1
F005D6F0: 10800008                 ba      loc_F005D710
F005D6F4: a0102000                 mov     0, %l0
F005D6F8: d004202c                 ld      [%l0+0x2C], %o0
F005D6FC: 932c6003                 sll     %l1, 3, %o1
F005D700: 90020009                 add     %o0, %o1, %o0
F005D704: f6222004                 st      %i3, [%o0+4]
F005D708: c0240000                 clr     [%l0]
F005D70C: c026a008                 clr     [%i2+8]
F005D710: 11000800                 sethi   0x200000, %o0
F005D714: 808c8008                 btst    %o0, %l2
F005D718: 02800005                 be      loc_F005D72C
F005D71C: 90100018                 mov     %i0, %o0
F005D720: 92100019                 mov     %i1, %o1
F005D724: 7fffea40                 call    _ipc_marequest_rename
F005D728: 9410001b                 mov     %i3, %o2
F005D72C: e2272008                 st      %l1, [%i4+8]
F005D730: e0272004                 st      %l0, [%i4+4]
F005D734: 110007c0                 sethi   0x1F0000, %o0
F005D738: 940c8008                 and     %l2, %o0, %o2
F005D73C: 170000c0                 sethi   0x30000, %o3
F005D740: 80a2800b                 cmp     %o2, %o3
F005D744: 113fe000                 sethi   -0x800000, %o0
F005D748: d2070000                 ld      [%i4], %o1
F005D74C: 902c8008                 andn    %l2, %o0, %o0
F005D750: 92124008                 bset    %o0, %o1
F005D754: 02800025                 be      loc_F005D7E8
F005D758: d2270000                 st      %o1, [%i4]
F005D75C: 80a2800b                 cmp     %o2, %o3
F005D760: 1880000a                 bgu     loc_F005D788
F005D764: 11000040                 sethi   0x10000, %o0
F005D768: 80a28008                 cmp     %o2, %o0
F005D76C: 02800013                 be      loc_F005D7B8
F005D770: 11000080                 sethi   0x20000, %o0
F005D774: 80a28008                 cmp     %o2, %o0
F005D778: 0280001d                 be      loc_F005D7EC
F005D77C: b8100010                 mov     %l0, %i4
F005D780: 10800035                 ba      loc_F005D854
F005D784: 113c043d                 sethi   -0xFEF0C00, %o0
F005D788: 11000200                 sethi   0x80000, %o0
F005D78C: 80a28008                 cmp     %o2, %o0
F005D790: 02800024                 be      loc_F005D820
F005D794: b8100010                 mov     %l0, %i4
F005D798: 18800003                 bgu     loc_F005D7A4
F005D79C: 11000400                 sethi   0x100000, %o0
F005D7A0: 11000100                 sethi   0x40000, %o0
F005D7A4: 80a28008                 cmp     %o2, %o0
F005D7A8: 2280002e                 be,a    loc_F005D860
F005D7AC: c026a004                 clr     [%i2+4]
F005D7B0: 10800029                 ba      loc_F005D854
F005D7B4: 113c043d                 sethi   -0xFEF0C00, %o0
F005D7B8: 90100018                 mov     %i0, %o0
F005D7BC: 92100010                 mov     %l0, %o1
F005D7C0: 94100019                 mov     %i1, %o2
F005D7C4: 7fffdb7b                 call    _ipc_hash_delete
F005D7C8: 9610001a                 mov     %i2, %o3
F005D7CC: 90100018                 mov     %i0, %o0
F005D7D0: 92100010                 mov     %l0, %o1
F005D7D4: 9410001b                 mov     %i3, %o2
F005D7D8: 7fffdb61                 call    _ipc_hash_insert
F005D7DC: 9610001c                 mov     %i4, %o3
F005D7E0: 10800020                 ba      loc_F005D860
F005D7E4: c026a004                 clr     [%i2+4]
F005D7E8: b8100010                 mov     %l0, %i4
F005D7EC: d0070000                 ld      [%i4], %o0
F005D7F0: 80a22000                 cmp     %o0, 0
F005D7F4: 12bffffe                 bne     loc_F005D7EC
F005D7F8: 01000000                 nop
F005D7FC: 4000e5ab                 call    _simple_lock_try
F005D800: 9010001c                 mov     %i4, %o0
F005D804: 80a22000                 cmp     %o0, 0
F005D808: 02bffff9                 be      loc_F005D7EC
F005D80C: 01000000                 nop
F005D810: f6272010                 st      %i3, [%i4+0x10]
F005D814: c0270000                 clr     [%i4]
F005D818: 10800012                 ba      loc_F005D860
F005D81C: c026a004                 clr     [%i2+4]
F005D820: d0070000                 ld      [%i4], %o0
F005D824: 80a22000                 cmp     %o0, 0
F005D828: 12bffffe                 bne     loc_F005D820
F005D82C: 01000000                 nop
F005D830: 4000e59e                 call    _simple_lock_try
F005D834: 9010001c                 mov     %i4, %o0! char *
F005D838: 80a22000                 cmp     %o0, 0
F005D83C: 02bffff9                 be      loc_F005D820
F005D840: 01000000                 nop
F005D844: f627200c                 st      %i3, [%i4+0xC]
F005D848: c0270000                 clr     [%i4]
F005D84C: 10800005                 ba      loc_F005D860
F005D850: c026a004                 clr     [%i2+4]
F005D854: 7ffede47                 call    _panic
F005D858: 90122370                 bset    0x370, %o0
F005D85C: c026a004                 clr     [%i2+4]
F005D860: 90100018                 mov     %i0, %o0
F005D864: 92100019                 mov     %i1, %o1
F005D868: 7fffd984                 call    _ipc_entry_dealloc
F005D86C: 9410001a                 mov     %i2, %o2
F005D870: c0262008                 clr     [%i0+8]
F005D874: b0102000                 mov     0, %i0
F005D878: 81c7e008                 ret
F005D87C: 81e80000                 restore
