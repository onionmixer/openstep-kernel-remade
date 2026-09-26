
uint _lseek(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  undefined uVar6;
  uint uVar5;
  undefined auStack_42 [20];
  int iStack_2e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar6 = _getvnodefp(*puVar1,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  bVar4 = *(byte *)(dword_40B57D4 + 100);
  if (bVar4 == 0) {
    iVar2 = *(int *)(iStack_8 + 0x16);
    if (*(int *)(iVar2 + 0x28) != 8) {
      uVar3 = puVar1[2];
      uVar5 = uVar3;
      if (uVar3 == 1) {
        if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) &&
           (uVar5 = puVar1[1] + *(int *)(iStack_8 + 0x1a), (int)uVar5 < 0)) {
loc_401A726:
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return uVar5;
        }
        *(int *)(iStack_8 + 0x1a) = puVar1[1] + *(int *)(iStack_8 + 0x1a);
      }
      else {
        if ((int)uVar3 < 2) {
          if (uVar3 == 0) {
            if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (uVar5 = 0, (int)puVar1[1] < 0))
            goto loc_401A726;
            *(undefined4 *)(iStack_8 + 0x1a) = puVar1[1];
            uVar5 = uVar3;
            goto loc_401A746;
          }
        }
        else if (uVar3 == 2) {
          uVar5 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                            (iVar2,auStack_42,*(undefined4 *)((int)_active_u + 0x1a));
          *(char *)(dword_40B57D4 + 100) = (char)uVar5;
          if (*(char *)(dword_40B57D4 + 100) != '\0') {
            return uVar5;
          }
          if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) &&
             (uVar5 = iStack_2e + puVar1[1], (int)uVar5 < 0)) goto loc_401A726;
          *(int *)(iStack_8 + 0x1a) = iStack_2e + puVar1[1];
          goto loc_401A746;
        }
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
loc_401A746:
      *(undefined4 *)(dword_40B57D4 + 0x5c) = *(undefined4 *)(iStack_8 + 0x1a);
      return uVar5;
    }
  }
  else if (bVar4 != 0x16) {
    return (uint)bVar4;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0x1d;
  return (uint)bVar4;
}

