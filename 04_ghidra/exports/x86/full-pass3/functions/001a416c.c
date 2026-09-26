/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a416c */

int FUN_001a416c(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (*(char *)(param_1 + 0x58) == '\0') {
    _IOLog("Registering: %s\n",param_1 + 8);
  }
  else {
    _IOLog("Registering: %s at %s\n",param_1 + 8,param_1 + 0x58);
  }
  piVar2 = (int *)_IOMalloc(0x10);
  *piVar2 = param_1;
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  piVar2[1] = DAT_001e8668;
  DAT_001e8668 = DAT_001e8668 + 1;
  if ((int **)DAT_001e866c == &DAT_001e866c) {
    DAT_001e866c = piVar2;
    DAT_001e8670 = piVar2;
    piVar2[2] = (int)&DAT_001e866c;
    piVar2[3] = (int)&DAT_001e866c;
  }
  else {
    piVar2[3] = (int)DAT_001e8670;
    piVar2[2] = (int)&DAT_001e866c;
    puVar1 = (undefined4 *)((int)DAT_001e8670 + 8);
    DAT_001e8670 = piVar2;
    *puVar1 = piVar2;
  }
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_connectToIndirectDevices__001f9ce0,param_1);
  return param_1;
}

