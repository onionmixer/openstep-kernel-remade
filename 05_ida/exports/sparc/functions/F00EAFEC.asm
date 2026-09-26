F00EAFEC: 9de3bf90                 save    %sp, -0x70, %sp
F00EAFF0: 400016d7                 call    _NXDefaultMallocZone
F00EAFF4: 213c0506                 sethi   %hi(paAllocfromzone), %l0
F00EAFF8: 94100008                 mov     %o0, %o2
F00EAFFC: 90100018                 mov     %i0, %o0! id
F00EB000: 40001a1c                 call    _objc_msgSend
F00EB004: d2042260                 ld      [%l0+%lo(paAllocfromzone)], %o1
F00EB008: 133c0504                 sethi   %hi(paInitcount), %o1
F00EB00C: d20260bc                 ld      [%o1+%lo(paInitcount)], %o1! SEL
F00EB010: 40001a18                 call    _objc_msgSend
F00EB014: 9410001a                 mov     %i2, %o2
F00EB018: 81c7e008                 ret
F00EB01C: 91e80008                 restore %g0, %o0, %o0
