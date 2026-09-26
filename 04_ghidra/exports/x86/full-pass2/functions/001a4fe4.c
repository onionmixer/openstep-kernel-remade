/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4fe4 */

void FUN_001a4fe4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *local_8;
  
  iVar5 = 0;
  _objc_msgSend(DAT_001e8684,PTR_s_lock_001f9220);
  do {
    iVar2 = FUN_001a3eac(iVar5,&local_8);
    if (iVar2 == -0x2c0) {
      _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
      return;
    }
    if (((-0x2c0 < iVar2) || (iVar2 != -0x2d7)) &&
       (iVar2 = _objc_msgSend(*local_8,PTR_s_deviceStyle_001f943c), iVar2 == 1)) {
      piVar3 = (int *)_objc_msgSend(*local_8,PTR_s_requiredProtocols_001f9424);
      if ((piVar3 == (int *)0x0) || (*piVar3 == 0)) {
        uVar4 = _objc_msgSend(*local_8,PTR_s_name_001f9228);
        _IOLog("Loaded class %s returns nil for +requiredProtocols\n",uVar4);
      }
      else {
        do {
          cVar1 = _objc_msgSend(param_3,PTR_s_conformsTo__001f9238,*piVar3);
          if (cVar1 == '\0') goto LAB_001a5151;
          piVar3 = piVar3 + 1;
        } while (*piVar3 != 0);
        iVar2 = local_8[4];
        if (iVar2 == 0) {
          uVar4 = _objc_msgSend(PTR_s_IODeviceDescription_001f9da0,PTR_s_alloc_001f9210,
                                PTR_s_init_001f924c);
          iVar2 = _objc_msgSend(uVar4);
        }
        _objc_msgSend(iVar2,PTR_s_setDirectDevice__001f9cc0,param_3);
        _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
        cVar1 = _objc_msgSend(*local_8,PTR_s_probe__001f9460,iVar2);
        if (cVar1 == '\0') {
          _objc_msgSend(iVar2,PTR_s_free_001f921c);
        }
        _objc_msgSend(DAT_001e8684,PTR_s_lock_001f9220);
      }
    }
LAB_001a5151:
    iVar5 = iVar5 + 1;
  } while( true );
}

