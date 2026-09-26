/* GHIDRADEC_FUNCTION index=2800 start=0xf00b9f9c */

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
/* GHIDRADEC_FUNCTION index=2801 start=0xf00ba2e0 */

/* WARNING: Removing unreachable block (ram,0xf00ba3dc) */
/* WARNING: Removing unreachable block (ram,0xf00ba3fc) */
/* WARNING: Removing unreachable block (ram,0xf00ba3f0) */
/* WARNING: Removing unreachable block (ram,0xf00ba338) */
/* WARNING: Removing unreachable block (ram,0xf00ba354) */
/* WARNING: Removing unreachable block (ram,0xf00ba3b0) */
/* WARNING: Removing unreachable block (ram,0xf00ba3c4) */
/* WARNING: Removing unreachable block (ram,0xf00ba458) */
/* WARNING: Removing unreachable block (ram,0xf00ba2e8) */

undefined8 _zsstart(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
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
  iVar8 = *(int *)(param_1 + 0x34);
  iVar7 = *(int *)(iVar8 + 0x18);
  iVar1 = param_1;
  _spltty();
  uVar4 = *(uint *)(param_1 + 0x40);
  if ((uVar4 & 0x129) != 0) goto loc_F00BA458;
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 <= *(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = uVar4 & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
    iVar2 = *(int *)(param_1 + 0x18);
  }
  if (iVar2 == 0) goto loc_F00BA458;
  if (*(sword *)(iVar7 + 0x118) < 1) {
    uVar4 = param_1 + 0x18;
    if ((*(uint *)(param_1 + 0x3c) & 0x200020) != 0) {
      _ndqb(uVar4,0);
loc_F00BA3FC:
      _splzs();
      *(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(param_1 + 0x1c);
      *(sword *)(iVar7 + 0x118) = (sword)uVar4;
      *(sword *)(iVar7 + 0x11a) = (sword)uVar4;
      pbVar5 = *(byte **)(iVar8 + 0x10);
      if ((*pbVar5 & 4) == 0) {
        uVar4 = *(uint *)(param_1 + 0x40);
      }
      else {
        pbVar3 = *(byte **)(iVar7 + 0x114);
        *(byte **)(iVar7 + 0x114) = pbVar3 + 1;
        pbVar5[2] = *pbVar3;
        *(sword *)(iVar7 + 0x118) = *(sword *)(iVar7 + 0x118) + -1;
        uVar4 = *(uint *)(param_1 + 0x40);
      }
      goto loc_F00BA450;
    }
    uVar6 = param_1 + 0x18;
    uVar4 = uVar6;
    _ndqb(uVar6,0x80);
    if (uVar4 != 0) goto loc_F00BA3FC;
    _getc(uVar6);
    _timeout(_ttrstrt,param_1,(uVar6 & 0x7f) + 6);
    uVar4 = *(uint *)(param_1 + 0x40) | 1;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x40);
loc_F00BA450:
    uVar4 = uVar4 | 0x20;
  }
  *(uint *)(param_1 + 0x40) = uVar4;
loc_F00BA458:
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2802 start=0xf00ba468 */

/* WARNING: Removing unreachable block (ram,0xf00ba4ac) */
/* WARNING: Removing unreachable block (ram,0xf00ba470) */

undefined8 _zsstop(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar1 = *(int *)(param_1 + 0x34);
  iVar2 = *(int *)(iVar1 + 0x18);
  _splzs();
  if ((*(uint *)(param_1 + 0x40) & 0x20) != 0) {
    if ((*(uint *)(param_1 + 0x40) & 0x100) == 0) {
      *(undefined2 *)(iVar2 + 0x11a) = 0;
    }
    else {
      *(sword *)(iVar2 + 0x11a) = *(sword *)(iVar2 + 0x11a) - *(sword *)(iVar2 + 0x118);
    }
    *(undefined2 *)(iVar2 + 0x118) = 0;
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2803 start=0xf00ba4bc */

/* WARNING: Removing unreachable block (ram,0xf00ba564) */
/* WARNING: Removing unreachable block (ram,0xf00ba4e4) */
/* WARNING: Removing unreachable block (ram,0xf00ba56c) */
/* WARNING: Removing unreachable block (ram,0xf00ba4c0) */

undefined8 _zsmctl(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  uint uVar5;
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
  iVar3 = *(int *)(param_1 + 0x34);
  _splzs();
  uVar4 = *(byte *)(iVar3 + 0x25) & 0x82;
  **(undefined **)(iVar3 + 0x10) = 0x10;
  _us_spin(2);
  uVar5 = uVar4 | **(byte **)(iVar3 + 0x10) & 0x28;
  if (param_3 == 1) {
    uVar1 = uVar5 | param_2;
loc_F00BA544:
    uVar4 = uVar1 & 0xffffff82;
    uVar5 = uVar1;
  }
  else if (param_3 < 2) {
    uVar1 = param_2;
    if (param_3 == 0) goto loc_F00BA544;
  }
  else {
    if (param_3 == 2) {
      uVar1 = uVar5 & ~param_2;
      goto loc_F00BA544;
    }
    if (param_3 == 3) goto loc_F00BA56C;
  }
  uVar1 = *(byte *)(iVar3 + 0x25) & 0x7d;
  bVar2 = (byte)uVar1;
  *(byte *)(iVar3 + 0x25) = bVar2;
  *(byte *)(iVar3 + 0x25) = bVar2 | (byte)uVar4;
  _zszwrite(*(undefined4 *)(iVar3 + 0x10),5,uVar1 | uVar4 & 0xff);
loc_F00BA56C:
  _splx(param_1);
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=2804 start=0xf00ba57c */

/* WARNING: Removing unreachable block (ram,0xf00ba5fc) */

undefined8 _zsa_txint(int param_1,undefined4 param_2)

{
  sword sVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 unaff_l0;
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
  iVar3 = *(int *)(param_1 + 0x18);
  pbVar4 = *(byte **)(param_1 + 0x10);
  if (*(sword *)(iVar3 + 0x118) < 1) {
    sVar1 = *(sword *)(iVar3 + 0xc);
  }
  else {
    if ((*pbVar4 & 4) != 0) {
      pbVar2 = *(byte **)(iVar3 + 0x114);
      *(byte **)(iVar3 + 0x114) = pbVar2 + 1;
      pbVar4[2] = *pbVar2;
      *(sword *)(iVar3 + 0x118) = *(sword *)(iVar3 + 0x118) + -1;
      goto locret_F00BA604;
    }
    sVar1 = *(sword *)(iVar3 + 0xc);
  }
  *(sword *)(iVar3 + 0xc) = sVar1 + 1;
  *pbVar4 = 0x28;
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
locret_F00BA604:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2805 start=0xf00ba60c */

/* WARNING: Removing unreachable block (ram,0xf00ba6b4) */
/* WARNING: Removing unreachable block (ram,0xf00ba674) */

undefined8 _zsa_xsint(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  sword sVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
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
  pbVar4 = *(byte **)(param_1 + 0x10);
  piVar6 = *(int **)(param_1 + 0x18);
  bVar1 = *pbVar4;
  bVar2 = *(byte *)((int)piVar6 + 0xe);
  iVar5 = *piVar6;
  *(byte *)((int)piVar6 + 0xe) = bVar1;
  *pbVar4 = 0x10;
  if (((bVar1 ^ bVar2) & 0x80) != 0) {
    if ((bVar1 & 0x80) != 0) {
      sVar3 = *(sword *)(piVar6 + 3);
      goto loc_F00BA680;
    }
    *(sword *)((int)piVar6 + 6) = *(sword *)((int)piVar6 + 6) + 1;
    *pbVar4 = 0x30;
    if ((*(word *)(iVar5 + 0x38) & 0x1f) != 2) {
      sVar3 = *(sword *)(piVar6 + 3);
      goto loc_F00BA680;
    }
    _prom_enter_mon();
  }
  sVar3 = *(sword *)(piVar6 + 3);
loc_F00BA680:
  *(sword *)(piVar6 + 3) = sVar3 + 1;
  *(sword *)((int)piVar6 + 10) = *(sword *)((int)piVar6 + 10) + 1;
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2806 start=0xf00ba6c4 */

/* WARNING: Removing unreachable block (ram,0xf00ba7b0) */

undefined8 _zsa_rxint(int param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
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
  piVar3 = *(int **)(param_1 + 0x18);
  bVar1 = *(byte *)(*(int *)(param_1 + 0x10) + 2);
  iVar4 = *piVar3;
  if ((bVar1 == 0) && ((*(byte *)((int)piVar3 + 0xe) & 0x80) != 0)) goto locret_F00BA7B8;
  sVar2 = *(sword *)(piVar3 + 0x44);
  *(sword *)(piVar3 + 0x44) = sVar2 + 1;
  *(byte *)((int)piVar3 + sVar2 + 0xf) = bVar1;
  if (0xff < *(sword *)(piVar3 + 0x44)) {
    *(undefined2 *)(piVar3 + 0x44) = 0;
  }
  if (*(sword *)(piVar3 + 0x44) == *(sword *)((int)piVar3 + 0x112)) {
    *(sword *)(piVar3 + 2) = *(sword *)(piVar3 + 2) + 1;
    sVar2 = *(sword *)(piVar3 + 3);
  }
  else {
    sVar2 = *(sword *)(piVar3 + 3);
  }
  *(sword *)(piVar3 + 3) = sVar2 + 1;
  if ((*(word *)(iVar4 + 0x38) & 0x1f) == 3) {
loc_F00BA78C:
    *(undefined2 *)(piVar3 + 1) = 0;
  }
  else {
    if ((bVar1 & 0x7f) != (int)*(char *)(iVar4 + 0x52)) {
      sVar2 = *(sword *)(piVar3 + 1);
      *(sword *)(piVar3 + 1) = sVar2 + 1;
      if ((sword)(sVar2 + 1) < 0x15) goto locret_F00BA7B8;
      goto loc_F00BA78C;
    }
    *(undefined2 *)(piVar3 + 1) = 0;
  }
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
locret_F00BA7B8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2807 start=0xf00ba7c0 */

/* WARNING: Removing unreachable block (ram,0xf00ba828) */
/* WARNING: Removing unreachable block (ram,0xf00ba7d0) */

undefined8 _zsa_srint(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  puVar2 = *(undefined **)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 0x18);
  puVar1 = puVar2;
  _zszread(puVar2,1);
  *puVar2 = 0x30;
  if (((uint)puVar1 & 0x20) != 0) {
    *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + 1;
    *(sword *)(iVar3 + 0xc) = *(sword *)(iVar3 + 0xc) + 1;
    *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
    if (_zssoftpend == 0) {
      _zssoftpend = 1;
      _setzssoft();
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2808 start=0xf00ba838 */

/* WARNING: Removing unreachable block (ram,0xf00ba850) */
/* WARNING: Removing unreachable block (ram,0xf00ba83c) */

sqword _zsa_softint(int param_1,uint param_2)

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
  iVar1 = *(int *)(param_1 + 0x18);
  _zsa_process();
  if (iVar1 != 0) {
    _zspoll(1);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2809 start=0xf00ba860 */

/* WARNING: Removing unreachable block (ram,0xf00ba8c8) */
/* WARNING: Removing unreachable block (ram,0xf00ba8a4) */
/* WARNING: Removing unreachable block (ram,0xf00ba908) */
/* WARNING: Removing unreachable block (ram,0xf00ba898) */

undefined8 _zspoll(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  sword *psVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
  undefined4 unaff_l3;
  sword sVar5;
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
  do {
    puVar4 = _zsaline;
    sVar5 = 0;
    psVar3 = (sword *)(_zsaline + 0xc);
    do {
      iVar1 = (int)*psVar3;
      if (iVar1 != 0) {
        *psVar3 = 0;
        _spl3();
        puVar2 = (undefined4 *)puVar4;
        _zsa_process();
        if (puVar2 != (undefined4 *)0x0) {
          sVar5 = sVar5 + 1;
          *psVar3 = *psVar3 + 1;
        }
        _splx(iVar1);
      }
      puVar4 = (undefined *)((int)puVar4 + 0x11c);
      psVar3 = psVar3 + 0x8e;
    } while (puVar4 < &_zssoftCAR);
  } while (sVar5 != 0);
  if (param_1 == 0) {
    _timeout(_zspoll,0,_zsticks);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2810 start=0xf00ba918 */

/* WARNING: Removing unreachable block (ram,0xf00babbc) */
/* WARNING: Removing unreachable block (ram,0xf00bab68) */
/* WARNING: Removing unreachable block (ram,0xf00baa84) */
/* WARNING: Removing unreachable block (ram,0xf00ba9e4) */
/* WARNING: Removing unreachable block (ram,0xf00ba9c8) */
/* WARNING: Removing unreachable block (ram,0xf00ba9d8) */
/* WARNING: Removing unreachable block (ram,0xf00ba98c) */
/* WARNING: Removing unreachable block (ram,0xf00baa64) */
/* WARNING: Removing unreachable block (ram,0xf00bab4c) */
/* WARNING: Removing unreachable block (ram,0xf00bac00) */
/* WARNING: Removing unreachable block (ram,0xf00ba9bc) */

undefined8 _zsa_process(int *param_1,undefined4 param_2)

{
  uint uVar1;
  word wVar3;
  sword sVar4;
  int iVar2;
  int iVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  byte *pbVar8;
  sword sVar9;
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
  iVar7 = *param_1;
  pbVar8 = *(byte **)(*(int *)(iVar7 + 0x34) + 0x10);
  if (*(sword *)((int)param_1 + 10) != 0) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    if ((*pbVar8 & 8) == 0) {
      if (*(char *)((int)&_zssoftCAR + (*(word *)(iVar7 + 0x38) & 0x1f)) != '\0') {
        uVar1 = *(uint *)(iVar7 + 0x40);
        goto loc_F00BA980;
      }
      if ((*(uint *)(iVar7 + 0x40) & 0x40000000) != 0) {
        uVar1 = *(uint *)(iVar7 + 0x40);
        goto loc_F00BA980;
      }
      if ((*(uint *)(iVar7 + 0x40) & 0x10) == 0) {
loc_F00BA9EC:
        uVar1 = *(uint *)(iVar7 + 0x40);
      }
      else {
        if ((*(uint *)(iVar7 + 0x3c) & 0x1000000) == 0) {
          _gsignal((int)*(sword *)(iVar7 + 0x44),1);
          _gsignal((int)*(sword *)(iVar7 + 0x44),0x13);
          _zsmctl(iVar7,0x80,2);
          _ttyflush(iVar7,3);
          goto loc_F00BA9EC;
        }
        uVar1 = *(uint *)(iVar7 + 0x40);
      }
      uVar1 = uVar1 & 0xffffffef;
    }
    else {
      uVar1 = *(uint *)(iVar7 + 0x40);
loc_F00BA980:
      if ((uVar1 & 0x10) != 0) {
        sVar4 = *(sword *)(param_1 + 2);
        goto loc_F00BA9FC;
      }
      _wakeup(iVar7 + 0x40);
      uVar1 = *(uint *)(iVar7 + 0x40) | 0x10;
    }
    *(uint *)(iVar7 + 0x40) = uVar1;
  }
  sVar4 = *(sword *)(param_1 + 2);
loc_F00BA9FC:
  if (sVar4 == 0) {
    sVar4 = *(sword *)((int)param_1 + 6);
  }
  else {
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0;
    *(undefined2 *)((int)param_1 + 0x112) = 0;
    sVar4 = *(sword *)((int)param_1 + 6);
  }
  if ((sVar4 != 0) && ((*pbVar8 & 0x80) == 0)) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    wVar3 = *(word *)(iVar7 + 0x38);
    if (wVar3 == _kbddev) {
      if (wVar3 == _rconsdev) {
        _kbdreset(iVar7);
      }
    }
    else if ((wVar3 & 0x1f) == 3) {
      _mstrynextbaudrate(iVar7);
    }
    else if ((*(uint *)(iVar7 + 0x40) & 4) != 0) {
      uVar6 = 0;
      if ((*(uint *)(iVar7 + 0x3c) & 0x20) == 0) {
        uVar6 = *(undefined *)(iVar7 + 0x4f);
      }
      (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30))(uVar6,iVar7);
    }
  }
  iVar2 = 0;
  sVar4 = *(sword *)((int)param_1 + 0x112);
  do {
    sVar9 = (sword)iVar2;
    iVar5 = (int)sVar4;
    if (iVar5 == *(sword *)(param_1 + 0x44)) {
loc_F00BAB98:
      sVar4 = *(sword *)(param_1 + 0x46);
    }
    else {
      *(sword *)((int)param_1 + 0x112) = (sword)(iVar5 + 1);
      uVar6 = *(undefined *)((int)param_1 + iVar5 + 0xf);
      if (0xff < (iVar5 + 1) * 0x10000 >> 0x10) {
        *(undefined2 *)((int)param_1 + 0x112) = 0;
      }
      if ((*(uint *)(iVar7 + 0x40) & 4) == 0) {
        sVar4 = *(sword *)(param_1 + 0x46);
      }
      else {
        wVar3 = *(word *)(iVar7 + 0x38) & 0x1f;
        if (wVar3 == 3) {
          _msinput(uVar6,iVar7);
          sVar4 = *(sword *)(param_1 + 0x46);
        }
        else {
          if (wVar3 != 2) {
            (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30))(uVar6,iVar7);
            goto loc_F00BAB98;
          }
          _kbdIntHandler(uVar6,iVar7);
          sVar4 = *(sword *)(param_1 + 0x46);
        }
      }
    }
    if (sVar4 < 1) {
      if ((*(uint *)(iVar7 + 0x40) & 0x20) == 0) {
        sVar4 = *(sword *)((int)param_1 + 0x112);
      }
      else {
        _ndflush(iVar7 + 0x18,(int)*(sword *)((int)param_1 + 0x11a));
        *(uint *)(iVar7 + 0x40) = *(uint *)(iVar7 + 0x40) & 0xffffffdf;
        if (*(char *)(iVar7 + 0x47) == 0) {
          _zsstart(iVar7);
          sVar4 = *(sword *)((int)param_1 + 0x112);
        }
        else {
          (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30 + 0xc))(iVar7);
          sVar4 = *(sword *)((int)param_1 + 0x112);
        }
      }
    }
    else {
      sVar4 = *(sword *)((int)param_1 + 0x112);
    }
    iVar2 = iVar2 + 1;
    if ((sVar4 == *(sword *)(param_1 + 0x44)) ||
       (sVar9 = (sword)iVar2, 0x13 < iVar2 * 0x10000 >> 0x10)) {
      return CONCAT44(param_2,(uint)(0x13 < sVar9));
    }
    sVar4 = *(sword *)((int)param_1 + 0x112);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2811 start=0xf00bac54 */

/* WARNING: Removing unreachable block (ram,0xf00bac60) */

undefined8 _zsidentify(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _strcmp(param_1,&unk_F011FB48);
  if (param_1 == 0) {
    _nzs = _nzs + 2;
  }
  return CONCAT44(param_2,(uint)(param_1 == 0));
}
/* GHIDRADEC_FUNCTION index=2812 start=0xf00bac90 */

/* WARNING: Removing unreachable block (ram,0xf00bafe0) */
/* WARNING: Removing unreachable block (ram,0xf00bafd4) */
/* WARNING: Removing unreachable block (ram,0xf00baf48) */
/* WARNING: Removing unreachable block (ram,0xf00baebc) */
/* WARNING: Removing unreachable block (ram,0xf00bae80) */
/* WARNING: Removing unreachable block (ram,0xf00bae4c) */
/* WARNING: Removing unreachable block (ram,0xf00bae08) */
/* WARNING: Removing unreachable block (ram,0xf00badd8) */
/* WARNING: Removing unreachable block (ram,0xf00bada8) */
/* WARNING: Removing unreachable block (ram,0xf00bad64) */
/* WARNING: Removing unreachable block (ram,0xf00bacfc) */
/* WARNING: Removing unreachable block (ram,0xf00bace4) */
/* WARNING: Removing unreachable block (ram,0xf00baccc) */
/* WARNING: Removing unreachable block (ram,0xf00bacd4) */
/* WARNING: Removing unreachable block (ram,0xf00bacec) */
/* WARNING: Removing unreachable block (ram,0xf00bad44) */
/* WARNING: Removing unreachable block (ram,0xf00bad8c) */
/* WARNING: Removing unreachable block (ram,0xf00badc0) */
/* WARNING: Removing unreachable block (ram,0xf00badf0) */
/* WARNING: Removing unreachable block (ram,0xf00bae1c) */
/* WARNING: Removing unreachable block (ram,0xf00bae60) */
/* WARNING: Removing unreachable block (ram,0xf00bae94) */
/* WARNING: Removing unreachable block (ram,0xf00baec4) */
/* WARNING: Removing unreachable block (ram,0xf00bafc0) */
/* WARNING: Removing unreachable block (ram,0xf00bacc0) */
/* WARNING: Removing unreachable block (ram,0xf00bb03c) */
/* WARNING: Removing unreachable block (ram,0xf00baff0) */
/* WARNING: Removing unreachable block (ram,0xf00bb024) */
/* WARNING: Removing unreachable block (ram,0xf00bb044) */
/* WARNING: Removing unreachable block (ram,0xf00bafe8) */

undefined8 _zsattach(int param_1,undefined *param_2)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 unaff_l0;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  sword *psVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined *puVar13;
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
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  sword asStack_10 [8];
  
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
  bVar14 = _zscom == 0;
  *(int *)(param_1 + 0x2c) = dword_F011FB10;
  if (bVar14) {
    iVar9 = _nzs << 7;
    _kalloc();
    _zscom = iVar9;
    _bzero();
    iVar9 = 4;
    _kalloc();
    _zssoftCAR = iVar9;
    _bzero();
    iVar9 = 0x10;
    _kalloc();
    _zsinfo = iVar9;
    _bzero();
    _zscurr = _zscom + 0x40;
    _zslast = _zscom;
    if (((_zscom == 0) || (_zssoftCAR == 0)) || (_zsinfo == 0)) {
      _printf(aZsNoSpaceForSt);
      uVar6 = 0xffffffff;
      goto locret_F00BB060;
    }
    iVar9 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar9 = *(int *)(param_1 + 0x2c);
  }
  iVar9 = _zscom + iVar9 * 0x80;
  _stop_mon_clock();
  if (*(int *)(param_1 + 0x10) - 1U < 2) {
    puVar8 = *(undefined4 **)(param_1 + 0x14);
    uVar3 = puVar8[1];
    iVar10 = 0;
    _map_regs(uVar3,puVar8[2],*puVar8);
    *(uint *)(iVar9 + 0x10) = uVar3;
    do {
      uVar4 = *(uint *)(iVar9 + 0x10) | 4;
      _zszread(uVar4,1);
      uVar6 = 1;
      if ((uVar4 & 1) != 0) {
        uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
        _zszread(uVar4,1);
        uVar6 = 0;
        if ((uVar4 & 1) != 0) {
          uVar4 = *(uint *)(iVar9 + 0x10) | 4;
          _zszread(uVar4,0);
          uVar6 = 0;
          if ((uVar4 & 4) != 0) {
            uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
            _zszread(uVar4,0);
            uVar6 = 0xc;
            if ((uVar4 & 4) != 0) break;
          }
        }
      }
      _us_spin(1000,uVar6);
      bVar14 = iVar10 < 0x1f5;
      iVar10 = iVar10 + 1;
    } while (bVar14);
    iVar10 = 0;
    param_2 = _zs_proto;
    psVar12 = (sword *)(iVar9 + 0x14);
    uVar4 = *(uint *)(iVar9 + 0x10) | 4;
    _zszread(uVar4,0xc);
    *(sword *)((int)register0x00000038 + -0x10) = (sword)uVar4;
    uVar4 = *(uint *)(iVar9 + 0x10) | 4;
    _zszread(uVar4,0xd);
    *(word *)((int)register0x00000038 + -0x10) =
         *(word *)((int)register0x00000038 + -0x10) | (word)(uVar4 << 8);
    uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
    _zszread(uVar4,0xc);
    *(sword *)((int)register0x00000038 + -0xe) = (sword)uVar4;
    uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
    _zszread(uVar4,0xd);
    *(word *)((int)register0x00000038 + -0xe) =
         *(word *)((int)register0x00000038 + -0xe) | (word)(uVar4 << 8);
    *(undefined *)(iVar9 + 0x29) = 0xc0;
    _zszwrite(*(undefined4 *)(iVar9 + 0x10),9,0xc0);
    _us_spin(10);
    *(undefined *)(iVar9 + 0x29) = 0;
    puVar13 = (undefined *)((int)register0x00000038 + -8);
    do {
      if (iVar10 == 0) {
        *(uint *)(psVar12 + -2) = uVar3 | 4;
      }
      else {
        iVar9 = iVar9 + 0x40;
        *(uint *)(psVar12 + 0x1e) = uVar3 & 0xfffffffb;
        psVar12 = psVar12 + 0x20;
        _zscurr = iVar9;
      }
      iVar2 = _zsinfo;
      iVar5 = *(int *)(param_1 + 0x2c) * 2 + iVar10;
      *psVar12 = (sword)iVar5;
      *(int *)(iVar2 + (iVar5 * 0x10000 >> 0xe)) = param_1;
      uVar6 = *(undefined4 *)(param_1 + 0x28);
      if (iVar10 == 0) {
        puVar7 = aPortAIgnoreCd;
      }
      else {
        puVar7 = aPortBIgnoreCd;
      }
      _getprop(uVar6,puVar7,0);
      *(char *)(_zssoftCAR + *psVar12) = (char)uVar6;
      if (_zs_proto._0_4_ != 0) {
        sVar1 = *(sword *)(puVar13 + -8);
        piVar11 = (int *)param_2;
        while( true ) {
          puVar8 = (undefined4 *)*piVar11;
          piVar11 = piVar11 + 1;
          (*(code *)*puVar8)(iVar9,(int)sVar1);
          if (*piVar11 == 0) break;
          sVar1 = *(sword *)(puVar13 + -8);
        }
      }
      iVar10 = iVar10 + 1;
      puVar13 = puVar13 + 2;
    } while (iVar10 < 2);
    *(undefined *)(iVar9 + 0x29) = 9;
    _zszwrite(*(undefined4 *)(iVar9 + 0x10),9,9);
    _us_spin(4000);
    _start_mon_clock();
    _zslast = iVar9;
    if (*(int *)(param_1 + 0x18) != 0) {
      _addintr(**(undefined4 **)(param_1 + 0x1c),_zsintr_hi,*(undefined4 *)(param_1 + 0xc),
               dword_F011FB10);
      _addintr(0x16,_zsintr,*(undefined4 *)(param_1 + 0xc),dword_F011FB10);
    }
    _report_dev(param_1);
    uVar6 = 0;
    dword_F011FB10 = dword_F011FB10 + 1;
  }
  else {
    _printf(aZsDWarningBadR,dword_F011FB10);
    uVar6 = 0xffffffff;
  }
locret_F00BB060:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=2813 start=0xf00bb068 */

/* WARNING: Removing unreachable block (ram,0xf00bb0e8) */
/* WARNING: Removing unreachable block (ram,0xf00bb090) */

undefined8 _zslevel6intr(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = 0;
  uVar1 = *(uint *)(_zscurr + 0x10);
  uVar4 = _zscurr;
  while ((uVar2 = uVar1 | 4, uVar1 == 0 || (_zszread(uVar2,3), uVar2 == 0))) {
    uVar4 = uVar4 + 0x80;
    if (_zslast < uVar4) {
      uVar4 = _zscom + 0x40;
    }
    iVar5 = iVar5 + 1;
    uVar1 = _zsNcurr._0_4_;
    if (1 < iVar5 * 0x10000 >> 0x10) goto locret_F00BB180;
    uVar1 = *(uint *)(uVar4 + 0x10);
  }
  uVar2 = *(uint *)(uVar4 + 0x10);
  _zscurr = uVar4;
  _zszread(uVar2,2);
  uVar1 = _zscurr;
  if ((uVar2 & 8) != 0) {
    uVar1 = _zscurr - 0x40;
  }
  uVar2 = uVar2 & 6;
  if (uVar2 == 2) {
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 8);
  }
  else if (uVar2 < 3) {
    if (uVar2 != 0) goto locret_F00BB180;
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 4);
  }
  else if (uVar2 == 4) {
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 0xc);
  }
  else {
    if (uVar2 != 6) goto locret_F00BB180;
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 0x10);
  }
  (*pcVar3)(uVar1);
locret_F00BB180:
  _zsNcurr._0_4_ = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2814 start=0xf00bb188 */

undefined8 _zsopinit(undefined4 *param_1,int param_2)

{
  undefined4 unaff_l0;
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
  *param_1 = *(undefined4 *)(param_2 + 4);
  param_1[1] = *(undefined4 *)(param_2 + 8);
  param_1[2] = *(undefined4 *)(param_2 + 0xc);
  param_1[3] = _zslevel6intr;
  param_1[7] = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2815 start=0xf00bb1bc */

/* WARNING: Removing unreachable block (ram,0xf00bb1c0) */

sqword _zsintr(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  iVar1 = param_1;
  _clrzssoft();
  if ((iVar1 != 0) && (_zssoftpend = 0, _zscom <= _zslast)) {
    piVar2 = (int *)(_zscom + 0x1c);
    uVar3 = _zscom;
    do {
      if ((*(byte *)(piVar2 + 5) & 1) != 0) {
        piVar2[6] = param_1;
        piVar2[7] = param_2;
        piVar2[8] = param_3;
        *(byte *)(piVar2 + 5) = *(byte *)(piVar2 + 5) & 0xfe;
        (**(code **)(*piVar2 + 0x14))(uVar3);
      }
      uVar3 = uVar3 + 0x40;
      piVar2 = piVar2 + 0x10;
    } while (uVar3 <= _zslast);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2816 start=0xf00bb24c */

/* WARNING: Removing unreachable block (ram,0xf00bb3d0) */
/* WARNING: Removing unreachable block (ram,0xf00bb37c) */
/* WARNING: Removing unreachable block (ram,0xf00bb34c) */
/* WARNING: Removing unreachable block (ram,0xf00bb31c) */
/* WARNING: Removing unreachable block (ram,0xf00bb2ec) */
/* WARNING: Removing unreachable block (ram,0xf00bb288) */
/* WARNING: Removing unreachable block (ram,0xf00bb2c4) */
/* WARNING: Removing unreachable block (ram,0xf00bb304) */
/* WARNING: Removing unreachable block (ram,0xf00bb334) */
/* WARNING: Removing unreachable block (ram,0xf00bb364) */
/* WARNING: Removing unreachable block (ram,0xf00bb3b8) */
/* WARNING: Removing unreachable block (ram,0xf00bb400) */
/* WARNING: Removing unreachable block (ram,0xf00bb258) */

undefined8 _zsnull_attach(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  sword sVar4;
  undefined4 uVar3;
  undefined4 uVar5;
  undefined4 unaff_l0;
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
  _zsopinit(param_1,_zsops_null);
  sVar4 = *(sword *)(param_1 + 0x14);
  bVar1 = false;
  if (sVar4 == 0) {
    iVar2 = *(int *)(*_zsinfo + 0x28);
    _getprop(iVar2,aPortARtsDtrOff,0);
    if (iVar2 == 0) {
      sVar4 = *(sword *)(param_1 + 0x14);
      goto loc_F00BB2A0;
    }
  }
  else {
loc_F00BB2A0:
    if (sVar4 != 1) goto loc_F00BB2E0;
    iVar2 = *(int *)(_zsinfo[1] + 0x28);
    _getprop(iVar2,aPortBRtsDtrOff,0);
    if (iVar2 == 0) goto loc_F00BB2E0;
  }
  bVar1 = true;
loc_F00BB2E0:
  *(undefined *)(param_1 + 0x24) = 0x46;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),4,0x46);
  *(undefined *)(param_1 + 0x23) = 0xc0;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),3,0xc0);
  *(undefined *)(param_1 + 0x2b) = 0x50;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xb,0x50);
  *(char *)(param_1 + 0x2c) = (char)param_2;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xc,param_2 & 0xff);
  *(char *)(param_1 + 0x2d) = (char)(param_2 >> 8);
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xd,param_2 >> 8 & 0xff);
  *(undefined *)(param_1 + 0x2e) = 2;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xe,2);
  *(undefined *)(param_1 + 0x23) = 0xc1;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),3,0xc1);
  if (bVar1) {
    *(undefined *)(param_1 + 0x25) = 0x68;
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar5 = 0x68;
  }
  else {
    *(undefined *)(param_1 + 0x25) = 0xea;
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar5 = 0xea;
  }
  _zszwrite(uVar3,5,uVar5);
  *(undefined *)(param_1 + 0x2e) = 3;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xe,3);
  if ((word)(*(sword *)(param_1 + 0x14) - 2U) < 2) {
    *(undefined *)(param_1 + 0x2f) = 0xe8;
    _zszwrite(*(undefined4 *)(param_1 + 0x10),0xf,0xe8);
  }
  **(undefined **)(param_1 + 0x10) = 0x40;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2817 start=0xf00bb41c */

/* WARNING: Removing unreachable block (ram,0xf00bb440) */
/* WARNING: Removing unreachable block (ram,0xf00bb44c) */
/* WARNING: Removing unreachable block (ram,0xf00bb430) */

undefined8 _zsnull_intr(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
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
  puVar1 = *(undefined **)(param_1 + 0x10);
  *puVar1 = 0x28;
  _us_spin(2);
  *puVar1 = 0x10;
  _us_spin(2);
  _us_spin(2);
  *puVar1 = 0x30;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2818 start=0xf00bb464 */

/* WARNING: Removing unreachable block (ram,0xf00bb470) */

undefined8 _zsnull_softint(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _printf(aZsDUnexpectedS,(int)*(sword *)(param_1 + 0x14));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2819 start=0xf00bb480 */

/* WARNING: Removing unreachable block (ram,0xf00bb4ac) */
/* WARNING: Removing unreachable block (ram,0xf00bb4b8) */
/* WARNING: Removing unreachable block (ram,0xf00bb49c) */

undefined8 _zsstealkey(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  puVar2 = *(undefined **)(_zscom + 0x90);
  *puVar2 = 0x28;
  _us_spin(2);
  *puVar2 = 0x10;
  _us_spin(2);
  bVar1 = puVar2[2];
  _us_spin(2);
  *puVar2 = 0x30;
  return CONCAT44(param_2,(uint)bVar1);
}
/* GHIDRADEC_FUNCTION index=2820 start=0xf00bb4d0 */

undefined8 _zsintr_hi(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  byte *pbVar2;
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
  
  _zsNcurr._0_4_ = _zscurr;
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
  pbVar2 = *(byte **)(_zscurr + 0x10);
  *pbVar2 = 2;
  bVar1 = *pbVar2;
  if ((bVar1 & 8) != 0) {
    _zsNcurr._0_4_ = _zsNcurr._0_4_ + -0x40;
  }
  (**(code **)(_zsNcurr._0_4_ + (bVar1 & 6) * 2))(_zsNcurr._0_4_);
  **(undefined **)(_zsNcurr._0_4_ + 0x10) = 0x38;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=2821 start=0xf00bb540 */

void _setzssoft(void)

{
  _set_intreg(0x400000,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2822 start=0xf00bb54c */

void _clrzssoft(void)

{
  _set_intreg(0x400000,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2823 start=0xf00bb558 */

undefined _zszread(undefined *param_1,undefined param_2)

{
  *param_1 = param_2;
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=2824 start=0xf00bb564 */

void _zszwrite(undefined *param_1,undefined param_2,undefined param_3)

{
  *param_1 = param_2;
  *param_1 = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=2825 start=0xf00bb570 */

qword _fbopen(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,-(uint)(param_3 <= (int)(param_1 & 0xff))) & 0xffffffff00000006;
}
/* GHIDRADEC_FUNCTION index=2826 start=0xf00bb598 */

/* WARNING: Removing unreachable block (ram,0xf00bb5a8) */

undefined8 _fbgetpage(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _pmap_getpte(_kernel_pmap,param_1,(undefined *)((int)register0x00000038 + -0xc));
  return CONCAT44(param_2,*(uint *)((int)register0x00000038 + -0xc) >> 8);
}
/* GHIDRADEC_FUNCTION index=2827 start=0xf00bb5c0 */

/* WARNING: Removing unreachable block (ram,0xf00bb5e8) */
/* WARNING: Removing unreachable block (ram,0xf00bb604) */
/* WARNING: Removing unreachable block (ram,0xf00bb5d4) */

undefined8 _cg14_identify(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  puVar1 = aCgfourteen_0;
  puVar2 = aSunwCgfourteen;
  _strcmp(aCgfourteen_0,param_1);
  if ((puVar1 == (undefined *)0x0) || (_strcmp(aSunwCgfourteen,param_1), puVar2 == (undefined *)0x0)
     ) {
    _printf(aSIdentified,param_1);
    iVar3 = _ncg14 + 1;
    _ncg14 = iVar3;
  }
  else {
    iVar3 = 0;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2828 start=0xf00bb624 */

sqword _cg14_attach(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  _cg14_devinfo = param_1;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2829 start=0xf00bb638 */

/* WARNING: Removing unreachable block (ram,0xf00bb65c) */
/* WARNING: Removing unreachable block (ram,0xf00bb644) */

undefined8 _sx_identify(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _strcmp(param_1,&aSunwSx);
  if (iVar1 != 0) {
    _strcmp(param_1,&aSx);
    uVar2 = 0;
    if (param_1 != 0) goto locret_F00BB674;
  }
  uVar2 = 1;
locret_F00BB674:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2830 start=0xf00bb67c */

sqword _sx_attach(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  _sx_dip = param_1;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2831 start=0xf00bb690 */

/* WARNING: Removing unreachable block (ram,0xf00bb6b4) */
/* WARNING: Removing unreachable block (ram,0xf00bb69c) */

undefined8 _s24_identify(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = param_1;
  _strcmp(param_1,aSunwTcx_0);
  if (iVar1 != 0) {
    _strcmp(param_1,&aTcx);
    iVar1 = 0;
    if (param_1 != 0) goto locret_F00BB6D8;
  }
  iVar1 = _ns24 + 1;
  _ns24 = iVar1;
locret_F00BB6D8:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2832 start=0xf00bb6e0 */

/* WARNING: Removing unreachable block (ram,0xf00bb6ec) */

sqword _s24_attach(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  _s24_devinfo_p = param_1;
  _report_dev();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2833 start=0xf00bb6fc */

/* WARNING: Removing unreachable block (ram,0xf00bb778) */
/* WARNING: Removing unreachable block (ram,0xf00bb80c) */
/* WARNING: Removing unreachable block (ram,0xf00bb71c) */

undefined8 _kmopen(uint param_1,undefined4 param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _cons_tp;
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
  uVar3 = _kmId;
  _objc_msgSend(_kmId,paKmopen,param_2);
  if (uVar3 == 0) {
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(code **)(iVar1 + 0x24) = sub_F00BBDB4;
    *(undefined *)(iVar1 + 0x47) = 2;
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      _ttychars(iVar1);
      *(undefined4 *)(iVar1 + 0x3c) = 0x140700d8;
      *(undefined *)(iVar1 + 0x4d) = 0x7f;
      *(undefined *)(iVar1 + 0x4a) = 0xd;
      *(undefined *)(iVar1 + 0x49) = 0xd;
      *(undefined4 *)(iVar1 + 0x40) = 0x10;
    }
    else if (((*(uint *)(iVar1 + 0x40) & 0x80) != 0) &&
            (uVar3 = 0x10, *(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) goto locret_F00BB8AC;
    uVar3 = (uint)(sword)param_1;
    (**(code **)(_linesw + *(char *)(iVar1 + 0x47) * 0x30))(uVar3,iVar1);
    if (uVar3 == 0) {
      if ((param_1 & 0xff) == 2) {
        uVar3 = (uint)_kbddev;
        _kbdopen(uVar3,_zs_tty + (uVar3 & 0xff) * 0x88);
      }
      if (uVar3 == 0) {
        *(undefined2 *)(iVar1 + 0x5c) = 0;
        *(undefined2 *)(iVar1 + 0x5e) = 0;
        *(undefined2 *)(iVar1 + 0x60) = 0;
        *(undefined2 *)(iVar1 + 0x62) = 0;
        if (cRamfeffe016 == '\x13') {
          sVar2 = (sword)(char)bRamfeffe050;
          if (bRamfeffe050 < 10) {
            sVar2 = 0x50;
          }
          else if (0x78 < bRamfeffe050) {
            sVar2 = 0x78;
          }
          *(sword *)(iVar1 + 0x5e) = sVar2;
          sVar2 = (sword)(char)bRamfeffe051;
          if (bRamfeffe051 < 10) {
            sVar2 = 0x22;
          }
          else if (0x30 < bRamfeffe051) {
            sVar2 = 0x30;
          }
          *(sword *)(iVar1 + 0x5c) = sVar2;
        }
      }
    }
  }
locret_F00BB8AC:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2834 start=0xf00bb8b4 */

/* WARNING: Removing unreachable block (ram,0xf00bb8e8) */

sqword _kmclose(undefined4 param_1,uint param_2)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _cons_tp;
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
  (**(code **)(DAT_f010b8d0 + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp);
  _ttyclose(iVar1);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2835 start=0xf00bb8f8 */

undefined8 _kmread(undefined4 param_1,undefined4 param_2)

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
  iVar1 = _cons_tp;
  (**(code **)(DAT_f010b8d4 + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2836 start=0xf00bb934 */

undefined8 _kmwrite(undefined4 param_1,undefined4 param_2)

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
  iVar1 = _cons_tp;
  (**(code **)(DAT_f010b8d8 + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2837 start=0xf00bb970 */

/* WARNING: Removing unreachable block (ram,0xf00bbb7c) */
/* WARNING: Removing unreachable block (ram,0xf00bbb0c) */
/* WARNING: Removing unreachable block (ram,0xf00bbac4) */
/* WARNING: Removing unreachable block (ram,0xf00bba90) */
/* WARNING: Removing unreachable block (ram,0xf00bbb44) */
/* WARNING: Removing unreachable block (ram,0xf00bbaa4) */
/* WARNING: Removing unreachable block (ram,0xf00bbafc) */
/* WARNING: Removing unreachable block (ram,0xf00bbad8) */
/* WARNING: Removing unreachable block (ram,0xf00bbc14) */
/* WARNING: Removing unreachable block (ram,0xf00bbb98) */

undefined8 _kmioctl(undefined4 param_1,uint param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined (*pauVar3) [12];
  undefined (*pauVar4) [14];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  
  iVar2 = _cons_tp;
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
  if (param_2 == 0x20006b02) {
    _basicConsoleMode = 1;
    (**(code **)(_basicConsole + 4))(_basicConsole,1,1,1,_mach_title);
    iVar5 = 0;
    goto locret_F00BBC2C;
  }
  iVar5 = _kmId;
  if ((int)param_2 < 0x20006b03) {
    if (param_2 == 0x80087467) {
      iVar5 = 0x16;
      goto locret_F00BBC2C;
    }
    if ((int)param_2 < -0x7ff78b98) {
      if (param_2 == 0x80046b09) {
        param_3 = (undefined4 *)*param_3;
        pauVar4 = paAnimationctl;
loc_F00BBB7C:
        _objc_msgSend(_kmId,pauVar4,param_3);
        goto locret_F00BBC2C;
      }
    }
    else {
      if (param_2 == 0x800c6b05) {
        uVar1 = (uint)(*(word *)(param_3 + 1) >> 2);
        .umul(uVar1,*(undefined2 *)((int)param_3 + 6));
        iVar5 = 0;
        if (-1 < (int)uVar1) {
          param_2 = uVar1;
          _kalloc();
          if (param_2 == 0) {
            iVar5 = -1;
          }
          else {
            iVar2 = param_3[2];
            _copyin(iVar2,param_2,uVar1);
            if (iVar2 == 0) {
              param_3[2] = param_2;
              iVar5 = _kmId;
              _objc_msgSend(_kmId,paDrawrect,param_3);
              _kfree(param_2,uVar1);
            }
            else {
              _kfree(param_2,uVar1);
              iVar5 = -1;
            }
          }
        }
        goto locret_F00BBC2C;
      }
      pauVar4 = (undefined (*) [14])paEraserect;
      if (param_2 == 0x800c6b06) goto loc_F00BBB7C;
    }
  }
  else {
    pauVar3 = paDisablecons;
    if (param_2 == 0x20006b08) {
loc_F00BBB44:
      _objc_msgSend(_kmId,pauVar3);
      goto locret_F00BBC2C;
    }
    if ((int)param_2 < 0x20006b09) {
      pauVar3 = (undefined (*) [12])paDumpmsgbuf;
      if (param_2 == 0x20006b03) goto loc_F00BBB44;
    }
    else {
      pauVar4 = (undefined (*) [14])paGetstatus;
      if (param_2 == 0x40046b0a) goto loc_F00BBB7C;
      if (param_2 == 0x40086b0b) {
        _objc_msgSend(_kmId,paGetscreensize,(undefined *)((int)register0x00000038 + -0x10));
        *(undefined2 *)param_3 = *(undefined2 *)((int)register0x00000038 + -0x10);
        *(undefined2 *)((int)param_3 + 2) = *(undefined2 *)((int)register0x00000038 + -0xe);
        *(undefined2 *)(param_3 + 1) = *(undefined2 *)((int)register0x00000038 + -0xc);
        iVar5 = 0;
        *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)register0x00000038 + -10);
        goto locret_F00BBC2C;
      }
    }
  }
  iVar5 = _cons_tp;
  (**(code **)(DAT_f010b8dc + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp,param_2,param_3,param_4);
  if ((iVar5 < 0) && (_ttioctl(iVar2,param_2,param_3,param_4), iVar5 = iVar2, iVar2 < 0)) {
    iVar5 = 0x19;
  }
locret_F00BBC2C:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=2838 start=0xf00bbc34 */

undefined8 _kmselect(undefined4 param_1,undefined4 param_2)

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
  iVar1 = _cons_tp;
  (**(code **)(DAT_f010b8f4 + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2839 start=0xf00bbc70 */

/* WARNING: Removing unreachable block (ram,0xf00bbca8) */
/* WARNING: Removing unreachable block (ram,0xf00bbc94) */

undefined8 _kmputc(undefined4 param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (_kmId == 0) {
    iVar1 = _kmAlertConsole;
    if (_kmAlertConsole == 0) {
      iVar1 = _basicConsole;
    }
    if (_basicConsoleMode != 2) {
      if (param_2 == 10) {
        (**(code **)(iVar1 + 0x14))(iVar1,0xd);
      }
      (**(code **)(iVar1 + 0x14))(iVar1,(int)(char)param_2);
      iVar1 = 0;
    }
  }
  else {
    if (param_2 == 10) {
      _objc_msgSend(_kmId,paKmputc,0xd);
    }
    iVar1 = _kmId;
    _objc_msgSend(_kmId,paKmputc,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2840 start=0xf00bbd1c */

/* WARNING: Removing unreachable block (ram,0xf00bbd34) */
/* WARNING: Removing unreachable block (ram,0xf00bbd60) */
/* WARNING: Removing unreachable block (ram,0xf00bbd48) */

undefined8 _kmgetc(undefined4 param_1,undefined4 param_2)

{
  undefined5 **ppuVar1;
  undefined4 unaff_l0;
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
  ppuVar1 = &paLock;
  if (_kmId == (undefined5 **)0x0) {
    _prom_getchar();
  }
  else {
    ppuVar1 = _kmId;
    _objc_msgSend(_kmId,paKmgetc);
  }
  if (ppuVar1 == (undefined5 **)0xd) {
    ppuVar1 = (undefined5 **)0xa;
  }
  _cnputc(ppuVar1);
  return CONCAT44(param_2,ppuVar1);
}
/* GHIDRADEC_FUNCTION index=2841 start=0xf00bbd70 */

/* WARNING: Removing unreachable block (ram,0xf00bbd94) */

undefined8 _kmgetc_silent(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (_kmId == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = _kmId;
    _objc_msgSend(_kmId,paKmgetc);
    if (iVar1 == 0xd) {
      iVar1 = 10;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2842 start=0xf00bc088 */

/* WARNING: Removing unreachable block (ram,0xf00bc0b0) */
/* WARNING: Removing unreachable block (ram,0xf00bc0a0) */

sqword _kmpopup(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  if (dword_F0132048 == 0) {
    _kminit();
  }
  _DoAlert(param_1,DAT_f011fd60);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2843 start=0xf00bc0c0 */

/* WARNING: Removing unreachable block (ram,0xf00bc0c4) */

sqword _kmrestore(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  _DoRestore();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2844 start=0xf00bc0d4 */

/* WARNING: Removing unreachable block (ram,0xf00bc11c) */
/* WARNING: Removing unreachable block (ram,0xf00bc110) */

sqword _alert(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
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
  _sprintf((undefined *)((int)register0x00000038 + -0xd0),param_4,param_5,param_6,
           *(undefined4 *)((int)register0x00000038 + 0x5c),
           *(undefined4 *)((int)register0x00000038 + 0x60),
           *(undefined4 *)((int)register0x00000038 + 100),
           *(undefined4 *)((int)register0x00000038 + 0x68),
           *(undefined4 *)((int)register0x00000038 + 0x6c),
           *(undefined4 *)((int)register0x00000038 + 0x70));
  _DoAlert(param_3,(undefined *)((int)register0x00000038 + -0xd0));
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2845 start=0xf00bc12c */

/* WARNING: Removing unreachable block (ram,0xf00bc130) */

sqword _alert_done(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  _DoRestore();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2846 start=0xf00bc140 */

/* WARNING: Removing unreachable block (ram,0xf00bc188) */
/* WARNING: Removing unreachable block (ram,0xf00bc178) */

undefined8
_aprint(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
       undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  undefined4 unaff_l0;
  char *pcVar2;
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
  char acStack_cf [207];
  
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
  pcVar2 = (char *)((int)register0x00000038 + -0xd0);
  _sprintf(pcVar2,param_1,param_2,param_3,param_4,param_5,param_6,
           *(undefined4 *)((int)register0x00000038 + 0x5c),
           *(undefined4 *)((int)register0x00000038 + 0x60),
           *(undefined4 *)((int)register0x00000038 + 100));
  cVar1 = *pcVar2;
  while( true ) {
    pcVar2 = pcVar2 + 1;
    _kmputc(0,(int)cVar1);
    if (pcVar2 == (char *)0x0) break;
    cVar1 = *pcVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2847 start=0xf00bc1a4 */

/* WARNING: Removing unreachable block (ram,0xf00bc1c0) */

undefined8 _kmdumplog(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (_kmId != 0) {
    _objc_msgSend(_kmId,paDumpmsgbuf);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2848 start=0xf00bc1d0 */

/* WARNING: Removing unreachable block (ram,0xf00bc1e4) */

undefined8 _kminit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
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
  bool bVar4;
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
  puVar1 = DAT_f0132000;
  dword_F0132048 = 1;
  _BasicAllocateConsole();
  bVar4 = DAT_f0121588._0_4_ == 0;
  if (bVar4) {
    _basicConsoleMode = 1;
    uVar2 = 1;
    pcVar3 = *(code **)(puVar1 + 4);
  }
  else {
    _basicConsoleMode = 2;
    uVar2 = 2;
    pcVar3 = *(code **)(puVar1 + 4);
  }
  _basicConsole = puVar1;
  (*pcVar3)(puVar1,uVar2,bVar4,bVar4,_mach_title);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2849 start=0xf00bc264 */

/* WARNING: Removing unreachable block (ram,0xf00bc280) */

undefined8 _kmDrawGraphicPanel(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (_kmId != 0) {
    _objc_msgSend(_kmId,paDrawgraphicpan,param_1);
  }
  return CONCAT44(param_2,param_1);
}

