F00598D4: 9de3bf90                 save    %sp, -0x70, %sp
F00598D8: 113c04efa6122300         set     _ipc_object_zones, %l3
F00598E0: a32e6002                 sll     %i1, 2, %l1
F00598E4: d0044013                 ld      [%l1+%l3], %o0
F00598E8: 40007df9                 call    _zalloc
F00598EC: a4100018                 mov     %i0, %l2
F00598F0: a0920000                 orcc    %o0, %g0, %l0
F00598F4: 12800004                 bne     loc_F0059904
F00598F8: 90100012                 mov     %l2, %o0
F00598FC: 1080002e                 ba      locret_F00599B4
F0059900: b0102006                 mov     6, %i0
F0059904: 9210001c                 mov     %i4, %o1
F0059908: 7fffe8a8                 call    _ipc_entry_alloc_name
F005990C: 9407bff4                 add     %fp, var_C, %o2
F0059910: b0920000                 orcc    %o0, %g0, %i0
F0059914: 02800006                 be      loc_F005992C
F0059918: 90100012                 mov     %l2, %o0
F005991C: d0044013                 ld      [%l1+%l3], %o0
F0059920: 40007e2c                 call    _zfree
F0059924: 92100010                 mov     %l0, %o1
F0059928: 30800023                 ba,a    locret_F00599B4
F005992C: d407bff4                 ld      [%fp+var_C], %o2
F0059930: 40000921                 call    _ipc_right_inuse
F0059934: 9210001c                 mov     %i4, %o1
F0059938: 80a22000                 cmp     %o0, 0
F005993C: 02800007                 be      loc_F0059958
F0059940: d007bff4                 ld      [%fp+var_C], %o0
F0059944: d0044013                 ld      [%l1+%l3], %o0
F0059948: 40007e22                 call    _zfree
F005994C: 92100010                 mov     %l0, %o1
F0059950: 10800019                 ba      locret_F00599B4
F0059954: b010200d                 mov     0xD, %i0
F0059958: 9416801b                 or      %i2, %i3, %o2
F005995C: d2020000                 ld      [%o0], %o1
F0059960: e0222004                 st      %l0, [%o0+4]
F0059964: 9212400a                 bset    %o2, %o1
F0059968: d2220000                 st      %o1, [%o0]
F005996C: c0240000                 clr     [%l0]
F0059970: d0040000                 ld      [%l0], %o0
F0059974: 80a22000                 cmp     %o0, 0
F0059978: 12bffffe                 bne     loc_F0059970
F005997C: 01000000                 nop
F0059980: 4000f54a                 call    _simple_lock_try
F0059984: 90100010                 mov     %l0, %o0
F0059988: 80a22000                 cmp     %o0, 0
F005998C: 02bffff9                 be      loc_F0059970
F0059990: 13200000                 sethi   0x80000000, %o1
F0059994: c024a008                 clr     [%l2+8]
F0059998: 90102001                 mov     1, %o0
F005999C: d0242004                 st      %o0, [%l0+4]
F00599A0: 912e6010                 sll     %i1, 16, %o0
F00599A4: 90120009                 bset    %o1, %o0
F00599A8: d0242008                 st      %o0, [%l0+8]
F00599AC: e0274000                 st      %l0, [%i5]
F00599B0: b0102000                 mov     0, %i0
F00599B4: 81c7e008                 ret
F00599B8: 81e80000                 restore
