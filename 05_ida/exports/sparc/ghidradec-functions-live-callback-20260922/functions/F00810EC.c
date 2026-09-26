
/* WARNING: Removing unreachable block (ram,0xf0081190) */
/* WARNING: Removing unreachable block (ram,0xf008116c) */
/* WARNING: Removing unreachable block (ram,0xf0081130) */
/* WARNING: Removing unreachable block (ram,0xf0081124) */
/* WARNING: Removing unreachable block (ram,0xf0081154) */
/* WARNING: Removing unreachable block (ram,0xf0081174) */
/* WARNING: Removing unreachable block (ram,0xf008119c) */
/* WARNING: Removing unreachable block (ram,0xf0081110) */

undefined8
_catch_exception_raise
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  uVar2 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  iVar1 = *(int *)(_active_threads + 0xc);
  _object_copyin(iVar1,param_2,6,0,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _convert_port_to_thread();
    _port_release(*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      sub_F00811AC(param_4,param_5,param_6,(undefined *)((int)register0x00000038 + -0x10),
                   *(int *)(iVar1 + 0x84) + 0x44);
      if (*(int *)((int)register0x00000038 + -0x10) != 0) {
        _thread_psignal(iVar1);
      }
      _thread_deallocate(iVar1);
      goto loc_F008118C;
    }
  }
  uVar2 = 4;
loc_F008118C:
  _port_deallocate_EXTERNAL(dword_F0130F60,param_3);
  _port_deallocate_EXTERNAL(dword_F0130F60,param_2);
  return CONCAT44(param_2,uVar2);
}

