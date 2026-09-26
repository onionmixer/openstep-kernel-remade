
/* WARNING: Removing unreachable block (ram,0xf003c2d0) */
/* WARNING: Removing unreachable block (ram,0xf003c298) */
/* WARNING: Removing unreachable block (ram,0xf003c2ec) */
/* WARNING: Removing unreachable block (ram,0xf003c308) */

undefined8 sub_F003C258(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar2 = *(int *)(param_1 + 0x5c);
  while ((1 < iVar2 || (iVar4 = _MAXCLIENTS, iVar2 < 0))) {
    _printf(aAuthgetUnknown);
    iVar2 = 0;
  }
  do {
    iVar2 = _nextunixvictim._0_4_ + 1;
    iVar3 = _nextunixvictim._0_4_ * 8;
    _nextunixvictim._0_4_ = iVar2;
    urem(iVar2,_MAXCLIENTS);
    _nextunixvictim._0_4_ = iVar2;
    if (*(sword *)(_unixauthtab + iVar3) == 0) break;
    iVar4 = iVar4 + -1;
  } while (0 < iVar4);
  if (*(sword *)(_unixauthtab + iVar3) == 0) {
    uVar1 = 1;
    if (*(int *)(_unixauthtab + iVar3 + 4) == 0) {
      _authkern_create();
      *(undefined4 *)(_unixauthtab + iVar3 + 4) = uVar1;
    }
    *(undefined2 *)(_unixauthtab + iVar3) = 1;
    iVar2 = *(int *)(_unixauthtab + iVar3 + 4);
  }
  else {
    _authkern_create();
  }
  return CONCAT44(param_2,iVar2);
}

