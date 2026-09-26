/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f2d0 */

int FUN_0019f2d0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  if (*(char *)(param_1 + 0x14e) == '\0') {
    if (param_3 == 10) {
      *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x170) + *(uint *)(param_1 + 0x158);
      *(uint *)(param_1 + 0x164) =
           *(int *)(param_1 + 0x174) + *(int *)(param_1 + 0x15c) +
           (uint)CARRY4(*(uint *)(param_1 + 0x170),*(uint *)(param_1 + 0x158));
      *(int *)(param_1 + 0x150) = param_4;
    }
    else {
      if (param_3 != 0xb) {
        return param_1;
      }
      if (*(int *)(param_1 + 0x150) != param_4) {
        return param_1;
      }
      *(undefined4 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0;
      *(undefined4 *)(param_1 + 0x150) = 0xffffffff;
    }
    _objc_msgSend(param_1,PTR_s_scheduleAutoRepeat_001f94f0);
  }
  return param_1;
}

