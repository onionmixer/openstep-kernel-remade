/* GHIDRADEC_FUNCTION index=1250 start=0xf006243c */

/* WARNING: Removing unreachable block (ram,0xf0062474) */
/* WARNING: Removing unreachable block (ram,0xf0062458) */

undefined8 _mach_port_destroy(int param_1,undefined4 param_2)

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
    iVar1 = 0x10;
  }
  else {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      _ipc_right_destroy(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
      iVar1 = param_1;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1251 start=0xf0062488 */

/* WARNING: Removing unreachable block (ram,0xf00624c0) */
/* WARNING: Removing unreachable block (ram,0xf00624a4) */

undefined8 _mach_port_deallocate(int param_1,undefined4 param_2)

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
    iVar1 = 0x10;
  }
  else {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      _ipc_right_dealloc(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
      iVar1 = param_1;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1252 start=0xf00624d4 */

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
/* GHIDRADEC_FUNCTION index=1253 start=0xf00625ac */

/* WARNING: Removing unreachable block (ram,0xf00625fc) */
/* WARNING: Removing unreachable block (ram,0xf00625d8) */

undefined8 _mach_port_mod_refs(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

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
    iVar1 = 0x10;
  }
  else if (param_3 < 5) {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      _ipc_right_delta(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,
                       param_4);
      iVar1 = param_1;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1254 start=0xf0062610 */

/* WARNING: Removing unreachable block (ram,0xf006261c) */

undefined8 _old_mach_port_get_receive_status(int param_1,undefined4 param_2,undefined4 *param_3)

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
  _mach_port_get_receive_status(param_1,param_2,(undefined *)((int)register0x00000038 + -0x30));
  if (param_1 == 0) {
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0x30);
    param_3[1] = *(undefined4 *)((int)register0x00000038 + -0x28);
    param_3[2] = *(undefined4 *)((int)register0x00000038 + -0x24);
    param_3[3] = *(undefined4 *)((int)register0x00000038 + -0x20);
    param_3[4] = *(undefined4 *)((int)register0x00000038 + -0x1c);
    param_3[5] = *(undefined4 *)((int)register0x00000038 + -0x18);
    param_3[6] = *(undefined4 *)((int)register0x00000038 + -0x14);
    param_1 = 0;
    param_3[7] = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1255 start=0xf006267c */

/* WARNING: Removing unreachable block (ram,0xf00626bc) */
/* WARNING: Removing unreachable block (ram,0xf00626a4) */

undefined8 _mach_port_set_qlimit(int param_1,undefined4 param_2,uint param_3)

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
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = 0x12;
    if ((param_3 < 0x11) &&
       (_ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc)),
       iVar1 = param_1, param_1 == 0)) {
      _ipc_port_set_qlimit(*(undefined4 *)((int)register0x00000038 + -0xc),param_3);
      iVar1 = 0;
      **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1256 start=0xf00626d8 */

/* WARNING: Removing unreachable block (ram,0xf00626f4) */

undefined8 _mach_port_set_mscount(int param_1,undefined4 param_2,undefined4 param_3)

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
    param_1 = 0x10;
  }
  else {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      puVar1[6] = param_3;
      *puVar1 = 0;
      param_1 = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1257 start=0xf0062720 */

/* WARNING: Removing unreachable block (ram,0xf0062754) */
/* WARNING: Removing unreachable block (ram,0xf006273c) */

undefined8 _mach_port_set_seqno(int param_1,undefined4 param_2,undefined4 param_3)

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
    param_1 = 0x10;
  }
  else {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      _ipc_port_set_seqno(*(undefined4 *)((int)register0x00000038 + -0xc),param_3);
      param_1 = 0;
      **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1258 start=0xf0062770 */

/* WARNING: Removing unreachable block (ram,0xf0062784) */

undefined8 _mach_port_gst_helper(int param_1,int *param_2,uint param_3,int param_4,uint *param_5)

{
  int *piVar1;
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
  int iVar3;
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
  do {
    do {
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *param_2 = 0;
  iVar3 = param_2[4];
  if (param_1 == param_2[0xc]) {
    uVar2 = *param_5;
    if (uVar2 < param_3) {
      *(int *)(param_4 + uVar2 * 4) = iVar3;
    }
    *param_5 = uVar2 + 1;
  }
  return CONCAT44(iVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=1259 start=0xf00627d0 */

/* WARNING: Removing unreachable block (ram,0xf0062a18) */
/* WARNING: Removing unreachable block (ram,0xf00629d8) */
/* WARNING: Removing unreachable block (ram,0xf00628f0) */
/* WARNING: Removing unreachable block (ram,0xf00628bc) */
/* WARNING: Removing unreachable block (ram,0xf00629a8) */
/* WARNING: Removing unreachable block (ram,0xf0062830) */
/* WARNING: Removing unreachable block (ram,0xf0062820) */
/* WARNING: Removing unreachable block (ram,0xf0062990) */
/* WARNING: Removing unreachable block (ram,0xf00628a4) */
/* WARNING: Removing unreachable block (ram,0xf00628e4) */
/* WARNING: Removing unreachable block (ram,0xf0062908) */
/* WARNING: Removing unreachable block (ram,0xf00629f8) */
/* WARNING: Removing unreachable block (ram,0xf0062928) */
/* WARNING: Removing unreachable block (ram,0xf0062804) */

undefined8
_mach_port_get_set_status(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  undefined4 uVar5;
  undefined4 unaff_l5;
  uint uVar6;
  undefined4 unaff_l6;
  uint uVar7;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
  uint uVar9;
  undefined4 unaff_i1;
  undefined4 uVar10;
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
    iVar8 = 0x10;
    uVar10 = param_2;
  }
  else {
    uVar10 = 0x20000;
    uVar7 = _page_size;
    while( true ) {
      iVar8 = _ipc_kernel_map;
      _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
      if (iVar8 != 0) break;
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
      iVar8 = param_1;
      _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
      iVar1 = _ipc_kernel_map;
      if (iVar8 != 0) {
        _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
        goto locret_F0062A34;
      }
      uVar3 = 0;
      if ((**(uint **)((int)register0x00000038 + -0x10) & 0x1f0000) != 0x80000) {
        *(undefined4 *)(param_1 + 8) = 0;
        _kmem_free(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
        iVar8 = 0x11;
        goto locret_F0062A34;
      }
      uVar6 = (*(uint **)((int)register0x00000038 + -0x10))[1];
      uVar4 = *(uint *)(param_1 + 0x18);
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
      puVar2 = *(uint **)(param_1 + 0x14);
      uVar9 = uVar7 >> 2;
      if (uVar4 != 0) {
        do {
          if ((*puVar2 & 0x20000) != 0) {
            _mach_port_gst_helper
                      (uVar6,puVar2[1],uVar9,uVar5,(undefined *)((int)register0x00000038 + -0x14));
          }
          uVar3 = uVar3 + 1;
          puVar2 = puVar2 + 4;
        } while (uVar3 < uVar4);
      }
      puVar2 = (uint *)(param_1 + 0x20);
      _ipc_splay_traverse_start();
      while (puVar2 != (uint *)0x0) {
        if ((*puVar2 & 0x20000) != 0) {
          _mach_port_gst_helper
                    (uVar6,puVar2[1],uVar9,uVar5,(undefined *)((int)register0x00000038 + -0x14));
        }
        puVar2 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_next(puVar2,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x20);
      uVar3 = *(uint *)((int)register0x00000038 + -0x14);
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar3 <= uVar9) {
        if (*(int *)((int)register0x00000038 + -0x14) == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
          iVar8 = *(int *)((int)register0x00000038 + -0xc);
loc_F0062A18:
          _kmem_free(_ipc_kernel_map,iVar8,uVar7);
        }
        else {
          uVar3 = *(int *)((int)register0x00000038 + -0x14) * 4 + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                           *(int *)((int)register0x00000038 + -0xc) + uVar3,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                   uVar3,1,(undefined *)((int)register0x00000038 + -0x18));
          if (uVar3 != uVar7) {
            uVar7 = uVar7 - uVar3;
            iVar8 = *(int *)((int)register0x00000038 + -0xc) + uVar3;
            goto loc_F0062A18;
          }
        }
        *param_3 = *(undefined4 *)((int)register0x00000038 + -0x18);
        iVar8 = 0;
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0x14);
        goto locret_F0062A34;
      }
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
      uVar7 = (*(int *)((int)register0x00000038 + -0x14) * 4 + _page_mask & ~_page_mask) +
              _page_size;
    }
    iVar8 = 6;
  }
locret_F0062A34:
  return CONCAT44(uVar10,iVar8);
}
/* GHIDRADEC_FUNCTION index=1260 start=0xf0062a3c */

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
/* GHIDRADEC_FUNCTION index=1261 start=0xf0062af0 */

/* WARNING: Removing unreachable block (ram,0xf0062b78) */
/* WARNING: Removing unreachable block (ram,0xf0062bec) */
/* WARNING: Removing unreachable block (ram,0xf0062bd4) */
/* WARNING: Removing unreachable block (ram,0xf0062b5c) */
/* WARNING: Removing unreachable block (ram,0xf0062b98) */
/* WARNING: Removing unreachable block (ram,0xf0062bb4) */

undefined8
_mach_port_request_notification
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
    iVar3 = 0x10;
    goto locret_F0062C04;
  }
  if (param_5 == -1) {
    iVar3 = 0x14;
    goto locret_F0062C04;
  }
  if (param_3 == 0x46) {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0x14));
    iVar3 = param_1;
    if (param_1 == 0) {
      _ipc_port_nsrequest(*(undefined4 *)((int)register0x00000038 + -0x14),param_4,param_5,param_6);
      iVar3 = 0;
    }
    goto locret_F0062C04;
  }
  if (param_3 < 0x47) {
    if (param_3 != 0x45) {
      iVar3 = 0x12;
      goto locret_F0062C04;
    }
    iVar3 = 0x12;
    if ((param_4 != 0) ||
       (_ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc)),
       iVar3 = param_1, param_1 != 0)) goto locret_F0062C04;
    _ipc_port_pdrequest(*(undefined4 *)((int)register0x00000038 + -0xc),param_5,
                        (undefined *)((int)register0x00000038 + -0x10));
    uVar1 = *(uint *)((int)register0x00000038 + -0x10);
    uVar2 = 0;
    if (uVar1 != 0) {
      if ((uVar1 & 1) == 0) {
        *param_6 = uVar1;
        goto loc_F0062C00;
      }
      _ipc_port_release_send(uVar1 & 0xfffffffe);
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
    }
    *param_6 = uVar2;
  }
  else {
    if (param_3 != 0x48) {
      iVar3 = 0x12;
      goto locret_F0062C04;
    }
    _ipc_right_dnrequest(param_1,param_2,param_4 != 0,param_5,param_6);
    iVar3 = param_1;
    if (param_1 != 0) goto locret_F0062C04;
  }
loc_F0062C00:
  iVar3 = 0;
locret_F0062C04:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1262 start=0xf0062c0c */

/* WARNING: Removing unreachable block (ram,0xf0062c6c) */

undefined8 _mach_port_insert_right(int param_1,int param_2,int param_3,int param_4)

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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else if (((param_2 == 0) || (param_2 == -1)) || (2 < param_4 - 0x10U)) {
    param_1 = 0x12;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    param_1 = 0x14;
  }
  else {
    _ipc_object_copyout_name(param_1,param_3,param_4,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1263 start=0xf0062c80 */

/* WARNING: Removing unreachable block (ram,0xf0062cc8) */
/* WARNING: Removing unreachable block (ram,0xf0062cb4) */

undefined8
_mach_port_extract_right(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else if (param_3 - 0x10U < 6) {
    _ipc_object_copyin(param_1,param_2,param_3,param_4);
    if (param_1 == 0) {
      _ipc_object_copyin_type();
      *param_5 = param_3;
    }
  }
  else {
    param_1 = 0x12;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1264 start=0xf0062cdc */

/* WARNING: Removing unreachable block (ram,0xf0062dfc) */
/* WARNING: Removing unreachable block (ram,0xf0062d54) */
/* WARNING: Removing unreachable block (ram,0xf0062d30) */
/* WARNING: Removing unreachable block (ram,0xf0062d88) */
/* WARNING: Removing unreachable block (ram,0xf0062db4) */
/* WARNING: Removing unreachable block (ram,0xf0062cf8) */

undefined8 _mach_port_get_receive_status(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
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
  if (param_1 == 0) {
    param_1 = 0x10;
    goto locret_F0062E78;
  }
  _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 != 0) goto locret_F0062E78;
  param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 0x30);
  if (param_2 == (int *)0x0) {
loc_F0062DE0:
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
loc_F0062DE4:
    *param_3 = 0;
    do {
      do {
      } while (*(int *)(iVar2 + 0x40) != 0);
      piVar1 = (int *)(iVar2 + 0x40);
      _simple_lock_try();
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
    } while (piVar1 == (int *)0x0);
    param_3[1] = *(int *)(iVar3 + 0x34);
    *(undefined4 *)(iVar3 + 0x40) = 0;
    puVar4 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else {
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (-1 < param_2[2]) {
      _ipc_pset_remove(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
      *param_2 = 0;
      if (param_2[1] != 0) goto loc_F0062DE0;
      _zfree((&_ipc_object_zones)[(param_2[2] & 0x7fffffffU) >> 0x10],param_2);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      goto loc_F0062DE4;
    }
    *param_3 = param_2[3];
    do {
      do {
      } while (param_2[4] != 0);
      piVar1 = param_2 + 4;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    param_3[1] = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x34);
    param_2[4] = 0;
    *param_2 = 0;
    puVar4 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  param_3[2] = puVar4[6];
  param_3[3] = puVar4[0xf];
  param_3[4] = puVar4[0xe];
  param_3[5] = puVar4[8];
  param_3[6] = (uint)(puVar4[7] != 0);
  param_3[7] = (uint)(puVar4[10] != 0);
  param_1 = 0;
  param_3[8] = (uint)(puVar4[9] != 0);
  *puVar4 = 0;
locret_F0062E78:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1265 start=0xf0062e80 */

/* WARNING: Removing unreachable block (ram,0xf0062eb0) */
/* WARNING: Removing unreachable block (ram,0xf0062f0c) */
/* WARNING: Removing unreachable block (ram,0xf0062e8c) */

undefined8 _port_translate_compat(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar1 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    iVar1 = param_1;
    _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10),
                    (undefined *)((int)register0x00000038 + -0x14));
    uVar3 = *(uint *)((int)register0x00000038 + -0x10);
    if (iVar1 == 0) {
      if ((uVar3 & 0x20000) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        uVar4 = 4;
        if ((uVar3 & 0x170000) != 0) {
          uVar4 = 7;
        }
      }
      else {
        param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4);
        do {
          do {
          } while (*param_2 != 0);
          piVar2 = param_2;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        *param_3 = param_2;
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 4;
    }
  }
  else {
    uVar4 = 4;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1266 start=0xf0062f34 */

/* WARNING: Removing unreachable block (ram,0xf0062fbc) */

undefined8 _convert_port_type(uint param_1,undefined4 param_2)

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
  bool bVar1;
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
  param_1 = param_1 & 0x1f0000;
  if (param_1 == 0x30000) {
    param_1 = 7;
    goto locret_F0062FC4;
  }
  if (param_1 < 0x30001) {
    if (param_1 == 0x10000) {
loc_F0062FB4:
      param_1 = 1;
      goto locret_F0062FC4;
    }
    bVar1 = param_1 == 0x20000;
    param_1 = 7;
    if (bVar1) goto locret_F0062FC4;
  }
  else {
    if (param_1 == 0x80000) {
      param_1 = 9;
      goto locret_F0062FC4;
    }
    if (param_1 < 0x80001) {
      bVar1 = param_1 == 0x40000;
      param_1 = 1;
      if (bVar1) goto locret_F0062FC4;
    }
    else if (param_1 == 0x100000) goto loc_F0062FB4;
  }
  _panic(aConvertPortTyp);
locret_F0062FC4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1267 start=0xf0062fcc */

/* WARNING: Removing unreachable block (ram,0xf0063054) */
/* WARNING: Removing unreachable block (ram,0xf00630ac) */
/* WARNING: Removing unreachable block (ram,0xf006302c) */
/* WARNING: Removing unreachable block (ram,0xf0063090) */
/* WARNING: Removing unreachable block (ram,0xf00630e0) */
/* WARNING: Removing unreachable block (ram,0xf0063074) */
/* WARNING: Removing unreachable block (ram,0xf0062fe0) */

undefined8
_port_names(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
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
  _mach_port_names(param_1,param_2,param_3,param_4,param_5);
  if (param_1 == 0) {
    puVar5 = (undefined4 *)*param_5;
    uVar3 = *param_4;
    *(undefined4 *)((int)register0x00000038 + -0x10) = uVar3;
    uVar4 = (int)puVar5 * 4 + _page_mask & ~_page_mask;
    iVar1 = _ipc_soft_map;
    _vm_move(_ipc_soft_map,uVar3,_ipc_kernel_map,uVar4,0,
             (undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      param_2 = (undefined4 *)0x0;
      _vm_deallocate(_ipc_soft_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar4);
      puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
      if (puVar5 != (undefined4 *)0x0) {
        do {
          uVar3 = *puVar2;
          param_2 = (undefined4 *)((int)param_2 + 1);
          _convert_port_type();
          *puVar2 = uVar3;
          puVar2 = puVar2 + 1;
        } while (param_2 < puVar5);
      }
      param_1 = _ipc_kernel_map;
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar4,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_4 = *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    else {
      _kmem_free(_ipc_soft_map,*param_4,*param_5 * 4 + _page_mask & ~_page_mask);
      _kmem_free(_ipc_soft_map,*param_2,*param_3 * 4 + _page_mask & ~_page_mask);
      param_1 = 6;
    }
  }
  else if (param_1 != 6) {
    param_1 = 4;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1268 start=0xf0063108 */

/* WARNING: Removing unreachable block (ram,0xf0063128) */
/* WARNING: Removing unreachable block (ram,0xf0063114) */

undefined8 _port_type(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  _mach_port_type(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0xc);
    _convert_port_type();
    *param_3 = uVar1;
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1269 start=0xf0063140 */

/* WARNING: Removing unreachable block (ram,0xf006314c) */

undefined8 _port_rename(int param_1,undefined4 param_2,undefined4 param_3)

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
  _mach_port_rename(param_1,param_2,param_3);
  if ((param_1 != 0) && (param_1 != 0xd)) {
    param_1 = 4;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1270 start=0xf0063170 */

/* WARNING: Removing unreachable block (ram,0xf0063180) */

undefined8 _port_allocate(int param_1,undefined4 param_2)

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
  if (param_1 != 0) {
    _ipc_port_alloc_compat(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
      goto locret_F00631AC;
    }
    if (param_1 == 6) goto locret_F00631AC;
  }
  param_1 = 4;
locret_F00631AC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1271 start=0xf00631b4 */

/* WARNING: Removing unreachable block (ram,0xf00631ec) */
/* WARNING: Removing unreachable block (ram,0xf0063218) */
/* WARNING: Removing unreachable block (ram,0xf00631c8) */

undefined8 _port_deallocate(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  if (param_1 != 0) {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      uVar2 = 4;
      goto locret_F0063230;
    }
    iVar1 = param_1;
    _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10),
                    (undefined *)((int)register0x00000038 + -0x14));
    if (iVar1 != 0) {
      uVar2 = 4;
      goto locret_F0063230;
    }
    if ((*(uint *)((int)register0x00000038 + -0x10) & 0x170000) != 0) {
      _ipc_right_destroy(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
      uVar2 = 0;
      goto locret_F0063230;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  uVar2 = 4;
locret_F0063230:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1272 start=0xf0063238 */

/* WARNING: Removing unreachable block (ram,0xf0063278) */
/* WARNING: Removing unreachable block (ram,0xf0063260) */

undefined8 _port_set_backlog(int param_1,undefined4 param_2,int param_3)

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
  if ((param_1 == 0) || (0xf < param_3 - 1U)) {
    param_1 = 4;
  }
  else {
    _port_translate_compat(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      _ipc_port_set_qlimit(*(undefined4 *)((int)register0x00000038 + -0xc),param_3);
      param_1 = 0;
      **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1273 start=0xf0063294 */

/* WARNING: Removing unreachable block (ram,0xf00632e4) */
/* WARNING: Removing unreachable block (ram,0xf0063310) */
/* WARNING: Removing unreachable block (ram,0xf00632c8) */

undefined8 _port_set_backup(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

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
  uint uVar2;
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
    param_1 = 4;
  }
  else {
    if (param_3 == 0xffffffff) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (param_3 != 0) {
        uVar2 = param_3 | 1;
      }
    }
    _port_translate_compat(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      _ipc_port_pdrequest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar2,
                          (undefined *)((int)register0x00000038 + -0x10));
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
      uVar1 = 0;
      if (uVar2 != 0) {
        if ((uVar2 & 1) == 0) {
          _ipc_notify_send_once();
          *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
        }
        else {
          *(uint *)((int)register0x00000038 + -0x10) = uVar2 & 0xfffffffe;
        }
        uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
      }
      param_1 = 0;
      *param_4 = uVar1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1274 start=0xf0063330 */

/* WARNING: Removing unreachable block (ram,0xf006341c) */
/* WARNING: Removing unreachable block (ram,0xf00633c0) */
/* WARNING: Removing unreachable block (ram,0xf006336c) */
/* WARNING: Removing unreachable block (ram,0xf00633f8) */
/* WARNING: Removing unreachable block (ram,0xf0063450) */
/* WARNING: Removing unreachable block (ram,0xf0063348) */

undefined8
_port_status(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,undefined4 *param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  puVar6 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if (param_1 == 0) {
loc_F0063398:
    uVar7 = 4;
    goto locret_F00634BC;
  }
  iVar4 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar4 != 0) {
    uVar7 = 4;
    goto locret_F00634BC;
  }
  iVar4 = param_1;
  _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                  (undefined *)((int)register0x00000038 + -0x10),
                  (undefined *)((int)register0x00000038 + -0x14));
  if (iVar4 != 0) {
    uVar7 = 4;
    goto locret_F00634BC;
  }
  if ((*(uint *)((int)register0x00000038 + -0x10) & 0x170000) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    goto loc_F0063398;
  }
  if ((*(uint *)((int)register0x00000038 + -0x10) & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *param_6 = 0;
    *puVar6 = 0;
    *param_3 = 0;
    *param_4 = -1;
    *param_5 = 0;
  }
  else {
    param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4);
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 8) = 0;
    piVar1 = (int *)param_2[0xc];
    if (piVar1 == (int *)0x0) {
loc_F0063474:
      iVar5 = 0;
      iVar4 = param_2[0xf];
    }
    else {
      do {
        do {
        } while (*piVar1 != 0);
        piVar2 = piVar1;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (-1 < piVar1[2]) {
        _ipc_pset_remove(piVar1,param_2);
        *piVar1 = 0;
        if (piVar1[1] == 0) {
          _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
        }
        goto loc_F0063474;
      }
      iVar5 = piVar1[3];
      *piVar1 = 0;
      iVar4 = param_2[0xf];
    }
    *param_2 = 0;
    iVar3 = param_2[0xe];
    *param_6 = 1;
    *puVar6 = 1;
    *param_3 = iVar5;
    *param_4 = iVar3;
    *param_5 = iVar4;
  }
  uVar7 = 0;
locret_F00634BC:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1275 start=0xf00634c4 */

/* WARNING: Removing unreachable block (ram,0xf00634d4) */

undefined8 _port_set_allocate(int param_1,undefined4 param_2)

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
  if (param_1 != 0) {
    _ipc_pset_alloc(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
      goto locret_F0063500;
    }
    if (param_1 == 6) goto locret_F0063500;
  }
  param_1 = 4;
locret_F0063500:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1276 start=0xf0063508 */

/* WARNING: Removing unreachable block (ram,0xf006354c) */
/* WARNING: Removing unreachable block (ram,0xf006351c) */

undefined8 _port_set_deallocate(int param_1,undefined4 param_2)

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
  if (param_1 != 0) {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) goto locret_F0063564;
    if ((**(uint **)((int)register0x00000038 + -0xc) & 0x80000) != 0) {
      _ipc_right_destroy(param_1,param_2);
      iVar1 = param_1;
      goto locret_F0063564;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  iVar1 = 4;
locret_F0063564:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1277 start=0xf006356c */

/* WARNING: Removing unreachable block (ram,0xf00635f0) */
/* WARNING: Removing unreachable block (ram,0xf00635a4) */
/* WARNING: Removing unreachable block (ram,0xf0063628) */
/* WARNING: Removing unreachable block (ram,0xf0063580) */

undefined8 _port_set_add(uint *param_1,undefined4 param_2,undefined4 param_3)

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
  undefined4 uVar3;
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
  if (param_1 != (uint *)0x0) {
    puVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_3,(undefined *)((int)register0x00000038 + -0xc));
    if (puVar1 != (uint *)0x0) {
      param_1 = (uint *)0x4;
      goto locret_F0063634;
    }
    puVar1 = param_1;
    _ipc_right_info(param_1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10),
                    (undefined *)((int)register0x00000038 + -0x14));
    if (puVar1 != (uint *)0x0) {
      param_1 = (uint *)0x4;
      goto locret_F0063634;
    }
    uVar2 = *(uint *)((int)register0x00000038 + -0x10);
    if ((uVar2 & 0x20000) == 0) {
      param_1[2] = 0;
      param_1 = (uint *)0x4;
      if ((uVar2 & 0x170000) != 0) {
        param_1 = (uint *)0x7;
      }
      goto locret_F0063634;
    }
    uVar3 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4);
    puVar1 = param_1;
    _ipc_entry_lookup(param_1,param_2);
    *(uint **)((int)register0x00000038 + -0xc) = puVar1;
    if ((puVar1 != (uint *)0x0) && ((*puVar1 & 0x80000) != 0)) {
      _ipc_pset_move(param_1,uVar3,puVar1[1]);
      goto locret_F0063634;
    }
    param_1[2] = 0;
  }
  param_1 = (uint *)0x4;
locret_F0063634:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1278 start=0xf006363c */

/* WARNING: Removing unreachable block (ram,0xf0063674) */
/* WARNING: Removing unreachable block (ram,0xf00636c4) */
/* WARNING: Removing unreachable block (ram,0xf0063650) */

undefined8 _port_set_remove(int param_1,undefined4 param_2)

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
  if (param_1 != 0) {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      param_1 = 4;
      goto locret_F00636D0;
    }
    iVar1 = param_1;
    _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10),
                    (undefined *)((int)register0x00000038 + -0x14));
    uVar2 = *(uint *)((int)register0x00000038 + -0x10);
    if (iVar1 == 0) {
      if ((uVar2 & 0x20000) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        param_1 = 4;
        if ((uVar2 & 0x170000) != 0) {
          param_1 = 7;
        }
      }
      else {
        _ipc_pset_move(param_1,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4),0);
      }
      goto locret_F00636D0;
    }
  }
  param_1 = 4;
locret_F00636D0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1279 start=0xf00636d8 */

/* WARNING: Removing unreachable block (ram,0xf00636e8) */

undefined8 _port_set_status(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  _mach_port_get_set_status(param_1,param_2,param_3,param_4);
  if ((param_1 != 0) && (param_1 != 6)) {
    param_1 = 4;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1280 start=0xf006370c */

/* WARNING: Removing unreachable block (ram,0xf0063750) */

undefined8 _port_insert_send(int param_1,int param_2,int param_3)

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
  bool bVar1;
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
  if ((((param_1 == 0) || (param_3 == 0)) || (param_3 == -1)) || ((param_2 == 0 || (param_2 == -1)))
     ) {
    param_1 = 4;
  }
  else {
    _ipc_object_copyout_name_compat(param_1,param_2,0x11);
    if (param_1 != 6) {
      if (param_1 < 7) {
        if (param_1 != 0) {
          param_1 = 4;
        }
      }
      else {
        bVar1 = param_1 == 0x15;
        if ((param_1 != 0xd) && (param_1 = 4, bVar1)) {
          param_1 = 5;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1281 start=0xf00637a0 */

/* WARNING: Removing unreachable block (ram,0xf00637c4) */

undefined8 _port_extract_send(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _ipc_object_copyin_compat(param_1,param_2,6,1,param_3);
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = 4;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1282 start=0xf00637e4 */

/* WARNING: Removing unreachable block (ram,0xf0063828) */

undefined8 _port_insert_receive(int param_1,int param_2,int param_3)

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
  bool bVar1;
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
  if ((((param_1 == 0) || (param_3 == 0)) || (param_3 == -1)) || ((param_2 == 0 || (param_2 == -1)))
     ) {
    param_1 = 4;
  }
  else {
    _ipc_object_copyout_name_compat(param_1,param_2,0x10);
    if (param_1 != 6) {
      if (param_1 < 7) {
        if (param_1 != 0) {
          param_1 = 4;
        }
      }
      else {
        bVar1 = param_1 == 0x15;
        if ((param_1 != 0xd) && (param_1 = 4, bVar1)) {
          param_1 = 5;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1283 start=0xf0063878 */

/* WARNING: Removing unreachable block (ram,0xf006389c) */

undefined8 _port_extract_receive(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _ipc_object_copyin_compat(param_1,param_2,5,1,param_3);
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = 4;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1284 start=0xf00638bc */

undefined8 _ast_init(undefined4 param_1,undefined4 param_2)

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
  iVar2 = 0;
  iVar1 = 0;
  do {
    *(undefined4 *)((int)&_need_ast + iVar1) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
  } while (iVar2 < 1);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1285 start=0xf00638ec */

/* WARNING: Removing unreachable block (ram,0xf0063b38) */
/* WARNING: Removing unreachable block (ram,0xf0063bc4) */
/* WARNING: Removing unreachable block (ram,0xf0063bcc) */
/* WARNING: Removing unreachable block (ram,0xf00638f4) */

undefined8 _ast_check(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
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
  
  iVar3 = _active_threads;
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
  puVar4 = DAT_f0134000;
  _splusclock();
  iVar6 = *(int *)(_processor_ptr + 0x114);
  if (iVar6 != 1) {
    if (iVar6 < 2) {
      if (iVar6 == 0) goto loc_F0063BCC;
    }
    else if (iVar6 < 4) goto loc_F0063BCC;
    _panic(aAstCheckBadPro);
    goto loc_F0063BCC;
  }
  iVar6 = *_active_u;
  if ((iVar6 != 0) &&
     ((*(char *)(iVar6 + 0x17) != '\0' ||
      (((iVar3 != 0 &&
        (uVar1 = *(uint *)(iVar6 + 0x18) | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c), uVar1 != 0)) &&
       (((*(uint *)(iVar6 + 0x28) & 0x10) != 0 ||
        ((uVar1 & ~(*(uint *)(iVar6 + 0x20) | *(uint *)(iVar6 + 0x1c))) != 0)))))))) {
    _need_ast = _need_ast | 0x20;
  }
  _need_ast = _need_ast | *(uint *)(iVar3 + 0x18c);
  if (_need_ast != 0) goto loc_F0063BCC;
  if (((*(uint *)(iVar3 + 0x4c) & 2) != 0) || (0 < *(int *)(_processor_ptr + 0x108))) {
    _need_ast = 4;
    goto loc_F0063BCC;
  }
  iVar6 = *(int *)(_processor_ptr + 300);
  if ((*(uint *)(iVar6 + 0x168) & 2) == 0) {
    if ((*(int *)(_processor_ptr + 0x124) != 0) || (*(int *)(iVar6 + 0x108) < 1)) goto loc_F0063BCC;
    iVar5 = *(int *)(iVar6 + 0x104) * 8;
    if (iVar6 + iVar5 == *(int *)(iVar6 + iVar5)) {
      do {
        do {
        } while (*(int *)(iVar6 + 0x100) != 0);
        piVar9 = (int *)(iVar6 + 0x100);
        _simple_lock_try();
      } while (piVar9 == (int *)0x0);
      iVar5 = *(int *)(iVar6 + 0x104);
      piVar9 = (int *)(iVar6 + iVar5 * 8);
      if (0 < *(int *)(iVar6 + 0x108)) {
        if (iVar5 < 0) {
          *(int *)(iVar6 + 0x104) = iVar5;
        }
        else {
          do {
            if (piVar9 != (int *)*piVar9) {
              *(int *)(iVar6 + 0x104) = iVar5;
              goto loc_F0063B90;
            }
            iVar5 = iVar5 + -1;
            piVar9 = piVar9 + -2;
          } while (-1 < iVar5);
          *(int *)(iVar6 + 0x104) = iVar5;
        }
      }
loc_F0063B90:
      *(undefined4 *)(iVar6 + 0x100) = 0;
      iVar6 = *(int *)(iVar6 + 0x104);
    }
    else {
      iVar6 = *(int *)(iVar6 + 0x104);
    }
    uVar1 = _need_ast;
    if (iVar6 < *(int *)(iVar3 + 0x58)) goto loc_F0063BCC;
  }
  else {
    iVar8 = *(int *)(iVar6 + 0x104);
    iVar5 = *(int *)(iVar3 + 0x60);
    iVar7 = *(int *)(iVar3 + 0x58);
    if (((iVar5 == 2) || (2 < iVar5)) || (iVar5 != 1)) {
      if (*(int *)(iVar6 + 0x108) == 0) goto loc_F0063AC4;
      bVar2 = false;
      if (((iVar7 <= iVar8) && (bVar2 = true, iVar8 <= iVar7)) &&
         (bVar2 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = false;
      if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < *(int *)(iVar6 + 0x108))) &&
         (bVar2 = true, iVar8 < iVar7)) {
loc_F0063AC4:
        bVar2 = false;
      }
    }
    uVar1 = 0;
    if (!bVar2) {
      if (*(int *)(iVar3 + 0x60) == 2) {
        *(undefined4 *)(_processor_ptr + 0x124) = 1;
      }
      goto loc_F0063BCC;
    }
  }
  _need_ast = uVar1;
  _need_ast = _need_ast | 4;
loc_F0063BCC:
  _splx(puVar4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1286 start=0xf0063bdc */

/* WARNING: Removing unreachable block (ram,0xf0063ce8) */
/* WARNING: Removing unreachable block (ram,0xf0063cc0) */
/* WARNING: Removing unreachable block (ram,0xf0063c14) */
/* WARNING: Removing unreachable block (ram,0xf0063c5c) */
/* WARNING: Removing unreachable block (ram,0xf0063ccc) */
/* WARNING: Removing unreachable block (ram,0xf0063c90) */
/* WARNING: Removing unreachable block (ram,0xf0063bf4) */

undefined8
_exception_with_continuation(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
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
  int *piVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_threads;
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
    _panic(aException);
  }
  *(undefined4 *)(iVar1 + 0x38) = param_4;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar5 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = *(int **)(iVar1 + 0xb4);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
  }
  else {
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    if (piVar5[2] < 0) {
      piVar5[1] = piVar5[1] + 1;
      piVar5[7] = piVar5[7] + 1;
      *piVar5 = 0;
      *(int *)(iVar1 + 200) = param_1;
      *(undefined4 *)(iVar1 + 0xcc) = param_2;
      *(undefined4 *)(iVar1 + 0xd0) = param_3;
      iVar3 = iVar1;
      _retrieve_thread_self_fast(iVar1);
      uVar4 = *(undefined4 *)(iVar1 + 0xc);
      _retrieve_task_self_fast(uVar4);
      _exception_raise(piVar5,iVar3,uVar4,param_1,param_2,param_3);
      goto locret_F0063CF0;
    }
    *piVar5 = 0;
  }
  _exception_try_task(param_1,param_2,param_3);
locret_F0063CF0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1287 start=0xf0063cf8 */

/* WARNING: Removing unreachable block (ram,0xf0063e0c) */
/* WARNING: Removing unreachable block (ram,0xf0063de4) */
/* WARNING: Removing unreachable block (ram,0xf0063d38) */
/* WARNING: Removing unreachable block (ram,0xf0063d80) */
/* WARNING: Removing unreachable block (ram,0xf0063df0) */
/* WARNING: Removing unreachable block (ram,0xf0063db4) */
/* WARNING: Removing unreachable block (ram,0xf0063d18) */

undefined8 _exception(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
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
  
  iVar1 = _active_threads;
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
    _panic(aException);
  }
  *(code **)(iVar1 + 0x38) = _thread_exception_return;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar5 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = *(int **)(iVar1 + 0xb4);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
  }
  else {
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    if (piVar5[2] < 0) {
      piVar5[1] = piVar5[1] + 1;
      piVar5[7] = piVar5[7] + 1;
      *piVar5 = 0;
      *(int *)(iVar1 + 200) = param_1;
      *(undefined4 *)(iVar1 + 0xcc) = param_2;
      *(undefined4 *)(iVar1 + 0xd0) = param_3;
      iVar3 = iVar1;
      _retrieve_thread_self_fast(iVar1);
      uVar4 = *(undefined4 *)(iVar1 + 0xc);
      _retrieve_task_self_fast(uVar4);
      _exception_raise(piVar5,iVar3,uVar4,param_1,param_2,param_3);
      goto locret_F0063E14;
    }
    *piVar5 = 0;
  }
  _exception_try_task(param_1,param_2,param_3);
locret_F0063E14:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1288 start=0xf0063e1c */

/* WARNING: Removing unreachable block (ram,0xf0063f40) */
/* WARNING: Removing unreachable block (ram,0xf0063f18) */
/* WARNING: Removing unreachable block (ram,0xf0063e68) */
/* WARNING: Removing unreachable block (ram,0xf0063eb0) */
/* WARNING: Removing unreachable block (ram,0xf0063f24) */
/* WARNING: Removing unreachable block (ram,0xf0063ee4) */
/* WARNING: Removing unreachable block (ram,0xf0063e48) */

undefined8 _exception_from_kernel(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar6;
  undefined4 unaff_l5;
  undefined4 uVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 uVar9;
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
  
  iVar1 = _active_threads;
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
  uVar7 = *(undefined4 *)(_active_threads + 0x38);
  uVar8 = *(undefined4 *)(_active_threads + 200);
  uVar9 = *(undefined4 *)(_active_threads + 0xcc);
  uVar6 = *(undefined4 *)(_active_threads + 0xd0);
  if (param_1 == 0) {
    _panic(aException);
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar5 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = *(int **)(iVar1 + 0xb4);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
  }
  else {
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    if (piVar5[2] < 0) {
      piVar5[1] = piVar5[1] + 1;
      piVar5[7] = piVar5[7] + 1;
      *piVar5 = 0;
      *(int *)(iVar1 + 200) = param_1;
      *(undefined4 *)(iVar1 + 0xcc) = param_2;
      *(undefined4 *)(iVar1 + 0xd0) = param_3;
      iVar3 = iVar1;
      _retrieve_thread_self_fast(iVar1);
      uVar4 = *(undefined4 *)(iVar1 + 0xc);
      _retrieve_task_self_fast(uVar4);
      _exception_raise(piVar5,iVar3,uVar4,param_1,param_2,param_3);
      *(undefined4 *)(iVar1 + 0x38) = uVar7;
      goto loc_F0063F4C;
    }
    *piVar5 = 0;
  }
  _exception_try_task(param_1,param_2,param_3);
  *(undefined4 *)(iVar1 + 0x38) = uVar7;
loc_F0063F4C:
  *(undefined4 *)(iVar1 + 200) = uVar8;
  *(undefined4 *)(iVar1 + 0xcc) = uVar9;
  *(undefined4 *)(iVar1 + 0xd0) = uVar6;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1289 start=0xf0063f60 */

/* WARNING: Removing unreachable block (ram,0xf0064028) */
/* WARNING: Removing unreachable block (ram,0xf0063fcc) */
/* WARNING: Removing unreachable block (ram,0xf006401c) */
/* WARNING: Removing unreachable block (ram,0xf0064044) */
/* WARNING: Removing unreachable block (ram,0xf0063f84) */

undefined8 _exception_try_task(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int iVar6;
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
  
  iVar3 = _active_threads;
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
  iVar6 = *(int *)(_active_threads + 0xc);
  uVar4 = param_2;
  do {
    do {
    } while (*(int *)(iVar6 + 100) != 0);
    piVar1 = (int *)(iVar6 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  piVar5 = *(int **)(iVar6 + 0x70);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar6 + 100) = 0;
    _exception_no_server();
    return CONCAT44(uVar4,piVar1);
  }
  do {
    do {
    } while (*piVar5 != 0);
    piVar1 = piVar5;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(undefined4 *)(iVar6 + 100) = 0;
  iVar2 = piVar5[2];
  if (iVar2 < 0) {
    piVar5[1] = piVar5[1] + 1;
    piVar5[7] = piVar5[7] + 1;
    *piVar5 = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    _retrieve_thread_self_fast(iVar3);
    _retrieve_task_self_fast(iVar6);
    _exception_raise(piVar5,iVar3,iVar6,param_1,param_2,param_3);
    return CONCAT44(param_2,param_1);
  }
  *piVar5 = 0;
  _exception_no_server();
  return CONCAT44(uVar4,iVar2);
}
/* GHIDRADEC_FUNCTION index=1290 start=0xf0064054 */

/* WARNING: Removing unreachable block (ram,0xf006407c) */
/* WARNING: Removing unreachable block (ram,0xf0064084) */
/* WARNING: Removing unreachable block (ram,0xf0064064) */

undefined8 _exception_no_server(undefined4 param_1,undefined4 param_2)

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
  
  iVar1 = _active_threads;
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
  while ((*(uint *)(iVar1 + 0x18c) & 3) != 0) {
    _thread_halt_self();
  }
  _task_terminate(*(undefined4 *)(iVar1 + 0xc));
  _thread_halt_self();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1291 start=0xf0064094 */

/* WARNING: Removing unreachable block (ram,0xf006480c) */
/* WARNING: Removing unreachable block (ram,0xf006476c) */
/* WARNING: Removing unreachable block (ram,0xf00646c4) */
/* WARNING: Removing unreachable block (ram,0xf00646ac) */
/* WARNING: Removing unreachable block (ram,0xf0064668) */
/* WARNING: Removing unreachable block (ram,0xf006463c) */
/* WARNING: Removing unreachable block (ram,0xf0064604) */
/* WARNING: Removing unreachable block (ram,0xf006452c) */
/* WARNING: Removing unreachable block (ram,0xf0064500) */
/* WARNING: Removing unreachable block (ram,0xf00644a4) */
/* WARNING: Removing unreachable block (ram,0xf0064464) */
/* WARNING: Removing unreachable block (ram,0xf00643c0) */
/* WARNING: Removing unreachable block (ram,0xf00642dc) */
/* WARNING: Removing unreachable block (ram,0xf00641f0) */
/* WARNING: Removing unreachable block (ram,0xf0064194) */
/* WARNING: Removing unreachable block (ram,0xf006414c) */
/* WARNING: Removing unreachable block (ram,0xf00640fc) */
/* WARNING: Removing unreachable block (ram,0xf00640d0) */
/* WARNING: Removing unreachable block (ram,0xf0064130) */
/* WARNING: Removing unreachable block (ram,0xf0064178) */
/* WARNING: Removing unreachable block (ram,0xf00641d8) */
/* WARNING: Removing unreachable block (ram,0xf0064244) */
/* WARNING: Removing unreachable block (ram,0xf0064378) */
/* WARNING: Removing unreachable block (ram,0xf0064458) */
/* WARNING: Removing unreachable block (ram,0xf0064480) */
/* WARNING: Removing unreachable block (ram,0xf00644c8) */
/* WARNING: Removing unreachable block (ram,0xf006451c) */
/* WARNING: Removing unreachable block (ram,0xf0064534) */
/* WARNING: Removing unreachable block (ram,0xf0064624) */
/* WARNING: Removing unreachable block (ram,0xf0064658) */
/* WARNING: Removing unreachable block (ram,0xf006467c) */
/* WARNING: Removing unreachable block (ram,0xf00646b4) */
/* WARNING: Removing unreachable block (ram,0xf0064754) */
/* WARNING: Removing unreachable block (ram,0xf00647b8) */
/* WARNING: Removing unreachable block (ram,0xf006481c) */
/* WARNING: Removing unreachable block (ram,0xf00640b8) */

undefined8
_exception_raise(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  undefined4 unaff_l0;
  int *piVar12;
  undefined4 unaff_l1;
  int iVar13;
  undefined4 unaff_l3;
  int *piVar14;
  undefined4 unaff_l4;
  undefined4 *puVar15;
  undefined4 unaff_l5;
  int *piVar16;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  uint uVar17;
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
  
  iVar2 = _ipc_kmsg_cache;
  iVar1 = _active_threads;
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
  if (_ipc_kmsg_cache == 0) {
    iVar2 = 0x100;
    _kalloc();
    if (iVar2 == 0) {
      _panic(aExceptionRaise);
    }
    *(undefined4 *)(iVar2 + 8) = 0x100;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar2 + 0x10) = 0;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar14 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar14 == (int *)0x0);
  piVar14 = *(int **)(iVar1 + 0xc0);
  if (piVar14 == (int *)0x0) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    piVar14 = _ipc_space_reply;
    _ipc_port_alloc_special();
    do {
      do {
      } while (*(int *)(iVar1 + 0xa8) != 0);
      piVar12 = (int *)(iVar1 + 0xa8);
      _simple_lock_try();
    } while (piVar12 == (int *)0x0);
    if ((piVar14 == (int *)0x0) || (*(int *)(iVar1 + 0xc0) != 0)) {
      _panic(aExceptionRaise_0);
    }
    *(int **)(iVar1 + 0xc0) = piVar14;
  }
  do {
    do {
    } while (*piVar14 != 0);
    piVar12 = piVar14;
    _simple_lock_try();
    piVar16 = piVar14 + 0x10;
  } while (piVar12 == (int *)0x0);
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  piVar14[8] = piVar14[8] + 1;
  piVar14[1] = piVar14[1] + 2;
  *(int **)(iVar1 + 0xc4) = piVar14;
  do {
    do {
    } while (*piVar16 != 0);
    piVar12 = piVar16;
    _simple_lock_try();
  } while (piVar12 == (int *)0x0);
  *piVar14 = 0;
  piVar12 = param_1;
  _simple_lock_try();
  if (piVar12 == (int *)0x0) {
    *piVar16 = 0;
    goto loc_F00646D0;
  }
  if ((param_1[2] < 0) && (param_1[3] != _ipc_space_kernel)) {
    piVar12 = (int *)(param_1[0xc] + 0x10);
    if (param_1[0xc] == 0) {
      piVar12 = param_1 + 0x10;
    }
    piVar3 = piVar12;
    _simple_lock_try();
    if (piVar3 != (int *)0x0) {
      *param_1 = 0;
      iVar13 = piVar12[2];
      if ((((iVar13 == 0) || (*(int *)(iVar1 + 0x38) == 0)) ||
          ((*(code **)(iVar13 + 0x34) != _mach_msg_continue &&
           (((*(code **)(iVar13 + 0x34) != _mach_msg_receive_continue ||
             (*(uint *)(iVar13 + 0x9c) < 0x40)) || ((*(uint *)(iVar13 + 200) & 0x200) != 0)))))) ||
         (iVar6 = iVar1, _thread_handoff(iVar1,_exception_raise_continue,iVar13), iVar6 == 0)) {
        *piVar16 = 0;
        *piVar12 = 0;
        goto loc_F00646D0;
      }
      iVar6 = piVar14[0x12];
      if (iVar6 == 0) {
        piVar14[0x12] = iVar1;
      }
      else {
        iVar8 = *(int *)(iVar6 + 0x94);
        *(int *)(iVar1 + 0x90) = iVar6;
        *(int *)(iVar1 + 0x94) = iVar8;
        *(int *)(iVar6 + 0x94) = iVar1;
        *(int *)(iVar8 + 0x90) = iVar1;
      }
      *(undefined4 *)(iVar1 + 0x98) = 0x10004001;
      *(undefined4 *)(iVar1 + 0x9c) = 0xffffffff;
      *piVar16 = 0;
      iVar6 = *(int *)(iVar13 + 0x90);
      if (iVar6 == iVar13) {
        piVar12[2] = 0;
      }
      else {
        iVar8 = *(int *)(iVar13 + 0x94);
        piVar12[2] = iVar6;
        *(int *)(iVar6 + 0x94) = iVar8;
        *(int *)(iVar8 + 0x90) = iVar6;
        *(int *)(iVar13 + 0x90) = iVar13;
        *(int *)(iVar13 + 0x94) = iVar13;
      }
      *piVar12 = 0;
      piVar12 = *(int **)(iVar13 + 0xd8);
      do {
        do {
        } while (*piVar12 != 0);
        piVar3 = piVar12;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      iVar6 = piVar12[1];
      piVar12[1] = iVar6 + -1;
      *piVar12 = 0;
      if (iVar6 + -1 == 0) {
        _zfree((&_ipc_object_zones)[(piVar12[2] & 0x7fffffffU) >> 0x10],piVar12);
      }
      uVar17 = *(uint *)(*(int *)(iVar13 + 0xc) + 0x88);
      *(undefined4 *)(iVar2 + 0x14) = 0x80001112;
      *(undefined4 *)(iVar2 + 0x18) = 0x40;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x28) = 0x960;
      *(undefined4 *)(iVar2 + 0x2c) = _exc_port_proto;
      *(undefined4 *)(iVar2 + 0x34) = _exc_port_proto;
      *(undefined4 *)(iVar2 + 0x3c) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x40) = param_4;
      *(undefined4 *)(iVar2 + 0x44) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x48) = param_5;
      *(undefined4 *)(iVar2 + 0x4c) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x50) = param_6;
      puVar15 = (undefined4 *)(iVar2 + 0x14);
      if (*(uint *)(iVar13 + 0xcc) < 0x40) {
        *(undefined4 *)(iVar2 + 0x14) = 0x80001211;
        *(int **)(iVar2 + 0x1c) = param_1;
        *(int **)(iVar2 + 0x20) = piVar14;
        *(undefined4 *)(iVar2 + 0x30) = param_2;
        *(undefined4 *)(iVar2 + 0x38) = param_3;
        _ipc_kmsg_destroy(iVar2);
        _thread_syscall_return(0x10004004);
      }
      do {
        do {
        } while (*(int *)(uVar17 + 8) != 0);
        piVar12 = (int *)(uVar17 + 8);
        _simple_lock_try();
      } while (piVar12 == (int *)0x0);
      do {
        do {
        } while (*param_1 != 0);
        piVar12 = param_1;
        _simple_lock_try();
      } while (piVar12 == (int *)0x0);
      if (-1 < param_1[2]) goto loc_F00644DC;
      piVar12 = piVar14;
      _simple_lock_try();
      if (piVar12 == (int *)0x0) goto loc_F00644DC;
      iVar6 = piVar14[2];
loc_F0064540:
      if (-1 < iVar6) {
        *piVar14 = 0;
loc_F00644DC:
        *param_1 = 0;
        *(undefined4 *)(uVar17 + 8) = 0;
        *puVar15 = 0x80001211;
        *(int **)(iVar2 + 0x1c) = param_1;
        *(int **)(iVar2 + 0x20) = piVar14;
        puVar4 = puVar15;
        _ipc_kmsg_copyout_header(puVar15,uVar17,0);
        if (puVar4 == (undefined4 *)0x0) goto loc_F006461C;
        *(undefined4 *)(iVar2 + 0x30) = param_2;
        *(undefined4 *)(iVar2 + 0x38) = param_3;
        _ipc_kmsg_copyout_dest(iVar2,uVar17);
        _ipc_kmsg_put(*(undefined4 *)(iVar13 + 0xc4),iVar2,0x18);
        _thread_syscall_return(puVar4);
        iVar6 = piVar14[2];
        goto loc_F0064540;
      }
      *piVar14 = 0;
      iVar10 = *(int *)(uVar17 + 0x14);
      iVar6 = *(int *)(iVar10 + 8);
      iVar8 = iVar6 * 0x10;
      if (iVar6 == 0) goto loc_F00644DC;
      iVar9 = iVar10 + iVar8;
      *(undefined4 *)(iVar10 + 8) = *(undefined4 *)(iVar9 + 8);
      *(undefined4 *)(iVar9 + 8) = 0;
      uVar7 = *(int *)(iVar10 + iVar8) + 0x1000000;
      *(uint *)(iVar2 + 0x1c) = iVar6 << 8 | uVar7 >> 0x18;
      *(uint *)(iVar10 + iVar8) = uVar7 | 0x40001;
      *(int **)(iVar9 + 4) = piVar14;
      *(undefined4 *)(uVar17 + 8) = 0;
      param_1[1] = param_1[1] + -1;
      iVar6 = 0;
      if (param_1[3] == uVar17) {
        iVar6 = param_1[4];
      }
      *(int *)(iVar2 + 0x20) = iVar6;
      iVar6 = param_1[7];
      param_1[7] = iVar6 + -1;
      if ((iVar6 + -1 == 0) && (iVar6 = param_1[9], iVar6 != 0)) {
        param_1[9] = 0;
        *param_1 = 0;
        _ipc_notify_no_senders(iVar6,param_1[6]);
      }
      else {
        *param_1 = 0;
      }
loc_F006461C:
      uVar7 = uVar17;
      _ipc_kmsg_copyout_object(uVar17,param_2,0x11,iVar2 + 0x30);
      _ipc_kmsg_copyout_object(uVar17,param_3,0x11,iVar2 + 0x38);
      if ((uVar7 | uVar17) == 0) {
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
      else {
        _ipc_kmsg_put(*(undefined4 *)(iVar13 + 0xc4),iVar2,*(undefined4 *)(iVar2 + 0x18));
        _thread_syscall_return(uVar7 | uVar17 | 0x1000400c);
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
      iVar6 = iVar2 + 0x14;
      _copyoutmsg(iVar6,*(undefined4 *)(iVar13 + 0xc4),0x40);
      if (iVar6 == 0) {
        if (_ipc_kmsg_cache != 0) {
          uVar5 = *(undefined4 *)(iVar13 + 0xc4);
          goto loc_F00646A8;
        }
      }
      else {
        uVar5 = *(undefined4 *)(iVar13 + 0xc4);
loc_F00646A8:
        _ipc_kmsg_put(uVar5,iVar2,*(undefined4 *)(iVar2 + 0x18));
        _thread_syscall_return();
      }
      _ipc_kmsg_cache = iVar2;
      _thread_syscall_return(0);
      goto loc_F00646D0;
    }
  }
  *piVar16 = 0;
  *param_1 = 0;
loc_F00646D0:
  *(undefined4 *)(iVar2 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar2 + 0x18) = 0x40;
  *(int **)(iVar2 + 0x1c) = param_1;
  *(int **)(iVar2 + 0x20) = piVar14;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0x960;
  *(undefined4 *)(iVar2 + 0x2c) = _exc_port_proto;
  *(undefined4 *)(iVar2 + 0x30) = param_2;
  *(undefined4 *)(iVar2 + 0x34) = _exc_port_proto;
  *(undefined4 *)(iVar2 + 0x38) = param_3;
  *(undefined4 *)(iVar2 + 0x3c) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x40) = param_4;
  *(undefined4 *)(iVar2 + 0x44) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x48) = param_5;
  _exception_raise_misses = _exception_raise_misses + 1;
  *(undefined4 *)(iVar2 + 0x4c) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x50) = param_6;
  _ipc_mqueue_send(iVar2,0x10000,0,0);
  do {
    do {
    } while (*piVar14 != 0);
    piVar12 = piVar14;
    _simple_lock_try();
  } while (piVar12 == (int *)0x0);
  if (piVar14[2] < 0) {
    do {
      do {
      } while (*piVar16 != 0);
      piVar12 = piVar16;
      _simple_lock_try();
    } while (piVar12 == (int *)0x0);
    *piVar14 = 0;
    if (*(int *)(iVar1 + 0x38) == 0) {
      pcVar11 = (code *)0x0;
    }
    else {
      pcVar11 = _exception_raise_continue;
    }
    _ipc_mqueue_receive(piVar16,0,0xffffffff,0,0,pcVar11,
                        (undefined *)((int)register0x00000038 + -0xc),
                        (undefined *)((int)register0x00000038 + -0x10));
  }
  else {
    *piVar14 = 0;
  }
  _exception_raise_continue_slow();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1292 start=0xf006482c */

/* WARNING: Removing unreachable block (ram,0xf006487c) */
/* WARNING: Removing unreachable block (ram,0xf00648b4) */
/* WARNING: Removing unreachable block (ram,0xf00648d4) */

undefined8 _exception_parse_reply(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  if (*(int *)(param_1 + 0x14) == 0x12) {
    if (*(int *)(param_1 + 0x18) == 0x20) {
      if (*(int *)(param_1 + 0x28) == 0x9c4) {
        if (*(int *)(param_1 + 0x2c) == _exc_code_proto) {
          uVar2 = *(undefined4 *)(param_1 + 0x30);
          if (*(int *)(param_1 + 8) == 0x100) {
            iVar1 = param_1;
            if (_ipc_kmsg_cache == 0) goto locret_F00648E0;
            iVar1 = *(int *)(param_1 + 8);
          }
          else {
            iVar1 = *(int *)(param_1 + 8);
          }
          if (iVar1 < 1) {
            _ipc_kmsg_free(param_1);
            iVar1 = _ipc_kmsg_cache;
          }
          else {
            _kfree(param_1);
            iVar1 = _ipc_kmsg_cache;
          }
          goto locret_F00648E0;
        }
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  _ipc_kmsg_destroy(param_1);
  uVar2 = 0xfffffed3;
  iVar1 = _ipc_kmsg_cache;
locret_F00648E0:
  _ipc_kmsg_cache = iVar1;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1293 start=0xf00648e8 */

/* WARNING: Removing unreachable block (ram,0xf006492c) */
/* WARNING: Removing unreachable block (ram,0xf0064920) */

undefined8 _exception_raise_continue(undefined4 param_1,undefined4 param_2)

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
  _ipc_mqueue_receive(*(int *)(_active_threads + 0xc4) + 0x40,0,0xffffffff,0,1,
                      _exception_raise_continue,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  _exception_raise_continue_slow();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1294 start=0xf006493c */

/* WARNING: Removing unreachable block (ram,0xf0064b60) */
/* WARNING: Removing unreachable block (ram,0xf0064af4) */
/* WARNING: Removing unreachable block (ram,0xf0064ad8) */
/* WARNING: Removing unreachable block (ram,0xf0064a58) */
/* WARNING: Removing unreachable block (ram,0xf00649e8) */
/* WARNING: Removing unreachable block (ram,0xf006499c) */
/* WARNING: Removing unreachable block (ram,0xf00649b8) */
/* WARNING: Removing unreachable block (ram,0xf0064a24) */
/* WARNING: Removing unreachable block (ram,0xf0064aac) */
/* WARNING: Removing unreachable block (ram,0xf0064aec) */
/* WARNING: Removing unreachable block (ram,0xf0064b28) */
/* WARNING: Removing unreachable block (ram,0xf0064b44) */
/* WARNING: Removing unreachable block (ram,0xf006498c) */

undefined8 _exception_raise_continue_slow(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar6;
  undefined4 unaff_i2;
  int *piVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar1 = _active_threads;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  piVar6 = *(int **)(_active_threads + 0xc4);
  piVar7 = piVar6 + 0x10;
  if (param_1 == (int *)0x10004005) {
    uVar2 = *(uint *)(_active_threads + 0x18c);
joined_r0xf0064974:
    while ((uVar2 & 3) != 0) {
      if (piVar6 == (int *)0x0) {
loc_F0064994:
        *(undefined4 *)(iVar1 + 0xc4) = 0;
      }
      else {
        if (piVar6 != (int *)0xffffffff) {
          _ipc_object_release(piVar6);
          goto loc_F0064994;
        }
        *(undefined4 *)(iVar1 + 0xc4) = 0;
      }
      piVar7 = (int *)0x0;
      _thread_halt_self_with_continuation(0);
      do {
        do {
        } while (*(int *)(iVar1 + 0xa8) != 0);
        piVar6 = (int *)(iVar1 + 0xa8);
        _simple_lock_try();
      } while (piVar6 == (int *)0x0);
      piVar6 = *(int **)(iVar1 + 0xc0);
      *(int **)(iVar1 + 0xc4) = piVar6;
      if (piVar6 == (int *)0x0) {
loc_F00649F0:
        uVar2 = *(uint *)(iVar1 + 0x18c);
      }
      else {
        if (piVar6 != (int *)0xffffffff) {
          piVar7 = piVar6 + 0x10;
          _ipc_object_reference();
          goto loc_F00649F0;
        }
        uVar2 = *(uint *)(iVar1 + 0x18c);
      }
      *(undefined4 *)(iVar1 + 0xa8) = 0;
    }
    if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
      do {
        do {
        } while (*piVar6 != 0);
        piVar3 = piVar6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if (piVar6[2] < 0) {
        do {
          do {
          } while (*piVar7 != 0);
          piVar3 = piVar7;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        *piVar6 = 0;
        if (*(int *)(iVar1 + 0x38) == 0) {
          pcVar5 = (code *)0x0;
        }
        else {
          pcVar5 = _exception_raise_continue;
        }
        param_1 = piVar7;
        _ipc_mqueue_receive(piVar7,0,0xffffffff,0,0,pcVar5,
                            (undefined *)((int)register0x00000038 + 0x48),
                            (undefined *)((int)register0x00000038 + 0x4c));
        if (param_1 != (int *)0x10004005) goto loc_F0064AC4;
        uVar2 = *(uint *)(iVar1 + 0x18c);
        goto joined_r0xf0064974;
      }
      *piVar6 = 0;
    }
    param_1 = (int *)0x10004009;
  }
loc_F0064AC4:
  if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
    _ipc_object_release(piVar6);
  }
  if (param_1 == (int *)0x0) {
    _ipc_port_release_sonce(piVar6);
    param_1 = *(int **)((int)register0x00000038 + 0x48);
    _exception_parse_reply();
  }
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0x10004009)) {
    if (*(int *)(iVar1 + 0x38) == 0) goto locret_F0064B68;
    _call_continuation();
    iVar4 = *(int *)(iVar1 + 200);
  }
  else {
    iVar4 = *(int *)(iVar1 + 200);
  }
  if (iVar4 == 0) {
    _exception_no_server();
  }
  else {
    _exception_try_task(iVar4,*(undefined4 *)(iVar1 + 0xcc),*(undefined4 *)(iVar1 + 0xd0));
  }
locret_F0064B68:
  return CONCAT44(piVar6,param_1);
}
/* GHIDRADEC_FUNCTION index=1295 start=0xf0064b70 */

/* WARNING: Removing unreachable block (ram,0xf0064bdc) */
/* WARNING: Removing unreachable block (ram,0xf0064bbc) */
/* WARNING: Removing unreachable block (ram,0xf0064be4) */
/* WARNING: Removing unreachable block (ram,0xf0064b98) */

undefined8 _exception_raise_continue_fast(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
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
  
  iVar2 = _active_threads;
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
  puVar3 = DAT_f0134000;
  param_1[8] = param_1[8] + -1;
  param_1[1] = param_1[1] + -2;
  *param_1 = 0;
  iVar1 = param_2;
  _exception_parse_reply();
  if (iVar1 != 0) {
    if (*(int *)(iVar2 + 200) != 0) {
      _exception_try_task();
    }
    _exception_no_server();
    return CONCAT44(param_2,param_1);
  }
  iVar2 = *(int *)(iVar2 + 0x38);
  if (iVar2 != 0) {
    _call_continuation();
  }
  _thread_exception_return();
  return CONCAT44(puVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=1296 start=0xf0064bf4 */

/* WARNING: Removing unreachable block (ram,0xf0064c50) */
/* WARNING: Removing unreachable block (ram,0xf0064cd8) */
/* WARNING: Removing unreachable block (ram,0xf0064c48) */

undefined8 _host_processors(int param_1,int *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  uVar7 = 0;
  if (param_1 == 0) {
    uVar8 = 4;
  }
  else {
    iVar4 = 0;
    iVar2 = 0;
    do {
      if (*(int *)((int)&_machine_slot + iVar2) != 0) {
        uVar7 = uVar7 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar4 < 1);
    if (uVar7 == 0) {
      _panic(aHostProcessors);
    }
    puVar1 = (undefined4 *)(uVar7 << 2);
    _kalloc();
    if (puVar1 == (undefined4 *)0x0) {
      uVar8 = 6;
    }
    else {
      iVar5 = 0;
      iVar4 = 0;
      iVar2 = 0;
      puVar3 = puVar1;
      do {
        if (*(int *)((int)&_machine_slot + iVar2) != 0) {
          *puVar3 = *(undefined4 *)((int)&_processor_ptr + iVar4);
          puVar3 = puVar3 + 1;
        }
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar5 < 1);
      *param_3 = uVar7;
      *param_2 = (int)puVar1;
      uVar6 = 0;
      if (uVar7 != 0) {
        do {
          uVar8 = *puVar1;
          uVar6 = uVar6 + 1;
          _convert_processor_to_port();
          *puVar1 = uVar8;
          puVar1 = puVar1 + 1;
        } while (uVar6 < uVar7);
      }
      uVar8 = 0;
    }
  }
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=1297 start=0xf0064cfc */

/* WARNING: Removing unreachable block (ram,0xf0064e68) */
/* WARNING: Removing unreachable block (ram,0xf0064e7c) */
/* WARNING: Removing unreachable block (ram,0xf0064e34) */

undefined8 _host_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 != 0) {
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          uVar4 = 4;
          goto locret_F0064E98;
        }
        if (4 < *param_4) {
          *param_3 = dword_F013C048;
          param_3[1] = DAT_f013c04c;
          param_3[2] = dword_F013C050;
          iVar3 = _master_processor;
          param_3[3] = (&dword_F0134764)[*(int *)(_master_processor + 0x144) * 8];
          uVar4 = 0;
          param_3[4] = (&dword_F0134768)[*(int *)(iVar3 + 0x144) * 8];
          *param_4 = 5;
          goto locret_F0064E98;
        }
      }
      else if (param_2 == 3) {
        if (1 < *param_4) {
          iVar3 = _tick;
          .div(_tick,1000);
          *param_3 = iVar3;
          param_3[1] = iVar3;
          uVar1 = 2;
loc_F0064E88:
          *param_4 = uVar1;
          uVar4 = 0;
          goto locret_F0064E98;
        }
      }
      else {
        if (param_2 != 4) {
          uVar4 = 4;
          goto locret_F0064E98;
        }
        if (5 < *param_4) {
          _bcopy(_avenrun,param_3,0xc);
          _bcopy(_mach_factor,param_3 + 3,0xc);
          uVar1 = 6;
          goto loc_F0064E88;
        }
      }
      uVar4 = 5;
      goto locret_F0064E98;
    }
    if (*param_4 != 0) {
      *param_4 = 0;
      iVar3 = 0;
      piVar2 = &_machine_slot;
      do {
        if ((*piVar2 != 0) && (piVar2[3] != 0)) {
          *param_3 = iVar3;
          param_3 = param_3 + 1;
          *param_4 = *param_4 + 1;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 8;
      } while (iVar3 < 1);
      uVar4 = 0;
      goto locret_F0064E98;
    }
  }
  uVar4 = 4;
locret_F0064E98:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1298 start=0xf0064ea0 */

/* WARNING: Removing unreachable block (ram,0xf0064eb8) */

undefined8 _host_kernel_version(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _strncpy(param_2,_version,0x200);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1299 start=0xf0064ed4 */

/* WARNING: Removing unreachable block (ram,0xf0064efc) */
/* WARNING: Removing unreachable block (ram,0xf0064f04) */
/* WARNING: Removing unreachable block (ram,0xf0064ee4) */

undefined8 _host_processor_sets(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  uVar3 = 4;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)0x4;
    _kalloc();
    if (puVar1 == (undefined4 *)0x0) {
      uVar3 = 6;
    }
    else {
      puVar2 = _default_pset;
      _pset_reference(_default_pset);
      _convert_pset_name_to_port();
      *puVar1 = puVar2;
      *param_2 = (int)puVar1;
      *param_3 = 1;
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}

