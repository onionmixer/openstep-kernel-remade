/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001082c4 */

undefined4 _groupmember(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  
  iVar1 = *(int *)(_active_u + 0x1c);
  if (*(short *)(iVar1 + 4) == param_1) {
LAB_001082da:
    uVar2 = 1;
  }
  else {
    for (psVar3 = (short *)(iVar1 + 10); (psVar3 < (short *)(iVar1 + 0x2a) && (*psVar3 != -1));
        psVar3 = psVar3 + 1) {
      if (*psVar3 == param_1) goto LAB_001082da;
    }
    uVar2 = 0;
  }
  return uVar2;
}

