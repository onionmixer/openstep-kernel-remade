/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012572c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _icmp_input(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  short local_c;
  
  pbVar7 = (byte *)(param_1 + *(int *)(param_1 + 4));
  uVar9 = (uint)*(short *)(pbVar7 + 2);
  uVar2 = *pbVar7 & 0xf;
  iVar3 = uVar2 * 4;
  if ((int)uVar9 < 8) {
    _DAT_001eab8c = _DAT_001eab8c + 1;
    goto LAB_00125bbc;
  }
  if (uVar9 < 0x24) {
    iVar8 = iVar3 + uVar9;
  }
  else {
    iVar8 = iVar3 + 0x24;
  }
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(short *)(param_1 + 8) < iVar8)) &&
     (param_1 = _m_pullup(param_1,iVar8), param_1 == 0)) {
    _DAT_001eab8c = _DAT_001eab8c + 1;
    return;
  }
  iVar8 = param_1 + *(int *)(param_1 + 4);
  local_c = (short)iVar3;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) - local_c;
  iVar3 = iVar3 + *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar3;
  pbVar7 = (byte *)(param_1 + iVar3);
  iVar3 = _in_cksum(param_1,uVar9);
  if (iVar3 != 0) {
    _DAT_001eab90 = _DAT_001eab90 + 1;
    goto LAB_00125bbc;
  }
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + local_c;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar2 * -4;
  if (0x12 < *pbVar7) goto switchD_00125817_caseD_0;
  *(int *)(&DAT_001eab9c + (uint)*pbVar7 * 4) = *(int *)(&DAT_001eab9c + (uint)*pbVar7 * 4) + 1;
  uVar2 = (uint)pbVar7[1];
  switch(*pbVar7) {
  default:
    goto switchD_00125817_caseD_0;
  case 3:
    if (5 < uVar2) {
LAB_0012590c:
      _DAT_001eab88 = _DAT_001eab88 + 1;
      goto switchD_00125817_caseD_0;
    }
    iVar3 = uVar2 + 8;
    break;
  case 4:
    if (uVar2 != 0) goto LAB_0012590c;
    iVar3 = 4;
    break;
  case 5:
    if ((0x23 < uVar9) && ((int)((pbVar7[8] & 0xf) * 4 + 0x10) <= (int)uVar9)) {
      _DAT_001dbd1c = *(undefined4 *)(iVar8 + 0xc);
      _DAT_001dbd0c = *(undefined4 *)(pbVar7 + 4);
      if ((uVar2 == 0) || (uVar2 == 2)) {
        uVar4 = _in_netof(*(undefined4 *)(pbVar7 + 0x18),0);
        _DAT_001dbcfc = _in_makeaddr(uVar4);
        _rtredirect(&DAT_001dbcf8,&DAT_001dbd08,2,&DAT_001dbd18);
        _DAT_001dbcfc = *(undefined4 *)(pbVar7 + 0x18);
        _pfctlinput(0xe,(sockaddr *)&DAT_001dbcf8);
      }
      else {
        _DAT_001dbcfc = *(undefined4 *)(pbVar7 + 0x18);
        _rtredirect(&DAT_001dbcf8,&DAT_001dbd08,6,&DAT_001dbd18);
        _pfctlinput(0xf,(sockaddr *)&DAT_001dbcf8);
      }
      goto switchD_00125817_caseD_0;
    }
    goto LAB_00125a32;
  case 8:
    *pbVar7 = 0;
    goto LAB_001259ed;
  case 0xb:
    if (1 < uVar2) goto LAB_0012590c;
    iVar3 = uVar2 + 0x12;
    break;
  case 0xc:
    if (uVar2 != 0) goto LAB_0012590c;
    iVar3 = 0x14;
    break;
  case 0xd:
    if (0x13 < uVar9) {
      *pbVar7 = 0xe;
      uVar4 = _iptime();
      *(undefined4 *)(pbVar7 + 0xc) = uVar4;
      *(undefined4 *)(pbVar7 + 0x10) = uVar4;
      goto LAB_001259ed;
    }
LAB_00125a32:
    _DAT_001eab94 = _DAT_001eab94 + 1;
    goto switchD_00125817_caseD_0;
  case 0xf:
    iVar3 = _in_netof(*(undefined4 *)(iVar8 + 0xc));
    if ((iVar3 == 0) && (iVar3 = _ifptoia(param_2), iVar3 != 0)) {
      uVar4 = _in_lnaof(*(undefined4 *)(iVar8 + 0xc));
      uVar4 = _in_netof(*(undefined4 *)(iVar3 + 4),uVar4);
      uVar4 = _in_makeaddr(uVar4);
      *(undefined4 *)(iVar8 + 0xc) = uVar4;
    }
    *pbVar7 = 0x10;
LAB_001259ed:
    *(short *)(iVar8 + 2) = *(short *)(iVar8 + 2) + local_c;
    _DAT_001eab98 = _DAT_001eab98 + 1;
    *(int *)(&DAT_001eab3c + (uint)*pbVar7 * 4) = *(int *)(&DAT_001eab3c + (uint)*pbVar7 * 4) + 1;
    _icmp_reflect(iVar8,param_2);
    return;
  case 0x11:
    if (((0xb < (int)uVar9) && (iVar3 = _ifptoia(param_2), iVar3 != 0)) &&
       ((*(byte *)(iVar3 + 0x3c) & 2) != 0)) {
      *pbVar7 = 0x12;
      uVar2 = *(uint *)(iVar3 + 0x34);
      *(uint *)(pbVar7 + 8) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      if (*(int *)(iVar8 + 0xc) == 0) {
        uVar1 = *(ushort *)(*(int *)(iVar3 + 0x20) + 0xc);
        if ((uVar1 & 2) == 0) {
          if ((uVar1 & 0x10) != 0) {
            *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(iVar3 + 0x14);
          }
        }
        else {
          *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(iVar3 + 0x14);
        }
      }
      goto LAB_001259ed;
    }
    goto switchD_00125817_caseD_0;
  case 0x12:
    iVar3 = _ifptoia(param_2);
    if ((iVar3 != 0) && ((*(uint *)(iVar3 + 0x3c) & 4) != 0)) {
      uVar2 = *(uint *)(pbVar7 + 8);
      if ((((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18) !=
            0xffffffff) &&
          ((uVar2 << 0x18 == 0xff000000 &&
           (*(uint *)(iVar3 + 0x3c) = *(uint *)(iVar3 + 0x3c) & 0xfffffffb,
           (*(byte *)(param_2 + 3) & 8) == 0)))) &&
         (uVar2 = *(uint *)(pbVar7 + 8),
         *(uint *)(iVar3 + 0x34) !=
         (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18 |
         *(uint *)(iVar3 + 0x34)))) {
        *(uint *)(iVar3 + 0x34) =
             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
        iVar5 = _in_ifinit(param_2,iVar3,iVar3);
        if (iVar5 == 0) {
          pcVar6 = _inet_ntoa((in_addr)(iVar8 + 0xc));
          _printf(s__s_d__setting_netmask_to__x__rec_001dbd4b,*param_2,(int)*(short *)(param_2 + 2),
                  *(undefined4 *)(iVar3 + 0x34),pcVar6);
          _wakeup(iVar3 + 0x34);
        }
        else {
          _printf(s_icmp_input__can_t_set_new_netmas_001dbd28);
        }
      }
    }
    goto switchD_00125817_caseD_0;
  }
  *(ushort *)(pbVar7 + 10) = *(ushort *)(pbVar7 + 10) >> 8 | *(ushort *)(pbVar7 + 10) << 8;
  if ((uVar9 < 0x24) || ((int)uVar9 < (int)((pbVar7[8] & 0xf) * 4 + 0x10))) {
    _DAT_001eab94 = _DAT_001eab94 + 1;
LAB_00125bbc:
    _m_freem(param_1);
    return;
  }
  _DAT_001dbcfc = *(undefined4 *)(pbVar7 + 0x18);
  if (*(code **)(&DAT_001dbb78 + (uint)(byte)(&_ip_protox)[pbVar7[0x11]] * 0x30) != (code *)0x0) {
    (**(code **)(&DAT_001dbb78 + (uint)(byte)(&_ip_protox)[pbVar7[0x11]] * 0x30))
              (iVar3,&DAT_001dbcf8,pbVar7 + 8);
  }
switchD_00125817_caseD_0:
  _DAT_001dbcfc = *(undefined4 *)(iVar8 + 0xc);
  _DAT_001dbd0c = *(undefined4 *)(iVar8 + 0x10);
  _raw_input(param_1,&DAT_001dbcf4,&DAT_001dbcf8,&DAT_001dbd08);
  return;
}

