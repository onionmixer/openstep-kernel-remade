F00A5130: 9de3bf98                 save    %sp, -0x68, %sp
F00A5134: 80a66000                 cmp     %i1, 0
F00A5138: 14800005                 bg      loc_F00A514C
F00A513C: a0062008                 add     %i0, 8, %l0
F00A5140: 113c0466                 sethi   %hi(aRmget), %o0! "rmget"
F00A5144: 7ffdc00b                 call    _panic
F00A5148: 901220c8                 bset    %lo(aRmget), %o0! "rmget"
F00A514C: d0062008                 ld      [%i0+8], %o0
F00A5150: 80a22000                 cmp     %o0, 0
F00A5154: 02800010                 be      loc_F00A5194
F00A5158: 98100010                 mov     %l0, %o4
F00A515C: d2032004                 ld      [%o4+4], %o1
F00A5160: 80a2401a                 cmp     %o1, %i2
F00A5164: 38800008                 bgu,a   loc_F00A5184
F00A5168: 98032008                 inc     8, %o4
F00A516C: d0030000                 ld      [%o4], %o0
F00A5170: 90024008                 add     %o1, %o0, %o0
F00A5174: 80a2001a                 cmp     %o0, %i2
F00A5178: 38800008                 bgu,a   loc_F00A5198
F00A517C: d0030000                 ld      [%o4], %o0
F00A5180: 98032008                 inc     8, %o4
F00A5184: d0030000                 ld      [%o4], %o0
F00A5188: 80a22000                 cmp     %o0, 0
F00A518C: 32bffff5                 bne,a   loc_F00A5160
F00A5190: d2032004                 ld      [%o4+4], %o1
F00A5194: d0030000                 ld      [%o4], %o0
F00A5198: 80a22000                 cmp     %o0, 0
F00A519C: 02800025                 be      loc_F00A5230
F00A51A0: 92068019                 add     %i2, %i1, %o1
F00A51A4: d4032004                 ld      [%o4+4], %o2
F00A51A8: 96028008                 add     %o2, %o0, %o3
F00A51AC: 80a2c009                 cmp     %o3, %o1
F00A51B0: 0a800020                 bcs     loc_F00A5230
F00A51B4: 80a2801a                 cmp     %o2, %i2
F00A51B8: 12800017                 bne     loc_F00A5214
F00A51BC: 80a2c009                 cmp     %o3, %o1
F00A51C0: 80a20019                 cmp     %o0, %i1
F00A51C4: 32800011                 bne,a   loc_F00A5208
F00A51C8: d0030000                 ld      [%o4], %o0
F00A51CC: 9410000c                 mov     %o4, %o2
F00A51D0: 9202a004                 add     %o2, 4, %o1
F00A51D4: d0026004                 ld      [%o1+4], %o0
F00A51D8: d0228000                 st      %o0, [%o2]
F00A51DC: d0026008                 ld      [%o1+8], %o0
F00A51E0: 9402a008                 inc     8, %o2
F00A51E4: d0224000                 st      %o0, [%o1]
F00A51E8: d0028000                 ld      [%o2], %o0
F00A51EC: 80a22000                 cmp     %o0, 0
F00A51F0: 12bffff9                 bne     loc_F00A51D4
F00A51F4: 92026008                 inc     8, %o1
F00A51F8: d0060000                 ld      [%i0], %o0
F00A51FC: 90022001                 inc     %o0
F00A5200: 1080002e                 ba      loc_F00A52B8
F00A5204: d0260000                 st      %o0, [%i0]
F00A5208: d2232004                 st      %o1, [%o4+4]
F00A520C: 1080002a                 ba      loc_F00A52B4
F00A5210: 90220019                 sub     %o0, %i1, %o0
F00A5214: 32800004                 bne,a   loc_F00A5224
F00A5218: d0060000                 ld      [%i0], %o0
F00A521C: 10800026                 ba      loc_F00A52B4
F00A5220: 90220019                 sub     %o0, %i1, %o0
F00A5224: 80a22000                 cmp     %o0, 0
F00A5228: 12800004                 bne     loc_F00A5238
F00A522C: 9410000c                 mov     %o4, %o2
F00A5230: 10800023                 ba      locret_F00A52BC
F00A5234: b0102000                 mov     0, %i0
F00A5238: 9402a008                 inc     8, %o2
F00A523C: d0028000                 ld      [%o2], %o0
F00A5240: 80a22000                 cmp     %o0, 0
F00A5244: 32bffffe                 bne,a   loc_F00A523C
F00A5248: 9402a008                 inc     8, %o2
F00A524C: c022a008                 clr     [%o2+8]
F00A5250: 9402bff8                 inc     -8, %o2
F00A5254: 80a2800c                 cmp     %o2, %o4
F00A5258: 2280000c                 be,a    loc_F00A5288
F00A525C: d0060000                 ld      [%i0], %o0
F00A5260: 9602a00c                 add     %o2, 0xC, %o3
F00A5264: d0028000                 ld      [%o2], %o0
F00A5268: d202fff8                 ld      [%o3-8], %o1
F00A526C: d022fffc                 st      %o0, [%o3-4]
F00A5270: d222c000                 st      %o1, [%o3]
F00A5274: 9402bff8                 inc     -8, %o2
F00A5278: 80a2800c                 cmp     %o2, %o4
F00A527C: 12bffffa                 bne     loc_F00A5264
F00A5280: 9602fff8                 inc     -8, %o3
F00A5284: d0060000                 ld      [%i0], %o0
F00A5288: 90023fff                 inc     -1, %o0
F00A528C: d0260000                 st      %o0, [%i0]
F00A5290: d2032004                 ld      [%o4+4], %o1
F00A5294: 94068019                 add     %i2, %i1, %o2
F00A5298: d0030000                 ld      [%o4], %o0
F00A529C: d423200c                 st      %o2, [%o4+0xC]
F00A52A0: 92024008                 add     %o1, %o0, %o1
F00A52A4: 9222400a                 sub     %o1, %o2, %o1
F00A52A8: d0032004                 ld      [%o4+4], %o0
F00A52AC: d2232008                 st      %o1, [%o4+8]
F00A52B0: 90268008                 sub     %i2, %o0, %o0
F00A52B4: d0230000                 st      %o0, [%o4]
F00A52B8: b010001a                 mov     %i2, %i0
F00A52BC: 81c7e008                 ret
F00A52C0: 81e80000                 restore
