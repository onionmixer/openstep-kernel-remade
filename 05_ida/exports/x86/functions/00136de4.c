/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136de4. */
int __cdecl svc_register(SVCXPRT *a1, unsigned __int32 a2, unsigned __int32 a3, void (*a4)(void), int a5)
{
  int v5; // eax
  _DWORD *v7; // eax
  _BYTE v8[4]; // [esp+Ch] [ebp-4h] BYREF

  v5 = sub_136E88(a2, a3, v8); /*0x136dfc*/
  if ( v5 ) /*0x136e06*/
  {
    if ( *(void (**)(void))(v5 + 12) != a4 ) /*0x136e0b*/
      return 0; /*0x136e0f*/
  }
  else
  {
    v7 = (_DWORD *)kalloc(0x10u); /*0x136e16*/
    v7[1] = a2; /*0x136e1b*/
    v7[2] = a3; /*0x136e1e*/
    v7[3] = a4; /*0x136e21*/
    *v7 = dword_1E5A1C; /*0x136e2a*/
    dword_1E5A1C = (int)v7; /*0x136e2c*/
  }
  return 1; /*0x136e39*/
}
