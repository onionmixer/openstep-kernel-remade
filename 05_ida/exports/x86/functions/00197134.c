/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197134. */
int __cdecl sub_197134(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // edx

  v1 = *(_DWORD *)(a1 + 64); /*0x19713b*/
  if ( (v1 & 0x121) != 0 || !*(_DWORD *)(a1 + 24) ) /*0x197145*/
  {
    if ( *(_DWORD *)(a1 + 24) <= ttlowat[*(_BYTE *)(a1 + 74) & 0x1F] ) /*0x197199*/
    {
      v2 = *(_DWORD *)(a1 + 64); /*0x19719b*/
      if ( (v2 & 0x40) != 0 ) /*0x1971a0*/
      {
        LOBYTE(v2) = v2 & 0xBF; /*0x1971a2*/
        *(_DWORD *)(a1 + 64) = v2; /*0x1971a4*/
        wakeup(a1 + 24); /*0x1971ab*/
      }
      v3 = *(_DWORD *)(a1 + 44); /*0x1971b3*/
      if ( v3 ) /*0x1971b8*/
      {
        selwakeup(v3, *(_DWORD *)(a1 + 64) & 0x1000); /*0x1971c4*/
        selthreadclear((_DWORD *)(a1 + 44)); /*0x1971cd*/
        *(_DWORD *)(a1 + 64) &= ~0x1000u; /*0x1971d2*/
      }
    }
  }
  else
  {
    LOBYTE(v1) = v1 | 0x20; /*0x19714b*/
    *(_DWORD *)(a1 + 64) = v1; /*0x19714d*/
    if ( *(_DWORD *)(a1 + 24) <= ttlowat[*(_BYTE *)(a1 + 74) & 0x1F] ) /*0x197161*/
      ns_timeout((int)sub_1971E4, a1, 1000); /*0x19717f*/
    else
      calloutDispatchUnique((int)sub_1971E4, a1); /*0x197169*/
  }
  return 0; /*0x1971db*/
}
