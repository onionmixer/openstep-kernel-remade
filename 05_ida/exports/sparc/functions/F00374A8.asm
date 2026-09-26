F00374A8: 9de3bf98                 save    %sp, -0x68, %sp
F00374AC: a0100018                 mov     %i0, %l0
F00374B0: 4000c2f0                 call    _kalloc
F00374B4: 9010206c                 mov     0x6C, %o0 ! 'l'
F00374B8: b0920000                 orcc    %o0, %g0, %i0
F00374BC: 12800004                 bne     loc_F00374CC
F00374C0: 90100018                 mov     %i0, %o0! void *
F00374C4: 10800018                 ba      locret_F0037524
F00374C8: b0102000                 mov     0, %i0
F00374CC: 40017663                 call    _bzero
F00374D0: 9210206c                 mov     0x6C, %o1 ! 'l'
F00374D4: f0262004                 st      %i0, [%i0+4]
F00374D8: f0260000                 st      %i0, [%i0]
F00374DC: e0262020                 st      %l0, [%i0+0x20]
F00374E0: 90102002                 mov     2, %o0
F00374E4: d0362064                 sth     %o0, [%i0+0x64]
F00374E8: 9010200c                 mov     0xC, %o0
F00374EC: d0362014                 sth     %o0, [%i0+0x14]
F00374F0: 90103fff                 mov     -1, %o0
F00374F4: d0362054                 sth     %o0, [%i0+0x54]
F00374F8: d0362056                 sth     %o0, [%i0+0x56]
F00374FC: 113c0432                 sethi   %hi(_tcp_mssdflt), %o0
F0037500: d2022110                 ld      [%o0+%lo(_tcp_mssdflt)], %o1
F0037504: c0362060                 clrh    [%i0+0x60]
F0037508: c02e201b                 clrb    [%i0+0x1B]
F003750C: 113c0432                 sethi   %hi(_tcp_rttdflt), %o0
F0037510: d0022114                 ld      [%o0+%lo(_tcp_rttdflt)], %o0
F0037514: d2362018                 sth     %o1, [%i0+0x18]
F0037518: 912a2003                 sll     %o0, 3, %o0
F003751C: d0362062                 sth     %o0, [%i0+0x62]
F0037520: f0242020                 st      %i0, [%l0+0x20]
F0037524: 81c7e008                 ret
F0037528: 81e80000                 restore
