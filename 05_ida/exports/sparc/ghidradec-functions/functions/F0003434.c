
void st_chk_flt(void)

{
  int iVar1;
  uint unaff_g1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l2;
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
  undefined auStackX_0 [92];
  
  iVar1 = _active_pcb;
  if ((unaff_g1 & 2) == 0) {
    func_0xf00032f8();
    return;
  }
  uVar2 = *(uint *)(_active_pcb + 0x230);
  *(BADSPACEBASE **)(uVar2 * 4 + _active_pcb + 0x210) = register0x00000038;
  iVar3 = uVar2 * 0x40 + iVar1;
  *(qword *)(iVar3 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
  *(qword *)(iVar3 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
  *(qword *)(iVar3 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
  *(qword *)(iVar3 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
  *(qword *)(iVar3 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
  *(qword *)(iVar3 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
  *(qword *)(iVar3 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
  *(qword *)(iVar3 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
  *(uint *)(iVar1 + 0x230) = (uVar2 & 0x3ffffff) + 1;
  func_0xf00032f8();
  return;
}
