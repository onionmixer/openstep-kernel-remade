/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a770 */

undefined4 _vm_set_policy(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    }
    if (param_2 == 0) {
      param_2 = *(uint *)(param_1 + 0x14);
    }
    _lock_read(param_1);
    for (iVar3 = *(int *)(param_1 + 0x10); iVar3 != param_1 + 0xc; iVar3 = *(int *)(iVar3 + 4)) {
      if ((*(byte *)(iVar3 + 0x18) & 5) == 0) {
        if ((*(uint *)(iVar3 + 8) <= param_3 + param_2) && (param_2 < *(uint *)(iVar3 + 0xc))) {
          for (iVar1 = *(int *)(iVar3 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
            *(undefined2 *)(iVar1 + 0x48) = (undefined2)param_4;
          }
        }
      }
      else {
        FUN_0017a6f4(*(undefined4 *)(iVar3 + 0x10),param_2,param_3 + param_2,param_4);
      }
    }
    _lock_done(param_1);
    uVar2 = 0;
  }
  return uVar2;
}

