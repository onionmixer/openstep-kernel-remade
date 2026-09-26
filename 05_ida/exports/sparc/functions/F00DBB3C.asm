F00DBB3C: 9de3bf90                 save    %sp, -0x70, %sp
F00DBB40: d006202c                 ld      [%i0+0x2C], %o0
F00DBB44: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DBB48: 80a24008                 cmp     %o1, %o0
F00DBB4C: 02800019                 be      locret_F00DBBB0
F00DBB50: a0100009                 mov     %o1, %l0
F00DBB54: 233c0505                 sethi   -0xFEBEC00, %l1
F00DBB58: d406202c                 ld      [%i0+0x2C], %o2
F00DBB5C: d602a03c                 ld      [%o2+0x3C], %o3
F00DBB60: 80a4000b                 cmp     %l0, %o3
F00DBB64: 12800004                 bne     loc_F00DBB74
F00DBB68: d202a040                 ld      [%o2+0x40], %o1! SEL
F00DBB6C: 10800003                 ba      loc_F00DBB78
F00DBB70: 90100010                 mov     %l0, %o0
F00DBB74: 9002e03c                 add     %o3, 0x3C, %o0 ! '<'
F00DBB78: 80a40009                 cmp     %l0, %o1
F00DBB7C: 12800004                 bne     loc_F00DBB8C
F00DBB80: d2222004                 st      %o1, [%o0+4]
F00DBB84: 10800003                 ba      loc_F00DBB90
F00DBB88: 90100010                 mov     %l0, %o0
F00DBB8C: 9002603c                 add     %o1, 0x3C, %o0 ! '<'
F00DBB90: d6220000                 st      %o3, [%o0]
F00DBB94: 90100018                 mov     %i0, %o0! id
F00DBB98: 40005736                 call    _objc_msgSend
F00DBB9C: d204606c                 ld      [%l1+0x6C], %o1
F00DBBA0: d006202c                 ld      [%i0+0x2C], %o0
F00DBBA4: 80a40008                 cmp     %l0, %o0
F00DBBA8: 32bfffed                 bne,a   loc_F00DBB5C
F00DBBAC: d406202c                 ld      [%i0+0x2C], %o2
F00DBBB0: 81c7e008                 ret
F00DBBB4: 81e80000                 restore
