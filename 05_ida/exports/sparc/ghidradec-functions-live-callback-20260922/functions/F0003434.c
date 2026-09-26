
void st_chk_flt(void)

{
  undefined (*pauVar1) [676];
  uint unaff_g1;
  uint uVar2;
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
  
  pauVar1 = _active_pcb;
  if ((unaff_g1 & 2) == 0) {
    func_0xf00032f8();
    return;
  }
  uVar2 = *(uint *)(*_active_pcb + 0x230);
  *(BADSPACEBASE **)(*_active_pcb + uVar2 * 4 + 0x210) = register0x00000038;
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
  *(qword *)(*pauVar1 + uVar2 * 0x40 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
  *(uint *)(*pauVar1 + 0x230) = (uVar2 & 0x3ffffff) + 1;
  func_0xf00032f8();
  return;
}

