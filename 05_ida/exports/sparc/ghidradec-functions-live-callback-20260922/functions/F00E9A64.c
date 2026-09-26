
/* WARNING: Removing unreachable block (ram,0xf00e9c8c) */
/* WARNING: Removing unreachable block (ram,0xf00e9c04) */
/* WARNING: Removing unreachable block (ram,0xf00e9bc4) */
/* WARNING: Removing unreachable block (ram,0xf00e9ad0) */
/* WARNING: Removing unreachable block (ram,0xf00e9ab4) */
/* WARNING: Removing unreachable block (ram,0xf00e9ba8) */
/* WARNING: Removing unreachable block (ram,0xf00e9bec) */
/* WARNING: Removing unreachable block (ram,0xf00e9c34) */
/* WARNING: Removing unreachable block (ram,0xf00e9a94) */
/* WARNING: Removing unreachable block (ram,0xf00e9a74) */

undefined8
-[IOFrameBufferDisplay getIntValues:forParameter:count:]
          (int *param_1,undefined4 param_2,int *param_3,int param_4,int *param_5)

{
  undefined (*pauVar1) [16];
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar7;
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
  undefined4 auStack_28 [10];
  
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
  iVar6 = *param_5;
  iVar3 = param_4;
  _strcmp(param_4,aIoFramebufferM);
  pauVar1 = paEnterlinearmod;
  if (iVar3 == 0) {
    *param_3 = 0;
    _objc_msgSend(param_1,pauVar1);
    *param_5 = 1;
loc_F00E9AA4:
    piVar7 = (int *)0x0;
    goto locret_F00E9C98;
  }
  iVar3 = param_4;
  _strcmp(param_4,aIoFramebufferD);
  if (iVar3 != 0) {
    iVar3 = param_4;
    _strcmp(param_4,aIoFramebufferR);
    if (iVar3 == 0) {
      piVar7 = param_1;
      _objc_msgSend(param_1,paRegisterwithed);
      *param_5 = 0;
      if (iVar6 != 0) {
        *param_5 = 1;
        _objc_msgSend(param_1,paToken_0);
        *param_3 = (int)param_1;
      }
    }
    else {
      iVar3 = param_4;
      _strcmp(param_4,aIogetdisplayin);
      if (iVar3 == 0) {
        if (*param_5 == 5) {
          _objc_msgSend(param_1,paDisplayinfo);
          *param_3 = *param_1;
          param_3[1] = param_1[1];
          param_3[2] = param_1[4];
          param_3[3] = param_1[6];
          piVar7 = (int *)0x0;
          param_3[4] = param_1[7];
        }
        else {
          piVar7 = (int *)0xfffffd3e;
        }
      }
      else {
        *(int **)((int)register0x00000038 + -0x10) = param_1;
        piVar7 = (int *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
        _objc_msgSendSuper(piVar7,paGetintvaluesFo_0,param_3,param_4,param_5);
      }
    }
    goto locret_F00E9C98;
  }
  _objc_msgSend(param_1,paDisplayinfo);
  *(int *)((int)register0x00000038 + -0x28) = *param_1;
  *(int *)((int)register0x00000038 + -0x24) = param_1[1];
  *(int *)((int)register0x00000038 + -0x20) = param_1[3];
  *(int *)((int)register0x00000038 + -0x18) = param_1[0x18];
  switch(param_1[6]) {
  case :
    uVar2 = 2;
    break;
  case :
    uVar2 = 8;
    break;
  case :
    uVar2 = 0xc;
    break;
  case :
    uVar2 = 0xf;
    break;
  case :
    uVar2 = 0x20;
    break;
  :
    goto def_F00E9B14;
  }
  *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar2;
def_F00E9B14:
  *param_5 = 0;
  iVar5 = 0;
  puVar4 = (undefined *)((int)register0x00000038 + -8);
  iVar3 = 0;
  do {
    iVar5 = iVar5 + 1;
    if (*param_5 == iVar6) goto loc_F00E9AA4;
    *(undefined4 *)(iVar3 + (int)param_3) = *(undefined4 *)(puVar4 + -0x20);
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + 4;
    *param_5 = *param_5 + 1;
  } while (iVar5 < 5);
  piVar7 = (int *)0x0;
locret_F00E9C98:
  return CONCAT44(param_2,piVar7);
}

