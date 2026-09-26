/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a6f4 */

void FUN_0017a6f4(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  _lock_read(param_1);
  for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != param_1 + 0xc; iVar2 = *(int *)(iVar2 + 4)) {
    if ((*(byte *)(iVar2 + 0x18) & 5) == 0) {
      if ((*(uint *)(iVar2 + 8) <= param_3) && (param_2 < *(uint *)(iVar2 + 0xc))) {
        for (iVar1 = *(int *)(iVar2 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
          *(short *)(iVar1 + 0x48) = (short)param_4;
        }
      }
    }
    else {
      FUN_0017a6f4(*(undefined4 *)(iVar2 + 0x10),param_2,param_3,param_4);
    }
  }
  _lock_done(param_1);
  return;
}

