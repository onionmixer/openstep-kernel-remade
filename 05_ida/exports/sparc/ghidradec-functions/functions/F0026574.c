
undefined8 _vno_lockrelease(int param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar4 = *(uint *)(*_active_u + 0x28);
  if ((uVar4 & 0x20000000) != 0) {
    *(uint *)(*_active_u + 0x28) = uVar4 & 0xdfffffff;
    iVar5 = _active_u[0x55];
    bVar2 = false;
    iVar6 = *(int *)(param_1 + 0x18);
    if (-1 < iVar5) {
      do {
        iVar3 = *(int *)(_active_u[0x53] + iVar5 * 4);
        if (iVar3 == 0) {
          bVar7 = iVar5 + -1 < 0;
        }
        else {
          bVar1 = *(byte *)(_active_u[0x54] + iVar5);
          if ((bVar1 & 4) == 0) {
            bVar7 = iVar5 + -1 < 0;
          }
          else {
            if (*(int *)(iVar3 + 0x18) == iVar6) {
              bVar2 = true;
              *(byte *)(_active_u[0x54] + iVar5) = bVar1 & 0xfb;
            }
            else {
              *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x20000000;
            }
            bVar7 = iVar5 + -1 < 0;
          }
        }
        iVar5 = iVar5 + -1;
      } while (!bVar7);
    }
    if (bVar2) {
      *(undefined2 *)((int)register0x00000038 + -0x20) = 3;
      *(undefined2 *)((int)register0x00000038 + -0x1e) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
      (**(code **)(*(int *)(iVar6 + 0x1c) + 0x60))
                (iVar6,(undefined *)((int)register0x00000038 + -0x20),8,_active_u[7],
                 (int)*(sword *)(*_active_u + 0x30));
      goto locret_F0026678;
    }
  }
  iVar6 = 0;
locret_F0026678:
  return CONCAT44(param_2,iVar6);
}
