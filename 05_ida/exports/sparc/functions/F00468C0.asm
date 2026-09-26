F00468C0: 9de3bf98                 save    %sp, -0x68, %sp
F00468C4: d2066008                 ld      [%i1+8], %o1
F00468C8: 80a26000                 cmp     %o1, 0
F00468CC: 02800005                 be      loc_F00468E0
F00468D0: a8102000                 mov     0, %l4
F00468D4: 113c0438                 sethi   %hi(aFifoRdwrNonZer), %o0! "fifo_rdwr: non-zero offset: %d\n"
F00468D8: 7fff3760                 call    _printf
F00468DC: 90122210                 bset    %lo(aFifoRdwrNonZer), %o0! "fifo_rdwr: non-zero offset: %d\n"
F00468E0: 10800006                 ba      loc_F00468F8
F00468E4: f0062030                 ld      [%i0+0x30], %i0
F00468E8: d0362040                 sth     %o0, [%i0+0x40]
F00468EC: 90100018                 mov     %i0, %o0! unsigned int
F00468F0: 7fff2f62                 call    _sleep
F00468F4: 9210200a                 mov     0xA, %o1
F00468F8: d0162040                 lduh    [%i0+0x40], %o0
F00468FC: 808a2001                 btst    1, %o0
F0046900: 12bffffa                 bne     loc_F00468E8
F0046904: 90122010                 bset    0x10, %o0
F0046908: d0162040                 lduh    [%i0+0x40], %o0
F004690C: 80a6a001                 cmp     %i2, 1
F0046910: 90122001                 bset    1, %o0
F0046914: 128000c6                 bne     loc_F0046C2C
F0046918: d0362040                 sth     %o0, [%i0+0x40]
F004691C: d2066014                 ld      [%i1+0x14], %o1
F0046920: 113c043c                 sethi   %hi(dword_F010F398), %o0
F0046924: d0022398                 ld      [%o0+%lo(dword_F010F398)], %o0
F0046928: 80a24008                 cmp     %o1, %o0
F004692C: 08800004                 bleu    loc_F004693C
F0046930: a4100009                 mov     %o1, %l2
F0046934: 10800165                 ba      loc_F0046EC8
F0046938: a8102016                 mov     0x16, %l4
F004693C: 80a4a000                 cmp     %l2, 0
F0046940: 22800163                 be,a    loc_F0046ECC
F0046944: d2162040                 lduh    [%i0+0x40], %o1
F0046948: 273c043c                 sethi   -0xFEF1000, %l3
F004694C: d0562082                 ldsh    [%i0+0x82], %o0
F0046950: 80a22000                 cmp     %o0, 0
F0046954: 028000ae                 be      loc_F0046C0C
F0046958: 113c043c                 sethi   %hi(_fifoinfo), %o0
F004695C: d406207c                 ld      [%i0+0x7C], %o2
F0046960: d2022394                 ld      [%o0+%lo(_fifoinfo)], %o1
F0046964: 9004800a                 add     %l2, %o2, %o0
F0046968: 80a20009                 cmp     %o0, %o1
F004696C: 28800034                 bleu,a  loc_F0046A3C
F0046970: d4562084                 ldsh    [%i0+0x84], %o2
F0046974: d0166010                 lduh    [%i1+0x10], %o0
F0046978: 808a2004                 btst    4, %o0
F004697C: 02800008                 be      loc_F004699C
F0046980: 80a48009                 cmp     %l2, %o1
F0046984: 088000be                 bleu    loc_F0046C7C
F0046988: 80a28009                 cmp     %o2, %o1
F004698C: 0a800028                 bcs     loc_F0046A2C
F0046990: 113c043c                 sethi   -0xFEF1000, %o0
F0046994: 108000bb                 ba      loc_F0046C80
F0046998: 113c04cf                 sethi   -0xFECC400, %o0
F004699C: 08800004                 bleu    loc_F00469AC
F00469A0: 80a28009                 cmp     %o2, %o1
F00469A4: 0a800022                 bcs     loc_F0046A2C
F00469A8: 113c043c                 sethi   -0xFEF1000, %o0
F00469AC: d0162088                 lduh    [%i0+0x88], %o0
F00469B0: d2162040                 lduh    [%i0+0x40], %o1
F00469B4: 90122002                 bset    2, %o0
F00469B8: d0362088                 sth     %o0, [%i0+0x88]
F00469BC: 1100003f901223fe         set     0xFFFE, %o0
F00469C4: 920a4008                 and     %o1, %o0, %o1
F00469C8: 808a6010                 btst    0x10, %o1
F00469CC: 02800008                 be      loc_F00469EC
F00469D0: d2362040                 sth     %o1, [%i0+0x40]
F00469D4: 1100003f901223ef         set     0xFFEF, %o0
F00469DC: 900a4008                 and     %o1, %o0, %o0
F00469E0: d0362040                 sth     %o0, [%i0+0x40]
F00469E4: 7fff3101                 call    _wakeup
F00469E8: 90100018                 mov     %i0, %o0
F00469EC: 90062080                 add     %i0, 0x80, %o0
F00469F0: 10800005                 ba      loc_F0046A04
F00469F4: 9210201a                 mov     0x1A, %o1
F00469F8: d0362040                 sth     %o0, [%i0+0x40]
F00469FC: 90100018                 mov     %i0, %o0! unsigned int
F0046A00: 9210200a                 mov     0xA, %o1
F0046A04: 7fff2f1d                 call    _sleep
F0046A08: 01000000                 nop
F0046A0C: d0162040                 lduh    [%i0+0x40], %o0
F0046A10: 808a2001                 btst    1, %o0
F0046A14: 12bffff9                 bne     loc_F00469F8
F0046A18: 90122010                 bset    0x10, %o0
F0046A1C: d0162040                 lduh    [%i0+0x40], %o0
F0046A20: 90122001                 bset    1, %o0
F0046A24: 10800074                 ba      loc_F0046BF4
F0046A28: d0362040                 sth     %o0, [%i0+0x40]
F0046A2C: d2022394                 ld      [%o0+0x394], %o1
F0046A30: d006207c                 ld      [%i0+0x7C], %o0
F0046A34: a4224008                 sub     %o1, %o0, %l2
F0046A38: d4562084                 ldsh    [%i0+0x84], %o2
F0046A3C: d6562086                 ldsh    [%i0+0x86], %o3
F0046A40: d206207c                 ld      [%i0+0x7C], %o1
F0046A44: 9022800b                 sub     %o2, %o3, %o0
F0046A48: 80a20009                 cmp     %o0, %o1
F0046A4C: 02800004                 be      loc_F0046A5C
F0046A50: 113c0438                 sethi   %hi(aFifoWritePtrMi), %o0! "fifo_write: ptr mismatch...size:%d  wpt"...
F0046A54: 7fff3701                 call    _printf
F0046A58: 90122230                 bset    %lo(aFifoWritePtrMi), %o0! "fifo_write: ptr mismatch...size:%d  wpt"...
F0046A5C: d2562086                 ldsh    [%i0+0x86], %o1
F0046A60: d004e39c                 ld      [%l3+0x39C], %o0
F0046A64: 80a24008                 cmp     %o1, %o0
F0046A68: 04800004                 ble     loc_F0046A78
F0046A6C: 113c0438                 sethi   %hi(aFifoWriteRptrT), %o0! "fifo_write: rptr too big...rptr:%d\n"
F0046A70: 7fff36fa                 call    _printf
F0046A74: 90122268                 bset    %lo(aFifoWriteRptrT), %o0! "fifo_write: rptr too big...rptr:%d\n"
F0046A78: e256208a                 ldsh    [%i0+0x8A], %l1
F0046A7C: d204e39c                 ld      [%l3+0x39C], %o1
F0046A80: 7ffefea0                 call    _umul
F0046A84: 90100011                 mov     %l1, %o0
F0046A88: e0562084                 ldsh    [%i0+0x84], %l0
F0046A8C: 80a40008                 cmp     %l0, %o0
F0046A90: 24800008                 ble,a   loc_F0046AB0
F0046A94: d056208a                 ldsh    [%i0+0x8A], %o0
F0046A98: 113c043890122290         set     aFifoWriteWptrT, %o0! "fifo_write: wptr too big...wptr:%d  nbu"...
F0046AA0: 92100010                 mov     %l0, %o1
F0046AA4: 7fff36ed                 call    _printf
F0046AA8: 94100011                 mov     %l1, %o2
F0046AAC: d056208a                 ldsh    [%i0+0x8A], %o0
F0046AB0: 7ffefe94                 call    _umul
F0046AB4: d204e39c                 ld      [%l3+0x39C], %o1
F0046AB8: d2562084                 ldsh    [%i0+0x84], %o1
F0046ABC: 90220009                 sub     %o0, %o1, %o0
F0046AC0: 80a20012                 cmp     %o0, %l2
F0046AC4: 3a800011                 bcc,a   loc_F0046B08
F0046AC8: e2562084                 ldsh    [%i0+0x84], %l1
F0046ACC: 4000018e                 call    sub_F0047104
F0046AD0: 90100018                 mov     %i0, %o0
F0046AD4: a0920000                 orcc    %o0, %g0, %l0
F0046AD8: 22800048                 be,a    loc_F0046BF8
F0046ADC: e4066014                 ld      [%i1+0x14], %l2
F0046AE0: c0240000                 clr     [%l0]
F0046AE4: d0062068                 ld      [%i0+0x68], %o0
F0046AE8: 80a22000                 cmp     %o0, 0
F0046AEC: 32800004                 bne,a   loc_F0046AFC
F0046AF0: d006206c                 ld      [%i0+0x6C], %o0
F0046AF4: 10800003                 ba      loc_F0046B00
F0046AF8: e0262068                 st      %l0, [%i0+0x68]
F0046AFC: e0220000                 st      %l0, [%o0]
F0046B00: 10bfffeb                 ba      loc_F0046AAC
F0046B04: e026206c                 st      %l0, [%i0+0x6C]
F0046B08: d004e39c                 ld      [%l3+0x39C], %o0
F0046B0C: 80a44008                 cmp     %l1, %o0
F0046B10: 06800006                 bl      loc_F0046B28
F0046B14: e0062068                 ld      [%i0+0x68], %l0
F0046B18: a2244008                 sub     %l1, %o0, %l1
F0046B1C: 80a44008                 cmp     %l1, %o0
F0046B20: 16bffffe                 bge     loc_F0046B18
F0046B24: e0040000                 ld      [%l0], %l0
F0046B28: 80a4a000                 cmp     %l2, 0
F0046B2C: 0280001b                 be      loc_F0046B98
F0046B30: 90100018                 mov     %i0, %o0
F0046B34: d004e39c                 ld      [%l3+0x39C], %o0
F0046B38: b4220011                 sub     %o0, %l1, %i2
F0046B3C: 80a4801a                 cmp     %l2, %i2
F0046B40: 08800003                 bleu    loc_F0046B4C
F0046B44: 92100012                 mov     %l2, %o1
F0046B48: 9210001a                 mov     %i2, %o1
F0046B4C: b4100009                 mov     %o1, %i2
F0046B50: 90040011                 add     %l0, %l1, %o0
F0046B54: 94102001                 mov     1, %o2
F0046B58: 7fff2df0                 call    _uiomove
F0046B5C: 96100019                 mov     %i1, %o3
F0046B60: a8920000                 orcc    %o0, %g0, %l4
F0046B64: 328000da                 bne,a   loc_F0046ECC
F0046B68: d2162040                 lduh    [%i0+0x40], %o1
F0046B6C: d206207c                 ld      [%i0+0x7C], %o1
F0046B70: a2102000                 mov     0, %l1
F0046B74: d0162084                 lduh    [%i0+0x84], %o0
F0046B78: 9202401a                 add     %o1, %i2, %o1
F0046B7C: d226207c                 st      %o1, [%i0+0x7C]
F0046B80: 9002001a                 add     %o0, %i2, %o0
F0046B84: d0362084                 sth     %o0, [%i0+0x84]
F0046B88: a4a4801a                 subcc   %l2, %i2, %l2
F0046B8C: 12bfffea                 bne     loc_F0046B34
F0046B90: e0040000                 ld      [%l0], %l0
F0046B94: 90100018                 mov     %i0, %o0
F0046B98: 40000388                 call    _smark
F0046B9C: 92102042                 mov     0x42, %o1 ! 'B'
F0046BA0: d0162088                 lduh    [%i0+0x88], %o0
F0046BA4: 808a2001                 btst    1, %o0
F0046BA8: 02800005                 be      loc_F0046BBC
F0046BAC: 900a3ffe                 and     %o0, -2, %o0
F0046BB0: d0362088                 sth     %o0, [%i0+0x88]
F0046BB4: 7fff308d                 call    _wakeup
F0046BB8: 90062082                 add     %i0, 0x82, %o0
F0046BBC: d0062070                 ld      [%i0+0x70], %o0
F0046BC0: 80a22000                 cmp     %o0, 0
F0046BC4: 0280000e                 be      loc_F0046BFC
F0046BC8: 80a4a000                 cmp     %l2, 0
F0046BCC: d2162088                 lduh    [%i0+0x88], %o1
F0046BD0: 7fff3d51                 call    _selwakeup
F0046BD4: 920a6004                 and     %o1, 4, %o1
F0046BD8: 4000b5f5                 call    _thread_deallocate
F0046BDC: d0062070                 ld      [%i0+0x70], %o0
F0046BE0: d0162088                 lduh    [%i0+0x88], %o0
F0046BE4: c0262070                 clr     [%i0+0x70]
F0046BE8: 900a3ffb                 and     %o0, -5, %o0
F0046BEC: 10800003                 ba      loc_F0046BF8
F0046BF0: d0362088                 sth     %o0, [%i0+0x88]
F0046BF4: e4066014                 ld      [%i1+0x14], %l2
F0046BF8: 80a4a000                 cmp     %l2, 0
F0046BFC: 32bfff55                 bne,a   loc_F0046950
F0046C00: d0562082                 ldsh    [%i0+0x82], %o0
F0046C04: 108000b2                 ba      loc_F0046ECC
F0046C08: d2162040                 lduh    [%i0+0x40], %o1
F0046C0C: 113c04cf                 sethi   %hi(_active_u), %o0
F0046C10: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0046C14: 9210200d                 mov     0xD, %o1! char *
F0046C18: d0020000                 ld      [%o0], %o0! unsigned int
F0046C1C: 7fff2a56                 call    _psignal
F0046C20: a8102020                 mov     0x20, %l4 ! ' '
F0046C24: 108000aa                 ba      loc_F0046ECC
F0046C28: d2162040                 lduh    [%i0+0x40], %o1
F0046C2C: e4066014                 ld      [%i1+0x14], %l2
F0046C30: 80a4a000                 cmp     %l2, 0
F0046C34: 228000a6                 be,a    loc_F0046ECC
F0046C38: d2162040                 lduh    [%i0+0x40], %o1
F0046C3C: f406207c                 ld      [%i0+0x7C], %i2
F0046C40: 80a6a000                 cmp     %i2, 0
F0046C44: 32800036                 bne,a   loc_F0046D1C
F0046C48: d4562084                 ldsh    [%i0+0x84], %o2
F0046C4C: 1100003fa21223fe         set     0xFFFE, %l1
F0046C54: 1100003fa01223ef         set     0xFFEF, %l0
F0046C5C: d0562080                 ldsh    [%i0+0x80], %o0
F0046C60: 80a22000                 cmp     %o0, 0
F0046C64: 2280009a                 be,a    loc_F0046ECC
F0046C68: d2162040                 lduh    [%i0+0x40], %o1
F0046C6C: d0166010                 lduh    [%i1+0x10], %o0
F0046C70: 808a2004                 btst    4, %o0
F0046C74: 2280000c                 be,a    loc_F0046CA4
F0046C78: d0162088                 lduh    [%i0+0x88], %o0
F0046C7C: 113c04cf                 sethi   -0xFECC400, %o0
F0046C80: d00221d8                 ld      [%o0+0x1D8], %o0
F0046C84: d0020000                 ld      [%o0], %o0
F0046C88: d2022014                 ld      [%o0+0x14], %o1
F0046C8C: 11000010                 sethi   0x4000, %o0
F0046C90: 808a4008                 btst    %o0, %o1
F0046C94: 0280008d                 be      loc_F0046EC8
F0046C98: a8102023                 mov     0x23, %l4 ! '#'
F0046C9C: 1080008b                 ba      loc_F0046EC8
F0046CA0: a810200b                 mov     0xB, %l4
F0046CA4: d2162040                 lduh    [%i0+0x40], %o1
F0046CA8: 90122001                 bset    1, %o0
F0046CAC: d0362088                 sth     %o0, [%i0+0x88]
F0046CB0: 900a4011                 and     %o1, %l1, %o0
F0046CB4: 808a2010                 btst    0x10, %o0
F0046CB8: 02800006                 be      loc_F0046CD0
F0046CBC: d0362040                 sth     %o0, [%i0+0x40]
F0046CC0: 900a0010                 and     %o0, %l0, %o0
F0046CC4: d0362040                 sth     %o0, [%i0+0x40]
F0046CC8: 7fff3048                 call    _wakeup
F0046CCC: 90100018                 mov     %i0, %o0
F0046CD0: 90062082                 add     %i0, 0x82, %o0
F0046CD4: 10800005                 ba      loc_F0046CE8
F0046CD8: 9210201a                 mov     0x1A, %o1
F0046CDC: d0362040                 sth     %o0, [%i0+0x40]
F0046CE0: 90100018                 mov     %i0, %o0! unsigned int
F0046CE4: 9210200a                 mov     0xA, %o1
F0046CE8: 7fff2e64                 call    _sleep
F0046CEC: 01000000                 nop
F0046CF0: d0162040                 lduh    [%i0+0x40], %o0
F0046CF4: 808a2001                 btst    1, %o0
F0046CF8: 12bffff9                 bne     loc_F0046CDC
F0046CFC: 90122010                 bset    0x10, %o0
F0046D00: d0162040                 lduh    [%i0+0x40], %o0
F0046D04: f406207c                 ld      [%i0+0x7C], %i2
F0046D08: 90122001                 bset    1, %o0
F0046D0C: 80a6a000                 cmp     %i2, 0
F0046D10: 02bfffd3                 be      loc_F0046C5C
F0046D14: d0362040                 sth     %o0, [%i0+0x40]
F0046D18: d4562084                 ldsh    [%i0+0x84], %o2
F0046D1C: d6562086                 ldsh    [%i0+0x86], %o3
F0046D20: d206207c                 ld      [%i0+0x7C], %o1
F0046D24: 9022800b                 sub     %o2, %o3, %o0
F0046D28: 80a20009                 cmp     %o0, %o1
F0046D2C: 02800004                 be      loc_F0046D3C
F0046D30: 113c0438                 sethi   %hi(aFifoReadPtrMis), %o0! "fifo_read: ptr mismatch...size:%d  wptr"...
F0046D34: 7fff3649                 call    _printf
F0046D38: 901222c0                 bset    %lo(aFifoReadPtrMis), %o0! "fifo_read: ptr mismatch...size:%d  wptr"...
F0046D3C: d2562086                 ldsh    [%i0+0x86], %o1
F0046D40: 273c043c                 sethi   %hi(dword_F010F39C), %l3
F0046D44: d004e39c                 ld      [%l3+%lo(dword_F010F39C)], %o0
F0046D48: 80a24008                 cmp     %o1, %o0
F0046D4C: 04800004                 ble     loc_F0046D5C
F0046D50: 113c0438                 sethi   %hi(aFifoReadRptrTo), %o0! "fifo_read: rptr too big...rptr:%d\n"
F0046D54: 7fff3641                 call    _printf
F0046D58: 901222f8                 bset    %lo(aFifoReadRptrTo), %o0! "fifo_read: rptr too big...rptr:%d\n"
F0046D5C: e256208a                 ldsh    [%i0+0x8A], %l1
F0046D60: d204e39c                 ld      [%l3+0x39C], %o1
F0046D64: 7ffefde7                 call    _umul
F0046D68: 90100011                 mov     %l1, %o0
F0046D6C: e0562084                 ldsh    [%i0+0x84], %l0
F0046D70: 80a40008                 cmp     %l0, %o0
F0046D74: 04800006                 ble     loc_F0046D8C
F0046D78: 113c0438                 sethi   %hi(aFifoReadWptrTo), %o0! "fifo_read: wptr too big...wptr:%d  nbuf"...
F0046D7C: 90122320                 bset    %lo(aFifoReadWptrTo), %o0! "fifo_read: wptr too big...wptr:%d  nbuf"...
F0046D80: 92100010                 mov     %l0, %o1
F0046D84: 7fff3635                 call    _printf
F0046D88: 94100011                 mov     %l1, %o2
F0046D8C: e2562086                 ldsh    [%i0+0x86], %l1
F0046D90: 80a4801a                 cmp     %l2, %i2
F0046D94: 08800003                 bleu    loc_F0046DA0
F0046D98: e0062068                 ld      [%i0+0x68], %l0
F0046D9C: a410001a                 mov     %i2, %l2
F0046DA0: 80a4a000                 cmp     %l2, 0
F0046DA4: 02800033                 be      loc_F0046E70
F0046DA8: 90100018                 mov     %i0, %o0
F0046DAC: 2b3c0438                 sethi   -0xFEF2000, %l5
F0046DB0: d004e39c                 ld      [%l3+0x39C], %o0
F0046DB4: b4220011                 sub     %o0, %l1, %i2
F0046DB8: 80a4801a                 cmp     %l2, %i2
F0046DBC: 08800003                 bleu    loc_F0046DC8
F0046DC0: 92100012                 mov     %l2, %o1
F0046DC4: 9210001a                 mov     %i2, %o1
F0046DC8: b4100009                 mov     %o1, %i2
F0046DCC: 90040011                 add     %l0, %l1, %o0
F0046DD0: 94102000                 mov     0, %o2
F0046DD4: 7fff2d51                 call    _uiomove
F0046DD8: 96100019                 mov     %i1, %o3
F0046DDC: a8920000                 orcc    %o0, %g0, %l4
F0046DE0: 3280003b                 bne,a   loc_F0046ECC
F0046DE4: d2162040                 lduh    [%i0+0x40], %o1
F0046DE8: a424801a                 sub     %l2, %i2, %l2
F0046DEC: d006207c                 ld      [%i0+0x7C], %o0
F0046DF0: d2162086                 lduh    [%i0+0x86], %o1
F0046DF4: 9022001a                 sub     %o0, %i2, %o0
F0046DF8: d026207c                 st      %o0, [%i0+0x7C]
F0046DFC: 9202401a                 add     %o1, %i2, %o1
F0046E00: d2362086                 sth     %o1, [%i0+0x86]
F0046E04: 932a6010                 sll     %o1, 16, %o1
F0046E08: d004e39c                 ld      [%l3+0x39C], %o0! char *
F0046E0C: 933a6010                 sra     %o1, 16, %o1
F0046E10: 80a24008                 cmp     %o1, %o0
F0046E14: 04800004                 ble     loc_F0046E24
F0046E18: a2102000                 mov     0, %l1
F0046E1C: 7fff360f                 call    _printf
F0046E20: 90156350                 or      %l5, 0x350, %o0
F0046E24: d2562086                 ldsh    [%i0+0x86], %o1
F0046E28: d004e39c                 ld      [%l3+0x39C], %o0
F0046E2C: 80a24008                 cmp     %o1, %o0
F0046E30: 1280000d                 bne     loc_F0046E64
F0046E34: 80a4a000                 cmp     %l2, 0
F0046E38: c0362086                 clrh    [%i0+0x86]
F0046E3C: 90100010                 mov     %l0, %o0
F0046E40: 40000106                 call    sub_F0047258
F0046E44: 92100018                 mov     %i0, %o1
F0046E48: a0100008                 mov     %o0, %l0
F0046E4C: e0262068                 st      %l0, [%i0+0x68]
F0046E50: d204e39c                 ld      [%l3+0x39C], %o1
F0046E54: d0162084                 lduh    [%i0+0x84], %o0
F0046E58: 90220009                 sub     %o0, %o1, %o0
F0046E5C: d0362084                 sth     %o0, [%i0+0x84]
F0046E60: 80a4a000                 cmp     %l2, 0
F0046E64: 12bfffd4                 bne     loc_F0046DB4
F0046E68: d004e39c                 ld      [%l3+0x39C], %o0
F0046E6C: 90100018                 mov     %i0, %o0
F0046E70: 400002d2                 call    _smark
F0046E74: 92102004                 mov     4, %o1
F0046E78: d0162088                 lduh    [%i0+0x88], %o0
F0046E7C: 808a2002                 btst    2, %o0
F0046E80: 02800005                 be      loc_F0046E94
F0046E84: 900a3ffd                 and     %o0, -3, %o0
F0046E88: d0362088                 sth     %o0, [%i0+0x88]
F0046E8C: 7fff2fd7                 call    _wakeup
F0046E90: 90062080                 add     %i0, 0x80, %o0
F0046E94: d0062074                 ld      [%i0+0x74], %o0
F0046E98: 80a22000                 cmp     %o0, 0
F0046E9C: 2280000c                 be,a    loc_F0046ECC
F0046EA0: d2162040                 lduh    [%i0+0x40], %o1
F0046EA4: d2162088                 lduh    [%i0+0x88], %o1
F0046EA8: 7fff3c9b                 call    _selwakeup
F0046EAC: 920a6008                 and     %o1, 8, %o1
F0046EB0: 4000b53f                 call    _thread_deallocate
F0046EB4: d0062074                 ld      [%i0+0x74], %o0
F0046EB8: d0162088                 lduh    [%i0+0x88], %o0
F0046EBC: c0262074                 clr     [%i0+0x74]
F0046EC0: 900a3ff7                 and     %o0, -9, %o0
F0046EC4: d0362088                 sth     %o0, [%i0+0x88]
F0046EC8: d2162040                 lduh    [%i0+0x40], %o1
F0046ECC: 1100003f901223fe         set     0xFFFE, %o0
F0046ED4: 920a4008                 and     %o1, %o0, %o1
F0046ED8: 808a6010                 btst    0x10, %o1
F0046EDC: 02800008                 be      loc_F0046EFC
F0046EE0: d2362040                 sth     %o1, [%i0+0x40]
F0046EE4: 1100003f901223ef         set     0xFFEF, %o0
F0046EEC: 900a4008                 and     %o1, %o0, %o0
F0046EF0: d0362040                 sth     %o0, [%i0+0x40]
F0046EF4: 7fff2fbd                 call    _wakeup
F0046EF8: 90100018                 mov     %i0, %o0
F0046EFC: c0266008                 clr     [%i1+8]
F0046F00: 81c7e008                 ret
F0046F04: 91e80014                 restore %g0, %l4, %o0
