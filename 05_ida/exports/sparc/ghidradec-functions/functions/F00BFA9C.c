
/* WARNING: Removing unreachable block (ram,0xf00bfb5c) */
/* WARNING: Removing unreachable block (ram,0xf00bfc00) */
/* WARNING: Removing unreachable block (ram,0xf00bfba4) */
/* WARNING: Removing unreachable block (ram,0xf00bfb0c) */
/* WARNING: Removing unreachable block (ram,0xf00bfaec) */
/* WARNING: Removing unreachable block (ram,0xf00bfae0) */
/* WARNING: Removing unreachable block (ram,0xf00bfaf8) */
/* WARNING: Removing unreachable block (ram,0xf00bfb84) */
/* WARNING: Removing unreachable block (ram,0xf00bfbc8) */
/* WARNING: Removing unreachable block (ram,0xf00bfb38) */
/* WARNING: Removing unreachable block (ram,0xf00bfb74) */
/* WARNING: Removing unreachable block (ram,0xf00bfab4) */

undefined8
-[EventSrcPCKeyboard getIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int *param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar3 = *param_5;
  iVar2 = param_4;
  _strcmp(param_4,aEvsCurrentkeyr);
  if (iVar2 == 0) {
    if (uVar3 < 4) goto locret_F00BFC18;
    *param_5 = 4;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    sub_F00BF194(param_1 + 0x170,param_3);
    sub_F00BF194(param_1 + 0x168,param_3 + 2);
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  else {
    iVar2 = param_4;
    _strcmp(param_4,aEvsCurrentkeym);
    if (iVar2 != 0) {
      iVar2 = param_4;
      _strcmp(param_4,aEvsEventdevice_0);
      if (iVar2 == 0) {
        *param_5 = 0;
        iVar2 = *(int *)(param_1 + 300);
        _objc_msgSend(iVar2,paInterfaceid);
        *param_3 = iVar2;
        param_3[2] = 1;
        param_3[1] = 0;
        iVar2 = *(int *)(param_1 + 300);
        puVar4 = (undefined *)0x0;
        _objc_msgSend(iVar2,paHandlerid);
        param_3[3] = iVar2;
        *param_5 = 4;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
        _objc_msgSendSuper(puVar4,paGetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar4 == (undefined *)0xfffffd39) {
          puVar4 = (undefined *)0xfffffd3e;
        }
      }
      goto locret_F00BFC18;
    }
    if (uVar3 == 0) goto locret_F00BFC18;
    *param_5 = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    iVar2 = *(int *)(param_1 + 0x128);
    if (iVar2 == 0) {
      *param_3 = 0;
    }
    else {
      _objc_msgSend(iVar2,paKeymappingleng);
      *param_3 = iVar2;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  puVar4 = (undefined *)0x0;
  _objc_msgSend(uVar1,paUnlock);
locret_F00BFC18:
  return CONCAT44(param_2,puVar4);
}
