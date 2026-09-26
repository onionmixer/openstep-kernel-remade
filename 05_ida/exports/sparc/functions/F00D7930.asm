F00D7930: 9de3bf88                 save    %sp, -0x78, %sp
F00D7934: c02fbfef                 clrb    [%fp+var_11]
F00D7938: 113c04bb                 sethi   %hi(unk_F012EEFC), %o0
F00D793C: d04a22fc                 ldsb    [%o0+%lo(unk_F012EEFC)], %o0
F00D7940: 80a22000                 cmp     %o0, 0
F00D7944: 02800007                 be      loc_F00D7960
F00D7948: c02fbfee                 clrb    [%fp+var_12]
F00D794C: 113c04bb                 sethi   %hi(dword_F012EF08), %o0
F00D7950: d0022308                 ld      [%o0+%lo(dword_F012EF08)], %o0
F00D7954: 80a22000                 cmp     %o0, 0
F00D7958: 12800009                 bne     loc_F00D797C
F00D795C: 113c04bb                 sethi   -0xFED1400, %o0
F00D7960: 90100018                 mov     %i0, %o0! id
F00D7964: 133c0505                 sethi   %hi(paInterruptoccur_1), %o1
F00D7968: d2026204                 ld      [%o1+%lo(paInterruptoccur_1)], %o1! SEL
F00D796C: 9407bfef                 add     %fp, var_11, %o2
F00D7970: 400067c0                 call    _objc_msgSend
F00D7974: 9607bfee                 add     %fp, var_12, %o3
F00D7978: 113c04bb                 sethi   -0xFED1400, %o0
F00D797C: d04a22fc                 ldsb    [%o0+0x2FC], %o0
F00D7980: 80a22000                 cmp     %o0, 0
F00D7984: 12800028                 bne     locret_F00D7A24
F00D7988: d04fbfef                 ldsb    [%fp+var_11], %o0
F00D798C: 80a22000                 cmp     %o0, 0
F00D7990: 12800006                 bne     loc_F00D79A8
F00D7994: 113c0505                 sethi   -0xFEBEC00, %o0
F00D7998: d04fbfee                 ldsb    [%fp+var_12], %o0
F00D799C: 80a22000                 cmp     %o0, 0
F00D79A0: 02800021                 be      locret_F00D7A24
F00D79A4: 113c0505                 sethi   -0xFEBEC00, %o0
F00D79A8: d2022200                 ld      [%o0+0x200], %o1! SEL
F00D79AC: 113c04cc                 sethi   %hi(qword_F01330D8), %o0! id
F00D79B0: d41a20d8                 ldd     [%o0+%lo(qword_F01330D8)], %o2
F00D79B4: 400067af                 call    _objc_msgSend
F00D79B8: 90100018                 mov     %i0, %o0
F00D79BC: d04fbfef                 ldsb    [%fp+var_11], %o0
F00D79C0: 80a22000                 cmp     %o0, 0
F00D79C4: 0280000b                 be      loc_F00D79F0
F00D79C8: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D79CC: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D79D0: 113c0505                 sethi   %hi(paAttempttostopd), %o0! id
F00D79D4: e00221fc                 ld      [%o0+%lo(paAttempttostopd)], %l0
F00D79D8: 400067a6                 call    _objc_msgSend
F00D79DC: 90100018                 mov     %i0, %o0
F00D79E0: 94100008                 mov     %o0, %o2
F00D79E4: 90100018                 mov     %i0, %o0! id
F00D79E8: 400067a2                 call    _objc_msgSend
F00D79EC: 92100010                 mov     %l0, %o1
F00D79F0: d04fbfee                 ldsb    [%fp+var_12], %o0
F00D79F4: 80a22000                 cmp     %o0, 0
F00D79F8: 0280000b                 be      locret_F00D7A24
F00D79FC: 113c0505                 sethi   %hi(paOutputchannel), %o0
F00D7A00: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D7A04: 113c0505                 sethi   %hi(paAttempttostopd), %o0! id
F00D7A08: e00221fc                 ld      [%o0+%lo(paAttempttostopd)], %l0
F00D7A0C: 40006799                 call    _objc_msgSend
F00D7A10: 90100018                 mov     %i0, %o0
F00D7A14: 94100008                 mov     %o0, %o2
F00D7A18: 90100018                 mov     %i0, %o0! id
F00D7A1C: 40006795                 call    _objc_msgSend
F00D7A20: 92100010                 mov     %l0, %o1
F00D7A24: 81c7e008                 ret
F00D7A28: 81e80000                 restore
