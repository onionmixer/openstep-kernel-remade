/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001abaec */

int FUN_001abaec(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_30;
  undefined *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  char local_18 [20];
  
  *(int *)(param_1 + 300) = param_1 + 0x128;
  *(int *)(param_1 + 0x128) = param_1 + 0x128;
  uVar1 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_deviceStyle_001f943c);
  iVar2 = _objc_msgSend(uVar1);
  if (iVar2 == 0) {
    local_30 = param_1;
    local_2c = PTR_s_IODirectDevice_001fa360;
    iVar2 = _objc_msgSendSuper(&local_30,PTR_s_initFromDeviceDescription__001f9560,param_3);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = _objc_msgSend(param_1,PTR_s_startIOThread_001f9b5c);
    if (iVar2 != 0) {
      _objc_msgSend(param_1,PTR_s_free_001f921c);
      return 0;
    }
  }
  _objc_msgSend(param_1,PTR_s_setUnit__001f9478,DAT_001e516c);
  iVar2 = DAT_001e516c;
  DAT_001e516c = DAT_001e516c + 1;
  _sprintf(local_18,"sc%d",iVar2);
  _objc_msgSend(param_1,PTR_s_setName__001f947c,local_18);
  _objc_msgSend(param_1,PTR_s_setDeviceKind__001f9480,"sc");
  _objc_msgSend(param_1,PTR_s_getDMAAlignment__001f93a0,&local_28);
  *(uint *)(param_1 + 0x230) = local_28;
  if (local_28 < local_24) {
    *(uint *)(param_1 + 0x230) = local_24;
  }
  if (*(uint *)(param_1 + 0x230) < local_20) {
    *(uint *)(param_1 + 0x230) = local_20;
  }
  if (*(uint *)(param_1 + 0x230) < local_1c) {
    *(uint *)(param_1 + 0x230) = local_1c;
  }
  if (*(int *)(param_1 + 0x230) == 1) {
    *(undefined4 *)(param_1 + 0x230) = 0;
  }
  return param_1;
}

