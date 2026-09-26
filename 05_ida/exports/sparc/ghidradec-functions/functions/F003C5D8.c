
/* WARNING: Removing unreachable block (ram,0xf003c698) */
/* WARNING: Removing unreachable block (ram,0xf003c658) */
/* WARNING: Removing unreachable block (ram,0xf003c6d0) */
/* WARNING: Removing unreachable block (ram,0xf003c610) */

undefined8 _nfs_netboot_prealloc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
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
  int aiStack_20 [8];
  
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
  uVar3 = 0;
  _MAXCLIENTS = _MAXCLIENTS + 3;
  if (_MAXCLIENTS != 0) {
    puVar4 = (undefined *)((int)register0x00000038 + -8);
    do {
      uVar3 = uVar3 + 1;
      uVar1 = param_1;
      sub_F003C3AC(param_1,*(undefined4 *)(_active_u + 0x1c));
      *(undefined4 *)(puVar4 + -0x18) = uVar1;
      puVar4 = puVar4 + 4;
    } while (uVar3 < _MAXCLIENTS);
  }
  uVar3 = 0;
  puVar4 = (undefined *)((int)register0x00000038 + -8);
  if (_MAXCLIENTS != 0) {
    do {
      if (*(int *)(puVar4 + -0x18) != 0) {
        sub_F003C6F0();
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 4;
    } while (uVar3 < _MAXCLIENTS);
  }
  puVar4 = DAT_f010cc00;
  uVar3 = 0;
  iVar2 = _MAXCLIENTS * 0x2260;
  _kalloc(iVar2);
  if (_MAXCLIENTS != 0) {
    puVar4 = _chtable;
    do {
      uVar3 = uVar3 + 1;
      _clntkudp_realloc(*(undefined4 *)(puVar4 + 8),iVar2);
      puVar4 = puVar4 + 0xc;
      iVar2 = iVar2 + 0x2260;
    } while (uVar3 < _MAXCLIENTS);
  }
  return CONCAT44(param_2,puVar4);
}
