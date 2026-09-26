
/* WARNING: Removing unreachable block (ram,0xf00c2de4) */
/* WARNING: Removing unreachable block (ram,0xf00c2dc8) */
/* WARNING: Removing unreachable block (ram,0xf00c2d64) */
/* WARNING: Removing unreachable block (ram,0xf00c2ce4) */

undefined8 sub_F00C2C34(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  undefined *puVar5;
  undefined6 *puVar6;
  undefined6 *puVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar8 = (int)(sword)*(word *)(param_2 + 0x38);
  iVar2 = (uint)(*(word *)(param_2 + 0x38) >> 8) * 0x2c;
  iVar3 = iVar8;
  (**(code **)(_cdevsw + iVar2 + 0x10))
            (iVar8,0x40067408,(undefined *)((int)register0x00000038 + -0x10),0);
  if (iVar3 == 0) {
    *(undefined2 *)((int)register0x00000038 + -0xc) = 0xe0;
    uVar4 = (undefined)*(undefined4 *)(param_1 + 0x24);
    sub_F00C2C0C();
    *(undefined *)((int)register0x00000038 + -0xf) = uVar4;
    *(undefined *)((int)register0x00000038 + -0x10) = uVar4;
    (**(code **)(_cdevsw + iVar2 + 0x10))
              (iVar8,0x80067409,(undefined *)((int)register0x00000038 + -0x10),0);
    if (iVar8 == 0) {
      if (_MS_DEBUG == 0) {
        cVar1 = *(char *)((int)register0x00000038 + -0x10);
      }
      else {
        if (*(int *)(param_1 + 0x24) == 0xc) {
          puVar6 = &aB4800_3;
        }
        else {
          puVar6 = &aB1200_1;
        }
        if (*(char *)((int)register0x00000038 + -0x10) == '\f') {
          puVar7 = &aB4800_4;
        }
        else {
          puVar7 = &aB1200_4;
        }
        _log(5,aMouseBaudRateC_1,puVar6,puVar7,0);
        cVar1 = *(char *)((int)register0x00000038 + -0x10);
      }
      *(int *)(param_1 + 0x24) = (int)cVar1;
      *(undefined4 *)(param_1 + 0x28) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      sub_F00C2698();
      goto locret_F00C2DEC;
    }
    puVar5 = aMouseBaudRateC_0;
    if (*(int *)(param_1 + 0x24) == 0xc) {
      puVar6 = &aB4800_1;
    }
    else {
      puVar6 = &aB1200_0;
    }
    if (*(char *)((int)register0x00000038 + -0x10) == '\f') {
      puVar7 = &aB4800_2;
    }
    else {
      puVar7 = &aB1200_3;
    }
  }
  else {
    puVar5 = aMouseBaudRateC;
    if (*(int *)(param_1 + 0x24) == 0xc) {
      puVar6 = &aB4800;
    }
    else {
      puVar6 = &aB1200;
    }
    iVar8 = iVar3;
    if (*(char *)((int)register0x00000038 + -0x10) == '\f') {
      puVar7 = &aB4800_0;
    }
    else {
      puVar7 = &aB1200_2;
    }
  }
  _log(5,puVar5,puVar6,puVar7,iVar8);
locret_F00C2DEC:
  return CONCAT44(_cdevsw + iVar2,param_1);
}
