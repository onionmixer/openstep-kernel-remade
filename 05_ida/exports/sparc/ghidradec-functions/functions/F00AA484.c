
/* WARNING: Removing unreachable block (ram,0xf00aa57c) */
/* WARNING: Removing unreachable block (ram,0xf00aa6e0) */
/* WARNING: Removing unreachable block (ram,0xf00aa538) */
/* WARNING: Removing unreachable block (ram,0xf00aa694) */
/* WARNING: Removing unreachable block (ram,0xf00aa560) */
/* WARNING: Removing unreachable block (ram,0xf00aa5d8) */
/* WARNING: Removing unreachable block (ram,0xf00aa4a0) */

undefined8 _sendsig(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar10;
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
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  uVar2 = *(undefined4 *)(_active_threads + 0x28);
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar2;
  _flush_user_windows_to_stack();
  iVar4 = _active_u[0x52];
  *(int *)((int)register0x00000038 + -0x14) = _active_u[0x52];
  *(int *)((int)register0x00000038 + -0x1c) = *(int *)(_active_threads + 0x28) + 0x234;
  if ((iVar4 == 0) &&
     ((_active_u[0x4e] >> ((char)*(undefined4 *)((int)register0x00000038 + 0x48) - 1U & 0x1f) & 1U)
      != 0)) {
    piVar1 = _active_u + 0x51;
    _active_u[0x52] = 1;
    *(int *)((int)register0x00000038 + -0x24) = *piVar1 + -0x8b0;
  }
  else {
    *(int *)((int)register0x00000038 + -0x24) =
         *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x44) + -0x8b0;
  }
  if (((*(uint *)((int)register0x00000038 + -0x24) & 7) == 0) &&
     (*(uint *)((int)register0x00000038 + -0x24) < 0xf0000000)) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    _setjmp();
    if (puVar3 == (undefined *)0x0) {
      uVar6 = *(undefined4 *)((int)register0x00000038 + -0x14);
      iVar4 = *(int *)((int)register0x00000038 + -0x24);
      puVar7 = *(undefined4 **)((int)register0x00000038 + -0x1c);
      *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x4c);
      *(undefined4 *)(iVar4 + 0x50) = uVar6;
      *(undefined4 *)(iVar4 + 0x54) = uVar2;
      *(undefined4 *)(iVar4 + 0x58) = puVar7[0x11];
      *(undefined4 *)(iVar4 + 0x5c) = puVar7[1];
      *(undefined4 *)(iVar4 + 0x60) = puVar7[2];
      *(undefined4 *)(iVar4 + 100) = *puVar7;
      *(undefined4 *)(iVar4 + 0x68) = puVar7[4];
      *(undefined4 *)(iVar4 + 0x6c) = puVar7[0xb];
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x70) =
           *(undefined4 *)(iVar4 + 0x230);
      iVar8 = 0;
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      if (0 < *(int *)(iVar4 + 0x230)) {
        iVar9 = 0xf0;
        param_2 = *(int *)((int)register0x00000038 + -0x2c);
        iVar10 = 0x10;
        param_1 = *(int *)((int)register0x00000038 + -0x24);
        iVar4 = *(int *)((int)register0x00000038 + -0x2c);
        do {
          iVar8 = iVar8 + 1;
          iVar4 = iVar4 + iVar10;
          iVar5 = *(int *)((int)register0x00000038 + -0x24) + iVar9;
          iVar9 = iVar9 + 0x40;
          iVar10 = iVar10 + 0x40;
          *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_2 + 0x210);
          _bcopy(iVar4,iVar5,0x40);
          iVar4 = *(int *)((int)register0x00000038 + -0x2c);
          param_2 = param_2 + 4;
          param_1 = param_1 + 4;
        } while (iVar8 < *(int *)(iVar4 + 0x230));
        uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x40) = uVar2;
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      if (*(int *)(iVar4 + 0x230) == 0) {
        _bcopy(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 0x44),
               *(undefined4 *)((int)register0x00000038 + -0x24),0x40);
        uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      switch(uVar2) {
      case :
      case :
      case :
      case :
      case :
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x44) =
             *(undefined4 *)(dword_F0133DDC + 0x44);
        *(undefined4 *)(dword_F0133DDC + 0x44) = 0;
        break;
      :
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x44) = 0;
      }
      iVar9 = *(int *)((int)register0x00000038 + -0x24);
      *(int *)(iVar9 + 0x48) = iVar9 + 0x50;
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(_active_threads + 0x74) = 0;
      *(undefined4 *)(iVar4 + 0x230) = 0;
      iVar8 = *(int *)((int)register0x00000038 + -0x1c);
      iVar4 = *(int *)((int)register0x00000038 + 0x44);
      *(int *)(iVar8 + 0x44) = iVar9;
      *(int *)(iVar8 + 4) = iVar4;
      *(int *)(iVar8 + 8) = iVar4 + 4;
      goto locret_F00AA790;
    }
  }
  _printf(aSendsigBadSign,(int)*(sword *)(*_active_u + 0x30),
          *(undefined4 *)((int)register0x00000038 + 0x48));
  _printf(aSigsp0xXAction,*(undefined4 *)((int)register0x00000038 + -0x24),
          *(undefined4 *)((int)register0x00000038 + 0x44),
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 4));
  _active_u[0x10] = 0;
  *(uint *)(*_active_u + 0x20) = *(uint *)(*_active_u + 0x20) & 0xfffffff7;
  *(uint *)(*_active_u + 0x24) = *(uint *)(*_active_u + 0x24) & 0xfffffff7;
  *(uint *)(*_active_u + 0x1c) = *(uint *)(*_active_u + 0x1c) & 0xfffffff7;
  *(undefined4 *)((int)register0x00000038 + 0x48) = 8;
  _psignal(*_active_u,4);
locret_F00AA790:
  return CONCAT44(param_2,param_1);
}
