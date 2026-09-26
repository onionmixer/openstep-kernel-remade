F00259A8: 9de3bf98                 save    %sp, -0x68, %sp
F00259AC: 7fff86a3                 call    _strlen
F00259B0: 90100018                 mov     %i0, %o0
F00259B4: 94100008                 mov     %o0, %o2
F00259B8: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00259BC: 04800004                 ble     loc_F00259CC
F00259C0: 90028018                 add     %o2, %i0, %o0
F00259C4: 1080000d                 ba      locret_F00259F8
F00259C8: b0102000                 mov     0, %i0
F00259CC: d24a3fff                 ldsb    [%o0-1], %o1
F00259D0: 98103fff                 mov     -1, %o4
F00259D4: d64e0000                 ldsb    [%i0], %o3
F00259D8: 90100019                 mov     %i1, %o0
F00259DC: 9602c009                 add     %o3, %o1, %o3
F00259E0: 9602c00a                 add     %o3, %o2, %o3
F00259E4: 9602c008                 add     %o3, %o0, %o3
F00259E8: 92100018                 mov     %i0, %o1
F00259EC: 40000135                 call    sub_F0025EC0
F00259F0: 960ae03f                 and     %o3, 0x3F, %o3
F00259F4: b0100008                 mov     %o0, %i0
F00259F8: 81c7e008                 ret
F00259FC: 81e80000                 restore
