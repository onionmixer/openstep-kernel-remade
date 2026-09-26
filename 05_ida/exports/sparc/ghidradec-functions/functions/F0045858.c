
/* WARNING: Removing unreachable block (ram,0xf00458e4) */
/* WARNING: Removing unreachable block (ram,0xf0045914) */
/* WARNING: Removing unreachable block (ram,0xf0045928) */
/* WARNING: Removing unreachable block (ram,0xf00458fc) */
/* WARNING: Removing unreachable block (ram,0xf0045864) */

undefined8 _xdr_bytes(uint *param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
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
  uVar4 = *param_2;
  puVar1 = param_1;
  _xdr_u_int(param_1,param_3);
  if (puVar1 == (uint *)0x0) {
    puVar3 = aXdrBytesSizeFa;
loc_F0045928:
    param_1 = (uint *)0x0;
    _printf(puVar3);
    goto locret_F0045930;
  }
  uVar5 = *param_3;
  uVar2 = *param_1;
  if (param_4 < uVar5) {
    if (uVar2 != 2) {
      puVar3 = aXdrBytesBadSiz;
      goto loc_F0045928;
    }
    uVar2 = *param_1;
  }
  if (uVar2 == 1) {
    if (uVar5 == 0) {
loc_F00458D4:
      param_1 = (uint *)0x1;
      goto locret_F0045930;
    }
    if (uVar4 == 0) {
      uVar4 = uVar5;
      _kalloc();
      *param_2 = uVar4;
    }
  }
  else if (1 < uVar2) {
    if (uVar2 != 2) {
      puVar3 = aXdrBytesBadOpF;
      goto loc_F0045928;
    }
    if (uVar4 != 0) {
      _kfree(uVar4,uVar5);
      *param_2 = 0;
    }
    goto loc_F00458D4;
  }
  _xdr_opaque(param_1,uVar4,uVar5);
locret_F0045930:
  return CONCAT44(param_2,param_1);
}
