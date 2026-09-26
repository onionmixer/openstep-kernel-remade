/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001395f0 */

void _set_blocksize(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  if (((_nblkdev <= (int)(uint)param_2._1_1_) ||
      ((code *)(&PTR__nodev_001e2d04)[(uint)param_2._1_1_ * 6] == (code *)0x0)) ||
     (iVar2 = (*(code *)(&PTR__nodev_001e2d04)[(uint)param_2._1_1_ * 6])((int)param_2), iVar2 == -1)
     ) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    return;
  }
  *(int *)(param_1 + 0x48) = iVar2;
  if (*(int *)(param_1 + 0x3c) == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x30);
  if (*(int *)(iVar1 + 0x48) != 0) {
    return;
  }
  *(int *)(iVar1 + 0x48) = iVar2;
  return;
}

