F00C81A4: 9de3bf90                 save    %sp, -0x70, %sp
F00C81A8: 113c0506                 sethi   %hi(paPhysicaldisk_0), %o0! id
F00C81AC: d2022164                 ld      [%o0+%lo(paPhysicaldisk_0)], %o1! SEL
F00C81B0: 4000a5b0                 call    _objc_msgSend
F00C81B4: 90100018                 mov     %i0, %o0! id
F00C81B8: 213c0506                 sethi   %hi(paNextlogicaldis_0), %l0
F00C81BC: 4000a5ad                 call    _objc_msgSend
F00C81C0: d2042198                 ld      [%l0+%lo(paNextlogicaldis_0)], %o1
F00C81C4: b0920000                 orcc    %o0, %g0, %i0
F00C81C8: 22800012                 be,a    locret_F00C8210
F00C81CC: b0102000                 mov     0, %i0
F00C81D0: 233c0506                 sethi   %hi(paIsblockdeviceo), %l1
F00C81D4: d2046130                 ld      [%l1+%lo(paIsblockdeviceo)], %o1! SEL
F00C81D8: 4000a5a6                 call    _objc_msgSend
F00C81DC: 90100018                 mov     %i0, %o0
F00C81E0: 912a2018                 sll     %o0, 24, %o0! id
F00C81E4: 80a22000                 cmp     %o0, 0
F00C81E8: 02800004                 be      loc_F00C81F8
F00C81EC: d2042198                 ld      [%l0+0x198], %o1! SEL
F00C81F0: 10800008                 ba      locret_F00C8210
F00C81F4: b0102001                 mov     1, %i0
F00C81F8: 4000a59e                 call    _objc_msgSend
F00C81FC: 90100018                 mov     %i0, %o0
F00C8200: b0920000                 orcc    %o0, %g0, %i0
F00C8204: 12bffff5                 bne     loc_F00C81D8
F00C8208: d2046130                 ld      [%l1+0x130], %o1
F00C820C: b0102000                 mov     0, %i0
F00C8210: 81c7e008                 ret
F00C8214: 81e80000                 restore
