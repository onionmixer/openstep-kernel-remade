/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193f34 */

void _probeNativeDevices(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  int local_c;
  undefined4 local_8;
  
  FUN_00194890();
  pcVar1 = (char *)_IOMalloc(0x80);
  local_c = 1;
  do {
    iVar2 = _findBootConfigString(local_c);
    if (iVar2 == 0) {
      _defaultBusClass =
           _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusClassWithName__001f930c,&DAT_001e2a20
                        );
      if (_defaultBusClass == 0) {
        _sprintf(pcVar1,s_Missing__s_kernel_bus_class_001e2a2a,&DAT_001e2a25);
                    /* WARNING: Subroutine does not return */
        _panic(pcVar1);
      }
      _defaultBus = _objc_msgSend(PTR_s_KernBus_001f9d8c,
                                  PTR_s_lookupBusInstanceWithName_busId__001f9310,&DAT_001e2a46,0);
      iVar2 = _eisa_id(0,&local_8);
      if (iVar2 == 0) {
        _printf(s_ISA_bus_001e2a7a);
        _is_ISA = 1;
      }
      else {
        _printf(s_CPU__EISA_id__08x_001e2a4b,local_8);
        iVar2 = 1;
        do {
          iVar6 = _eisa_id(iVar2,&local_8);
          if (iVar6 != 0) {
            _printf(s_slot__x__EISA_id__08x_001e2a5e,iVar2,local_8);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 0x10);
        _led_msg(&DAT_001e2a75);
        _is_ISA = 0;
      }
      uVar3 = _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_driverKitVersion_001f9430);
      _printf(s_DriverKit_version__d_001e2a83,uVar3);
      local_c = 1;
      while( true ) {
        iVar2 = _findBootConfigString(local_c);
        if (iVar2 == 0) break;
        FUN_00194140(iVar2);
        local_c = local_c + 1;
      }
      _IOFree(pcVar1,0x80);
      return;
    }
    uVar3 = _objc_msgSend(PTR_s_IOConfigTable_001f9d90,PTR_s_newForConfigData__001f937c,iVar2);
    pcVar4 = (char *)_objc_msgSend(uVar3,PTR_s_valueForStringKey__001f9308,s_Family_001e2a0b);
    if (pcVar4 != (char *)0x0) {
      iVar2 = 4;
      bVar9 = true;
      pcVar7 = pcVar4;
      pcVar8 = &DAT_001e2a12;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar9);
      if (bVar9) {
        uVar5 = _objc_msgSend(uVar3,PTR_s_valueForStringKey__001f9308,s_Bus_Class_001e2a16);
        uVar5 = _objc_getClass(uVar5);
        _objc_msgSend(uVar5,PTR_s_probeBus__001f942c,uVar3);
      }
      _objc_msgSend(uVar3,PTR_s_freeString__001f9314,pcVar4);
    }
    local_c = local_c + 1;
  } while( true );
}

