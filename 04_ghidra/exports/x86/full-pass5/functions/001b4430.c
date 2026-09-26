/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b4430 */

int FUN_001b4430(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001fa450;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if (*(int *)(param_1 + 0x4f4) == 0) {
    uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    *(undefined4 *)(param_1 + 0x4f4) = uVar1;
  }
  iVar2 = _objc_msgSend(param_1,PTR_s_setKeyMapping_length_canFree__001f994c,param_3,param_4,
                        (int)param_5);
  if (iVar2 == 0) {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  return param_1;
}

