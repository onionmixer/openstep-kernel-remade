/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012dc70 */

undefined4 FUN_0012dc70(short *param_1,uint *param_2)

{
  uint uVar1;
  short *psVar2;
  bool bVar3;
  
  uVar1 = 0;
  if (*param_2 != 0) {
    psVar2 = (short *)param_2[1];
    do {
      if (*psVar2 == *param_1) {
        if (*param_1 == 2) {
          bVar3 = *(int *)(param_1 + 2) == *(int *)(psVar2 + 2);
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          return 1;
        }
      }
      psVar2 = psVar2 + 8;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *param_2);
  }
  return 0;
}

