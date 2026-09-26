
/* WARNING: Removing unreachable block (ram,0xf00c088c) */
/* WARNING: Removing unreachable block (ram,0xf00c0820) */
/* WARNING: Removing unreachable block (ram,0xf00c07d8) */
/* WARNING: Removing unreachable block (ram,0xf00c0804) */
/* WARNING: Removing unreachable block (ram,0xf00c0830) */
/* WARNING: Removing unreachable block (ram,0xf00c07b4) */
/* WARNING: Removing unreachable block (ram,0xf00c0784) */

undefined8
-[EventSrcPCPointer getIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,uint *param_3,int param_4,int *param_5)

{
  undefined7 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
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
  puVar4 = (undefined *)0xfffffd3e;
  iVar3 = *param_5;
  iVar2 = param_4;
  _strcmp(param_4,aEvsCurrentmous);
  if (iVar2 == 0) {
    *param_3 = iVar3 - 1U >> 1;
    _objc_msgSend(param_1,paPointerscaling_0,param_3,param_3 + 1);
    puVar4 = (undefined *)0x0;
    *param_5 = *param_3 * 2 + 1;
  }
  else {
    iVar2 = param_4;
    _strcmp(param_4,aEvsCurrentmous_0);
    if (iVar2 == 0) {
      if (iVar3 != 0) {
        *param_5 = 1;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
        puVar1 = paUnlock;
        *param_3 = *(uint *)(param_1 + 0x134);
        puVar4 = (undefined *)0x0;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),puVar1);
      }
    }
    else {
      iVar2 = param_4;
      _strcmp(param_4,aEvsEventdevice_1);
      if (iVar2 == 0) {
        *param_5 = 0;
        *param_3 = 4;
        param_3[2] = 2;
        param_3[1] = 0;
        param_3[3] = 0;
        *param_5 = 4;
        puVar4 = (undefined *)0x0;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
        _objc_msgSendSuper(puVar4,paGetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar4 == (undefined *)0xfffffd39) {
          puVar4 = (undefined *)0xfffffd3e;
        }
      }
    }
  }
  return CONCAT44(param_2,puVar4);
}
