
/* WARNING: Removing unreachable block (ram,0xf00c2974) */
/* WARNING: Removing unreachable block (ram,0xf00c28b4) */
/* WARNING: Removing unreachable block (ram,0xf00c2984) */
/* WARNING: Removing unreachable block (ram,0xf00c26ec) */

undefined8 _msinput(uint param_1,uint *param_2)

{
  uint *puVar1;
  byte bVar4;
  char cVar5;
  sword sVar3;
  int iVar2;
  uint uVar6;
  int iVar7;
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
  puVar1 = param_2;
  sub_F00C2BC4();
  if ((puVar1 == (uint *)0x0) || (uVar6 = *puVar1, uVar6 == 0)) goto locret_F00C298C;
  param_2 = (uint *)(uVar6 + *(sword *)(uVar6 + 2) * 0xc + 4);
  bVar4 = (byte)param_1;
  switch(*(undefined2 *)(puVar1 + 8)) {
  case :
    if ((param_1 & 0xf0) != 0x80) goto locret_F00C298C;
    *(byte *)((int)param_2 + 2) = bVar4 & 7;
    *(word *)(puVar1 + 7) = (word)param_1 & 8;
    puVar1[0xb] = puVar1[0xb] + 1;
    break;
  case :
    iVar7 = (int)*(char *)param_2 + (int)(char)bVar4;
    if (iVar7 < 0x80) {
      if (iVar7 < -0x80) {
loc_F00C281C:
        *(char *)param_2 = -0x80;
      }
      else {
        *(char *)param_2 = (char)iVar7;
      }
    }
    else {
loc_F00C2824:
      *(char *)param_2 = '\x7f';
    }
    break;
  case :
    iVar7 = (int)*(char *)((int)param_2 + 1) - (int)(char)bVar4;
    if (iVar7 < 0x80) {
      if (-0x81 < iVar7) {
        *(char *)((int)param_2 + 1) = (char)iVar7;
        break;
      }
      cVar5 = -0x80;
    }
    else {
      cVar5 = '\x7f';
    }
    goto loc_F00C285C;
  case :
    iVar7 = (int)*(char *)param_2 + (int)(char)bVar4;
    if (0x7f < iVar7) goto loc_F00C2824;
    if (iVar7 < -0x80) goto loc_F00C281C;
    *(char *)param_2 = (char)iVar7;
    break;
  case :
    iVar7 = (int)*(char *)((int)param_2 + 1) - (int)(char)bVar4;
    if (iVar7 < 0x80) {
      cVar5 = -0x80;
      if (-0x81 < iVar7) {
        *(char *)((int)param_2 + 1) = (char)iVar7;
        break;
      }
    }
    else {
      cVar5 = '\x7f';
    }
loc_F00C285C:
    *(char *)((int)param_2 + 1) = cVar5;
  }
  if (*(sword *)(puVar1 + 8) != 4) {
    if (*(sword *)(puVar1 + 7) == 0) {
      sVar3 = *(sword *)(puVar1 + 8);
    }
    else {
      if (*(sword *)(puVar1 + 8) == 2) {
        *(undefined2 *)(puVar1 + 8) = 0;
        goto loc_F00C28A0;
      }
      sVar3 = *(sword *)(puVar1 + 8);
    }
    *(sword *)(puVar1 + 8) = sVar3 + 1;
    goto locret_F00C298C;
  }
  *(undefined2 *)(puVar1 + 8) = 0;
loc_F00C28A0:
  if (*(sword *)((int)puVar1 + 0x22) != 0) {
    _untimeout(sub_F00C2994,puVar1);
    ((char *)((int)puVar1 + 0x22))[0] = '\0';
    ((char *)((int)puVar1 + 0x22))[1] = '\0';
  }
  if (*(char *)((int)param_2 + 2) != *(char *)((int)puVar1 + 0x1e)) {
    cVar5 = *(char *)((int)param_2 + 2);
    goto loc_F00C2980;
  }
  if ((*param_2 & 0xffff0000) == 0) goto locret_F00C298C;
  iVar7 = _ms_jitter_thresh;
  if (*(sword *)(puVar1 + 7) != 0) {
    iVar7 = _ms_jitter_thresh << 1;
  }
  iVar2 = (int)*(char *)param_2;
  if (iVar2 < 0) {
    if (-iVar7 == iVar2 || -iVar2 < iVar7) {
      cVar5 = *(char *)((int)param_2 + 1);
      goto loc_F00C2930;
    }
    cVar5 = *(char *)((int)param_2 + 2);
  }
  else if (iVar7 < iVar2) {
    cVar5 = *(char *)((int)param_2 + 2);
  }
  else {
    cVar5 = *(char *)((int)param_2 + 1);
loc_F00C2930:
    iVar2 = (int)cVar5;
    if (iVar2 < 0) {
      if (-iVar7 == iVar2 || -iVar2 < iVar7) goto loc_F00C2960;
      cVar5 = *(char *)((int)param_2 + 2);
    }
    else {
      if (iVar2 <= iVar7) {
loc_F00C2960:
        ((char *)((int)puVar1 + 0x22))[0] = '\0';
        ((char *)((int)puVar1 + 0x22))[1] = '\x01';
        _timeout(sub_F00C2994,puVar1,_msjittertimeout);
        goto locret_F00C298C;
      }
      cVar5 = *(char *)((int)param_2 + 2);
    }
  }
loc_F00C2980:
  *(char *)((int)puVar1 + 0x1e) = cVar5;
  sub_F00C2994();
locret_F00C298C:
  return CONCAT44(param_2,param_1);
}
