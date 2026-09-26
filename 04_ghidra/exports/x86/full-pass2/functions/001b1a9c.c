/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1a9c */

int FUN_001b1a9c(int param_1)

{
  _objc_msgSend(*(undefined4 *)(param_1 + 0x20c),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x20a) == '\x01') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x20c),PTR_s_unlock_001f9474);
  }
  else {
    *(undefined1 *)(param_1 + 0x20a) = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x20c),PTR_s_unlock_001f9474);
    _objc_msgSend(param_1,PTR_s_sendIOThreadAsyncMsg_to_with__001f99e8,
                  PTR_s__performKickEventConsumer__001f99c4,param_1,0);
  }
  return param_1;
}

