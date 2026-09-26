/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136e40. */
void __cdecl svc_unregister(unsigned __int32 a1, unsigned __int32 a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // [esp+0h] [ebp-4h] BYREF

  v2 = (_DWORD *)sub_136E88(a1, a2, &v3); /*0x136e52*/
  if ( v2 ) /*0x136e5c*/
  {
    if ( v3 ) /*0x136e63*/
      *v3 = *v2; /*0x136e72*/
    else
      dword_1E5A1C = *v2; /*0x136e67*/
    *v2 = 0; /*0x136e74*/
    kfree((int)v2, 0x10u); /*0x136e7d*/
  }
}
