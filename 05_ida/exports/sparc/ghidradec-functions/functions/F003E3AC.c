
/* WARNING: Removing unreachable block (ram,0xf003e438) */
/* WARNING: Removing unreachable block (ram,0xf003e3f0) */
/* WARNING: Removing unreachable block (ram,0xf003e454) */
/* WARNING: Removing unreachable block (ram,0xf003e3cc) */

undefined8 sub_F003E3AC(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  do {
    iVar1 = param_1;
    _pmap_kgetport(param_1,0x186a5,1,0x11);
    if (iVar1 == -1) {
      iVar1 = 0xf;
locret_F003E4C4:
      return CONCAT44(param_2,iVar1);
    }
    if (iVar1 != 1) {
      while (iVar1 = param_1,
            sub_F003E138(param_1,0x186a5,1,1,_xdr_bp_path_t,
                         (undefined *)((int)register0x00000038 + 0x4c),_xdr_fhstatus,
                         (undefined *)((int)register0x00000038 + -0x30)), iVar1 == 5) {
        _printf(aMountnfsSSMoun,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c));
      }
      if (iVar1 == 0) {
        *(undefined2 *)(param_1 + 2) = 0x801;
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0x2c);
        param_4[1] = *(undefined4 *)((int)register0x00000038 + -0x28);
        param_4[2] = *(undefined4 *)((int)register0x00000038 + -0x24);
        param_4[3] = *(undefined4 *)((int)register0x00000038 + -0x20);
        param_4[4] = *(undefined4 *)((int)register0x00000038 + -0x1c);
        param_4[5] = *(undefined4 *)((int)register0x00000038 + -0x18);
        param_4[6] = *(undefined4 *)((int)register0x00000038 + -0x14);
        param_4[7] = *(undefined4 *)((int)register0x00000038 + -0x10);
        iVar1 = *(int *)((int)register0x00000038 + -0x30);
      }
      goto locret_F003E4C4;
    }
    _printf(aMountnfsSSPort,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c));
  } while( true );
}
