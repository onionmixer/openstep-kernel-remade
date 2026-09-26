
/* WARNING: Removing unreachable block (ram,0xf0024754) */
/* WARNING: Removing unreachable block (ram,0xf00246d0) */
/* WARNING: Removing unreachable block (ram,0xf0024698) */
/* WARNING: Removing unreachable block (ram,0xf0024618) */
/* WARNING: Removing unreachable block (ram,0xf0024650) */
/* WARNING: Removing unreachable block (ram,0xf00246b4) */
/* WARNING: Removing unreachable block (ram,0xf0024708) */
/* WARNING: Removing unreachable block (ram,0xf0024744) */
/* WARNING: Removing unreachable block (ram,0xf00245fc) */

undefined8
_breada(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  uint *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar2;
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
  puVar2 = (uint *)0x0;
  DAT_f01353b8._0_4_ = DAT_f01353b8._0_4_ + 1;
  puVar1 = param_1;
  _incore(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    puVar2 = param_1;
    _getblk(param_1,param_2,param_3);
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 1;
      if ((int)puVar2[6] < (int)puVar2[5]) {
        _panic(&aBreada);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
      *(int *)(_active_u + 0x198) = *(int *)(_active_u + 0x198) + 1;
    }
    else {
      DAT_f01353b8._4_4_ = DAT_f01353b8._4_4_ + 1;
    }
  }
  if ((param_4 != 0) && (puVar1 = param_1, _incore(param_1,param_4), puVar1 == (uint *)0x0)) {
    puVar1 = param_1;
    _getblk(param_1,param_4,param_5);
    if ((*puVar1 & 2) == 0) {
      *puVar1 = *puVar1 | 0x101;
      if ((int)puVar1[6] < (int)puVar1[5]) {
        _panic(aBreadrabp);
      }
      (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
      *(int *)(_active_u + 0x198) = *(int *)(_active_u + 0x198) + 1;
    }
    else {
      _brelse();
      DAT_f01353b8._8_4_ = DAT_f01353b8._8_4_ + 1;
    }
  }
  if (puVar2 == (uint *)0x0) {
    _bread(param_1,param_2,param_3);
  }
  else {
    _biowait(puVar2);
    param_1 = puVar2;
  }
  return CONCAT44(param_2,param_1);
}

