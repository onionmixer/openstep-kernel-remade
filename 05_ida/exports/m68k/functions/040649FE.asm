040649FE: 4856                     pea     (a6)
04064A00: 2c4f                     movea.l sp,a6
04064A02: 48e73020                 movem.l d2-d3/a2,-(sp)
04064A06: 246e0008                 movea.l 8(a6),a2
04064A0A: 226e000c                 movea.l $C(a6),a1
04064A0E: 41e9fffe                 lea     -2(a1),a0
04064A12: 7606                     moveq   #6,d3
04064A14: b688                     cmp.l   a0,d3
04064A16: 6412                     bcc.s   loc_4064A2A
04064A18: 2f09                     move.l  a1,-(sp)
04064A1A: 4879040a9d2c             pea     (aAdbKeyboardEve).l; "adb_keyboard: event had reg0 length %d"...
04064A20: 61fffffa6936             bsr.l   _printf
04064A26: 600005dc                 bra.w   loc_4065004
04064A2A: 1412                     move.b  (a2),d2
04064A2C: 1002                     move.b  d2,d0
04064A2E: 0200007f                 andi.b  #$7F,d0
04064A32: 0c00007f                 cmpi.b  #$7F,d0
04064A36: 670005b8                 beq.w   loc_4064FF0
04064A3A: 7201                     moveq   #1,d1
04064A3C: c2b9040b4f3e             and.l   (dword_40B4F3E).l,d1
04064A42: 41f9040b4f36             lea     (unk_40B4F36).l,a0
04064A48: 1002                     move.b  d2,d0
04064A4A: 0200007f                 andi.b  #$7F,d0
04064A4E: eff000471a00             bfins   d0,(a0,d1.l*2){1:7}
04064A54: 7201                     moveq   #1,d1
04064A56: c2b9040b4f3e             and.l   (dword_40B4F3E).l,d1
04064A5C: d281                     add.l   d1,d1
04064A5E: 1412                     move.b  (a2),d2
04064A60: 02020080                 andi.b  #$80,d2
04064A64: 10301800                 move.b  (a0,d1.l),d0
04064A68: 0200007f                 andi.b  #$7F,d0
04064A6C: 8002                     or.b    d2,d0
04064A6E: 11801800                 move.b  d0,(a0,d1.l)
04064A72: 52b9040b4f3e             addq.l  #1,(dword_40B4F3E).l
04064A78: 142a0001                 move.b  1(a2),d2
04064A7C: 1002                     move.b  d2,d0
04064A7E: 0200007f                 andi.b  #$7F,d0
04064A82: 0c00007f                 cmpi.b  #$7F,d0
04064A86: 673a                     beq.s   loc_4064AC2
04064A88: 7201                     moveq   #1,d1
04064A8A: c2b9040b4f3e             and.l   (dword_40B4F3E).l,d1
04064A90: 1002                     move.b  d2,d0
04064A92: 0200007f                 andi.b  #$7F,d0
04064A96: eff000471a00             bfins   d0,(a0,d1.l*2){1:7}
04064A9C: 7201                     moveq   #1,d1
04064A9E: c2b9040b4f3e             and.l   (dword_40B4F3E).l,d1
04064AA4: d281                     add.l   d1,d1
04064AA6: 142a0001                 move.b  1(a2),d2
04064AAA: 02020080                 andi.b  #$80,d2
04064AAE: 10301800                 move.b  (a0,d1.l),d0
04064AB2: 0200007f                 andi.b  #$7F,d0
04064AB6: 8002                     or.b    d2,d0
04064AB8: 11801800                 move.b  d0,(a0,d1.l)
04064ABC: 52b9040b4f3e             addq.l  #1,(dword_40B4F3E).l
04064AC2: 2639040b4f3a             move.l  (dword_40B4F3A).l,d3
04064AC8: b6b9040b4f3e             cmp.l   (dword_40B4F3E).l,d3
04064ACE: 67000534                 beq.w   loc_4065004
04064AD2: 7001                     moveq   #1,d0
04064AD4: c0b9040b4f3a             and.l   (dword_40B4F3A).l,d0
04064ADA: 41f9040b4f36             lea     (unk_40B4F36).l,a0
04064AE0: 34300a00                 move.w  (a0,d0.l*2),d2
04064AE4: 52b9040b4f3a             addq.l  #1,(dword_40B4F3A).l
04064AEA: e9c21401                 bfextu  d2{16:1},d1
04064AEE: ef01                     asl.b   #7,d1
04064AF0: 1039040b4f4d             move.b  (byte_40B4F4D).l,d0
04064AF6: 0200007f                 andi.b  #$7F,d0
04064AFA: 8001                     or.b    d1,d0
04064AFC: 13c0040b4f4d             move.b  d0,(byte_40B4F4D).l
04064B02: e9c21447                 bfextu  d2{17:7},d1
04064B06: 41f9040ad0f2             lea     (unk_40AD0F2).l,a0
04064B0C: 12301800                 move.b  (a0,d1.l),d1
04064B10: 0201007f                 andi.b  #$7F,d1
04064B14: 0200ff80                 andi.b  #$80,d0
04064B18: 8001                     or.b    d1,d0
04064B1A: 13c0040b4f4d             move.b  d0,(byte_40B4F4D).l
04064B20: e8c00647                 bftst   d0{25:7}
04064B24: 670a                     beq.s   loc_4064B30
04064B26: 00390080040b4f4c         ori.b   #$80,(byte_40B4F4C).l
04064B2E: 6008                     bra.s   loc_4064B38
04064B30: 0239007f040b4f4c         andi.b  #$7F,(byte_40B4F4C).l
04064B38: e9c20408                 bfextu  d2{16:8},d0
04064B3C: 4a00                     tst.b   d0
04064B3E: 6c000200                 bge.w   loc_4064D40
04064B42: e9c20447                 bfextu  d2{17:7},d0
04064B46: 76ca                     moveq   #$FFFFFFCA,d3
04064B48: d083                     add.l   d3,d0
04064B4A: 7647                     moveq   #$47,d3 ; 'G'
04064B4C: b680                     cmp.l   d0,d3
04064B4E: 650003da                 bcs.w   loc_4064F2A
04064B52: 207c04064b5e             movea.l #$4064B5E,a0
04064B58: 20700c00                 movea.l (a0,d0.l*4),a0
04064B5C: 4ed0                     jmp     (a0)
04064B5E: 04064c7e                 subi.b  #$7E,d6 ; '~'
04064B62: 04064cb2                 subi.b  #$B2,d6
04064B66: 04064cc6                 subi.b  #$C6,d6
04064B6A: 04064d20                 subi.b  #$20,d6 ; ' '
04064B6E: 04064cf8                 subi.b  #$F8,d6
04064B72: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B76: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B7A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B7E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B82: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B86: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B8A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B8E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B92: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B96: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B9A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064B9E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BA2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BA6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BAA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BAE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BB2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BB6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BBA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BBE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BC2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BC6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BCA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BCE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BD2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BD6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BDA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BDE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BE2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BE6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BEA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BEE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BF2: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BF6: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BFA: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064BFE: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C02: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C06: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C0A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C0E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C12: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C16: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C1A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C1E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C22: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C26: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C2A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C2E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C32: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C36: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C3A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C3E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C42: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C46: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C4A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C4E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C52: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C56: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C5A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C5E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C62: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C66: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C6A: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C6E: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064C72: 04064cda                 subi.b  #$DA,d6
04064C76: 04064d0c                 subi.b  #$C,d6
04064C7A: 04064c98                 subi.b  #$98,d6
04064C7E: 1239040b4f46             move.b  (byte_40B4F46).l,d1
04064C84: 1601                     move.b  d1,d3
04064C86: 0203007f                 andi.b  #$7F,d3
04064C8A: 13c3040b4f46             move.b  d3,(byte_40B4F46).l
04064C90: e9c11641                 bfextu  d1{25:1},d1
04064C94: 6000020a                 bra.w   loc_4064EA0
04064C98: 1039040b4f46             move.b  (byte_40B4F46).l,d0
04064C9E: 1600                     move.b  d0,d3
04064CA0: 020300bf                 andi.b  #$BF,d3
04064CA4: 13c3040b4f46             move.b  d3,(byte_40B4F46).l
04064CAA: 4a00                     tst.b   d0
04064CAC: 5dc1                     slt     d1
04064CAE: 600001ee                 bra.w   loc_4064E9E
04064CB2: 023900fd040b4f46         andi.b  #$FD,(byte_40B4F46).l
04064CBA: 023900e7040b4f4c         andi.b  #$E7,(byte_40B4F4C).l
04064CC2: 60000266                 bra.w   loc_4064F2A
04064CC6: 023900f7040b4f46         andi.b  #$F7,(byte_40B4F46).l
04064CCE: 023900fd040b4f4c         andi.b  #$FD,(byte_40B4F4C).l
04064CD6: 60000252                 bra.w   loc_4064F2A
04064CDA: 023900fb040b4f46         andi.b  #$FB,(byte_40B4F46).l
04064CE2: 4a39040b4f47             tst.b   (byte_40B4F47).l
04064CE8: 6d000240                 blt.w   loc_4064F2A
04064CEC: 023900fb040b4f4c         andi.b  #$FB,(byte_40B4F4C).l
04064CF4: 60000234                 bra.w   loc_4064F2A
04064CF8: 023900df040b4f4c         andi.b  #$DF,(byte_40B4F4C).l
04064D00: 023900df040b4f46         andi.b  #$DF,(byte_40B4F46).l
04064D08: 60000220                 bra.w   loc_4064F2A
04064D0C: 023900bf040b4f4c         andi.b  #$BF,(byte_40B4F4C).l
04064D14: 023900ef040b4f46         andi.b  #$EF,(byte_40B4F46).l
04064D1C: 6000020c                 bra.w   loc_4064F2A
04064D20: 0239007f040b4f47         andi.b  #$7F,(byte_40B4F47).l
04064D28: 08390002040b4f46         btst    #2,(byte_40B4F46).l
04064D30: 6608                     bne.s   loc_4064D3A
04064D32: 023900fb040b4f4c         andi.b  #$FB,(byte_40B4F4C).l
04064D3A: 42a7                     clr.l   -(sp)
04064D3C: 600001e4                 bra.w   loc_4064F22
04064D40: e9c20447                 bfextu  d2{17:7},d0
04064D44: 76ca                     moveq   #$FFFFFFCA,d3
04064D46: d083                     add.l   d3,d0
04064D48: 7647                     moveq   #$47,d3 ; 'G'
04064D4A: b680                     cmp.l   d0,d3
04064D4C: 650001dc                 bcs.w   loc_4064F2A
04064D50: 207c04064d5c             movea.l #$4064D5C,a0
04064D56: 20700c00                 movea.l (a0,d0.l*4),a0
04064D5A: 4ed0                     jmp     (a0)
04064D5C: 04064e7c                 subi.b  #$7C,d6 ; '|'
04064D60: 04064eb4                 subi.b  #$B4,d6
04064D64: 04064ec6                 subi.b  #$C6,d6
04064D68: 04064f0e                 subi.b  #$E,d6
04064D6C: 04064eea                 subi.b  #$EA,d6
04064D70: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D74: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D78: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D7C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D80: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D84: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D88: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D8C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D90: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D94: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D98: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064D9C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DA0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DA4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DA8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DAC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DB0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DB4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DB8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DBC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DC0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DC4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DC8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DCC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DD0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DD4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DD8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DDC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DE0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DE4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DE8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DEC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DF0: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DF4: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DF8: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064DFC: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E00: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E04: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E08: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E0C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E10: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E14: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E18: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E1C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E20: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E24: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E28: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E2C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E30: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E34: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E38: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E3C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E40: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E44: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E48: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E4C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E50: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E54: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E58: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E5C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E60: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E64: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E68: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E6C: 04064f2a                 subi.b  #$2A,d6 ; '*'
04064E70: 04064ed8                 subi.b  #$D8,d6
04064E74: 04064efc                 subi.b  #$FC,d6
04064E78: 04064e88                 subi.b  #$88,d6
04064E7C: 1039040b4f46             move.b  (byte_40B4F46).l,d0
04064E82: 00000080                 ori.b   #$80,d0
04064E86: 600a                     bra.s   loc_4064E92
04064E88: 1039040b4f46             move.b  (byte_40B4F46).l,d0
04064E8E: 00000040                 ori.b   #$40,d0 ; '@'
04064E92: 13c0040b4f46             move.b  d0,(byte_40B4F46).l
04064E98: 020000c0                 andi.b  #$C0,d0
04064E9C: 56c1                     sne     d1
04064E9E: 4401                     neg.b   d1
04064EA0: 1039040b4f4c             move.b  (byte_40B4F4C).l,d0
04064EA6: 020000fe                 andi.b  #$FE,d0
04064EAA: 8001                     or.b    d1,d0
04064EAC: 13c0040b4f4c             move.b  d0,(byte_40B4F4C).l
04064EB2: 6076                     bra.s   loc_4064F2A
04064F22: 61fffffff988             bsr.l   _adb_keyboard_LED
04064F28: 584f                     addq.w  #4,sp
04064F2A: 4ab9040c32d8             tst.l   (_eventsOpen).l
04064F30: 670e                     beq.s   loc_4064F40
04064F32: 41f9040b4f4d             lea     (byte_40B4F4D).l,a0
04064F38: e9c20447                 bfextu  d2{17:7},d0
04064F3C: efd00047                 bfins   d0,(a0){1:7}
04064F40: e9c20447                 bfextu  d2{17:7},d0
04064F44: 1439040b4f4c             move.b  (byte_40B4F4C).l,d2
04064F4A: 6c000084                 bge.w   loc_4064FD0
04064F4E: 7632                     moveq   #$32,d3 ; '2'
04064F50: b680                     cmp.l   d0,d3
04064F52: 672a                     beq.s   loc_4064F7E
04064F54: 7643                     moveq   #$43,d3 ; 'C'
04064F56: b680                     cmp.l   d0,d3
04064F58: 6676                     bne.s   loc_4064FD0
04064F5A: 1002                     move.b  d2,d0
04064F5C: 02000028                 andi.b  #$28,d0 ; '('
04064F60: 0c000028                 cmpi.b  #$28,d0 ; '('
04064F64: 666a                     bne.s   loc_4064FD0
04064F66: 61ff0000b814             bsr.l   _km_reset
04064F6C: 1039040b4f4c             move.b  (byte_40B4F4C).l,d0
04064F72: 02000028                 andi.b  #$28,d0 ; '('
04064F76: 0c000028                 cmpi.b  #$28,d0 ; '('
04064F7A: 67ea                     beq.s   loc_4064F66
04064F7C: 6052                     bra.s   loc_4064FD0
04064F7E: 4a39040b4f4d             tst.b   (byte_40B4F4D).l
04064F84: 6d4a                     blt.s   loc_4064FD0
04064F86: 1002                     move.b  d2,d0
04064F88: 02000028                 andi.b  #$28,d0 ; '('
04064F8C: 0c000028                 cmpi.b  #$28,d0 ; '('
04064F90: 6608                     bne.s   loc_4064F9A
04064F92: 61fffffff7b4             bsr.l   _adb_force_NMI
04064F98: 602e                     bra.s   loc_4064FC8
04064F9A: 08020003                 btst    #3,d2
04064F9E: 6730                     beq.s   loc_4064FD0
04064FA0: 42a7                     clr.l   -(sp)
04064FA2: 61fffffff7ee             bsr.l   _adb_watchdog
04064FA8: 4879040a9d12             pea     (aRestartPowerOf).l; "Restart/Power-Off"
04064FAE: 4879040a9d24             pea     (aRestart).l; "restart"
04064FB4: 61ff0002e9c0             bsr.l   _mini_mon
04064FBA: 48780001                 pea     (1).w
04064FBE: 61fffffff7d2             bsr.l   _adb_watchdog
04064FC4: 504f                     addq.w  #8,sp
04064FC6: 504f                     addq.w  #8,sp
04064FC8: 61ff00004e48             bsr.l   _AllKeysUp
04064FCE: 600e                     bra.s   loc_4064FDE
04064FD0: 4879040b4f4a             pea     (unk_40B4F4A).l
04064FD6: 61ff00002d94             bsr.l   _ev_k_intr
04064FDC: 584f                     addq.w  #4,sp
04064FDE: 2639040b4f3a             move.l  (dword_40B4F3A).l,d3
04064FE4: b6b9040b4f3e             cmp.l   (dword_40B4F3E).l,d3
04064FEA: 6600fae6                 bne.w   loc_4064AD2
04064FEE: 6014                     bra.s   loc_4065004
04064FF0: 2f09                     move.l  a1,-(sp)
04064FF2: 4879040a9d54             pea     (aAdbKeyboardEve_0).l; "adb_keyboard: event with NULL keycodes!"...
04064FF8: 61fffffa635e             bsr.l   _printf
04064FFE: 61ff00004e12             bsr.l   _AllKeysUp
04065004: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
0406500A: 4e5e                     unlk    a6
0406500C: 4e75                     rts
