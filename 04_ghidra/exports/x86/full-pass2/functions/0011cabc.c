/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cabc */

undefined4 _pn_append(int param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  iVar1 = ~uVar4 - 1;
  if ((uint)(iVar1 + *(int *)(param_1 + 8)) < 0x400) {
    _bcopy(param_2,(void *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)),~uVar4);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
    uVar3 = 0;
  }
  else {
    uVar3 = 0x3f;
  }
  return uVar3;
}

