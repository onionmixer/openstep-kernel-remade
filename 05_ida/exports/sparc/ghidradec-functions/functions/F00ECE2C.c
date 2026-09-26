
/* WARNING: Removing unreachable block (ram,0xf00ece74) */
/* WARNING: Removing unreachable block (ram,0xf00eceb4) */
/* WARNING: Removing unreachable block (ram,0xf00ece30) */

void _NXDefaultExceptionRaiser(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
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
  puVar1 = param_1;
  _current_thread_EXTERNAL();
  puVar3 = unk_F012F048;
  puVar2 = DAT_f012f058;
  do {
    if (puVar2 == puVar1) {
loc_F00ECE80:
      uVar4 = *(uint *)puVar3;
      while( true ) {
        while (uVar4 == 0) {
          if (__NXUncaughtExceptionHandler != (code *)0x0) {
            (*__NXUncaughtExceptionHandler)(param_1,param_2,param_3);
          }
          _panic(aUncaughtExcept);
          uVar4 = *(uint *)puVar3;
        }
        if ((uVar4 & 1) == 0) break;
        iVar5 = ((int)(uVar4 - 1) / 2) * 0xc;
        iVar6 = iVar5 + *(uint *)((int)puVar3 + 4);
        *(uint *)puVar3 = *(uint *)(iVar5 + *(uint *)((int)puVar3 + 4));
        *(int *)((int)puVar3 + 0xc) = (int)((iVar6 - *(uint *)((int)puVar3 + 4)) * -0x55555555) >> 2
        ;
        (**(code **)(iVar6 + 4))(*(undefined4 *)(iVar6 + 8),param_1,param_2,param_3);
        uVar4 = *(uint *)puVar3;
      }
      *(uint **)(uVar4 + 0x78) = param_1;
      *(undefined4 *)(uVar4 + 0x7c) = param_2;
      *(undefined4 *)(uVar4 + 0x80) = param_3;
      *(uint *)puVar3 = *(uint *)(uVar4 + 0x74);
                    /* WARNING: Subroutine does not return */
      _longjmp(uVar4,1);
    }
    puVar3 = *(undefined **)((int)puVar3 + 0x14);
    if ((uint *)puVar3 == (uint *)0x0) {
      sub_F00EC878();
      puVar3 = (undefined *)puVar1;
      goto loc_F00ECE80;
    }
    puVar2 = *(uint **)((int)puVar3 + 0x10);
  } while( true );
}
