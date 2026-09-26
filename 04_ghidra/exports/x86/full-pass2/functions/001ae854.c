/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae854 */

undefined4 FUN_001ae854(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char local_18 [20];
  
  *(undefined4 *)(param_1 + 0x128) = param_4;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(byte *)(param_1 + 0x11c) = *(byte *)(param_1 + 0x11c) & 0xfe;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(param_1 + 300) = uVar1;
  *(undefined4 *)(param_1 + 0x130) = 0;
  _sprintf(local_18,"sg%d",param_3);
  _objc_msgSend(param_1,PTR_s_setName__001f947c,local_18);
  _objc_msgSend(param_1,PTR_s_setDeviceKind__001f9480,"SCSIGeneric");
  uVar1 = _objc_msgSend(param_4,PTR_s_name_001f9228);
  _objc_msgSend(param_1,PTR_s_setLocation__001f9484,uVar1);
  _objc_msgSend(param_1,PTR_s_setUnit__001f9478,param_3);
  _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
  return 0;
}

