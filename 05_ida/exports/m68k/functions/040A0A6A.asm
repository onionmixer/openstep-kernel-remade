040A0A6A: 4e56ff40                 link    a6,#-$C0
040A0A6E: f327                     fsave   -(sp)
040A0A70: 08ae0002ff24             bclr    #2,var_DC(a6)
040A0A76: f35f                     frestore (sp)+
040A0A78: 4e5e                     unlk    a6
040A0A7A: 52b9040b30f8             addq.l  #1,(dword_40B30F8).l
040A0A80: 4ef904001b3e             jmp     std_trap
