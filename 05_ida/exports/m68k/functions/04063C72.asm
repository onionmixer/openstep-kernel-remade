04063C72: 4856                     pea     (a6)
04063C74: 2c4f                     movea.l sp,a6
04063C76: 48e73f3c                 movem.l d2-d7/a2-a5,-(sp)
04063C7A: 262e000c                 move.l  $C(a6),d3
04063C7E: 2c2e0010                 move.l  $10(a6),d6
04063C82: 282e0014                 move.l  $14(a6),d4
04063C86: 246e0018                 movea.l $18(a6),a2
04063C8A: 242e001c                 move.l  $1C(a6),d2
04063C8E: 286e0024                 movea.l $24(a6),a4
04063C92: 2e2e0028                 move.l  $28(a6),d7
04063C96: 4ab9040b06f0             tst.l   (_panel_req_port).l
04063C9C: 660000fe                 bne.w   loc_4063D9C
04063CA0: 7201                     moveq   #1,d1
04063CA2: b28a                     cmp.l   a2,d1
04063CA4: 6718                     beq.s   loc_4063CBE
04063CA6: 6d06                     blt.s   loc_4063CAE
04063CA8: 4a8a                     tst.l   a2
04063CAA: 670a                     beq.s   loc_4063CB6
04063CAC: 6020                     bra.s   loc_4063CCE
04063CAE: 7202                     moveq   #2,d1
04063CB0: b28a                     cmp.l   a2,d1
04063CB2: 6712                     beq.s   loc_4063CC6
04063CB4: 6018                     bra.s   loc_4063CCE
04063CB6: 203c040a9b0f             move.l  #$40A9B0F,d0
04063CBC: 6016                     bra.s   loc_4063CD4
04063CBE: 203c040a9b16             move.l  #$40A9B16,d0
04063CC4: 600e                     bra.s   loc_4063CD4
04063CC6: 203c040a9b1e             move.l  #$40A9B1E,d0
04063CCC: 6006                     bra.s   loc_4063CD4
04063CCE: 203c040a62e7             move.l  #$40A62E7,d0
04063CD4: 7206                     moveq   #6,d1
04063CD6: b283                     cmp.l   d3,d1
04063CD8: 650000b0                 bcs.w   loc_4063D8A
04063CDC: 207c04063ce8             movea.l #$4063CE8,a0
04063CE2: 20703c00                 movea.l (a0,d3.l*4),a0
04063CE6: 4ed0                     jmp     (a0)
04063CE8: 04063d04                 subi.b  #4,d6
04063CEC: 04063d1a                 subi.b  #$1A,d6
04063CF0: 04063d30                 subi.b  #$30,d6 ; '0'
04063CF4: 04063d46                 subi.b  #$46,d6 ; 'F'
04063CF8: 04063d5c                 subi.b  #$5C,d6 ; '\'
04063CFC: 04063d6c                 subi.b  #$6C,d6 ; 'l'
04063D00: 04063d76                 subi.b  #$76,d6 ; 'v'
04063D04: 2f02                     move.l  d2,-(sp)
04063D06: 2f04                     move.l  d4,-(sp)
04063D08: 2f00                     move.l  d0,-(sp)
04063D0A: 4879040a9b23             pea     (aPleaseInsertSD).l; "Please Insert %s Disk %d in Drive %d\n"
04063D10: 61fffffa7646             bsr.l   _printf
04063D16: 60000180                 bra.w   loc_4063E98
04063D1A: 2f02                     move.l  d2,-(sp)
04063D1C: 2f0c                     move.l  a4,-(sp)
04063D1E: 2f00                     move.l  d0,-(sp)
04063D20: 4879040a9b49             pea     (aPleaseInsertSD_0).l; "Please Insert %s Disk '%s' in Drive %d"...
04063D26: 61fffffa7630             bsr.l   _printf
04063D2C: 6000016a                 bra.w   loc_4063E98
04063D30: 2f02                     move.l  d2,-(sp)
04063D32: 2f04                     move.l  d4,-(sp)
04063D34: 2f00                     move.l  d0,-(sp)
04063D36: 4879040a9b71             pea     (aWrongDiskPleas).l; "Wrong Disk: Please Insert %s Disk %d in"...
04063D3C: 61fffffa761a             bsr.l   _printf
04063D42: 60000154                 bra.w   loc_4063E98
04063D46: 2f02                     move.l  d2,-(sp)
04063D48: 2f0c                     move.l  a4,-(sp)
04063D4A: 2f00                     move.l  d0,-(sp)
04063D4C: 4879040a9ba3             pea     (aWrongDiskPleas_0).l; "Wrong Disk: Please Insert %s Disk '%s' "...
04063D52: 61fffffa7604             bsr.l   _printf
04063D58: 6000013e                 bra.w   loc_4063E98
04063D5C: 4879040a9bd7             pea     (aSwapDeviceFull).l; "***Swap Device Full***\n"
04063D62: 61fffffa75f4             bsr.l   _printf
04063D68: 6000012e                 bra.w   loc_4063E98
04063D6C: 2f0c                     move.l  a4,-(sp)
04063D6E: 4879040a9bef             pea     (aFileSystemSFul).l; "***File System %s Full***\n"
04063D74: 601c                     bra.s   loc_4063D92
04063D76: 2f02                     move.l  d2,-(sp)
04063D78: 2f00                     move.l  d0,-(sp)
04063D7A: 4879040a9c0a             pea     (aPleaseEjectSDi).l; "Please Eject %s Disk %d\n"
04063D80: 61fffffa75d6             bsr.l   _printf
04063D86: 60000110                 bra.w   loc_4063E98
04063D8A: 2f03                     move.l  d3,-(sp)
04063D8C: 4879040a9c23             pea     (aVolPanelReques).l; "vol_panel_request: bogus panel_type (%d"...
04063D92: 61fffffa75c4             bsr.l   _printf
04063D98: 600000fe                 bra.w   loc_4063E98
04063D9C: 4878008c                 pea     ($8C).w
04063DA0: 2a3c0404a200             move.l  #$404A200,d5
04063DA6: 2a45                     movea.l d5,a5
04063DA8: 4e95                     jsr     (a5)
04063DAA: 2640                     movea.l d0,a3
04063DAC: 4878008c                 pea     ($8C).w
04063DB0: 2f0b                     move.l  a3,-(sp)
04063DB2: 4879040b0780             pea     (unk_40B0780).l
04063DB8: 61ff0002ef72             bsr.l   _bcopy
04063DBE: 504f                     addq.w  #8,sp
04063DC0: 584f                     addq.w  #4,sp
04063DC2: 2779040b06f4000c         move.l  (dword_40B06F4).l,$C(a3)
04063DCA: 2779040b06f00010         move.l  (_panel_req_port).l,$10(a3)
04063DD2: 2743001c                 move.l  d3,$1C(a3)
04063DD6: 27460020                 move.l  d6,$20(a3)
04063DDA: 2779040b4e8a0024         move.l  (dword_40B4E8A).l,$24(a3)
04063DE2: 52b9040b4e8a             addq.l  #1,(dword_40B4E8A).l
04063DE8: 27440028                 move.l  d4,$28(a3)
04063DEC: 274a002c                 move.l  a2,$2C(a3)
04063DF0: 27420030                 move.l  d2,$30(a3)
04063DF4: 276e00200034             move.l  $20(a6),$34(a3)
04063DFA: 2f0c                     move.l  a4,-(sp)
04063DFC: 45f9040930e6             lea     (_strlen).l,a2
04063E02: 4e92                     jsr     (a2)
04063E04: 504f                     addq.w  #8,sp
04063E06: 7227                     moveq   #$27,d1 ; '''
04063E08: b280                     cmp.l   d0,d1
04063E0A: 6404                     bcc.s   loc_4063E10
04063E0C: 422c0027                 clr.b   $27(a4)
04063E10: 2f07                     move.l  d7,-(sp)
04063E12: 4e92                     jsr     (a2)
04063E14: 584f                     addq.w  #4,sp
04063E16: 7227                     moveq   #$27,d1 ; '''
04063E18: b280                     cmp.l   d0,d1
04063E1A: 6406                     bcc.s   loc_4063E22
04063E1C: 2a47                     movea.l d7,a5
04063E1E: 422d0027                 clr.b   $27(a5)
04063E22: 2f0c                     move.l  a4,-(sp)
04063E24: 486b003c                 pea     $3C(a3)
04063E28: 45f9040930a0             lea     (_strcpy).l,a2
04063E2E: 4e92                     jsr     (a2)
04063E30: 2f07                     move.l  d7,-(sp)
04063E32: 486b0064                 pea     $64(a3)
04063E36: 4e92                     jsr     (a2)
04063E38: 42a7                     clr.l   -(sp)
04063E3A: 48780001                 pea     (1).w
04063E3E: 2f0b                     move.l  a3,-(sp)
04063E40: 61fffffe4cd6             bsr.l   _msg_send_from_kernel
04063E46: defc001c                 adda.w  #$1C,sp
04063E4A: 4a80                     tst.l   d0
04063E4C: 664c                     bne.s   loc_4063E9A
04063E4E: 2a6e0030                 movea.l $30(a6),a5
04063E52: 2aab0024                 move.l  $24(a3),(a5)
04063E56: 4a86                     tst.l   d6
04063E58: 673e                     beq.s   loc_4063E98
04063E5A: 48780014                 pea     ($14).w
04063E5E: 2a45                     movea.l d5,a5
04063E60: 4e95                     jsr     (a5)
04063E62: 2440                     movea.l d0,a2
04063E64: 4a8a                     tst.l   a2
04063E66: 6604                     bne.s   loc_4063E6C
04063E68: 7006                     moveq   #6,d0
04063E6A: 602e                     bra.s   loc_4063E9A
04063E6C: 256b00240008             move.l  $24(a3),8(a2)
04063E72: 256e0008000c             move.l  8(a6),$C(a2)
04063E78: 256e002c0010             move.l  $2C(a6),$10(a2)
04063E7E: 41f9040b0708             lea     (off_40B0708).l,a0
04063E84: 2250                     movea.l (a0),a1
04063E86: 228a                     move.l  a2,(a1)
04063E88: 25490004                 move.l  a1,4(a2)
04063E8C: 24bc040b0704             move.l  #$40B0704,(a2)
04063E92: 23ca040b0708             move.l  a2,(off_40B0708).l
04063E98: 4280                     clr.l   d0
04063E9A: 4cee3cfcffd8             movem.l -$28(a6),d2-d7/a2-a5
04063EA0: 4e5e                     unlk    a6
04063EA2: 4e75                     rts
