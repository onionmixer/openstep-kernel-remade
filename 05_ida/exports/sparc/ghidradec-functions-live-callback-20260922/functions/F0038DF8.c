
/* WARNING: Removing unreachable block (ram,0xf00390e0) */
/* WARNING: Removing unreachable block (ram,0xf0038f5c) */
/* WARNING: Removing unreachable block (ram,0xf0038ea4) */
/* WARNING: Removing unreachable block (ram,0xf0038ecc) */
/* WARNING: Removing unreachable block (ram,0xf0039010) */
/* WARNING: Removing unreachable block (ram,0xf0039200) */
/* WARNING: Removing unreachable block (ram,0xf0038e64) */
/* WARNING: Removing unreachable block (ram,0xf0038e3c) */

undefined8 _igmp_input(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l1;
  int iVar7;
  int iVar8;
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
  bool bVar9;
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
  _igmpstat = _igmpstat + 1;
  uVar4 = *(uint *)(param_1 + 4);
  iVar8 = (int)*(sword *)(param_1 + uVar4 + 2);
  uVar2 = *(byte *)(param_1 + uVar4) & 0xf;
  iVar5 = uVar2 * 4;
  if (iVar8 < 8) {
    DAT_f013a8a4._0_4_ = DAT_f013a8a4._0_4_ + 1;
    _m_freem(param_1);
    goto locret_F0039208;
  }
  if (((0x7c < uVar4) || ((int)*(sword *)(param_1 + 8) < iVar5 + 8)) && (_m_pullup(), param_1 == 0))
  {
    DAT_f013a8a4._0_4_ = DAT_f013a8a4._0_4_ + 1;
    goto locret_F0039208;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar5;
  iVar7 = *(int *)(param_1 + 4);
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)uVar2 * -4;
  iVar3 = param_1;
  _in_cksum(param_1,iVar8);
  iVar8 = param_1 + iVar7;
  if (iVar3 != 0) {
    DAT_f013a8a4._4_4_ = DAT_f013a8a4._4_4_ + 1;
    _m_freem(param_1);
    goto locret_F0039208;
  }
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar2 * -4;
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)iVar5;
  cVar1 = *(char *)(param_1 + iVar7);
  iVar5 = param_1 + *(int *)(param_1 + 4);
  if (cVar1 == '\x11') {
    DAT_f013a8a4._8_4_ = DAT_f013a8a4._8_4_ + 1;
    if (param_2 != _loifp) {
      if (*(int *)(iVar5 + 0x10) != dword_F012F4E8) {
        DAT_f013a8a4._12_4_ = DAT_f013a8a4._12_4_ + 1;
        _m_freem(param_1);
        goto locret_F0039208;
      }
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      piVar6 = (int *)0x0;
      *(int *)((int)register0x00000038 + -0x10) = _in_ifaddr;
      if (_in_ifaddr != 0) {
        iVar8 = *(int *)((int)register0x00000038 + -0x10);
        do {
          piVar6 = *(int **)(iVar8 + 0x44);
          iVar3 = *(int *)(iVar8 + 0x40);
          *(int *)((int)register0x00000038 + -0x10) = iVar3;
          if (piVar6 != (int *)0x0) {
            *(int *)((int)register0x00000038 + -0xc) = piVar6[5];
            break;
          }
          iVar8 = *(int *)((int)register0x00000038 + -0x10);
        } while (iVar3 != 0);
      }
      if (piVar6 != (int *)0x0) {
        iVar8 = piVar6[1];
        do {
          if (iVar8 == param_2) {
            if (piVar6[4] == 0) {
              if (*piVar6 != dword_F012F4E8) {
                iVar8 = _ipstat + *(int *)(_in_ifaddr + 4) + *piVar6;
                urem(iVar8,0x32);
                piVar6[4] = iVar8 + 1;
                dword_F010C9CC = 1;
              }
              piVar6 = *(int **)((int)register0x00000038 + -0xc);
            }
            else {
              piVar6 = *(int **)((int)register0x00000038 + -0xc);
            }
          }
          else {
            piVar6 = *(int **)((int)register0x00000038 + -0xc);
          }
          if (piVar6 == (int *)0x0) {
            if (*(int *)((int)register0x00000038 + -0x10) != 0) {
              iVar8 = *(int *)((int)register0x00000038 + -0x10);
              do {
                piVar6 = *(int **)(iVar8 + 0x44);
                iVar3 = *(int *)(iVar8 + 0x40);
                *(int *)((int)register0x00000038 + -0x10) = iVar3;
                if (piVar6 != (int *)0x0) goto loc_F0039038;
                iVar8 = *(int *)((int)register0x00000038 + -0x10);
              } while (iVar3 != 0);
            }
          }
          else {
loc_F0039038:
            *(int *)((int)register0x00000038 + -0xc) = piVar6[5];
          }
          if (piVar6 == (int *)0x0) break;
          iVar8 = piVar6[1];
        } while( true );
      }
    }
  }
  else if ((cVar1 == '\x12') && (DAT_f013a8a4._16_4_ = DAT_f013a8a4._16_4_ + 1, param_2 != _loifp))
  {
    uVar2 = *(uint *)(iVar8 + 4);
    if (((uVar2 & 0xf0000000) != 0xe0000000) || (uVar2 != *(uint *)(iVar5 + 0x10))) {
      DAT_f013a8a4._20_4_ = DAT_f013a8a4._20_4_ + 1;
      _m_freem(param_1);
      goto locret_F0039208;
    }
    if (((*(uint *)(iVar5 + 0xc) & 0xff000000) == 0) && (_in_ifaddr != 0)) {
      iVar7 = *(int *)(_in_ifaddr + 0x20);
      iVar3 = _in_ifaddr;
      while ((iVar7 != param_2 && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0))) {
        iVar7 = *(int *)(iVar3 + 0x20);
      }
      if (iVar3 != 0) {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar3 + 0x30);
      }
    }
    bVar9 = _in_ifaddr == 0;
    iVar3 = _in_ifaddr;
    if (!bVar9) {
      iVar7 = *(int *)(_in_ifaddr + 0x20);
      while (bVar9 = iVar3 == 0, iVar7 != param_2) {
        iVar3 = *(int *)(iVar3 + 0x40);
        if (iVar3 == 0) {
          bVar9 = true;
          break;
        }
        iVar7 = *(int *)(iVar3 + 0x20);
      }
    }
    if (bVar9) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar3 + 0x44);
      if (piVar6 == (int *)0x0) goto loc_F00391DC;
      iVar3 = *piVar6;
      while ((iVar3 != *(int *)(iVar8 + 4) && (piVar6 = (int *)piVar6[5], piVar6 != (int *)0x0))) {
        iVar3 = *piVar6;
      }
    }
    if (piVar6 != (int *)0x0) {
      piVar6[4] = 0;
      DAT_f013a8a4._24_4_ = DAT_f013a8a4._24_4_ + 1;
    }
  }
loc_F00391DC:
  DAT_f010c9b0._0_4_ = *(undefined4 *)(iVar5 + 0xc);
  DAT_f010c9c0._0_4_ = *(undefined4 *)(iVar5 + 0x10);
  _raw_input(param_1,&unk_F010C9A8);
locret_F0039208:
  return CONCAT44(param_2,param_1);
}

