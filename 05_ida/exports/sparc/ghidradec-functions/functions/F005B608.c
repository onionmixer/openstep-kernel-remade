
/* WARNING: Removing unreachable block (ram,0xf005b63c) */
/* WARNING: Removing unreachable block (ram,0xf005b620) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005b620 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int _ipc_pset_alloc(undefined4 *param_1)

{
  undefined8 in_o0_1;
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
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
  _ipc_object_alloc(iVar1,(undefined4 *)in_o0_1,0x80000,0,
                    (undefined *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 == 0) {
    iVar1 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
    *(int *)(iVar1 + 0xc) = (int)*(undefined8 *)((int)register0x00000038 + -0x10);
    _ipc_mqueue_init(iVar1 + 0x10);
    *(undefined4 *)in_o0_1 = *(undefined4 *)((int)register0x00000038 + -0xc);
    iVar1 = 0;
    *param_1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  return iVar1;
}
