
/* WARNING: Removing unreachable block (ram,0xf002629c) */

undefined8 _vno_ioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  *(int *)((int)register0x00000038 + 0x44) = param_1;
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x54) = uVar3;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  uVar3 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x54) + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
  switch(uVar3) {
  case :
    iVar1 = *(int *)((int)register0x00000038 + 0x48);
    if (iVar1 == -0x3ffb9996) {
      iVar2 = *(int *)((int)register0x00000038 + 0x44);
      *(uint *)((int)register0x00000038 + -0x50) = *(uint *)(iVar2 + 8) & 0x1000;
      iVar1 = **(int **)((int)register0x00000038 + 0x4c);
      if (iVar1 == 1) {
        *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0x1000;
loc_F00261E0:
        iVar2 = *(int *)((int)register0x00000038 + -0x50);
      }
      else {
        if (1 < iVar1) {
          if (iVar1 != 2) {
            uVar3 = 0x16;
            goto locret_F0026328;
          }
          *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xffffefff;
          goto loc_F00261E0;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x50);
        if (iVar1 != 0) {
          uVar3 = 0x16;
          goto locret_F0026328;
        }
      }
      if (iVar2 == 0) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      **(undefined4 **)((int)register0x00000038 + 0x4c) = uVar3;
      uVar3 = 0;
      goto locret_F0026328;
    }
    break;
  case :
  case :
    iVar1 = *(int *)((int)register0x00000038 + 0x48);
    break;
  :
    goto def_F0026130;
  case :
  case :
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
    iVar1 = dword_F0133DDC + 0x28;
    _setjmp();
    if (iVar1 != 0) {
      if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
        *(undefined *)(dword_F0133DDC + 0x39) = 2;
        goto loc_F0026324;
      }
      uVar3 = 4;
      goto loc_F0026320;
    }
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0x54);
    (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0x54) + 0x1c) + 0xc))
              (uVar3,*(undefined4 *)((int)register0x00000038 + 0x48),
               *(undefined4 *)((int)register0x00000038 + 0x4c),
               *(undefined4 *)(*(int *)((int)register0x00000038 + 0x44) + 8),
               *(undefined4 *)(*(int *)((int)register0x00000038 + 0x44) + 0x20));
    *(undefined4 *)((int)register0x00000038 + -0x4c) = uVar3;
    goto loc_F0026324;
  }
  if (iVar1 < -0x7ffb9983) {
def_F0026130:
    uVar3 = 0x19;
loc_F0026320:
    *(undefined4 *)((int)register0x00000038 + -0x4c) = uVar3;
  }
  else if (-0x7ffb9982 < iVar1) {
    uVar3 = 0x19;
    if (iVar1 != 0x4004667f) goto loc_F0026320;
    iVar1 = *(int *)((int)register0x00000038 + -0x54);
    (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0x54) + 0x1c) + 0x14))
              (iVar1,(undefined *)((int)register0x00000038 + -0x48),_active_u[7]);
    *(int *)((int)register0x00000038 + -0x4c) = iVar1;
    if (iVar1 == 0) {
      **(int **)((int)register0x00000038 + 0x4c) =
           *(int *)((int)register0x00000038 + -0x30) -
           *(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x1c);
    }
  }
loc_F0026324:
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
locret_F0026328:
  return CONCAT44(param_2,uVar3);
}
