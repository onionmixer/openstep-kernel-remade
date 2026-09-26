/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122d1c */

undefined4 _arpioctl(int param_1,short *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint *puVar11;
  undefined4 *local_2c;
  int local_28;
  uint local_24;
  
  iVar7 = 0;
  if ((*param_2 != 2) || (param_2[8] != 0)) {
    return 0x2f;
  }
  uVar2 = _splimp();
  puVar10 = (uint *)(&_arptab + (*(uint *)(param_2 + 2) % 0x13) * 0xb4);
  iVar3 = 0;
  do {
    if (*puVar10 == *(uint *)(param_2 + 2)) break;
    iVar3 = iVar3 + 1;
    puVar10 = puVar10 + 5;
  } while (iVar3 < 9);
  if (8 < iVar3) {
    puVar10 = (uint *)0x0;
  }
  if (puVar10 == (uint *)0x0) {
    if (param_1 != -0x7fdb96e2) {
      _splx(uVar2);
      return 6;
    }
    iVar7 = _ifa_ifwithnet(param_2);
    if (iVar7 == 0) {
      _splx(uVar2);
      return 0x33;
    }
  }
  if (param_1 == -0x7fdb96e0) {
    uVar4 = _splimp();
    if (puVar10[3] != 0) {
      _m_freem(puVar10[3]);
    }
    puVar10[3] = 0;
    *(undefined1 *)((int)puVar10 + 0xb) = 0;
    *(undefined1 *)((int)puVar10 + 10) = 0;
    *puVar10 = 0;
    _splx(uVar4);
  }
  else if (param_1 < -0x7fdb96df) {
    if (param_1 == -0x7fdb96e2) {
      if (puVar10 == (uint *)0x0) {
        uVar1 = *(uint *)(iVar7 + 0x20);
        local_2c = (undefined4 *)0xffffffff;
        if (DAT_001dba20 != 0) {
          DAT_001dba20 = 0;
          _timeout(0x1220b4);
        }
        puVar5 = (uint *)(&_arptab + (*(uint *)(param_2 + 2) % 0x13) * 0xb4);
        local_28 = 0;
        puVar8 = puVar5;
        puVar11 = (uint *)0x0;
        do {
          puVar10 = puVar8;
          if (*(byte *)((int)puVar5 + 0xb) == 0) goto LAB_00122ee7;
          puVar10 = puVar11;
          if (((*(byte *)((int)puVar5 + 0xb) & 4) == 0) &&
             ((puVar11 == (uint *)0x0 || ((int)local_2c < (int)(uint)*(byte *)((int)puVar5 + 10)))))
          {
            local_2c = (undefined4 *)(uint)*(byte *)((int)puVar5 + 10);
            puVar10 = puVar5;
          }
          local_28 = local_28 + 1;
          puVar5 = puVar5 + 5;
          puVar8 = puVar8 + 5;
          puVar11 = puVar10;
        } while (local_28 < 9);
        if (puVar10 == (uint *)0x0) {
LAB_00122efe:
          _splx(uVar2);
          return 0x31;
        }
        uVar4 = _splimp();
        if (puVar10[3] != 0) {
          _m_freem(puVar10[3]);
        }
        puVar10[3] = 0;
        *(undefined1 *)((int)puVar10 + 0xb) = 0;
        *(undefined1 *)((int)puVar10 + 10) = 0;
        *puVar10 = 0;
        _splx(uVar4);
LAB_00122ee7:
        *puVar10 = *(uint *)(param_2 + 2);
        *(undefined1 *)((int)puVar10 + 0xb) = 1;
        puVar10[4] = uVar1;
        if (puVar10 == (uint *)0x0) goto LAB_00122efe;
        if ((*(byte *)(param_2 + 0x10) & 4) != 0) {
          local_24 = 0xffffffff;
          local_2c = (undefined4 *)0x0;
          if (DAT_001dba20 != 0) {
            DAT_001dba20 = 0;
            _timeout(0x1220b4);
          }
          puVar6 = (undefined4 *)(&_arptab + (*(uint *)(param_2 + 2) % 0x13) * 0xb4);
          local_28 = 0;
          puVar9 = puVar6;
          do {
            if (*(byte *)((int)puVar6 + 0xb) == 0) goto LAB_00123005;
            if (((*(byte *)((int)puVar6 + 0xb) & 4) == 0) &&
               ((local_2c == (undefined4 *)0x0 ||
                ((int)local_24 < (int)(uint)*(byte *)((int)puVar6 + 10))))) {
              local_24 = (uint)*(byte *)((int)puVar6 + 10);
              local_2c = puVar6;
            }
            local_28 = local_28 + 1;
            puVar6 = puVar6 + 5;
            puVar9 = puVar9 + 5;
          } while (local_28 < 9);
          if (local_2c == (undefined4 *)0x0) {
LAB_0012301a:
            uVar4 = _splimp();
            if (puVar10[3] != 0) {
              _m_freem(puVar10[3]);
            }
            puVar10[3] = 0;
            *(undefined1 *)((int)puVar10 + 0xb) = 0;
            *(undefined1 *)((int)puVar10 + 10) = 0;
            *puVar10 = 0;
            _splx(uVar4);
            _splx(uVar2);
            return 0x31;
          }
          uVar4 = _splimp();
          if (local_2c[3] != 0) {
            _m_freem(local_2c[3]);
          }
          local_2c[3] = 0;
          *(undefined1 *)((int)local_2c + 0xb) = 0;
          *(undefined1 *)((int)local_2c + 10) = 0;
          *local_2c = 0;
          _splx(uVar4);
          puVar9 = local_2c;
LAB_00123005:
          *puVar9 = *(undefined4 *)(param_2 + 2);
          *(undefined1 *)((int)puVar9 + 0xb) = 1;
          puVar9[4] = uVar1;
          if (puVar9 == (undefined4 *)0x0) goto LAB_0012301a;
          uVar4 = _splimp();
          if (puVar9[3] != 0) {
            _m_freem(puVar9[3]);
          }
          puVar9[3] = 0;
          *(undefined1 *)((int)puVar9 + 0xb) = 0;
          *(undefined1 *)((int)puVar9 + 10) = 0;
          *puVar9 = 0;
          _splx(uVar4);
        }
      }
      _bcopy(param_2 + 9,puVar10 + 1,6);
      *(byte *)((int)puVar10 + 0xb) = *(byte *)(param_2 + 0x10) & 0x1c | 3;
      *(undefined1 *)((int)puVar10 + 10) = 0;
    }
  }
  else if (param_1 == -0x3fdb96e1) {
    _bcopy(puVar10 + 1,param_2 + 9,6);
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)((int)puVar10 + 0xb);
  }
  _splx(uVar2);
  return 0;
}

