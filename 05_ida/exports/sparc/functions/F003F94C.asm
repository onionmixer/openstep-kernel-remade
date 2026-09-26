F003F94C: 9de3bf58                 save    %sp, -0xA8, %sp
F003F950: 90100018                 mov     %i0, %o0
F003F954: 9207bfb8                 add     %fp, var_48, %o1
F003F958: 9410001a                 mov     %i2, %o2
F003F95C: 7fffe813                 call    _nfsgetattr
F003F960: 96102000                 mov     0, %o3
F003F964: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F003F968: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F003F96C: d02aa038                 stb     %o0, [%o2+0x38]
F003F970: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F003F974: f04a2038                 ldsb    [%o0+0x38], %i0
F003F978: 80a62000                 cmp     %i0, 0
F003F97C: 12800029                 bne     locret_F003FA20
F003F980: 01000000                 nop
F003F984: d256a002                 ldsh    [%i2+2], %o1
F003F988: 80a26000                 cmp     %o1, 0
F003F98C: 02800024                 be      loc_F003FA1C
F003F990: d057bfbe                 ldsh    [%fp+var_42], %o0
F003F994: 80a24008                 cmp     %o1, %o0
F003F998: 02800018                 be      loc_F003F9F8
F003F99C: d017bfbc                 lduh    [%fp+var_44], %o0
F003F9A0: d056a004                 ldsh    [%i2+4], %o0
F003F9A4: d657bfc0                 ldsh    [%fp+var_40], %o3
F003F9A8: 80a2000b                 cmp     %o0, %o3
F003F9AC: 02800012                 be      loc_F003F9F4
F003F9B0: b33e6003                 sra     %i1, 3, %i1
F003F9B4: 9206a00a                 add     %i2, 0xA, %o1
F003F9B8: 9406a02a                 add     %i2, 0x2A, %o2 ! '*'
F003F9BC: 80a2400a                 cmp     %o1, %o2
F003F9C0: 3a80000d                 bcc,a   loc_F003F9F4
F003F9C4: b33e6003                 sra     %i1, 3, %i1
F003F9C8: d0524000                 ldsh    [%o1], %o0
F003F9CC: 80a23fff                 cmp     %o0, -1
F003F9D0: 02800008                 be      loc_F003F9F0
F003F9D4: 80a2c008                 cmp     %o3, %o0
F003F9D8: 22800008                 be,a    loc_F003F9F8
F003F9DC: d017bfbc                 lduh    [%fp+var_44], %o0
F003F9E0: 92026002                 inc     2, %o1
F003F9E4: 80a2400a                 cmp     %o1, %o2
F003F9E8: 2abffff9                 bcs,a   loc_F003F9CC
F003F9EC: d0524000                 ldsh    [%o1], %o0
F003F9F0: b33e6003                 sra     %i1, 3, %i1
F003F9F4: d017bfbc                 lduh    [%fp+var_44], %o0
F003F9F8: 900a0019                 and     %o0, %i1, %o0
F003F9FC: 80a20019                 cmp     %o0, %i1
F003FA00: 02800007                 be      loc_F003FA1C
F003FA04: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F003FA08: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F003FA0C: b010200d                 mov     0xD, %i0
F003FA10: 9010200d                 mov     0xD, %o0
F003FA14: 10800003                 ba      locret_F003FA20
F003FA18: d02a6038                 stb     %o0, [%o1+0x38]
F003FA1C: b0102000                 mov     0, %i0
F003FA20: 81c7e008                 ret
F003FA24: 81e80000                 restore
