F00AA484: 9de3bf70                 save    %sp, -0x90, %sp
F00AA488: f027a044                 st      %i0, [%fp+arg_44]
F00AA48C: 213c04d0                 sethi   %hi(_active_threads), %l0
F00AA490: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F00AA494: f227a048                 st      %i1, [%fp+arg_48]
F00AA498: d0022028                 ld      [%o0+0x28], %o0
F00AA49C: f427a04c                 st      %i2, [%fp+arg_4C]
F00AA4A0: 7fffede6                 call    _flush_user_windows_to_stack
F00AA4A4: d027bfd4                 st      %o0, [%fp+var_2C]
F00AA4A8: 113c04cf                 sethi   %hi(_active_u), %o0
F00AA4AC: d60221d8                 ld      [%o0+%lo(_active_u)], %o3
F00AA4B0: d4042260                 ld      [%l0+%lo(_active_threads)], %o2
F00AA4B4: d002e148                 ld      [%o3+0x148], %o0
F00AA4B8: d202e148                 ld      [%o3+0x148], %o1
F00AA4BC: d027bfec                 st      %o0, [%fp+var_14]
F00AA4C0: d002a028                 ld      [%o2+0x28], %o0
F00AA4C4: 80a26000                 cmp     %o1, 0
F00AA4C8: 90022234                 inc     0x234, %o0
F00AA4CC: 1280000e                 bne     loc_F00AA504
F00AA4D0: d027bfe4                 st      %o0, [%fp+var_1C]
F00AA4D4: d007a048                 ld      [%fp+arg_48], %o0
F00AA4D8: d202e138                 ld      [%o3+0x138], %o1
F00AA4DC: 90023fff                 inc     -1, %o0
F00AA4E0: 933a4008                 sra     %o1, %o0, %o1
F00AA4E4: 808a6001                 btst    1, %o1
F00AA4E8: 02800007                 be      loc_F00AA504
F00AA4EC: 90102001                 mov     1, %o0
F00AA4F0: d202e144                 ld      [%o3+0x144], %o1
F00AA4F4: d022e148                 st      %o0, [%o3+0x148]
F00AA4F8: 92027750                 inc     -0x8B0, %o1
F00AA4FC: 10800006                 ba      loc_F00AA514
F00AA500: d227bfdc                 st      %o1, [%fp+var_24]
F00AA504: d807bfe4                 ld      [%fp+var_1C], %o4
F00AA508: d0032044                 ld      [%o4+0x44], %o0
F00AA50C: 90023750                 inc     -0x8B0, %o0
F00AA510: d027bfdc                 st      %o0, [%fp+var_24]
F00AA514: da07bfdc                 ld      [%fp+var_24], %o5
F00AA518: 808b6007                 btst    7, %o5
F00AA51C: 1280000c                 bne     loc_F00AA54C
F00AA520: 213c04cf                 sethi   %hi(_active_u), %l0
F00AA524: 113bffff901223ff         set     -0x10000001, %o0
F00AA52C: 80a34008                 cmp     %o5, %o0
F00AA530: 38800008                 bgu,a   loc_F00AA550
F00AA534: d00421d8                 ld      [%l0+%lo(_active_u)], %o0! jmp_buf
F00AA538: 7fffb207                 call    _setjmp
F00AA53C: 9007bff0                 add     %fp, var_10, %o0
F00AA540: 80a22000                 cmp     %o0, 0
F00AA544: 02800028                 be      loc_F00AA5E4
F00AA548: 213c04cf                 sethi   -0xFECC400, %l0
F00AA54C: d00421d8                 ld      [%l0+0x1D8], %o0
F00AA550: d0020000                 ld      [%o0], %o0
F00AA554: d2522030                 ldsh    [%o0+0x30], %o1
F00AA558: d407a048                 ld      [%fp+arg_48], %o2
F00AA55C: 113c046f                 sethi   %hi(aSendsigBadSign), %o0! "sendsig: bad signal stack pid=%d, sig=%"...
F00AA560: 7ffda83e                 call    _printf
F00AA564: 901223f8                 bset    %lo(aSendsigBadSign), %o0! "sendsig: bad signal stack pid=%d, sig=%"...
F00AA568: d407a044                 ld      [%fp+arg_44], %o2
F00AA56C: d807bfe4                 ld      [%fp+var_1C], %o4
F00AA570: d207bfdc                 ld      [%fp+var_24], %o1
F00AA574: 113c0470                 sethi   %hi(aSigsp0xXAction), %o0! "sigsp = 0x%x, action = 0x%x, upc = 0x%x"...
F00AA578: d6032004                 ld      [%o4+4], %o3
F00AA57C: 7ffda837                 call    _printf
F00AA580: 90122028                 bset    %lo(aSigsp0xXAction), %o0! "sigsp = 0x%x, action = 0x%x, upc = 0x%x"...
F00AA584: d00421d8                 ld      [%l0+0x1D8], %o0
F00AA588: c0222040                 clr     [%o0+0x40]
F00AA58C: d00421d8                 ld      [%l0+0x1D8], %o0
F00AA590: d2020000                 ld      [%o0], %o1
F00AA594: d0026020                 ld      [%o1+0x20], %o0
F00AA598: 900a3ff7                 and     %o0, -9, %o0
F00AA59C: d0226020                 st      %o0, [%o1+0x20]
F00AA5A0: d00421d8                 ld      [%l0+0x1D8], %o0
F00AA5A4: d2020000                 ld      [%o0], %o1
F00AA5A8: d0026024                 ld      [%o1+0x24], %o0
F00AA5AC: 900a3ff7                 and     %o0, -9, %o0
F00AA5B0: d0226024                 st      %o0, [%o1+0x24]
F00AA5B4: d00421d8                 ld      [%l0+0x1D8], %o0
F00AA5B8: d2020000                 ld      [%o0], %o1
F00AA5BC: d002601c                 ld      [%o1+0x1C], %o0
F00AA5C0: 900a3ff7                 and     %o0, -9, %o0
F00AA5C4: d022601c                 st      %o0, [%o1+0x1C]
F00AA5C8: 90102008                 mov     8, %o0
F00AA5CC: d20421d8                 ld      [%l0+0x1D8], %o1! char *
F00AA5D0: d027a048                 st      %o0, [%fp+arg_48]
F00AA5D4: d0024000                 ld      [%o1], %o0! unsigned int
F00AA5D8: 7ffd9be7                 call    _psignal
F00AA5DC: 92102004                 mov     4, %o1
F00AA5E0: 3080006c                 ba,a    locret_F00AA790
F00AA5E4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00AA5E8: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00AA5EC: d407bfec                 ld      [%fp+var_14], %o2
F00AA5F0: da07bfdc                 ld      [%fp+var_24], %o5
F00AA5F4: d807bfe4                 ld      [%fp+var_1C], %o4
F00AA5F8: 9007bff0                 add     %fp, var_10, %o0
F00AA5FC: d0226074                 st      %o0, [%o1+0x74]
F00AA600: d007a04c                 ld      [%fp+arg_4C], %o0
F00AA604: d4236050                 st      %o2, [%o5+0x50]
F00AA608: d0236054                 st      %o0, [%o5+0x54]
F00AA60C: d0032044                 ld      [%o4+0x44], %o0
F00AA610: d0236058                 st      %o0, [%o5+0x58]
F00AA614: d0032004                 ld      [%o4+4], %o0
F00AA618: d023605c                 st      %o0, [%o5+0x5C]
F00AA61C: d0032008                 ld      [%o4+8], %o0
F00AA620: d0236060                 st      %o0, [%o5+0x60]
F00AA624: d0030000                 ld      [%o4], %o0
F00AA628: d0236064                 st      %o0, [%o5+0x64]
F00AA62C: d0032010                 ld      [%o4+0x10], %o0
F00AA630: d0236068                 st      %o0, [%o5+0x68]
F00AA634: d003202c                 ld      [%o4+0x2C], %o0
F00AA638: d023606c                 st      %o0, [%o5+0x6C]
F00AA63C: da07bfd4                 ld      [%fp+var_2C], %o5
F00AA640: d807bfdc                 ld      [%fp+var_24], %o4
F00AA644: d0036230                 ld      [%o5+0x230], %o0
F00AA648: d0232070                 st      %o0, [%o4+0x70]
F00AA64C: d0036230                 ld      [%o5+0x230], %o0
F00AA650: a0102000                 mov     0, %l0
F00AA654: 80a40008                 cmp     %l0, %o0
F00AA658: 16800018                 bge     loc_F00AA6B8
F00AA65C: d007a048                 ld      [%fp+arg_48], %o0
F00AA660: a21020f0                 mov     0xF0, %l1
F00AA664: f207bfd4                 ld      [%fp+var_2C], %i1
F00AA668: b4102010                 mov     0x10, %i2
F00AA66C: f007bfdc                 ld      [%fp+var_24], %i0
F00AA670: da07bfd4                 ld      [%fp+var_2C], %o5
F00AA674: 94102040                 mov     0x40, %o2 ! '@'! size_t
F00AA678: d807bfdc                 ld      [%fp+var_24], %o4
F00AA67C: a0042001                 inc     %l0
F00AA680: d6066210                 ld      [%i1+0x210], %o3
F00AA684: 9003401a                 add     %o5, %i2, %o0! void *
F00AA688: 92030011                 add     %o4, %l1, %o1! void *
F00AA68C: a2046040                 inc     0x40, %l1 ! '@'
F00AA690: b406a040                 inc     0x40, %i2 ! '@'
F00AA694: 7fffa91f                 call    _bcopy
F00AA698: d6262074                 st      %o3, [%i0+0x74]
F00AA69C: da07bfd4                 ld      [%fp+var_2C], %o5
F00AA6A0: b2066004                 inc     4, %i1
F00AA6A4: d0036230                 ld      [%o5+0x230], %o0
F00AA6A8: 80a40008                 cmp     %l0, %o0
F00AA6AC: 06bffff2                 bl      loc_F00AA674
F00AA6B0: b0062004                 inc     4, %i0
F00AA6B4: d007a048                 ld      [%fp+arg_48], %o0
F00AA6B8: d807bfdc                 ld      [%fp+var_24], %o4
F00AA6BC: da07bfd4                 ld      [%fp+var_2C], %o5
F00AA6C0: d0232040                 st      %o0, [%o4+0x40]
F00AA6C4: d0036230                 ld      [%o5+0x230], %o0
F00AA6C8: 80a22000                 cmp     %o0, 0
F00AA6CC: 12800008                 bne     loc_F00AA6EC
F00AA6D0: d007a048                 ld      [%fp+arg_48], %o0
F00AA6D4: d807bfe4                 ld      [%fp+var_1C], %o4
F00AA6D8: d207bfdc                 ld      [%fp+var_24], %o1! void *
F00AA6DC: d0032044                 ld      [%o4+0x44], %o0! void *
F00AA6E0: 7fffa90c                 call    _bcopy
F00AA6E4: 94102040                 mov     0x40, %o2 ! '@'
F00AA6E8: d007a048                 ld      [%fp+arg_48], %o0
F00AA6EC: 92023ffc                 add     %o0, -4, %o1
F00AA6F0: 80a26007                 cmp     %o1, 7! switch 8 cases
F00AA6F4: 18800017                 bgu     def_F00AA708! jumptable F00AA708 default case, cases 1,2,5
F00AA6F8: 113c02a9                 sethi   %hi(jpt_F00AA708), %o0
F00AA6FC: 90122310                 bset    %lo(jpt_F00AA708), %o0
F00AA700: 932a6002                 sll     %o1, 2, %o1
F00AA704: d0024008                 ld      [%o1+%o0], %o0
F00AA708: 81c20000                 jmp     %o0! switch jump
F00AA70C: 01000000                 nop
F00AA730: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1! jumptable F00AA708 cases 0,3,4,6,7
F00AA734: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F00AA738: da07bfdc                 ld      [%fp+var_24], %o5
F00AA73C: d0022044                 ld      [%o0+0x44], %o0
F00AA740: d0236044                 st      %o0, [%o5+0x44]
F00AA744: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F00AA748: 10800004                 ba      loc_F00AA758
F00AA74C: c0222044                 clr     [%o0+0x44]
F00AA750: d807bfdc                 ld      [%fp+var_24], %o4! jumptable F00AA708 default case, cases 1,2,5
F00AA754: c0232044                 clr     [%o4+0x44]
F00AA758: da07bfdc                 ld      [%fp+var_24], %o5
F00AA75C: 90036050                 add     %o5, 0x50, %o0 ! 'P'
F00AA760: d0236048                 st      %o0, [%o5+0x48]
F00AA764: 113c04d0                 sethi   %hi(_active_threads), %o0
F00AA768: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00AA76C: d807bfd4                 ld      [%fp+var_2C], %o4
F00AA770: c0222074                 clr     [%o0+0x74]
F00AA774: c0232230                 clr     [%o4+0x230]
F00AA778: d807bfe4                 ld      [%fp+var_1C], %o4
F00AA77C: d007a044                 ld      [%fp+arg_44], %o0
F00AA780: da232044                 st      %o5, [%o4+0x44]
F00AA784: d0232004                 st      %o0, [%o4+4]
F00AA788: 90022004                 inc     4, %o0
F00AA78C: d0232008                 st      %o0, [%o4+8]
F00AA790: 81c7e008                 ret
F00AA794: 81e80000                 restore
