
/* WARNING: Removing unreachable block (ram,0xf0062dfc) */
/* WARNING: Removing unreachable block (ram,0xf0062d54) */
/* WARNING: Removing unreachable block (ram,0xf0062d30) */
/* WARNING: Removing unreachable block (ram,0xf0062d88) */
/* WARNING: Removing unreachable block (ram,0xf0062db4) */
/* WARNING: Removing unreachable block (ram,0xf0062cf8) */

undefined8 _mach_port_get_receive_status(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
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
  if (param_1 == 0) {
    param_1 = 0x10;
    goto locret_F0062E78;
  }
  _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 != 0) goto locret_F0062E78;
  param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 0x30);
  if (param_2 == (int *)0x0) {
loc_F0062DE0:
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
loc_F0062DE4:
    *param_3 = 0;
    do {
      do {
      } while (*(int *)(iVar2 + 0x40) != 0);
      piVar1 = (int *)(iVar2 + 0x40);
      _simple_lock_try();
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
    } while (piVar1 == (int *)0x0);
    param_3[1] = *(int *)(iVar3 + 0x34);
    *(undefined4 *)(iVar3 + 0x40) = 0;
    puVar4 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else {
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (-1 < param_2[2]) {
      _ipc_pset_remove(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
      *param_2 = 0;
      if (param_2[1] != 0) goto loc_F0062DE0;
      _zfree((&_ipc_object_zones)[(param_2[2] & 0x7fffffffU) >> 0x10],param_2);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      goto loc_F0062DE4;
    }
    *param_3 = param_2[3];
    do {
      do {
      } while (param_2[4] != 0);
      piVar1 = param_2 + 4;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    param_3[1] = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x34);
    param_2[4] = 0;
    *param_2 = 0;
    puVar4 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  param_3[2] = puVar4[6];
  param_3[3] = puVar4[0xf];
  param_3[4] = puVar4[0xe];
  param_3[5] = puVar4[8];
  param_3[6] = (uint)(puVar4[7] != 0);
  param_3[7] = (uint)(puVar4[10] != 0);
  param_1 = 0;
  param_3[8] = (uint)(puVar4[9] != 0);
  *puVar4 = 0;
locret_F0062E78:
  return CONCAT44(param_2,param_1);
}

