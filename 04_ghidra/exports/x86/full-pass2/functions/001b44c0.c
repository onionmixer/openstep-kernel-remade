/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b44c0 */

int FUN_001b44c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined1 param_5)

{
  int iVar1;
  undefined1 local_4f4 [1264];
  
  iVar1 = _objc_msgSend(param_1,PTR_s__parseKeyMapping_length_into__001f9948,param_3,param_4,
                        local_4f4);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),PTR_s_lock_001f9220);
    if ((*(int *)(param_1 + 0x4ec) != 0) && (*(char *)(param_1 + 0x4fc) == '\x01')) {
      _IOFree(*(int *)(param_1 + 0x4ec),*(undefined4 *)(param_1 + 0x4f0));
    }
    _bcopy(local_4f4,(void *)(param_1 + 4),0x4f0);
    *(undefined1 *)(param_1 + 0x4fc) = param_5;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),PTR_s_unlock_001f9474);
  }
  return param_1;
}

