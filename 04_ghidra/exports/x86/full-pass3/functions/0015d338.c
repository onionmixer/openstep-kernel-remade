/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d338 */

int FUN_0015d338(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34 [5];
  undefined1 local_20 [28];
  
  pcVar4 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar3 = pcVar4;
  do {
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar3) {
      return 2;
    }
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_0015d57c(pcVar4,local_20,&local_38,&local_3c,&local_40);
  if (iVar2 == 0) {
    _memset(local_34,0,0x14);
    local_34[0] = 0;
    iVar2 = FUN_0015cb1c(local_40,param_2,local_20,local_38,local_3c,param_3,&local_44,local_34);
    if ((iVar2 == 0) && (local_44 < *(uint *)(param_1 + 0xc))) {
      iVar2 = 3;
    }
    _vn_rele(local_40);
  }
  return iVar2;
}

