04001EC8: 52b9040b5658             addq.l  #1,(dword_40B5658).l
04001ECE: 48e7ffff                 movem.l d0-d7/a0-a7,-(sp)
04001ED2: 4e7a8800                 movec   usp,a0
04001ED6: 2f48003c                 move.l  a0,$40+var_4(sp)
04001EDA: 4def0038                 lea     $40+var_8(sp),a6
04001EDE: 244f                     movea.l sp,a2
04001EE0: 2e79040b57cc             movea.l (_stack_pointers).l,sp
04001EE6: 2f0a                     move.l  a2,-(sp)
04001EE8: 4eb90409a044             jsr     _unix_syscall
04001EEE: 2e4a                     movea.l a2,sp
04001EF0: 206f003c                 movea.l $44+var_8(sp),a0
04001EF4: 4e7b8800                 movec   a0,usp
04001EF8: 4cd77fff                 movem.l (sp),d0-d7/a0-a6
04001EFC: defc0040                 adda.w  #$40,sp ; '@'
04001F00: 4e73                     rte
