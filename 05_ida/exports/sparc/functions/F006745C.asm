F006745C: 9de3bf98                 save    %sp, -0x68, %sp
F0067460: 80a62000                 cmp     %i0, 0
F0067464: 12800004                 bne     loc_F0067474
F0067468: 80a66002                 cmp     %i1, 2
F006746C: 10800042                 ba      locret_F0067574
F0067470: b0102004                 mov     4, %i0
F0067474: 0280000f                 be      loc_F00674B0
F0067478: 80a66002                 cmp     %i1, 2
F006747C: 14800007                 bg      loc_F0067498
F0067480: 80a66003                 cmp     %i1, 3
F0067484: 80a66001                 cmp     %i1, 1
F0067488: 02800020                 be      loc_F0067508
F006748C: a006206c                 add     %i0, 0x6C, %l0 ! 'l'
F0067490: 10800039                 ba      locret_F0067574
F0067494: b0102004                 mov     4, %i0
F0067498: 0280001b                 be      loc_F0067504
F006749C: 80a66004                 cmp     %i1, 4
F00674A0: 0280001a                 be      loc_F0067508
F00674A4: a0062074                 add     %i0, 0x74, %l0 ! 't'
F00674A8: 10800033                 ba      locret_F0067574
F00674AC: b0102004                 mov     4, %i0
F00674B0: f0062088                 ld      [%i0+0x88], %i0
F00674B4: b2062008                 add     %i0, 8, %i1
F00674B8: d0064000                 ld      [%i1], %o0
F00674BC: 80a22000                 cmp     %o0, 0
F00674C0: 12bffffe                 bne     loc_F00674B8
F00674C4: 01000000                 nop
F00674C8: 4000be78                 call    _simple_lock_try
F00674CC: 90100019                 mov     %i1, %o0
F00674D0: 80a22000                 cmp     %o0, 0
F00674D4: 02bffff9                 be      loc_F00674B8
F00674D8: 01000000                 nop
F00674DC: d006200c                 ld      [%i0+0xC], %o0
F00674E0: 80a22000                 cmp     %o0, 0
F00674E4: 32800005                 bne,a   loc_F00674F8
F00674E8: d0062044                 ld      [%i0+0x44], %o0
F00674EC: c0262008                 clr     [%i0+8]
F00674F0: 10800021                 ba      locret_F0067574
F00674F4: b0102005                 mov     5, %i0
F00674F8: c0262008                 clr     [%i0+8]
F00674FC: 10800016                 ba      loc_F0067554
F0067500: f4262044                 st      %i2, [%i0+0x44]
F0067504: a0062070                 add     %i0, 0x70, %l0 ! 'p'
F0067508: b2062064                 add     %i0, 0x64, %i1 ! 'd'
F006750C: d0064000                 ld      [%i1], %o0
F0067510: 80a22000                 cmp     %o0, 0
F0067514: 12bffffe                 bne     loc_F006750C
F0067518: 01000000                 nop
F006751C: 4000be63                 call    _simple_lock_try
F0067520: 90100019                 mov     %i1, %o0
F0067524: 80a22000                 cmp     %o0, 0
F0067528: 02bffff9                 be      loc_F006750C
F006752C: 01000000                 nop
F0067530: d0062068                 ld      [%i0+0x68], %o0
F0067534: 80a22000                 cmp     %o0, 0
F0067538: 32800005                 bne,a   loc_F006754C
F006753C: d0040000                 ld      [%l0], %o0
F0067540: c0262064                 clr     [%i0+0x64]
F0067544: 1080000c                 ba      locret_F0067574
F0067548: b0102005                 mov     5, %i0
F006754C: f4240000                 st      %i2, [%l0]
F0067550: c0262064                 clr     [%i0+0x64]
F0067554: 80a22000                 cmp     %o0, 0
F0067558: 02800006                 be      loc_F0067570
F006755C: 80a23fff                 cmp     %o0, -1
F0067560: 02800005                 be      locret_F0067574
F0067564: b0102000                 mov     0, %i0
F0067568: 7fffceed                 call    _ipc_port_release_send
F006756C: 01000000                 nop
F0067570: b0102000                 mov     0, %i0
F0067574: 81c7e008                 ret
F0067578: 81e80000                 restore
