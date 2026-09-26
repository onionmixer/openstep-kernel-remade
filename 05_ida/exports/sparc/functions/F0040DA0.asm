F0040DA0: 9de3bf98                 save    %sp, -0x68, %sp
F0040DA4: 90100018                 mov     %i0, %o0
F0040DA8: 4000b0f8                 call    _mfs_fsync_invalidate
F0040DAC: 92100019                 mov     %i1, %o1
F0040DB0: d0062030                 ld      [%i0+0x30], %o0
F0040DB4: d0122060                 lduh    [%o0+0x60], %o0
F0040DB8: 808a2010                 btst    0x10, %o0
F0040DBC: 02800004                 be      locret_F0040DCC
F0040DC0: 01000000                 nop
F0040DC4: 40000004                 call    sub_F0040DD4
F0040DC8: 90100018                 mov     %i0, %o0
F0040DCC: 81c7e008                 ret
F0040DD0: 81e80000                 restore
