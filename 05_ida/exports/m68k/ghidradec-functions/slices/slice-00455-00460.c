/* GHIDRADEC_FUNCTION index=455 start=0x4015c82 */

int _uipc_usrreq(sword *param_1,int param_2,undefined2 *param_3,int param_4,int param_5)

{
  int iVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 auStack_c [2];
  
  iVar1 = *(int *)(param_1 + 4);
  iVar4 = 0;
  if (param_2 == 0xb) {
loc_40160E8:
    return 0x2d;
  }
  if (((param_2 != 9) && (param_5 != 0)) && (*(sword *)(param_5 + 8) != 0)) {
loc_4015cc2:
    iVar4 = 0x2d;
    goto loc_40160DA;
  }
  if ((iVar1 == 0) && (param_2 != 0)) {
loc_4015D6A:
    iVar4 = 0x16;
    goto loc_40160DA;
  }
  switch(param_2) {
  case :
    if (iVar1 == 0) {
      iVar4 = _unp_attach(param_1);
      break;
    }
loc_4015E8A:
    iVar4 = 0x38;
    break;
  case :
    _unp_detach(iVar1);
    break;
  case :
    iVar4 = _unp_bind(iVar1,param_4);
    break;
  case :
    if (*(int *)(iVar1 + 4) != 0) break;
    goto loc_4015D6A;
  case :
    iVar4 = _unp_connect(param_1,param_4);
    break;
  case :
    if ((*(int *)(iVar1 + 0xc) == 0) || (iVar6 = *(int *)(*(int *)(iVar1 + 0xc) + 0x18), iVar6 == 0)
       ) {
      *(undefined2 *)(param_4 + 8) = 0x10;
      puVar7 = (undefined4 *)(*(int *)(param_4 + 4) + param_4);
      *puVar7 = _sun_noname;
      puVar7[1] = dword_40AE746;
      puVar7[2] = dword_40AE74A;
      puVar7[3] = dword_40AE74E;
      break;
    }
    goto loc_40160A0;
  case :
    _unp_disconnect(iVar1);
    break;
  case :
    _socantsendmore(param_1);
    _unp_usrclosed(iVar1);
    break;
  case :
    if (*param_1 != 1) {
      if (*param_1 == 2) {
                    /* WARNING: Subroutine does not return */
        _panic(&aUipc1);
      }
      puVar8 = (undefined *)&aUipc2;
      goto loc_40160D2;
    }
    if (*(int **)(iVar1 + 0xc) != (int *)0x0) {
      iVar6 = **(int **)(iVar1 + 0xc);
      *(sword *)(iVar6 + 0x3e) =
           (*(sword *)(iVar1 + 0x22) - param_1[0x13]) + *(sword *)(iVar6 + 0x3e);
      *(uint *)(iVar1 + 0x20) = (uint)(word)param_1[0x13];
      *(sword *)(iVar6 + 0x3a) =
           (*(sword *)(iVar1 + 0x1e) - param_1[0x11]) + *(sword *)(iVar6 + 0x3a);
      *(uint *)(iVar1 + 0x1c) = (uint)(word)param_1[0x11];
      _sowakeup(iVar6,iVar6 + 0x38);
    }
    break;
  case :
    if ((param_5 != 0) && (iVar4 = _unp_internalize(param_5), iVar4 != 0)) break;
    if (*param_1 == 1) {
      if ((*(byte *)((int)param_1 + 7) & 0x10) == 0) {
        if (*(int *)(iVar1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aUipc3);
        }
        iVar6 = **(int **)(iVar1 + 0xc);
        if (param_5 == 0) {
          _sbappend(iVar6 + 0x22,param_3);
        }
        else {
          _sbappendrights(iVar6 + 0x22,param_3,param_5);
        }
        param_1[0x1f] =
             param_1[0x1f] - (*(sword *)(iVar6 + 0x26) - *(sword *)(*(int *)(iVar1 + 0xc) + 0x22));
        *(uint *)(*(int *)(iVar1 + 0xc) + 0x20) = (uint)*(word *)(iVar6 + 0x26);
        param_1[0x1d] =
             param_1[0x1d] - (*(sword *)(iVar6 + 0x22) - *(sword *)(*(int *)(iVar1 + 0xc) + 0x1e));
        *(uint *)(*(int *)(iVar1 + 0xc) + 0x1c) = (uint)*(word *)(iVar6 + 0x22);
        _sowakeup(iVar6,iVar6 + 0x22);
        param_3 = (undefined2 *)0x0;
      }
      else {
        iVar4 = 0x20;
      }
      break;
    }
    if (*param_1 != 2) {
      puVar8 = (undefined *)&aUipc4;
      goto loc_40160D2;
    }
    if (param_4 == 0) {
      if (*(int *)(iVar1 + 0xc) == 0) {
        iVar4 = 0x39;
        break;
      }
    }
    else {
      if (*(int *)(iVar1 + 0xc) != 0) goto loc_4015E8A;
      iVar4 = _unp_connect(param_1,param_4);
      if (iVar4 != 0) break;
    }
    iVar6 = **(int **)(iVar1 + 0xc);
    iVar3 = *(int *)(iVar1 + 0x18);
    if (iVar3 == 0) {
      puVar7 = &_sun_noname;
    }
    else {
      puVar7 = (undefined4 *)(*(int *)(iVar3 + 4) + iVar3);
    }
    iVar5 = (uint)*(word *)(iVar6 + 0x28) - (uint)*(word *)(iVar6 + 0x26);
    iVar3 = (uint)*(word *)(iVar6 + 0x24) - (uint)*(word *)(iVar6 + 0x22);
    if (iVar5 < iVar3) {
      iVar3 = iVar5;
    }
    if (iVar3 < 1) {
loc_4015F20:
      iVar4 = 0x37;
    }
    else {
      iVar3 = _sbappendaddr(iVar6 + 0x22,puVar7,param_3,param_5);
      if (iVar3 == 0) goto loc_4015F20;
      _sowakeup(iVar6,iVar6 + 0x22);
      param_3 = (undefined2 *)0x0;
    }
    if (param_4 != 0) {
      _unp_disconnect(iVar1);
    }
    break;
  case :
    _unp_drop(iVar1,0x35);
    break;
  :
    puVar8 = aPiusrreq;
loc_40160D2:
                    /* WARNING: Subroutine does not return */
    _panic(puVar8);
  case :
    wVar2 = param_1[0x1d];
    *(uint *)(param_3 + 0x16) = (uint)wVar2;
    if ((*param_1 == 1) && (*(int **)(iVar1 + 0xc) != (int *)0x0)) {
      *(uint *)(param_3 + 0x16) = (uint)*(word *)(**(int **)(iVar1 + 0xc) + 0x22) + (uint)wVar2;
    }
    *param_3 = 0xffff;
    if (*(int *)(iVar1 + 8) == 0) {
      *(int *)(iVar1 + 8) = _unp_vno;
      _unp_vno = _unp_vno + 1;
    }
    *(undefined4 *)(param_3 + 1) = *(undefined4 *)(iVar1 + 8);
    param_3[3] = 0x11b6;
    param_3[4] = 1;
    param_3[5] = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
    param_3[6] = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 4);
    *(uint *)(param_3 + 8) = (uint)(word)param_1[0x11];
    _getthetime(auStack_c);
    *(undefined4 *)(param_3 + 10) = auStack_c[0];
    *(undefined4 *)(param_3 + 0xe) = auStack_c[0];
    *(undefined4 *)(param_3 + 0x12) = auStack_c[0];
    return 0;
  case :
    goto loc_40160E8;
  case :
    goto loc_4015cc2;
  case :
  case :
    break;
  case :
    if ((*(int *)(iVar1 + 0xc) == 0) || (iVar6 = *(int *)(*(int *)(iVar1 + 0xc) + 0x18), iVar6 == 0)
       ) break;
loc_40160A0:
    *(undefined2 *)(param_4 + 8) = *(undefined2 *)(iVar6 + 8);
    iVar1 = *(int *)(*(int *)(iVar1 + 0xc) + 0x18);
    _bcopy(*(int *)(iVar1 + 4) + iVar1,*(int *)(param_4 + 4) + param_4,(int)*(sword *)(param_4 + 8))
    ;
    break;
  case :
    iVar4 = _unp_connect2(param_1,param_4);
  }
loc_40160DA:
  if (param_3 != (undefined2 *)0x0) {
    _m_freem(param_3);
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=456 start=0x40160f2 */

int _unp_attach(sword *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = _unpst_sendspace;
  uVar4 = _unpst_recvspace;
  if ((*param_1 != 1) && (uVar3 = _unpdg_sendspace, uVar4 = _unpdg_recvspace, *param_1 != 2)) {
                    /* WARNING: Subroutine does not return */
    _panic(aUnpAttackBadSo);
  }
  iVar1 = _soreserve(param_1,uVar3,uVar4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_kalloc(0x24);
    _bzero(puVar2,0x24);
    *(undefined4 **)(param_1 + 4) = puVar2;
    *puVar2 = param_1;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=457 start=0x401617c */

void _unp_detach(int *param_1)

{
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 0x20) = 0;
    _vn_rele(param_1[1]);
    param_1[1] = 0;
  }
  if (param_1[3] != 0) {
    _unp_disconnect(param_1);
  }
  while (param_1[4] != 0) {
    _unp_drop(param_1[4],0x36);
  }
  _soisdisconnected(*param_1);
  *(undefined4 *)(*param_1 + 8) = 0;
  _m_freem(param_1[6]);
  _kfree(param_1,0x24);
  if (_unp_rights != 0) {
    _unp_gc();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=458 start=0x4016208 */

/* WARNING: Type propagation algorithm not settling */

int _unp_bind(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int aiStack_42 [2];
  undefined2 uStack_3a;
  
  iVar2 = *(int *)(param_2 + 4) + param_2;
  if ((param_1[1] == 0) && (*(sword *)(param_2 + 8) != 0x70)) {
    *(undefined *)(iVar2 + *(sword *)(param_2 + 8)) = 0;
    _vattr_null(aiStack_42 + 1);
    aiStack_42[1] = 6;
    uStack_3a = 0x1ff;
    iVar2 = _vn_create(iVar2 + 2,1,aiStack_42 + 1,1,0,aiStack_42);
    if (iVar2 == 0) {
      *(undefined4 *)(aiStack_42[0] + 0x20) = *param_1;
      param_1[1] = aiStack_42[0];
      uVar1 = _m_copy(param_2,0,1000000000);
      param_1[6] = uVar1;
      iVar2 = 0;
    }
    else if (iVar2 == 0x11) {
      iVar2 = 0x30;
    }
  }
  else {
    iVar2 = 0x16;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=459 start=0x40162a6 */

int _unp_connect(sword *param_1,int param_2)

{
  int iVar1;
  sword *psVar2;
  int iStack_8;
  
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if (*(int *)(param_2 + 4) + -0xc + (int)*(sword *)(param_2 + 8) == 0x70) {
    return 0x28;
  }
  *(undefined *)(*(sword *)(param_2 + 8) + iVar1) = 0;
  iVar1 = _lookupname(iVar1 + 2,1,1,0,&iStack_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(int *)(iStack_8 + 0x28) != 6) {
    iVar1 = 0x26;
    goto loc_4016350;
  }
  psVar2 = *(sword **)(iStack_8 + 0x20);
  if (psVar2 != (sword *)0x0) {
    if (*psVar2 != *param_1) {
      iVar1 = 0x29;
      goto loc_4016350;
    }
    if (((*(byte *)(*(int *)(param_1 + 6) + 9) & 4) == 0) ||
       (((*(byte *)((int)psVar2 + 3) & 2) != 0 &&
        (psVar2 = (sword *)_sonewconn(psVar2), psVar2 != (sword *)0x0)))) {
      iVar1 = _unp_connect2(param_1,psVar2);
      goto loc_4016350;
    }
  }
  iVar1 = 0x3d;
loc_4016350:
  _vn_rele(iStack_8);
  return iVar1;
}

