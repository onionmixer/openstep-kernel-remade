F003C118: 9de3bf98                 save    %sp, -0x68, %sp
F003C11C: 113c0433                 sethi   %hi(_nfs_portmon), %o0
F003C120: d0022044                 ld      [%o0+%lo(_nfs_portmon)], %o0
F003C124: 80a22000                 cmp     %o0, 0
F003C128: 22800010                 be,a    loc_F003C168
F003C12C: d206600c                 ld      [%i1+0xC], %o1
F003C130: d206601c                 ld      [%i1+0x1C], %o1
F003C134: d0126012                 lduh    [%o1+0x12], %o0
F003C138: 80a223ff                 cmp     %o0, 0x3FF
F003C13C: 0880000a                 bleu    loc_F003C164
F003C140: 90026014                 add     %o1, 0x14, %o0! char *
F003C144: 213c0433                 sethi   %hi(aNfsRequestFrom), %l0! "NFS request from unprivileged port from"...
F003C148: 7fffcc93                 call    _inet_ntoa
F003C14C: a0142148                 bset    %lo(aNfsRequestFrom), %l0! "NFS request from unprivileged port from"...
F003C150: 92100008                 mov     %o0, %o1
F003C154: 7fff6141                 call    _printf
F003C158: 90100010                 mov     %l0, %o0
F003C15C: 1080003d                 ba      locret_F003C250
F003C160: b0102000                 mov     0, %i0
F003C164: d206600c                 ld      [%i1+0xC], %o1
F003C168: d0062008                 ld      [%i0+8], %o0
F003C16C: 80a24008                 cmp     %o1, %o0
F003C170: 32800002                 bne,a   loc_F003C178
F003C174: 92102000                 mov     0, %o1
F003C178: 80a26000                 cmp     %o1, 0
F003C17C: 02800010                 be      loc_F003C1BC
F003C180: 80a26001                 cmp     %o1, 1
F003C184: 32800033                 bne,a   locret_F003C250
F003C188: b0102000                 mov     0, %i0
F003C18C: e0066018                 ld      [%i1+0x18], %l0
F003C190: d0042008                 ld      [%l0+8], %o0
F003C194: 80a22000                 cmp     %o0, 0
F003C198: 32800010                 bne,a   loc_F003C1D8
F003C19C: d036a002                 sth     %o0, [%i2+2]
F003C1A0: d006601c                 ld      [%i1+0x1C], %o0
F003C1A4: 9206200c                 add     %i0, 0xC, %o1
F003C1A8: 7fffffc5                 call    sub_F003C0BC
F003C1AC: 90022010                 inc     0x10, %o0
F003C1B0: 80a22000                 cmp     %o0, 0
F003C1B4: 32800008                 bne,a   loc_F003C1D4
F003C1B8: d0042008                 ld      [%l0+8], %o0
F003C1BC: d0062004                 ld      [%i0+4], %o0
F003C1C0: d036a002                 sth     %o0, [%i2+2]
F003C1C4: d0062004                 ld      [%i0+4], %o0
F003C1C8: 9206a00a                 add     %i2, 0xA, %o1
F003C1CC: 10800013                 ba      loc_F003C218
F003C1D0: d036a004                 sth     %o0, [%i2+4]
F003C1D4: d036a002                 sth     %o0, [%i2+2]
F003C1D8: d004200c                 ld      [%l0+0xC], %o0
F003C1DC: d036a004                 sth     %o0, [%i2+4]
F003C1E0: d0042010                 ld      [%l0+0x10], %o0
F003C1E4: 9206a00a                 add     %i2, 0xA, %o1
F003C1E8: 10800006                 ba      loc_F003C200
F003C1EC: d4042014                 ld      [%l0+0x14], %o2
F003C1F0: d0324000                 sth     %o0, [%o1]
F003C1F4: 9402a004                 inc     4, %o2
F003C1F8: d0042010                 ld      [%l0+0x10], %o0
F003C1FC: 92026002                 inc     2, %o1
F003C200: 912a2001                 sll     %o0, 1, %o0
F003C204: 9002200a                 inc     0xA, %o0
F003C208: 90068008                 add     %i2, %o0, %o0
F003C20C: 80a24008                 cmp     %o1, %o0
F003C210: 2abffff8                 bcs,a   loc_F003C1F0
F003C214: d012a002                 lduh    [%o2+2], %o0
F003C218: 9006a02a                 add     %i2, 0x2A, %o0 ! '*'
F003C21C: 80a24008                 cmp     %o1, %o0
F003C220: 3a800009                 bcc,a   loc_F003C244
F003C224: d056a002                 ldsh    [%i2+2], %o0
F003C228: 94103fff                 mov     -1, %o2
F003C22C: d4324000                 sth     %o2, [%o1]
F003C230: 92026002                 inc     2, %o1
F003C234: 80a24008                 cmp     %o1, %o0
F003C238: 2abffffe                 bcs,a   loc_F003C230
F003C23C: d4324000                 sth     %o2, [%o1]
F003C240: d056a002                 ldsh    [%i2+2], %o0
F003C244: 90380008                 xnor    %g0, %o0, %o0
F003C248: 80a00008                 cmp     %g0, %o0
F003C24C: b0402000                 addc    %g0, 0, %i0
F003C250: 81c7e008                 ret
F003C254: 81e80000                 restore
