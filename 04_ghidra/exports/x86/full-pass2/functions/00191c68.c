/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191c68 */

undefined4 FUN_00191c68(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_a8;
  undefined1 local_a4 [80];
  undefined1 local_54 [80];
  
  piVar2 = (int *)_objc_msgSend(PTR_s_SCSIDisk_001f9d94,PTR_s_requiredProtocols_001f9424);
  if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {
LAB_00191d2a:
    uVar4 = 1;
  }
  else {
    iVar6 = 0;
    while ((iVar3 = _objc_msgSend(PTR_s_IODevice_001f9d68,
                                  PTR_s_lookupByObjectNumber_deviceKind__001f9360,iVar6,local_a4,
                                  local_54), iVar3 == 0 || (iVar3 == -0x2d7))) {
      iVar3 = _IOGetObjectForDeviceName(local_54,&local_a8);
      if (iVar3 == 0) {
        iVar3 = *piVar2;
        piVar5 = piVar2;
        while( true ) {
          if (iVar3 == 0) goto LAB_00191d2a;
          cVar1 = _objc_msgSend(local_a8,PTR_s_conformsTo__001f9238,*piVar5);
          if (cVar1 == '\0') break;
          piVar5 = piVar5 + 1;
          iVar3 = *piVar5;
        }
      }
      iVar6 = iVar6 + 1;
    }
    uVar4 = 0;
  }
  return uVar4;
}

