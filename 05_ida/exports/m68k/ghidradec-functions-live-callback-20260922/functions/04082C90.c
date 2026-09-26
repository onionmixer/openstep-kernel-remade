
/* WARNING: Removing unreachable block (ram,0x04082cfa) */

void _dspq_enqueue_state(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  
  puStack_c = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 0xc;
  dword_40B5090 = puVar1;
  puStack_c[1] = param_1;
  *(undefined *)(puStack_c + 8) = 0;
  *(undefined *)(puStack_c + 9) = 1;
  *(undefined *)((int)puStack_c + 0x23) = 0;
  *(undefined *)((int)puStack_c + 0x22) = 1;
  *(undefined *)((int)puStack_c + 0x21) = 0;
  puStack_c[7] = &puStack_c;
  puStack_c[6] = &puStack_c;
  puStack_8 = puStack_c;
  _dspq_enqueue(&puStack_c);
  return;
}

