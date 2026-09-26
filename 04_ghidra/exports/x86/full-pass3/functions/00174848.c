/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174848 */

undefined4 _vm_map_insert(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if (((param_4 < *(uint *)(param_1 + 0x14)) || (*(uint *)(param_1 + 0x18) < param_5)) ||
     (param_5 <= param_4)) {
    uVar1 = 1;
  }
  else {
    iVar2 = _vm_map_lookup_entry(param_1,param_4,&local_8);
    if ((iVar2 == 0) &&
       ((*(int *)(local_8 + 4) == param_1 + 0xc || (param_5 <= *(uint *)(*(int *)(local_8 + 4) + 8))
        ))) {
      if ((param_2 == 0) &&
         (((local_8 != param_1 + 0xc && (*(uint *)(local_8 + 0xc) == param_4)) &&
          (((*(byte *)(local_8 + 0x18) & 5) == 0 &&
           ((((*(int *)(local_8 + 0x24) == 1 && (*(int *)(local_8 + 0x1c) == 3)) &&
             (*(int *)(local_8 + 0x20) == 7)) &&
            ((*(short *)(local_8 + 0x28) == 0 &&
             (iVar2 = _vm_object_coalesce(*(undefined4 *)(local_8 + 0x10),0,
                                          *(undefined4 *)(local_8 + 0x14),0,
                                          param_4 - *(int *)(local_8 + 8),param_5 - param_4),
             iVar2 != 0)))))))))) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (param_5 - *(int *)(local_8 + 0xc));
        *(uint *)(local_8 + 0xc) = param_5;
      }
      else {
        uVar1 = _vm_map_kentry_zone;
        if (*(int *)(param_1 + 0x20) != 0) {
          uVar1 = _vm_map_entry_zone;
        }
        piVar3 = (int *)_zalloc(uVar1);
        if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar3[2] = param_4;
        piVar3[3] = param_5;
        *(byte *)(piVar3 + 6) = *(byte *)(piVar3 + 6) & 0xfa;
        piVar3[4] = param_2;
        piVar3[5] = param_3;
        *(byte *)(piVar3 + 6) = *(byte *)(piVar3 + 6) & 0xb7;
        if (*(int *)(param_1 + 0x2c) != 0) {
          piVar3[9] = 1;
          piVar3[7] = 3;
          piVar3[8] = 7;
          *(undefined2 *)(piVar3 + 10) = 0;
        }
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *piVar3 = local_8;
        piVar3[1] = *(int *)(local_8 + 4);
        iVar2 = *piVar3;
        *(int **)piVar3[1] = piVar3;
        *(int **)(iVar2 + 4) = piVar3;
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (piVar3[3] - piVar3[2]);
        if ((*(int *)(param_1 + 0x40) == local_8) && ((uint)piVar3[2] <= *(uint *)(local_8 + 0xc)))
        {
          *(int **)(param_1 + 0x40) = piVar3;
        }
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 3;
    }
  }
  return uVar1;
}

