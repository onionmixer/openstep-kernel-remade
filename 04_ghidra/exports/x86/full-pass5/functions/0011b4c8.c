/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b4c8 */

undefined4 _dnlc_lookupSymLink(char *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  iVar1 = ~uVar4 - 1;
  if (iVar1 < 0x21) {
    uVar3 = FUN_0011b8dc(param_2,param_1,iVar1,
                         (int)*param_1 + (int)param_1[~uVar4 - 2] + iVar1 + param_2 & 0x3f,
                         0xffffffff);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

