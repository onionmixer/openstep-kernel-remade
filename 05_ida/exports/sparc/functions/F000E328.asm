F000E328: 9de3bf90                 save    %sp, -0x70, %sp
F000E32C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000E330: d80261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o4
F000E334: d0032024                 ld      [%o4+0x24], %o0
F000E338: d4020000                 ld      [%o0], %o2
F000E33C: 113c04d0                 sethi   %hi(_page_mask), %o0
F000E340: d60220d8                 ld      [%o0+%lo(_page_mask)], %o3
F000E344: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F000E348: d0027ffc                 ld      [%o1-4], %o0
F000E34C: 9402800b                 add     %o2, %o3, %o2
F000E350: d0022270                 ld      [%o0+0x270], %o0
F000E354: a22a800b                 andn    %o2, %o3, %l1
F000E358: 80a44008                 cmp     %l1, %o0
F000E35C: 04800005                 ble     loc_F000E370
F000E360: 113c04d0                 sethi   -0xFECC000, %o0
F000E364: 9010200c                 mov     0xC, %o0
F000E368: 10800023                 ba      locret_F000E3F4
F000E36C: d02b2038                 stb     %o0, [%o4+0x38]
F000E370: d0022260                 ld      [%o0+0x260], %o0
F000E374: d002200c                 ld      [%o0+0xC], %o0
F000E378: e002200c                 ld      [%o0+0xC], %l0
F000E37C: 40016a92                 call    _lock_write
F000E380: 90100010                 mov     %l0, %o0
F000E384: d004204c                 ld      [%l0+0x4C], %o0
F000E388: 90022001                 inc     %o0
F000E38C: d024204c                 st      %o0, [%l0+0x4C]
F000E390: 90100010                 mov     %l0, %o0
F000E394: 92100011                 mov     %l1, %o1
F000E398: 4001d844                 call    _vm_map_lookup_entry
F000E39C: 9407bff4                 add     %fp, var_C, %o2
F000E3A0: 80a22000                 cmp     %o0, 0
F000E3A4: 12800012                 bne     loc_F000E3EC
F000E3A8: d007bff4                 ld      [%fp+var_C], %o0
F000E3AC: d202200c                 ld      [%o0+0xC], %o1
F000E3B0: 90100010                 mov     %l0, %o0
F000E3B4: 40016b20                 call    _lock_done
F000E3B8: d227bff0                 st      %o1, [%fp+size]
F000E3BC: 90100010                 mov     %l0, %o0! target_task
F000E3C0: 9207bff0                 add     %fp, size, %o1! address
F000E3C4: d407bff0                 ld      [%fp+size], %o2! size
F000E3C8: 96102000                 mov     0, %o3! flags
F000E3CC: 4001f115                 call    _vm_allocate
F000E3D0: 9424400a                 sub     %l1, %o2, %o2
F000E3D4: 92920000                 orcc    %o0, %g0, %o1
F000E3D8: 02800007                 be      locret_F000E3F4
F000E3DC: 113c042c                 sethi   %hi(aCouldNotSbrkRe), %o0! "could not sbrk, return = %d\n"
F000E3E0: 400018b0                 call    _uprintf
F000E3E4: 901220b0                 bset    %lo(aCouldNotSbrkRe), %o0! "could not sbrk, return = %d\n"
F000E3E8: 30800003                 ba,a    locret_F000E3F4
F000E3EC: 40016b12                 call    _lock_done
F000E3F0: 90100010                 mov     %l0, %o0
F000E3F4: 81c7e008                 ret
F000E3F8: 81e80000                 restore
