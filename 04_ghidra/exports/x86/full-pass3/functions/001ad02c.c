/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad02c */

void FUN_001ad02c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
  *puVar1 = 7;
  *(byte *)(puVar1 + 8) = *(byte *)(puVar1 + 8) & 0xfe;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x18c)) {
    do {
      _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x18c));
  }
  _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar1);
  if ((*(byte *)(param_1 + 0x18a) & 1) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x184),PTR_s_releaseTarget_lun_forOwner__001f9ac8,
                  *(undefined1 *)(param_1 + 0x188),*(undefined1 *)(param_1 + 0x189),param_1);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_free_001f921c);
  local_c = param_1;
  local_8 = _objc_getOrigClass("IODisk",PTR_s_free_001f921c);
  _objc_msgSendSuper(&local_c);
  return;
}

