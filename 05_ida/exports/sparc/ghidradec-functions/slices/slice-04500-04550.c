/* GHIDRADEC_FUNCTION index=4500 start=0xf00d04c4 */

/* WARNING: Removing unreachable block (ram,0xf00d0500) */
/* WARNING: Removing unreachable block (ram,0xf00d0518) */
/* WARNING: Removing unreachable block (ram,0xf00d04f4) */
/* WARNING: Removing unreachable block (ram,0xf00d052c) */
/* WARNING: Removing unreachable block (ram,0xf00d04d0) */

undefined8 -[SCSIGeneric release:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 300),paLock);
  if (param_3 == *(int *)(param_1 + 0x130)) {
    _objc_msgSend(param_1,paClearreservati);
    *(undefined4 *)(param_1 + 0x130) = 0;
    uVar2 = *(undefined4 *)(param_1 + 300);
  }
  else {
    iVar1 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSBogusCloseCal,iVar1);
    uVar2 = *(undefined4 *)(param_1 + 300);
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4501 start=0xf00d053c */

/* WARNING: Removing unreachable block (ram,0xf00d0580) */
/* WARNING: Removing unreachable block (ram,0xf00d05a4) */
/* WARNING: Removing unreachable block (ram,0xf00d054c) */

undefined8
-[SCSIGeneric setTarget:lun:isRoot:]
          (int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_1 + 0x128);
  _objc_msgSend(iVar1,paNumberoftarget);
  uVar2 = 0xfffffd3e;
  if ((int)(param_3 & 0xff) < iVar1) {
    if ((param_4 & 0xff) < 9) {
      _objc_msgSend(param_1,paClearreservati);
      iVar1 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar1,paReservescsi3ta,0,param_3 & 0xff,0,param_4 & 0xff,param_1);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x120) = 1;
      }
      else if ((param_5 & 0xff) == 0) {
        uVar2 = 0xfffffd2b;
        goto locret_F00D0600;
      }
      *(qword *)(param_1 + 0x108) = (qword)(param_3 & 0xff);
      *(qword *)(param_1 + 0x110) = (qword)(param_4 & 0xff);
      uVar2 = 0;
      *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 0x80000000;
    }
    else {
      uVar2 = 0xfffffd3e;
    }
  }
locret_F00D0600:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4502 start=0xf00d0608 */

/* WARNING: Removing unreachable block (ram,0xf00d0678) */
/* WARNING: Removing unreachable block (ram,0xf00d069c) */
/* WARNING: Removing unreachable block (ram,0xf00d061c) */
/* WARNING: Removing unreachable block (ram,0xf00d0674) */

undefined8
-[SCSIGeneric setSCSI3Target:lun:isRoot:]
          (int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,uint param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar2 = *(uint *)(param_1 + 0x128);
  cVar1 = *(char *)((int)register0x00000038 + 0x5f);
  _objc_msgSend(uVar2,paNumberoftarget);
  if ((uint)((int)uVar2 >> 0x1f) <= param_3) {
    if ((int)uVar2 >> 0x1f != param_3) {
      uVar4 = 0xfffffd3e;
      goto locret_F00D06E4;
    }
    if (uVar2 <= param_4) {
      uVar4 = 0xfffffd3e;
      goto locret_F00D06E4;
    }
  }
  if (param_5 == 0) {
    if (param_6 < 9) {
      _objc_msgSend(param_1,paClearreservati);
      iVar3 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar3,paReservescsi3ta,param_3,param_4,0,param_6,param_1);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x120) = 1;
        *(qword *)(param_1 + 0x108) = CONCAT44(param_3,param_4);
      }
      else {
        if (cVar1 == '\0') {
          uVar4 = 0xfffffd2b;
          goto locret_F00D06E4;
        }
        *(qword *)(param_1 + 0x108) = CONCAT44(param_3,param_4);
      }
      *(qword *)(param_1 + 0x110) = (qword)param_6;
      uVar4 = 0;
      *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 0x80000000;
    }
    else {
      uVar4 = 0xfffffd3e;
    }
  }
  else {
    uVar4 = 0xfffffd3e;
  }
locret_F00D06E4:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4503 start=0xf00d06ec */

/* WARNING: Removing unreachable block (ram,0xf00d0728) */
/* WARNING: Removing unreachable block (ram,0xf00d0734) */
/* WARNING: Removing unreachable block (ram,0xf00d0710) */

undefined8 -[SCSIGeneric setController:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (param_3 == *(int *)(param_1 + 0x118)) {
    uVar2 = 0;
  }
  else {
    _objc_msgSend(param_1,paClearreservati);
    puVar1 = (undefined *)((int)register0x00000038 + -0x20);
    _sprintf(puVar1,&aScD,param_3);
    _IOGetObjectForDeviceName(puVar1,(undefined *)((int)register0x00000038 + -0x24));
    uVar2 = 0xfffffd40;
    if (puVar1 == (undefined *)0x0) {
      *(int *)(param_1 + 0x118) = param_3;
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)((int)register0x00000038 + -0x24);
      *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0x7fffffff;
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4504 start=0xf00d0770 */

sqword -[SCSIGeneric enableAutoSense](int param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x80000000;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4505 start=0xf00d078c */

sqword -[SCSIGeneric disableAutoSense](int param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0x7fffffff;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4506 start=0xf00d07a8 */

undefined8 -[SCSIGeneric autoSense](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(uint *)(param_1 + 0x11c) >> 0x1f);
}
/* GHIDRADEC_FUNCTION index=4507 start=0xf00d07bc */

/* WARNING: Removing unreachable block (ram,0xf00d08f0) */
/* WARNING: Removing unreachable block (ram,0xf00d08a8) */
/* WARNING: Removing unreachable block (ram,0xf00d08d0) */
/* WARNING: Removing unreachable block (ram,0xf00d0908) */
/* WARNING: Removing unreachable block (ram,0xf00d0834) */

undefined8
-[SCSIGeneric executeRequest:buffer:client:senseBuf:]
          (int param_1,undefined4 param_2,byte *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar2;
  undefined8 in_l4_5;
  undefined4 uVar3;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (((*(uint *)(param_1 + 0x124) & 0x80000000) != 0) && (*(int *)(param_1 + 0x108) == 0)) {
    if ((uint)*param_3 != *(uint *)(param_1 + 0x10c)) {
      iVar4 = 7;
      goto locret_F00D0910;
    }
    if ((*(int *)(param_1 + 0x110) == 0) && ((uint)param_3[1] == *(uint *)(param_1 + 0x114))) {
      iVar4 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar4,paExecuterequest_0,param_3,param_4,param_5);
      if (iVar4 == 2) {
        *param_6 = *(undefined4 *)(param_3 + 0x40);
        param_6[1] = *(undefined4 *)(param_3 + 0x44);
        param_6[2] = *(undefined4 *)(param_3 + 0x48);
        param_6[3] = *(undefined4 *)(param_3 + 0x4c);
        param_6[4] = *(undefined4 *)(param_3 + 0x50);
        param_6[5] = *(undefined4 *)(param_3 + 0x54);
        param_6[6] = *(undefined4 *)(param_3 + 0x58);
      }
      else if ((iVar4 == 3) && ((*(uint *)(param_1 + 0x11c) & 0x80000000) != 0)) {
        iVar1 = param_1;
        _objc_msgSend(param_1,paGetsense,param_6);
        if (param_1 == 0) {
          iVar4 = 2;
        }
        else {
          iVar4 = iVar1;
          _objc_msgSend(iVar1,paName);
          uVar3 = (undefined4)*(undefined8 *)(iVar4 + 0x108);
          uVar2 = (undefined4)*(undefined8 *)(iVar4 + 0x110);
          iVar4 = 3;
          _IOFindNameForValue(param_1,_IOScStatusStrings);
          _IOLog(aSRequestSenseO,iVar1,uVar3,uVar2,param_1);
        }
      }
      goto locret_F00D0910;
    }
  }
  iVar4 = 7;
locret_F00D0910:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=4508 start=0xf00d0918 */

/* WARNING: Removing unreachable block (ram,0xf00d0a50) */
/* WARNING: Removing unreachable block (ram,0xf00d0a08) */
/* WARNING: Removing unreachable block (ram,0xf00d0a30) */
/* WARNING: Removing unreachable block (ram,0xf00d0a68) */
/* WARNING: Removing unreachable block (ram,0xf00d0994) */

undefined8
-[SCSIGeneric executeSCSI3Request:buffer:client:senseBuf:]
          (int param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5,
          int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar3;
  undefined8 in_l4_5;
  undefined4 uVar4;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar5;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if ((*(uint *)(param_1 + 0x124) & 0x80000000) != 0) {
    if (*param_3 != *(int *)(param_1 + 0x108)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[1] != *(int *)(param_1 + 0x10c)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[2] != *(int *)(param_1 + 0x110)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[3] == *(int *)(param_1 + 0x114)) {
      iVar5 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar5,paExecutescsi3re_0,param_3,param_4,param_5);
      if (iVar5 == 2) {
        *param_6 = param_3[0x14];
        param_6[1] = param_3[0x15];
        param_6[2] = param_3[0x16];
        param_6[3] = param_3[0x17];
        param_6[4] = param_3[0x18];
        param_6[5] = param_3[0x19];
        param_6[6] = param_3[0x1a];
      }
      else if ((iVar5 == 3) && ((*(uint *)(param_1 + 0x11c) & 0x80000000) != 0)) {
        iVar1 = param_1;
        _objc_msgSend(param_1,paGetsense,param_6);
        if (iVar1 == 0) {
          iVar5 = 2;
        }
        else {
          iVar2 = param_1;
          _objc_msgSend(param_1,paName);
          uVar4 = (undefined4)*(undefined8 *)(param_1 + 0x108);
          uVar3 = (undefined4)*(undefined8 *)(param_1 + 0x110);
          iVar5 = 3;
          _IOFindNameForValue(iVar1,_IOScStatusStrings);
          _IOLog(aSRequestSenseO,iVar2,uVar4,uVar3,iVar1);
        }
      }
      goto locret_F00D0A70;
    }
  }
  iVar5 = 7;
locret_F00D0A70:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=4509 start=0xf00d0a78 */

/* WARNING: Removing unreachable block (ram,0xf00d0a84) */

undefined8 -[SCSIGeneric resetSCSIBus](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  uVar1 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar1,paResetscsibus);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4510 start=0xf00d0a94 */

undefined8 -[SCSIGeneric controller](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x128));
}
/* GHIDRADEC_FUNCTION index=4511 start=0xf00d0aa4 */

/* WARNING: Removing unreachable block (ram,0xf00d0b98) */
/* WARNING: Removing unreachable block (ram,0xf00d0ae8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ad4) */
/* WARNING: Removing unreachable block (ram,0xf00d0b80) */
/* WARNING: Removing unreachable block (ram,0xf00d0be8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ac4) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d0b98 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[SCSIGeneric getSense:](void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 in_o0_1;
  undefined8 uVar3;
  qword qVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 in_o2_3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined4 uVar8;
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
  
  puVar6 = (undefined4 *)((qword)in_o2_3 >> 0x20);
  puVar1 = (undefined4 *)((qword)in_o0_1 >> 0x20);
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
  puVar7 = (uint *)((int)register0x00000038 + -0x6c);
  _objc_msgSend();
  _bzero((undefined *)((int)register0x00000038 + -0x70));
  _objc_msgSend();
  *(char *)((int)register0x00000038 + -0x70) = (char)*(undefined8 *)(puVar1 + 0x42);
  uVar3 = *(undefined8 *)(puVar1 + 0x44);
  *(char *)((int)register0x00000038 + -0x6f) = (char)uVar3;
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  if (*(uint *)((int)register0x00000038 + -0x78) < 2) {
    uVar3 = 0x1c00000000;
  }
  *(int *)((int)register0x00000038 + -0x5c) = (int)((qword)uVar3 >> 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x58) = 10;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) & 0x7fffffff;
  *(undefined *)puVar7 = 3;
  uVar3 = *(undefined8 *)(puVar1 + 0x44);
  qVar4 = CONCAT44((int)uVar3,*puVar7) & 0x7ff1fffff;
  iVar2 = (int)(qVar4 >> 0x20);
  uVar5 = (uint)qVar4;
  *puVar7 = uVar5 | iVar2 << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x1c;
  uVar8 = puVar1[0x4a];
  _IOVmTaskSelf();
  _objc_msgSend(uVar8,uVar5,(undefined *)((int)register0x00000038 + -0x70),(int)uVar3,iVar2);
  if (iVar2 == 0) {
    *puVar6 = *puVar1;
    puVar6[1] = puVar1[1];
    puVar6[2] = puVar1[2];
    puVar6[3] = puVar1[3];
    puVar6[4] = puVar1[4];
    puVar6[5] = puVar1[5];
    puVar6[6] = puVar1[6];
  }
  _IOFree();
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=4512 start=0xf00d0bf8 */

/* WARNING: Removing unreachable block (ram,0xf00d0c64) */
/* WARNING: Removing unreachable block (ram,0xf00d0c30) */
/* WARNING: Removing unreachable block (ram,0xf00d0c58) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d0c30 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[SCSIGeneric clearReservation](int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
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
  if (*(int *)(param_1 + 0x120) == 0) {
    uVar2 = *(uint *)(param_1 + 0x124);
  }
  else {
    if (*(int *)(param_1 + 0x124) < 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paReleasescsi3ta,
                    (int)((qword)*(undefined8 *)(param_1 + 0x108) >> 0x20),
                    (int)*(undefined8 *)(param_1 + 0x108),
                    (int)((qword)*(undefined8 *)(param_1 + 0x110) >> 0x20));
      *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0x7fffffff;
    }
    else {
      iVar1 = param_1;
      _objc_msgSend(param_1,paName);
      _IOLog(aSClearreservat,iVar1);
    }
    *(undefined4 *)(param_1 + 0x120) = 0;
    uVar2 = *(uint *)(param_1 + 0x124);
  }
  *(uint *)(param_1 + 0x124) = uVar2 & 0x7fffffff;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4513 start=0xf00d0c88 */

sqword -[IODisplay allocateConsoleInfo](undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4514 start=0xf00d0c94 */

/* WARNING: Removing unreachable block (ram,0xf00d0cac) */
/* WARNING: Removing unreachable block (ram,0xf00d0ca0) */

undefined8 -[IODisplay devicePort](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4515 start=0xf00d0cbc */

undefined8 -[IODisplay hideCursor:](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4516 start=0xf00d0cc8 */

undefined8 -[IODisplay moveCursor:frame:token:](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4517 start=0xf00d0cd4 */

undefined8 -[IODisplay showCursor:frame:token:](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4518 start=0xf00d0ce0 */

undefined8 -[IODisplay setBrightness:token:](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4519 start=0xf00d0cec */

undefined8 -[IODisplay displayInfo](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1 + 0x128);
}
/* GHIDRADEC_FUNCTION index=4520 start=0xf00d0cf8 */

undefined8 -[IODisplay token](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x1b0));
}
/* GHIDRADEC_FUNCTION index=4521 start=0xf00d0d08 */

undefined8 -[IODisplay setToken:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x1b0) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4522 start=0xf00d0d18 */

/* WARNING: Removing unreachable block (ram,0xf00d0d6c) */
/* WARNING: Removing unreachable block (ram,0xf00d0d40) */
/* WARNING: Removing unreachable block (ram,0xf00d0db4) */
/* WARNING: Removing unreachable block (ram,0xf00d0d78) */
/* WARNING: Removing unreachable block (ram,0xf00d0d28) */

undefined8
-[IODisplay getIntValues:forParameter:count:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *param_5;
  iVar1 = param_4;
  _strcmp(param_4,aIogetdisplaypo);
  if ((iVar1 == 0) || (iVar1 = param_4, _strcmp(param_4,aIoDisplayGetpo), iVar1 == 0)) {
    if (iVar3 == 0) {
      puVar2 = (undefined *)0xfffffd3e;
    }
    else {
      _objc_msgSend(param_1,paDeviceport_0);
      _IOConvertPort();
      *param_3 = param_1;
      *param_5 = 1;
      puVar2 = (undefined *)0x0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421b8;
    _objc_msgSendSuper(puVar2,paGetintvaluesFo_0,param_3,param_4,param_5);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4523 start=0xf00d0dc8 */

/* WARNING: Removing unreachable block (ram,0xf00d0e28) */
/* WARNING: Removing unreachable block (ram,0xf00d0df8) */
/* WARNING: Removing unreachable block (ram,0xf00d0de0) */
/* WARNING: Removing unreachable block (ram,0xf00d0e0c) */
/* WARNING: Removing unreachable block (ram,0xf00d0e60) */
/* WARNING: Removing unreachable block (ram,0xf00d0dd4) */

undefined8
-[IODisplay getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar1 == 0) {
loc_F00D0E3C:
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    _objc_msgSend();
    if (iVar1 != 0) {
      iVar2 = iVar1;
      _strlen();
      if (iVar2 + 1U <= *param_5) {
        _strcpy(param_3,iVar1);
        *param_5 = iVar2 + 1U;
        puVar3 = (undefined *)0x0;
        goto locret_F00D0E6C;
      }
      goto loc_F00D0E3C;
    }
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421b8;
  _objc_msgSendSuper(puVar3,paGetcharvaluesF_0,param_3,param_4,param_5);
locret_F00D0E6C:
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4524 start=0xf00d0e74 */

/* WARNING: Removing unreachable block (ram,0xf00d1384) */
/* WARNING: Removing unreachable block (ram,0xf00d1518) */
/* WARNING: Removing unreachable block (ram,0xf00d14bc) */
/* WARNING: Removing unreachable block (ram,0xf00d1418) */
/* WARNING: Removing unreachable block (ram,0xf00d13dc) */
/* WARNING: Removing unreachable block (ram,0xf00d1358) */
/* WARNING: Removing unreachable block (ram,0xf00d1278) */
/* WARNING: Removing unreachable block (ram,0xf00d11b4) */
/* WARNING: Removing unreachable block (ram,0xf00d112c) */
/* WARNING: Removing unreachable block (ram,0xf00d10a4) */
/* WARNING: Removing unreachable block (ram,0xf00d1070) */
/* WARNING: Removing unreachable block (ram,0xf00d1034) */
/* WARNING: Removing unreachable block (ram,0xf00d0f1c) */
/* WARNING: Removing unreachable block (ram,0xf00d0eb8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ee4) */
/* WARNING: Removing unreachable block (ram,0xf00d0f48) */
/* WARNING: Removing unreachable block (ram,0xf00d1060) */
/* WARNING: Removing unreachable block (ram,0xf00d108c) */
/* WARNING: Removing unreachable block (ram,0xf00d10d0) */
/* WARNING: Removing unreachable block (ram,0xf00d1158) */
/* WARNING: Removing unreachable block (ram,0xf00d11e0) */
/* WARNING: Removing unreachable block (ram,0xf00d12a4) */
/* WARNING: Removing unreachable block (ram,0xf00d13b0) */
/* WARNING: Removing unreachable block (ram,0xf00d1400) */
/* WARNING: Removing unreachable block (ram,0xf00d1460) */
/* WARNING: Removing unreachable block (ram,0xf00d14f4) */
/* WARNING: Removing unreachable block (ram,0xf00d1550) */
/* WARNING: Removing unreachable block (ram,0xf00d1498) */
/* WARNING: Removing unreachable block (ram,0xf00d0e8c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d1550 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventDriver getIntValues:forParameter:count:](int *param_1,undefined4 param_2,uint *param_3)

{
  undefined8 in_o0_1;
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 **ppuVar4;
  undefined4 **ppuVar5;
  int iVar6;
  undefined4 unaff_l1;
  uint uVar7;
  int iVar8;
  int iVar9;
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
  undefined4 auStack_20 [8];
  
  iVar2 = (int)((qword)in_o0_1 >> 0x20);
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
  iVar8 = -0x2c2;
  uVar7 = *param_3;
  *(undefined4 *)((int)register0x00000038 + -0x38) = 0;
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 < 2) goto loc_F00D1560;
    *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
    _objc_msgSend();
    *param_1 = (int)sRam000001f8;
    param_1[1] = (int)sRam000001fa;
    goto loc_F00D1498;
  }
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x38) = 1;
      iVar8 = 0;
      *param_1 = iRam00000160;
    }
    goto loc_F00D1560;
  }
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 < 6) goto loc_F00D1560;
    *(undefined4 *)((int)register0x00000038 + -0x38) = 6;
    _objc_msgSend();
    if (cRam000001d2 == '\x01') {
      iVar2 = (uint)*(word *)(iRam00000168 + 0x4c) << 0x10;
      uVar7 = iVar2 >> 0x10;
      *(uint *)((int)register0x00000038 + -0x18) = uVar7 >> 8 | (iVar2 >> 0x1f) << 0x18;
      *(uint *)((int)register0x00000038 + -0x14) = uVar7 << 0x18;
    }
    else {
      *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
    }
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) =
         *(undefined8 *)((int)register0x00000038 + -0x18);
    do {
      *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) = uRam000001d8;
    do {
      *(undefined4 *)((int)param_1 + iVar2 + 8) = *(undefined4 *)(puVar1 + -8);
      in_o0_1 = uRam000001e8;
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) = uRam000001e8;
    do {
      *(undefined4 *)((int)param_1 + iVar2 + 0x10) = *(undefined4 *)(puVar1 + -8);
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
  }
  else {
    _strcmp();
    if (iVar2 == 0) {
      if (uVar7 < 3) goto loc_F00D1560;
      *(undefined4 *)((int)register0x00000038 + -0x38) = 3;
      _objc_msgSend();
      _objc_msgSend(0);
      *param_1 = 0;
      param_1[1] = iRam000001c4;
      _objc_msgSend();
      param_1[2] = 0;
    }
    else {
      _strcmp();
      if (iVar2 == 0) {
        if (uVar7 < 2) goto loc_F00D1560;
        *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
        _objc_msgSend();
        puVar1 = (undefined *)((int)register0x00000038 + -0x18);
        iVar2 = 0;
        *(qword *)((int)register0x00000038 + -0x18) =
             CONCAT44(uRam000001bc >> 8,uRam000001bc << 0x18);
        *(qword *)((int)register0x00000038 + -0x20) =
             CONCAT44(uRam000001bc >> 8,uRam000001bc << 0x18);
        do {
          *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
          puVar1 = puVar1 + 4;
          iVar2 = iVar2 + 4;
        } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
      }
      else {
        _strcmp();
        if (iVar2 == 0) {
          if (uVar7 < 2) goto loc_F00D1560;
          *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
          _objc_msgSend();
          puVar1 = (undefined *)((int)register0x00000038 + -0x18);
          iVar2 = 0;
          *(qword *)((int)register0x00000038 + -0x18) =
               CONCAT44(uRam000001a0 >> 8,uRam000001a0 << 0x18);
          *(qword *)((int)register0x00000038 + -0x20) =
               CONCAT44(uRam000001a0 >> 8,uRam000001a0 << 0x18);
          do {
            *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
            puVar1 = puVar1 + 4;
            iVar2 = iVar2 + 4;
          } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
        }
        else {
          _strcmp();
          if (iVar2 == 0) {
            if (uVar7 < 2) goto loc_F00D1560;
            *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
            _objc_msgSend();
            uVar7 = uRam000001a0;
            if (cRam000001d2 == '\x01') {
              if (cRam000001d3 == '\0') {
                uVar7 = iRam000001a4 - *(int *)(iRam00000168 + 0x10);
                goto loc_F00D1224;
              }
              *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
            }
            else {
loc_F00D1224:
              *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(uVar7 >> 8,uVar7 << 0x18);
            }
            puVar1 = (undefined *)((int)register0x00000038 + -0x18);
            iVar2 = 0;
            in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x18);
            *(undefined8 *)((int)register0x00000038 + -0x20) = in_o0_1;
            do {
              *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
              puVar1 = puVar1 + 4;
              iVar2 = iVar2 + 4;
            } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
          }
          else {
            _strcmp();
            if (iVar2 == 0) {
              if (uVar7 < 2) goto loc_F00D1560;
              *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
              _objc_msgSend();
              if (cRam000001d2 == '\x01') {
                if (cRam000001d3 == '\0') {
                  uVar7 = *(uint *)(iRam00000168 + 0x10);
                  uVar3 = uRam000001a0;
                }
                else {
                  uVar3 = *(uint *)(iRam00000168 + 0x10);
                  uVar7 = uRam000001a0;
                }
                uVar3 = uVar3 - (iRam000001a4 - uVar7);
                *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(uVar3 >> 8,uVar3 * 0x1000000)
                ;
              }
              else {
                *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
              }
              puVar1 = (undefined *)((int)register0x00000038 + -0x18);
              iVar2 = 0;
              in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x18);
              *(undefined8 *)((int)register0x00000038 + -0x20) = in_o0_1;
              do {
                *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
                puVar1 = puVar1 + 4;
                iVar2 = iVar2 + 4;
              } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
            }
            else {
              _strcmp();
              if (iVar2 == 0) {
                if (uVar7 < 2) goto loc_F00D1560;
                *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
                _objc_msgSend();
                *param_1 = (int)sRam000001b0;
                param_1[1] = (int)sRam000001b2;
              }
              else {
                _strcmp();
                if (iVar2 == 0) {
                  if (uVar7 == 0) goto loc_F00D1560;
                  *(undefined4 *)((int)register0x00000038 + -0x38) = 1;
                  _objc_msgSend();
                  *param_1 = (int)cRam000001d3;
                }
                else {
                  _strcmp();
                  if (iVar2 != 0) {
                    *(uint *)((int)register0x00000038 + -0x38) = *param_3;
                    _objc_msgSend();
                    iVar6 = *(int *)(iVar2 + 0x174);
                    do {
                      iVar9 = iVar8;
                      if (iVar2 + 0x174 == iVar6) break;
                      iVar6 = *(int *)(iVar6 + 4);
                      _objc_msgSend();
                      iVar9 = iVar2;
                    } while (iVar2 == -0x2c2);
                    _objc_msgSend();
                    iVar8 = iVar9;
                    if (iVar9 == -0x2c2) {
                      *(int *)((int)register0x00000038 + -0x10) = iVar2;
                      *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                      _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),(int)in_o0_1
                                         ,param_1,param_2,
                                         (undefined *)((int)register0x00000038 + -0x38));
                      iVar8 = iVar2;
                    }
                    goto loc_F00D1560;
                  }
                  _objc_msgSend();
                  ppuVar4 = puRam00000174;
                  if (puRam00000174 != &puRam00000174) {
                    do {
                      if (uVar7 < 4) break;
                      *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
                      ppuVar5 = (undefined4 **)ppuVar4[1];
                      _objc_msgSend(*ppuVar4,(int)in_o0_1,
                                    param_1 + *(int *)((int)register0x00000038 + -0x38),param_2,
                                    (undefined *)((int)register0x00000038 + -0x34));
                      if ((int)((qword)in_o0_1 >> 0x20) == 0) {
                        in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x38);
                        uVar7 = uVar7 - (int)in_o0_1;
                        *(int *)((int)register0x00000038 + -0x38) =
                             (int)((qword)in_o0_1 >> 0x20) + (int)in_o0_1;
                      }
                      ppuVar4 = ppuVar5;
                    } while (ppuVar5 != &puRam00000174);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
loc_F00D1498:
  _objc_msgSend((int)((qword)in_o0_1 >> 0x20));
  iVar8 = 0;
loc_F00D1560:
  *param_3 = (uint)((qword)in_o0_1 >> 0x20);
  return iVar8;
}
/* GHIDRADEC_FUNCTION index=4525 start=0xf00d156c */

/* WARNING: Removing unreachable block (ram,0xf00d16e8) */
/* WARNING: Removing unreachable block (ram,0xf00d17cc) */
/* WARNING: Removing unreachable block (ram,0xf00d1810) */
/* WARNING: Removing unreachable block (ram,0xf00d1854) */
/* WARNING: Removing unreachable block (ram,0xf00d1a04) */
/* WARNING: Removing unreachable block (ram,0xf00d1b50) */
/* WARNING: Removing unreachable block (ram,0xf00d1b00) */
/* WARNING: Removing unreachable block (ram,0xf00d1ad0) */
/* WARNING: Removing unreachable block (ram,0xf00d1bd4) */
/* WARNING: Removing unreachable block (ram,0xf00d1b74) */
/* WARNING: Removing unreachable block (ram,0xf00d1a68) */
/* WARNING: Removing unreachable block (ram,0xf00d1a18) */
/* WARNING: Removing unreachable block (ram,0xf00d19c4) */
/* WARNING: Removing unreachable block (ram,0xf00d193c) */
/* WARNING: Removing unreachable block (ram,0xf00d1908) */
/* WARNING: Removing unreachable block (ram,0xf00d18dc) */
/* WARNING: Removing unreachable block (ram,0xf00d1868) */
/* WARNING: Removing unreachable block (ram,0xf00d17e0) */
/* WARNING: Removing unreachable block (ram,0xf00d1734) */
/* WARNING: Removing unreachable block (ram,0xf00d1690) */
/* WARNING: Removing unreachable block (ram,0xf00d1634) */
/* WARNING: Removing unreachable block (ram,0xf00d15e8) */
/* WARNING: Removing unreachable block (ram,0xf00d15b8) */
/* WARNING: Removing unreachable block (ram,0xf00d15a4) */
/* WARNING: Removing unreachable block (ram,0xf00d15d8) */
/* WARNING: Removing unreachable block (ram,0xf00d1620) */
/* WARNING: Removing unreachable block (ram,0xf00d1648) */
/* WARNING: Removing unreachable block (ram,0xf00d16cc) */
/* WARNING: Removing unreachable block (ram,0xf00d179c) */
/* WARNING: Removing unreachable block (ram,0xf00d1824) */
/* WARNING: Removing unreachable block (ram,0xf00d18b4) */
/* WARNING: Removing unreachable block (ram,0xf00d18ec) */
/* WARNING: Removing unreachable block (ram,0xf00d192c) */
/* WARNING: Removing unreachable block (ram,0xf00d1988) */
/* WARNING: Removing unreachable block (ram,0xf00d19d4) */
/* WARNING: Removing unreachable block (ram,0xf00d1a40) */
/* WARNING: Removing unreachable block (ram,0xf00d1a80) */
/* WARNING: Removing unreachable block (ram,0xf00d1bac) */
/* WARNING: Removing unreachable block (ram,0xf00d1c08) */
/* WARNING: Removing unreachable block (ram,0xf00d1ae0) */
/* WARNING: Removing unreachable block (ram,0xf00d1b18) */
/* WARNING: Removing unreachable block (ram,0xf00d19f0) */
/* WARNING: Removing unreachable block (ram,0xf00d1840) */
/* WARNING: Removing unreachable block (ram,0xf00d17fc) */
/* WARNING: Removing unreachable block (ram,0xf00d17b8) */
/* WARNING: Removing unreachable block (ram,0xf00d1750) */
/* WARNING: Removing unreachable block (ram,0xf00d1b64) */
/* WARNING: Removing unreachable block (ram,0xf00d157c) */

undefined8 -[EventDriver setIntValues:forParameter:count:](undefined *param_1,undefined4 param_2)

{
  undefined (*pauVar1) [30];
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined (*pauVar6) [25];
  undefined4 *puVar7;
  int iVar8;
  undefined8 in_o2_3;
  uint uVar9;
  undefined8 in_o4_5;
  undefined4 unaff_l0;
  int *piVar10;
  undefined4 unaff_l1;
  undefined *puVar11;
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
  undefined4 auStack_38 [14];
  
  iVar8 = (int)((qword)in_o4_5 >> 0x20);
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
  puVar7 = (undefined4 *)((qword)in_o2_3 >> 0x20);
  iVar4 = (int)in_o2_3;
  puVar11 = (undefined *)0xfffffd3e;
  iVar2 = iVar4;
  _strcmp(iVar4,aEvSetscreen);
  if (iVar2 == 0) {
    if (iVar8 == 7) {
      _objc_msgSend(param_1,paEvsetscreen,puVar7);
      puVar11 = param_1;
    }
    goto locret_F00D1C14;
  }
  iVar2 = iVar4;
  _strcmp(iVar4,aEvStartcursor);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,paStartcursor);
    puVar11 = (undefined *)0x0;
    goto locret_F00D1C14;
  }
  iVar2 = iVar4;
  _strcmp(iVar4,aEvMousepositio);
  if (iVar2 == 0) {
    if (iVar8 != 2) goto locret_F00D1C14;
    *(sword *)((int)register0x00000038 + -0x18) = (sword)*puVar7;
    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar7[1];
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    _objc_msgSend(param_1,paSetcursorposit,(undefined *)((int)register0x00000038 + -0x18));
    param_1 = *(undefined **)(param_1 + 0x110);
    pauVar6 = paUnlock;
  }
  else {
    iVar2 = iVar4;
    _strcmp(iVar4,aEvsSetwaitthre);
    if (iVar2 == 0) {
      puVar11 = (undefined *)((int)register0x00000038 + -0x30);
      iVar8 = 0;
      do {
        *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
        puVar11 = puVar11 + 4;
        iVar8 = iVar8 + 4;
      } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
      uVar3 = *(undefined4 *)(param_1 + 0x110);
      *(undefined8 *)((int)register0x00000038 + -0x30) =
           *(undefined8 *)((int)register0x00000038 + -0x38);
      _objc_msgSend(uVar3,paLock);
      if (param_1[0x1d2] == '\0') {
loc_F00D1B58:
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar6 = paUnlock;
      }
      else {
        *(word *)(*(int *)(param_1 + 0x168) + 0x4c) =
             (word)((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8) |
             (word)(byte)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18);
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar6 = paUnlock;
      }
    }
    else {
      iVar2 = iVar4;
      _strcmp(iVar4,aEvsSetwaitsust);
      if (iVar2 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
        pauVar6 = paUnlock;
        puVar11 = (undefined *)((int)register0x00000038 + -0x30);
        iVar8 = 0;
        do {
          *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
          puVar11 = puVar11 + 4;
          iVar8 = iVar8 + 4;
        } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
        *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)((int)register0x00000038 + -0x38);
        param_1 = *(undefined **)(param_1 + 0x110);
      }
      else {
        iVar2 = iVar4;
        _strcmp(iVar4,aEvsSetwaitfram);
        if (iVar2 == 0) {
          _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
          pauVar6 = paUnlock;
          puVar11 = (undefined *)((int)register0x00000038 + -0x30);
          iVar8 = 0;
          do {
            *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
            puVar11 = puVar11 + 4;
            iVar8 = iVar8 + 4;
          } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
          *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)((int)register0x00000038 + -0x38);
          param_1 = *(undefined **)(param_1 + 0x110);
        }
        else {
          iVar2 = iVar4;
          _strcmp(iVar4,aEvsSetbrightne);
          if (iVar2 == 0) {
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
            _objc_msgSend(param_1,paSetbrightness,*puVar7);
            param_1 = *(undefined **)(param_1 + 0x110);
            pauVar6 = paUnlock;
          }
          else {
            iVar2 = iVar4;
            _strcmp(iVar4,aEvsSetattenuat);
            if (iVar2 == 0) {
              _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
              _objc_msgSend(param_1,paSetuseraudiovo,*puVar7);
              param_1 = *(undefined **)(param_1 + 0x110);
              pauVar6 = paUnlock;
            }
            else {
              iVar2 = iVar4;
              _strcmp(iVar4,aEvsSetautodimb);
              if (iVar2 == 0) {
                _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                _objc_msgSend(param_1,paSetautodimbrig,*puVar7);
                param_1 = *(undefined **)(param_1 + 0x110);
                pauVar6 = paUnlock;
              }
              else {
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetclicktim);
                if (iVar2 == 0) {
                  puVar11 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar8 = 0;
                  do {
                    *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
                    puVar11 = puVar11 + 4;
                    iVar8 = iVar8 + 4;
                  } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar3 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar3,paLock);
                  pauVar6 = paUnlock;
                  *(uint *)(param_1 + 0x1bc) =
                       (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8 |
                       (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetclickspa);
                if (iVar2 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  *(sword *)(param_1 + 0x1b0) = (sword)*puVar7;
                  pauVar6 = paUnlock;
                  *(sword *)(param_1 + 0x1b2) = (sword)puVar7[1];
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetautodimt);
                if (iVar2 == 0) {
                  puVar11 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar8 = 0;
                  do {
                    *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
                    puVar11 = puVar11 + 4;
                    iVar8 = iVar8 + 4;
                  } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar3 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar3,paLock);
                  pauVar6 = paUnlock;
                  uVar9 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) <<
                          8 | (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  *(uint *)(param_1 + 0x1a4) =
                       (*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) + uVar9;
                  *(uint *)(param_1 + 0x1a0) = uVar9;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetautodims);
                if (iVar2 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  _objc_msgSend(param_1,paForceautodimst,(int)*(char *)((int)puVar7 + 3));
                  param_1 = *(undefined **)(param_1 + 0x110);
                  pauVar6 = paUnlock;
                }
                else {
                  iVar2 = iVar4;
                  _strcmp(iVar4,aEvsResetmouse);
                  pauVar6 = (undefined (*) [25])paResetmousepara;
                  if ((iVar2 != 0) &&
                     (iVar2 = iVar4, _strcmp(iVar4,aEvsResetkeyboa), pauVar6 = paResetkeyboardp,
                     iVar2 != 0)) {
                    iVar2 = iVar4;
                    _strcmp(iVar4,aEvLlpostevent);
                    if ((iVar2 != 0) && (iVar2 = iVar4, _strcmp(iVar4,aEvPointerllpos), iVar2 != 0))
                    {
                      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
                      piVar10 = *(int **)(param_1 + 0x174);
                      if ((int *)(param_1 + 0x174) == piVar10) {
                        uVar3 = *(undefined4 *)(param_1 + 0x170);
                      }
                      else {
                        do {
                          puVar5 = (undefined *)*piVar10;
                          piVar10 = (int *)piVar10[1];
                          _objc_msgSend(puVar5,paSetintvaluesFo_0,puVar7);
                          if (puVar5 != (undefined *)0xfffffd3e) {
                            puVar11 = puVar5;
                          }
                        } while ((int *)(param_1 + 0x174) != piVar10);
                        uVar3 = *(undefined4 *)(param_1 + 0x170);
                      }
                      _objc_msgSend(uVar3,paUnlock);
                      puVar5 = (undefined *)((int)register0x00000038 + -0x10);
                      if (puVar11 == (undefined *)0xfffffd3e) {
                        *(undefined **)((int)register0x00000038 + -0x10) = param_1;
                        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                        _objc_msgSendSuper(puVar5,paSetintvaluesFo_0,puVar7);
                        puVar11 = puVar5;
                      }
                      goto locret_F00D1C14;
                    }
                    if (iVar8 != 6) goto locret_F00D1C14;
                    *(sword *)((int)register0x00000038 + -0x18) = (sword)puVar7[1];
                    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar7[2];
                    *(undefined4 *)((int)register0x00000038 + -0x28) = puVar7[3];
                    *(undefined4 *)((int)register0x00000038 + -0x24) = puVar7[4];
                    *(undefined4 *)((int)register0x00000038 + -0x20) = puVar7[5];
                    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                    _strcmp(iVar4,aEvPointerllpos);
                    if (iVar4 == 0) {
                      _objc_msgSend(param_1,paSetcursorposit,
                                    (undefined *)((int)register0x00000038 + -0x18));
                    }
                    pauVar1 = paPosteventAtAtt;
                    uVar3 = *puVar7;
                    _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x38));
                    _objc_msgSend(param_1,pauVar1,uVar3);
                    goto loc_F00D1B58;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  _objc_msgSend(param_1,pauVar6);
  puVar11 = (undefined *)0x0;
locret_F00D1C14:
  return CONCAT44(param_2,puVar11);
}
/* GHIDRADEC_FUNCTION index=4526 start=0xf00d1c1c */

/* WARNING: Removing unreachable block (ram,0xf00d1cc8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ca4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e64) */
/* WARNING: Removing unreachable block (ram,0xf00d1e30) */
/* WARNING: Removing unreachable block (ram,0xf00d1e04) */
/* WARNING: Removing unreachable block (ram,0xf00d1ddc) */
/* WARNING: Removing unreachable block (ram,0xf00d1d50) */
/* WARNING: Removing unreachable block (ram,0xf00d1d70) */
/* WARNING: Removing unreachable block (ram,0xf00d1d18) */
/* WARNING: Removing unreachable block (ram,0xf00d1d80) */
/* WARNING: Removing unreachable block (ram,0xf00d1d9c) */
/* WARNING: Removing unreachable block (ram,0xf00d1df4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e18) */
/* WARNING: Removing unreachable block (ram,0xf00d1e44) */
/* WARNING: Removing unreachable block (ram,0xf00d1c98) */
/* WARNING: Removing unreachable block (ram,0xf00d1cb4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e80) */
/* WARNING: Removing unreachable block (ram,0xf00d1c4c) */

undefined8 sub_F00D1C1C(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  uint uVar8;
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
  bool bVar9;
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
  bVar1 = true;
  puVar7 = (undefined *)0x200;
  puVar5 = (undefined *)((int)register0x00000038 + -0x208);
  uVar8 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(param_1 + 0x148);
    *(undefined **)(puVar5 + 4) = puVar7;
    puVar3 = puVar5;
    _msg_receive(puVar5,0x1000,0);
    if (puVar3 == (undefined *)0xffffff36) {
      bVar1 = false;
loc_F00D1E74:
      bVar9 = !bVar1;
    }
    else if ((int)puVar3 < -0xc9) {
      if (puVar3 == (undefined *)0xffffff34) {
        if ((undefined *)0x200 < puVar7) {
          _IOFree(puVar5,puVar7);
        }
        puVar7 = *(undefined **)(puVar5 + 4);
        puVar5 = puVar7;
        _IOMalloc();
        goto loc_F00D1E74;
      }
loc_F00D1CB4:
      iVar2 = param_1;
      _objc_msgSend(param_1,paName);
      _IOLog(aSErrorOnMsgRec,iVar2,puVar3);
      bVar9 = !bVar1;
    }
    else {
      if (puVar3 != (undefined *)0x0) goto loc_F00D1CB4;
      if (*(int *)(puVar5 + 0xc) == *(int *)(param_1 + 0x13c)) {
        bVar9 = !bVar1;
        if ((*(int *)(puVar5 + 0x1c) == *(int *)(param_1 + 0x144)) &&
           (bVar9 = !bVar1, *(int *)(puVar5 + 0x1c) != 0)) {
          _objc_msgSend(param_1,paEvcloseToken,*(undefined4 *)(param_1 + 0x134),
                        *(undefined4 *)(param_1 + 0x114));
          bVar9 = !bVar1;
        }
        goto loc_F00D1E78;
      }
      puVar3 = (undefined *)0x0;
      if (*(int *)(puVar5 + 0x14) == 1) {
        if (*(int *)(puVar5 + 0xc) == *(int *)(param_1 + 0x134)) {
          _objc_msgSend(param_1,paIoophandler,puVar5 + 0x1c);
          puVar3 = (undefined *)0x1;
        }
      }
      else {
        if (iVar6 == 0) {
          uVar8 = 0x1400;
          iVar6 = 0x1400;
          _IOMalloc();
        }
        puVar3 = puVar5;
        _Event_server(puVar5,iVar6);
      }
      iVar2 = param_1;
      if (puVar3 == (undefined *)0x0) {
        _objc_msgSend(param_1,paName);
        puVar3 = aSInvalidMessag;
        iVar4 = *(int *)(puVar5 + 0x14);
loc_F00D1E30:
        _IOLog(puVar3,iVar2,iVar4);
loc_F00D1E38:
        if (iVar6 != 0) {
          _IOFree(iVar6,uVar8);
          iVar6 = 0;
          uVar8 = 0;
        }
      }
      else {
        if (*(int *)(puVar5 + 0x10) == 0) goto loc_F00D1E38;
        if (iVar6 != 0) {
          if (uVar8 < *(uint *)(iVar6 + 4)) {
            iVar4 = param_1;
            _objc_msgSend(param_1,paName);
            _IOLog(aSReplyMsgOverf,iVar4,*(undefined4 *)(iVar6 + 4),uVar8);
          }
          iVar4 = iVar6;
          _msg_send(iVar6,0,0);
          if (iVar4 != 0) {
            _objc_msgSend(param_1,paName);
            puVar3 = aSErrorOnMsgSen;
            goto loc_F00D1E30;
          }
          goto loc_F00D1E38;
        }
      }
      bVar9 = !bVar1;
      if ((undefined *)0x200 < puVar7) {
        _IOFree(puVar5,puVar7);
        puVar7 = (undefined *)0x200;
        puVar5 = (undefined *)((int)register0x00000038 + -0x208);
        goto loc_F00D1E74;
      }
    }
loc_F00D1E78:
    if (bVar9) {
      _IOExitThread();
      return CONCAT44(param_2,param_1);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4527 start=0xf00d1e90 */

/* WARNING: Removing unreachable block (ram,0xf00d1ef8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ec8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ee0) */
/* WARNING: Removing unreachable block (ram,0xf00d1f08) */
/* WARNING: Removing unreachable block (ram,0xf00d1eb0) */

undefined8 +[EventDriver probe:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  if (dword_F012EEA8 == 0) {
    _objc_msgSend(param_1,paAlloc);
    dword_F012EEA8 = param_1;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    _objc_msgSend();
    _objc_msgSend(dword_F012EEA8,paSetname,&aEvent0);
    _objc_msgSend(dword_F012EEA8,paSetdevicekind,&aEvent);
    iVar1 = dword_F012EEA8;
    _objc_msgSend(dword_F012EEA8,paInit);
    uVar2 = (uint)(iVar1 != 0);
  }
  else {
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4528 start=0xf00d1f20 */

undefined8 +[EventDriver deviceStyle](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,2);
}
/* GHIDRADEC_FUNCTION index=4529 start=0xf00d1f2c */

undefined8 +[EventDriver instance](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,dword_F012EEA8);
}
/* GHIDRADEC_FUNCTION index=4530 start=0xf00d1f40 */

/* WARNING: Removing unreachable block (ram,0xf00d20d4) */
/* WARNING: Removing unreachable block (ram,0xf00d20bc) */
/* WARNING: Removing unreachable block (ram,0xf00d2064) */
/* WARNING: Removing unreachable block (ram,0xf00d2044) */
/* WARNING: Removing unreachable block (ram,0xf00d2024) */
/* WARNING: Removing unreachable block (ram,0xf00d2004) */
/* WARNING: Removing unreachable block (ram,0xf00d1ff4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fd4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fb8) */
/* WARNING: Removing unreachable block (ram,0xf00d1f9c) */
/* WARNING: Removing unreachable block (ram,0xf00d1f80) */
/* WARNING: Removing unreachable block (ram,0xf00d1f68) */
/* WARNING: Removing unreachable block (ram,0xf00d1f78) */
/* WARNING: Removing unreachable block (ram,0xf00d1f88) */
/* WARNING: Removing unreachable block (ram,0xf00d1fa4) */
/* WARNING: Removing unreachable block (ram,0xf00d1fc0) */
/* WARNING: Removing unreachable block (ram,0xf00d1fe8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ffc) */
/* WARNING: Removing unreachable block (ram,0xf00d2018) */
/* WARNING: Removing unreachable block (ram,0xf00d2038) */
/* WARNING: Removing unreachable block (ram,0xf00d2058) */
/* WARNING: Removing unreachable block (ram,0xf00d20a0) */
/* WARNING: Removing unreachable block (ram,0xf00d20c8) */
/* WARNING: Removing unreachable block (ram,0xf00d20f0) */
/* WARNING: Removing unreachable block (ram,0xf00d1f58) */

undefined8 -[EventDriver init](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined7 *puVar2;
  undefined7 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  undefined4 unaff_l0;
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
  
  puVar3 = paNxlock;
  puVar1 = paNew;
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
  puVar2 = paNxlock;
  _objc_msgSend(paNxlock,paNew);
  *(undefined7 **)(param_1 + 0x110) = puVar2;
  puVar2 = puVar3;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 0x170) = puVar2;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 0x214) = puVar3;
  _task_self();
  _port_allocate_EXTERNAL();
  if (puVar3 == (undefined7 *)0x0) {
    _task_self();
    _port_allocate_EXTERNAL();
    if (puVar3 == (undefined7 *)0x0) {
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar3 == (undefined7 *)0x0) {
        uVar4 = *(undefined4 *)(param_1 + 0x134);
        _IOGetKernPort();
        uVar5 = *(undefined4 *)(param_1 + 0x138);
        _ev_port_list = uVar4;
        _IOGetKernPort();
        iVar6 = *(int *)(param_1 + 0x13c);
        DAT_f010fa94 = uVar5;
        _IOGetKernPort();
        *(int *)(param_1 + 0x140) = iVar6;
        _task_self();
        _port_set_allocate_EXTERNAL();
        if (iVar6 == 0) {
          _task_self();
          _port_set_add_EXTERNAL();
          if (iVar6 == 0) {
            _task_self();
            _port_set_add_EXTERNAL();
            if (iVar6 == 0) {
              _task_self();
              _port_set_add_EXTERNAL();
              if (iVar6 == 0) {
                *(int *)(param_1 + 0x178) = param_1 + 0x174;
                *(int *)(param_1 + 0x174) = param_1 + 0x174;
                *(int *)((int)register0x00000038 + -0x10) = param_1;
                *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
                *(undefined2 *)(param_1 + 0x1a8) = 100;
                *(undefined2 *)(param_1 + 0x1aa) = 100;
                pcVar7 = sub_F00D1C1C;
                _IOForkThread(sub_F00D1C1C,param_1);
                _IOSetThreadPolicy();
                _IOSetThreadPriority(pcVar7,0x1c);
                if (*(char *)(param_1 + 0x108) == '\0') {
                  _objc_msgSend(param_1,paRegisterdevice);
                  *(undefined *)(param_1 + 0x108) = 1;
                }
              }
              else {
                param_1 = 0;
              }
            }
            else {
              param_1 = 0;
            }
          }
          else {
            param_1 = 0;
          }
        }
        else {
          param_1 = 0;
        }
      }
      else {
        param_1 = 0;
      }
    }
    else {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4531 start=0xf00d2108 */

/* WARNING: Removing unreachable block (ram,0xf00d217c) */
/* WARNING: Removing unreachable block (ram,0xf00d215c) */
/* WARNING: Removing unreachable block (ram,0xf00d214c) */
/* WARNING: Removing unreachable block (ram,0xf00d213c) */
/* WARNING: Removing unreachable block (ram,0xf00d212c) */
/* WARNING: Removing unreachable block (ram,0xf00d2124) */
/* WARNING: Removing unreachable block (ram,0xf00d2134) */
/* WARNING: Removing unreachable block (ram,0xf00d2144) */
/* WARNING: Removing unreachable block (ram,0xf00d2154) */
/* WARNING: Removing unreachable block (ram,0xf00d2170) */
/* WARNING: Removing unreachable block (ram,0xf00d2198) */
/* WARNING: Removing unreachable block (ram,0xf00d211c) */

undefined8 -[EventDriver free](int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
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
  _objc_msgSend(param_1,paEvcloseToken,*(undefined4 *)(param_1 + 0x134),
                *(undefined4 *)(param_1 + 0x114));
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_set_deallocate_EXTERNAL();
  puVar1 = paFree;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paFree);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
  _objc_msgSendSuper(puVar2,puVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4532 start=0xf00d21a8 */

/* WARNING: Removing unreachable block (ram,0xf00d221c) */
/* WARNING: Removing unreachable block (ram,0xf00d222c) */
/* WARNING: Removing unreachable block (ram,0xf00d21cc) */

undefined8
-[EventDriver evOpen:token:](int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
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
  uVar1 = 0;
  if (param_3 == *(int *)(param_1 + 0x134)) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    if (*(char *)(param_1 + 0x1d0) == '\x01') {
      uVar1 = 0xfffffd2b;
    }
    else {
      *(undefined *)(param_1 + 0x1d0) = 1;
      if (*(char *)(param_1 + 0x1d1) == '\0') {
        *(undefined *)(param_1 + 0x1d1) = 1;
        *(undefined4 *)(param_1 + 0x1cc) = 0x40;
        *(undefined4 *)(param_1 + 0x1c4) = 0x20;
      }
      _objc_msgSend(param_1,paSeteventport,param_4);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  }
  else {
    uVar1 = 0xfffffd3e;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4533 start=0xf00d2240 */

/* WARNING: Removing unreachable block (ram,0xf00d2348) */
/* WARNING: Removing unreachable block (ram,0xf00d2314) */
/* WARNING: Removing unreachable block (ram,0xf00d22f0) */
/* WARNING: Removing unreachable block (ram,0xf00d22bc) */
/* WARNING: Removing unreachable block (ram,0xf00d2298) */
/* WARNING: Removing unreachable block (ram,0xf00d22a8) */
/* WARNING: Removing unreachable block (ram,0xf00d22cc) */
/* WARNING: Removing unreachable block (ram,0xf00d22fc) */
/* WARNING: Removing unreachable block (ram,0xf00d2338) */
/* WARNING: Removing unreachable block (ram,0xf00d2280) */
/* WARNING: Removing unreachable block (ram,0xf00d2250) */

undefined8
-[EventDriver evClose:token:](int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
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
  
  uVar2 = paLock;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    if (param_4 == *(int *)(param_1 + 0x114)) {
      _objc_msgSend(param_1,paForceautodimst,0);
      _objc_msgSend(param_1,paHidecursor_0);
      uVar1 = paUnlock;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
      _objc_msgSend(param_1,paDetacheventsou);
      if (*(char *)(param_1 + 0x1d2) == '\x01') {
        _objc_msgSend(param_1,paUnmapeventshme,*(undefined4 *)(param_1 + 0x114));
        uVar3 = *(undefined4 *)(param_1 + 0x110);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x110);
      }
      _objc_msgSend(uVar3,uVar2);
      if (*(int *)(param_1 + 0x180) != 0) {
        _IOFree(*(int *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x17c));
        *(undefined4 *)(param_1 + 0x180) = 0;
        *(undefined4 *)(param_1 + 0x17c) = 0;
        *(undefined4 *)(param_1 + 0x188) = 0;
        *(undefined4 *)(param_1 + 0x184) = 0;
      }
      _objc_msgSend(param_1,paSeteventport,0);
      *(undefined *)(param_1 + 0x1d0) = 0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
      uVar2 = 0;
      goto locret_F00D2354;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  _objc_msgSend(uVar2,paUnlock);
  uVar2 = 0xfffffd3e;
locret_F00D2354:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4534 start=0xf00d235c */

/* WARNING: Removing unreachable block (ram,0xf00d2400) */
/* WARNING: Removing unreachable block (ram,0xf00d23c0) */
/* WARNING: Removing unreachable block (ram,0xf00d239c) */
/* WARNING: Removing unreachable block (ram,0xf00d23d8) */
/* WARNING: Removing unreachable block (ram,0xf00d2418) */
/* WARNING: Removing unreachable block (ram,0xf00d2388) */

undefined8
-[EventDriver evFrameBufferDevicePort:unitName:unitClass:unitPort:]
          (int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,undefined4 *param_6)

{
  undefined6 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
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
  *param_6 = 0;
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    iVar6 = -0x2c2;
  }
  else {
    iVar6 = -0x2c2;
    if (param_3 == *(int *)(param_1 + 0x114)) {
      _IOGetObjectForDeviceName(param_4,(undefined *)((int)register0x00000038 + -0x14));
      if (param_4 != 0) {
        _objc_getClass();
        puVar1 = paProbe_0;
        *(uint *)((int)register0x00000038 + -0x14) = param_5;
        iVar6 = param_4;
        if (param_5 == 0) goto locret_F00D2430;
        _objc_msgSend();
        iVar3 = *(int *)((int)register0x00000038 + -0x14);
        if ((param_5 & 0xff) == 0) goto locret_F00D2430;
        _objc_msgSend(iVar3,puVar1);
        *(int *)((int)register0x00000038 + -0x14) = iVar3;
        if (iVar3 == 0) goto locret_F00D2430;
      }
      uVar2 = paDeviceport_0;
      uVar4 = *(uint *)((int)register0x00000038 + -0x14);
      _objc_msgSend(uVar4,paRespondsto,paDeviceport_0);
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x14);
      if ((uVar4 & 0xff) == 0) {
        iVar6 = -0x2c1;
      }
      else {
        _objc_msgSend(uVar5,uVar2);
        *param_6 = uVar5;
        iVar6 = 0;
      }
    }
  }
locret_F00D2430:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=4535 start=0xf00d2438 */

/* WARNING: Removing unreachable block (ram,0xf00d24b8) */
/* WARNING: Removing unreachable block (ram,0xf00d248c) */
/* WARNING: Removing unreachable block (ram,0xf00d24f0) */
/* WARNING: Removing unreachable block (ram,0xf00d2454) */

undefined8
-[EventDriver getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  uVar1 = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *param_5;
  _objc_msgSend(uVar1,paLock);
  piVar3 = *(int **)(param_1 + 0x174);
  if ((int *)(param_1 + 0x174) == piVar3) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
    puVar2 = (undefined *)0xfffffd3e;
  }
  else {
    do {
      puVar2 = (undefined *)*piVar3;
      piVar3 = (int *)piVar3[1];
      _objc_msgSend(puVar2,paGetcharvaluesF_0,param_3,param_4,
                    (undefined *)((int)register0x00000038 + -0x14));
      if (puVar2 != (undefined *)0xfffffd3e) break;
      puVar2 = (undefined *)0xfffffd3e;
    } while ((int *)(param_1 + 0x174) != piVar3);
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
  if (puVar2 == (undefined *)0xfffffd3e) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
    _objc_msgSendSuper(puVar2,paGetcharvaluesF_0,param_3,param_4,
                       (undefined *)((int)register0x00000038 + -0x14));
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
  *param_5 = uVar1;
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4536 start=0xf00d250c */

/* WARNING: Removing unreachable block (ram,0xf00d2580) */
/* WARNING: Removing unreachable block (ram,0xf00d2558) */
/* WARNING: Removing unreachable block (ram,0xf00d25b4) */
/* WARNING: Removing unreachable block (ram,0xf00d2520) */

undefined8
-[EventDriver setCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
  piVar3 = *(int **)(param_1 + 0x174);
  if ((int *)(param_1 + 0x174) == piVar3) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  else {
    do {
      puVar2 = (undefined *)*piVar3;
      piVar3 = (int *)piVar3[1];
      _objc_msgSend(puVar2,paSetcharvaluesF_0,param_3,param_4,param_5);
      if (puVar2 != (undefined *)0xfffffd3e) {
        puVar4 = puVar2;
      }
    } while ((int *)(param_1 + 0x174) != piVar3);
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  if (puVar4 == (undefined *)0xfffffd3e) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
    _objc_msgSendSuper(puVar2,paSetcharvaluesF_0,param_3,param_4,param_5);
    puVar4 = puVar2;
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=4537 start=0xf00d25c8 */

/* WARNING: Removing unreachable block (ram,0xf00d2698) */
/* WARNING: Removing unreachable block (ram,0xf00d2650) */
/* WARNING: Removing unreachable block (ram,0xf00d265c) */
/* WARNING: Removing unreachable block (ram,0xf00d26b4) */
/* WARNING: Removing unreachable block (ram,0xf00d25d8) */

undefined8 -[EventDriver _resetMouseParameters](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  
  uVar2 = paLock;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    *(undefined4 *)(param_1 + 0x1bc) = 0x1e;
    *(undefined2 *)(param_1 + 0x1b2) = 3;
    *(undefined2 *)(param_1 + 0x1b0) = 3;
    *(undefined4 *)(param_1 + 0x1b8) = 0xffffffe2;
    *(undefined2 *)(param_1 + 0x1ae) = 0xfffd;
    *(undefined2 *)(param_1 + 0x1ac) = 0xfffd;
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    uVar1 = paUnlock;
    *(int *)(param_1 + 0x1a4) = *(int *)(*(int *)(param_1 + 0x168) + 0x10) + 0x48a8;
    *(undefined4 *)(param_1 + 0x1a0) = 0x48a8;
    *(undefined4 *)(param_1 + 0x1c8) = 0x10;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),uVar2);
    puVar3 = *(undefined4 **)(param_1 + 0x174);
    if ((undefined4 *)(param_1 + 0x174) == puVar3) {
      uVar2 = *(undefined4 *)(param_1 + 0x170);
    }
    else {
      uVar2 = *puVar3;
      while( true ) {
        puVar3 = (undefined4 *)puVar3[1];
        _objc_msgSend(uVar2,paSetintvaluesFo_0,(undefined *)((int)register0x00000038 + -0x14),
                      aEvsResetmouse,1);
        if ((undefined4 *)(param_1 + 0x174) == puVar3) break;
        uVar2 = *puVar3;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x170);
    }
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4538 start=0xf00d26c4 */

/* WARNING: Removing unreachable block (ram,0xf00d270c) */
/* WARNING: Removing unreachable block (ram,0xf00d2728) */
/* WARNING: Removing unreachable block (ram,0xf00d26d0) */

undefined8 -[EventDriver _resetKeyboardParameters](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
  puVar2 = *(undefined4 **)(param_1 + 0x174);
  if ((undefined4 *)(param_1 + 0x174) == puVar2) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  else {
    uVar1 = *puVar2;
    while( true ) {
      puVar2 = (undefined4 *)puVar2[1];
      _objc_msgSend(uVar1,paSetintvaluesFo_0,(undefined *)((int)register0x00000038 + -0x14),
                    aEvsResetkeyboa,1);
      if ((undefined4 *)(param_1 + 0x174) == puVar2) break;
      uVar1 = *puVar2;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4539 start=0xf00d2738 */

/* WARNING: Removing unreachable block (ram,0xf00d27cc) */

undefined8
-[EventDriver registerScreen:bounds:shmem:size:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    *param_5 = 0;
    *param_6 = 0;
    iVar1 = -1;
  }
  else {
    if (*(int *)(param_1 + 0x184) == 0) {
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x164);
      iVar1 = *(int *)(param_1 + 0x188);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x188);
    }
    iVar2 = *(int *)(param_1 + 0x180);
    *(undefined4 *)(iVar2 + iVar1 * 0x14) = param_3;
    iVar2 = iVar2 + iVar1 * 0x14;
    iVar1 = *(int *)(param_1 + 0x184);
    if (*(int *)(iVar2 + 8) != 0) {
      *(int *)(iVar2 + 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x184);
    }
    *(int *)(param_1 + 0x184) = iVar1 + *(int *)(iVar2 + 8);
    *param_5 = *(undefined4 *)(iVar2 + 4);
    *param_6 = *(undefined4 *)(iVar2 + 8);
    _bcopy(iVar2 + 0xc,param_4,8);
    iVar1 = *(int *)(param_1 + 0x188);
    *(int *)(param_1 + 0x188) = iVar1 + 1;
    iVar1 = iVar1 + 0x100;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4540 start=0xf00d27ec */

/* WARNING: Removing unreachable block (ram,0xf00d28c8) */
/* WARNING: Removing unreachable block (ram,0xf00d2838) */
/* WARNING: Removing unreachable block (ram,0xf00d28b4) */
/* WARNING: Removing unreachable block (ram,0xf00d28d8) */
/* WARNING: Removing unreachable block (ram,0xf00d27f8) */

undefined8 -[EventDriver unregisterScreen:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  param_3 = param_3 + -0x100;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    if (param_3 < 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    if (*(int *)(param_1 + 0x188) <= param_3) {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    _objc_msgSend(param_1,paHidecursor_0);
    *(undefined4 *)(*(int *)(param_1 + 0x180) + param_3 * 0x14) = 0;
    if (*(int *)(param_1 + 0x18c) == param_3) {
      iVar2 = *(int *)(param_1 + 0x188) + -1;
      if (iVar2 != -1) {
        iVar3 = iVar2 * 0x14;
        do {
          if (*(int *)(iVar3 + *(int *)(param_1 + 0x180)) != 0) {
            *(int *)(param_1 + 0x18c) = iVar2;
            break;
          }
          iVar2 = iVar2 + -1;
          iVar3 = iVar3 + -0x14;
        } while (iVar2 != -1);
      }
      _objc_msgSend(param_1,paSetcursorposit,*(int *)(param_1 + 0x168) + 0x18);
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    _objc_msgSend(param_1,paShowcursor);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x110);
loc_F00D28D4:
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4541 start=0xf00d28e8 */

/* WARNING: Removing unreachable block (ram,0xf00d2930) */
/* WARNING: Removing unreachable block (ram,0xf00d2968) */
/* WARNING: Removing unreachable block (ram,0xf00d2924) */

undefined8 -[EventDriver evSetScreen:](int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar3 = param_3[1];
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    uVar4 = 0xfffffd3f;
  }
  else {
    if (*(int *)(param_1 + 0x180) == 0) {
      iVar1 = *param_3 * 0x14;
      *(int *)(param_1 + 0x17c) = iVar1;
      _IOMalloc();
      *(int *)(param_1 + 0x180) = iVar1;
      _bzero();
      *(undefined4 *)(param_1 + 0x160) = 0xe18;
      *(undefined4 *)(param_1 + 0x184) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined2 *)(param_1 + 0x19e) = 0;
      *(undefined2 *)(param_1 + 0x19a) = 0;
      *(undefined2 *)(param_1 + 0x19c) = 0;
      *(undefined2 *)(param_1 + 0x198) = 0;
    }
    if ((int)uVar3 < 0) {
      uVar4 = 0xfffffd3e;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x17c);
      .udiv(uVar2,0x14);
      if (uVar3 < uVar2) {
        iVar1 = *(int *)(param_1 + 0x180) + uVar3 * 0x14;
        *(sword *)(iVar1 + 0xc) = (sword)param_3[3];
        *(sword *)(iVar1 + 0xe) = (sword)param_3[4];
        *(sword *)(iVar1 + 0x10) = (sword)param_3[5];
        *(sword *)(iVar1 + 0x12) = (sword)param_3[6];
        *(int *)(iVar1 + 8) = param_3[2];
        *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + param_3[2];
        if (*(sword *)(iVar1 + 0xc) < *(sword *)(param_1 + 0x198)) {
          *(undefined2 *)(param_1 + 0x198) = *(undefined2 *)(iVar1 + 0xc);
        }
        if (*(sword *)(iVar1 + 0x10) < *(sword *)(param_1 + 0x19c)) {
          *(undefined2 *)(param_1 + 0x19c) = *(undefined2 *)(iVar1 + 0x10);
        }
        if (*(sword *)(iVar1 + 0xe) < *(sword *)(param_1 + 0x19a)) {
          *(undefined2 *)(param_1 + 0x19a) = *(undefined2 *)(iVar1 + 0xe);
        }
        if (*(sword *)(iVar1 + 0x12) < *(sword *)(param_1 + 0x19e)) {
          *(undefined2 *)(param_1 + 0x19e) = *(undefined2 *)(iVar1 + 0x12);
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0xfffffd3e;
      }
    }
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4542 start=0xf00d2a68 */

undefined8 -[EventDriver workspaceBounds](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1 + 0x198);
}
/* GHIDRADEC_FUNCTION index=4543 start=0xf00d2a74 */

/* WARNING: Removing unreachable block (ram,0xf00d2b80) */
/* WARNING: Removing unreachable block (ram,0xf00d2b64) */
/* WARNING: Removing unreachable block (ram,0xf00d2b44) */
/* WARNING: Removing unreachable block (ram,0xf00d2b04) */
/* WARNING: Removing unreachable block (ram,0xf00d2ba8) */
/* WARNING: Removing unreachable block (ram,0xf00d2bb8) */
/* WARNING: Removing unreachable block (ram,0xf00d2b30) */
/* WARNING: Removing unreachable block (ram,0xf00d2b54) */
/* WARNING: Removing unreachable block (ram,0xf00d2b70) */
/* WARNING: Removing unreachable block (ram,0xf00d2b8c) */
/* WARNING: Removing unreachable block (ram,0xf00d2ae4) */

undefined8
-[EventDriver mapEventShmem:task:size:at:]
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  undefined (*pauVar2) [10];
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  if (param_3 == *(int *)(param_1 + 0x114)) {
    if (*(char *)(param_1 + 0x1d0) == '\0') {
      iVar4 = -0x2c1;
    }
    else {
      if (param_4 != 0) {
        if (param_5 == 0) {
          iVar4 = -0x2c2;
          goto locret_F00D2BC4;
        }
        if (*(int *)(param_1 + 0x150) != 0) {
          iVar4 = -0x2c2;
          goto locret_F00D2BC4;
        }
        if (*(int *)(param_1 + 0x154) == 0) {
          iVar4 = param_4;
          _createEventShmem(param_4,param_5,(undefined *)((int)register0x00000038 + -0x14),
                            (undefined *)((int)register0x00000038 + -0x18),param_1 + 0x15c);
          uVar1 = paLock;
          if (iVar4 == 0) {
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
            *(int *)(param_1 + 0x160) = param_5;
            *(int *)(param_1 + 0x150) = param_4;
            uVar3 = *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)(param_1 + 0x158) = uVar3;
            *param_6 = uVar3;
            pauVar2 = paInitshmem;
            *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)((int)register0x00000038 + -0x14);
            _objc_msgSend(param_1,pauVar2);
            uVar3 = paUnlock;
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
            _objc_msgSend(param_1,paResetmousepara);
            _objc_msgSend(param_1,paResetkeyboardp);
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
            _objc_msgSend(param_1,paSchedulenextpe);
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar3);
            iVar4 = 0;
          }
          else {
            _objc_msgSend(param_1,paName);
            _IOLog(aSCreateeventsh,param_1,iVar4);
          }
          goto locret_F00D2BC4;
        }
      }
      iVar4 = -0x2c2;
    }
  }
  else {
    iVar4 = -0x2c1;
  }
locret_F00D2BC4:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=4544 start=0xf00d2bcc */

/* WARNING: Removing unreachable block (ram,0xf00d2c8c) */
/* WARNING: Removing unreachable block (ram,0xf00d2c58) */
/* WARNING: Removing unreachable block (ram,0xf00d2c38) */
/* WARNING: Removing unreachable block (ram,0xf00d2c68) */
/* WARNING: Removing unreachable block (ram,0xf00d2c18) */
/* WARNING: Removing unreachable block (ram,0xf00d2bd8) */

undefined8 -[EventDriver unmapEventShmem:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (param_3 == *(int *)(param_1 + 0x114)) {
    if (*(char *)(param_1 + 0x1d0) == '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
    }
    else {
      if (*(char *)(param_1 + 0x1d2) != '\0') {
        iVar3 = *(int *)(param_1 + 0x150);
        *(undefined *)(param_1 + 0x1d2) = 0;
        _destroyEventShmem(iVar3,*(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x160),
                           *(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c));
        if (iVar3 != 0) {
          iVar2 = param_1;
          _objc_msgSend(param_1,paName);
          _IOLog(aSDestroyevents,iVar2,iVar3);
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        *(undefined4 *)(param_1 + 0x15c) = 0;
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x154) = 0;
        uVar1 = paUnlock;
        *(undefined4 *)(param_1 + 0x150) = 0;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
        goto locret_F00D2C98;
      }
      uVar1 = *(undefined4 *)(param_1 + 0x110);
    }
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x110);
  }
  _objc_msgSend(uVar1,paUnlock);
  iVar3 = -0x2c1;
locret_F00D2C98:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=4545 start=0xf00d2ca0 */

/* WARNING: Removing unreachable block (ram,0xf00d2dec) */

undefined4 -[EventDriver initShmem](undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  int *piVar8;
  undefined2 *puVar9;
  int iVar11;
  qword qVar10;
  undefined4 unaff_l0;
  undefined2 *puVar12;
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
  
  uVar6 = (undefined)param_1;
  uVar4 = (undefined)((uint)param_1 >> 8);
  uVar2 = (undefined2)((uint)param_1 >> 0x10);
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
  iVar1 = CONCAT31(CONCAT21(uVar2,uVar4),uVar6);
  *(undefined2 *)(iVar1 + 0x1a8) = 100;
  *(undefined2 *)(iVar1 + 0x1aa) = 100;
  piVar8 = *(int **)(iVar1 + 0x15c);
  *piVar8 = 8;
  piVar8[1] = *piVar8 + 0xe10;
  iVar11 = 0x4f;
  puVar12 = (undefined2 *)(*(int *)(iVar1 + 0x15c) + *piVar8);
  puVar9 = puVar12 + 0x6ca;
  *(int *)(iVar1 + 0x164) = *(int *)(iVar1 + 0x15c) + piVar8[1];
  *(undefined *)((int)puVar12 + 0x49) = 1;
  *(undefined *)(puVar12 + 0x25) = 1;
  puVar12[0x26] = 0x47;
  *(undefined8 *)(iVar1 + 0x1e8) = 75000000;
  *(undefined8 *)(iVar1 + 0x1d8) = 300000000;
  *(undefined8 *)(iVar1 + 0x1e0) = 0;
  *(undefined8 *)(iVar1 + 0x1f0) = 0;
  *(undefined4 *)(iVar1 + 0x16c) = 0x50;
  do {
    *(undefined4 *)(puVar9 + 0x2c) = 0;
    *(undefined4 *)(puVar9 + 0x32) = 0;
    *(undefined4 *)(puVar9 + 0x34) = 0;
    *(undefined4 *)(puVar9 + 0x2a) = 0;
    *(int *)(puVar9 + 0x28) = iVar11 + 1;
    iVar11 = iVar11 + -1;
    puVar9 = puVar9 + -0x16;
  } while (iVar11 != -1);
  puVar12[2] = 0;
  *(undefined4 *)(puVar12 + (*(int *)(iVar1 + 0x16c) + -1) * 0x16 + 0x28) = 0;
  *puVar12 = (sword)*(undefined4 *)(puVar12 + (sword)puVar12[2] * 0x16 + 0x28);
  puVar12[1] = (sword)*(undefined4 *)(puVar12 + (sword)puVar12[2] * 0x16 + 0x28);
  *(undefined4 *)(puVar12 + 4) = 0;
  puVar12[3] = 0xd;
  *(undefined4 *)(puVar12 + 6) = 0;
  _IOGetTimestamp((char)(undefined *)((int)register0x00000038 + -0x18));
  qVar10 = *(qword *)((int)register0x00000038 + -0x18);
  uVar3 = (undefined2)(qVar10 >> 0x28);
  uVar5 = (undefined)(qVar10 >> 0x20);
  uVar7 = (undefined)(qVar10 >> 0x18);
  if ((qVar10 & 0xffffff00000000) == 0 && (uint)qVar10 >> 0x18 == 0) {
    uVar3 = 0;
    uVar5 = 0;
    uVar7 = 1;
  }
  *(uint *)(puVar12 + 8) = CONCAT31(CONCAT21(uVar3,uVar5),uVar7);
  puVar12[0xc] = *(undefined2 *)(iVar1 + 0x1a8);
  puVar12[0xd] = *(undefined2 *)(iVar1 + 0x1aa);
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfd;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfb;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xef;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xf7;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfe;
  *(undefined4 *)(puVar12 + 0x1a) = 0;
  *(undefined4 *)(puVar12 + 10) = 0;
  *(undefined4 *)(puVar12 + 0x20) = 0;
  *(undefined2 **)(iVar1 + 0x168) = puVar12;
  *(undefined *)(iVar1 + 0x1d2) = 1;
  return CONCAT22(uVar2,CONCAT11(uVar4,uVar6));
}
/* GHIDRADEC_FUNCTION index=4546 start=0xf00d2e84 */

/* WARNING: Removing unreachable block (ram,0xf00d2eb4) */
/* WARNING: Removing unreachable block (ram,0xf00d2ecc) */
/* WARNING: Removing unreachable block (ram,0xf00d2ea8) */

undefined8 -[EventDriver setEventPort:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
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
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  else {
    if (param_3 == *(int *)(param_1 + 0x114)) {
      iVar1 = *(int *)(param_1 + 0x14c);
      goto loc_F00D2EC0;
    }
    iVar1 = param_3;
    _IOGetKernPort();
    *(int *)(param_1 + 0x144) = iVar1;
    _port_request_notification();
  }
  iVar1 = *(int *)(param_1 + 0x14c);
loc_F00D2EC0:
  if (iVar1 == 0) {
    uVar2 = 0x1c;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x14c) = uVar2;
    *(int *)(param_1 + 0x114) = param_3;
  }
  else {
    *(int *)(param_1 + 0x114) = param_3;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x14c);
  *puVar3 = dword_F012EEE0;
  puVar3[1] = DAT_f012eee4._0_4_;
  puVar3[2] = DAT_f012eee4._4_4_;
  puVar3[3] = DAT_f012eee4._8_4_;
  puVar3[4] = DAT_f012eee4._12_4_;
  puVar3[5] = DAT_f012eee4._16_4_;
  puVar3[6] = DAT_f012eee4._20_4_;
  *(int *)(*(int *)(param_1 + 0x14c) + 0x10) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4547 start=0xf00d2f30 */

undefined8
-[EventDriver setSpecialKeyPort:keyFlavor:keyPort:]
          (int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_3 == *(int *)(param_1 + 0x134)) {
    if (param_4 < 7) {
      *(undefined4 *)(param_4 * 4 + param_1 + 0x118) = param_5;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffd3f;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4548 start=0xf00d2f68 */

undefined8 -[EventDriver specialKeyPort:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_3 < 7) {
    uVar1 = *(undefined4 *)(param_3 * 4 + param_1 + 0x118);
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4549 start=0xf00d2f90 */

undefined8 -[EventDriver ev_port](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x134));
}

