
undefined * _clnt_sperrno(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = 0;
  puVar2 = unk_40AEF96;
  do {
    if (param_1 == *(int *)puVar2) {
      return *(undefined **)(unk_40AEF96 + uVar1 * 8 + 4);
    }
    puVar2 = (undefined *)((int)puVar2 + 8);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x11);
  return aRpcUnknownErro;
}

