/* GHIDRADEC_FUNCTION index=4850 start=0xf00e3dbc */

/* WARNING: Removing unreachable block (ram,0xf00e3e34) */
/* WARNING: Removing unreachable block (ram,0xf00e3e28) */

undefined8 sub_F00E3DBC(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x2c) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if (*(int *)(param_1 + 0x20) == 0x2200028) {
        *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
        uVar1 = *(undefined4 *)(param_1 + 0xc);
        _audio_port_to_stream();
        __NXAudioStreamControl();
      }
      else {
        uVar1 = 0xfffffed0;
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4851 start=0xf00e3e64 */

/* WARNING: Removing unreachable block (ram,0xf00e3e9c) */
/* WARNING: Removing unreachable block (ram,0xf00e3e90) */

undefined8 sub_F00E3E64(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_stream();
    __NXAudioStreamInfo();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4852 start=0xf00e3ee0 */

/* WARNING: Removing unreachable block (ram,0xf00e3f14) */
/* WARNING: Removing unreachable block (ram,0xf00e3f0c) */

undefined8 sub_F00E3EE0(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_stream();
    __NXAudioRemoveStream();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4853 start=0xf00e3f40 */

/* WARNING: Removing unreachable block (ram,0xf00e40b4) */
/* WARNING: Removing unreachable block (ram,0xf00e406c) */

undefined8 sub_F00E3F40(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x70) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((((((*(uint *)(param_1 + 0x18) & 0xc) == 4) &&
           (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x1c) == 0x90008)) &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) &&
         ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x2200018 &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x38) == 0x2200018)))) &&
        ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x40) == 0x2200018 &&
         ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x48) == 0x2200018 &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x50) == 0x2200018)))))) &&
       ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x58) == 0x2200018 &&
        ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x60) == 0x6200018 &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x68) == 0x2200018)))))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioPlayStream();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4854 start=0xf00e40e4 */

/* WARNING: Removing unreachable block (ram,0xf00e4148) */
/* WARNING: Removing unreachable block (ram,0xf00e413c) */

undefined8 sub_F00E40E4(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioSetStreamPeakOptions();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4855 start=0xf00e4178 */

/* WARNING: Removing unreachable block (ram,0xf00e41b0) */
/* WARNING: Removing unreachable block (ram,0xf00e41a4) */

undefined8 sub_F00E4178(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_stream();
    __NXAudioGetStreamPeak();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4856 start=0xf00e41f4 */

/* WARNING: Removing unreachable block (ram,0xf00e42cc) */
/* WARNING: Removing unreachable block (ram,0xf00e42ac) */

undefined8 sub_F00E41F4(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x48) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((((*(int *)(param_1 + 0x18) == 0x2200018) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) &&
       (((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x2200018 &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x38) == 0x6200018)) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x40) == 0x2200018)))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioRecordStream();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4857 start=0xf00e42fc */

/* WARNING: Removing unreachable block (ram,0xf00e43b0) */
/* WARNING: Removing unreachable block (ram,0xf00e4398) */

undefined8 sub_F00E42FC(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x40) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((((*(uint *)(param_1 + 0x18) & 0xc) == 4) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x1c) == 0x90008)) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) &&
       ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x6200018 &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x38) == 0x2200018)))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioPlayStreamData();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4858 start=0xf00e43e0 */

/* WARNING: Removing unreachable block (ram,0xf00e447c) */
/* WARNING: Removing unreachable block (ram,0xf00e4468) */

undefined8 sub_F00E43E0(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) == 0x38) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((((*(int *)(param_1 + 0x18) == 0x2200018) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x6200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x2200018)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioRecordStreamData();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4859 start=0xf00e44ac */

/* WARNING: Removing unreachable block (ram,0xf00e44e8) */
/* WARNING: Removing unreachable block (ram,0xf00e44dc) */

undefined8 sub_F00E44AC(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
    _audio_port_to_device();
    __NXAudioGetDeviceName();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x8081008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x8080008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = (uVar2 + 3 & 0xfffffffc) + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4860 start=0xf00e4548 */

/* WARNING: Removing unreachable block (ram,0xf00e4604) */
/* WARNING: Removing unreachable block (ram,0xf00e45e8) */

undefined8 sub_F00E4548(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  if ((*(int *)(param_1 + 4) - 0x428U < 0x401) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      uVar1 = 0xfffffed0;
      if ((*(uint *)(param_1 + 0x20) & 0xffff000c) == 0x2200008) {
        iVar2 = (*(uint *)(param_1 + 0x20) >> 4 & 0xfff) * 4;
        uVar1 = 0xfffffed0;
        if ((*(int *)(param_1 + 4) == iVar2 + 0x428) &&
           (uVar1 = 0xfffffed0, *(int *)(param_1 + iVar2 + 0x24) == 0x2201008)) {
          uVar1 = *(undefined4 *)(param_1 + 0xc);
          _audio_port_to_device();
          __NXAudioSetDeviceParameters();
        }
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4861 start=0xf00e4634 */

/* WARNING: Removing unreachable block (ram,0xf00e46b8) */
/* WARNING: Removing unreachable block (ram,0xf00e46a0) */

undefined8 sub_F00E4634(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) - 0x1cU < 0x401) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (((*(uint *)(param_1 + 0x18) & 0xffff000c) == 0x2200008) &&
       (uVar1 = 0xfffffed0,
       *(int *)(param_1 + 4) == (*(uint *)(param_1 + 0x18) >> 4 & 0xfff) * 4 + 0x1c)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_device();
      __NXAudioGetDeviceParameters();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x424;
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4862 start=0xf00e46f4 */

/* WARNING: Removing unreachable block (ram,0xf00e4730) */
/* WARNING: Removing unreachable block (ram,0xf00e4724) */

undefined8 sub_F00E46F4(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
    _audio_port_to_device();
    __NXAudioGetDeviceSupportedParameters();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4863 start=0xf00e478c */

/* WARNING: Removing unreachable block (ram,0xf00e47e4) */
/* WARNING: Removing unreachable block (ram,0xf00e47d4) */

undefined8 sub_F00E478C(int param_1,int param_2)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
      _audio_port_to_device();
      __NXAudioGetDeviceParameterValues();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4864 start=0xf00e4844 */

/* WARNING: Removing unreachable block (ram,0xf00e488c) */
/* WARNING: Removing unreachable block (ram,0xf00e4874) */

undefined8 sub_F00E4844(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
    _audio_port_to_device();
    __NXAudioGetSamplingRates();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
      *(undefined4 *)(param_2 + 0x28) = 0x2200018;
      *(undefined4 *)(param_2 + 0x30) = 0x2200018;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x38) = 0x2201008;
      *(uint *)(param_2 + 0x38) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x3c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4865 start=0xf00e490c */

/* WARNING: Removing unreachable block (ram,0xf00e4948) */
/* WARNING: Removing unreachable block (ram,0xf00e493c) */

undefined8 sub_F00E490C(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
    _audio_port_to_device();
    __NXAudioGetDataEncodings();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4866 start=0xf00e49a4 */

/* WARNING: Removing unreachable block (ram,0xf00e49d8) */
/* WARNING: Removing unreachable block (ram,0xf00e49d0) */

undefined8 sub_F00E49A4(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    _audio_port_to_device();
    __NXAudioGetChannelCountLimit();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = 0x2200018;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4867 start=0xf00e4a10 */

/* WARNING: Removing unreachable block (ram,0xf00e4ab0) */
/* WARNING: Removing unreachable block (ram,0xf00e4a98) */

undefined8 sub_F00E4A10(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  if ((*(int *)(param_1 + 4) - 0x420U < 0x401) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(uint *)(param_1 + 0x18) & 0xffff000c) == 0x2200008) {
      iVar2 = (*(uint *)(param_1 + 0x18) >> 4 & 0xfff) * 4;
      uVar1 = 0xfffffed0;
      if ((*(int *)(param_1 + 4) == iVar2 + 0x420) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + iVar2 + 0x1c) == 0x2201008)) {
        uVar1 = *(undefined4 *)(param_1 + 0xc);
        _audio_port_to_stream();
        __NXAudioSetStreamParameters();
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4868 start=0xf00e4ae0 */

/* WARNING: Removing unreachable block (ram,0xf00e4b64) */
/* WARNING: Removing unreachable block (ram,0xf00e4b4c) */

undefined8 sub_F00E4AE0(int param_1,int param_2)

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
  if ((*(int *)(param_1 + 4) - 0x1cU < 0x401) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (((*(uint *)(param_1 + 0x18) & 0xffff000c) == 0x2200008) &&
       (uVar1 = 0xfffffed0,
       *(int *)(param_1 + 4) == (*(uint *)(param_1 + 0x18) >> 4 & 0xfff) * 4 + 0x1c)) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioGetStreamParameters();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x424;
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4869 start=0xf00e4ba0 */

/* WARNING: Removing unreachable block (ram,0xf00e4bdc) */
/* WARNING: Removing unreachable block (ram,0xf00e4bd0) */

undefined8 sub_F00E4BA0(int param_1,int param_2)

{
  int iVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
    _audio_port_to_stream();
    __NXAudioGetStreamSupportedParameters();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4870 start=0xf00e4c38 */

/* WARNING: Removing unreachable block (ram,0xf00e4c90) */
/* WARNING: Removing unreachable block (ram,0xf00e4c80) */

undefined8 sub_F00E4C38(int param_1,int param_2)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0x100;
      _audio_port_to_stream();
      __NXAudioGetStreamParameterValues();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2201008;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4871 start=0xf00e4e24 */

/* WARNING: Removing unreachable block (ram,0xf00e4e28) */

undefined8 -[IODirectDevice initSPARC](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = (undefined4 *)0x4;
  _IOMalloc();
  *(undefined4 **)(param_1 + 0x118) = puVar1;
  *puVar1 = 3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4872 start=0xf00e4e44 */

/* WARNING: Removing unreachable block (ram,0xf00e4e4c) */

undefined8 -[IODirectDevice freeSPARC](int param_1,undefined4 param_2)

{
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
  _IOFree(*(undefined4 *)(param_1 + 0x118),4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4873 start=0xf00e4e5c */

undefined8 -[IOSPARCDeviceDescription getDeviceInfo](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x24));
}
/* GHIDRADEC_FUNCTION index=4874 start=0xf00e4e6c */

undefined8
-[IOSPARCDeviceDescription setDeviceInfo:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x24) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4875 start=0xf00e6a34 */

/* WARNING: Removing unreachable block (ram,0xf00e7bac) */
/* WARNING: Removing unreachable block (ram,0xf00e7c70) */
/* WARNING: Removing unreachable block (ram,0xf00e79b0) */
/* WARNING: Removing unreachable block (ram,0xf00e8088) */
/* WARNING: Removing unreachable block (ram,0xf00e7fa0) */
/* WARNING: Removing unreachable block (ram,0xf00e7d68) */
/* WARNING: Removing unreachable block (ram,0xf00e6edc) */
/* WARNING: Removing unreachable block (ram,0xf00e6ff8) */
/* WARNING: Removing unreachable block (ram,0xf00e6e48) */
/* WARNING: Removing unreachable block (ram,0xf00e7464) */
/* WARNING: Removing unreachable block (ram,0xf00e728c) */
/* WARNING: Removing unreachable block (ram,0xf00e7864) */
/* WARNING: Removing unreachable block (ram,0xf00e7780) */
/* WARNING: Removing unreachable block (ram,0xf00e7640) */
/* WARNING: Removing unreachable block (ram,0xf00e7138) */
/* WARNING: Removing unreachable block (ram,0xf00e6ad0) */
/* WARNING: Removing unreachable block (ram,0xf00e6bec) */
/* WARNING: Removing unreachable block (ram,0xf00e6a8c) */
/* WARNING: Removing unreachable block (ram,0xf00e6c3c) */
/* WARNING: Removing unreachable block (ram,0xf00e6b20) */
/* WARNING: Removing unreachable block (ram,0xf00e7534) */
/* WARNING: Removing unreachable block (ram,0xf00e7768) */
/* WARNING: Removing unreachable block (ram,0xf00e784c) */
/* WARNING: Removing unreachable block (ram,0xf00e717c) */
/* WARNING: Removing unreachable block (ram,0xf00e743c) */
/* WARNING: Removing unreachable block (ram,0xf00e7378) */
/* WARNING: Removing unreachable block (ram,0xf00e6fa8) */
/* WARNING: Removing unreachable block (ram,0xf00e6e8c) */
/* WARNING: Removing unreachable block (ram,0xf00e796c) */
/* WARNING: Removing unreachable block (ram,0xf00e7e74) */
/* WARNING: Removing unreachable block (ram,0xf00e7fb8) */
/* WARNING: Removing unreachable block (ram,0xf00e80a0) */
/* WARNING: Removing unreachable block (ram,0xf00e7ac0) */
/* WARNING: Removing unreachable block (ram,0xf00e7c98) */
/* WARNING: Removing unreachable block (ram,0xf00e8114) */
/* WARNING: Removing unreachable block (ram,0xf00e6a44) */

undefined8
-[IOFrameBufferDisplay moveCursor:frame:token:]
          (int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  byte bVar1;
  word wVar2;
  word wVar3;
  sword sVar4;
  sword sVar5;
  sword sVar6;
  sword sVar7;
  undefined (*pauVar8) [12];
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar15;
  uint uVar14;
  int iVar16;
  int *piVar17;
  undefined *puVar18;
  undefined4 *puVar19;
  char cVar21;
  undefined *puVar20;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar22;
  uint *puVar23;
  undefined4 unaff_l3;
  byte bVar24;
  undefined4 unaff_l4;
  uint *puVar25;
  byte *pbVar26;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint *puVar27;
  undefined4 unaff_l7;
  byte *pbVar28;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  byte *pbVar29;
  undefined4 unaff_i3;
  byte *pbVar30;
  uint uVar31;
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
  *(int *)((int)register0x00000038 + -0x44) = param_1;
  iVar9 = *(int *)(param_1 + 0x1fc);
  *(int *)((int)register0x00000038 + -0x4c) = iVar9;
  iVar9 = iVar9 + 4;
  _ev_try_lock();
  puVar10 = *(undefined4 **)((int)register0x00000038 + -0x4c);
  if (iVar9 == 0) goto loc_F00E811C;
  *puVar10 = param_4;
  *(undefined2 *)(puVar10 + 7) = *param_3;
  *(undefined2 *)((int)puVar10 + 0x1e) = param_3[1];
  cVar21 = *(char *)(puVar10 + 2);
  *(char *)(puVar10 + 2) = cVar21 + '\x01';
  iVar9 = *(int *)((int)register0x00000038 + -0x4c);
  if (cVar21 == '\0') {
    iVar9 = *(int *)((int)register0x00000038 + -0x44);
    _objc_msgSend(iVar9,paDisplayinfo);
    uVar13 = *(uint *)(iVar9 + 0x18);
    if (uVar13 < 4) {
      if (uVar13 < 2) {
        if (uVar13 == 1) {
          iVar11 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar11,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x14) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar16 + 0x12);
          iVar12 = *(int *)(iVar11 + 8);
          iVar9 = iVar12;
          .umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar20 = (undefined *)(iVar16 + 0x848);
          puVar18 = (undefined *)
                    (*(int *)(iVar11 + 0x14) + iVar9 +
                    ((int)*(sword *)((int)register0x00000038 + -0x18) -
                    (int)*(sword *)(iVar16 + 0x30)));
          iVar16 = (uint)*(word *)((int)register0x00000038 + -0x16) -
                   (int)*(sword *)((int)register0x00000038 + -0x18);
          iVar11 = ((uint)*(word *)((int)register0x00000038 + -0x12) -
                   (uint)*(word *)((int)register0x00000038 + -0x14)) + -1;
          iVar9 = iVar16;
          if (iVar11 * 0x10000 >> 0x10 == -1) goto loc_F00E6CDC;
          do {
            while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
              *puVar18 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar18 = puVar18 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar11 = iVar11 + -1;
            puVar18 = puVar18 + (iVar12 - (iVar16 * 0x10000 >> 0x10));
            iVar9 = iVar16;
          } while (iVar11 * 0x10000 >> 0x10 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
      else {
loc_F00E6CDC:
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
    }
    else {
      if (uVar13 == 4) {
        iVar11 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar11,paDisplayinfo);
        iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
        *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar16 + 0xc);
        *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar16 + 0xe);
        sVar4 = *(sword *)(iVar16 + 0x10);
        *(sword *)((int)register0x00000038 + -0x14) = sVar4;
        *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar16 + 0x12);
        iVar12 = *(int *)(iVar11 + 8);
        iVar9 = iVar12;
        .umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
        puVar19 = (undefined4 *)(iVar16 + 0x1048);
        puVar10 = (undefined4 *)
                  (*(int *)(iVar11 + 0x14) + iVar9 * 4 +
                  ((int)*(sword *)((int)register0x00000038 + -0x18) - (int)*(sword *)(iVar16 + 0x30)
                  ) * 4);
        iVar11 = (int)*(sword *)((int)register0x00000038 + -0x16) -
                 (int)*(sword *)((int)register0x00000038 + -0x18);
        iVar9 = (int)*(sword *)((int)register0x00000038 + -0x12) -
                (int)*(sword *)((int)register0x00000038 + -0x14);
        while (iVar9 = iVar9 + -1, iVar16 = iVar11, iVar9 != -1) {
          while (iVar16 + -1 != -1) {
            *puVar10 = *puVar19;
            puVar19 = puVar19 + 1;
            puVar10 = puVar10 + 1;
            iVar16 = iVar16 + -1;
          }
          puVar10 = puVar10 + (iVar12 - iVar11);
        }
        goto loc_F00E6CDC;
      }
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  iVar11 = *(int *)((int)register0x00000038 + -0x4c);
  if (*(char *)(iVar9 + 9) != '\0') {
    *(undefined *)(iVar9 + 9) = 0;
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    if (*(char *)(iVar9 + 8) != '\0') {
      *(char *)(iVar9 + 8) = *(char *)(iVar9 + 8) + -1;
      iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  if (*(char *)(iVar11 + 10) == '\0') goto loc_F00E78D4;
  piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
  iVar9 = *piVar17;
  wVar2 = *(word *)(piVar17 + iVar9 + 0xe);
  *(word *)((int)register0x00000038 + -0x20) = wVar2;
  wVar3 = *(word *)((int)piVar17 + iVar9 * 4 + 0x3a);
  *(word *)((int)register0x00000038 + -0x1e) = wVar3;
  cVar21 = '\0';
  iVar9 = (uint)*(word *)(piVar17 + 7) - (uint)wVar2;
  *(sword *)((int)register0x00000038 + -0x28) = (sword)iVar9;
  *(sword *)((int)register0x00000038 + -0x26) = (sword)(iVar9 + 0x10);
  iVar11 = (uint)*(word *)((int)piVar17 + 0x1e) - (uint)wVar3;
  *(sword *)((int)register0x00000038 + -0x24) = (sword)iVar11;
  *(sword *)((int)register0x00000038 + -0x22) = (sword)(iVar11 + 0x10);
  if (((iVar9 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x16)) &&
      ((int)*(sword *)(piVar17 + 5) < (iVar9 + 0x10) * 0x10000 >> 0x10)) &&
     (iVar11 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x1a))) {
    if ((int)*(sword *)(piVar17 + 6) < (iVar11 + 0x10) * 0x10000 >> 0x10) {
      cVar21 = '\x01';
    }
    else {
      cVar21 = '\0';
    }
  }
  if (cVar21 == *(char *)((int)piVar17 + 0xb)) {
    iVar9 = *(int *)((int)register0x00000038 + -0x4c);
  }
  else {
    *(char *)((int)piVar17 + 0xb) = cVar21;
    if (*(char *)((int)piVar17 + 0xb) == '\0') {
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
      iVar11 = *(int *)(iVar9 + 0x1fc);
      if (*(char *)(iVar11 + 8) == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
      else {
        *(char *)(iVar11 + 8) = *(char *)(iVar11 + 8) + -1;
        if (*(char *)(iVar11 + 8) == '\0') {
          piVar17 = *(int **)(iVar9 + 0x1fc);
          iVar9 = *piVar17;
          sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x36) =
               *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
          *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
          *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
          iVar9 = *(int *)((int)register0x00000038 + -0x44);
          *(sword *)(piVar17 + 9) =
               *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x36);
          pauVar8 = paDisplayinfo;
          sVar4 = *(sword *)(piVar17 + 9);
          *(int **)((int)register0x00000038 + -0x54) = piVar17;
          *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
          _objc_msgSend(iVar9,pauVar8);
          uVar13 = *(uint *)(iVar9 + 0x18);
          if (uVar13 < 4) {
            if (1 < uVar13) goto loc_F00E78B0;
            if (uVar13 == 1) {
              iVar9 = *(int *)((int)register0x00000038 + -0x44);
              _objc_msgSend(iVar9,paDisplayinfo);
              piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
              sVar4 = *(sword *)(piVar17 + 8);
              *(sword *)((int)register0x00000038 + -0x40) = sVar4;
              sVar5 = *(sword *)((int)piVar17 + 0x22);
              *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
              sVar6 = *(sword *)(piVar17 + 9);
              *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
              sVar7 = *(sword *)((int)piVar17 + 0x26);
              *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
              if (sVar6 < *(sword *)(piVar17 + 0xd)) {
                *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
              }
              if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
                *(undefined2 *)((int)register0x00000038 + -0x3a) =
                     *(undefined2 *)((int)piVar17 + 0x36);
              }
              if (sVar4 < *(sword *)(piVar17 + 0xc)) {
                *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
              }
              uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
              if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
                *(undefined2 *)((int)register0x00000038 + -0x3e) =
                     *(undefined2 *)((int)piVar17 + 0x32);
                uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
              }
              *(undefined2 *)(piVar17 + 3) = uVar15;
              *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e)
              ;
              *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
              *(undefined2 *)((int)piVar17 + 0x12) =
                   *(undefined2 *)((int)register0x00000038 + -0x3a);
              sVar4 = *(sword *)(piVar17 + 0xd);
              *(undefined4 *)((int)register0x00000038 + -0x5c) = *(undefined4 *)(iVar9 + 8);
              iVar11 = *(int *)((int)register0x00000038 + -0x5c);
              .umul(iVar11,(int)*(sword *)((int)register0x00000038 + -0x3c) - (int)sVar4);
              iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
              pbVar28 = (byte *)(piVar17 + 0x212);
              pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar11 +
                                (iVar16 - *(sword *)(piVar17 + 0xc)));
              iVar11 = *(int *)(iVar9 + 0x1c);
              *(int *)((int)register0x00000038 + -100) =
                   *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
              *(int *)((int)register0x00000038 + -0x5c) =
                   *(int *)((int)register0x00000038 + -0x5c) -
                   (*(sword *)((int)register0x00000038 + -0x3e) - iVar16);
              iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x3c) -
                      (int)*(sword *)(piVar17 + 9)) * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
              pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
              pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
              iVar9 = (int)*(sword *)((int)register0x00000038 + -0x3a) -
                      (int)*(sword *)((int)register0x00000038 + -0x3c);
              param_2 = 0x10 - *(int *)((int)register0x00000038 + -100);
              if (iVar11 == 1) {
                iVar9 = iVar9 + -1;
                if (iVar9 < 0) goto loc_F00E78B0;
                do {
                  iVar11 = *(int *)((int)register0x00000038 + -100);
                  while (iVar11 = iVar11 + -1, -1 < iVar11) {
                    uVar13 = (uint)*pbVar29;
                    *pbVar28 = *pbVar29;
                    pbVar28 = pbVar28 + 1;
                    bVar1 = *pbVar26;
                    pbVar26 = pbVar26 + 1;
                    .umul(uVar13,0xff - (uint)*pbVar30);
                    pbVar30 = pbVar30 + 1;
                    *pbVar29 = bVar1 + (char)(uVar13 + ((int)uVar13 >> 8) + 1 >> 8);
                    pbVar29 = pbVar29 + 1;
                  }
                  pbVar26 = pbVar26 + param_2;
                  pbVar30 = pbVar30 + param_2;
                  iVar9 = iVar9 + -1;
                  pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x5c);
                } while (-1 < iVar9);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
              }
              else {
                iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x208);
                iVar9 = iVar9 + -1;
                iVar11 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x20c);
                if (iVar9 < 0) goto loc_F00E78B0;
                do {
                  iVar12 = *(int *)((int)register0x00000038 + -100);
                  while (iVar12 = iVar12 + -1, -1 < iVar12) {
                    *pbVar28 = *pbVar29;
                    if (*pbVar30 != 0) {
                      bVar24 = *pbVar26;
                      bVar1 = ~*pbVar30;
                      if (bVar1 != 0) {
                        uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                        uVar13 = (uVar22 & 0xff00ff00) >> 8;
                        .umul(uVar13,bVar1);
                        uVar22 = uVar22 & 0xff00ff;
                        .umul(uVar22,bVar1);
                        uVar13 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                                 (uVar13 + 0x10001 + ((uVar13 & 0xff00ff00) >> 8) & 0xff00ff00 |
                                 uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                        if (((uVar13 ^ uVar13 >> 8) & 0xffff00) == 0) {
                          bVar24 = *(byte *)((uVar13 >> 0x18) + iVar11 + 0x300);
                        }
                        else {
                          bVar24 = *(char *)((uVar13 >> 8 & 0xff) + iVar11 + 0x200) +
                                   *(char *)(iVar11 + (uVar13 >> 0x18)) +
                                   *(char *)((uVar13 >> 0x10 & 0xff) + iVar11 + 0x100);
                        }
                      }
                      *pbVar29 = bVar24;
                    }
                    pbVar28 = pbVar28 + 1;
                    pbVar30 = pbVar30 + 1;
                    pbVar26 = pbVar26 + 1;
                    pbVar29 = pbVar29 + 1;
                  }
                  pbVar26 = pbVar26 + param_2;
                  pbVar30 = pbVar30 + param_2;
                  iVar9 = iVar9 + -1;
                  pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x5c);
                } while (-1 < iVar9);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
              }
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x54);
            }
          }
          else if (uVar13 == 4) {
            iVar9 = *(int *)((int)register0x00000038 + -0x44);
            _objc_msgSend(iVar9,paDisplayinfo);
            piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
            sVar4 = *(sword *)(piVar17 + 8);
            *(sword *)((int)register0x00000038 + -0x40) = sVar4;
            sVar5 = *(sword *)((int)piVar17 + 0x22);
            *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
            sVar6 = *(sword *)(piVar17 + 9);
            *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
            sVar7 = *(sword *)((int)piVar17 + 0x26);
            *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
            if (sVar6 < *(sword *)(piVar17 + 0xd)) {
              *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
            }
            if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
              *(undefined2 *)((int)register0x00000038 + -0x3a) =
                   *(undefined2 *)((int)piVar17 + 0x36);
            }
            if (sVar4 < *(sword *)(piVar17 + 0xc)) {
              *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
            }
            uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
            if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
              *(undefined2 *)((int)register0x00000038 + -0x3e) =
                   *(undefined2 *)((int)piVar17 + 0x32);
              uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
            }
            *(undefined2 *)(piVar17 + 3) = uVar15;
            *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
            *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
            *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
            param_2 = *(int *)(iVar9 + 8);
            iVar11 = param_2;
            .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x3c) -
                          (int)*(sword *)(piVar17 + 0xd));
            puVar27 = (uint *)(piVar17 + 0x412);
            iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
            puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar11 * 4 +
                              (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
            iVar11 = (int)*(sword *)((int)register0x00000038 + -0x3c);
            iVar12 = *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
            param_2 = param_2 - iVar12;
            puVar25 = (uint *)(piVar17 +
                              *piVar17 * 0x100 +
                              (iVar11 - *(sword *)(piVar17 + 9)) * 0x10 +
                              (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
            if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
              iVar11 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
              iVar9 = iVar12;
              if (iVar11 != -1) {
                do {
                  while (iVar9 + -1 != -1) {
                    uVar13 = *puVar23;
                    *puVar27 = uVar13;
                    uVar31 = *puVar25;
                    puVar27 = puVar27 + 1;
                    uVar22 = uVar31 >> 0x18;
                    puVar25 = puVar25 + 1;
                    if (uVar22 != 0) {
                      if (uVar22 == 0xff) {
                        *puVar23 = uVar31;
                      }
                      else {
                        uVar13 = uVar13 << 8;
                        uVar14 = (uVar13 & 0xff00ff00) >> 8;
                        .umul(uVar14,uVar22 ^ 0xff);
                        uVar13 = uVar13 & 0xff00ff;
                        .umul(uVar13,uVar22 ^ 0xff);
                        *puVar23 = uVar31 * 0x100 +
                                   (uVar14 + 0xff00ff & 0xff00ff00 |
                                   uVar13 + 0xff00ff >> 8 & 0xff00ff) >> 8 | 0xff000000;
                      }
                    }
                    puVar23 = puVar23 + 1;
                    iVar9 = iVar9 + -1;
                  }
                  puVar25 = puVar25 + (0x10 - iVar12);
                  iVar11 = iVar11 + -1;
                  puVar23 = puVar23 + param_2;
                  iVar9 = iVar12;
                } while (iVar11 != -1);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
                goto loc_F00E78B4;
              }
            }
            else {
              iVar11 = *(sword *)((int)register0x00000038 + -0x3a) - iVar11;
              while (iVar11 = iVar11 + -1, iVar9 = iVar12, iVar11 != -1) {
                while (iVar9 + -1 != -1) {
                  uVar22 = *puVar23;
                  *puVar27 = uVar22;
                  uVar31 = *puVar25;
                  puVar27 = puVar27 + 1;
                  uVar13 = uVar31 & 0xff;
                  puVar25 = puVar25 + 1;
                  if (uVar13 != 0) {
                    if (uVar13 == 0xff) {
                      *puVar23 = uVar31;
                    }
                    else {
                      uVar14 = (uVar22 & 0xff00ff00) >> 8;
                      .umul(uVar14,uVar13 ^ 0xff);
                      uVar22 = uVar22 & 0xff00ff;
                      .umul(uVar22,uVar13 ^ 0xff);
                      *puVar23 = uVar31 + (uVar14 + 0xff00ff & 0xff00ff00 |
                                          uVar22 + 0xff00ff >> 8 & 0xff00ff);
                    }
                  }
                  puVar23 = puVar23 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar25 = puVar25 + (0x10 - iVar12);
                puVar23 = puVar23 + param_2;
              }
            }
loc_F00E78B0:
            iVar9 = *(int *)((int)register0x00000038 + -0x54);
          }
          else {
            iVar9 = *(int *)((int)register0x00000038 + -0x54);
          }
loc_F00E78B4:
          *(undefined2 *)(iVar9 + 0x28) = *(undefined2 *)(iVar9 + 0x20);
          *(undefined2 *)(iVar9 + 0x2a) = *(undefined2 *)(iVar9 + 0x22);
          *(undefined2 *)(iVar9 + 0x2c) = *(undefined2 *)(iVar9 + 0x24);
          *(undefined2 *)(iVar9 + 0x2e) = *(undefined2 *)(iVar9 + 0x26);
          goto loc_F00E78D4;
        }
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
    }
    else {
      cVar21 = *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc) + 8);
      *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc) + 8) = cVar21 + '\x01';
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      if (cVar21 == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar9,paDisplayinfo);
        uVar13 = *(uint *)(iVar9 + 0x18);
        if (uVar13 < 4) {
          if (uVar13 < 2) {
            if (uVar13 == 1) {
              iVar11 = *(int *)((int)register0x00000038 + -0x44);
              _objc_msgSend(iVar11,paDisplayinfo);
              iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
              *(undefined2 *)((int)register0x00000038 + -0x30) = *(undefined2 *)(iVar16 + 0xc);
              *(undefined2 *)((int)register0x00000038 + -0x2e) = *(undefined2 *)(iVar16 + 0xe);
              sVar4 = *(sword *)(iVar16 + 0x10);
              *(sword *)((int)register0x00000038 + -0x2c) = sVar4;
              *(undefined2 *)((int)register0x00000038 + -0x2a) = *(undefined2 *)(iVar16 + 0x12);
              iVar12 = *(int *)(iVar11 + 8);
              iVar9 = iVar12;
              .umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
              puVar20 = (undefined *)(iVar16 + 0x848);
              puVar18 = (undefined *)
                        (*(int *)(iVar11 + 0x14) + iVar9 +
                        ((int)*(sword *)((int)register0x00000038 + -0x30) -
                        (int)*(sword *)(iVar16 + 0x30)));
              iVar16 = (uint)*(word *)((int)register0x00000038 + -0x2e) -
                       (int)*(sword *)((int)register0x00000038 + -0x30);
              iVar11 = ((uint)*(word *)((int)register0x00000038 + -0x2a) -
                       (uint)*(word *)((int)register0x00000038 + -0x2c)) + -1;
              iVar9 = iVar16;
              if (iVar11 * 0x10000 >> 0x10 == -1) goto loc_F00E78D4;
              do {
                while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
                  *puVar18 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                iVar11 = iVar11 + -1;
                puVar18 = puVar18 + (iVar12 - (iVar16 * 0x10000 >> 0x10));
                iVar9 = iVar16;
              } while (iVar11 * 0x10000 >> 0x10 != -1);
              iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            }
          }
          else {
loc_F00E78D4:
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
        }
        else if (uVar13 == 4) {
          iVar11 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar11,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x30) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x2e) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x2c) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x2a) = *(undefined2 *)(iVar16 + 0x12);
          iVar12 = *(int *)(iVar11 + 8);
          iVar9 = iVar12;
          .umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar19 = (undefined4 *)(iVar16 + 0x1048);
          puVar10 = (undefined4 *)
                    (*(int *)(iVar11 + 0x14) + iVar9 * 4 +
                    ((int)*(sword *)((int)register0x00000038 + -0x30) -
                    (int)*(sword *)(iVar16 + 0x30)) * 4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x2e) -
                   (int)*(sword *)((int)register0x00000038 + -0x30);
          iVar11 = ((int)*(sword *)((int)register0x00000038 + -0x2a) -
                   (int)*(sword *)((int)register0x00000038 + -0x2c)) + -1;
          iVar9 = iVar16;
          if (iVar11 == -1) goto loc_F00E78D4;
          do {
            while (iVar9 + -1 != -1) {
              *puVar10 = *puVar19;
              puVar19 = puVar19 + 1;
              puVar10 = puVar10 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar11 = iVar11 + -1;
            puVar10 = puVar10 + (iVar12 - iVar16);
            iVar9 = iVar16;
          } while (iVar11 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
    }
  }
  if (*(char *)(iVar9 + 8) == '\0') {
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
  }
  else {
    *(char *)(iVar9 + 8) = *(char *)(iVar9 + 8) + -1;
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    if (*(char *)(iVar9 + 8) == '\0') {
      piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x38) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x36) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x36);
      pauVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -0x6c) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,pauVar8);
      uVar13 = *(uint *)(iVar9 + 0x18);
      if (uVar13 < 4) {
        if (1 < uVar13) goto loc_F00E80EC;
        if (uVar13 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x40) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x3a) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x3e) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
          }
          *(undefined2 *)(piVar17 + 3) = uVar15;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x74) = *(undefined4 *)(iVar9 + 8);
          iVar11 = *(int *)((int)register0x00000038 + -0x74);
          .umul(iVar11,(int)*(sword *)((int)register0x00000038 + -0x3c) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar11 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar11 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x7c) =
               *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
          *(int *)((int)register0x00000038 + -0x74) =
               *(int *)((int)register0x00000038 + -0x74) -
               (*(sword *)((int)register0x00000038 + -0x3e) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x3c) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x3a) -
                  (int)*(sword *)((int)register0x00000038 + -0x3c);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x7c);
          if (iVar11 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) {
loc_F00E80EC:
              iVar11 = *(int *)((int)register0x00000038 + -0x6c);
            }
            else {
              do {
                iVar11 = *(int *)((int)register0x00000038 + -0x7c);
                while (iVar11 = iVar11 + -1, -1 < iVar11) {
                  uVar13 = (uint)*pbVar29;
                  *pbVar28 = *pbVar29;
                  pbVar28 = pbVar28 + 1;
                  bVar1 = *pbVar26;
                  pbVar26 = pbVar26 + 1;
                  .umul(uVar13,0xff - (uint)*pbVar30);
                  pbVar30 = pbVar30 + 1;
                  *pbVar29 = bVar1 + (char)(uVar13 + ((int)uVar13 >> 8) + 1 >> 8);
                  pbVar29 = pbVar29 + 1;
                }
                pbVar26 = pbVar26 + param_2;
                pbVar30 = pbVar30 + param_2;
                iVar9 = iVar9 + -1;
                pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x74);
              } while (-1 < iVar9);
              iVar11 = *(int *)((int)register0x00000038 + -0x6c);
            }
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x208);
            iVar9 = iVar9 + -1;
            iVar11 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x20c);
            if (iVar9 < 0) goto loc_F00E80EC;
            do {
              iVar12 = *(int *)((int)register0x00000038 + -0x7c);
              while (iVar12 = iVar12 + -1, -1 < iVar12) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar13 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar13,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,bVar1);
                    uVar13 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar13 + 0x10001 + ((uVar13 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar13 ^ uVar13 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar13 >> 0x18) + iVar11 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar13 >> 8 & 0xff) + iVar11 + 0x200) +
                               *(char *)(iVar11 + (uVar13 >> 0x18)) +
                               *(char *)((uVar13 >> 0x10 & 0xff) + iVar11 + 0x100);
                    }
                  }
                  *pbVar29 = bVar24;
                }
                pbVar28 = pbVar28 + 1;
                pbVar30 = pbVar30 + 1;
                pbVar26 = pbVar26 + 1;
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x74);
            } while (-1 < iVar9);
            iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          }
        }
        else {
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
        }
      }
      else if (uVar13 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x40) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x3a) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x3e) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
        }
        *(undefined2 *)(piVar17 + 3) = uVar15;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
        param_2 = *(int *)(iVar9 + 8);
        iVar11 = param_2;
        .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x3c) -
                      (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar11 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar11 = (int)*(sword *)((int)register0x00000038 + -0x3c);
        iVar12 = *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
        param_2 = param_2 - iVar12;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar11 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          iVar9 = iVar12;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar13 = *puVar23;
                *puVar27 = uVar13;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar13 = uVar13 << 8;
                    uVar14 = (uVar13 & 0xff00ff00) >> 8;
                    .umul(uVar14,uVar22 ^ 0xff);
                    uVar13 = uVar13 & 0xff00ff;
                    .umul(uVar13,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar14 + 0xff00ff & 0xff00ff00 | uVar13 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar12);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar12;
            } while (iVar16 != -1);
            iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          }
        }
        else {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          iVar9 = iVar12;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar22 = *puVar23;
                *puVar27 = uVar22;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar13 = uVar31 & 0xff;
                puVar25 = puVar25 + 1;
                if (uVar13 != 0) {
                  if (uVar13 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar14 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar14,uVar13 ^ 0xff);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,uVar13 ^ 0xff);
                    *puVar23 = uVar31 + (uVar14 + 0xff00ff & 0xff00ff00 |
                                        uVar22 + 0xff00ff >> 8 & 0xff00ff);
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar12);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar12;
            } while (iVar16 != -1);
            goto loc_F00E80EC;
          }
        }
      }
      else {
        iVar11 = *(int *)((int)register0x00000038 + -0x6c);
      }
      *(undefined2 *)(iVar11 + 0x28) = *(undefined2 *)(iVar11 + 0x20);
      *(undefined2 *)(iVar11 + 0x2a) = *(undefined2 *)(iVar11 + 0x22);
      *(undefined2 *)(iVar11 + 0x2c) = *(undefined2 *)(iVar11 + 0x24);
      *(undefined2 *)(iVar11 + 0x2e) = *(undefined2 *)(iVar11 + 0x26);
      iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  _ev_unlock(iVar11 + 4);
loc_F00E811C:
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x44));
}
/* GHIDRADEC_FUNCTION index=4876 start=0xf00e8128 */

/* WARNING: Removing unreachable block (ram,0xf00e8ff4) */
/* WARNING: Removing unreachable block (ram,0xf00e90b8) */
/* WARNING: Removing unreachable block (ram,0xf00e8df8) */
/* WARNING: Removing unreachable block (ram,0xf00e94d0) */
/* WARNING: Removing unreachable block (ram,0xf00e93e8) */
/* WARNING: Removing unreachable block (ram,0xf00e91b0) */
/* WARNING: Removing unreachable block (ram,0xf00e87c0) */
/* WARNING: Removing unreachable block (ram,0xf00e8884) */
/* WARNING: Removing unreachable block (ram,0xf00e85c4) */
/* WARNING: Removing unreachable block (ram,0xf00e8c94) */
/* WARNING: Removing unreachable block (ram,0xf00e8bb0) */
/* WARNING: Removing unreachable block (ram,0xf00e897c) */
/* WARNING: Removing unreachable block (ram,0xf00e8324) */
/* WARNING: Removing unreachable block (ram,0xf00e8440) */
/* WARNING: Removing unreachable block (ram,0xf00e8290) */
/* WARNING: Removing unreachable block (ram,0xf00e83f0) */
/* WARNING: Removing unreachable block (ram,0xf00e82d4) */
/* WARNING: Removing unreachable block (ram,0xf00e8580) */
/* WARNING: Removing unreachable block (ram,0xf00e8a88) */
/* WARNING: Removing unreachable block (ram,0xf00e8bc8) */
/* WARNING: Removing unreachable block (ram,0xf00e8cac) */
/* WARNING: Removing unreachable block (ram,0xf00e86d4) */
/* WARNING: Removing unreachable block (ram,0xf00e88ac) */
/* WARNING: Removing unreachable block (ram,0xf00e8db4) */
/* WARNING: Removing unreachable block (ram,0xf00e92bc) */
/* WARNING: Removing unreachable block (ram,0xf00e9400) */
/* WARNING: Removing unreachable block (ram,0xf00e94e8) */
/* WARNING: Removing unreachable block (ram,0xf00e8f08) */
/* WARNING: Removing unreachable block (ram,0xf00e90e0) */
/* WARNING: Removing unreachable block (ram,0xf00e955c) */
/* WARNING: Removing unreachable block (ram,0xf00e8138) */

undefined8
-[IOFrameBufferDisplay showCursor:frame:token:]
          (int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  byte bVar1;
  word wVar2;
  word wVar3;
  sword sVar4;
  sword sVar5;
  sword sVar6;
  sword sVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined2 uVar14;
  uint uVar12;
  uint uVar13;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined *puVar18;
  undefined4 *puVar19;
  char cVar21;
  undefined *puVar20;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar22;
  uint *puVar23;
  undefined4 unaff_l3;
  byte bVar24;
  undefined4 unaff_l4;
  uint *puVar25;
  byte *pbVar26;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint *puVar27;
  undefined4 unaff_l7;
  byte *pbVar28;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  byte *pbVar29;
  undefined4 unaff_i3;
  byte *pbVar30;
  uint uVar31;
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
  *(int *)((int)register0x00000038 + -0x3c) = param_1;
  iVar9 = *(int *)(param_1 + 0x1fc);
  *(int *)((int)register0x00000038 + -0x44) = iVar9;
  iVar9 = iVar9 + 4;
  _ev_try_lock();
  puVar10 = *(undefined4 **)((int)register0x00000038 + -0x44);
  if (iVar9 == 0) goto loc_F00E9564;
  *puVar10 = param_4;
  *(undefined2 *)(puVar10 + 7) = *param_3;
  *(undefined2 *)((int)puVar10 + 0x1e) = param_3[1];
  if (*(char *)((int)puVar10 + 10) == '\0') goto loc_F00E8D1C;
  piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
  iVar9 = *piVar17;
  wVar2 = *(word *)(piVar17 + iVar9 + 0xe);
  *(word *)((int)register0x00000038 + -0x18) = wVar2;
  wVar3 = *(word *)((int)piVar17 + iVar9 * 4 + 0x3a);
  *(word *)((int)register0x00000038 + -0x16) = wVar3;
  cVar21 = '\0';
  iVar9 = (uint)*(word *)(piVar17 + 7) - (uint)wVar2;
  *(sword *)((int)register0x00000038 + -0x20) = (sword)iVar9;
  *(sword *)((int)register0x00000038 + -0x1e) = (sword)(iVar9 + 0x10);
  iVar15 = (uint)*(word *)((int)piVar17 + 0x1e) - (uint)wVar3;
  *(sword *)((int)register0x00000038 + -0x1c) = (sword)iVar15;
  *(sword *)((int)register0x00000038 + -0x1a) = (sword)(iVar15 + 0x10);
  if (((iVar9 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x16)) &&
      ((int)*(sword *)(piVar17 + 5) < (iVar9 + 0x10) * 0x10000 >> 0x10)) &&
     (iVar15 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x1a))) {
    if ((int)*(sword *)(piVar17 + 6) < (iVar15 + 0x10) * 0x10000 >> 0x10) {
      cVar21 = '\x01';
    }
    else {
      cVar21 = '\0';
    }
  }
  if (cVar21 == *(char *)((int)piVar17 + 0xb)) {
    iVar9 = *(int *)((int)register0x00000038 + -0x3c);
loc_F00E8D20:
    iVar15 = *(int *)(iVar9 + 0x1fc);
  }
  else {
    *(char *)((int)piVar17 + 0xb) = cVar21;
    if (*(char *)((int)piVar17 + 0xb) != '\0') {
      cVar21 = *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc) + 8);
      *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc) + 8) = cVar21 + '\x01';
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      if (cVar21 == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        uVar12 = *(uint *)(iVar9 + 0x18);
        if (uVar12 < 4) {
          if (uVar12 < 2) {
            if (uVar12 == 1) {
              iVar15 = *(int *)((int)register0x00000038 + -0x3c);
              _objc_msgSend(iVar15,paDisplayinfo);
              iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
              *(undefined2 *)((int)register0x00000038 + -0x28) = *(undefined2 *)(iVar16 + 0xc);
              *(undefined2 *)((int)register0x00000038 + -0x26) = *(undefined2 *)(iVar16 + 0xe);
              sVar4 = *(sword *)(iVar16 + 0x10);
              *(sword *)((int)register0x00000038 + -0x24) = sVar4;
              *(undefined2 *)((int)register0x00000038 + -0x22) = *(undefined2 *)(iVar16 + 0x12);
              iVar11 = *(int *)(iVar15 + 8);
              iVar9 = iVar11;
              .umul(iVar11,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
              puVar20 = (undefined *)(iVar16 + 0x848);
              puVar18 = (undefined *)
                        (*(int *)(iVar15 + 0x14) + iVar9 +
                        ((int)*(sword *)((int)register0x00000038 + -0x28) -
                        (int)*(sword *)(iVar16 + 0x30)));
              iVar16 = (uint)*(word *)((int)register0x00000038 + -0x26) -
                       (int)*(sword *)((int)register0x00000038 + -0x28);
              iVar15 = ((uint)*(word *)((int)register0x00000038 + -0x22) -
                       (uint)*(word *)((int)register0x00000038 + -0x24)) + -1;
              iVar9 = iVar16;
              if (iVar15 * 0x10000 >> 0x10 == -1) goto loc_F00E8D1C;
              do {
                while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
                  *puVar18 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                iVar15 = iVar15 + -1;
                puVar18 = puVar18 + (iVar11 - (iVar16 * 0x10000 >> 0x10));
                iVar9 = iVar16;
              } while (iVar15 * 0x10000 >> 0x10 != -1);
              iVar9 = *(int *)((int)register0x00000038 + -0x3c);
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x3c);
            }
          }
          else {
loc_F00E8D1C:
            iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          }
        }
        else if (uVar12 == 4) {
          iVar15 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar15,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x28) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x26) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x24) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x22) = *(undefined2 *)(iVar16 + 0x12);
          iVar11 = *(int *)(iVar15 + 8);
          iVar9 = iVar11;
          .umul(iVar11,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar19 = (undefined4 *)(iVar16 + 0x1048);
          puVar10 = (undefined4 *)
                    (*(int *)(iVar15 + 0x14) + iVar9 * 4 +
                    ((int)*(sword *)((int)register0x00000038 + -0x28) -
                    (int)*(sword *)(iVar16 + 0x30)) * 4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x26) -
                   (int)*(sword *)((int)register0x00000038 + -0x28);
          iVar15 = ((int)*(sword *)((int)register0x00000038 + -0x22) -
                   (int)*(sword *)((int)register0x00000038 + -0x24)) + -1;
          iVar9 = iVar16;
          if (iVar15 == -1) goto loc_F00E8D1C;
          do {
            while (iVar9 + -1 != -1) {
              *puVar10 = *puVar19;
              puVar19 = puVar19 + 1;
              puVar10 = puVar10 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar15 = iVar15 + -1;
            puVar10 = puVar10 + (iVar11 - iVar16);
            iVar9 = iVar16;
          } while (iVar15 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        }
      }
      goto loc_F00E8D20;
    }
    iVar9 = *(int *)((int)register0x00000038 + -0x3c);
    iVar15 = *(int *)(iVar9 + 0x1fc);
    if (*(char *)(iVar15 + 8) != '\0') {
      *(char *)(iVar15 + 8) = *(char *)(iVar15 + 8) + -1;
      if (*(char *)(iVar15 + 8) != '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        goto loc_F00E8D20;
      }
      piVar17 = *(int **)(iVar9 + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x30) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x2e) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x2e);
      uVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -0x4c) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,uVar8);
      uVar12 = *(uint *)(iVar9 + 0x18);
      if (uVar12 < 4) {
        if (1 < uVar12) goto loc_F00E8CF8;
        if (uVar12 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x36) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x34) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x32) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          }
          *(undefined2 *)(piVar17 + 3) = uVar14;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x54) = *(undefined4 *)(iVar9 + 8);
          iVar15 = *(int *)((int)register0x00000038 + -0x54);
          .umul(iVar15,(int)*(sword *)((int)register0x00000038 + -0x34) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar15 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar15 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x5c) =
               *(sword *)((int)register0x00000038 + -0x36) - iVar16;
          *(int *)((int)register0x00000038 + -0x54) =
               *(int *)((int)register0x00000038 + -0x54) -
               (*(sword *)((int)register0x00000038 + -0x36) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x34) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x32) -
                  (int)*(sword *)((int)register0x00000038 + -0x34);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x5c);
          if (iVar15 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) goto loc_F00E8CF8;
            do {
              iVar15 = *(int *)((int)register0x00000038 + -0x5c);
              while (iVar15 = iVar15 + -1, -1 < iVar15) {
                uVar12 = (uint)*pbVar29;
                *pbVar28 = *pbVar29;
                pbVar28 = pbVar28 + 1;
                bVar1 = *pbVar26;
                pbVar26 = pbVar26 + 1;
                .umul(uVar12,0xff - (uint)*pbVar30);
                pbVar30 = pbVar30 + 1;
                *pbVar29 = bVar1 + (char)(uVar12 + ((int)uVar12 >> 8) + 1 >> 8);
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x54);
            } while (-1 < iVar9);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x208);
            iVar9 = iVar9 + -1;
            iVar15 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x20c);
            if (iVar9 < 0) goto loc_F00E8CF8;
            do {
              iVar11 = *(int *)((int)register0x00000038 + -0x5c);
              while (iVar11 = iVar11 + -1, -1 < iVar11) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar12 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar12,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,bVar1);
                    uVar12 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar12 + 0x10001 + ((uVar12 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar12 ^ uVar12 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar12 >> 0x18) + iVar15 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar12 >> 8 & 0xff) + iVar15 + 0x200) +
                               *(char *)(iVar15 + (uVar12 >> 0x18)) +
                               *(char *)((uVar12 >> 0x10 & 0xff) + iVar15 + 0x100);
                    }
                  }
                  *pbVar29 = bVar24;
                }
                pbVar28 = pbVar28 + 1;
                pbVar30 = pbVar30 + 1;
                pbVar26 = pbVar26 + 1;
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x54);
            } while (-1 < iVar9);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
      else if (uVar12 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x38) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x36) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x34) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x32) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        }
        *(undefined2 *)(piVar17 + 3) = uVar14;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
        param_2 = *(int *)(iVar9 + 8);
        iVar15 = param_2;
        .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x34) -
                      (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar15 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar15 = (int)*(sword *)((int)register0x00000038 + -0x34);
        iVar11 = *(sword *)((int)register0x00000038 + -0x36) - iVar16;
        param_2 = param_2 - iVar11;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar15 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar15 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar9 = iVar11;
          if (iVar15 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar12 = *puVar23;
                *puVar27 = uVar12;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar12 = uVar12 << 8;
                    uVar13 = (uVar12 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar22 ^ 0xff);
                    uVar12 = uVar12 & 0xff00ff;
                    .umul(uVar12,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar13 + 0xff00ff & 0xff00ff00 | uVar12 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar15 = iVar15 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar15 != -1);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            goto loc_F00E8CFC;
          }
        }
        else {
          iVar15 = *(sword *)((int)register0x00000038 + -0x32) - iVar15;
          while (iVar15 = iVar15 + -1, iVar9 = iVar11, iVar15 != -1) {
            while (iVar9 + -1 != -1) {
              uVar22 = *puVar23;
              *puVar27 = uVar22;
              uVar31 = *puVar25;
              puVar27 = puVar27 + 1;
              uVar12 = uVar31 & 0xff;
              puVar25 = puVar25 + 1;
              if (uVar12 != 0) {
                if (uVar12 == 0xff) {
                  *puVar23 = uVar31;
                }
                else {
                  uVar13 = (uVar22 & 0xff00ff00) >> 8;
                  .umul(uVar13,uVar12 ^ 0xff);
                  uVar22 = uVar22 & 0xff00ff;
                  .umul(uVar22,uVar12 ^ 0xff);
                  *puVar23 = uVar31 + (uVar13 + 0xff00ff & 0xff00ff00 |
                                      uVar22 + 0xff00ff >> 8 & 0xff00ff);
                }
              }
              puVar23 = puVar23 + 1;
              iVar9 = iVar9 + -1;
            }
            puVar25 = puVar25 + (0x10 - iVar11);
            puVar23 = puVar23 + param_2;
          }
        }
loc_F00E8CF8:
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
      else {
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
loc_F00E8CFC:
      *(undefined2 *)(iVar9 + 0x28) = *(undefined2 *)(iVar9 + 0x20);
      *(undefined2 *)(iVar9 + 0x2a) = *(undefined2 *)(iVar9 + 0x22);
      *(undefined2 *)(iVar9 + 0x2c) = *(undefined2 *)(iVar9 + 0x24);
      *(undefined2 *)(iVar9 + 0x2e) = *(undefined2 *)(iVar9 + 0x26);
      goto loc_F00E8D1C;
    }
  }
  if (*(char *)(iVar15 + 8) == '\0') {
    iVar9 = *(int *)((int)register0x00000038 + -0x44);
  }
  else {
    *(char *)(iVar15 + 8) = *(char *)(iVar15 + 8) + -1;
    if (*(char *)(iVar15 + 8) == '\0') {
      piVar17 = *(int **)(iVar9 + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x30) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x2e) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x2e);
      uVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -100) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,uVar8);
      uVar12 = *(uint *)(iVar9 + 0x18);
      if (uVar12 < 4) {
        if (1 < uVar12) goto loc_F00E9534;
        if (uVar12 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x36) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x34) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x32) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          }
          *(undefined2 *)(piVar17 + 3) = uVar14;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x6c) = *(undefined4 *)(iVar9 + 8);
          iVar15 = *(int *)((int)register0x00000038 + -0x6c);
          .umul(iVar15,(int)*(sword *)((int)register0x00000038 + -0x34) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar15 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar15 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x74) =
               *(sword *)((int)register0x00000038 + -0x36) - iVar16;
          *(int *)((int)register0x00000038 + -0x6c) =
               *(int *)((int)register0x00000038 + -0x6c) -
               (*(sword *)((int)register0x00000038 + -0x36) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x34) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x32) -
                  (int)*(sword *)((int)register0x00000038 + -0x34);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x74);
          if (iVar15 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) {
loc_F00E9534:
              iVar15 = *(int *)((int)register0x00000038 + -100);
            }
            else {
              do {
                iVar15 = *(int *)((int)register0x00000038 + -0x74);
                while (iVar15 = iVar15 + -1, -1 < iVar15) {
                  uVar12 = (uint)*pbVar29;
                  *pbVar28 = *pbVar29;
                  pbVar28 = pbVar28 + 1;
                  bVar1 = *pbVar26;
                  pbVar26 = pbVar26 + 1;
                  .umul(uVar12,0xff - (uint)*pbVar30);
                  pbVar30 = pbVar30 + 1;
                  *pbVar29 = bVar1 + (char)(uVar12 + ((int)uVar12 >> 8) + 1 >> 8);
                  pbVar29 = pbVar29 + 1;
                }
                pbVar26 = pbVar26 + param_2;
                pbVar30 = pbVar30 + param_2;
                iVar9 = iVar9 + -1;
                pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x6c);
              } while (-1 < iVar9);
              iVar15 = *(int *)((int)register0x00000038 + -100);
            }
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x208);
            iVar9 = iVar9 + -1;
            iVar15 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x20c);
            if (iVar9 < 0) goto loc_F00E9534;
            do {
              iVar11 = *(int *)((int)register0x00000038 + -0x74);
              while (iVar11 = iVar11 + -1, -1 < iVar11) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar12 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar12,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,bVar1);
                    uVar12 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar12 + 0x10001 + ((uVar12 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar12 ^ uVar12 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar12 >> 0x18) + iVar15 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar12 >> 8 & 0xff) + iVar15 + 0x200) +
                               *(char *)(iVar15 + (uVar12 >> 0x18)) +
                               *(char *)((uVar12 >> 0x10 & 0xff) + iVar15 + 0x100);
                    }
                  }
                  *pbVar29 = bVar24;
                }
                pbVar28 = pbVar28 + 1;
                pbVar30 = pbVar30 + 1;
                pbVar26 = pbVar26 + 1;
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x6c);
            } while (-1 < iVar9);
            iVar15 = *(int *)((int)register0x00000038 + -100);
          }
        }
        else {
          iVar15 = *(int *)((int)register0x00000038 + -100);
        }
      }
      else if (uVar12 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x38) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x36) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x34) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x32) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        }
        *(undefined2 *)(piVar17 + 3) = uVar14;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
        param_2 = *(int *)(iVar9 + 8);
        iVar15 = param_2;
        .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x34) -
                      (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar15 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar15 = (int)*(sword *)((int)register0x00000038 + -0x34);
        iVar11 = *(sword *)((int)register0x00000038 + -0x36) - iVar16;
        param_2 = param_2 - iVar11;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar15 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar15 = *(int *)((int)register0x00000038 + -100);
          iVar9 = iVar11;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar12 = *puVar23;
                *puVar27 = uVar12;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar12 = uVar12 << 8;
                    uVar13 = (uVar12 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar22 ^ 0xff);
                    uVar12 = uVar12 & 0xff00ff;
                    .umul(uVar12,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar13 + 0xff00ff & 0xff00ff00 | uVar12 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar16 != -1);
            iVar15 = *(int *)((int)register0x00000038 + -100);
          }
        }
        else {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar15 = *(int *)((int)register0x00000038 + -100);
          iVar9 = iVar11;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar22 = *puVar23;
                *puVar27 = uVar22;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar12 = uVar31 & 0xff;
                puVar25 = puVar25 + 1;
                if (uVar12 != 0) {
                  if (uVar12 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar13 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar12 ^ 0xff);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,uVar12 ^ 0xff);
                    *puVar23 = uVar31 + (uVar13 + 0xff00ff & 0xff00ff00 |
                                        uVar22 + 0xff00ff >> 8 & 0xff00ff);
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar16 != -1);
            goto loc_F00E9534;
          }
        }
      }
      else {
        iVar15 = *(int *)((int)register0x00000038 + -100);
      }
      *(undefined2 *)(iVar15 + 0x28) = *(undefined2 *)(iVar15 + 0x20);
      *(undefined2 *)(iVar15 + 0x2a) = *(undefined2 *)(iVar15 + 0x22);
      *(undefined2 *)(iVar15 + 0x2c) = *(undefined2 *)(iVar15 + 0x24);
      *(undefined2 *)(iVar15 + 0x2e) = *(undefined2 *)(iVar15 + 0x26);
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
    }
    else {
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
    }
  }
  _ev_unlock(iVar9 + 4);
loc_F00E9564:
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x3c));
}
/* GHIDRADEC_FUNCTION index=4877 start=0xf00e9570 */

/* WARNING: Removing unreachable block (ram,0xf00e9650) */
/* WARNING: Removing unreachable block (ram,0xf00e9630) */
/* WARNING: Removing unreachable block (ram,0xf00e95d8) */
/* WARNING: Removing unreachable block (ram,0xf00e95a4) */
/* WARNING: Removing unreachable block (ram,0xf00e9618) */
/* WARNING: Removing unreachable block (ram,0xf00e9644) */
/* WARNING: Removing unreachable block (ram,0xf00e9660) */
/* WARNING: Removing unreachable block (ram,0xf00e9588) */

undefined8 -[IOFrameBufferDisplay _registerWithED](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [10];
  undefined (*pauVar2) [9];
  undefined (*pauVar3) [12];
  undefined (*pauVar4) [12];
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  
  pauVar3 = paEventdriver_0;
  pauVar2 = paInstance;
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
  pauVar4 = paEventdriver_0;
  _objc_msgSend(paEventdriver_0,paInstance);
  _objc_msgSend();
  if (pauVar4 != (undefined (*) [12])0xffffffff) {
    if (*(uint *)((int)register0x00000038 + -0x1c) < 0x1449) {
      iVar5 = *(int *)(param_1 + 0x1fc);
      _memset(iVar5,0);
      *(undefined *)(iVar5 + 8) = 1;
      *(undefined2 *)(iVar5 + 0x30) = *(undefined2 *)((int)register0x00000038 + -0x18);
      *(undefined2 *)(iVar5 + 0x32) = *(undefined2 *)((int)register0x00000038 + -0x16);
      *(undefined2 *)(iVar5 + 0x34) = *(undefined2 *)((int)register0x00000038 + -0x14);
      pauVar1 = paSettoken;
      *(undefined2 *)(iVar5 + 0x36) = *(undefined2 *)((int)register0x00000038 + -0x12);
      uVar6 = 0;
      _objc_msgSend(param_1,pauVar1,pauVar4);
      goto locret_F00E966C;
    }
    _objc_msgSend(param_1,paName);
    _IOLog(aSShmemSizeSize,param_1,*(undefined4 *)((int)register0x00000038 + -0x1c),0x1448);
    _objc_msgSend(pauVar3,pauVar2);
    _objc_msgSend();
  }
  uVar6 = 0xfffffd3e;
locret_F00E966C:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=4878 start=0xf00e9674 */

/* WARNING: Removing unreachable block (ram,0xf00e9744) */
/* WARNING: Removing unreachable block (ram,0xf00e985c) */
/* WARNING: Removing unreachable block (ram,0xf00e96b4) */
/* WARNING: Removing unreachable block (ram,0xf00e9810) */
/* WARNING: Removing unreachable block (ram,0xf00e96f8) */
/* WARNING: Removing unreachable block (ram,0xf00e9900) */
/* WARNING: Removing unreachable block (ram,0xf00e967c) */

undefined8 -[IOFrameBufferDisplay hideCursor:](int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  undefined4 unaff_l0;
  int iVar10;
  undefined4 unaff_l1;
  int iVar11;
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
  iVar3 = *(int *)(param_1 + 0x1fc) + 4;
  _ev_try_lock();
  if (iVar3 == 0) goto locret_F00E9908;
  cVar1 = *(char *)(*(int *)(param_1 + 0x1fc) + 8);
  *(char *)(*(int *)(param_1 + 0x1fc) + 8) = cVar1 + '\x01';
  if (cVar1 == '\0') {
    iVar3 = param_1;
    _objc_msgSend(param_1,paDisplayinfo);
    uVar4 = *(uint *)(iVar3 + 0x18);
    if (uVar4 < 4) {
      if (uVar4 < 2) {
        if (uVar4 == 1) {
          iVar3 = param_1;
          _objc_msgSend(param_1,paDisplayinfo);
          iVar10 = *(int *)(param_1 + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar10 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar10 + 0xe);
          sVar2 = *(sword *)(iVar10 + 0x10);
          *(sword *)((int)register0x00000038 + -0x14) = sVar2;
          *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar10 + 0x12);
          iVar11 = *(int *)(iVar3 + 8);
          iVar5 = iVar11;
          .umul(iVar11,(int)sVar2 - (int)*(sword *)(iVar10 + 0x34));
          puVar9 = (undefined *)(iVar10 + 0x848);
          puVar7 = (undefined *)
                   (*(int *)(iVar3 + 0x14) + iVar5 +
                   ((int)*(sword *)((int)register0x00000038 + -0x18) -
                   (int)*(sword *)(iVar10 + 0x30)));
          iVar10 = (uint)*(word *)((int)register0x00000038 + -0x16) -
                   (int)*(sword *)((int)register0x00000038 + -0x18);
          iVar5 = ((uint)*(word *)((int)register0x00000038 + -0x12) -
                  (uint)*(word *)((int)register0x00000038 + -0x14)) + -1;
          iVar3 = iVar10;
          if (iVar5 * 0x10000 >> 0x10 == -1) goto loc_F00E98FC;
          do {
            while ((iVar3 + -1) * 0x10000 >> 0x10 != -1) {
              *puVar7 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar7 = puVar7 + 1;
              iVar3 = iVar3 + -1;
            }
            iVar5 = iVar5 + -1;
            puVar7 = puVar7 + (iVar11 - (iVar10 * 0x10000 >> 0x10));
            iVar3 = iVar10;
          } while (iVar5 * 0x10000 >> 0x10 != -1);
          iVar3 = *(int *)(param_1 + 0x1fc);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x1fc);
        }
      }
      else {
loc_F00E98FC:
        iVar3 = *(int *)(param_1 + 0x1fc);
      }
    }
    else {
      if (uVar4 == 4) {
        iVar3 = param_1;
        _objc_msgSend(param_1,paDisplayinfo);
        iVar10 = *(int *)(param_1 + 0x1fc);
        *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar10 + 0xc);
        *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar10 + 0xe);
        sVar2 = *(sword *)(iVar10 + 0x10);
        *(sword *)((int)register0x00000038 + -0x14) = sVar2;
        *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar10 + 0x12);
        iVar11 = *(int *)(iVar3 + 8);
        iVar5 = iVar11;
        .umul(iVar11,(int)sVar2 - (int)*(sword *)(iVar10 + 0x34));
        puVar8 = (undefined4 *)(iVar10 + 0x1048);
        puVar6 = (undefined4 *)
                 (*(int *)(iVar3 + 0x14) + iVar5 * 4 +
                 ((int)*(sword *)((int)register0x00000038 + -0x18) - (int)*(sword *)(iVar10 + 0x30))
                 * 4);
        iVar5 = (int)*(sword *)((int)register0x00000038 + -0x16) -
                (int)*(sword *)((int)register0x00000038 + -0x18);
        iVar3 = (int)*(sword *)((int)register0x00000038 + -0x12) -
                (int)*(sword *)((int)register0x00000038 + -0x14);
        while (iVar3 = iVar3 + -1, iVar10 = iVar5, iVar3 != -1) {
          while (iVar10 + -1 != -1) {
            *puVar6 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar6 = puVar6 + 1;
            iVar10 = iVar10 + -1;
          }
          puVar6 = puVar6 + (iVar11 - iVar5);
        }
        goto loc_F00E98FC;
      }
      iVar3 = *(int *)(param_1 + 0x1fc);
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1fc);
  }
  _ev_unlock(iVar3 + 4);
locret_F00E9908:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4879 start=0xf00e9910 */

/* WARNING: Removing unreachable block (ram,0xf00e993c) */
/* WARNING: Removing unreachable block (ram,0xf00e992c) */

undefined8
-[IOFrameBufferDisplay setBrightness:token:](undefined4 param_1,undefined4 param_2,uint param_3)

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
  if (0x40 < param_3) {
    uVar1 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSInvalidArgToS,uVar1,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4880 start=0xf00e994c */

/* WARNING: Removing unreachable block (ram,0xf00e9984) */
/* WARNING: Removing unreachable block (ram,0xf00e9968) */
/* WARNING: Removing unreachable block (ram,0xf00e9994) */
/* WARNING: Removing unreachable block (ram,0xf00e9958) */

undefined8 +[IOFrameBufferDisplay probe:](int param_1,undefined4 param_2)

{
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
  _objc_msgSend(param_1,paAlloc);
  _objc_msgSend();
  if (param_1 != 0) {
    _objc_msgSend();
    _objc_msgSend(param_1,paRegisterdevice);
  }
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=4881 start=0xf00e99b0 */

/* WARNING: Removing unreachable block (ram,0xf00e9a14) */
/* WARNING: Removing unreachable block (ram,0xf00e9a44) */
/* WARNING: Removing unreachable block (ram,0xf00e99f8) */
/* WARNING: Removing unreachable block (ram,0xf00e9a28) */
/* WARNING: Removing unreachable block (ram,0xf00e99d4) */

undefined8
-[IOFrameBufferDisplay initFromDeviceDescription:]
          (undefined *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar3;
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
  undefined auStackX_0 [92];
  
  uVar1 = uRamf0142370;
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
  *(undefined **)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
  puVar2 = puVar3;
  _objc_msgSendSuper(puVar3,paInitfromdevice,param_3);
  if (puVar2 == (undefined *)0x0) {
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
    _objc_msgSendSuper(puVar3,paFree);
  }
  else {
    _sprintf((undefined *)((int)register0x00000038 + -0x28),aDisplayD,dword_F012EF7C);
    dword_F012EF7C = dword_F012EF7C + 1;
    _objc_msgSend(param_1,paSetunit);
    _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
    puVar3 = param_1;
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4882 start=0xf00e9a58 */

undefined8 -[IOFrameBufferDisplay allocateConsoleInfo](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4883 start=0xf00e9a64 */

/* WARNING: Removing unreachable block (ram,0xf00e9c8c) */
/* WARNING: Removing unreachable block (ram,0xf00e9c04) */
/* WARNING: Removing unreachable block (ram,0xf00e9bc4) */
/* WARNING: Removing unreachable block (ram,0xf00e9ad0) */
/* WARNING: Removing unreachable block (ram,0xf00e9ab4) */
/* WARNING: Removing unreachable block (ram,0xf00e9ba8) */
/* WARNING: Removing unreachable block (ram,0xf00e9bec) */
/* WARNING: Removing unreachable block (ram,0xf00e9c34) */
/* WARNING: Removing unreachable block (ram,0xf00e9a94) */
/* WARNING: Removing unreachable block (ram,0xf00e9a74) */

undefined8
-[IOFrameBufferDisplay getIntValues:forParameter:count:]
          (int *param_1,undefined4 param_2,int *param_3,int param_4,int *param_5)

{
  undefined (*pauVar1) [16];
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar7;
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
  undefined4 auStack_28 [10];
  
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
  iVar6 = *param_5;
  iVar3 = param_4;
  _strcmp(param_4,aIoFramebufferM);
  pauVar1 = paEnterlinearmod;
  if (iVar3 == 0) {
    *param_3 = 0;
    _objc_msgSend(param_1,pauVar1);
    *param_5 = 1;
loc_F00E9AA4:
    piVar7 = (int *)0x0;
    goto locret_F00E9C98;
  }
  iVar3 = param_4;
  _strcmp(param_4,aIoFramebufferD);
  if (iVar3 != 0) {
    iVar3 = param_4;
    _strcmp(param_4,aIoFramebufferR);
    if (iVar3 == 0) {
      piVar7 = param_1;
      _objc_msgSend(param_1,paRegisterwithed);
      *param_5 = 0;
      if (iVar6 != 0) {
        *param_5 = 1;
        _objc_msgSend(param_1,paToken_0);
        *param_3 = (int)param_1;
      }
    }
    else {
      iVar3 = param_4;
      _strcmp(param_4,aIogetdisplayin);
      if (iVar3 == 0) {
        if (*param_5 == 5) {
          _objc_msgSend(param_1,paDisplayinfo);
          *param_3 = *param_1;
          param_3[1] = param_1[1];
          param_3[2] = param_1[4];
          param_3[3] = param_1[6];
          piVar7 = (int *)0x0;
          param_3[4] = param_1[7];
        }
        else {
          piVar7 = (int *)0xfffffd3e;
        }
      }
      else {
        *(int **)((int)register0x00000038 + -0x10) = param_1;
        piVar7 = (int *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
        _objc_msgSendSuper(piVar7,paGetintvaluesFo_0,param_3,param_4,param_5);
      }
    }
    goto locret_F00E9C98;
  }
  _objc_msgSend(param_1,paDisplayinfo);
  *(int *)((int)register0x00000038 + -0x28) = *param_1;
  *(int *)((int)register0x00000038 + -0x24) = param_1[1];
  *(int *)((int)register0x00000038 + -0x20) = param_1[3];
  *(int *)((int)register0x00000038 + -0x18) = param_1[0x18];
  switch(param_1[6]) {
  case :
    uVar2 = 2;
    break;
  case :
    uVar2 = 8;
    break;
  case :
    uVar2 = 0xc;
    break;
  case :
    uVar2 = 0xf;
    break;
  case :
    uVar2 = 0x20;
    break;
  :
    goto def_F00E9B14;
  }
  *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar2;
def_F00E9B14:
  *param_5 = 0;
  iVar5 = 0;
  puVar4 = (undefined *)((int)register0x00000038 + -8);
  iVar3 = 0;
  do {
    iVar5 = iVar5 + 1;
    if (*param_5 == iVar6) goto loc_F00E9AA4;
    *(undefined4 *)(iVar3 + (int)param_3) = *(undefined4 *)(puVar4 + -0x20);
    puVar4 = puVar4 + 4;
    iVar3 = iVar3 + 4;
    *param_5 = *param_5 + 1;
  } while (iVar5 < 5);
  piVar7 = (int *)0x0;
locret_F00E9C98:
  return CONCAT44(param_2,piVar7);
}
/* GHIDRADEC_FUNCTION index=4884 start=0xf00e9ca0 */

/* WARNING: Removing unreachable block (ram,0xf00e9ef8) */
/* WARNING: Removing unreachable block (ram,0xf00e9eac) */
/* WARNING: Removing unreachable block (ram,0xf00e9e40) */
/* WARNING: Removing unreachable block (ram,0xf00e9dd4) */
/* WARNING: Removing unreachable block (ram,0xf00e9d48) */
/* WARNING: Removing unreachable block (ram,0xf00e9d18) */
/* WARNING: Removing unreachable block (ram,0xf00e9cdc) */
/* WARNING: Removing unreachable block (ram,0xf00e9d08) */
/* WARNING: Removing unreachable block (ram,0xf00e9d2c) */
/* WARNING: Removing unreachable block (ram,0xf00e9dc0) */
/* WARNING: Removing unreachable block (ram,0xf00e9e04) */
/* WARNING: Removing unreachable block (ram,0xf00e9e70) */
/* WARNING: Removing unreachable block (ram,0xf00e9ec4) */
/* WARNING: Removing unreachable block (ram,0xf00e9cc8) */
/* WARNING: Removing unreachable block (ram,0xf00e9cac) */

undefined8
-[IOFrameBufferDisplay setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  iVar2 = param_4;
  _strcmp(param_4,aIoFramebufferU);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,paReverttovgamod);
loc_F00E9CD0:
    puVar4 = (undefined *)0x0;
    goto locret_F00E9F0C;
  }
  iVar2 = param_4;
  _strcmp(param_4,aIoFramebufferU_0);
  if (iVar2 == 0) {
    puVar4 = (undefined *)0xfffffd3e;
    if (param_5 == 1) {
      _objc_msgSend(paEventdriver_0,paInstance);
      _objc_msgSend();
      puVar4 = (undefined *)0x0;
    }
    goto locret_F00E9F0C;
  }
  iVar2 = param_4;
  _strcmp(param_4,aIosettransfert);
  if (iVar2 != 0) {
    iVar2 = param_4;
    _strcmp(param_4,aIoBm256ToBm38M);
    if (iVar2 == 0) {
      if (param_5 == 0x100) {
        if (*(int *)(param_1 + 0x208) == 0) {
          uVar1 = 0x400;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x208) = uVar1;
        }
        uVar3 = 0;
        iVar2 = 0;
        do {
          uVar3 = uVar3 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x208) + iVar2) = *(undefined4 *)(iVar2 + param_3);
          iVar2 = iVar2 + 4;
        } while (uVar3 < 0x100);
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = (undefined *)0xfffffd3e;
      }
      goto locret_F00E9F0C;
    }
    iVar2 = param_4;
    _strcmp(param_4,aIoBm38ToBm256M);
    if (iVar2 == 0) {
      if (param_5 == 0x100) {
        if (*(int *)(param_1 + 0x20c) == 0) {
          uVar1 = 0x400;
          _IOMalloc();
          *(undefined4 *)(param_1 + 0x20c) = uVar1;
        }
        uVar3 = 0;
        iVar2 = 0;
        do {
          uVar3 = uVar3 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x20c) + iVar2) = *(undefined4 *)(iVar2 + param_3);
          iVar2 = iVar2 + 4;
        } while (uVar3 < 0x100);
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = (undefined *)0xfffffd3e;
      }
      goto locret_F00E9F0C;
    }
    iVar2 = param_4;
    _strcmp(param_4,aSparcfbconfigu);
    if (iVar2 != 0) {
      iVar2 = param_4;
      _strcmp(param_4,aIodisplaydobli);
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      if (iVar2 == 0) {
        puVar4 = (undefined *)0xfffffd42;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
        _objc_msgSendSuper(puVar4,paSetintvaluesFo_0,param_3,param_4,param_5);
      }
      goto locret_F00E9F0C;
    }
    goto loc_F00E9CD0;
  }
  iVar2 = param_1;
  _objc_msgSend(param_1,paDisplayinfo);
  switch(*(undefined4 *)(iVar2 + 0x18)) {
  case :
    bVar5 = param_5 == 4;
    break;
  case :
  case :
    bVar5 = param_5 == 0x100;
    break;
  case :
    bVar5 = param_5 == 0x10;
    break;
  case :
    bVar5 = param_5 == 0x20;
    break;
  :
    goto def_F00E9D6C;
  }
  if (bVar5) {
    _objc_msgSend(param_1,paSettransfertab,param_3,param_5);
    puVar4 = (undefined *)0x0;
  }
  else {
def_F00E9D6C:
    puVar4 = (undefined *)0xfffffd3e;
  }
locret_F00E9F0C:
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=4885 start=0xf00e9f14 */

/* WARNING: Removing unreachable block (ram,0xf00e9f60) */
/* WARNING: Removing unreachable block (ram,0xf00e9f50) */
/* WARNING: Removing unreachable block (ram,0xf00e9f90) */
/* WARNING: Removing unreachable block (ram,0xf00e9f20) */

undefined8
-[IOFrameBufferDisplay getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined *puVar2;
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
  iVar1 = param_4;
  _strcmp(param_4,aIoFramebufferP);
  if (iVar1 == 0) {
    if (*param_5 == 0x40) {
      _objc_msgSend(param_1,paDisplayinfo);
      _strncpy(param_3,param_1 + 0x20,0x40);
      puVar2 = (undefined *)0x0;
    }
    else {
      puVar2 = (undefined *)0xfffffd3e;
    }
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
    _objc_msgSendSuper(puVar2,paGetcharvaluesF_0,param_3,param_4,param_5);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4886 start=0xf00e9fa4 */

/* WARNING: Removing unreachable block (ram,0xf00e9fcc) */

undefined8
-[IOFrameBufferDisplay setCharValues:forParameter:count:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _objc_msgSendSuper(puVar1,paSetcharvaluesF_0,param_3,param_4,param_5);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4887 start=0xf00e9fdc */

undefined8 -[IOFrameBufferDisplay enterLinearMode](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4888 start=0xf00e9fe8 */

undefined8 -[IOFrameBufferDisplay revertToVGAMode](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4889 start=0xf00e9ff4 */

sqword -[IOFrameBufferDisplay mapFrameBufferAtPhysicalAddress:length:]
                 (undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4890 start=0xf00ea000 */

/* WARNING: Removing unreachable block (ram,0xf00ea0fc) */
/* WARNING: Removing unreachable block (ram,0xf00ea0b4) */
/* WARNING: Removing unreachable block (ram,0xf00ea01c) */
/* WARNING: Removing unreachable block (ram,0xf00ea03c) */
/* WARNING: Removing unreachable block (ram,0xf00ea0d8) */
/* WARNING: Removing unreachable block (ram,0xf00ea118) */
/* WARNING: Removing unreachable block (ram,0xf00ea00c) */

undefined8 -[IOFrameBufferDisplay validMode:](undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  _objc_msgSend(param_1,paDisplayinfo);
  puVar4 = aColorspace;
  _strlen();
  if (*param_3 != '\0') {
loc_F00EA038:
    pcVar2 = param_3;
    _strncmp(param_3,aColorspace,puVar4);
    if (pcVar2 != (char *)0x0) goto loc_f00ea048;
    param_3 = param_3 + (int)puVar4;
    while( true ) {
      cVar1 = *param_3;
      if ((cVar1 == '\0') || ((cVar1 != ' ' && (cVar1 != '\t')))) break;
      param_3 = param_3 + 1;
    }
    uVar6 = (uint)param_3 & -(uint)(cVar1 != '\0');
    goto loc_F00EA0A0;
  }
loc_F00EA09C:
  uVar6 = 0;
loc_F00EA0A0:
  if (uVar6 == 0) {
    uVar5 = 0;
  }
  else {
    uVar3 = uVar6;
    _strncmp(uVar6,&aBw8,4);
    if (uVar3 == 0) {
      uVar5 = 8;
    }
    else {
      uVar3 = uVar6;
      _strncmp(uVar6,aRgb2568,9);
      if (uVar3 == 0) {
        uVar5 = 0x100;
      }
      else {
        uVar3 = uVar6;
        _strncmp(uVar6,aRgb88824,9);
        if (uVar3 != 0) {
          _strncmp(uVar6,aRgb88832,9);
          uVar5 = 0;
          if (uVar6 != 0) goto locret_F00EA138;
        }
        uVar5 = 0x378;
      }
    }
  }
locret_F00EA138:
  return CONCAT44(param_2,uVar5);
loc_f00ea048:
  param_3 = param_3 + 1;
  if (*param_3 == '\0') goto loc_F00EA09C;
  goto loc_F00EA038;
}
/* GHIDRADEC_FUNCTION index=4891 start=0xf00ea140 */

/* WARNING: Removing unreachable block (ram,0xf00ea174) */
/* WARNING: Removing unreachable block (ram,0xf00ea158) */
/* WARNING: Removing unreachable block (ram,0xf00ea18c) */
/* WARNING: Removing unreachable block (ram,0xf00ea14c) */

undefined8 -[IOFrameBufferDisplay selectMode:count:valid:](int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if ((iVar1 == 0) || (_objc_msgSend(), iVar1 == 0)) {
    param_1 = 0;
  }
  else {
    _objc_msgSend(param_1,paValidmode,iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4892 start=0xf00ea1a8 */

/* WARNING: Removing unreachable block (ram,0xf00ea1c0) */

undefined8
-[IOFrameBufferDisplay selectMode:count:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  _objc_msgSend(param_1,paSelectmodeCoun_0,param_3,param_4,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4893 start=0xf00ea1d0 */

undefined8 -[IOFrameBufferDisplay setTransferTable:count:](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4894 start=0xf00ea1dc */

/* WARNING: Removing unreachable block (ram,0xf00ea1ec) */

undefined8 sub_F00EA1DC(uint param_1,undefined4 param_2)

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
  if (param_1 < 2) {
    iVar1 = 0;
  }
  else {
    param_1 = param_1 >> 1;
    sub_F00EA1DC(param_1);
    iVar1 = param_1 + 1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4895 start=0xf00ea200 */

int sub_F00EA200(byte param_1)

{
  return (1 << (param_1 & 0x1f)) + -1;
}
/* GHIDRADEC_FUNCTION index=4896 start=0xf00ea210 */

/* WARNING: Removing unreachable block (ram,0xf00ea2d8) */
/* WARNING: Removing unreachable block (ram,0xf00ea250) */

undefined8 sub_F00EA210(char *param_1,byte *param_2)

{
  char cVar1;
  byte *pbVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  byte *pbVar3;
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
  cVar1 = *param_1;
  if (cVar1 == '*') {
loc_F00EA25C:
    pbVar2 = (byte *)0x0;
    if (param_2 == (byte *)0x0) {
      pbVar2 = (byte *)0x0;
      goto locret_F00EA2E0;
    }
    while( true ) {
      pbVar3 = param_2 + 1;
      if (*param_2 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*param_2);
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 8);
      pbVar3 = param_2 + 2;
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 0x10);
      pbVar3 = param_2 + 3;
      if (*pbVar3 == 0) break;
      pbVar2 = (byte *)((uint)pbVar2 ^ (uint)*pbVar3 << 0x18);
      param_2 = param_2 + 4;
    }
  }
  else {
    pbVar3 = param_2;
    if (cVar1 < '+') {
      if (cVar1 == '%') goto loc_F00EA25C;
loc_F00EA2D4:
      pbVar2 = (byte *)((uint)param_2 >> 0x10 ^ (uint)param_2);
    }
    else {
      if (cVar1 != '@') goto loc_F00EA2D4;
      pbVar2 = param_2;
      _objc_msgSend(param_2,paHash);
    }
  }
  .urem();
  param_2 = pbVar3;
locret_F00EA2E0:
  return CONCAT44(param_2,pbVar2);
}
/* GHIDRADEC_FUNCTION index=4897 start=0xf00ea2e8 */

/* WARNING: Removing unreachable block (ram,0xf00ea394) */
/* WARNING: Removing unreachable block (ram,0xf00ea36c) */
/* WARNING: Removing unreachable block (ram,0xf00ea33c) */

undefined8 sub_F00EA2E8(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  if (param_2 == param_3) {
    uVar3 = 1;
    goto locret_F00EA3A4;
  }
  cVar1 = *param_1;
  if (cVar1 != '*') {
    if ('*' < cVar1) {
      uVar3 = 0;
      if (cVar1 == '@') {
        pcVar2 = param_2;
        _objc_msgSend(param_2,paIsequal);
        uVar3 = (uint)(char)pcVar2;
      }
      goto locret_F00EA3A4;
    }
    if (cVar1 != '%') {
      uVar3 = 0;
      goto locret_F00EA3A4;
    }
  }
  pcVar2 = param_3;
  if ((param_2 == (char *)0x0) || (pcVar2 = param_2, param_3 == (char *)0x0)) {
    _strlen(pcVar2);
    uVar3 = (uint)(pcVar2 == (char *)0x0);
  }
  else {
    uVar3 = 0;
    if (*param_2 == *param_3) {
      _strcmp(param_2,param_3);
      uVar3 = (uint)(pcVar2 == (char *)0x0);
    }
  }
locret_F00EA3A4:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4898 start=0xf00ea3ac */

/* WARNING: Removing unreachable block (ram,0xf00ea3b8) */

undefined8 sub_F00EA3AC(undefined4 param_1,undefined4 param_2)

{
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
  _objc_msgSend(param_1,paFree);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4899 start=0xf00ea3d0 */

/* WARNING: Removing unreachable block (ram,0xf00ea3e0) */

undefined8 +[HashTable initialize](undefined4 param_1,undefined4 param_2)

{
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
  _objc_msgSend(param_1,paSetversion,1);
  return CONCAT44(param_2,param_1);
}

