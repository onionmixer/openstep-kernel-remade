/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185e04 */

undefined4 FUN_00185e04(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if ((*param_1 == ' ') || (*param_1 == '\t')) goto LAB_00185e2f;
  }
LAB_00185e34:
  puVar5 = (undefined4 *)0x0;
  cVar1 = *param_1;
  pcVar3 = param_1;
  while ((cVar1 != '\0' &&
         (((cVar1 = *pcVar3, (byte)(cVar1 - 0x30U) < 10 || ((byte)(cVar1 + 0x9fU) < 6)) ||
          ((byte)(cVar1 + 0xbfU) < 6))))) {
    cVar1 = *pcVar3;
    if ((byte)(cVar1 - 0x30U) < 10) {
      iVar4 = cVar1 + -0x30;
    }
    else if ((byte)(cVar1 + 0x9fU) < 6) {
      iVar4 = cVar1 + -0x57;
    }
    else if ((byte)(cVar1 + 0xbfU) < 6) {
      iVar4 = cVar1 + -0x37;
    }
    else {
      iVar4 = 0;
    }
    puVar5 = (undefined4 *)(iVar4 + (int)puVar5 * 0x10);
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  if (puVar5 != (undefined4 *)0x0) {
    DAT_001e75a0 = puVar5;
  }
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if ((*param_1 == ' ') || (*param_1 == '\t')) goto LAB_00185ec7;
  }
LAB_00185ecc:
  cVar1 = *param_1;
  puVar5 = DAT_001e75a0;
  if (cVar1 != 's') {
    iVar4 = 0;
    while ((cVar1 != '\0' &&
           (((cVar1 = *param_1, (byte)(cVar1 - 0x30U) < 10 || ((byte)(cVar1 + 0x9fU) < 6)) ||
            ((byte)(cVar1 + 0xbfU) < 6))))) {
      cVar1 = *param_1;
      if ((byte)(cVar1 - 0x30U) < 10) {
        iVar2 = cVar1 + -0x30;
      }
      else if ((byte)(cVar1 + 0x9fU) < 6) {
        iVar2 = cVar1 + -0x57;
      }
      else if ((byte)(cVar1 + 0xbfU) < 6) {
        iVar2 = cVar1 + -0x37;
      }
      else {
        iVar2 = 0;
      }
      iVar4 = iVar2 + iVar4 * 0x10;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    }
    if (iVar4 == 0) {
      iVar4 = DAT_001e1740;
    }
    DAT_001e1740 = iVar4;
    iVar4 = DAT_001e1740;
    if (0x400 < DAT_001e1740) {
      iVar4 = 0x400;
    }
    pcVar3 = s__08x___001e1744;
    while( true ) {
      _safe_prf(pcVar3,puVar5);
      iVar4 = iVar4 + -1;
      if (iVar4 == -1) break;
      puVar5 = (undefined4 *)*DAT_001e75a0;
      DAT_001e75a0 = DAT_001e75a0 + 1;
      pcVar3 = s__08x_001e174c;
    }
    puVar5 = (undefined4 *)&DAT_001e1752;
  }
  _safe_prf(puVar5);
  return 1;
LAB_00185e2f:
  for (; (*param_1 != '\0' && ((*param_1 == ' ' || (*param_1 == '\t')))); param_1 = param_1 + 1) {
  }
  goto LAB_00185e34;
LAB_00185ec7:
  for (; (*param_1 != '\0' && ((*param_1 == ' ' || (*param_1 == '\t')))); param_1 = param_1 + 1) {
  }
  goto LAB_00185ecc;
}

