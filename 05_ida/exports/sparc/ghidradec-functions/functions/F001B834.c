
/* WARNING: Removing unreachable block (ram,0xf001b850) */

undefined8 _ptcopen(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  if ((param_1 & 0xff) < 0x20) {
    iVar1 = (int)(sword)param_1;
    _pty_alloc();
    iVar1 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0x24) == 0) {
      *(code **)(iVar1 + 0x24) = _ptsstart;
      (**(code **)(DAT_f010b8f0 + *(char *)(iVar1 + 0x47) * 0x30))(iVar1,1);
      *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffbfffff | 0x10;
      puVar2 = *(undefined4 **)(DAT_f012f210 + (param_1 & 0xff) * 0x10);
      uVar3 = 0;
      *puVar2 = 0;
      *(undefined *)(puVar2 + 3) = 0;
      *(undefined *)((int)puVar2 + 0xd) = 0;
      puVar2[2] = 0;
      puVar2[1] = 0;
    }
    else {
      uVar3 = 5;
    }
  }
  else {
    uVar3 = 6;
  }
  return CONCAT44(param_2,uVar3);
}
