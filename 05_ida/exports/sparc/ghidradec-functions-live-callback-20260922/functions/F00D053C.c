
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

