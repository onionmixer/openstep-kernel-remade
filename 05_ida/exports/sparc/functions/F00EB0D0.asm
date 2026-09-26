F00EB0D0: 9de3bf90                 save    %sp, -0x70, %sp
F00EB0D4: a0100018                 mov     %i0, %l0
F00EB0D8: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00EB0DC: 90100010                 mov     %l0, %o0! id
F00EB0E0: 400019e4                 call    _objc_msgSend
F00EB0E4: d2026014                 ld      [%o1+%lo(paClass)], %o1
F00EB0E8: 133c0506                 sethi   %hi(paAllocfromzone), %o1
F00EB0EC: d2026260                 ld      [%o1+%lo(paAllocfromzone)], %o1! SEL
F00EB0F0: 400019e0                 call    _objc_msgSend
F00EB0F4: 9410001a                 mov     %i2, %o2
F00EB0F8: 133c0504                 sethi   %hi(paInitcount), %o1
F00EB0FC: d20260bc                 ld      [%o1+%lo(paInitcount)], %o1! SEL
F00EB100: 400019dc                 call    _objc_msgSend
F00EB104: d4042008                 ld      [%l0+8], %o2
F00EB108: b0100008                 mov     %o0, %i0
F00EB10C: d0042008                 ld      [%l0+8], %o0
F00EB110: d0262008                 st      %o0, [%i0+8]
F00EB114: d4042008                 ld      [%l0+8], %o2! __len
F00EB118: d0062004                 ld      [%i0+4], %o0! __dst
F00EB11C: d2042004                 ld      [%l0+4], %o1! __src
F00EB120: 7ffc73ac                 call    _memmove
F00EB124: 952aa002                 sll     %o2, 2, %o2
F00EB128: 81c7e008                 ret
F00EB12C: 81e80000                 restore
