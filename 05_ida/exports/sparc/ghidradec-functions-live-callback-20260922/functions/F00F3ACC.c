
/* WARNING: Removing unreachable block (ram,0xf00f3ad8) */
/* WARNING: Removing unreachable block (ram,0xf00f3ad0) */

undefined8 __sel_init(undefined (*param_1) [28],int param_2,int param_3,undefined4 param_4)

{
  undefined (*pauVar1) [28];
  undefined (*pauVar2) [28];
  undefined (**ppauVar3) [28];
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
  pauVar1 = param_1;
  _NXDefaultMallocZone();
  pauVar2 = pauVar1;
  _NXDefaultMallocZone();
  (**(code **)(*pauVar1 + 4))();
  *(undefined (**) [28])*pauVar2 = param_1;
  *(undefined4 *)(*pauVar2 + 4) = 0x335;
  *(undefined4 *)(*pauVar2 + 8) = 0;
  *(int *)(*pauVar2 + 0xc) = param_2;
  *(int *)(*pauVar2 + 0x10) = param_2 + param_3;
  *(undefined4 *)(*pauVar2 + 0x14) = param_4;
  ppauVar3 = &off_F012F16C;
  pauVar1 = off_F012F16C;
  if (off_F012F16C != (undefined (*) [28])0x0) {
    while (pauVar1 != &unk_F012F150) {
      ppauVar3 = (undefined (**) [28])(*pauVar1 + 0x18);
      if (*(int *)(*pauVar1 + 0x18) == 0) goto locret_F00F3B58;
      pauVar1 = *ppauVar3;
    }
    *(undefined **)(*pauVar2 + 0x18) = unk_F012F150;
    *ppauVar3 = pauVar2;
  }
locret_F00F3B58:
  return CONCAT44(param_2 + param_3,param_1);
}

