/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4e48 */

undefined4 FUN_001a4e48(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 local_c;
  int local_8;
  
  bVar2 = false;
  iVar4 = FUN_001a3e30(param_3,&local_8);
  if (iVar4 == 0) {
    *(undefined4 *)(local_8 + 0x10) = param_4;
  }
  iVar4 = _objc_msgSend(param_3,PTR_s_deviceStyle_001f943c);
  if (iVar4 == 1) {
    piVar5 = (int *)_objc_msgSend(param_3,PTR_s_requiredProtocols_001f9424);
    if ((piVar5 == (int *)0x0) || (*piVar5 == 0)) {
      uVar7 = _objc_msgSend(param_3,PTR_s_name_001f9228);
      _IOLog("Loaded class %s returns nil for +requiredProtocols\n",uVar7);
    }
    else {
      iVar4 = 0;
      do {
        iVar6 = FUN_001a3d58(iVar4,&local_c);
        if (((iVar6 != -0x2c0) && (-0x2c0 < iVar6)) && (iVar6 == 0)) {
          iVar1 = *piVar5;
          piVar8 = piVar5;
          while (iVar1 != 0) {
            cVar3 = _objc_msgSend(local_c,PTR_s_conformsTo__001f9238,*piVar8);
            if (cVar3 == '\0') goto LAB_001a4f61;
            piVar8 = piVar8 + 1;
            iVar1 = *piVar8;
          }
          _objc_msgSend(param_4,PTR_s_setDirectDevice__001f9cc0,local_c);
          cVar3 = _objc_msgSend(param_3,PTR_s_probe__001f9460,param_4);
          if (cVar3 != '\0') {
            bVar2 = true;
          }
        }
LAB_001a4f61:
        iVar4 = iVar4 + 1;
      } while (iVar6 != -0x2c0);
    }
  }
  else if ((iVar4 == 0) || (iVar4 == 2)) {
    cVar3 = _objc_msgSend(param_3,PTR_s_respondsTo__001f9464,PTR_s_probe__001f9460);
    if (cVar3 == '\0') {
      uVar7 = _objc_msgSend(param_3,PTR_s_name_001f9228);
      _IOLog("addLoadedClass: Class %s does not respond to probe:\n",uVar7);
    }
    else {
      cVar3 = _objc_msgSend(param_3,PTR_s_probe__001f9460,param_4);
      if (cVar3 != '\0') {
        bVar2 = true;
      }
    }
  }
  if (bVar2) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0xfffffd40;
  }
  return uVar7;
}

