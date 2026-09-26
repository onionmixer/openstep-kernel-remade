/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2fdc */

int FUN_001b2fdc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined2 param_5,
                undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined2 param_9,
                char param_10,uint param_11,int param_12)

{
  int *piVar1;
  int iStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  undefined2 *puStack_20;
  undefined2 local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  local_e = (short)param_10;
  local_8 = param_5;
  local_c = param_7;
  local_a = param_6;
  local_10 = param_9;
  local_6 = param_8;
  puStack_20 = (undefined2 *)PTR_s_lock_001f9220;
  uStack_24 = *(uint *)(param_1 + 0x110);
  iStack_28 = 0x1b303b;
  _objc_msgSend();
  piVar1 = (int *)&stack0xffffffe4;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
    puStack_20 = &local_10;
    iStack_28 = param_1 + 0x1a8;
    uStack_2c = param_3;
    puStack_30 = PTR_s_postEvent_at_atTime_withData__001f9a00;
    piVar1 = &iStack_34;
    iStack_34 = param_1;
    uStack_24 = param_11 >> 0x18 | param_12 << 8;
    _objc_msgSend();
  }
  *(undefined **)((int)piVar1 + -4) = PTR_s_unlock_001f9474;
  *(undefined4 *)((int)piVar1 + -8) = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)((int)piVar1 + -0xc) = 0x1b3094;
  _objc_msgSend();
  return param_1;
}

