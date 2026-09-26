/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e67c */

void __ioSetDriverPowerManagementState(undefined4 param_1)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int iVar5;
  undefined4 local_8;
  
  puVar1 = PTR_s_setPowerManagement__001f9244;
  while( true ) {
    iVar5 = unaff_EBX + 1;
    iVar3 = _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_lookupByObjectNumber_instance__001f9230,
                          unaff_EBX,&local_8);
    if (iVar3 == -0x2c0) break;
    unaff_EBX = iVar5;
    if (iVar3 != -0x2d7) {
      uVar4 = _objc_msgSend(local_8,PTR_s_class_001f9234,PTR_s_conformsTo__001f9238,&DAT_001fdd2c);
      cVar2 = _objc_msgSend(uVar4);
      if (cVar2 != '\0') {
        _objc_msgSend(local_8,PTR_s_perform_with__001f923c,puVar1,param_1);
      }
    }
  }
  return;
}

