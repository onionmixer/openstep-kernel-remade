040A0CAA: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
040A0CB2: 6606                     bne.s   loc_40A0CBA
040A0CB4: 4ef904001b3e             jmp     std_trap
040A0CBA: 4ef9040a5492             jmp     fpsp_unsupp
