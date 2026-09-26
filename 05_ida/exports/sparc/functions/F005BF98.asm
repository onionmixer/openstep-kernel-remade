F005BF98: 9de3bf98                 save    %sp, -0x68, %sp
F005BF9C: d2068000                 ld      [%i2], %o1
F005BFA0: 110007c0                 sethi   0x1F0000, %o0
F005BFA4: a20a4008                 and     %o1, %o0, %l1
F005BFA8: 110000c0                 sethi   0x30000, %o0
F005BFAC: 80a44008                 cmp     %l1, %o0
F005BFB0: 22800026                 be,a    loc_F005C048
F005BFB4: e006a004                 ld      [%i2+4], %l0
F005BFB8: 18800007                 bgu     loc_F005BFD4
F005BFBC: 11000040                 sethi   0x10000, %o0
F005BFC0: 80a44008                 cmp     %l1, %o0
F005BFC4: 02800020                 be      loc_F005C044
F005BFC8: 11000080                 sethi   0x20000, %o0
F005BFCC: 10800009                 ba      loc_F005BFF0
F005BFD0: 80a44008                 cmp     %l1, %o0
F005BFD4: 11000200                 sethi   0x80000, %o0
F005BFD8: 80a44008                 cmp     %l1, %o0
F005BFDC: 2280000e                 be,a    loc_F005C014
F005BFE0: f406a004                 ld      [%i2+4], %i2
F005BFE4: 18800007                 bgu     loc_F005C000
F005BFE8: 11000100                 sethi   0x40000, %o0
F005BFEC: 80a44008                 cmp     %l1, %o0
F005BFF0: 22800016                 be,a    loc_F005C048
F005BFF4: e006a004                 ld      [%i2+4], %l0
F005BFF8: 1080006c                 ba      loc_F005C1A8
F005BFFC: 113c043d                 sethi   -0xFEF0C00, %o0
F005C000: 11000400                 sethi   0x100000, %o0
F005C004: 80a44008                 cmp     %l1, %o0
F005C008: 12800068                 bne     loc_F005C1A8
F005C00C: 113c043d                 sethi   -0xFEF0C00, %o0
F005C010: 30800068                 ba,a    locret_F005C1B0
F005C014: d0068000                 ld      [%i2], %o0
F005C018: 80a22000                 cmp     %o0, 0
F005C01C: 12bffffe                 bne     loc_F005C014
F005C020: 01000000                 nop
F005C024: 4000eba1                 call    _simple_lock_try
F005C028: 9010001a                 mov     %i2, %o0
F005C02C: 80a22000                 cmp     %o0, 0
F005C030: 02bffff9                 be      loc_F005C014
F005C034: 01000000                 nop
F005C038: 7ffffe6d                 call    _ipc_pset_destroy
F005C03C: 9010001a                 mov     %i2, %o0
F005C040: 3080005c                 ba,a    locret_F005C1B0
F005C044: e006a004                 ld      [%i2+4], %l0
F005C048: a4102000                 mov     0, %l2
F005C04C: a6102000                 mov     0, %l3
F005C050: d0040000                 ld      [%l0], %o0
F005C054: 80a22000                 cmp     %o0, 0
F005C058: 12bffffe                 bne     loc_F005C050
F005C05C: 01000000                 nop
F005C060: 4000eb92                 call    _simple_lock_try
F005C064: 90100010                 mov     %l0, %o0
F005C068: 80a22000                 cmp     %o0, 0
F005C06C: 02bffff9                 be      loc_F005C050
F005C070: 01000000                 nop
F005C074: d0042008                 ld      [%l0+8], %o0
F005C078: 80a22000                 cmp     %o0, 0
F005C07C: 26800012                 bl,a    loc_F005C0C4
F005C080: d006a008                 ld      [%i2+8], %o0
F005C084: d0042004                 ld      [%l0+4], %o0
F005C088: 90023fff                 inc     -1, %o0
F005C08C: d0242004                 st      %o0, [%l0+4]
F005C090: c0240000                 clr     [%l0]
F005C094: 80a22000                 cmp     %o0, 0
F005C098: 12800046                 bne     locret_F005C1B0
F005C09C: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005C0A0: d0042008                 ld      [%l0+8], %o0
F005C0A4: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005C0A8: 912a2001                 sll     %o0, 1, %o0
F005C0AC: 91322011                 srl     %o0, 17, %o0
F005C0B0: 912a2002                 sll     %o0, 2, %o0
F005C0B4: d0020009                 ld      [%o0+%o1], %o0
F005C0B8: 40007446                 call    _zfree
F005C0BC: 92100010                 mov     %l0, %o1
F005C0C0: 3080003c                 ba,a    locret_F005C1B0
F005C0C4: 80a22000                 cmp     %o0, 0
F005C0C8: 02800008                 be      loc_F005C0E8
F005C0CC: 90100018                 mov     %i0, %o0
F005C0D0: 92100010                 mov     %l0, %o1
F005C0D4: 94100019                 mov     %i1, %o2
F005C0D8: 7fffff25                 call    _ipc_right_dncancel
F005C0DC: 9610001a                 mov     %i2, %o3
F005C0E0: 10800003                 ba      loc_F005C0EC
F005C0E4: b0100008                 mov     %o0, %i0
F005C0E8: b0102000                 mov     0, %i0
F005C0EC: 11000040                 sethi   0x10000, %o0
F005C0F0: 808c4008                 btst    %o0, %l1
F005C0F4: 0280000e                 be      loc_F005C12C
F005C0F8: 11000080                 sethi   0x20000, %o0
F005C0FC: d004201c                 ld      [%l0+0x1C], %o0
F005C100: 90023fff                 inc     -1, %o0
F005C104: 80a22000                 cmp     %o0, 0
F005C108: 12800008                 bne     loc_F005C128
F005C10C: d024201c                 st      %o0, [%l0+0x1C]
F005C110: e4042024                 ld      [%l0+0x24], %l2
F005C114: 80a4a000                 cmp     %l2, 0
F005C118: 02800005                 be      loc_F005C12C
F005C11C: 11000080                 sethi   0x20000, %o0
F005C120: c0242024                 clr     [%l0+0x24]
F005C124: e6042018                 ld      [%l0+0x18], %l3
F005C128: 11000080                 sethi   0x20000, %o0
F005C12C: 808c4008                 btst    %o0, %l1
F005C130: 02800008                 be      loc_F005C150
F005C134: 11000100                 sethi   0x40000, %o0
F005C138: 7ffff9fc                 call    _ipc_port_clear_receiver
F005C13C: 90100010                 mov     %l0, %o0
F005C140: 7ffffa95                 call    _ipc_port_destroy
F005C144: 90100010                 mov     %l0, %o0
F005C148: 1080000e                 ba      loc_F005C180
F005C14C: 80a4a000                 cmp     %l2, 0
F005C150: 808c4008                 btst    %o0, %l1
F005C154: 22800007                 be,a    loc_F005C170
F005C158: d0042004                 ld      [%l0+4], %o0
F005C15C: c0240000                 clr     [%l0]
F005C160: 7ffff455                 call    _ipc_notify_send_once
F005C164: 90100010                 mov     %l0, %o0
F005C168: 10800006                 ba      loc_F005C180
F005C16C: 80a4a000                 cmp     %l2, 0
F005C170: 90023fff                 inc     -1, %o0
F005C174: d0242004                 st      %o0, [%l0+4]
F005C178: c0240000                 clr     [%l0]
F005C17C: 80a4a000                 cmp     %l2, 0
F005C180: 02800004                 be      loc_F005C190
F005C184: 90100012                 mov     %l2, %o0
F005C188: 7ffff41f                 call    _ipc_notify_no_senders
F005C18C: 92100013                 mov     %l3, %o1
F005C190: 80a62000                 cmp     %i0, 0
F005C194: 02800007                 be      locret_F005C1B0
F005C198: 90100018                 mov     %i0, %o0! char *
F005C19C: 7ffff394                 call    _ipc_notify_port_deleted
F005C1A0: 92100019                 mov     %i1, %o1
F005C1A4: 30800003                 ba,a    locret_F005C1B0
F005C1A8: 7ffee3f2                 call    _panic
F005C1AC: 90122298                 bset    0x298, %o0
F005C1B0: 81c7e008                 ret
F005C1B4: 81e80000                 restore
