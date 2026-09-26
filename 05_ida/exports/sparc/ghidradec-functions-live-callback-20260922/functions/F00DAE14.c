
/* WARNING: Removing unreachable block (ram,0xf00daef4) */
/* WARNING: Removing unreachable block (ram,0xf00daea4) */
/* WARNING: Removing unreachable block (ram,0xf00dae94) */
/* WARNING: Removing unreachable block (ram,0xf00dae4c) */
/* WARNING: Removing unreachable block (ram,0xf00dae8c) */
/* WARNING: Removing unreachable block (ram,0xf00dae9c) */
/* WARNING: Removing unreachable block (ram,0xf00daee4) */
/* WARNING: Removing unreachable block (ram,0xf00daec4) */
/* WARNING: Removing unreachable block (ram,0xf00dae38) */

undefined8
-[AudioStream initChannel:tag:user:owner:type:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
          undefined4 param_6)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [12];
  undefined7 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422a8;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  pauVar2 = paAudiodevice;
  *(undefined4 *)(param_1 + 4) = param_3;
  _objc_msgSend(param_3,pauVar2);
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  *(undefined4 *)(param_1 + 100) = 0x5622;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  puVar3 = paNxlock;
  puVar1 = paAlloc;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  _objc_msgSend(puVar3,puVar1);
  _objc_msgSend();
  *(undefined7 **)(param_1 + 0x28) = puVar3;
  _task_self();
  _port_allocate_EXTERNAL();
  if (puVar3 == (undefined7 *)0x0) {
    uVar4 = *param_5;
    *(undefined4 *)(param_1 + 0xc) = uVar4;
    _IOConvertPort(uVar4,2,0);
    *(undefined4 *)(param_1 + 0x10) = uVar4;
    *(undefined4 *)(param_1 + 0x14) = param_6;
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
  }
  else {
    _IOLog(aAudioInitchann,aMachErr);
    _objc_msgSend(param_1,paFree);
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}

