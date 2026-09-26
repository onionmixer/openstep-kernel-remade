/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae488 */

void FUN_001ae488(int param_1,undefined4 param_2,undefined1 *param_3,char param_4,undefined4 param_5
                 ,undefined2 param_6)

{
  char cVar1;
  undefined1 local_8;
  
  if (param_4 == '\0') {
    cVar1 = *(char *)(param_1 + 0x189);
    *param_3 = 0x2a;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x189);
    *param_3 = 0x28;
  }
  param_3[1] = param_3[1] & 0x1f | cVar1 << 5;
  param_3[2] = (char)((uint)param_5 >> 0x18);
  param_3[3] = (char)((uint)param_5 >> 0x10);
  param_3[4] = (char)((uint)param_5 >> 8);
  param_3[5] = (char)param_5;
  param_3[7] = (char)((ushort)param_6 >> 8);
  local_8 = (undefined1)param_6;
  param_3[8] = local_8;
  return;
}

