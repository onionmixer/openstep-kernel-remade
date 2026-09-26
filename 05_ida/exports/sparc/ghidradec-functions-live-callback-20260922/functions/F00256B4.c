
undefined8 _dnlc_init(int param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined *puVar4;
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
  int iVar5;
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
  dword_F01355D8 = &_nc_lru;
  dword_F01355DC = &_nc_lru;
  iVar5 = 0;
  if (0 < _ncsize) {
    param_2 = 0;
    do {
      param_1 = _ncache;
      puVar1 = dword_F01355D8;
      iVar5 = iVar5 + 1;
      puVar3 = (undefined8 *)(_ncache + param_2);
      puVar2 = puVar3;
      *(undefined8 **)(puVar3 + 1) = dword_F01355D8;
      dword_F01355D8 = puVar2;
      *(undefined8 **)((int)puVar1 + 0xc) = puVar3;
      *(undefined8 **)((int)puVar3 + 0xc) = &_nc_lru;
      *(undefined8 **)((int)puVar3 + 4) = puVar3;
      *(undefined8 **)(param_1 + param_2) = puVar3;
      *(undefined4 *)(puVar3 + 2) = 0;
      *(undefined4 *)((int)puVar3 + 0x14) = 0;
      *(undefined *)((int)puVar3 + 0x44) = 0;
      param_2 = param_2 + 0x48;
    } while (iVar5 < _ncsize);
  }
  iVar5 = 0;
  puVar4 = _nc_hash;
  do {
    *(undefined **)(puVar4 + 4) = puVar4;
    *(undefined **)puVar4 = puVar4;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 8;
  } while (iVar5 < 0x40);
  return CONCAT44(param_2,param_1);
}

