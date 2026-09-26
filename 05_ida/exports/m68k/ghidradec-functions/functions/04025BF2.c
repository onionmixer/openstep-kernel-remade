
void _igmp_input(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  
  _igmpstat = _igmpstat + 1;
  pbVar1 = (byte *)(param_1 + *(uint *)(param_1 + 4));
  uVar5 = *pbVar1 & 0xf;
  iVar9 = uVar5 * 4;
  iVar8 = (int)*(sword *)(pbVar1 + 2);
  if (iVar8 < 8) {
    dword_40BBE20 = dword_40BBE20 + 1;
  }
  else {
    if (((0x7c < *(uint *)(param_1 + 4)) || ((int)*(sword *)(param_1 + 8) < iVar9 + 8)) &&
       (param_1 = _m_pullup(param_1,iVar9 + 8), param_1 == 0)) {
      dword_40BBE20 = dword_40BBE20 + 1;
      return;
    }
    *(int *)(param_1 + 4) = iVar9 + *(int *)(param_1 + 4);
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - (sword)iVar9;
    pcVar4 = (char *)(*(int *)(param_1 + 4) + param_1);
    iVar8 = _in_cksum(param_1,iVar8);
    if (iVar8 == 0) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar5 * -4;
      *(sword *)(param_1 + 8) = (sword)iVar9 + *(sword *)(param_1 + 8);
      iVar8 = _in_ifaddr;
      iVar9 = dword_40B3528;
      iVar12 = *(int *)(param_1 + 4) + param_1;
      if (*pcVar4 == '\x11') {
        dword_40BBE28 = dword_40BBE28 + 1;
        if (param_2 != _loifp) {
          if (*(int *)(iVar12 + 0x10) != dword_40B3528) {
            dword_40BBE2C = dword_40BBE2C + 1;
            goto loc_4025DC8;
          }
          piVar11 = (int *)0x0;
          piVar10 = (int *)0x0;
          iVar3 = _in_ifaddr;
          do {
            iVar6 = 0;
            if (iVar3 == 0) goto joined_r0x04025d06;
            piVar10 = *(int **)(iVar3 + 0x44);
            iVar3 = *(int *)(iVar3 + 0x40);
          } while (piVar10 == (int *)0x0);
          piVar11 = (int *)piVar10[5];
          iVar6 = iVar3;
joined_r0x04025d06:
          if (piVar10 != (int *)0x0) {
            iVar3 = iVar6;
            piVar7 = piVar11;
            if (((param_2 == piVar10[1]) && (piVar10[4] == 0)) && (iVar9 != *piVar10)) {
              piVar10[4] = (uint)(*piVar10 + *(int *)(iVar8 + 4) + _ipstat) % 0x32 + 1;
              dword_40AEC04 = 1;
            }
            while (piVar10 = piVar7, piVar10 == (int *)0x0) {
              iVar6 = 0;
              if (iVar3 == 0) goto joined_r0x04025d06;
              puVar2 = (undefined4 *)(iVar3 + 0x44);
              iVar3 = *(int *)(iVar3 + 0x40);
              piVar7 = (int *)*puVar2;
            }
            piVar11 = (int *)piVar10[5];
            iVar6 = iVar3;
            goto joined_r0x04025d06;
          }
        }
      }
      else if ((*pcVar4 == '\x12') && (dword_40BBE30 = dword_40BBE30 + 1, param_2 != _loifp)) {
        if (((*(uint *)(pcVar4 + 4) & 0xf0000000) != 0xe0000000) ||
           (*(uint *)(pcVar4 + 4) != *(uint *)(iVar12 + 0x10))) {
          dword_40BBE34 = dword_40BBE34 + 1;
          goto loc_4025DC8;
        }
        if (((*(uint *)(iVar12 + 0xc) & 0xff000000) == 0) && (iVar9 = _in_ifaddr, _in_ifaddr != 0))
        {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if (iVar9 != 0) {
            *(undefined4 *)(iVar12 + 0xc) = *(undefined4 *)(iVar9 + 0x30);
          }
        }
        iVar9 = _in_ifaddr;
        if (_in_ifaddr != 0) {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if ((iVar9 != 0) && (piVar11 = *(int **)(iVar9 + 0x44), piVar11 != (int *)0x0)) {
            do {
              if (*(int *)(pcVar4 + 4) == *piVar11) break;
              piVar11 = (int *)piVar11[5];
            } while (piVar11 != (int *)0x0);
            if (piVar11 != (int *)0x0) {
              piVar11[4] = 0;
              dword_40BBE38 = dword_40BBE38 + 1;
            }
          }
        }
      }
      unk_40AEBE8._0_4_ = *(undefined4 *)(iVar12 + 0xc);
      unk_40AEBF8._0_4_ = *(undefined4 *)(iVar12 + 0x10);
      _raw_input(param_1,&unk_40AEBE0,0x40aebe4,0x40aebf4);
      return;
    }
    dword_40BBE24 = dword_40BBE24 + 1;
  }
loc_4025DC8:
  _m_freem(param_1);
  return;
}
