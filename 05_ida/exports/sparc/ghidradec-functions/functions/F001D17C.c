
/* WARNING: Removing unreachable block (ram,0xf001d1a0) */

undefined8 _syioctl(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
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
  int iVar4;
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
  if (param_2 == (undefined *)0x20007471) {
    param_2 = DAT_f0133c00;
    iVar4 = *_active_u;
    iVar1 = (int)*(sword *)(iVar4 + 0x30);
    _get_posix_proc();
    iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
    if (*(int *)(iVar2 + 4) == iVar4) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar1 + 0x10) + 8) + 0xc) = 0;
      uVar3 = *(uint *)(iVar4 + 0x28);
    }
    else {
      uVar3 = *(uint *)(iVar4 + 0x28);
    }
    *(uint *)(iVar4 + 0x28) = uVar3 & 0xbfffffff;
    _active_u[0x59] = 0;
    iVar1 = 0;
    *(undefined2 *)(_active_u + 0x5a) = 0;
  }
  else {
    iVar1 = 6;
    if (_active_u[0x59] != 0) {
      iVar1 = (int)(sword)*(word *)(_active_u + 0x5a);
      (**(code **)(DAT_f011ca00 + (uint)(*(word *)(_active_u + 0x5a) >> 8) * 0x2c))
                (iVar1,param_2,param_3,param_4);
    }
  }
  return CONCAT44(param_2,iVar1);
}
