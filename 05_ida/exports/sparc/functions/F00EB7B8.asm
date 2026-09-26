F00EB7B8: 9de3bf90                 save    %sp, -0x70, %sp
F00EB7BC: 113c04bc                 sethi   %hi(__zoneAlloc), %o0
F00EB7C0: d6022104                 ld      [%o0+%lo(__zoneAlloc)], %o3
F00EB7C4: 90100018                 mov     %i0, %o0
F00EB7C8: 92102000                 mov     0, %o1
F00EB7CC: 9fc2c000                 call    %o3
F00EB7D0: 9410001a                 mov     %i2, %o2
F00EB7D4: 81c7e008                 ret
F00EB7D8: 91e80008                 restore %g0, %o0, %o0
