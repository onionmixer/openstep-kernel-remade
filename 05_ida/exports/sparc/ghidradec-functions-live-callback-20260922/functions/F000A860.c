
/* WARNING: Removing unreachable block (ram,0xf000a978) */
/* WARNING: Removing unreachable block (ram,0xf000a93c) */
/* WARNING: Removing unreachable block (ram,0xf000a960) */
/* WARNING: Removing unreachable block (ram,0xf000a9c8) */
/* WARNING: Removing unreachable block (ram,0xf000a8ec) */

undefined8 _dup2(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint *puVar2;
  undefined4 unaff_l1;
  int iVar3;
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
  puVar2 = *(uint **)(dword_F0133DDC + 0x24);
  if (((*puVar2 < *(uint *)(_active_u + 0x158)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x14c) + *puVar2 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (0xff < puVar2[1]) {
      *(undefined *)(dword_F0133DDC + 0x38) = 9;
      goto locret_F000A9D0;
    }
    *(uint *)(dword_F0133DDC + 0x30) = puVar2[1];
    if (*puVar2 == puVar2[1]) goto locret_F000A9D0;
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38));
    if ((iVar3 == *(int *)(*(int *)(_active_u + 0x14c) + *puVar2 * 4)) &&
       (iVar1 = *(int *)(*(int *)(_active_u + 0x14c) + puVar2[1] * 4), iVar1 != -0x10000)) {
      if (iVar1 != 0) {
        _vno_lockrelease();
        if ((*(byte *)(*(int *)(_active_u + 0x150) + puVar2[1]) & 2) != 0) {
          _munmapfd(puVar2[1]);
        }
        _closef(*(undefined4 *)(*(int *)(_active_u + 0x14c) + puVar2[1] * 4));
        *(undefined *)(dword_F0133DDC + 0x38) = 0;
      }
      if (iVar3 == *(int *)(*(int *)(_active_u + 0x14c) + *puVar2 * 4)) {
        _dupit(puVar2[1],iVar3,(int)*(char *)(*(int *)(_active_u + 0x150) + *puVar2));
        goto locret_F000A9D0;
      }
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 9;
locret_F000A9D0:
  return CONCAT44(param_2,param_1);
}

