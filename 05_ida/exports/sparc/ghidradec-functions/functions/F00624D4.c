
/* WARNING: Removing unreachable block (ram,0xf0062524) */
/* WARNING: Removing unreachable block (ram,0xf006258c) */
/* WARNING: Removing unreachable block (ram,0xf0062500) */

undefined8 _mach_port_get_refs(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  if (param_1 == 0) {
    iVar2 = 0x10;
  }
  else if (param_3 < 5) {
    iVar2 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if ((iVar2 == 0) &&
       (iVar2 = param_1,
       _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10),
                       (undefined *)((int)register0x00000038 + -0x14)), iVar2 == 0)) {
      *(undefined4 *)(param_1 + 8) = 0;
      if ((*(uint *)((int)register0x00000038 + -0x10) & 1 << ((char)param_3 + 0x10U & 0x1f)) == 0) {
        *param_4 = 0;
      }
      else {
        if (param_3 < 4) {
          if (param_3 != 0) {
            *param_4 = 1;
            goto locret_F00625A4;
          }
          uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
        }
        else {
          uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
          if (param_3 != 4) {
            _panic(aMachPortGetRef);
            goto locret_F00625A4;
          }
        }
        *param_4 = uVar1;
      }
    }
  }
  else {
    iVar2 = 0x12;
  }
locret_F00625A4:
  return CONCAT44(param_2,iVar2);
}
