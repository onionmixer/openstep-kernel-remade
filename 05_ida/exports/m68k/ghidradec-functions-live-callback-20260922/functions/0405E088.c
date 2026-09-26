
undefined4 _vm_map_lookup_entry(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x30);
  puVar1 = (undefined4 *)(param_1 + 8);
  if (puVar1 == puVar2) {
    puVar2 = *(undefined4 **)(param_1 + 0xc);
  }
  if (param_2 < (uint)puVar2[2]) {
    puVar1 = (undefined4 *)puVar2[1];
    puVar2 = *(undefined4 **)(param_1 + 0xc);
  }
  else {
    if (puVar1 == puVar2) goto loc_405E0EC;
    if (param_2 < (uint)puVar2[3]) {
      *param_3 = puVar2;
      return 1;
    }
  }
  for (; puVar1 != puVar2; puVar2 = (undefined4 *)puVar2[1]) {
    if (param_2 < (uint)puVar2[3]) {
      if ((uint)puVar2[2] <= param_2) {
        *param_3 = puVar2;
        *(undefined4 **)(param_1 + 0x30) = puVar2;
        return 1;
      }
      break;
    }
  }
loc_405E0EC:
  *param_3 = *puVar2;
  *(undefined4 *)(param_1 + 0x30) = *param_3;
  return 0;
}

