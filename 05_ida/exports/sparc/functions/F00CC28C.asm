F00CC28C: 9de3bf80                 save    %sp, -0x80, %sp
F00CC290: a007bfe0                 add     %fp, __b, %l0
F00CC294: 90100010                 mov     %l0, %o0! __b
F00CC298: 92102000                 mov     0, %o1! __c
F00CC29C: 7ffce838                 call    _memset
F00CC2A0: 94102018                 mov     0x18, %o2
F00CC2A4: d00fbfe3                 ldub    [%fp+__b+3], %o0
F00CC2A8: d027bfe0                 st      %o0, [%fp+__b]
F00CC2AC: d0062158                 ld      [%i0+0x158], %o0
F00CC2B0: 80a22000                 cmp     %o0, 0
F00CC2B4: 12800006                 bne     loc_F00CC2CC
F00CC2B8: 01000000                 nop
F00CC2BC: d006215c                 ld      [%i0+0x15C], %o0
F00CC2C0: 80a22000                 cmp     %o0, 0
F00CC2C4: 02800015                 be      locret_F00CC318
F00CC2C8: 01000000                 nop
F00CC2CC: 98102000                 mov     0, %o4
F00CC2D0: 9a102000                 mov     0, %o5
F00CC2D4: d83e2158                 std     %o4, [%i0+0x158]
F00CC2D8: 90102018                 mov     0x18, %o0
F00CC2DC: d027bfe4                 st      %o0, [%fp+var_1C]
F00CC2E0: 113c0504                 sethi   %hi(paInterruptport_0), %o0! id
F00CC2E4: d2022308                 ld      [%o0+%lo(paInterruptport_0)], %o1! SEL
F00CC2E8: 40009562                 call    _objc_msgSend
F00CC2EC: 90100018                 mov     %i0, %o0
F00CC2F0: 7ffff7e9                 call    _IOGetKernPort
F00CC2F4: 01000000                 nop
F00CC2F8: d027bff0                 st      %o0, [%fp+var_10]
F00CC2FC: 110008c890122323         set     0x232323, %o0
F00CC304: d027bff4                 st      %o0, [%fp+var_C]
F00CC308: 90100010                 mov     %l0, %o0
F00CC30C: 92102000                 mov     0, %o1
F00CC310: 7ffe6647                 call    _msg_send_from_kernel
F00CC314: 94102000                 mov     0, %o2
F00CC318: 81c7e008                 ret
F00CC31C: 81e80000                 restore
