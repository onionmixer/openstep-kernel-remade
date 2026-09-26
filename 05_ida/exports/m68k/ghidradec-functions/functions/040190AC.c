
undefined4 _vno_lockrelease(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  word wVar6;
  sword sVar9;
  undefined4 uVar8;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iVar7;
  
  uVar1 = *(uint *)(*_active_u + 0x28);
  if ((uVar1 & 0x20000000) != 0) {
    bVar5 = false;
    *(uint *)(*_active_u + 0x28) = uVar1 & 0xdfffffff;
    iVar2 = *(int *)(param_1 + 0x16);
    iVar7 = *(int *)((int)_active_u + 0x14e);
    if (-1 < iVar7) {
      do {
        iVar3 = *(int *)(*(int *)((int)_active_u + 0x146) + iVar7 * 4);
        if (iVar3 != 0) {
          bVar4 = *(byte *)(*(int *)((int)_active_u + 0x14a) + iVar7);
          if ((bVar4 & 4) != 0) {
            if (iVar2 == *(int *)(iVar3 + 0x16)) {
              bVar5 = true;
              *(byte *)(*(int *)((int)_active_u + 0x14a) + iVar7) = bVar4 & 0xfb;
            }
            else {
              *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 0x20;
            }
          }
        }
        wVar6 = (word)((uint)iVar7 >> 0x10);
        sVar9 = (sword)iVar7 + -1;
        iVar7 = CONCAT22(wVar6,sVar9);
      } while ((sVar9 != -1) || (iVar7 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
    }
    if (bVar5) {
      uStack_16 = 3;
      uStack_14 = 0;
      uStack_12 = 0;
      uStack_e = 0;
      uVar8 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x60))
                        (iVar2,&uStack_16,8,*(undefined4 *)((int)_active_u + 0x1a),
                         (int)*(sword *)(*_active_u + 0x30));
      return uVar8;
    }
  }
  return 0;
}
