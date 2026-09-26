/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118118 */

int _uipc_usrreq(short *param_1,int param_2,undefined2 *param_3,int param_4,int param_5)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *local_14;
  int iVar8;
  undefined4 local_c [2];
  
  iVar3 = *(int *)(param_1 + 4);
  iVar8 = 0;
  if (param_2 == 0xb) {
LAB_001185eb:
    return 0x2d;
  }
  if (((param_2 != 9) && (param_5 != 0)) && (*(short *)(param_5 + 8) != 0)) {
switchD_00118179_caseD_e:
    iVar8 = 0x2d;
    goto switchD_00118179_caseD_f;
  }
  if ((iVar3 == 0) && (param_2 != 0)) {
LAB_0011820a:
    iVar8 = 0x16;
    goto switchD_00118179_caseD_f;
  }
  switch(param_2) {
  case 0:
    if (iVar3 == 0) {
      iVar8 = _unp_attach(param_1);
      break;
    }
LAB_00118368:
    iVar8 = 0x38;
    break;
  case 1:
    _unp_detach(iVar3);
    break;
  case 2:
    iVar8 = _unp_bind(iVar3,param_4);
    break;
  case 3:
    if (*(int *)(iVar3 + 4) != 0) break;
    goto LAB_0011820a;
  case 4:
    iVar8 = _unp_connect(param_1,param_4);
    break;
  case 5:
    if ((*(int *)(iVar3 + 0xc) == 0) || (iVar4 = *(int *)(*(int *)(iVar3 + 0xc) + 0x18), iVar4 == 0)
       ) {
      *(undefined2 *)(param_4 + 8) = 0x10;
      iVar3 = *(int *)(param_4 + 4);
      *(undefined4 *)(iVar3 + param_4) = _sun_noname;
      *(undefined4 *)(iVar3 + 4 + param_4) = DAT_001db3a8;
      *(undefined4 *)(iVar3 + 8 + param_4) = DAT_001db3ac;
      *(undefined4 *)(iVar3 + 0xc + param_4) = DAT_001db3b0;
      break;
    }
    *(undefined2 *)(param_4 + 8) = *(undefined2 *)(iVar4 + 8);
    sVar2 = *(short *)(param_4 + 8);
    goto LAB_001185ad;
  case 6:
    _unp_disconnect(iVar3);
    break;
  case 7:
    _socantsendmore(param_1);
    _unp_usrclosed(iVar3);
    break;
  case 8:
    if (*param_1 != 1) {
      if (*param_1 == 2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_uipc_1_001db3b4);
      }
      pcVar7 = s_uipc_2_001db3bb;
      goto LAB_001185d1;
    }
    if (*(int **)(iVar3 + 0xc) != (int *)0x0) {
      iVar4 = **(int **)(iVar3 + 0xc);
      *(short *)(iVar4 + 0x42) =
           *(short *)(iVar4 + 0x42) + (*(short *)(iVar3 + 0x20) - param_1[0x14]);
      *(uint *)(iVar3 + 0x20) = (uint)(ushort)param_1[0x14];
      *(short *)(iVar4 + 0x3e) =
           *(short *)(iVar4 + 0x3e) + (*(short *)(iVar3 + 0x1c) - param_1[0x12]);
      *(uint *)(iVar3 + 0x1c) = (uint)(ushort)param_1[0x12];
      _sowakeup(iVar4,iVar4 + 0x3c);
    }
    break;
  case 9:
    if ((param_5 != 0) && (iVar8 = _unp_internalize(param_5), iVar8 != 0)) break;
    if (*param_1 == 1) {
      if ((*(byte *)(param_1 + 3) & 0x10) == 0) {
        if (*(int *)(iVar3 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_uipc_3_001db3c2);
        }
        iVar4 = **(int **)(iVar3 + 0xc);
        if (param_5 == 0) {
          _sbappend(iVar4 + 0x24,param_3);
        }
        else {
          _sbappendrights(iVar4 + 0x24,param_3,param_5);
        }
        param_1[0x21] =
             param_1[0x21] - (*(short *)(iVar4 + 0x28) - *(short *)(*(int *)(iVar3 + 0xc) + 0x20));
        *(uint *)(*(int *)(iVar3 + 0xc) + 0x20) = (uint)*(ushort *)(iVar4 + 0x28);
        param_1[0x1f] =
             param_1[0x1f] - (*(short *)(iVar4 + 0x24) - *(short *)(*(int *)(iVar3 + 0xc) + 0x1c));
        *(uint *)(*(int *)(iVar3 + 0xc) + 0x1c) = (uint)*(ushort *)(iVar4 + 0x24);
        _sowakeup(iVar4,iVar4 + 0x24);
        param_3 = (undefined2 *)0x0;
      }
      else {
        iVar8 = 0x20;
      }
      break;
    }
    if (*param_1 != 2) {
      pcVar7 = s_uipc_4_001db3c9;
      goto LAB_001185d1;
    }
    if (param_4 == 0) {
      if (*(int *)(iVar3 + 0xc) == 0) {
        iVar8 = 0x39;
        break;
      }
    }
    else {
      if (*(int *)(iVar3 + 0xc) != 0) goto LAB_00118368;
      iVar8 = _unp_connect(param_1,param_4);
      if (iVar8 != 0) break;
    }
    iVar4 = **(int **)(iVar3 + 0xc);
    iVar5 = *(int *)(iVar3 + 0x18);
    if (iVar5 == 0) {
      local_14 = &_sun_noname;
    }
    else {
      local_14 = (undefined4 *)(iVar5 + *(int *)(iVar5 + 4));
    }
    iVar6 = (uint)*(ushort *)(iVar4 + 0x2a) - (uint)*(ushort *)(iVar4 + 0x28);
    iVar5 = (uint)*(ushort *)(iVar4 + 0x26) - (uint)*(ushort *)(iVar4 + 0x24);
    if (iVar6 < iVar5) {
      iVar5 = iVar6;
    }
    if (iVar5 < 1) {
LAB_00118410:
      iVar8 = 0x37;
    }
    else {
      iVar5 = _sbappendaddr(iVar4 + 0x24,local_14,param_3,param_5);
      if (iVar5 == 0) goto LAB_00118410;
      _sowakeup(iVar4,iVar4 + 0x24);
      param_3 = (undefined2 *)0x0;
    }
    if (param_4 != 0) {
      _unp_disconnect(iVar3);
    }
    break;
  case 10:
    _unp_drop(iVar3,0x35);
    break;
  default:
    pcVar7 = s_piusrreq_001db3d0;
LAB_001185d1:
                    /* WARNING: Subroutine does not return */
    _panic(pcVar7);
  case 0xc:
    uVar1 = param_1[0x1f];
    *(uint *)(param_3 + 0x18) = (uint)uVar1;
    if ((*param_1 == 1) && (*(int **)(iVar3 + 0xc) != (int *)0x0)) {
      *(uint *)(param_3 + 0x18) = (uint)*(ushort *)(**(int **)(iVar3 + 0xc) + 0x24) + (uint)uVar1;
    }
    *param_3 = 0xffff;
    if (*(int *)(iVar3 + 8) == 0) {
      *(int *)(iVar3 + 8) = _unp_vno;
      _unp_vno = _unp_vno + 1;
    }
    *(undefined4 *)(param_3 + 2) = *(undefined4 *)(iVar3 + 8);
    param_3[4] = 0x11b6;
    param_3[5] = 1;
    param_3[6] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    param_3[7] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4);
    *(uint *)(param_3 + 10) = (uint)(ushort)param_1[0x12];
    _getthetime(local_c);
    *(undefined4 *)(param_3 + 0xc) = local_c[0];
    *(undefined4 *)(param_3 + 0x10) = local_c[0];
    *(undefined4 *)(param_3 + 0x14) = local_c[0];
    return 0;
  case 0xd:
    goto LAB_001185eb;
  case 0xe:
    goto switchD_00118179_caseD_e;
  case 0xf:
  case 0x13:
    break;
  case 0x10:
    if ((*(int *)(iVar3 + 0xc) == 0) || (iVar4 = *(int *)(*(int *)(iVar3 + 0xc) + 0x18), iVar4 == 0)
       ) break;
    *(undefined2 *)(param_4 + 8) = *(undefined2 *)(iVar4 + 8);
    sVar2 = *(short *)(param_4 + 8);
LAB_001185ad:
    iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + 0x18);
    _bcopy((void *)(iVar3 + *(int *)(iVar3 + 4)),(void *)(param_4 + *(int *)(param_4 + 4)),
           (int)sVar2);
    break;
  case 0x11:
    iVar8 = _unp_connect2(param_1,param_4);
  }
switchD_00118179_caseD_f:
  if (param_3 != (undefined2 *)0x0) {
    _m_freem(param_3);
  }
  return iVar8;
}

