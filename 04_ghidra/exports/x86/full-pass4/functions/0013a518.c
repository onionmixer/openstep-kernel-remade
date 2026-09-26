/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a518 */

undefined4 _spec_realvp(int param_1,int *param_2)

{
  int iVar1;
  int local_8;
  
  if (param_1 != 0) {
    if ((*(undefined ***)(param_1 + 0x1c) == &_spec_vnodeops) ||
       (*(undefined ***)(param_1 + 0x1c) == &_fifo_vnodeops)) {
      param_1 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
    }
    if (param_1 != 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))(param_1,&local_8);
      if (iVar1 == 0) {
        param_1 = local_8;
      }
    }
  }
  *param_2 = param_1;
  return 0;
}

