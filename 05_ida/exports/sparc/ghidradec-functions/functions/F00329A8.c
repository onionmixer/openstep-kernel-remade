
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
