/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159000. */
int __cdecl thread_go(int a1)
{
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // edx
  int v4; // eax

  v1 = splsched(); /*0x15900d*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x15900f*/
  do /*0x159026*/
  {
    while ( *v2 ) /*0x159014*/
      ; /*0x159016*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159026*/
  if ( *(_DWORD *)(a1 + 324) ) /*0x159028*/
    reset_timeout(a1 + 280); /*0x159038*/
  v3 = *(_DWORD *)(a1 + 76); /*0x159040*/
  switch ( v3 & 0xF ) /*0x15904e*/
  {
    case 1: /*0x15904e*/
    case 9: /*0x15904e*/
    case 0xB: /*0x15904e*/
      v4 = *(_DWORD *)(a1 + 76); /*0x159094*/
      LOBYTE(v4) = v3 & 0xFA | 4; /*0x159098*/
      *(_DWORD *)(a1 + 76) = v4; /*0x15909a*/
      *(_DWORD *)(a1 + 68) = 0; /*0x15909d*/
      thread_setrun(a1, 1); /*0x1590a7*/
      break; /*0x1590af*/
    case 3: /*0x15904e*/
    case 5: /*0x15904e*/
    case 7: /*0x15904e*/
    case 0xD: /*0x15904e*/
    case 0xF: /*0x15904e*/
      LOBYTE(v3) = v3 & 0xFE; /*0x1590b4*/
      *(_DWORD *)(a1 + 76) = v3; /*0x1590b7*/
      *(_DWORD *)(a1 + 68) = 0; /*0x1590ba*/
      break; /*0x1590ba*/
    default:
      break;
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1590c1*/
  return splx(v1); /*0x1590cf*/
}
