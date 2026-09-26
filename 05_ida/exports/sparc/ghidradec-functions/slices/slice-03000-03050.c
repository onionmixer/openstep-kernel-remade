/* GHIDRADEC_FUNCTION index=3000 start=0xf00dee98 */

/* WARNING: Removing unreachable block (ram,0xf00deedc) */
/* WARNING: Removing unreachable block (ram,0xf00deef8) */
/* WARNING: Removing unreachable block (ram,0xf00deeb8) */

undefined8 __NXAudioSetDeviceParameters(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    uVar1 = param_1;
    _objc_msgSend(param_1,paCheckowner,param_2);
    if ((uVar1 & 0xff) == 0) {
      uVar1 = 200;
    }
    else {
      _objc_msgSend(param_1,paAudiodevice);
      _objc_msgSend();
      uVar1 = ((param_1 & 0xff) != 0) - 1 & 0xd2;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3001 start=0xf00def18 */

/* WARNING: Removing unreachable block (ram,0xf00def48) */
/* WARNING: Removing unreachable block (ram,0xf00def2c) */

undefined8 __NXAudioGetDeviceParameters(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paAudiodevice);
    _objc_msgSend();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3002 start=0xf00def64 */

/* WARNING: Removing unreachable block (ram,0xf00def94) */
/* WARNING: Removing unreachable block (ram,0xf00def7c) */

undefined8 __NXAudioGetDeviceSupportedParameters(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  *param_3 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paAudiodevice);
    _objc_msgSend();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3003 start=0xf00defb0 */

/* WARNING: Removing unreachable block (ram,0xf00defec) */
/* WARNING: Removing unreachable block (ram,0xf00defd0) */

undefined8
__NXAudioGetDeviceParameterValues
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  *param_4 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paAudiodevice);
    _objc_msgSend();
    uVar1 = ((param_1 & 0xff) != 0) - 1 & 0xd2;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3004 start=0xf00df00c */

/* WARNING: Removing unreachable block (ram,0xf00df06c) */
/* WARNING: Removing unreachable block (ram,0xf00df04c) */
/* WARNING: Removing unreachable block (ram,0xf00df034) */
/* WARNING: Removing unreachable block (ram,0xf00df060) */
/* WARNING: Removing unreachable block (ram,0xf00df080) */
/* WARNING: Removing unreachable block (ram,0xf00df028) */

undefined8 __NXAudioGetSamplingRates(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *in_o5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  char cVar2;
  
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
  *in_o5 = 0;
  uVar3 = paAudiodevice;
  if (param_1 == 0) {
    uVar3 = 0xca;
  }
  else {
    iVar1 = param_1;
    _objc_msgSend(param_1,paAudiodevice);
    cVar2 = (char)iVar1;
    _objc_msgSend();
    *param_2 = (int)cVar2;
    _objc_msgSend(param_1,uVar3);
    _objc_msgSend();
    _objc_msgSend(param_1,uVar3);
    _objc_msgSend();
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3005 start=0xf00df09c */

/* WARNING: Removing unreachable block (ram,0xf00df0c8) */
/* WARNING: Removing unreachable block (ram,0xf00df0b4) */

undefined8 __NXAudioGetDataEncodings(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  *param_3 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paAudiodevice);
    _objc_msgSend();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3006 start=0xf00df0e4 */

/* WARNING: Removing unreachable block (ram,0xf00df108) */
/* WARNING: Removing unreachable block (ram,0xf00df0fc) */

undefined8 __NXAudioGetChannelCountLimit(int param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  *param_2 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paAudiodevice);
    _objc_msgSend();
    *param_2 = param_1;
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3007 start=0xf00df128 */

/* WARNING: Removing unreachable block (ram,0xf00df150) */
/* WARNING: Removing unreachable block (ram,0xf00df16c) */
/* WARNING: Removing unreachable block (ram,0xf00df144) */

undefined8 __NXAudioSetStreamParameters(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend();
    _objc_msgSend();
    uVar1 = ((param_1 & 0xff) != 0) - 1 & 0xd2;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3008 start=0xf00df18c */

/* WARNING: Removing unreachable block (ram,0xf00df1ac) */
/* WARNING: Removing unreachable block (ram,0xf00df1c8) */
/* WARNING: Removing unreachable block (ram,0xf00df1a0) */

undefined8 __NXAudioGetStreamParameters(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend();
    _objc_msgSend();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3009 start=0xf00df1e4 */

/* WARNING: Removing unreachable block (ram,0xf00df208) */
/* WARNING: Removing unreachable block (ram,0xf00df220) */
/* WARNING: Removing unreachable block (ram,0xf00df1fc) */

undefined8 __NXAudioGetStreamSupportedParameters(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  *param_3 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend();
    _objc_msgSend();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3010 start=0xf00df23c */

/* WARNING: Removing unreachable block (ram,0xf00df268) */
/* WARNING: Removing unreachable block (ram,0xf00df284) */
/* WARNING: Removing unreachable block (ram,0xf00df25c) */

undefined8
__NXAudioGetStreamParameterValues
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  *param_4 = 0;
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend();
    _objc_msgSend();
    uVar1 = ((param_1 & 0xff) != 0) - 1 & 0xd2;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3011 start=0xf00e0314 */

/* WARNING: Removing unreachable block (ram,0xf00e0350) */
/* WARNING: Removing unreachable block (ram,0xf00e03c0) */
/* WARNING: Removing unreachable block (ram,0xf00e0370) */
/* WARNING: Removing unreachable block (ram,0xf00e03e0) */
/* WARNING: Removing unreachable block (ram,0xf00e0390) */

undefined8 _snd_server(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 uVar4;
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
  uVar4 = 1;
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar3 = 0;
  if (uVar2 < 2) {
    iVar3 = param_1;
    sub_F00DF338(param_1,param_2);
  }
  else if (uVar2 - 100 < 0x11) {
    iVar3 = param_1;
    sub_F00DF950(param_1,param_2);
  }
  else {
    if (uVar2 - 200 < 8) {
      _IOLog(aAudioReceivedD);
      uVar1 = *(undefined4 *)(param_1 + 0x10);
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x10);
    }
    uVar4 = 0;
    _audio_snd_reply_illegal_msg(param_2,0,uVar1,uVar2,0x66);
  }
  if (iVar3 != 0) {
    _audio_snd_reply_illegal_msg
              (param_2,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),iVar3);
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3012 start=0xf00e03f0 */

/* WARNING: Removing unreachable block (ram,0xf00e04ac) */
/* WARNING: Removing unreachable block (ram,0xf00e0494) */

undefined8 _get_partition(undefined *param_1,undefined *param_2)

{
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
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  param_2[0xc] = param_1[0xc];
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = param_1[0xf];
  param_2[0x10] = param_1[0x10];
  param_2[0x11] = param_1[0x11];
  param_2[0x12] = param_1[0x12];
  param_2[0x13] = param_1[0x13];
  _bcopy(param_1 + 0x14,param_2 + 0x14,0x10);
  param_2[0x24] = param_1[0x24];
  _bcopy(param_1 + 0x25,param_2 + 0x25,8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3013 start=0xf00e04bc */

/* WARNING: Removing unreachable block (ram,0xf00e0728) */
/* WARNING: Removing unreachable block (ram,0xf00e0638) */
/* WARNING: Removing unreachable block (ram,0xf00e04d8) */
/* WARNING: Removing unreachable block (ram,0xf00e0648) */
/* WARNING: Removing unreachable block (ram,0xf00e0740) */
/* WARNING: Removing unreachable block (ram,0xf00e04c8) */

undefined8 _get_disktab(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  _bcopy(param_1,param_2,0x18);
  _bcopy(param_1 + 0x18,param_2 + 0x18,0x18);
  *(undefined *)(param_2 + 0x30) = *(undefined *)(param_1 + 0x30);
  *(undefined *)(param_2 + 0x31) = *(undefined *)(param_1 + 0x31);
  *(undefined *)(param_2 + 0x32) = *(undefined *)(param_1 + 0x32);
  *(undefined *)(param_2 + 0x33) = *(undefined *)(param_1 + 0x33);
  *(undefined *)(param_2 + 0x34) = *(undefined *)(param_1 + 0x34);
  *(undefined *)(param_2 + 0x35) = *(undefined *)(param_1 + 0x35);
  *(undefined *)(param_2 + 0x36) = *(undefined *)(param_1 + 0x36);
  *(undefined *)(param_2 + 0x37) = *(undefined *)(param_1 + 0x37);
  *(undefined *)(param_2 + 0x38) = *(undefined *)(param_1 + 0x38);
  *(undefined *)(param_2 + 0x39) = *(undefined *)(param_1 + 0x39);
  *(undefined *)(param_2 + 0x3a) = *(undefined *)(param_1 + 0x3a);
  *(undefined *)(param_2 + 0x3b) = *(undefined *)(param_1 + 0x3b);
  *(undefined *)(param_2 + 0x3c) = *(undefined *)(param_1 + 0x3c);
  *(undefined *)(param_2 + 0x3d) = *(undefined *)(param_1 + 0x3d);
  *(undefined *)(param_2 + 0x3e) = *(undefined *)(param_1 + 0x3e);
  *(undefined *)(param_2 + 0x3f) = *(undefined *)(param_1 + 0x3f);
  *(undefined *)(param_2 + 0x40) = *(undefined *)(param_1 + 0x40);
  *(undefined *)(param_2 + 0x41) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_2 + 0x42) = *(undefined *)(param_1 + 0x42);
  *(undefined *)(param_2 + 0x43) = *(undefined *)(param_1 + 0x43);
  *(undefined *)(param_2 + 0x44) = *(undefined *)(param_1 + 0x44);
  *(undefined *)(param_2 + 0x45) = *(undefined *)(param_1 + 0x45);
  *(undefined *)(param_2 + 0x46) = *(undefined *)(param_1 + 0x46);
  *(undefined *)(param_2 + 0x47) = *(undefined *)(param_1 + 0x47);
  *(undefined *)(param_2 + 0x48) = *(undefined *)(param_1 + 0x48);
  *(undefined *)(param_2 + 0x49) = *(undefined *)(param_1 + 0x49);
  *(undefined *)(param_2 + 0x4a) = *(undefined *)(param_1 + 0x4a);
  puVar5 = (undefined *)(param_1 + 0x50);
  *(undefined *)(param_2 + 0x4b) = *(undefined *)(param_1 + 0x4b);
  puVar4 = (undefined *)(param_2 + 0x50);
  *(undefined *)(param_2 + 0x4c) = *(undefined *)(param_1 + 0x4c);
  iVar3 = 0;
  *(undefined *)(param_2 + 0x4d) = *(undefined *)(param_1 + 0x4d);
  puVar2 = (undefined *)(param_2 + 0x53);
  *(undefined *)(param_2 + 0x4e) = *(undefined *)(param_1 + 0x4e);
  puVar1 = (undefined *)(param_1 + 0x53);
  *(undefined *)(param_2 + 0x4f) = *(undefined *)(param_1 + 0x4f);
  do {
    iVar3 = iVar3 + 1;
    *puVar4 = *puVar5;
    puVar2[-2] = puVar1[-2];
    puVar5 = puVar5 + 4;
    puVar2[-1] = puVar1[-1];
    puVar4 = puVar4 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x58,param_2 + 0x58,0x18);
  _bcopy(param_1 + 0x70,param_2 + 0x70,0x20);
  iVar9 = 0;
  iVar8 = 0;
  *(undefined *)(param_2 + 0x90) = *(undefined *)(param_1 + 0x90);
  iVar7 = 0;
  *(undefined *)(param_2 + 0x91) = *(undefined *)(param_1 + 0x91);
  iVar3 = param_1;
  do {
    iVar6 = iVar8 + param_2;
    *(undefined *)(iVar6 + 0x94) = *(undefined *)(iVar3 + 0x92);
    *(undefined *)(iVar6 + 0x95) = *(undefined *)(iVar3 + 0x93);
    *(undefined *)(iVar6 + 0x96) = *(undefined *)(iVar3 + 0x94);
    *(undefined *)(iVar6 + 0x97) = *(undefined *)(iVar3 + 0x95);
    *(undefined *)(iVar6 + 0x98) = *(undefined *)(iVar3 + 0x96);
    *(undefined *)(iVar6 + 0x99) = *(undefined *)(iVar3 + 0x97);
    *(undefined *)(iVar6 + 0x9a) = *(undefined *)(iVar3 + 0x98);
    *(undefined *)(iVar6 + 0x9b) = *(undefined *)(iVar3 + 0x99);
    *(undefined *)(iVar6 + 0x9c) = *(undefined *)(iVar3 + 0x9a);
    *(undefined *)(iVar6 + 0x9d) = *(undefined *)(iVar3 + 0x9b);
    *(undefined *)(iVar6 + 0x9e) = *(undefined *)(iVar3 + 0x9c);
    *(undefined *)(iVar6 + 0x9f) = *(undefined *)(iVar3 + 0x9d);
    *(undefined *)(iVar6 + 0xa0) = *(undefined *)(iVar3 + 0x9e);
    iVar8 = iVar8 + 0x30;
    *(undefined *)(iVar6 + 0xa2) = *(undefined *)(iVar3 + 0xa0);
    iVar7 = iVar7 + 0x2e;
    *(undefined *)(iVar6 + 0xa3) = *(undefined *)(iVar3 + 0xa1);
    iVar9 = iVar9 + 1;
    *(undefined *)(iVar6 + 0xa4) = *(undefined *)(iVar3 + 0xa2);
    *(undefined *)(iVar6 + 0xa5) = *(undefined *)(iVar3 + 0xa3);
    *(undefined *)(iVar6 + 0xa6) = *(undefined *)(iVar3 + 0xa4);
    *(undefined *)(iVar6 + 0xa7) = *(undefined *)(iVar3 + 0xa5);
    _bcopy(iVar3 + 0xa6,iVar6 + 0xa8,0x10);
    *(undefined *)(iVar6 + 0xb8) = *(undefined *)(iVar3 + 0xb6);
    _bcopy(iVar3 + 0xb7,iVar6 + 0xb9,8);
    iVar3 = iVar7 + param_1;
  } while (iVar9 < 8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3014 start=0xf00e075c */

undefined8 _get_dl_un(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
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
  int iVar2;
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
  iVar2 = 0;
  puVar1 = param_1 + 3;
  do {
    *param_2 = *param_1;
    iVar2 = iVar2 + 1;
    param_2[1] = puVar1[-2];
    param_2[2] = puVar1[-1];
    param_1 = param_1 + 4;
    param_2[3] = *puVar1;
    puVar1 = puVar1 + 4;
    param_2 = param_2 + 4;
  } while (iVar2 < 0x686);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3015 start=0xf00e07a8 */

/* WARNING: Removing unreachable block (ram,0xf00e0acc) */
/* WARNING: Removing unreachable block (ram,0xf00e09dc) */
/* WARNING: Removing unreachable block (ram,0xf00e086c) */
/* WARNING: Removing unreachable block (ram,0xf00e087c) */
/* WARNING: Removing unreachable block (ram,0xf00e09ec) */
/* WARNING: Removing unreachable block (ram,0xf00e0ae4) */
/* WARNING: Removing unreachable block (ram,0xf00e0814) */

undefined8 _get_disk_label(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  undefined *puVar8;
  undefined4 unaff_l6;
  undefined *puVar9;
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
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  _bcopy(param_1 + 0xc,param_2 + 0xc,0x18);
  param_2[0x24] = param_1[0x24];
  param_2[0x25] = param_1[0x25];
  param_2[0x26] = param_1[0x26];
  puVar9 = param_1 + 0x2c;
  param_2[0x27] = param_1[0x27];
  puVar8 = param_2 + 0x2c;
  param_2[0x28] = param_1[0x28];
  param_2[0x29] = param_1[0x29];
  param_2[0x2a] = param_1[0x2a];
  param_2[0x2b] = param_1[0x2b];
  _bcopy(puVar9,puVar8,0x18);
  _bcopy(param_1 + 0x44,param_2 + 0x44,0x18);
  param_2[0x5c] = param_1[0x5c];
  param_2[0x5d] = param_1[0x5d];
  param_2[0x5e] = param_1[0x5e];
  param_2[0x5f] = param_1[0x5f];
  param_2[0x60] = param_1[0x60];
  param_2[0x61] = param_1[0x61];
  param_2[0x62] = param_1[0x62];
  param_2[99] = param_1[99];
  param_2[100] = param_1[100];
  param_2[0x65] = param_1[0x65];
  param_2[0x66] = param_1[0x66];
  param_2[0x67] = param_1[0x67];
  param_2[0x68] = param_1[0x68];
  param_2[0x69] = param_1[0x69];
  param_2[0x6a] = param_1[0x6a];
  param_2[0x6b] = param_1[0x6b];
  param_2[0x6c] = param_1[0x6c];
  param_2[0x6d] = param_1[0x6d];
  param_2[0x6e] = param_1[0x6e];
  param_2[0x6f] = param_1[0x6f];
  param_2[0x70] = param_1[0x70];
  param_2[0x71] = param_1[0x71];
  param_2[0x72] = param_1[0x72];
  param_2[0x73] = param_1[0x73];
  param_2[0x74] = param_1[0x74];
  param_2[0x75] = param_1[0x75];
  param_2[0x76] = param_1[0x76];
  puVar5 = param_1 + 0x7c;
  param_2[0x77] = param_1[0x77];
  puVar4 = param_2 + 0x7c;
  param_2[0x78] = param_1[0x78];
  iVar3 = 0;
  param_2[0x79] = param_1[0x79];
  puVar2 = param_2 + 0x7f;
  param_2[0x7a] = param_1[0x7a];
  puVar1 = param_1 + 0x7f;
  param_2[0x7b] = param_1[0x7b];
  do {
    iVar3 = iVar3 + 1;
    *puVar4 = *puVar5;
    puVar2[-2] = puVar1[-2];
    puVar5 = puVar5 + 4;
    puVar2[-1] = puVar1[-1];
    puVar4 = puVar4 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x84,param_2 + 0x84,0x18);
  _bcopy(param_1 + 0x9c,param_2 + 0x9c,0x20);
  iVar7 = 0;
  param_2[0xbc] = param_1[0xbc];
  iVar6 = 0;
  param_2[0xbd] = param_1[0xbd];
  puVar1 = puVar9;
  iVar3 = 0;
  do {
    puVar8[iVar3 + 0x94] = puVar1[0x92];
    puVar8[iVar3 + 0x95] = puVar1[0x93];
    puVar8[iVar3 + 0x96] = puVar1[0x94];
    puVar8[iVar3 + 0x97] = puVar1[0x95];
    puVar8[iVar3 + 0x98] = puVar1[0x96];
    puVar8[iVar3 + 0x99] = puVar1[0x97];
    puVar8[iVar3 + 0x9a] = puVar1[0x98];
    puVar8[iVar3 + 0x9b] = puVar1[0x99];
    puVar8[iVar3 + 0x9c] = puVar1[0x9a];
    puVar8[iVar3 + 0x9d] = puVar1[0x9b];
    puVar8[iVar3 + 0x9e] = puVar1[0x9c];
    puVar8[iVar3 + 0x9f] = puVar1[0x9d];
    puVar8[iVar3 + 0xa0] = puVar1[0x9e];
    puVar8[iVar3 + 0xa2] = puVar1[0xa0];
    iVar6 = iVar6 + 0x2e;
    puVar8[iVar3 + 0xa3] = puVar1[0xa1];
    iVar7 = iVar7 + 1;
    puVar8[iVar3 + 0xa4] = puVar1[0xa2];
    puVar8[iVar3 + 0xa5] = puVar1[0xa3];
    puVar8[iVar3 + 0xa6] = puVar1[0xa4];
    puVar8[iVar3 + 0xa7] = puVar1[0xa5];
    _bcopy(puVar1 + 0xa6,puVar8 + iVar3 + 0xa8,0x10);
    puVar8[iVar3 + 0xb8] = puVar1[0xb6];
    _bcopy(puVar1 + 0xb7,puVar8 + iVar3 + 0xb9,8);
    puVar1 = puVar9 + iVar6;
    iVar3 = iVar3 + 0x30;
  } while (iVar7 < 8);
  puVar4 = param_1 + 0x22e;
  iVar3 = 0;
  puVar1 = param_2 + 0x240;
  puVar2 = param_1 + 0x231;
  do {
    *puVar1 = *puVar4;
    iVar3 = iVar3 + 1;
    puVar1[1] = puVar2[-2];
    puVar1[2] = puVar2[-1];
    puVar4 = puVar4 + 4;
    puVar1[3] = *puVar2;
    puVar2 = puVar2 + 4;
    puVar1 = puVar1 + 4;
  } while (iVar3 < 0x686);
  param_2[0x1c58] = param_1[0x1c46];
  param_2[0x1c59] = param_1[0x1c47];
  param_2[0x240] = param_1[0x22e];
  param_2[0x241] = param_1[0x22f];
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3016 start=0xf00e0b80 */

/* WARNING: Removing unreachable block (ram,0xf00e0c3c) */
/* WARNING: Removing unreachable block (ram,0xf00e0c24) */

undefined8 _put_partition(undefined *param_1,undefined *param_2)

{
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
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  param_2[0xc] = param_1[0xc];
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = param_1[0xf];
  param_2[0x10] = param_1[0x10];
  param_2[0x11] = param_1[0x11];
  param_2[0x12] = param_1[0x12];
  param_2[0x13] = param_1[0x13];
  _bcopy(param_1 + 0x14,param_2 + 0x14,0x10);
  param_2[0x24] = param_1[0x24];
  _bcopy(param_1 + 0x25,param_2 + 0x25,8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3017 start=0xf00e0c4c */

/* WARNING: Removing unreachable block (ram,0xf00e0eb8) */
/* WARNING: Removing unreachable block (ram,0xf00e0dc8) */
/* WARNING: Removing unreachable block (ram,0xf00e0c68) */
/* WARNING: Removing unreachable block (ram,0xf00e0dd8) */
/* WARNING: Removing unreachable block (ram,0xf00e0ed0) */
/* WARNING: Removing unreachable block (ram,0xf00e0c58) */

undefined8 _put_disktab(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  _bcopy(param_1,param_2,0x18);
  _bcopy(param_1 + 0x18,param_2 + 0x18,0x18);
  *(undefined *)(param_2 + 0x30) = *(undefined *)(param_1 + 0x30);
  *(undefined *)(param_2 + 0x31) = *(undefined *)(param_1 + 0x31);
  *(undefined *)(param_2 + 0x32) = *(undefined *)(param_1 + 0x32);
  *(undefined *)(param_2 + 0x33) = *(undefined *)(param_1 + 0x33);
  *(undefined *)(param_2 + 0x34) = *(undefined *)(param_1 + 0x34);
  *(undefined *)(param_2 + 0x35) = *(undefined *)(param_1 + 0x35);
  *(undefined *)(param_2 + 0x36) = *(undefined *)(param_1 + 0x36);
  *(undefined *)(param_2 + 0x37) = *(undefined *)(param_1 + 0x37);
  *(undefined *)(param_2 + 0x38) = *(undefined *)(param_1 + 0x38);
  *(undefined *)(param_2 + 0x39) = *(undefined *)(param_1 + 0x39);
  *(undefined *)(param_2 + 0x3a) = *(undefined *)(param_1 + 0x3a);
  *(undefined *)(param_2 + 0x3b) = *(undefined *)(param_1 + 0x3b);
  *(undefined *)(param_2 + 0x3c) = *(undefined *)(param_1 + 0x3c);
  *(undefined *)(param_2 + 0x3d) = *(undefined *)(param_1 + 0x3d);
  *(undefined *)(param_2 + 0x3e) = *(undefined *)(param_1 + 0x3e);
  *(undefined *)(param_2 + 0x3f) = *(undefined *)(param_1 + 0x3f);
  *(undefined *)(param_2 + 0x40) = *(undefined *)(param_1 + 0x40);
  *(undefined *)(param_2 + 0x41) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_2 + 0x42) = *(undefined *)(param_1 + 0x42);
  *(undefined *)(param_2 + 0x43) = *(undefined *)(param_1 + 0x43);
  *(undefined *)(param_2 + 0x44) = *(undefined *)(param_1 + 0x44);
  *(undefined *)(param_2 + 0x45) = *(undefined *)(param_1 + 0x45);
  *(undefined *)(param_2 + 0x46) = *(undefined *)(param_1 + 0x46);
  *(undefined *)(param_2 + 0x47) = *(undefined *)(param_1 + 0x47);
  *(undefined *)(param_2 + 0x48) = *(undefined *)(param_1 + 0x48);
  *(undefined *)(param_2 + 0x49) = *(undefined *)(param_1 + 0x49);
  *(undefined *)(param_2 + 0x4a) = *(undefined *)(param_1 + 0x4a);
  puVar5 = (undefined *)(param_2 + 0x50);
  *(undefined *)(param_2 + 0x4b) = *(undefined *)(param_1 + 0x4b);
  puVar4 = (undefined *)(param_1 + 0x50);
  *(undefined *)(param_2 + 0x4c) = *(undefined *)(param_1 + 0x4c);
  iVar3 = 0;
  *(undefined *)(param_2 + 0x4d) = *(undefined *)(param_1 + 0x4d);
  puVar2 = (undefined *)(param_2 + 0x53);
  *(undefined *)(param_2 + 0x4e) = *(undefined *)(param_1 + 0x4e);
  puVar1 = (undefined *)(param_1 + 0x53);
  *(undefined *)(param_2 + 0x4f) = *(undefined *)(param_1 + 0x4f);
  do {
    iVar3 = iVar3 + 1;
    *puVar5 = *puVar4;
    puVar2[-2] = puVar1[-2];
    puVar4 = puVar4 + 4;
    puVar2[-1] = puVar1[-1];
    puVar5 = puVar5 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x58,param_2 + 0x58,0x18);
  _bcopy(param_1 + 0x70,param_2 + 0x70,0x20);
  iVar9 = 0;
  iVar8 = 0;
  *(undefined *)(param_2 + 0x90) = *(undefined *)(param_1 + 0x90);
  iVar7 = 0;
  *(undefined *)(param_2 + 0x91) = *(undefined *)(param_1 + 0x91);
  iVar3 = param_1;
  do {
    iVar6 = iVar8 + param_2;
    *(undefined *)(iVar6 + 0x92) = *(undefined *)(iVar3 + 0x94);
    *(undefined *)(iVar6 + 0x93) = *(undefined *)(iVar3 + 0x95);
    *(undefined *)(iVar6 + 0x94) = *(undefined *)(iVar3 + 0x96);
    *(undefined *)(iVar6 + 0x95) = *(undefined *)(iVar3 + 0x97);
    *(undefined *)(iVar6 + 0x96) = *(undefined *)(iVar3 + 0x98);
    *(undefined *)(iVar6 + 0x97) = *(undefined *)(iVar3 + 0x99);
    *(undefined *)(iVar6 + 0x98) = *(undefined *)(iVar3 + 0x9a);
    *(undefined *)(iVar6 + 0x99) = *(undefined *)(iVar3 + 0x9b);
    *(undefined *)(iVar6 + 0x9a) = *(undefined *)(iVar3 + 0x9c);
    *(undefined *)(iVar6 + 0x9b) = *(undefined *)(iVar3 + 0x9d);
    *(undefined *)(iVar6 + 0x9c) = *(undefined *)(iVar3 + 0x9e);
    *(undefined *)(iVar6 + 0x9d) = *(undefined *)(iVar3 + 0x9f);
    *(undefined *)(iVar6 + 0x9e) = *(undefined *)(iVar3 + 0xa0);
    iVar8 = iVar8 + 0x2e;
    *(undefined *)(iVar6 + 0xa0) = *(undefined *)(iVar3 + 0xa2);
    iVar7 = iVar7 + 0x30;
    *(undefined *)(iVar6 + 0xa1) = *(undefined *)(iVar3 + 0xa3);
    iVar9 = iVar9 + 1;
    *(undefined *)(iVar6 + 0xa2) = *(undefined *)(iVar3 + 0xa4);
    *(undefined *)(iVar6 + 0xa3) = *(undefined *)(iVar3 + 0xa5);
    *(undefined *)(iVar6 + 0xa4) = *(undefined *)(iVar3 + 0xa6);
    *(undefined *)(iVar6 + 0xa5) = *(undefined *)(iVar3 + 0xa7);
    _bcopy(iVar3 + 0xa8,iVar6 + 0xa6,0x10);
    *(undefined *)(iVar6 + 0xb6) = *(undefined *)(iVar3 + 0xb8);
    _bcopy(iVar3 + 0xb9,iVar6 + 0xb7,8);
    iVar3 = iVar7 + param_1;
  } while (iVar9 < 8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3018 start=0xf00e0eec */

undefined8 _put_dl_un(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
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
  int iVar2;
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
  iVar2 = 0;
  puVar1 = param_2 + 3;
  do {
    *param_2 = *param_1;
    iVar2 = iVar2 + 1;
    puVar1[-2] = param_1[1];
    puVar1[-1] = param_1[2];
    param_2 = param_2 + 4;
    *puVar1 = param_1[3];
    puVar1 = puVar1 + 4;
    param_1 = param_1 + 4;
  } while (iVar2 < 0x686);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3019 start=0xf00e0f38 */

/* WARNING: Removing unreachable block (ram,0xf00e125c) */
/* WARNING: Removing unreachable block (ram,0xf00e116c) */
/* WARNING: Removing unreachable block (ram,0xf00e0ffc) */
/* WARNING: Removing unreachable block (ram,0xf00e100c) */
/* WARNING: Removing unreachable block (ram,0xf00e117c) */
/* WARNING: Removing unreachable block (ram,0xf00e1274) */
/* WARNING: Removing unreachable block (ram,0xf00e0fa4) */

undefined8 _put_disk_label(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  undefined *puVar8;
  undefined4 unaff_l6;
  undefined *puVar9;
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
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  _bcopy(param_1 + 0xc,param_2 + 0xc,0x18);
  param_2[0x24] = param_1[0x24];
  param_2[0x25] = param_1[0x25];
  param_2[0x26] = param_1[0x26];
  puVar9 = param_1 + 0x2c;
  param_2[0x27] = param_1[0x27];
  puVar8 = param_2 + 0x2c;
  param_2[0x28] = param_1[0x28];
  param_2[0x29] = param_1[0x29];
  param_2[0x2a] = param_1[0x2a];
  param_2[0x2b] = param_1[0x2b];
  _bcopy(puVar9,puVar8,0x18);
  _bcopy(param_1 + 0x44,param_2 + 0x44,0x18);
  param_2[0x5c] = param_1[0x5c];
  param_2[0x5d] = param_1[0x5d];
  param_2[0x5e] = param_1[0x5e];
  param_2[0x5f] = param_1[0x5f];
  param_2[0x60] = param_1[0x60];
  param_2[0x61] = param_1[0x61];
  param_2[0x62] = param_1[0x62];
  param_2[99] = param_1[99];
  param_2[100] = param_1[100];
  param_2[0x65] = param_1[0x65];
  param_2[0x66] = param_1[0x66];
  param_2[0x67] = param_1[0x67];
  param_2[0x68] = param_1[0x68];
  param_2[0x69] = param_1[0x69];
  param_2[0x6a] = param_1[0x6a];
  param_2[0x6b] = param_1[0x6b];
  param_2[0x6c] = param_1[0x6c];
  param_2[0x6d] = param_1[0x6d];
  param_2[0x6e] = param_1[0x6e];
  param_2[0x6f] = param_1[0x6f];
  param_2[0x70] = param_1[0x70];
  param_2[0x71] = param_1[0x71];
  param_2[0x72] = param_1[0x72];
  param_2[0x73] = param_1[0x73];
  param_2[0x74] = param_1[0x74];
  param_2[0x75] = param_1[0x75];
  param_2[0x76] = param_1[0x76];
  puVar5 = param_2 + 0x7c;
  param_2[0x77] = param_1[0x77];
  puVar4 = param_1 + 0x7c;
  param_2[0x78] = param_1[0x78];
  iVar3 = 0;
  param_2[0x79] = param_1[0x79];
  puVar2 = param_2 + 0x7f;
  param_2[0x7a] = param_1[0x7a];
  puVar1 = param_1 + 0x7f;
  param_2[0x7b] = param_1[0x7b];
  do {
    iVar3 = iVar3 + 1;
    *puVar5 = *puVar4;
    puVar2[-2] = puVar1[-2];
    puVar4 = puVar4 + 4;
    puVar2[-1] = puVar1[-1];
    puVar5 = puVar5 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x84,param_2 + 0x84,0x18);
  _bcopy(param_1 + 0x9c,param_2 + 0x9c,0x20);
  iVar7 = 0;
  param_2[0xbc] = param_1[0xbc];
  iVar6 = 0;
  param_2[0xbd] = param_1[0xbd];
  puVar1 = puVar9;
  iVar3 = 0;
  do {
    puVar8[iVar3 + 0x92] = puVar1[0x94];
    puVar8[iVar3 + 0x93] = puVar1[0x95];
    puVar8[iVar3 + 0x94] = puVar1[0x96];
    puVar8[iVar3 + 0x95] = puVar1[0x97];
    puVar8[iVar3 + 0x96] = puVar1[0x98];
    puVar8[iVar3 + 0x97] = puVar1[0x99];
    puVar8[iVar3 + 0x98] = puVar1[0x9a];
    puVar8[iVar3 + 0x99] = puVar1[0x9b];
    puVar8[iVar3 + 0x9a] = puVar1[0x9c];
    puVar8[iVar3 + 0x9b] = puVar1[0x9d];
    puVar8[iVar3 + 0x9c] = puVar1[0x9e];
    puVar8[iVar3 + 0x9d] = puVar1[0x9f];
    puVar8[iVar3 + 0x9e] = puVar1[0xa0];
    puVar8[iVar3 + 0xa0] = puVar1[0xa2];
    iVar6 = iVar6 + 0x30;
    puVar8[iVar3 + 0xa1] = puVar1[0xa3];
    iVar7 = iVar7 + 1;
    puVar8[iVar3 + 0xa2] = puVar1[0xa4];
    puVar8[iVar3 + 0xa3] = puVar1[0xa5];
    puVar8[iVar3 + 0xa4] = puVar1[0xa6];
    puVar8[iVar3 + 0xa5] = puVar1[0xa7];
    _bcopy(puVar1 + 0xa8,puVar8 + iVar3 + 0xa6,0x10);
    puVar8[iVar3 + 0xb6] = puVar1[0xb8];
    _bcopy(puVar1 + 0xb9,puVar8 + iVar3 + 0xb7,8);
    puVar1 = puVar9 + iVar6;
    iVar3 = iVar3 + 0x2e;
  } while (iVar7 < 8);
  puVar4 = param_2 + 0x22e;
  iVar3 = 0;
  puVar1 = param_1 + 0x240;
  puVar2 = param_2 + 0x231;
  do {
    *puVar4 = *puVar1;
    iVar3 = iVar3 + 1;
    puVar2[-2] = puVar1[1];
    puVar2[-1] = puVar1[2];
    puVar4 = puVar4 + 4;
    *puVar2 = puVar1[3];
    puVar2 = puVar2 + 4;
    puVar1 = puVar1 + 4;
  } while (iVar3 < 0x686);
  param_2[0x1c46] = param_1[0x1c58];
  param_2[0x1c47] = param_1[0x1c59];
  param_2[0x22e] = param_1[0x240];
  param_2[0x22f] = param_1[0x241];
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3020 start=0xf00e1310 */

qword _checksum16(word *param_1,int param_2)

{
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
  uint uVar1;
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
  uVar1 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = uVar1 + *param_1;
    param_1 = param_1 + 1;
  }
  uVar1 = (uVar1 >> 0x10) + (uVar1 & 0xffff);
  if (0xffff < uVar1) {
    uVar1 = uVar1 - 0xffff;
  }
  return CONCAT44(0xffffffff,uVar1) & 0xffffffff0000ffff;
}
/* GHIDRADEC_FUNCTION index=3021 start=0xf00e136c */

undefined8 _check_label(word *param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  word *pwVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  word *pwVar7;
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
  iVar2 = *(int *)param_1;
  if ((iVar2 == 0x4e655854) || (iVar2 == 0x646c5632)) {
    uVar3 = 0x1c48;
    pwVar7 = param_1 + 0xe23;
  }
  else {
    uVar3 = 0x230;
    if (iVar2 != 0x646c5633) {
      puVar4 = aBadDiskLabelMa;
      goto locret_F00E1470;
    }
    pwVar7 = param_1 + 0x117;
  }
  if (*(int *)(param_1 + 2) == param_2) {
    param_1[2] = 0;
    param_1[3] = 0;
    uVar3 = uVar3 >> 1;
    uVar6 = 0;
    wVar1 = *pwVar7;
    *pwVar7 = 0;
    pwVar5 = param_1;
    while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
      uVar6 = uVar6 + *pwVar5;
      pwVar5 = pwVar5 + 1;
    }
    uVar3 = (uVar6 >> 0x10) + (uVar6 & 0xffff);
    if (0xffff < uVar3) {
      uVar3 = uVar3 - 0xffff;
    }
    if ((uVar3 & 0xffff) == (uint)wVar1) {
      *(int *)(param_1 + 2) = param_2;
      *pwVar7 = wVar1;
      puVar4 = (undefined *)0x0;
    }
    else {
      puVar4 = aLabelChecksumE;
    }
  }
  else {
    puVar4 = aLabelInWrongLo;
  }
locret_F00E1470:
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=3022 start=0xf00e1478 */

undefined8 _audio_snd_reply_ret_device(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x12f;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3023 start=0xf00e1494 */

undefined8 _audio_snd_reply_ret_stream(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x130;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3024 start=0xf00e14b0 */

undefined8
_audio_snd_reply_illegal_msg
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x13a;
  *(undefined4 *)(param_1 + 4) = 0x24;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(uint *)(param_1 + 0x18) = dword_F012EF5C & 0xffff000f | 0x20;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x20) = param_5;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3025 start=0xf00e14f8 */

undefined8
_audio_snd_reply_recorded_data
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
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
  *(undefined *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 4) = 0x30;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 300;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x20) = dword_F012EF50;
  *(undefined4 *)(param_1 + 0x24) = DAT_f012ef54._0_4_;
  *(undefined4 *)(param_1 + 0x28) = param_5;
  *(undefined4 *)(param_1 + 0x2c) = param_4;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3026 start=0xf00e1554 */

undefined8 _audio_snd_reply_timed_out(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x12d;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3027 start=0xf00e1584 */

undefined8
_audio_snd_reply_ret_samples(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  *(undefined4 *)(param_1 + 4) = 0x24;
  *(undefined4 *)(param_1 + 0x14) = 0x12e;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3028 start=0xf00e15b8 */

undefined8 _audio_snd_reply_overflow(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x133;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3029 start=0xf00e15e8 */

undefined8 _audio_snd_reply_started(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x135;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3030 start=0xf00e1618 */

undefined8 _audio_snd_reply_completed(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x136;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3031 start=0xf00e1648 */

undefined8 _audio_snd_reply_aborted(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x137;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3032 start=0xf00e1678 */

undefined8 _audio_snd_reply_paused(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x138;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3033 start=0xf00e16a8 */

undefined8 _audio_snd_reply_resumed(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x139;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3034 start=0xf00e16d8 */

undefined8 _audio_snd_reply_ret_parms(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x131;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3035 start=0xf00e1708 */

undefined8 _audio_snd_reply_ret_volume(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0x132;
  *(undefined4 *)(param_1 + 4) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = dword_F012EF5C;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3036 start=0xf00e1738 */

undefined8
_audio_snd_reply_ret_formats
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined4 uVar1;
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
  *(undefined4 *)(param_1 + 0x14) = 0x140;
  *(undefined4 *)(param_1 + 4) = 0x30;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x18) = dword_F012EF5C & 0xffff000f | 0x50;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = param_5;
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  *(undefined4 *)(param_1 + 0x28) = param_6;
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3037 start=0xf00e178c */

undefined8 _audio_swapSamples(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
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
  if (((uint)param_1 & 1) != 0) {
    param_1 = (undefined2 *)((uint)param_1 & 0xfffffffe);
  }
  if (((uint)param_2 & 1) != 0) {
    param_2 = (undefined2 *)((uint)param_2 & 0xfffffffe);
  }
  while (param_3 = param_3 + -1, param_3 != -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3038 start=0xf00e17dc */

undefined8 _audio_twosComp8ToUnary(byte *param_1,byte *param_2,int param_3)

{
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    *param_2 = *param_1 ^ 0x80 | *param_1 & 0x7f;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3039 start=0xf00e1820 */

/* WARNING: Removing unreachable block (ram,0xf00e1934) */
/* WARNING: Removing unreachable block (ram,0xf00e18ac) */
/* WARNING: Removing unreachable block (ram,0xf00e1a08) */
/* WARNING: Removing unreachable block (ram,0xf00e1c24) */
/* WARNING: Removing unreachable block (ram,0xf00e1bcc) */
/* WARNING: Removing unreachable block (ram,0xf00e1b3c) */
/* WARNING: Removing unreachable block (ram,0xf00e1b94) */
/* WARNING: Removing unreachable block (ram,0xf00e1bec) */
/* WARNING: Removing unreachable block (ram,0xf00e199c) */
/* WARNING: Removing unreachable block (ram,0xf00e1a4c) */
/* WARNING: Removing unreachable block (ram,0xf00e1918) */
/* WARNING: Removing unreachable block (ram,0xf00e1c48) */
/* WARNING: Removing unreachable block (ram,0xf00e1b04) */

undefined8
_audio_scaleSamples(byte *param_1,undefined2 *param_2,uint param_3,int param_4,int param_5,
                   int param_6)

{
  byte bVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar8;
  undefined4 unaff_i2;
  int iVar9;
  undefined4 unaff_i3;
  int iVar10;
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
  iVar7 = 0;
  iVar10 = *(int *)((int)register0x00000038 + 0x5c);
  iVar3 = param_6 >> 8;
  iVar9 = iVar10 >> 8;
  if (param_4 == 1) {
    if (param_5 == 1) {
      iVar10 = param_3 - 1;
      if (iVar10 != -1) {
        bVar1 = *param_1;
        do {
          iVar5 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2);
          param_1 = param_1 + 1;
          .umul(iVar5,(iVar3 + iVar9) / 2);
          iVar5 = iVar5 >> 7;
          if (iVar5 < 0x8000) {
            if (iVar5 < -0x8000) {
              *(undefined *)param_2 = 0;
              goto loc_F00E1B30;
            }
            uVar6 = (undefined)iVar5;
            _audio_shortToMulaw();
            *(undefined *)param_2 = uVar6;
          }
          else {
            *(undefined *)param_2 = 0x80;
loc_F00E1B30:
            iVar7 = iVar7 + 1;
          }
          param_2 = (undefined2 *)((int)param_2 + 1);
          iVar10 = iVar10 + -1;
          if (iVar10 == -1) break;
          bVar1 = *param_1;
        } while( true );
      }
    }
    else if ((param_5 == 2) && (iVar10 = (param_3 >> 1) - 1, iVar10 != -1)) {
      bVar1 = *param_1;
      do {
        iVar5 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2);
        .umul(iVar5,iVar3);
        iVar5 = iVar5 >> 7;
        if (iVar5 < 0x8000) {
          if (iVar5 < -0x8000) {
            *(undefined *)param_2 = 0;
            goto loc_F00E1BC0;
          }
          uVar6 = (undefined)iVar5;
          _audio_shortToMulaw();
          *(undefined *)param_2 = uVar6;
        }
        else {
          *(undefined *)param_2 = 0x80;
loc_F00E1BC0:
          iVar7 = iVar7 + 1;
        }
        puVar8 = (undefined *)((int)param_2 + 1);
        iVar5 = (int)*(sword *)(_audio_muLaw + (uint)param_1[1] * 2);
        param_1 = param_1 + 2;
        .umul(iVar5,iVar9);
        iVar5 = iVar5 >> 7;
        if (iVar5 < 0x8000) {
          if (iVar5 < -0x8000) {
            *puVar8 = 0;
            goto loc_F00E1C18;
          }
          uVar6 = (undefined)iVar5;
          _audio_shortToMulaw();
          *puVar8 = uVar6;
        }
        else {
          *puVar8 = 0x80;
loc_F00E1C18:
          iVar7 = iVar7 + 1;
        }
        param_2 = param_2 + 1;
        iVar10 = iVar10 + -1;
        if (iVar10 == -1) break;
        bVar1 = *param_1;
      } while( true );
    }
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        if (param_5 == 1) {
          iVar9 = (param_3 >> 1) - 1;
          if (iVar9 != -1) {
            sVar2 = *(sword *)param_1;
            do {
              iVar3 = (int)sVar2;
              .umul(iVar3,(param_6 + iVar10) / 2);
              iVar3 = iVar3 >> 0xf;
              param_1 = param_1 + 2;
              if (iVar3 < 0x8000) {
                if (iVar3 < -0x8000) {
                  *param_2 = 0x8000;
                  goto loc_F00E18DC;
                }
                *param_2 = (sword)iVar3;
              }
              else {
                *param_2 = 0x7fff;
loc_F00E18DC:
                iVar7 = iVar7 + 1;
              }
              param_2 = param_2 + 1;
              iVar9 = iVar9 + -1;
              if (iVar9 == -1) break;
              sVar2 = *(sword *)param_1;
            } while( true );
          }
        }
        else {
          param_3 = param_3 >> 2;
          if (param_5 == 2) {
            while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
              uVar4 = (uint)*(sword *)param_1;
              .umul(uVar4,param_6);
              *param_2 = (sword)(uVar4 >> 0xf);
              uVar4 = (uint)*(sword *)(param_1 + 2);
              .umul(uVar4,iVar10);
              param_1 = param_1 + 4;
              param_2[1] = (sword)(uVar4 >> 0xf);
              param_2 = param_2 + 2;
            }
          }
        }
        goto locret_F00E1C50;
      }
    }
    else if (param_4 == 3) {
      if (param_5 == 1) {
        iVar10 = param_3 - 1;
        if (iVar10 != -1) {
          bVar1 = *param_1;
          do {
            iVar5 = (int)(char)bVar1;
            .umul(iVar5,(iVar3 + iVar9) / 2);
            iVar5 = iVar5 >> 7;
            param_1 = param_1 + 1;
            if (iVar5 < 0x80) {
              if (iVar5 < -0x80) {
                *(undefined *)param_2 = 0x80;
                goto loc_F00E19CC;
              }
              *(char *)param_2 = (char)iVar5;
            }
            else {
              *(undefined *)param_2 = 0x7f;
loc_F00E19CC:
              iVar7 = iVar7 + 1;
            }
            param_2 = (undefined2 *)((int)param_2 + 1);
            iVar10 = iVar10 + -1;
            if (iVar10 == -1) break;
            bVar1 = *param_1;
          } while( true );
        }
      }
      else if ((param_5 == 2) && (iVar10 = (param_3 >> 1) - 1, iVar10 != -1)) {
        bVar1 = *param_1;
        do {
          iVar5 = (int)(char)bVar1;
          .umul(iVar5,iVar3);
          iVar5 = iVar5 >> 7;
          if (iVar5 < 0x80) {
            if (iVar5 < -0x80) {
              *(undefined *)param_2 = 0x80;
              goto loc_F00E1A38;
            }
            *(char *)param_2 = (char)iVar5;
          }
          else {
            *(undefined *)param_2 = 0x7f;
loc_F00E1A38:
            iVar7 = iVar7 + 1;
          }
          puVar8 = (undefined *)((int)param_2 + 1);
          iVar5 = (int)(char)param_1[1];
          .umul(iVar5,iVar9);
          iVar5 = iVar5 >> 7;
          param_1 = param_1 + 2;
          if (iVar5 < 0x80) {
            if (iVar5 < -0x80) {
              *puVar8 = 0x80;
              goto loc_F00E1A7C;
            }
            *puVar8 = (char)iVar5;
          }
          else {
            *puVar8 = 0x7f;
loc_F00E1A7C:
            iVar7 = iVar7 + 1;
          }
          param_2 = param_2 + 1;
          iVar10 = iVar10 + -1;
          if (iVar10 == -1) break;
          bVar1 = *param_1;
        } while( true );
      }
      goto locret_F00E1C50;
    }
    _IOLog(aAudioUnrecogni_4);
  }
locret_F00E1C50:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=3040 start=0xf00e1c58 */

/* WARNING: Removing unreachable block (ram,0xf00e1c68) */

undefined8
_audio_resample22To44(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  _audio_convertMonoToStereo(param_1,param_2,param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3041 start=0xf00e1c78 */

/* WARNING: Removing unreachable block (ram,0xf00e1d1c) */

undefined8 _audio_resample44To22(undefined2 *param_1,undefined2 *param_2,uint param_3,int param_4)

{
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
  uint uVar1;
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
  uVar1 = param_3 >> 1;
  if (param_4 == 1) {
joined_r0xf00e1cf4:
    while (uVar1 = uVar1 - 1, uVar1 != 0xffffffff) {
      *(undefined *)param_2 = *(undefined *)param_1;
      param_2 = (undefined2 *)((int)param_2 + 1);
      param_1 = param_1 + 1;
    }
  }
  else {
    if (param_4 < 2) {
      param_3 = param_3 >> 2;
      if (param_4 == 0) {
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          *param_2 = *param_1;
          param_2 = param_2 + 1;
          param_1 = param_1 + 2;
        }
        goto locret_F00E1D24;
      }
    }
    else if (param_4 == 3) goto joined_r0xf00e1cf4;
    _IOLog(aAudioUnrecogni_5);
  }
locret_F00E1D24:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3042 start=0xf00e1d2c */

/* WARNING: Removing unreachable block (ram,0xf00e1de0) */

undefined8
_audio_convertMonoToStereo(undefined2 *param_1,undefined2 *param_2,uint param_3,int param_4)

{
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
  if (param_4 == 1) {
joined_r0xf00e1dac:
    while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
      *(undefined *)param_2 = *(undefined *)param_1;
      *(undefined *)((int)param_2 + 1) = *(undefined *)param_1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      param_2 = param_2 + 1;
    }
  }
  else {
    if (param_4 < 2) {
      param_3 = param_3 >> 1;
      if (param_4 == 0) {
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          *param_2 = *param_1;
          param_2[1] = *param_1;
          param_1 = param_1 + 1;
          param_2 = param_2 + 2;
        }
        goto locret_F00E1DE8;
      }
    }
    else if (param_4 == 3) goto joined_r0xf00e1dac;
    _IOLog(aAudioUnrecogni_6);
  }
locret_F00E1DE8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3043 start=0xf00e1df0 */

/* WARNING: Removing unreachable block (ram,0xf00e1f3c) */
/* WARNING: Removing unreachable block (ram,0xf00e1f20) */

undefined8 _audio_convertStereoToMono(byte *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  byte bVar1;
  sword sVar2;
  undefined uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  uVar6 = param_3 >> 1;
  if (param_4 == 1) {
    while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
      bVar1 = *param_1;
      pbVar5 = param_1 + 1;
      param_1 = param_1 + 2;
      iVar4 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2) +
              (int)*(sword *)(_audio_muLaw + (uint)*pbVar5 * 2) +
              ((int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2) +
               (int)*(sword *)(_audio_muLaw + (uint)*pbVar5 * 2) & 1U);
      uVar3 = (undefined)((uint)((iVar4 - (iVar4 >> 0x1f)) * 0x8000) >> 0x10);
      _audio_shortToMulaw();
      *(undefined *)param_2 = uVar3;
      param_2 = (undefined2 *)((int)param_2 + 1);
    }
  }
  else {
    if (param_4 < 2) {
      param_3 = param_3 >> 2;
      if (param_4 == 0) {
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          sVar2 = *(sword *)param_1;
          pbVar5 = param_1 + 2;
          param_1 = param_1 + 4;
          iVar4 = (int)sVar2 + (int)*(sword *)pbVar5 + ((int)sVar2 + (int)*(sword *)pbVar5 & 1U);
          *param_2 = (sword)((uint)(iVar4 - (iVar4 >> 0x1f)) >> 1);
          param_2 = param_2 + 1;
        }
        goto locret_F00E1F44;
      }
    }
    else if (param_4 == 3) {
      while (uVar6 = uVar6 - 1, uVar6 != 0xffffffff) {
        bVar1 = *param_1;
        pbVar5 = param_1 + 1;
        param_1 = param_1 + 2;
        iVar4 = (int)(char)bVar1 + (int)(char)*pbVar5 + ((int)(char)bVar1 + (int)(char)*pbVar5 & 1U)
        ;
        *(char *)param_2 = (char)((uint)(iVar4 - (iVar4 >> 0x1f)) >> 1);
        param_2 = (undefined2 *)((int)param_2 + 1);
      }
      goto locret_F00E1F44;
    }
    _IOLog(aAudioUnrecogni_6);
  }
locret_F00E1F44:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3044 start=0xf00e1f4c */

undefined8 _audio_convertLinear8ToLinear16(byte *param_1,sword *param_2,int param_3)

{
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    *param_2 = (word)*param_1 << 8;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3045 start=0xf00e1f88 */

/* WARNING: Removing unreachable block (ram,0xf00e1fac) */

undefined8 _audio_convertLinear8ToMulaw8(int param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    param_1 = param_1 + 1;
    uVar1 = 0;
    _audio_shortToMulaw();
    *param_2 = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3046 start=0xf00e1fc8 */

undefined8 _audio_convertLinear16ToLinear8(undefined2 *param_1,undefined *param_2,int param_3)

{
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    *param_2 = (char)((word)*param_1 >> 8);
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3047 start=0xf00e2004 */

/* WARNING: Removing unreachable block (ram,0xf00e2020) */

undefined8 _audio_convertLinear16ToMulaw8(undefined2 *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    uVar1 = (undefined)*param_1;
    param_1 = param_1 + 1;
    _audio_shortToMulaw();
    *param_2 = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3048 start=0xf00e203c */

undefined8 _audio_convertMulaw8ToLinear16(byte *param_1,undefined *param_2,int param_3)

{
  byte bVar1;
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
  while (param_3 = param_3 + -1, param_3 != -1) {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = (char)*(undefined2 *)(_audio_muLaw + (uint)bVar1 * 2);
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3049 start=0xf00e2080 */

undefined8 _audio_convertMulaw8ToLinear8(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}

