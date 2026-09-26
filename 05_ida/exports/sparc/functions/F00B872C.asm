F00B872C: 9de3bf98                 save    %sp, -0x68, %sp
F00B8730: 90100018                 mov     %i0, %o0
F00B8734: 92100019                 mov     %i1, %o1
F00B8738: f2020000                 ld      [%o0], %i1
F00B873C: 9410001a                 mov     %i2, %o2
F00B8740: d8066018                 ld      [%i1+0x18], %o4
F00B8744: 9fc30000                 call    %o4
F00B8748: 9610001c                 mov     %i4, %o3
F00B874C: b0920000                 orcc    %o0, %g0, %i0
F00B8750: 12800008                 bne     loc_F00B8770
F00B8754: 80a6e000                 cmp     %i3, 0
F00B8758: 80a72001                 cmp     %i4, 1
F00B875C: 12800017                 bne     locret_F00B87B8
F00B8760: 113c047d                 sethi   %hi(aScsiResallocNo), %o0! "scsi_resalloc: No packet after sleep"
F00B8764: 7ffd7283                 call    _panic
F00B8768: 90122058                 bset    %lo(aScsiResallocNo), %o0! "scsi_resalloc: No packet after sleep"
F00B876C: 30800013                 ba,a    locret_F00B87B8
F00B8770: 02800012                 be      locret_F00B87B8
F00B8774: 90100018                 mov     %i0, %o0
F00B8778: 9210001b                 mov     %i3, %o1
F00B877C: d606601c                 ld      [%i1+0x1C], %o3
F00B8780: 9fc2c000                 call    %o3
F00B8784: 9410001c                 mov     %i4, %o2
F00B8788: 80a22000                 cmp     %o0, 0
F00B878C: 1280000b                 bne     locret_F00B87B8
F00B8790: 80a72001                 cmp     %i4, 1
F00B8794: 32800006                 bne,a   loc_F00B87AC
F00B8798: 90100018                 mov     %i0, %o0
F00B879C: 113c047d                 sethi   %hi(aScsiResallocNo_0), %o0! "scsi_resalloc: No dma after sleep"
F00B87A0: 7ffd7274                 call    _panic
F00B87A4: 90122080                 bset    %lo(aScsiResallocNo_0), %o0! "scsi_resalloc: No dma after sleep"
F00B87A8: 90100018                 mov     %i0, %o0
F00B87AC: d2066020                 ld      [%i1+0x20], %o1
F00B87B0: 9fc24000                 call    %o1
F00B87B4: b0102000                 mov     0, %i0
F00B87B8: 81c7e008                 ret
F00B87BC: 81e80000                 restore
