
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

