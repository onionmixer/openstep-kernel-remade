
/* WARNING: Removing unreachable block (ram,0xf00224f0) */
/* WARNING: Removing unreachable block (ram,0xf0022514) */
/* WARNING: Removing unreachable block (ram,0xf00229b4) */
/* WARNING: Removing unreachable block (ram,0xf00225e8) */
/* WARNING: Removing unreachable block (ram,0xf00229cc) */
/* WARNING: Removing unreachable block (ram,0xf0022614) */
/* WARNING: Removing unreachable block (ram,0xf00227fc) */
/* WARNING: Removing unreachable block (ram,0xf00227dc) */
/* WARNING: Removing unreachable block (ram,0xf0022770) */
/* WARNING: Removing unreachable block (ram,0xf0022698) */
/* WARNING: Removing unreachable block (ram,0xf0022948) */
/* WARNING: Removing unreachable block (ram,0xf002288c) */
/* WARNING: Removing unreachable block (ram,0xf00226e0) */
/* WARNING: Removing unreachable block (ram,0xf0022784) */
/* WARNING: Removing unreachable block (ram,0xf0022810) */
/* WARNING: Removing unreachable block (ram,0xf0022870) */
/* WARNING: Removing unreachable block (ram,0xf0022674) */
/* WARNING: Removing unreachable block (ram,0xf00225e0) */
/* WARNING: Removing unreachable block (ram,0xf00227a4) */
/* WARNING: Removing unreachable block (ram,0xf0022540) */
/* WARNING: Removing unreachable block (ram,0xf0022500) */
/* WARNING: Removing unreachable block (ram,0xf00229e0) */
/* WARNING: Removing unreachable block (ram,0xf0022554) */

undefined8 _uipc_usrreq(sword *param_1,int param_2,undefined2 *param_3,int param_4,sword *param_5)

{
  word wVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  sword sVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 unaff_l0;
  sword *psVar8;
  undefined4 unaff_l1;
  sword *psVar9;
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
  bool bVar10;
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
  psVar9 = (sword *)0x0;
  psVar8 = *(sword **)(param_1 + 4);
  if (param_2 == 0xb) {
loc_F0022428:
    psVar9 = (sword *)0x2d;
    goto locret_F00229EC;
  }
  if (((param_2 != 9) && (param_5 != (sword *)0x0)) && (param_5[4] != 0)) {
loc_F0022454:
    psVar9 = (sword *)0x2d;
    goto loc_F00229D4;
  }
  if ((psVar8 == (sword *)0x0) && (param_2 != 0)) {
    psVar9 = (sword *)0x16;
    goto loc_F00229D4;
  }
  switch(param_2) {
  case :
    psVar9 = (sword *)0x38;
    if (psVar8 == (sword *)0x0) {
      _unp_attach(param_1);
      psVar9 = param_1;
    }
  case :
  case :
loc_F00229D4:
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _unp_detach(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _unp_bind(psVar8,param_4);
    psVar9 = psVar8;
    goto loc_F00229D4;
  case :
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int *)(psVar8 + 2) == 0) {
      psVar9 = (sword *)0x16;
    }
    break;
  case :
    _unp_connect(param_1,param_4);
    psVar9 = param_1;
    goto loc_F00229D4;
  case :
    if ((*(int *)(psVar8 + 6) == 0) || (iVar3 = *(int *)(*(int *)(psVar8 + 6) + 0x18), iVar3 == 0))
    {
      *(undefined2 *)(param_4 + 8) = 0x10;
      iVar3 = *(int *)(param_4 + 4);
      *(undefined2 *)(param_4 + iVar3) = _sun_noname;
      param_4 = param_4 + iVar3;
      *(undefined2 *)(param_4 + 2) = DAT_f010bcf2._0_2_;
      *(undefined2 *)(param_4 + 4) = DAT_f010bcf2._2_2_;
      *(undefined2 *)(param_4 + 6) = DAT_f010bcf2._4_2_;
      *(undefined2 *)(param_4 + 8) = DAT_f010bcf2._6_2_;
      *(undefined2 *)(param_4 + 10) = DAT_f010bcf2._8_2_;
      *(undefined2 *)(param_4 + 0xc) = DAT_f010bcf2._10_2_;
      *(undefined2 *)(param_4 + 0xe) = DAT_f010bcf2._12_2_;
      goto loc_F00229D4;
    }
    sVar5 = *(sword *)(iVar3 + 8);
loc_F0022994:
    *(sword *)(param_4 + 8) = sVar5;
    _bcopy(*(int *)(*(int *)(psVar8 + 6) + 0x18) +
           *(int *)(*(int *)(*(int *)(psVar8 + 6) + 0x18) + 4),param_4 + *(int *)(param_4 + 4),
           (int)sVar5);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
loc_F00227A4:
    _unp_disconnect(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _socantsendmore(param_1);
    _unp_usrclosed(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    if (*param_1 != 1) {
      if (*param_1 != 2) {
        puVar4 = (undefined *)&aUipc2;
        goto loc_F00229CC;
      }
      _panic(&aUipc1);
    }
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int **)(psVar8 + 6) != (int *)0x0) {
      param_2 = **(int **)(psVar8 + 6);
      *(sword *)(param_2 + 0x42) =
           *(sword *)(param_2 + 0x42) + ((sword)*(undefined4 *)(psVar8 + 0x10) - param_1[0x14]);
      *(uint *)(psVar8 + 0x10) = (uint)(word)param_1[0x14];
      *(sword *)(param_2 + 0x3e) =
           *(sword *)(param_2 + 0x3e) + ((sword)*(undefined4 *)(psVar8 + 0xe) - param_1[0x12]);
      *(uint *)(psVar8 + 0xe) = (uint)(word)param_1[0x12];
      _sowakeup(param_2,param_2 + 0x3c);
      bVar10 = param_3 == (undefined2 *)0x0;
    }
    break;
  case :
    if (param_5 == (sword *)0x0) {
      sVar5 = *param_1;
    }
    else {
      psVar9 = param_5;
      _unp_internalize();
      bVar10 = param_3 == (undefined2 *)0x0;
      if (psVar9 != (sword *)0x0) break;
      sVar5 = *param_1;
    }
    if (sVar5 == 1) {
      if ((param_1[3] & 0x10U) == 0) {
        if (*(int *)(psVar8 + 6) == 0) {
          _panic(&aUipc3);
          piVar2 = *(int **)(psVar8 + 6);
        }
        else {
          piVar2 = *(int **)(psVar8 + 6);
        }
        param_2 = *piVar2;
        if (param_5 == (sword *)0x0) {
          _sbappend(param_2 + 0x24,param_3);
          iVar3 = *(int *)(psVar8 + 6);
        }
        else {
          _sbappendrights(param_2 + 0x24,param_3,param_5);
          iVar3 = *(int *)(psVar8 + 6);
        }
        param_1[0x21] =
             param_1[0x21] - (*(sword *)(param_2 + 0x28) - (sword)*(undefined4 *)(iVar3 + 0x20));
        *(uint *)(*(int *)(psVar8 + 6) + 0x20) = (uint)*(word *)(param_2 + 0x28);
        param_3 = (undefined2 *)0x0;
        param_1[0x1f] =
             param_1[0x1f] -
             (*(sword *)(param_2 + 0x24) - (sword)*(undefined4 *)(*(int *)(psVar8 + 6) + 0x1c));
        *(uint *)(*(int *)(psVar8 + 6) + 0x1c) = (uint)*(word *)(param_2 + 0x24);
        _sowakeup(param_2,param_2 + 0x24);
        bVar10 = true;
        break;
      }
      psVar9 = (sword *)0x20;
    }
    else {
      if (sVar5 != 2) {
        puVar4 = (undefined *)&aUipc4;
        goto loc_F00229CC;
      }
      if (param_4 == 0) {
        if (*(int *)(psVar8 + 6) != 0) {
          piVar2 = *(int **)(psVar8 + 6);
          goto loc_F0022710;
        }
        psVar9 = (sword *)0x39;
      }
      else {
        psVar9 = (sword *)0x38;
        if (*(int *)(psVar8 + 6) == 0) {
          _unp_connect(param_1,param_4);
          bVar10 = param_3 == (undefined2 *)0x0;
          psVar9 = param_1;
          if (param_1 != (sword *)0x0) break;
          piVar2 = *(int **)(psVar8 + 6);
loc_F0022710:
          iVar3 = *(int *)(psVar8 + 0xc);
          param_2 = *piVar2;
          if (iVar3 == 0) {
            puVar7 = &_sun_noname;
          }
          else {
            puVar7 = (undefined2 *)(iVar3 + *(int *)(iVar3 + 4));
          }
          iVar3 = (uint)*(word *)(param_2 + 0x26) - (uint)*(word *)(param_2 + 0x24);
          iVar6 = (uint)*(word *)(param_2 + 0x2a) - (uint)*(word *)(param_2 + 0x28);
          if (iVar6 < iVar3) {
            iVar3 = iVar6;
          }
          iVar6 = param_2 + 0x24;
          if ((iVar3 < 1) ||
             (iVar3 = iVar6, _sbappendaddr(iVar6,puVar7,param_3,param_5), iVar3 == 0)) {
            psVar9 = (sword *)0x37;
          }
          else {
            _sowakeup(param_2,iVar6);
            param_3 = (undefined2 *)0x0;
          }
          bVar10 = param_3 == (undefined2 *)0x0;
          if (param_4 != 0) goto loc_F00227A4;
          break;
        }
      }
    }
    goto loc_F00229D4;
  case :
    _unp_drop(psVar8,0x35);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  :
    puVar4 = aPiusrreq;
loc_F00229CC:
    _panic(puVar4);
    goto loc_F00229D4;
  case :
    wVar1 = param_1[0x1f];
    *(uint *)(param_3 + 0x18) = (uint)wVar1;
    if ((*param_1 == 1) && (*(int **)(psVar8 + 6) != (int *)0x0)) {
      param_2 = **(int **)(psVar8 + 6);
      *(uint *)(param_3 + 0x18) = (uint)wVar1 + (uint)*(word *)(param_2 + 0x24);
    }
    *param_3 = 0xffff;
    iVar3 = *(int *)(psVar8 + 4);
    if (iVar3 == 0) {
      iVar3 = _unp_vno + 1;
      *(int *)(psVar8 + 4) = _unp_vno;
      _unp_vno = iVar3;
      iVar3 = *(int *)(psVar8 + 4);
    }
    *(int *)(param_3 + 2) = iVar3;
    param_3[4] = 0x11b6;
    param_3[5] = 1;
    param_3[6] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    param_3[7] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4);
    *(uint *)(param_3 + 10) = (uint)(word)param_1[0x12];
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    psVar9 = (sword *)0x0;
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x10);
    goto locret_F00229EC;
  case :
    goto loc_F0022428;
  case :
    goto loc_F0022454;
  case :
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int *)(psVar8 + 6) != 0) {
      iVar3 = *(int *)(*(int *)(psVar8 + 6) + 0x18);
      bVar10 = param_3 == (undefined2 *)0x0;
      if (iVar3 != 0) {
        sVar5 = *(sword *)(iVar3 + 8);
        goto loc_F0022994;
      }
    }
    break;
  case :
    _unp_connect2(param_1,param_4);
    psVar9 = param_1;
    goto loc_F00229D4;
  }
  if (!bVar10) {
    _m_freem(param_3);
  }
locret_F00229EC:
  return CONCAT44(param_2,psVar9);
}
