
uint _exportfs(void)

{
  undefined4 *puVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined uVar6;
  uint *puVar5;
  int *piVar7;
  word *pwStack_c;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar3 = _suser();
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return 0;
  }
  uVar4 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(char *)(dword_40B57D4 + 100) = (char)uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  uVar6 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 100))(iStack_8,&pwStack_c);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  iVar3 = *(int *)(iStack_8 + 0x24);
  uVar4 = _vn_rele(iStack_8);
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  if (puVar1[1] == 0) {
    uVar6 = _unexport(iVar3 + 0x14,pwStack_c);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    uVar4 = _kfree(pwStack_c,*pwStack_c + 2);
    return uVar4;
  }
  puVar5 = (uint *)_kalloc(0x30);
  puVar5[8] = *(uint *)(iVar3 + 0x14);
  puVar5[9] = *(uint *)(iVar3 + 0x18);
  puVar5[10] = (uint)pwStack_c;
  uVar6 = _copyinmsg(puVar1[1],puVar5,0x20);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*puVar5 & 0xfffffffc) == 0) {
      uVar4 = 0;
      if ((*puVar5 & 2) != 0) {
        uVar4 = _loadaddrs(puVar5 + 6);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
        if (*(char *)(dword_40B57D4 + 100) != '\0') goto loc_4026938;
      }
      if (puVar5[2] == 1) {
        uVar4 = _loadaddrs(puVar5 + 3);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        piVar7 = &_exported;
        iVar3 = _exported;
        do {
          if (iVar3 == 0) {
            puVar5[0xb] = 0;
            *piVar7 = (int)puVar5;
            return uVar4;
          }
          uVar4 = _bcmp(*piVar7 + 0x20,puVar5 + 8,8);
          if (uVar4 == 0) {
            wVar2 = **(word **)(*piVar7 + 0x28);
            uVar4 = (uint)wVar2;
            if ((wVar2 != *(word *)puVar5[10]) ||
               (uVar4 = _bcmp(*(word **)(*piVar7 + 0x28) + 1,(word *)puVar5[10] + 1,wVar2),
               uVar4 != 0)) goto loc_4026926;
            iVar3 = *piVar7;
            *piVar7 = *(int *)(iVar3 + 0x2c);
            uVar4 = _exportfree(iVar3);
          }
          else {
loc_4026926:
            piVar7 = (int *)(*piVar7 + 0x2c);
          }
          iVar3 = *piVar7;
        } while( true );
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
loc_4026938:
  _kfree((word *)puVar5[10],*(word *)puVar5[10] + 2);
  uVar4 = _kfree(puVar5,0x30);
  return uVar4;
}

