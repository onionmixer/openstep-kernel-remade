
/* WARNING: Removing unreachable block (ram,0xf0076720) */
/* WARNING: Removing unreachable block (ram,0xf0076710) */

undefined8 _calloutInitialize(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  if (dword_F0110BB0 == 0) {
    dword_F0130F20 = 0;
    DAT_f0130f30 = &dword_F0130F2C;
    dword_F0130F2C = &dword_F0130F2C;
    DAT_f0130f38 = &dword_F0130F34;
    dword_F0130F34 = &dword_F0130F34;
    DAT_f0130f28 = &dword_F0130F24;
    dword_F0130F24 = &dword_F0130F24;
    unk_F0130520._0_4_ = &dword_F0130F24;
    puVar1 = (undefined4 *)unk_F0130520;
    while( true ) {
      puVar1[1] = DAT_f0130f28;
      *DAT_f0130f28 = puVar1;
      puVar2 = puVar1 + 10;
      DAT_f0130f28 = puVar1;
      if (unk_F0130520 + 0x9ff < puVar2) break;
      *puVar2 = &dword_F0130F24;
      puVar1 = puVar2;
    }
    _kernel_thread(_kernel_task,sub_F00776A8,0);
    _set_timer_expire_func(0,sub_F00776C8);
    dword_F0110BB0 = 1;
  }
  return CONCAT44(param_2,param_1);
}
