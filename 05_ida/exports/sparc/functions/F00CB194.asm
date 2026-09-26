F00CB194: 9de3bf80                 save    %sp, -0x80, %sp
F00CB198: a007bfe0                 add     %fp, __b, %l0
F00CB19C: 90100010                 mov     %l0, %o0! __b
F00CB1A0: 92102000                 mov     0, %o1! __c
F00CB1A4: 7ffcec76                 call    _memset
F00CB1A8: 94102018                 mov     0x18, %o2
F00CB1AC: d00fbfe3                 ldub    [%fp+__b+3], %o0
F00CB1B0: d027bfe0                 st      %o0, [%fp+__b]
F00CB1B4: d0062130                 ld      [%i0+0x130], %o0
F00CB1B8: 80a22000                 cmp     %o0, 0
F00CB1BC: 12800006                 bne     loc_F00CB1D4
F00CB1C0: 01000000                 nop
F00CB1C4: d0062134                 ld      [%i0+0x134], %o0
F00CB1C8: 80a22000                 cmp     %o0, 0
F00CB1CC: 02800015                 be      locret_F00CB220
F00CB1D0: 01000000                 nop
F00CB1D4: 98102000                 mov     0, %o4
F00CB1D8: 9a102000                 mov     0, %o5
F00CB1DC: d83e2130                 std     %o4, [%i0+0x130]
F00CB1E0: 90102018                 mov     0x18, %o0
F00CB1E4: d027bfe4                 st      %o0, [%fp+var_1C]
F00CB1E8: 113c0504                 sethi   %hi(paInterruptport_0), %o0! id
F00CB1EC: d2022308                 ld      [%o0+%lo(paInterruptport_0)], %o1! SEL
F00CB1F0: 400099a0                 call    _objc_msgSend
F00CB1F4: 90100018                 mov     %i0, %o0
F00CB1F8: 7ffffc27                 call    _IOGetKernPort
F00CB1FC: 01000000                 nop
F00CB200: d027bff0                 st      %o0, [%fp+var_10]
F00CB204: 110008c890122323         set     0x232323, %o0
F00CB20C: d027bff4                 st      %o0, [%fp+var_C]
F00CB210: 90100010                 mov     %l0, %o0
F00CB214: 92102000                 mov     0, %o1
F00CB218: 7ffe6a85                 call    _msg_send_from_kernel
F00CB21C: 94102000                 mov     0, %o2
F00CB220: 81c7e008                 ret
F00CB224: 81e80000                 restore
