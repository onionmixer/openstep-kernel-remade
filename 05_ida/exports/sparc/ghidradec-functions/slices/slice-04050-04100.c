/* GHIDRADEC_FUNCTION index=4050 start=0xf00c076c */

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
/* GHIDRADEC_FUNCTION index=4051 start=0xf00c08ac */

undefined8
-[EventSrcPCPointer getCharValues:forParameter:count:](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0xfffffd3e);
}
/* GHIDRADEC_FUNCTION index=4052 start=0xf00c08b8 */

/* WARNING: Removing unreachable block (ram,0xf00c096c) */
/* WARNING: Removing unreachable block (ram,0xf00c0940) */
/* WARNING: Removing unreachable block (ram,0xf00c090c) */
/* WARNING: Removing unreachable block (ram,0xf00c091c) */
/* WARNING: Removing unreachable block (ram,0xf00c095c) */
/* WARNING: Removing unreachable block (ram,0xf00c09a8) */
/* WARNING: Removing unreachable block (ram,0xf00c08cc) */

undefined8
-[EventSrcPCPointer setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int *param_3,int param_4,uint param_5)

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
  undefined *puVar3;
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
  puVar3 = (undefined *)0xfffffd3e;
  iVar2 = param_4;
  _strcmp(param_4,aEvsSetmousesca);
  if (iVar2 == 0) {
    if ((param_5 < 0x2a) && (*param_3 * 2 + 1U <= param_5)) {
      puVar3 = (undefined *)0x0;
      _objc_msgSend(param_1,paSetpointerscal,*param_3,param_3 + 1);
    }
  }
  else {
    iVar2 = param_4;
    _strcmp(param_4,aEvsSetmousehan);
    if (iVar2 == 0) {
      if (param_5 == 1) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
        uVar1 = paUnlock;
        puVar3 = (undefined *)0x0;
        *(int *)(param_1 + 0x134) = *param_3;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),uVar1);
      }
    }
    else {
      iVar2 = param_4;
      _strcmp(param_4,aEvsResetmouse_0);
      if (iVar2 == 0) {
        puVar3 = (undefined *)0x0;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar3 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
        _objc_msgSendSuper(puVar3,paSetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar3 == (undefined *)0xfffffd39) {
          puVar3 = (undefined *)0xfffffd3e;
        }
      }
    }
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4053 start=0xf00c09c8 */

undefined8 -[PCPointer getResolution](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x32);
}
/* GHIDRADEC_FUNCTION index=4054 start=0xf00c09d4 */

/* WARNING: Removing unreachable block (ram,0xf00c0a08) */
/* WARNING: Removing unreachable block (ram,0xf00c0a14) */
/* WARNING: Removing unreachable block (ram,0xf00c09e8) */

undefined8 -[PCPointer setEventTarget:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
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
  bool bVar2;
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
  uVar1 = param_3;
  _objc_msgSend(param_3,paConformsto,stru_F01458FC);
  bVar2 = (uVar1 & 0xff) == 0;
  if (bVar2) {
    _object_getClassName(param_3);
    _IOLog(aPcpointerSetev,param_3);
  }
  else {
    *(uint *)(param_1 + 0x128) = param_3;
  }
  return CONCAT44(param_2,(uint)!bVar2);
}
/* GHIDRADEC_FUNCTION index=4055 start=0xf00c0ae0 */

sqword -[PCPointer mouseInit:](undefined4 param_1,uint param_2)

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
/* GHIDRADEC_FUNCTION index=4056 start=0xf00c0aec */

undefined8 +[PCPointer activePointerDevice](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,dword_F0132F80);
}
/* GHIDRADEC_FUNCTION index=4057 start=0xf00c0b00 */

/* WARNING: Removing unreachable block (ram,0xf00c0b8c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b5c) */
/* WARNING: Removing unreachable block (ram,0xf00c0bb8) */
/* WARNING: Removing unreachable block (ram,0xf00c0b1c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b34) */
/* WARNING: Removing unreachable block (ram,0xf00c0bc8) */
/* WARNING: Removing unreachable block (ram,0xf00c0b78) */
/* WARNING: Removing unreachable block (ram,0xf00c0b9c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b0c) */

undefined8 +[PCPointer probe:](uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  bool bVar2;
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
  _objc_msgSend(param_1,paAlloc);
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x128) = 0;
  uVar1 = param_1;
  _objc_msgSend();
  bVar2 = (uVar1 & 0xff) == 0;
  if (bVar2) {
    _IOLog(aPcpointerProbe);
    _objc_msgSend(param_1,paFree);
  }
  else {
    _sprintf((undefined *)((int)register0x00000038 + -0x28),aPcpointerD,dword_F0132F7C);
    dword_F0132F7C = dword_F0132F7C + 1;
    _objc_msgSend(param_1,paSetunit);
    _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
    _objc_msgSend(param_1,paRegisterdevice);
    dword_F0132F80 = param_1;
  }
  return CONCAT44(param_2,(uint)!bVar2);
}
/* GHIDRADEC_FUNCTION index=4058 start=0xf00c0bdc */

undefined8 sub_F00C0BDC(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  undefined8 in_i0_1;
  undefined8 uVar3;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  uVar3 = CONCAT44(param_1,param_2);
  if (dword_F0132FF0 != 5) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined *)((int)register0x00000038 + -0xc) = 0;
    *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(param_2,param_3);
    iVar2 = dword_F0132FF0 * 0x10;
    iVar1 = dword_F0132FF0 * 2;
    dword_F0132FF0 = dword_F0132FF0 + 1;
    (&qword_F0132FA0)[iVar1] = CONCAT44(param_2,param_3);
    uVar3 = *(undefined8 *)((int)register0x00000038 + -0x10);
    *(undefined8 *)(DAT_f0132fa8 + iVar2) = uVar3;
  }
  return CONCAT44((int)uVar3,(int)((qword)uVar3 >> 0x20));
}
/* GHIDRADEC_FUNCTION index=4059 start=0xf00c0c30 */

/* WARNING: Removing unreachable block (ram,0xf00c0c90) */
/* WARNING: Removing unreachable block (ram,0xf00c0c7c) */
/* WARNING: Removing unreachable block (ram,0xf00c0cc0) */
/* WARNING: Removing unreachable block (ram,0xf00c0cac) */

undefined8 sub_F00C0C30(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
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
  if (((*(int *)(param_1 + 1) == 0x62) && (*(char *)((int)param_1 + 0xc) != '\0')) &&
     ((dword_F0133004 & 0x4000000) != 0)) {
    if ((dword_F0133004 & 0x1000000) == 0) {
      _mini_mon(&aRestart_0,&aRestart_1,param_2);
      uVar1 = *param_1;
    }
    else {
      _mini_mon(&unk_F0120E30,aKernelDebugger,param_2);
      sub_F00C0BDC(0x78,(int)((qword)*param_1 >> 0x20),(int)*param_1);
      uVar1 = *param_1;
    }
    sub_F00C0BDC(0x7a,(int)((qword)uVar1 >> 0x20),(int)uVar1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4060 start=0xf00c0ef4 */

undefined8 sub_F00C0EF4(int *param_1)

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
  undefined *puVar2;
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
  iVar1 = 0;
  puVar2 = _kbddata;
  do {
    iVar1 = iVar1 + 1;
    if (*(int *)(puVar2 + 0x1c) == *param_1) goto locret_F00C0F2C;
    puVar2 = puVar2 + 0x2c;
  } while (iVar1 < 4);
  puVar2 = _kbddata;
locret_F00C0F2C:
  return CONCAT44(*param_1,puVar2);
}
/* GHIDRADEC_FUNCTION index=4061 start=0xf00c1080 */

/* WARNING: Removing unreachable block (ram,0xf00c119c) */
/* WARNING: Removing unreachable block (ram,0xf00c13cc) */
/* WARNING: Removing unreachable block (ram,0xf00c1350) */
/* WARNING: Removing unreachable block (ram,0xf00c1118) */
/* WARNING: Removing unreachable block (ram,0xf00c1228) */
/* WARNING: Removing unreachable block (ram,0xf00c11d8) */
/* WARNING: Removing unreachable block (ram,0xf00c11cc) */
/* WARNING: Removing unreachable block (ram,0xf00c1238) */
/* WARNING: Removing unreachable block (ram,0xf00c1218) */
/* WARNING: Removing unreachable block (ram,0xf00c126c) */
/* WARNING: Removing unreachable block (ram,0xf00c1128) */
/* WARNING: Removing unreachable block (ram,0xf00c13c4) */
/* WARNING: Removing unreachable block (ram,0xf00c115c) */
/* WARNING: Removing unreachable block (ram,0xf00c118c) */
/* WARNING: Removing unreachable block (ram,0xf00c1088) */

undefined8 sub_F00C1080(uint param_1,undefined4 param_2)

{
  byte bVar1;
  char *pcVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 uVar6;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  pcVar2 = (char *)((int)register0x00000038 + 0x48);
  sub_F00C0EF4();
  uVar6 = 0;
  if (pcVar2 == (char *)0x0) goto locret_F00C13F4;
  bVar1 = pcVar2[1];
  if (bVar1 == 1) {
    if ((param_1 & 0xff) == 0x7f) {
      sub_F00C13FC(*(undefined4 *)((int)register0x00000038 + 0x48),0);
    }
    else if ((param_1 & 0xff) == 0xff) {
      pcVar2[1] = '\x02';
    }
    else if ((param_1 & 0x80) == 0) {
      _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
    }
    else {
      sub_F00C13FC(*(undefined4 *)((int)register0x00000038 + 0x48),param_1 & 0x40 | 1);
    }
    goto locret_F00C13F4;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      if ((param_1 & 0xff) == 0x7f) {
        pcVar2[1] = '\x01';
        uVar5 = *(undefined4 *)((int)register0x00000038 + 0x48);
        uVar3 = _hz;
        .div(_hz,10);
        _timeout(_kbdidletimeout,uVar5,uVar3);
      }
      else if ((param_1 & 0xff) == 0xff) {
        pcVar2[1] = '\x02';
      }
      goto locret_F00C13F4;
    }
    cVar4 = pcVar2[2];
  }
  else {
    if (bVar1 == 2) {
      if ((param_1 & 0xff) == 4) {
        _kbdcmd(*(undefined4 *)((int)register0x00000038 + 0x48),0xf);
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      else {
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
        if ((param_1 & 0xff) != 0x81) {
          _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
          goto locret_F00C13F4;
        }
      }
      sub_F00C13FC(uVar3,param_1 & 0xff);
      if (_kbdclick == 0) {
        uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      else if (((0 < _kbdclick) &&
               (uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48), _kbdclick == 1)) ||
              (uVar3 = *(undefined4 *)((int)register0x00000038 + 0x48), _keyclick != 0)) {
        _kbdcmd(uVar3,10);
        goto locret_F00C13F4;
      }
      _kbdcmd(uVar3,0xb);
      goto locret_F00C13F4;
    }
    if (bVar1 == 3) {
      if ((((param_1 & 0xff) == 0) && (pcVar2[2] != '\x04')) || ((param_1 & 0xff) == 0xff)) {
        _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
        goto locret_F00C13F4;
      }
      cVar4 = pcVar2[2];
    }
    else {
      cVar4 = pcVar2[2];
    }
  }
  switch(cVar4) {
  case :
    break;
  case :
    if (*(int *)(pcVar2 + 0xc) == 0) goto locret_F00C13F4;
    if ((param_1 & 0xff) == (uint)*(byte *)(*(int *)(pcVar2 + 0xc) + 0x25)) {
      _us_spin(100000);
      uVar6 = 0;
      _prom_enter_mon();
      pcVar2[2] = '\0';
      goto locret_F00C13F4;
    }
    pcVar2[2] = '\0';
    break;
  case :
    if ((param_1 & 0x80) == 0) {
      if ((param_1 & 0xff) == 0x7f) goto locret_F00C13F4;
      pcVar2[2] = '\0';
      break;
    }
    if (*pcVar2 == '\x01') {
      pcVar2[2] = '\x03';
      goto locret_F00C13F4;
    }
    if ((param_1 & 0xff) != 0xfe) {
      _kbdreset(*(undefined4 *)((int)register0x00000038 + 0x48));
      goto locret_F00C13F4;
    }
    goto loc_F00C1344;
  case :
    if ((param_1 & 0xff) == 0x7f) {
      pcVar2[2] = '\x02';
      goto locret_F00C13F4;
    }
    pcVar2[2] = '\0';
    break;
  case :
    pcVar2[0x2b] = (char)param_1;
    pcVar2[2] = '\0';
    goto locret_F00C13F4;
  case :
  case :
  case :
    if ((param_1 & 0xff) == 0x7f) goto locret_F00C13F4;
    goto loc_F00C13EC;
  :
    goto locret_F00C13F4;
  }
  uVar6 = 0;
  if ((*(int *)(pcVar2 + 0xc) == 0) ||
     ((param_1 & 0xff) != (uint)*(byte *)(*(int *)(pcVar2 + 0xc) + 0x24))) {
    if ((param_1 & 0xff) == 0xfe) {
loc_F00C1344:
      uVar6 = 0;
      pcVar2[2] = '\x04';
    }
    else {
      uVar6 = 1;
      if ((param_1 & 0xff) == 0x7f) {
        pcVar2[2] = '\x02';
loc_F00C13EC:
        uVar6 = 0;
      }
    }
  }
  else {
    pcVar2[2] = '\x01';
  }
locret_F00C13F4:
  return CONCAT44(uVar6,uVar6);
}
/* GHIDRADEC_FUNCTION index=4062 start=0xf00c13fc */

/* WARNING: Removing unreachable block (ram,0xf00c1404) */

undefined8 sub_F00C13FC(undefined4 param_1,uint param_2)

{
  byte *pbVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  pbVar1 = (byte *)((int)register0x00000038 + 0x44);
  sub_F00C0EF4();
  if (pbVar1 != (byte *)0x0) {
    *pbVar1 = (byte)param_2 & 0xf;
    pbVar1[1] = 3;
    pbVar1[8] = 0;
    pbVar1[9] = 0;
    pbVar1[10] = 0;
    pbVar1[0xb] = 0;
    if ((param_2 & 0x40) != 0) {
      pbVar1[8] = 0;
      pbVar1[9] = 0;
      pbVar1[10] = 0;
      pbVar1[0xb] = 1;
    }
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    *(undefined (**) [44])(pbVar1 + 0xc) = _keytables;
    pbVar1[3] = 0x7f;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4063 start=0xf00c160c */

/* WARNING: Removing unreachable block (ram,0xf00c1638) */
/* WARNING: Removing unreachable block (ram,0xf00c1644) */
/* WARNING: Removing unreachable block (ram,0xf00c1614) */

undefined8 sub_F00C160C(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  pcVar1 = (char *)((int)register0x00000038 + 0x44);
  sub_F00C0EF4();
  if ((pcVar1 != (char *)0x0) && (*pcVar1 == '\x04')) {
    _kbdcmd(*(undefined4 *)((int)register0x00000038 + 0x44),0xe);
    _kbdcmd(*(undefined4 *)((int)register0x00000038 + 0x44),(int)pcVar1[0x2a]);
  }
  return CONCAT44(param_2,pcVar1);
}
/* GHIDRADEC_FUNCTION index=4064 start=0xf00c17b8 */

/* WARNING: Removing unreachable block (ram,0xf00c1828) */
/* WARNING: Removing unreachable block (ram,0xf00c1810) */
/* WARNING: Removing unreachable block (ram,0xf00c1850) */
/* WARNING: Removing unreachable block (ram,0xf00c17cc) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00c1810 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[TYPE5Keyboard interruptHandler](void)

{
  int iVar1;
  int iVar2;
  undefined8 in_o0_1;
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
  if (*(int *)(iVar2 + 0x140) != 0) {
    _spltty();
    if (dword_F0132FF0 == 1) {
      *(undefined8 *)((int)register0x00000038 + -0x60) = qword_F0132FA0;
      *(undefined8 *)((int)register0x00000038 + -0x58) = DAT_f0132fa8._0_8_;
    }
    else {
      _bcopy(&qword_F0132FA0,(int)in_o0_1,dword_F0132FF0 << 4);
    }
    iVar1 = dword_F0132FF0;
    iVar3 = 0;
    dword_F0132FF0 = 0;
    _splx();
    if (0 < iVar1) {
      do {
        iVar3 = iVar3 + 1;
        _objc_msgSend(*(undefined4 *)(iVar2 + 0x140));
      } while (iVar3 < iVar1);
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=4065 start=0xf00c186c */

/* WARNING: Removing unreachable block (ram,0xf00c1914) */
/* WARNING: Removing unreachable block (ram,0xf00c18f4) */
/* WARNING: Removing unreachable block (ram,0xf00c18b0) */
/* WARNING: Removing unreachable block (ram,0xf00c1938) */
/* WARNING: Removing unreachable block (ram,0xf00c1924) */
/* WARNING: Removing unreachable block (ram,0xf00c18c4) */
/* WARNING: Removing unreachable block (ram,0xf00c1888) */

void sub_F00C186C(int param_1)

{
  int iVar1;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paInterruptport_0);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
  do {
    while( true ) {
      while( true ) {
        *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x128);
        puVar2 = (undefined *)((int)register0x00000038 + -0x20);
        _msg_receive((undefined *)((int)register0x00000038 + -0x20),0,0);
        if (puVar2 == (undefined *)0x0) break;
        _IOLog(aKbdthreadMsgRe,puVar2);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      }
      if (*(int *)((int)register0x00000038 + -0xc) != 0x232325) break;
      if (*(int *)((int)register0x00000038 + -0x14) == iVar1) {
        _objc_msgSend(param_1,paInterrupthandl);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      }
      else if (*(int *)((int)register0x00000038 + -0x14) == *(int *)(param_1 + 0x13c)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paInterrupthandl);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      }
      else {
        _IOLog(aKbdthreadBogus);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      }
    }
    _IOLog(aKbdthreadNonIn,0);
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4066 start=0xf00c1950 */

/* WARNING: Removing unreachable block (ram,0xf00c1a78) */
/* WARNING: Removing unreachable block (ram,0xf00c1adc) */
/* WARNING: Removing unreachable block (ram,0xf00c1aa0) */
/* WARNING: Removing unreachable block (ram,0xf00c1a60) */
/* WARNING: Removing unreachable block (ram,0xf00c1a50) */
/* WARNING: Removing unreachable block (ram,0xf00c1a3c) */
/* WARNING: Removing unreachable block (ram,0xf00c19e8) */
/* WARNING: Removing unreachable block (ram,0xf00c19d0) */
/* WARNING: Removing unreachable block (ram,0xf00c1990) */
/* WARNING: Removing unreachable block (ram,0xf00c199c) */
/* WARNING: Removing unreachable block (ram,0xf00c19f8) */
/* WARNING: Removing unreachable block (ram,0xf00c1a14) */
/* WARNING: Removing unreachable block (ram,0xf00c1a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c1a58) */
/* WARNING: Removing unreachable block (ram,0xf00c1a88) */
/* WARNING: Removing unreachable block (ram,0xf00c1ab0) */
/* WARNING: Removing unreachable block (ram,0xf00c1acc) */
/* WARNING: Removing unreachable block (ram,0xf00c19b4) */
/* WARNING: Removing unreachable block (ram,0xf00c197c) */

undefined8 -[TYPE5Keyboard kbdInit:](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined7 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  *(undefined *)(param_1 + 300) = 0;
  *(undefined *)(param_1 + 0x12d) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  puVar2 = paNxlock;
  puVar1 = paNew;
  _type5kbd_owner = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  _objc_msgSend(puVar2,puVar1);
  *(undefined7 **)(param_1 + 0x148) = puVar2;
  iVar3 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar3 == 0) {
    _IOLog(aType5keyboardK);
    uVar5 = 0;
  }
  else {
    iVar4 = iVar3;
    _objc_msgSend(iVar3,paValueforstring,aInterface);
    if (iVar4 == 0) {
      _IOLog(aType5keyboardK_0);
      iVar4 = 7;
    }
    else {
      _PCPatoi();
    }
    *(int *)(param_1 + 0x130) = iVar4;
    _objc_msgSend(iVar3,paValueforstring,aHandlerId);
    if (iVar3 == 0) {
      _IOLog(aType5keyboardK_1);
      *(undefined4 *)(param_1 + 0x134) = 0;
    }
    else {
      _PCPatoi();
      *(int *)(param_1 + 0x134) = iVar3;
    }
    iVar3 = param_1;
    _objc_msgSend(param_1,paEnableallinter);
    _task_self();
    _port_set_allocate_EXTERNAL();
    if (iVar3 == 0) {
      _task_self();
      uVar5 = *(undefined4 *)(param_1 + 0x128);
      iVar4 = param_1;
      _objc_msgSend(param_1,paInterruptport_0);
      _port_set_add_EXTERNAL(iVar3,uVar5,iVar4);
      if (iVar3 == 0) {
        _IOForkThread(sub_F00C186C,param_1);
        uVar5 = 1;
      }
      else {
        _IOLog(aKbdinitPortSet_0,iVar3);
        uVar5 = 0xffffffff;
      }
    }
    else {
      _IOLog(aKbdinitPortSet);
      uVar5 = 0;
    }
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=4067 start=0xf00c1af0 */

/* WARNING: Removing unreachable block (ram,0xf00c1bac) */
/* WARNING: Removing unreachable block (ram,0xf00c1b64) */
/* WARNING: Removing unreachable block (ram,0xf00c1b38) */
/* WARNING: Removing unreachable block (ram,0xf00c1b0c) */
/* WARNING: Removing unreachable block (ram,0xf00c1b20) */
/* WARNING: Removing unreachable block (ram,0xf00c1b50) */
/* WARNING: Removing unreachable block (ram,0xf00c1b9c) */
/* WARNING: Removing unreachable block (ram,0xf00c1b84) */
/* WARNING: Removing unreachable block (ram,0xf00c1afc) */

undefined8 +[TYPE5Keyboard probe:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
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
  bool bVar2;
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
  _objc_msgSend(param_1,paAlloc);
  _objc_msgSend();
  _objc_msgSend();
  _objc_msgSend(param_1,paSetname,aType5keyboard0_1);
  _objc_msgSend(param_1,paSetdevicekind,aType5keyboard_1);
  uVar1 = param_1;
  _objc_msgSend(param_1,paKbdinit,param_3);
  bVar2 = (uVar1 & 0xff) == 0;
  if (bVar2) {
    _IOLog(aType5keyboardP);
    _objc_msgSend(param_1,paFree);
  }
  else {
    _objc_msgSend(param_1,paRegisterdevice);
    dword_F0132F98 = param_1;
  }
  return CONCAT44(param_2,(uint)!bVar2);
}
/* GHIDRADEC_FUNCTION index=4068 start=0xf00c1bc0 */

/* WARNING: Removing unreachable block (ram,0xf00c1bd0) */

undefined8
-[TYPE5Keyboard getHandler:level:argument:forInterrupt:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

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
  _remintr(0x16,_zsintr);
  *param_3 = _zsintr;
  *param_4 = 0x16;
  *param_5 = param_1;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=4069 start=0xf00c1bf0 */

/* WARNING: Removing unreachable block (ram,0xf00c1c1c) */
/* WARNING: Removing unreachable block (ram,0xf00c1c00) */

undefined8 -[TYPE5Keyboard free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  
  uVar1 = paFree;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141dd0;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4070 start=0xf00c1c2c */

/* WARNING: Removing unreachable block (ram,0xf00c1c40) */
/* WARNING: Removing unreachable block (ram,0xf00c1c5c) */
/* WARNING: Removing unreachable block (ram,0xf00c1c34) */

undefined8
-[TYPE5Keyboard attachMouse:withPort:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  *(undefined4 *)(param_1 + 0x138) = param_3;
  *(undefined4 *)(param_1 + 0x13c) = param_4;
  _task_self();
  _port_set_add_EXTERNAL();
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    _IOLog(aAttachmousePor,param_1);
    uVar1 = 0xffffffff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4071 start=0xf00c1c70 */

undefined8 -[TYPE5Keyboard detachMouse](undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=4072 start=0xf00c1c7c */

undefined8 -[TYPE5Keyboard interfaceId](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x130));
}
/* GHIDRADEC_FUNCTION index=4073 start=0xf00c1c8c */

undefined8 -[TYPE5Keyboard handlerId](int param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=4074 start=0xf00c1c9c */

/* WARNING: Removing unreachable block (ram,0xf00c1cf4) */
/* WARNING: Removing unreachable block (ram,0xf00c1cc4) */

undefined8
-[TYPE5Keyboard setAlphaLockFeedback:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined *puVar1;
  byte bVar2;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0x14);
  *(undefined **)((int)register0x00000038 + -0x14) = _zs_tty + (uint)bRamf0120e25 * 0x88;
  sub_F00C0EF4();
  if ((param_3 & 0xff) == 0) {
    bVar2 = puVar1[0x2a] & 0xf7;
  }
  else {
    bVar2 = puVar1[0x2a] | 8;
  }
  puVar1[0x2a] = bVar2;
  sub_F00C160C(*(undefined4 *)((int)register0x00000038 + -0x14));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4075 start=0xf00c1dec */

/* WARNING: Removing unreachable block (ram,0xf00c1e40) */
/* WARNING: Removing unreachable block (ram,0xf00c1e74) */
/* WARNING: Removing unreachable block (ram,0xf00c1e20) */
/* WARNING: Removing unreachable block (ram,0xf00c1e64) */
/* WARNING: Removing unreachable block (ram,0xf00c1e84) */
/* WARNING: Removing unreachable block (ram,0xf00c1ebc) */
/* WARNING: Removing unreachable block (ram,0xf00c1df8) */

undefined8 -[TYPE5Keyboard becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined5 *puVar1;
  undefined (*pauVar2) [28];
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paLock);
  pauVar2 = paRelinquishowne;
  uVar3 = *(uint *)(param_1 + 0x140);
  if (uVar3 == 0) {
    *(undefined4 *)(param_1 + 0x140) = param_3;
    iVar6 = 0;
  }
  else {
    _objc_msgSend(uVar3,paRespondsto,paRelinquishowne);
    puVar1 = paName;
    if ((uVar3 & 0xff) == 0) {
      iVar6 = -0x2d5;
      iVar4 = param_1;
      _objc_msgSend(param_1,paName);
      uVar5 = *(undefined4 *)(param_1 + 0x140);
      _objc_msgSend(uVar5,puVar1);
      _IOLog(aSOwnerSDoesNot,iVar4,uVar5);
    }
    else {
      iVar6 = *(int *)(param_1 + 0x140);
      _objc_msgSend(iVar6,pauVar2,param_1);
    }
    if (iVar6 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x148);
      goto loc_F00C1EB8;
    }
    *(undefined4 *)(param_1 + 0x140) = param_3;
  }
  uVar5 = *(undefined4 *)(param_1 + 0x148);
  _type5kbd_owner = param_3;
loc_F00C1EB8:
  _objc_msgSend(uVar5,paUnlock);
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=4076 start=0xf00c1ecc */

/* WARNING: Removing unreachable block (ram,0xf00c1f84) */
/* WARNING: Removing unreachable block (ram,0xf00c1f40) */
/* WARNING: Removing unreachable block (ram,0xf00c1f08) */
/* WARNING: Removing unreachable block (ram,0xf00c1f78) */
/* WARNING: Removing unreachable block (ram,0xf00c1f5c) */
/* WARNING: Removing unreachable block (ram,0xf00c1ed8) */

undefined8 -[TYPE5Keyboard relinquishOwnership:](int param_1,undefined4 param_2,uint param_3)

{
  undefined (*pauVar1) [16];
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paLock);
  iVar3 = -0x2d5;
  if (*(uint *)(param_1 + 0x140) == param_3) {
    iVar3 = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    _type5kbd_owner = 0;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paUnlock);
  pauVar1 = paCanbecomeowner;
  if (iVar3 == 0) {
    uVar2 = *(uint *)(param_1 + 0x144);
    if ((uVar2 != 0) && (uVar2 != param_3)) {
      _objc_msgSend(uVar2,paRespondsto,paCanbecomeowner);
      if ((uVar2 & 0xff) == 0) {
        _objc_msgSend(param_1,paName);
        _IOLog(aSDesiredownerD_0,param_1);
      }
      else {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x144),pauVar1,param_1);
      }
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=4077 start=0xf00c1f94 */

/* WARNING: Removing unreachable block (ram,0xf00c1fd8) */
/* WARNING: Removing unreachable block (ram,0xf00c1fa0) */

undefined8 -[TYPE5Keyboard desireOwnership:](int param_1,undefined4 param_2,int param_3)

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
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paLock);
  if (*(int *)(param_1 + 0x144) == 0) {
    *(int *)(param_1 + 0x144) = param_3;
  }
  else {
    if (*(int *)(param_1 + 0x144) != param_3) {
      uVar1 = 0xfffffd2b;
      goto loc_F00C1FD0;
    }
    *(int *)(param_1 + 0x144) = param_3;
  }
  uVar1 = 0;
loc_F00C1FD0:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paUnlock);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4078 start=0xf00c2120 */

/* WARNING: Removing unreachable block (ram,0xf00c213c) */

undefined8 -[SUNMouse interruptHandler](int param_1,undefined4 param_2)

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
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paDispatchpointe,&qword_F0133008);
  }
  dword_F0133028 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4079 start=0xf00c2154 */

/* WARNING: Removing unreachable block (ram,0xf00c21dc) */
/* WARNING: Removing unreachable block (ram,0xf00c2198) */
/* WARNING: Removing unreachable block (ram,0xf00c21cc) */
/* WARNING: Removing unreachable block (ram,0xf00c21ac) */
/* WARNING: Removing unreachable block (ram,0xf00c2174) */

void sub_F00C2154(int param_1)

{
  undefined *puVar1;
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
  _objc_msgSend(param_1,paInterruptport_0);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
  do {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x130);
      puVar1 = (undefined *)((int)register0x00000038 + -0x20);
      _msg_receive((undefined *)((int)register0x00000038 + -0x20),0,0);
      if (puVar1 == (undefined *)0x0) break;
      _IOLog(aMousethreadMsg,puVar1);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
    if (*(int *)((int)register0x00000038 + -0xc) == 0x232325) {
      _objc_msgSend(param_1,paInterrupthandl);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
    else {
      _IOLog(aMousethreadNon,0);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4080 start=0xf00c21f4 */

/* WARNING: Removing unreachable block (ram,0xf00c2330) */
/* WARNING: Removing unreachable block (ram,0xf00c2314) */
/* WARNING: Removing unreachable block (ram,0xf00c22ec) */
/* WARNING: Removing unreachable block (ram,0xf00c22bc) */
/* WARNING: Removing unreachable block (ram,0xf00c226c) */
/* WARNING: Removing unreachable block (ram,0xf00c2254) */
/* WARNING: Removing unreachable block (ram,0xf00c2224) */
/* WARNING: Removing unreachable block (ram,0xf00c2218) */
/* WARNING: Removing unreachable block (ram,0xf00c223c) */
/* WARNING: Removing unreachable block (ram,0xf00c227c) */
/* WARNING: Removing unreachable block (ram,0xf00c22a0) */
/* WARNING: Removing unreachable block (ram,0xf00c22c4) */
/* WARNING: Removing unreachable block (ram,0xf00c2304) */
/* WARNING: Removing unreachable block (ram,0xf00c2340) */
/* WARNING: Removing unreachable block (ram,0xf00c22dc) */
/* WARNING: Removing unreachable block (ram,0xf00c2208) */

undefined8 -[SUNMouse mouseInit:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _objc_msgSend(param_1,paSetdevicekind,aSunmouse_0);
  iVar1 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar1 == 0) {
    _IOLog(aSunmouseMousei);
    uVar3 = 0;
    goto locret_F00C234C;
  }
  _objc_msgSend();
  if (iVar1 == 0) {
    _IOLog(aSunmouseMousei_0);
loc_F00C2294:
    *(undefined4 *)(param_1 + 0x134) = 200;
  }
  else {
    _PCPatoi();
    *(int *)(param_1 + 0x134) = iVar1;
    if (iVar1 < 0) goto loc_F00C2294;
  }
  _objc_msgSend(param_1,paEnableallinter);
  dword_F0133028 = 0;
  puVar2 = unk_F0133018;
  DAT_f0133022._0_1_ = 0;
  byte_F0133021 = 0;
  _task_self();
  _port_set_allocate_EXTERNAL();
  if (puVar2 == (undefined *)0x0) {
    _task_self();
    uVar3 = *(undefined4 *)(param_1 + 0x130);
    iVar1 = param_1;
    _objc_msgSend(param_1,paInterruptport_0);
    _port_set_add_EXTERNAL(puVar2,uVar3,iVar1);
    if (puVar2 == (undefined *)0x0) {
      _IOForkThread(sub_F00C2154,param_1);
      uVar3 = 1;
    }
    else {
      _IOLog(aMouseinitPortS_0,puVar2);
      uVar3 = 0xffffffff;
    }
  }
  else {
    _IOLog(aMouseinitPortS);
    uVar3 = 0;
  }
locret_F00C234C:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4081 start=0xf00c2354 */

/* WARNING: Removing unreachable block (ram,0xf00c2380) */
/* WARNING: Removing unreachable block (ram,0xf00c2360) */

undefined8 -[SUNMouse free](int param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 300),paDetachmouse);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141df8;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4082 start=0xf00c23c4 */

undefined8
-[SUNMouse getHandler:level:argument:forInterrupt:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

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
  *param_3 = _zsintr_ms;
  *param_4 = 0x16;
  *param_5 = 0xdeadbeef;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=4083 start=0xf00c23f0 */

undefined8 -[SUNMouse getResolution](int param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=4084 start=0xf00c2698 */

/* WARNING: Removing unreachable block (ram,0xf00c26d0) */
/* WARNING: Removing unreachable block (ram,0xf00c26d8) */
/* WARNING: Removing unreachable block (ram,0xf00c269c) */

undefined8 sub_F00C2698(int *param_1,undefined4 param_2)

{
  int *piVar1;
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
  piVar1 = param_1;
  _spltty();
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined2 *)(*param_1 + 2) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  *(undefined *)(param_1 + 5) = 7;
  *(undefined *)((int)param_1 + 0x1e) = 7;
  _ttyflush(param_1[6],1);
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4085 start=0xf00c2994 */

/* WARNING: Removing unreachable block (ram,0xf00c2b78) */
/* WARNING: Removing unreachable block (ram,0xf00c2bb4) */
/* WARNING: Removing unreachable block (ram,0xf00c2b70) */

undefined8 sub_F00C2994(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  sword *psVar8;
  undefined4 unaff_l1;
  byte bVar9;
  byte bVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar11;
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
  psVar8 = (sword *)*param_1;
  iVar11 = *(int *)(param_1[6] + 0x34);
  if (psVar8 != (sword *)0x0) {
    pbVar5 = (byte *)(psVar8 + psVar8[1] * 6 + 2);
    if (_ms_speedlaw != 0) {
      iVar6 = _ms_speedlimit;
      if (*(sword *)(param_1 + 7) != 0) {
        iVar6 = _ms_speedlimit << 1;
      }
      iVar4 = (int)*(char *)(psVar8 + psVar8[1] * 6 + 2);
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar7 = (int)(char)pbVar5[1];
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if ((iVar6 < iVar4) || (iVar6 < iVar7)) {
        _ms_speed_count._0_4_ = _ms_speed_count._0_4_ + 1;
      }
      if (iVar6 < iVar4) {
        iVar4 = iVar4 - iVar6 >> 1;
        if (0 < (char)*pbVar5) {
          iVar4 = -iVar4;
        }
        iVar4 = (char)*pbVar5 + iVar4;
        if (_ms_maxspeed < iVar4) {
          *pbVar5 = (byte)_ms_maxspeed;
        }
        else {
          iVar3 = -_ms_maxspeed;
          if (-_ms_maxspeed <= iVar4) {
            iVar3 = iVar4;
          }
          *pbVar5 = (byte)iVar3;
        }
      }
      if (iVar6 < iVar7) {
        iVar6 = iVar7 - iVar6 >> 1;
        if (0 < (char)pbVar5[1]) {
          iVar6 = -iVar6;
        }
        iVar6 = (char)pbVar5[1] + iVar6;
        if (_ms_maxspeed < iVar6) {
          pbVar5[1] = (byte)_ms_maxspeed;
        }
        else {
          iVar4 = -_ms_maxspeed;
          if (-_ms_maxspeed <= iVar6) {
            iVar4 = iVar6;
          }
          pbVar5[1] = (byte)iVar4;
        }
      }
    }
    bVar1 = pbVar5[2];
    if (*(sword *)(param_1 + 7) == 0) {
      bVar10 = 0;
      bVar9 = 0;
    }
    else {
      bVar9 = *pbVar5 & 1;
      bVar10 = pbVar5[1] & 1;
      *pbVar5 = (char)*pbVar5 >> 1;
      pbVar5[1] = (char)pbVar5[1] >> 1;
    }
    sVar2 = psVar8[1];
    psVar8[1] = sVar2 + 1;
    pbVar5 = pbVar5 + 0xc;
    if (*psVar8 <= (sword)(sVar2 + 1)) {
      psVar8[1] = 0;
      pbVar5 = (byte *)(psVar8 + 2);
    }
    if (psVar8[1] == *(sword *)(param_1 + 2)) {
      if (_ms_overrun_msg != 0) {
        _printf(aMouseBufferFlu);
      }
      sub_F00C2698(param_1);
      pbVar5 = (byte *)(psVar8 + 2);
      _ms_overrun_cnt = _ms_overrun_cnt + 1;
      *(byte *)(psVar8 + 3) = bVar1;
    }
    else {
      pbVar5[2] = bVar1;
    }
    *pbVar5 = bVar9;
    pbVar5[1] = bVar10;
    iVar6 = *(int *)(iVar11 + 0x34);
    if (iVar6 != 0) {
      _MouseIntHandler(iVar6,*(undefined4 *)(iVar11 + 0x38),param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4086 start=0xf00c2bc4 */

/* WARNING: Removing unreachable block (ram,0xf00c2bf8) */

undefined8 sub_F00C2BC4(int param_1,undefined4 param_2)

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
  undefined *puVar2;
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
  iVar1 = 0;
  puVar2 = _msdata;
  do {
    iVar1 = iVar1 + 1;
    if (*(int *)(puVar2 + 0x18) == param_1) goto locret_F00C2C04;
    puVar2 = puVar2 + 0x34;
  } while (iVar1 < 1);
  _printf(aMstptomsdCalle);
  puVar2 = (undefined *)0x0;
locret_F00C2C04:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4087 start=0xf00c2c0c */

undefined8 sub_F00C2C0C(int param_1,undefined4 param_2)

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
  uVar1 = 0xc;
  if ((param_1 != 9) && (param_1 == 0xc)) {
    uVar1 = 9;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4088 start=0xf00c2c34 */

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
/* GHIDRADEC_FUNCTION index=4089 start=0xf00c2f04 */

/* WARNING: Removing unreachable block (ram,0xf00c2fe0) */
/* WARNING: Removing unreachable block (ram,0xf00c3098) */
/* WARNING: Removing unreachable block (ram,0xf00c2fd0) */

undefined8 sub_F00C2F04(char *param_1,undefined4 *param_2,uint *param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 unaff_l3;
  int iVar11;
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
  bool bVar12;
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
  bVar2 = false;
  iVar11 = 0;
  cVar1 = *param_1;
  pcVar8 = param_1;
  while( true ) {
    iVar7 = (int)cVar1;
    pcVar9 = pcVar8 + 1;
    if (((iVar7 == 0x20) || ((iVar7 - 9U & 0xff) < 2)) || (bVar12 = false, iVar7 == 10)) {
      bVar12 = true;
    }
    if (!bVar12) break;
    cVar1 = *pcVar9;
    pcVar8 = pcVar9;
  }
  if (iVar7 == 0x2d) {
    cVar1 = *pcVar9;
    bVar2 = true;
  }
  else {
    if (iVar7 != 0x2b) goto loc_F00C2F84;
    cVar1 = *pcVar9;
  }
  iVar7 = (int)cVar1;
  pcVar9 = pcVar8 + 2;
loc_F00C2F84:
  bVar12 = true;
  if ((iVar7 == 0x30) && ((*pcVar9 == 'x' || (bVar12 = true, *pcVar9 == 'X')))) {
    iVar7 = (int)pcVar9[1];
    iVar11 = 0x10;
    pcVar9 = pcVar9 + 2;
    bVar12 = false;
  }
  if ((bVar12) && (iVar11 = 10, iVar7 == 0x30)) {
    iVar11 = 8;
  }
  uVar3 = 0xffffffff;
  .udiv(0xffffffff,iVar11);
  iVar4 = -1;
  .urem(0xffffffff,iVar11);
  uVar6 = 0;
  iVar10 = 0;
  do {
    uVar5 = iVar7 - 0x30;
    if (9 < (uVar5 & 0xff)) {
      if (((iVar7 - 0x41U & 0xff) < 0x1a) || (bVar12 = false, (iVar7 - 0x61U & 0xff) < 0x1a)) {
        bVar12 = true;
      }
      if (!bVar12) {
loc_F00C30B4:
        if (iVar10 < 0) {
          uVar6 = 0xffffffff;
        }
        else if (bVar2) {
          uVar6 = -uVar6;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar10 != 0) {
            param_1 = pcVar9 + -1;
          }
          *param_2 = param_1;
        }
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar6;
        }
        return CONCAT44(param_2,(uint)(0 < iVar10));
      }
      uVar5 = iVar7 - 0x37;
      if (0x19 < (iVar7 - 0x41U & 0xff)) {
        uVar5 = iVar7 - 0x57;
      }
    }
    if (iVar11 <= (int)uVar5) goto loc_F00C30B4;
    if (iVar10 < 0) {
loc_F00C308C:
      iVar10 = -1;
    }
    else if (uVar3 < uVar6) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
      if ((uVar6 == uVar3) && (iVar4 < (int)uVar5)) goto loc_F00C308C;
      .umul(uVar6,iVar11);
      uVar6 = uVar6 + uVar5;
    }
    iVar7 = (int)*pcVar9;
    pcVar9 = pcVar9 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4090 start=0xf00c310c */

undefined8 sub_F00C310C(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=4091 start=0xf00c3334 */

/* WARNING: Removing unreachable block (ram,0xf00c38ac) */
/* WARNING: Removing unreachable block (ram,0xf00c3a64) */
/* WARNING: Removing unreachable block (ram,0xf00c3a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c39f4) */
/* WARNING: Removing unreachable block (ram,0xf00c383c) */
/* WARNING: Removing unreachable block (ram,0xf00c3814) */
/* WARNING: Removing unreachable block (ram,0xf00c39bc) */
/* WARNING: Removing unreachable block (ram,0xf00c37dc) */
/* WARNING: Removing unreachable block (ram,0xf00c37b4) */
/* WARNING: Removing unreachable block (ram,0xf00c379c) */
/* WARNING: Removing unreachable block (ram,0xf00c3780) */
/* WARNING: Removing unreachable block (ram,0xf00c3754) */
/* WARNING: Removing unreachable block (ram,0xf00c3728) */
/* WARNING: Removing unreachable block (ram,0xf00c398c) */
/* WARNING: Removing unreachable block (ram,0xf00c36e4) */
/* WARNING: Removing unreachable block (ram,0xf00c36ac) */
/* WARNING: Removing unreachable block (ram,0xf00c3964) */
/* WARNING: Removing unreachable block (ram,0xf00c393c) */
/* WARNING: Removing unreachable block (ram,0xf00c38fc) */
/* WARNING: Removing unreachable block (ram,0xf00c38cc) */
/* WARNING: Removing unreachable block (ram,0xf00c3638) */
/* WARNING: Removing unreachable block (ram,0xf00c35e4) */
/* WARNING: Removing unreachable block (ram,0xf00c35c0) */
/* WARNING: Removing unreachable block (ram,0xf00c3558) */
/* WARNING: Removing unreachable block (ram,0xf00c3520) */
/* WARNING: Removing unreachable block (ram,0xf00c34d0) */
/* WARNING: Removing unreachable block (ram,0xf00c34b8) */
/* WARNING: Removing unreachable block (ram,0xf00c3490) */
/* WARNING: Removing unreachable block (ram,0xf00c3440) */
/* WARNING: Removing unreachable block (ram,0xf00c340c) */
/* WARNING: Removing unreachable block (ram,0xf00c33e0) */
/* WARNING: Removing unreachable block (ram,0xf00c338c) */
/* WARNING: Removing unreachable block (ram,0xf00c3370) */
/* WARNING: Removing unreachable block (ram,0xf00c33a4) */
/* WARNING: Removing unreachable block (ram,0xf00c33f4) */
/* WARNING: Removing unreachable block (ram,0xf00c3424) */
/* WARNING: Removing unreachable block (ram,0xf00c3470) */
/* WARNING: Removing unreachable block (ram,0xf00c34a8) */
/* WARNING: Removing unreachable block (ram,0xf00c34c4) */
/* WARNING: Removing unreachable block (ram,0xf00c34e4) */
/* WARNING: Removing unreachable block (ram,0xf00c3528) */
/* WARNING: Removing unreachable block (ram,0xf00c3570) */
/* WARNING: Removing unreachable block (ram,0xf00c35dc) */
/* WARNING: Removing unreachable block (ram,0xf00c3600) */
/* WARNING: Removing unreachable block (ram,0xf00c3660) */
/* WARNING: Removing unreachable block (ram,0xf00c38e0) */
/* WARNING: Removing unreachable block (ram,0xf00c3918) */
/* WARNING: Removing unreachable block (ram,0xf00c3950) */
/* WARNING: Removing unreachable block (ram,0xf00c367c) */
/* WARNING: Removing unreachable block (ram,0xf00c36c0) */
/* WARNING: Removing unreachable block (ram,0xf00c3700) */
/* WARNING: Removing unreachable block (ram,0xf00c371c) */
/* WARNING: Removing unreachable block (ram,0xf00c3738) */
/* WARNING: Removing unreachable block (ram,0xf00c3764) */
/* WARNING: Removing unreachable block (ram,0xf00c3794) */
/* WARNING: Removing unreachable block (ram,0xf00c37a4) */
/* WARNING: Removing unreachable block (ram,0xf00c37c8) */
/* WARNING: Removing unreachable block (ram,0xf00c37f0) */
/* WARNING: Removing unreachable block (ram,0xf00c3804) */
/* WARNING: Removing unreachable block (ram,0xf00c382c) */
/* WARNING: Removing unreachable block (ram,0xf00c39d8) */
/* WARNING: Removing unreachable block (ram,0xf00c3a10) */
/* WARNING: Removing unreachable block (ram,0xf00c3a48) */
/* WARNING: Removing unreachable block (ram,0xf00c386c) */
/* WARNING: Removing unreachable block (ram,0xf00c388c) */
/* WARNING: Removing unreachable block (ram,0xf00c3354) */

undefined8 sub_F00C3334(undefined4 param_1)

{
  undefined (*pauVar1) [12];
  undefined (*pauVar2) [14];
  undefined (*pauVar3) [14];
  undefined (*pauVar4) [14];
  int iVar5;
  undefined (*pauVar6) [15];
  undefined (*pauVar7) [12];
  uint uVar8;
  undefined (*pauVar9) [14];
  undefined (*pauVar10) [14];
  undefined *puVar11;
  undefined (*pauVar12) [14];
  undefined (*pauVar13) [11];
  char cVar14;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined (*pauVar15) [12];
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined (*pauVar16) [12];
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar17;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar18;
  undefined4 unaff_i1;
  undefined (*pauVar19) [11];
  undefined4 unaff_i2;
  int iVar20;
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
  pauVar15 = (undefined (*) [12])0x0;
  pauVar19 = (undefined (*) [11])0x0;
  pauVar16 = (undefined (*) [12])0x0;
  *(undefined *)((int)register0x00000038 + -0x19) = 0;
  *(undefined *)((int)register0x00000038 + -0x39) = 0;
  iVar20 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  pauVar1 = (undefined (*) [12])0x80;
  _IOMalloc();
  pauVar2 = paIoconfigtable;
  _objc_msgSend(paIoconfigtable,paNewforconfigda,param_1);
  uVar18 = paValueforstring;
  pauVar3 = pauVar2;
  _objc_msgSend();
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,uVar18,&aDynamic);
  if (pauVar4 != (undefined (*) [14])0x0) {
    if (((*pauVar4)[0] == 'Y') || ((*pauVar4)[0] == 'y')) {
      _objc_msgSend(_autoConfigTables,paAddobject,pauVar2);
      _objc_msgSend(pauVar2,paFreestring,pauVar4);
      uVar18 = 1;
      goto locret_F00C3A70;
    }
    _objc_msgSend(pauVar2,paFreestring,pauVar4);
  }
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aPromName);
  *(undefined (**) [14])((int)register0x00000038 + -0x34) = pauVar4;
  if (pauVar4 == (undefined (*) [14])0x0) {
loc_F00C3454:
    *(undefined *)((int)register0x00000038 + -0x39) = 1;
  }
  else {
    iVar5 = *(int *)((int)register0x00000038 + -0x34);
    _strcmp(iVar5,&aPseudo);
    if (iVar5 == 0) goto loc_F00C3454;
  }
  uVar18 = paValueforstring;
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aClassNames);
  if (pauVar4 == (undefined (*) [14])0x0) {
    pauVar4 = pauVar2;
    _objc_msgSend(pauVar2,uVar18,aDriverName_0);
  }
  pauVar6 = paKernstringlist;
  _objc_msgSend(paKernstringlist,paAlloc);
  _objc_msgSend();
  *(undefined (**) [15])((int)register0x00000038 + -0x14) = pauVar6;
  pauVar9 = pauVar4;
  _strlen(pauVar4);
  _IOFree(pauVar4,*pauVar9 + 1);
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,uVar18,aBusType_1);
  if ((pauVar4 == (undefined (*) [14])0x0) || ((*pauVar4)[0] == '\0')) {
    *(undefined6 **)((int)register0x00000038 + -0x24) = &aSparc_4;
  }
  else {
    *(undefined (**) [14])((int)register0x00000038 + -0x24) = pauVar4;
  }
  _sprintf(pauVar1,aSkernbus_0,*(undefined4 *)((int)register0x00000038 + -0x24));
  pauVar7 = pauVar1;
  _objc_getClass();
  *(undefined (**) [12])((int)register0x00000038 + -0x2c) = pauVar7;
  if (pauVar7 == (undefined (*) [12])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x2c) = _defaultBusClass;
  }
  pauVar9 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aInstance);
  *(undefined (**) [14])((int)register0x00000038 + -0xc) = pauVar9;
  if (pauVar9 == (undefined (*) [14])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  }
  else {
    sub_F00C2F04();
    if (pauVar9 == (undefined (*) [14])0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
    else if (1 < *(int *)((int)register0x00000038 + -0x10)) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
  }
  uVar18 = paAlloc;
  iVar5 = 0;
  uVar17 = 0;
  while( true ) {
    uVar8 = *(uint *)((int)register0x00000038 + -0x14);
    _objc_msgSend(uVar8,paCount_0);
    pauVar9 = *(undefined (**) [14])((int)register0x00000038 + -0x14);
    if (uVar8 <= uVar17) break;
    _objc_msgSend(pauVar9,paStringat,uVar17);
    pauVar10 = pauVar9;
    _objc_getClass();
    if (pauVar10 == (undefined (*) [14])0x0) {
      _IOLog(aConfiguredrive,pauVar9);
      if (pauVar3 == (undefined (*) [14])0x0) goto loc_F00C39C8;
      puVar11 = aDriverSCouldNo;
      pauVar9 = pauVar3;
      goto loc_F00C39BC;
    }
    uVar8 = *(uint *)((int)register0x00000038 + -0x2c);
    if (*(char *)((int)register0x00000038 + -0x19) == '\0') {
      if ((pauVar3 != (undefined (*) [14])0x0) &&
         (pauVar12 = pauVar3, sub_F00C310C(), ((uint)pauVar12 & 0xff) == 0)) goto loc_F00C39C8;
      *(undefined *)((int)register0x00000038 + -0x19) = 1;
      uVar8 = *(uint *)((int)register0x00000038 + -0x2c);
    }
    _objc_msgSend(uVar8,paConfiguredrive,pauVar2);
    if ((uVar8 & 0xff) != 0) {
      iVar5 = 1;
      break;
    }
    pauVar12 = pauVar10;
    _objc_msgSend(pauVar10,paDevicestyle);
    if (pauVar12 == (undefined (*) [14])0x0) {
      pauVar15 = *(undefined (**) [12])((int)register0x00000038 + -0x2c);
      _objc_msgSend(pauVar15,paDevicedescript,pauVar2);
      if (pauVar15 == (undefined (*) [12])0x0) {
        puVar11 = aConfiguredrive_3;
      }
      else {
        pauVar7 = pauVar15;
        _objc_msgSend();
        cVar14 = *(char *)((int)register0x00000038 + -0x39);
        if (pauVar7 == (undefined (*) [12])0x0) {
          _objc_msgSend(pauVar15,paSetbus,_defaultBus);
          cVar14 = *(char *)((int)register0x00000038 + -0x39);
        }
        if (cVar14 == '\0') {
          iVar20 = *(int *)((int)register0x00000038 + -0x34);
          _findDeviceinfoForDevice(iVar20,*(undefined4 *)((int)register0x00000038 + -0x10));
          if (iVar20 == 0) {
            _IOLog(aConfiguredrive_1,*(undefined4 *)((int)register0x00000038 + -0x34),pauVar9);
            goto loc_F00C39C8;
          }
          _objc_msgSend(pauVar15,paAdddeviceinfo,iVar20);
        }
        pauVar7 = pauVar15;
        _objc_msgSend(pauVar15,paBus_0);
        _objc_msgSend();
        if (pauVar7 == (undefined (*) [12])0x0) {
          puVar11 = aConfiguredrive_4;
        }
        else {
          pauVar19 = paKerndevice;
          _objc_msgSend(paKerndevice,uVar18);
          _objc_msgSend();
          if (pauVar19 != (undefined (*) [11])0x0) {
            _objc_msgSend(pauVar15,paSetdevice,pauVar19);
            _sprintf(pauVar1,aIoSdevicedescr,*(undefined4 *)((int)register0x00000038 + -0x24));
            pauVar16 = pauVar1;
            _objc_getClass();
            _objc_msgSend();
            _objc_msgSend();
            if (pauVar16 != (undefined (*) [12])0x0) {
              pauVar13 = pauVar19;
              _create_dev_port(pauVar19);
              _objc_msgSend(pauVar16,paSetdeviceport,pauVar13);
              _objc_msgSend(pauVar16,paSetdeviceinfo,iVar20);
              goto loc_F00C3860;
            }
            goto loc_F00C39C8;
          }
          puVar11 = aConfiguredrive_2;
        }
      }
loc_F00C39BC:
      _IOLog(puVar11,pauVar9);
loc_F00C39C8:
      if (pauVar3 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFreestring,pauVar3);
      }
      if (pauVar4 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFreestring,pauVar4);
      }
      if (pauVar2 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFree);
      }
      if (pauVar16 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar16,paFree);
      }
      if (pauVar15 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar15,paFree);
      }
      uVar18 = paFree;
      if (pauVar19 == (undefined (*) [11])0x0) goto loc_F00C3A6C;
      goto loc_F00C3A64;
    }
    if ((undefined (*) [14])0x2 < pauVar12) {
      puVar11 = aInvalidStyleFo;
      goto loc_F00C39BC;
    }
    pauVar15 = paKerndevicedesc;
    _objc_msgSend(paKerndevicedesc,uVar18);
    _objc_msgSend();
    if (pauVar15 == (undefined (*) [12])0x0) goto loc_F00C39C8;
    pauVar16 = paIodevicedescri;
    _objc_msgSend(paIodevicedescri,uVar18);
    _objc_msgSend();
    if (pauVar16 == (undefined (*) [12])0x0) goto loc_F00C39C8;
loc_F00C3860:
    pauVar12 = pauVar10;
    _objc_msgSend(pauVar10,paRespondsto,paProbe);
    if (((uint)pauVar12 & 0xff) == 0) {
      _IOLog(aConfiguredrive_0,pauVar9);
      uVar17 = uVar17 + 1;
    }
    else {
      pauVar7 = paIodevice_0;
      _objc_msgSend(paIodevice_0,paAddloadedclass_0,pauVar10,pauVar16);
      if (pauVar7 == (undefined (*) [12])0x0) {
        iVar5 = iVar5 + 1;
      }
      uVar17 = uVar17 + 1;
    }
  }
  _IOFree(pauVar1,0x80);
  uVar18 = paFree;
  _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x14),paFree);
  if (pauVar3 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar2,paFreestring,pauVar3);
  }
  if (pauVar4 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar2,paFreestring,pauVar4);
  }
  if (iVar5 == 0) {
    if (pauVar2 != (undefined (*) [14])0x0) {
      _objc_msgSend(pauVar2,uVar18);
    }
    if (pauVar16 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar16,uVar18);
    }
    if (pauVar15 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar15,uVar18);
    }
    if (pauVar19 != (undefined (*) [11])0x0) {
loc_F00C3A64:
      _objc_msgSend(pauVar19,uVar18);
    }
loc_F00C3A6C:
    uVar18 = 0;
  }
  else {
    uVar18 = 1;
  }
locret_F00C3A70:
  return CONCAT44(pauVar19,uVar18);
}
/* GHIDRADEC_FUNCTION index=4092 start=0xf00c3a78 */

/* WARNING: Removing unreachable block (ram,0xf00c3af0) */
/* WARNING: Removing unreachable block (ram,0xf00c3ad4) */
/* WARNING: Removing unreachable block (ram,0xf00c3b04) */
/* WARNING: Removing unreachable block (ram,0xf00c3ac0) */
/* WARNING: Removing unreachable block (ram,0xf00c3aa8) */

undefined8 sub_F00C3A78(uint *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
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
  
  uVar1 = paProbe;
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
  if (param_1 != (uint *)0x0) {
    uVar2 = *param_1;
    while (uVar2 != 0) {
      uVar2 = *param_1;
      _objc_getClass();
      if (uVar2 == 0) {
        _printf(aProbeIndirectC,*param_1);
      }
      else {
        uVar3 = uVar2;
        _objc_msgSend(uVar2,paRespondsto,uVar1);
        if ((uVar3 & 0xff) == 0) {
          _printf(aProbeIndirectC_0,*param_1);
        }
        else {
          _objc_msgSend(uVar2,uVar1,param_2);
        }
      }
      param_1 = param_1 + 1;
      uVar2 = *param_1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4093 start=0xf00c3c24 */

/* WARNING: Removing unreachable block (ram,0xf00c3c4c) */

undefined8 sub_F00C3C24(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined2 *puVar2;
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
  puVar2 = &_static_KERNBOOTSTRUCT;
  iVar1 = 0;
  if (0 < (int)DAT_f0121590._0_4_) {
    do {
      iVar1 = iVar1 + 1;
      _objc_registerModule(*(undefined4 *)(puVar2 + 0xaa),0);
      puVar2 = puVar2 + 4;
    } while (iVar1 < (int)DAT_f0121590._0_4_);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4094 start=0xf00c3c88 */

/* WARNING: Removing unreachable block (ram,0xf00c3cc8) */
/* WARNING: Removing unreachable block (ram,0xf00c3cd8) */
/* WARNING: Removing unreachable block (ram,0xf00c3cb4) */

undefined8
-[SPARCKernBusInterrupt initForResource:item:shareable:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined (*pauVar1) [9];
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInitforresourc_0,param_3,
                     param_4,(int)param_5);
  pauVar1 = paKernlock;
  _objc_msgSend(paKernlock,paAlloc);
  _objc_msgSend();
  *(undefined (**) [9])(param_1 + 0x2c) = pauVar1;
  *(undefined4 *)(param_1 + 0x30) = 9;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4095 start=0xf00c3cf4 */

/* WARNING: Removing unreachable block (ram,0xf00c3d20) */
/* WARNING: Removing unreachable block (ram,0xf00c3d04) */

undefined8 -[SPARCKernBusInterrupt free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  
  uVar1 = paFree;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4096 start=0xf00c3d30 */

/* WARNING: Removing unreachable block (ram,0xf00c3d78) */
/* WARNING: Removing unreachable block (ram,0xf00c3d54) */
/* WARNING: Removing unreachable block (ram,0xf00c3d90) */
/* WARNING: Removing unreachable block (ram,0xf00c3d3c) */

undefined8
-[SPARCKernBusInterrupt attachDeviceInterrupt:](int param_1,undefined4 param_2,int param_3)

{
  undefined8 *puVar1;
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
  _objc_msgSend(param_1,paItem_0);
  if (param_3 == 0) {
    param_1 = 0;
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paAcquire);
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paAttachdevicein_0,param_3);
    puVar1 = paRelease;
    *(undefined *)(param_1 + 0x34) = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),puVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4097 start=0xf00c3da8 */

/* WARNING: Removing unreachable block (ram,0xf00c3df4) */
/* WARNING: Removing unreachable block (ram,0xf00c3dcc) */
/* WARNING: Removing unreachable block (ram,0xf00c3e0c) */
/* WARNING: Removing unreachable block (ram,0xf00c3db4) */

undefined8
-[SPARCKernBusInterrupt attachDeviceInterrupt:atLevel:]
          (int param_1,undefined4 param_2,int param_3,undefined4 param_4)

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
  _objc_msgSend(param_1,paItem_0);
  if (param_3 == 0) {
    param_1 = 0;
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paAcquire);
    *(undefined4 *)(param_1 + 0x30) = param_4;
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paAttachdevicein_0,param_3);
    uVar1 = paRelease;
    *(undefined *)(param_1 + 0x34) = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4098 start=0xf00c3e24 */

/* WARNING: Removing unreachable block (ram,0xf00c3e64) */
/* WARNING: Removing unreachable block (ram,0xf00c3e40) */
/* WARNING: Removing unreachable block (ram,0xf00c3e78) */
/* WARNING: Removing unreachable block (ram,0xf00c3e30) */

undefined8
-[SPARCKernBusInterrupt detachDeviceInterrupt:](int param_1,undefined4 param_2,undefined4 param_3)

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
  _objc_msgSend(param_1,paItem_0);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paAcquire);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paDetachdevicein,param_3);
  uVar1 = paRelease;
  *(undefined *)(param_1 + 0x34) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4099 start=0xf00c3e88 */

/* WARNING: Removing unreachable block (ram,0xf00c3ec4) */
/* WARNING: Removing unreachable block (ram,0xf00c3ea4) */
/* WARNING: Removing unreachable block (ram,0xf00c3ee4) */
/* WARNING: Removing unreachable block (ram,0xf00c3e94) */

undefined8 -[SPARCKernBusInterrupt suspend](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paItem_0);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paAcquire);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e48;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSuspend);
  if (*(char *)(param_1 + 0x35) != '\0') {
    *(undefined *)(param_1 + 0x35) = 0;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x2c),paRelease);
  return CONCAT44(param_2,param_1);
}

