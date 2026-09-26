/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b6f0 */

void _dnlc_remove(int param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar5 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  iVar1 = ~uVar5 - 1;
  if (iVar1 < 0x21) {
    cVar2 = *param_2;
    cVar3 = param_2[~uVar5 - 2];
    while( true ) {
      iVar4 = FUN_0011b8dc(param_1,param_2,iVar1,(int)cVar2 + (int)cVar3 + iVar1 + param_1 & 0x3f,
                           0xffffffff);
      if (iVar4 == 0) break;
      FUN_0011b830(iVar4);
    }
  }
  return;
}

