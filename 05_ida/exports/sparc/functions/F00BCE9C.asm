F00BCE9C: 9de3bf90                 save    %sp, -0x70, %sp
F00BCEA0: d006210c                 ld      [%i0+0x10C], %o0
F00BCEA4: 80a22000                 cmp     %o0, 0
F00BCEA8: 02800006                 be      loc_F00BCEC0
F00BCEAC: 9210001a                 mov     %i2, %o1
F00BCEB0: d4022018                 ld      [%o0+0x18], %o2
F00BCEB4: 9fc28000                 call    %o2
F00BCEB8: b0102000                 mov     0, %i0
F00BCEBC: 30800002                 ba,a    locret_F00BCEC4
F00BCEC0: b0102016                 mov     0x16, %i0
F00BCEC4: 81c7e008                 ret
F00BCEC8: 81e80000                 restore
