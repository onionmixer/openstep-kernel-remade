/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1b88 */

int FUN_001c1b88(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_10;
  int local_c;
  undefined4 local_8;
  
  iVar2 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,"PCI"
                        ,0);
  local_c = param_1;
  local_8 = _objc_getOrigClass("IOEISADeviceDescription",PTR_s__initWithDelegate__001f9458,param_3);
  _objc_msgSendSuper(&local_c);
  puVar3 = (undefined1 *)_IOMalloc(4);
  *(undefined1 **)(param_1 + 0x24) = puVar3;
  local_10 = 0;
  if (iVar2 != 0) {
    cVar1 = _objc_msgSend(iVar2,PTR_s_isPCIPresent_001f9680);
    if (cVar1 == '\x01') {
      iVar2 = _objc_msgSend(iVar2,PTR_s_configAddress_device_function_bu_001f9660,param_3,puVar3 + 1
                            ,puVar3 + 2,puVar3 + 3);
      if (iVar2 == 0) {
        local_10 = 1;
      }
    }
  }
  *puVar3 = local_10;
  return param_1;
}

