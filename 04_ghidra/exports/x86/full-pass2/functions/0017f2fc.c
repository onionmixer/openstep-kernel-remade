/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f2fc */

void FUN_0017f2fc(int param_1)

{
  int iVar1;
  int local_c;
  undefined *local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9e38;
    _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  _objc_msgSend(iVar1,PTR_s__destroyMapping__001f9280,param_1);
  return;
}

