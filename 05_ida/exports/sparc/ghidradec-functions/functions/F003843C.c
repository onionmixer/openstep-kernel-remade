
/* WARNING: Removing unreachable block (ram,0xf0038714) */
/* WARNING: Removing unreachable block (ram,0xf00386a8) */
/* WARNING: Removing unreachable block (ram,0xf0038694) */
/* WARNING: Removing unreachable block (ram,0xf00388a0) */
/* WARNING: Removing unreachable block (ram,0xf0038844) */
/* WARNING: Removing unreachable block (ram,0xf0038748) */
/* WARNING: Removing unreachable block (ram,0xf0038544) */
/* WARNING: Removing unreachable block (ram,0xf00384a4) */
/* WARNING: Removing unreachable block (ram,0xf00384e0) */
/* WARNING: Removing unreachable block (ram,0xf0038598) */
/* WARNING: Removing unreachable block (ram,0xf00387f8) */
/* WARNING: Removing unreachable block (ram,0xf0038888) */
/* WARNING: Removing unreachable block (ram,0xf0038670) */
/* WARNING: Removing unreachable block (ram,0xf00386b8) */
/* WARNING: Removing unreachable block (ram,0xf0038700) */
/* WARNING: Removing unreachable block (ram,0xf00388b0) */
/* WARNING: Removing unreachable block (ram,0xf0038460) */

undefined8 _udp_input(uint param_1,uint param_2)

{
  sword sVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 *puVar8;
  undefined4 *puVar9;
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
  if ((*(uint *)(param_1 + 4) < 0x7d) && (0x1b < *(word *)(param_1 + 8))) {
    iVar3 = *(int *)(param_1 + 4);
  }
  else {
    _m_pullup(param_1,0x1c);
    if (param_1 == 0) {
      _udpstat = _udpstat + 1;
      goto locret_F00388B8;
    }
    iVar3 = *(int *)(param_1 + 4);
  }
  puVar9 = (undefined4 *)(param_1 + iVar3);
  if (5 < (*(byte *)(param_1 + iVar3) & 0xf)) {
    _ip_stripoptions(puVar9,0);
  }
  uVar5 = (uint)*(word *)(puVar9 + 6);
  uVar4 = (uint)*(sword *)((int)puVar9 + 2);
  if (uVar4 == uVar5) {
loc_F00384E8:
    *(undefined4 *)((int)register0x00000038 + -0x20) = *puVar9;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = puVar9[1];
    *(undefined4 *)((int)register0x00000038 + -0x18) = puVar9[2];
    *(undefined4 *)((int)register0x00000038 + -0x14) = puVar9[3];
    *(undefined4 *)((int)register0x00000038 + -0x10) = puVar9[4];
    if ((_udpcksum != 0) && (*(sword *)((int)puVar9 + 0x1a) != 0)) {
      puVar9[1] = 0;
      *puVar9 = 0;
      *(undefined *)(puVar9 + 2) = 0;
      *(undefined2 *)((int)puVar9 + 10) = *(undefined2 *)(puVar9 + 6);
      uVar4 = param_1;
      _in_cksum(param_1,uVar5 + 0x14);
      *(sword *)((int)puVar9 + 0x1a) = (sword)uVar4;
      if ((uVar4 & 0xffff) != 0) {
        DAT_f0136544._0_4_ = DAT_f0136544._0_4_ + 1;
        goto loc_F00388B0;
      }
    }
    if ((puVar9[4] & 0xf0000000) != 0xe0000000) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = puVar9[4];
      puVar2 = (undefined *)((int)register0x00000038 + -0x24);
      _in_broadcast();
      if (puVar2 == (undefined *)0x0) {
        puVar8 = &_udb;
        *(undefined4 *)((int)register0x00000038 + -0x28) = puVar9[3];
        *(undefined4 *)((int)register0x00000038 + -0x2c) = puVar9[4];
        _in_pcblookup(&_udb,(undefined *)((int)register0x00000038 + -0x28),
                      *(undefined2 *)(puVar9 + 5),(undefined *)((int)register0x00000038 + -0x2c),
                      *(undefined2 *)((int)puVar9 + 0x16),1);
        if (puVar8 == (undefined4 *)0x0) {
          if (_in_ifaddr != 0) {
            iVar7 = *(int *)(_in_ifaddr + 0x20);
            iVar3 = _in_ifaddr;
            while( true ) {
              if ((*(word *)(iVar7 + 0xc) & 2) == 0) {
                iVar3 = *(int *)(iVar3 + 0x40);
              }
              else {
                uVar4 = *(uint *)(iVar3 + 0x28) ^ puVar9[4];
                if ((((uVar4 == ~*(uint *)(iVar3 + 0x2c)) || (uVar4 == 0)) ||
                    (uVar4 = *(uint *)(iVar3 + 0x30) ^ puVar9[4], uVar4 == ~*(uint *)(iVar3 + 0x34))
                    ) || (uVar4 == 0)) goto loc_F00388B0;
                iVar3 = *(int *)(iVar3 + 0x40);
              }
              if (iVar3 == 0) break;
              iVar7 = *(int *)(iVar3 + 0x20);
            }
          }
          iVar3 = puVar9[4];
          if ((iVar3 != -1) && (iVar3 != 0)) {
            *(int *)((int)register0x00000038 + -0x2c) = iVar3;
            puVar2 = (undefined *)((int)register0x00000038 + -0x2c);
            _in_broadcast();
            if (puVar2 == (undefined *)0x0) {
              *puVar9 = *(undefined4 *)((int)register0x00000038 + -0x20);
              puVar9[1] = *(undefined4 *)((int)register0x00000038 + -0x1c);
              puVar9[2] = *(undefined4 *)((int)register0x00000038 + -0x18);
              puVar9[3] = *(undefined4 *)((int)register0x00000038 + -0x14);
              puVar9[4] = *(undefined4 *)((int)register0x00000038 + -0x10);
              _icmp_error(puVar9,3,3,param_2,0);
              goto locret_F00388B8;
            }
          }
        }
        else {
          DAT_f010c97a._0_2_ = *(undefined2 *)(puVar9 + 5);
          DAT_f010c97a._2_4_ = puVar9[3];
          *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
          iVar3 = puVar8[7] + 0x24;
          _sbappendaddr(iVar3,_udp_in,param_1,0);
          if (iVar3 != 0) {
            _sowakeup(puVar8[7],puVar8[7] + 0x24);
            goto locret_F00388B8;
          }
        }
        goto loc_F00388B0;
      }
    }
    DAT_f010c97a._0_2_ = *(undefined2 *)(puVar9 + 5);
    DAT_f010c97a._2_4_ = puVar9[3];
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
    iVar3 = 0;
    if ((undefined4 **)_udb != &_udb) {
      sVar1 = *(sword *)(_udb + 6);
      puVar8 = _udb;
      do {
        if (sVar1 == *(sword *)((int)puVar9 + 0x16)) {
          if (puVar8[5] == 0) {
            iVar7 = puVar8[3];
          }
          else {
            if (puVar8[5] != puVar9[4]) {
              puVar8 = (undefined4 *)*puVar8;
              goto loc_F00386D8;
            }
            iVar7 = puVar8[3];
          }
          if (iVar7 == 0) {
loc_F0038660:
            if ((iVar3 == 0) || (param_2 = param_1, _m_copy(param_1,0,1000000000), param_2 == 0)) {
loc_F00386C0:
              iVar3 = puVar8[7];
            }
            else {
              iVar6 = iVar3 + 0x24;
              iVar7 = iVar6;
              _sbappendaddr(iVar6,_udp_in,param_2,0);
              if (iVar7 != 0) {
                _sowakeup(iVar3,iVar6);
                goto loc_F00386C0;
              }
              _m_freem(param_2);
              iVar3 = puVar8[7];
            }
            if ((*(word *)(iVar3 + 2) & 4) == 0) break;
            puVar8 = (undefined4 *)*puVar8;
          }
          else if (iVar7 == puVar9[3]) {
            if (*(sword *)(puVar8 + 4) == *(sword *)(puVar9 + 5)) goto loc_F0038660;
            puVar8 = (undefined4 *)*puVar8;
          }
          else {
            puVar8 = (undefined4 *)*puVar8;
          }
        }
        else {
          puVar8 = (undefined4 *)*puVar8;
        }
loc_F00386D8:
        if ((undefined4 **)puVar8 == &_udb) break;
        sVar1 = *(sword *)(puVar8 + 6);
      } while( true );
    }
    iVar7 = iVar3 + 0x24;
    if ((iVar3 != 0) && (iVar6 = iVar7, _sbappendaddr(iVar7,_udp_in,param_1,0), iVar6 != 0)) {
      _sowakeup(iVar3,iVar7);
      goto locret_F00388B8;
    }
  }
  else {
    if ((int)uVar5 <= (int)uVar4) {
      _m_adj(param_1,uVar5 - uVar4);
      goto loc_F00384E8;
    }
    DAT_f0136544._4_4_ = DAT_f0136544._4_4_ + 1;
  }
loc_F00388B0:
  _m_freem(param_1);
locret_F00388B8:
  return CONCAT44(param_2,param_1);
}

