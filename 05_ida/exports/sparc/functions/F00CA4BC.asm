F00CA4BC: 9de3bf90                 save    %sp, -0x70, %sp
F00CA4C0: 9210001b                 mov     %i3, %o1! __src
F00CA4C4: 912ea001                 sll     %i2, 1, %o0
F00CA4C8: 9002001a                 add     %o0, %i2, %o0
F00CA4CC: 912a2003                 sll     %o0, 3, %o0
F00CA4D0: 9022001a                 sub     %o0, %i2, %o0
F00CA4D4: 912a2002                 sll     %o0, 2, %o0
F00CA4D8: a0022128                 add     %o0, 0x128, %l0
F00CA4DC: d0060010                 ld      [%i0+%l0], %o0
F00CA4E0: 80a22000                 cmp     %o0, 0
F00CA4E4: 1280000e                 bne     loc_F00CA51C
F00CA4E8: a2060010                 add     %i0, %l0, %l1
F00CA4EC: 90046008                 add     %l1, 8, %o0! __dst
F00CA4F0: 7ffcf50b                 call    _strncpy
F00CA4F4: 94102051                 mov     0x51, %o2 ! 'Q'
F00CA4F8: f8260010                 st      %i4, [%i0+%l0]
F00CA4FC: fa246004                 st      %i5, [%l1+4]
F00CA500: 90100018                 mov     %i0, %o0! id
F00CA504: 133c0506                 sethi   %hi(paInitializeunit), %o1
F00CA508: d2026090                 ld      [%o1+%lo(paInitializeunit)], %o1! SEL
F00CA50C: 40009cd9                 call    _objc_msgSend
F00CA510: 9410001a                 mov     %i2, %o2
F00CA514: 10800003                 ba      locret_F00CA520
F00CA518: b0102000                 mov     0, %i0
F00CA51C: b0103d2b                 mov     -0x2D5, %i0
F00CA520: 81c7e008                 ret
F00CA524: 81e80000                 restore
