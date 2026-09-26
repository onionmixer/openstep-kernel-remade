
/* WARNING: Removing unreachable block (ram,0xf003ced8) */
/* WARNING: Removing unreachable block (ram,0xf003ce0c) */
/* WARNING: Removing unreachable block (ram,0xf003cddc) */
/* WARNING: Removing unreachable block (ram,0xf003cd50) */
/* WARNING: Removing unreachable block (ram,0xf003cdb8) */
/* WARNING: Removing unreachable block (ram,0xf003cd9c) */
/* WARNING: Removing unreachable block (ram,0xf003cda8) */
/* WARNING: Removing unreachable block (ram,0xf003cd48) */
/* WARNING: Removing unreachable block (ram,0xf003cd58) */
/* WARNING: Removing unreachable block (ram,0xf003cde8) */
/* WARNING: Removing unreachable block (ram,0xf003ce88) */
/* WARNING: Removing unreachable block (ram,0xf003cee4) */
/* WARNING: Removing unreachable block (ram,0xf003cd00) */

undefined8 _makenfsnode(int *param_1,int *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined2 uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  bVar1 = false;
  piVar2 = param_1;
  sub_F003D2E0(param_1,param_3);
  piVar3 = _rpfreelist;
  if (piVar2 == (int *)0x0) {
    if ((_rpfreelist == (int *)0x0) || (_rnew < _nrnode)) {
      if (_rnode_zone == (int *)0x0) {
        piVar3 = (int *)0xc8;
        _zinit(200,2000000,0,0,aRnodeStructure);
        _rnode_zone = piVar3;
      }
      piVar3 = _rnode_zone;
      _zalloc();
      piVar3[3] = 0;
      _vm_info_init(piVar3 + 3);
      _rnew = _rnew + 1;
    }
    else {
      _rpfreelist = (int *)*_rpfreelist;
      sub_F003D214(piVar3);
      _rp_rmhash(piVar3);
      _rinactive(piVar3);
      _rreuse = _rreuse + 1;
    }
    iVar5 = piVar3[3];
    _bzero(piVar3,200);
    piVar3[3] = iVar5;
    _mfs_uncache(piVar3 + 3);
    *(undefined4 *)piVar3[3] = 0;
    *(int *)(piVar3[3] + 0x14) = piVar3[0x26];
    _bcopy(param_1,piVar3 + 0x10,0x20);
    *(undefined2 *)((int)piVar3 + 0x12) = 1;
    piVar3[10] = (int)_nfs_vnodeops;
    if (param_2 != (int *)0x0) {
      iVar5 = *param_2;
      if ((iVar5 == 4) && (param_2[7] == -1)) {
        iVar5 = 8;
      }
      piVar3[0xd] = iVar5;
      if (*param_2 == 4) {
        if (param_2[7] == -1) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined2 *)((int)param_2 + 0x1e);
        }
      }
      else {
        uVar4 = *(undefined2 *)((int)param_2 + 0x1e);
      }
      *(undefined2 *)(piVar3 + 0xe) = uVar4;
    }
    piVar3[0xf] = (int)piVar3;
    piVar3[0xc] = param_3;
    sub_F003CEF4(piVar3);
    bVar1 = true;
    *(int *)(*(int *)(param_3 + 0x128) + 0x18) = *(int *)(*(int *)(param_3 + 0x128) + 0x18) + 1;
    piVar2 = piVar3;
  }
  piVar2 = piVar2 + 3;
  if (param_2 != (int *)0x0) {
    if (!bVar1) {
      *(int *)((int)register0x00000038 + -0x10) = param_2[0xd];
      *(int *)((int)register0x00000038 + -0xc) = param_2[0xe];
      _nfs_cache_check(piVar2,(undefined *)((int)register0x00000038 + -0x10),param_2[5],0);
    }
    _nfs_attrcache(piVar2,param_2);
  }
  return CONCAT44(param_2,piVar2);
}
