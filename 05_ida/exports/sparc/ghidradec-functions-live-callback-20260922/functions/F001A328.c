
/* WARNING: Removing unreachable block (ram,0xf001a3b8) */
/* WARNING: Removing unreachable block (ram,0xf001a3a4) */
/* WARNING: Removing unreachable block (ram,0xf001a354) */
/* WARNING: Removing unreachable block (ram,0xf001a34c) */
/* WARNING: Removing unreachable block (ram,0xf001a370) */
/* WARNING: Removing unreachable block (ram,0xf001a3d8) */
/* WARNING: Removing unreachable block (ram,0xf001a384) */
/* WARNING: Removing unreachable block (ram,0xf001a340) */

undefined8 _ttyretype(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar4 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar4 + 0x57) != -1) {
    _ttyecho(*(char *)((int)puVar4 + 0x57),param_1);
  }
  uVar1 = 10;
  _ttyoutput(10,puVar4);
  _spltty();
  puVar3 = (undefined4 *)(puVar4[4] + -1);
  while( true ) {
    puVar2 = puVar4 + 3;
    _nextc3(puVar2,puVar3,(undefined *)((int)register0x00000038 + -0xc));
    if (puVar2 == (undefined4 *)0x0) break;
    _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_1);
    puVar3 = puVar2;
  }
  puVar3 = (undefined4 *)(puVar4[1] + -1);
  while( true ) {
    puVar2 = puVar4;
    _nextc3(puVar4,puVar3,(undefined *)((int)register0x00000038 + -0xc));
    if (puVar2 == (undefined4 *)0x0) break;
    _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_1);
    puVar3 = puVar2;
  }
  puVar4[0x10] = puVar4[0x10] & 0xfffbffff;
  _splx(uVar1);
  *(undefined *)(puVar4 + 0x13) = 0;
  *(char *)((int)puVar4 + 0x4b) = (char)*puVar4;
  return CONCAT44(param_2,param_1);
}

