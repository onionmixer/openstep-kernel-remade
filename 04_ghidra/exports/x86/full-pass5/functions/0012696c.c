/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012696c */

undefined4 _ip_dooptions(byte *param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 local_14;
  uint local_c;
  undefined4 local_8;
  
  local_14 = 0xc;
  pbVar9 = param_1 + 0x14;
  iVar1 = (*param_1 & 0xf) * 4 + -0x14;
  do {
    if ((iVar1 < 1) || (bVar3 = *pbVar9, bVar3 == 0)) {
      return 0;
    }
    if (bVar3 != 1) {
      local_c = (uint)pbVar9[1];
      if ((local_c != 0) && ((int)local_c <= iVar1)) goto LAB_001269d4;
      pbVar6 = param_1 + -1;
LAB_00126c72:
      iVar5 = (int)pbVar9 - (int)pbVar6;
      goto LAB_00126c76;
    }
    local_c = 1;
LAB_001269d4:
    if (bVar3 == 0x44) {
      iVar5 = (int)pbVar9 - (int)param_1;
      if (pbVar9[1] < 5) goto LAB_00126c76;
      uVar7 = (uint)pbVar9[2];
      uVar8 = (uint)pbVar9[1];
      if (uVar8 - 4 < uVar7) {
        bVar3 = (pbVar9[3] >> 4) + 1;
        pbVar9[3] = pbVar9[3] & 0xf | bVar3 * '\x10';
        if ((bVar3 & 0xf) == 0) goto LAB_00126c76;
      }
      else {
        bVar3 = pbVar9[3];
        if ((bVar3 & 0xf) == 1) {
          if (uVar8 < uVar7 + 8) goto LAB_00126c76;
          iVar5 = _ifptoia(param_2);
          _bcopy((void *)(iVar5 + 4),pbVar9 + (uVar7 - 1),4);
          pbVar9[2] = pbVar9[2] + 4;
        }
        else if ((bVar3 & 0xf) == 0) {
          if ((bVar3 & 0xf) != 0) goto LAB_00126c76;
        }
        else {
          if (((bVar3 & 0xf) != 2) || (uVar8 < uVar7 + 8)) goto LAB_00126c76;
          _bcopy(pbVar9 + (uVar7 - 1),&DAT_001dbd94,4);
          iVar5 = _ifa_ifwithaddr(&_ipaddr);
          if (iVar5 == 0) goto LAB_00126c43;
          pbVar9[2] = pbVar9[2] + 4;
        }
        local_8 = _iptime();
        _bcopy(&local_8,pbVar9 + (pbVar9[2] - 1),4);
        pbVar9[2] = pbVar9[2] + 4;
      }
    }
    else if (bVar3 < 0x45) {
      if (bVar3 == 7) {
        if (pbVar9[2] < 4) {
LAB_00126c6c:
          pbVar6 = param_1 + -2;
          goto LAB_00126c72;
        }
        uVar8 = pbVar9[2] - 1;
        if (uVar8 <= local_c - 4) {
          _bcopy(param_1 + 0x10,&DAT_001dbd94,4);
          iVar5 = _ip_rtaddr(DAT_001dbd94);
          if (iVar5 == 0) {
            local_14 = 3;
            iVar5 = 1;
            goto LAB_00126c76;
          }
          _bcopy((void *)(iVar5 + 4),pbVar9 + uVar8,4);
          pbVar9[2] = pbVar9[2] + 4;
        }
      }
    }
    else if ((bVar3 == 0x83) || (bVar3 == 0x89)) {
      bVar2 = pbVar9[2];
      if (bVar2 < 4) goto LAB_00126c6c;
      DAT_001dbd94 = *(undefined4 *)(param_1 + 0x10);
      iVar5 = _ifa_ifwithaddr(&_ipaddr);
      if (iVar5 == 0) {
        if (bVar3 == 0x89) {
LAB_00126aad:
          local_14 = 3;
          iVar5 = 5;
LAB_00126c76:
          _icmp_error(param_1,local_14,iVar5,param_2,0);
          return 1;
        }
      }
      else {
        uVar8 = bVar2 - 1;
        if (local_c - 4 < uVar8) {
          _save_rte(pbVar9,*(undefined4 *)(param_1 + 0xc));
        }
        else {
          _bcopy(pbVar9 + uVar8,&DAT_001dbd94,4);
          if (bVar3 == 0x89) {
            uVar4 = _in_netof(DAT_001dbd94);
            iVar5 = _in_iaonnetof(uVar4);
            if (iVar5 == 0) goto LAB_00126aad;
          }
          iVar5 = _ip_rtaddr(DAT_001dbd94);
          if (iVar5 == 0) goto LAB_00126aad;
          *(undefined4 *)(param_1 + 0x10) = DAT_001dbd94;
          _bcopy((void *)(iVar5 + 4),pbVar9 + uVar8,4);
          pbVar9[2] = pbVar9[2] + 4;
        }
      }
    }
LAB_00126c43:
    iVar1 = iVar1 - local_c;
    pbVar9 = pbVar9 + local_c;
  } while( true );
}

