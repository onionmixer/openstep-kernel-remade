
void _access(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined uVar6;
  int iVar5;
  word wVar7;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar6 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  iVar5 = *(int *)(_active_u + 0x1a);
  uVar3 = *(undefined2 *)(iVar5 + 2);
  uVar4 = *(undefined2 *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 2) = *(undefined2 *)(iVar5 + 6);
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 4) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 8);
  wVar7 = 0;
  uVar2 = puVar1[1];
  if (uVar2 != 0) {
    if ((uVar2 & 4) != 0) {
      wVar7 = 0x100;
    }
    if ((uVar2 & 2) != 0) {
      iVar5 = _isrofile(iStack_8);
      if (iVar5 != 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
        goto loc_401A83C;
      }
      wVar7 = wVar7 | 0x80;
    }
    if ((*(byte *)((int)puVar1 + 7) & 1) != 0) {
      wVar7 = wVar7 | 0x40;
    }
    uVar6 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x1c))
                      (iStack_8,wVar7,*(undefined4 *)(_active_u + 0x1a));
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
  }
loc_401A83C:
  _vn_rele(iStack_8);
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2) = uVar3;
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 4) = uVar4;
  return;
}

