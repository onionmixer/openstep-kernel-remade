/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012bc40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _igmp_input(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  byte *pbVar8;
  uint *puVar9;
  int iVar10;
  char *pcVar11;
  short local_14;
  
  __igmpstat = __igmpstat + 1;
  pbVar8 = (byte *)(param_1 + *(uint *)(param_1 + 4));
  uVar4 = *pbVar8 & 0xf;
  iVar5 = uVar4 * 4;
  iVar10 = (int)*(short *)(pbVar8 + 2);
  if (iVar10 < 8) {
    _DAT_001eee74 = _DAT_001eee74 + 1;
    _m_freem(param_1);
    return;
  }
  if (((0x7c < *(uint *)(param_1 + 4)) || ((int)*(short *)(param_1 + 8) < iVar5 + 8)) &&
     (param_1 = _m_pullup(param_1,iVar5 + 8), param_1 == 0)) {
    _DAT_001eee74 = _DAT_001eee74 + 1;
    return;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar5;
  local_14 = (short)iVar5;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) - local_14;
  pcVar11 = (char *)(param_1 + *(int *)(param_1 + 4));
  iVar5 = _in_cksum(param_1,iVar10);
  if (iVar5 == 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar4 * -4;
    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + local_14;
    iVar5 = param_1 + *(int *)(param_1 + 4);
    if (*pcVar11 == '\x11') {
      _DAT_001eee7c = _DAT_001eee7c + 1;
      if (_loifp != param_2) {
        if (*(uint *)(iVar5 + 0x10) != DAT_001e59ac) {
          _DAT_001eee80 = _DAT_001eee80 + 1;
          goto LAB_0012be3d;
        }
        puVar9 = (uint *)0x0;
        puVar6 = (uint *)0x0;
        iVar10 = _in_ifaddr;
        do {
          iVar2 = 0;
          if (iVar10 == 0) goto joined_r0x0012bd88;
          puVar6 = *(uint **)(iVar10 + 0x44);
          iVar10 = *(int *)(iVar10 + 0x40);
        } while (puVar6 == (uint *)0x0);
        puVar9 = (uint *)puVar6[5];
        iVar2 = iVar10;
joined_r0x0012bd88:
        if (puVar6 != (uint *)0x0) {
          iVar10 = iVar2;
          puVar3 = puVar9;
          if (((puVar6[1] == param_2) && (puVar6[4] == 0)) &&
             (uVar4 = *puVar6, DAT_001e59ac != uVar4)) {
            uVar1 = *(uint *)(_in_ifaddr + 4);
            puVar6[4] = ((uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                         uVar1 << 0x18) + __ipstat +
                        (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
                        uVar4 << 0x18)) % 0x32 + 1;
            DAT_001dbf44 = 1;
          }
          while (puVar6 = puVar3, puVar6 == (uint *)0x0) {
            iVar2 = 0;
            if (iVar10 == 0) goto joined_r0x0012bd88;
            puVar6 = (uint *)(iVar10 + 0x44);
            iVar10 = *(int *)(iVar10 + 0x40);
            puVar3 = (uint *)*puVar6;
          }
          puVar9 = (uint *)puVar6[5];
          iVar2 = iVar10;
          goto joined_r0x0012bd88;
        }
      }
    }
    else if ((*pcVar11 == '\x12') && (_DAT_001eee84 = _DAT_001eee84 + 1, _loifp != param_2)) {
      if (((*(uint *)(pcVar11 + 4) & 0xf0) != 0xe0) ||
         (*(uint *)(iVar5 + 0x10) != *(uint *)(pcVar11 + 4))) {
        _DAT_001eee88 = _DAT_001eee88 + 1;
        goto LAB_0012be3d;
      }
      if (((*(uint *)(iVar5 + 0xc) & 0xff) == 0) && (iVar10 = _in_ifaddr, _in_ifaddr != 0)) {
        do {
          if (*(uint *)(iVar10 + 0x20) == param_2) break;
          iVar10 = *(int *)(iVar10 + 0x40);
        } while (iVar10 != 0);
        if (iVar10 != 0) {
          uVar4 = *(uint *)(iVar10 + 0x30);
          *(uint *)(iVar5 + 0xc) =
               uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        }
      }
      iVar10 = _in_ifaddr;
      if (_in_ifaddr != 0) {
        do {
          if (*(uint *)(iVar10 + 0x20) == param_2) break;
          iVar10 = *(int *)(iVar10 + 0x40);
        } while (iVar10 != 0);
        if ((iVar10 != 0) && (piVar7 = *(int **)(iVar10 + 0x44), piVar7 != (int *)0x0)) {
          do {
            if (*piVar7 == *(int *)(pcVar11 + 4)) break;
            piVar7 = (int *)piVar7[5];
          } while (piVar7 != (int *)0x0);
          if (piVar7 != (int *)0x0) {
            piVar7[4] = 0;
            _DAT_001eee8c = _DAT_001eee8c + 1;
          }
        }
      }
    }
    _DAT_001dbf28 = *(undefined4 *)(iVar5 + 0xc);
    _DAT_001dbf38 = *(undefined4 *)(iVar5 + 0x10);
    _raw_input(param_1,&DAT_001dbf20,&DAT_001dbf24,&DAT_001dbf34);
  }
  else {
    _DAT_001eee78 = _DAT_001eee78 + 1;
LAB_0012be3d:
    _m_freem(param_1);
  }
  return;
}

