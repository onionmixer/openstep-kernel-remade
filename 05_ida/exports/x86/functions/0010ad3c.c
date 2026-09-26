/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ad3c. */
unsigned int __cdecl inittodr(int a1)
{
  unsigned int result; // eax
  int v2; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int v3; // [esp+24h] [ebp-8h] BYREF
  int v4; // [esp+28h] [ebp-4h]

  if ( a1 < 536112000 )
  {
    printf("WARNING: preposterous time in file system");
    return printf(" -- CHECK AND RESET THE DATE!\n"); /*0x10ae9c*/
  }
  microtime(&v3); /*0x10ad6c*/
  boottime = v3; /*0x10ad74*/
  dword_1E97AC = 0; /*0x10ad7a*/
  result = v3 - a1; /*0x10ad8c*/
  if ( (int)(v3 - a1) < 0 ) /*0x10ad93*/
    result = a1 - v3; /*0x10ad95*/
  if ( result > 0x2A2FF || (int)v3 <= a1 )
  {
    if ( v3 > 0x1E1337F )
    {
      if ( result <= 0x76A700 )
      {
        printf("WARNING: clock lost %d days", result / 0x15180);
        return printf(" -- CHECK AND RESET THE DATE!\n"); /*0x10ae8f*/
      }
      printf("WARNING: preposterous time in Real Time Clock");
      v3 = a1; /*0x10ae15*/
      v4 = 0; /*0x10ae18*/
      if ( !suser() ) /*0x10ae29*/
        goto LABEL_13; /*0x10ae29*/
    }
    else
    {
      printf("WARNING: clock not set properly");
      v3 = a1; /*0x10adb8*/
      v4 = 0; /*0x10adbb*/
      if ( !suser() ) /*0x10adcc*/
      {
LABEL_13:
        boottime = v3; /*0x10ae6a*/
        dword_1E97AC = v4; /*0x10ae76*/
        return printf(" -- CHECK AND RESET THE DATE!\n"); /*0x10ae7c*/
      }
    }
    getthetime(&v2); /*0x10ae2f*/
    boottime += v3 - v2; /*0x10ae3c*/
    dword_1E97AC = 0; /*0x10ae42*/
    host_set_time(dword_1E97B4, v3, v4); /*0x10ae62*/
    goto LABEL_13; /*0x10ae62*/
  }
  return result; /*0x10aea4*/
}
