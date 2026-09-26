F00EC254: 9de3bf98                 save    %sp, -0x68, %sp
F00EC258: 40001240                 call    _NXZoneFromPtr
F00EC25C: 90100018                 mov     %i0, %o0
F00EC260: 94920000                 orcc    %o0, %g0, %o2
F00EC264: 12800006                 bne     loc_F00EC27C
F00EC268: 90100018                 mov     %i0, %o0
F00EC26C: 40001238                 call    _NXDefaultMallocZone
F00EC270: 01000000                 nop
F00EC274: 94100008                 mov     %o0, %o2
F00EC278: 90100018                 mov     %i0, %o0
F00EC27C: 7fffffe2                 call    __internal_object_copyFromZone
F00EC280: 92100019                 mov     %i1, %o1
F00EC284: 81c7e008                 ret
F00EC288: 91e80008                 restore %g0, %o0, %o0
