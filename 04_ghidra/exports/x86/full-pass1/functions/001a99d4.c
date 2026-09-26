/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a99d4 */

void FUN_001a99d4(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined *local_8;
  
  while( true ) {
    iVar1 = _objc_msgSend(param_1,PTR_s_dequeue_001f9b64);
    if (iVar1 == 0) break;
    _nb_free(iVar1);
  }
  local_c = param_1;
  local_8 = PTR_s_Object_001fa298;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

