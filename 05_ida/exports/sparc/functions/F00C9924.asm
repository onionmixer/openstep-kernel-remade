F00C9924: 9de3bf90                 save    %sp, -0x70, %sp
F00C9928: 90100018                 mov     %i0, %o0! id
F00C992C: 133c0506                 sethi   %hi(paChangeinterrup), %o1
F00C9930: d20260cc                 ld      [%o1+%lo(paChangeinterrup)], %o1! SEL
F00C9934: 9410001a                 mov     %i2, %o2
F00C9938: 40009fce                 call    _objc_msgSend
F00C993C: 96102000                 mov     0, %o3
F00C9940: 81c7e008                 ret
F00C9944: 81e80000                 restore
