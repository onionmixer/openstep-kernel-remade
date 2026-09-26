/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c19b0 */

int FUN_001c19b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  uVar2 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,"PCI"
                        ,0);
  cVar1 = _objc_msgSend(param_1,PTR_s_isPCIPresent_001f9680);
  if (cVar1 == '\0') {
    iVar3 = -0x2c0;
  }
  else {
    iVar3 = _objc_msgSend(param_5,PTR_s_getPCIdevice_function_bus__001f967c,&local_5,&local_6,
                          &local_7);
    if (iVar3 == 0) {
      iVar3 = _objc_msgSend(uVar2,PTR_s_getRegister_device_function_bus__001f9678,param_4,local_5,
                            local_6,local_7,param_3);
    }
  }
  return iVar3;
}

