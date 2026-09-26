/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123dc4 */

char * _inet_ntoa(in_addr param_1)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  byte local_c;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)param_1.s_addr;
  pbVar3 = (byte *)&local_8;
  pcVar1 = &DAT_001e58f4;
  iVar4 = 0;
  do {
    if (iVar4 != 0) {
      *pcVar1 = '.';
      pcVar1 = pcVar1 + 1;
    }
    pcVar2 = pcVar1;
    if (99 < *pbVar3) {
      *pcVar1 = *pbVar3 / 100 + 0x30;
      pcVar2 = pcVar1 + 1;
      if ((byte)((*pbVar3 % 100) / 10) == 0) {
        *pcVar2 = '0';
        pcVar2 = pcVar1 + 2;
      }
      local_c = *pbVar3 % 100;
      *pbVar3 = local_c;
    }
    if (9 < *pbVar3) {
      *pcVar2 = *pbVar3 / 10 + 0x30;
      pcVar2 = pcVar2 + 1;
      local_c = *pbVar3 % 10;
      *pbVar3 = local_c;
    }
    *pcVar2 = *pbVar3 + 0x30;
    pcVar1 = pcVar2 + 1;
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  *pcVar1 = '\0';
  return &DAT_001e58f4;
}

