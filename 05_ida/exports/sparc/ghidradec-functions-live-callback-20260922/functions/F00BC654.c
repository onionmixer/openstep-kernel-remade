
/* WARNING: Removing unreachable block (ram,0xf00bc6c4) */
/* WARNING: Removing unreachable block (ram,0xf00bc694) */
/* WARNING: Removing unreachable block (ram,0xf00bc758) */
/* WARNING: Removing unreachable block (ram,0xf00bc664) */

undefined8 -[kmDevice kmOpen:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
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
  bool bVar4;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar3 = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),paLock);
  if ((param_3 & 0xa0000000) == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x108);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x114);
    if (iVar2 != 1) {
      if (iVar2 == 3) {
        uVar1 = *(undefined4 *)(param_1 + 0x108);
        goto loc_F00BC754;
      }
      _suser();
      if (iVar2 == 0) {
        uVar3 = 0xd;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x114);
        if (iVar2 == 4) {
          uVar3 = 0x10;
        }
        else {
          _FBAllocateConsole();
          bVar4 = _wserver_on == 0;
          *(int *)(param_1 + 0x110) = iVar2;
          if ((bVar4) && (_basicConsoleMode != 0)) {
            *(undefined4 *)(param_1 + 0x110) = _basicConsole;
          }
          iVar2 = *(int *)(param_1 + 0x110);
          if (iVar2 == 0) {
            *(undefined4 *)(param_1 + 0x110) = _basicConsole;
            iVar2 = *(int *)(param_1 + 0x110);
          }
          (**(code **)(iVar2 + 4))(iVar2,3,0,1,off_F011FE80);
          *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x114);
          *(undefined4 *)(param_1 + 0x114) = 3;
          *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
        }
      }
    }
    uVar1 = *(undefined4 *)(param_1 + 0x108);
  }
loc_F00BC754:
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,uVar3);
}

