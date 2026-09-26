/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001340d8 */

int FUN_001340d8(int param_1,int *param_2)

{
  int iVar1;
  undefined1 local_44 [20];
  short local_30;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                    (param_1,local_44,*(undefined4 *)(_active_u + 0x1c));
  if (iVar1 == 0) {
    *param_2 = (int)local_30;
    if (*(int *)(*(int *)(param_1 + 0x30) + 0x7c) != 0) {
      *param_2 = local_30 + -1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

