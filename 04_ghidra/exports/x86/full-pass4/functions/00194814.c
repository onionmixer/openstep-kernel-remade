/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194814 */

char * _findBootConfigString(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int local_8;
  
  pcVar4 = &DAT_000134fc;
  local_8 = 0;
  if (DAT_000134fc == '\0') {
    _IOLog(s_WARNING__No_config_table_in_KERN_001e2cb7);
    pcVar4 = (char *)0x0;
  }
  else {
    iVar3 = 0;
    if (0 < param_1) {
      do {
        uVar2 = 0xffffffff;
        pcVar5 = pcVar4;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        local_8 = uVar2 + local_8;
        pcVar4 = pcVar4 + uVar2;
        if (((uVar2 == 1) || (0xd000 < local_8)) || (*pcVar4 == '\0')) {
          return (char *)0x0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1);
    }
  }
  return pcVar4;
}

