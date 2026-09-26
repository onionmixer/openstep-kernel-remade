F0022368: 9de3bf98                 save    %sp, -0x68, %sp! int
F002236C: a0100018                 mov     %i0, %l0
F0022370: 80a6a070                 cmp     %i2, 0x70 ! 'p'
F0022374: 04800004                 ble     loc_F0022384
F0022378: 9210001b                 mov     %i3, %o1
F002237C: 10800013                 ba      locret_F00223C8
F0022380: b0102016                 mov     0x16, %i0
F0022384: 7fffed76                 call    _m_get
F0022388: 90102001                 mov     1, %o0
F002238C: b6920000                 orcc    %o0, %g0, %i3
F0022390: 32800004                 bne,a   loc_F00223A0
F0022394: f436e008                 sth     %i2, [%i3+8]
F0022398: 1080000c                 ba      locret_F00223C8
F002239C: b0102037                 mov     0x37, %i0 ! '7'
F00223A0: d206e004                 ld      [%i3+4], %o1! int
F00223A4: 90100019                 mov     %i1, %o0! int
F00223A8: 9410001a                 mov     %i2, %o2! int
F00223AC: 4001d72b                 call    _copyin
F00223B0: 9206c009                 add     %i3, %o1, %o1
F00223B4: b0920000                 orcc    %o0, %g0, %i0
F00223B8: 22800004                 be,a    locret_F00223C8
F00223BC: f6240000                 st      %i3, [%l0]
F00223C0: 7fffedbd                 call    _m_free
F00223C4: 9010001b                 mov     %i3, %o0
F00223C8: 81c7e008                 ret
F00223CC: 81e80000                 restore
