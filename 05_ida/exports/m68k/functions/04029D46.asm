04029D46: 4e56ffb4                 link    a6,#-$4C
04029D4A: 48e73c3c                 movem.l d2-d5/a2-a5,-(sp)
04029D4E: 4ab9040aee7e             tst.l   (dword_40AEE7E).l
04029D54: 6706                     beq.s   loc_4029D5C
04029D56: 4280                     clr.l   d0
04029D58: 6000028c                 bra.w   loc_4029FE6
04029D5C: 7201                     moveq   #1,d1
04029D5E: 23c1040aee7e             move.l  d1,(dword_40AEE7E).l
04029D64: 48780010                 pea     ($10).w
04029D68: 45eefff0                 lea     var_10(a6),a2
04029D6C: 2f0a                     move.l  a2,-(sp)
04029D6E: 61ff000690a2             bsr.l   _bzero
04029D74: 48780002                 pea     (2).w
04029D78: 61ffffff1ff0             bsr.l   _ifb_ifwithaf
04029D7E: 2640                     movea.l d0,a3
04029D80: 504f                     addq.w  #8,sp
04029D82: 584f                     addq.w  #4,sp
04029D84: 4a8b                     tst.l   a3
04029D86: 6612                     bne.s   loc_4029D9A
04029D88: 4879040a6e03             pea     (aWhoamiZeroIfp).l; "whoami: zero ifp\n"
04029D8E: 61fffffe15c8             bsr.l   _printf
04029D94: 7041                     moveq   #$41,d0 ; 'A'
04029D96: 6000024e                 bra.w   loc_4029FE6
04029D9A: 61ff0006f7ba             bsr.l   _initrootnet
04029DA0: 4a80                     tst.l   d0
04029DA2: 670e                     beq.s   loc_4029DB2
04029DA4: 4879040a6e15             pea     (aWhoamiInitroot).l; "whoami: initrootnet failed"
04029DAA: 61fffffe1eba             bsr.l   _panic
04029DB0: 584f                     addq.w  #4,sp
04029DB2: 2f0b                     move.l  a3,-(sp)
04029DB4: 4beeffb8                 lea     var_48(a6),a5
04029DB8: 2f0d                     move.l  a5,-(sp)
04029DBA: 2f3cc0206912             move.l  #$C0206912,-(sp)
04029DC0: 42a7                     clr.l   -(sp)
04029DC2: 283c0401eec4             move.l  #$401EEC4,d4
04029DC8: 2044                     movea.l d4,a0
04029DCA: 4e90                     jsr     (a0)
04029DCC: 2a00                     move.l  d0,d5
04029DCE: 504f                     addq.w  #8,sp
04029DD0: 504f                     addq.w  #8,sp
04029DD2: 6724                     beq.s   loc_4029DF8
04029DD4: 306b000c                 movea.w $C(a3),a0
04029DD8: 2f08                     move.l  a0,-(sp)
04029DDA: 2f05                     move.l  d5,-(sp)
04029DDC: 4879040a6e30             pea     (aWhoamiInContro).l; "whoami: in_control 0x%x if_flags 0x%x\n"
04029DE2: 61fffffe1574             bsr.l   _printf
04029DE8: 4879040a6e57             pea     (aBadSiocgifbrda).l; "bad SIOCGIFBRDADDR in_control"
04029DEE: 61fffffe1e76             bsr.l   _panic
04029DF4: 504f                     addq.w  #8,sp
04029DF6: 504f                     addq.w  #8,sp
04029DF8: 48780010                 pea     ($10).w
04029DFC: 2f0a                     move.l  a2,-(sp)
04029DFE: 45eeffc8                 lea     var_38(a6),a2
04029E02: 2f0a                     move.l  a2,-(sp)
04029E04: 49f904092d2c             lea     (_bcopy).l,a4
04029E0A: 4e94                     jsr     (a4)
04029E0C: 48780010                 pea     ($10).w
04029E10: 4879040b3554             pea     (unk_40B3554).l
04029E16: 2f0a                     move.l  a2,-(sp)
04029E18: 4e94                     jsr     (a4)
04029E1A: 7201                     moveq   #1,d1
04029E1C: 2d41ffe8                 move.l  d1,var_18(a6)
04029E20: 2f0b                     move.l  a3,-(sp)
04029E22: 2f0d                     move.l  a5,-(sp)
04029E24: 2f3cc020690d             move.l  #$C020690D,-(sp)
04029E2A: 42a7                     clr.l   -(sp)
04029E2C: 2044                     movea.l d4,a0
04029E2E: 4e90                     jsr     (a0)
04029E30: defc0028                 adda.w  #$28,sp ; '('
04029E34: 4a80                     tst.l   d0
04029E36: 670e                     beq.s   loc_4029E46
04029E38: 4879040a6e75             pea     (aBadSiocgifaddr).l; "bad SIOCGIFADDR in_control"
04029E3E: 61fffffe1e26             bsr.l   _panic
04029E44: 584f                     addq.w  #4,sp
04029E46: 2d6effccffb4             move.l  var_34(a6),var_4C(a6)
04029E4C: 48780004                 pea     (4).w
04029E50: 486effec                 pea     var_14(a6)
04029E54: 486effb4                 pea     var_4C(a6)
04029E58: 4e94                     jsr     (a4)
04029E5A: 7403                     moveq   #3,d2
04029E5C: 4283                     clr.l   d3
04029E5E: 48780100                 pea     ($100).w
04029E62: 45f90404a200             lea     (_kalloc).l,a2
04029E68: 4e92                     jsr     (a2)
04029E6A: 2d40ffd8                 move.l  d0,var_28(a6)
04029E6E: 48780100                 pea     ($100).w
04029E72: 4e92                     jsr     (a2)
04029E74: 2d40ffdc                 move.l  d0,var_24(a6)
04029E78: 4284                     clr.l   d4
04029E7A: defc0014                 adda.w  #$14,sp
04029E7E: 47f90400b358             lea     (_printf).l,a3
04029E84: 42a7                     clr.l   -(sp)
04029E86: 2f03                     move.l  d3,-(sp)
04029E88: 2f02                     move.l  d2,-(sp)
04029E8A: 486effd8                 pea     var_28(a6)
04029E8E: 487904030aac             pea     (_xdr_bp_whoami_res).l
04029E94: 486effe8                 pea     var_18(a6)
04029E98: 487904030a8c             pea     (_xdr_bp_whoami_arg).l
04029E9E: 48780001                 pea     (1).w
04029EA2: 48780001                 pea     (1).w
04029EA6: 2f3c000186ba             move.l  #$186BA,-(sp)
04029EAC: 486efff0                 pea     var_10(a6)
04029EB0: 61fffffffdc2             bsr.l   sub_4029C74
04029EB6: 2440                     movea.l d0,a2
04029EB8: defc002c                 adda.w  #$2C,sp ; ','
04029EBC: 7205                     moveq   #5,d1
04029EBE: b28a                     cmp.l   a2,d1
04029EC0: 661e                     bne.s   loc_4029EE0
04029EC2: 4a84                     tst.l   d4
04029EC4: 661a                     bne.s   loc_4029EE0
04029EC6: 4879040a6e90             pea     (aNoBootparamSer_0).l; "No bootparam server responding; still t"...
04029ECC: 4e93                     jsr     (a3)
04029ECE: 48780005                 pea     (5).w
04029ED2: 4879040a6ebe             pea     (aWhoamiPmapRmtc).l; "whoami: pmap_rmtcall status 0x%x\n"
04029ED8: 4e93                     jsr     (a3)
04029EDA: 7801                     moveq   #1,d4
04029EDC: 504f                     addq.w  #8,sp
04029EDE: 584f                     addq.w  #4,sp
04029EE0: 7414                     moveq   #$14,d2
04029EE2: 4283                     clr.l   d3
04029EE4: 7205                     moveq   #5,d1
04029EE6: b28a                     cmp.l   a2,d1
04029EE8: 679a                     beq.s   loc_4029E84
04029EEA: 4a84                     tst.l   d4
04029EEC: 670e                     beq.s   loc_4029EFC
04029EEE: 4879040a6ce4             pea     (aBootparamRespo).l; "Bootparam response received\n"
04029EF4: 61fffffe1462             bsr.l   _printf
04029EFA: 584f                     addq.w  #4,sp
04029EFC: 4a8a                     tst.l   a2
04029EFE: 6716                     beq.s   loc_4029F16
04029F00: 2a0a                     move.l  a2,d5
04029F02: 2f05                     move.l  d5,-(sp)
04029F04: 4879040a6ee0             pea     (aWhoamiRpcCallF).l; "whoami RPC call failed with status %d\n"
04029F0A: 61fffffe144c             bsr.l   _printf
04029F10: 504f                     addq.w  #8,sp
04029F12: 600000b6                 bra.w   loc_4029FCA
04029F16: 2f2effd8                 move.l  var_28(a6),-(sp)
04029F1A: 49f9040930e6             lea     (_strlen).l,a4
04029F20: 4e94                     jsr     (a4)
04029F22: 23c0040b5db4             move.l  d0,(_hostnamelen).l
04029F28: 584f                     addq.w  #4,sp
04029F2A: 0c8000000100             cmpi.l  #$100,d0
04029F30: 630e                     bls.s   loc_4029F40
04029F32: 4879040a6f07             pea     (aWhoamiHostname).l; "whoami: hostname too long"
04029F38: 61fffffe141e             bsr.l   _printf
04029F3E: 6060                     bra.s   loc_4029FA0
04029F40: 4a80                     tst.l   d0
04029F42: 6e12                     bgt.s   loc_4029F56
04029F44: 4879040a6f21             pea     (aWhoamiNoHostNa).l; "whoami: no host name\n"
04029F4A: 61fffffe140c             bsr.l   _printf
04029F50: 7a06                     moveq   #6,d5
04029F52: 584f                     addq.w  #4,sp
04029F54: 6074                     bra.s   loc_4029FCA
04029F56: 2f00                     move.l  d0,-(sp)
04029F58: 4879040b5cb4             pea     (_hostname).l
04029F5E: 2f2effd8                 move.l  var_28(a6),-(sp)
04029F62: 47f904092d2c             lea     (_bcopy).l,a3
04029F68: 4e93                     jsr     (a3)
04029F6A: 504f                     addq.w  #8,sp
04029F6C: 2ebc040b5cb4             move.l  #$40B5CB4,(sp)
04029F72: 4879040a6f37             pea     (aHostnameS).l; "hostname: %s\n"
04029F78: 45f90400b358             lea     (_printf).l,a2
04029F7E: 4e92                     jsr     (a2)
04029F80: 2f2effdc                 move.l  var_24(a6),-(sp)
04029F84: 4e94                     jsr     (a4)
04029F86: 23c0040b5c9c             move.l  d0,(_domainnamelen).l
04029F8C: 504f                     addq.w  #8,sp
04029F8E: 584f                     addq.w  #4,sp
04029F90: 0c8000000100             cmpi.l  #$100,d0
04029F96: 630e                     bls.s   loc_4029FA6
04029F98: 4879040a6f45             pea     (aWhoamiDomainna).l; "whoami: domainname too long"
04029F9E: 4e92                     jsr     (a2)
04029FA0: 7a3f                     moveq   #$3F,d5 ; '?'
04029FA2: 584f                     addq.w  #4,sp
04029FA4: 6024                     bra.s   loc_4029FCA
04029FA6: 4a80                     tst.l   d0
04029FA8: 6f20                     ble.s   loc_4029FCA
04029FAA: 2f00                     move.l  d0,-(sp)
04029FAC: 4879040b5b9c             pea     (_domainname).l
04029FB2: 2f2effdc                 move.l  var_24(a6),-(sp)
04029FB6: 4e93                     jsr     (a3)
04029FB8: 4879040b5b9c             pea     (_domainname).l
04029FBE: 4879040a6f61             pea     (aDomainnameS).l; "domainname: %s\n"
04029FC4: 4e92                     jsr     (a2)
04029FC6: defc0014                 adda.w  #$14,sp
04029FCA: 48780100                 pea     ($100).w
04029FCE: 2f2effd8                 move.l  var_28(a6),-(sp)
04029FD2: 45f90404a2c4             lea     (_kfree).l,a2
04029FD8: 4e92                     jsr     (a2)
04029FDA: 48780100                 pea     ($100).w
04029FDE: 2f2effdc                 move.l  var_24(a6),-(sp)
04029FE2: 4e92                     jsr     (a2)
04029FE4: 2005                     move.l  d5,d0
04029FE6: 4cee3c3cff94             movem.l var_6C(a6),d2-d5/a2-a5
04029FEC: 4e5e                     unlk    a6
04029FEE: 4e75                     rts
