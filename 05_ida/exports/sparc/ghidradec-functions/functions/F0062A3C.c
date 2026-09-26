
/* WARNING: Removing unreachable block (ram,0xf0062a98) */
/* WARNING: Removing unreachable block (ram,0xf0062adc) */
/* WARNING: Removing unreachable block (ram,0xf0062a58) */

undefined8 _mach_port_move_member(uint *param_1,uint param_2,int param_3)

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
  uint *puVar2;
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
  if (param_1 == (uint *)0x0) {
    puVar2 = (uint *)0x10;
    goto locret_F0062AE8;
  }
  puVar2 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (puVar2 != (uint *)0x0) goto locret_F0062AE8;
  if ((**(uint **)((int)register0x00000038 + -0xc) & 0x20000) == 0) {
loc_F0062ACC:
    param_1[2] = 0;
    puVar2 = (uint *)0x11;
  }
  else {
    param_2 = (*(uint **)((int)register0x00000038 + -0xc))[1];
    if (param_3 == 0) {
      uVar1 = 0;
    }
    else {
      puVar2 = param_1;
      _ipc_entry_lookup(param_1,param_3);
      *(uint **)((int)register0x00000038 + -0xc) = puVar2;
      if (puVar2 == (uint *)0x0) {
        param_1[2] = 0;
        puVar2 = (uint *)0xf;
        goto locret_F0062AE8;
      }
      if ((*puVar2 & 0x80000) == 0) goto loc_F0062ACC;
      uVar1 = puVar2[1];
    }
    _ipc_pset_move(param_1,param_2,uVar1);
    puVar2 = param_1;
  }
locret_F0062AE8:
  return CONCAT44(param_2,puVar2);
}
