F00C52A8: 9de3bf88                 save    %sp, -0x78, %sp
F00C52AC: 9010001b                 mov     %i3, %o0! __s1
F00C52B0: 133c03ea                 sethi   %hi(aIounit), %o1! "IOUnit"
F00C52B4: 7ffd0bbe                 call    _strcmp
F00C52B8: 92126198                 bset    %lo(aIounit), %o1! "IOUnit"
F00C52BC: 80a22000                 cmp     %o0, 0
F00C52C0: 12800004                 bne     loc_F00C52D0
F00C52C4: 9010001b                 mov     %i3, %o0
F00C52C8: 10800025                 ba      loc_F00C535C
F00C52CC: d0062004                 ld      [%i0+4], %o0! __s1
F00C52D0: 133c03ea                 sethi   %hi(aIoblockmajor), %o1! "IOBlockMajor"
F00C52D4: 7ffd0bb6                 call    _strcmp
F00C52D8: 921261a0                 bset    %lo(aIoblockmajor), %o1! "IOBlockMajor"
F00C52DC: 80a22000                 cmp     %o0, 0
F00C52E0: 3280000e                 bne,a   loc_F00C5318
F00C52E4: 9010001b                 mov     %i3, %o0
F00C52E8: 113c0504                 sethi   %hi(paClass), %o0! id
F00C52EC: d2022014                 ld      [%o0+%lo(paClass)], %o1! SEL
F00C52F0: 4000b160                 call    _objc_msgSend
F00C52F4: 90100018                 mov     %i0, %o0
F00C52F8: 7ffffd2a                 call    sub_F00C47A0
F00C52FC: 9207bfec                 add     %fp, var_14, %o1
F00C5300: 80a22000                 cmp     %o0, 0
F00C5304: 1280001a                 bne     locret_F00C536C
F00C5308: b0103d39                 mov     -0x2C7, %i0
F00C530C: d007bfec                 ld      [%fp+var_14], %o0
F00C5310: 10800013                 ba      loc_F00C535C
F00C5314: d0022008                 ld      [%o0+8], %o0! __s1
F00C5318: 133c03ea                 sethi   %hi(aIocharactermaj), %o1! "IOCharacterMajor"
F00C531C: 7ffd0ba4                 call    _strcmp
F00C5320: 921261b0                 bset    %lo(aIocharactermaj), %o1! "IOCharacterMajor"
F00C5324: 80a22000                 cmp     %o0, 0
F00C5328: 32800011                 bne,a   locret_F00C536C
F00C532C: b0103d39                 mov     -0x2C7, %i0
F00C5330: 113c0504                 sethi   %hi(paClass), %o0! id
F00C5334: d2022014                 ld      [%o0+%lo(paClass)], %o1! SEL
F00C5338: 4000b14e                 call    _objc_msgSend
F00C533C: 90100018                 mov     %i0, %o0
F00C5340: 7ffffd18                 call    sub_F00C47A0
F00C5344: 9207bfe8                 add     %fp, var_18, %o1
F00C5348: 80a22000                 cmp     %o0, 0
F00C534C: 12800008                 bne     locret_F00C536C
F00C5350: b0103d39                 mov     -0x2C7, %i0
F00C5354: d007bfe8                 ld      [%fp+var_18], %o0
F00C5358: d002200c                 ld      [%o0+0xC], %o0
F00C535C: b0102000                 mov     0, %i0
F00C5360: d0268000                 st      %o0, [%i2]
F00C5364: 90102001                 mov     1, %o0
F00C5368: d0270000                 st      %o0, [%i4]
F00C536C: 81c7e008                 ret
F00C5370: 81e80000                 restore
