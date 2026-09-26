F006356C: 9de3bf88                 save    %sp, -0x78, %sp
F0063570: 80a62000                 cmp     %i0, 0
F0063574: 0280002a                 be      loc_F006361C
F0063578: 90100018                 mov     %i0, %o0
F006357C: 9210001a                 mov     %i2, %o1
F0063580: 7fffe13f                 call    _ipc_right_lookup_write
F0063584: 9407bff4                 add     %fp, var_C, %o2
F0063588: 80a22000                 cmp     %o0, 0
F006358C: 3280002a                 bne,a   locret_F0063634
F0063590: b0102004                 mov     4, %i0
F0063594: 90100018                 mov     %i0, %o0
F0063598: 9210001a                 mov     %i2, %o1
F006359C: d407bff4                 ld      [%fp+var_C], %o2
F00635A0: 9607bff0                 add     %fp, var_10, %o3
F00635A4: 7fffe5c7                 call    _ipc_right_info
F00635A8: 9807bfec                 add     %fp, var_14, %o4
F00635AC: 80a22000                 cmp     %o0, 0
F00635B0: 32800021                 bne,a   locret_F0063634
F00635B4: b0102004                 mov     4, %i0
F00635B8: d207bff0                 ld      [%fp+var_10], %o1
F00635BC: 11000080                 sethi   0x20000, %o0
F00635C0: 808a4008                 btst    %o0, %o1
F00635C4: 32800009                 bne,a   loc_F00635E8
F00635C8: d207bff4                 ld      [%fp+var_C], %o1
F00635CC: c0262008                 clr     [%i0+8]
F00635D0: 110005c0                 sethi   0x170000, %o0
F00635D4: 808a4008                 btst    %o0, %o1
F00635D8: 02800017                 be      locret_F0063634
F00635DC: b0102004                 mov     4, %i0
F00635E0: 10800015                 ba      locret_F0063634
F00635E4: b0102007                 mov     7, %i0
F00635E8: f4026004                 ld      [%o1+4], %i2
F00635EC: 90100018                 mov     %i0, %o0
F00635F0: 7fffc113                 call    _ipc_entry_lookup
F00635F4: 92100019                 mov     %i1, %o1
F00635F8: 94920000                 orcc    %o0, %g0, %o2
F00635FC: 02800007                 be      loc_F0063618
F0063600: d427bff4                 st      %o2, [%fp+var_C]
F0063604: d2028000                 ld      [%o2], %o1
F0063608: 11000200                 sethi   0x80000, %o0
F006360C: 808a4008                 btst    %o0, %o1
F0063610: 12800005                 bne     loc_F0063624
F0063614: 90100018                 mov     %i0, %o0
F0063618: c0262008                 clr     [%i0+8]
F006361C: 10800006                 ba      locret_F0063634
F0063620: b0102004                 mov     4, %i0
F0063624: d402a004                 ld      [%o2+4], %o2
F0063628: 7fffe067                 call    _ipc_pset_move
F006362C: 9210001a                 mov     %i2, %o1
F0063630: b0100008                 mov     %o0, %i0
F0063634: 81c7e008                 ret
F0063638: 81e80000                 restore
