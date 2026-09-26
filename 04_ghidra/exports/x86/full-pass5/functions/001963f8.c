/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001963f8 */

int FUN_001963f8(int param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_lock_001f9220);
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x114) = param_4;
  *(undefined4 *)(param_1 + 0x170) = 0;
  if (param_3 != '\0') {
    iVar1 = _objc_msgSend(param_1,PTR_s_initKb_001f9488);
    if (iVar1 == 0) {
      _IOLog(s_kmDevice__No_Keyboard_Found_001e3900);
    }
  }
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa018;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if (*(char *)(param_1 + 0x174) == '\0') {
    _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
    *(undefined1 *)(param_1 + 0x174) = 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_unlock_001f9474);
  return param_1;
}

