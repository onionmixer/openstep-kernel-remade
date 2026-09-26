/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6010 */

undefined4 FUN_001a6010(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x184) = param_3;
  _objc_msgSend(param_1,PTR_s_setIsPhysical__001f9ca8,0);
  uVar2 = _objc_msgSend(param_3,PTR_s_blockSize_001f93a8);
  *(undefined4 *)(param_1 + 0x18c) = uVar2;
  cVar1 = _objc_msgSend(param_3,PTR_s_isRemovable_001f93c8);
  _objc_msgSend(param_1,PTR_s_setRemovable__001f9ca4,(int)cVar1);
  cVar1 = _objc_msgSend(param_3,PTR_s_isFormatted_001f9398);
  _objc_msgSend(param_1,PTR_s_setFormattedInternal__001f9ca0,(int)cVar1);
  cVar1 = _objc_msgSend(param_3,PTR_s_isWriteProtected_001f9cb0);
  _objc_msgSend(param_1,PTR_s_setWriteProtected__001f9c9c,(int)cVar1);
  _objc_msgSend(param_1,PTR_s_setLogicalDisk__001f9c98,0);
  uVar2 = _objc_msgSend(param_3,PTR_s_devAndIdInfo_001f9c94);
  _objc_msgSend(param_1,PTR_s_setDevAndIdInfo__001f9c90,uVar2);
  return 0;
}

