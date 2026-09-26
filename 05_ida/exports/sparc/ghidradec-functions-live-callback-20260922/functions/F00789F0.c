
/* WARNING: Removing unreachable block (ram,0xf0078a90) */
/* WARNING: Removing unreachable block (ram,0xf0078aa0) */
/* WARNING: Removing unreachable block (ram,0xf0078a34) */

undefined8 sub_F00789F0(uint param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
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
  if (_zone_free_space_count < 8) {
    puVar4 = __zone_default_space;
    puVar3 = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    _zget_space(__zone_default_space,0x1c,0);
    *(uint *)puVar4 = param_1;
    *(uint *)((int)puVar4 + 4) = param_2;
    *(uint *)((int)puVar4 + 8) = 0;
    *(uint *)((int)puVar4 + 0xc) = 0;
    *(uint *)((int)puVar4 + 0x10) = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      *(uint *)((int)puVar4 + 0x10) = *(uint *)((int)puVar4 + 0x10) + 1;
    }
    puVar1 = __zone_default_space;
    uVar2 = *(uint *)((int)puVar4 + 4) >> ((byte)*(uint *)((int)puVar4 + 0x10) & 0x1f);
    *(uint *)((int)puVar4 + 0x18) = uVar2;
    _zget_space(__zone_default_space,uVar2 << 4,0);
    *(undefined **)((int)puVar4 + 0x14) = puVar1;
    _bzero();
    *puVar3 = puVar4;
  }
  else {
    puVar4 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar4);
}

