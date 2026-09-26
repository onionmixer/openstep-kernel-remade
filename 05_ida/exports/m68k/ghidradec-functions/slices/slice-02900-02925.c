/* GHIDRADEC_FUNCTION index=2900 start=0x4036ada */

undefined4 sub_4036ADA(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2901 start=0x4036ae4 */

undefined4 sub_4036AE4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iStack_20;
  int iStack_1c;
  word wStack_18;
  word wStack_16;
  char cStack_14;
  char cStack_13;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x6e) != 0) {
    do {
      iVar1 = _rdwri(0,param_1,&iStack_1c,0xc,uVar2,1,&iStack_20);
      if ((((iVar1 != 0) || (iStack_20 != 0)) || (wStack_18 == 0)) ||
         ((iStack_1c != 0 &&
          (((2 < wStack_16 || (cStack_14 != '.')) ||
           ((wStack_16 != 1 && ((cStack_13 != '.' || (param_2 != iStack_1c)))))))))) {
        return 0;
      }
      uVar2 = wStack_18 + uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x6e));
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2902 start=0x4036b74 */

int sub_4036B74(int param_1,int param_2)

{
  int iVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iStack_8;
  
  iVar5 = 0;
  while ((byte_40AF2D6 & 1) != 0) {
    byte_40AF2D6 = byte_40AF2D6 | 2;
    _sleep(&byte_40AF2D6,10);
  }
  byte_40AF2D6 = 1;
  iVar4 = param_2;
  if (*(int *)(param_2 + 0x46) == *(int *)(param_1 + 0x46)) {
    iVar5 = 0x16;
  }
  else if (*(int *)(param_2 + 0x46) != 2) {
    do {
      iVar3 = 0;
      if ((((*(word *)(iVar4 + 0x62) & 0xf000) != 0x4000) || (*(sword *)(iVar4 + 100) == 0)) ||
         (*(uint *)(iVar4 + 0x6e) < 0x18)) {
        puVar6 = aBadSizeUnlinke;
loc_4036C34:
        sub_4036AAC(iVar4,puVar6,0);
        iVar5 = 0x14;
        goto loc_4036CC0;
      }
      iVar3 = _blkatoff(iVar4,0,&iStack_8);
      if (iVar3 == 0) break;
      if ((*(sword *)(iStack_8 + 0x12) != 2) || (*(sword *)(iStack_8 + 0x14) != 0x2e2e)) {
        puVar6 = aMangledEntry;
        goto loc_4036C34;
      }
      iVar1 = *(int *)(iStack_8 + 0xc);
      if (iVar1 == *(int *)(param_1 + 0x46)) {
        iVar5 = 0x16;
        goto loc_4036CC0;
      }
      if (iVar1 == 2) goto loc_4036CC0;
      _brelse(iVar3);
      iVar3 = 0;
      if (param_2 == iVar4) {
        wVar2 = *(word *)(param_2 + 0x42);
        *(word *)(param_2 + 0x42) = wVar2 & 0xfffe;
        if ((wVar2 & 0x10) != 0) {
          *(word *)(param_2 + 0x42) = wVar2 & 0xffee;
          _wakeup(param_2);
        }
      }
      else {
        _iput(iVar4);
      }
      iVar4 = _iget((int)*(sword *)(iVar4 + 0x44),*(undefined4 *)(iVar4 + 0x4e),iVar1);
    } while (iVar4 != 0);
    iVar5 = (int)*(char *)(dword_40B57D4 + 100);
loc_4036CC0:
    if (iVar3 != 0) {
      _brelse(iVar3);
    }
  }
  if ((byte_40AF2D6 & 2) != 0) {
    _wakeup(&byte_40AF2D6);
  }
  byte_40AF2D6 = 0;
  if ((iVar4 != 0) && (param_2 != iVar4)) {
    _iput(iVar4);
    while ((*(word *)(param_2 + 0x42) & 1) != 0) {
      *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x10;
      _sleep(param_2,10);
    }
    *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 1;
    if ((iVar5 == 0) && (*(sword *)(param_2 + 100) == 0)) {
      iVar5 = 2;
    }
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=2903 start=0x4036d3e */

void sub_4036D3E(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (dword_40C10A0 == 0) {
    if (-1 < *(char *)(param_1 + 0xc)) {
      return;
    }
    iVar1 = (*dword_40C1090)(param_1);
    if (iVar1 != 0) {
      return;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0x7f;
    pcVar2 = dword_40C109C;
  }
  else {
    if ((char)*(byte *)(param_1 + 0xc) < '\0') {
      return;
    }
    if ((int *)(param_1 + 0xe) != *(int **)(param_1 + 0xe)) {
      return;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x80;
    pcVar2 = dword_40C1098;
  }
  (*pcVar2)(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2904 start=0x4036d9e */

int sub_4036D9E(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 0x38);
  if (iVar2 < param_2) {
    iVar1 = *(int *)(iVar3 + 0xc);
    iVar2 = iVar3;
    while (iVar1 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar3 + 0x38) < *(int *)(iVar2 + 0x38)) {
        return iVar2;
      }
      if (param_2 < *(int *)(iVar3 + 0x38)) {
        return iVar2;
      }
      iVar2 = iVar3;
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
  else {
    if (iVar2 < param_1[2]) {
      if (param_2 < iVar2) {
        return 0;
      }
    }
    else {
      if (*(int *)(iVar3 + 0xc) == 0) {
        return iVar3;
      }
      do {
        iVar2 = *(int *)(iVar3 + 0xc);
        if (*(int *)(iVar2 + 0x38) < *(int *)(iVar3 + 0x38)) break;
        iVar3 = iVar2;
      } while (*(int *)(iVar2 + 0xc) != 0);
    }
    do {
      iVar2 = iVar3;
      if (*(int *)(iVar2 + 0xc) == 0) {
        return iVar2;
      }
      iVar3 = *(int *)(iVar2 + 0xc);
    } while (*(int *)(*(int *)(iVar2 + 0xc) + 0x38) <= param_2);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2905 start=0x4036e20 */

void sub_4036E20(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_2[2] < *(int *)(param_3 + 0x38)) {
    iVar1 = *(int *)(*param_2 + 0x38);
    if ((*(int *)(param_3 + 0x38) < iVar1) || (iVar1 < param_2[2])) {
      *(int *)(param_3 + 0xc) = *param_2;
      *param_2 = param_3;
      return;
    }
  }
  iVar1 = sub_4036D9E(param_2,*(undefined4 *)(param_3 + 0x38));
  if (iVar1 == 0) {
    *(int *)(param_3 + 0xc) = *param_2;
    *param_2 = param_3;
  }
  else {
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = param_3;
    if (iVar1 == param_2[1]) {
      param_2[1] = param_3;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2906 start=0x4036e8c */

int * sub_4036E8C(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x16) == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + -1;
    piVar3 = (int *)_kalloc(0x18);
    piVar3[3] = 0;
    piVar3[1] = 0;
    *piVar3 = 0;
    piVar3[2] = 0;
  }
  piVar3[1] = param_3;
  *piVar3 = param_3;
  *(undefined4 *)(param_3 + 0xc) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xe);
  if (param_2 == puVar2) {
    puVar2 = (undefined4 *)*param_2;
    if (puVar2 == param_2) {
      *(int **)(param_1 + 0x12) = piVar3;
    }
    else {
      puVar2[5] = piVar3;
    }
    piVar3[4] = (int)puVar2;
    piVar3[5] = param_1 + 0xe;
    *(int **)(param_1 + 0xe) = piVar3;
  }
  else if (puVar2 == (undefined4 *)param_2[4]) {
    puVar1 = *(undefined4 **)(param_1 + 0x12);
    if (puVar1 == puVar2) {
      *puVar1 = piVar3;
    }
    else {
      puVar1[4] = piVar3;
    }
    piVar3[5] = (int)puVar1;
    piVar3[4] = param_1 + 0xe;
    *(int **)(param_1 + 0x12) = piVar3;
  }
  else {
    piVar3[5] = (int)param_2;
    piVar3[4] = param_2[4];
    param_2[4] = piVar3;
    *(int **)(piVar3[4] + 0x14) = piVar3;
  }
  return piVar3;
}
/* GHIDRADEC_FUNCTION index=2907 start=0x4036f4a */

void sub_4036F4A(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = sub_4036D9E(param_1,param_2 + -1);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    *(undefined4 *)(param_1[1] + 0xc) = *param_1;
    param_1[1] = iVar1;
    *param_1 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  param_1[2] = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2908 start=0x4036f96 */

byte sub_4036F96(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  char cVar8;
  char cVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  puVar2 = (uint *)(param_1 + 0xe);
  puVar7 = (uint *)*puVar2;
  cVar12 = puVar7 < puVar2;
  if (puVar7 == puVar2) {
    iVar6 = sub_4036E8C(param_1,puVar2,param_2);
    *(int *)(iVar6 + 0xc) = iVar1;
    iVar1 = *(int *)(param_1 + 0x1a);
    *(int *)(iVar6 + 8) = iVar1;
    return cVar12 << 4 | (iVar1 < 0) << 3 | (iVar1 == 0) << 2;
  }
  if (((((*(byte *)(param_1 + 0xc) & 0x10) != 0) &&
       (puVar7[2] = *(undefined4 *)(*puVar7 + 0x38), (*(byte *)(param_1 + 0xc) & 0x10) != 0)) &&
      ((int)puVar7[3] < iVar1)) && (0 < *(int *)(param_1 + 0x16))) {
    iVar6 = *puVar7;
    if (iVar6 == puVar7[1]) {
      puVar7[3] = iVar1;
    }
    else {
      *puVar7 = *(undefined4 *)(iVar6 + 0xc);
      puVar7 = (uint *)sub_4036E8C(param_1,puVar2,iVar6);
      *(int *)((int)puVar7 + 0xc) = iVar1;
      *(undefined4 *)((int)puVar7 + 8) = *(undefined4 *)(iVar6 + 0x38);
    }
  }
  for (; ((uint *)(param_1 + 0xeU) != puVar7 && (iVar1 < *(int *)((int)puVar7 + 0xc)));
      puVar7 = *(uint **)((int)puVar7 + 0x10)) {
  }
  cVar12 = puVar7 < param_1 + 0xeU;
  if (puVar7 == (uint *)(param_1 + 0xeU)) {
    if (*(int *)(param_1 + 0x16) == 0) {
      cVar8 = param_1 < 0;
      cVar9 = param_1 == 0;
      cVar11 = '\0';
      bVar13 = 0;
      sub_4036E20(param_1,*(undefined4 *)(param_1 + 0x12),param_2,
                  (*(uint *)(param_1 + 0xc) & 0x1fffffff) >> 0x1c);
      return cVar12 << 4 | cVar8 << 3 | cVar9 << 2 | cVar11 << 1 | bVar13;
    }
loc_403707E:
    if (puVar7 == (uint *)(param_1 + 0xeU)) {
      puVar7 = *(uint **)(param_1 + 0x12);
    }
    if (*(int *)((int)puVar7 + 0xc) < iVar1) {
      puVar7 = (uint *)sub_4036E8C(param_1,*(undefined4 *)((int)puVar7 + 0x14),param_2);
      *(int *)((int)puVar7 + 0xc) = iVar1;
      if (*(uint *)((int)puVar7 + 0x14) == param_1 + 0xeU) {
        *(undefined4 *)((int)puVar7 + 8) = *(undefined4 *)(param_1 + 0x1a);
      }
      else {
        *(undefined4 *)((int)puVar7 + 8) =
             *(undefined4 *)(*(int *)(*(uint *)((int)puVar7 + 0x14) + 4) + 0x38);
      }
      goto loc_4037106;
    }
    if (iVar1 != *(int *)((int)puVar7 + 0xc)) {
      iVar6 = sub_4036E8C(param_1,puVar7,param_2);
      *(int *)(iVar6 + 0xc) = iVar1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)((int)puVar7 + 4) + 0x38);
      goto loc_4037106;
    }
  }
  else if (*(int *)(param_1 + 0x16) != 0) goto loc_403707E;
  sub_4036E20(param_1,puVar7,param_2,(*(uint *)(param_1 + 0xc) & 0x1fffffff) >> 0x1c);
loc_4037106:
  uVar3 = param_1 + 0xe;
  iVar1 = (int)puVar7 - uVar3;
  bVar10 = puVar7 == (uint *)uVar3;
  if (!bVar10) {
    iVar1 = *(uint *)((int)puVar7 + 0x10) - uVar3;
    uVar5 = *(uint *)((int)puVar7 + 0x10);
    uVar4 = (uint)puVar7;
    while (puVar7 = (uint *)uVar5, bVar10 = puVar7 == (uint *)uVar3, !bVar10) {
      sub_4036F4A(puVar7,*(undefined4 *)(*(int *)(uVar4 + 4) + 0x38));
      iVar1 = *(uint *)((int)puVar7 + 0x10) - uVar3;
      uVar5 = *(uint *)((int)puVar7 + 0x10);
      uVar4 = (uint)puVar7;
    }
  }
  return (puVar7 < uVar3) << 4 | (iVar1 < 0) << 3 | bVar10 << 2 | SBORROW4((int)puVar7,uVar3) << 1 |
         puVar7 < uVar3;
}
/* GHIDRADEC_FUNCTION index=2909 start=0x40386c0 */

uint sub_40386C0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar1 = (uint *)(_lf_svnode_hash + (param_1 & 0x3f) * 4);
  uVar2 = *puVar1;
  puVar3 = puVar1;
  do {
    if (uVar2 == 0) {
      puVar4 = (uint *)_kalloc(0x10);
      *puVar4 = param_1;
      puVar4[1] = 0;
      puVar4[2] = 0;
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
loc_4038714:
      puVar4[3] = *puVar1;
      *puVar1 = (uint)puVar4;
loc_403871A:
      return *puVar1;
    }
    puVar4 = (uint *)*puVar3;
    if (param_1 == *puVar4) {
      if (puVar1 == puVar3) goto loc_403871A;
      *puVar3 = puVar4[3];
      goto loc_4038714;
    }
    puVar3 = puVar4 + 3;
    uVar2 = *puVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2910 start=0x4038728 */

void sub_4038728(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  if ((int)param_1[2] < 1) {
    puVar1 = (uint *)(_lf_svnode_hash + (*param_1 & 0x3f) * 4);
    uVar2 = *puVar1;
    while( true ) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aLfFreeSvnodeCa);
      }
      puVar3 = (uint *)*puVar1;
      if (param_1 == puVar3) break;
      puVar1 = puVar3 + 3;
      uVar2 = *puVar1;
    }
    _vn_rele(*puVar3);
    *puVar1 = puVar3[3];
    _kfree(puVar3,0x10);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2911 start=0x403878c */

undefined4 sub_403878C(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iStack_c;
  int *piStack_8;
  
  uVar6 = 0x23;
  if (*(sword *)(param_1 + 2) == 2) {
    uVar6 = 0x28;
  }
  while (iVar3 = sub_4038B8C(param_1), iVar3 != 0) {
    if ((*(byte *)(param_1 + 1) & 1) != 0) {
      sub_4038E3A(param_1);
      return 0xb;
    }
    iVar4 = *(int *)(iVar3 + 0xc);
    iVar5 = 0;
    while ((*(int *)(iVar4 + 0x12) != 0 && (iVar5 < 0x32))) {
      iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x12) + 0x14) + 0xc);
      iVar5 = iVar5 + 1;
      if (iVar4 == *(int *)(param_1 + 0xc)) {
        sub_4038E3A(param_1);
        return 0x4e;
      }
    }
    *(int *)(param_1 + 0x14) = iVar3;
    sub_4038D12(iVar3,param_1);
    *(int *)(*(int *)(param_1 + 0xc) + 0x12) = param_1;
    iVar4 = _sleep(param_1,uVar6 | 0x100);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x12) = 0;
    if (iVar4 != 0) {
      sub_4038D40(iVar3,param_1);
      sub_4038E3A(param_1);
      return 4;
    }
  }
  piStack_8 = (int *)(*(int *)(param_1 + 0x10) + 4);
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  bVar2 = true;
loc_4038866:
  iVar3 = sub_4038BEC(uVar7,param_1,1,&piStack_8,&iStack_c);
  if (iVar3 != 0) {
    uVar7 = *(undefined4 *)(iStack_c + 0x14);
  }
  switch(iVar3) {
  case :
    if (!bVar2) {
      return 0;
    }
    *piStack_8 = param_1;
    *(int *)(param_1 + 0x14) = iStack_c;
    return 0;
  case :
    if ((*(sword *)(param_1 + 2) == 1) && (*(sword *)(iStack_c + 2) == 2)) {
      sub_4038E00(iStack_c);
    }
    *(undefined2 *)(iStack_c + 2) = *(undefined2 *)(param_1 + 2);
    break;
  case :
    if (*(sword *)(param_1 + 2) != *(sword *)(iStack_c + 2)) {
      if (*(int *)(iStack_c + 4) == *(int *)(param_1 + 4)) {
        *piStack_8 = param_1;
        *(int *)(param_1 + 0x14) = iStack_c;
        *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
      }
      else {
        sub_4038D6C(iStack_c,param_1);
      }
      goto loc_4038A12;
    }
    break;
  case :
    if ((*(sword *)(param_1 + 2) == 1) && (*(sword *)(iStack_c + 2) == 2)) {
      sub_4038E00(iStack_c);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iStack_c + 0x18);
      sub_4038D12(param_1,uVar1);
    }
    if (bVar2) {
      *piStack_8 = param_1;
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iStack_c + 0x14);
      piStack_8 = (int *)(param_1 + 0x14);
      bVar2 = false;
    }
    else {
      *piStack_8 = *(int *)(iStack_c + 0x14);
    }
    sub_4038E3A(iStack_c);
    goto loc_4038866;
  case :
    goto loc_40389c2;
  case :
    if (bVar2) {
      *piStack_8 = param_1;
      *(int *)(param_1 + 0x14) = iStack_c;
    }
    *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
loc_4038A12:
    sub_4038E00(iStack_c);
    return 0;
  :
    return 0;
  }
  sub_4038E3A(param_1);
  return 0;
loc_40389c2:
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iStack_c + 0x14);
  *(int *)(iStack_c + 0x14) = param_1;
  *(int *)(iStack_c + 8) = *(int *)(param_1 + 4) + -1;
  piStack_8 = (int *)(param_1 + 0x14);
  sub_4038E00(iStack_c);
  bVar2 = false;
  goto loc_4038866;
}
/* GHIDRADEC_FUNCTION index=2912 start=0x4038a24 */

undefined4 sub_4038A24(int param_1)

{
  int iVar1;
  int iStack_c;
  int *piStack_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  piStack_8 = (int *)(*(int *)(param_1 + 0x10) + 4);
loc_4038A42:
  iVar1 = sub_4038BEC(iVar1,param_1,1,&piStack_8,&iStack_c);
  if (iVar1 == 0) {
    return 0;
  }
  sub_4038E00(iStack_c);
  switch(iVar1) {
  case :
    *piStack_8 = *(int *)(iStack_c + 0x14);
    sub_4038E3A(iStack_c);
    return 0;
  case :
    if (*(int *)(iStack_c + 4) != *(int *)(param_1 + 4)) {
      sub_4038D6C(iStack_c,param_1);
      *(undefined4 *)(iStack_c + 0x14) = *(undefined4 *)(param_1 + 0x14);
      return 0;
    }
    break;
  case :
    *piStack_8 = *(int *)(iStack_c + 0x14);
    iVar1 = *(int *)(iStack_c + 0x14);
    sub_4038E3A(iStack_c);
    goto loc_4038A42;
  case :
    goto loc_4038af8;
  case :
    break;
  :
    return 0;
  }
  *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
  return 0;
loc_4038af8:
  *(int *)(iStack_c + 8) = *(int *)(param_1 + 4) + -1;
  piStack_8 = (int *)(iStack_c + 0x14);
  iVar1 = *piStack_8;
  goto loc_4038A42;
}
/* GHIDRADEC_FUNCTION index=2913 start=0x4038b30 */

undefined4 sub_4038B30(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = sub_4038B8C(param_1);
  if (iVar1 == 0) {
    *param_2 = 3;
  }
  else {
    *param_2 = *(undefined2 *)(iVar1 + 2);
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(iVar1 + 4);
    if (*(int *)(iVar1 + 8) == -1) {
      *(undefined4 *)(param_2 + 4) = 0;
    }
    else {
      *(int *)(param_2 + 4) = (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4)) + 1;
    }
    *(undefined4 *)(param_2 + 6) = **(undefined4 **)(iVar1 + 0xc);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2914 start=0x4038b8c */

int sub_4038B8C(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_c;
  int iStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  iStack_8 = *(int *)(param_1 + 0x10) + 4;
  while( true ) {
    iVar2 = sub_4038BEC(uVar1,param_1,2,&iStack_8,&iStack_c);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(sword *)(param_1 + 2) == 2) break;
    if (*(sword *)(iStack_c + 2) == 2) {
      return iStack_c;
    }
    uVar1 = *(undefined4 *)(iStack_c + 0x14);
  }
  return iStack_c;
}
/* GHIDRADEC_FUNCTION index=2915 start=0x4038bec */

undefined4 sub_4038BEC(int param_1,int param_2,uint param_3,undefined4 *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  
  *param_5 = param_1;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_2 + 4);
    uVar2 = *(uint *)(param_2 + 8);
    do {
      if ((((param_3 & 1) == 0) || (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) &&
         (((param_3 & 2) == 0 || (*(int *)(param_1 + 0xc) != *(int *)(param_2 + 0xc))))) {
        if (((*(uint *)(param_1 + 8) == 0xffffffff) || (uVar1 <= *(uint *)(param_1 + 8))) &&
           ((uVar2 == 0xffffffff || (*(uint *)(param_1 + 4) <= uVar2)))) {
          if ((uVar1 == *(uint *)(param_1 + 4)) && (uVar2 == *(uint *)(param_1 + 8))) {
            return 1;
          }
          if (((*(uint *)(param_1 + 4) <= uVar1) && (uVar2 != 0xffffffff)) &&
             ((uVar2 <= *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 2;
          }
          if ((uVar1 <= *(uint *)(param_1 + 4)) &&
             ((uVar2 == 0xffffffff ||
              ((*(uint *)(param_1 + 8) != 0xffffffff && (*(uint *)(param_1 + 8) <= uVar2)))))) {
            return 3;
          }
          if ((*(uint *)(param_1 + 4) < uVar1) &&
             ((uVar1 <= *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 4;
          }
          if (((uVar1 < *(uint *)(param_1 + 4)) && (uVar2 != 0xffffffff)) &&
             ((uVar2 < *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 5;
          }
                    /* WARNING: Subroutine does not return */
          _panic(aLfFindoverlapD);
        }
        if ((((param_3 & 1) != 0) && (uVar2 != 0xffffffff)) && (uVar2 < *(uint *)(param_1 + 4))) {
          return 0;
        }
      }
      *param_4 = (int *)(param_1 + 0x14);
      param_1 = *(int *)(param_1 + 0x14);
      *param_5 = param_1;
    } while (param_1 != 0);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2916 start=0x4038d12 */

void sub_4038D12(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x18) = param_2;
    }
    else {
      for (; *(int *)(iVar1 + 0x18) != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      }
      *(int *)(iVar1 + 0x18) = param_2;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2917 start=0x4038d40 */

undefined4 sub_4038D40(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &param_1;
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    iVar1 = *piVar2;
    if (param_2 == iVar1) break;
    piVar2 = (int *)(iVar1 + 0x18);
    param_1 = *piVar2;
  }
  *piVar2 = *(int *)(iVar1 + 0x18);
  return 1;
}
/* GHIDRADEC_FUNCTION index=2918 start=0x4038d6c */

void sub_4038D6C(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 4) == *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 4) = *(int *)(param_2 + 8) + 1;
    *(int *)(param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) {
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      iVar2 = _kalloc(0x1c);
      _bcopy(param_1,iVar2,0x1c);
      piVar1 = (int *)(*(int *)(iVar2 + 0x10) + 8);
      *piVar1 = *piVar1 + 1;
      *(int *)(iVar2 + 4) = *(int *)(param_2 + 8) + 1;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      *(int *)(param_2 + 0x14) = iVar2;
    }
    *(int *)(param_1 + 0x14) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2919 start=0x4038e00 */

void sub_4038E00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    _wakeup(iVar1);
    iVar1 = iVar2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2920 start=0x4038e3a */

void sub_4038E3A(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + 8);
  *piVar1 = *piVar1 + -1;
  _kfree(param_1,0x1c);
  return;
}
/* GHIDRADEC_FUNCTION index=2921 start=0x40396d2 */

/* WARNING: Removing unreachable block (ram,0x040399a2) */

int sub_40396D2(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined *puVar14;
  int aiStack_42 [15];
  
  piVar13 = (int *)0x0;
  iVar12 = 0;
  if (dword_40AF5C6 == 0) {
    _ihinit();
    dword_40AF5C6 = 1;
  }
  uVar3 = 3;
  if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
    uVar3 = 1;
  }
  iVar4 = (*(code *)**(undefined4 **)(*param_1 + 0x1c))
                    (param_1,uVar3,*(undefined4 *)(_active_u + 0x1a));
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar1 = true;
  uVar5 = (**(code **)(*(int *)(*param_1 + 0x1c) + 0x80))(*param_1);
  if (uVar5 == 0) {
    uVar3 = 3;
    if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
      uVar3 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar3,1,*(undefined4 *)(_active_u + 0x1a))
    ;
    _binval(*param_1);
    return 0xf;
  }
  iVar6 = _bread(*param_1,0x2000 / uVar5,0x2000);
  iVar11 = 0;
  iVar4 = iVar12;
  piVar2 = _mounttab;
  if ((*(byte *)(iVar6 + 3) & 4) == 0) {
    while (piVar13 = piVar2, piVar13 != (int *)0x0) {
      iVar4 = *(int *)((int)piVar13 + 10);
      if ((iVar4 != 0) && (*(sword *)(piVar13 + 1) == *(sword *)(*param_1 + 0x2c))) {
        if ((*(byte *)(param_3 + 0xf) & 0x40) != 0) goto loc_40398E2;
        piVar13 = (int *)0x0;
        iVar11 = 0x10;
        bVar1 = false;
        iVar4 = iVar12;
        goto loc_4039B50;
      }
      piVar2 = (int *)piVar13[7];
    }
    _vol_notify_cancel((int)*(sword *)(*param_1 + 0x2c));
    piVar2 = _mounttab;
    if ((*(uint *)(param_3 + 0xc) & 0x40) == 0) {
      while (piVar13 = piVar2, piVar13 != (int *)0x0) {
        if (*(int *)((int)piVar13 + 10) == 0) goto loc_4039876;
        piVar2 = (int *)piVar13[7];
      }
      piVar13 = (int *)_kalloc(0x20);
      _bzero(piVar13,0x20);
      if (piVar13 == (int *)0x0) {
        iVar11 = 0x18;
        goto loc_4039B56;
      }
      piVar13[7] = (int)_mounttab;
      _mounttab = piVar13;
loc_4039876:
      *(int **)(param_3 + 0x126) = piVar13;
      *piVar13 = param_3;
      *(int *)((int)piVar13 + 10) = iVar6;
      *(undefined2 *)(piVar13 + 1) = 0xffff;
      *(int *)((int)piVar13 + 6) = *param_1;
      iVar7 = *(int *)(iVar6 + 0x20);
      if (((*(int *)(iVar7 + 0x55c) != 0x11954) || (0x2000 < (int)*(uint *)(iVar7 + 0x30))) ||
         (*(uint *)(iVar7 + 0x30) < 0x562)) {
        iVar11 = 0x16;
        goto loc_4039B56;
      }
      iVar4 = _geteblk(*(undefined4 *)(iVar7 + 0x68));
      *(int *)((int)piVar13 + 10) = iVar4;
      _bcopy(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar4 + 0x20),
             *(undefined4 *)(iVar7 + 0x68));
loc_40398E2:
      if ((*(byte *)(param_3 + 0xf) & 1) == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0;
        _bwrite(iVar6);
        if (*(char *)(dword_40B57D4 + 100) == '\x1e') {
          *(undefined *)(dword_40B57D4 + 100) = 0;
          if (*param_1 == _rootvp) {
                    /* WARNING: Subroutine does not return */
            _panic(aRootDeviceIsPh);
          }
          *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 1;
        }
      }
      else {
        _brelse(iVar6);
      }
      iVar6 = 0;
      iVar12 = *(int *)(iVar4 + 0x20);
      if ((*(uint *)(param_3 + 0xc) & 1) == 0) {
        if (*(char *)(iVar12 + 0xd1) == '\x01') {
          *(undefined *)(iVar12 + 0xd1) = 2;
        }
        else {
          *(undefined *)(iVar12 + 0xd1) = 3;
        }
        *(undefined *)(iVar12 + 0xd0) = 1;
        *(undefined *)(iVar12 + 0xd2) = 0;
        if ((*(byte *)(param_3 + 0xf) & 0x40) != 0) {
          *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
          _sbupdate(piVar13);
          return 0;
        }
      }
      else {
        if ((*(uint *)(param_3 + 0xc) & 0x40) != 0) {
          puVar14 = aMountfsCanTRem;
          goto loc_403995C;
        }
        *(undefined *)(iVar12 + 0xd0) = 0;
        *(undefined *)(iVar12 + 0xd2) = 1;
      }
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar12 + 0x30);
      iVar8 = (*(int *)(iVar12 + 0x9c) + -1 + *(int *)(iVar12 + 0x34)) / *(int *)(iVar12 + 0x34);
      iVar7 = _kalloc(*(int *)(iVar12 + 0x9c));
      if (iVar7 != 0) {
        iVar9 = 0;
        if (0 < iVar8) {
          do {
            iVar10 = *(int *)(iVar12 + 0x30);
            if (iVar8 < *(int *)(iVar12 + 0x38) + iVar9) {
              iVar10 = *(int *)(iVar12 + 0x34) * (iVar8 - iVar9);
            }
            iVar6 = _bread(*(undefined4 *)((int)piVar13 + 6),
                           iVar9 + *(int *)(iVar12 + 0x98) << (*(uint *)(iVar12 + 100) & 0x3f),
                           iVar10);
            if ((*(byte *)(iVar6 + 3) & 4) != 0) {
              _kfree(iVar7,*(undefined4 *)(iVar12 + 0x9c));
              goto loc_4039B50;
            }
            _bcopy(*(undefined4 *)(iVar6 + 0x20),iVar7,iVar10);
            *(int *)(iVar12 + (iVar9 >> (*(uint *)(iVar12 + 0x60) & 0x3f)) * 4 + 0x2d8) = iVar7;
            iVar7 = iVar10 + iVar7;
            _brelse(iVar6);
            iVar9 = *(int *)(iVar12 + 0x38) + iVar9;
          } while (iVar9 < iVar8);
        }
        if (*(char *)(iVar12 + 0xd2) == '\0') {
          _sbupdate(piVar13);
        }
        *(byte *)(iVar12 + 0xd3) = *(byte *)(iVar12 + 0xd3) & 0xfc;
        iVar4 = (*(int *)(iVar12 + 0x3c) * *(int *)(iVar12 + 0x28)) / 100;
        *(int *)(iVar12 + 0x8c) = iVar4;
        *(int *)(iVar12 + 0x88) = iVar4;
        if (iVar4 < 0x65) {
          *(int *)(iVar12 + 0x88) = iVar4 * 2;
        }
        else {
          *(int *)(iVar12 + 0x88) = iVar4 + 100;
        }
        iVar4 = (*(int *)(iVar12 + 0xb8) * *(int *)(iVar12 + 0x2c)) / 100;
        *(int *)(iVar12 + 0x94) = iVar4;
        if (0x32 < iVar4) {
          *(undefined4 *)(iVar12 + 0x94) = 0x32;
        }
        *(undefined4 *)(iVar12 + 0x90) = *(undefined4 *)(iVar12 + 0x94);
        *(undefined2 *)(piVar13 + 1) = *(undefined2 *)(*(int *)((int)piVar13 + 6) + 0x2c);
        *(int *)(param_3 + 0x14) = (int)*(sword *)(piVar13 + 1);
        *(undefined4 *)(param_3 + 0x18) = 0;
        _copystr(param_2,iVar12 + 0xd4,0x1ff,aiStack_42);
        _bzero(iVar12 + aiStack_42[0] + 0xd4,0x200 - aiStack_42[0]);
        return 0;
      }
      iVar11 = 0xc;
      iVar12 = iVar4;
      goto loc_4039B56;
    }
    *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
    puVar14 = aMountfsIllegal;
    iVar4 = iVar12;
loc_403995C:
    _printf(puVar14);
    iVar11 = 0x16;
  }
loc_4039B50:
  iVar12 = iVar4;
  if (iVar11 == 0) {
    iVar11 = 5;
  }
loc_4039B56:
  if (piVar13 != (int *)0x0) {
    *(undefined4 *)((int)piVar13 + 10) = 0;
  }
  if (iVar12 != 0) {
    _brelse(iVar12);
  }
  if (iVar6 != 0) {
    _brelse(iVar6);
  }
  if (bVar1) {
    uVar3 = 3;
    if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
      uVar3 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar3,1,*(undefined4 *)(_active_u + 0x1a))
    ;
    _binval(*param_1);
  }
  return iVar11;
}
/* GHIDRADEC_FUNCTION index=2922 start=0x4039bda */

undefined4 sub_4039BDA(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x126);
  iVar4 = _iflush((int)*(sword *)(iVar1 + 4));
  if ((iVar4 < 0) && ((param_2 == 0 || (iVar4 < 0)))) {
    uVar5 = 0x10;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar1 + 10) + 0x20);
    iVar3 = -(int)-(*(char *)(iVar2 + 0xd2) == '\0');
    if ((iVar3 != 0) && (*(char *)(iVar2 + 0xd1) == '\x02')) {
      *(undefined *)(iVar2 + 0xd1) = 1;
      _sbupdate(iVar1);
    }
    _kfree(*(undefined4 *)(iVar2 + 0x2d8),*(undefined4 *)(iVar2 + 0x9c));
    _brelse(*(undefined4 *)(iVar1 + 10));
    *(undefined4 *)(iVar1 + 10) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
    if (iVar4 == 0) {
      (**(code **)(*(int *)(*(int *)(iVar1 + 6) + 0x1c) + 4))
                (*(int *)(iVar1 + 6),iVar3,1,*(undefined4 *)(_active_u + 0x1a));
      _binval(*(undefined4 *)(iVar1 + 6));
      _vn_rele(*(undefined4 *)(iVar1 + 6));
      *(undefined4 *)(iVar1 + 6) = 0;
      iVar4 = _mounttab;
      if (_mounttab == iVar1) {
        _mounttab = *(int *)(iVar1 + 0x1c);
      }
      else {
        for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
          if (iVar1 == *(int *)(iVar4 + 0x1c)) {
            *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
          }
        }
      }
      _kfree(iVar1,0x20);
    }
    uVar5 = 0;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2923 start=0x4039f30 */

int sub_4039F30(undefined4 param_1,byte *param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 0x28) == 3) {
      *(undefined2 *)param_2 = *(undefined2 *)(iStack_8 + 0x2c);
      _vn_rele(iStack_8);
      iVar1 = 6;
      if ((int)(uint)*param_2 < _nblkdev) {
        iVar1 = 0;
      }
    }
    else {
      _vn_rele(iStack_8);
      iVar1 = 0xf;
    }
  }
  else if (*(char *)(dword_40B57D4 + 100) == '\x02') {
    iVar1 = 0x13;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2924 start=0x403a0f2 */

undefined4 sub_403A0F2(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  word wVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if ((param_3 == 1) && (*(int *)*param_1 != 0)) {
    _vnode_uncache(param_1);
  }
  iVar1 = *(int *)((int)param_1 + 0x2e);
  if ((*(word *)(iVar1 + 0x62) & 0xf000) == 0x8000) {
    bVar3 = true;
    while ((*(word *)(iVar1 + 0x42) & 1) != 0) {
      *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 0x10;
      _sleep(iVar1,10);
    }
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 1;
    if (((param_4 & 2) != 0) && (param_3 == 1)) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x6e);
    }
  }
  else {
    bVar3 = false;
  }
  uVar4 = sub_403A216(iVar1,param_2,param_3,param_4);
  if ((*(word *)(iVar1 + 0x42) & 0x46) != 0) {
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar1 + 0x43) & 4) != 0) {
      *(undefined4 *)(iVar1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x43) & 2) != 0) {
      *(undefined4 *)(iVar1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(iVar1 + 0x4a) = 0;
      *(undefined4 *)(iVar1 + 0x82) = _iuniqtime;
    }
    *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) & 0xffb9;
  }
  if (bVar3) {
    wVar2 = *(word *)(iVar1 + 0x42);
    *(word *)(iVar1 + 0x42) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar1 + 0x42) = wVar2 & 0xffee;
      _wakeup(iVar1);
    }
  }
  return uVar4;
}

