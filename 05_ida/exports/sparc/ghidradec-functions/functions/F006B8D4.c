
/* WARNING: Removing unreachable block (ram,0xf006b988) */
/* WARNING: Removing unreachable block (ram,0xf006b948) */
/* WARNING: Removing unreachable block (ram,0xf006b930) */
/* WARNING: Removing unreachable block (ram,0xf006b964) */
/* WARNING: Removing unreachable block (ram,0xf006b998) */
/* WARNING: Removing unreachable block (ram,0xf006b910) */

undefined8
_netipc_listen(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined2 param_4,
              undefined2 param_5,uint param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  int *piVar6;
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
  iVar4 = *(int *)((int)register0x00000038 + 0x5c);
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    if (iVar4 == 0) {
      uVar5 = 4;
    }
    else {
      puVar1 = _listener_zone;
      _zalloc();
      puVar1[1] = param_2;
      *(undefined2 *)(puVar1 + 3) = param_4;
      puVar1[2] = param_3;
      *(undefined2 *)((int)puVar1 + 0xe) = param_5;
      puVar1[4] = iVar4;
      _ipc_object_reference(iVar4);
      iVar3 = (param_6 & 0xf) * 8;
      param_2 = _listeners;
      piVar6 = (int *)(_listeners + iVar3);
      _splnet();
      do {
        do {
        } while (*piVar6 != 0);
        piVar2 = piVar6;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *puVar1 = *(undefined4 *)(_listeners + iVar3 + 4);
      *(undefined4 **)(_listeners + iVar3 + 4) = puVar1;
      *piVar6 = 0;
      _splx(param_2);
      _ipc_kobject_set(iVar4,0,0x11);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 8;
  }
  return CONCAT44(param_2,uVar5);
}
