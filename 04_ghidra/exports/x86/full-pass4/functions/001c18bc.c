/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c18bc */

int FUN_001c18bc(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  uVar3 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,"PCI"
                        ,0);
  cVar2 = _objc_msgSend(param_1,PTR_s_isPCIPresent_001f9680);
  if (cVar2 == '\0') {
    iVar4 = -0x2c0;
  }
  else {
    iVar4 = _objc_msgSend(param_4,PTR_s_getPCIdevice_function_bus__001f967c,&local_5,&local_6,
                          &local_7);
    if (iVar4 == 0) {
      uVar5 = 0;
      do {
        uVar1 = *param_3;
        param_3 = param_3 + 1;
        iVar4 = _objc_msgSend(uVar3,PTR_s_setRegister_device_function_bus__001f9670,uVar5 & 0xff,
                              local_5,local_6,local_7,uVar1);
        if (iVar4 != 0) {
          return iVar4;
        }
        uVar5 = uVar5 + 4;
      } while ((int)uVar5 < 0x100);
      iVar4 = 0;
    }
  }
  return iVar4;
}

