/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001962b4 */

int FUN_001962b4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char local_18 [20];
  
  if (DAT_001e7778 == 0) {
    DAT_001e7774 = 0;
    DAT_001e7778 = 1;
  }
  iVar2 = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
  uVar3 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(iVar2 + 0x108) = uVar3;
  DAT_001e776c = _objc_msgSend(uVar3,PTR_s_methodFor__001f9470,PTR_s_lock_001f9220);
  DAT_001e7770 = _objc_msgSend(*(undefined4 *)(iVar2 + 0x108),PTR_s_methodFor__001f9470,
                               PTR_s_unlock_001f9474);
  *(undefined4 *)(iVar2 + 0x120) = 0;
  iVar4 = 1;
  do {
    *(undefined4 *)(iVar2 + 0x10c + iVar4 * 4) = 0;
    iVar1 = DAT_001e7764;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  if (DAT_001e7764 == 0) {
    _kmId = iVar2;
  }
  *(undefined4 *)(iVar2 + 0x10c) = _basicConsole;
  _objc_msgSend(_kmId,PTR_s_setUnit__001f9478,iVar1);
  iVar4 = DAT_001e7764;
  DAT_001e7764 = DAT_001e7764 + 1;
  _sprintf(local_18,s_kmDevice_d_001e38ec,iVar4);
  _objc_msgSend(_kmId,PTR_s_setName__001f947c,local_18);
  _objc_msgSend(_kmId,PTR_s_setDeviceKind__001f9480,s_kmDevice_001e38f7);
  _objc_msgSend(_kmId,PTR_s_setLocation__001f9484,0);
  return iVar2;
}

