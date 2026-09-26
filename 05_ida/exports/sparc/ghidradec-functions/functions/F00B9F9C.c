
/* WARNING: Removing unreachable block (ram,0xf00ba188) */
/* WARNING: Removing unreachable block (ram,0xf00ba2bc) */
/* WARNING: Removing unreachable block (ram,0xf00ba29c) */
/* WARNING: Removing unreachable block (ram,0xf00ba270) */
/* WARNING: Removing unreachable block (ram,0xf00ba228) */
/* WARNING: Removing unreachable block (ram,0xf00ba1fc) */
/* WARNING: Removing unreachable block (ram,0xf00ba1a8) */
/* WARNING: Removing unreachable block (ram,0xf00ba158) */
/* WARNING: Removing unreachable block (ram,0xf00ba168) */
/* WARNING: Removing unreachable block (ram,0xf00ba1e4) */
/* WARNING: Removing unreachable block (ram,0xf00ba210) */
/* WARNING: Removing unreachable block (ram,0xf00ba258) */
/* WARNING: Removing unreachable block (ram,0xf00ba288) */
/* WARNING: Removing unreachable block (ram,0xf00ba2b4) */
/* WARNING: Removing unreachable block (ram,0xf00ba2d0) */
/* WARNING: Removing unreachable block (ram,0xf00ba190) */
/* WARNING: Removing unreachable block (ram,0xf00ba150) */
/* WARNING: Removing unreachable block (ram,0xf00b9fe8) */

undefined8 _zsparam(int param_1,undefined4 param_2)

{
  undefined uVar1;
  word wVar2;
  byte bVar5;
  char cVar6;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  byte bVar9;
  undefined4 unaff_l3;
  byte bVar10;
  undefined4 unaff_l4;
  char cVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  char cVar12;
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
  iVar7 = *(int *)(param_1 + 0x34);
  if ((*(sword *)(param_1 + 0x38) == _rconsdev) && ((*(uint *)(param_1 + 0x3c) & 0xc0) != 0xc0)) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0xc0;
  }
  cVar12 = '\x13';
  if (*(char *)(param_1 + 0x49) == '\0') {
    _zsmctl(param_1,0,0);
    goto locret_F00BA2D8;
  }
  cVar11 = '\x01';
  bVar10 = 0x40;
  bVar5 = *(byte *)(iVar7 + 0x25) & 0x82;
  bVar9 = bVar5 | 8;
  if (*(char *)(param_1 + 0x49) == '\x04') {
    cVar12 = '\x17';
    cVar11 = -0x7f;
    bVar10 = 0x43;
    bVar9 = bVar5 | 0x48;
loc_F00BA0A8:
    cVar6 = *(char *)(param_1 + 0x49);
  }
  else {
    if ((*(uint *)(param_1 + 0x3c) & 0x200020) != 0) {
loc_F00BA080:
      cVar11 = -0x3f;
      bVar9 = bVar5 | 0x68;
      goto loc_F00BA0A8;
    }
    uVar3 = *(uint *)(param_1 + 0x3c) & 0xc0;
    if (uVar3 == 0x40) {
      cVar12 = '\x17';
      bVar10 = 0x41;
loc_F00BA0A4:
      cVar11 = 'A';
      bVar9 = bVar5 | 0x28;
      goto loc_F00BA0A8;
    }
    if (0x40 < uVar3) {
      if (uVar3 == 0x80) {
        cVar12 = '\x17';
      }
      else if (uVar3 != 0xc0) {
        cVar6 = *(char *)(param_1 + 0x49);
        goto loc_F00BA0AC;
      }
      bVar10 = 0x43;
      goto loc_F00BA0A4;
    }
    if (uVar3 == 0) goto loc_F00BA080;
    cVar6 = *(char *)(param_1 + 0x49);
  }
loc_F00BA0AC:
  if (cVar6 == '\x03') {
    bVar10 = bVar10 | 0xc;
  }
  else if (cVar6 == '\x04') {
    bVar10 = bVar10 | 8;
  }
  else {
    bVar10 = bVar10 | 4;
  }
  if ((((cVar12 != *(char *)(iVar7 + 0x21)) || (cVar11 != *(char *)(iVar7 + 0x23))) ||
      (bVar10 != *(byte *)(iVar7 + 0x24))) ||
     ((bVar9 != *(byte *)(iVar7 + 0x25) ||
      ((word)((word)*(byte *)(iVar7 + 0x2c) + (word)*(byte *)(iVar7 + 0x2d) * 0x100) !=
       *(sword *)(_zs_speeds + (*(byte *)(param_1 + 0x49) & 0xf) * 2))))) {
    iVar8 = 1000;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 8;
    iVar4 = param_1;
    _zsstop(param_1,0);
    while( true ) {
      _splzs();
      uVar3 = *(uint *)(iVar7 + 0x10);
      _zszread(uVar3,1);
      iVar8 = iVar8 + -1;
      if ((uVar3 & 1) != 0) break;
      if (iVar8 < 1) {
        *(undefined *)(iVar7 + 0x23) = 0;
        goto loc_F00BA1A0;
      }
      _splx(iVar4);
      iVar4 = 100;
      _us_spin();
    }
    *(undefined *)(iVar7 + 0x23) = 0;
loc_F00BA1A0:
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),3,0);
    **(undefined **)(iVar7 + 0x10) = 0x10;
    **(undefined **)(iVar7 + 0x10) = 0x30;
    uVar1 = *(undefined *)(*(int *)(iVar7 + 0x10) + 2);
    *(char *)(iVar7 + 0x21) = cVar12;
    _zszwrite(*(int *)(iVar7 + 0x10),1,cVar12,cVar12,uVar1);
    *(byte *)(iVar7 + 0x24) = bVar10;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),4,bVar10);
    *(char *)(iVar7 + 0x23) = cVar11;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),3);
    *(byte *)(iVar7 + 0x25) = bVar9;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),5,bVar9);
    wVar2 = *(word *)(_zs_speeds + (*(byte *)(param_1 + 0x49) & 0xf) * 2);
    *(undefined *)(iVar7 + 0x2b) = 0x50;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),0xb,0x50);
    *(undefined *)(iVar7 + 0x2e) = 2;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),0xe,2);
    *(char *)(iVar7 + 0x2c) = (char)wVar2;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),0xc,wVar2 & 0xff);
    *(char *)(iVar7 + 0x2d) = (char)(wVar2 >> 8);
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),0xd);
    *(undefined *)(iVar7 + 0x2e) = 3;
    _zszwrite(*(undefined4 *)(iVar7 + 0x10),0xe,3);
    _splx(iVar4);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffff7;
    _zsstart();
  }
locret_F00BA2D8:
  return CONCAT44(param_2,param_1);
}
