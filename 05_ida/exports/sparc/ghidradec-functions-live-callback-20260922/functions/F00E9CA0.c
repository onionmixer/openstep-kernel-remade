
/* WARNING: Removing unreachable block (ram,0xf00e9ef8) */
/* WARNING: Removing unreachable block (ram,0xf00e9eac) */
/* WARNING: Removing unreachable block (ram,0xf00e9e40) */
/* WARNING: Removing unreachable block (ram,0xf00e9dd4) */
/* WARNING: Removing unreachable block (ram,0xf00e9d48) */
/* WARNING: Removing unreachable block (ram,0xf00e9d18) */
/* WARNING: Removing unreachable block (ram,0xf00e9cdc) */
/* WARNING: Removing unreachable block (ram,0xf00e9d08) */
/* WARNING: Removing unreachable block (ram,0xf00e9d2c) */
/* WARNING: Removing unreachable block (ram,0xf00e9dc0) */
/* WARNING: Removing unreachable block (ram,0xf00e9e04) */
/* WARNING: Removing unreachable block (ram,0xf00e9e70) */
/* WARNING: Removing unreachable block (ram,0xf00e9ec4) */
/* WARNING: Removing unreachable block (ram,0xf00e9cc8) */
/* WARNING: Removing unreachable block (ram,0xf00e9cac) */

undefined8
-[IOFrameBufferDisplay setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar5;
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
  iVar2 = param_4;
  _strcmp(param_4,aIoFramebufferU);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,paReverttovgamod);
loc_F00E9CD0:
    puVar4 = (undefined *)0x0;
    goto locret_F00E9F0C;
  }
  iVar2 = param_4;
  _strcmp(param_4,aIoFramebufferU_0);
  if (iVar2 == 0) {
    puVar4 = (undefined *)0xfffffd3e;
    if (param_5 == 1) {
      _objc_msgSend(paEventdriver_0,paInstance);
      _objc_msgSend();
      puVar4 = (undefined *)0x0;
    }
    goto locret_F00E9F0C;
  }
  iVar2 = param_4;
  _strcmp(param_4,aIosettransfert);
  if (iVar2 != 0) {
    iVar2 = param_4;
    _strcmp(param_4,aIoBm256ToBm38M);
    if (iVar2 == 0) {
      if (param_5 == 0x100) {
        if (*(int *)(param_1 + 0x208) == 0) {
          uVar1 = 0x400;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x208) = uVar1;
        }
        uVar3 = 0;
        iVar2 = 0;
        do {
          uVar3 = uVar3 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x208) + iVar2) = *(undefined4 *)(iVar2 + param_3);
          iVar2 = iVar2 + 4;
        } while (uVar3 < 0x100);
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = (undefined *)0xfffffd3e;
      }
      goto locret_F00E9F0C;
    }
    iVar2 = param_4;
    _strcmp(param_4,aIoBm38ToBm256M);
    if (iVar2 == 0) {
      if (param_5 == 0x100) {
        if (*(int *)(param_1 + 0x20c) == 0) {
          uVar1 = 0x400;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x20c) = uVar1;
        }
        uVar3 = 0;
        iVar2 = 0;
        do {
          uVar3 = uVar3 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x20c) + iVar2) = *(undefined4 *)(iVar2 + param_3);
          iVar2 = iVar2 + 4;
        } while (uVar3 < 0x100);
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = (undefined *)0xfffffd3e;
      }
      goto locret_F00E9F0C;
    }
    iVar2 = param_4;
    _strcmp(param_4,aSparcfbconfigu);
    if (iVar2 != 0) {
      iVar2 = param_4;
      _strcmp(param_4,aIodisplaydobli);
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      if (iVar2 == 0) {
        puVar4 = (undefined *)0xfffffd42;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
        _objc_msgSendSuper(puVar4,paSetintvaluesFo_0,param_3,param_4,param_5);
      }
      goto locret_F00E9F0C;
    }
    goto loc_F00E9CD0;
  }
  iVar2 = param_1;
  _objc_msgSend(param_1,paDisplayinfo);
  switch(*(undefined4 *)(iVar2 + 0x18)) {
  case :
    bVar5 = param_5 == 4;
    break;
  case :
  case :
    bVar5 = param_5 == 0x100;
    break;
  case :
    bVar5 = param_5 == 0x10;
    break;
  case :
    bVar5 = param_5 == 0x20;
    break;
  :
    goto def_F00E9D6C;
  }
  if (bVar5) {
    _objc_msgSend(param_1,paSettransfertab,param_3,param_5);
    puVar4 = (undefined *)0x0;
  }
  else {
def_F00E9D6C:
    puVar4 = (undefined *)0xfffffd3e;
  }
locret_F00E9F0C:
  return CONCAT44(param_2,puVar4);
}

