
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

