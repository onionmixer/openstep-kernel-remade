/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9694 */

int FUN_001a9694(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001fa270;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  uVar1 = _if_attach(FUN_001a95c8,0,FUN_001a95f8,FUN_001a9630,FUN_001a965c,param_4,param_5,param_6,
                     param_7,param_8,0,param_3);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return param_1;
}

