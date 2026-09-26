F00AE504: 9de3bf98                 save    %sp, -0x68, %sp
F00AE508: d2068000                 ld      [%i2], %o1
F00AE50C: c026601c                 clr     [%i1+0x1C]
F00AE510: c0266020                 clr     [%i1+0x20]
F00AE514: 9132601f                 srl     %o1, 31, %o0
F00AE518: d0264000                 st      %o0, [%i1]
F00AE51C: 90102001                 mov     1, %o0
F00AE520: d0266004                 st      %o0, [%i1+4]
F00AE524: 912a6001                 sll     %o1, 1, %o0
F00AE528: 99322011                 srl     %o0, 17, %o4
F00AE52C: 113ffff090122001         set     -0x3FFF, %o0
F00AE534: 90030008                 add     %o4, %o0, %o0
F00AE538: d0266008                 st      %o0, [%i1+8]
F00AE53C: 912a6010                 sll     %o1, 16, %o0
F00AE540: 95322010                 srl     %o0, 16, %o2
F00AE544: d426600c                 st      %o2, [%i1+0xC]
F00AE548: 111fffc0                 sethi   0x7FFF0000, %o0
F00AE54C: 968a4008                 andcc   %o1, %o0, %o3
F00AE550: 02800005                 be      loc_F00AE564
F00AE554: 9a10000a                 mov     %o2, %o5
F00AE558: 1100004090128008         set     0x10000, %o0
F00AE560: d026600c                 st      %o0, [%i1+0xC]
F00AE564: f6266010                 st      %i3, [%i1+0x10]
F00AE568: f8266014                 st      %i4, [%i1+0x14]
F00AE56C: 1100001f901223fe         set     0x7FFE, %o0
F00AE574: 80a30008                 cmp     %o4, %o0
F00AE578: 14800012                 bg      loc_F00AE5C0
F00AE57C: fa266018                 st      %i5, [%i1+0x18]
F00AE580: 9017001b                 or      %i4, %i3, %o0
F00AE584: d206600c                 ld      [%i1+0xC], %o1
F00AE588: 9012001d                 bset    %i5, %o0
F00AE58C: 80920009                 orcc    %o0, %o1, %g0
F00AE590: 12800004                 bne     loc_F00AE5A0
F00AE594: 80a2e000                 cmp     %o3, 0
F00AE598: 10800020                 ba      locret_F00AE618
F00AE59C: c0266004                 clr     [%i1+4]
F00AE5A0: 1280001e                 bne     locret_F00AE618
F00AE5A4: 01000000                 nop
F00AE5A8: 4000008c                 call    _fpu_normalize
F00AE5AC: 90100019                 mov     %i1, %o0
F00AE5B0: d0066008                 ld      [%i1+8], %o0
F00AE5B4: 90022001                 inc     %o0
F00AE5B8: 10800018                 ba      locret_F00AE618
F00AE5BC: d0266008                 st      %o0, [%i1+8]
F00AE5C0: 9012801c                 or      %o2, %i4, %o0
F00AE5C4: 9012001b                 bset    %i3, %o0
F00AE5C8: 8092001d                 orcc    %o0, %i5, %g0
F00AE5CC: 12800005                 bne     loc_F00AE5E0
F00AE5D0: 11000020                 sethi   0x8000, %o0
F00AE5D4: 90102002                 mov     2, %o0
F00AE5D8: 10800010                 ba      locret_F00AE618
F00AE5DC: d0266004                 st      %o0, [%i1+4]
F00AE5E0: 808b4008                 btst    %o0, %o5
F00AE5E4: 02800004                 be      loc_F00AE5F4
F00AE5E8: 90102004                 mov     4, %o0
F00AE5EC: 10800007                 ba      loc_F00AE608
F00AE5F0: d0266004                 st      %o0, [%i1+4]
F00AE5F4: 90102005                 mov     5, %o0
F00AE5F8: d0266004                 st      %o0, [%i1+4]
F00AE5FC: 90100018                 mov     %i0, %o0
F00AE600: 40000131                 call    _fpu_set_exception
F00AE604: 92102004                 mov     4, %o1
F00AE608: d006600c                 ld      [%i1+0xC], %o0
F00AE60C: 13000020                 sethi   0x8000, %o1
F00AE610: 90120009                 bset    %o1, %o0
F00AE614: d026600c                 st      %o0, [%i1+0xC]
F00AE618: 81c7e008                 ret
F00AE61C: 81e80000                 restore
