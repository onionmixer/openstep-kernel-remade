
/* WARNING: Removing unreachable block (ram,0xf006b864) */
/* WARNING: Removing unreachable block (ram,0xf006b794) */
/* WARNING: Removing unreachable block (ram,0xf006b730) */
/* WARNING: Removing unreachable block (ram,0xf006b70c) */
/* WARNING: Removing unreachable block (ram,0xf006b700) */
/* WARNING: Removing unreachable block (ram,0xf006b6c0) */
/* WARNING: Removing unreachable block (ram,0xf006b874) */
/* WARNING: Removing unreachable block (ram,0xf006b750) */
/* WARNING: Removing unreachable block (ram,0xf006b810) */
/* WARNING: Removing unreachable block (ram,0xf006b89c) */
/* WARNING: Removing unreachable block (ram,0xf006b698) */

undefined8 sub_F006B604(undefined *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar10;
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
  puVar4 = param_1;
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    uVar6 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x18) = uVar6;
    if ((-1 < *(int *)(param_1 + 0x14)) && (0x2b < uVar6)) {
      uVar8 = (uint)*(sword *)(param_1 + 0x2e);
      if ((0x14 < uVar8) && (uVar8 <= uVar6 - 0x18)) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        puVar10 = param_1 + 0x2c;
        if (0 < (int)uVar8) {
          param_2 = 0xf0111c00;
          puVar2 = DAT_f0134800;
          puVar9 = (undefined4 *)((int)register0x00000038 + -0xc);
          puVar4 = puVar10;
          do {
            _spltty();
            puVar3 = _mfree;
            if (_mfree == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x1;
              _m_more(1,1);
            }
            else {
              if (*(sword *)((int)_mfree + 10) != 0) {
                _panic(&aMget_15);
              }
              *(undefined2 *)((int)puVar3 + 10) = 1;
              word_F0134B0C = word_F0134B0C + -1;
              DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
              _mfree = (undefined4 *)*puVar3;
              puVar3[1] = 0xc;
              *puVar3 = 0;
            }
            _splx(puVar2);
            if (puVar3 == (undefined4 *)0x0) {
              _m_freem(*(undefined4 *)((int)register0x00000038 + -0xc));
              goto locret_F006B8A4;
            }
            uVar6 = _page_size >> 1;
            if (uVar8 < 0x70) {
loc_F006B7EC:
              uVar6 = 0x70;
              if ((int)uVar8 < 0x71) {
                uVar6 = uVar8;
              }
            }
            else {
              _spltty(uVar6);
              if (_mclfree == (int *)0x0) {
                _m_clalloc(1,1,0);
              }
              piVar1 = _mclfree;
              if (_mclfree != (int *)0x0) {
                iVar7 = (int)_mclfree - _mbutl >> 10;
                _mclrefcnt[iVar7] = _mclrefcnt[iVar7] + '\x01';
                DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
                _mclfree = (int *)*_mclfree;
              }
              _splx(uVar6);
              if (piVar1 == (int *)0x0) {
                *(undefined2 *)(puVar3 + 2) = 0x70;
              }
              else {
                puVar3[1] = (int)piVar1 - (int)puVar3;
                *(undefined2 *)(puVar3 + 2) = 0x400;
                *(undefined2 *)(puVar3 + 3) = 1;
              }
              uVar6 = (uint)*(sword *)(puVar3 + 2);
              if (uVar6 != _page_size) goto loc_F006B7EC;
              if (uVar8 <= uVar6) {
                uVar6 = uVar8;
              }
            }
            *(sword *)(puVar3 + 2) = (sword)uVar6;
            puVar10 = puVar4 + uVar6;
            uVar8 = uVar8 - uVar6;
            _bcopy(puVar4,(int)puVar3 + puVar3[1]);
            *puVar9 = puVar3;
            puVar2 = puVar4;
            puVar9 = puVar3;
            puVar4 = puVar10;
          } while (0 < (int)uVar8);
        }
        if (DAT_f010fcd0._0_4_ == *(int *)(param_1 + 0x3c)) {
          uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
        }
        else {
          if (unk_F010FCC8 != 0) {
            if (*(sword *)(unk_F010FCC8 + 0x26) == 1) {
              _rtfree(unk_F010FCC8);
            }
            else {
              *(sword *)(unk_F010FCC8 + 0x26) = *(sword *)(unk_F010FCC8 + 0x26) + -1;
            }
          }
          unk_F010FCC8 = 0;
          uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
        }
        _ip_output(uVar5,0,&unk_F010FCC8,0x21);
        puVar4 = puVar10;
      }
    }
  }
locret_F006B8A4:
  return CONCAT44(param_2,puVar4);
}

