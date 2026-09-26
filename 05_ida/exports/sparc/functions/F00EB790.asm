F00EB790: 9de3bf90                 save    %sp, -0x70, %sp
F00EB794: 400014ee                 call    _NXDefaultMallocZone
F00EB798: 213c04bc                 sethi   %hi(__zoneAlloc), %l0
F00EB79C: 94100008                 mov     %o0, %o2
F00EB7A0: d6042104                 ld      [%l0+%lo(__zoneAlloc)], %o3
F00EB7A4: 90100018                 mov     %i0, %o0
F00EB7A8: 9fc2c000                 call    %o3
F00EB7AC: 92102000                 mov     0, %o1
F00EB7B0: 81c7e008                 ret
F00EB7B4: 91e80008                 restore %g0, %o0, %o0
