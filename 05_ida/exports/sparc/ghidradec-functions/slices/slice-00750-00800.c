/* GHIDRADEC_FUNCTION index=750 start=0xf00328c4 */

/* WARNING: Removing unreachable block (ram,0xf003292c) */
/* WARNING: Removing unreachable block (ram,0xf0032944) */
/* WARNING: Removing unreachable block (ram,0xf00328c8) */

undefined8 _ip_slowtimo(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  _splnet();
  if ((_ipq != (undefined4 *)0x0) && ((undefined4 **)_ipq != &_ipq)) {
    cVar1 = *(char *)(_ipq + 2);
    puVar2 = _ipq;
    while( true ) {
      *(char *)(puVar2 + 2) = cVar1 + -1;
      puVar2 = (undefined4 *)*puVar2;
      if (*(char *)(puVar2[1] + 8) == '\0') {
        iRamf01364f0 = iRamf01364f0 + 1;
        _ip_freef(puVar2[1]);
      }
      if ((undefined4 **)puVar2 == &_ipq) break;
      cVar1 = *(char *)(puVar2 + 2);
    }
  }
  _splx();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=751 start=0xf0032954 */

/* WARNING: Removing unreachable block (ram,0xf0032988) */

undefined8 _ip_drain(undefined4 param_1,undefined4 param_2)

{
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
  if ((undefined4 **)_ipq != &_ipq) {
    do {
      iRamf01364ec = iRamf01364ec + 1;
      _ip_freef(_ipq);
    } while ((undefined4 **)_ipq != &_ipq);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=752 start=0xf00329a8 */

/* WARNING: Removing unreachable block (ram,0xf0032d00) */
/* WARNING: Removing unreachable block (ram,0xf0032b54) */
/* WARNING: Removing unreachable block (ram,0xf0032afc) */
/* WARNING: Removing unreachable block (ram,0xf0032ad8) */
/* WARNING: Removing unreachable block (ram,0xf0032a64) */
/* WARNING: Removing unreachable block (ram,0xf0032c98) */
/* WARNING: Removing unreachable block (ram,0xf0032c70) */
/* WARNING: Removing unreachable block (ram,0xf0032c50) */
/* WARNING: Removing unreachable block (ram,0xf0032c78) */
/* WARNING: Removing unreachable block (ram,0xf0032cb4) */
/* WARNING: Removing unreachable block (ram,0xf0032ac0) */
/* WARNING: Removing unreachable block (ram,0xf0032ae0) */
/* WARNING: Removing unreachable block (ram,0xf0032aa4) */
/* WARNING: Removing unreachable block (ram,0xf0032b64) */
/* WARNING: Removing unreachable block (ram,0xf0032b80) */
/* WARNING: Removing unreachable block (ram,0xf0032c40) */

undefined8 _ip_dooptions(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint uVar8;
  undefined4 unaff_l1;
  uint *puVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 uVar12;
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
  uVar12 = 0xc;
  iVar11 = (*param_1 & 0xf) * 4 + -0x14;
  puVar9 = (uint *)(param_1 + 0x14);
  if (0 < iVar11) {
    do {
      bVar1 = *(byte *)puVar9;
      if (bVar1 == 0) break;
      if (bVar1 != 1) {
        uVar10 = (uint)*(byte *)((int)puVar9 + 1);
        if ((uVar10 != 0) && ((int)uVar10 <= iVar11)) goto loc_F0032A1C;
        pbVar3 = param_1 + -1;
loc_F0032CEC:
        iVar7 = (int)puVar9 - (int)pbVar3;
loc_F0032CF4:
        _icmp_error(param_1,uVar12,iVar7,param_2,0);
        uVar12 = 1;
        goto locret_F0032D0C;
      }
      uVar10 = 1;
loc_F0032A1C:
      if (bVar1 == 0x44) {
        uVar8 = (uint)*(byte *)((int)puVar9 + 1);
        iVar7 = (int)puVar9 - (int)param_1;
        if (4 < uVar8) {
          uVar6 = (uint)*(byte *)((int)puVar9 + 2);
          uVar5 = *puVar9;
          if (uVar8 - 4 < uVar6) {
            uVar8 = (uVar5 >> 4 & 0xf) + 1 & 0xf;
            *puVar9 = uVar5 & 0xffffff0f | uVar8 << 4;
            if (uVar8 != 0) {
              iVar11 = iVar11 - uVar10;
              goto loc_F0032CC8;
            }
          }
          else {
            uVar5 = uVar5 & 0xf;
            pbVar3 = (byte *)((int)puVar9 + (uVar6 - 1));
            if (uVar5 == 1) {
              if (uVar6 + 8 <= uVar8) {
                iVar7 = param_2;
                _ifptoia(param_2);
                _bcopy(iVar7 + 4,pbVar3,4);
                bVar1 = *(byte *)((int)puVar9 + 2);
loc_F0032C90:
                pbVar3 = (byte *)(bVar1 + 4);
                *(byte *)((int)puVar9 + 2) = (byte)pbVar3;
loc_F0032C98:
                iVar11 = iVar11 - uVar10;
                _iptime();
                *(byte **)((int)register0x00000038 + -0x10) = pbVar3;
                _bcopy((undefined *)((int)register0x00000038 + -0x10),
                       (byte *)((int)puVar9 + (*(byte *)((int)puVar9 + 2) - 1)),4);
                *(byte *)((int)puVar9 + 2) = *(byte *)((int)puVar9 + 2) + 4;
                goto loc_F0032CC8;
              }
            }
            else if (uVar5 < 2) {
              pbVar3 = param_1;
              if (uVar5 == 0) goto loc_F0032C98;
            }
            else if ((uVar5 == 2) && (uVar6 + 8 <= uVar8)) {
              _bcopy(pbVar3,DAT_f010c7e0,4);
              puVar4 = _ipaddr;
              _ifa_ifwithaddr();
              if (puVar4 == (undefined *)0x0) {
                iVar11 = iVar11 - uVar10;
                goto loc_F0032CC8;
              }
              bVar1 = *(byte *)((int)puVar9 + 2);
              goto loc_F0032C90;
            }
          }
        }
        goto loc_F0032CF4;
      }
      if (bVar1 < 0x45) {
        if (bVar1 == 7) {
          uVar8 = *(byte *)((int)puVar9 + 2) - 1;
          if (*(byte *)((int)puVar9 + 2) < 4) {
loc_F0032CE8:
            pbVar3 = param_1 + -2;
            goto loc_F0032CEC;
          }
          if (uVar10 - 4 < uVar8) {
            iVar11 = iVar11 - uVar10;
          }
          else {
            _bcopy(param_1 + 0x10,DAT_f010c7e0,4);
            puVar4 = (undefined *)((int)register0x00000038 + -0xc);
            *(undefined4 *)((int)register0x00000038 + -0xc) = DAT_f010c7e0._0_4_;
            _ip_rtaddr();
            if (puVar4 == (undefined *)0x0) {
              uVar12 = 3;
              iVar7 = 1;
              goto loc_F0032CF4;
            }
            pbVar3 = (byte *)((int)puVar9 + uVar8);
loc_F0032B80:
            iVar11 = iVar11 - uVar10;
            _bcopy(puVar4 + 4,pbVar3,4);
            *(byte *)((int)puVar9 + 2) = *(byte *)((int)puVar9 + 2) + 4;
          }
        }
        else {
          iVar11 = iVar11 - uVar10;
        }
      }
      else if ((bVar1 == 0x83) || (bVar1 == 0x89)) {
        bVar2 = *(byte *)((int)puVar9 + 2);
        if (bVar2 < 4) goto loc_F0032CE8;
        DAT_f010c7e0._0_4_ = *(undefined4 *)(param_1 + 0x10);
        puVar4 = _ipaddr;
        _ifa_ifwithaddr();
        if (puVar4 == (undefined *)0x0) {
          iVar11 = iVar11 - uVar10;
          if (bVar1 == 0x89) goto loc_F0032B14;
        }
        else {
          uVar8 = bVar2 - 1;
          if (uVar8 <= uVar10 - 4) {
            pbVar3 = (byte *)((int)puVar9 + uVar8);
            _bcopy(pbVar3,DAT_f010c7e0,4);
            if (bVar1 == 0x89) {
              puVar4 = (undefined *)((int)register0x00000038 + -0xc);
              *(undefined4 *)((int)register0x00000038 + -0xc) = DAT_f010c7e0._0_4_;
              _in_netof();
              _in_iaonnetof();
              if (puVar4 == (undefined *)0x0) goto loc_F0032B14;
            }
            puVar4 = (undefined *)((int)register0x00000038 + -0xc);
            *(undefined4 *)((int)register0x00000038 + -0xc) = DAT_f010c7e0._0_4_;
            _ip_rtaddr();
            if (puVar4 != (undefined *)0x0) {
              *(undefined4 *)(param_1 + 0x10) = DAT_f010c7e0._0_4_;
              goto loc_F0032B80;
            }
loc_F0032B14:
            uVar12 = 3;
            iVar7 = 5;
            goto loc_F0032CF4;
          }
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0xc);
          _save_rte(puVar9,(undefined *)((int)register0x00000038 + -0xc));
          iVar11 = iVar11 - uVar10;
        }
      }
      else {
        iVar11 = iVar11 - uVar10;
      }
loc_F0032CC8:
      puVar9 = (uint *)((int)puVar9 + uVar10);
    } while (0 < iVar11);
  }
  uVar12 = 0;
locret_F0032D0C:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=753 start=0xf0032d14 */

/* WARNING: Removing unreachable block (ram,0xf0032d88) */
/* WARNING: Removing unreachable block (ram,0xf0032d5c) */

undefined8 _ip_rtaddr(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = *param_1;
  if ((_ipforward_rt == 0) || (iVar2 != DAT_f0136728._0_4_)) {
    if (_ipforward_rt != 0) {
      if (*(sword *)(_ipforward_rt + 0x26) == 1) {
        _rtfree(_ipforward_rt);
      }
      else {
        *(sword *)(_ipforward_rt + 0x26) = *(sword *)(_ipforward_rt + 0x26) + -1;
      }
      _ipforward_rt = 0;
    }
    unk_F0136724._0_2_ = 2;
    DAT_f0136728._0_4_ = iVar2;
    _rtalloc(&_ipforward_rt);
  }
  if (_ipforward_rt == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      iVar1 = *(int *)(_in_ifaddr + 0x20);
      while ((iVar1 != *(int *)(_ipforward_rt + 0x2c) &&
             (iVar2 = *(int *)(iVar2 + 0x40), iVar2 != 0))) {
        iVar1 = *(int *)(iVar2 + 0x20);
      }
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=754 start=0xf0032de8 */

/* WARNING: Removing unreachable block (ram,0xf0032e18) */
/* WARNING: Removing unreachable block (ram,0xf0032e30) */

undefined8 _save_rte(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  undefined4 uVar3;
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
  uVar2 = (uint)*(byte *)(param_1 + 1);
  uVar3 = *param_2;
  if (uVar2 < 0xa4) {
    _bcopy(param_1,unk_F012F445,uVar2);
    uVar1 = uVar2 - 3 >> 2;
    _ip_nhops = uVar1 + 1;
    *(undefined4 *)(unk_F012F445 + uVar1 * 4 + 3) = uVar3;
  }
  else if (_ipprintfs != 0) {
    _printf(aSaveRteOlenD,uVar2);
  }
  return CONCAT44(uVar3,uVar2);
}
/* GHIDRADEC_FUNCTION index=755 start=0xf0032e60 */

/* WARNING: Removing unreachable block (ram,0xf0032ed4) */
/* WARNING: Removing unreachable block (ram,0xf0032e78) */

undefined8 _ip_srcroute(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  iVar1 = 0;
  if ((_ip_nhops == 0) || (_m_get(0,10), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar2 = _ip_nhops * 4;
    *(sword *)(iVar1 + 8) = (sword)iVar2 + 4;
    *(undefined4 *)(iVar1 + *(int *)(iVar1 + 4)) = *(undefined4 *)(&DAT_f012f444 + iVar2);
    DAT_f012f444 = 1;
    _bcopy(&DAT_f012f444,iVar1 + *(int *)(iVar1 + 4) + 4,4);
    puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4) + 8);
    for (puVar4 = (undefined4 *)((int)&DAT_f012f440 + iVar2); DAT_f012f447 < puVar4;
        puVar4 = puVar4 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=756 start=0xf0032f14 */

/* WARNING: Removing unreachable block (ram,0xf0032f6c) */
/* WARNING: Removing unreachable block (ram,0xf0032f4c) */

undefined8 _ip_stripoptions(uint *param_1,int param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  uint *puVar2;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
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
  bVar1 = *(byte *)param_1;
  uVar4 = (uint)param_1 & 0xffffff80;
  puVar2 = param_1 + 5;
  iVar3 = (bVar1 & 0xf) * 4 + -0x14;
  if (param_2 != 0) {
    *(sword *)(param_2 + 8) = (sword)iVar3;
    *(undefined4 *)(param_2 + 4) = 0xc;
    _bcopy(puVar2,param_2 + 0xc,iVar3);
  }
  _bcopy(puVar2 + ((bVar1 & 0xf) - 5),puVar2,(*(sword *)(uVar4 + 8) + -0x14) - iVar3);
  *(sword *)(uVar4 + 8) = *(sword *)(uVar4 + 8) - (sword)iVar3;
  *param_1 = *param_1 & 0xf0ffffff | 0x5000000;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=757 start=0xf0032fa0 */

/* WARNING: Removing unreachable block (ram,0xf0033430) */
/* WARNING: Removing unreachable block (ram,0xf0033274) */
/* WARNING: Removing unreachable block (ram,0xf0033180) */
/* WARNING: Removing unreachable block (ram,0xf00330d8) */
/* WARNING: Removing unreachable block (ram,0xf0033074) */
/* WARNING: Removing unreachable block (ram,0xf0033034) */
/* WARNING: Removing unreachable block (ram,0xf0033024) */
/* WARNING: Removing unreachable block (ram,0xf0033048) */
/* WARNING: Removing unreachable block (ram,0xf0033088) */
/* WARNING: Removing unreachable block (ram,0xf0033108) */
/* WARNING: Removing unreachable block (ram,0xf003325c) */
/* WARNING: Removing unreachable block (ram,0xf00332c4) */
/* WARNING: Removing unreachable block (ram,0xf0033470) */
/* WARNING: Removing unreachable block (ram,0xf0032fdc) */

undefined8 _ip_forward(byte *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar7;
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
  bool bVar8;
  undefined uVar9;
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
  uVar9 = 0;
  iVar5 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  if (_ipprintfs != 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x10);
    _printf(aForwardSrcXDst,(undefined *)((int)register0x00000038 + -0xc),
            (undefined *)((int)register0x00000038 + -0x10),param_1[8]);
  }
  bVar8 = _ipforwarding == 0;
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_1 + 4);
  if ((bVar8) || (_in_interfaces < 2)) {
    iRamf01364f8 = iRamf01364f8 + 1;
    _m_freem((uint)param_1 & 0xffffff80);
  }
  else {
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x10);
    _in_canforward();
    if (puVar1 == (undefined *)0x0) {
      _m_freem((uint)param_1 & 0xffffff80);
    }
    else {
      if (param_1[8] < 2) {
        uVar6 = 0xb;
        uVar9 = 0;
      }
      else {
        param_1[8] = param_1[8] - 1;
        iVar2 = (int)*(sword *)(param_1 + 2);
        _imin(iVar2,0x40);
        uVar3 = (uint)param_1 & 0xffffff80;
        _m_copy(uVar3,0,iVar2);
        if ((_ipforward_rt == 0) || (*(int *)(param_1 + 0x10) != DAT_f0136728._0_4_)) {
          if (_ipforward_rt != 0) {
            if (*(sword *)(_ipforward_rt + 0x26) == 1) {
              _rtfree(_ipforward_rt);
            }
            else {
              *(sword *)(_ipforward_rt + 0x26) = *(sword *)(_ipforward_rt + 0x26) + -1;
            }
            _ipforward_rt = 0;
          }
          unk_F0136724._0_2_ = 2;
          DAT_f0136728._0_4_ = *(undefined4 *)(param_1 + 0x10);
          _rtalloc(&_ipforward_rt);
        }
        if (((((_ipforward_rt != 0) && (*(int *)(_ipforward_rt + 0x2c) == param_2)) &&
             ((*(word *)(_ipforward_rt + 0x24) & 0x30) == 0)) &&
            ((*(int *)(_ipforward_rt + 8) != 0 && (_ipsendredirects != 0)))) &&
           ((*param_1 & 0xf) == 5)) {
          uVar4 = *(uint *)(param_1 + 0xc);
          uVar7 = *(uint *)(param_1 + 0x10);
          iVar2 = param_2;
          _ifptoia();
          if ((iVar2 != 0) && ((uVar4 & *(uint *)(iVar2 + 0x34)) == *(uint *)(iVar2 + 0x30))) {
            if ((*(word *)(_ipforward_rt + 0x24) & 2) == 0) {
              uVar6 = *(undefined4 *)(param_1 + 0x10);
            }
            else {
              uVar6 = *(undefined4 *)(_ipforward_rt + 0x18);
            }
            *(undefined4 *)((int)register0x00000038 + -0x14) = uVar6;
            iVar5 = 5;
            uVar9 = 0;
            if ((*(uint *)(_ipforward_rt + 0x24) & 0x60000) == 0x20000) {
              for (iVar2 = *(int *)(_in_ifaddr + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x40))
              {
                if ((uVar7 & *(uint *)(iVar2 + 0x2c)) == *(uint *)(iVar2 + 0x28)) {
                  if (*(uint *)(iVar2 + 0x34) != *(uint *)(iVar2 + 0x2c)) goto loc_F0033220;
                  break;
                }
              }
            }
            else {
loc_F0033220:
              uVar9 = 1;
            }
            if (_ipprintfs != 0) {
              *(undefined4 *)((int)register0x00000038 + -0x10) =
                   *(undefined4 *)((int)register0x00000038 + -0x14);
              _printf(aRedirectDToX,uVar9,(undefined *)((int)register0x00000038 + -0x10));
            }
          }
        }
        uVar4 = (uint)param_1 & 0xffffff80;
        _ip_output(uVar4,0,&_ipforward_rt,1);
        if (uVar4 == 0) {
          if (iVar5 == 0) {
            if (uVar3 != 0) {
              _m_freem(uVar3);
            }
            iRamf01364f4 = iRamf01364f4 + 1;
            goto locret_F0033478;
          }
          iRamf01364fc = iRamf01364fc + 1;
        }
        else {
          iRamf01364f8 = iRamf01364f8 + 1;
        }
        uVar6 = 3;
        if (uVar3 == 0) goto locret_F0033478;
        param_1 = (byte *)(uVar3 + *(int *)(uVar3 + 4));
        switch(uVar4) {
        case :
          uVar6 = 5;
          break;
        case :
          uVar9 = 3;
          break;
        case :
          uVar9 = 4;
          break;
        case :
        case :
          puVar1 = (undefined *)((int)register0x00000038 + -0x10);
          *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x10);
          _in_localaddr(puVar1);
          uVar9 = puVar1 != (undefined *)0x0;
          break;
        case :
          uVar6 = 4;
          break;
        case :
        case :
          uVar9 = 1;
        }
      }
      _icmp_error(param_1,uVar6,uVar9,param_2,(undefined *)((int)register0x00000038 + -0x14));
    }
  }
locret_F0033478:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=758 start=0xf0033480 */

/* WARNING: Removing unreachable block (ram,0xf0033bc4) */
/* WARNING: Removing unreachable block (ram,0xf0033b6c) */
/* WARNING: Removing unreachable block (ram,0xf0033b44) */
/* WARNING: Removing unreachable block (ram,0xf0033a90) */
/* WARNING: Removing unreachable block (ram,0xf00339dc) */
/* WARNING: Removing unreachable block (ram,0xf0033978) */
/* WARNING: Removing unreachable block (ram,0xf0033908) */
/* WARNING: Removing unreachable block (ram,0xf003387c) */
/* WARNING: Removing unreachable block (ram,0xf00337bc) */
/* WARNING: Removing unreachable block (ram,0xf0033604) */
/* WARNING: Removing unreachable block (ram,0xf00335e4) */
/* WARNING: Removing unreachable block (ram,0xf0033550) */
/* WARNING: Removing unreachable block (ram,0xf003359c) */
/* WARNING: Removing unreachable block (ram,0xf00335fc) */
/* WARNING: Removing unreachable block (ram,0xf003362c) */
/* WARNING: Removing unreachable block (ram,0xf00337f0) */
/* WARNING: Removing unreachable block (ram,0xf00338f4) */
/* WARNING: Removing unreachable block (ram,0xf003395c) */
/* WARNING: Removing unreachable block (ram,0xf00339d0) */
/* WARNING: Removing unreachable block (ram,0xf0033a4c) */
/* WARNING: Removing unreachable block (ram,0xf0033b0c) */
/* WARNING: Removing unreachable block (ram,0xf0033b60) */
/* WARNING: Removing unreachable block (ram,0xf0033660) */
/* WARNING: Removing unreachable block (ram,0xf0033c04) */
/* WARNING: Removing unreachable block (ram,0xf00334ac) */

undefined8 _ip_output(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  sword sVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  code *pcVar7;
  word wVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 unaff_l0;
  int *piVar12;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar13;
  undefined4 unaff_l4;
  int iVar14;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar15;
  undefined4 unaff_l7;
  int *piVar16;
  undefined4 unaff_i0;
  int iVar17;
  undefined4 unaff_i1;
  undefined4 *puVar18;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar19;
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
  *(undefined4 *)((int)register0x00000038 + -0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x4c) = param_4;
  uVar15 = 0x14;
  piVar12 = (int *)0x0;
  iVar14 = *(int *)((int)register0x00000038 + -0x44);
  iVar17 = 0;
  if (param_2 != 0) {
    iVar14 = *(int *)((int)register0x00000038 + -0x44);
    _ip_insertoptions(iVar14,param_2,(undefined *)((int)register0x00000038 + -0x3c));
    uVar15 = *(uint *)((int)register0x00000038 + -0x3c);
  }
  iVar9 = *(int *)(iVar14 + 4);
  puVar18 = (undefined4 *)(iVar14 + iVar9);
  if ((*(uint *)((int)register0x00000038 + -0x4c) & 1) == 0) {
    *(uint *)(iVar14 + iVar9) = *(uint *)(iVar14 + iVar9) & 0xfffffff | 0x40000000;
    sVar1 = _ip_id + 1;
    *(sword *)(puVar18 + 1) = _ip_id;
    _ip_id = sVar1;
    *(word *)((int)puVar18 + 6) = *(word *)((int)puVar18 + 6) & 0x4000;
    *(uint *)(iVar14 + iVar9) =
         *(uint *)(iVar14 + iVar9) & 0xf0ffffff | ((int)uVar15 >> 2 & 0xfU) << 0x18;
  }
  else {
    uVar15 = (*(byte *)(iVar14 + iVar9) & 0xf) << 2;
  }
  if (param_3 == (int *)0x0) {
    param_3 = (int *)((int)register0x00000038 + -0x20);
    _bzero(param_3,0x14);
    iVar9 = *param_3;
  }
  else {
    iVar9 = *param_3;
  }
  piVar16 = param_3 + 1;
  if (iVar9 == 0) {
loc_F00335B4:
    iVar9 = *param_3;
  }
  else {
    if ((*(word *)(iVar9 + 0x24) & 1) == 0) {
      sVar1 = *(sword *)(iVar9 + 0x26);
loc_F0033590:
      if (sVar1 == 1) {
        _rtfree(iVar9);
        *param_3 = 0;
      }
      else {
        *(sword *)(iVar9 + 0x26) = sVar1 + -1;
        *param_3 = 0;
      }
      goto loc_F00335B4;
    }
    if (param_3[2] != puVar18[4]) {
      sVar1 = *(sword *)(iVar9 + 0x26);
      goto loc_F0033590;
    }
    iVar9 = *param_3;
  }
  uVar11 = *(uint *)((int)register0x00000038 + -0x4c);
  if (iVar9 == 0) {
    *(undefined2 *)piVar16 = 2;
    param_3[2] = puVar18[4];
    uVar11 = *(uint *)((int)register0x00000038 + -0x4c);
  }
  if ((uVar11 & 0x10) != 0) {
    piVar12 = piVar16;
    _ifa_ifwithdstaddr();
    piVar2 = (int *)((int)register0x00000038 + -0x40);
    bVar19 = false;
    if (piVar12 == (int *)0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x40) = puVar18[4];
      _in_netof();
      _in_iaonnetof();
      bVar19 = piVar2 == (int *)0x0;
      piVar12 = piVar2;
    }
    if (!bVar19) {
      iVar9 = piVar12[8];
      goto loc_F0033698;
    }
    iVar17 = 0x33;
    goto loc_F0033BC0;
  }
  if (*param_3 == 0) {
    _rtalloc(param_3);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
  }
  if ((iVar6 == 0) || (iVar9 = *(int *)(iVar6 + 0x2c), iVar9 == 0)) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x40);
    *(undefined4 *)((int)register0x00000038 + -0x40) = puVar18[4];
    _in_localaddr();
    if (puVar3 != (undefined *)0x0) {
      iVar17 = 0x41;
      goto loc_F0033BC0;
    }
    iVar14 = *(int *)((int)register0x00000038 + -0x44);
    iVar17 = 0x33;
  }
  else {
    *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
    if ((*(word *)(*param_3 + 0x24) & 2) != 0) {
      piVar16 = (int *)(*param_3 + 0x14);
    }
loc_F0033698:
    if ((puVar18[4] & 0xf0000000) == 0xe0000000) {
      piVar16 = param_3 + 1;
      if (((*(uint *)((int)register0x00000038 + -0x4c) & 2) == 0) || (param_5 == 0)) {
        iVar10 = 0;
        *(undefined *)(puVar18 + 2) = 1;
        iVar6 = iVar9;
loc_F003370C:
        iVar4 = puVar18[3];
        iVar9 = iVar6;
      }
      else {
        iVar6 = *(int *)(param_5 + 4);
        iVar10 = param_5 + iVar6;
        *(undefined *)(puVar18 + 2) = *(undefined *)(iVar10 + 4);
        iVar6 = *(int *)(param_5 + iVar6);
        if (iVar6 != 0) goto loc_F003370C;
        iVar4 = puVar18[3];
      }
      bVar19 = piVar12 == (int *)0x0;
      if ((iVar4 == 0) && (bVar19 = _in_ifaddr == (int *)0x0, piVar12 = _in_ifaddr, !bVar19)) {
        iVar6 = _in_ifaddr[8];
        while (iVar6 != iVar9) {
          piVar12 = (int *)piVar12[0x10];
          if (piVar12 == (int *)0x0) goto loc_F0033750;
          iVar6 = piVar12[8];
        }
        puVar18[3] = piVar12[1];
loc_F0033750:
        bVar19 = piVar12 == (int *)0x0;
      }
      if (bVar19) {
        piVar12 = (int *)0x0;
loc_F0033798:
        if ((piVar12 == (int *)0x0) || ((iVar10 != 0 && (*(char *)(iVar10 + 5) == '\0'))))
        goto loc_F00337CC;
        _ip_mloopback(iVar9,iVar14,piVar16);
        cVar5 = *(char *)(puVar18 + 2);
      }
      else {
        piVar12 = (int *)piVar12[0x11];
        if (piVar12 != (int *)0x0) {
          iVar6 = *piVar12;
          while ((iVar6 != puVar18[4] && (piVar12 = (int *)piVar12[5], piVar12 != (int *)0x0))) {
            iVar6 = *piVar12;
          }
          goto loc_F0033798;
        }
loc_F00337CC:
        if (_ip_mrouter != 0) {
          if ((*(uint *)((int)register0x00000038 + -0x4c) & 1) != 0) {
            cVar5 = *(char *)(puVar18 + 2);
            goto loc_F0033808;
          }
          puVar13 = puVar18;
          _ip_mforward(puVar18,iVar9);
          if (puVar13 != (undefined4 *)0x0) goto loc_F0033BC4;
        }
        cVar5 = *(char *)(puVar18 + 2);
      }
loc_F0033808:
      if ((cVar5 != '\0') && (iVar9 != _loifp)) {
        iVar17 = (int)*(sword *)((int)puVar18 + 2);
        goto loc_F00338D0;
      }
    }
    else {
      if (puVar18[3] == 0) {
        if (_in_ifaddr == (int *)0x0) {
          iVar17 = piVar16[1];
        }
        else {
          iVar17 = _in_ifaddr[8];
          piVar12 = _in_ifaddr;
          while (iVar17 != iVar9) {
            piVar12 = (int *)piVar12[0x10];
            if (piVar12 == (int *)0x0) goto loc_F0033874;
            iVar17 = piVar12[8];
          }
          puVar18[3] = piVar12[1];
loc_F0033874:
          iVar17 = piVar16[1];
        }
      }
      else {
        iVar17 = piVar16[1];
      }
      puVar3 = (undefined *)((int)register0x00000038 + -0x40);
      *(int *)((int)register0x00000038 + -0x40) = iVar17;
      _in_broadcast();
      if (puVar3 == (undefined *)0x0) {
        iVar17 = (int)*(sword *)((int)puVar18 + 2);
loc_F00338D0:
        if (iVar17 <= *(sword *)(iVar9 + 10)) {
          *(sword *)((int)puVar18 + 2) = (sword)iVar17;
          *(undefined2 *)((int)puVar18 + 10) = 0;
          *(undefined2 *)((int)puVar18 + 6) = *(undefined2 *)((int)puVar18 + 6);
          iVar17 = iVar14;
          _in_cksum(iVar14,uVar15);
          *(sword *)((int)puVar18 + 10) = (sword)iVar17;
          _if_output_mbuf(iVar9,iVar14,piVar16);
          goto loc_F0033BCC;
        }
        iVar17 = 0x28;
        if ((*(word *)((int)puVar18 + 6) & 0x4000) == 0) {
          uVar11 = (int)*(sword *)(iVar9 + 10) - uVar15 & 0xfffffff8;
          *(uint *)((int)register0x00000038 + -0x3c) = uVar11;
          if ((int)uVar11 < 8) {
            iVar14 = *(int *)((int)register0x00000038 + -0x44);
            goto loc_F0033BC4;
          }
          iVar6 = iVar9;
          (**(code **)(iVar9 + 0x40))();
          iVar17 = 0x37;
          if (iVar6 != 0) {
            iVar17 = iVar6;
            _nb_map();
            _mbuf_read(iVar14,iVar17,0,uVar15 + *(int *)((int)register0x00000038 + -0x3c));
            *(undefined4 *)((int)register0x00000038 + -0x38) = *puVar18;
            *(undefined4 *)((int)register0x00000038 + -0x34) = puVar18[1];
            *(undefined4 *)((int)register0x00000038 + -0x30) = puVar18[2];
            *(undefined4 *)((int)register0x00000038 + -0x2c) = puVar18[3];
            *(undefined4 *)((int)register0x00000038 + -0x28) = puVar18[4];
            *(sword *)((int)register0x00000038 + -0x36) =
                 (sword)uVar15 + (sword)*(undefined4 *)((int)register0x00000038 + -0x3c);
            *(word *)((int)register0x00000038 + -0x32) = *(word *)((int)puVar18 + 6) | 0x2000;
            *(undefined2 *)((int)register0x00000038 + -0x2e) = 0;
            _bcopy((undefined *)((int)register0x00000038 + -0x38),iVar17,0x14);
            iVar10 = iVar6;
            _in_cksum(iVar6,uVar15);
            *(sword *)((int)register0x00000038 + -0x2e) = (sword)iVar10;
            *(undefined *)(iVar17 + 10) = *(undefined *)((int)register0x00000038 + -0x2e);
            *(undefined *)(iVar17 + 0xb) = *(undefined *)((int)register0x00000038 + -0x2d);
            iVar17 = iVar9;
            (**(code **)(iVar9 + 0x34))(iVar9,iVar6,piVar16);
            if (iVar17 == 0) {
              iVar6 = uVar15 + *(int *)((int)register0x00000038 + -0x3c);
              puVar13 = (undefined4 *)0x14;
              if (iVar6 < *(sword *)((int)puVar18 + 2)) {
                pcVar7 = *(code **)(iVar9 + 0x40);
                while (iVar10 = iVar9, (*pcVar7)(), iVar10 != 0) {
                  iVar17 = iVar10;
                  _nb_map();
                  *(undefined4 *)((int)register0x00000038 + -0x38) = *puVar18;
                  *(undefined4 *)((int)register0x00000038 + -0x34) = puVar18[1];
                  *(undefined4 *)((int)register0x00000038 + -0x30) = puVar18[2];
                  *(undefined4 *)((int)register0x00000038 + -0x2c) = puVar18[3];
                  *(undefined4 *)((int)register0x00000038 + -0x28) = puVar18[4];
                  if (0x14 < uVar15) {
                    puVar13 = puVar18;
                    _ip_optcopy(puVar18,iVar17);
                    puVar13 = puVar13 + 5;
                    *(uint *)((int)register0x00000038 + -0x38) =
                         *(uint *)((int)register0x00000038 + -0x38) & 0xf0ffffff |
                         ((int)puVar13 >> 2 & 0xfU) << 0x18;
                  }
                  wVar8 = (sword)((int)(iVar6 - uVar15) >> 3) +
                          (*(word *)((int)puVar18 + 6) & 0xdfff);
                  *(word *)((int)register0x00000038 + -0x32) = wVar8;
                  if ((*(word *)((int)puVar18 + 6) & 0x2000) != 0) {
                    *(word *)((int)register0x00000038 + -0x32) = wVar8 | 0x2000;
                  }
                  if (iVar6 + *(int *)((int)register0x00000038 + -0x3c) <
                      (int)*(sword *)((int)puVar18 + 2)) {
                    *(word *)((int)register0x00000038 + -0x32) =
                         *(word *)((int)register0x00000038 + -0x32) | 0x2000;
                  }
                  else {
                    _nb_shrink_bot(iVar10,(iVar6 + *(int *)((int)register0x00000038 + -0x3c)) -
                                          (int)*(sword *)((int)puVar18 + 2));
                    *(int *)((int)register0x00000038 + -0x3c) = *(sword *)((int)puVar18 + 2) - iVar6
                    ;
                  }
                  *(sword *)((int)register0x00000038 + -0x36) =
                       (sword)*(undefined4 *)((int)register0x00000038 + -0x3c) + (sword)puVar13;
                  _mbuf_read(iVar14,iVar17 + (int)puVar13,iVar6);
                  *(undefined2 *)((int)register0x00000038 + -0x2e) = 0;
                  *(undefined2 *)((int)register0x00000038 + -0x32) =
                       *(undefined2 *)((int)register0x00000038 + -0x32);
                  _bcopy((undefined *)((int)register0x00000038 + -0x38),iVar17,0x14);
                  iVar4 = iVar10;
                  _in_cksum(iVar10,puVar13);
                  *(sword *)((int)register0x00000038 + -0x2e) = (sword)iVar4;
                  *(undefined *)(iVar17 + 10) = *(undefined *)((int)register0x00000038 + -0x2e);
                  *(undefined *)(iVar17 + 0xb) = *(undefined *)((int)register0x00000038 + -0x2d);
                  iVar17 = iVar9;
                  (**(code **)(iVar9 + 0x34))(iVar9,iVar10,piVar16);
                  if ((iVar17 != 0) ||
                     (iVar6 = iVar6 + *(int *)((int)register0x00000038 + -0x3c),
                     *(sword *)((int)puVar18 + 2) <= iVar6)) goto loc_F0033BC0;
                  pcVar7 = *(code **)(iVar9 + 0x40);
                }
                iVar17 = 0x37;
              }
            }
          }
        }
      }
      else if ((*(word *)(iVar9 + 0xc) & 2) == 0) {
        iVar17 = 0x31;
      }
      else if ((*(uint *)((int)register0x00000038 + -0x4c) & 0x20) == 0) {
        iVar17 = 0xd;
      }
      else {
        iVar17 = 0x28;
        if (*(sword *)((int)puVar18 + 2) <= *(sword *)(iVar9 + 10)) {
          iVar17 = (int)*(sword *)((int)puVar18 + 2);
          goto loc_F00338D0;
        }
      }
loc_F0033BC0:
      iVar14 = *(int *)((int)register0x00000038 + -0x44);
    }
  }
loc_F0033BC4:
  iVar9 = iVar17;
  _m_freem(iVar14);
loc_F0033BCC:
  if (((param_3 == (int *)((int)register0x00000038 + -0x20)) &&
      (iVar17 = *(int *)((int)register0x00000038 + -0x20),
      (*(uint *)((int)register0x00000038 + -0x4c) & 0x10) == 0)) && (iVar17 != 0)) {
    if (*(sword *)(iVar17 + 0x26) == 1) {
      _rtfree(iVar17);
    }
    else {
      *(sword *)(iVar17 + 0x26) = *(sword *)(iVar17 + 0x26) + -1;
    }
  }
  return CONCAT44(puVar18,iVar9);
}
/* GHIDRADEC_FUNCTION index=759 start=0xf0033c1c */

/* WARNING: Removing unreachable block (ram,0xf0033d34) */
/* WARNING: Removing unreachable block (ram,0xf0033c8c) */
/* WARNING: Removing unreachable block (ram,0xf0033cd8) */
/* WARNING: Removing unreachable block (ram,0xf0033ce4) */
/* WARNING: Removing unreachable block (ram,0xf0033d78) */
/* WARNING: Removing unreachable block (ram,0xf0033d60) */
/* WARNING: Removing unreachable block (ram,0xf0033c64) */

undefined8 _ip_insertoptions(undefined4 *param_1,int param_2,int *param_3)

{
  sword sVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  int iVar9;
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
  iVar7 = *(int *)(param_2 + *(int *)(param_2 + 4));
  iVar8 = (int)param_1 + param_1[1];
  sVar1 = *(sword *)(param_2 + 8);
  iVar3 = (int)sVar1;
  param_2 = param_2 + *(int *)(param_2 + 4);
  iVar9 = iVar3 + -4;
  if (iVar7 != 0) {
    *(int *)(iVar8 + 0x10) = iVar7;
  }
  uVar6 = param_1[1];
  uVar4 = iVar3 + 8;
  if ((uVar6 < 0x7c) && (bVar2 = uVar4 <= uVar6, uVar4 = uVar6 - iVar9, bVar2)) {
    param_1[1] = uVar4;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + (sword)iVar9;
    _ovbcopy(iVar8,(int)param_1 + param_1[1],0x14);
  }
  else {
    _spltty();
    puVar5 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
      _m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_9);
      }
      *(undefined2 *)((int)puVar5 + 10) = 2;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
      _mfree = (undefined4 *)*puVar5;
      puVar5[1] = 0xc;
      *puVar5 = 0;
    }
    _splx(uVar4);
    if (puVar5 == (undefined4 *)0x0) goto locret_F0033D94;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + -0x14;
    param_1[1] = param_1[1] + 0x14;
    *puVar5 = param_1;
    puVar5[1] = 0x68 - iVar9;
    *(sword *)(puVar5 + 2) = sVar1 + 0x10;
    _bcopy(iVar8,(int)puVar5 + puVar5[1],0x14);
    param_1 = puVar5;
  }
  iVar7 = param_1[1];
  _bcopy(param_2 + 4,(int)param_1 + iVar7 + 0x14,iVar9);
  *param_3 = iVar3 + 0x10;
  *(sword *)((int)param_1 + iVar7 + 2) = *(sword *)((int)param_1 + iVar7 + 2) + (sword)iVar9;
locret_F0033D94:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=760 start=0xf0033d9c */

/* WARNING: Removing unreachable block (ram,0xf0033dfc) */

undefined8 _ip_optcopy(byte *param_1,int param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  byte *pbVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined *puVar6;
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
  pbVar4 = param_1 + 0x14;
  puVar3 = (undefined *)(param_2 + 0x14);
  for (uVar2 = (*param_1 & 0xf) * 4 - 0x14; 0 < (int)uVar2; uVar2 = uVar2 - uVar5) {
    bVar1 = *pbVar4;
    if (bVar1 == 0) break;
    if (bVar1 == 1) {
      uVar5 = 1;
    }
    else {
      uVar5 = (uint)pbVar4[1];
    }
    if ((int)uVar2 < (int)uVar5) {
      uVar5 = uVar2;
    }
    if ((bVar1 & 0x80) != 0) {
      _bcopy(pbVar4,puVar3,uVar5);
      puVar3 = puVar3 + uVar5;
    }
    pbVar4 = pbVar4 + uVar5;
  }
  for (puVar6 = puVar3 + (-0x14 - param_2); ((uint)puVar6 & 3) != 0; puVar6 = puVar6 + 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return CONCAT44(param_2,puVar6);
}
/* GHIDRADEC_FUNCTION index=761 start=0xf0033e48 */

/* WARNING: Removing unreachable block (ram,0xf0033eb8) */
/* WARNING: Removing unreachable block (ram,0xf0033f48) */
/* WARNING: Removing unreachable block (ram,0xf0033ef8) */
/* WARNING: Removing unreachable block (ram,0xf0033e88) */
/* WARNING: Removing unreachable block (ram,0xf0033f88) */
/* WARNING: Removing unreachable block (ram,0xf0033f58) */

undefined8 _ip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  iVar2 = 0;
  iVar3 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (param_4 == 1) {
        iVar1 = 1;
        _m_get(1,10);
        *param_5 = iVar1;
        if (*(int *)(iVar3 + 0x38) == 0) {
          *(undefined2 *)(iVar1 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(*(int *)(iVar3 + 0x38) + 4);
          *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar3 + 0x38) + 8);
          iVar1 = *param_5;
          _bcopy(*(int *)(iVar3 + 0x38) + *(int *)(*(int *)(iVar3 + 0x38) + 4),
                 iVar1 + *(int *)(iVar1 + 4),(int)*(sword *)(iVar1 + 8));
        }
      }
      else {
        if (param_4 < 1) goto loc_F0033F68;
        iVar2 = 0x16;
        if ((param_4 < 8) && (2 < param_4)) {
          _ip_getmoptions(param_4,*(undefined4 *)(iVar3 + 0x3c),param_5);
          iVar2 = param_4;
        }
      }
    }
    else if (param_1 == 1) {
      if (param_4 == 1) {
        iVar2 = iVar3 + 0x38;
        _ip_pcbopts(iVar2,*param_5);
        goto locret_F0033F90;
      }
      if (param_4 < 1) goto loc_F0033F68;
      iVar2 = 0x16;
      if ((param_4 < 8) && (2 < param_4)) {
        _ip_setmoptions(param_4,iVar3 + 0x3c,*param_5);
        iVar2 = param_4;
      }
    }
  }
  else {
loc_F0033F68:
    iVar2 = 0x16;
  }
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free();
  }
locret_F0033F90:
  return CONCAT44(iVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=762 start=0xf0033f98 */

/* WARNING: Removing unreachable block (ram,0xf00340d4) */
/* WARNING: Removing unreachable block (ram,0xf00340f8) */
/* WARNING: Removing unreachable block (ram,0xf0034024) */
/* WARNING: Removing unreachable block (ram,0xf0034034) */
/* WARNING: Removing unreachable block (ram,0xf00340c4) */
/* WARNING: Removing unreachable block (ram,0xf0033fdc) */
/* WARNING: Removing unreachable block (ram,0xf0033fac) */

undefined8 _ip_pcbopts(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  char *pcVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  if (*param_1 != 0) {
    _m_free();
  }
  *param_1 = 0;
  if (param_2 != 0) {
    uVar3 = (uint)*(sword *)(param_2 + 8);
    if (uVar3 != 0) {
      if (((uVar3 & 3) == 0) && (*(int *)(param_2 + 4) + uVar3 + 4 < 0x7d)) {
        *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + 4;
        iVar2 = param_2 + *(int *)(param_2 + 4);
        pcVar5 = (char *)(iVar2 + 4);
        _ovbcopy(iVar2,pcVar5);
        _bzero(param_2 + *(int *)(param_2 + 4),4);
        if ((int)uVar3 < 1) {
          *param_1 = param_2;
        }
        else {
          do {
            cVar1 = *pcVar5;
            if (cVar1 == '\0') break;
            if (cVar1 == '\x01') {
              uVar4 = 1;
            }
            else {
              uVar4 = (uint)(byte)pcVar5[1];
              if ((uVar4 < 2) || ((int)uVar3 < (int)uVar4)) goto loc_F00340F8;
            }
            if ((cVar1 == -0x7d) || (cVar1 == -0x77)) {
              if (uVar4 < 7) goto loc_F00340F8;
              uVar4 = uVar4 - 4;
              *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + -4;
              pcVar5[1] = (char)uVar4;
              _bcopy(pcVar5 + 3,param_2 + *(int *)(param_2 + 4),4);
              _ovbcopy(pcVar5 + 7,pcVar5 + 3,uVar3);
              uVar3 = (uVar3 - 4) - uVar4;
            }
            else {
              uVar3 = uVar3 - uVar4;
            }
            pcVar5 = pcVar5 + uVar4;
          } while (0 < (int)uVar3);
          *param_1 = param_2;
        }
        uVar6 = 0;
      }
      else {
loc_F00340F8:
        _m_free(param_2);
        uVar6 = 0x16;
      }
      goto locret_F0034104;
    }
  }
  uVar6 = 0;
  if (param_2 != 0) {
    _m_free(param_2);
    uVar6 = 0;
  }
locret_F0034104:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=763 start=0xf003410c */

/* WARNING: Removing unreachable block (ram,0xf0034478) */
/* WARNING: Removing unreachable block (ram,0xf0034380) */
/* WARNING: Removing unreachable block (ram,0xf00341b4) */
/* WARNING: Removing unreachable block (ram,0xf00341a8) */
/* WARNING: Removing unreachable block (ram,0xf003414c) */
/* WARNING: Removing unreachable block (ram,0xf00345d0) */
/* WARNING: Removing unreachable block (ram,0xf0034398) */
/* WARNING: Removing unreachable block (ram,0xf0034648) */
/* WARNING: Removing unreachable block (ram,0xf0034120) */

undefined8 _ip_setmoptions(undefined4 param_1,int *param_2,int param_3)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int *piVar6;
  sword sVar7;
  int *piVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined4 unaff_l3;
  undefined4 uVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar13;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  iVar3 = *param_2;
  uVar12 = 0;
  if (iVar3 == 0) {
    _spltty();
    iVar9 = _mfree;
    bVar14 = _mfree == 0;
    *param_2 = _mfree;
    if (bVar14) {
      iVar9 = 1;
      _m_more(1,0xe);
      *param_2 = iVar9;
    }
    else {
      if (*(sword *)(iVar9 + 10) != 0) {
        _panic(&aMget_10);
      }
      *(undefined2 *)(*param_2 + 10) = 0xe;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b28._0_2_ = DAT_f0134b28._0_2_ + 1;
      _mfree = *(int *)*param_2;
      *(undefined4 *)*param_2 = 0;
      *(undefined4 *)(*param_2 + 4) = 0xc;
    }
    _splx(iVar3);
    iVar3 = *param_2;
    if (iVar3 == 0) {
      uVar12 = 0x37;
      goto locret_F0034658;
    }
    iVar9 = iVar3 + *(int *)(iVar3 + 4);
    *(undefined4 *)(iVar3 + *(int *)(iVar3 + 4)) = 0;
    *(undefined *)(iVar9 + 4) = 1;
    *(undefined *)(iVar9 + 5) = 1;
    *(undefined2 *)(iVar9 + 6) = 0;
  }
  piVar10 = (int *)(*param_2 + *(int *)(*param_2 + 4));
  switch(param_1) {
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 4) {
      iVar3 = *(int *)(param_3 + *(int *)(param_3 + 4));
      if (iVar3 == 0) {
        *piVar10 = 0;
      }
      else {
        iVar9 = 0;
        if (_in_ifaddr != 0) {
          iVar9 = *(int *)(_in_ifaddr + 4);
          iVar13 = _in_ifaddr;
          while ((iVar9 != iVar3 && (iVar13 = *(int *)(iVar13 + 0x40), iVar13 != 0))) {
            iVar9 = *(int *)(iVar13 + 4);
          }
          iVar9 = 0;
          if (iVar13 != 0) {
            iVar9 = *(int *)(iVar13 + 0x20);
          }
        }
        if (iVar9 == 0) {
          uVar12 = 0x31;
        }
        else {
          *piVar10 = iVar9;
        }
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 1) {
      *(undefined *)(piVar10 + 1) = *(undefined *)(param_3 + *(int *)(param_3 + 4));
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 1) {
      bVar1 = *(byte *)(param_3 + *(int *)(param_3 + 4));
      if (bVar1 < 2) {
        *(byte *)((int)piVar10 + 5) = bVar1;
      }
      else {
        uVar12 = 0x16;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 8) {
      iVar3 = *(int *)(param_3 + 4);
      piVar11 = (int *)(param_3 + iVar3);
      if ((*(uint *)(param_3 + iVar3) & 0xf0000000) == 0xe0000000) {
        if (piVar11[1] == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
          *(undefined2 *)((int)register0x00000038 + -0x1c) = 2;
          *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_3 + iVar3);
          _rtalloc((undefined *)((int)register0x00000038 + -0x20));
          if (*(int *)((int)register0x00000038 + -0x20) == 0) {
            uVar12 = 0x31;
            break;
          }
          iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x2c);
          _rtfree();
        }
        else {
          iVar3 = 0;
          if (_in_ifaddr != 0) {
            iVar3 = *(int *)(_in_ifaddr + 4);
            iVar9 = _in_ifaddr;
            while ((iVar3 != piVar11[1] && (iVar9 = *(int *)(iVar9 + 0x40), iVar9 != 0))) {
              iVar3 = *(int *)(iVar9 + 4);
            }
            iVar3 = 0;
            if (iVar9 != 0) {
              iVar3 = *(int *)(iVar9 + 0x20);
            }
          }
        }
        iVar9 = 0;
        if (iVar3 == 0) goto loc_F00345C4;
        iVar13 = -0x14;
        piVar8 = piVar10;
        if (*(word *)((int)piVar10 + 6) != 0) {
          do {
            if ((((int *)piVar8[2])[1] == iVar3) && (*(int *)piVar8[2] == *piVar11)) {
              wVar2 = *(word *)((int)piVar10 + 6);
              goto loc_F003444C;
            }
            iVar9 = iVar9 + 1;
            piVar8 = piVar8 + 1;
          } while (iVar9 < (int)(uint)*(word *)((int)piVar10 + 6));
          wVar2 = *(word *)((int)piVar10 + 6);
loc_F003444C:
          iVar13 = iVar9 + -0x14;
          if (iVar9 < (int)(uint)wVar2) {
            uVar12 = 0x30;
            break;
          }
        }
        puVar4 = (undefined *)((int)register0x00000038 + -0x24);
        if (iVar13 == 0) {
          uVar12 = 0x3b;
        }
        else {
          *(int *)((int)register0x00000038 + -0x24) = *piVar11;
          _in_addmulti(puVar4,iVar3);
          piVar10[iVar9 + 2] = (int)puVar4;
          if (puVar4 == (undefined *)0x0) {
            uVar12 = 0x37;
          }
          else {
            *(sword *)((int)piVar10 + 6) = *(sword *)((int)piVar10 + 6) + 1;
          }
        }
      }
      else {
loc_F00344EC:
        uVar12 = 0x16;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 8) {
      piVar11 = (int *)(param_3 + *(int *)(param_3 + 4));
      if ((*(uint *)(param_3 + *(int *)(param_3 + 4)) & 0xf0000000) != 0xe0000000)
      goto loc_F00344EC;
      iVar3 = piVar11[1];
      if (iVar3 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = 0;
        if (_in_ifaddr != 0) {
          iVar9 = *(int *)(_in_ifaddr + 4);
          iVar13 = _in_ifaddr;
          while ((iVar9 != iVar3 && (iVar13 = *(int *)(iVar13 + 0x40), iVar13 != 0))) {
            iVar9 = *(int *)(iVar13 + 4);
          }
          iVar9 = 0;
          if (iVar13 != 0) {
            iVar9 = *(int *)(iVar13 + 0x20);
          }
        }
        if (iVar9 == 0) {
          uVar12 = 0x31;
          break;
        }
      }
      uVar5 = (uint)*(word *)((int)piVar10 + 6);
      iVar13 = 0;
      iVar3 = -uVar5;
      piVar8 = piVar10;
      if (uVar5 != 0) {
        do {
          piVar6 = (int *)piVar8[2];
          if (iVar9 == 0) {
loc_F0034590:
            if (*piVar6 == *piVar11) {
              wVar2 = *(word *)((int)piVar10 + 6);
              goto loc_F00345B8;
            }
          }
          else if (piVar6[1] == iVar9) {
            piVar6 = (int *)piVar8[2];
            goto loc_F0034590;
          }
          iVar13 = iVar13 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar13 < (int)uVar5);
        wVar2 = *(word *)((int)piVar10 + 6);
loc_F00345B8:
        iVar3 = iVar13 - (uint)wVar2;
      }
      if (iVar3 == 0) {
loc_F00345C4:
        uVar12 = 0x31;
      }
      else {
        _in_delmulti(piVar10[iVar13 + 2]);
        iVar13 = iVar13 + 1;
        if (iVar13 < (int)(uint)*(word *)((int)piVar10 + 6)) {
          piVar11 = piVar10 + iVar13;
          do {
            iVar13 = iVar13 + 1;
            piVar11[1] = piVar11[2];
            piVar11 = piVar11 + 1;
          } while (iVar13 < (int)(uint)*(word *)((int)piVar10 + 6));
          sVar7 = *(sword *)((int)piVar10 + 6);
        }
        else {
          sVar7 = *(sword *)((int)piVar10 + 6);
        }
        *(sword *)((int)piVar10 + 6) = sVar7 + -1;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  :
    uVar12 = 0x2d;
  }
  if ((*piVar10 == 0) && (piVar10[1] == 0x1010000)) {
    _m_free(*param_2);
    *param_2 = 0;
  }
locret_F0034658:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=764 start=0xf0034660 */

/* WARNING: Removing unreachable block (ram,0xf0034668) */

undefined8 _ip_getmoptions(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined uVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  int *piVar5;
  undefined4 unaff_i2;
  int iVar6;
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
  iVar1 = 1;
  _m_get(1,0xe);
  *param_3 = iVar1;
  if (param_2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(param_2 + *(int *)(param_2 + 4));
  }
  if (param_1 == 4) {
    iVar6 = *param_3;
    iVar1 = *(int *)(iVar6 + 4);
    *(undefined2 *)(iVar6 + 8) = 1;
    if (piVar5 == (int *)0x0) {
loc_F0034774:
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined *)(piVar5 + 1);
    }
loc_F0034778:
    *(undefined *)(iVar6 + iVar1) = uVar2;
  }
  else {
    if (4 < param_1) {
      if (param_1 != 5) {
        uVar4 = 0x2d;
        goto locret_F0034780;
      }
      iVar6 = *param_3;
      iVar1 = *(int *)(iVar6 + 4);
      *(undefined2 *)(iVar6 + 8) = 1;
      if (piVar5 == (int *)0x0) goto loc_F0034774;
      uVar2 = *(undefined *)((int)piVar5 + 5);
      goto loc_F0034778;
    }
    if (param_1 != 3) {
      uVar4 = 0x2d;
      goto locret_F0034780;
    }
    iVar1 = *param_3;
    *(undefined2 *)(iVar1 + 8) = 4;
    puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4));
    if ((piVar5 == (int *)0x0) || (piVar5 = (int *)*piVar5, piVar5 == (int *)0x0)) {
      *(undefined4 *)(iVar1 + *(int *)(iVar1 + 4)) = 0;
    }
    else if (_in_ifaddr == 0) {
      *puVar3 = 0;
    }
    else {
      iVar6 = *(int *)(_in_ifaddr + 0x20);
      iVar1 = _in_ifaddr;
      while (((int *)iVar6 != piVar5 && (iVar1 = *(int *)(iVar1 + 0x40), iVar1 != 0))) {
        iVar6 = *(int *)(iVar1 + 0x20);
      }
      if (iVar1 == 0) {
        *puVar3 = 0;
      }
      else {
        *puVar3 = *(undefined4 *)(iVar1 + 4);
      }
    }
  }
  uVar4 = 0;
locret_F0034780:
  return CONCAT44(piVar5,uVar4);
}
/* GHIDRADEC_FUNCTION index=765 start=0xf0034788 */

/* WARNING: Removing unreachable block (ram,0xf00347d0) */
/* WARNING: Removing unreachable block (ram,0xf00347b8) */

undefined8 _ip_freemoptions(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
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
  iVar1 = 0;
  if (param_1 != 0) {
    iVar3 = param_1 + *(int *)(param_1 + 4);
    iVar2 = iVar3;
    if (*(sword *)(iVar3 + 6) != 0) {
      do {
        iVar1 = iVar1 + 1;
        _in_delmulti(*(undefined4 *)(iVar2 + 8));
        iVar2 = iVar2 + 4;
      } while (iVar1 < (int)(uint)*(word *)(iVar3 + 6));
    }
    _m_free(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=766 start=0xf00347e0 */

/* WARNING: Removing unreachable block (ram,0xf003482c) */
/* WARNING: Removing unreachable block (ram,0xf0034840) */
/* WARNING: Removing unreachable block (ram,0xf00347f0) */

undefined8 _ip_mloopback(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  _m_copy(param_2,0,1000000000);
  if (param_2 != 0) {
    iVar2 = *(int *)(param_2 + 4);
    iVar3 = param_2 + iVar2;
    *(undefined2 *)(iVar3 + 10) = 0;
    *(undefined2 *)(iVar3 + 2) = *(undefined2 *)(iVar3 + 2);
    *(undefined2 *)(iVar3 + 6) = *(undefined2 *)(iVar3 + 6);
    iVar1 = param_2;
    _in_cksum(param_2,(*(byte *)(param_2 + iVar2) & 0xf) << 2);
    *(sword *)(iVar3 + 10) = (sword)iVar1;
    _looutput(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=767 start=0xf0034850 */

/* WARNING: Removing unreachable block (ram,0xf003488c) */

undefined8 _rip_input(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = param_1 + *(int *)(param_1 + 4);
  DAT_f010c8a2._0_2_ = (word)*(byte *)(iVar1 + 9);
  DAT_f010c884._0_4_ = *(undefined4 *)(iVar1 + 0x10);
  DAT_f010c894._0_4_ = *(undefined4 *)(iVar1 + 0xc);
  _raw_input();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=768 start=0xf003489c */

/* WARNING: Removing unreachable block (ram,0xf0034a10) */
/* WARNING: Removing unreachable block (ram,0xf0034a00) */
/* WARNING: Removing unreachable block (ram,0xf00348e4) */

undefined8 _rip_output(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  sword sVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
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
  iVar6 = *(int *)(param_2 + 8);
  sVar7 = 0;
  if ((*(sword *)(iVar6 + 0x2e) == 0xff) || (piVar8 = param_1, *(sword *)(iVar6 + 0x2e) == 2)) {
    iVar2 = *(int *)((int)param_1 + param_1[1] + 0xc);
    if (iVar2 == 0) {
      uVar4 = *(undefined4 *)(iVar6 + 0x10);
    }
    else {
      iVar3 = 0;
      if (_in_ifaddr != 0) {
        iVar3 = *(int *)(_in_ifaddr + 4);
        iVar5 = _in_ifaddr;
        while ((iVar3 != iVar2 && (iVar5 = *(int *)(iVar5 + 0x40), iVar5 != 0))) {
          iVar3 = *(int *)(iVar5 + 4);
        }
        iVar3 = 0;
        if (iVar5 != 0) {
          iVar3 = *(int *)(iVar5 + 0x20);
        }
      }
      if (iVar3 == 0) {
        piVar8 = (int *)0x31;
        goto loc_F0034A10;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x10);
    }
    *(undefined4 *)((int)param_1 + param_1[1] + 0x10) = uVar4;
  }
  else {
    for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      sVar7 = sVar7 + *(sword *)(piVar8 + 2);
    }
    piVar1 = (int *)0x0;
    _m_get(0,2);
    if (piVar1 == (int *)0x0) {
      piVar8 = (int *)0x37;
loc_F0034A10:
      _m_freem(param_1);
      param_1 = piVar8;
      goto locret_F0034A18;
    }
    piVar1[1] = 0x68;
    *(undefined2 *)(piVar1 + 2) = 0x14;
    iVar2 = piVar1[1];
    *piVar1 = (int)param_1;
    *(undefined *)((int)piVar1 + iVar2 + 1) = 0;
    *(undefined2 *)((int)piVar1 + iVar2 + 6) = 0;
    *(char *)((int)piVar1 + iVar2 + 9) = (char)*(undefined2 *)(iVar6 + 0x2e);
    *(sword *)((int)piVar1 + iVar2 + 2) = sVar7 + 0x14;
    if ((*(word *)(iVar6 + 0x4c) & 1) == 0) {
      *(undefined4 *)((int)piVar1 + iVar2 + 0xc) = 0;
    }
    else {
      piVar8 = (int *)0x2f;
      param_1 = piVar1;
      if (*(sword *)(iVar6 + 0x1c) != 2) goto loc_F0034A10;
      *(undefined4 *)((int)piVar1 + iVar2 + 0xc) = *(undefined4 *)(iVar6 + 0x20);
    }
    *(undefined4 *)((int)piVar1 + iVar2 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
    *(undefined *)((int)piVar1 + iVar2 + 8) = 0xff;
    param_1 = piVar1;
  }
  _ip_output(param_1,*(undefined4 *)(iVar6 + 0x34),iVar6 + 0x38,*(word *)(param_2 + 2) & 0x10 | 0x22
             ,*(undefined4 *)(iVar6 + 0x50));
locret_F0034A18:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=769 start=0xf0034a20 */

/* WARNING: Removing unreachable block (ram,0xf0034a90) */
/* WARNING: Removing unreachable block (ram,0xf0034a64) */
/* WARNING: Removing unreachable block (ram,0xf0034ae0) */
/* WARNING: Removing unreachable block (ram,0xf0034b30) */
/* WARNING: Removing unreachable block (ram,0xf0034aa0) */
/* WARNING: Removing unreachable block (ram,0xf0034b70) */
/* WARNING: Removing unreachable block (ram,0xf0034b40) */

undefined8 _rip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar2 = 0;
  iVar3 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (param_4 == 1) {
        iVar1 = 1;
        _m_get(1,10);
        *param_5 = iVar1;
        if (*(int *)(iVar3 + 0x34) == 0) {
          *(undefined2 *)(iVar1 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(*(int *)(iVar3 + 0x34) + 4);
          *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar3 + 0x34) + 8);
          iVar1 = *param_5;
          _bcopy(*(int *)(iVar3 + 0x34) + *(int *)(*(int *)(iVar3 + 0x34) + 4),
                 iVar1 + *(int *)(iVar1 + 4),(int)*(sword *)(iVar1 + 8));
        }
      }
      else {
        if (param_4 < 1) goto loc_F0034B50;
        iVar2 = 0x16;
        if ((param_4 < 8) && (2 < param_4)) {
          _ip_getmoptions(param_4,*(undefined4 *)(iVar3 + 0x50),param_5);
          iVar2 = param_4;
        }
      }
    }
    else if (param_1 == 1) {
      if (param_4 == 1) {
        iVar2 = iVar3 + 0x34;
        _ip_pcbopts(iVar2,*param_5);
        goto locret_F0034B78;
      }
      if (((param_4 < 1) || (7 < param_4)) || (param_4 < 3)) {
        _ip_mrouter_cmd(param_4,param_2,*param_5);
        iVar2 = param_4;
      }
      else {
        _ip_setmoptions(param_4,iVar3 + 0x50,*param_5);
        iVar2 = param_4;
      }
    }
  }
  else {
loc_F0034B50:
    iVar2 = 0x16;
  }
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free();
  }
locret_F0034B78:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=770 start=0xf0034b80 */

/* WARNING: Removing unreachable block (ram,0xf0034be8) */
/* WARNING: Removing unreachable block (ram,0xf0034bfc) */
/* WARNING: Removing unreachable block (ram,0xf0034c64) */
/* WARNING: Removing unreachable block (ram,0xf0034bc0) */

undefined8
_tcp_trace(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined2 param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar1 = _tcp_debx + 1;
  iVar3 = _tcp_debx * 0xa4;
  puVar2 = DAT_f0136400;
  _tcp_debx = iVar1;
  if (iVar1 == 100) {
    _tcp_debx = 0;
  }
  _iptime();
  *(undefined **)(_tcp_debug + iVar3) = puVar2;
  *(sword *)(_tcp_debug + iVar3 + 4) = (sword)param_1;
  *(sword *)(_tcp_debug + iVar3 + 6) = (sword)param_2;
  *(int *)(_tcp_debug + iVar3 + 8) = param_3;
  if (param_3 == 0) {
    _bzero(iVar3 + -0xfec9848,0x6c);
  }
  else {
    _memcpy(iVar3 + -0xfec9848,param_3,0x6c);
  }
  if (param_4 == (undefined4 *)0x0) {
    _bzero(iVar3 + -0xfec9874,0x28);
  }
  else {
    *(undefined4 *)(_tcp_debug + iVar3 + 0xc) = *param_4;
    *(undefined4 *)(_tcp_debug + iVar3 + 0x10) = param_4[1];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x14) = param_4[2];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x18) = param_4[3];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x1c) = param_4[4];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x20) = param_4[5];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x24) = param_4[6];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x28) = param_4[7];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x2c) = param_4[8];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x30) = param_4[9];
  }
  *(undefined2 *)(_tcp_debug + iVar3 + 0x34) = param_5;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=771 start=0xf0034c78 */

/* WARNING: Removing unreachable block (ram,0xf0034ec8) */
/* WARNING: Removing unreachable block (ram,0xf0034e04) */
/* WARNING: Removing unreachable block (ram,0xf0034d48) */
/* WARNING: Removing unreachable block (ram,0xf0034edc) */
/* WARNING: Removing unreachable block (ram,0xf0034f08) */
/* WARNING: Removing unreachable block (ram,0xf0034d5c) */
/* WARNING: Removing unreachable block (ram,0xf0034d28) */

undefined8 _tcp_reass(int *param_1,int *param_2,int param_3)

{
  sword sVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  iVar7 = *(int *)(param_1[8] + 0x1c);
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)*param_1;
    if (piVar5 == param_1) {
      piVar3 = (int *)piVar5[1];
    }
    else {
      iVar6 = piVar5[6];
      while (iVar6 == param_2[6] || iVar6 - param_2[6] < 0) {
        piVar5 = (int *)*piVar5;
        if (piVar5 == param_1) {
          piVar3 = (int *)piVar5[1];
          goto loc_F0034CC8;
        }
        iVar6 = piVar5[6];
      }
      piVar3 = (int *)piVar5[1];
    }
loc_F0034CC8:
    if (piVar3 != param_1) {
      iVar6 = (piVar3[6] + (int)*(sword *)((int)piVar3 + 10)) - param_2[6];
      if (iVar6 < 1) {
        piVar5 = (int *)*piVar3;
      }
      else {
        if (*(sword *)((int)param_2 + 10) <= iVar6) {
          DAT_f013a81c._0_4_ = DAT_f013a81c._0_4_ + 1;
          DAT_f013a81c._4_4_ = DAT_f013a81c._4_4_ + (int)*(sword *)((int)param_2 + 10);
          _m_freem(param_3);
          uVar8 = 0;
          goto locret_F0034F14;
        }
        _m_adj(param_3,iVar6);
        *(sword *)((int)param_2 + 10) = *(sword *)((int)param_2 + 10) - (sword)iVar6;
        param_2[6] = param_2[6] + iVar6;
        piVar5 = (int *)*piVar3;
      }
    }
    DAT_f013a81c._16_4_ = DAT_f013a81c._16_4_ + 1;
    DAT_f013a81c._20_4_ = DAT_f013a81c._20_4_ + (int)*(sword *)((int)param_2 + 10);
    param_2[5] = param_3;
    if (piVar5 == param_1) {
loc_F0034E18:
      piVar5 = (int *)piVar5[1];
    }
    else {
      sVar1 = *(sword *)((int)param_2 + 10);
      while( true ) {
        iVar6 = (param_2[6] + (int)sVar1) - piVar5[6];
        if (iVar6 < 1) break;
        if (iVar6 < *(sword *)((int)piVar5 + 10)) {
          piVar5[6] = piVar5[6] + iVar6;
          *(sword *)((int)piVar5 + 10) = *(sword *)((int)piVar5 + 10) - (sword)iVar6;
          _m_adj(piVar5[5]);
          piVar5 = (int *)piVar5[1];
          goto loc_F0034E1C;
        }
        piVar5 = (int *)*piVar5;
        piVar3 = (int *)piVar5[1];
        iVar6 = piVar3[5];
        *(int *)(*piVar3 + 4) = piVar3[1];
        *(int *)piVar3[1] = *piVar3;
        _m_freem(iVar6);
        if (piVar5 == param_1) goto loc_F0034E18;
        sVar1 = *(sword *)((int)param_2 + 10);
      }
      piVar5 = (int *)piVar5[1];
    }
loc_F0034E1C:
    *param_2 = *piVar5;
    param_2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = param_2;
    *piVar5 = (int)param_2;
  }
  if (*(sword *)(param_1 + 2) < 3) {
    uVar8 = 0;
  }
  else {
    param_2 = (int *)*param_1;
    if (param_2 == param_1) {
      uVar8 = 0;
    }
    else {
      iVar6 = param_1[0x10];
      if (param_2[6] == iVar6) {
        if (*(sword *)(param_1 + 2) == 3) {
          if (*(sword *)((int)param_2 + 10) != 0) {
            uVar8 = 0;
            goto locret_F0034F14;
          }
          iVar4 = (int)*(sword *)((int)param_2 + 10);
          iVar6 = param_1[0x10];
        }
        else {
          iVar4 = (int)*(sword *)((int)param_2 + 10);
        }
        while( true ) {
          param_1[0x10] = iVar6 + iVar4;
          bVar2 = *(byte *)((int)param_2 + 0x21);
          *(int *)(*param_2 + 4) = param_2[1];
          *(int *)param_2[1] = *param_2;
          piVar5 = param_2 + 5;
          uVar8 = bVar2 & 1;
          param_2 = (int *)*param_2;
          if ((*(word *)(iVar7 + 6) & 0x20) == 0) {
            _sbappend(iVar7 + 0x24,*piVar5);
          }
          else {
            _m_freem(*piVar5);
          }
          if ((param_2 == param_1) || (iVar6 = param_1[0x10], param_2[6] != iVar6)) break;
          iVar4 = (int)*(sword *)((int)param_2 + 10);
        }
        _sowakeup(iVar7,iVar7 + 0x24);
      }
      else {
        uVar8 = 0;
      }
    }
  }
locret_F0034F14:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=772 start=0xf0034f1c */

/* WARNING: Removing unreachable block (ram,0xf003659c) */
/* WARNING: Removing unreachable block (ram,0xf0036554) */
/* WARNING: Removing unreachable block (ram,0xf0036444) */
/* WARNING: Removing unreachable block (ram,0xf00363f8) */
/* WARNING: Removing unreachable block (ram,0xf0036310) */
/* WARNING: Removing unreachable block (ram,0xf0036324) */
/* WARNING: Removing unreachable block (ram,0xf0036234) */
/* WARNING: Removing unreachable block (ram,0xf0036048) */
/* WARNING: Removing unreachable block (ram,0xf003600c) */
/* WARNING: Removing unreachable block (ram,0xf0036480) */
/* WARNING: Removing unreachable block (ram,0xf0035f90) */
/* WARNING: Removing unreachable block (ram,0xf0035f58) */
/* WARNING: Removing unreachable block (ram,0xf0035f04) */
/* WARNING: Removing unreachable block (ram,0xf0035ea4) */
/* WARNING: Removing unreachable block (ram,0xf0035dac) */
/* WARNING: Removing unreachable block (ram,0xf0035d7c) */
/* WARNING: Removing unreachable block (ram,0xf0035d58) */
/* WARNING: Removing unreachable block (ram,0xf0035c88) */
/* WARNING: Removing unreachable block (ram,0xf00364cc) */
/* WARNING: Removing unreachable block (ram,0xf0035c08) */
/* WARNING: Removing unreachable block (ram,0xf0035b58) */
/* WARNING: Removing unreachable block (ram,0xf00359dc) */
/* WARNING: Removing unreachable block (ram,0xf00358a8) */
/* WARNING: Removing unreachable block (ram,0xf0035854) */
/* WARNING: Removing unreachable block (ram,0xf0035698) */
/* WARNING: Removing unreachable block (ram,0xf0035680) */
/* WARNING: Removing unreachable block (ram,0xf0035668) */
/* WARNING: Removing unreachable block (ram,0xf00355fc) */
/* WARNING: Removing unreachable block (ram,0xf0035514) */
/* WARNING: Removing unreachable block (ram,0xf0035440) */
/* WARNING: Removing unreachable block (ram,0xf00353d8) */
/* WARNING: Removing unreachable block (ram,0xf00352bc) */
/* WARNING: Removing unreachable block (ram,0xf0035250) */
/* WARNING: Removing unreachable block (ram,0xf00350d0) */
/* WARNING: Removing unreachable block (ram,0xf0035078) */
/* WARNING: Removing unreachable block (ram,0xf0034fbc) */
/* WARNING: Removing unreachable block (ram,0xf0034f7c) */
/* WARNING: Removing unreachable block (ram,0xf0035044) */
/* WARNING: Removing unreachable block (ram,0xf00350a4) */
/* WARNING: Removing unreachable block (ram,0xf0035178) */
/* WARNING: Removing unreachable block (ram,0xf0035278) */
/* WARNING: Removing unreachable block (ram,0xf00353a0) */
/* WARNING: Removing unreachable block (ram,0xf00353e8) */
/* WARNING: Removing unreachable block (ram,0xf0035508) */
/* WARNING: Removing unreachable block (ram,0xf00355e4) */
/* WARNING: Removing unreachable block (ram,0xf0035650) */
/* WARNING: Removing unreachable block (ram,0xf0035678) */
/* WARNING: Removing unreachable block (ram,0xf00356bc) */
/* WARNING: Removing unreachable block (ram,0xf003583c) */
/* WARNING: Removing unreachable block (ram,0xf003586c) */
/* WARNING: Removing unreachable block (ram,0xf00357a0) */
/* WARNING: Removing unreachable block (ram,0xf0035a4c) */
/* WARNING: Removing unreachable block (ram,0xf0035af0) */
/* WARNING: Removing unreachable block (ram,0xf00364ac) */
/* WARNING: Removing unreachable block (ram,0xf0036538) */
/* WARNING: Removing unreachable block (ram,0xf0035ca0) */
/* WARNING: Removing unreachable block (ram,0xf0035d68) */
/* WARNING: Removing unreachable block (ram,0xf0035da0) */
/* WARNING: Removing unreachable block (ram,0xf0035dec) */
/* WARNING: Removing unreachable block (ram,0xf0035efc) */
/* WARNING: Removing unreachable block (ram,0xf0035f1c) */
/* WARNING: Removing unreachable block (ram,0xf0035f48) */
/* WARNING: Removing unreachable block (ram,0xf0036068) */
/* WARNING: Removing unreachable block (ram,0xf0036494) */
/* WARNING: Removing unreachable block (ram,0xf0036038) */
/* WARNING: Removing unreachable block (ram,0xf00361f4) */
/* WARNING: Removing unreachable block (ram,0xf0036340) */
/* WARNING: Removing unreachable block (ram,0xf0036304) */
/* WARNING: Removing unreachable block (ram,0xf0036368) */
/* WARNING: Removing unreachable block (ram,0xf0036408) */
/* WARNING: Removing unreachable block (ram,0xf0036468) */
/* WARNING: Removing unreachable block (ram,0xf0036594) */
/* WARNING: Removing unreachable block (ram,0xf00365b0) */
/* WARNING: Removing unreachable block (ram,0xf0034f64) */

undefined8 _tcp_input(uint param_1)

{
  byte bVar1;
  word wVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 uVar7;
  sword sVar8;
  word wVar9;
  undefined *puVar6;
  int in_o4;
  sword sVar11;
  undefined4 uVar10;
  uint *puVar12;
  undefined4 uVar13;
  undefined4 unaff_l0;
  int iVar14;
  int iVar15;
  undefined4 unaff_l1;
  uint *puVar16;
  undefined4 *puVar17;
  undefined4 unaff_l3;
  uint uVar18;
  uint uVar19;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  byte bVar20;
  undefined4 unaff_l6;
  int iVar21;
  undefined4 unaff_l7;
  int iVar22;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar23;
  undefined4 unaff_i2;
  int iVar24;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar25;
  bool bVar26;
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
  sVar11 = (sword)in_o4;
  iVar21 = 0;
  iVar22 = 0;
  puVar16 = (uint *)0x0;
  bVar3 = false;
  iVar24 = 0;
  DAT_f013a804._0_4_ = DAT_f013a804._0_4_ + 1;
  uVar23 = 0;
  puVar17 = (undefined4 *)(param_1 + *(int *)(param_1 + 4));
  if (5 < (*(byte *)(param_1 + *(int *)(param_1 + 4)) & 0xf)) {
    _ip_stripoptions(puVar17,0);
  }
  if (*(word *)(param_1 + 8) < 0x28) {
    _m_pullup(param_1,0x28);
    if (param_1 == 0) {
      DAT_f013a804._20_4_ = DAT_f013a804._20_4_ + 1;
      goto locret_F00365B8;
    }
    puVar17 = (undefined4 *)(param_1 + *(int *)(param_1 + 4));
  }
  sVar8 = *(sword *)((int)puVar17 + 2);
  iVar14 = (int)sVar8;
  puVar17[1] = 0;
  *(undefined *)(puVar17 + 2) = 0;
  *puVar17 = 0;
  *(sword *)((int)puVar17 + 10) = sVar8;
  uVar18 = param_1;
  _in_cksum(param_1,iVar14 + 0x14);
  *(sword *)(puVar17 + 9) = (sword)uVar18;
  if ((uVar18 & 0xffff) == 0) {
    uVar18 = ((uint)puVar17[8] >> 0x1c) * 4;
    if ((0x13 < uVar18) && (uVar18 - iVar14 == 0 || (int)uVar18 < iVar14)) {
      *(word *)((int)puVar17 + 10) = sVar8 + (word)((uint)puVar17[8] >> 0x1c) * -4;
      if (uVar18 < 0x15) {
loc_F00350D8:
        bVar20 = *(byte *)((int)puVar17 + 0x21);
        puVar17[6] = puVar17[6];
        puVar17[7] = puVar17[7];
        *(undefined2 *)((int)puVar17 + 0x22) = *(undefined2 *)((int)puVar17 + 0x22);
        *(undefined2 *)((int)puVar17 + 0x26) = *(undefined2 *)((int)puVar17 + 0x26);
        do {
          sVar11 = (sword)in_o4;
          if ((((*(sword *)(_tcp_last_inpcb + 6) != *(sword *)((int)puVar17 + 0x16)) ||
               (*(sword *)(_tcp_last_inpcb + 4) != *(sword *)(puVar17 + 5))) ||
              (_tcp_last_inpcb[3] != puVar17[3])) ||
             (puVar4 = _tcp_last_inpcb, _tcp_last_inpcb[5] != puVar17[4])) {
            puVar4 = &_tcb;
            *(undefined4 *)((int)register0x00000038 + -0xc) = puVar17[3];
            *(undefined4 *)((int)register0x00000038 + -0x10) = puVar17[4];
            _in_pcblookup(&_tcb,(undefined *)((int)register0x00000038 + -0xc),
                          *(undefined2 *)(puVar17 + 5),
                          (undefined *)((int)register0x00000038 + -0x10),
                          *(undefined2 *)((int)puVar17 + 0x16),1);
            if (puVar4 != (undefined4 *)0x0) {
              _tcp_last_inpcb = puVar4;
            }
            _tcppcbcachemiss = _tcppcbcachemiss + 1;
          }
          bVar26 = iVar22 == 0;
          if (puVar4 == (undefined4 *)0x0) goto loc_F00364A4;
          puVar16 = (uint *)puVar4[8];
          bVar26 = iVar22 == 0;
          if (puVar16 == (uint *)0x0) goto loc_F00364A4;
          if (*(sword *)(puVar16 + 2) == 0) goto loc_F0036548;
          iVar21 = puVar4[7];
          wVar9 = *(word *)(iVar21 + 2);
          if ((wVar9 & 3) != 0) {
            if ((wVar9 & 1) != 0) {
              _tcp_saveti = *puVar17;
              DAT_f013a864._0_4_ = puVar17[1];
              DAT_f013a864._4_4_ = puVar17[2];
              DAT_f013a864._8_4_ = puVar17[3];
              DAT_f013a864._12_4_ = puVar17[4];
              DAT_f013a864._16_4_ = puVar17[5];
              DAT_f013a864._20_4_ = puVar17[6];
              DAT_f013a864._24_4_ = puVar17[7];
              DAT_f013a864._28_4_ = puVar17[8];
              DAT_f013a864._32_4_ = puVar17[9];
              wVar9 = *(word *)(iVar21 + 2);
              in_o4 = (int)*(sword *)(puVar16 + 2);
            }
            sVar11 = (sword)in_o4;
            if ((wVar9 & 2) != 0) {
              _sonewconn(iVar21,0);
              bVar26 = iVar22 == 0;
              if (iVar21 == 0) goto loc_F003654C;
              puVar4 = *(undefined4 **)(iVar21 + 8);
              puVar4[5] = puVar17[4];
              uVar18 = (uint)*(word *)((int)puVar17 + 0x16);
              iVar24 = iVar24 + 1;
              *(word *)(puVar4 + 6) = *(word *)((int)puVar17 + 0x16);
              _ip_srcroute();
              puVar4[0xe] = uVar18;
              puVar16 = (uint *)puVar4[8];
              *(undefined2 *)(puVar16 + 2) = 1;
            }
          }
          sVar11 = (sword)in_o4;
          *(undefined2 *)(puVar16 + 0x16) = 0;
          *(sword *)((int)puVar16 + 0xe) = (sword)_tcp_keepidle;
          if ((iVar22 != 0) && (*(sword *)(puVar16 + 2) != 1)) {
            _tcp_dooptions(puVar16,iVar22,puVar17);
            iVar22 = 0;
          }
          if (*(sword *)(puVar16 + 2) == 4) {
            if ((bVar20 & 0x37) == 0x10) {
              if (puVar17[6] == puVar16[0x10]) {
                wVar9 = *(word *)((int)puVar17 + 0x22);
                if (wVar9 == 0) {
                  iVar14 = *(int *)(param_1 + 4);
                }
                else if (wVar9 == *(word *)(puVar16 + 0xf)) {
                  uVar18 = puVar16[10];
                  if (uVar18 == puVar16[0x14]) {
                    uVar19 = puVar17[7];
                    if (*(sword *)((int)puVar17 + 10) == 0) {
                      if ((int)(uVar19 - puVar16[9]) < 1) {
loc_F003552C:
                        iVar14 = *(int *)(param_1 + 4);
                      }
                      else {
                        if (uVar19 == uVar18 || (int)(uVar19 - uVar18) < 0) {
                          if (*(word *)(puVar16 + 0x15) < wVar9) goto loc_F003552C;
                          _tcppredack = _tcppredack + 1;
                          if ((*(sword *)((int)puVar16 + 0x5a) != 0) &&
                             (0 < (int)(puVar17[7] - puVar16[0x17]))) {
                            _tcp_xmit_timer(puVar16);
                          }
                          DAT_f013a804._72_4_ = DAT_f013a804._72_4_ + 1;
                          DAT_f013a804._76_4_ = DAT_f013a804._76_4_ + (puVar17[7] - puVar16[9]);
                          _sbdrop(iVar21 + 0x3c,puVar17[7] - puVar16[9]);
                          puVar16[9] = puVar17[7];
                          _m_freem(param_1);
                          if (puVar16[9] == puVar16[0x14]) {
                            *(undefined2 *)((int)puVar16 + 10) = 0;
loc_F0035420:
                            wVar9 = *(word *)(iVar21 + 0x50);
                          }
                          else {
                            if (*(sword *)(puVar16 + 3) == 0) {
                              *(undefined2 *)((int)puVar16 + 10) = *(undefined2 *)(puVar16 + 5);
                              goto loc_F0035420;
                            }
                            wVar9 = *(word *)(iVar21 + 0x50);
                          }
                          if (((wVar9 & 4) != 0) || (*(int *)(iVar21 + 0x4c) != 0)) {
                            _sowakeup(iVar21,iVar21 + 0x3c);
                          }
                          wVar9 = *(word *)(iVar21 + 0x3c);
                          goto loc_F0036460;
                        }
                        iVar14 = *(int *)(param_1 + 4);
                      }
                    }
                    else if (uVar19 == puVar16[9]) {
                      if ((uint *)*puVar16 == puVar16) {
                        iVar14 = (uint)*(word *)(iVar21 + 0x26) - (uint)*(word *)(iVar21 + 0x24);
                        iVar15 = (uint)*(word *)(iVar21 + 0x2a) - (uint)*(word *)(iVar21 + 0x28);
                        if (iVar15 < iVar14) {
                          iVar14 = iVar15;
                        }
                        if (*(sword *)((int)puVar17 + 10) <= iVar14) {
                          puVar16[0x10] = puVar16[0x10] + (int)*(sword *)((int)puVar17 + 10);
                          DAT_f013a804._4_4_ = DAT_f013a804._4_4_ + 1;
                          DAT_f013a804._8_4_ =
                               DAT_f013a804._8_4_ + (int)*(sword *)((int)puVar17 + 10);
                          _tcppreddat = _tcppreddat + 1;
                          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
                          *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
                          _sbappend(iVar21 + 0x24);
                          _sowakeup(iVar21,iVar21 + 0x24);
                          *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 2;
                          goto locret_F00365B8;
                        }
                        iVar14 = *(int *)(param_1 + 4);
                      }
                      else {
                        iVar14 = *(int *)(param_1 + 4);
                      }
                    }
                    else {
                      iVar14 = *(int *)(param_1 + 4);
                    }
                  }
                  else {
                    iVar14 = *(int *)(param_1 + 4);
                  }
                }
                else {
                  iVar14 = *(int *)(param_1 + 4);
                }
              }
              else {
                iVar14 = *(int *)(param_1 + 4);
              }
            }
            else {
              iVar14 = *(int *)(param_1 + 4);
            }
          }
          else {
            iVar14 = *(int *)(param_1 + 4);
          }
          *(int *)(param_1 + 4) = iVar14 + 0x28;
          *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
          iVar14 = (uint)*(word *)(iVar21 + 0x26) - (uint)*(word *)(iVar21 + 0x24);
          iVar15 = (uint)*(word *)(iVar21 + 0x2a) - (uint)*(word *)(iVar21 + 0x28);
          if (iVar15 < iVar14) {
            iVar14 = iVar15;
          }
          if (iVar14 < 0) {
            iVar14 = 0;
          }
          if (iVar14 <= (int)(puVar16[0x13] - puVar16[0x10])) {
            iVar14 = puVar16[0x13] - puVar16[0x10];
          }
          sVar8 = *(sword *)(puVar16 + 2);
          *(sword *)((int)puVar16 + 0x3e) = (sword)iVar14;
          if (sVar8 == 1) {
            bVar26 = iVar22 == 0;
            if ((bVar20 & 4) != 0) goto loc_F003654C;
            bVar26 = iVar22 == 0;
            if ((bVar20 & 0x10) != 0) goto loc_F00364A4;
            puVar6 = (undefined *)((int)register0x00000038 + -0x10);
            if ((bVar20 & 2) == 0) goto loc_F0036548;
            *(undefined4 *)((int)register0x00000038 + -0x10) = puVar17[4];
            _in_broadcast();
            bVar26 = iVar22 == 0;
            if (puVar6 != (undefined *)0x0) goto loc_F003654C;
            iVar14 = 0;
            _m_get(0,8);
            if (iVar14 == 0) goto loc_F0036548;
            *(undefined2 *)(iVar14 + 8) = 0x10;
            iVar15 = *(int *)(iVar14 + 4);
            *(undefined2 *)(iVar14 + iVar15) = 2;
            iVar15 = iVar14 + iVar15;
            *(undefined4 *)(iVar15 + 4) = puVar17[3];
            *(undefined2 *)(iVar15 + 2) = *(undefined2 *)(puVar17 + 5);
            iVar15 = puVar4[5];
            if (iVar15 == 0) {
              puVar4[5] = puVar17[4];
            }
            puVar5 = puVar4;
            _in_pcbconnect(puVar4,iVar14);
            if (puVar5 != (undefined4 *)0x0) {
              puVar4[5] = iVar15;
              _m_free(iVar14);
              bVar26 = iVar22 == 0;
              goto loc_F003654C;
            }
            _m_free(iVar14);
            puVar12 = puVar16;
            _tcp_template();
            puVar16[7] = (uint)puVar12;
            if (puVar12 == (uint *)0x0) {
              _tcp_drop(puVar16,0x37);
              iVar24 = 0;
              goto loc_F0036548;
            }
            if (iVar22 != 0) {
              _tcp_dooptions(puVar16,iVar22,puVar17);
            }
            if (uVar23 == 0) {
              puVar16[0xe] = _tcp_iss;
            }
            else {
              puVar16[0xe] = uVar23;
            }
            _tcp_iss = _tcp_iss + 64000;
            uVar18 = puVar16[0xe];
            puVar16[0x12] = puVar17[6];
            puVar16[0xb] = uVar18;
            puVar16[0x14] = uVar18;
            puVar16[10] = uVar18;
            puVar16[9] = uVar18;
            *(undefined2 *)(puVar16 + 2) = 3;
            *(undefined2 *)((int)puVar16 + 0xe) = 0x96;
            puVar16[0x10] = puVar16[0x12] + 1;
            puVar16[0x13] = puVar16[0x12] + 1;
            *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
            DAT_f013a7a4._0_4_ = DAT_f013a7a4._0_4_ + 1;
loc_F0035884:
            iVar22 = puVar17[6];
loc_F0035888:
            puVar17[6] = iVar22 + 1;
            iVar22 = (int)*(sword *)((int)puVar17 + 10) - (uint)*(word *)((int)puVar16 + 0x3e);
            if ((int)(uint)*(word *)((int)puVar16 + 0x3e) < (int)*(sword *)((int)puVar17 + 10)) {
              _m_adj(param_1,-iVar22);
              *(undefined2 *)((int)puVar17 + 10) = *(undefined2 *)((int)puVar16 + 0x3e);
              bVar20 = bVar20 & 0xfe;
              DAT_f013a804._48_4_ = DAT_f013a804._48_4_ + 1;
              DAT_f013a804._52_4_ = DAT_f013a804._52_4_ + iVar22;
            }
            puVar16[0xc] = puVar17[6] - 1;
            puVar16[0x11] = puVar17[6];
            goto loc_F0036080;
          }
          if (sVar8 < 1) {
loc_F00358F4:
            uVar18 = puVar16[0x10];
          }
          else {
            if (sVar8 < 4) {
              bVar1 = bVar20 & 0x10;
              if (bVar1 != 0) {
                uVar18 = puVar17[7];
                bVar26 = iVar22 == 0;
                if (((int)(uVar18 - puVar16[0xe]) < 1) ||
                   (bVar26 = iVar22 == 0,
                   uVar18 != puVar16[0x14] && -1 < (int)(uVar18 - puVar16[0x14])))
                goto loc_F00364A4;
              }
              if ((bVar20 & 4) == 0) {
                if (*(sword *)(puVar16 + 2) == 3) goto loc_F00358F4;
                if ((bVar20 & 2) != 0) {
                  if (bVar1 == 0) {
                    *(undefined2 *)((int)puVar16 + 10) = 0;
                  }
                  else {
                    uVar18 = puVar17[7];
                    puVar16[9] = uVar18;
                    if ((int)(puVar16[10] - uVar18) < 0) {
                      puVar16[10] = uVar18;
                    }
                    *(undefined2 *)((int)puVar16 + 10) = 0;
                  }
                  uVar18 = puVar17[6];
                  puVar16[0x12] = uVar18;
                  uVar18 = uVar18 + 1;
                  puVar16[0x10] = uVar18;
                  puVar16[0x13] = uVar18;
                  *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
                  if (((bVar20 & 0x10) == 0) || ((int)(puVar16[9] - puVar16[0xe]) < 1)) {
                    *(undefined2 *)(puVar16 + 2) = 3;
                    goto loc_F0035884;
                  }
                  DAT_f013a7a4._4_4_ = DAT_f013a7a4._4_4_ + 1;
                  _soisconnected(iVar21);
                  *(undefined2 *)(puVar16 + 2) = 4;
                  _tcp_reass(puVar16,0,0);
                  if (*(sword *)((int)puVar16 + 0x5a) == 0) {
                    iVar22 = puVar17[6];
                  }
                  else {
                    _tcp_xmit_timer(puVar16);
                    iVar22 = puVar17[6];
                  }
                  goto loc_F0035888;
                }
              }
              else if (bVar1 != 0) {
                _tcp_drop(puVar16,0x3d);
              }
              goto loc_F0036548;
            }
            uVar18 = puVar16[0x10];
          }
          iVar14 = uVar18 - puVar17[6];
          if (0 < iVar14) {
            if ((bVar20 & 2) != 0) {
              puVar17[6] = puVar17[6] + 1;
              if (*(word *)((int)puVar17 + 0x26) < 2) {
                bVar20 = bVar20 & 0xdd;
              }
              else {
                *(word *)((int)puVar17 + 0x26) = *(word *)((int)puVar17 + 0x26) - 1;
                bVar20 = bVar20 & 0xfd;
              }
              iVar14 = iVar14 + -1;
            }
            if ((*(sword *)((int)puVar17 + 10) < iVar14) ||
               ((iVar14 == *(sword *)((int)puVar17 + 10) && ((bVar20 & 1) == 0)))) {
              DAT_f013a804._24_4_ = DAT_f013a804._24_4_ + 1;
              DAT_f013a804._28_4_ = DAT_f013a804._28_4_ + (int)*(sword *)((int)puVar17 + 10);
              if ((bVar20 & 1) == 0) goto loc_F0036474;
              sVar8 = *(sword *)((int)puVar17 + 10);
              bVar25 = (bVar20 & 4) == 0;
              if (iVar14 != sVar8 + 1) goto loc_F0036478;
              bVar20 = bVar20 & 0xfe;
              *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
              iVar14 = (int)sVar8;
            }
            else {
              DAT_f013a804._32_4_ = DAT_f013a804._32_4_ + 1;
              DAT_f013a804._36_4_ = DAT_f013a804._36_4_ + iVar14;
            }
            _m_adj(param_1,iVar14);
            puVar17[6] = puVar17[6] + iVar14;
            *(sword *)((int)puVar17 + 10) = *(sword *)((int)puVar17 + 10) - (sword)iVar14;
            if (iVar14 < (int)(uint)*(word *)((int)puVar17 + 0x26)) {
              *(word *)((int)puVar17 + 0x26) = *(word *)((int)puVar17 + 0x26) - (sword)iVar14;
            }
            else {
              bVar20 = bVar20 & 0xdf;
              *(undefined2 *)((int)puVar17 + 0x26) = 0;
            }
          }
          if ((*(word *)(iVar21 + 6) & 1) == 0) {
            iVar14 = (int)*(sword *)((int)puVar17 + 10);
          }
          else if (*(sword *)(puVar16 + 2) < 6) {
            iVar14 = (int)*(sword *)((int)puVar17 + 10);
          }
          else {
            if (*(sword *)((int)puVar17 + 10) != 0) {
              _tcp_close();
              DAT_f013a804._56_4_ = DAT_f013a804._56_4_ + 1;
              goto loc_F00364A0;
            }
            iVar14 = (int)*(sword *)((int)puVar17 + 10);
          }
          iVar14 = (puVar17[6] + iVar14) - (puVar16[0x10] + (uint)*(word *)((int)puVar16 + 0x3e));
          if (iVar14 < 1) goto loc_F0035B70;
          DAT_f013a804._48_4_ = DAT_f013a804._48_4_ + 1;
          if (iVar14 < *(sword *)((int)puVar17 + 10)) {
            DAT_f013a804._52_4_ = DAT_f013a804._52_4_ + iVar14;
            goto loc_F0035B54;
          }
          DAT_f013a804._52_4_ = DAT_f013a804._52_4_ + (int)*(sword *)((int)puVar17 + 10);
          if ((bVar20 & 2) == 0) goto loc_F0035B00;
          if (*(sword *)(puVar16 + 2) != 10) {
            sVar8 = *(sword *)((int)puVar16 + 0x3e);
            goto loc_F0035B04;
          }
          if ((int)(puVar17[6] - puVar16[0x10]) < 1) goto loc_F0035B00;
          uVar23 = puVar16[0x10] + 0x1f400;
          _tcp_close();
        } while( true );
      }
      if ((uint)(int)*(sword *)(param_1 + 8) < uVar18 + 0x14) {
        _m_pullup();
        if (param_1 == 0) {
          DAT_f013a804._20_4_ = DAT_f013a804._20_4_ + 1;
          goto locret_F00365B8;
        }
        puVar17 = (undefined4 *)(param_1 + *(int *)(param_1 + 4));
      }
      iVar22 = 0;
      _m_get(0,1);
      bVar26 = iVar22 == 0;
      if (!bVar26) {
        *(sword *)(iVar22 + 8) = (sword)uVar18 + -0x14;
        iVar15 = param_1 + *(int *)(param_1 + 4) + 0x28;
        _bcopy(iVar15,iVar22 + *(int *)(iVar22 + 4));
        iVar14 = (uint)*(word *)(param_1 + 8) - (uint)*(word *)(iVar22 + 8);
        *(sword *)(param_1 + 8) = (sword)iVar14;
        _bcopy(iVar15 + *(sword *)(iVar22 + 8),iVar15,(iVar14 * 0x10000 >> 0x10) + -0x28);
        goto loc_F00350D8;
      }
      goto loc_F003654C;
    }
    DAT_f013a804._16_4_ = DAT_f013a804._16_4_ + 1;
  }
  else {
    DAT_f013a804._12_4_ = DAT_f013a804._12_4_ + 1;
  }
loc_F0036548:
  bVar26 = iVar22 == 0;
loc_F003654C:
  if (!bVar26) {
    _m_free(iVar22);
  }
  if ((puVar16 != (uint *)0x0) && ((*(word *)(*(int *)(puVar16[8] + 0x1c) + 2) & 1) != 0)) {
    _tcp_trace(4,(int)sVar11,puVar16,&_tcp_saveti,0);
  }
  _m_freem(param_1);
  goto loc_F00365A8;
loc_F0035B00:
  sVar8 = *(sword *)((int)puVar16 + 0x3e);
loc_F0035B04:
  bVar25 = (bVar20 & 4) == 0;
  if ((sVar8 != 0) || (bVar25 = (bVar20 & 4) == 0, puVar17[6] != puVar16[0x10])) {
loc_F0036478:
    bVar26 = iVar22 == 0;
    if (bVar25) {
      _m_freem(param_1);
      *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
      _tcp_output();
      goto locret_F00365B8;
    }
    goto loc_F003654C;
  }
  *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
  DAT_f013a804._60_4_ = DAT_f013a804._60_4_ + 1;
loc_F0035B54:
  _m_adj(param_1,-iVar14);
  bVar20 = bVar20 & 0xf6;
  *(sword *)((int)puVar17 + 10) = *(sword *)((int)puVar17 + 10) - (sword)iVar14;
loc_F0035B70:
  if ((bVar20 & 4) != 0) {
    switch((int)((*(word *)(puVar16 + 2) - 3) * 0x10000) >> 0x10) {
    case :
      uVar7 = 0x3d;
      break;
    case :
    case :
    case :
    case :
      uVar7 = 0x36;
      break;
    case :
    case :
    case :
loc_F0036064:
      goto loc_F0036068;
    :
      goto loc_F0035C00;
    }
    *(undefined2 *)(iVar21 + 0x56) = uVar7;
    *(undefined2 *)(puVar16 + 2) = 0;
    DAT_f013a7a4._8_4_ = DAT_f013a7a4._8_4_ + 1;
loc_F0036068:
    _tcp_close();
    goto loc_F0036548;
  }
loc_F0035C00:
  if ((bVar20 & 2) == 0) {
    bVar26 = iVar22 == 0;
    if ((bVar20 & 0x10) == 0) goto loc_F003654C;
    sVar8 = *(sword *)(puVar16 + 2);
    if (sVar8 != 3) {
      if (sVar8 < 3) goto loc_F0036080;
      bVar26 = (bVar20 & 0x10) == 0;
      if (sVar8 < 0xb) {
        uVar18 = puVar17[7];
        goto loc_F0035CB8;
      }
      goto loc_F0036084;
    }
    uVar18 = puVar17[7];
    bVar26 = iVar22 == 0;
    if ((puVar16[9] != uVar18 && -1 < (int)(puVar16[9] - uVar18)) ||
       (bVar26 = iVar22 == 0, uVar18 != puVar16[0x14] && -1 < (int)(uVar18 - puVar16[0x14])))
    goto loc_F00364A4;
    DAT_f013a7a4._4_4_ = DAT_f013a7a4._4_4_ + 1;
    _soisconnected(iVar21);
    *(undefined2 *)(puVar16 + 2) = 4;
    _tcp_reass(puVar16,0,0);
    puVar16[0xc] = puVar17[6] - 1;
    uVar18 = puVar17[7];
loc_F0035CB8:
    iVar14 = _tcprexmtthresh;
    if (uVar18 == puVar16[9] || (int)(uVar18 - puVar16[9]) < 0) {
      if (*(sword *)((int)puVar17 + 10) == 0) {
        if (*(sword *)((int)puVar17 + 0x22) == *(sword *)(puVar16 + 0xf)) {
          DAT_f013a804._64_4_ = DAT_f013a804._64_4_ + 1;
          if (*(sword *)((int)puVar16 + 10) == 0) {
            *(undefined2 *)((int)puVar16 + 0x16) = 0;
          }
          else if (puVar17[7] == puVar16[9]) {
            sVar8 = *(sword *)((int)puVar16 + 0x16) + 1;
            *(sword *)((int)puVar16 + 0x16) = sVar8;
            if (sVar8 == iVar14) {
              uVar18 = (uint)*(word *)(puVar16 + 0xf);
              uVar19 = puVar16[10];
              _min(uVar18,*(undefined2 *)(puVar16 + 0x15));
              uVar18 = uVar18 >> 1;
              .udiv(uVar18,*(undefined2 *)(puVar16 + 6));
              if (uVar18 < 2) {
                uVar18 = 2;
              }
              uVar7 = (undefined2)uVar18;
              .umul();
              *(undefined2 *)((int)puVar16 + 0x56) = uVar7;
              *(undefined2 *)((int)puVar16 + 10) = 0;
              *(undefined2 *)((int)puVar16 + 0x5a) = 0;
              puVar16[10] = puVar17[7];
              *(undefined2 *)(puVar16 + 0x15) = *(undefined2 *)(puVar16 + 6);
              _tcp_output(puVar16);
              sVar8 = *(sword *)(puVar16 + 6);
              .umul(sVar8,(int)*(sword *)((int)puVar16 + 0x16));
              *(sword *)(puVar16 + 0x15) = *(sword *)((int)puVar16 + 0x56) + sVar8;
              if (0 < (int)(uVar19 - puVar16[10])) {
                puVar16[10] = uVar19;
              }
              goto loc_F0036548;
            }
            if (iVar14 < sVar8) {
              *(sword *)(puVar16 + 0x15) = *(sword *)(puVar16 + 0x15) + *(sword *)(puVar16 + 6);
              _tcp_output(puVar16);
              bVar26 = iVar22 == 0;
              goto loc_F003654C;
            }
          }
          else {
            *(undefined2 *)((int)puVar16 + 0x16) = 0;
          }
        }
        else {
          *(undefined2 *)((int)puVar16 + 0x16) = 0;
        }
      }
      else {
        *(undefined2 *)((int)puVar16 + 0x16) = 0;
      }
      goto loc_F0036080;
    }
    if (_tcprexmtthresh < *(sword *)((int)puVar16 + 0x16)) {
      if (*(word *)((int)puVar16 + 0x56) < *(word *)(puVar16 + 0x15)) {
        *(word *)(puVar16 + 0x15) = *(word *)((int)puVar16 + 0x56);
      }
      *(undefined2 *)((int)puVar16 + 0x16) = 0;
    }
    else {
      *(undefined2 *)((int)puVar16 + 0x16) = 0;
    }
    if (0 < (int)(puVar17[7] - puVar16[0x14])) {
      DAT_f013a804._68_4_ = DAT_f013a804._68_4_ + 1;
loc_F0036474:
      bVar25 = (bVar20 & 4) == 0;
      goto loc_F0036478;
    }
    iVar14 = puVar17[7] - puVar16[9];
    DAT_f013a804._72_4_ = DAT_f013a804._72_4_ + 1;
    DAT_f013a804._76_4_ = DAT_f013a804._76_4_ + iVar14;
    if (*(sword *)((int)puVar16 + 0x5a) == 0) {
      uVar18 = puVar17[7];
    }
    else if (puVar17[7] == puVar16[0x17] || (int)(puVar17[7] - puVar16[0x17]) < 0) {
      uVar18 = puVar17[7];
    }
    else {
      _tcp_xmit_timer(puVar16);
      uVar18 = puVar17[7];
    }
    if (uVar18 == puVar16[0x14]) {
      *(undefined2 *)((int)puVar16 + 10) = 0;
      bVar3 = true;
loc_F0035EE0:
      wVar9 = *(word *)(puVar16 + 6);
    }
    else {
      if (*(sword *)(puVar16 + 3) == 0) {
        *(undefined2 *)((int)puVar16 + 10) = *(undefined2 *)(puVar16 + 5);
        goto loc_F0035EE0;
      }
      wVar9 = *(word *)(puVar16 + 6);
    }
    uVar18 = (uint)wVar9;
    wVar2 = *(word *)(puVar16 + 0x15);
    if ((uint)*(word *)((int)puVar16 + 0x56) < (uint)wVar2) {
      .umul();
      .udiv();
      uVar18 = uVar18 + (wVar9 >> 3);
    }
    iVar15 = wVar2 + uVar18;
    _min(iVar15,0xffff);
    *(sword *)(puVar16 + 0x15) = (sword)iVar15;
    bVar25 = iVar14 <= (int)(uint)*(word *)(iVar21 + 0x3c);
    if (bVar25) {
      _sbdrop(iVar21 + 0x3c,iVar14);
      *(sword *)(puVar16 + 0xf) = *(sword *)(puVar16 + 0xf) - (sword)iVar14;
      wVar9 = *(word *)(iVar21 + 0x50);
    }
    else {
      *(word *)(puVar16 + 0xf) = *(sword *)(puVar16 + 0xf) - *(word *)(iVar21 + 0x3c);
      _sbdrop(iVar21 + 0x3c,*(undefined2 *)(iVar21 + 0x3c));
      wVar9 = *(word *)(iVar21 + 0x50);
    }
    bVar25 = !bVar25;
    if (((wVar9 & 4) != 0) || (*(int *)(iVar21 + 0x4c) != 0)) {
      _sowakeup(iVar21,iVar21 + 0x3c);
    }
    uVar18 = puVar17[7];
    puVar16[9] = uVar18;
    if ((int)(puVar16[10] - uVar18) < 0) {
      puVar16[10] = uVar18;
    }
    sVar8 = *(sword *)(puVar16 + 2);
    if (sVar8 == 7) {
      if (bVar25) {
        *(undefined2 *)(puVar16 + 2) = 10;
        _tcp_canceltimers(puVar16);
        *(undefined2 *)(puVar16 + 4) = 0x78;
        _soisdisconnected(iVar21);
        bVar26 = (bVar20 & 0x10) == 0;
      }
      else {
loc_F0036080:
        bVar26 = (bVar20 & 0x10) == 0;
      }
    }
    else if (sVar8 < 8) {
      if (sVar8 == 6) {
        bVar26 = (bVar20 & 0x10) == 0;
        if (bVar25) {
          if ((*(word *)(iVar21 + 6) & 0x20) != 0) {
            _soisdisconnected(iVar21);
            *(sword *)(puVar16 + 4) = (sword)_tcp_maxidle;
          }
          *(undefined2 *)(puVar16 + 2) = 9;
          goto loc_F0036080;
        }
      }
      else {
        bVar26 = (bVar20 & 0x10) == 0;
      }
    }
    else if (sVar8 == 8) {
      bVar26 = (bVar20 & 0x10) == 0;
      if (bVar25) goto loc_F0036064;
    }
    else {
      if (sVar8 == 10) {
        *(undefined2 *)(puVar16 + 4) = 0x78;
        goto loc_F0036474;
      }
      bVar26 = (bVar20 & 0x10) == 0;
    }
loc_F0036084:
    bVar25 = (bVar20 & 0x20) == 0;
    if ((!bVar26) &&
       (((int)(puVar16[0xc] - puVar17[6]) < 0 ||
        ((bVar25 = (bVar20 & 0x20) == 0, puVar16[0xc] == puVar17[6] &&
         (((int)(puVar16[0xd] - puVar17[7]) < 0 ||
          ((bVar25 = (bVar20 & 0x20) == 0, puVar16[0xd] == puVar17[7] &&
           (bVar25 = (bVar20 & 0x20) == 0, *(word *)(puVar16 + 0xf) < *(word *)((int)puVar17 + 0x22)
           )))))))))) {
      if (*(sword *)((int)puVar17 + 10) == 0) {
        if (puVar16[0xd] == puVar17[7]) {
          if (*(word *)(puVar16 + 0xf) < *(word *)((int)puVar17 + 0x22)) {
            DAT_f013a804._80_4_ = DAT_f013a804._80_4_ + 1;
          }
          uVar7 = *(undefined2 *)((int)puVar17 + 0x22);
        }
        else {
          uVar7 = *(undefined2 *)((int)puVar17 + 0x22);
        }
      }
      else {
        uVar7 = *(undefined2 *)((int)puVar17 + 0x22);
      }
      *(undefined2 *)(puVar16 + 0xf) = uVar7;
      puVar16[0xc] = puVar17[6];
      puVar16[0xd] = puVar17[7];
      if (*(word *)((int)puVar16 + 0x66) < *(word *)(puVar16 + 0xf)) {
        *(word *)((int)puVar16 + 0x66) = *(word *)(puVar16 + 0xf);
      }
      bVar3 = true;
      bVar25 = (bVar20 & 0x20) == 0;
    }
    if (bVar25) {
      uVar18 = puVar16[0x10];
loc_F0036244:
      if (uVar18 != puVar16[0x11] && -1 < (int)(uVar18 - puVar16[0x11])) {
        puVar16[0x11] = uVar18;
      }
loc_F0036258:
      iVar22 = (int)*(sword *)((int)puVar17 + 10);
    }
    else {
      uVar18 = (uint)*(word *)((int)puVar17 + 0x26);
      if (uVar18 == 0) {
        uVar18 = puVar16[0x10];
        goto loc_F0036244;
      }
      if (9 < *(sword *)(puVar16 + 2)) {
        uVar18 = puVar16[0x10];
        goto loc_F0036244;
      }
      if (0xffff < uVar18 + *(word *)(iVar21 + 0x24)) {
        *(undefined2 *)((int)puVar17 + 0x26) = 0;
        bVar20 = bVar20 & 0xdf;
        goto loc_F0036258;
      }
      uVar18 = puVar17[6] + uVar18;
      if (uVar18 == puVar16[0x11] || (int)(uVar18 - puVar16[0x11]) < 0) {
        wVar9 = *(word *)((int)puVar17 + 0x26);
      }
      else {
        puVar16[0x11] = uVar18;
        uVar18 = ((uint)*(word *)(iVar21 + 0x24) + (uVar18 - puVar16[0x10])) - 1;
        *(sword *)(iVar21 + 0x58) = (sword)uVar18;
        if ((uVar18 & 0xffff) == 0) {
          *(word *)(iVar21 + 6) = *(word *)(iVar21 + 6) | 0x40;
        }
        _sohasoutofband(iVar21);
        *(byte *)(puVar16 + 0x1a) = *(byte *)(puVar16 + 0x1a) & 0xfc;
        wVar9 = *(word *)((int)puVar17 + 0x26);
      }
      iVar22 = (int)*(sword *)((int)puVar17 + 10);
      if ((int)(uint)wVar9 <= iVar22) {
        if ((*(word *)(iVar21 + 2) & 0x100) == 0) {
          _tcp_pulloutofband(iVar21,puVar17,param_1);
          iVar22 = (int)*(sword *)((int)puVar17 + 10);
        }
        else {
          iVar22 = (int)*(sword *)((int)puVar17 + 10);
        }
      }
    }
    if (iVar22 == 0) {
      if ((bVar20 & 1) != 0) {
        sVar8 = *(sword *)(puVar16 + 2);
        goto loc_F0036278;
      }
loc_F0036340:
      _m_freem(param_1);
      puVar12 = (uint *)0x0;
    }
    else {
      sVar8 = *(sword *)(puVar16 + 2);
loc_F0036278:
      if (9 < sVar8) goto loc_F0036340;
      if (((puVar17[6] == puVar16[0x10]) && ((uint *)*puVar16 == puVar16)) && (sVar8 == 4)) {
        *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 2;
        puVar16[0x10] = puVar16[0x10] + (int)*(sword *)((int)puVar17 + 10);
        puVar12 = (uint *)(uint)*(byte *)((int)puVar17 + 0x21);
        DAT_f013a804._4_4_ = DAT_f013a804._4_4_ + 1;
        DAT_f013a804._8_4_ = DAT_f013a804._8_4_ + (int)*(sword *)((int)puVar17 + 10);
        _sbappend(iVar21 + 0x24,param_1);
        _sowakeup(iVar21,iVar21 + 0x24);
      }
      else {
        puVar12 = puVar16;
        _tcp_reass(puVar16,puVar17,param_1);
        *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
      }
    }
    if (((uint)puVar12 & 1) == 0) {
      wVar9 = *(word *)(iVar21 + 2);
    }
    else {
      if (*(sword *)(puVar16 + 2) < 10) {
        _socantrcvmore(iVar21);
        *(byte *)((int)puVar16 + 0x1b) = *(byte *)((int)puVar16 + 0x1b) | 1;
        puVar16[0x10] = puVar16[0x10] + 1;
        wVar9 = *(word *)(puVar16 + 2);
      }
      else {
        wVar9 = *(word *)(puVar16 + 2);
      }
      switch((int)((wVar9 - 3) * 0x10000) >> 0x10) {
      case :
      case :
        *(undefined2 *)(puVar16 + 2) = 5;
        break;
      case :
        *(undefined2 *)(puVar16 + 2) = 7;
        break;
      case :
        *(undefined2 *)(puVar16 + 2) = 10;
        _tcp_canceltimers(puVar16);
        *(undefined2 *)(puVar16 + 4) = 0x78;
        _soisdisconnected(iVar21);
        wVar9 = *(word *)(iVar21 + 2);
        goto loc_F0036424;
      case :
        *(undefined2 *)(puVar16 + 4) = 0x78;
      }
      wVar9 = *(word *)(iVar21 + 2);
    }
loc_F0036424:
    if ((wVar9 & 1) != 0) {
      _tcp_trace(0,(int)sVar11,puVar16,&_tcp_saveti,0);
    }
    if (!bVar3) {
      wVar9 = *(byte *)((int)puVar16 + 0x1b) & 1;
loc_F0036460:
      if (wVar9 == 0) goto locret_F00365B8;
    }
    _tcp_output(puVar16);
    goto locret_F00365B8;
  }
  _tcp_drop(puVar16,0x36);
loc_F00364A0:
  bVar26 = iVar22 == 0;
loc_F00364A4:
  if (!bVar26) {
    _m_free(iVar22);
    iVar22 = 0;
  }
  bVar26 = iVar22 == 0;
  if ((bVar20 & 4) != 0) goto loc_F003654C;
  puVar6 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x10) = puVar17[4];
  _in_broadcast();
  bVar26 = iVar22 == 0;
  if (puVar6 != (undefined *)0x0) goto loc_F003654C;
  if ((bVar20 & 0x10) == 0) {
    if ((bVar20 & 2) != 0) {
      *(sword *)((int)puVar17 + 10) = *(sword *)((int)puVar17 + 10) + 1;
    }
    uVar10 = 0;
    uVar13 = 0x14;
    iVar22 = puVar17[6] + (int)*(sword *)((int)puVar17 + 10);
  }
  else {
    iVar22 = 0;
    uVar10 = puVar17[7];
    uVar13 = 4;
  }
  _tcp_respond(puVar16,puVar17,param_1,iVar22,uVar10,uVar13);
loc_F00365A8:
  if (iVar24 != 0) {
    _soabort(iVar21);
  }
locret_F00365B8:
  return CONCAT44(uVar23,param_1);
}
/* GHIDRADEC_FUNCTION index=773 start=0xf00365c0 */

/* WARNING: Removing unreachable block (ram,0xf0036640) */
/* WARNING: Removing unreachable block (ram,0xf0036658) */
/* WARNING: Removing unreachable block (ram,0xf0036634) */

undefined8 _tcp_dooptions(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  char *pcVar3;
  int iVar4;
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
  iVar4 = (int)*(sword *)(param_2 + 8);
  pcVar3 = (char *)(param_2 + *(int *)(param_2 + 4));
  while (0 < iVar4) {
    cVar1 = *pcVar3;
    if (cVar1 == '\0') break;
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = (uint)(byte)pcVar3[1];
      if (uVar2 == 0) break;
    }
    if (cVar1 == '\x02') {
      if (uVar2 == 4) {
        if ((*(byte *)(param_3 + 0x21) & 2) == 0) {
          iVar4 = iVar4 + -4;
        }
        else {
          _bcopy(pcVar3 + 2,(undefined *)((int)register0x00000038 + -10),2);
          _tcp_mss(param_1,*(undefined2 *)((int)register0x00000038 + -10));
          iVar4 = iVar4 + -4;
        }
      }
      else {
        iVar4 = iVar4 - uVar2;
      }
    }
    else {
      iVar4 = iVar4 - uVar2;
    }
    pcVar3 = pcVar3 + uVar2;
  }
  _m_free(param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=774 start=0xf0036668 */

/* WARNING: Removing unreachable block (ram,0xf00366f4) */
/* WARNING: Removing unreachable block (ram,0xf00366c0) */

undefined8 _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
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
  iVar4 = *(word *)(param_2 + 0x26) - 1;
  if (iVar4 < 0) {
loc_F00366F4:
    _panic(aTcpPulloutofba);
  }
  else {
    sVar1 = *(sword *)(param_3 + 2);
    while (sVar1 <= iVar4) {
      param_3 = (int *)*param_3;
      iVar4 = iVar4 - sVar1;
      if ((param_3 == (int *)0x0) || (iVar4 < 0)) goto loc_F00366F4;
      sVar1 = *(sword *)(param_3 + 2);
    }
    iVar2 = param_3[1];
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x20);
    *(undefined *)(iVar3 + 0x69) = *(undefined *)((int)param_3 + iVar4 + iVar2);
    iVar2 = (int)param_3 + iVar4 + iVar2;
    *(byte *)(iVar3 + 0x68) = *(byte *)(iVar3 + 0x68) | 1;
    _bcopy(iVar2 + 1,iVar2,(*(sword *)(param_3 + 2) - iVar4) + -1);
    *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + -1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=775 start=0xf0036704 */

qword _tcp_xmit_timer(int param_1)

{
  word wVar1;
  word wVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar4;
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
  DAT_f013a7bc._0_4_ = DAT_f013a7bc._0_4_ + 1;
  wVar1 = *(word *)(param_1 + 0x60);
  uVar4 = (uint)wVar1;
  if (uVar4 == 0) {
    *(sword *)(param_1 + 0x60) = *(sword *)(param_1 + 0x5a) << 3;
    *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x5a) << 1;
  }
  else {
    iVar3 = (uint)*(word *)(param_1 + 0x5a) - (((int)(uVar4 * 0x10000) >> 0x13) + 1);
    *(sword *)(param_1 + 0x60) = (sword)(uVar4 + iVar3);
    if ((int)((uVar4 + iVar3) * 0x10000) < 1) {
      *(undefined2 *)(param_1 + 0x60) = 1;
    }
    if (iVar3 * 0x10000 < 0) {
      iVar3 = -iVar3;
    }
    iVar3 = (uint)*(word *)(param_1 + 0x62) +
            (iVar3 - ((int)((uint)*(word *)(param_1 + 0x62) << 0x10) >> 0x12));
    *(sword *)(param_1 + 0x62) = (sword)iVar3;
    if (0 < iVar3 * 0x10000) {
      *(undefined2 *)(param_1 + 0x5a) = 0;
      goto loc_F00367BC;
    }
    *(undefined2 *)(param_1 + 0x62) = 1;
  }
  *(undefined2 *)(param_1 + 0x5a) = 0;
loc_F00367BC:
  *(undefined2 *)(param_1 + 0x12) = 0;
  iVar3 = (uint)*(word *)(param_1 + 0x62) + ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x13)
  ;
  *(sword *)(param_1 + 0x14) = (sword)iVar3;
  wVar2 = *(word *)(param_1 + 100);
  iVar3 = iVar3 * 0x10000 >> 0x10;
  if ((iVar3 < (int)(uint)wVar2) || (wVar2 = 0x80, 0x80 < iVar3)) {
    *(word *)(param_1 + 0x14) = wVar2;
  }
  *(undefined2 *)(param_1 + 0x6a) = 0;
  return (qword)CONCAT24(wVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=776 start=0xf0036808 */

/* WARNING: Removing unreachable block (ram,0xf0036960) */
/* WARNING: Removing unreachable block (ram,0xf0036950) */
/* WARNING: Removing unreachable block (ram,0xf0036920) */
/* WARNING: Removing unreachable block (ram,0xf0036910) */
/* WARNING: Removing unreachable block (ram,0xf0036888) */
/* WARNING: Removing unreachable block (ram,0xf00368a4) */
/* WARNING: Removing unreachable block (ram,0xf0036918) */
/* WARNING: Removing unreachable block (ram,0xf003692c) */
/* WARNING: Removing unreachable block (ram,0xf0036958) */
/* WARNING: Removing unreachable block (ram,0xf003696c) */
/* WARNING: Removing unreachable block (ram,0xf0036840) */

undefined8 _tcp_mss(int param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined2 uVar6;
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
  iVar4 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar4 + 0x24) == 0) {
    if (*(int *)(iVar4 + 0xc) != 0) {
      *(undefined2 *)(iVar4 + 0x28) = 2;
      *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0xc);
      _rtalloc(iVar4 + 0x24);
    }
    uVar3 = _tcp_mssdflt;
    if (*(int *)(iVar4 + 0x24) == 0) goto locret_F0036978;
    iVar1 = *(int *)(*(int *)(iVar4 + 0x24) + 0x2c);
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar4 + 0x24) + 0x2c);
  }
  uVar5 = (int)*(sword *)(iVar1 + 10) - 0x28;
  iVar1 = *(int *)(iVar4 + 0x1c);
  if (0x400 < (int)uVar5) {
    uVar5 = uVar5 & 0xfffffc00;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0xc);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(iVar4 + 0xc);
  _in_localaddr();
  if (puVar2 == (undefined *)0x0) {
    _min(uVar5,_tcp_mssdflt);
  }
  uVar3 = param_2 & 0xffff;
  if ((uVar3 != 0) && ((int)uVar3 < (int)uVar5)) {
    uVar5 = uVar3;
  }
  if ((int)uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  if (((int)uVar5 < (int)(uint)*(word *)(param_1 + 0x18)) || ((param_2 & 0xffff) != 0)) {
    uVar3 = (uint)*(word *)(iVar1 + 0x3e);
    if (uVar5 <= uVar3) {
      _min(uVar3,0xffff);
      .udiv();
      .umul();
      _sbreserve(iVar1 + 0x3c,uVar3);
      uVar3 = uVar5;
    }
    uVar6 = (undefined2)uVar3;
    *(undefined2 *)(param_1 + 0x18) = uVar6;
    uVar5 = (uint)*(word *)(iVar1 + 0x26);
    if (uVar3 < uVar5) {
      _min(uVar5,0xffff);
      .udiv();
      .umul();
      _sbreserve(iVar1 + 0x24,uVar5);
      *(undefined2 *)(param_1 + 0x54) = uVar6;
    }
    else {
      *(undefined2 *)(param_1 + 0x54) = uVar6;
    }
  }
  else {
    *(sword *)(param_1 + 0x54) = (sword)uVar5;
    uVar3 = uVar5;
  }
locret_F0036978:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=777 start=0xf0036980 */

/* WARNING: Removing unreachable block (ram,0xf00370d4) */
/* WARNING: Removing unreachable block (ram,0xf0036f74) */
/* WARNING: Removing unreachable block (ram,0xf0036e4c) */
/* WARNING: Removing unreachable block (ram,0xf0036d70) */
/* WARNING: Removing unreachable block (ram,0xf0036c60) */
/* WARNING: Removing unreachable block (ram,0xf0036c38) */
/* WARNING: Removing unreachable block (ram,0xf0036c2c) */
/* WARNING: Removing unreachable block (ram,0xf0036cac) */
/* WARNING: Removing unreachable block (ram,0xf0036cb8) */
/* WARNING: Removing unreachable block (ram,0xf0036e3c) */
/* WARNING: Removing unreachable block (ram,0xf0036eac) */
/* WARNING: Removing unreachable block (ram,0xf00370a0) */
/* WARNING: Removing unreachable block (ram,0xf00370f0) */
/* WARNING: Removing unreachable block (ram,0xf0036bec) */

undefined8 _tcp_output(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  word wVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 *in_o5;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  uint uVar10;
  uint uVar11;
  undefined4 unaff_l3;
  int iVar12;
  undefined4 unaff_l4;
  byte bVar13;
  undefined4 unaff_l5;
  int iVar14;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar15;
  undefined4 unaff_i1;
  int iVar16;
  undefined4 unaff_i2;
  int iVar17;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar18;
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
  bVar18 = *(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x24);
  iVar14 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (bVar18) goto loc_F00369C4;
  if (*(sword *)(param_1 + 0x14) <= *(sword *)(param_1 + 0x58)) {
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_1 + 0x18);
    goto loc_F00369C4;
  }
  wVar5 = *(word *)(param_1 + 0x3c);
  do {
    iVar16 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    uVar11 = (uint)wVar5;
    if ((uint)*(word *)(param_1 + 0x54) < (uint)wVar5) {
      uVar11 = (uint)*(word *)(param_1 + 0x54);
    }
    if (*(char *)(param_1 + 0x1a) != '\0') {
      if (uVar11 == 0) {
        uVar11 = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    bVar13 = _tcp_outflags[*(sword *)(param_1 + 8)];
    uVar10 = (uint)*(word *)(iVar14 + 0x3c);
    if (uVar11 < *(word *)(iVar14 + 0x3c)) {
      uVar10 = uVar11;
    }
    uVar10 = uVar10 - iVar16;
    if ((int)uVar10 < 0) {
      uVar10 = 0;
      if (uVar11 == 0) {
        *(undefined2 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      }
      wVar5 = *(word *)(param_1 + 0x18);
    }
    else {
      wVar5 = *(word *)(param_1 + 0x18);
    }
    uVar8 = (uint)wVar5;
    uVar11 = uVar10;
    if ((int)uVar8 < (int)uVar10) {
      uVar11 = uVar8;
    }
    if ((int)((*(int *)(param_1 + 0x28) + uVar11) -
             (*(int *)(param_1 + 0x24) + (uint)*(word *)(iVar14 + 0x3c))) < 0) {
      bVar13 = bVar13 & 0xfe;
    }
    uVar2 = (uint)*(word *)(iVar14 + 0x24);
    iVar12 = *(word *)(iVar14 + 0x26) - uVar2;
    iVar7 = (uint)*(word *)(iVar14 + 0x2a) - (uint)*(word *)(iVar14 + 0x28);
    if (iVar7 < iVar12) {
      iVar12 = iVar7;
    }
    if (uVar11 == 0) {
loc_F0036B1C:
      if (iVar12 < 1) {
        bVar1 = *(byte *)(param_1 + 0x1b);
      }
      else {
        uVar2 = iVar12 - (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40));
        if (((int)((uint)*(word *)(param_1 + 0x18) * 2) <= (int)uVar2) ||
           (uVar2 = uVar2 * 2, (int)(uint)*(word *)(iVar14 + 0x26) <= (int)uVar2))
        goto loc_F0036C04;
        bVar1 = *(byte *)(param_1 + 0x1b);
      }
      if (((bVar1 & 1) == 0) && ((bVar13 & 6) == 0)) {
        uVar2 = *(int *)(param_1 + 0x2c) - *(uint *)(param_1 + 0x24);
        if (((int)uVar2 < 1) &&
           (((bVar13 & 1) == 0 ||
            (((bVar1 & 0x10) != 0 &&
             (uVar2 = *(uint *)(param_1 + 0x28), uVar2 != *(uint *)(param_1 + 0x24))))))) {
          if (*(sword *)(iVar14 + 0x3c) == 0) {
            piVar15 = (int *)0x0;
          }
          else if (*(sword *)(param_1 + 10) == 0) {
            if (*(sword *)(param_1 + 0xc) == 0) {
              *(undefined2 *)(param_1 + 0x12) = 0;
              _tcp_setpersist(param_1);
              piVar15 = (int *)0x0;
            }
            else {
              piVar15 = (int *)0x0;
            }
          }
          else {
            piVar15 = (int *)0x0;
          }
          goto locret_F0037178;
        }
      }
    }
    else if (((uVar11 != uVar8) &&
             (((bVar18 && ((*(byte *)(param_1 + 0x1b) & 4) == 0)) ||
              (uVar2 = uVar11 + iVar16, (int)uVar2 < (int)(uint)*(word *)(iVar14 + 0x3c))))) &&
            ((uVar2 = (uint)*(char *)(param_1 + 0x1a), uVar2 == 0 &&
             (uVar2 = (uint)(*(word *)(param_1 + 0x66) >> 1), (int)uVar11 < (int)uVar2)))) {
      uVar2 = *(uint *)(param_1 + 0x50);
      goto loc_F0036B1C;
    }
loc_F0036C04:
    iVar7 = 0;
    iVar17 = 0x28;
    if (((bVar13 & 2) != 0) && (uVar2 = param_1, (*(byte *)(param_1 + 0x1b) & 8) == 0)) {
      iVar7 = 4;
      iVar17 = 0x2c;
      in_o5 = &_tcp_initopt;
      _tcp_mss(param_1,0);
      DAT_f010c8da._0_2_ = (undefined2)uVar2;
    }
    _spltty();
    piVar15 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar15 = (int *)0x0;
      _m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_11);
      }
      *(undefined2 *)((int)piVar15 + 10) = 2;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
      _mfree = (int *)*piVar15;
      piVar15[1] = 0xc;
      *piVar15 = 0;
    }
    _splx(uVar2);
    if (piVar15 == (int *)0x0) {
      piVar15 = (int *)0x37;
      goto locret_F0037178;
    }
    piVar15[1] = 0x54 - iVar7;
    *(sword *)(piVar15 + 2) = (sword)iVar17;
    if (uVar11 == 0) {
      if ((*(byte *)(param_1 + 0x1b) & 1) == 0) {
        if ((bVar13 & 7) == 0) {
          if (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) < 1) {
            DAT_f013a7f4._8_4_ = DAT_f013a7f4._8_4_ + 1;
          }
          else {
            DAT_f013a7f4._4_4_ = DAT_f013a7f4._4_4_ + 1;
          }
        }
        else {
          DAT_f013a7f4._12_4_ = DAT_f013a7f4._12_4_ + 1;
        }
      }
      else {
        DAT_f013a7e8._8_4_ = DAT_f013a7e8._8_4_ + 1;
      }
loc_F0036E24:
      iVar6 = *(int *)(param_1 + 0x1c);
    }
    else {
      if (*(char *)(param_1 + 0x1a) == '\0') {
        iVar6 = *(int *)(param_1 + 0x28);
loc_F0036D1C:
        if (iVar6 - *(int *)(param_1 + 0x50) < 0) {
          DAT_f013a7e8._0_4_ = DAT_f013a7e8._0_4_ + 1;
          DAT_f013a7e8._4_4_ = DAT_f013a7e8._4_4_ + uVar11;
        }
        else {
          DAT_f013a7e0._0_4_ = DAT_f013a7e0._0_4_ + 1;
          DAT_f013a7e0._4_4_ = DAT_f013a7e0._4_4_ + uVar11;
        }
      }
      else {
        if (uVar11 != 1) {
          iVar6 = *(int *)(param_1 + 0x28);
          goto loc_F0036D1C;
        }
        DAT_f013a7f4._0_4_ = DAT_f013a7f4._0_4_ + 1;
      }
      iVar6 = *(int *)(iVar14 + 0x48);
      _m_copy(iVar6,iVar16,uVar11);
      *piVar15 = iVar6;
      if (iVar6 == 0) {
        uVar11 = 0;
        goto loc_F0036E24;
      }
      if (iVar16 + uVar11 == (uint)*(word *)(iVar14 + 0x3c)) {
        bVar13 = bVar13 | 8;
        goto loc_F0036E24;
      }
      iVar6 = *(int *)(param_1 + 0x1c);
    }
    iVar9 = (int)piVar15 + piVar15[1];
    if (iVar6 == 0) {
      _panic(aTcpOutput);
    }
    _bcopy(*(undefined4 *)(param_1 + 0x1c),iVar9,0x28);
    if ((bVar13 & 1) == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else if ((*(byte *)(param_1 + 0x1b) & 0x10) == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else if (*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x50)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    *(undefined4 *)(iVar9 + 0x18) = uVar3;
    *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(param_1 + 0x40);
    if (iVar7 != 0) {
      _bcopy(in_o5,iVar9 + 0x28,iVar7);
      *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) & 0xfffffff | (iVar7 + 0x14) * 0x4000000;
    }
    *(byte *)(iVar9 + 0x21) = bVar13;
    if ((iVar12 < (int)(uint)(*(word *)(iVar14 + 0x26) >> 2)) &&
       (iVar12 < (int)(uint)*(word *)(param_1 + 0x18))) {
      iVar12 = 0;
    }
    if (0xffff < iVar12) {
      iVar12 = 0xffff;
    }
    iVar6 = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40);
    if (iVar12 < iVar6) {
      iVar12 = iVar6;
    }
    *(sword *)(iVar9 + 0x22) = (sword)iVar12;
    iVar6 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28);
    if (iVar6 < 1) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
    }
    else {
      *(sword *)(iVar9 + 0x26) = (sword)iVar6;
      *(byte *)(iVar9 + 0x21) = *(byte *)(iVar9 + 0x21) | 0x20;
    }
    if (uVar11 + iVar7 != 0) {
      *(sword *)(iVar9 + 10) = (sword)iVar7 + (sword)uVar11 + 0x14;
    }
    piVar4 = piVar15;
    _in_cksum(piVar15,iVar17 + uVar11);
    *(sword *)(iVar9 + 0x24) = (sword)piVar4;
    if ((*(char *)(param_1 + 0x1a) == '\0') || (*(sword *)(param_1 + 0xc) == 0)) {
      iVar17 = *(int *)(param_1 + 0x28);
      if ((bVar13 & 3) == 0) {
loc_F0036FDC:
        iVar6 = *(int *)(param_1 + 0x28);
      }
      else {
        if ((bVar13 & 2) != 0) {
          *(int *)(param_1 + 0x28) = iVar17 + 1;
        }
        iVar6 = *(int *)(param_1 + 0x28);
        if ((bVar13 & 1) != 0) {
          *(int *)(param_1 + 0x28) = iVar6 + 1;
          *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 0x10;
          goto loc_F0036FDC;
        }
      }
      iVar6 = iVar6 + uVar11;
      *(int *)(param_1 + 0x28) = iVar6;
      if ((0 < iVar6 - *(int *)(param_1 + 0x50)) &&
         (*(int *)(param_1 + 0x50) = iVar6, *(sword *)(param_1 + 0x5a) == 0)) {
        *(undefined2 *)(param_1 + 0x5a) = 1;
        *(int *)(param_1 + 0x5c) = iVar17;
        DAT_f013a7b8._0_4_ = DAT_f013a7b8._0_4_ + 1;
      }
      if (*(sword *)(param_1 + 10) == 0) {
        if (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24)) {
          *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
          if (*(sword *)(param_1 + 0xc) != 0) {
            *(undefined2 *)(param_1 + 0xc) = 0;
            *(undefined2 *)(param_1 + 0x12) = 0;
          }
          goto loc_F0037084;
        }
        wVar5 = *(word *)(iVar14 + 2);
      }
      else {
        wVar5 = *(word *)(iVar14 + 2);
      }
    }
    else {
      iVar17 = *(int *)(param_1 + 0x28) + uVar11;
      if (iVar17 != *(int *)(param_1 + 0x50) && -1 < iVar17 - *(int *)(param_1 + 0x50)) {
        *(int *)(param_1 + 0x50) = iVar17;
      }
loc_F0037084:
      wVar5 = *(word *)(iVar14 + 2);
    }
    if ((wVar5 & 1) != 0) {
      _tcp_trace(1,(int)*(sword *)(param_1 + 8),param_1,iVar9,0);
    }
    *(sword *)(iVar9 + 2) = (sword)iVar7 + 0x28 + (sword)uVar11;
    *(undefined *)(iVar9 + 8) = 0x3c;
    _ip_output(piVar15,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
               *(int *)(param_1 + 0x20) + 0x24,*(word *)(iVar14 + 2) & 0x10,0);
    if (piVar15 != (int *)0x0) {
      if (piVar15 == (int *)0x37) {
        _tcp_quench(*(undefined4 *)(param_1 + 0x20));
        piVar15 = (int *)0x0;
        goto locret_F0037178;
      }
      if (((piVar15 != (int *)0x41) && (piVar15 != (int *)0x32)) || (*(sword *)(param_1 + 8) < 3))
      goto locret_F0037178;
      *(sword *)(param_1 + 0x6a) = (sword)piVar15;
      goto loc_F0037174;
    }
    DAT_f013a7b8._36_4_ = DAT_f013a7b8._36_4_ + 1;
    if ((0 < iVar12) &&
       (iVar12 = *(int *)(param_1 + 0x40) + iVar12,
       iVar12 != *(int *)(param_1 + 0x4c) && -1 < iVar12 - *(int *)(param_1 + 0x4c))) {
      *(int *)(param_1 + 0x4c) = iVar12;
    }
    *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) & 0xfc;
    if ((int)uVar10 <= (int)uVar8) {
loc_F0037174:
      piVar15 = (int *)0x0;
locret_F0037178:
      return CONCAT44(iVar16,piVar15);
    }
loc_F00369C4:
    wVar5 = *(word *)(param_1 + 0x3c);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=778 start=0xf0037180 */

/* WARNING: Removing unreachable block (ram,0xf00371c8) */
/* WARNING: Removing unreachable block (ram,0xf00371ac) */

undefined8 _tcp_setpersist(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined2 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x12) + (int)*(sword *)(param_1 + 0x62)
          >> 1;
  if (*(sword *)(param_1 + 10) != 0) {
    _panic(aTcpOutputRexmt);
  }
  .umul(iVar3,*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4));
  sVar1 = (sword)iVar3;
  *(sword *)(param_1 + 0xc) = sVar1;
  if (sVar1 < 10) {
    uVar2 = 10;
  }
  else {
    uVar2 = 0x78;
    if (sVar1 < 0x79) goto loc_F00371FC;
  }
  *(undefined2 *)(param_1 + 0xc) = uVar2;
loc_F00371FC:
  if (*(sword *)(param_1 + 0x12) < 0xc) {
    *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=779 start=0xf0037218 */

undefined8 _tcp_init(undefined4 param_1,undefined4 param_2)

{
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
  _tcp_iss = 1;
  DAT_f0136744._0_4_ = &_tcb;
  _tcb = &_tcb;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=780 start=0xf0037240 */

/* WARNING: Removing unreachable block (ram,0xf0037258) */

undefined8 _tcp_template(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x20);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = 0;
    _m_get(0,2);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto locret_F0037300;
    }
    *(undefined4 *)(iVar1 + 4) = 0x54;
    *(undefined2 *)(iVar1 + 8) = 0x28;
    puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4));
  }
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined *)(puVar2 + 2) = 0;
  *(undefined *)((int)puVar2 + 9) = 6;
  *(undefined2 *)((int)puVar2 + 10) = 0x14;
  puVar2[3] = *(undefined4 *)(iVar3 + 0x14);
  puVar2[4] = *(undefined4 *)(iVar3 + 0xc);
  *(undefined2 *)(puVar2 + 5) = *(undefined2 *)(iVar3 + 0x18);
  *(undefined2 *)((int)puVar2 + 0x16) = *(undefined2 *)(iVar3 + 0x10);
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = puVar2[8] & 0xffffff | 0x50000000;
  *(undefined *)((int)puVar2 + 0x21) = 0;
  *(undefined2 *)((int)puVar2 + 0x22) = 0;
  *(undefined2 *)(puVar2 + 9) = 0;
  *(undefined2 *)((int)puVar2 + 0x26) = 0;
locret_F0037300:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=781 start=0xf0037308 */

/* WARNING: Removing unreachable block (ram,0xf003746c) */
/* WARNING: Removing unreachable block (ram,0xf0037358) */
/* WARNING: Removing unreachable block (ram,0xf0037498) */
/* WARNING: Removing unreachable block (ram,0xf00373dc) */

undefined8
_tcp_respond(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,undefined param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined2 uVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
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
  uVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 0x20);
    iVar2 = *(int *)(iVar7 + 0x1c);
    iVar6 = (uint)*(word *)(iVar2 + 0x26) - (uint)*(word *)(iVar2 + 0x24);
    iVar2 = (uint)*(word *)(iVar2 + 0x2a) - (uint)*(word *)(iVar2 + 0x28);
    if (iVar2 < iVar6) {
      iVar6 = iVar2;
    }
    uVar5 = (undefined2)iVar6;
    iVar6 = iVar7 + 0x24;
  }
  puVar3 = (undefined4 *)0x0;
  if (param_3 == (undefined4 *)0x0) {
    _m_get(0,2);
    if (puVar3 == (undefined4 *)0x0) goto locret_F00374A0;
    iVar2 = puVar3[1];
    *(undefined2 *)(puVar3 + 2) = 0x28;
    *(undefined4 *)((int)puVar3 + iVar2) = *param_2;
    *(undefined4 *)((int)puVar3 + iVar2 + 4) = param_2[1];
    *(undefined4 *)((int)puVar3 + iVar2 + 8) = param_2[2];
    *(undefined4 *)((int)puVar3 + iVar2 + 0xc) = param_2[3];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x10) = param_2[4];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x14) = param_2[5];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x18) = param_2[6];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x1c) = param_2[7];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x20) = param_2[8];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x24) = param_2[9];
    param_6 = 0x10;
    param_2 = (undefined4 *)((int)puVar3 + puVar3[1]);
    param_3 = puVar3;
  }
  else {
    _m_freem(*param_3);
    *param_3 = 0;
    param_3[1] = (int)param_2 - (int)param_3;
    *(undefined2 *)(param_3 + 2) = 0x28;
    uVar4 = param_2[4];
    uVar1 = *(undefined2 *)((int)param_2 + 0x16);
    param_2[4] = param_2[3];
    param_2[3] = uVar4;
    *(undefined2 *)((int)param_2 + 0x16) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)(param_2 + 5) = uVar1;
  }
  param_2[1] = 0;
  *param_2 = 0;
  *(undefined *)(param_2 + 2) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0x14;
  param_2[6] = param_5;
  param_2[7] = param_4;
  *(undefined2 *)((int)param_2 + 0x26) = 0;
  param_2[8] = param_2[8] & 0xffffff | 0x50000000;
  *(undefined *)((int)param_2 + 0x21) = param_6;
  *(undefined2 *)((int)param_2 + 0x22) = uVar5;
  puVar3 = param_3;
  _in_cksum(param_3,0x28);
  *(sword *)(param_2 + 9) = (sword)puVar3;
  *(undefined2 *)((int)param_2 + 2) = 0x28;
  *(char *)(param_2 + 2) = (char)_tcp_ttl;
  _ip_output(param_3,0,iVar6,0,0);
locret_F00374A0:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=782 start=0xf00374a8 */

/* WARNING: Removing unreachable block (ram,0xf00374cc) */
/* WARNING: Removing unreachable block (ram,0xf00374b0) */

undefined8 _tcp_newtcpcb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  iVar3 = 0x6c;
  _kalloc();
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    _bzero(iVar3,0x6c);
    *(int *)(iVar3 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(iVar3 + 0x20) = param_1;
    *(undefined2 *)(iVar3 + 100) = 2;
    *(undefined2 *)(iVar3 + 0x14) = 0xc;
    *(undefined2 *)(iVar3 + 0x54) = 0xffff;
    *(undefined2 *)(iVar3 + 0x56) = 0xffff;
    uVar1 = _tcp_mssdflt;
    *(undefined2 *)(iVar3 + 0x60) = 0;
    *(undefined *)(iVar3 + 0x1b) = 0;
    iVar2 = _tcp_rttdflt;
    *(sword *)(iVar3 + 0x18) = (sword)uVar1;
    *(sword *)(iVar3 + 0x62) = (sword)(iVar2 << 3);
    *(int *)(param_1 + 0x20) = iVar3;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=783 start=0xf003752c */

/* WARNING: Removing unreachable block (ram,0xf003759c) */
/* WARNING: Removing unreachable block (ram,0xf0037548) */

undefined8 _tcp_drop(int param_1,int param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (*(sword *)(param_1 + 8) < 3) {
    DAT_f013a7ac._4_4_ = DAT_f013a7ac._4_4_ + 1;
  }
  else {
    *(undefined2 *)(param_1 + 8) = 0;
    _tcp_output(param_1);
    DAT_f013a7ac._0_4_ = DAT_f013a7ac._0_4_ + 1;
  }
  if (param_2 == 0x3c) {
    if (*(sword *)(param_1 + 0x6a) != 0) {
      param_2 = (int)*(sword *)(param_1 + 0x6a);
    }
    *(sword *)(iVar1 + 0x56) = (sword)param_2;
  }
  else {
    *(sword *)(iVar1 + 0x56) = (sword)param_2;
  }
  _tcp_close(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=784 start=0xf00375ac */

/* WARNING: Removing unreachable block (ram,0xf0037620) */
/* WARNING: Removing unreachable block (ram,0xf0037608) */
/* WARNING: Removing unreachable block (ram,0xf0037614) */
/* WARNING: Removing unreachable block (ram,0xf0037644) */
/* WARNING: Removing unreachable block (ram,0xf00375e4) */

sqword _tcp_close(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  undefined4 uVar5;
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
  puVar4 = (undefined4 *)param_1[8];
  uVar5 = puVar4[7];
  if ((int *)*param_1 != param_1) {
    piVar3 = *(int **)*param_1;
    while( true ) {
      piVar2 = (int *)piVar3[1];
      iVar1 = piVar2[5];
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      _m_freem(iVar1);
      if (piVar3 == param_1) break;
      piVar3 = (int *)*piVar3;
    }
  }
  if (param_1[7] != 0) {
    _m_free(param_1[7] & 0xffffff80);
  }
  _kfree(param_1,0x6c);
  puVar4[8] = 0;
  _soisdisconnected(uVar5);
  if (puVar4 == _tcp_last_inpcb) {
    _tcp_last_inpcb = &_tcb;
  }
  _in_pcbdetach(puVar4);
  DAT_f013a7b4._0_4_ = DAT_f013a7b4._0_4_ + 1;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=785 start=0xf0037668 */

undefined8 _tcp_drain(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=786 start=0xf0037674 */

/* WARNING: Removing unreachable block (ram,0xf00376d8) */
/* WARNING: Removing unreachable block (ram,0xf00376c0) */
/* WARNING: Removing unreachable block (ram,0xf00376cc) */

undefined8 _tcp_notify(int param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x1c);
  sVar1 = *(sword *)(iVar2 + 0x56);
  if (*(sword *)(iVar2 + 6) == 4) {
    iVar2 = *(int *)(param_1 + 0x20);
loc_F00376B8:
    *(sword *)(iVar2 + 0x6a) = sVar1;
    _wakeup(*(int *)(param_1 + 0x1c) + 0x54);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x24);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x3c);
  }
  else {
    if ((sVar1 != 0x41) && (sVar1 != 0x33)) {
      if (sVar1 != 0x40) {
        iVar2 = *(int *)(param_1 + 0x20);
        goto loc_F00376B8;
      }
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    *(undefined2 *)(iVar2 + 0x56) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=787 start=0xf00376e8 */

/* WARNING: Removing unreachable block (ram,0xf0037788) */

undefined8 _tcp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
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
  pcVar2 = _tcp_notify;
  if (param_1 == 4) {
    pcVar2 = _tcp_quench;
  }
  else if ((0x15 < param_1) || (_inetctlerrmap[param_1] == '\0')) goto locret_F0037790;
  if (param_3 == (byte *)0x0) {
    uVar3 = 0;
    uVar5 = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = _zeroin_addr;
  }
  else {
    bVar1 = *param_3;
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_3 + 0xc);
    iVar4 = (bVar1 & 0xf) * 4;
    uVar3 = *(undefined2 *)(param_3 + iVar4 + 2);
    uVar5 = *(undefined2 *)(param_3 + iVar4);
  }
  _in_pcbnotify(&_tcb,param_2,uVar3,(undefined *)((int)register0x00000038 + -0xc),uVar5,param_1,
                pcVar2);
locret_F0037790:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=788 start=0xf0037798 */

undefined8 _tcp_quench(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x54) = *(undefined2 *)(iVar1 + 0x18);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=789 start=0xf00377bc */

/* WARNING: Removing unreachable block (ram,0xf003782c) */
/* WARNING: Removing unreachable block (ram,0xf0037844) */
/* WARNING: Removing unreachable block (ram,0xf00377c0) */

undefined8 _tcp_fasttimo(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  uVar1 = param_1;
  _splnet();
  if ((_tcb != (undefined4 *)0x0) && ((undefined4 **)_tcb != &_tcb)) {
    iVar2 = _tcb[8];
    puVar3 = _tcb;
    while( true ) {
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else if ((*(byte *)(iVar2 + 0x1b) & 2) == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) & 0xfd | 1;
        DAT_f013a7c0._0_4_ = DAT_f013a7c0._0_4_ + 1;
        _tcp_output(iVar2);
        puVar3 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar3 == &_tcb) break;
      iVar2 = puVar3[8];
    }
  }
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=790 start=0xf0037854 */

/* WARNING: Removing unreachable block (ram,0xf00378f0) */
/* WARNING: Removing unreachable block (ram,0xf0037968) */
/* WARNING: Removing unreachable block (ram,0xf0037858) */

undefined8 _tcp_slowtimo(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 *puVar5;
  undefined4 unaff_l4;
  undefined4 *puVar6;
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
  _splnet();
  _tcp_maxidle = _tcp_keepintvl << 3;
  if (_tcb != (undefined4 *)0x0) {
    if ((undefined4 **)_tcb != &_tcb) {
      iVar2 = _tcb[8];
      puVar5 = _tcb;
      do {
        puVar6 = (undefined4 *)*puVar5;
        if (iVar2 != 0) {
          iVar4 = 0;
          iVar3 = iVar2;
          do {
            if (((*(sword *)(iVar3 + 10) != 0) &&
                (uVar1 = (int)*(sword *)(iVar3 + 10) - 1, *(sword *)(iVar3 + 10) = (sword)uVar1,
                (uVar1 & 0xffff) == 0)) &&
               (_tcp_usrreq(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x1c),0x13,0,iVar4,0),
               (undefined4 *)puVar6[1] != puVar5)) goto loc_F0037940;
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 2;
          } while (iVar4 < 4);
          *(sword *)(iVar2 + 0x58) = *(sword *)(iVar2 + 0x58) + 1;
          if (*(sword *)(iVar2 + 0x5a) != 0) {
            *(sword *)(iVar2 + 0x5a) = *(sword *)(iVar2 + 0x5a) + 1;
          }
        }
loc_F0037940:
        if ((undefined4 **)puVar6 == &_tcb) break;
        iVar2 = puVar6[8];
        puVar5 = puVar6;
      } while( true );
    }
    _tcp_iss = _tcp_iss + 64000;
  }
  _splx();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=791 start=0xf0037978 */

undefined8 _tcp_canceltimers(int param_1,undefined4 param_2)

{
  int iVar1;
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
  *(undefined2 *)(param_1 + 0x10) = 0;
  iVar1 = param_1 + 6;
  while (param_1 <= iVar1 + -2) {
    *(undefined2 *)(iVar1 + 8) = 0;
    iVar1 = iVar1 + -2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=792 start=0xf003799c */

/* WARNING: Removing unreachable block (ram,0xf0037b4c) */
/* WARNING: Removing unreachable block (ram,0xf0037b24) */
/* WARNING: Removing unreachable block (ram,0xf0037a8c) */
/* WARNING: Removing unreachable block (ram,0xf0037a04) */
/* WARNING: Removing unreachable block (ram,0xf0037b78) */
/* WARNING: Removing unreachable block (ram,0xf0037c10) */
/* WARNING: Removing unreachable block (ram,0xf0037ad8) */
/* WARNING: Removing unreachable block (ram,0xf0037b40) */
/* WARNING: Removing unreachable block (ram,0xf0037c50) */
/* WARNING: Removing unreachable block (ram,0xf0037b68) */

undefined8 _tcp_timers(int param_1,uint param_2)

{
  word wVar1;
  int iVar2;
  sword sVar4;
  uint uVar3;
  undefined2 uVar5;
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
  if (param_2 == 1) {
    DAT_f013a7c4._8_4_ = DAT_f013a7c4._8_4_ + 1;
    _tcp_setpersist(param_1);
    *(undefined *)(param_1 + 0x1a) = 1;
    _tcp_output(param_1);
    *(undefined *)(param_1 + 0x1a) = 0;
    goto locret_F0037C5C;
  }
  if ((int)param_2 < 2) {
    if (param_2 != 0) goto locret_F0037C5C;
    sVar4 = *(sword *)(param_1 + 0x12) + 1;
    *(sword *)(param_1 + 0x12) = sVar4;
    if (sVar4 < 0xd) {
      DAT_f013a7c4._4_4_ = DAT_f013a7c4._4_4_ + 1;
      iVar2 = ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x13) +
              (int)*(sword *)(param_1 + 0x62);
      .umul(iVar2,*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4));
      sVar4 = (sword)iVar2;
      *(sword *)(param_1 + 0x14) = sVar4;
      if ((int)sVar4 < (int)(uint)*(word *)(param_1 + 100)) {
        *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
      }
      else if (0x80 < sVar4) {
        *(undefined2 *)(param_1 + 0x14) = 0x80;
      }
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
      if (3 < *(sword *)(param_1 + 0x12)) {
        _in_losing(*(undefined4 *)(param_1 + 0x20));
        *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 2);
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      *(undefined2 *)(param_1 + 0x5a) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      uVar3 = (uint)*(word *)(param_1 + 0x3c);
      if ((uint)*(word *)(param_1 + 0x54) < (uint)*(word *)(param_1 + 0x3c)) {
        uVar3 = (uint)*(word *)(param_1 + 0x54);
      }
      wVar1 = *(word *)(param_1 + 0x18);
      param_2 = (uint)wVar1;
      uVar3 = uVar3 >> 1;
      .div(uVar3,param_2);
      if (uVar3 < 2) {
        uVar3 = 2;
      }
      uVar5 = (undefined2)uVar3;
      *(word *)(param_1 + 0x54) = wVar1;
      *(undefined2 *)(param_1 + 0x16) = 0;
      .umul();
      *(undefined2 *)(param_1 + 0x56) = uVar5;
      _tcp_output(param_1);
      goto locret_F0037C5C;
    }
    *(undefined2 *)(param_1 + 0x12) = 0xc;
    DAT_f013a7c4._0_4_ = DAT_f013a7c4._0_4_ + 1;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        if ((*(sword *)(param_1 + 8) == 10) || (_tcp_maxidle < *(sword *)(param_1 + 0x58))) {
          _tcp_close(param_1);
        }
        else {
          *(sword *)(param_1 + 0x10) = (sword)_tcp_keepintvl;
        }
      }
      goto locret_F0037C5C;
    }
    DAT_f013a7c4._12_4_ = DAT_f013a7c4._12_4_ + 1;
    if (3 < *(sword *)(param_1 + 8)) {
      if (((*(word *)(*(int *)(*(int *)(param_1 + 0x20) + 0x1c) + 2) & 8) == 0) ||
         (5 < *(sword *)(param_1 + 8))) {
        *(sword *)(param_1 + 0xe) = (sword)_tcp_keepidle;
        goto locret_F0037C5C;
      }
      if ((int)*(sword *)(param_1 + 0x58) < _tcp_keepidle + _tcp_maxidle) {
        DAT_f013a7c4._16_4_ = DAT_f013a7c4._16_4_ + 1;
        _tcp_respond(param_1,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x40),
                     *(int *)(param_1 + 0x24) + -1,0);
        *(sword *)(param_1 + 0xe) = (sword)_tcp_keepintvl;
        goto locret_F0037C5C;
      }
    }
    DAT_f013a7c4._20_4_ = DAT_f013a7c4._20_4_ + 1;
  }
  _tcp_drop(param_1,0x3c);
locret_F0037C5C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=793 start=0xf0037c64 */

/* WARNING: Removing unreachable block (ram,0xf0038110) */
/* WARNING: Removing unreachable block (ram,0xf0037dcc) */
/* WARNING: Removing unreachable block (ram,0xf0037de0) */
/* WARNING: Removing unreachable block (ram,0xf0037e74) */
/* WARNING: Removing unreachable block (ram,0xf0037e84) */
/* WARNING: Removing unreachable block (ram,0xf0037e4c) */
/* WARNING: Removing unreachable block (ram,0xf0037f30) */
/* WARNING: Removing unreachable block (ram,0xf0037f48) */
/* WARNING: Removing unreachable block (ram,0xf0037f7c) */
/* WARNING: Removing unreachable block (ram,0xf0037f94) */
/* WARNING: Removing unreachable block (ram,0xf0038084) */
/* WARNING: Removing unreachable block (ram,0xf003809c) */
/* WARNING: Removing unreachable block (ram,0xf00380c4) */
/* WARNING: Removing unreachable block (ram,0xf0037cdc) */
/* WARNING: Removing unreachable block (ram,0xf00380b0) */
/* WARNING: Removing unreachable block (ram,0xf0038064) */
/* WARNING: Removing unreachable block (ram,0xf0038054) */
/* WARNING: Removing unreachable block (ram,0xf00380e0) */
/* WARNING: Removing unreachable block (ram,0xf0037f5c) */
/* WARNING: Removing unreachable block (ram,0xf0037f28) */
/* WARNING: Removing unreachable block (ram,0xf0037e34) */
/* WARNING: Removing unreachable block (ram,0xf0037e60) */
/* WARNING: Removing unreachable block (ram,0xf0037f68) */
/* WARNING: Removing unreachable block (ram,0xf0037e04) */
/* WARNING: Removing unreachable block (ram,0xf0037eec) */
/* WARNING: Removing unreachable block (ram,0xf0037d74) */
/* WARNING: Removing unreachable block (ram,0xf0038118) */
/* WARNING: Removing unreachable block (ram,0xf0037cb8) */
/* WARNING: Removing unreachable block (ram,0xf0037c84) */

undefined8 _tcp_usrreq(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  word wVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar8;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  iVar5 = 0;
  iVar7 = 0;
  if (param_2 == 0xb) {
    _in_control(param_1,param_3,param_4);
    iVar7 = param_1;
    goto locret_F0038120;
  }
  iVar2 = param_1;
  if ((param_5 != 0) && (iVar2 = 0, *(sword *)(param_5 + 8) != 0)) {
    iVar7 = 0x16;
    goto locret_F0038120;
  }
  _splnet();
  iVar8 = *(int *)(param_1 + 8);
  if ((iVar8 == 0) && (param_2 != 0)) {
    iVar7 = 0x16;
    _splx();
    goto locret_F0038120;
  }
  iVar6 = 0;
  if (iVar8 != 0) {
    iVar5 = *(int *)(iVar8 + 0x20);
    iVar6 = (int)*(sword *)(iVar5 + 8);
  }
  switch(param_2) {
  case :
    iVar7 = 0x38;
    if (iVar8 == 0) {
      iVar7 = param_1;
      _tcp_attach();
      bVar9 = iVar5 == 0;
      if (iVar7 != 0) goto loc_F00380EC;
      if ((*(word *)(param_1 + 2) & 0x80) == 0) {
        iVar5 = *(int *)(param_1 + 8);
      }
      else if (*(sword *)(param_1 + 4) == 0) {
        *(undefined2 *)(param_1 + 4) = 0x78;
        iVar5 = *(int *)(param_1 + 8);
      }
      else {
        iVar5 = *(int *)(param_1 + 8);
      }
      iVar5 = *(int *)(iVar5 + 0x20);
    }
    break;
  case :
    if (1 < *(sword *)(iVar5 + 8)) goto loc_F0037EEC;
    _tcp_close();
    break;
  case :
    _in_pcbbind(iVar8,param_4);
    iVar7 = iVar8;
    break;
  case :
    if (*(sword *)(iVar8 + 0x18) == 0) {
      _in_pcbbind(iVar8,0);
      iVar7 = iVar8;
    }
    bVar9 = iVar5 == 0;
    if (iVar7 == 0) {
      *(undefined2 *)(iVar5 + 8) = 1;
    }
    goto loc_F00380EC;
  case :
    if (*(sword *)(iVar8 + 0x18) == 0) {
      iVar7 = iVar8;
      _in_pcbbind(iVar8,0);
      bVar9 = iVar5 == 0;
      if (iVar7 != 0) goto loc_F00380EC;
    }
    iVar7 = iVar8;
    _in_pcbconnect(iVar8,param_4);
    bVar9 = iVar5 == 0;
    if (iVar7 == 0) {
      iVar7 = iVar5;
      _tcp_template();
      *(int *)(iVar5 + 0x1c) = iVar7;
      if (iVar7 != 0) {
        _soisconnecting(param_1);
        _tcpstat = _tcpstat + 1;
        *(undefined2 *)(iVar5 + 8) = 2;
        *(undefined2 *)(iVar5 + 0xe) = 0x96;
        *(int *)(iVar5 + 0x38) = _tcp_iss;
        _tcp_iss = _tcp_iss + 64000;
        uVar3 = *(undefined4 *)(iVar5 + 0x38);
        *(undefined4 *)(iVar5 + 0x2c) = uVar3;
        *(undefined4 *)(iVar5 + 0x50) = uVar3;
        *(undefined4 *)(iVar5 + 0x28) = uVar3;
        *(undefined4 *)(iVar5 + 0x24) = uVar3;
        goto loc_F0037F68;
      }
      _in_pcbdisconnect(iVar8);
      iVar7 = 0x37;
      break;
    }
    goto loc_F00380EC;
  case :
    *(undefined2 *)(param_4 + 8) = 0x10;
    iVar4 = *(int *)(param_4 + 4);
    *(undefined2 *)(param_4 + iVar4) = 2;
    iVar4 = param_4 + iVar4;
    *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar8 + 0x10);
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar8 + 0xc);
    break;
  case :
loc_F0037EEC:
    _tcp_disconnect();
    break;
  case :
    _socantsendmore(param_1);
    _tcp_usrclosed();
    bVar9 = iVar5 == 0;
    if (!bVar9) goto loc_F0037F68;
    goto loc_F00380EC;
  case :
    _tcp_output(iVar5);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    _sbappend(param_1 + 0x3c,param_3);
loc_F0037F68:
    iVar7 = iVar5;
    _tcp_output();
    break;
  case :
    _tcp_drop(iVar5,0x35);
    break;
  :
    _panic(aTcpUsrreq);
    break;
  case :
    *(uint *)(param_3 + 0x30) = (uint)*(word *)(param_1 + 0x3e);
    _splx(iVar2);
    iVar7 = 0;
    goto locret_F0038120;
  case :
    if (*(sword *)(param_1 + 0x58) == 0) {
      if ((*(word *)(param_1 + 6) & 0x40) == 0) {
        iVar7 = 0x16;
        break;
      }
      wVar1 = *(word *)(param_1 + 2);
    }
    else {
      wVar1 = *(word *)(param_1 + 2);
    }
    if ((wVar1 & 0x100) == 0) {
      if ((*(byte *)(iVar5 + 0x68) & 2) == 0) {
        if ((*(byte *)(iVar5 + 0x68) & 1) == 0) {
          iVar7 = 0x23;
        }
        else {
          *(undefined2 *)(param_3 + 8) = 1;
          *(undefined *)(param_3 + *(int *)(param_3 + 4)) = *(undefined *)(iVar5 + 0x69);
          if ((param_4 & 2) == 0) {
            *(byte *)(iVar5 + 0x68) = *(byte *)(iVar5 + 0x68) ^ 3;
          }
        }
      }
      else {
        iVar7 = 0x16;
      }
    }
    else {
      iVar7 = 0x16;
    }
    break;
  case :
    iVar7 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
    iVar8 = (uint)*(word *)(param_1 + 0x42) - (uint)*(word *)(param_1 + 0x40);
    if (iVar8 < iVar7) {
      iVar7 = iVar8;
    }
    if (iVar7 < -0x200) {
      _m_freem(param_3);
      iVar7 = 0x37;
    }
    else {
      _sbappend(param_1 + 0x3c,param_3);
      *(uint *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x24) + (uint)*(word *)(param_1 + 0x3c);
      *(undefined *)(iVar5 + 0x1a) = 1;
      iVar7 = iVar5;
      _tcp_output(iVar5);
      *(undefined *)(iVar5 + 0x1a) = 0;
    }
    break;
  case :
    _in_setsockaddr(iVar8,param_4);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    _in_setpeeraddr(iVar8,param_4);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    iVar7 = 0x2d;
    break;
  case :
    _tcp_timers(iVar5,param_4);
    param_2 = param_2 | param_4 << 8;
  }
  bVar9 = iVar5 == 0;
loc_F00380EC:
  if ((!bVar9) && ((*(word *)(param_1 + 2) & 1) != 0)) {
    _tcp_trace(2,iVar6,iVar5,0,param_2);
  }
  _splx(iVar2);
locret_F0038120:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=794 start=0xf0038128 */

/* WARNING: Removing unreachable block (ram,0xf00381d8) */
/* WARNING: Removing unreachable block (ram,0xf00381ec) */
/* WARNING: Removing unreachable block (ram,0xf0038150) */

undefined8 _tcp_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar3 = 0;
  iVar2 = *(int *)(*(int *)(param_2 + 8) + 0x20);
  if (param_3 == 6) {
    if (param_1 == 0) {
      iVar1 = 1;
      _m_get(1,10);
      *param_5 = iVar1;
      *(undefined2 *)(iVar1 + 8) = 4;
      if (param_4 == 1) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = *(byte *)(iVar2 + 0x1b) & 4;
      }
      else if (param_4 == 2) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)*(word *)(iVar2 + 0x18);
      }
      else {
        iVar3 = 0x16;
      }
    }
    else if (param_1 == 1) {
      iVar1 = *param_5;
      if (param_4 == 1) {
        if (iVar1 == 0) {
          iVar3 = 0x16;
        }
        else if (*(word *)(iVar1 + 8) < 4) {
          iVar3 = 0x16;
        }
        else if (*(int *)(iVar1 + *(int *)(iVar1 + 4)) == 0) {
          *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) & 0xfb;
        }
        else {
          *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) | 4;
        }
      }
      else {
        iVar3 = 0x16;
      }
      if (iVar1 != 0) {
        _m_free(iVar1);
      }
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    _ip_ctloutput(param_1,param_2,param_3,param_4,param_5);
    iVar3 = param_1;
  }
  return CONCAT44(iVar2,iVar3);
}
/* GHIDRADEC_FUNCTION index=795 start=0xf0038248 */

/* WARNING: Removing unreachable block (ram,0xf00382b4) */
/* WARNING: Removing unreachable block (ram,0xf003829c) */
/* WARNING: Removing unreachable block (ram,0xf00382e0) */
/* WARNING: Removing unreachable block (ram,0xf0038280) */

undefined8 _tcp_attach(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  int iVar3;
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
  if ((((*(sword *)(param_1 + 0x3e) != 0) && (*(sword *)(param_1 + 0x26) != 0)) ||
      (iVar3 = param_1, _soreserve(param_1,_tcp_sendspace,_tcp_recvspace), iVar3 == 0)) &&
     (iVar3 = param_1, _in_pcballoc(param_1,&_tcb), iVar3 == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    iVar3 = iVar2;
    _tcp_newtcpcb();
    if (iVar3 == 0) {
      wVar1 = *(word *)(param_1 + 6);
      *(word *)(param_1 + 6) = wVar1 & 0xfffe;
      _in_pcbdetach(iVar2);
      iVar3 = 0x37;
      *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | wVar1 & 1;
    }
    else {
      *(undefined2 *)(iVar3 + 8) = 0;
      iVar3 = 0;
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=796 start=0xf0038300 */

/* WARNING: Removing unreachable block (ram,0xf0038348) */
/* WARNING: Removing unreachable block (ram,0xf0038368) */
/* WARNING: Removing unreachable block (ram,0xf0038360) */
/* WARNING: Removing unreachable block (ram,0xf003837c) */
/* WARNING: Removing unreachable block (ram,0xf0038318) */
/* WARNING: Removing unreachable block (ram,0xf0038358) */

undefined8 _tcp_disconnect(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (*(sword *)(param_1 + 8) < 4) {
    _tcp_close(param_1);
  }
  else if (((*(word *)(iVar1 + 2) & 0x80) == 0) || (*(sword *)(iVar1 + 4) != 0)) {
    _soisdisconnecting(iVar1);
    _sbflush(iVar1 + 0x24);
    _tcp_usrclosed();
    if (param_1 != 0) {
      _tcp_output();
    }
  }
  else {
    _tcp_drop(param_1,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=797 start=0xf003838c */

/* WARNING: Removing unreachable block (ram,0xf0038410) */
/* WARNING: Removing unreachable block (ram,0xf00383d0) */

undefined8 _tcp_usrclosed(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
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
  switch(*(undefined2 *)(param_1 + 8)) {
  case :
  case :
  case :
    *(undefined2 *)(param_1 + 8) = 0;
    _tcp_close();
    goto def_F00383AC;
  case :
  case :
    uVar1 = 6;
    break;
  case :
    uVar1 = 8;
    break;
  :
    goto def_F00383AC;
  }
  *(undefined2 *)(param_1 + 8) = uVar1;
def_F00383AC:
  if ((param_1 != 0) && (8 < *(sword *)(param_1 + 8))) {
    _soisdisconnected(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=798 start=0xf0038420 */

undefined8 _udp_init(undefined4 param_1,undefined4 param_2)

{
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
  DAT_f0136504._0_4_ = &_udb;
  _udb = &_udb;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=799 start=0xf003843c */

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

