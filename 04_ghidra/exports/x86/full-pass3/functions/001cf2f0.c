/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf2f0 */

int __nameForHeader(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    iVar1 = *_NXArgv;
  }
  else {
    iVar1 = FUN_001cf2c0();
    piVar2 = (int *)(iVar1 + 0x1c);
    piVar3 = (int *)(*(int *)(iVar1 + 0x14) + (int)piVar2);
    for (; piVar2 < piVar3; piVar2 = (int *)((int)piVar2 + piVar2[1])) {
      if ((*piVar2 == 6) && (piVar2[4] == param_1)) {
        return (int)piVar2 + piVar2[2];
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

