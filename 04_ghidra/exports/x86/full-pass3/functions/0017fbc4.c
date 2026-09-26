/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017fbc4 */

int FUN_0017fbc4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                char param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_KernBusItem_001f9f50;
  _objc_msgSendSuper(&local_c,PTR_s_initForResource_item_shareable__001f9254,param_3,param_4,
                     (int)param_6);
  uVar1 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_KernLock_001f9d84,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_KernLock_001f9d84,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  *(int *)(param_1 + 0x28) = param_5;
  if (param_5 == 0) {
    pcVar2 = _KernDeviceInterruptDispatch;
    if (param_6 != '\0') {
      pcVar2 = _KernDeviceInterruptDispatchShared;
    }
    *(code **)(param_1 + 0x28) = pcVar2;
  }
  return param_1;
}

