
/* WARNING: Removing unreachable block (ram,0xf001df00) */
/* WARNING: Removing unreachable block (ram,0xf001de80) */
/* WARNING: Removing unreachable block (ram,0xf001de74) */
/* WARNING: Removing unreachable block (ram,0xf001ddf0) */
/* WARNING: Removing unreachable block (ram,0xf001dd8c) */
/* WARNING: Removing unreachable block (ram,0xf001de00) */
/* WARNING: Removing unreachable block (ram,0xf001de28) */
/* WARNING: Removing unreachable block (ram,0xf001df34) */
/* WARNING: Removing unreachable block (ram,0xf001ded4) */
/* WARNING: Removing unreachable block (ram,0xf001dd68) */

undefined8 _m_copy(int *param_1,int param_2,int param_3)

{
  sword sVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar5;
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
  if (param_3 == 0) {
loc_F001DF3C:
    uVar6 = 0;
  }
  else {
    if ((param_2 < 0) || (param_3 < 0)) {
      _panic(&aMCopy);
    }
    for (; 0 < param_2; param_2 = param_2 - sVar1) {
      if (param_1 == (int *)0x0) {
        _panic(&aMCopy_1);
        sVar1 = sRam00000008;
      }
      else {
        sVar1 = *(sword *)(param_1 + 2);
      }
      if (param_2 < sVar1) break;
      param_1 = (int *)*param_1;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    if (0 < param_3) {
      puVar2 = DAT_f0134800;
      puVar5 = (undefined4 *)((int)register0x00000038 + -0xc);
      do {
        if (param_1 == (int *)0x0) {
          if (param_3 != 1000000000) {
            _panic(&aMCopy_0);
            uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
            goto locret_F001DF40;
          }
          break;
        }
        _spltty();
        puVar3 = _mfree;
        if (_mfree == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
          _m_more(0,(int)*(sword *)((int)param_1 + 10));
        }
        else {
          if (*(sword *)((int)_mfree + 10) != 0) {
            _panic(&aMget_2);
          }
          *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)((int)param_1 + 10);
          word_F0134B0C = word_F0134B0C + -1;
          (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] =
               (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] + 1;
          _mfree = (undefined4 *)*puVar3;
          puVar3[1] = 0xc;
          *puVar3 = 0;
        }
        _splx(puVar2);
        *puVar5 = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          _m_freem(*(undefined4 *)((int)register0x00000038 + -0xc));
          goto loc_F001DF3C;
        }
        iVar4 = param_3;
        if (*(sword *)(param_1 + 2) - param_2 < param_3) {
          iVar4 = *(sword *)(param_1 + 2) - param_2;
        }
        *(sword *)(puVar3 + 2) = (sword)iVar4;
        if (((uint)param_1[1] < 0x7d) || ((sword)iVar4 < 0x71)) {
          puVar2 = (undefined *)((int)param_1 + param_2 + param_1[1]);
          _bcopy(puVar2,(int)puVar3 + puVar3[1],(int)*(sword *)(puVar3 + 2));
        }
        else {
          _mcldup(param_1,puVar3,param_2);
          puVar2 = (undefined *)(puVar3[1] + param_2);
          puVar3[1] = puVar2;
        }
        param_2 = 0;
        if (param_3 != 1000000000) {
          puVar2 = (undefined *)(int)*(sword *)(puVar3 + 2);
          param_3 = param_3 - (int)puVar2;
        }
        param_1 = (int *)*param_1;
        puVar5 = puVar3;
      } while (0 < param_3);
    }
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
locret_F001DF40:
  return CONCAT44(param_2,uVar6);
}
