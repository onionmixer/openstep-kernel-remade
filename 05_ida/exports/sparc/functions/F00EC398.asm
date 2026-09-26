F00EC398: 9de3bf98                 save    %sp, -0x68, %sp
F00EC39C: 400011ef                 call    _NXZoneFromPtr
F00EC3A0: 90100018                 mov     %i0, %o0
F00EC3A4: 94920000                 orcc    %o0, %g0, %o2
F00EC3A8: 12800006                 bne     loc_F00EC3C0
F00EC3AC: 90100018                 mov     %i0, %o0
F00EC3B0: 400011e7                 call    _NXDefaultMallocZone
F00EC3B4: 01000000                 nop
F00EC3B8: 94100008                 mov     %o0, %o2
F00EC3BC: 90100018                 mov     %i0, %o0
F00EC3C0: 7fffffbe                 call    __internal_object_reallocFromZone
F00EC3C4: 92100019                 mov     %i1, %o1
F00EC3C8: 81c7e008                 ret
F00EC3CC: 91e80008                 restore %g0, %o0, %o0
