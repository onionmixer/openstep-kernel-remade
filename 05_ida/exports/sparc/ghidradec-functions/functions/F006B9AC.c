
/* WARNING: Removing unreachable block (ram,0xf006ba84) */
/* WARNING: Removing unreachable block (ram,0xf006ba78) */
/* WARNING: Removing unreachable block (ram,0xf006ba00) */
/* WARNING: Removing unreachable block (ram,0xf006ba50) */
/* WARNING: Removing unreachable block (ram,0xf006baa8) */
/* WARNING: Removing unreachable block (ram,0xf006b9e4) */

undefined8 _netipc_ignore(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l1;
  undefined *puVar7;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
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
  uVar9 = 5;
  if (param_2 == 0) {
    uVar9 = 4;
  }
  else {
    puVar7 = _listeners;
    puVar2 = &_mach_net_kmsg_zone;
    piVar8 = (int *)(_listeners + 4);
    do {
      _splnet();
      do {
        do {
        } while (*(int *)puVar7 != 0);
        piVar4 = (int *)puVar7;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      piVar4 = (int *)*piVar8;
      if (piVar4 != (int *)0x0) {
        iVar3 = piVar4[4];
        piVar5 = piVar4;
        do {
          uVar1 = _listener_zone;
          if (iVar3 == param_2) {
            uVar9 = 0;
            if (piVar5 == (int *)*piVar8) {
              *piVar8 = *piVar5;
              _zfree(uVar1,piVar5);
              piVar4 = (int *)*piVar8;
              if (piVar4 == (int *)0x0) break;
            }
            else {
              *piVar4 = *piVar5;
              _zfree(uVar1,piVar5);
            }
            _ipc_object_release(param_2);
            piVar6 = (int *)*piVar4;
          }
          else {
            piVar6 = (int *)*piVar5;
            piVar4 = piVar5;
          }
          if (piVar6 == (int *)0x0) break;
          iVar3 = piVar6[4];
          piVar5 = piVar6;
        } while( true );
      }
      *(int *)puVar7 = 0;
      _splx(puVar2);
      puVar7 = (undefined *)((int)puVar7 + 8);
      piVar8 = piVar8 + 2;
    } while (puVar7 < &_mach_net_kmsg_zone);
  }
  return CONCAT44(param_2,uVar9);
}
