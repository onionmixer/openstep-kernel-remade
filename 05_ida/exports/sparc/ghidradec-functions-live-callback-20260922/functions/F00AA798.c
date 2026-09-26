
/* WARNING: Removing unreachable block (ram,0xf00aa8c0) */
/* WARNING: Removing unreachable block (ram,0xf00aa7e8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _sigreturn(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint *puVar4;
  int iVar5;
  undefined4 unaff_l3;
  uint *puVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
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
  iVar5 = *(int *)(_active_threads + 0x28);
  puVar4 = *(uint **)(iVar5 + 0x260);
  if ((((puVar4 < &dword_F0000000) && (((uint)puVar4 & 3) == 0)) && ((puVar4[3] & 3) == 0)) &&
     ((puVar4[4] & 3) == 0)) {
    _flush_user_windows();
    _active_u[0x52] = *puVar4 & 1;
    *(uint *)(*_active_u + 0x1c) = puVar4[1] & 0xfffefeff;
    *(uint *)(iVar5 + 0x278) = puVar4[2];
    *(uint *)(iVar5 + 0x238) = puVar4[3];
    *(uint *)(iVar5 + 0x23c) = puVar4[4];
    *(uint *)(iVar5 + 0x234) = *(uint *)(iVar5 + 0x234) & 0xff0fffff | puVar4[5] & 0xf00000;
    *(uint *)(iVar5 + 0x244) = puVar4[6];
    *(uint *)(iVar5 + 0x260) = puVar4[7];
    iVar3 = 0;
    if (puVar4[8] < __nwindows) {
      iVar8 = *(int *)(iVar5 + 0x230);
      if (0 < (int)puVar4[8]) {
        iVar7 = 0xa0;
        puVar6 = puVar4;
        do {
          iVar1 = (int)puVar4 + iVar7;
          iVar7 = iVar7 + 0x40;
          iVar2 = iVar8 + iVar3;
          iVar3 = iVar3 + 1;
          *(uint *)(iVar2 * 4 + iVar5 + 0x210) = puVar6[9];
          _copyin(iVar1,iVar5 + iVar2 * 0x40 + 0x10,0x40);
          puVar6 = puVar6 + 1;
        } while (iVar3 < (int)puVar4[8]);
      }
      *(uint *)(iVar5 + 0x230) = *(int *)(iVar5 + 0x230) + puVar4[8];
    }
    else {
      *(undefined4 *)(iVar5 + 0x230) = 0;
    }
    *(undefined *)(dword_F0133DDC + 0x39) = 1;
  }
  return CONCAT44(param_2,param_1);
}

