F0095040: 1b3c0464                 sethi   %hi(_bcopy_res), %o5
F0095044: d86b6300                 ldstub  [%o5+%lo(_bcopy_res)], %o4
F0095048: 80930000                 tst     %o4
F009504C: 1280001e                 bne     locret_F00950C4
F0095050: 1b3c0447                 sethi   %hi(_page_size), %o5
F0095054: d803613c                 ld      [%o5+%lo(_page_size)], %o4
F0095058: 1b0070009a136100         set     0x1C00100, %o5
F0095060: 0300700082106200         set     0x1C00200, %g1
F0095068: d4bb4040                 stda    %o2, [%o5]2
F009506C: d0b84040                 stda    %o0, [%g1]2
F0095070: 98a32020                 deccc   0x20, %o4 ! ' '
F0095074: 12bffffe                 bne     loc_F009506C
F0095078: 92026020                 inc     0x20, %o1 ! ' '
F009507C: 1b0070039a136200         set     0x1C00E00, %o5
F0095084: d09b4040                 ldda    [%o5]2, %o0
F0095088: 15010000                 sethi   0x4000000, %o2
F009508C: 808a8008                 btst    %o0, %o2
F0095090: 02800006                 be      loc_F00950A8
F0095094: 1b3c0464                 sethi   -0xFEE7000, %o5
F0095098: 15008000                 sethi   0x2000000, %o2
F009509C: 808a8008                 btst    %o0, %o2
F00950A0: 32800005                 bne,a   loc_F00950B4
F00950A4: 01000000                 nop
F00950A8: c0236300                 clr     [%o5+0x300]
F00950AC: 81c3e008                 retl
F00950B0: 90102000                 mov     0, %o0
F00950B4: 113c0254901220cc         set     aHwBzeroStreamO, %o0! "hw bzero stream operation failed; using"...
F00950BC: 7ffe002d                 call    _panic
F00950C0: 01000000                 nop
F00950C4: 81c3e008                 retl
F00950C8: 90102001                 mov     1, %o0
