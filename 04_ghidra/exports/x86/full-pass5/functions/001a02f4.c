/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a02f4 */

int FUN_001a02f4(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  if (*(uint *)(param_1 + 0x148) < *param_3) {
    *param_3 = *(uint *)(param_1 + 0x148);
  }
  uVar1 = 0;
  if (*param_3 != 0) {
    do {
      *param_4 = (int)*(short *)(param_1 + 0x14c + uVar1 * 2);
      param_4[1] = (int)*(short *)(param_1 + 0x174 + uVar1 * 2);
      param_4 = param_4 + 2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *param_3);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  return param_1;
}

