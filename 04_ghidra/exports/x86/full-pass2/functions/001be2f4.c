/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be2f4 */

void _audio_convertMonoToStereo(undefined2 *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  if (param_4 == 1) {
joined_r0x001be348:
    while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      *(undefined1 *)((int)param_2 + 1) = *(undefined1 *)param_1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      param_2 = param_2 + 1;
    }
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        param_3 = param_3 >> 1;
        while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
          *param_2 = *param_1;
          param_2[1] = *param_1;
          param_1 = param_1 + 1;
          param_2 = param_2 + 2;
        }
        return;
      }
    }
    else if (param_4 == 3) goto joined_r0x001be348;
    _IOLog("Audio: unrecognized format %d in convMono\n",param_4);
  }
  return;
}

