
/* WARNING: Removing unreachable block (ram,0xf00bd6b8) */
/* WARNING: Removing unreachable block (ram,0xf00bd620) */

undefined8 _DoAlert(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  undefined5 **ppuVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  if (_kmId == 0) {
    if ((_basicConsoleMode == 3) || (_basicConsoleMode == 1)) {
      if (_basicConsole != 0) {
        cVar2 = *param_2;
        cVar1 = *param_2;
        while (cVar1 != '\0') {
          param_2 = param_2 + 1;
          (**(code **)(_basicConsole + 0x14))(_basicConsole,(int)cVar2);
          cVar2 = *param_2;
          cVar1 = *param_2;
        }
      }
    }
    else {
      iVar4 = _basicConsoleMode;
      _BasicAllocateConsole();
      _kmAlertConsole = iVar4;
      if (iVar4 != 0) {
        (**(code **)(iVar4 + 4))();
        cVar2 = *param_2;
        cVar1 = *param_2;
        while (cVar1 != '\0') {
          param_2 = param_2 + 1;
          (**(code **)(_kmAlertConsole + 0x14))(_kmAlertConsole,(int)cVar2);
          cVar2 = *param_2;
          cVar1 = *param_2;
        }
      }
    }
  }
  else {
    (*dword_F0132068)(*(undefined4 *)(_kmId + 0x108),paLock);
    if ((*(int *)(_kmId + 0x114) != 1) && (ppuVar3 = &paLock, *(int *)(_kmId + 0x114) != 3)) {
      _FBAllocateConsole();
      iVar4 = _kmId;
      *(undefined5 ***)(_kmId + 0x110) = ppuVar3;
      if (ppuVar3 == (undefined5 **)0x0) {
        *(int *)(iVar4 + 0x110) = _basicConsole;
      }
      (**(code **)(*(int *)(_kmId + 0x110) + 4))(*(int *)(_kmId + 0x110),3,0,1,param_1);
      iVar4 = _kmId;
      *(undefined4 *)(_kmId + 0x118) = *(undefined4 *)(_kmId + 0x114);
      *(undefined4 *)(iVar4 + 0x114) = 3;
      *(int *)(iVar4 + 0x11c) = *(int *)(iVar4 + 0x11c) + 1;
    }
    (*dword_F013206C)(*(undefined4 *)(_kmId + 0x108),paUnlock);
    if (*(int *)(_kmId + 0x114) == 3) {
      iVar4 = *(int *)(_kmId + 0x110);
    }
    else {
      iVar4 = *(int *)(_kmId + 0x10c);
    }
    cVar1 = *param_2;
    while (cVar2 = *param_2, cVar1 != '\0') {
      param_2 = param_2 + 1;
      (**(code **)(iVar4 + 0x14))(iVar4,(int)cVar2);
      cVar1 = *param_2;
    }
  }
  return CONCAT44(param_2,param_1);
}

