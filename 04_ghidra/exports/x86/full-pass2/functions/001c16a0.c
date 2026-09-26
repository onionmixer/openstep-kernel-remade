/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c16a0 */

int FUN_001c16a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined1 local_10;
  int local_c;
  undefined4 local_8;
  
  iVar2 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,
                        "EISA",0);
  local_c = param_1;
  local_8 = _objc_getOrigClass("IODeviceDescription",PTR_s__initWithDelegate__001f9458,param_3);
  _objc_msgSendSuper(&local_c);
  pvVar3 = (void *)_IOMalloc(0x1c);
  *(void **)(param_1 + 0x20) = pvVar3;
  _bzero(pvVar3,0x1c);
  iVar1 = *(int *)(param_1 + 0x20);
  local_10 = 0;
  if (iVar2 != 0) {
    iVar2 = _objc_msgSend(iVar2,PTR_s_getEISASlotNumber_slotID_usingDe_001f9684,iVar1 + 0x14,
                          iVar1 + 0x18,param_3);
    if (iVar2 == 0) {
      local_10 = 1;
    }
  }
  *(undefined1 *)(iVar1 + 0x10) = local_10;
  return param_1;
}

