F00EB888: 9de3bf90                 save    %sp, -0x70, %sp
F00EB88C: 400014b3                 call    _NXZoneFromPtr
F00EB890: 90100018                 mov     %i0, %o0
F00EB894: 80a22000                 cmp     %o0, 0
F00EB898: 12800004                 bne     locret_F00EB8A8
F00EB89C: 01000000                 nop
F00EB8A0: 400014ab                 call    _NXDefaultMallocZone
F00EB8A4: 01000000                 nop
F00EB8A8: 81c7e008                 ret
F00EB8AC: 91e80008                 restore %g0, %o0, %o0
