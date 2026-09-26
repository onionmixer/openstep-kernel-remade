/* GHIDRADEC_FUNCTION index=4200 start=0xf00c6884 */

/* WARNING: Removing unreachable block (ram,0xf00c6890) */

undefined8 -[IODisk lockLogicalDisks](int param_1,undefined4 param_2)

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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x11c),paLock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4201 start=0xf00c68a0 */

/* WARNING: Removing unreachable block (ram,0xf00c68ac) */

undefined8 -[IODisk unlockLogicalDisks](int param_1,undefined4 param_2)

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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x11c),paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4202 start=0xf00c68bc */

/* WARNING: Removing unreachable block (ram,0xf00c6920) */

undefined8 -[IODisk stringFromReturn:](undefined4 param_1,undefined4 param_2,int param_3)

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
  puVar1 = unk_F012EC34;
  if (DAT_f012ec38._0_4_ != 0) {
    puVar2 = DAT_f012ec38;
    do {
      if (*(int *)puVar1 == param_3) {
        puVar2 = *(undefined **)puVar2;
        goto locret_F00C692C;
      }
      puVar2 = (undefined *)((int)puVar2 + 8);
      puVar1 = (undefined *)((int)puVar1 + 8);
    } while (*(int *)puVar2 != 0);
  }
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ee8;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  _objc_msgSendSuper(puVar2,paStringfromretu);
locret_F00C692C:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4203 start=0xf00c6934 */

/* WARNING: Removing unreachable block (ram,0xf00c6988) */

undefined8 -[IODisk errnoFromReturn:](undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
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
  if (param_3 == -0x44d) {
    puVar1 = (undefined *)0x16;
  }
  else {
    if (param_3 < -0x44c) {
      if (param_3 == -0x44e) {
        puVar1 = (undefined *)0x6;
        goto locret_F00C6994;
      }
    }
    else if (param_3 == -0x44c) {
      puVar1 = (undefined *)0x6;
      goto locret_F00C6994;
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ee8;
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    _objc_msgSendSuper(puVar1,paErrnofromretur);
  }
locret_F00C6994:
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4204 start=0xf00c699c */

/* WARNING: Removing unreachable block (ram,0xf00c69d0) */

undefined8
-[IODisk requestInsertionPanelForDiskType:](undefined4 param_1,undefined4 param_2,uint param_3)

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
  if (param_3 == 1) {
    uVar1 = 0;
  }
  else if (param_3 < 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = param_2;
    if (param_3 == 2) {
      uVar1 = 0xffffffff;
    }
  }
  _volCheckRequest(param_1,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4205 start=0xf00c69e0 */

/* WARNING: Removing unreachable block (ram,0xf00c6a14) */

undefined8 -[IODisk diskIsEjecting:](undefined4 param_1,undefined4 param_2,uint param_3)

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
  if (param_3 == 1) {
    uVar1 = 0;
  }
  else if (param_3 < 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = param_2;
    if (param_3 == 2) {
      uVar1 = 0xffffffff;
    }
  }
  _volCheckEjecting(param_1,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4206 start=0xf00c6a24 */

/* WARNING: Removing unreachable block (ram,0xf00c6a28) */

undefined8 -[IODisk diskNotReady](undefined4 param_1,undefined4 param_2)

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
  _volCheckNotReady(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4207 start=0xf00c6a38 */

sqword -[IODisk needsManualPolling](undefined4 param_1,uint param_2)

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
/* GHIDRADEC_FUNCTION index=4208 start=0xf00c6a44 */

/* WARNING: Removing unreachable block (ram,0xf00c6a90) */
/* WARNING: Removing unreachable block (ram,0xf00c6a64) */

undefined8
-[IOLogicalDisk readAt:length:buffer:actualLength:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar2;
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
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  iVar1 = param_1;
  _objc_msgSend(param_1,paDiskparamcommo,param_3,param_4,
                (undefined *)((int)register0x00000038 + -0x14),
                (undefined *)((int)register0x00000038 + -0x18));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x184);
    _objc_msgSend(iVar1,paReadatLengthBu,*(undefined4 *)((int)register0x00000038 + -0x14),
                  *(undefined4 *)((int)register0x00000038 + -0x18),param_5,param_6,uVar2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4209 start=0xf00c6aa0 */

/* WARNING: Removing unreachable block (ram,0xf00c6aec) */
/* WARNING: Removing unreachable block (ram,0xf00c6ac0) */

undefined8
-[IOLogicalDisk readAsyncAt:length:buffer:pending:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar2;
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
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  iVar1 = param_1;
  _objc_msgSend(param_1,paDiskparamcommo,param_3,param_4,
                (undefined *)((int)register0x00000038 + -0x14),
                (undefined *)((int)register0x00000038 + -0x18));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x184);
    _objc_msgSend(iVar1,paReadasyncatLen,*(undefined4 *)((int)register0x00000038 + -0x14),
                  *(undefined4 *)((int)register0x00000038 + -0x18),param_5,param_6,uVar2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4210 start=0xf00c6afc */

/* WARNING: Removing unreachable block (ram,0xf00c6b40) */
/* WARNING: Removing unreachable block (ram,0xf00c6b70) */
/* WARNING: Removing unreachable block (ram,0xf00c6b0c) */

undefined8
-[IOLogicalDisk writeAt:length:buffer:actualLength:client:]
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar2 = param_1;
  _objc_msgSend(param_1,paIswriteprotect);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paDiskparamcommo,param_3,param_4,
                  (undefined *)((int)register0x00000038 + -0x14),
                  (undefined *)((int)register0x00000038 + -0x18));
    if (uVar2 == 0) {
      uVar2 = *(uint *)(param_1 + 0x184);
      _objc_msgSend(uVar2,paWriteatLengthB,*(undefined4 *)((int)register0x00000038 + -0x14),
                    *(undefined4 *)((int)register0x00000038 + -0x18),param_5,param_6,uVar1);
    }
  }
  else {
    uVar2 = 0xfffffd31;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4211 start=0xf00c6b84 */

/* WARNING: Removing unreachable block (ram,0xf00c6bc8) */
/* WARNING: Removing unreachable block (ram,0xf00c6bf8) */
/* WARNING: Removing unreachable block (ram,0xf00c6b94) */

undefined8
-[IOLogicalDisk writeAsyncAt:length:buffer:pending:client:]
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar2 = param_1;
  _objc_msgSend(param_1,paIswriteprotect);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paDiskparamcommo,param_3,param_4,
                  (undefined *)((int)register0x00000038 + -0x14),
                  (undefined *)((int)register0x00000038 + -0x18));
    if (uVar2 == 0) {
      uVar2 = *(uint *)(param_1 + 0x184);
      _objc_msgSend(uVar2,paWriteasyncatLe,*(undefined4 *)((int)register0x00000038 + -0x14),
                    *(undefined4 *)((int)register0x00000038 + -0x18),param_5,param_6,uVar1);
    }
  }
  else {
    uVar2 = 0xfffffd31;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4212 start=0xf00c6c0c */

/* WARNING: Removing unreachable block (ram,0xf00c6c18) */

undefined8 -[IOLogicalDisk updateReadyState](int param_1,undefined4 param_2)

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
  uVar1 = *(undefined4 *)(param_1 + 0x184);
  _objc_msgSend(uVar1,paUpdatereadysta);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4213 start=0xf00c6c28 */

/* WARNING: Removing unreachable block (ram,0xf00c6d00) */
/* WARNING: Removing unreachable block (ram,0xf00c6cd4) */
/* WARNING: Removing unreachable block (ram,0xf00c6ca8) */
/* WARNING: Removing unreachable block (ram,0xf00c6c7c) */
/* WARNING: Removing unreachable block (ram,0xf00c6c4c) */
/* WARNING: Removing unreachable block (ram,0xf00c6c68) */
/* WARNING: Removing unreachable block (ram,0xf00c6c94) */
/* WARNING: Removing unreachable block (ram,0xf00c6cc0) */
/* WARNING: Removing unreachable block (ram,0xf00c6ce8) */
/* WARNING: Removing unreachable block (ram,0xf00c6d10) */
/* WARNING: Removing unreachable block (ram,0xf00c6c3c) */

sqword -[IOLogicalDisk connectToPhysicalDisk:](int param_1,uint param_2,undefined4 param_3)

{
  undefined (*pauVar1) [17];
  undefined (*pauVar2) [19];
  undefined (*pauVar3) [22];
  undefined (*pauVar4) [14];
  undefined4 uVar5;
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
  *(undefined4 *)(param_1 + 0x184) = param_3;
  _objc_msgSend(param_1,paSetisphysical,0);
  uVar5 = param_3;
  _objc_msgSend(param_3,paBlocksize);
  *(undefined4 *)(param_1 + 0x18c) = uVar5;
  pauVar4 = paSetremovable;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIsremovable);
  _objc_msgSend(param_1,pauVar4,(int)(char)uVar5);
  pauVar3 = paSetformattedin;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIsformatted);
  _objc_msgSend(param_1,pauVar3,(int)(char)uVar5);
  pauVar2 = paSetwriteprotec;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIswriteprotect);
  _objc_msgSend(param_1,pauVar2,(int)(char)uVar5);
  _objc_msgSend(param_1,paSetlogicaldisk,0);
  pauVar1 = paSetdevandidinf;
  _objc_msgSend(param_3,paDevandidinfo_0);
  _objc_msgSend(param_1,pauVar1,param_3);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4214 start=0xf00c6d20 */

undefined8 -[IOLogicalDisk setPartitionBase:](int param_1,undefined4 param_2,undefined4 param_3)

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
  *(undefined4 *)(param_1 + 0x188) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4215 start=0xf00c6d30 */

/* WARNING: Removing unreachable block (ram,0xf00c6d80) */
/* WARNING: Removing unreachable block (ram,0xf00c6d64) */
/* WARNING: Removing unreachable block (ram,0xf00c6d8c) */
/* WARNING: Removing unreachable block (ram,0xf00c6d3c) */

undefined8 -[IOLogicalDisk isOpen](uint param_1,undefined4 param_2)

{
  undefined (*pauVar1) [16];
  uint uVar2;
  char cVar3;
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
  uVar2 = param_1;
  _objc_msgSend(param_1,paIsinstanceopen);
  pauVar1 = paNextlogicaldis_0;
  if ((uVar2 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paNextlogicaldis_0);
    if (uVar2 == 0) {
      iVar4 = 0;
    }
    else {
      _objc_msgSend(param_1,pauVar1);
      cVar3 = (char)param_1;
      _objc_msgSend();
      iVar4 = (int)cVar3;
    }
  }
  else {
    iVar4 = 1;
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=4216 start=0xf00c6da4 */

/* WARNING: Removing unreachable block (ram,0xf00c6dc8) */
/* WARNING: Removing unreachable block (ram,0xf00c6de8) */
/* WARNING: Removing unreachable block (ram,0xf00c6db0) */

undefined8 -[IOLogicalDisk free](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paNextlogicaldis_0);
  if (iVar1 != 0) {
    _objc_msgSend(iVar1,paFree);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f10;
  _objc_msgSendSuper(puVar2,paFree);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4217 start=0xf00c6df8 */

undefined8 -[IOLogicalDisk physicalDisk](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x184));
}
/* GHIDRADEC_FUNCTION index=4218 start=0xf00c6e08 */

undefined8 -[IOLogicalDisk physicalBlockSize](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x18c));
}
/* GHIDRADEC_FUNCTION index=4219 start=0xf00c6e18 */

undefined8 -[IOLogicalDisk setPhysicalBlockSize:](int param_1,undefined4 param_2,undefined4 param_3)

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
  *(undefined4 *)(param_1 + 0x18c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4220 start=0xf00c6e28 */

/* WARNING: Removing unreachable block (ram,0xf00c6e3c) */

undefined8 -[IOLogicalDisk isDiskReady:](int param_1,undefined4 param_2,char param_3)

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
  uVar1 = *(undefined4 *)(param_1 + 0x184);
  _objc_msgSend(uVar1,paIsdiskready,(int)param_3);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4221 start=0xf00c6e4c */

/* WARNING: Removing unreachable block (ram,0xf00c6e7c) */
/* WARNING: Removing unreachable block (ram,0xf00c6ea0) */
/* WARNING: Removing unreachable block (ram,0xf00c6e58) */

undefined8 -[IOLogicalDisk isAnyOtherOpen](int param_1,undefined4 param_2)

{
  int iVar1;
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
  uVar2 = *(uint *)(param_1 + 0x184);
  _objc_msgSend(uVar2,paNextlogicaldis_0);
  if (uVar2 == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = uVar2 - param_1;
    do {
      if ((iVar1 != 0) &&
         (uVar3 = uVar2, _objc_msgSend(uVar2,paIsinstanceopen), (uVar3 & 0xff) != 0)) {
        uVar4 = 1;
        goto locret_F00C6EB8;
      }
      _objc_msgSend(uVar2,paNextlogicaldis_0);
      iVar1 = uVar2 - param_1;
    } while (uVar2 != 0);
    uVar4 = 0;
  }
locret_F00C6EB8:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4222 start=0xf00c6ec0 */

undefined8 -[IOLogicalDisk isInstanceOpen](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 400));
}
/* GHIDRADEC_FUNCTION index=4223 start=0xf00c6ed0 */

undefined8 -[IOLogicalDisk setInstanceOpen:](int param_1,undefined4 param_2,uint param_3)

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
  *(bool *)(param_1 + 400) = (param_3 & 0xff) != 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4224 start=0xf00c6eec */

/* WARNING: Removing unreachable block (ram,0xf00c6f54) */
/* WARNING: Removing unreachable block (ram,0xf00c702c) */
/* WARNING: Removing unreachable block (ram,0xf00c7004) */
/* WARNING: Removing unreachable block (ram,0xf00c6fc4) */
/* WARNING: Removing unreachable block (ram,0xf00c6f88) */
/* WARNING: Removing unreachable block (ram,0xf00c6f14) */
/* WARNING: Removing unreachable block (ram,0xf00c6f74) */
/* WARNING: Removing unreachable block (ram,0xf00c6f98) */
/* WARNING: Removing unreachable block (ram,0xf00c6ff4) */
/* WARNING: Removing unreachable block (ram,0xf00c7014) */
/* WARNING: Removing unreachable block (ram,0xf00c6fb0) */
/* WARNING: Removing unreachable block (ram,0xf00c6f64) */
/* WARNING: Removing unreachable block (ram,0xf00c6efc) */

undefined8
-[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]
          (uint param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paName);
  iVar2 = *(int *)(param_1 + 0x184);
  _objc_msgSend(iVar2,paIsdiskready,1);
  if (iVar2 == -0x44e) {
    iVar2 = -0x44e;
  }
  else if (iVar2 == 0) {
    uVar3 = param_1;
    _objc_msgSend(param_1,paBlocksize);
    uVar4 = param_1;
    _objc_msgSend(param_1,paDisksize);
    iVar2 = param_4;
    .urem(param_4,uVar3);
    if (iVar2 == 0) {
      .udiv(param_4,uVar3);
      if ((uVar4 < param_3 + param_4) && (param_4 = uVar4 - param_3, uVar4 <= param_3)) {
        iVar2 = -0x2c2;
      }
      else {
        .udiv(uVar3,*(undefined4 *)(param_1 + 0x18c));
        .umul(param_4,uVar3);
        .umul(param_3,uVar3);
        *param_5 = param_3 + *(int *)(param_1 + 0x188);
        .umul(param_4,*(undefined4 *)(param_1 + 0x18c));
        *param_6 = param_4;
        iVar2 = 0;
      }
    }
    else {
      _IOLog(aSBytesRequeste,uVar1);
      iVar2 = -0x2c2;
    }
  }
  else {
    _objc_msgSend(param_1,paStringfromretu,iVar2);
    _IOLog(aSDevicerwcommo,uVar1,param_1);
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=4225 start=0xf00c7044 */

undefined8 +[IODiskPartition deviceStyle](undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=4226 start=0xf00c7050 */

undefined8 +[IODiskPartition requiredProtocols](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,unk_F012EC64);
}
/* GHIDRADEC_FUNCTION index=4227 start=0xf00c7064 */

/* WARNING: Removing unreachable block (ram,0xf00c748c) */
/* WARNING: Removing unreachable block (ram,0xf00c7458) */
/* WARNING: Removing unreachable block (ram,0xf00c741c) */
/* WARNING: Removing unreachable block (ram,0xf00c7400) */
/* WARNING: Removing unreachable block (ram,0xf00c73bc) */
/* WARNING: Removing unreachable block (ram,0xf00c7390) */
/* WARNING: Removing unreachable block (ram,0xf00c7368) */
/* WARNING: Removing unreachable block (ram,0xf00c7338) */
/* WARNING: Removing unreachable block (ram,0xf00c72f4) */
/* WARNING: Removing unreachable block (ram,0xf00c72b0) */
/* WARNING: Removing unreachable block (ram,0xf00c7278) */
/* WARNING: Removing unreachable block (ram,0xf00c7260) */
/* WARNING: Removing unreachable block (ram,0xf00c7220) */
/* WARNING: Removing unreachable block (ram,0xf00c71fc) */
/* WARNING: Removing unreachable block (ram,0xf00c71c8) */
/* WARNING: Removing unreachable block (ram,0xf00c71a0) */
/* WARNING: Removing unreachable block (ram,0xf00c7180) */
/* WARNING: Removing unreachable block (ram,0xf00c7154) */
/* WARNING: Removing unreachable block (ram,0xf00c7128) */
/* WARNING: Removing unreachable block (ram,0xf00c70cc) */
/* WARNING: Removing unreachable block (ram,0xf00c7094) */
/* WARNING: Removing unreachable block (ram,0xf00c70a8) */
/* WARNING: Removing unreachable block (ram,0xf00c710c) */
/* WARNING: Removing unreachable block (ram,0xf00c713c) */
/* WARNING: Removing unreachable block (ram,0xf00c716c) */
/* WARNING: Removing unreachable block (ram,0xf00c7190) */
/* WARNING: Removing unreachable block (ram,0xf00c71b4) */
/* WARNING: Removing unreachable block (ram,0xf00c71ec) */
/* WARNING: Removing unreachable block (ram,0xf00c70e8) */
/* WARNING: Removing unreachable block (ram,0xf00c7230) */
/* WARNING: Removing unreachable block (ram,0xf00c7284) */
/* WARNING: Removing unreachable block (ram,0xf00c728c) */
/* WARNING: Removing unreachable block (ram,0xf00c72c4) */
/* WARNING: Removing unreachable block (ram,0xf00c7304) */
/* WARNING: Removing unreachable block (ram,0xf00c7350) */
/* WARNING: Removing unreachable block (ram,0xf00c7378) */
/* WARNING: Removing unreachable block (ram,0xf00c73a8) */
/* WARNING: Removing unreachable block (ram,0xf00c73d0) */
/* WARNING: Removing unreachable block (ram,0xf00c7324) */
/* WARNING: Removing unreachable block (ram,0xf00c7428) */
/* WARNING: Removing unreachable block (ram,0xf00c746c) */
/* WARNING: Removing unreachable block (ram,0xf00c74a4) */
/* WARNING: Removing unreachable block (ram,0xf00c7084) */

undefined8
+[IODiskPartition probe:](undefined4 param_1,undefined (**param_2) [20],undefined (*param_3) [16])

{
  undefined (*pauVar1) [18];
  undefined (*pauVar2) [16];
  undefined (*pauVar3) [16];
  undefined (*pauVar4) [16];
  undefined *puVar5;
  undefined (*pauVar6) [16];
  undefined (*pauVar7) [13];
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined (*pauVar9) [16];
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined (*pauVar10) [16];
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined (*pauVar12) [16];
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  pauVar10 = (undefined (*) [16])0x0;
  pauVar9 = (undefined (*) [16])0x0;
  pauVar12 = (undefined (*) [16])0x0;
  *(undefined *)((int)register0x00000038 + -0x31) = 0;
  _objc_msgSend(param_3,paDirectdevice);
  pauVar2 = param_3;
  _objc_msgSend();
  pauVar6 = param_3;
  _objc_msgSend(param_3,paIsphysical_0);
  if (((uint)pauVar6 & 0xff) == 0) {
    uVar11 = 0;
    goto locret_F00C74B0;
  }
  pauVar6 = param_3;
  _objc_msgSend(param_3,paNextlogicaldis_0);
  if (pauVar6 == (undefined (*) [16])0x0) {
    pauVar6 = paIodiskpartitio_1;
    _objc_msgSend(paIodiskpartitio_1,paNew);
    _sprintf((undefined *)((int)register0x00000038 + -0x30),&aSa,pauVar2);
    _objc_msgSend(pauVar6,paSetname,(undefined *)((int)register0x00000038 + -0x30));
    _objc_msgSend(pauVar6,paSetdevicekind,aIodiskpartitio);
    _objc_msgSend(pauVar6,paSetdrivename,aIodiskpartitio_0);
    _objc_msgSend(pauVar6,paSetlocation,0);
    _objc_msgSend(pauVar6,paInit);
    _objc_msgSend(pauVar6,paRegisterdevice);
    _objc_msgSend(pauVar6,paConnecttophysi,param_3);
    _objc_msgSend(param_3,paSetlogicaldisk,pauVar6);
    pauVar6[0x1a][8] = 0;
    pauVar6[0x1a][9] = 0;
    pauVar6[0x1a][10] = 0;
    pauVar1 = paRegisterunixdi;
    _objc_msgSend(param_3,paRegisterunixdi,0);
    _objc_msgSend(pauVar6,pauVar1,0);
  }
  else {
    _objc_msgSend();
    pauVar6[0x1a][8] = 0;
    pauVar6[0x1a][9] = 0;
    pauVar6[0x1a][10] = 0;
  }
  iVar8 = 0;
  param_2 = &paSearchreserveq;
  pauVar3 = param_3;
  _objc_msgSend(param_3,paLastreadystate_0);
  do {
    pauVar4 = param_3;
    _objc_msgSend(param_3,paUpdatereadysta);
    if (pauVar4 != (undefined (*) [16])0x1) {
      if (pauVar4 < (undefined (*) [16])0x2) break;
      if (pauVar4 == (undefined (*) [16])0x2) {
        bVar13 = true;
        if (0 < iVar8) {
          _IOLog(&asc_F00FAC48);
          bVar13 = true;
        }
        goto loc_F00C740C;
      }
    }
    if (iVar8 == 0) {
      _IOLog(aSWaitingForDri,pauVar2);
    }
    else {
      _IOLog(&DAT_f00fac78);
    }
    _IOSleep(1000);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0xf);
  if (0 < iVar8) {
    _IOLog(&asc_F00FAC48);
  }
  _objc_msgSend(param_3,paSetlastreadyst,pauVar4);
  if (pauVar4 == (undefined (*) [16])0x0) {
    if (pauVar3 != (undefined (*) [16])0x0) {
      _objc_msgSend(param_3,paUpdatephysical);
    }
    pauVar3 = param_3;
    _objc_msgSend(param_3,paIsformatted);
    if (((uint)pauVar3 & 0xff) == 0) {
      puVar5 = aSDiskUnformatt;
      goto loc_F00C7324;
    }
    pauVar9 = param_3;
    _objc_msgSend(param_3,paBlocksize);
    _objc_msgSend(pauVar6,paSetphysicalblo,pauVar9);
    uVar11 = paDisksize;
    pauVar12 = param_3;
    _objc_msgSend(param_3,paDisksize);
    pauVar10 = (undefined (*) [16])0x1c5c;
    _IOMalloc();
    pauVar3 = pauVar6;
    _objc_msgSend(pauVar6,paReadlabel,pauVar10);
    if (pauVar3 == (undefined (*) [16])0x0) {
      *(undefined *)((int)register0x00000038 + -0x31) = 1;
      pauVar7 = paProbelabel;
      param_3 = pauVar10;
    }
    else {
      _IOLog(aSNoValidDiskLa,pauVar2);
      _objc_msgSend(pauVar6,paSetblocksize,pauVar9);
      pauVar7 = paSetdisksize;
      _objc_msgSend(param_3,uVar11);
    }
    _objc_msgSend(pauVar6,pauVar7,param_3);
    bVar13 = false;
  }
  else {
    puVar5 = aSDiskNotReady;
loc_F00C7324:
    _IOLog(puVar5,pauVar2);
    bVar13 = true;
  }
loc_F00C740C:
  if (!bVar13) {
    _IOLog(aSDeviceBlockSi,pauVar2,pauVar9);
    pauVar6 = (undefined (*) [16])((uint)pauVar12 >> 10);
    .umul(pauVar6,pauVar9);
    if (pauVar6 < (undefined (*) [16])0x2801) {
      puVar5 = aSDeviceCapacit_0;
      .umul(pauVar12,pauVar9);
    }
    else {
      puVar5 = aSDeviceCapacit;
      pauVar12 = pauVar6;
    }
    _IOLog(puVar5,pauVar2,(uint)pauVar12 >> 10);
  }
  if (*(char *)((int)register0x00000038 + -0x31) != '\0') {
    _IOLog(aSDiskLabelS,pauVar2,*pauVar10 + 0xc);
  }
  if (pauVar10 != (undefined (*) [16])0x0) {
    _IOFree(pauVar10,0x1c5c);
  }
  uVar11 = 1;
locret_F00C74B0:
  return CONCAT44(param_2,uVar11);
}
/* GHIDRADEC_FUNCTION index=4228 start=0xf00c74b8 */

/* WARNING: Removing unreachable block (ram,0xf00c7550) */
/* WARNING: Removing unreachable block (ram,0xf00c7674) */
/* WARNING: Removing unreachable block (ram,0xf00c760c) */
/* WARNING: Removing unreachable block (ram,0xf00c75e0) */
/* WARNING: Removing unreachable block (ram,0xf00c75ac) */
/* WARNING: Removing unreachable block (ram,0xf00c7510) */
/* WARNING: Removing unreachable block (ram,0xf00c74e4) */
/* WARNING: Removing unreachable block (ram,0xf00c74f8) */
/* WARNING: Removing unreachable block (ram,0xf00c7570) */
/* WARNING: Removing unreachable block (ram,0xf00c75b8) */
/* WARNING: Removing unreachable block (ram,0xf00c75ec) */
/* WARNING: Removing unreachable block (ram,0xf00c7634) */
/* WARNING: Removing unreachable block (ram,0xf00c7694) */
/* WARNING: Removing unreachable block (ram,0xf00c7560) */
/* WARNING: Removing unreachable block (ram,0xf00c74d0) */

undefined8 -[IODiskPartition readLabel:](uint param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar9;
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
  uVar2 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar3 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar4 = param_1;
  _objc_msgSend(param_1,paName);
  uVar9 = uVar2;
  _objc_msgSend(uVar2,paIsdiskready,1);
  if (uVar9 == 0xfffffbb2) {
    uVar9 = 0xfffffbb2;
  }
  else if (uVar9 == 0) {
    uVar4 = uVar2;
    _objc_msgSend(uVar2,paIsformatted);
    if ((uVar3 == 0) || ((char)uVar4 == '\0')) {
      uVar9 = 0xfffffbb3;
    }
    else {
      uVar5 = uVar3 + 0x1c47;
      .udiv(uVar5,uVar3);
      uVar3 = uVar5;
      .umul();
      iVar8 = 0;
      iVar7 = 0;
      param_2 = uVar3 + _page_mask & ~_page_mask;
      uVar4 = param_2;
      _IOMalloc();
      uVar6 = uVar4;
      do {
        _IOVmTaskSelf();
        uVar9 = uVar2;
        _objc_msgSend(uVar2,paReadatLengthBu,iVar7,uVar3,uVar4,
                      (undefined *)((int)register0x00000038 + -0x14),uVar6);
        uVar6 = uVar9;
        if (((uVar9 == 0) && (uVar6 = *(uint *)((int)register0x00000038 + -0x14), uVar6 == uVar3))
           && (uVar6 = uVar4, _check_label(uVar4,iVar7), uVar6 == 0)) {
          bVar1 = true;
          break;
        }
        bVar1 = false;
        if (uVar9 == 0xfffffbb2) break;
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + uVar5;
        bVar1 = false;
      } while (iVar8 < 4);
      if (bVar1) {
        *(undefined *)(param_1 + 0x1a8) = 1;
        _get_disk_label(uVar4,param_3);
        uVar9 = 0;
      }
      else if (uVar9 != 0xfffffbb2) {
        uVar9 = 0xfffffbb4;
      }
      _IOFree(uVar4,param_2);
    }
  }
  else {
    _objc_msgSend(param_1,paStringfromretu,uVar9);
    _IOLog(aSReadlabelBogu,uVar4,param_1);
  }
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=4229 start=0xf00c76a4 */

/* WARNING: Removing unreachable block (ram,0xf00c795c) */
/* WARNING: Removing unreachable block (ram,0xf00c77b0) */
/* WARNING: Removing unreachable block (ram,0xf00c7874) */
/* WARNING: Removing unreachable block (ram,0xf00c78d8) */
/* WARNING: Removing unreachable block (ram,0xf00c78ac) */
/* WARNING: Removing unreachable block (ram,0xf00c7850) */
/* WARNING: Removing unreachable block (ram,0xf00c7834) */
/* WARNING: Removing unreachable block (ram,0xf00c7808) */
/* WARNING: Removing unreachable block (ram,0xf00c77d8) */
/* WARNING: Removing unreachable block (ram,0xf00c7718) */
/* WARNING: Removing unreachable block (ram,0xf00c76f0) */
/* WARNING: Removing unreachable block (ram,0xf00c76d4) */
/* WARNING: Removing unreachable block (ram,0xf00c7708) */
/* WARNING: Removing unreachable block (ram,0xf00c7738) */
/* WARNING: Removing unreachable block (ram,0xf00c77fc) */
/* WARNING: Removing unreachable block (ram,0xf00c7824) */
/* WARNING: Removing unreachable block (ram,0xf00c7840) */
/* WARNING: Removing unreachable block (ram,0xf00c78b8) */
/* WARNING: Removing unreachable block (ram,0xf00c794c) */
/* WARNING: Removing unreachable block (ram,0xf00c7884) */
/* WARNING: Removing unreachable block (ram,0xf00c77bc) */
/* WARNING: Removing unreachable block (ram,0xf00c7970) */
/* WARNING: Removing unreachable block (ram,0xf00c76c0) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00c78d8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[IODiskPartition writeLabel:](uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined8 in_o2_3;
  undefined8 uVar7;
  undefined4 unaff_l0;
  int *piVar8;
  undefined4 unaff_l1;
  int iVar9;
  uint uVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar13;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  piVar6 = (int *)((qword)in_o2_3 >> 0x20);
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
  iVar11 = 0;
  uVar10 = 0;
  uVar13 = 0;
  uVar1 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar2 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar12 = param_1;
  _objc_msgSend(param_1,paChecksafeconfi,aWritelabel);
  if (uVar12 != 0) goto locret_F00C7978;
  _objc_msgSend(uVar1,paLocklogicaldis);
  uVar12 = uVar1;
  _objc_msgSend(uVar1,paIsformatted);
  if ((uVar12 & 0xff) == 0) {
    uVar12 = 0xfffffd36;
  }
  else {
    _objc_msgSend(param_1,paFreepartitions);
    *(undefined *)(param_1 + 0x1a8) = 0;
    iVar5 = *piVar6;
    if ((iVar5 == 0x4e655854) || (iVar5 == 0x646c5632)) {
      param_2 = 0x1c48;
      piVar8 = piVar6 + 0x716;
      iVar5 = 0x1c46;
    }
    else {
      if (iVar5 != 0x646c5633) {
        uVar12 = 0xfffffd3e;
        _objc_msgSend(param_1,paName);
        _IOLog(aSWritelabelBad,param_1);
        goto loc_F00C7958;
      }
      param_2 = 0x230;
      piVar8 = piVar6 + 0x90;
      iVar5 = 0x22e;
    }
    _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
    piVar6[1] = 0;
    iVar3 = uVar2 + 0x1c47;
    uVar7 = *(undefined8 *)((int)register0x00000038 + -0x18);
    piVar6[10] = (int)uVar7;
    *(undefined2 *)piVar8 = 0;
    .udiv(iVar3,uVar2);
    iVar4 = iVar3;
    .umul();
    uVar13 = iVar4 + _page_mask & ~_page_mask;
    uVar10 = uVar13;
    _IOMalloc();
    _put_disk_label(piVar6,uVar10);
    uVar12 = uVar10;
    _checksum16(uVar10,param_2 >> 1);
    *(sword *)(uVar10 + iVar5) = (sword)uVar12;
    uVar2 = uVar10;
    _check_label(uVar10,0);
    if (uVar2 == 0) {
      iVar9 = 0;
      iVar5 = 0;
      .umul(0,iVar3);
      do {
        *(int *)(uVar10 + 4) = iVar5;
        _IOVmTaskSelf();
        uVar12 = uVar1;
        _objc_msgSend(uVar1,paWriteatLengthB,iVar5,(int)uVar7,uVar10,
                      (undefined *)((int)register0x00000038 + -0x1c));
        if ((uVar12 == 0) && (*(int *)((int)register0x00000038 + -0x1c) == iVar4)) {
          iVar11 = iVar11 + 1;
        }
        if (uVar12 == 0xfffffbb2) break;
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + iVar3;
      } while (iVar9 < 4);
      if (iVar11 == 0) {
        if (uVar12 == 0xfffffbb2) {
          uVar12 = 0xfffffbb2;
        }
        else {
          uVar12 = 0xfffffd36;
        }
      }
      else {
        *(undefined *)(param_1 + 0x1a8) = 1;
        uVar12 = 0;
        _objc_msgSend(param_1,paProbelabel,piVar6);
      }
    }
    else {
      uVar12 = 0xfffffd3e;
      _objc_msgSend(param_1,paName);
      _IOLog(aSWritelabelBad_0,param_1,uVar2);
    }
  }
loc_F00C7958:
  _objc_msgSend(uVar1,paUnlocklogicald);
  if (uVar10 != 0) {
    _IOFree(uVar10,uVar13);
  }
locret_F00C7978:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=4230 start=0xf00c7980 */

/* WARNING: Removing unreachable block (ram,0xf00c79b0) */
/* WARNING: Removing unreachable block (ram,0xf00c7990) */

undefined8 -[IODiskPartition free](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paUnregisterunix,*(undefined4 *)(param_1 + 0x1a4));
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4231 start=0xf00c79c0 */

/* WARNING: Removing unreachable block (ram,0xf00c7a54) */
/* WARNING: Removing unreachable block (ram,0xf00c7a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c79e8) */
/* WARNING: Removing unreachable block (ram,0xf00c7a04) */
/* WARNING: Removing unreachable block (ram,0xf00c7a3c) */
/* WARNING: Removing unreachable block (ram,0xf00c7a64) */
/* WARNING: Removing unreachable block (ram,0xf00c79cc) */

undefined8 -[IODiskPartition eject](uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar2 = param_1;
  _objc_msgSend(param_1,paChecksafeconfi,&aEject);
  if (uVar2 == 0) {
    _objc_msgSend(param_1,paFreepartitions);
    *(undefined *)(param_1 + 0x1a8) = 0;
    *(uint *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetformattedin,0);
    uVar2 = uVar1;
    _objc_msgSend(uVar1,paNeedsmanualpol);
    if ((uVar2 & 0xff) != 0) {
      _vol_check_manual_poll();
    }
    _objc_msgSend(uVar1,paEjectphysical);
    uVar2 = uVar1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4232 start=0xf00c7a74 */

/* WARNING: Removing unreachable block (ram,0xf00c7ae0) */
/* WARNING: Removing unreachable block (ram,0xf00c7ab4) */
/* WARNING: Removing unreachable block (ram,0xf00c7ad4) */

undefined8
-[IODiskPartition readAt:length:buffer:actualLength:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    _objc_msgSend(param_1,paName,param_3,param_4,param_5,param_6);
    _IOLog(aSReadAttemptWi,param_1);
    puVar1 = (undefined *)0xfffffd3e;
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper(puVar1,paReadatLengthBu);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4233 start=0xf00c7af4 */

/* WARNING: Removing unreachable block (ram,0xf00c7b60) */
/* WARNING: Removing unreachable block (ram,0xf00c7b34) */
/* WARNING: Removing unreachable block (ram,0xf00c7b54) */

undefined8
-[IODiskPartition readAsyncAt:length:buffer:pending:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    _objc_msgSend(param_1,paName,param_3,param_4,param_5,param_6);
    _IOLog(aSReadAttemptWi,param_1);
    puVar1 = (undefined *)0xfffffd3e;
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper(puVar1,paReadasyncatLen);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4234 start=0xf00c7b74 */

/* WARNING: Removing unreachable block (ram,0xf00c7be0) */
/* WARNING: Removing unreachable block (ram,0xf00c7bb4) */
/* WARNING: Removing unreachable block (ram,0xf00c7bd4) */

undefined8
-[IODiskPartition writeAt:length:buffer:actualLength:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    _objc_msgSend(param_1,paName,param_3,param_4,param_5,param_6);
    _IOLog(aSWriteAttemptW,param_1);
    puVar1 = (undefined *)0xfffffd3e;
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper(puVar1,paWriteatLengthB);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4235 start=0xf00c7bf4 */

/* WARNING: Removing unreachable block (ram,0xf00c7c60) */
/* WARNING: Removing unreachable block (ram,0xf00c7c34) */
/* WARNING: Removing unreachable block (ram,0xf00c7c54) */

undefined8
-[IODiskPartition writeAsyncAt:length:buffer:pending:client:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

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
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    _objc_msgSend(param_1,paName,param_3,param_4,param_5,param_6);
    _IOLog(aSWriteAttemptW,param_1);
    puVar1 = (undefined *)0xfffffd3e;
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper(puVar1,paWriteasyncatLe);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4236 start=0xf00c7c74 */

/* WARNING: Removing unreachable block (ram,0xf00c7cf0) */
/* WARNING: Removing unreachable block (ram,0xf00c7cc8) */
/* WARNING: Removing unreachable block (ram,0xf00c7ca8) */
/* WARNING: Removing unreachable block (ram,0xf00c7ce0) */
/* WARNING: Removing unreachable block (ram,0xf00c7d00) */
/* WARNING: Removing unreachable block (ram,0xf00c7c88) */

undefined8 -[IODiskPartition setFormatted:](int param_1,undefined4 param_2,char param_3)

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
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar2 = param_1;
  _objc_msgSend(param_1,paChecksafeconfi,aSetformatted);
  if (iVar2 == 0) {
    iVar2 = param_1;
    _objc_msgSend(param_1,paPhysicaldisk_0);
    uVar1 = paSetformattedin;
    iVar3 = (int)param_3;
    _objc_msgSend();
    if (iVar3 != 0) {
      _objc_msgSend(iVar2,paUpdatephysical);
    }
    _objc_msgSend(iVar2,uVar1,iVar3);
    _objc_msgSend(param_1,uVar1,iVar3);
    iVar2 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=4237 start=0xf00c7d14 */

/* WARNING: Removing unreachable block (ram,0xf00c7d4c) */
/* WARNING: Removing unreachable block (ram,0xf00c7d20) */

undefined8 -[IODiskPartition setFormattedInternal:](int param_1,undefined4 param_2,char param_3)

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
  _objc_msgSend(param_1,paFreepartitions);
  *(undefined *)(param_1 + 0x1a8) = 0;
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetformattedin,(int)param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4238 start=0xf00c7d5c */

undefined8 -[IODiskPartition isBlockDeviceOpen](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x1a9));
}
/* GHIDRADEC_FUNCTION index=4239 start=0xf00c7d6c */

/* WARNING: Removing unreachable block (ram,0xf00c7da0) */

undefined8 -[IODiskPartition setBlockDeviceOpen:](int param_1,undefined4 param_2,uint param_3)

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
  *(bool *)(param_1 + 0x1a9) = (param_3 & 0xff) != 0;
  _objc_msgSend(param_1,paSetinstanceope,(*(uint *)(param_1 + 0x1a8) & 0xffff00) != 0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4240 start=0xf00c7db0 */

undefined8 -[IODiskPartition isRawDeviceOpen](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x1aa));
}
/* GHIDRADEC_FUNCTION index=4241 start=0xf00c7dc0 */

/* WARNING: Removing unreachable block (ram,0xf00c7df4) */

undefined8 -[IODiskPartition setRawDeviceOpen:](int param_1,undefined4 param_2,uint param_3)

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
  *(bool *)(param_1 + 0x1aa) = (param_3 & 0xff) != 0;
  _objc_msgSend(param_1,paSetinstanceope,(*(uint *)(param_1 + 0x1a8) & 0xffff00) != 0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4242 start=0xf00c7e04 */

/* WARNING: Removing unreachable block (ram,0xf00c7e3c) */
/* WARNING: Removing unreachable block (ram,0xf00c7f08) */
/* WARNING: Removing unreachable block (ram,0xf00c7ee4) */
/* WARNING: Removing unreachable block (ram,0xf00c7ec4) */
/* WARNING: Removing unreachable block (ram,0xf00c7e98) */
/* WARNING: Removing unreachable block (ram,0xf00c7e6c) */
/* WARNING: Removing unreachable block (ram,0xf00c7eac) */
/* WARNING: Removing unreachable block (ram,0xf00c7ed4) */
/* WARNING: Removing unreachable block (ram,0xf00c7ef4) */
/* WARNING: Removing unreachable block (ram,0xf00c7f14) */
/* WARNING: Removing unreachable block (ram,0xf00c7e48) */
/* WARNING: Removing unreachable block (ram,0xf00c7e14) */

undefined8 -[IODiskPartition _probeLabel:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  _objc_msgSend(param_1,paPhysicaldisk_0);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    iVar4 = 1;
    iVar5 = 0xf0;
    _objc_msgSend(param_1,paInitpartitionD,0,param_3 + 0x2c);
    uVar1 = paSetlogicaldisk;
    iVar2 = param_1;
    do {
      iVar3 = iVar2;
      if (0 < *(int *)(param_3 + iVar5 + 4)) {
        iVar3 = paIodiskpartitio_1;
        _objc_msgSend(paIodiskpartitio_1,paNew);
        _objc_msgSend();
        _objc_msgSend(iVar3,paInitpartitionD,iVar4,param_3 + 0x2c);
        _objc_msgSend(iVar3,paInit);
        _objc_msgSend(iVar3,paRegisterdevice);
        _objc_msgSend(iVar2,uVar1,iVar3);
        _objc_msgSend(param_1,paPhysicaldisk_0);
        _objc_msgSend();
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
      iVar2 = iVar3;
    } while (iVar4 < 7);
  }
  else {
    iVar2 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSProbelabelOnP,iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4243 start=0xf00c7f34 */

/* WARNING: Removing unreachable block (ram,0xf00c80b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8088) */
/* WARNING: Removing unreachable block (ram,0xf00c8068) */
/* WARNING: Removing unreachable block (ram,0xf00c8040) */
/* WARNING: Removing unreachable block (ram,0xf00c8014) */
/* WARNING: Removing unreachable block (ram,0xf00c7fec) */
/* WARNING: Removing unreachable block (ram,0xf00c7fc0) */
/* WARNING: Removing unreachable block (ram,0xf00c7f94) */
/* WARNING: Removing unreachable block (ram,0xf00c7f6c) */
/* WARNING: Removing unreachable block (ram,0xf00c7f80) */
/* WARNING: Removing unreachable block (ram,0xf00c7fac) */
/* WARNING: Removing unreachable block (ram,0xf00c7fd8) */
/* WARNING: Removing unreachable block (ram,0xf00c8004) */
/* WARNING: Removing unreachable block (ram,0xf00c802c) */
/* WARNING: Removing unreachable block (ram,0xf00c805c) */
/* WARNING: Removing unreachable block (ram,0xf00c8074) */
/* WARNING: Removing unreachable block (ram,0xf00c809c) */
/* WARNING: Removing unreachable block (ram,0xf00c80d0) */
/* WARNING: Removing unreachable block (ram,0xf00c7f50) */

undefined8
-[IODiskPartition _initPartition:disktab:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined (*pauVar1) [9];
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar6 = param_3 * 0x30 + 0x94;
  iVar2 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  iVar5 = iVar2;
  _objc_msgSend();
  _sprintf((undefined *)((int)register0x00000038 + -0x30),&aSC,iVar5,param_3 + 0x61);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x30));
  _objc_msgSend(param_1,paSetdrivename,aIodiskpartitio_0);
  _objc_msgSend(param_1,paSetlocation,0);
  _objc_msgSend(param_1,paSetdisksize,*(undefined4 *)(param_4 + iVar6 + 4));
  _objc_msgSend(param_1,paSetblocksize,*(undefined4 *)(param_4 + 0x30));
  pauVar1 = paSetunit;
  iVar5 = iVar2;
  _objc_msgSend(iVar2,paUnit_0);
  _objc_msgSend(param_1,pauVar1,iVar5);
  uVar3 = paSetwriteprotec;
  _objc_msgSend(iVar2,paIswriteprotect);
  _objc_msgSend(param_1,uVar3,(int)(char)iVar2);
  iVar5 = *(int *)(param_4 + iVar6) + (int)*(sword *)(param_4 + 0x44);
  iVar2 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar3 = *(undefined4 *)(param_4 + 0x30);
  .udiv(uVar3,iVar2);
  .umul(iVar5,uVar3);
  _objc_msgSend(param_1,paSetpartitionba,iVar5);
  *(int *)(param_1 + 0x1a4) = param_3;
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar4 = aIologicaldisk;
  _objc_getOrigClass();
  *(undefined **)((int)register0x00000038 + -0xc) = puVar4;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetformattedin,1);
  *(undefined *)(param_1 + 0x1a8) = 1;
  _objc_msgSend(param_1,paRegisterunixdi,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4244 start=0xf00c80e0 */

/* WARNING: Removing unreachable block (ram,0xf00c8188) */
/* WARNING: Removing unreachable block (ram,0xf00c8154) */
/* WARNING: Removing unreachable block (ram,0xf00c8134) */
/* WARNING: Removing unreachable block (ram,0xf00c8168) */
/* WARNING: Removing unreachable block (ram,0xf00c8194) */
/* WARNING: Removing unreachable block (ram,0xf00c80ec) */

undefined8 -[IODiskPartition _freePartitions](uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paNextlogicaldis_0);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    if (uVar1 == 0) {
      uVar4 = 0;
      goto locret_F00C819C;
    }
    uVar2 = uVar1;
    _objc_msgSend(uVar1,paIsopen);
    if ((uVar2 & 0xff) == 0) {
      _objc_msgSend(uVar1,paFree);
      _objc_msgSend(param_1,paSetlogicaldisk,0);
      uVar4 = 0;
      goto locret_F00C819C;
    }
    puVar3 = aSFreepartition_0;
  }
  else {
    puVar3 = aSFreepartition;
  }
  uVar4 = 0xfffffd2b;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar3,param_1);
locret_F00C819C:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4245 start=0xf00c81a4 */

/* WARNING: Removing unreachable block (ram,0xf00c81d8) */
/* WARNING: Removing unreachable block (ram,0xf00c81bc) */
/* WARNING: Removing unreachable block (ram,0xf00c81f8) */
/* WARNING: Removing unreachable block (ram,0xf00c81b0) */

undefined8 -[IODiskPartition isAnyBlockDevOpen](uint param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paPhysicaldisk_0);
  _objc_msgSend();
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    do {
      uVar1 = param_1;
      _objc_msgSend(param_1,paIsblockdeviceo);
      if ((uVar1 & 0xff) != 0) {
        uVar2 = 1;
        goto locret_F00C8210;
      }
      _objc_msgSend(param_1,paNextlogicaldis_0);
    } while (param_1 != 0);
    uVar2 = 0;
  }
locret_F00C8210:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4246 start=0xf00c8218 */

/* WARNING: Removing unreachable block (ram,0xf00c82ac) */
/* WARNING: Removing unreachable block (ram,0xf00c827c) */
/* WARNING: Removing unreachable block (ram,0xf00c82bc) */
/* WARNING: Removing unreachable block (ram,0xf00c8248) */

undefined8 -[IODiskPartition checkSafeConfig:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  if (*(int *)(param_1 + 0x1a4) == 0) {
    uVar1 = param_1;
    _objc_msgSend(param_1,paIsanyblockdevo);
    if ((uVar1 & 0xff) == 0) {
      uVar1 = param_1;
      _objc_msgSend(param_1,paIsanyotheropen);
      if ((uVar1 & 0xff) == 0) {
        uVar3 = 0;
        goto locret_F00C82C4;
      }
      puVar2 = aSSWithOtherPar;
    }
    else {
      puVar2 = aSSWithOpenBloc;
    }
  }
  else {
    puVar2 = aSSOnPartition0;
  }
  uVar3 = 0xfffffd2b;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar2,param_1,param_3);
locret_F00C82C4:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4247 start=0xf00c8424 */

/* WARNING: Removing unreachable block (ram,0xf00c8454) */
/* WARNING: Removing unreachable block (ram,0xf00c84a4) */
/* WARNING: Removing unreachable block (ram,0xf00c8428) */

undefined8
sub_F00C8424(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
            undefined2 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
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
  puVar4 = (undefined4 *)0x18;
  _IOMalloc();
  *puVar4 = param_1;
  puVar4[1] = param_2;
  puVar4[2] = param_3;
  *(undefined2 *)(puVar4 + 3) = param_4;
  uVar3 = paLock;
  uVar2 = dword_F01330B0;
  *(undefined2 *)((int)puVar4 + 0xe) = param_5;
  _objc_msgSend(uVar2,uVar3);
  if ((undefined4 **)dword_F01330A8 == &dword_F01330A8) {
    dword_F01330A8 = puVar4;
    DAT_f01330ac = puVar4;
    puVar4[4] = &dword_F01330A8;
    puVar4[5] = &dword_F01330A8;
  }
  else {
    puVar4[5] = DAT_f01330ac;
    puVar4[4] = &dword_F01330A8;
    puVar1 = (undefined4 *)((int)DAT_f01330ac + 0x10);
    DAT_f01330ac = puVar4;
    *puVar1 = puVar4;
  }
  _objc_msgSend(dword_F01330B0,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4248 start=0xf00c84b4 */

/* WARNING: Removing unreachable block (ram,0xf00c86f8) */
/* WARNING: Removing unreachable block (ram,0xf00c86b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8688) */
/* WARNING: Removing unreachable block (ram,0xf00c8664) */
/* WARNING: Removing unreachable block (ram,0xf00c863c) */
/* WARNING: Removing unreachable block (ram,0xf00c8600) */
/* WARNING: Removing unreachable block (ram,0xf00c85b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8524) */
/* WARNING: Removing unreachable block (ram,0xf00c84f8) */
/* WARNING: Removing unreachable block (ram,0xf00c84d8) */
/* WARNING: Removing unreachable block (ram,0xf00c850c) */
/* WARNING: Removing unreachable block (ram,0xf00c8558) */
/* WARNING: Removing unreachable block (ram,0xf00c85e8) */
/* WARNING: Removing unreachable block (ram,0xf00c861c) */
/* WARNING: Removing unreachable block (ram,0xf00c8654) */
/* WARNING: Removing unreachable block (ram,0xf00c8674) */
/* WARNING: Removing unreachable block (ram,0xf00c869c) */
/* WARNING: Removing unreachable block (ram,0xf00c86d4) */
/* WARNING: Removing unreachable block (ram,0xf00c8710) */
/* WARNING: Removing unreachable block (ram,0xf00c84d0) */

void sub_F00C84B4(void)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  undefined (*pauVar4) [12];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar5;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
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
  uVar7 = 1;
  puVar2 = DAT_f00fa400;
  while( true ) {
    sub_F00C8724();
    puVar5 = dword_F01330A0;
    _vol_check_manual_poll();
    if ((uint **)puVar5 != &dword_F01330A0) break;
loc_F00C8710:
    puVar2 = (undefined *)0x3e8;
    _IOSleep();
  }
  uVar3 = *puVar5;
  do {
    _objc_msgSend(uVar3,paName);
    uVar6 = *puVar5;
    uVar3 = uVar6;
    _objc_msgSend(uVar6,paLastreadystate_0);
    if (uVar3 != 0) {
      uVar7 = *puVar5;
      _objc_msgSend(uVar7,paNeedsmanualpol);
      if ((((uVar7 & 0xff) == 0) || (puVar2 != (undefined *)0x0)) || (uVar7 = uVar3, uVar3 == 3)) {
        uVar7 = uVar6;
        _objc_msgSend(uVar6,paUpdatereadysta);
      }
    }
    if (uVar3 < 3) {
      if (uVar3 == 0) {
        puVar5 = (uint *)puVar5[6];
      }
      else if (uVar7 == 0) {
        _objc_msgSend(uVar6,paSetlastreadyst,0);
        if (*(char *)((int)puVar5 + 0xd) != '\0') {
          _vol_panel_remove(puVar5[4]);
        }
        _objc_msgSend(uVar6,paUpdatephysical);
        _objc_msgSend(uVar6,paDiskbecameread);
        pauVar4 = paIodevicedescri;
        _objc_msgSend(paIodevicedescri,paNew);
        _objc_msgSend();
        uVar3 = paIodiskpartitio_1;
        _objc_msgSend(paIodiskpartitio_1,paProbe,pauVar4);
        if ((uVar3 & 0xff) == 0) {
          _objc_msgSend(pauVar4,paFree);
          cVar1 = *(char *)((int)puVar5 + 0xd);
        }
        else {
          cVar1 = *(char *)((int)puVar5 + 0xd);
        }
        if (cVar1 == '\0') {
          sub_F00C8AA4(uVar6,(int)*(sword *)(puVar5 + 1),(int)*(sword *)((int)puVar5 + 6));
        }
        else {
          *(undefined *)((int)puVar5 + 0xd) = 0;
        }
loc_F00C8700:
        puVar5 = (uint *)puVar5[6];
      }
      else {
        puVar5 = (uint *)puVar5[6];
      }
    }
    else if (uVar3 == 3) {
      if (uVar7 == 0) {
        uVar3 = puVar5[2];
        puVar5[2] = uVar3 - 1;
        if (uVar3 - 1 == 0) {
          _objc_msgSend(uVar6,paUnit_0);
          _vol_panel_request(0,6,1,0,puVar5[5],uVar6,0,&asc_F00FA528,&asc_F00FA528,0,puVar5 + 4);
          *(undefined *)(puVar5 + 3) = 1;
        }
        goto loc_F00C8700;
      }
      _objc_msgSend(uVar6,paSetlastreadyst,2);
      if (*(char *)(puVar5 + 3) == '\0') {
        puVar5 = (uint *)puVar5[6];
      }
      else {
        *(undefined *)(puVar5 + 3) = 0;
        _vol_panel_remove(puVar5[4]);
        puVar5 = (uint *)puVar5[6];
      }
    }
    else {
      puVar5 = (uint *)puVar5[6];
    }
    if ((uint **)puVar5 == &dword_F01330A0) goto loc_F00C8710;
    uVar3 = *puVar5;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4249 start=0xf00c8724 */

/* WARNING: Removing unreachable block (ram,0xf00c8a6c) */
/* WARNING: Removing unreachable block (ram,0xf00c88d0) */
/* WARNING: Removing unreachable block (ram,0xf00c88a8) */
/* WARNING: Removing unreachable block (ram,0xf00c8878) */
/* WARNING: Removing unreachable block (ram,0xf00c89d0) */
/* WARNING: Removing unreachable block (ram,0xf00c8980) */
/* WARNING: Removing unreachable block (ram,0xf00c8a14) */
/* WARNING: Removing unreachable block (ram,0xf00c8830) */
/* WARNING: Removing unreachable block (ram,0xf00c87b8) */
/* WARNING: Removing unreachable block (ram,0xf00c881c) */
/* WARNING: Removing unreachable block (ram,0xf00c8a4c) */
/* WARNING: Removing unreachable block (ram,0xf00c89ec) */
/* WARNING: Removing unreachable block (ram,0xf00c89a0) */
/* WARNING: Removing unreachable block (ram,0xf00c8968) */
/* WARNING: Removing unreachable block (ram,0xf00c888c) */
/* WARNING: Removing unreachable block (ram,0xf00c88b8) */
/* WARNING: Removing unreachable block (ram,0xf00c8a58) */
/* WARNING: Removing unreachable block (ram,0xf00c8a94) */
/* WARNING: Removing unreachable block (ram,0xf00c8738) */

undefined8 sub_F00C8724(undefined4 param_1,undefined4 *param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined (*pauVar3) [13];
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar10;
  uint uVar11;
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
  puVar10 = (uint *)0x0;
  _objc_msgSend(dword_F01330B0,paLock);
  if ((int **)dword_F01330A8 != &dword_F01330A8) {
    param_2 = &DAT_f0133000;
    param_1 = 0xf00c8858;
    do {
      piVar2 = dword_F01330A8;
      puVar9 = (undefined4 *)dword_F01330A8[4];
      puVar7 = (undefined4 *)dword_F01330A8[5];
      puVar8 = &dword_F01330A8;
      if ((int **)puVar9 != &dword_F01330A8) {
        puVar8 = puVar9 + 4;
      }
      puVar8[1] = puVar7;
      puVar8 = &dword_F01330A8;
      if ((int **)puVar7 != &dword_F01330A8) {
        puVar8 = puVar7 + 4;
      }
      *puVar8 = puVar9;
      _objc_msgSend(dword_F01330B0,paUnlock);
      pauVar3 = paAbortrequest;
      uVar11 = piVar2[1];
      iVar5 = 0;
      if (*piVar2 == 0) {
loc_F00C8840:
        switch(iVar5) {
        case :
          uVar4 = uVar11;
          _objc_msgSend(uVar11,paUpdatereadysta);
          _objc_msgSend(uVar11,paSetlastreadyst,uVar4);
          if (uVar4 == 0) {
            sub_F00C8AA4(uVar11,(int)*(sword *)(piVar2 + 3),(int)*(sword *)((int)piVar2 + 0xe));
            uVar4 = uVar11;
            _objc_msgSend(uVar11,paIsremovable);
            if ((uVar4 & 0xff) == 0) break;
          }
          puVar10 = (uint *)0x20;
          _IOMalloc();
          *puVar10 = uVar11;
          *(undefined2 *)(puVar10 + 1) = *(undefined2 *)(piVar2 + 3);
          *(undefined2 *)((int)puVar10 + 6) = *(undefined2 *)((int)piVar2 + 0xe);
          puVar10[2] = 0;
          *(undefined *)(puVar10 + 3) = 0;
          *(undefined *)((int)puVar10 + 0xd) = 0;
          puVar10[5] = piVar2[2];
          if ((uint **)dword_F01330A0 == &dword_F01330A0) {
            dword_F01330A0 = puVar10;
            DAT_f01330a4 = puVar10;
            puVar10[6] = (uint)&dword_F01330A0;
            puVar10[7] = (uint)&dword_F01330A0;
          }
          else {
            puVar10[7] = (uint)DAT_f01330a4;
            puVar10[6] = (uint)&dword_F01330A0;
            puVar1 = DAT_f01330a4 + 6;
            DAT_f01330a4 = puVar10;
            *puVar1 = (uint)puVar10;
          }
          break;
        case :
          puVar7 = (undefined4 *)puVar10[6];
          puVar8 = (undefined4 *)puVar10[7];
          if ((uint **)puVar7 == &dword_F01330A0) {
            puVar9 = &dword_F01330A0;
          }
          else {
            puVar9 = puVar7 + 6;
          }
          puVar9[1] = puVar8;
          if ((uint **)puVar8 == &dword_F01330A0) {
            puVar8 = &dword_F01330A0;
          }
          else {
            puVar8 = puVar8 + 6;
          }
          *puVar8 = puVar7;
          _IOFree(puVar10,0x20);
          break;
        case :
          uVar4 = uVar11;
          _objc_msgSend(uVar11,paUnit_0);
          if ((*(char *)((int)puVar10 + 0xd) == '\0') &&
             (uVar6 = uVar11, _objc_msgSend(uVar11,paLastreadystate_0), uVar6 != 0)) {
            _vol_panel_disk_num(sub_F00C8BC4,0,piVar2[2],uVar4,uVar11,0,puVar10 + 4);
            *(undefined *)((int)puVar10 + 0xd) = 1;
          }
          break;
        case :
          _objc_msgSend(uVar11,paSetlastreadyst,3);
          puVar10[2] = 5;
          *(undefined *)(puVar10 + 3) = 0;
          puVar10[5] = piVar2[2];
          break;
        case :
          _objc_msgSend(uVar11,paSetlastreadyst,1);
          break;
        case :
          if (*(char *)((int)puVar10 + 0xd) != '\0') {
            *(undefined *)((int)puVar10 + 0xd) = 0;
            _objc_msgSend(uVar11,pauVar3);
          }
        }
      }
      else {
        if ((uint **)dword_F01330A0 == &dword_F01330A0) {
loc_F00C8804:
          puVar10 = (uint *)0x0;
        }
        else {
          uVar4 = *dword_F01330A0;
          puVar10 = dword_F01330A0;
          while (uVar4 != uVar11) {
            puVar10 = (uint *)puVar10[6];
            if ((uint **)puVar10 == &dword_F01330A0) goto loc_F00C8804;
            uVar4 = *puVar10;
          }
        }
        if (puVar10 != (uint *)0x0) {
          iVar5 = *piVar2;
          goto loc_F00C8840;
        }
        _objc_msgSend(uVar11,paName);
        _IOLog(aVolcheckDiskSN,uVar11,*piVar2);
      }
      _IOFree(piVar2,0x18);
      _objc_msgSend(dword_F01330B0,paLock);
    } while ((int **)dword_F01330A8 != &dword_F01330A8);
  }
  _objc_msgSend(dword_F01330B0,paUnlock);
  return CONCAT44(param_2,param_1);
}

