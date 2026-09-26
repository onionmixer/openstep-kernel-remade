/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160adc. */
int __cdecl power_callout(int a1, int a2)
{
  int v2; // ebx
  __int64 v3; // rax
  int v5; // [esp+4h] [ebp-4h] BYREF

  v2 = a2; /*0x160ae3*/
  if ( !PMGetPowerEvent(&v5) ) /*0x160aea*/
  {
    switch ( v5 ) /*0x160b07*/
    {
      case 1: /*0x160b07*/
      case 9: /*0x160b07*/
        dword_1E5E4C = 1; /*0x160b3c*/
        PMSetPowerState(1, 1); /*0x160b4a*/
        break; /*0x160b52*/
      case 2: /*0x160b07*/
      case 8: /*0x160b07*/
      case 10: /*0x160b07*/
        dword_1E5E4C = 2; /*0x160b54*/
        PMSetPowerState(1, 2); /*0x160b62*/
        dword_1E5E4C = 0; /*0x160b67*/
        PMSetPowerState(1, 0); /*0x160b75*/
        break; /*0x160b7d*/
      case 3: /*0x160b07*/
      case 4: /*0x160b07*/
      case 11: /*0x160b07*/
        if ( dword_1E5E4C ) /*0x160b87*/
        {
          dword_1E5E4C = 0; /*0x160b89*/
          PMSetPowerState(1, 0); /*0x160b97*/
        }
        goto LABEL_7; /*0x160b97*/
      case 7: /*0x160b07*/
LABEL_7:
        PMUpdateClock(); /*0x160b9f*/
        break; /*0x160b9f*/
      default:
        break;
    }
  }
  if ( !a2 ) /*0x160ba6*/
    v2 = calloutEntryAllocate(power_callout, 0); /*0x160bb4*/
  v3 = calloutDeadlineFromInterval(1010000000, 0); /*0x160bc0*/
  return calloutEntryDispatchDelayed(v2, v3, HIDWORD(v3)); /*0x160bcd*/
}
