/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001425a4 */

int FUN_001425a4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  local_8 = *(int *)(param_1 + 0x10) + 4;
  while( true ) {
    iVar1 = FUN_00142600(uVar2,param_1,2,&local_8,&local_c);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(short *)(param_1 + 2) == 2) break;
    if (*(short *)(local_c + 2) == 2) {
      return local_c;
    }
    uVar2 = *(undefined4 *)(local_c + 0x14);
  }
  return local_c;
}

