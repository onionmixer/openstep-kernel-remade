F008542C: 9de3bf90                 save    %sp, -0x70, %sp
F0085430: d006a018                 ld      [%i2+0x18], %o0
F0085434: 13080000                 sethi   0x20000000, %o1
F0085438: 808a0009                 btst    %o1, %o0
F008543C: 1280007b                 bne     locret_F0085628
F0085440: 01000000                 nop
F0085444: d006e018                 ld      [%i3+0x18], %o0
F0085448: 808a0009                 btst    %o1, %o0
F008544C: 12800077                 bne     locret_F0085628
F0085450: 01000000                 nop
F0085454: d016e028                 lduh    [%i3+0x28], %o0
F0085458: 80a22000                 cmp     %o0, 0
F008545C: 02800004                 be      loc_F008546C
F0085460: 90100019                 mov     %i1, %o0
F0085464: 7fffff2b                 call    _vm_map_entry_unwire
F0085468: 9210001b                 mov     %i3, %o1
F008546C: d006602c                 ld      [%i1+0x2C], %o0
F0085470: 80a22000                 cmp     %o0, 0
F0085474: 3280000a                 bne,a   loc_F008549C
F0085478: d0066024                 ld      [%i1+0x24], %o0
F008547C: d006e010                 ld      [%i3+0x10], %o0
F0085480: d406e00c                 ld      [%i3+0xC], %o2
F0085484: d606e008                 ld      [%i3+8], %o3
F0085488: d206e014                 ld      [%i3+0x14], %o1
F008548C: 9422800b                 sub     %o2, %o3, %o2
F0085490: 400006ca                 call    _vm_object_pmap_remove
F0085494: 9402400a                 add     %o1, %o2, %o2
F0085498: d0066024                 ld      [%i1+0x24], %o0
F008549C: d206e008                 ld      [%i3+8], %o1
F00854A0: 40005f37                 call    _pmap_remove
F00854A4: d406e00c                 ld      [%i3+0xC], %o2
F00854A8: d016a028                 lduh    [%i2+0x28], %o0
F00854AC: 80a22000                 cmp     %o0, 0
F00854B0: 1280005a                 bne     loc_F0085618
F00854B4: 90100019                 mov     %i1, %o0
F00854B8: d206a018                 ld      [%i2+0x18], %o1
F00854BC: 11008000                 sethi   0x2000000, %o0
F00854C0: 808a4008                 btst    %o0, %o1
F00854C4: 32800027                 bne,a   loc_F0085560
F00854C8: d006a010                 ld      [%i2+0x10], %o0
F00854CC: d006202c                 ld      [%i0+0x2C], %o0
F00854D0: 80a22000                 cmp     %o0, 0
F00854D4: 12800012                 bne     loc_F008551C
F00854D8: 01000000                 nop
F00854DC: a0062034                 add     %i0, 0x34, %l0 ! '4'
F00854E0: d0040000                 ld      [%l0], %o0
F00854E4: 80a22000                 cmp     %o0, 0
F00854E8: 12bffffe                 bne     loc_F00854E0
F00854EC: 01000000                 nop
F00854F0: 4000466e                 call    _simple_lock_try
F00854F4: 90100010                 mov     %l0, %o0
F00854F8: 80a22000                 cmp     %o0, 0
F00854FC: 02bffff9                 be      loc_F00854E0
F0085500: 01000000                 nop
F0085504: d0062030                 ld      [%i0+0x30], %o0
F0085508: c0262034                 clr     [%i0+0x34]
F008550C: 901a2001                 btog    1, %o0
F0085510: 80a00008                 cmp     %g0, %o0
F0085514: 90603fff                 subc    %g0, -1, %o0
F0085518: 80a22000                 cmp     %o0, 0
F008551C: 2280000a                 be,a    loc_F0085544
F0085520: d006a010                 ld      [%i2+0x10], %o0
F0085524: d0062024                 ld      [%i0+0x24], %o0
F0085528: d206a008                 ld      [%i2+8], %o1
F008552C: d606a01c                 ld      [%i2+0x1C], %o3
F0085530: d406a00c                 ld      [%i2+0xC], %o2
F0085534: 40006524                 call    _pmap_protect
F0085538: 960afffd                 and     %o3, -3, %o3
F008553C: 10800009                 ba      loc_F0085560
F0085540: d006a010                 ld      [%i2+0x10], %o0
F0085544: d406a00c                 ld      [%i2+0xC], %o2
F0085548: d606a008                 ld      [%i2+8], %o3
F008554C: d206a014                 ld      [%i2+0x14], %o1
F0085550: 9422800b                 sub     %o2, %o3, %o2
F0085554: 40000671                 call    _vm_object_pmap_copy
F0085558: 9402400a                 add     %o1, %o2, %o2
F008555C: d006a010                 ld      [%i2+0x10], %o0
F0085560: da06a00c                 ld      [%i2+0xC], %o5
F0085564: d406a008                 ld      [%i2+8], %o2
F0085568: 9606e010                 add     %i3, 0x10, %o3
F008556C: d206a014                 ld      [%i2+0x14], %o1
F0085570: 9806e014                 add     %i3, 0x14, %o4
F0085574: e006e010                 ld      [%i3+0x10], %l0
F0085578: 9423400a                 sub     %o5, %o2, %o2
F008557C: 400006af                 call    _vm_object_copy
F0085580: 9a07bff4                 add     %fp, var_C, %o5
F0085584: d007bff4                 ld      [%fp+var_C], %o0
F0085588: 80a22000                 cmp     %o0, 0
F008558C: 02800005                 be      loc_F00855A0
F0085590: 13008000                 sethi   0x2000000, %o1
F0085594: d006a018                 ld      [%i2+0x18], %o0
F0085598: 90120009                 bset    %o1, %o0
F008559C: d026a018                 st      %o0, [%i2+0x18]
F00855A0: d006e018                 ld      [%i3+0x18], %o0
F00855A4: 13008000                 sethi   0x2000000, %o1
F00855A8: 90120009                 bset    %o1, %o0
F00855AC: d026e018                 st      %o0, [%i3+0x18]
F00855B0: d006a018                 ld      [%i2+0x18], %o0
F00855B4: 13040000                 sethi   0x10000000, %o1
F00855B8: 90120009                 bset    %o1, %o0
F00855BC: d026a018                 st      %o0, [%i2+0x18]
F00855C0: d006e018                 ld      [%i3+0x18], %o0
F00855C4: 90120009                 bset    %o1, %o0
F00855C8: d026e018                 st      %o0, [%i3+0x18]
F00855CC: d006a01c                 ld      [%i2+0x1C], %o0
F00855D0: 808a2004                 btst    4, %o0
F00855D4: 02800007                 be      loc_F00855F0
F00855D8: 01000000                 nop
F00855DC: d006e020                 ld      [%i3+0x20], %o0
F00855E0: d206e01c                 ld      [%i3+0x1C], %o1
F00855E4: 900a2004                 and     %o0, 4, %o0
F00855E8: 92124008                 bset    %o0, %o1
F00855EC: d226e01c                 st      %o1, [%i3+0x1C]
F00855F0: 400004b2                 call    _vm_object_deallocate
F00855F4: 90100010                 mov     %l0, %o0
F00855F8: d0066024                 ld      [%i1+0x24], %o0
F00855FC: d2062024                 ld      [%i0+0x24], %o1
F0085600: d406e008                 ld      [%i3+8], %o2
F0085604: d606e00c                 ld      [%i3+0xC], %o3
F0085608: d806a008                 ld      [%i2+8], %o4
F008560C: 4000695c                 call    _pmap_copy
F0085610: 9622c00a                 sub     %o3, %o2, %o3
F0085614: 30800005                 ba,a    locret_F0085628
F0085618: 92100018                 mov     %i0, %o1
F008561C: 9410001b                 mov     %i3, %o2
F0085620: 7ffff67b                 call    _vm_fault_copy_entry
F0085624: 9610001a                 mov     %i2, %o3
F0085628: 81c7e008                 ret
F008562C: 81e80000                 restore
