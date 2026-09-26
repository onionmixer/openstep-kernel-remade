
/* WARNING: Removing unreachable block (ram,0xf0045214) */
/* WARNING: Removing unreachable block (ram,0xf0045260) */

undefined8 _svckudp_dupsave(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
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
  if (_ndupreqs < 400) {
    puVar1 = (uint *)0x28;
    _kalloc();
    if (_drmru == (uint *)0x0) {
      puVar1[8] = (uint)puVar1;
    }
    else {
      puVar1[8] = *(uint *)((int)_drmru + 0x20);
      *(uint **)((int)_drmru + 0x20) = puVar1;
    }
    _ndupreqs = _ndupreqs + 1;
  }
  else {
    puVar1 = *(uint **)((int)_drmru + 0x20);
    sub_F00453CC(puVar1);
  }
  *puVar1 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  puVar1[7] = *param_1;
  puVar1[6] = param_1[1];
  puVar1[5] = param_1[2];
  uVar2 = param_1[7];
  puVar1[1] = *(uint *)(uVar2 + 0x10);
  puVar1[2] = *(uint *)(uVar2 + 0x14);
  puVar1[3] = *(uint *)(uVar2 + 0x18);
  puVar1[4] = *(uint *)(uVar2 + 0x1c);
  _drmru = puVar1;
  puVar1[9] = *(uint *)(_drhashtbl + (*puVar1 & 0x1f) * 4);
  *(uint **)(_drhashtbl + (*puVar1 & 0x1f) * 4) = puVar1;
  return CONCAT44(param_2,param_1);
}
