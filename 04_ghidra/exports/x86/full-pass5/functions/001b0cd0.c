/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0cd0 */

undefined4 FUN_001b0cd0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if ((*(char *)(param_1 + 0x1d0) == '\0') || (*(int *)(param_1 + 0x114) != param_4)) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    uVar1 = 0xfffffd3e;
  }
  else {
    _objc_msgSend(param_1,PTR_s_forceAutoDimState__001f9a3c,0);
    _objc_msgSend(param_1,PTR_s_hideCursor_001f9a38);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    _objc_msgSend(param_1,PTR_s_detachEventSources_001f9a34);
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      _objc_msgSend(param_1,PTR_s_unmapEventShmem__001f9a30,*(undefined4 *)(param_1 + 0x114));
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
    if (*(int *)(param_1 + 0x180) != 0) {
      _IOFree(*(int *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x17c));
      *(undefined4 *)(param_1 + 0x180) = 0;
      *(undefined4 *)(param_1 + 0x17c) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined4 *)(param_1 + 0x184) = 0;
    }
    _objc_msgSend(param_1,PTR_s_setEventPort__001f9a40,0);
    *(undefined1 *)(param_1 + 0x1d0) = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    uVar1 = 0;
  }
  return uVar1;
}

