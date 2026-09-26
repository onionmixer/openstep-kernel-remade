04083CCA: 4856                     pea     (a6)
04083CCC: 2c4f                     movea.l sp,a6
04083CCE: 2f0a                     move.l  a2,-(sp)
04083CD0: 246e0008                 movea.l 8(a6),a2
04083CD4: 206a0004                 movea.l 4(a2),a0
04083CD8: 48680010                 pea     $10(a0)
04083CDC: 42a7                     clr.l   -(sp)
04083CDE: 48780006                 pea     (6).w
04083CE2: 2f280010                 move.l  $10(a0),-(sp)
04083CE6: 2f39040c6eb8             move.l  (dword_40C6EB8).l,-(sp)
04083CEC: 61fffffc6322             bsr.l   _object_copyin
04083CF2: 42a7                     clr.l   -(sp)
04083CF4: 42a7                     clr.l   -(sp)
04083CF6: 2f2a0004                 move.l  4(a2),-(sp)
04083CFA: 61fffffc4e1c             bsr.l   _msg_send_from_kernel
04083D00: defc0020                 adda.w  #$20,sp ; ' '
04083D04: 206a0004                 movea.l 4(a2),a0
04083D08: 2f280010                 move.l  $10(a0),-(sp)
04083D0C: 61fffffc63a2             bsr.l   _port_release
04083D12: 2f0a                     move.l  a2,-(sp)
04083D14: 61fffffffdda             bsr.l   _dspq_free_msg
04083D1A: 246efffc                 movea.l -4(a6),a2
04083D1E: 4e5e                     unlk    a6
04083D20: 4e75                     rts
